/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_gtim.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the GTIM 			  *
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
#ifndef KF32A1x6_GTIM_H_
#define KF32A1x6_GTIM_H_


#include "kf32a1x6.h"

/* 定时器名称校验 */
#define CHECK_GPTIM_PERIPH(PERIPH)      (((PERIPH) == T0_SFR) \
                                      || ((PERIPH) == T1_SFR) \
                                      || ((PERIPH) == T2_SFR) \
                                      || ((PERIPH) == T3_SFR) \
                                      || ((PERIPH) == T4_SFR) \
                                      || ((PERIPH) == T18_SFR) \
                                      || ((PERIPH) == T19_SFR) \
                                      || ((PERIPH) == T21_SFR))


/*** 通用定时器(GPTIM)、CCP相关定义  */
/**
  * 描述  通用定时器(GPTIM)配置信息结构体
  */
typedef struct
{
    uint32_t m_Counter;         /* 定时器计数值，取值32位数据。 */
    uint32_t m_Period;          /* 定时器周期值，取值32位数据。 */
    uint32_t m_Prescaler;       /* 定时器预分频值，取值32位数据。 */
    uint16_t m_CounterMode;     /* 定时器计数模式，
                                   取值为宏“GPTIM定时器计数模式”中的一个 */
    uint16_t m_Clock;           /* 定时器工作时钟，
                                   取值为宏“GPTIM定时器工作时钟”中的一个 */
    uint16_t m_WorkMode;        /* 定时/计数模式选择
                                   取值为宏“GPTIM定时/计数模式选择”中的一个 */
    uint16_t m_MasterMode;      /* 主模式选择，
                                   取值为宏“GPTIM主模式选择”中的一个 */
    uint16_t m_SlaveMode;       /* 从模式选择，
                                   取值为宏“GPTIM从模式选择”中的一个 */
    uint16_t m_EXPulseSync;     /* Tx计数模式外部触发脉冲输入同步控制，
                                   取值为宏“GPTIM计数模式外部触发脉冲输入同步控制”中的一个 */
    uint16_t m_MasterSlaveSync; /* 主从模式同步控制，
                                   取值为TRUE或FALSE */
} GPTIM_InitTypeDef; /* T0/T1/T2/T3/T4/T18/T19/T20/T21 */

/**
  * 描述  CCP比较模式配置信息结构体
  */
typedef struct
{
    uint16_t m_Channel;         /* 通道编号，
                                   取值范围满足“CCP通道”的宏。 */
    uint16_t m_CompareMode;     /* 捕捉/比较器模式选择，
                                   取值范围满足宏CHECK_CCP_CMP_MODE的约定条件。 */
    uint32_t m_CompareValue;    /* 与TX比较的值，
                                   取值范围为32位数据。 */
} CCP_CompareInitTypeDef;

/**
  * 描述  CCP捕捉模式配置信息结构体
  */
typedef struct
{
    uint16_t m_Channel;         /* 通道编号，
                                   取值范围满足“CCP通道”的宏。 */
    uint16_t m_CaptureMode;     /* 捕捉/比较器模式选择，
                                   取值范围满足宏CHECK_CCP_CAP_MODE的约定条件。 */
    FunctionalState m_PWMInput;        /* PWM测量模式，
                                   取值为TRUE或FALSE。 */
    FunctionalState m_XORMode;         /* 输入异或模式，
                                   取值为TRUE或FALSE。 */
    FunctionalState m_ChannelCompare4; /* 比较器的输出触发捕捉，只有通道4可以配置，
                                   取值为TRUE或FALSE。 */
} CCP_CaptureInitTypeDef;

/**
  * 描述  CCP PWM模式配置信息结构体
  */
typedef struct
{
    uint16_t m_Channel;         /* 通道编号，
                                   取值范围满足“CCP通道”的宏。 */
    uint16_t m_PwmMode;         /* 捕捉/比较器模式选择，
                                   取值范围满足宏CHECK_CCP_PWM_MODE的约定条件。 */
    uint32_t m_DutyRatio;       /* 占空比，
                                   取值范围为32位数据。 */
    uint32_t m_OutputCtl;       /* 通道输出控制，
                                   取值为“CCP通道输出控制”中的一个。 */
    uint32_t m_SinglePWM;       /* 单脉冲输出模式，
                                   取值为TRUE或FALSE。 */
    uint32_t m_CloseTimer;      /* 单脉冲输出模式选择，
                                   取值为TRUE或FALSE。 */
} CCP_PWMInitTypeDef;

/**
  * GPTIM定时器计数模式
  */
