/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_dac.c                                 	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the DAC peripherals function, 	  *
 *  					including:											  *
 *          			+ Initialization and configuration functions          *
 *          			+ Data read-write function                            *
 *          			+ DAC checksum register configuration function		  *
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

#include "kf32a1x6_dac.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/*******************************************************************************
**                   (DAC) module Private Macro Definitions                   **
*******************************************************************************/

/* DAC˽�ж��� ----------------------------------------------------*/
/* DACx_CTL�Ĵ����������� */
#define DAC_CTL_INIT_MASK               (DAC_CTL_TRIGEN \
                                       | DAC_CTL_TREVT \
                                       | DAC_CTL_DE \
                                       | DAC_CTL_WAVE \
                                       | DAC_CTL_MAS)

/* DACx_CTL�Ĵ����������� */
#define DAC_CTL1_INIT_MASK              (DAC_CTL1_CLK \
                                       | DAC_CTL1_RFS \
                                       | DAC_CTL1_BUFEN \
                                       | DAC_CTL1_SEL)


/**
  *   ##### ��ʼ�������ú��� #####
  */
/**
  * ����  DAC���踴λ��ʹ������ʱ�ӡ�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  * ����  �ޡ�
  */
void DAC_Reset (DAC_SFRmap* DACx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));

    if (DACx == DAC0_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_DAC0RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_DAC0RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_DAC0CLKEN, TRUE);
    }
    else if (DACx == DAC1_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_DAC1RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_DAC1RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_DAC1CLKEN, TRUE);
    }
    else if (DACx == DAC2_SFR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_DAC2RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_DAC2RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_DAC2CLKEN, TRUE);
    }
    else if (DACx == DAC3_SFR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_DAC3RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_DAC3RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_DAC3CLKEN, TRUE);
    }
    else
    {
    	;
    }
}

/**
  * ����  DAC�������á�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       dacInitStruct: DAC������Ϣ
  * ����  �ޡ�
  */
void DAC_Configuration (DAC_SFRmap* DACx, DAC_InitTypeDef* dacInitStruct)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(dacInitStruct->m_TriggerEnable));
    CHECK_RESTRICTION(CHECK_DAC_TRIGGER_EVENT(dacInitStruct->m_TriggerEvent));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(dacInitStruct->m_TriggerDMAEnable));
    CHECK_RESTRICTION(CHECK_DAC_WAVE(dacInitStruct->m_Wave));
    CHECK_RESTRICTION(CHECK_DAC_MAS(dacInitStruct->m_Mas));
    CHECK_RESTRICTION(CHECK_DAC_CLK(dacInitStruct->m_Clock));
    CHECK_RESTRICTION(CHECK_DAC_CLK_DIV(dacInitStruct->m_ClockDiv));
    CHECK_RESTRICTION(CHECK_DAC_RFS(dacInitStruct->m_ReferenceVoltage));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(dacInitStruct->m_OutputBuffer));
    CHECK_RESTRICTION(CHECK_DAC_OUTPUT_PIN(dacInitStruct->m_OutputPin));
    CHECK_RESTRICTION(CHECK_DAC_OUTPUT(dacInitStruct->m_Output));

    /*---------------------------- DACx_CTL�Ĵ�������  -----------------*/
    /* ���ݽṹ���Աm_TriggerEnable������TRIGENλ�� */
    /* ���ݽṹ���Աm_TriggerEvent������TREVTλ�� */
    /* ���ݽṹ���Աm_TriggerDMAEnable������DEλ�� */
    /* ���ݽṹ���Աm_Wave������WAVEλ�� */
    /* ���ݽṹ���Աm_Mas������MASλ�� */
    tmpreg = ((dacInitStruct->m_TriggerEnable << DAC_CTL_TRIGEN_POS) | \
              (dacInitStruct->m_TriggerEvent) | \
              (dacInitStruct->m_TriggerDMAEnable << DAC_CTL_DE_POS) | \
              (dacInitStruct->m_Wave) | \
              (dacInitStruct->m_Mas));
    DACx->CTL = SFR_Config (DACx->CTL, ~DAC_CTL_INIT_MASK, tmpreg);

    /*---------------------------- DACx_CTL1�Ĵ������� -----------------*/
    /* ���ݽṹ���Աm_ClockDiv������CLKDIVλ�� */
    /* ���ݽṹ���Աm_Clock������CLKλ�� */
    /* ���ݽṹ���Աm_ReferenceVoltage������RFSλ�� */
    /* ���ݽṹ���Աm_OutputBuffer������BUFENλ�� */
    /* ���ݽṹ���Աm_OutputPin������SELλ�� */
    tmpreg = (dacInitStruct->m_ClockDiv)\
    	   | (dacInitStruct->m_Clock) \
           | (dacInitStruct->m_ReferenceVoltage) \
           | (dacInitStruct->m_OutputBuffer << DAC_CTL1_BUFEN_POS) \
           | (dacInitStruct->m_OutputPin);
    DACx->CTL1 = SFR_Config (DACx->CTL1, ~DAC_CTL1_INIT_MASK, tmpreg);

    /*---------------------------- DACx_DAHD�Ĵ������� -----------------*/
    /* ���ݽṹ���Աm_Output������DAHDλ�� */
    tmpreg = dacInitStruct->m_Output;
    DACx->DAHD = SFR_Config (DACx->DAHD, ~DAC_DAHD_DAHD, tmpreg);
}

