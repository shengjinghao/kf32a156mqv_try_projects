/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_rng.c                               	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Random number generator(RNG)   *
 *  				    peripherals function                              	  *
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

#include "kf32a1x6_rng.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"

/**
  * 描述: 复位RNG外设，使能外设时钟。
  * 输入: 无。
  * 返回: 无。
  */
void RNG_Reset(void)
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_RNGRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_RNGRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_RNGCLKEN, TRUE);
}
/**
  * 描述: 真随机数模式使能。
  * 输入: 	NewState:
  * 				TRUE : 模块工作在真随机数模式
  * 				FALSE ： 模块工作在伪随机数模式
  * 返回: 无。
  */
void RNG_Real_RNG_Mode_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_TRNGMS, NewState << RNG_CTL_TRNGMS_POS);
}
/**
  * 描述: 真随机种子矫正使能。
  * 输入: 	NewState:
  * 				TRUE : 使能真随机数种子矫正
  * 				FALSE ： 禁止真随机数种子矫正
  * 返回: 无。
  */
void RNG_Real_RNG_Seed_Correct_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_RECEN, NewState << RNG_CTL_RECEN_POS);
}
/**
  * 描述: 真随机种子发生器高功耗使能。
  * 输入: 	NewState:
  * 				TRUE : 使能高功耗模式
  * 				FALSE ：禁止高功耗模式
  * 返回: 无。
  */
void RNG_Real_RNG_Seed_High_Pow_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_HIPOW, NewState << RNG_CTL_HIPOW_POS);
}
/**
  * 描述: 真随机种子发生器频率校准。
  * 输入: 	Select:
  * 				RNG_FREQUENCY_CALI_GEAR0 : 档位0
  * 				RNG_FREQUENCY_CALI_GEAR1 : 档位1
  * 				RNG_FREQUENCY_CALI_GEAR2 : 档位2
  * 				RNG_FREQUENCY_CALI_GEAR3 : 档位3
  * 返回: 无。
  */
void RNG_Real_RNG_Seed_Frequency_Cail_Select(uint32_t Select)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_RNG_FREQUENCY_CALI_GEAR(Select));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_ADD, Select << RNG_CTL_ADD0_POS);
}
/**
  * 描述: 真随机种子输出使能。
  * 输入: 	NewState:
  * 				TRUE : 使能真随机种子序列输出
  * 				FALSE ：禁止真随机种子序列输出
  * 返回: 无。
  */
void RNG_Real_RNG_Seed_Output_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_TSEEDGO, NewState << RNG_CTL_TSEEDGO_POS);
}
/**
  * 描述: 真随机种子发生器使能。
  * 输入: 	NewState:
  * 				TRUE : 使能真随机种子发生器工作
  * 				FALSE ：禁止真随机种子发生器工作
  * 返回: 无。
  */
void RNG_Real_RNG_Seed_Generator_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_TSEEDEN, NewState << RNG_CTL_TSEEDEN_POS);
}
/**
  * 描述: RNG 时钟分频控制。
  * 输入: 	DIV:
  * 				RNG_CLK_DIV1 : 1分频
  * 				RNG_CLK_DIV2 : 2分频
  * 				RNG_CLK_DIV4 : 4分频
  * 				RNG_CLK_DIV8 : 8分频
  * 				RNG_CLK_DIV16 : 16分频
  * 				RNG_CLK_DIV32 : 32分频
  * 				RNG_CLK_DIV64 : 64分频
  * 				RNG_CLK_DIV128 : 128分频
  * 				RNG_CLK_DIV256 : 256分频
  * 				RNG_CLK_DIV512 : 512分频
  * 				RNG_CLK_DIV1024 : 1024分频
  * 				RNG_CLK_DIV2048 : 2048分频
  * 				RNG_CLK_DIV4096 : 4096分频
  * 				RNG_CLK_DIV8192 : 8192分频
  * 				RNG_CLK_DIV16384 : 16384分频
  * 				RNG_CLK_DIV32768 : 32768分频
  * 返回: 无。
  */
