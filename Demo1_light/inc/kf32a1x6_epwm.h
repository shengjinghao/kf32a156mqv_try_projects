/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_epwm.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the EPWM 			  *
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
#ifndef KF32A1x6_EPWM_H_
#define KF32A1x6_EPWM_H_

#include "kf32a1x6.h"

/**
  * EPWM外设判断
  */
#define CHECK_EPWM_ALL_PERIPH(PERIPH)    				(((PERIPH) == EPWM11_SFR) \
                                       	   	   	   	 || ((PERIPH) == EPWM12_SFR) \
                                       	   	   	   	 || ((PERIPH) == EPWM13_SFR) \
                                       	   	   	   	 || ((PERIPH) == EPWM16_SFR))

/**
 * 	8、16、32位值限制
 * */
#define CHECK_EPWM_8BIT_LIMIT(VALUE)					((VALUE) <= 0xFF)
#define CHECK_EPWM_16BIT_LIMIT(VALUE)					((VALUE) <= 0xFFFF)
#define CHECK_EPWM_32BIT_LIMIT(VALUE)					((VALUE) <= 0xFFFFFFFF)

/**
 * 	子模块寄存器锁
 * */
#define EPWM_SUBMODULE_CHANNELA_AQ_LOCK					((uint32_t)0)
#define EPWM_SUBMODULE_CHANNELB_AQ_LOCK					((uint32_t)1)
#define EPWM_SUBMODULE_DB_LOCK							((uint32_t)2)
#define EPWM_SUBMODULE_PC_LOCK							((uint32_t)3)
#define EPWM_SUBMODULE_ET_LOCK							((uint32_t)4)
#define EPWM_SUBMODULE_HRPWM_LOCK						((uint32_t)5)
#define CHECK_EPWM_SUBMODULE_LOCK(Select)				((Select) <= EPWM_SUBMODULE_HRPWM_LOCK)

/**
 * 	捕捉事件选择
 * */
#define EPWM_CAP_TRIGGER_EVENT_TZ1						((uint32_t)0)
#define EPWM_CAP_TRIGGER_EVENT_TZ2						((uint32_t)1)
#define EPWM_CAP_TRIGGER_EVENT_TZ3						((uint32_t)2)
#define EPWM_CAP_TRIGGER_EVENT_TZ4						((uint32_t)3)
#define CHECK_EPWM_CAP_TRIGGER_EVENT(SELSECT)			((SELSECT) <= EPWM_CAP_TRIGGER_EVENT_TZ4)

/**
 * 	配置相位方向控制
 * */
#define EPWM_SYNC_TRIGGER_DOWM							((uint32_t)0)
#define EPWM_SYNC_TRIGGER_UP							((uint32_t)1)
#define CHECK_EPWM_SYNC_TRIGGER_DIRECTION(SEL)			((SEL) <= EPWM_SYNC_TRIGGER_UP)

/**
 * 	 同步事件输出选择
 * */
#define EPWM_SYNC_EVENT_OUT_EPWM_SWF					((uint32_t)0)
#define EPWM_SYNC_EVENT_OUT_COUNT0						((uint32_t)1)
#define EPWM_SYNC_EVENT_OUT_EPWMRB						((uint32_t)2)
#define EPWM_SYNC_EVENT_OUT_DISABLE						((uint32_t)3)
#define CHECK_EPWM_SYNC_EVENT_OUT(SEL)					((SEL) <= EPWM_SYNC_EVENT_OUT_DISABLE)

/**
 * 	Tx计数模式
 * */
#define EPWM_COUNT_DOWM_UF								((uint32_t)0)
#define EPWM_COUNT_UP_OF								((uint32_t)4)
#define EPWM_COUNT_UP_DOWM_OF							((uint32_t)5)
#define EPWM_COUNT_UP_DOWM_UF							((uint32_t)6)
#define EPWM_COUNT_UP_DOWM_OUF							((uint32_t)7)
#define CHECK_EPWM_COUNT_MODE(SEL)						(((SEL) == EPWM_COUNT_DOWM_UF) \
													  || ((SEL) == EPWM_COUNT_UP_OF) \
													  || ((SEL) == EPWM_COUNT_UP_DOWM_OF) \
													  || ((SEL) == EPWM_COUNT_UP_DOWM_UF) \
													  || ((SEL) == EPWM_COUNT_UP_DOWM_OUF))

