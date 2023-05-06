/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_op.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the OP			  *
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
#ifndef KF32A1x6_OP_H_
#define KF32A1x6_OP_H_

#include "kf32a1x6.h"


/**
 * 	OPx校验
 * */
#define OP0_NUM							((uint32_t)0)
#define OP1_NUM							((uint32_t)1)
#define OP2_NUM							((uint32_t)2)
#define OP3_NUM							((uint32_t)3)
#define CHECK_OP_ALL_NUM(OPX)			((OPX) <= OP3_NUM)
#define CHECK_OP_OP012_NUM(OPX)			((OPX) <= OP2_NUM)
/**
 * 	OP放大倍数选择
 * */
#define OP_GAIN_2dB						((uint32_t)0)
#define OP_GAIN_4dB						((uint32_t)1)
#define OP_GAIN_8dB						((uint32_t)2)
#define OP_GAIN_16dB					((uint32_t)3)
#define OP_GAIN_32dB					((uint32_t)4)
#define OP_GAIN_64dB					((uint32_t)5)
#define CHECK_OP_GAIN_VALUE(VALUE)		(((VALUE) == OP_GAIN_2dB) \
									 || ((VALUE) == OP_GAIN_4dB) \
									 || ((VALUE) == OP_GAIN_8dB) \
									 || ((VALUE) == OP_GAIN_16dB) \
									 || ((VALUE) == OP_GAIN_32dB) \
									 || ((VALUE) == OP_GAIN_64dB))
/**
 * 	OP共模参考正端输入
 * */
#define OP_HALF_AVDD					((uint32_t)1)
#define OP_HALF_2V						((uint32_t)3)
#define CHECK_OP_VCOM_SEL(SELECT)		(((SELECT) == OP_HALF_AVDD) \
									||   ((SELECT) == OP_HALF_2V))
/**
 *  OP失调校准值参数校验
 * */
#define CHECK_OP_TRIM_VALUE(VALUE)		(((VALUE) >> 0x06) == 0x00)
/**
 *  OP失调校准方向
 * */
#define OP_TRIM_DIRECTION_NEGETIVE		((uint32_t)0)
#define OP_TRIM_DIRECTION_POSITIVE		((uint32_t)1)
#define CHECK_OP_TRIM_DIRECTION(DIR)	((DIR) <= OP_TRIM_DIRECTION_POSITIVE)


/* 可编程增益放大器(OP)控制功能函数定义*****************************************/
void OP_Reset(void);
void OP_Enable(uint32_t OPx_NUM, FunctionalState NewState);
void OP_OUTPUT_Enable(uint32_t OPx_NUM, FunctionalState NewState);
void OP_GAIN_Select(uint32_t OPx_NUM,uint32_t GAIN_Value, FunctionalState NewState);
void OP_OPUPUT_Parallel_Resistance(uint32_t OPx_NUM, FunctionalState NewState);
void OP_Positive_INPUT_Selsect(uint32_t OPx_NUM_OUTPUT, uint32_t OPx_NUM_PINPUT, FunctionalState NewState);
void OP_Positive_Negetive_Short(uint32_t OPx_NUM, FunctionalState NewState);
void OP_VCOM_Positive_Select(uint32_t Select);
void OP_VCOM_Buffer_Output_Enable(FunctionalState NewState);
void OP_VCOM_Buffer_Enable(FunctionalState NewState);
void CMP3_Enable(FunctionalState NewState);
void OP_TRIM_PMOS_Enable(FunctionalState NewState);
void OP_TRIM_NMOS_Enable(FunctionalState NewState);
RetStatus OP_TRIM_OUT_Flag(uint32_t OPx_NUM);
void OP_TRIM_PMOS_Value_Config(uint32_t OPx_NUM, uint8_t Value);
void OP_TRIM_PMOS_Direction_Select(uint32_t OPx_NUM, uint32_t Direction);
void OP_TRIM_NMOS_Value_Config(uint32_t OPx_NUM, uint8_t Value);
void OP_TRIM_NMOS_Direction_Select(uint32_t OPx_NUM, uint32_t Direction);


#endif /* KF32A1x6_OP_H_ */
