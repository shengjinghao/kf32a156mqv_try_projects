/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_spi.c                               	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the serial peripheral interface    *
 *                   	(SPI) peripheral functions, including:                *
 *          			+ Serial Peripheral Interface (SPI) initialization    *
 *          			  function       									  *
 *          			+ Serial Peripheral Interface (SPI) configuration 	  *
 *          			  function      									  *
 *          			+ Serial Peripheral Interface (SPI) interrupt 		  *
 *          			  management function 								  *
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd                 *
 *  All rights reserved.                                                      *
 *                                                                            *
 *  This software is copyright protected and proprietary to                    *
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.                                 *
 ******************************************************************************
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  *
 *                     		REVISON HISTORY                               	  *
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  *
 *  Data       Version  Author        Description                             *
 *  ~~~~~~~~~~ ~~~~~~~~ ~~~~~~~~~~~~  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  *
 *  2021-07-08 00.01.00 FAE Group     Version 2.0 update                      *
 *                                                                            *
 *                                                                            *
 *****************************************************************************/

/******************************************************************************
**                      		Include Files                                **
******************************************************************************/


#include "kf32a1x6_spi.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/*******************************************************************************
**                  (SPI) Module Private Macro Definitions                    **
*******************************************************************************/

/* SPI��ʱ��˽�ж��� ----------------------------------------------------*/
/* SPIx_CTLR�Ĵ���SPI��ʼ������ */
#define SPI_CTLR_SPI_INIT_MASK          (SPI_CTLR_SPIMS \
                                       | SPI_CTLR_SPICKS \
                                       | SPI_CTLR_SPIDS \
                                       | SPI_CTLR_SPICKP \
                                       | SPI_CTLR_SPICKE \
                                       | SPI_CTLR_SPIBS )

/* SPIx_CTLR�Ĵ���I2S��ʼ������ */
#define SPI_CTLR_I2S_INIT_MASK          (SPI_CTLR_I2SMC \
                                       | SPI_CTLR_I2SSS \
                                       | SPI_CTLR_PCMS \
                                       | SPI_CTLR_I2SCKS \
                                       | SPI_CTLR_PCMCKP )


/**
  *   ##### ��������ӿ�(SPI)��ʼ������ #####
  */
/**
  * ����  SPI���踴λ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  �ޡ�
  */
void SPI_Reset(SPI_SFRmap* SPIx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    if (SPIx == SPI0_SFR)
    {
       RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_SPI0RST, TRUE);
       RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_SPI0RST, FALSE);
       PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_SPI0CLKEN, TRUE);
    }
    else if (SPIx == SPI1_SFR)
    {
       RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_SPI1RST, TRUE);
       RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_SPI1RST, FALSE);
       PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_SPI1CLKEN, TRUE);
    }
    else if (SPIx == SPI2_SFR)
    {
       RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_SPI2RST, TRUE);
       RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_SPI2RST, FALSE);
       PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_SPI2CLKEN, TRUE);
    }
    else if (SPIx == SPI3_SFR)
    {
       RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_SPI3RST, TRUE);
       RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_SPI3RST, FALSE);
       PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_SPI3CLKEN, TRUE);
    }
    else
    {
        ;
    }
}