#define GPTIM_COUNT_DOWN_UF             ((uint32_t)0x0 << GPTIM_CTL1_TXCMS0_POS)
#define GPTIM_COUNT_UP_OF               ((uint32_t)0x4 << GPTIM_CTL1_TXCMS0_POS)
#define GPTIM_COUNT_UP_DOWN_OF          ((uint32_t)0x1 << GPTIM_CTL1_TXCMS0_POS)
#define GPTIM_COUNT_UP_DOWN_UF          ((uint32_t)0x2 << GPTIM_CTL1_TXCMS0_POS)
#define GPTIM_COUNT_UP_DOWN_OUF         ((uint32_t)0x3 << GPTIM_CTL1_TXCMS0_POS)
#define CHECK_GPTIM_COUNTER_MODE(MODE)  (((MODE) == GPTIM_COUNT_DOWN_UF) \
                                      || ((MODE) == GPTIM_COUNT_UP_OF) \
                                      || ((MODE) == GPTIM_COUNT_UP_DOWN_OF) \
                                      || ((MODE) == GPTIM_COUNT_UP_DOWN_UF) \
                                      || ((MODE) == GPTIM_COUNT_UP_DOWN_OUF))

/**
  * GPTIM定时器工作时钟
  */
#define GPTIM_SCLK                      ((uint32_t)0x0 << GPTIM_CTL1_TXCLK0_POS)
#define GPTIM_HFCLK                     ((uint32_t)0x1 << GPTIM_CTL1_TXCLK0_POS)
#define GPTIM_LFCLK                     ((uint32_t)0x2 << GPTIM_CTL1_TXCLK0_POS)
#define GPTIM_T0_INTLF                  ((uint32_t)0x3 << GPTIM_CTL1_TXCLK0_POS)
#define CHECK_GPTIM_CLOCK_CONFIG(CLK)   (((CLK) == GPTIM_SCLK) \
                                      || ((CLK) == GPTIM_HFCLK) \
                                      || ((CLK) == GPTIM_LFCLK) \
                                      || ((CLK) == GPTIM_T0_INTLF))

/**
  * GPTIM定时/计数模式选择
  */
#define GPTIM_TIMER_MODE                ((uint32_t)0 << GPTIM_CTL1_TXCS_POS)
#define GPTIM_COUNTER_MODE              ((uint32_t)1 << GPTIM_CTL1_TXCS_POS)
#define CHECK_GPTIM_WORK_MODE(MODE)     (((MODE) == GPTIM_TIMER_MODE) \
                                      || ((MODE) == GPTIM_COUNTER_MODE))

/**
  * GPTIM主模式选择
  */
#define GPTIM_MASTER_TXUR_SIGNAL        ((uint32_t)0 << GPTIM_CTL2_TXMMS0_POS)
#define GPTIM_MASTER_TXEN_SIGNAL        ((uint32_t)1 << GPTIM_CTL2_TXMMS0_POS)
#define GPTIM_MASTER_TXIF_SIGNAL        ((uint32_t)2 << GPTIM_CTL2_TXMMS0_POS)
#define GPTIM_MASTER_CCPXCH1IF_SIGNAL   ((uint32_t)3 << GPTIM_CTL2_TXMMS0_POS)
#define GPTIM_MASTER_CCPXCH1_SIGNAL     ((uint32_t)4 << GPTIM_CTL2_TXMMS0_POS)
#define GPTIM_MASTER_CCPXCH2_SIGNAL     ((uint32_t)5 << GPTIM_CTL2_TXMMS0_POS)
#define GPTIM_MASTER_CCPXCH3_SIGNAL     ((uint32_t)6 << GPTIM_CTL2_TXMMS0_POS)
#define GPTIM_MASTER_CCPXCH4_SIGNAL     ((uint32_t)7 << GPTIM_CTL2_TXMMS0_POS)
#define CHECK_GPTIM_MASTER_MODE(MODE)   (((MODE) == GPTIM_MASTER_TXUR_SIGNAL) \
                                      || ((MODE) == GPTIM_MASTER_TXEN_SIGNAL) \
                                      || ((MODE) == GPTIM_MASTER_TXIF_SIGNAL) \
                                      || ((MODE) == GPTIM_MASTER_CCPXCH1IF_SIGNAL) \
                                      || ((MODE) == GPTIM_MASTER_CCPXCH1_SIGNAL) \
                                      || ((MODE) == GPTIM_MASTER_CCPXCH2_SIGNAL) \
                                      || ((MODE) == GPTIM_MASTER_CCPXCH3_SIGNAL) \
                                      || ((MODE) == GPTIM_MASTER_CCPXCH4_SIGNAL))

