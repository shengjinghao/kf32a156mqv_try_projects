/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_hrcap.c                            	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the High precision capture 		  *
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

#include "kf32a1x6_hrcap.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### 高精度捕捉(HRCAP)控制功能函数 #####
  */
/**
  * 描述 : 复位HRCAP模块，使能外设时钟。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 返回 : 无。
  */
void HRCAP_Reset (HRCAP_SFRmap* HRCAPx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));

	if(HRCAPx == HRCAP0_SFR)
	{
		/* 复位PLA模块 */
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP0RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP0RST, FALSE);
		/* 使能PLA时钟 */
		PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_HRCAP0CLKEN, TRUE);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		/* 复位PLA模块 */
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP1RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP1RST, FALSE);
		/* 使能PLA时钟 */
		PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_HRCAP1CLKEN, TRUE);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		/* 复位PLA模块 */
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP2RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP2RST, FALSE);
		/* 使能PLA时钟 */
		PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_HRCAP2CLKEN, TRUE);
	}
	else
	{
		;
	}
}

/**
  * 描述 : HRCAPx模块工作时钟选择。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  CLK : 	HRCAP_CLK_SCLK : SCLK
  * 	  			HRCAP_CLK_HFCLK : HFCLK
  * 	  			HRCAP_CLK_LFCLK : LFCLK
  * 返回 : 无。
  */
void HRCAP_CLK_Select(HRCAP_SFRmap* HRCAPx, uint32_t CLK)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CLK(CLK));

	tmpreg = CLK << HRCAP_CTL_CLKSEL0_POS;
	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_CTL = SFR_Config(HC0_CTL, ~HRCAP_CTL_CLKSEL, tmpreg);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_CTL = SFR_Config(HC1_CTL, ~HRCAP_CTL_CLKSEL, tmpreg);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_CTL = SFR_Config(HC2_CTL, ~HRCAP_CTL_CLKSEL, tmpreg);
	}
	else
	{
		;
	}
}

/**
  * 描述 : HRCAPx软件复位使能。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  NewState : 	TRUE : 使能HRCAPx软件复位
  * 	  				FALSE : 禁止HRCAPx软件复位
  * 返回 : 无。
  */
void HRCAP_Software_Reset_Enable(HRCAP_SFRmap* HRCAPx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << HRCAP_CTL_SOFTRESET_POS;
	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_CTL = SFR_Config(HC0_CTL, ~HRCAP_CTL_SOFTRESET, tmpreg);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_CTL = SFR_Config(HC1_CTL, ~HRCAP_CTL_SOFTRESET, tmpreg);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_CTL = SFR_Config(HC2_CTL, ~HRCAP_CTL_SOFTRESET, tmpreg);
	}
	else
	{
		;
	}
}

/**
  * 描述 : HRCAPx中断使能。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  Select : 		HRCAP_COUNTOVER_INT : HRCAPx计数溢出中断
  * 	  				HRCAP_FALL_INT : HRCAPx下降沿捕捉中断
  * 	  				HRCAP_RISE_INT : HRCAPx上升沿捕捉中断
  * 	  NewState : 	TRUE : 使能HRCAPx软件复位
  * 	  				FALSE : 禁止HRCAPx软件复位
  * 返回 : 无。
  */
void HRCAP_INT_Enable(HRCAP_SFRmap* HRCAPx,uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_INT(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (HRCAP_CTL_RISEINTE_POS + Select);
	tmask = 1 << (HRCAP_CTL_RISEINTE_POS + Select);
	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_CTL = SFR_Config(HC0_CTL, ~tmask, tmpreg);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_CTL = SFR_Config(HC1_CTL, ~tmask, tmpreg);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_CTL = SFR_Config(HC2_CTL, ~tmask, tmpreg);
	}
	else
	{
		;
	}
}

