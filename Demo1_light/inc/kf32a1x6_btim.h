/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_btim.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the BTIM 			  *
 						peripherals.										  *	
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
#ifndef KF32A1x6_BTIM_H_
#define KF32A1x6_BTIM_H_

#include "kf32a1x6.h"

/* 定时器名称校验 */

/* 定时器指针定义 */
#define T0_TYPE                         (GPTIM_SFRmap *)
#define T1_TYPE                         (GPTIM_SFRmap *)
#define T2_TYPE                         (GPTIM_SFRmap *)
#define T3_TYPE                         (GPTIM_SFRmap *)
#define T4_TYPE                         (GPTIM_SFRmap *)
#define T5_TYPE                         (ATIM_SFRmap *)
#define T6_TYPE                         (ATIM_SFRmap *)
#define T14_TYPE                        (BTIM_SFRmap *)
#define T18_TYPE                        (GPTIM_SFRmap *)
#define T19_TYPE                        (GPTIM_SFRmap *)
#define T21_TYPE                        (GPTIM_SFRmap *)
#define CHECK_TIM_ALL_PERIPH(ADDR)      (((ADDR) == T0_ADDR) \
                                      || ((ADDR) == T1_ADDR) \
                                      || ((ADDR) == T2_ADDR) \
                                      || ((ADDR) == T3_ADDR) \
                                      || ((ADDR) == T4_ADDR) \
                                      || ((ADDR) == T5_ADDR) \
                                      || ((ADDR) == T6_ADDR) \
                                      || ((ADDR) == T14_ADDR) \
                                      || ((ADDR) == T18_ADDR) \
                                      || ((ADDR) == T19_ADDR) \
                                      || ((ADDR) == T21_ADDR))

#define CHECK_BTIM_PERIPH(PERIPH)       ((PERIPH) == T14_SFR)

/*** 基本定时器(BTIM)相关定义  */

/**
  * 描述  基本定时器(BTIM)配置信息结构体
  */
typedef struct
{
    uint16_t m_Counter;         /* 定时器计数值，取值16位数据。 */
    uint16_t m_Period;          /* 定时器周期值，取值16位数据。 */
    uint16_t m_Prescaler;       /* 定时器预分频值，取值16位数据。 */
    uint16_t m_CounterMode;     /* 定时器计数模式，
                                   取值为宏“BTIM定时器计数模式”中的一个 */
    uint16_t m_Clock;           /* 定时器工作时钟，
                                   取值为宏“BTIM定时器工作时钟”中的一个 */
    uint16_t m_WorkMode;        /* 定时/计数模式选择
                                   取值为宏“BTIM定时/计数模式选择”中的一个 */
    uint16_t m_MasterMode;      /* 主模式选择，
                                   取值为宏“BTIM主模式选择”中的一个 */
    uint16_t m_SlaveMode;       /* 从模式选择，
                                   取值为宏“BTIM从模式选择”中的一个 */
    uint16_t m_EXPulseSync;     /* Tx计数模式外部触发脉冲输入同步控制，
                                   取值为宏“BTIM计数模式外部触发脉冲输入同步控制”中的一个 */
    uint16_t m_MasterSlaveSync; /* 主从模式同步控制，
                                   取值为TRUE或FALSE */
} BTIM_InitTypeDef; /* T14 / T15 */


/**
  * BTIM定时器计数模式
  */
#define BTIM_COUNT_DOWN_UF              ((uint32_t)0 << BTIM_CTL1_TXCMS0_POS)
#define BTIM_COUNT_UP_OF                ((uint32_t)4 << BTIM_CTL1_TXCMS0_POS)
#define BTIM_COUNT_UP_DOWN_OF           ((uint32_t)1 << BTIM_CTL1_TXCMS0_POS)
#define BTIM_COUNT_UP_DOWN_UF           ((uint32_t)2 << BTIM_CTL1_TXCMS0_POS)
#define BTIM_COUNT_UP_DOWN_OUF          ((uint32_t)3 << BTIM_CTL1_TXCMS0_POS)
#define CHECK_BTIM_COUNTER_MODE(MODE)   ((((MODE) & 0x3F) == 0) && \
                                         (((MODE) >> 9) == 0))

/**
  * BTIM定时器工作时钟
  */
