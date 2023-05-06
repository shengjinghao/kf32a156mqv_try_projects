/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_aes.h                              	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the system control related function*
 *                    	declaration and related macro definition.	          *
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
 *  2021-07-08 00.01.00 FAE Group     Version 2.0 update                      *
 *                                                                            *
 *                                                                            *
 *****************************************************************************/

/******************************************************************************
**                      		Include Files                                **
******************************************************************************/

#include "kf32a1x6_aes.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"

/**
  *   ##### 初始化及配置函数 #####
  */
/**
  * 描述AES外设复位，使能外设时钟。
  * 输入  : 无
  * 返回  无。
  */
void AES_Reset ()
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_AESRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_AESRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_AESCLKEN, TRUE);
}

/**
  * 描述： AES 运行使能。
  * 输入： NewState:
  * 	  		TRUE:触发 AES 工作；
  * 	 		FALSE: 无影响
  * 返回： 无。
  * 注释：上升沿有效， 需要手动清零；
  */
void AES_Run_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_AESRUN, NewState << AES_CTL_AESRUN_POS);
}

/**
  * 描述： AES 高速模式使能。
  * 输入： NewState:
  * 	  		TRUE:高速模式使能位；
  * 	 		FALSE: 无影响
  * 返回： 无。
  */
void AES_High_Speed_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_HSMODE, NewState << AES_CTL_HSMODE_POS);
}

/**
  * 描述： CBC模式使能位。
  * 输入： Mode:
  * 	  		AES_WORK_ECB_MODE: 工作在ECB模式
  * 	 		AES_WORK_CBC_MODE: 工作在CBC模式
  * 返回： 无。
  */
void AES_CBC_Mode_Select(uint32_t Mode)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_AES_WORK_MODE(Mode));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_CBCEN, Mode << AES_CTL_CBCEN_POS);
}

/**
  * 描述： AES工作时钟源选择。
  * 输入： Source:
  * 	  		AES_TRNG_SCK_SCLK: 选用SCLK为TRNG工作时钟
  * 	 		AES_TRNG_SCK_HFCLK: 选用SCLK为TRNG工作时钟
  * 	 		AES_TRNG_SCK_LFCLK: 选用SCLK为TRNG工作时钟
  * 返回： 无。
  */
void AES_TRNG_SCK_Select(uint32_t Source)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_AES_TRNG_SCK(Source));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_CKS, Source << AES_CTL_CKS0_POS);
}

/**
  * 描述： AES工作时钟分频选择
  * 输入： CLKDIV:
  * 	  		AES_SCK_DIV0:    不分频
  * 	 		AES_SCK_DIV2:    2分频
  * 	 		AES_SCK_DIV4:    4分频
  * 	 		AES_SCK_DIV8:  	 8分频
  * 	 		AES_SCK_DIV16:   16分频
  * 	 		AES_SCK_DIV32:   32分频
  * 	 		AES_SCK_DIV64:   64分频
  * 	 		AES_SCK_DIV128:  128分频
  * 返回： 无。
  */
void AES_SCK_DIV_Select(uint32_t CLKDIV)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_AES_SCK_DIV(CLKDIV));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_DIV, CLKDIV << AES_CTL_DIV0_POS);
}

/**
  * 描述： AES密钥扩展轮数选择
  * 输入： RNG_NUM:  RNG_NUM <= 0x1F
  * 返回： 无。
  */
void AES_RND_NUM_Config(uint32_t RNG_NUM)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_AES_RNG_NUM(RNG_NUM));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_RND_NUM, RNG_NUM << AES_CTL_RND_NUM0_POS);
}

/**
  * 描述： AES密钥长度选择
  * 输入： KEY_LEN:  KEY_LEN <= 0x07
  * 返回： 无。
  * 注释： 密钥字长 =（KEY_LEN+1）/4
  */
void AES_KEY_LEN_Config(uint32_t KEY_LEN)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_KEY_LEN(KEY_LEN));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_KEY_LEN, KEY_LEN << AES_CTL_KEY_LEN0_POS);
}

