/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_EWDT.c                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the External Watchdog (EWDT) 	  *
 *  				    peripherals function                          		  *
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

#include "kf32a1x6_ewdt.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### 外围看门狗(EWDT)控制功能函数 #####
  */
/**
  * 描述  复位EWDT模块，使能外设时钟。
  * 输入  无。
  * 返回  无。
  */
void EWDT_Reset (void)
{
    /* 复位EWDT模块 */
    RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_EWDTRST, TRUE);
    RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_EWDTRST, FALSE);
    /* 使能EWDT时钟 */
    PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_EWDTCLKEN, TRUE);
}

/**
  * 描述  EWDT工作时钟选择。
  * 输入  CLK ： 	EWDT_CLK_INTLF ： 选择INTLF为工作时钟
  * 			EWDT_CLK_SCLK ： 选择SCLK为工作时钟
  * 			EWDT_CLK_LFCLK ： 选择LFCLK为工作时钟
  * 			EWDT_CLK_LP4M ： 选择LP4M为工作时钟
  * 返回  无
  * 注： 低功耗模式下仅可以选择INTLF或LP4M
  */
void EWDT_CLK_Select(uint32_t CLK)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EWDT_CLK(CLK));

	tmpreg = CLK << EWDT_CTL_CLKS0_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_CLKS, tmpreg);
}

/**
  * 描述  外围看门狗预分频。
  * 输入  DIV : 	EWDT_CLK_DIV1 		: EWDTCLK为所选时钟
  * 			EWDT_CLK_DIV2 		: EWDTCLK为所选时钟/2
  * 			EWDT_CLK_DIV4 		: EWDTCLK为所选时钟/4
  * 			EWDT_CLK_DIV8 		: EWDTCLK为所选时钟/8
  * 			EWDT_CLK_DIV16 		: EWDTCLK为所选时钟/16
  * 			EWDT_CLK_DIV32 		: EWDTCLK为所选时钟/32
  * 			EWDT_CLK_DIV64 		: EWDTCLK为所选时钟/64
  * 			EWDT_CLK_DIV128 	: EWDTCLK为所选时钟/128
  * 			EWDT_CLK_DIV256 	: EWDTCLK为所选时钟/256
  * 			EWDT_CLK_DIV512 	: EWDTCLK为所选时钟/512
  * 			EWDT_CLK_DIV1024 	: EWDTCLK为所选时钟/1024
  * 			EWDT_CLK_DIV2048 	: EWDTCLK为所选时钟/2048
  * 			EWDT_CLK_DIV4096 	: EWDTCLK为所选时钟/4096
  * 			EWDT_CLK_DIV8192 	: EWDTCLK为所选时钟/8192
  * 			EWDT_CLK_DIV16384 	: EWDTCLK为所选时钟/16384
  * 			EWDT_CLK_DIV32768 	: EWDTCLK为所选时钟/32768
  * 			EWDT_CLK_DIV65536 	: EWDTCLK为所选时钟/65536
  * 			EWDT_CLK_DIV131072 	: EWDTCLK为所选时钟/131072
  * 			EWDT_CLK_DIV262144 	: EWDTCLK为所选时钟/262144
  * 返回  无
  */
void EWDT_Clock_Div_Select(uint32_t CLK_DIV)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EWDT_CLK_DIV(CLK_DIV));

	tmpreg = CLK_DIV << EWDT_CTL_WPS0_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_WPS, tmpreg);
}

/**
  * 描述 EWDTIN输入信号极性选择。
  * 输入  Select : 	EWDT_INTPUT_EFFECTIVE_LOW : EWDTIN输入信号低有效
  * 	 			EWDT_INTPUT_EFFECTIVE_HIGH : EWDTIN输入信号高有效
  * 返回  无。
  */
void EWDT_Input_Effective_Single_Select(uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EWDT_INTPUT_EFFECTIVE(Select));

	tmpreg = Select << EWDT_CTL_EWDTIN_POL_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_EWDTIN_POL, tmpreg);
}

/**
  * 描述 EWDTIN输入信号使能。
  * 输入  NewState : 	TRUE : EWDTIN输入信号未使能
  * 	 			FALSE : EWDTIN输入信号未使能
  * 返回  无。
  */
void EWDT_Input_Single_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EWDT_CTL_EWDTIN_EN_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_EWDTIN_EN, tmpreg);
}