/**
  * ����  SPIģʽ��ʼ�����á�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       SPIInitStruct: SPIЭ����Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void SPI_Configuration(SPI_SFRmap* SPIx, SPI_InitTypeDef* spiInitStruct)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_SPI_MODE(spiInitStruct->m_Mode));
    CHECK_RESTRICTION(CHECK_SPI_CLK(spiInitStruct->m_Clock));
    CHECK_RESTRICTION(CHECK_SPI_FIRST_BIT(spiInitStruct->m_FirstBit));
    CHECK_RESTRICTION(CHECK_SPI_CKP(spiInitStruct->m_CKP));
    CHECK_RESTRICTION(CHECK_SPI_CKE(spiInitStruct->m_CKE));
    CHECK_RESTRICTION(CHECK_SPI_DATASIZE(spiInitStruct->m_DataSize));

    /*----------------- ����SPI_CTLR�Ĵ���  -----------------*/
    /* ���ݽṹ���Աm_Mode������SPIMSλ�� */
    /* ���ݽṹ���Աm_Clock������SPICKSλ�� */
    /* ���ݽṹ���Աm_FirstBit������SPIDSλ�� */
    /* ���ݽṹ���Աm_CKP������SPICKPλ�� */
    /* ���ݽṹ���Աm_CKE������SPICKEλ�� */
    /* ���ݽṹ���Աm_DataSize������SPIBSλ�� */
    tmpreg = ((spiInitStruct->m_Mode)      \
            | (spiInitStruct->m_Clock)     \
            | (spiInitStruct->m_FirstBit)  \
            | (spiInitStruct->m_CKP)       \
            | (spiInitStruct->m_CKE)       \
            | (spiInitStruct->m_DataSize));
    SPIx->CTLR = SFR_Config (SPIx->CTLR, ~SPI_CTLR_SPI_INIT_MASK, tmpreg);

    /*----------------- ����SPI_BRGR�Ĵ���  -----------------*/
    /* ���ݽṹ���Աm_BaudRate������SPIBRGλ�� */
    tmpreg = (uint32_t)spiInitStruct->m_BaudRate << SPI_BRGR_SPIBRG0_POS;
    SPIx->BRGR = SFR_Config (SPIx->BRGR, ~SPI_BRGR_SPIBRG, tmpreg);
}

/**
  * ����  I2Sģʽ��ʼ�����á�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       I2SInitStruct:I2SЭ����Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void I2S_Configuration(SPI_SFRmap* SPIx, I2S_InitTypeDef* i2sInitStruct)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_I2S_MODE(i2sInitStruct->m_Mode));
    CHECK_RESTRICTION(CHECK_I2S_STANDARD(i2sInitStruct->m_Standard));
    CHECK_RESTRICTION(CHECK_I2S_PCM(i2sInitStruct->m_PCM));
    CHECK_RESTRICTION(CHECK_I2S_CLK(i2sInitStruct->m_Clock));

    /*----------------- SPIx_CTLR�Ĵ������� -----------------*/
    /* ���ݽṹ���Աm_Mode������I2SMCλ�� */
    /* ���ݽṹ���Աm_STANDARD������I2SSSλ�� */
    /* ���ݽṹ���Աm_PCM������PCMSλ�� */
    /* ���ݽṹ���Աm_CLK������CHLENλ�� */
    /* ���ݽṹ���Աm_CPOL������PCMCKPλ�� */
    tmpreg = ((i2sInitStruct->m_Mode)     \
            | (i2sInitStruct->m_Standard) \
            | (i2sInitStruct->m_PCM)      \
            | (i2sInitStruct->m_Clock));
    SPIx->CTLR = SFR_Config (SPIx->CTLR, ~SPI_CTLR_I2S_INIT_MASK , tmpreg);

    /*----------------- ����SPI_BRGR�Ĵ���  -----------------*/
    /* ���ݽṹ���Աm_Prescaler������I2SDIVλ�� */
    tmpreg = (uint32_t)i2sInitStruct->m_Prescaler << SPI_BRGR_I2SDIV0_POS;
    SPIx->BRGR = SFR_Config (SPIx->BRGR, ~SPI_BRGR_I2SDIV, tmpreg);
}

/**
  * ����  ��ʼ��SPIЭ����Ϣ�ṹ�塣
  * ����  SPI_InitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void SPI_Struct_Init(SPI_InitTypeDef* SPI_InitStruct)
{
    /* ��ʼ�� SPIģʽѡ�� */
    SPI_InitStruct->m_Mode = SPI_MODE_SLAVE;
    /* ��ʼ��SPI����ʱ��ѡ�� */
    SPI_InitStruct->m_Clock = SPI_CLK_HFCLK;
    /* ��ʼ�� SPI���ݷ���ѡ��λ */
    SPI_InitStruct->m_FirstBit = SPI_FIRSTBIT_MSB;
    /* ��ʼ�� SPIʱ�Ӽ���ѡ�� */
    SPI_InitStruct->m_CKP = SPI_CKP_LOW;
    /* ��ʼ�� SPIʱ�ӱ���ѡ�� */
    SPI_InitStruct->m_CKE = SPI_CKE_1EDGE;
    /* ��ʼ�� SPIλģʽѡ�� */
    SPI_InitStruct->m_DataSize = SPI_DATASIZE_8BITS;
    /* ��ʼ�� SPI������û���� */
    SPI_InitStruct->m_BaudRate = 0;
}

