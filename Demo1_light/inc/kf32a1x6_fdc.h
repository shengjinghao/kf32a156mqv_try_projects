/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_fdc.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0	                                       	      *
 *  $Description$     : This file contains the headers of the FDC 			  *
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
#ifndef KF32A1x6_FDC_H_
#define KF32A1x6_FDC_H_

#include "kf32a1x6.h"


/**
 * 	FDC 内存指针
 * */
#define CHECK_FDC_ALL_PERPH(PERIPH)							(((PERIPH) == FDC0_SFR) \
														|| 	 ((PERIPH) == FDC1_SFR) \
														|| 	 ((PERIPH) == FDC2_SFR))

/**
 * 	FDC工作时钟选择
 * */
#define FDC_WORK_CLK_SCLK									((uint32_t)0)
#define FDC_WORK_CLK_HFCLK									((uint32_t)1)
#define FDC_WORK_CLK_LFCLK									((uint32_t)3)
#define CHECK_FDC_WORK_CLK(CLK)								((CLK) <= FDC_WORK_CLK_LFCLK)

/**
 * 	FDC工作模式选择
 * */
#define FDC_WORK_RANDOM										((uint32_t)0)
#define FDC_WORK_FIXED										((uint32_t)1)
#define CHECK_FDC_WORK_MODE(MODE)							((MODE) <= FDC_WORK_FIXED)

/**
 * 	更新模式选择
 * */
#define FDC_UPDATA_NOW										((uint32_t)0)
#define FDC_UPDATA_EQUAL_MODA1								((uint32_t)1)
#define FDC_UPDATA_TRIGGER									((uint32_t)2)
#define FDC_UPDATA_TRIGGER_MODA1							((uint32_t)3)
#define CHECK_FDC_UPDATA_MODE(MODE)							((MODE) <= FDC_UPDATA_TRIGGER_MODA1)

/**
 * 	预分频选择
 * */
#define FDC_PRE_SCALER_MUL									((uint32_t)0)
#define FDC_PRE_SCALER_2MUL									((uint32_t)1)
#define FDC_PRE_SCALER_4MUL									((uint32_t)2)
#define FDC_PRE_SCALER_8MUL									((uint32_t)3)
#define FDC_PRE_SCALER_16MUL								((uint32_t)4)
#define FDC_PRE_SCALER_32MUL								((uint32_t)5)
#define FDC_PRE_SCALER_64MUL								((uint32_t)6)
#define FDC_PRE_SCALER_128MUL								((uint32_t)7)
#define CHECK_FDC_PRESCALER(SELECT)							((SELECT) <= FDC_PRE_SCALER_128MUL)

/**
 * 	分频因子
 * */
#define CHECK_FDC_SCALER_FACTOR(VALUE)						(((VALUE) >> 6) == 0)

/**
 * 	触发输入源选择
 * */
#define FDC_INPUT_TRIGGLE									((uint32_t)0)
#define FDC_SOFTWARE_TRIGGLE								((uint32_t)1)
#define CHECK_FDC_INPUT_TRIGGLE(SELECT)						((SELECT) <= FDC_SOFTWARE_TRIGGLE)

/**
 * 	FDC计数周期
 * */
#define CHECK_FDC_COUNT_CYCLE(VALUE)						((VALUE) <= 0xFFFF)

/**
 * 	FDC通道序列错误标志清零
 * */
#define CHECK_FDC_CHANNEL_LIST_ERROR(FLAG)					((FLAG)<=4)

/**
 * 	FDC通道
 * */
#define FDC_CHANNLE_0										((uint32_t)0)
#define FDC_CHANNLE_1										((uint32_t)1)
#define FDC_CHANNLE_2										((uint32_t)2)
#define FDC_CHANNLE_3										((uint32_t)3)
#define CHECK_FDC_CHANNEL(CHANNEL)							((CHANNEL) <= FDC_CHANNLE_3)

/**
 * 	FDC通道预触发输出选择
 * */
#define FDC_PRE_TRIGGLE_MODE0								((uint32_t)0)
#define FDC_PRE_TRIGGLE_BYPASS								((uint32_t)1)
#define CHECK_FDC_PRE_TRIGGLE(SELECT)						((SELECT) <= FDC_PRE_TRIGGLE_BYPASS)

/**
 * 	FDC通道m的第x个预触发信号延迟
 * */
#define CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(VALUE)			((VALUE) <= 0xFFFF)

/**
 *  FDC脉冲输出延时
 * */
#define CHECK_FDC_PULSE_OUTPUT_DELAY(VALUE)					((VALUE) <= 0xFFFF)


void FDC_Reset(FDC_SFRmap* FDCx);
void FDC_TRGI_Count_Reset_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Work_Clk_Select(FDC_SFRmap* FDCx, uint32_t CLK);
RetStatus FDC_Clear_MDLIF_Flag(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Cycle_Scan_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Work_Mode_Select(FDC_SFRmap* FDCx, uint32_t MODE);
void FDC_Updata_Mode_Select(FDC_SFRmap* FDCx, uint32_t MODE);
void FDC_Sequence_Error_INT_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Software_Triggle_Enable(FDC_SFRmap* FDCx);
void FDC_MDL_INT_DMA_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Prescaler_Select(FDC_SFRmap* FDCx, uint32_t Select);
void FDC_Scaler_Factor(FDC_SFRmap* FDCx, uint32_t Value);
void FDC_Triggle_Input_Select(FDC_SFRmap* FDCx, uint32_t Select);
void FDC_MDL_INT_Enable(FDC_SFRmap* FDCx, uint32_t Select);
FlagStatus FDC_Get_MDL_INT_Flag(FDC_SFRmap* FDCx);
void FDC_Single_Mode_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Ldok_Write1(FDC_SFRmap* FDCx);
void FDC_Pulse_Output_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Set_Count_Cycle(FDC_SFRmap* FDCx, uint32_t Value);
uint16_t FDC_Get_Count_Cycle(FDC_SFRmap* FDCx);
uint16_t FDC_Get_Count_Value(FDC_SFRmap* FDCx);
uint16_t FDC_Get_INT_Delay_Value(FDC_SFRmap* FDCx);
void FDC_Clear_Channel_List_Error_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n, FunctionalState NewState);
FlagStatus FDC_Get_Channel_List_Error_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n);
FlagStatus FDC_Get_CFn_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n);
void FDC_Channel_Pre_Triggle_Select(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n, uint32_t Select);
void FDC_Channel_Pre_Signel_Enable(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n, FunctionalState NewState);
void FDC_Channelm_Pre_Triggle_Delay0(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Channelm_Pre_Triggle_Delay1(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Channelm_Pre_Triggle_Delay2(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Channelm_Pre_Triggle_Delay3(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Channelm_Pre_Triggle_Delay4(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Pulse_Output_DelayH(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Pulse_Output_DelayL(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);



#endif /* KF32A1x6_FDC_H_ */
