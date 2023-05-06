/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_atim.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the ATIM 			  *
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

#ifndef KF32A1x6_ATIM_H_
#define KF32A1x6_ATIM_H_


#include "kf32a1x6.h"

/* ��ʱ������У�� */

#define CHECK_ATIM_PERIPH(PERIPH)       (((PERIPH) == T5_SFR) \
                                      || ((PERIPH) == T6_SFR))

/**
  * ����״̬
  */
#define PIN_INACTIVE                    ((uint32_t)0x0)
#define PIN_ACTIVE                      ((uint32_t)0x1)
#define PIN_TRISTATE                    ((uint32_t)0x2)
#define CHECK_PIN_STATE(STATE)                (((STATE) == PIN_INACTIVE) \
                                      || ((STATE) == PIN_ACTIVE) \
                                      || ((STATE) == PIN_TRISTATE))

/*** �߼���ʱ��(ATIM)��ECCP��ض���  */
/**
  * ����  �߼���ʱ��(ATIM)������Ϣ�ṹ��
  */
typedef struct
{
    uint16_t m_Counter;         /* ��ʱ������ֵ��ȡֵ16λ���ݡ� */
    uint16_t m_Period;          /* ��ʱ������ֵ��ȡֵ16λ���ݡ� */
    uint16_t m_Prescaler;       /* ��ʱ��Ԥ��Ƶֵ��ȡֵ16λ���ݡ� */
    uint16_t m_Postscaler;      /* ��ʱ�����Ƶ����ֵ��
                                   ȡֵΪ�ꡰATIM��ʱ�����Ƶ����ֵ���е�һ���� */
    uint32_t m_CounterMode;     /* ��ʱ������ģʽ��
                                   ȡֵΪ�ꡰATIM��ʱ������ģʽ���е�һ�� */
    uint16_t m_Clock;           /* ��ʱ������ʱ�ӣ�
                                   ȡֵΪ�ꡰATIM��ʱ������ʱ�ӡ��е�һ�� */
    uint16_t m_WorkMode;        /* ��ʱ/����ģʽѡ��
                                   ȡֵΪ�ꡰATIM��ʱ/����ģʽѡ���е�һ�� */
    uint16_t m_EXPulseSync;     /* Tx����ģʽ�ⲿ������������ͬ�����ƣ�
                                   ȡֵΪ�ꡰATIM����ģʽ�ⲿ������������ͬ�����ơ��е�һ�� */
} ATIM_InitTypeDef; /* T5/T6��T9/T10 */

/**
  * ����  ECCP ��׽ģʽ������Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_Channel;         /* ͨ����ţ�
                                   ȡֵ��Χ���㡰ECCPͨ�����ĺꡣ */
    uint32_t m_Mode;            /* ��׽ģʽѡ��
                                   ȡֵ��Χ�����CHECK_ECCP_CAP_MODE��Լ�������� */
    FunctionalState m_PWMInput;        /* PWM����ģʽ��
                                   ȡֵΪTRUE��FALSE�� */
    FunctionalState m_XORMode;         /* �������ģʽ��
                                   ȡֵΪTRUE��FALSE�� */
} ECCP_CaptureInitTypeDef;

/**
  * ����  ECCP PWMģʽ������Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_Channel;         /* ͨ����ţ�
                                   ȡֵ��Χ���㡰ECCPͨ�����ĺꡣ */
    uint32_t m_Mode;            /* ��׽/�Ƚ���ģʽѡ��
                                   ȡֵ��Χ�����CHECK_ECCP_PWM_MODE��Լ�������� */
    uint16_t m_DutyRatio;       /* ռ�ձȣ�
                                   ȡֵ��ΧΪ0~65535�� */
    uint8_t m_DeadTime;         /* ͨ���������ƣ�
                                   ȡֵΪ0~255�� */
    uint8_t m_OutputMode;       /* ͨ�����ģʽ��
                                   ȡֵΪ��ECCPͨ�����ģʽ���е�һ���� */
    uint16_t m_HOutputCtl;      /* ͨ��H������ƣ�
                                   ȡֵΪ��ECCPͨ��������ơ��е�һ���� */
    uint16_t m_LOutputCtl;      /* ͨ��L������ƣ�
                                   ȡֵΪ��ECCPͨ��������ơ��е�һ���� */
    FunctionalState m_PhaseMove;       /* ��λ�ƶ�ʹ�ܣ�
                                   ȡֵΪTRUE��FALSE�� */
    FunctionalState m_SinglePWM;       /* ���������ģʽ��
                                   ȡֵΪTRUE��FALSE�� */
    FunctionalState m_CloseTimer;      /* ���������ģʽѡ��
                                   ȡֵΪTRUE��FALSE�� */
} ECCP_PWMInitTypeDef;

/**
  * ATIM��ʱ�����Ƶ����ֵ
  */
#define ATIM_POSTSCALER_DIV_1           ((uint16_t)0x0)
#define ATIM_POSTSCALER_DIV_2           ((uint16_t)0x1)
#define ATIM_POSTSCALER_DIV_3           ((uint16_t)0x2)
#define ATIM_POSTSCALER_DIV_4           ((uint16_t)0x3)
#define ATIM_POSTSCALER_DIV_5           ((uint16_t)0x4)
#define ATIM_POSTSCALER_DIV_6           ((uint16_t)0x5)
#define ATIM_POSTSCALER_DIV_7           ((uint16_t)0x6)
#define ATIM_POSTSCALER_DIV_8           ((uint16_t)0x7)
#define ATIM_POSTSCALER_DIV_9           ((uint16_t)0x8)
#define ATIM_POSTSCALER_DIV_10          ((uint16_t)0x9)
#define ATIM_POSTSCALER_DIV_11          ((uint16_t)0xA)
#define ATIM_POSTSCALER_DIV_12          ((uint16_t)0xB)
#define ATIM_POSTSCALER_DIV_13          ((uint16_t)0xC)
#define ATIM_POSTSCALER_DIV_14          ((uint16_t)0xD)
#define ATIM_POSTSCALER_DIV_15          ((uint16_t)0xE)
#define ATIM_POSTSCALER_DIV_16          ((uint16_t)0xF)
#define CHECK_ATIM_POSTSCALER(SCALER)   (((SCALER) >= 0) && ((SCALER) <= 0xF))