/**
  * ����  ��ʼ��I2SЭ����Ϣ�ṹ�塣
  * ����  I2S_InitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void I2S_Struct_Init(I2S_InitTypeDef* I2S_InitStruct)
{
    /* ��ʼ�� I2Sģʽѡ�� */
    I2S_InitStruct->m_Mode = I2S_MODE_SLAVE_TX;
    /* ��ʼ�� I2S��׼ѡ�� */
    I2S_InitStruct->m_Standard = I2S_STANDARD_PHILLIPS;
    /* ��ʼ�� PCM֡ͬ�� */
    I2S_InitStruct->m_PCM = I2S_PCM_LONG;
    /* ��ʼ�� I2Sʱ�ӷ�Ƶѡ�� */
    I2S_InitStruct->m_Clock = I2S_CLK_BAUDRATE;
    /* ��ʼ�� I2SԤ��Ƶ */
    I2S_InitStruct->m_Prescaler = 0;
}
/**
  *   ##### ��������ӿ�(SPI)��ʼ������������� #####
  */


/**
  *   ##### ��������ӿ�(SPI)���ú��� #####
  */
/**
  * ����  ����SPIģ����ʹ��λ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: SPIʹ��λ������Ϣ��ȡֵΪ TRUE �� FALSE��
  * ����  �ޡ�
  */
void SPI_Cmd (SPI_SFRmap* SPIx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*----------------- ����SPI_CTLR�Ĵ���SPIENλ  -----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��SPI */
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_SPIEN_POS);
    }
    else
    {
        /* ��ֹSPI */
        SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_SPIEN_POS);
    }
}

/**
  * ����  ����I2Sѡ��λ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: I2Sѡ��λ������Ϣ��ȡֵΪ TRUE �� FALSE��
  *       TRUE������ѡ��I2S����ģʽ
  *       FALSE:����ѡ��SPI����ģʽ
  * ����  �ޡ�
  */
void I2S_Mode_Select(SPI_SFRmap* SPIx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*----------------- ����SPI_CTLR�Ĵ���I2SMODλ  -----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��I2S */
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_I2SMOD_POS);
    }
    else
    {
        /* ��ֹI2S */
        SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_I2SMOD_POS);
    }
}

/**
  * ����  ��ȡSPI_I2S�������ݡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  32λ�������ݡ�
  */
uint32_t
SPI_I2S_ReceiveData (SPI_SFRmap* SPIx)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*----------------- ��ȡSPI_BUFR�Ĵ���  -----------------*/
    tmpreg = SPIx->BUFR;

    return tmpreg;
}

/**
  * ����  ����SPI_I2S����32λ���ݡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  �ޡ�
  */
void SPI_I2S_SendData32(SPI_SFRmap* SPIx, uint32_t Data)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*----------------- ����SPI_BUFR�Ĵ���  -----------------*/
    SPIx->BUFR = Data;
}

/**
  * ����  ����SPI_I2S����8λ���ݡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  �ޡ�
  */
void SPI_I2S_SendData8(SPI_SFRmap* SPIx, uint8_t Data)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*----------------- ����SPI_BUFR�Ĵ���  -----------------*/
    SPIx->BUFR = Data;
}

/**
  * ����  ����SPI�����ʼĴ�����
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       BAUDRATE: ������ѡ��ȡֵΪ0~65535��
  * ����  �ޡ�
  */
void SPI_BaudRate_Config (SPI_SFRmap* SPIx, uint16_t BAUDRATE)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*---------------- ����SPI_CTLR�Ĵ���I2SSSλ ----------------*/
    tmpreg = (uint32_t)BAUDRATE<< SPI_BRGR_SPIBRG0_POS;
    SPIx->BRGR = SFR_Config (SPIx->BRGR, ~SPI_BRGR_SPIBRG, tmpreg);
}

/**
  * ����  ����I2SԤ��Ƶ�Ĵ�����
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       DIV: I2SԤ��Ƶѡ��ȡֵΪ0~255��
  * ����  �ޡ�
  */
