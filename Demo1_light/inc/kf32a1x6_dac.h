/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_dac.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the DAC 			  *
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
#ifndef KF32A1x6_DAC_H_
#define KF32A1x6_DAC_H_

#include "kf32a1x6.h"


/**
  * DAC�����ж�
  */
#define CHECK_DAC_ALL_PERIPH(PERIPH)    (((PERIPH) == DAC0_SFR) \
                                      || ((PERIPH) == DAC1_SFR) \
                                      || ((PERIPH) == DAC2_SFR) \
                                      || ((PERIPH) == DAC3_SFR))

/**
  * ����  DAC������Ϣ�ṹ��
  */
typedef struct
{
    FunctionalState m_TriggerEnable;    /* DACͨ������ʹ�ܣ�
                                           ȡֵΪTRUE��FALSE */
    uint32_t m_TriggerEvent;            /* DACͨ�������¼�
                                           ȡֵΪ�ꡰDAC�����¼����е�һ�� */
    FunctionalState m_TriggerDMAEnable; /* DAC����DMAʹ�ܣ�
                                           ȡֵΪTRUE��FALSE */
    uint32_t m_Wave;                    /* DAC���η�����ʹ��
                                           ȡֵΪ�ꡰDAC���η�����ʹ��ѡ���е�һ�� */
    uint32_t m_Mas;                     /* DAC����/��ֵѡ����
                                           ȡֵΪ�ꡰDAC����/��ֵѡ�������е�һ�� */
    uint32_t m_Clock;                   /* DAC����ʱ��
                                           ȡֵΪ�ꡰDAC����ʱ�ӡ��е�һ�� */
    uint32_t m_ClockDiv;                /* DACʱ�ӷ�Ƶ��
                                            ȡֵΪ�ꡰDACʱ�ӷ�Ƶ���е�һ���� */
    uint32_t m_ReferenceVoltage;        /* DAC�ο���ѹѡ��
                                           ȡֵΪ�ꡰDAC�ο���ѹѡ���е�һ�� */
    FunctionalState m_OutputBuffer;     /* DAC�������ʹ�ܣ�
                                           ȡֵΪTRUE��FALSE */
    uint32_t m_OutputPin;               /* DAC������ţ�
                                           ȡֵΪ�ꡰDAC�������ѡ���е�һ�� */
    uint32_t m_Output;                  /* DAC�������
                                           ȡֵΪ12λ����(0~0xFFF) */
}DAC_InitTypeDef;


/**
  * DAC�������ѡ��
  */
#define DAC_OUTPUT_PIN_0                ((uint32_t)0 << DAC_CTL1_SEL_POS)
#define DAC_OUTPUT_PIN_1                ((uint32_t)1 << DAC_CTL1_SEL_POS)
#define CHECK_DAC_OUTPUT_PIN(SEL)       (((SEL) == DAC_OUTPUT_PIN_0) \
                                      || ((SEL) == DAC_OUTPUT_PIN_1))

/**
  * DAC�����¼�
  */
#define DAC_TRIGGER_T1_TRGO             ((uint32_t)0x0 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T3_TRGO             ((uint32_t)0x1 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T5_TRGO             ((uint32_t)0x2 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T9_TRGO             ((uint32_t)0x3 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T14_TRGO            ((uint32_t)0x4 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T15_TRGO            ((uint32_t)0x5 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_EINT9_TRGO          ((uint32_t)0x6 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_SOFTWARE_TRGO       ((uint32_t)0x7 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T0_TRGO             ((uint32_t)0x8 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T2_TRGO             ((uint32_t)0x9 << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T4_TRGO             ((uint32_t)0xA << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T18_TRGO            ((uint32_t)0xB << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T19_TRGO            ((uint32_t)0xC << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T20_TRGO            ((uint32_t)0xD << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_T21_TRGO            ((uint32_t)0xE << DAC_CTL_TREVT0_POS)
#define DAC_TRIGGER_NONE                ((uint32_t)0xF << DAC_CTL_TREVT0_POS)
#define CHECK_DAC_TRIGGER_EVENT(EVENT)  ((((EVENT) >> 8) == 0) \
                                      && (((EVENT) & 0xF) == 0))