/**
  * ATIM��ʱ������ģʽ
  */
#define ATIM_COUNT_DOWN_UF              ((uint32_t)0x0 << ATIM_TXCTL_TXCMS0_POS)
#define ATIM_COUNT_UP_OF                ((uint32_t)0x4 << ATIM_TXCTL_TXCMS0_POS)
#define ATIM_COUNT_UP_DOWN_OF           ((uint32_t)0x1 << ATIM_TXCTL_TXCMS0_POS)
#define ATIM_COUNT_UP_DOWN_UF           ((uint32_t)0x2 << ATIM_TXCTL_TXCMS0_POS)
#define ATIM_COUNT_UP_DOWN_OUF          ((uint32_t)0x3 << ATIM_TXCTL_TXCMS0_POS)
#define CHECK_ATIM_COUNTER_MODE(MODE)   (((MODE) == ATIM_COUNT_DOWN_UF) \
                                      || ((MODE) == ATIM_COUNT_UP_OF) \
                                      || ((MODE) == ATIM_COUNT_UP_DOWN_OF) \
                                      || ((MODE) == ATIM_COUNT_UP_DOWN_UF) \
                                      || ((MODE) == ATIM_COUNT_UP_DOWN_OUF))

/**
  * ATIM��ʱ������ʱ��
  */
#define ATIM_SCLK                       ((uint32_t)0x0 << ATIM_TXCTL_TXCLK0_POS)
#define ATIM_HFCLK                      ((uint32_t)0x1 << ATIM_TXCTL_TXCLK0_POS)
#define ATIM_LFCLK                      ((uint32_t)0x2 << ATIM_TXCTL_TXCLK0_POS)
#define CHECK_ATIM_CLOCK_CONFIG(CLK)    (((CLK) == ATIM_SCLK) \
                                      || ((CLK) == ATIM_HFCLK) \
                                      || ((CLK) == ATIM_LFCLK))

/**
  * ATIM��ʱ/����ģʽѡ��
  */
#define ATIM_TIMER_MODE                 ((uint32_t)0 << ATIM_TXCTL_TXCS_POS)
#define ATIM_COUNTER_MODE               ((uint32_t)1 << ATIM_TXCTL_TXCS_POS)
#define CHECK_ATIM_WORK_MODE(MODE)      (((MODE) == ATIM_TIMER_MODE) \
                                      || ((MODE) == ATIM_COUNTER_MODE))

/**
  * ATIM����ģʽ�ⲿ������������ͬ������
  */
#define ATIM_EX_SYNC_MODE               ((uint32_t)0x0 << ATIM_TXCTL_TXSY_POS)
#define ATIM_NO_SYNC_MODE               ((uint32_t)0x1 << ATIM_TXCTL_TXSY_POS)
#define CHECK_ATIM_SYNC_MODE(MODE)      (((MODE) == ATIM_EX_SYNC_MODE) \
                                      || ((MODE) == ATIM_NO_SYNC_MODE))

/**
  * ECCPͨ��
  */
#define ECCP_CHANNEL_1                  ((uint32_t)0x0)
#define ECCP_CHANNEL_2                  ((uint32_t)0x1)
#define ECCP_CHANNEL_3                  ((uint32_t)0x2)
#define ECCP_CHANNEL_4                  ((uint32_t)0x3)
#define CHECK_ECCP_CHANNEL(CHANNEL)     (((CHANNEL) >> 2) == 0)

/**
  * ECCPͨ��ģʽѡ��
  */
#define ECCP_MODE_RST                   ((uint32_t)0x0)
#define ECCP_CMP_TOGGLE_LEVEL           ((uint32_t)0x2)
#define ECCP_CAP_FALLING_EDGE           ((uint32_t)0x4)
#define ECCP_CAP_RISING_EDGE            ((uint32_t)0x5)
#define ECCP_CAP_4TH_RISING_EDGE        ((uint32_t)0x6)
#define ECCP_CAP_16TH_RISING_EDGE       ((uint32_t)0x7)
#define ECCP_CMP_ACTIVE_LEVEL           ((uint32_t)0x8)
#define ECCP_CMP_INACTIVE_LEVEL         ((uint32_t)0x9)
#define ECCP_CMP_SOFT_INT               ((uint32_t)0xA)
#define ECCP_CMP_SPECIAL_EVENT          ((uint32_t)0xB)
#define ECCP_PWM_FREE                   ((uint32_t)0xC)
#define ECCP_PWM_COORDINATION           ((uint32_t)0xD)
#define ECCP_PWM_SINGLE                 ((uint32_t)0xE)
#define CHECK_ECCP_MODE(MODE)           (((MODE) == ECCP_MODE_RST) \
                                      || ((MODE) == ECCP_CMP_TOGGLE_LEVEL) \
                                      || ((MODE) == ECCP_CAP_RISING_EDGE) \
                                      || ((MODE) == ECCP_CAP_FALLING_EDGE) \
                                      || ((MODE) == ECCP_CAP_4TH_RISING_EDGE) \
                                      || ((MODE) == ECCP_CAP_16TH_RISING_EDGE) \
                                      || ((MODE) == ECCP_CMP_ACTIVE_LEVEL) \
                                      || ((MODE) == ECCP_CMP_INACTIVE_LEVEL) \
                                      || ((MODE) == ECCP_CMP_SOFT_INT) \
                                      || ((MODE) == ECCP_CMP_SPECIAL_EVENT) \
                                      || ((MODE) == ECCP_PWM_MODE))