/**
  * GPTIM从模式选择
  */
#define GPTIM_SLAVE_FORBIDDEN_MODE      ((uint32_t)0 << GPTIM_CTL2_TXSMS0_POS)
#define GPTIM_SLAVE_TRIGGER_MODE        ((uint32_t)4 << GPTIM_CTL2_TXSMS0_POS)
#define GPTIM_SLAVE_GATED_MODE          ((uint32_t)5 << GPTIM_CTL2_TXSMS0_POS)
#define GPTIM_SLAVE_RESET_MODE          ((uint32_t)6 << GPTIM_CTL2_TXSMS0_POS)
#define GPTIM_SLAVE_COUNTER_MODE        ((uint32_t)7 << GPTIM_CTL2_TXSMS0_POS)
#define CHECK_GPTIM_SLAVE_MODE(MODE)    (((MODE) == GPTIM_SLAVE_FORBIDDEN_MODE) \
                                      || ((MODE) == GPTIM_SLAVE_TRIGGER_MODE) \
                                      || ((MODE) == GPTIM_SLAVE_GATED_MODE) \
                                      || ((MODE) == GPTIM_SLAVE_RESET_MODE) \
                                      || ((MODE) == GPTIM_SLAVE_COUNTER_MODE))

/**
  * GPTIM计数模式外部触发脉冲输入同步控制
  */
#define GPTIM_EX_SYNC_MODE              ((uint32_t)0x0 << GPTIM_CTL1_TXSY_POS)
#define GPTIM_NO_SYNC_MODE              ((uint32_t)0x1 << GPTIM_CTL1_TXSY_POS)
#define CHECK_GPTIM_SYNC_MODE(MODE)     (((MODE) == GPTIM_EX_SYNC_MODE) \
                                      || ((MODE) == GPTIM_NO_SYNC_MODE))

/**
  * GPTIM触发选择
  */
#define GPTIM_TRIGGER_T1                ((uint32_t)0x0 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T2                ((uint32_t)0x1 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T3                ((uint32_t)0x2 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T4                ((uint32_t)0x3 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T5                ((uint32_t)0x4 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T9                ((uint32_t)0x5 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T14               ((uint32_t)0x6 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T15               ((uint32_t)0x7 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T18               ((uint32_t)0x8 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T19               ((uint32_t)0x9 << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T20               ((uint32_t)0xA << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_T21               ((uint32_t)0xB << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_TXCK              ((uint32_t)0xC << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_CCPXCH1           ((uint32_t)0xD << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_CCPXCH2           ((uint32_t)0xE << GPTIM_CTL2_TXTS0_POS)
#define GPTIM_TRIGGER_CCPXCH3           ((uint32_t)0xF << GPTIM_CTL2_TXTS0_POS)
#define CHECK_GPTIM_TRIGGER_MODE(MODE)  (((uint32_t)(MODE) & (~GPTIM_CTL2_TXTS)) == 0)

/**
  * CCP通道
  */
#define CCP_CHANNEL_1                   ((uint16_t)0)
#define CCP_CHANNEL_2                   ((uint16_t)1)
#define CCP_CHANNEL_3                   ((uint16_t)2)
#define CCP_CHANNEL_4                   ((uint16_t)3)
#define CHECK_CCP_CHANNEL(CHANNEL)      (((CHANNEL) >> 2) == 0)

/**
  * CCP通道模式选择
  */
#define CCP_MODE_RST                    ((uint16_t)0x0)
#define CCP_CMP_TOGGLE_LEVEL            ((uint16_t)0x2)
#define CCP_CAP_FALLING_EDGE            ((uint16_t)0x4)
#define CCP_CAP_RISING_EDGE             ((uint16_t)0x5)
#define CCP_CAP_4TH_RISING_EDGE         ((uint16_t)0x6)
#define CCP_CAP_16TH_RISING_EDGE        ((uint16_t)0x7)
#define CCP_CMP_ACTIVE_LEVEL            ((uint16_t)0x8)
#define CCP_CMP_INACTIVE_LEVEL          ((uint16_t)0x9)
#define CCP_CMP_SOFT_INT                ((uint16_t)0xA)
#define CCP_CMP_SPECIAL_EVENT           ((uint16_t)0xB)
#define CCP_PWM_MODE                    ((uint16_t)0xC)
#define CHECK_CCP_MODE(MODE)            (((MODE) == CCP_MODE_RST) \
                                      || ((MODE) == CCP_CMP_TOGGLE_LEVEL) \
                                      || ((MODE) == CCP_CAP_RISING_EDGE) \
                                      || ((MODE) == CCP_CAP_FALLING_EDGE) \
                                      || ((MODE) == CCP_CAP_4TH_RISING_EDGE) \
                                      || ((MODE) == CCP_CAP_16TH_RISING_EDGE) \
                                      || ((MODE) == CCP_CMP_ACTIVE_LEVEL) \
                                      || ((MODE) == CCP_CMP_INACTIVE_LEVEL) \
                                      || ((MODE) == CCP_CMP_SOFT_INT) \
                                      || ((MODE) == CCP_CMP_SPECIAL_EVENT) \
                                      || ((MODE) == CCP_PWM_MODE))