/**
  * ����  ��ʼ��DAC������Ϣ�ṹ�塣
  * ����  dacInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void DAC_Struct_Init (DAC_InitTypeDef* dacInitStruct)
{
    /* ��ʼ�� DACͨ������ʹ�� */
    dacInitStruct->m_TriggerEnable = FALSE;
    /* ��ʼ�� DACͨ�������¼� */
    dacInitStruct->m_TriggerEvent = DAC_TRIGGER_T1_TRGO;
    /* ��ʼ�� DAC����DMAʹ�� */
    dacInitStruct->m_TriggerDMAEnable = FALSE;
    /* ��ʼ�� DAC���η�����ʹ�� */
    dacInitStruct->m_Wave = DAC_WAVE_NONE;
    /* ��ʼ�� DAC����/��ֵѡ���� */
    dacInitStruct->m_Mas = DAC_LFSR_UNMASK_BITS0_0;
    /* ��ʼ�� DAC����ʱ�� */
    dacInitStruct->m_Clock = DAC_CLK_SCLK;
    /* ��ʼ�� DACʱ�ӷ�Ƶ */
    dacInitStruct->m_ClockDiv = DAC_CLK_DIV_1;
    /* ��ʼ�� DAC�ο���ѹѡ�� */
    dacInitStruct->m_ReferenceVoltage = DAC_RFS_AVDD;
    /* ��ʼ�� DAC�������ʹ�� */
    dacInitStruct->m_OutputBuffer = FALSE;
    /* ��ʼ�� DAC������� */
    dacInitStruct->m_OutputPin = DAC_OUTPUT_PIN_0;
    /* ��ʼ�� DAC������� */
    dacInitStruct->m_Output = 0;
}

/**
  * ����  ����DACʹ��λ��
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       NewState: DACʹ��λ������Ϣ��
  *                 ȡֵΪ TRUE �� FALSE��
  * ����  �ޡ�
  */
void DAC_Cmd (DAC_SFRmap* DACx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ʹ��DAC */
        SFR_SET_BIT_ASM(DACx->CTL, DAC_CTL_EN_POS);
    }
    else
    {
        /* ��ֹDAC */
        SFR_CLR_BIT_ASM(DACx->CTL, DAC_CTL_EN_POS);
    }
}

/**
  * ����  ����DACʹ��λ��
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       NewState: DACʹ��λ������Ϣ��
  *                 ȡֵΪ TRUE �� FALSE��
  * ����  �ޡ�
  */
void DAC_Software_Trigger_Cmd (DAC_SFRmap* DACx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ʹ��DAC������� */
        SFR_SET_BIT_ASM(DACx->CTL, DAC_CTL_SWTRIG_POS);
    }
    else
    {
        /* ��ֹDAC������� */
        SFR_CLR_BIT_ASM(DACx->CTL, DAC_CTL_SWTRIG_POS);
    }
}

/**
  * ����  ����DACͨ��DMAģʽʹ�ܡ�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       NewState: DACʹ��λ������Ϣ��
  *                 ȡֵΪ TRUE �� FALSE��
  * ����  �ޡ�
  */
