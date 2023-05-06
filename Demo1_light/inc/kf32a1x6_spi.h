/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_spi.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the SPI			  *
 *						peripherals.										  *
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
 *  										                                  *
 *                                                                            *
 *                                                                            *
 *****************************************************************************/
#ifndef KF32A1x6_SPI_H_
#define KF32A1x6_SPI_H_

#include "kf32a1x6.h"


/* SPI�����ж� ------------------------------------------------------------*/
#define CHECK_SPI_ALL_PERIPH(PERIPH)    (((PERIPH) == SPI0_SFR) \
                                      || ((PERIPH) == SPI1_SFR) \
                                      || ((PERIPH) == SPI2_SFR) \
                                      || ((PERIPH) == SPI3_SFR))


/**
  * ����  ��������ӿ�(SPI)SPIЭ����Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_Mode;                 /* SPIģʽѡ��
                                        ȡֵΪ�ꡰSPIģʽ���е�һ���� */
    uint32_t m_Clock;                /* SPI����ʱ��ѡ��Ĵ�����
                                        ȡֵΪ�ꡰSPI����ʱ�ӡ��е�һ���� */
    uint32_t m_FirstBit;             /* SPI���ݷ���ѡ��λ.
                                        ȡֵΪ�ꡰSPI���ݷ����е�һ���� */
    uint32_t m_CKP;                  /* ʱ�Ӽ���ѡ��λ.
                                        ȡֵΪ�ꡰSPIʱ�Ӽ��ԡ��е�һ���� */
    uint32_t m_CKE;                  /* SPIʱ�ӱ���ѡ��λ.
                                        ȡֵΪ�ꡰSPIʱ�ӱ��ء��е�һ���� */
    uint32_t m_DataSize;             /* SPIλģʽѡ��
                                        ȡֵΪ�ꡰSPIλģʽ���е�һ���� */
    uint16_t m_BaudRate;             /* SPI������ѡ��
                                        ȡֵΪ0~0xFFFF�� */
}SPI_InitTypeDef;

/**
  * ����  ��������ӿ�(SPI)I2SЭ����Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_Mode;                 /* I2Sģʽѡ��
                                        ȡֵΪ�ꡰI2Sģʽ���е�һ���� */
    uint32_t m_Standard;             /* I2S��׼ѡ��
                                        ȡֵΪ�ꡰI2S��׼���е�һ����  */
    uint32_t m_PCM;                  /* PCM֡ͬ����
                                        ȡֵΪ�ꡰPCM֡ͬ�����е�һ���� */
    uint32_t m_Clock;                /* I2Sģʽ��ʱ�ӷ�Ƶѡ��
                                        ȡֵΪ�ꡰI2Sģʽ��ʱ�ӷ�Ƶ���е�һ���� */
    uint8_t m_Prescaler;             /* I2SԤ��Ƶ��
                                        ȡֵΪ0~0xFF�� */
}I2S_InitTypeDef;

/**
  * SPIģʽ
  */
#define SPI_MODE_MASTER_CLKDIV4         ((uint32_t)0<<SPI_CTLR_SPIMS0_POS)
#define SPI_MODE_MASTER_CLKDIV16        ((uint32_t)1<<SPI_CTLR_SPIMS0_POS)
#define SPI_MODE_MASTER_CLKDIV64        ((uint32_t)2<<SPI_CTLR_SPIMS0_POS)
#define SPI_MODE_MASTER_T2DIV2          ((uint32_t)3<<SPI_CTLR_SPIMS0_POS)
#define SPI_MODE_SLAVE                  ((uint32_t)4<<SPI_CTLR_SPIMS0_POS)
#define CHECK_SPI_MODE(MODE)            (((MODE) == SPI_MODE_MASTER_CLKDIV4) \
                                      || ((MODE) == SPI_MODE_MASTER_CLKDIV16) \
                                      || ((MODE) == SPI_MODE_MASTER_CLKDIV64) \
                                      || ((MODE) == SPI_MODE_MASTER_T2DIV2) \
                                      || ((MODE) == SPI_MODE_SLAVE))

/**
  * SPI����ʱ��
  */