/**
 * 	Tx工作时钟选择
 * */
#define EPWM_CLK_SCLK									((uint32_t)0)
#define EPWM_CLK_HFCLK									((uint32_t)1)
#define EPWM_CLK_LFCLK									((uint32_t)3)
#define CHECK_EPWM_CLK(CLK)								((CLK) <= EPWM_CLK_LFCLK)

/**
 * 	Tx定时/计数模式
 * */
#define EPWM_TIMER_MODE									((uint32_t)0)
#define EPWM_COUNTER_MODE								((uint32_t)1)
#define CHECK_EPWM_MODE(SEL)							((SEL) <= EPWM_COUNTER_MODE)

/**
 * 	寄存器A/寄存器B/寄存器C/寄存器D
 * */
#define EPWM_REGISTER_A									((uint32_t)0)
#define EPWM_REGISTER_B									((uint32_t)1)
#define EPWM_REGISTER_C									((uint32_t)2)
#define EPWM_REGISTER_D									((uint32_t)3)
#define CHECK_EPWM_REGISTER_AB(SEL)						((SEL) <= EPWM_REGISTER_D)

/**
 * 	EPWMA/EPWMB强制输出电平
 * */
#define EPWM_OUT_NONE			                        ((uint32_t)0)
#define EPWM_OUT_LOW 			                        ((uint32_t)1)
#define EPWM_OUT_HIGH			                        ((uint32_t)2)
#define EPWM_OUT_TOGGLE						            ((uint32_t)3)
#define EPWM_OUT_PROHIBIT						        ((uint32_t)3)
#define CHECK_EPWM_MANDATORY_OUT(SEL)					((SEL) <= EPWM_OUT_TOGGLE)

/**
 *  当Tx计数值等于EPWMx_RAB寄存器且计数方向向x时，EPWMxAB输出
 * */
#define EPWM_CERB_DD_EPWMAB_OUT	                        ((uint32_t)5)
#define EPWM_CERB_DU_EPWMAB_OUT	                        ((uint32_t)4)
#define EPWM_CERA_DD_EPWMAB_OUT	                        ((uint32_t)3)
#define EPWM_CERA_DU_EPWMAB_OUT	                        ((uint32_t)2)
#define EPWM_CEPPX_EPWMAB_OUT                           ((uint32_t)1)
#define EPWM_CE0_EPWMAB_OUT                             ((uint32_t)0)
#define CHECK_EPWM_TXCOUNT_EQUAL_XX_EPWMAB_OUT(SEL)			((SEL) <= EPWM_CERB_DD_EPWMAB_OUT)

/**
 * 	死区输入选择
 * */
#define EPWM_EPWMA_UP_EPWMA_DOWM						((uint32_t)0)
#define EPWM_EPWMB_UP_EPWMA_DOWM						((uint32_t)1)
#define EPWM_EPWMA_UP_EPWMB_DOWM						((uint32_t)2)
#define EPWM_EPWMB_UP_EPWMB_DOWM						((uint32_t)3)
#define CHECK_EPWM_DEAD_ZONE(SEL)						((SEL) <= EPWM_EPWMB_UP_EPWMB_DOWM)

/**
 * 	死区输出极性选择
 * */
#define EPWM_EPWMA_NTOGGLE_EPWMB_NTOGGLE				((uint32_t)0)
#define EPWM_EPWMA_TOGGLE_EPWMB_NTOGGLE					((uint32_t)1)
#define EPWM_EPWMA_NTOGGLE_EPWMB_TOGGLE					((uint32_t)2)
#define EPWM_EPWMA_TOGGLE_EPWMB_TOGGLE					((uint32_t)3)
#define CHECK_EPWM_DEAD_ZONE_OUT_POLARITY(SEL)			((SEL) <= EPWM_EPWMA_TOGGLE_EPWMB_TOGGLE)