/**
  * 描述  EWDT的输出有效信号极性选择。
  * 输入  Select : 	EWDT_RESET_EFFECTIVE_LOW : EWDT产生的复位信号低有效
  * 	 			EWDT_RESET_EFFECTIVE_HIGH : EWDT产生的复位信号高有效
  * 返回  无。
  */
void EWDT_Output_Effective_Single_Select(uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EWDT_RESET_EFFECTIVE(Select));

	tmpreg = Select << EWDT_CTL_OUTSEL_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_OUTSEL, tmpreg);
}

/**
  * 描述  外围看门狗下窗口配置。
  * 输入  Threshold : Threshold <= 0x3F
  * 返回  无
  */
void EWDT_Threshold_Config(uint32_t Threshold)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EWDT_THRESHOLD(Threshold));

	tmpreg = Threshold << EWDT_CTL_WW0_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_WW, tmpreg);
}

/**
  * 描述 外围看门狗使能。
  * 输入  NewState : 	TRUE : 使能外围看门狗功能
  * 	 			FALSE : 禁止外围看门狗功能
  * 返回  无。
  */
void EWDT_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_EWDTEN, NewState);
}

/**
  * 描述 获取外围看门狗计数值。
  * 输入 无
  * 返回  EWDT的计数值。
  */
uint8_t
EWDT_Get_Count_Value(void)
{
	return (EWDT_CNT & EWDT_CNT_WT0);
}

/**
  * 描述 设置外围看门狗计数值。
  * 输入 Value ： Value <= 0x3F
  * 返回  无。
  */
void EWDT_Set_Count_Value(uint8_t Value)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EWDT_COUNT_VALUE(Value));

	EWDT_CNT = SFR_Config(EWDT_CNT, ~EWDT_CNT_WT0, Value);
}


/**
  *   ##### 外围看门狗(EWDT)中断函数 #####
  */


/**
  * 描述  EWDT产生复位信号中断使能。
  * 输入  NewState ： 	TRUE ： 使能EWDT产生复位信号触发中断
  * 					FALSE ： 禁止EWDT产生复位信号触发中断
  * 返回  无
  */
void EWDT_Reset_Single_INT_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EWDT_CTL_EWDTRSTIE_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_EWDTRSTIE, tmpreg);
}

/**
  * 描述 计数器计数到40时中断使能。
  * 输入  NewState : 	TRUE : 计数器计数到40时触发中断
  * 	 			FALSE : 禁止计数器计数到40时触发中断
  * 返回  无。
  */
void EWDT_Count40_INT_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EWDT_CTL_WT40IE_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_WT40IE, tmpreg);
}

/**
  * 描述  获取EWDT发生复位时的中断标志。
  * 输入  无
  * 返回  0 ： EWDT未发生复位
  * 	 1 : EWDT发生复位。
  */
FlagStatus EWDT_Get_Reset_INT_Flag(void)
{
	return ((EWDT_CTL & EWDT_CTL_EWDTRSTIF) >> EWDT_CTL_EWDTRSTIF_POS);
}

/**
  * 描述  获取外围看门狗计数到40中断标志。
  * 输入  无
  * 返回  无
  */
FlagStatus EWDT_Get_Count40_INT_Flag(void)
{
	return ((EWDT_CTL & EWDT_CTL_WT40IF) >> EWDT_CTL_WT40IF_POS);
}

/**
  * 描述  清零EWDT产生复位时中断标志。
  * 输入  无
  * 返回:清除EWDT产生复位时中断标志状态
  */
RetStatus EWDT_Clear_Reset_INT_Flag(void)
{
	uint32_t wait_flag = 0x0000;
	SFR_SET_BIT_ASM(EWDT_CTL, EWDT_CTL_EWDTRSTIC_POS);
	while((EWDT_CTL & EWDT_CTL_EWDTRSTIF)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	SFR_CLR_BIT_ASM(EWDT_CTL, EWDT_CTL_EWDTRSTIC_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * 描述  清零计数器计数到40时中断标志位。
  * 输入  无
  * 返回  :清除计数器计数中断标志状态
  */
RetStatus EWDT_Clear_Count40_INT_Flag(void)
{
	uint32_t wait_flag = 0x0000;
	SFR_SET_BIT_ASM(EWDT_CTL, EWDT_CTL_WW40IC_POS);
	while((EWDT_CTL & EWDT_CTL_WT40IF)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	SFR_CLR_BIT_ASM(EWDT_CTL, EWDT_CTL_WW40IC_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}