#define SPI_CLK_SCLK                    ((uint32_t)0<<SPI_CTLR_SPICKS0_POS)
#define SPI_CLK_HFCLK                   ((uint32_t)1<<SPI_CTLR_SPICKS0_POS)
#define SPI_CLK_LFCLK                   ((uint32_t)2<<SPI_CTLR_SPICKS0_POS)
#define CHECK_SPI_CLK(CLK)              (((CLK) == SPI_CLK_SCLK) \
                                      || ((CLK) == SPI_CLK_HFCLK) \
                                      || ((CLK) == SPI_CLK_LFCLK))
/**
  * SPI���ݷ���ѡ��λ
  */
#define SPI_FIRSTBIT_LSB                ((uint32_t)0<<SPI_CTLR_SPIDS_POS)
#define SPI_FIRSTBIT_MSB                ((uint32_t)1<<SPI_CTLR_SPIDS_POS)
#define CHECK_SPI_FIRST_BIT(BIT)        (((BIT) == SPI_FIRSTBIT_MSB) \
                                      || ((BIT) == SPI_FIRSTBIT_LSB))

/**
 * SPI�Ӷ�����ѡ��λ
 * */
#define SPI_PIN_SS0						((uint32_t)0<<SPI_CTLR_SSEL0_POS)
#define SPI_PIN_SS1						((uint32_t)1<<SPI_CTLR_SSEL0_POS)
#define SPI_PIN_SS2						((uint32_t)2<<SPI_CTLR_SSEL0_POS)
#define SPI_PIN_SS3						((uint32_t)3<<SPI_CTLR_SSEL0_POS)
#define CHECK_SPI_SALVE_PIN(SEL)		(((SEL) == SPI_PIN_SS0) \
									  || ((SEL) == SPI_PIN_SS1) \
									  || ((SEL) == SPI_PIN_SS2) \
		  	  	  	  	  	  	  	  || ((SEL) == SPI_PIN_SS3))

/**
 * SPI�˿�����ģʽ
 * */
#define SPI_SDO_SDI						((uint32_t)0<<SPI_CTLR_SPIIOS_POS)
#define SPI_MOSI_MISO					((uint32_t)1<<SPI_CTLR_SPIIOS_POS)
#define CHECK_SPI_PORT_MODE(MODE)		(((MODE) == SPI_SDO_SDI) \
									  || ((MODE) == SPI_MOSI_MISO))
/**
  * SPIʱ�Ӽ���
  */
#define SPI_CKP_LOW                    ((uint32_t)0<<SPI_CTLR_SPICKP_POS)
#define SPI_CKP_HIGH                   ((uint32_t)1<<SPI_CTLR_SPICKP_POS)
#define CHECK_SPI_CKP(CKP)             (((CKP) == SPI_CKP_LOW) \
                                     || ((CKP) == SPI_CKP_HIGH))

/**
  * SPIʱ�ӱ���
  */
#define SPI_CKE_1EDGE                  ((uint32_t)0<<SPI_CTLR_SPICKE_POS)
#define SPI_CKE_2EDGE                  ((uint32_t)1<<SPI_CTLR_SPICKE_POS)
#define CHECK_SPI_CKE(CKE)             (((CKE) == SPI_CKE_1EDGE) \
                                     || ((CKE) == SPI_CKE_2EDGE))

/**
  * SPIλģʽ
  */
#define SPI_DATASIZE_8BITS              ((uint32_t)0<<SPI_CTLR_SPIBS0_POS)
#define SPI_DATASIZE_16BITS             ((uint32_t)1<<SPI_CTLR_SPIBS0_POS)
#define SPI_DATASIZE_32BITS             ((uint32_t)2<<SPI_CTLR_SPIBS0_POS)
#define CHECK_SPI_DATASIZE(DATASIZE)    (((DATASIZE) == SPI_DATASIZE_8BITS) \
                                      || ((DATASIZE) == SPI_DATASIZE_16BITS) \
                                      || ((DATASIZE) == SPI_DATASIZE_32BITS))

/**
  * I2Sģʽ
  */
#define I2S_MODE_SLAVE_TX               ((uint32_t)0<<SPI_CTLR_I2SMC0_POS)
#define I2S_MODE_SLAVE_RX               ((uint32_t)1<<SPI_CTLR_I2SMC0_POS)
#define I2S_MODE_MASTER_TX              ((uint32_t)2<<SPI_CTLR_I2SMC0_POS)
#define I2S_MODE_MASTER_RX              ((uint32_t)3<<SPI_CTLR_I2SMC0_POS)
#define CHECK_I2S_MODE(MODE)            (((MODE) == I2S_MODE_SLAVE_TX) \
                                      || ((MODE) == I2S_MODE_SLAVE_RX) \
                                      || ((MODE) == I2S_MODE_MASTER_TX) \
                                      || ((MODE) == I2S_MODE_MASTER_RX))