#define CHECK_ECCP_CAP_MODE(MODE)       (((MODE) == ECCP_MODE_RST) \
                                      || ((MODE) == ECCP_CAP_RISING_EDGE) \
                                      || ((MODE) == ECCP_CAP_FALLING_EDGE) \
                                      || ((MODE) == ECCP_CAP_4TH_RISING_EDGE) \
                                      || ((MODE) == ECCP_CAP_16TH_RISING_EDGE))
#define CHECK_ECCP_CMP_MODE(MODE)       (((MODE) == ECCP_MODE_RST) \
                                      || ((MODE) == ECCP_CMP_TOGGLE_LEVEL) \
                                      || ((MODE) == ECCP_CMP_ACTIVE_LEVEL) \
                                      || ((MODE) == ECCP_CMP_INACTIVE_LEVEL) \
                                      || ((MODE) == ECCP_CMP_SOFT_INT) \
                                      || ((MODE) == ECCP_CMP_SPECIAL_EVENT))
#define CHECK_ECCP_PWM_MODE(MODE)       (((MODE) == ECCP_MODE_RST) \
                                      || ((MODE) == ECCP_PWM_FREE) \
                                      || ((MODE) == ECCP_PWM_COORDINATION) \
                                      || ((MODE) == ECCP_PWM_SINGLE))

/**
  * ECCPͨ�����ģʽ
  */
#define ECCP_OUTPUT_INDEPENDENT         ((uint8_t)0x0)
#define ECCP_OUTPUT_COMPLEMENTARY       ((uint8_t)0x1)
#define CHECK_ECCP_OUTPUT_MODE(MODE)    (((MODE) == ECCP_OUTPUT_INDEPENDENT) \
                                     || ((MODE) == ECCP_OUTPUT_COMPLEMENTARY))

/**
  * ECCPͨ���������
  */
#define ECCP_CHANNEL_OUTPUT_PWM_ACTIVE   ((uint16_t)0x0)
#define ECCP_CHANNEL_OUTPUT_PWM_INACTIVE ((uint16_t)0x1)
#define ECCP_CHANNEL_OUTPUT_INACTIVE     ((uint16_t)0x2)
#define ECCP_CHANNEL_OUTPUT_ACTIVE       ((uint16_t)0x3)
#define CHECK_ECCP_CHANNEL_OUTPUT(CTL)   (((CTL) >> 2) == 0)

/**
  * ATIM��ģʽѡ��
  */
#define ATIM_SLAVE_FORBIDDEN_MODE       ((uint32_t)0x0)
#define ATIM_SLAVE_TRIGGER_MODE         ((uint32_t)0x4)
#define ATIM_SLAVE_GATED_MODE           ((uint32_t)0x5)
#define ATIM_SLAVE_RESET_MODE           ((uint32_t)0x6)
#define ATIM_SLAVE_COUNTER_MODE         ((uint32_t)0x7)
#define CHECK_ATIM_SLAVE_MODE(MODE)     (((MODE) == ATIM_SLAVE_FORBIDDEN_MODE) \
                                     || ((MODE) == ATIM_SLAVE_TRIGGER_MODE) \
                                     || ((MODE) == ATIM_SLAVE_GATED_MODE) \
                                     || ((MODE) == ATIM_SLAVE_RESET_MODE) \
                                     || ((MODE) == ATIM_SLAVE_COUNTER_MODE))

/**
  * ATIM��ģʽѡ��
  */
#define ATIM_MASTER_TXEN_SIGNAL         ((uint32_t)1 << ECCP_CTL2_TXMMS0_POS)
#define ATIM_MASTER_TXIF_SIGNAL         ((uint32_t)2 << ECCP_CTL2_TXMMS0_POS)
#define ATIM_MASTER_CCPXCH1IF_SIGNAL    ((uint32_t)3 << ECCP_CTL2_TXMMS0_POS)
#define ATIM_MASTER_CCPXCH1_SIGNAL      ((uint32_t)4 << ECCP_CTL2_TXMMS0_POS)
#define ATIM_MASTER_CCPXCH2_SIGNAL      ((uint32_t)5 << ECCP_CTL2_TXMMS0_POS)
#define ATIM_MASTER_CCPXCH3_SIGNAL      ((uint32_t)6 << ECCP_CTL2_TXMMS0_POS)
#define ATIM_MASTER_CCPXCH4_SIGNAL      ((uint32_t)7 << ECCP_CTL2_TXMMS0_POS)
#define CHECK_ATIM_MASTER_MODE(MODE)    (((MODE) == ATIM_MASTER_TXEN_SIGNAL) \
                                     || ((MODE) == ATIM_MASTER_TXIF_SIGNAL) \
                                     || ((MODE) == ATIM_MASTER_CCPXCH1IF_SIGNAL) \
                                     || ((MODE) == ATIM_MASTER_CCPXCH1_SIGNAL) \
                                     || ((MODE) == ATIM_MASTER_CCPXCH2_SIGNAL) \
                                     || ((MODE) == ATIM_MASTER_CCPXCH3_SIGNAL) \
                                     || ((MODE) == ATIM_MASTER_CCPXCH4_SIGNAL))

/**
  * ATIM����ѡ��
  */
#define ATIM_TRIGGER_T1                 ((uint32_t)0x0 << ECCP_CTL2_TXTS0_POS)
#define ATIM_TRIGGER_T20                ((uint32_t)0x1 << ECCP_CTL2_TXTS0_POS)
#define ATIM_TRIGGER_T5                 ((uint32_t)0x2 << ECCP_CTL2_TXTS0_POS)
#define ATIM_TRIGGER_T9                 ((uint32_t)0x3 << ECCP_CTL2_TXTS0_POS)
#define ATIM_TRIGGER_ECCPXCH1           ((uint32_t)0x4 << ECCP_CTL2_TXTS0_POS)
#define ATIM_TRIGGER_ECCPXCH2           ((uint32_t)0x5 << ECCP_CTL2_TXTS0_POS)
#define ATIM_TRIGGER_ECCPXCH3           ((uint32_t)0x6 << ECCP_CTL2_TXTS0_POS)
#define ATIM_TRIGGER_TXCK               ((uint32_t)0x7 << ECCP_CTL2_TXTS0_POS)
#define CHECK_ATIM_TRIGGER_MODE(MODE)   (((uint32_t)(MODE) & (~ECCP_CTL2_TXTS)) == 0)

