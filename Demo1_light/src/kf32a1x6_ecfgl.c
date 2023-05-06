/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_ecfgl.c                               	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Enhance Configurable logic 	  *
 *						unit (ECFGL) peripherals function              		  *
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

#include "kf32a1x6_ecfgl.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### 可编程逻辑阵列(ECFGL)控制功能函数 #####
  */
/**
  * 描述 : 复位ECFGL模块，使能外设时钟。
  * 输入 : 无。
  * 返回 : 无。
  */
void ECFGL_Reset (void)
{
    /* 复位ECFGL模块 */
    RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_ECFGLRST, TRUE);
    RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_ECFGLRST, FALSE);
    /* 使能ECFGL时钟 */
    PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_ECFGLPCLKEN, TRUE);
}
/**
  * 描述 : ECFGL输出使能。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 	 	NewState :
  * 	 				TRUE : 使能ECFGL输出
  * 	 				FALSE : 禁止ECFGL输出
  * 返回 : 无。
  */
void ECFGL_Output_Enable(uint32_t ECFGLx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << ECFGL_CTL_EN_POS;
	tmask = ECFGL_CTL_EN;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * 描述 : 可编程逻辑盒子功能选择。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 	 	Function ： 	ECFGL_FUNCTION_0
  * 	 				ECFGL_FUNCTION_NOR
  * 	 				ECFGL_FUNCTION_B_AND_notA
  * 	 				ECFGL_FUNCTION_notA
  * 	 				ECFGL_FUNCTION_A_AND_notB
  * 	 				ECFGL_FUNCTION_notB
  * 	 				ECFGL_FUNCTION_EXOR
  * 	 				ECFGL_FUNCTION_NAND
  * 	 				ECFGL_FUNCTION_AND
  * 	 				ECFGL_FUNCTION_EXNOR
  * 	 				ECFGL_FUNCTION_B
  * 	 				ECFGL_FUNCTION_notA_OR_B
  * 	 				ECFGL_FUNCTION_A
  * 	 				ECFGL_FUNCTION_A_OR_notB
  * 	 				ECFGL_FUNCTION_OR
  * 	 				ECFGL_FUNCTION_1
  * 返回 : 无。
  */
void ECFGL_Function_Select(uint32_t ECFGLx, uint32_t Function)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_FUNCTION(Function));

	tmpreg = Function << ECFGL_CTL_FUNSEL0_POS;
	tmask = ECFGL_CTL_FUNSEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * 描述 : MUX4输入选择。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 	 	Select ： 	ECFGL_MUX4IN_ECFGL_OUTPUT : 选择可编程逻辑盒子的输出
  * 	 				ECFGL_MUX4IN_ECFGL_OUTPUT_FLTER : 选择可编程逻辑盒子的输出经滤波采样后的信号
  * 返回 : 无。
  */
void ECFGL_MUX4IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX4IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX4SEL_POS;
	tmask = ECFGL_CTL_MUX4SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * 描述 : MUX3输入选择。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 	 	Select ： 	ECFGL_MUX3IN_EXTERNAL_SINGLE : 选择外部信号
  * 	 				ECFGL_MUX3IN_MUX1_OUTPUT : 选择MUX1的输出
  * 返回 : 无。
  */
void ECFGL_MUX3IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX3IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX3SEL_POS;
	tmask = ECFGL_CTL_MUX3SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * 描述 : MUX2输入选择。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 	 	Select ： 	ECFGL_MUX2IN_SOFTWARE : 选择软件位
  * 	 				ECFGL_MUX2IN_MUX0_OUTPUT : 选择MUX0的输出
  * 返回 : 无。
  */
void ECFGL_MUX2IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX2IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX2SEL_POS;
	tmask = ECFGL_CTL_MUX2SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * 描述 : MUX1输入选择。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 	 	Select ： 	ECFGL_MUX1IN_00 : 详细作用见用户手册
  * 	 				ECFGL_MUX1IN_01 : 详细作用见用户手册
  * 	 				ECFGL_MUX1IN_10 : 详细作用见用户手册
  * 	 				ECFGL_MUX1IN_11 : 详细作用见用户手册
  * 返回 : 无。
  */
void ECFGL_MUX1IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX1IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX1SEL0_POS;
	tmask = ECFGL_CTL_MUX1SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * 描述 : MUX0输入选择。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 	 	Select ： 	ECFGL_MUX0IN_00 : 详细作用见用户手册
  * 	 				ECFGL_MUX0IN_01 : 详细作用见用户手册
  * 	 				ECFGL_MUX0IN_10 : 详细作用见用户手册
  * 	 				ECFGL_MUX0IN_11 : 详细作用见用户手册
  * 返回 : 无。
  */
void ECFGL_MUX0IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX0IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX0SEL0_POS;
	tmask = ECFGL_CTL_MUX0SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}


/**
  * 描述 : MUX2软件选择位时的输入。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 	 	Select ： 	ECFGL_MUX2IN_0 : 对应子模块MUX2SEL=0时，选择软件位，MUX2输入0
  * 	 				ECFGL_MUX2IN_1 : 对应子模块MUX2SEL=0时，选择软件位，MUX2输入1
  * 返回 : 无。
  */