/**
  * I2S��׼
  */
#define I2S_STANDARD_PHILLIPS           ((uint32_t)0<<SPI_CTLR_I2SSS0_POS)
#define I2S_STANDARD_MSB                ((uint32_t)1<<SPI_CTLR_I2SSS0_POS)
#define I2S_STANDARD_LSB                ((uint32_t)2<<SPI_CTLR_I2SSS0_POS)
#define I2S_STANDARD_PCM                ((uint32_t)3<<SPI_CTLR_I2SSS0_POS)
#define CHECK_I2S_STANDARD(STANDARD)    (((STANDARD) == I2S_STANDARD_PHILLIPS) \
                                      || ((STANDARD) == I2S_STANDARD_MSB) \
                                      || ((STANDARD) == I2S_STANDARD_LSB) \
                                      || ((STANDARD) == I2S_STANDARD_PCM))

/**
  * PCM֡ͬ��
  */
#define I2S_PCM_SHORT                   ((uint32_t)0<<SPI_CTLR_PCMS_POS)
#define I2S_PCM_LONG                    ((uint32_t)1<<SPI_CTLR_PCMS_POS)
#define CHECK_I2S_PCM(PCM)              (((PCM) == I2S_PCM_SHORT) \
                                      || ((PCM) == I2S_PCM_LONG ))

/**
  * I2Sģʽ��ʱ�ӷ�Ƶ
  */
#define I2S_CLK_BAUDRATEDIV8            ((uint32_t)3<<SPI_CTLR_I2SCKS0_POS)
#define I2S_CLK_BAUDRATEDIV4            ((uint32_t)2<<SPI_CTLR_I2SCKS0_POS)
#define I2S_CLK_BAUDRATE                ((uint32_t)0<<SPI_CTLR_I2SCKS0_POS)
#define CHECK_I2S_CLK(CLK)              (((CLK) == I2S_CLK_BAUDRATEDIV8) \
									  || ((CLK) == I2S_CLK_BAUDRATEDIV4) \
                                      || ((CLK) == I2S_CLK_BAUDRATE ))

/**
  * SPI_I2S_�ж϶���
  */
#define SPI_I2S_IT_ROVFIE               ((uint32_t)1<<SPI_STR_ROVFIE_POS)
#define SPI_I2S_IT_TOVFIE               ((uint32_t)1<<SPI_STR_TOVFIE_POS)
#define SPI_I2S_IT_RNEIE                ((uint32_t)1<<SPI_STR_RNEIE_POS)
#define SPI_I2S_IT_TNEIE                ((uint32_t)1<<SPI_STR_TNEIE_POS)
#define SPI_I2S_IT_SRCDE                ((uint32_t)1<<SPI_STR_SRCDE_POS)
#define SPI_I2S_IT_STXDE                ((uint32_t)1<<SPI_STR_STXDE_POS)
#define CHECK_SPI_I2S_CONFIG_IT(IT)     (((IT) == SPI_I2S_IT_ROVFIE ) \
                                      || ((IT) == SPI_I2S_IT_TOVFIE) \
                                      || ((IT) == SPI_I2S_IT_RNEIE) \
                                      || ((IT) == SPI_I2S_IT_TNEIE) \
                                      || ((IT) == SPI_I2S_IT_SRCDE ) \
                                      || ((IT) == SPI_I2S_IT_STXDE))
#define CHECK_SPI_I2S_GET_IT(IT)        (((IT) == SPI_I2S_IT_ROVFIE) \
                                      || ((IT) == SPI_I2S_IT_TOVFIE) \
                                      || ((IT) == SPI_I2S_IT_RNEIE) \
                                      || ((IT) == SPI_I2S_IT_TNEIE) \
                                      || ((IT) == SPI_I2S_IT_SRCDE) \
                                      || ((IT) == SPI_I2S_IT_STXDE))

/**
  * SPI_I2S��־λ����
  */