/**
 *  �Ƚ������㶨ʱ������ѡ��
 * */
#define ATIM_UP_EDGE					((uint32_t)0x0 << ATIM_TXCCTCTL_CRSET_POS)
#define ATIM_DOWN_EDGE					((uint32_t)0x1 << ATIM_TXCCTCTL_CRSET_POS)
#define CHECK_ATIM_UP_DOWN_EDGE(EDGE)	(((EDGE) == ATIM_UP_EDGE) \
									   || (EDGE) == ATIM_DOWN_EDGE)

/**
 *  �Ƚ���x���㶨ʱ��
 * */
#define ATIM_CMP0						((uint32_t)0x0 << ATIM_TXCCTCTL_CCTSEL0_POS)
#define ATIM_CMP1						((uint32_t)0x1 << ATIM_TXCCTCTL_CCTSEL0_POS)
#define ATIM_CMP2						((uint32_t)0x2 << ATIM_TXCCTCTL_CCTSEL0_POS)
#define ATIM_CMP3						((uint32_t)0x3 << ATIM_TXCCTCTL_CCTSEL0_POS)
#define CHECK_ATIM_CMP_CHOOSE(CMPNUM)	(((CMPNUM) == ATIM_CMP0) \
									  || ((CMPNUM) == ATIM_CMP1) \
									  || ((CMPNUM) == ATIM_CMP2) \
									  || ((CMPNUM) == ATIM_CMP3))

/**
  * ECCPͨ���˿�
  */
#define ECCP_PORT_LOW                   ((uint32_t)0x0)
#define ECCP_PORT_HIGH                  ((uint32_t)0x2)
#define CHECK_ECCP_PORT(PORT)           (((PORT) == ECCP_PORT_LOW) \
                                     || ((PORT) == ECCP_PORT_HIGH))

/**
  * ECCP�Զ��ر��¼�״̬
  */
#define ECCP_CHANNEL_WORKING_STATE      ((uint32_t)0x0)
#define ECCP_CHANNEL_SHUTDOWN_STATE     ((uint32_t)0x1)
#define CHECK_ECCP_CHANNEL_STATE(STATE) (((STATE) == ECCP_CHANNEL_SHUTDOWN_STATE) \
                                      || ((STATE) == ECCP_CHANNEL_WORKING_STATE))

/**
  * ͨ���Զ��ر�Դ
  */
#define ECCP_CHANNEL_SHUTDOWN_FORBID    ((uint32_t)0x0)
#define ECCP_CHANNEL_CMP2CMP3_ACTIVE    ((uint32_t)0x1)
#define ECCP_CHANNEL_BKIN_INACTIVE      ((uint32_t)0x2)
#define CHECK_ECCP_SHUTDOWN_SIGNAL(STATE) \
                                        (((STATE) == ECCP_CHANNEL_SHUTDOWN_FORBID) \
                                        || ((STATE) == ECCP_CHANNEL_CMP2CMP3_ACTIVE)\
                                      || ((STATE) == ECCP_CHANNEL_BKIN_INACTIVE))
/**
  * ͨ��x�Ƚ����ر�Դѡ��
  */
#define CMP0_OUTPUT_SHUNT    ((uint32_t)0x0)
#define CMP1_OUTPUT_SHUNT    ((uint32_t)0x1)
#define CMP2_OUTPUT_SHUNT    ((uint32_t)0x2)
#define CMP3_OUTPUT_SHUNT    ((uint32_t)0x3)
#define CHECK_CHANNELX_SHUTDOWN_SIGNAL(STATE) (((STATE) >> 0x02) == 0x00)

/**
 * TZ�ضϿ���ԴBKINѡ��
 * */
#define ECCP_CHANNEL_BKIN_HIGH			((uint32_t)0)
#define ECCP_CHANNEL_FLTI2_HIGH			((uint32_t)1)
#define CHECK_TZ_SHOWDOWN_SEL(STATE)	(((STATE) >> 0x01) == 0x00)

/**
  * �����ʱ��
  */
#define ECCP_ZERO_CLOCK_DIV_1           ((uint32_t)0x0 << ECCP_ZPDCTL0_ZCLK0_POS)
#define ECCP_ZERO_CLOCK_DIV_2           ((uint32_t)0x1 << ECCP_ZPDCTL0_ZCLK0_POS)
#define ECCP_ZERO_CLOCK_DIV_4           ((uint32_t)0x2 << ECCP_ZPDCTL0_ZCLK0_POS)
#define ECCP_ZERO_CLOCK_DIV_8           ((uint32_t)0x3 << ECCP_ZPDCTL0_ZCLK0_POS)
#define ECCP_ZERO_CLOCK_DIV_16          ((uint32_t)0x4 << ECCP_ZPDCTL0_ZCLK0_POS)
#define ECCP_ZERO_CLOCK_DIV_32          ((uint32_t)0x5 << ECCP_ZPDCTL0_ZCLK0_POS)
#define ECCP_ZERO_CLOCK_DIV_64          ((uint32_t)0x6 << ECCP_ZPDCTL0_ZCLK0_POS)
#define ECCP_ZERO_CLOCK_DIV_128         ((uint32_t)0x7 << ECCP_ZPDCTL0_ZCLK0_POS)
#define ECCP_ZERO_CLOCK_DIV_256         ((uint32_t)0x8 << ECCP_ZPDCTL0_ZCLK0_POS)
#define ECCP_ZERO_CLOCK_DIV_512         ((uint32_t)0x9 << ECCP_ZPDCTL0_ZCLK0_POS)
#define CHECK_ECCP_ZERO_CLOCK(CLK)      (((CLK) == ECCP_ZERO_CLOCK_DIV_1) \
                                      || ((CLK) == ECCP_ZERO_CLOCK_DIV_2) \
                                      || ((CLK) == ECCP_ZERO_CLOCK_DIV_4) \
                                      || ((CLK) == ECCP_ZERO_CLOCK_DIV_8) \
                                      || ((CLK) == ECCP_ZERO_CLOCK_DIV_16) \
                                      || ((CLK) == ECCP_ZERO_CLOCK_DIV_32) \
                                      || ((CLK) == ECCP_ZERO_CLOCK_DIV_64) \
                                      || ((CLK) == ECCP_ZERO_CLOCK_DIV_128) \
                                      || ((CLK) == ECCP_ZERO_CLOCK_DIV_256) \
                                      || ((CLK) == ECCP_ZERO_CLOCK_DIV_512))

