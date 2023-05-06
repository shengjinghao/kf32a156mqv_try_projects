/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_ecfgl.h                               	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the ECFGL			  *
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
#ifndef KF32A1x6_ECFGL_H_
#define KF32A1x6_ECFGL_H_

#include "kf32a1x6.h"


/**
 * 	ECFGLx 校验
 * */
#define ECFGL0										((uint32_t)0)
#define ECFGL1										((uint32_t)1)
#define ECFGL2										((uint32_t)2)
#define ECFGL3										((uint32_t)3)
#define ECFGL4										((uint32_t)4)
#define ECFGL5										((uint32_t)5)
#define ECFGL6										((uint32_t)6)
#define ECFGL7										((uint32_t)7)
#define ECFGL8										((uint32_t)8)
#define ECFGL9										((uint32_t)9)
#define ECFGL10										((uint32_t)10)
#define ECFGL11										((uint32_t)11)
#define ECFGL12										((uint32_t)12)
#define ECFGL13										((uint32_t)13)
#define ECFGL14										((uint32_t)14)
#define ECFGL15										((uint32_t)15)
#define CHECK_ECFGL_ALL_MODULE(MODULE)				((MODULE) <= ECFGL15)

/**
 * 	可编程逻辑盒子功能选择
 * */
#define ECFGL_FUNCTION_0         						((uint32_t)0)
#define ECFGL_FUNCTION_NOR       						((uint32_t)1)
#define ECFGL_FUNCTION_B_AND_notA						((uint32_t)2)
#define ECFGL_FUNCTION_notA      						((uint32_t)3)
#define ECFGL_FUNCTION_A_AND_notB						((uint32_t)4)
#define ECFGL_FUNCTION_notB      						((uint32_t)5)
#define ECFGL_FUNCTION_EXOR      						((uint32_t)6)
#define ECFGL_FUNCTION_NAND      						((uint32_t)7)
#define ECFGL_FUNCTION_AND       						((uint32_t)8)
#define ECFGL_FUNCTION_EXNOR     						((uint32_t)9)
#define ECFGL_FUNCTION_B         						((uint32_t)10)
#define ECFGL_FUNCTION_notA_OR_B 						((uint32_t)11)
#define ECFGL_FUNCTION_A         						((uint32_t)12)
#define ECFGL_FUNCTION_A_OR_notB 						((uint32_t)13)
#define ECFGL_FUNCTION_OR        						((uint32_t)14)
#define ECFGL_FUNCTION_1         						((uint32_t)15)
#define CHECK_ECFGL_FUNCTION(SELECT)					((SELECT) <= ECFGL_FUNCTION_1)

/**
 * 	MUX4输入选择
 * */
#define ECFGL_MUX4IN_ECFGL_OUTPUT						((uint32_t)0)
#define ECFGL_MUX4IN_ECFGL_OUTPUT_FLTER					((uint32_t)1)
#define CHECK_ECFGL_MUX4IN(SELECT)					((SELECT) <= ECFGL_MUX4IN_ECFGL_OUTPUT_FLTER)

/**
 * 	MUX3输入选择
 * */
#define ECFGL_MUX3IN_EXTERNAL_SINGLE					((uint32_t)0)
#define ECFGL_MUX3IN_MUX1_OUTPUT						((uint32_t)1)
#define CHECK_ECFGL_MUX3IN(SELECT)					((SELECT) <= ECFGL_MUX3IN_MUX1_OUTPUT)

/**
 * 	MUX2输入选择
 * */
#define ECFGL_MUX2IN_SOFTWARE							((uint32_t)0)
#define ECFGL_MUX2IN_MUX0_OUTPUT						((uint32_t)1)
#define CHECK_ECFGL_MUX2IN(SELECT)					((SELECT) <= ECFGL_MUX2IN_MUX0_OUTPUT)

/**
 * 	MUX1输入选择
 * */
#define ECFGL_MUX1IN_00								((uint32_t)0)
#define ECFGL_MUX1IN_01								((uint32_t)1)
#define ECFGL_MUX1IN_10								((uint32_t)2)
#define ECFGL_MUX1IN_11								((uint32_t)3)
#define CHECK_ECFGL_MUX1IN(SELECT)					((SELECT) <= ECFGL_MUX1IN_11)

/**
 * 	MUX0输入选择
 * */
#define ECFGL_MUX0IN_00								((uint32_t)0)
#define ECFGL_MUX0IN_01								((uint32_t)1)
#define ECFGL_MUX0IN_10								((uint32_t)2)
#define ECFGL_MUX0IN_11								((uint32_t)3)
#define CHECK_ECFGL_MUX0IN(SELECT)					((SELECT) <= ECFGL_MUX0IN_11)


/**
 * 	MUX2软件选择位时的输入
 * */
#define ECFGL_MUX2IN_0								((uint32_t)0)
#define ECFGL_MUX2IN_1								((uint32_t)1)
#define CEHCK_ECFGL_MUX2IN(SELECT)					((SELECT) <= ECFGL_MUX2IN_1)


/**
 * 	滤波时钟分频选择
 * */
#define ECFGL_FLITER_DIV1								((uint32_t)0)
#define ECFGL_FLITER_DIV2								((uint32_t)1)
#define ECFGL_FLITER_DIV4								((uint32_t)2)
#define ECFGL_FLITER_DIV8								((uint32_t)3)
#define ECFGL_FLITER_DIV16							((uint32_t)4)
#define CHECK_ECFGL_FLITER_DIV(DIV)					((DIV) <= ECFGL_FLITER_DIV16)

/**
 * 	滤波时钟选择
 * */
#define ECFGL_CLK_SCLK								((uint32_t)0)
#define ECFGL_CLK_HFCLK								((uint32_t)1)
#define ECFGL_CLK_LFCLK								((uint32_t)2)
#define ECFGL_CLK_CH1_TROUT							((uint32_t)3)
#define ECFGL_CLK_INTLF								((uint32_t)4)
#define CHECK_ECFGL_FLITER_CLK(CLK)					((CLK) <= ECFGL_CLK_INTLF)


void ECFGL_Reset (void);
void ECFGL_Output_Enable(uint32_t ECFGLx, FunctionalState NewState);
void ECFGL_Function_Select(uint32_t ECFGLx, uint32_t Function);
void ECFGL_MUX4IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX3IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX2IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX1IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX0IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX2IN_Software_Bit_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_Fliter_Clock_Div_Select(uint32_t ECFGL_DIV);
void ECFGL_Fliter_Clock_Select(uint32_t CLK);
RetStatus ECFGLx_Clear_INT_Flag(uint32_t ECFGLx);
FlagStatus ECFGLx_Get_INT_Flag(uint32_t ECFGLx);
void ECFGLx_Rise_INT_Enable(uint32_t ECFGLx, FunctionalState NewState);
void ECFGLx_Fall_INT_Enable(uint32_t ECFGLx, FunctionalState NewState);
void ECFGLx_Trigger_ADC_Enable(FunctionalState NewState);
void ECFGLx_Trigger_ADC_Source_Select(uint32_t ECFGLx);
FlagStatus ECFGLx_Get_ECFGLx_Output_Status(uint32_t ECFGLx);



#endif /* KF32A1x6_ECFGL_H_ */