void RNG_CLK_DIV_Select(uint32_t DIV)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_RNG_CLK_DIV(DIV));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_CLKDIV, DIV << RNG_CTL_CLKDIV0_POS);
}
/**
  * 描述: RNG工作时钟源选择。
  * 输入: 	CLK:
  * 				RNG_CLK_SCLK : 选用SCLK作为RNG模块工作时钟
  * 				RNG_CLK_HFCLK : 选用HFCLK作为RNG模块工作时钟
  * 				RNG_CLK_LFCLK : 选用LFCLK作为RNG模块工作时钟
  * 				RNG_CLK_INTLF : 选用INTLF作为RNG模块工作时钟
  * 返回: 无。
  */
void RNG_Work_CLK_Select(uint32_t CLK)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_RNG_CLK(CLK));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_CLKS, CLK << RNG_CTL_CLKS0_POS);
}
/**
  * 描述: 随机种子选择。
  * 输入: 	Seed:
  * 				RNG_SEED_CPU : 随机种子来自CPU写入
  * 				RNG_SEED_REAL : 随机种子来自真随机种子发生器
  * 返回: 无。
  */
void RNG_Seed_Select(uint32_t Seed)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_RNG_SEED(Seed));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_RNGSEL, Seed << RNG_CTL_RNGSEL_POS);
}
/**
  * 描述: RNG使能。
  * 输入: 	NewState:
  * 				TRUE : 使能RNG
  * 				FALSE : 不使能
  * 返回: 无。
  */
void RNG_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_RNGEN, NewState);
}


/**
  * 描述: 随机数的当前错误状态。
  * 输入: 无
  * 返回: 	0：超过32个位具有相同位（0或1）
  * 		1：超过32位连续交替的0和1（0101010...）
  */
FlagStatus RNG_Get_Current_Error_Status(void)
{
	return ((RNG_STATE & RNG_STATE_DEIS) >> RNG_STATE_DEIS_POS);
}
/**
  * 描述: 中断标志使能。
  * 输入: Select : 	RNG_INT_TSR ： 真随机数种子就绪中断标志
  * 				RNG_INT_DR ： 随机数数据就绪中断标志
  * 				RNG_INT_DE ： 随机数错误中断标志
  * 	  NewState：TRUE : 使能
  * 	  			FALSE : 无作用
  * 返回: 无
  */
void RNG_INT_Enable(uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_RNG_INT(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (RNG_STATE_DEIE_POS + Select);
	tmask = (uint32_t)1 << (RNG_STATE_DEIE_POS + Select);
	RNG_STATE = SFR_Config(RNG_STATE, ~tmask, tmpreg);
}
/**
  * 描述: 中断标志清零。
  * 输入: Select : 	RNG_INT_TSR ： 真随机数种子就绪中断标志
  * 				RNG_INT_DR ： 随机数数据就绪中断标志
  * 				RNG_INT_DE ： 随机数错误中断标志
  * 返回: 中断标志清零是否成功状态
  */
RetStatus RNG_Clear_INT_Flag(uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;
	uint32_t wait_flag=0x0000;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_RNG_INT(Select));

	tmpreg = (uint32_t)1 << (RNG_STATE_DEIC_POS + Select);
	tmask = (uint32_t)1 << (RNG_STATE_DEIC_POS + Select);
	RNG_STATE = SFR_Config(RNG_STATE, ~tmask, tmpreg);
	while((RNG_STATE & ((uint32_t)1<<Select))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	RNG_STATE = SFR_Config(RNG_STATE, ~tmask, FALSE);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * 描述: 获取中断标志。
  * 输入: Select : 	RNG_INT_TSR ： 真随机数种子就绪中断标志
  * 				RNG_INT_DR ： 随机数数据就绪中断标志
  * 				RNG_INT_DE ： 随机数错误中断标志
  * 返回: 0 ：未就绪（没有错误）
  * 	  1 : 就绪(错误)
  */
FlagStatus RNG_Get_INT_Flag(uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_RNG_INT(Select));

	tmask = (uint32_t)1 << Select;
	return ((RNG_STATE & tmask) >> Select);
}
/**
  * 描述: 获取随机数种子。
  * 输入：无
  * 返回: 16位的随机种子
  */
uint16_t RNG_Seed_Value(void)
{
	return (RNG_SEED & 0xFFFF);
}
/**
  * 描述: 获取随机数种子。
  * 输入：无
  * 返回: 16位的随机种子
  */
uint32_t RNG_Data_Value(void)
{
	return RNG_DR;
}