/**
  * ͨ��������ѹ
  */
#define ECCP_ZERO_VOLTAGE_DECIMAL_15    ((uint32_t)0x0)
#define ECCP_ZERO_VOLTAGE_DECIMAL_25    ((uint32_t)0x1)
#define ECCP_ZERO_VOLTAGE_DECIMAL_35    ((uint32_t)0x2)
#define ECCP_ZERO_VOLTAGE_DECIMAL_45    ((uint32_t)0x3)
#define ECCP_ZERO_VOLTAGE_DECIMAL_55    ((uint32_t)0x4)
#define CHECK_ECCP_ZERO_VOLTAGE(VOL)    (((VOL) == ECCP_ZERO_VOLTAGE_DECIMAL_15) \
                                     || ((VOL) == ECCP_ZERO_VOLTAGE_DECIMAL_25) \
                                     || ((VOL) == ECCP_ZERO_VOLTAGE_DECIMAL_35) \
                                     || ((VOL) == ECCP_ZERO_VOLTAGE_DECIMAL_45) \
                                     || ((VOL) == ECCP_ZERO_VOLTAGE_DECIMAL_55))

/**
 * 	FlexMUX ���ͨ��ѡ��λ
 * */
#define ECCP_FlexMUX_CH1					((uint32_t)0x0)
#define ECCP_FlexMUX_CH2					((uint32_t)0x1)
#define ECCP_FlexMUX_CH3					((uint32_t)0x2)
#define ECCP_FlexMUX_CH4					((uint32_t)0x3)
#define CHECK_ECCP_FlexMUX_CH(CHANNEL)	(((CHANNEL) >> 0x02) == 0x00)

/**
 * 	ͨ��x����ģʽѡ��λ
 * */
#define ECCP_NORMAL_PWM_WAVE			((uint32_t)0)
#define ECCP_MOULATION_WAVE				((uint32_t)1)
#define CHECK_CHANNEL_MODULATION(STATE)	(((STATE) >> 0x02) == 0x00)

/**
 * 	��׽����ģʽ
 * */
#define ECCP_CAPTEST_NORMAL				((uint32_t)0)
#define ECCP_CAPTEST_CAP				((uint32_t)1)
#define CHECK_ECCP_CAP_TEST(STATE)		(((STATE) >> 0x01) == 0x00)

/**
 * 	��������ź���Ч��ѡ��
 * */
#define ECCP_PPX_CYCLE_LOW				((uint32_t)0)
#define ECCP_PPX_CYCLE_HIGH				((uint32_t)1)
#define ECCP_EQUAL_COMBH_HIGH			((uint32_t)2)
#define ECCP_EQUAL_COMBH_LOW			((uint32_t)3)
#define CHECK_ECCP_UNION_SINGEL_EFFECTIVE(SINGEL)\
										(((SINGEL) >> 0x02) == 0x00)

/**
 *  ���Ͽ��ƼĴ���ֵУ��
 * */
#define CHECK_ECCP_COM_VALUE(VALUE)		((VALUE) <= 0xFFFF)

/**
 * 	Fault ����ģʽѡ��
 * */
#define ECCP_FAULT_AUTO0				((uint32_t)0)
#define ECCP_FAULT_AUTO1				((uint32_t)1)
#define ECCP_FAULT_MANUAL0				((uint32_t)2)
#define ECCP_FAULT_MANUAL1				((uint32_t)3)
#define CHECK_ECCP_FAULE_MODE(MODE)		((MODE) <= 0x03)

/**
 * 	�˲�����ѡ��λ
 * */
#define ECCP_PULSEWIDTH1				((uint32_t)0)
#define ECCP_PULSEWIDTH2				((uint32_t)1)
#define ECCP_PULSEWIDTH3				((uint32_t)2)
#define ECCP_PULSEWIDTH4				((uint32_t)3)
#define ECCP_PULSEWIDTH5				((uint32_t)4)
#define ECCP_PULSEWIDTH6				((uint32_t)5)
#define ECCP_PULSEWIDTH7				((uint32_t)6)
#define ECCP_PULSEWIDTH8				((uint32_t)7)
#define CHECK_ECCP_PULSEWIDTH(VALUE)	((uint32_t)VALUE <= 0x07)

/**
 * 	Filter CLK ��Ƶ��
 * */