/**
  * DAC���η�����ʹ��ѡ��
  */
#define DAC_WAVE_NONE                   ((uint32_t)0<<DAC_CTL_WAVE0_POS)
#define DAC_WAVE_NOISE                  ((uint32_t)1<<DAC_CTL_WAVE0_POS)
#define DAC_WAVE_TRIANGLE               ((uint32_t)2<<DAC_CTL_WAVE0_POS)
#define CHECK_DAC_WAVE(WAVE)            (((WAVE) == DAC_WAVE_NONE) \
        							  || ((WAVE) == DAC_WAVE_NOISE) \
        							  || ((WAVE) == DAC_WAVE_TRIANGLE))

/**
  * DAC����/��ֵѡ����
  */
#define DAC_LFSR_UNMASK_BITS0_0         ((uint32_t)0x0<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS1_0         ((uint32_t)0x1<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS2_0         ((uint32_t)0x2<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS3_0         ((uint32_t)0x3<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS4_0         ((uint32_t)0x4<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS5_0         ((uint32_t)0x5<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS6_0         ((uint32_t)0x6<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS7_0         ((uint32_t)0x7<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS8_0         ((uint32_t)0x8<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS9_0         ((uint32_t)0x9<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS10_0        ((uint32_t)0xA<<DAC_CTL_MAS0_POS)
#define DAC_LFSR_UNMASK_BITS11_0        ((uint32_t)0xB<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_1        ((uint32_t)0x0<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_3        ((uint32_t)0x1<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_7        ((uint32_t)0x2<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_15       ((uint32_t)0x3<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_31       ((uint32_t)0x4<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_63       ((uint32_t)0x5<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_127      ((uint32_t)0x6<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_255      ((uint32_t)0x7<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_511      ((uint32_t)0x8<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_1023     ((uint32_t)0x9<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_2047     ((uint32_t)0xA<<DAC_CTL_MAS0_POS)
#define DAC_TRIANGLE_AMPLITUDE_4095     ((uint32_t)0xB<<DAC_CTL_MAS0_POS)
#define CHECK_DAC_MAS(MAS)              ((((MAS) >> (DAC_CTL_MAS0_POS + 4)) == 0) \
	                                  && (((MAS) << (32 - DAC_CTL_MAS0_POS)) == 0))

/**
  * DAC����ʱ��
  */
#define DAC_CLK_SCLK                    ((uint32_t)0<<DAC_CTL1_CLK0_POS)
#define DAC_CLK_HFCLK                   ((uint32_t)1<<DAC_CTL1_CLK0_POS)
#define DAC_CLK_LFCLK                   ((uint32_t)2<<DAC_CTL1_CLK0_POS)
#define CHECK_DAC_CLK(CLK)              (((CLK) == DAC_CLK_SCLK) \
                                      || ((CLK) == DAC_CLK_HFCLK) \
                                      || ((CLK) == DAC_CLK_LFCLK))

/**
  * DACʱ�ӷ�Ƶ
  */
#define DAC_CLK_DIV_1                   ((uint32_t)0<<DAC_CTL1_CLKDIV0_POS)
#define DAC_CLK_DIV_2                   ((uint32_t)1<<DAC_CTL1_CLKDIV0_POS)
#define DAC_CLK_DIV_4                   ((uint32_t)2<<DAC_CTL1_CLKDIV0_POS)
#define DAC_CLK_DIV_8                   ((uint32_t)3<<DAC_CTL1_CLKDIV0_POS)
#define DAC_CLK_DIV_16                  ((uint32_t)4<<DAC_CTL1_CLKDIV0_POS)
#define DAC_CLK_DIV_32                  ((uint32_t)5<<DAC_CTL1_CLKDIV0_POS)
#define DAC_CLK_DIV_64                  ((uint32_t)6<<DAC_CTL1_CLKDIV0_POS)
#define DAC_CLK_DIV_128                 ((uint32_t)7<<DAC_CTL1_CLKDIV0_POS)
#define CHECK_DAC_CLK_DIV(CLK)       	(((CLK) == DAC_CLK_DIV_1)\
									  || ((CLK) == DAC_CLK_DIV_2) \
                                      || ((CLK) == DAC_CLK_DIV_4) \
                                      || ((CLK) == DAC_CLK_DIV_8) \
                                      || ((CLK) == DAC_CLK_DIV_16) \
                                      || ((CLK) == DAC_CLK_DIV_32) \
                                      || ((CLK) == DAC_CLK_DIV_64) \
                                      || ((CLK) == DAC_CLK_DIV_128))