/**
 * 	死区输出选择
 * */
#define EPWM_UP_BYPASS_DOWN_BYPASS						((uint32_t)0)
#define EPWM_UP_BYPASS_DOWN_ENABLE						((uint32_t)1)
#define EPWM_UP_ENABLE_DOWN_BYPASS						((uint32_t)2)
#define EPWM_UP_ENABLE_DOWN_ENABLE						((uint32_t)3)
#define CHECK_EPWM_DEAD_ZONE_OUT(SEL)					((SEL) <= EPWM_UP_ENABLE_DOWN_ENABLE)

/**
 *	死区时间设置
 * */
#define EPWM_DOWM_EDGE_DEAD_ZONE						((uint32_t)0)
#define EPWM_UP_EDGE_DEAD_ZONE							((uint32_t)1)
#define CHECK_EPWM_UP_DOWN_EDGE_DEAD_ZONE(SEL)			((SEL) <= EPWM_UP_EDGE_DEAD_ZONE)

/**
 * 	PCLK频率设置
 * */
#define EPWM_PCLK_DIV1									((uint32_t)0)
#define EPWM_PCLK_DIV2									((uint32_t)1)
#define EPWM_PCLK_DIV3									((uint32_t)2)
#define EPWM_PCLK_DIV4									((uint32_t)3)
#define EPWM_PCLK_DIV5									((uint32_t)4)
#define EPWM_PCLK_DIV6									((uint32_t)5)
#define EPWM_PCLK_DIV7									((uint32_t)6)
#define EPWM_PCLK_DIV8									((uint32_t)7)
#define CHECK_EPWM_PCLK_DIV(DIV)						((DIV) <= EPWM_PCLK_DIV8)

/**
 * 	PCLK占空比设置
 * */
#define EPWM_PCLK_DUTY_CYCLE78							((uint32_t)0)
#define EPWM_PCLK_DUTY_CYCLE68							((uint32_t)1)
#define EPWM_PCLK_DUTY_CYCLE58							((uint32_t)2)
#define EPWM_PCLK_DUTY_CYCLE48							((uint32_t)3)
#define EPWM_PCLK_DUTY_CYCLE38							((uint32_t)4)
#define EPWM_PCLK_DUTY_CYCLE28							((uint32_t)5)
#define EPWM_PCLK_DUTY_CYCLE18							((uint32_t)6)
#define CHECK_EPWM_PCLK_DUTY_CYCLE(SEL)					((SEL) <= EPWM_PCLK_DUTY_CYCLE18)

/**
 * 	斩波第一个脉冲宽度选择
 * */
#define EPWM_CHOPPING_PULSE_WIDTH1                       ((uint32_t)0)
#define EPWM_CHOPPING_PULSE_WIDTH2                       ((uint32_t)1)
#define EPWM_CHOPPING_PULSE_WIDTH3                       ((uint32_t)2)
#define EPWM_CHOPPING_PULSE_WIDTH4                       ((uint32_t)3)
#define EPWM_CHOPPING_PULSE_WIDTH5                       ((uint32_t)4)
#define EPWM_CHOPPING_PULSE_WIDTH6                       ((uint32_t)5)
#define EPWM_CHOPPING_PULSE_WIDTH7                       ((uint32_t)6)
#define EPWM_CHOPPING_PULSE_WIDTH8                       ((uint32_t)7)
#define EPWM_CHOPPING_PULSE_WIDTH9                       ((uint32_t)8)
#define EPWM_CHOPPING_PULSE_WIDTH10                      ((uint32_t)9)
#define EPWM_CHOPPING_PULSE_WIDTH11                      ((uint32_t)10)
#define EPWM_CHOPPING_PULSE_WIDTH12                      ((uint32_t)11)
#define EPWM_CHOPPING_PULSE_WIDTH13                      ((uint32_t)12)
#define EPWM_CHOPPING_PULSE_WIDTH14                      ((uint32_t)13)
#define EPWM_CHOPPING_PULSE_WIDTH15                      ((uint32_t)14)
#define EPWM_CHOPPING_PULSE_WIDTH16                      ((uint32_t)15)
#define CHECK_EPWM_CHOPPING_PULSE_WIDTH(SEL)			 ((SEL) <= EPWM_CHOPPING_PULSE_WIDTH16)