void I2S_DIV_Config (SPI_SFRmap* SPIx,uint8_t DIV)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*---------------- ����SPI_CTLR�Ĵ���λI2SSS ----------------*/
    tmpreg = (uint32_t)DIV << SPI_BRGR_I2SDIV0_POS;
    SPIx->BRGR = SFR_Config (SPIx->BRGR, ~SPI_BRGR_I2SDIV, tmpreg);
}

/**
  * ����  ����SPIͬ�����ж˿�ģʽѡ��λ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       MODE: ģʽѡ��ȡֵ��ΧΪ��
  *               SPI_MODE_MASTER_CLKDIV4: SPI����ģʽ��ʱ�� = ����ʱ��/4
  *               SPI_MODE_MASTER_CLKDIV16: SPI����ģʽ��ʱ�� = ����ʱ��/16
  *               SPI_MODE_MASTER_CLKDIV64: SPI����ģʽ��ʱ�� = ����ʱ��/64
  *               SPI_MODE_MASTER_T2DIV2: SPI����ģʽ��ʱ�� = TIMER2/2
  *               SPI_MODE_SLAVE: SPI�Ӷ�ģʽ��ʱ�� = SCK���š�ʹ��SS���ſ���
  * ����  �ޡ�
  */
void SPI_MODE_Config (SPI_SFRmap* SPIx,uint32_t MODE)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_SPI_MODE(MODE));

    /*---------------- ����SPI_CTLR�Ĵ���SPIMSλ ----------------*/
    SPIx->CTLR = SFR_Config (SPIx->CTLR, ~SPI_CTLR_SPIMS, MODE);
}

/**
  * ����  ����SPI����ʱ��ѡ��Ĵ�����
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       ClockSource: ģʽѡ��ȡֵ��ΧΪ��
  *                      SPI_CLK_SCLK  :ѡ��SCLKΪSPI����ʱ��
  *                      SPI_CLK_HFCLK :ѡ��HFCLKΪSPI����ʱ��
  *                      SPI_CLK_LFCLK :ѡ��LFCLKΪSPI����ʱ��
  * ����  �ޡ�
  */
void SPI_CLK_Config (SPI_SFRmap* SPIx,uint32_t ClockSource)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_SPI_CLK(ClockSource));

    /*---------------- ����SPI_CTLR�Ĵ���SPIMSλ ----------------*/
    SPIx->CTLR = SFR_Config (SPIx->CTLR, ~SPI_CTLR_SPICKS, ClockSource);
}

/**
  * ����  ����SPI���ݷ���ѡ��λ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       DataDirection: SPI���ݷ���ȡֵΪ��
  *                        SPI_FIRSTBIT_MSB:�����λ����ǰ��
  *                        SPI_FIRSTBIT_LSB:�����λ����ǰ��
  * ����  �ޡ�
  */
void SPI_Data_Direction_Config(SPI_SFRmap* SPIx,uint32_t DataDirection)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_SPI_FIRST_BIT(DataDirection));

    /*---------------- ����SPI_CTLR�Ĵ���SPIDSλ ----------------*/
    if (DataDirection != SPI_FIRSTBIT_LSB)
    {
        /* MSB�����λ����ǰ */
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_SPIDS_POS);
    }
    else
    {
        /* LSB�����λ����ǰ */
        SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_SPIDS_POS);
    }
}

/**
  * ����  SPI�Ӷ�ѡ��λ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       Select: SPT�Ӷ�ѡ��λ��ȡֵΪ��
  *                   SPI_PIN_SS0:ѡ��SS0������Ϊ�Ӷ�ѡ���ź�,
  *                   SPI_PIN_SS1:ѡ��SS1������Ϊ�Ӷ�ѡ���ź�,
  *                   SPI_PIN_SS2:ѡ��SS2������Ϊ�Ӷ�ѡ���ź�,
  *                   SPI_PIN_SS3:ѡ��SS3������Ϊ�Ӷ�ѡ���źš�
  * ����  �ޡ�
  */
void SPI_Slave_PIN_Config (SPI_SFRmap* SPIx,uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_SPI_SALVE_PIN(Select));

    /*---------------- ����SPI_CTLR�Ĵ���SSELλ ----------------*/
    SPIx->CTLR = SFR_Config(SPIx->CTLR, ~SPI_CTLR_SSEL, Select);
}