/**
  * DAC�ο���ѹѡ��
  */
#define DAC_RFS_AVDD                    ((uint32_t)0<<DAC_CTL1_RFS0_POS)
#define DAC_RFS_REF                     ((uint32_t)1<<DAC_CTL1_RFS0_POS)
#define DAC_RFS_2V                      ((uint32_t)2<<DAC_CTL1_RFS0_POS)
#define CHECK_DAC_RFS(RFS)              (((RFS) == DAC_RFS_AVDD) \
                                      || ((RFS) == DAC_RFS_REF) \
                                      || ((RFS) == DAC_RFS_2V))
/**
  * DAC�������
  */
#define CHECK_DAC_OUTPUT(DATA)          (((DATA) >> 12) == 0)

/**
  * DACУ׼��������
  */
#define DAC_Negetive					((uint32_t)0)
#define DAC_Positive					((uint32_t)1)
#define CHECK_DAC_CAL_DIRECTION(DIR)	((DIR) <= 0x01)

/**
 *  DACУ׼��λ
 * */
#define CHECK_DAC_TRIMP(VALUE)			((VALUE) <= 0x3F)

/**
 * 	DAC���������������
 * */
#define DAC_TEST_GROUP1					((uint32_t)0)
#define DAC_TEST_GROUP2					((uint32_t)1)
#define DAC_TEST_GROUP3					((uint32_t)2)
#define DAC_TEST_GROUP4					((uint32_t)3)
#define CHECK_DAC_TEST_GROUP(GROUP)		((GROUP) <= 0x03)


/** ��ʼ�������ú��� ************************************************/
void DAC_Reset (DAC_SFRmap* DACx);
void DAC_Configuration (DAC_SFRmap* DACx, DAC_InitTypeDef* dacInitStruct);
void DAC_Struct_Init (DAC_InitTypeDef* dacInitStruct);
void DAC_Cmd (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Software_Trigger_Cmd (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_DMA_Cmd (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Output_Buffer_Config (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Output_Port_Config (DAC_SFRmap* DACx, FunctionalState NewState);
/** ���ݶ�д���� ****************************************************/
void DAC_Write_Output_Data (DAC_SFRmap* DACx, uint32_t Value);
uint32_t DAC_Read_Output_Data (DAC_SFRmap* DACx);
/** DACУ��Ĵ������ú��� *******************************************/
void DAC_PCalibration_Direction_Config (DAC_SFRmap* DACx, uint32_t Direction);
void DAC_PCalibration_Value_Config (DAC_SFRmap* DACx, uint32_t Value);
uint16_t DAC_PCalibration_Value_Read (DAC_SFRmap* DACx);
void DAC_NCalibration_Direction_Config (DAC_SFRmap* DACx, uint32_t Direction);
void DAC_NCalibration_Value_Config (DAC_SFRmap* DACx, uint32_t Value);
uint16_t DAC_NCalibration_Value_Read (DAC_SFRmap* DACx);
uint8_t  DAC_TRIM_STATE_Value_Read (DAC_SFRmap* DACx);
void DAC_TRIMHI_Enable(DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_TRIMLO_Enable(DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Test_Group_Config(DAC_SFRmap* DACx, uint32_t TestGroup);
void DAC_Test_Group_Enable(DAC_SFRmap* DACx, FunctionalState NewState);



#endif /* KF32A1x6_DAC_H_ */