#define SPI_I2S_FLAG_ROVFIF             ((uint32_t)1<<SPI_STR_ROVFIF_POS)
#define SPI_I2S_FLAG_TOVFIF             ((uint32_t)1<<SPI_STR_TOVFIF_POS)
#define SPI_I2S_FLAG_BSY                ((uint32_t)1<<SPI_STR_SPIBUSY_POS)
#define CHECK_SPI_I2S_GET_FLAG(FLAG)    (((FLAG) == SPI_I2S_FLAG_BSY) \
                                      || ((FLAG) == SPI_I2S_FLAG_ROVFIF) \
                                      || ((FLAG) == SPI_I2S_FLAG_TOVFIF))

/**
  * SPI������
  */
#define CHECK_SPI_BRGR(BAUDRATE)        (((uint32_t)(BAUDRATE) >> 16) == 0)

/**
  * I2SԤ��Ƶ
  */
#define CHECK_I2S_DIV(DIV)             (((uint32_t)(DIV) >> 8) == 0)


/* ��������ӿ�(SPI)��ʼ����������******************************************/
void SPI_Reset(SPI_SFRmap* SPIx);
void SPI_Configuration(SPI_SFRmap* SPIx, SPI_InitTypeDef* spiInitStruct);
void I2S_Configuration(SPI_SFRmap* SPIx, I2S_InitTypeDef* i2sInitStruct);
void SPI_Struct_Init(SPI_InitTypeDef* SPI_InitStruct);
void I2S_Struct_Init(I2S_InitTypeDef* I2S_InitStruct);

/* ��������ӿ�(SPI)���ú�������********************************************/
void SPI_Cmd (SPI_SFRmap* SPIx, FunctionalState NewState);
void I2S_Mode_Select(SPI_SFRmap* SPIx, FunctionalState NewState);
uint32_t SPI_I2S_ReceiveData(SPI_SFRmap* SPIx);
void SPI_I2S_SendData32(SPI_SFRmap* SPIx, uint32_t Data);
void SPI_I2S_SendData8(SPI_SFRmap* SPIx, uint8_t Data);
void SPI_BaudRate_Config (SPI_SFRmap* SPIx, uint16_t BAUDRATE);
void I2S_DIV_Config (SPI_SFRmap* SPIx, uint8_t DIV);
void SPI_MODE_Config (SPI_SFRmap* SPIx, uint32_t MODE);
void SPI_CLK_Config (SPI_SFRmap* SPIx, uint32_t ClockSource);
void SPI_Data_Direction_Config(SPI_SFRmap* SPIx, uint32_t DataDirection);
void SPI_Slave_PIN_Config (SPI_SFRmap* SPIx,uint32_t Select);
void SPI_Port_Connection_Mode (SPI_SFRmap* SPIx,uint32_t Mode);
void SPI_Clock_Polarity_Config (SPI_SFRmap* SPIx, uint32_t Polarity);
void SPI_Clock_Edge_Config (SPI_SFRmap* SPIx, uint32_t ClockEdge);
void SPI_BIT_SELECT_Config(SPI_SFRmap* SPIx, uint32_t DataSize);
void SPI_I2S_MODE_Config (SPI_SFRmap* SPIx, uint32_t Mode);
void SPI_I2S_STANDARD_Config(SPI_SFRmap* SPIx, uint32_t Standard);
void SPI_PCM_Config (SPI_SFRmap* SPIx, uint32_t NewState);
void SPI_CHLEN_Config (SPI_SFRmap* SPIx, uint32_t NewState);
void SPI_MAIN_CLOCK_OUT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_I2S_Idle_MCK_Outpue_Select(SPI_SFRmap* SPIx,FunctionalState NewState);
/* ��������ӿ�(SPI)�жϹ���������****************************************/
void SPI_Receive_Overflow_INT_Enable (SPI_SFRmap* SPIx,
                    FunctionalState NewState);
void SPI_Transmit_Overflow_INT_Enable (SPI_SFRmap* SPIx,
                    FunctionalState NewState);
void SPI_RNEIE_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_TNEIE_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_Receive_DMA_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_Transmit_DMA_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_Transmit_CHSIDE_INT_Enable (SPI_SFRmap* SPIx,
                    FunctionalState NewState);
FlagStatus SPI_Get_BUSY_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Receive_Overflow_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Transmit_Overflow_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Receive_Buf_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Transmit_Buf_Flag (SPI_SFRmap* SPIx);
RetStatus SPI_Clear_Receive_Overflow_INT_Flag (SPI_SFRmap* SPIx);
RetStatus SPI_Clear_Transmit_Overflow_INT_Flag (SPI_SFRmap* SPIx);


#endif /* KF32A1x6_SPI_H_ */