/**
  * ����  ����SPI�˿�����ģʽ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       Mode: SPIʱ�Ӽ��ԣ�ȡֵΪ��
  *                   SPI_SDO_SDI:�������ӣ�SDO/SDI�� ��ʽ
  *                   SPI_MOSI_MISO:ֱ�����ӣ�MOSI/MISO�� ��ʽ��
  * ����  �ޡ�
  */
void SPI_Port_Connection_Mode (SPI_SFRmap* SPIx,uint32_t Mode)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_SPI_PORT_MODE(Mode));

    /*---------------- ����SPI_CTLR�Ĵ���SPIIOSλ ----------------*/
    SPIx->CTLR = SFR_Config(SPIx->CTLR, ~SPI_CTLR_SPIIOS, Mode);
}

/**
  * ����  ����SPIʱ�Ӽ���ѡ��λ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       Polarity: SPIʱ�Ӽ��ԣ�ȡֵΪ��
  *                   SPI_CKP_LOW:����״̬ʱ��ʱ��Ϊ�͵�ƽ��
  *                   SPI_CKP_HIGH:����״̬ʱ��ʱ��Ϊ�ߵ�ƽ��
  * ����  �ޡ�
  */
void SPI_Clock_Polarity_Config (SPI_SFRmap* SPIx,uint32_t Polarity)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_SPI_CKP(Polarity));

    /*---------------- ����SPI_CTLR�Ĵ���SPICKPλ ----------------*/
    if (Polarity != SPI_CKP_LOW)
    {
        /* ����״̬ʱ��ʱ��Ϊ�ߵ�ƽ */
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_SPICKP_POS);
    }
    else
    {
        /* ����״̬ʱ��ʱ��Ϊ�͵�ƽ */
        SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_SPICKP_POS);
    }
}

/**
  * ����  ����SPIʱ�ӱ���ѡ��λ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       ClockEdge: SPIʱ�ӱ��أ�ȡֵΪ��
  *                    SPI_CKE_2EDGE:�ڵ�2��ʱ���أ������������½����������ݣ�
  *                    SPI_CKE_1EDGE:�ڵ�1��ʱ���أ������������½����������ݡ�
  * ����  �ޡ�
  */
void SPI_Clock_Edge_Config (SPI_SFRmap* SPIx,uint32_t ClockEdge)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_SPI_CKE(ClockEdge));

    /*---------------- ����SPI_CTLR�Ĵ���SPICKEλ ----------------*/
    if (ClockEdge != SPI_CKE_1EDGE)
    {
        /* �ڵ�2��ʱ���أ������������½����������� */
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_SPICKE_POS);
    }
    else
    {
        /* �ڵ�1��ʱ���أ������������½����������� */
        SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_SPICKE_POS);
    }
}

/**
  * ����  ����SPIλģʽѡ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       DataSize: ģʽѡ��ȡֵ��ΧΪ��
  *                   SPI_DATASIZE_8BITS  :SPIʹ��8λģʽ����֧��I2Sģʽ��
  *                   SPI_DATASIZE_16BITS :SPIʹ��16λģʽ
  *                   SPI_DATASIZE_32BITS :SPIʹ��32λģʽ
  * ����  �ޡ�
  */
void SPI_BIT_SELECT_Config(SPI_SFRmap* SPIx,uint32_t DataSize)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_SPI_DATASIZE(DataSize));

    /*---------------- ����SPI_CTLR�Ĵ���SPIBSλ ----------------*/
    SPIx->CTLR = SFR_Config (SPIx->CTLR, ~SPI_CTLR_SPIBS, DataSize);
}

/**
  * ����  ����I2Sģʽ���á�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       Mode: ģʽѡ��ȡֵ��ΧΪ��
  *               I2S_MODE_SLAVE_TX   :���豸����ģʽ
  *               I2S_MODE_SLAVE_RX   :���豸����ģʽ
  *               I2S_MODE_MASTER_TX  :���豸����ģʽ
  *               I2S_MODE_MASTER_RX  :���豸����ģʽ
  * ����  �ޡ�
  */