#define CHECK_CCP_CAP_MODE(MODE)        (((MODE) == CCP_MODE_RST) \
                                      || ((MODE) == CCP_CAP_RISING_EDGE) \
                                      || ((MODE) == CCP_CAP_FALLING_EDGE) \
                                      || ((MODE) == CCP_CAP_4TH_RISING_EDGE) \
                                      || ((MODE) == CCP_CAP_16TH_RISING_EDGE))
#define CHECK_CCP_CMP_MODE(MODE)        (((MODE) == CCP_MODE_RST) \
                                      || ((MODE) == CCP_CMP_TOGGLE_LEVEL) \
                                      || ((MODE) == CCP_CMP_ACTIVE_LEVEL) \
                                      || ((MODE) == CCP_CMP_INACTIVE_LEVEL) \
                                      || ((MODE) == CCP_CMP_SOFT_INT) \
                                      || ((MODE) == CCP_CMP_SPECIAL_EVENT))
#define CHECK_CCP_PWM_MODE(MODE)        (((MODE) == CCP_MODE_RST) \
                                      || ((MODE) == CCP_PWM_MODE))

/**
  * CCP比较器检测选择
  */
#define CCP_COMPARE_SELECT_1            ((uint32_t)0x0 << CCP_CTL2_PXASS0_POS)
#define CCP_COMPARE_SELECT_2            ((uint32_t)0x1 << CCP_CTL2_PXASS0_POS)
#define CCP_COMPARE_SELECT_3            ((uint32_t)0x2 << CCP_CTL2_PXASS0_POS)
#define CHECK_CCP_COMPARE_SELECT(ASS)   (((ASS) == CCP_COMPARE_SELECT_1) \
                                      || ((ASS) == CCP_COMPARE_SELECT_2) \
                                      || ((ASS) == CCP_COMPARE_SELECT_3))

/**
  * CCP通道输出控制
  */
#define CCP_CHANNEL_OUTPUT_PWM_ACTIVE   ((uint32_t)0x0)
#define CCP_CHANNEL_OUTPUT_PWM_INACTIVE ((uint32_t)0x1)
#define CCP_CHANNEL_OUTPUT_INACTIVE     ((uint32_t)0x2)
#define CCP_CHANNEL_OUTPUT_ACTIVE       ((uint32_t)0x3)
#define CHECK_CCP_CHANNEL_OUTPUT(CTL)   (((CTL) >> 2) == 0)

/**
  * 通用定时器、CCP函数定义
  */
/* 通用定时器(GPTIM)初始化及配置函数定义 *********************************/
void GPTIM_Reset (GPTIM_SFRmap*  GPTIMx);
void GPTIM_Configuration(GPTIM_SFRmap* GPTIMx,
                    GPTIM_InitTypeDef* gptimInitStruct);
