/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : KF32A1x6_rng.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the RNG			  *
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
#ifndef KF32A1x6_RNG_H_
#define KF32A1x6_RNG_H_

#include "kf32a1x6.h"


/**
 * 	真随机种子发生器频率校准
 * */
#define RNG_FREQUENCY_CALI_GEAR0						((uint32_t)0)
#define RNG_FREQUENCY_CALI_GEAR1						((uint32_t)1)
#define RNG_FREQUENCY_CALI_GEAR2						((uint32_t)2)
#define RNG_FREQUENCY_CALI_GEAR3						((uint32_t)3)
#define CHECK_RNG_FREQUENCY_CALI_GEAR(SELECT)			((SELECT) <= RNG_FREQUENCY_CALI_GEAR3)

/**
 *  RNG 时钟分频控制
 * */
#define RNG_CLK_DIV1									((uint32_t)0)
#define RNG_CLK_DIV2									((uint32_t)1)
#define RNG_CLK_DIV4									((uint32_t)2)
#define RNG_CLK_DIV8									((uint32_t)3)
#define RNG_CLK_DIV16									((uint32_t)4)
#define RNG_CLK_DIV32									((uint32_t)5)
#define RNG_CLK_DIV64									((uint32_t)6)
#define RNG_CLK_DIV128									((uint32_t)7)
#define RNG_CLK_DIV256									((uint32_t)8)
#define RNG_CLK_DIV512									((uint32_t)9)
#define RNG_CLK_DIV1024									((uint32_t)10)
#define RNG_CLK_DIV2048									((uint32_t)11)
#define RNG_CLK_DIV4096									((uint32_t)12)
#define RNG_CLK_DIV8192									((uint32_t)13)
#define RNG_CLK_DIV16384								((uint32_t)14)
#define RNG_CLK_DIV32768								((uint32_t)15)
#define CHECK_RNG_CLK_DIV(DIV)							((DIV) <= RNG_CLK_DIV32768)

/**
 * 	RNG工作时钟源选择位
 * */
#define RNG_CLK_SCLK									((uint32_t)0)
#define RNG_CLK_HFCLK									((uint32_t)1)
#define RNG_CLK_LFCLK									((uint32_t)2)
#define RNG_CLK_INTLF									((uint32_t)3)
#define CHECK_RNG_CLK(CLK)								((CLK) <= RNG_CLK_INTLF)

/**
 * 	随机种子选择
 * */
#define RNG_SEED_CPU									((uint32_t)0)
#define RNG_SEED_REAL									((uint32_t)1)
#define CHECK_RNG_SEED(SEED)							((SEED) <= RNG_SEED_REAL)

/**
 * 	中断标志使能
 * */
#define RNG_INT_DE										((uint32_t)0)
#define RNG_INT_DR										((uint32_t)1)
#define RNG_INT_TSR										((uint32_t)2)
#define CHECK_RNG_INT(SELECT)							((SELECT) <= RNG_INT_TSR)


void RNG_Reset(void);
void RNG_Real_RNG_Mode_Enable(FunctionalState NewState);
void RNG_Real_RNG_Seed_Correct_Enable(FunctionalState NewState);
void RNG_Real_RNG_Seed_High_Pow_Enable(FunctionalState NewState);
void RNG_Real_RNG_Seed_Frequency_Cail_Select(uint32_t Select);
void RNG_Real_RNG_Seed_Output_Enable(FunctionalState NewState);
void RNG_Real_RNG_Seed_Generator_Enable(FunctionalState NewState);
void RNG_CLK_DIV_Select(uint32_t DIV);
void RNG_Work_CLK_Select(uint32_t CLK);
void RNG_Seed_Select(uint32_t Seed);
void RNG_Enable(FunctionalState NewState);
FlagStatus RNG_Get_Current_Error_Status(void);
void RNG_INT_Enable(uint32_t Select, FunctionalState NewState);
RetStatus RNG_Clear_INT_Flag(uint32_t Select);
FlagStatus RNG_Get_INT_Flag(uint32_t Select);
uint16_t RNG_Seed_Value(void);
uint32_t RNG_Data_Value(void);



#endif /* KF32A1x6_RNG_H_ */
