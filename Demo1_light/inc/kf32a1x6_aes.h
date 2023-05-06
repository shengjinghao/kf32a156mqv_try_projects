/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_aes.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the AES 			  *
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

#ifndef KF32A1x6_AES_H_
#define KF32A1x6_AES_H_

#include "kf32a1x6.h"

/**
 * 	AES CBC模式
 * */
#define AES_WORK_ECB_MODE					((uint32_t)0)
#define AES_WORK_CBC_MODE					((uint32_t)1)
#define CHECK_AES_WORK_MODE(MODE)			((MODE) <= AES_WORK_CBC_MODE)

/**
 * 	AES工作时钟源选择
 * */
#define AES_TRNG_SCK_SCLK					((uint32_t)0)
#define AES_TRNG_SCK_HFCLK					((uint32_t)1)
#define AES_TRNG_SCK_LFCLK					((uint32_t)3)
#define CHECK_AES_TRNG_SCK(CLK)				((CLK) <= AES_TRNG_SCK_LFCLK)

/**
 * 	AES工作时钟分频选择
 * */
#define AES_SCK_DIV0						((uint32_t)0)
#define AES_SCK_DIV2						((uint32_t)1)
#define AES_SCK_DIV4						((uint32_t)2)
#define AES_SCK_DIV8						((uint32_t)3)
#define AES_SCK_DIV16						((uint32_t)4)
#define AES_SCK_DIV32						((uint32_t)5)
#define AES_SCK_DIV64						((uint32_t)6)
#define AES_SCK_DIV128						((uint32_t)7)
#define CHECK_AES_SCK_DIV(DIV)				((DIV) <= AES_SCK_DIV128)

/**
 * 	密钥扩展轮数选择
 * */
#define CHECK_AES_RNG_NUM(NUM)				((NUM) <= 0x1F)

/**
 * 	密钥长度选择
 * */
#define CHECK_KEY_LEN(LEN)					((LEN) <= 0x07)

/**
 * 	S 盒子逆替换使能
 * */
#define AES_SBOX_NOR_REPLACE				((uint32_t)0)
#define AES_SBOX_INV_REPLACE				((uint32_t)1)
#define CHECK_AES_SBOX_INV(MODE)			((MODE) <= AES_SBOX_INV_REPLACE)

/**
 * 	AES加密功能选择
 * */
#define AES_DECRYPT							((uint32_t)0)
#define AES_ENCRYPT							((uint32_t)1)
#define CHECK_AES_DE_ENCRYPT(Function)		((Function) <= AES_ENCRYPT)

/**
 * 	算法自定义使能
 * */
#define AES_STANDARD_ALGORITHM				((uint32_t)0)
#define AES_CUSTOMIZE_ALGORITHM				((uint32_t)1)
#define CHECK_AES_ALGORITHM(MODE)			((MODE) <= AES_CUSTOMIZE_ALGORITHM)


void AES_Reset ();
void AES_Run_Enable(FunctionalState NewState);
void AES_High_Speed_Enable(FunctionalState NewState);
void AES_CBC_Mode_Select(uint32_t Mode);
void AES_TRNG_SCK_Select(uint32_t Source);
void AES_SCK_DIV_Select(uint32_t CLKDIV);
void AES_RND_NUM_Config(uint32_t RNG_NUM);
void AES_KEY_LEN_Config(uint32_t KEY_LEN);
void AES_SBOX_INV_Enable(uint32_t SBOXMODE);
void AES_ENCRYPT_Function_Enable(uint32_t EN_DECRYPT);
void AES_CUSTOMIZE_ALGORITHM_Enable(uint32_t ALGORITHM);
void AES_Enable(FunctionalState NewState);


FlagStatus AES_Get_INT_Flag(void);
void AES_Clear_INT_Flag(void);
void AES_INT_Enable(AbleStatus NewState);


void AES_INPUT0_DATA (uint32_t DATA);
void AES_INPUT1_DATA (uint32_t DATA);
void AES_INPUT2_DATA (uint32_t DATA);
void AES_INPUT3_DATA (uint32_t DATA);

uint32_t GET_AES_OUTPUT0_DATA (void);
uint32_t GET_AES_OUTPUT1_DATA (void);
uint32_t GET_AES_OUTPUT2_DATA (void);
uint32_t GET_AES_OUTPUT3_DATA (void);















#endif /* KF32A1x6_AES_H_ */