/**
  * 描述 : HRCAPx捕捉输入选择。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  Select : 		HRCAP_EXTERNAL_INPUT : 选择专用的HRCAPx外部输入引脚
  * 	  				HRCAP_HRPWMX_OUTPUT : 选择对应的HRPWMx输出信号
  * 返回 : 无。
  */
void HRCAP_Cap_Input_Select(HRCAP_SFRmap* HRCAPx, uint32_t Select)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_INPUT(Select));

	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_CTL = SFR_Config(HC0_CTL, ~HRCAP_CTL_HCINSEL, Select);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_CTL = SFR_Config(HC1_CTL, ~HRCAP_CTL_HCINSEL, Select);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_CTL = SFR_Config(HC2_CTL, ~HRCAP_CTL_HCINSEL, Select);
	}
	else
	{
		;
	}
}

/**
  * 描述 : 获取16位的经过锁存之后的HRCAPx计数器的值。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 返回 : 16位的计数值。
  * 注：推荐使用此函数获取HRCAPx计数器的值。
  */
uint16_t HRCAP_Read_Latch_Count_Value(HRCAP_SFRmap* HRCAPx)
{
	uint32_t Value = 0;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));

	if(HRCAPx == HRCAP0_SFR)
	{
		Value = (HC0_COUNTER & HRCAP_COUNTER_COUNTERSR) >> HRCAP_COUNTER_COUNTERSR0_POS;
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		Value = (HC1_COUNTER & HRCAP_COUNTER_COUNTERSR) >> HRCAP_COUNTER_COUNTERSR0_POS;
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		Value = (HC2_COUNTER & HRCAP_COUNTER_COUNTERSR) >> HRCAP_COUNTER_COUNTERSR0_POS;
	}
	else
	{
		;
	}

	return Value;
}

/**
  * 描述 : 获取16位的HRCAPx计数器的值。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 返回 : 16位的计数值。
  */
uint16_t HRCAP_Read_Count_Value(HRCAP_SFRmap* HRCAPx)
{
	uint32_t Value = 0;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));

	if(HRCAPx == HRCAP0_SFR)
	{
		Value = HC0_COUNTER & HRCAP_COUNTER_COUNTER;
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		Value = HC1_COUNTER & HRCAP_COUNTER_COUNTER;
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		Value = HC2_COUNTER & HRCAP_COUNTER_COUNTER;
	}
	else
	{
		;
	}

	return Value;
}

/**
  * 描述 : 获取16位的HRCAPx上升沿整数捕捉寄存器的值。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  HRCAP_REG ：    HRCAP_REGISTER0 : 寄存器0
  * 	  				HRCAP_REGISTER1 : 寄存器1
  * 返回 : 16位的值。
  */
uint16_t HRCAP_Read_Rise_Integer_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG)
{
	uint32_t Value = 0;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_REGISTER(HRCAP_REG));

	Value = HRCAPx->RISE[HRCAP_REG] & HRCAP_RISE0_RISE0;

	return Value;
}

/**
  * 描述 : 获取16位的HRCAPx下降沿整数捕捉寄存器的值。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  HRCAP_REG ：    HRCAP_REGISTER0 : 寄存器0
  * 	  				HRCAP_REGISTER1 : 寄存器1
  * 返回 : 16位的值。
  */
uint16_t HRCAP_Read_Fall_Integer_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG)
{
	uint32_t Value = 0;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_REGISTER(HRCAP_REG));

	Value = HRCAPx->FALL[HRCAP_REG] & HRCAP_FALL0_FALL0;

	return Value;
}

/**
  * 描述 : 获取16位的HRCAPx上升沿小数捕捉寄存器的值。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  HRCAP_REG ：    HRCAP_REGISTER0 : 寄存器0
  * 	  				HRCAP_REGISTER1 : 寄存器1
  * 返回 : 16位的值。
  */
uint16_t HRCAP_Read_Rise_Decimal_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG)
{
	uint32_t Value = 0;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_REGISTER(HRCAP_REG));

	Value = HRCAPx->HRRISE[HRCAP_REG] & HRCAP_HRRISE0_HRRISE0;

	return Value;
}