#define ECCP_CLKDIV1					((uint32_t)0x00)
#define ECCP_CLKDIV2					((uint32_t)0x01)
#define ECCP_CLKDIV3					((uint32_t)0x02)
#define ECCP_CLKDIV4					((uint32_t)0x03)
#define ECCP_CLKDIV5					((uint32_t)0x04)
#define ECCP_CLKDIV6					((uint32_t)0x05)
#define ECCP_CLKDIV7					((uint32_t)0x06)
#define ECCP_CLKDIV8					((uint32_t)0x07)
#define ECCP_CLKDIV9					((uint32_t)0x08)
#define ECCP_CLKDIV10					((uint32_t)0x09)
#define ECCP_CLKDIV11					((uint32_t)0x0A)
#define ECCP_CLKDIV12					((uint32_t)0x0B)
#define ECCP_CLKDIV13					((uint32_t)0x0C)
#define ECCP_CLKDIV14					((uint32_t)0x0D)
#define ECCP_CLKDIV15					((uint32_t)0x0E)
#define ECCP_CLKDIV16					((uint32_t)0x0F)
#define CHECK_ECCP_FILTER_CLKDIV(CLKDIV)	((CLKDIV) <= 0x0F)

/**
 * 	FRCVALֵУ��
 * */
#define CHECK_ECCP_FRCVAL_VALUE(VALUE)	((VALUE) <= 0x1F)

/**
 * 	����AD��������
 * */
#define ECCP_TRIGGLE_AD_UP				((uint32_t)0)
#define ECCP_TRIGGLE_AD_DOWN			((uint32_t)1)
#define CHECK_ECCP_ECCP_TRIGGLE_AD_DIR(DIRCTION)\
										((DIRCTION) <= 0x01)

/**
 *  CCRx
 * */
#define ECCP_CCR0						((uint32_t)0)
#define ECCP_CCR1						((uint32_t)1)
#define CHECK_ECCP_CCRX(CCRX)			((CCRX) <= 0x01)


/**
  * �߼���ʱ����ECCP��������
  */
/* �߼���ʱ��(ATIM)��ʼ�������ú�������***********************************/
void ATIM_Reset (ATIM_SFRmap* ATIMx);
void ATIM_X_Configuration(ATIM_SFRmap* ATIMx, ATIM_InitTypeDef* atimInitStruct);
void ATIM_Z_Configuration(ATIM_SFRmap* ATIMx, ATIM_InitTypeDef* atimInitStruct);
void ATIM_Struct_Init (ATIM_InitTypeDef* atimInitStruct);
void ATIM_X_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Updata_Configuration (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter,uint32_t UpdataOutput, uint32_t UpdataImmediately);
void ATIM_Z_Updata_Configuration (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter,uint32_t UpdataOutput, uint32_t UpdataImmediately);
void ATIM_X_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter);
void ATIM_Z_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter);
void ATIM_X_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period);
void ATIM_Z_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period);
void ATIM_X_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler);
void ATIM_Z_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler);
void ATIM_X_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode);
void ATIM_Z_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode);
void ATIM_X_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock);
void ATIM_Z_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock);
void ATIM_X_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler);
void ATIM_Z_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler);
void ATIM_X_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync);
void ATIM_Z_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync);
void ATIM_X_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState);
void ATIM_Z_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState);
DIRStatus ATIM_X_Get_Direction (ATIM_SFRmap* ATIMx);
DIRStatus ATIM_Z_Get_Direction (ATIM_SFRmap* ATIMx);
void ATIM_X_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx,uint16_t CompareAD0, uint16_t CompareAD1);
void ATIM_Z_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx, uint16_t CompareAD);
void ATIM_X_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,FunctionalState NewState);
void ATIM_Z_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,FunctionalState NewState);
void ATIM_X_Updata_Output_Ctl (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_Output_Ctl (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter);
void ATIM_Z_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter);
void ATIM_X_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode);
void ATIM_Z_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode);
void ATIM_Master_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t MasterMode);
void ATIM_Master_Slave_Snyc_Enable (ATIM_SFRmap* ATIMx,FunctionalState NewState);
void ATIM_Trigger_Select_Config (ATIM_SFRmap* ATIMx,FunctionalState TriggerSelect);
void ATIM_Timer_Unite_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
uint16_t ATIM_X_Get_Counter (ATIM_SFRmap* ATIMx);
uint16_t ATIM_Z_Get_Counter (ATIM_SFRmap* ATIMx);
uint16_t ATIM_X_Get_Period (ATIM_SFRmap* ATIMx);
uint16_t ATIM_Z_Get_Period (ATIM_SFRmap* ATIMx);
uint16_t ATIM_X_Get_Prescaler (ATIM_SFRmap* ATIMx);
uint16_t ATIM_Z_Get_Prescaler (ATIM_SFRmap* ATIMx);
RetStatus ATIM_X_Cmp_Clear_Tim_Enable(ATIM_SFRmap* ATIMx, FunctionalState NewState);
RetStatus ATIM_Z_Cmp_Clear_Tim_Enable(ATIM_SFRmap* ATIMx, FunctionalState NewState);
RetStatus ATIM_X_Cmp_Clear_Tim_Edge_Choose(ATIM_SFRmap* ATIMx, uint8_t Edge);
RetStatus ATIM_Z_Cmp_Clear_Tim_Edge_Choose(ATIM_SFRmap* ATIMx, uint8_t Edge);
RetStatus ATIM_X_Cmp_Clear_Tim_Choose(ATIM_SFRmap* ATIMx, uint8_t Cmpnum);
RetStatus ATIM_Z_Cmp_Clear_Tim_Choose(ATIM_SFRmap* ATIMx, uint8_t Cmpnum);


