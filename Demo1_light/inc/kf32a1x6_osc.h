/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_osc.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the OSC			  *
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
#ifndef KF32A1x6_OSC_H_
#define KF32A1x6_OSC_H_

#include "kf32a1x6.h"

/*** ����(OSC)��ض���  */

/**
  * ����  ����(OSC) SCLK��ʱ��������Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_InputSource;     /* ��Դѡ�񣬸��ݲ�ͬ��ʱ�ӣ�ȡֵ��ͬ��
                                   	   ȡֵ���㡰SCLK��Դѡ�񡱡���HFCK��Դѡ�񡱡���LFCK��Դѡ�񡱡�
                                   	   ��CK48M��Դѡ�񡱶����һ���� */
    uint32_t m_CLKDivision;     /* ʱ�ӷ�Ƶϵ����
                                   	   ȡֵ���㡰SCLK��Ƶϵ��������HFCK��Ƶϵ��������LFCK��Ƶϵ������
                                   ��CK48M��Ƶϵ���������һ���� */
    uint32_t m_PLLInputSource;  /* PLL����ʱ��Դѡ�񣬵���ԴΪPLLʱ��Ч��
                                   	   ȡֵΪ�ꡰPLL����ʱ��Դѡ���е�һ���� */

    uint32_t m_StartDelay;      /* PLL �� �ⲿ������ʱʱ�����ã�����ԴΪPLL���ⲿʱ��Ч��
                                   	   ȡֵΪ�ꡰPLL������ʱʱ�����á����ⲿ������ʱʱ�����á��е�һ���� */
} OSC_InitTypeDef;

/**
  * LFCK��Ƶϵ��
  */
#define LFCK_DIVISION_1                 ((uint32_t)0x0)
#define LFCK_DIVISION_2                 ((uint32_t)0x1)
#define LFCK_DIVISION_4                 ((uint32_t)0x2)
#define LFCK_DIVISION_8                 ((uint32_t)0x3)
#define LFCK_DIVISION_16                ((uint32_t)0x4)
#define LFCK_DIVISION_32                ((uint32_t)0x5)
#define LFCK_DIVISION_64                ((uint32_t)0x6)
#define LFCK_DIVISION_128               ((uint32_t)0x7)
#define CHECK_LFCK_DIVISION(LFCK)       ((uint32_t)(LFCK) <= LFCK_DIVISION_128)

/**
  * HFCK��Ƶϵ��
  */
#define HFCK_DIVISION_1                 ((uint32_t)0x0)
#define HFCK_DIVISION_2                 ((uint32_t)0x1)
#define HFCK_DIVISION_4                 ((uint32_t)0x2)
#define HFCK_DIVISION_8                 ((uint32_t)0x3)
#define HFCK_DIVISION_16                ((uint32_t)0x4)
#define HFCK_DIVISION_32                ((uint32_t)0x5)
#define HFCK_DIVISION_64                ((uint32_t)0x6)
#define HFCK_DIVISION_128               ((uint32_t)0x7)
#define HFCK_DIVISION_256               ((uint32_t)0x8)
#define HFCK_DIVISION_512               ((uint32_t)0x9)
#define CHECK_HFCK_DIVISION(HFCK)       ((uint32_t)(HFCK) <= HFCK_DIVISION_512)

/**
  * SCLK��Ƶϵ��
  */
#define SCLK_DIVISION_1                 ((uint32_t)0x0)
#define SCLK_DIVISION_2                 ((uint32_t)0x1)
#define SCLK_DIVISION_4                 ((uint32_t)0x2)
#define SCLK_DIVISION_8                 ((uint32_t)0x3)
#define SCLK_DIVISION_16                ((uint32_t)0x4)
#define SCLK_DIVISION_32                ((uint32_t)0x5)
#define SCLK_DIVISION_64                ((uint32_t)0x6)
#define SCLK_DIVISION_128               ((uint32_t)0x7)
#define CHECK_SCLK_DIVISION(SCLK)       ((uint32_t)(SCLK) <= SCLK_DIVISION_128)

/**
  * PLL����ʱ��Դѡ��
  */
#define PLL_INPUT_INTHF                 ((uint32_t)0x0)
#define PLL_INPUT_EXTHF                 ((uint32_t)0x1)
#define CHECK_PLL_INPUT(CFG)            (((CFG) >> 0x01) == 0x00)

/**
  * HFCK��Դѡ��
  */
#define HFCK_SOURCE_INTHF               ((uint32_t)0x0)
#define HFCK_SOURCE_EXTHF               ((uint32_t)0x2)
#define HFCK_SOURCE_PLL                 ((uint32_t)0x4)
#define HFCK_SOURCE_LP4M				((uint32_t)0x6)
#define CHECK_HFCK_SOURCE(HFCK)         (((HFCK) >> 0x03) == 0x00)