#define BTIM_SCLK                       ((uint32_t)0 << BTIM_CTL1_TXCLK0_POS)
#define BTIM_HFCLK                      ((uint32_t)1 << BTIM_CTL1_TXCLK0_POS)
#define BTIM_LFCLK                      ((uint32_t)2 << BTIM_CTL1_TXCLK0_POS)
#define CHECK_BTIM_CLOCK_CONFIG(CLK)    ((((CLK) & 0x7) == 0) && \
                                         (((CLK) >> 5) == 0))

/**
  * BTIM定时/计数模式选择
  */
#define BTIM_TIMER_MODE                 ((uint32_t)0 << BTIM_CTL1_TXCS_POS)
#define BTIM_COUNTER_MODE               ((uint32_t)1 << BTIM_CTL1_TXCS_POS)
#define CHECK_BTIM_WORK_MODE(MODE)      (((MODE) == BTIM_TIMER_MODE) \
                                      || ((MODE) == BTIM_COUNTER_MODE))

/**
  * BTIM主模式选择
  */
#define BTIM_MASTER_TXUR_SIGNAL           ((uint32_t)0 << BTIM_CTL2_TXMMS0_POS)
#define BTIM_MASTER_TXEN_SIGNAL           ((uint32_t)1 << BTIM_CTL2_TXMMS0_POS)
#define BTIM_MASTER_TXIF_SIGNAL           ((uint32_t)2 << BTIM_CTL2_TXMMS0_POS)
#define CHECK_BTIM_MASTER_MODE(MODE)     (((MODE) == BTIM_MASTER_TXUR_SIGNAL) \
                                      || ((MODE) == BTIM_MASTER_TXEN_SIGNAL) \
                                      || ((MODE) == BTIM_MASTER_TXIF_SIGNAL))

/**
  * BTIM从模式选择
  */
#define BTIM_SLAVE_FORBIDDEN_MODE       ((uint32_t)0 << BTIM_CTL2_TXSMS0_POS)
#define BTIM_SLAVE_TRIGGER_MODE         ((uint32_t)4 << BTIM_CTL2_TXSMS0_POS)
#define BTIM_SLAVE_GATED_MODE           ((uint32_t)5 << BTIM_CTL2_TXSMS0_POS)
#define BTIM_SLAVE_RESET_MODE           ((uint32_t)6 << BTIM_CTL2_TXSMS0_POS)
#define BTIM_SLAVE_COUNTER_MODE         ((uint32_t)7 << BTIM_CTL2_TXSMS0_POS)
#define CHECK_BTIM_SLAVE_MODE(MODE)     (((MODE) == BTIM_SLAVE_FORBIDDEN_MODE) \
                                      || ((MODE) == BTIM_SLAVE_TRIGGER_MODE) \
                                      || ((MODE) == BTIM_SLAVE_GATED_MODE) \
                                      || ((MODE) == BTIM_SLAVE_RESET_MODE) \
                                      || ((MODE) == BTIM_SLAVE_COUNTER_MODE))

/**
  * BTIM计数模式外部触发脉冲输入同步控制
  */
#define BTIM_EX_SYNC_MODE               ((uint32_t)0 << BTIM_CTL1_TXSY_POS)
#define BTIM_NO_SYNC_MODE               ((uint32_t)1 << BTIM_CTL1_TXSY_POS)
#define CHECK_BTIM_SYNC_MODE(MODE)      (((MODE) == BTIM_EX_SYNC_MODE) \
                                      || ((MODE) == BTIM_NO_SYNC_MODE))

/**
  * BTIM触发选择
  */