void DAC_DMA_Cmd (DAC_SFRmap* DACx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ʹ��DACͨ��DMAģʽ */
        SFR_SET_BIT_ASM(DACx->CTL, DAC_CTL_DE_POS);
    }
    else
    {
        /* ��ֹDACͨ��DMAģʽ */
        SFR_CLR_BIT_ASM(DACx->CTL, DAC_CTL_DE_POS);
    }
}

/**
  * ����  ����DAC�������ʹ�ܡ�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       NewState: DACʹ��λ������Ϣ��
  *                 ȡֵΪ TRUE �� FALSE���ֱ��ʾ���������򲻴����塣
  * ����  �ޡ�
  */
void DAC_Output_Buffer_Config (DAC_SFRmap* DACx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ʹ��DAC������� */
        SFR_SET_BIT_ASM(DACx->CTL1, DAC_CTL1_BUFEN_POS);
    }
    else
    {
        /* ��ֹDAC������� */
        SFR_CLR_BIT_ASM(DACx->CTL1, DAC_CTL1_BUFEN_POS);
    }
}

/**
  * ����  ����DAC���IO��ѡ��
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       NewState: DACʹ��λ������Ϣ��
  *                 ȡֵΪ TRUE �� FALSE���ֱ��ʾ�����IO��1���������IO��0��
  * ����  �ޡ�
  */
void DAC_Output_Port_Config (DAC_SFRmap* DACx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* DAC�����IO��1 */
        SFR_SET_BIT_ASM(DACx->CTL1, DAC_CTL1_SEL_POS);
    }
    else
    {
        /* DAC�����IO��0 */
        SFR_CLR_BIT_ASM(DACx->CTL1, DAC_CTL1_SEL_POS);
    }
}

/**
  *   ##### ��ʼ�������ú������� #####
  */



/**
  *   ##### ���ݶ�д���� #####
  */
/**
  * ����  дDAC������ݣ�ֻ��д��DACx_DAHD�Ĵ�����
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       Value: д�����ݼĴ�����ֵ��
  *              ȡֵΪ12λ���ݡ�
  * ����  �ޡ�
  */
void DAC_Write_Output_Data (DAC_SFRmap* DACx, uint32_t Value)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_DAC_OUTPUT(Value));

    DACx->DAHD = Value;
}

/**
  * ����  ��DAC������ݡ�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  * ����  32λ�������ݵ�12λ���ݡ�
  */
uint32_t DAC_Read_Output_Data (DAC_SFRmap* DACx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));

    return (DAC_DAHD_DAHD & DACx->DATA);
}

/**
  *   ##### ���ݶ�д�������� #####
  */



/**
  *   ##### DACУ��Ĵ������ú��� #####
  */

/**
  * ����  P��У׼����
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       Direction: DAC_Positive	DAC����У׼
  *       			 DAC_Negetive	DAC����У׼
  * ����  �ޡ�
  */
void DAC_PCalibration_Direction_Config (DAC_SFRmap* DACx, uint32_t Direction)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_DAC_CAL_DIRECTION(Direction));

    tmpreg = Direction << DAC_CAL_TRIMPPOL_POS;
    DACx->CAL = SFR_Config (DACx->CAL, ~DAC_CAL_TRIMPPOL, tmpreg);
}

/**
  * ����  P��У׼��λ���á�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       Value:  Value <= 0x3F
  * ����  �ޡ�
  */
void DAC_PCalibration_Value_Config (DAC_SFRmap* DACx, uint32_t Value)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_DAC_TRIMP(Value));

    tmpreg = Value << DAC_CAL_TRIMP0_POS;
    DACx->CAL = SFR_Config (DACx->CAL, ~DAC_CAL_TRIMP, tmpreg);
}

/**
  * ����  P��У׼��λ��ȡ��
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  * ����  P��У׼��λ��ǰֵ��
  */
uint16_t DAC_PCalibration_Value_Read (DAC_SFRmap* DACx)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));

    return((DACx->CAL && DAC_CAL_TRIMP) >> DAC_CAL_TRIMP0_POS);
}