/**
  * LFCK��Դѡ��
  */
#define LFCK_INPUT_INTLF                ((uint32_t)0x0)
#define LFCK_INPUT_EXTLF                ((uint32_t)0x1)
#define CHECK_LFCK_INPUT(LFCK)          ((LFCK) <= LFCK_INPUT_EXTLF)

/**
  * SCLK��Դѡ��
  */
#define SCLK_SOURCE_INTHF               ((uint32_t)0x0)
#define SCLK_SOURCE_INTLF               ((uint32_t)0x1)
#define SCLK_SOURCE_EXTHF               ((uint32_t)0x2)
#define SCLK_SOURCE_EXTLF               ((uint32_t)0x3)
#define SCLK_SOURCE_PLL                 ((uint32_t)0x4)
#define SCLK_SOURCE_LP4M                ((uint32_t)0x6)
#define CHECK_SCLK_SOURCE(SCLK)         (((SCLK) >> 0x03) == 0x00)
/**
  * CLKOUT���ʱ�ӷ�Ƶ
  */
#define CLKOUT_DIVISION_1				((uint32_t)0x0)
#define CLKOUT_DIVISION_2				((uint32_t)0x1)
#define CLKOUT_DIVISION_4				((uint32_t)0x2)
#define CLKOUT_DIVISION_8				((uint32_t)0x3)
#define CLKOUT_DIVISION_16				((uint32_t)0x4)
#define CLKOUT_DIVISION_32				((uint32_t)0x5)
#define CLKOUT_DIVISION_64				((uint32_t)0x6)
#define CLKOUT_DIVISION_128				((uint32_t)0x7)
#define CHECK_CLOOUT_DIVISION(DIV)		(((DIV) >> 0x03) == 0x00)

/**
  * CLKOUT���ʱ��ѡ��
  */
#define CLKOUT_SCLK                      ((uint32_t)0x0)
#define CLKOUT_EXTLF                     ((uint32_t)0x1)
#define CLKOUT_EXTHF                     ((uint32_t)0x2)
#define CLKOUT_INTHF                     ((uint32_t)0x4)
#define CLKOUT_PLL                       ((uint32_t)0x5)
#define CLKOUT_LP4M				         ((uint32_t)0x6)
#define CHECK_CLKOUT_SEL(CLKOUT)         (((CLKOUT) >> 0x03) == 0x00)

/**
 * FSCM_DIVISIONʱ�ӹ��ϼ���Ƶ
 */
#define FSCM_DIVISION_8				 	 ((uint32_t)0x3)
#define FSCM_DIVISION_16				 ((uint32_t)0x4)
#define FSCM_DIVISION_32				 ((uint32_t)0x5)
#define FSCM_DIVISION_64				 ((uint32_t)0x6)
#define FSCM_DIVISION_128				 ((uint32_t)0x7)
#define CHECK_FSMC_DIVISION(DIV)		 (((DIV) >> 0x03) == 0x00)

/**
 * FSCM_SOURCEʱ�ӹ��ϼ���Ƶ
 */
#define FSCM_SOURCE_EXTHF				 ((uint32_t)0x0)
#define FSCM_SOURCE_EXTLF				 ((uint32_t)0x1)
#define FSCM_SOURCE_SCLK				 ((uint32_t)0x2)
#define FSCM_SOURCE_INTLF				 ((uint32_t)0x3)
#define FSCM_SOURCE_INTHF				 ((uint32_t)0x4)
#define FSCM_SOURCE_PLL				 	 ((uint32_t)0x5)
#define FSCM_SOURCE_LP4M				 ((uint32_t)0x6)
#define FSCM_SOURCE_SCLK_DIV			 ((uint32_t)0x7)
#define CHECK_FSCM_SOURCE(SOURCE)		 (((SOURCE) >> 0x03) == 0x00)

/**
  * CK48M��Ƶϵ��
  */
#define CK48M_DIVISION_1                ((uint32_t)0x0)
#define CK48M_DIVISION_2                ((uint32_t)0x1)
#define CK48M_DIVISION_4                ((uint32_t)0x2)
#define CHECK_CK48M_DIVISION(CLK)       (((CLK) >> 0x02) == 0x00)

/**
  * CK48M��Դѡ��
  */
#define CK48M_SOURCE_INTHF              ((uint32_t)0x0)
#define CK48M_SOURCE_EXTHF              ((uint32_t)0x2)
#define CK48M_SOURCE_PLL                ((uint32_t)0x4)
#define CHECK_CK48M_SOURCE(CLK)         (((CLK) >> 0x03) == 0x00)