/* �߼���ʱ��(ATIM)�жϼ���־����������*********************************/
void ATIM_X_Updata_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Trigger_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Trigger_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
FlagStatus ATIM_X_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_Z_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_X_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_Z_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_X_Get_Trigger_INT_Flag (ATIM_SFRmap* ATIMx);
void ATIM_X_Generate_Trigger_Config (ATIM_SFRmap* ATIMx,FunctionalState NewState);
FlagStatus ATIM_X_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_Z_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_X_Get_Trigger_DMA_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_X_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_Z_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_X_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_Z_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_X_Clear_Trigger_INT_Flag (ATIM_SFRmap* ATIMx);
/* ��ǿ�Ͳ�׽/�Ƚ�/PWM����(ECCP)��׽���ܺ�������**************************/
void ECCP_Compare_Configuration(ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t CompareMode, uint16_t CompareValue);
void ECCP_Capture_Configuration (ECCP_SFRmap* ECCPx,ECCP_CaptureInitTypeDef* eccpInitStruct);
void ECCP_Capture_Struct_Init (ECCP_CaptureInitTypeDef* eccpInitStruct);
void ECCP_PWM_Configuration (ECCP_SFRmap* ECCPx,ECCP_PWMInitTypeDef* ECCP_InitStruct);
void ECCP_PWM_Struct_Init (ECCP_PWMInitTypeDef* ECCP_InitStruct);
void ECCP_Capture_Mode_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t EdgeConfig);
void ECCP_Compare_Mode_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t CmpConfig);
void ECCP_PWM_Mode_Config (ECCP_SFRmap* ECCPx, uint32_t PWMConfig);
uint16_t ECCP_Get_Capture_Result (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_Set_Compare_Result (ECCP_SFRmap* ECCPx,uint32_t Channel, uint16_t Value);
void ECCP_Generate_Trigger_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState);
void ECCP_PWM_Input_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Input_XOR_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Single_Pulse_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Single_Pulse_Shut_Enable (ECCP_SFRmap* ECCPx,FunctionalState NewState);
void ECCP_PWM_Restart_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Dead_Time_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint8_t DeadTime);
void ECCP_Channel_Output_Control (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t Port, uint32_t ChannelOutputCtl);
void ECCP_Channel_Output_Mode (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t ChannelOutputMode);
void ECCP_Channel_Work_State_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t WorkingState);
void ECCP_TZ_Showdown_SEL(ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal);
void ECCP_TX_Showdown_SEL(ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal);
void ECCP_CHANNEL4_Shutdown_SEL (ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal);
void ECCP_CHANNEL123_Shutdown_SEL (ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal);
FlagStatus ECCP_Get_Channel_Work_State (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_Channel_Shutdown_Signal (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t ShutDownSignal);
void ECCP_Channel_Pin_Ctl (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t Port, uint32_t ChannelPinCtl);
void ECCP_Zero_Clock_Config (ECCP_SFRmap* ECCPx, uint32_t ZeroClock);
void ECCP_Channel_Pin_Tristate_Enable (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t Port, uint32_t PinTristateCtl);
void ECCP_FlexMUX_CHANNEL_SEL (ECCP_SFRmap* ECCPx,uint32_t FlexMUXSignal);
void ECCP_Channel_Modulation_SEL (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t ChannelState);
void ECCP_GTB_OUTPUT_Config (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_GTB_MODE_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_CAPTEST_MODE_Config(ECCP_SFRmap* ECCPx, uint32_t CAPTEST);
void ECCP_UNION_SINGEL_EFFECTIVE_Config(ECCP_SFRmap* ECCPx, uint32_t UnionOutputSingel);
void ECCP_UNION_SINGEL_OUTPUT_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_COMH_Value_Config(ECCP_SFRmap* ECCPx, uint32_t Channel, uint16_t COMHValue);
void ECCP_COML_Value_Config(ECCP_SFRmap* ECCPx, uint32_t Channel, uint16_t COMLValue);
void ECCP_Fault_Contral_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel, FunctionalState NewState);
void ECCP_Fault_Output_Polarity_Select (ECCP_SFRmap* ECCPx, uint32_t Channel, uint32_t OutPolarity);
void ECCP_Filter_PulseWidth_Config(ECCP_SFRmap* ECCPx, uint32_t Channel, uint32_t PulseWidth);
void ECCP_Filter_Function_Enable(ECCP_SFRmap* ECCPx, uint32_t Channel, FunctionalState NewState);
void ECCP_Filter_CLKDIV_Config(ECCP_SFRmap* ECCPx, uint32_t Channel, uint32_t ClkDiv);
void ECCP_Fault_Function_Enable(ECCP_SFRmap* ECCPx, uint32_t Channel, FunctionalState NewState);
FlagStatus ECCP_Get_Fault_INT_Flag(ECCP_SFRmap* ECCPx,uint32_t Channel);
RetStatus ECCP_Clear_Fault_INT_Flag(ECCP_SFRmap* ECCPx,uint32_t Channel);
void ECCP_Fault_INT_Enable(ECCP_SFRmap* ECCPx, uint32_t Channel, FunctionalState NewState);
void ECCP_UNION_jitter_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_CYCLE_jitter_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_EDGE_jitter_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_FRCVAL_Value_Config(ECCP_SFRmap* ECCPx, uint8_t Value);
void ECCP_Tz_Triggle_AD_Driction_SEL(ECCP_SFRmap* ECCPx, FunctionalState Direction);
void ECCP_Tx_Triggle_AD_Driction_SEL(ECCP_SFRmap* ECCPx,uint8_t CCRx, FunctionalState Direction);
void ECCP_Tz_Triggle_AD_Driction_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Tx_Triggle_AD_Driction_Enable(ECCP_SFRmap* ECCPx, uint8_t CCRx, FunctionalState NewState);


/* ��ǿ�Ͳ�׽/�Ƚ�/PWM����(ECCP)�жϼ���־����������********************/
void ECCP_Channel_INT_Enable (ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState);
void ECCP_X_Turn_off_DMA_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Channel_DMA_Enable (ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState);
FlagStatus ECCP_Get_Channel_Trigger_INT_Flag (ECCP_SFRmap* ECCPx,uint32_t Channel);
FlagStatus ECCP_X_Get_Turn_off_DMA_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ECCP_Get_Trigger_DMA_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel);
RetStatus ECCP_Clear_Channel_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_PWM_Move_Phase_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Channel_Zero_Detect_Sequential_Ctl (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t NewState);
FlagStatus ECCP_Get_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,uint32_t Channel);
void ECCP_Clear_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,uint32_t Channel);
void ECCP_Channel_Zero_Detect_Enable (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t NewState);
void ECCP_Channel_Zero_Voltage_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t ZeroDetectVoltage);