/**
  * ����  N��У׼����
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       Direction: DAC_Positive	DAC����У׼
  *       			 DAC_Negetive	DAC����У׼
  * ����  �ޡ�
  */
void DAC_NCalibration_Direction_Config (DAC_SFRmap* DACx, uint32_t Direction)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_DAC_CAL_DIRECTION(Direction));

    tmpreg = Direction << DAC_CAL_TRIMNPOL_POS;
    DACx->CAL = SFR_Config (DACx->CAL, ~DAC_CAL_TRIMNPOL, tmpreg);
}

/**
  * ����  N��У׼��λ���á�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  *       Value:  Value <= 0x3F
  * ����  �ޡ�
  */
void DAC_NCalibration_Value_Config (DAC_SFRmap* DACx, uint32_t Value)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_DAC_TRIMP(Value));

    tmpreg = Value << DAC_CAL_TRIMN0_POS;
    DACx->CAL = SFR_Config (DACx->CAL, ~DAC_CAL_TRIMN, tmpreg);
}

/**
  * ����  N��У׼��λ��ȡ��
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  * ����  P��У׼��λ��ǰֵ��
  */
uint16_t DAC_NCalibration_Value_Read (DAC_SFRmap* DACx)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));

    return((DACx->CAL && DAC_CAL_TRIMN) >> DAC_CAL_TRIMN0_POS);
}

/**
  * ����  У׼״̬λ��ȡ��
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  * ����  У׼״̬λ��ǰֵ��
  */
uint8_t DAC_TRIM_STATE_Value_Read (DAC_SFRmap* DACx)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));

    return((DACx->CAL && DAC_CAL_TRIMSTATE) >> DAC_CAL_TRIMSTATE_POS);
}

/**
  * ����  У׼�߹�ģʹ�ܡ�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  * 	 NewState: TRUE ʹ��
  * 	 		   FALSE ��ֹ
  * ����  �ޡ�
  */
void DAC_TRIMHI_Enable(DAC_SFRmap* DACx, FunctionalState NewState)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    tmpreg = NewState << DAC_CAL_TRIMHI_POS;
    DACx->CAL = SFR_Config(DACx->CAL, ~DAC_CAL_TRIMHI, tmpreg);
}

/**
  * ����  У׼�͹�ģʹ�ܡ�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  * 	 NewState: TRUE ʹ��
  * 	 		   FALSE ��ֹ
  * ����  �ޡ�
  */
void DAC_TRIMLO_Enable(DAC_SFRmap* DACx, FunctionalState NewState)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    tmpreg = NewState << DAC_CAL_TRIMLO_POS;
    DACx->CAL = SFR_Config(DACx->CAL, ~DAC_CAL_TRIMLO, tmpreg);
}

/**
  * ����  ��������������ơ�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  * 	 TestGroup: DAC_TEST_GROUP1 �������������һ��
  * 	 			DAC_TEST_GROUP2 ������������ڶ���
  * 	 			DAC_TEST_GROUP3 �����������������
  * 	 			DAC_TEST_GROUP4 �����������������
  * ����  �ޡ�
  */
void DAC_Test_Group_Config(DAC_SFRmap* DACx, uint32_t TestGroup)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_DAC_TEST_GROUP(TestGroup));

    tmpreg = TestGroup << DAC_CAL_TP0_POS;
    DACx->CAL = SFR_Config(DACx->CAL, ~DAC_CAL_TP, tmpreg);
}

/**
  * ����  �����������ʹ�ܡ�
  * ����  DACx: ָ��DAC�ڴ�ṹ��ָ�룬ȡֵΪDAC0_SFR��DAC1_SFR��DAC2_SFR��DAC3_SFR��
  * 	 NewState��TRUE ʹ�ܲ����������
  * 	 		   FALSE ��ֹ�����������
  * ����  �ޡ�
  */
void DAC_Test_Group_Enable(DAC_SFRmap* DACx, FunctionalState NewState)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DAC_ALL_PERIPH(DACx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    tmpreg = NewState << DAC_CAL_TPEN_POS;
    DACx->CAL = SFR_Config(DACx->CAL, ~DAC_CAL_TPEN, tmpreg);
}


/**
  *   ##### DACУ��Ĵ������ú������� #####
  */