/**
  * PLL������ʱʱ������
  */
#define PLL_START_DELAY_64              ((uint32_t)0x00)
#define PLL_START_DELAY_128             ((uint32_t)0x01)
#define PLL_START_DELAY_256             ((uint32_t)0x02)
#define PLL_START_DELAY_512             ((uint32_t)0x03)
#define PLL_START_DELAY_1024            ((uint32_t)0x04)
#define PLL_START_DELAY_2048            ((uint32_t)0x05)
#define PLL_START_DELAY_4096            ((uint32_t)0x06)
#define PLL_START_DELAY_8192            ((uint32_t)0x07)
#define PLL_START_DELAY_16384           ((uint32_t)0x08)
#define PLL_START_DELAY_32768           ((uint32_t)0x09)
#define CHECK_PLL_START_DELAY(PLL)      (((PLL) >> 0x04) == 0x00)

/**
  * �ⲿ������ʱʱ������
  */
#define EXT_START_DELAY_256              ((uint32_t)0x00)
#define EXT_START_DELAY_512              ((uint32_t)0x01)
#define EXT_START_DELAY_1024             ((uint32_t)0x02)
#define EXT_START_DELAY_2048             ((uint32_t)0x03)
#define EXT_START_DELAY_4096             ((uint32_t)0x04)
#define EXT_START_DELAY_8192             ((uint32_t)0x05)
#define EXT_START_DELAY_16384            ((uint32_t)0x06)
#define EXT_START_DELAY_32770            ((uint32_t)0x07)
#define EXT_START_DELAY_65536            ((uint32_t)0x08)
#define EXT_START_DELAY_131072           ((uint32_t)0x09)
#define CHECK_EXT_START_DELAY(EXT)       (((EXT) >> 0x04) == 0x00)

/**
  * PLL��Ƶϵ��
  */
#define CHECK_PLL_MULTIPLE_NValue(MUL)         ((uint32_t)(MUL) <= 0xF)
#define CHECK_PLL_MULTIPLE_MValue(MUL)         ((uint32_t)(MUL) <= 0x3FFF)

#define PLL_MULTIPLE_NOValue_8	8
#define PLL_MULTIPLE_NOValue_4	4
#define PLL_MULTIPLE_NOValue_2	2
#define PLL_MULTIPLE_NOValue_1	1
#define CHECK_PLL_MULTIPLE_NOValue(MUL)         (((MUL) == PLL_MULTIPLE_NOValue_1) \
											  || ((MUL) == PLL_MULTIPLE_NOValue_2) \
											  || ((MUL) == PLL_MULTIPLE_NOValue_4) \
											  || ((MUL) == PLL_MULTIPLE_NOValue_8))

/**
  * ����Ư������ѡ��
  */
#define ZERO_DRIFT_SCALEDIV32           OSC_HFOSCCAL0_SCALEDIV32
#define ZERO_DRIFT_SCALEDIV16           OSC_HFOSCCAL0_SCALEDIV16
#define ZERO_DRIFT_SCALEDIV8            OSC_HFOSCCAL0_SCALEDIV8
#define ZERO_DRIFT_SCALEDIV4            OSC_HFOSCCAL0_SCALEDIV4
#define ZERO_DRIFT_SCALEDIV2            OSC_HFOSCCAL0_SCALEDIV2
#define ZERO_DRIFT_SCALE1X              OSC_HFOSCCAL0_SCALE1X
#define ZERO_DRIFT_SCALE2X              OSC_HFOSCCAL0_SCALE2X
#define ZERO_DRIFT_SCALE4X              OSC_HFOSCCAL0_SCALE4X
#define ZERO_DRIFT_SCALE8X              OSC_HFOSCCAL0_SCALE8X
#define ZERO_DRIFT_SCALE16X0            OSC_HFOSCCAL0_SCALE16X0
#define ZERO_DRIFT_SCALE16X1            OSC_HFOSCCAL0_SCALE16X1
#define ZERO_DRIFT_SCALE16X2            OSC_HFOSCCAL0_SCALE16X2
#define ZERO_DRIFT_SCALE16X3            OSC_HFOSCCAL0_SCALE16X3
#define ZERO_DRIFT_SCALE16X4            OSC_HFOSCCAL0_SCALE16X4
#define ZERO_DRIFT_SCALE32X             OSC_HFOSCCAL0_SCALE32X
#define CHECK_ZERO_DRIFT(SCALE)         (((SCALE) << 16) == 0x00)
/**
  * �����������λ
  */
#define FREQUENCY_MORE_THAN_10M         ((uint32_t)0)
#define FREQUENCY_LESS_THAN_10M         ((uint32_t)1)
#define CHECK_FEEDBACK_RESISTANCE(SW)   (((SW) == FREQUENCY_MORE_THAN_10M) \
                                      || ((SW) == FREQUENCY_LESS_THAN_10M))