void GPTIM_Struct_Init (GPTIM_InitTypeDef* gptimInitStruct);
void GPTIM_Cmd (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Set_Counter (GPTIM_SFRmap* GPTIMx, uint32_t Counter);
void GPTIM_Set_Period (GPTIM_SFRmap* GPTIMx, uint32_t Period);
void GPTIM_Set_Prescaler (GPTIM_SFRmap* GPTIMx, uint32_t Prescaler);
void GPTIM_Counter_Mode_Config (GPTIM_SFRmap* GPTIMx, uint32_t CounterMode);
void GPTIM_Clock_Config (GPTIM_SFRmap* GPTIMx, uint32_t NewClock);
void GPTIM_External_Pulse_Sync_Config (GPTIM_SFRmap* GPTIMx,
                    uint32_t PulseSync);
void GPTIM_Work_Mode_Config (GPTIM_SFRmap* GPTIMx, uint32_t NewState);
void GPTIM_Updata_Immediately_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
void GPTIM_Master_Slave_Snyc_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
void GPTIM_Trigger_Select_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState TriggerSelect);
void GPTIM_Slave_Mode_Config (GPTIM_SFRmap* GPTIMx, FunctionalState SlaveMode);
void GPTIM_Master_Mode_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState MasterMode);
void GPTIM_Updata_Rising_Edge_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
void GPTIM_Updata_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Trigger_DMA_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Updata_DMA_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Updata_INT_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Trigger_INT_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Generate_Trigger_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
DIRStatus GPTIM_Get_Direction (GPTIM_SFRmap* GPTIMx);
uint32_t GPTIM_Get_Counter (GPTIM_SFRmap* GPTIMx);
uint32_t GPTIM_Get_Period (GPTIM_SFRmap* GPTIMx);
uint32_t GPTIM_Get_Prescaler (GPTIM_SFRmap* GPTIMx);
/* 通用定时器(GPTIM)中断及标志管理函数定义 *******************************/
void GPTIM_Overflow_INT_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
RetStatus GPTIM_Clear_Overflow_INT_Flag (GPTIM_SFRmap* GPTIMx);
RetStatus GPTIM_Clear_Updata_INT_Flag (GPTIM_SFRmap* GPTIMx);
RetStatus GPTIM_Clear_Trigger_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Overflow_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Updata_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Trigger_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Updata_DMA_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Trigger_DMA_INT_Flag (GPTIM_SFRmap* GPTIMx);
/* 通用捕捉/比较/PWM外设(CCP)捕捉功能函数定义 ****************************/
void CCP_Compare_Configuration(CCP_SFRmap* CCPx,
                    CCP_CompareInitTypeDef* ccpInitStruct);
void CCP_Compare_Struct_Init (CCP_CompareInitTypeDef* ccpInitStruct);
void CCP_Capture_Configuration (CCP_SFRmap* CCPx,
                    CCP_CaptureInitTypeDef* ccpInitStruct);
void CCP_Capture_Struct_Init (CCP_CaptureInitTypeDef* ccpInitStruct);
void CCP_PWM_Configuration (CCP_SFRmap* CCPx,
                    CCP_PWMInitTypeDef* ccpInitStruct);
void CCP_PWM_Struct_Init (CCP_PWMInitTypeDef* ccpInitStruct);
void CCP_Capture_Mode_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t EdgeConfig);
void CCP_Compare_Mode_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t EdgeConfig);
void CCP_PWM_Mode_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t EdgeConfig);
uint32_t CCP_Get_Capture_Result (CCP_SFRmap* CCPx, uint32_t Channel);
void CCP_Set_Compare_Result (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t Value);
#define CCP_Set_PWM_Duty_Ratio(CCPX, CHANNEL, VALUE)  \
        CCP_Set_Compare_Result(CCPX, CHANNEL, VALUE)
uint32_t CCP_Get_Compare_Result (CCP_SFRmap* CCPx, uint32_t Channel);
#define CCP_Get_PWM_Duty_Ratio(CCPX, CHANNEL)  \
        CCP_Get_Compare_Result(CCPX, CHANNEL)
void CCP_Compare_PWM_Signal_Clear (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_Compare_Check_Config (CCP_SFRmap* CCPx, uint32_t CompareSelect);
void CCP_Channel_Output_Control (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t ChannelOutputCtl);
void CCP_Single_Pulse_Shut_Enable (CCP_SFRmap* CCPx, FunctionalState NewState);
void CCP_Single_Pulse_Enable (CCP_SFRmap* CCPx, FunctionalState NewState);
void CCP_PWM_Input_Measurement_Config (CCP_SFRmap* CCPx,
                    FunctionalState NewState);
void CCP_Input_XOR_Config (CCP_SFRmap* CCPx, FunctionalState NewState);
void CCP_Channel_DMA_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_Generate_Trigger_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_USART_Receive_Config (CCP_SFRmap* CCPx, FunctionalState NewState);
/* 通用捕捉/比较/PWM外设(CCP)中断及标志管理函数定义 **********************/
FlagStatus CCP_Get_Channel_Trigger_INT_Flag (CCP_SFRmap* CCPx, uint32_t Channel);
FlagStatus CCP_Get_Trigger_DMA_INT_Flag (CCP_SFRmap* CCPx, uint32_t Channel);
void CCP_Channel_INT_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
RetStatus CCP_Clear_Channel_INT_Flag (CCP_SFRmap* CCPx, uint32_t Channel);
/*** 通用定时器(GPTIM)、CCP相关定义结束  */


#endif /* KF32A1x6_GTIM_H_ */
