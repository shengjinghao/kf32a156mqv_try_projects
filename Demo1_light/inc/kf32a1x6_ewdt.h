/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_ewdt.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the EWDT 			  *
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
#include "kf32a1x6.h"


#ifndef KF32A1x6_EWDT_H_
#define KF32A1x6_EWDT_H_


/**
 * 	EWDT的输出有效信号极性
 * */
#define EWDT_RESET_EFFECTIVE_LOW					((uint32_t)0)
#define EWDT_RESET_EFFECTIVE_HIGH					((uint32_t)1)
#define CHECK_EWDT_RESET_EFFECTIVE(SELECT)			((SELECT) <= EWDT_RESET_EFFECTIVE_HIGH)

/**
 * 	时钟选择
 * */
#define EWDT_CLK_INTLF								((uint32_t)0)
#define EWDT_CLK_SCLK								((uint32_t)1)
#define EWDT_CLK_LFCLK								((uint32_t)2)
#define EWDT_CLK_LP4M								((uint32_t)3)
#define CHECK_EWDT_CLK(CLK)							((CLK) <= EWDT_CLK_LP4M)

/**
 * 	EWDTIN输入信号极性选择
 * */
#define EWDT_INTPUT_EFFECTIVE_LOW					((uint32_t)0)
#define EWDT_INTPUT_EFFECTIVE_HIGH					((uint32_t)1)
#define CHECK_EWDT_INTPUT_EFFECTIVE(SELECT)			((SELECT) <= EWDT_INTPUT_EFFECTIVE_HIGH)

/**
 * 	外围看门狗配置
 * */
#define CHECK_EWDT_THRESHOLD(VALUE)					((VALUE) <= 0x7F)

/**
 * 	外围看门狗预分频
 * */
#define	EWDT_CLK_DIV1 								((uint32_t)0)
#define	EWDT_CLK_DIV2 								((uint32_t)1)
#define	EWDT_CLK_DIV4 								((uint32_t)2)
#define	EWDT_CLK_DIV8 								((uint32_t)3)
#define	EWDT_CLK_DIV16 		                        ((uint32_t)4)
#define	EWDT_CLK_DIV32 		                        ((uint32_t)5)
#define	EWDT_CLK_DIV64 		                        ((uint32_t)6)
#define	EWDT_CLK_DIV128 		                    ((uint32_t)7)
#define	EWDT_CLK_DIV256 		                    ((uint32_t)8)
#define	EWDT_CLK_DIV512 		                    ((uint32_t)9)
#define	EWDT_CLK_DIV1024 	                        ((uint32_t)10)
#define	EWDT_CLK_DIV2048 	                        ((uint32_t)11)
#define	EWDT_CLK_DIV4096 	                        ((uint32_t)12)
#define	EWDT_CLK_DIV8192 	                        ((uint32_t)13)
#define	EWDT_CLK_DIV16384 	                        ((uint32_t)14)
#define	EWDT_CLK_DIV32768 	                        ((uint32_t)15)
#define	EWDT_CLK_DIV65536 	                        ((uint32_t)16)
#define	EWDT_CLK_DIV131072                          ((uint32_t)17)
#define	EWDT_CLK_DIV262144                          ((uint32_t)18)
#define CHECK_EWDT_CLK_DIV(DIV)						((DIV) <= EWDT_CLK_DIV262144)

/**
 * 	外围看门狗计数值
 * */
#define CHECK_EWDT_COUNT_VALUE(VALUE)				((VALUE) <= 0x40)



void EWDT_Reset (void);
void EWDT_Output_Effective_Single_Select(uint32_t Select);
FlagStatus EWDT_Get_Reset_INT_Flag(void);
RetStatus EWDT_Clear_Reset_INT_Flag(void);
void EWDT_Reset_Single_INT_Enable(FunctionalState NewState);
void EWDT_CLK_Select(uint32_t CLK);
void EWDT_Input_Effective_Single_Select(uint32_t Select);
void EWDT_Input_Single_Enable(FunctionalState NewState);
RetStatus EWDT_Clear_Count40_INT_Flag(void);
void EWDT_Threshold_Config(uint32_t Threshold);
void EWDT_Clock_Div_Select(uint32_t DIV);
FlagStatus EWDT_Get_Count40_INT_Flag(void);
void EWDT_Count40_INT_Enable(FunctionalState NewState);
void EWDT_Enable(FunctionalState NewState);
uint8_t EWDT_Get_Count_Value(void);
void EWDT_Set_Count_Value(uint8_t Value);


#endif /* KF32A1x6_EWDT_H_ */