void SPI_I2S_MODE_Config (SPI_SFRmap* SPIx,uint32_t Mode)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_I2S_MODE(Mode));

    /*---------------- ����SPI_CTLR�Ĵ���I2SMCλ ----------------*/
    SPIx->CTLR = SFR_Config (SPIx->CTLR, ~SPI_CTLR_I2SMC, Mode);
}

/**
  * ����  ����I2S��׼ѡ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       Standard: ģʽѡ��ȡֵ��ΧΪ��
  *                   I2S_STANDARD_PHILLIPS :I2S�����ֱ�׼
  *                   I2S_STANDARD_MSB      :���ֽڶ����׼���Ҷ��룩
  *                   I2S_STANDARD_LSB      :���ֽڶ����׼������룩
  *                   I2S_STANDARD_PCM      :PCM��׼
  * ����  �ޡ�
  */
void SPI_I2S_STANDARD_Config(SPI_SFRmap* SPIx,uint32_t Standard)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_I2S_STANDARD(Standard));

    /*---------------- ����SPI_CTLR�Ĵ���I2SSSλ ----------------*/
    SPIx->CTLR = SFR_Config (SPIx->CTLR, ~SPI_CTLR_I2SSS, Standard);
}

/**
  * ����  ����I2S PCM֡ͬ����
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: PCM֡ͬ�����ã�ȡֵΪ��
  *                   I2S_PCM_LONG: ��֡ͬ����
  *                   I2S_PCM_SHORT:��֡ͬ����
  * ����  �ޡ�
  */
void SPI_PCM_Config (SPI_SFRmap* SPIx,uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_I2S_PCM(NewState));

    /*---------------- ����SPI_CTLR�Ĵ���PCMSλ ----------------*/
    if (NewState != I2S_PCM_SHORT)
    {
        /* ��֡ͬ��*/
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_PCMS_POS);
    }
    else
    {
        /*��֡ͬ��*/
        SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_PCMS_POS);
    }
}

/**
  * ����  ����I2S ģʽ��ʱ�ӷ�Ƶѡ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: ʱ�ӷ�Ƶ���ã�ȡֵΪ��
  *                   I2S_CLK_BAUDRATE:���������ʣ�
  *                   I2S_CLK_BAUDRATEDIV2:����������/2��
  * ����  �ޡ�
  */
void SPI_CHLEN_Config (SPI_SFRmap* SPIx,uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_I2S_CLK(NewState));

    /*---------------- ����SPI_CTLR�Ĵ���CHLENλ ----------------*/
    if (NewState == I2S_CLK_BAUDRATEDIV8)
    {
        /* ����������/8*/
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_I2SCKS0_POS);
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_I2SCKS1_POS);
    }
    else if(NewState == I2S_CLK_BAUDRATEDIV4)
    {
        /*����������/4*/
        SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_I2SCKS0_POS);
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_I2SCKS1_POS);
    }
    else
    {
    	/* ����������*/
    	SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_I2SCKS0_POS);
    	SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_I2SCKS1_POS);
    }
}

/**
  * ����  �������豸ʱ�����ʹ�ܡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: ���豸ʱ�����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void SPI_MAIN_CLOCK_OUT_Enable (SPI_SFRmap* SPIx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SPI_BRGR�Ĵ���MCKENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��MCK���*/
        SFR_SET_BIT_ASM(SPIx->BRGR, SPI_BRGR_MCKEN_POS);
    }
    else
    {
        /*δʹ��MCK���*/
        SFR_CLR_BIT_ASM(SPIx->BRGR, SPI_BRGR_MCKEN_POS);
    }
}

/**
  * ����  I2S����ʱ MCK ���ģʽѡ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: TRUE����ֹ���ģʽ�� ����ʱ MCK ��ֹ
  *       			FALSE���������ģʽ�� ����ʱ MCK �����
  * ����  �ޡ�
  */
void SPI_I2S_Idle_MCK_Outpue_Select(SPI_SFRmap* SPIx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SPI_CTLR�Ĵ���MCKOSλ ----------------*/
    if (NewState != FALSE)
    {
        /* �������ģʽ */
        SFR_SET_BIT_ASM(SPIx->CTLR, SPI_CTLR_MCKOS_POS);
    }
    else
    {
        /* ��ֹ���ģʽ */
        SFR_CLR_BIT_ASM(SPIx->CTLR, SPI_CTLR_MCKOS_POS);
    }
}


