/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_rst.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the RESET			  *
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
#ifndef KF32A1x6_RST_H_
#define KF32A1x6_RST_H_

#include "kf32a1x6.h"

/**
 *	RST_CTL0复位控制寄存器对于的外设编号
 **/
#define CHECK_RST_CTL0_RESET_PERIPH(PERIPH) ((((PERIPH) >> 9) == 0x00) \
											&& ((PERIPH) != 0x00))

/**
 *	RST_CTL1复位控制寄存器对于的外设编号
 **/
#define CHECK_RST_CTL1_RESET_PERIPH(PERIPH)	((((PERIPH) & 0xE0440381) == 0x00) \
											&& ((PERIPH) != 0x00))

/**
 *	RST_CTL2复位控制寄存器对于的外设编号
 **/
#define CHECK_RST_CTL2_RESET_PERIPH(PERIPH)	((((PERIPH) & 0x469EA0DC) == 0x00) \
											&& ((PERIPH) != 0x00))

/**
 *	RST_CTL3复位控制寄存器对于的外设编号
 **/
#define CHECK_RST_CTL3_RESET_PERIPH(PERIPH)	((((PERIPH) & 0x49879) == 0x00) \
											&& ((PERIPH) != 0x00))



/* 复位模块(RST)功能配置函数定义********************************************/
void RST_CTL0_Peripheral_Reset_Enable(uint32_t RST_CTL0Periph,
                    FunctionalState NewState);
void RST_CTL1_Peripheral_Reset_Enable(uint32_t RST_CTL1Periph,
                    FunctionalState NewState);
void RST_CTL2_Peripheral_Reset_Enable(uint32_t RST_CTL2Periph,
                    FunctionalState NewState);
void RST_CTL3_Peripheral_Reset_Enable(uint32_t RST_CTL3Periph,
                    FunctionalState NewState);

#endif /* KF32A1x6_RST_H_ */