/**
  * 描述 : 获取16位的HRCAPx下降沿小数捕捉寄存器的值。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  HRCAP_REG ：    HRCAP_REGISTER0 : 寄存器0
  * 	  				HRCAP_REGISTER1 : 寄存器1
  * 返回 : 16位的值。
  */
uint16_t HRCAP_Read_Fall_Decimal_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG)
{
	uint32_t Value = 0;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_REGISTER(HRCAP_REG));

	Value = HRCAPx->HRFALL[HRCAP_REG] & HRCAP_HRFALL0_HRFALL0;

	return Value;
}

/**
  * 描述 : 获取HRCAPx中断标志位。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  Select : 	HRCAP_RISEOVER_INT : 上升沿捕捉中断溢出事件
  * 	  			HRCAP_COUNTOVER_INT : 计数溢出事件
  * 	  			HRCAP_FALL_INT : 下降沿捕捉中断事件
  * 	  			HRCAP_RISE_INT : 上升沿捕捉中断事件
  * 返回 : 0 : 无中断事件发生
  * 	  1  ： 发送中断事件。
  */
FlagStatus HRCAP_Get_INT_Flag(HRCAP_SFRmap* HRCAPx, uint32_t Select)
{
	uint32_t Value = 0;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_INT_FLAG(Select));

	Select += HRCAP_SR_RISEIF_POS;
	tmask = 1 << Select;
	if(HRCAPx == HRCAP0_SFR)
	{
		Value = (HC0_SR & tmask) >> Select;
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		Value = (HC1_SR & tmask) >> Select;
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		Value = (HC2_SR & tmask) >> Select;
	}
	else
	{
		;
	}

	return Value;
}

/**
  * 描述 : 清除HRCAPx中断标志位。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  Select : 	HRCAP_RISEOVER_INT : 上升沿捕捉中断溢出事件
  * 	  			HRCAP_COUNTOVER_INT : 计数溢出事件
  * 	  			HRCAP_FALL_INT : 下降沿捕捉中断事件
  * 	  			HRCAP_RISE_INT : 上升沿捕捉中断事件
  * 返回 : 清除HRCAPx中断标志位是否成功
  */
RetStatus HRCAP_Clear_INT_Flag(HRCAP_SFRmap* HRCAPx, uint32_t Select)
{
	uint32_t tmask;
	uint32_t wait_flag=0x0000;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_INT_FLAG(Select));


	tmask = 1 << (Select+HRCAP_SRIC_RISEIC_POS);

	HRCAPx->SRIC = SFR_Config(HRCAPx->SRIC, ~tmask, tmask);
	while((HRCAPx->SR & tmask)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	HRCAPx->SRIC = SFR_Config(HRCAPx->SRIC, ~tmask, 0);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * 描述 : HRCAPx中断标志位强制置位使能。
  * 输入 : HRCAPx : 	HRCAP0_SFR、HRCAP1_SFR和HRCAP2_SFR
  * 	  Select : 	HRCAP_COUNTOVER_INT : 计数溢出事件
  * 	  			HRCAP_FALL_INT : 下降沿捕捉中断事件
  * 	  			HRCAP_RISE_INT : 上升沿捕捉中断事件
  * 	  NewState : TRUE : 强制置位
  * 	  			 FALSE : 无动作
  */
void HRCAP_INT_Mandatory_Enable(HRCAP_SFRmap* HRCAPx, uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_MANDATORY_INT(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (Select + HRCAP_IFRC_RISEIFRC_POS);
	tmask = 1 << (Select + HRCAP_IFRC_RISEIFRC_POS);

	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_IFRC = SFR_Config(HC0_IFRC, ~tmask, tmpreg);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_IFRC = SFR_Config(HC1_IFRC, ~tmask, tmpreg);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_IFRC = SFR_Config(HC2_IFRC, ~tmask, tmpreg);
	}
	else
	{
		;
	}
}