/**
 * 	EPWMx自动重启
 * */
#define EPWM_PXASE_SOFTWARE_CLEAR_RESET						((uint32_t)0)
#define EPWM_PXASE_AUTO_CLEAR_RESET							((uint32_t)1)
#define CHECK_EPWM_PXASE_CLEAR_RESET(SEL)					((SEL) <= EPWM_PXASE_AUTO_CLEAR_RESET)

/**
 * 	引脚EPWMxAB关闭状态控制
 * */
#define EPWM_DRIVER_PIN_EPWMAB_LOW						((uint32_t)0)
#define EPWM_DRIVER_PIN_EPWMAB_HIGH						((uint32_t)1)
#define EPWM_DRIVER_PIN_EPWMAB_3STATUS					((uint32_t)3)
#define CHECK_EPWM_DRIVER_PIN_EPWMAB(SEL)				((SEL) <= EPWM_DRIVER_PIN_EPWMAB_3STATUS)

/**
 * 	EPWMx自动关闭源选择
 * */
#define EPWM_AUTO_SHOWDOWN_SOURCE_NO                    ((uint32_t)0)
#define EPWM_AUTO_SHOWDOWN_SOURCE_TZ1_HIGH              ((uint32_t)1)
#define EPWM_AUTO_SHOWDOWN_SOURCE_TZ2_HIGH              ((uint32_t)2)
#define EPWM_AUTO_SHOWDOWN_SOURCE_TZ3_HIGH              ((uint32_t)3)
#define EPWM_AUTO_SHOWDOWN_SOURCE_TZ4_HIGH              ((uint32_t)4)
#define EPWM_AUTO_SHOWDOWN_SOURCE_CLKIF                 ((uint32_t)5)
#define EPWM_AUTO_SHOWDOWN_SOURCE_QEIIF                 ((uint32_t)6)
#define CHECK_EPWM_AUTO_SHOWDOWN_SOURCE(SEL)			((SEL) <= EPWM_AUTO_SHOWDOWN_SOURCE_QEIIF)

/**
 * 	触发AD事件
 * */
#define EPWM_TRIGGER_AD_EVENT0							((uint32_t)0)
#define EPWM_TRIGGER_AD_EVENT1							((uint32_t)1)
#define CHECK_EPWM_TRIGGER_AD_EVENT(EVENT)				((EVENT) <= EPWM_TRIGGER_AD_EVENT1)

/**
 *  触发AD时的计数方向
 * */
#define EPWM_TRIGGER_AD_UP								((uint32_t)0)
#define EPWM_TRIGGER_AD_DOWM							((uint32_t)1)
#define EPWM_TRIGGER_AD_UD								((uint32_t)2)
#define CHECK_EPWM_TRIGGER_AD_UD(DIR)					((DIR) <= EPWM_TRIGGER_AD_UD)

/**
 * 	触发AD事件周期选择
 * */
#define EPWM_1_TRIGGER_EVENT_TRIGGER_AD                 ((uint32_t)0)
#define EPWM_2_TRIGGER_EVENT_TRIGGER_AD              	((uint32_t)1)
#define EPWM_3_TRIGGER_EVENT_TRIGGER_AD              	((uint32_t)2)
#define EPWM_4_TRIGGER_EVENT_TRIGGER_AD              	((uint32_t)3)
#define CHECK_EPWM_TRIGGER_EVENT_TRIGGER_AD(SEL)		((SEL) <= EPWM_4_TRIGGER_EVENT_TRIGGER_AD)

/**
 * 	触发AD事件选择
 * */
#define EPWM_TIMER_EQUAL_0PULSE							((uint32_t)0)
#define EPWM_TIMER_EQUAL_PPPULSE						((uint32_t)1)
#define EPWM_TIMER_EQUAL_DUTYA							((uint32_t)2)
#define EPWM_TIMER_EQUAL_DUTYB							((uint32_t)3)
#define CEHCK_EPWM_TRIGGER_AD_EVENT(SEL)				((SEL) <= EPWM_TIMER_EQUAL_DUTYB)