/**
  * �ڲ���Ƶ���������µ��ڿ���
  */
#define CHECK_POSITIVE_DRIFT(SCALE)     ((uint32_t)(SCALE) <= 0x1F)

/**
  * �ڲ���Ƶ�����ĸ��µ��ڿ���
  */
#define CHECK_NEGATIVE_DRIFT(SCALE)     ((uint32_t)(SCALE) <= 0x1F)

/**
  * ��������ѡ��
  */
#define CHECK_CURRENT_GAIN(SEL)         ((uint32_t)(SEL) <= 3)


/* ����(OSC)�����ʼ������****************************************/
void OSC_SCLK_Configuration (OSC_InitTypeDef* oscInitStruct);
void OSC_HFCK_Configuration (OSC_InitTypeDef* oscInitStruct);
void OSC_LFCK_Configuration (OSC_InitTypeDef* oscInitStruct);
void OSC_Struct_Init (OSC_InitTypeDef* oscInitStruct);
/* ����(OSC)�������ú���******************************************/
void OSC_LFCK_Division_Config (uint32_t LFDivision);
void OSC_HFCK_Division_Config (uint32_t HFDivision);
void OSC_SCK_Division_Config (uint32_t SclkDivision);
void OSC_PLL_Input_Source_Config (uint32_t NewState);
void OSC_HFCK_Source_Config (uint32_t HFSource);
void OSC_HFCK_Enable (FunctionalState NewState);
void OSC_LFCK_Source_Config (uint32_t NewState);
void OSC_LFCK_Enable (FunctionalState NewState);
void OSC_SCK_Source_Config (uint32_t SclkSource);
void OSC_Backup_Write_Read_Enable (FunctionalState NewState);
void OSC_SCLK_Output_Enable (FunctionalState NewState);
void OSC_SCLK_Output_Select (uint32_t ClkSource);
void OSC_SCLK_Output_Division_Config (uint32_t OutputDivision);
void OSC_Clock_Failure_Check_Enable (FunctionalState NewState);
void OSC_Clock_Failure_Check_Division_Config (uint32_t FSCM_DIV);
void OSC_PLL_Multiple_Value_Select (uint32_t PLLmultiple_M,uint32_t PLLmultiple_N,uint32_t PLLmultiple_NO);
void OSC_PLL_RST(void);
void OSC_PLL_Start_Delay_Config (uint32_t PLLDelay);
void OSC_EXTHF_Start_Delay_Config (uint32_t ExternalDelay);
void OSC_EXTLF_Start_Delay_Config (uint32_t ExternalDelay);
void OSC_LP4M_Software_Enable (FunctionalState NewState);
void OSC_PLL_Software_Enable (FunctionalState NewState);
void OSC_EXTHF_Software_Enable (FunctionalState NewState);
void OSC_EXTLF_Software_Enable (FunctionalState NewState);
void OSC_INTHF_Software_Enable (FunctionalState NewState);
void OSC_INTLF_Software_Enable (FunctionalState NewState);
void OSC_Zero_Drift_Config (uint32_t Scale, FunctionalState NewState);
void OSC_Positive_Drift_Config (uint32_t PositiveDrift);
void OSC_Negative_Drift_Config (uint32_t PositiveDrift);
void OSC_Current_Gain_Config (uint32_t PositiveDrift);
void OSC_High_Speed_Enable (FunctionalState NewState);
void OSC_External_Input_Enable (FunctionalState NewState);
void OSC_Feedback_Resistance_Config (uint32_t NewState);
/* ����(OSC)�жϿ��ƺ���******************************************/
void OSC_LP4M_INT_Enable (FunctionalState NewState);
void OSC_PLL_INT_Enable (FunctionalState NewState);
void OSC_EXTHF_INT_Enable (FunctionalState NewState);
void OSC_EXTLF_INT_Enable (FunctionalState NewState);
void OSC_INTHF_INT_Enable (FunctionalState NewState);
void OSC_INTLF_INT_Enable (FunctionalState NewState);
FlagStatus OSC_Get_Clock_Failure_INT_Flag (void);
FlagStatus OSC_Get_LP4MIF_INT_Flag (void);
FlagStatus OSC_Get_PLL_INT_Flag (void);
FlagStatus OSC_Get_EXTHF_INT_Flag (void);
FlagStatus OSC_Get_EXTLF_INT_Flag (void);
FlagStatus OSC_Get_INTHF_INT_Flag (void);
FlagStatus OSC_Get_INTLF_INT_Flag (void);


#endif /* KF32A1x6_OSC_H_ */