#define BTIM_TRIGGER_T1                 ((uint32_t)0 << BTIM_CTL2_TXTS0_POS)
#define BTIM_TRIGGER_T2                 ((uint32_t)1 << BTIM_CTL2_TXTS0_POS)
#define BTIM_TRIGGER_T3                 ((uint32_t)2 << BTIM_CTL2_TXTS0_POS)
#define BTIM_TRIGGER_T4                 ((uint32_t)3 << BTIM_CTL2_TXTS0_POS)
#define BTIM_TRIGGER_T5                 ((uint32_t)4 << BTIM_CTL2_TXTS0_POS)
#define BTIM_TRIGGER_T14                ((uint32_t)6 << BTIM_CTL2_TXTS0_POS)
#define BTIM_TRIGGER_T18                ((uint32_t)8 << BTIM_CTL2_TXTS0_POS)
#define BTIM_TRIGGER_T19                ((uint32_t)9 << BTIM_CTL2_TXTS0_POS)
#define BTIM_TRIGGER_T21                ((uint32_t)0xB << BTIM_CTL2_TXTS0_POS)
#define BTIM_TRIGGER_TXCK               ((uint32_t)0xC << BTIM_CTL2_TXTS0_POS)
#define CHECK_BTIM_TRIGGER_MODE(MODE)   (((MODE) == BTIM_TRIGGER_T1) \
                                      || ((MODE) == BTIM_TRIGGER_T2) \
                                      || ((MODE) == BTIM_TRIGGER_T3) \
                                      || ((MODE) == BTIM_TRIGGER_T4) \
                                      || ((MODE) == BTIM_TRIGGER_T5) \
                                      || ((MODE) == BTIM_TRIGGER_T14) \
                                      || ((MODE) == BTIM_TRIGGER_T18) \
                                      || ((MODE) == BTIM_TRIGGER_T19) \
                                      || ((MODE) == BTIM_TRIGGER_T21) \
                                      || ((MODE) == BTIM_TRIGGER_TXCK))


/* 定时器外设复位函数定义 ************************************************/
void TIM_Reset (void* TIMx);
void BTIM_Reset (BTIM_SFRmap* BTIMx);

/* 基本定时器(BTIM)初始化及配置函数定义 **********************************/
void BTIM_Configuration (BTIM_SFRmap* BTIMx,BTIM_InitTypeDef* btimInitStruct);
void BTIM_Struct_Init (BTIM_InitTypeDef* btimInitStruct);
void BTIM_Cmd (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Set_Counter (BTIM_SFRmap* BTIMx, uint16_t Counter);
void BTIM_Set_Period (BTIM_SFRmap* BTIMx, uint16_t Period);
void BTIM_Set_Prescaler (BTIM_SFRmap* BTIMx, uint16_t Prescaler);
void BTIM_Counter_Mode_Config (BTIM_SFRmap* BTIMx, uint32_t CounterMode);
void BTIM_Clock_Config (BTIM_SFRmap* BTIMx, uint32_t NewClock);
void BTIM_External_Pulse_Sync_Config (BTIM_SFRmap* BTIMx, uint32_t PulseSync);
void BTIM_Work_Mode_Config (BTIM_SFRmap* BTIMx, uint32_t NewState);
void BTIM_Generate_Trigger_Config (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Single_Pulse_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Single_Pulse_Shut_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Updata_Immediately_Config (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Master_Slave_Snyc_Config (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Trigger_Select_Config (BTIM_SFRmap* BTIMx,uint32_t TriggerSelect);
void BTIM_Slave_Mode_Config (BTIM_SFRmap* BTIMx,uint32_t SlaveMode);
void BTIM_Master_Mode_Config (BTIM_SFRmap* BTIMx,uint32_t MasterMode);
void BTIM_Updata_Rising_Edge_Config (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Updata_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState);
DIRStatus BTIM_Get_Direction (BTIM_SFRmap* BTIMx);
uint16_t BTIM_Get_Counter (BTIM_SFRmap* BTIMx);
uint16_t BTIM_Get_Period (BTIM_SFRmap* BTIMx);
uint16_t BTIM_Get_Prescaler (BTIM_SFRmap* BTIMx);

/* 基本定时器(BTIM)中断及标志管理函数 ************************************/
void BTIM_Trigger_DMA_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Updata_DMA_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Overflow_INT_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Trigger_INT_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Updata_INT_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState);
INTStatus BTIM_Get_Trigger_DMA_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Updata_DMA_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Overflow_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Trigger_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Updata_INT_Status (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Trigger_DMA_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Updata_DMA_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Overflow_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Trigger_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Updata_INT_Flag (BTIM_SFRmap* BTIMx);
RetStatus BTIM_Clear_Overflow_INT_Flag (BTIM_SFRmap* BTIMx);
RetStatus BTIM_Clear_Trigger_INT_Flag (BTIM_SFRmap* BTIMx);
RetStatus BTIM_Clear_Updata_INT_Flag (BTIM_SFRmap* BTIMx);

/*** 基本定时器(BTIM)相关定义结束  */

#endif /* KF32A1x6_BTIM_H_ */