/**
  * 描述： S 盒子逆替换使能位
  * 输入： SBOXMODE:
					AES_SBOX_NOR_REPLACE: S盒子正常替换
					AES_SBOX_INV_REPLACE: S盒子逆替换
  * 返回： 无。
  */
void AES_SBOX_INV_Enable(uint32_t SBOXMODE)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_AES_SBOX_INV(SBOXMODE));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_SB0X_INV, SBOXMODE << AES_CTL_SB0X_INV_POS);
}

/**
  * 描述： 加密功能使能位
  * 输入： EN_DECRYPT:
					AES_DECRYPT: 选择 AES 解密功能
					AES_ENCRYPT: 选择 AES 加密功能
  * 返回： 无。
  */
void AES_ENCRYPT_Function_Enable(uint32_t EN_DECRYPT)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_AES_DE_ENCRYPT(EN_DECRYPT));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_ENCRYPT, EN_DECRYPT << AES_CTL_ENCRYPT_POS);
}

/**
  * 描述： 算法自定义使能
  * 输入： ALGORITHM:
					AES_STANDARD_ALGORITHM: AES 采用标准算法
					AES_CUSTOMIZE_ALGORITHM: AES 采用自定义算法
  * 返回： 无。
  */
void AES_CUSTOMIZE_ALGORITHM_Enable(uint32_t ALGORITHM)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_AES_ALGORITHM(ALGORITHM));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_AESLIKE, ALGORITHM << AES_CTL_AESLIKE_POS);
}

/**
  * 描述： AES 使能
  * 输入： NewState:
					TRUE: AES 使能
					FALSE: AES 禁止
  * 返回： 无。
  */
void AES_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_AESEN, NewState);
}


/**
  * 描述： AES 加/解密完成中断标志
  * 输入： 无
  * 返回： 0：正在加解密过程或者未开始加解密
  *		  1：1 次加密/解密完成
  */
FlagStatus AES_Get_INT_Flag(void)
{
	if(AES_INT & AES_INT_AESIF)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/**
  * 描述： AES 中断标志清零
  * 输入： 无
  * 返回： 无。
  */
void AES_Clear_INT_Flag(void)
{
	SFR_SET_BIT_ASM(AES_INT, AES_INT_AESIC_POS);//huanglt
	while(AES_INT & AES_INT_AESIF);
	SFR_CLR_BIT_ASM(AES_INT, AES_INT_AESIC_POS);
}

/**
  * 描述： AES 中断使能位
  * 输入： NewState:
  * 				ENABLE: AES 中断使能
  * 				DISABLE: AES 中断禁止
  * 返回： 无。
  */
void AES_INT_Enable(AbleStatus NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	AES_INT = SFR_Config(AES_INT, ~AES_INT_AESIE, NewState);
}


/**
  * 描述 AES输入寄存器。
  * 输入  INPUTDATA:位宽bit32
  * 返回  无。
  */
void AES_INPUT0_DATA (uint32_t DATA)
{

	AES_SFR->INPUT0=DATA;
}
void AES_INPUT1_DATA (uint32_t DATA)
{

	AES_SFR->INPUT1=DATA;
}
void AES_INPUT2_DATA (uint32_t DATA)
{

	AES_SFR->INPUT2=DATA;
}
void AES_INPUT3_DATA (uint32_t DATA)
{

	AES_SFR->INPUT3=DATA;
}
/**
  * 描述 AES输出寄存器。
  * 输入 :无
  * 返回： OUTPUTDATA:位宽bit32
  */
uint32_t GET_AES_OUTPUT0_DATA (void)
{
	uint32_t DATA;
	DATA=AES_SFR->OUTPUT0;

	return	DATA;
}
uint32_t GET_AES_OUTPUT1_DATA (void)
{
	uint32_t DATA;
	DATA=AES_SFR->OUTPUT1;

	return	DATA;
}
uint32_t GET_AES_OUTPUT2_DATA (void)
{
	uint32_t DATA;
	DATA=AES_SFR->OUTPUT2;

	return	DATA;
}
uint32_t GET_AES_OUTPUT3_DATA (void)
{
	uint32_t DATA;
	DATA=AES_SFR->OUTPUT3;

	return	DATA;
}