/**
  *   ##### ��������ӿ�(SPI)���ú���������� #####
  */


/**
  *   ##### ��������ӿ�(SPI)�жϹ����� #####
  */
/**
  * ����  ����SPI��������ж�ʹ�ܡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: SPI��������ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void SPI_Receive_Overflow_INT_Enable (SPI_SFRmap* SPIx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SPI_STR�Ĵ���ROVFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��SPI��������ж� */
        SFR_SET_BIT_ASM(SPIx->STR, SPI_STR_ROVFIE_POS);
    }
    else
    {
        /* ��ֹSPI��������ж� */
        SFR_CLR_BIT_ASM(SPIx->STR, SPI_STR_ROVFIE_POS);
    }
}

/**
  * ����  ����SPI��������ж�ʹ�ܡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: SPI��������ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void SPI_Transmit_Overflow_INT_Enable (SPI_SFRmap* SPIx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SPI_STR�Ĵ���TOVFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��SPI��������ж� */
        SFR_SET_BIT_ASM(SPIx->STR, SPI_STR_TOVFIE_POS);
    }
    else
    {
        /* ��ֹSPI��������ж� */
        SFR_CLR_BIT_ASM(SPIx->STR, SPI_STR_TOVFIE_POS);
    }
}

/**
  * ����  ����SPI RBUF��Ϊ���ж�ʹ�ܡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: SPI RBUF��Ϊ���ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void SPI_RNEIE_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SPI_STR�Ĵ���RNEIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��SPI RBUF��Ϊ���ж� */
        SFR_SET_BIT_ASM(SPIx->STR, SPI_STR_RNEIE_POS);
    }
    else
    {
        /* ��ֹSPI RBUF��Ϊ���ж� */
        SFR_CLR_BIT_ASM(SPIx->STR, SPI_STR_RNEIE_POS);
    }
}

/**
  * ����  ����SPI TBUFΪ���ж�ʹ�ܡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: SPI TBUFΪ���ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void SPI_TNEIE_INT_Enable (SPI_SFRmap* SPIx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SPI_STR�Ĵ���TNEIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��SPI TBUFΪ���ж� */
        SFR_SET_BIT_ASM(SPIx->STR, SPI_STR_TNEIE_POS);
    }
    else
    {
        /* ��ֹSPI TBUFΪ���ж� */
        SFR_CLR_BIT_ASM(SPIx->STR, SPI_STR_TNEIE_POS);
    }
}

/**
  * ����  ����SPI����DMA�ж�ʹ�ܡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: SPI����DMA�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void SPI_Receive_DMA_INT_Enable (SPI_SFRmap* SPIx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SPI_STR�Ĵ���SRCDEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��SPI����DMA�ж� */
        SFR_SET_BIT_ASM(SPIx->STR, SPI_STR_SRCDE_POS);
    }
    else
    {
        /* ��ֹSPI����DMA�ж� */
        SFR_CLR_BIT_ASM(SPIx->STR, SPI_STR_SRCDE_POS);
    }
}

/**
  * ����  ����SPI����DMA�ж�ʹ�ܡ�
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: SPI����DMA�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void SPI_Transmit_DMA_INT_Enable (SPI_SFRmap* SPIx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SPI_STR�Ĵ���STXDEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��SPI����DMA�ж� */
        SFR_SET_BIT_ASM(SPIx->STR, SPI_STR_STXDE_POS);
    }
    else
    {
        /* ��ֹSPI����DMA�ж� */
        SFR_CLR_BIT_ASM(SPIx->STR, SPI_STR_STXDE_POS);
    }
}

/**
  * ����  ����SPI��������ѡ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  *       NewState: SPI��������ѡ��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void SPI_Transmit_CHSIDE_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SPI_STR�Ĵ���CHSIDEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ڷ��͵��������� */
        SFR_SET_BIT_ASM(SPIx->STR, SPI_STR_CHSIDE_POS);
    }
    else
    {
        /* ���ڷ��͵��������� */
        SFR_CLR_BIT_ASM(SPIx->STR, SPI_STR_CHSIDE_POS);
    }
}

/**
  * ����  ��ȡSPIæ״̬ ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  1: SPI���ڷ������ݣ�
  *       0: SPIû���ڷ������ݡ�
  */