/*** �߼���ʱ��(ATIM)��ECCP��ض������  */


/*** ��ǿ���������ģ��(EPWM)����ض�ʱ������  */
/**
  * ����  ��ǿ���������ģ�鶨ʱ��(ETIM)��ʱ��������Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_Counter;         /* ��ʱ������ֵ��ȡֵ32λ���ݡ� */
    uint32_t m_Period;          /* ��ʱ������ֵ��ȡֵ32λ���ݡ� */
    uint32_t m_Prescaler;       /* ��ʱ��Ԥ��Ƶֵ��ȡֵ32λ���ݡ� */
    uint32_t m_Phase;           /* ��ʱ����λֵ��ȡֵ32λ���ݡ� */
    uint32_t m_CounterMode;     /* ��ʱ������ģʽ��
                                   ȡֵΪ�ꡰETIM��ʱ������ģʽ���е�һ�� */
    uint32_t m_Sync;            /* Tx����ģʽ�ⲿ������������ͬ�����ƣ�
                                   ȡֵΪ�ꡰETIM����ģʽ�ⲿ������������ͬ�����ơ��е�һ�� */
    uint32_t m_Clock;           /* ��ʱ������ʱ�ӣ�
                                   ȡֵΪ�ꡰETIM��ʱ������ʱ�ӡ��е�һ�� */
    uint32_t m_WorkMode;        /* ��ʱ/����ģʽѡ��
                                   ȡֵΪ�ꡰETIM��ʱ/����ģʽѡ���е�һ�� */
    FunctionalState m_PhaseEn;  /* ��λ�Ĵ�������ʹ��,
                                   ȡֵΪTRUE �� FALSE�� */
    uint32_t m_PhaseDirection;  /* ��λ������ƣ�
                                   ȡֵΪ�ꡰETIM��λ������ơ��е�һ�� */
    FunctionalState m_GateEn;  /* �ſ�ʹ��,
                                   ȡֵΪTRUE �� FALSE�� */
} ETIM_InitTypeDef; /* T11��T12��T13 */

/**
  * ETIM��λ�������
  */
#define ETIM_PHASE_DOWN                 ((uint32_t)0x0 << EPWM_TXCTL_PHSDIR_POS)
#define ETIM_PHASE_UP                   ((uint32_t)0x1 << EPWM_TXCTL_PHSDIR_POS)
#define CHECK_ETIM_PHASE_DIR(DIR)       (((DIR) == ETIM_PHASE_UP) \
                                      || ((DIR) == ETIM_PHASE_DOWN))

/**
  * ETIM��ʱ������ģʽ
  */
#define ETIM_COUNT_DOWN_UF              ((uint32_t)0x0 << EPWM_TXCTL_TXCMS0_POS)
#define ETIM_COUNT_UP_OF                ((uint32_t)0x4 << EPWM_TXCTL_TXCMS0_POS)
#define ETIM_COUNT_UP_DOWN_OF           ((uint32_t)0x1 << EPWM_TXCTL_TXCMS0_POS)
#define ETIM_COUNT_UP_DOWN_UF           ((uint32_t)0x2 << EPWM_TXCTL_TXCMS0_POS)
#define ETIM_COUNT_UP_DOWN_OUF          ((uint32_t)0x3 << EPWM_TXCTL_TXCMS0_POS)
#define CHECK_ETIM_COUNTER_MODE(MODE)   (((MODE) == ETIM_COUNT_DOWN_UF) \
                                      || ((MODE) == ETIM_COUNT_UP_OF) \
                                      || ((MODE) == ETIM_COUNT_UP_DOWN_OF) \
                                      || ((MODE) == ETIM_COUNT_UP_DOWN_UF) \
                                      || ((MODE) == ETIM_COUNT_UP_DOWN_OUF))

/**
  * ETIM��ʱ������ʱ��
  */
#define ETIM_SCLK                       ((uint32_t)0x0 << EPWM_TXCTL_TXCLK0_POS)
#define ETIM_HFCLK                      ((uint32_t)0x1 << EPWM_TXCTL_TXCLK0_POS)
#define ETIM_LFCLK                      ((uint32_t)0x2 << EPWM_TXCTL_TXCLK0_POS)
#define CHECK_ETIM_CLOCK_CONFIG(CLK)    (((CLK) == ETIM_SCLK) \
                                      || ((CLK) == ETIM_HFCLK) \
                                      || ((CLK) == ETIM_LFCLK))

/**
  * ETIM��ʱ/����ģʽѡ��
  */
#define ETIM_TIMER_MODE                 ((uint32_t)0 << EPWM_TXCTL_TXCS_POS)
#define ETIM_COUNTER_MODE               ((uint32_t)1 << EPWM_TXCTL_TXCS_POS)
#define CHECK_ETIM_WORK_MODE(MODE)      (((MODE) == ETIM_TIMER_MODE) \
                                      || ((MODE) == ETIM_COUNTER_MODE))

/**
  * ETIM����ģʽ�ⲿ������������ͬ������
  */
#define ETIM_EX_SYNC_MODE               ((uint32_t)0x0 << EPWM_TXCTL_TXSY_POS)
#define ETIM_NO_SYNC_MODE               ((uint32_t)0x1 << EPWM_TXCTL_TXSY_POS)
#define CHECK_ETIM_SYNC_MODE(MODE)      (((MODE) == ETIM_EX_SYNC_MODE) \
                                      || ((MODE) == ETIM_NO_SYNC_MODE))










#endif /* KF32A1x6_ATIM_H_ */