/**
 * 	标志位
 * */
#define EPWM_SHOTDOWN_EVENT								((uint32_t)2)
#define EPWM_UPDATA_EVENT								((uint32_t)3)
#define EPWM_COUNT_OVERFLOW								((uint32_t)4)
#define EPWM_COUNT_EQUAL_EPWMRB							((uint32_t)5)
#define EPWM_COUNT_EQUAL_EPWMRA							((uint32_t)6)
#define EPWM_COUNT_EQUAL_EPWMRC							((uint32_t)7)
#define EPWM_COUNT_EQUAL_EPWMRD							((uint32_t)8)
#define CHECK_EPWM_FALG(SEL)							((SEL) <= EPWM_COUNT_EQUAL_EPWMRD)

/**
 * 	HRPWM输出B端控制
 * */
#define EPWM_EPWMB_NORMAL_OUTPUT						((uint32_t)0)
#define EPWM_EPWMB_REVERSE_OUTPUT_EPWMA					((uint32_t)1)
#define CHECK_EPWM_EPWMB_OUTPUT(SEL)					((SEL) <= EPWM_EPWMB_REVERSE_OUTPUT_EPWMA)

/**
 * 	x_PPX周期寄存器更新事件选择
 * */
#define EPWM_COUNT_VALUE_EQUAL_0						((uint32_t)0)
#define EPWM_COUNT_VALUE_EQUAL_TxPPX					((uint32_t)1)
#define EPWM_COUNT_VALUE_EQUAL_0_TxPPX					((uint32_t)2)
#define EPWM_INPUT_SYCN_SINGLE							((uint32_t)3)
#define CEHCK_EPWM_TXPPX_CYCLE_UPDATA_EVENT(SEL)		((SEL) <= EPWM_INPUT_SYCN_SINGLE)

/**
 * 	UDCTL EPWMx更新控制寄存器
 * */
#define EPWM_UDCTL_PPUD									((uint32_t)0)
#define EPWM_UDCTL_PRUD									((uint32_t)1)
#define EPWM_UDCTL_CMAUD								((uint32_t)2)
#define EPWM_UDCTL_CMBUD								((uint32_t)3)
#define EPWM_UDCTL_CMCUD								((uint32_t)4)
#define EPWM_UDCTL_CMDUD								((uint32_t)5)
#define EPWM_UDCTL_EAUD									((uint32_t)6)
#define EPWM_UDCTL_EBUD									((uint32_t)7)
#define EPWM_UDCTL_HRPUD								((uint32_t)8)
#define CHECK_EPWM_UDCTL_UD(SEL)						((SEL) <= EPWM_UDCTL_HRPUD)