FlagStatus SPI_Get_BUSY_Flag (SPI_SFRmap* SPIx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*---------------- ��ȡSPI_STR�Ĵ���SPIBUSYλ ----------------*/
    if ((SPIx->STR) & SPI_STR_SPIBUSY)
    {
        /* SPI���ڷ������� */
        return SET;
    }
    else
    {
        /* SPIû���ڷ������� */
        return RESET;
    }
}

/**
  * ����  ��ȡSPI��������жϱ�־״̬ ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  1: SPI���������
  *       0: SPIû�н��������
  */
FlagStatus SPI_Get_Receive_Overflow_Flag (SPI_SFRmap* SPIx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*---------------- ��ȡSPI_STR�Ĵ���ROVFIFλ ----------------*/
    if (SPIx->STR & SPI_STR_ROVFIF)
    {
        /* SPI������� */
        return SET;
    }
    else
    {
        /* SPIû�н������ */
        return RESET;
    }
}

/**
  * ����  ��ȡSPI�������������־״̬ ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  1: SPI�������������
  *       0: SPIû�в������������
  */
FlagStatus SPI_Get_Transmit_Overflow_Flag (SPI_SFRmap* SPIx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*---------------- ��ȡSPI_STR�Ĵ���TOVFIFλ ----------------*/
    if (SPIx->STR & SPI_STR_TOVFIF)
    {
        /* SPI����������� */
        return SET;
    }
    else
    {
        /* SPIû�в���������� */
        return RESET;
    }
}

/**
  * ����  ��ȡSPI����BUFδ��״̬ ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  1: SPI����BUF��Ϊ�գ�
  *       0: SPI����BUFΪ�ա�
  */
FlagStatus SPI_Get_Receive_Buf_Flag (SPI_SFRmap* SPIx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*---------------- ��ȡSPI_STR�Ĵ���RNEλ ----------------*/
    if (SPIx->STR & SPI_STR_RNE)
    {
        /* SPI����BUF��Ϊ�� */
        return SET;
    }
    else
    {
        /* SPI����BUFΪ�� */
        return RESET;
    }
}

/**
  * ����  ��ȡSPI����BUFδ��״̬ ��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  1: SPI����BUF��Ϊ�գ�
  *       0: SPI����BUFΪ�ա�
  */
FlagStatus SPI_Get_Transmit_Buf_Flag (SPI_SFRmap* SPIx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*---------------- ��ȡSPI_STR�Ĵ���TNEλ ----------------*/
    if (SPIx->STR & SPI_STR_TNE)
    {
        /* SPI����BUF��Ϊ�� */
        return SET;
    }
    else
    {
        /* SPI����BUFΪ�� */
        return RESET;
    }
}

/**
  * ����  ����SPI��������жϱ�־��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  :���SPI��������жϱ�־�Ƿ�ɹ�״̬��
  */
RetStatus SPI_Clear_Receive_Overflow_INT_Flag (SPI_SFRmap* SPIx)
{
	uint32_t wait_flag=0x0000;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*---------------- ����SPI_STR�Ĵ���ROVFICλ ----------------*/
    SFR_SET_BIT_ASM(SPIx->STR, SPI_STR_ROVFIC_POS);
    while((SPIx->STR & SPI_STR_ROVFIF)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(SPIx->STR, SPI_STR_ROVFIC_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * ����  ����SPI��������жϱ�־��
  * ����  SPIx: ָ��SPI�ڴ�ṹ��ָ�룬ȡֵΪSPI0_SFR~SPI3_SFR��
  * ����  :���SPI��������жϱ�־�Ƿ�ɹ�״̬��
  */
RetStatus SPI_Clear_Transmit_Overflow_INT_Flag (SPI_SFRmap* SPIx)
{
	uint32_t wait_flag=0x0000;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPI_ALL_PERIPH(SPIx));

    /*---------------- ����SPI_STR�Ĵ���TOVFICλ ----------------*/
    SFR_SET_BIT_ASM(SPIx->STR, SPI_STR_TOVFIC_POS);
    while((SPIx->STR & SPI_STR_TOVFIF)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(SPIx->STR, SPI_STR_TOVFIC_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  *   ##### ��������ӿ�(SPI)�жϹ������������ #####
  */