void ECFGL_MUX2IN_Software_Bit_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CEHCK_ECFGL_MUX2IN(Select));

	tmpreg = Select << ECFGLx;
	tmask = 1 << ECFGLx;
	ECFGL_SOFTSEL = SFR_Config(ECFGL_SOFTSEL, ~tmask, tmpreg);
}
/**
  * 描述 : 滤波时钟分频选择。
  * 输入 : 	ECFGL_DIV ： 	ECFGL_FLITER_DIV1 : 1分频
  *  			 		ECFGL_FLITER_DIV2 : 2分频
  *  			 		ECFGL_FLITER_DIV4 : 4分频
  *  			 		ECFGL_FLITER_DIV8 : 8分频
  *  			 		ECFGL_FLITER_DIV16 : 16分频
  * 返回 : 无。
  */
void ECFGL_Fliter_Clock_Div_Select(uint32_t ECFGL_DIV)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_FLITER_DIV(ECFGL_DIV));

	tmpreg = ECFGL_DIV << ECFGL_FCLK_FCLKDIV0_POS;
	ECFGL_FCLK = SFR_Config(ECFGL_FCLK, ~ECFGL_FCLK_FCLKDIV, tmpreg);
}
/**
  * 描述 : 滤波时钟选择。
  * 输入 : 	CLK ： 	ECFGL_CLK_SCLK : SCLK
  *  			 	ECFGL_CLK_HFCLK : HFCLK
  *  			 	ECFGL_CLK_LFCLK : LFCLK
  *  			 	ECFGL_CLK_CH1_TROUT : TRGMUX的CH1_TROUT
  *  			 	ECFGL_CLK_INTLF : INTLF
  * 返回 : 无。
  */
void ECFGL_Fliter_Clock_Select(uint32_t CLK)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_FLITER_CLK(CLK));

	ECFGL_FCLK = SFR_Config(ECFGL_FCLK, ~ECFGL_FCLK_FCLKSEL, CLK);
}
/**
  * 描述 : ECFGLx中断清零。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 返回 : ECFGLx中断清零状态。
  */
RetStatus ECFGLx_Clear_INT_Flag(uint32_t ECFGLx)
{
	uint32_t tmask;
	uint32_t wait_flag = 0x0000;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));

	tmask = 1 << ECFGLx;
	ECFGL_IC = SFR_Config(ECFGL_IC, ~tmask, tmask);
	while((ECFGL_IF & tmask)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	ECFGL_IC = SFR_Config(ECFGL_IC, ~tmask, 0);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * 描述 : 获取ECFGLx中断标志。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 返回 : 	0 ： 无作用
  *			1 ： 对应的子模块	产生了中断
  */
FlagStatus ECFGLx_Get_INT_Flag(uint32_t ECFGLx)
{
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));

	tmask = 1 << ECFGLx;
	return ((ECFGL_IF & tmask) >> ECFGLx);
}
/**
  * 描述 : ECFGLx上升边沿中断允许。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 		Select :
  * 				TRUE : ECFGLx_IF 将在ECFGLx_OUT出现上升沿时置1
  * 				FALSE : ECFGLx_IF 不会在ECFGLx_OUT出现上升沿时置1
  * 返回 : 	无。
  */
void ECFGLx_Rise_INT_Enable(uint32_t ECFGLx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << ECFGLx;
	tmask = 1 << ECFGLx;
	ECFGL_RFCTL = SFR_Config(ECFGL_RFCTL, ~tmask, tmpreg);
}
/**
  * 描述 : ECFGLx下降边沿中断允许。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 		NewState :
  * 				TRUE : ECFGLx_IF 将在ECFGLx_OUT出现下降沿时置1
  * 				FALSE : ECFGLx_IF 不会在ECFGLx_OUT出现下降沿时置1
  * 返回 : 	无。
  */
void ECFGLx_Fall_INT_Enable(uint32_t ECFGLx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << ECFGLx;
	tmask = 1 << ECFGLx;
	ECFGL_FFCTL = SFR_Config(ECFGL_FFCTL, ~tmask, tmpreg);
}
/**
  * 描述 :  ADC触发使能。
  * 输入 : 	NewState :
  * 				TRUE ： 使能ECFGL触发ADC的功能
  * 				FALSE : 无作用
  * 返回 : 	无。
  */
void ECFGLx_Trigger_ADC_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << ECFGL_ADC_ADCTRIEN_POS;
	ECFGL_ADC = SFR_Config(ECFGL_ADC, ~ECFGL_ADC_ADCTRIEN, tmpreg);
}
/**
  * 描述 :  触发源选择。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 返回 : 	无。
  */
void ECFGLx_Trigger_ADC_Source_Select(uint32_t ECFGLx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));

	ECFGL_ADC = SFR_Config(ECFGL_ADC, ~ECFGL_ADC_ADCTRISEL, ECFGLx);
}
/**
  * 描述 : 获取ECFGLx输出状态。
  * 输入 : 	ECFGLx : 范围ECFGL0~ECFGL15。
  * 返回 : 	0 ： ECFGLx输出0
  *			1 ： ECFGLx输出1
  */
FlagStatus ECFGLx_Get_ECFGLx_Output_Status(uint32_t ECFGLx)
{
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));

	tmask = 1 << ECFGLx;
	return ((ECFGL_OUT & tmask) >> ECFGLx);
}