void EPWM_Reset (EPWM_SFRmap* EPWMx);
void EPWM_TxCNT_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value);
uint32_t EPWM_Get_TxCNT_Value(EPWM_SFRmap* EPWMx);
void EPWM_TxPHS_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value);
uint32_t EPWM_Get_TxPHS_Value(EPWM_SFRmap* EPWMx);
void EPWM_TxPPX_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value);
uint32_t EPWM_Get_TxPPX_Value(EPWM_SFRmap* EPWMx);
void EPWM_TxPRSC_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value);
uint32_t EPWM_Get_TxPRSC_Value(EPWM_SFRmap* EPWMx);
void EPWM_Response_UpperLevel_LINK_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_NextLevel_LINK_Ask_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_SYNC_Single_Trigger_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Submodule_Register_Lock_Config(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState);
void EPWM_Cap_Function_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Cap_Trigger_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
FlagStatus EPWM_Get_CountValue_MAX_Status(EPWM_SFRmap* EPWMx);
RetStatus EPWM_Clear_CountValue_MAX_Status(EPWM_SFRmap* EPWMx);
void EPWM_Phase_Direction_Config(EPWM_SFRmap* EPWMx, uint32_t Direction);
void EPWM_Software_SYNC_Event(EPWM_SFRmap* EPWMx);
void EPWM_SYNC_Event_Out_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Phase_Register_Loading_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
FlagStatus EPWM_Get_External_SYNC_Event_Status(EPWM_SFRmap* EPWMx);
RetStatus EPWM_Clear_External_SYNC_Event_Status(EPWM_SFRmap* EPWMx);
void EPWM_Updata_Event_Generate_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Updata_Event_Config(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Updata_Event_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Counter_Mode_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
FlagStatus EPWM_Get_Tx_Count_Direction(EPWM_SFRmap* EPWMx);
void EPWM_Work_Clock_Select(EPWM_SFRmap* EPWMx, uint32_t CLK);
void EPWM_External_Pulse_Sync_Config(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Gated_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Work_Mode_Config(EPWM_SFRmap* EPWMx, uint32_t Mode);
void EPWM_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Duty_Cycle_RegisterABCD_Config(EPWM_SFRmap* EPWMx, uint32_t Register,uint32_t Value);
uint32_t EPWM_Get_Duty_Cycle_RegisterABCD_Value(EPWM_SFRmap* EPWMx, uint32_t Register);
void EPWM_Single_Mandatory_Output_Enable(EPWM_SFRmap* EPWMx, uint32_t Register, FunctionalState NewState);
void EPWM_Single_Mandatory_Output_Config(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Select);
void EPWM_Continuous_Mandatory_Output_Config(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Select);
void EPWM_EPWMxAB_OUTPUT_Select(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Event, uint32_t Select);
void EPWM_Dead_Zone_Input_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Dead_Zone_Output_Polarity_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Dead_Zone_Output_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Dead_Zone_Time_Config(EPWM_SFRmap* EPWMx, uint32_t Select, uint32_t Value);
void EPWM_PCLK_Frequency_Config(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_PCLK_Duty_Cycle_Config(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Chopping_Pulse_Width_Config(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Chopping_Pulse_Mode_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Auto_Reset_Enable(EPWM_SFRmap* EPWMx, uint32_t NewState);
void EPWM_Pin_EPWMA_ShouDown_Status_Config(EPWM_SFRmap* EPWMx, uint32_t Status);
void EPWM_Pin_EPWMB_ShouDown_Status_Config(EPWM_SFRmap* EPWMx, uint32_t Status);
FlagStatus EPWM_Get_Auto_ShowDown_Event_Status(EPWM_SFRmap* EPWMx);
void EPWM_Claer_Auto_ShowDown_Event_Status(EPWM_SFRmap* EPWMx);
void EPWM_Auto_ShowDown_Source_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Trigger_AD_Event_Mode_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select);
uint8_t EPWM_Get_Trigger_AD_Event_Single(EPWM_SFRmap* EPWMx, uint32_t Event);
void EPWM_Trigger_Event_Cycle_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select);
void EPWM_Software_Trigger_AD_Event_Enable(EPWM_SFRmap* EPWMx, uint32_t Event, FunctionalState NewState);
void EPWM_Trigger_AD_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select);
void EPWM_Trigger_AD_Event_Enable(EPWM_SFRmap* EPWMx, uint32_t Event, FunctionalState NewState);
void EPWM_INT_Enable(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState);
FlagStatus EPWM_Get_INT_Flag(EPWM_SFRmap* EPWMx, uint32_t Select);
RetStatus EPWM_Clear_INT_Flag(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Trigger_DMA_Enable(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState);
FlagStatus EPWM_Get_Trigger_DMA_Flag(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_HRPWM_OUTPUTB_CONTRAL_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_HRPWM_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_8Bit_HRPWM_Duty_Cycle(EPWM_SFRmap* EPWMx, uint8_t Value);
uint32_t EPWM_Get_Cap_Register_Current_Value(EPWM_SFRmap* EPWMx);
void EPWM_UDCTL_Updata_Enable(EPWM_SFRmap* EPWMx, uint32_t Mode, FunctionalState NewState);
void EPWM_UDCTL_Register_Updata_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Mode, uint32_t Select);
void EPWM_Global_Loading_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);







#endif /* KF32A1x6_EPWM_H_ */
