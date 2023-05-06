/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_fdc.c                                 	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Flex Delay Controller (FDC) 	  *
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
#include "kf32a1x6_fdc.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### 可编程延时模块(FDC)初始化函数 #####
  */

/**
  * 描述: 复位FDC外设，使能外设时钟。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 返回: 无。
  */
void FDC_Reset(FDC_SFRmap* FDCx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	if(FDCx == FDC0_SFR)
	{
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC0RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC0RST, FALSE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_FDC0CLKEN, TRUE);
	}
	else if(FDCx == FDC1_SFR)
	{
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC1RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC1RST, FALSE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_FDC1CLKEN, TRUE);
	}
	else if(FDCx == FDC2_SFR)
	{
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC2RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC2RST, FALSE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_FDC2CLKEN, TRUE);
	}
	else
	{
		;
	}
}
/**
  * 描述: TRGI/SWTRIG 信号在 FDC 计数器计数过程中复位计数值使能。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 	  	NewState:
  * 	  			TRUE: 使能
  * 	  			FALSE: 不使能
  * 返回: 无。
  */
void FDC_TRGI_Count_Reset_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_TCLR_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_TCLR, tmpreg);
}
/**
  * 描述: 配置FDC工作时钟选择。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 	  	CLK:
  * 	  			FDC_WORK_CLK_SCLK: 选择SCLK作为FDC的工作时钟
  * 	  			FDC_WORK_CLK_HFCLK: 选择HFCLK作为FDC的工作时钟
  * 	  			FDC_WORK_CLK_LFCLK: 选择LFCLK作为FDC的工作时钟
  * 返回: 无。
  */
void FDC_Work_Clk_Select(FDC_SFRmap* FDCx, uint32_t CLK)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_WORK_CLK(CLK));

	tmpreg = CLK << FDC_CTL_CLKSEL0_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_CLKSEL, tmpreg);
}
/**
  * 描述: MDLIF标志位清除。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 	  	NewState:
  * 	  			TRUE: 清除MDLIF标志位
  * 	  			FALSE: 不清除MDLIF标志位
  * 返回: 无。
  */
RetStatus FDC_Clear_MDLIF_Flag(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t wait_flag = 0x0000;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_MDLIC_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_MDLIC, tmpreg);
	while((!(FDCx->CTL & FDC_CTL_MDLIC))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_MDLIC, 0);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * 描述: 循环扫描CHmDLY寄存器使能。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 	  	NewState:
  * 	  			TRUE: 使能
  * 	  			FALSE: 不使能
  * 返回: 无。
  */
void FDC_Cycle_Scan_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_CMODE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_CMODE, tmpreg);
}
/**
  * 描述: FDC工作模式选择。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 	  	MODE:
  * 	  			FDC_WORK_RANDOM: FDC工作在随机模式
  * 	  			FDC_WORK_FIXED: FDC工作在定序模式
  * 返回: 无。
  */
void FDC_Work_Mode_Select(FDC_SFRmap* FDCx, uint32_t MODE)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_WORK_MODE(MODE));

	tmpreg = MODE << FDC_CTL_BBMODE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_BBMODE, tmpreg);
}
/**
  * 描述: 更新模式选择。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 	  	MODE:
  * 	  			FDC_UPDATA_NOW: 在LDOK写一后，BUF中的值立即更新到寄存器中
  * 	  			FDC_UPDATA_EQUAL_MODA1: 在LDOK写一后，BUF中的值在FDC计数值等于MOD+1时，更新到寄存器中
  * 	  			FDC_UPDATA_TRIGGER： 在LDOK写一后，BUF中的值在检测到输入触发后更新到寄存器中
  * 	  			FDC_UPDATA_TRIGGER_MODA1: 在LDOK写一后，BUF中的值在检测到输入触发或者FDC计数值等于MOD+1时，均可更新到寄存器中
  * 返回: 无。
  */
void FDC_Updata_Mode_Select(FDC_SFRmap* FDCx, uint32_t MODE)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_UPDATA_MODE(MODE));

	tmpreg = MODE << FDC_CTL_LDMOD0_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_LDMOD, tmpreg);
}
/**
  * 描述: FDC序列错误中断使能。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 	  	NewState:
  * 	  			TRUE: 使能FDC序列错误中断
  * 	  			FALSE: 不使能FDC序列错误中断
  * 返回: 无。
  */
void FDC_Sequence_Error_INT_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_FDCEIE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_FDCEIE, tmpreg);
}
/**
  * 描述: 软件触发。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 返回: 无。
  * 注： 当FDC使能并且选择软件触发作为FDC的触发输入源时，对SWTRIG写一，复位FDC计数器使其重新计数。
  */
void FDC_Software_Triggle_Enable(FDC_SFRmap* FDCx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_SWTRIG, FDC_CTL_SWTRIG);
}
/**
  * 描述: MDL中断DMA请求使能。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		NewState:
  * 				TRUE: 使能MDLIF产生DMA请求
  * 				FALSE: 禁止MDLIF产生DMA请求
  * 返回: 无。
  */
void FDC_MDL_INT_DMA_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_FDCDE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_FDCDE, tmpreg);
}
/**
  * 描述: 预分频选择。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Select:
  * 				FDC_PRE_SCALER_MUL: 计数时钟选择1：MUL
  * 				FDC_PRE_SCALER_2MUL: 计数时钟选择1：2*MUL
  * 				FDC_PRE_SCALER_4MUL: 计数时钟选择1：4*MUL
  * 				FDC_PRE_SCALER_8MUL: 计数时钟选择1：8*MUL
  * 				FDC_PRE_SCALER_16MUL: 计数时钟选择1：16*MUL
  * 				FDC_PRE_SCALER_32MUL: 计数时钟选择1：32*MUL
  * 				FDC_PRE_SCALER_64MUL: 计数时钟选择1：64*MUL
  * 				FDC_PRE_SCALER_128MUL: 计数时钟选择1：128*MUL
  * 返回: 无。
  */
void FDC_Prescaler_Select(FDC_SFRmap* FDCx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_PRESCALER(Select));

	tmpreg = Select << FDC_CTL_PRESC0_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_PRESC, tmpreg);
}
/**
  * 描述: 分频因子。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Value: Value <= 0x3F
  * 返回: 无。
  */
void FDC_Scaler_Factor(FDC_SFRmap* FDCx, uint32_t Value)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_SCALER_FACTOR(Value));

	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_MULSEL, Value << FDC_CTL_MULSEL0_POS);
}
/**
  * 描述: 触发输入源选择。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Select: 	FDC_INPUT_TRIGGLE: 选择输入源触发
  * 					FDC_SOFTWARE_TRIGGLE: 选择软件触发
  * 返回: 无。
  */
void FDC_Triggle_Input_Select(FDC_SFRmap* FDCx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_INPUT_TRIGGLE(Select));

	tmpreg = Select << FDC_CTL_TRGSEL_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_TRGSEL, tmpreg);
}
/**
  * 描述: MDL中断使能位。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		NewState: 	TRUE: 允许MDL中断使能
  * 					FALSE: 禁止MDL中断使能
  * 返回: 无。
  */
void FDC_MDL_INT_Enable(FDC_SFRmap* FDCx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_INPUT_TRIGGLE(Select));

	tmpreg = Select << FDC_CTL_MDLIE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_MDLIE, tmpreg);
}
/**
  * 描述: 获取MDL中断标志。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 返回: 无。
  */
FlagStatus FDC_Get_MDL_INT_Flag(FDC_SFRmap* FDCx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	return ((FDCx->CTL & FDC_CTL_MDLIF) >> FDC_CTL_MDLIF_POS);
}
/**
  * 描述: 单次模式使能。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		NewState: 	TRUE: FDC选择单次模式
  * 					FALSE: FDC选择连续模式
  * 返回: 无。
  */
void FDC_Single_Mode_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_CONT_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_CONT, tmpreg);
}
/**
  * 描述: LDOK位写1。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 返回: 无。
  */
void FDC_Ldok_Write1(FDC_SFRmap* FDCx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_LDOK, FDC_CTL_LDOK);
}
/**
  * 描述: 脉冲输出使能信号。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		NewState: 	TRUE: 使能脉冲输出功能
  * 					FALSE: 不使能脉冲输出功能
  * 返回: 无。
  */
void FDC_Pulse_Output_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_POEN_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_POEN, tmpreg);
}
/**
  * 描述: FDC模块使能。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		NewState: 	TRUE: 使能脉冲输出功能
  * 					FALSE: 不使能脉冲输出功能
  * 返回: 无。
  */
void FDC_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_FDCEN, FDC_CTL_FDCEN);
}


/**
  * 描述: 配置FDC计数周期。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Value: Value <= 0xFFFF
  * 返回: 无。
  */
void FDC_Set_Count_Cycle(FDC_SFRmap* FDCx, uint32_t Value)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_COUNT_CYCLE(Value));

	FDCx->MOD = Value;
}
/**
  * 描述: 获取FDC计数周期。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 返回:  16位的计数周期。
  */
uint16_t FDC_Get_Count_Cycle(FDC_SFRmap* FDCx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	return (FDCx->MOD & 0xFFFF);
}
/**
  * 描述: 获取FDC当前的计数值。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 返回:  16位的计数值。
  */
uint16_t FDC_Get_Count_Value(FDC_SFRmap* FDCx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	return (FDCx->CNT & 0xFFFF);
}
/**
  * 描述: 获取FDC中断延时。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 返回:  16位值。
  */
uint16_t FDC_Get_INT_Delay_Value(FDC_SFRmap* FDCx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	return (FDCx->IDLY & 0xFFFF);
}
/**
  * 描述: FDC通道序列错误标志清零。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		n: n<=4
  * 		NewState:  	TRUE: 清零ERRICn标志位
  * 				   	FALSE: 不清零ERRICn标志位
  * 返回:  无
  */
void FDC_Clear_Channel_List_Error_Flag(FDC_SFRmap* FDCx,uint32_t Channel, uint8_t n, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (FDC_CH0CTL_ERRIC0_POS + n);
	tmask = 1 << (FDC_CH0CTL_ERRIC0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0CTL = SFR_Config(FDCx->CH0CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1CTL = SFR_Config(FDCx->CH1CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2CTL = SFR_Config(FDCx->CH2CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3CTL = SFR_Config(FDCx->CH3CTL, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * 描述: 获取FDC通道序列错误标志。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		n: n<=4
  * 返回:  FDC通道序列错误标志
  */
FlagStatus FDC_Get_Channel_List_Error_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));

	tmpreg = FDC_CH0CTL_ERR0_POS + n;
	tmask = (uint32_t)1 << (FDC_CH0CTL_ERR0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		return ((FDCx->CH0CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_1:
		return ((FDCx->CH1CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_2:
		return ((FDCx->CH2CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_3:
		return ((FDCx->CH3CTL & tmask) >> tmpreg);
		break;
	default:break;
	}
}
/**
  * 描述: 获取CFn标志。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		n: n<=4
  * 返回:  CFn标志状态
  */
FlagStatus FDC_Get_CFn_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));

	tmpreg = FDC_CH0CTL_CF0_POS + n;
	tmask = (uint32_t)1 << (FDC_CH0CTL_CF0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		return ((FDCx->CH0CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_1:
		return ((FDCx->CH1CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_2:
		return ((FDCx->CH2CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_3:
		return ((FDCx->CH3CTL & tmask) >> tmpreg);
		break;
	default:break;
	}
}
/**
  * 描述: 配置FDC通道预触发输出选择。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		n: n<=4
  * 		Select:     FDC_PRE_TRIGGLE_MODE0 :预触发信号在检测到FDC输入信号上升沿或者SWTRIG被置一后，	当CNT等于DLYn值后产生
  * 					FDC_PRE_TRIGGLE_BYPASS :预触发信号在检测到FDC输入信号上升沿或者SWTRIG	被置一后立即产生
  * 返回:  无
  */
void FDC_Channel_Pre_Triggle_Select(FDC_SFRmap* FDCx,uint32_t Channel, uint8_t n, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));
	CHECK_RESTRICTION(CHECK_FDC_PRE_TRIGGLE(Select));

	tmpreg = Select << (FDC_CH0CTL_TOS0_POS + n);
	tmask = 1 << (FDC_CH0CTL_TOS0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0CTL = SFR_Config(FDCx->CH0CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1CTL = SFR_Config(FDCx->CH1CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2CTL = SFR_Config(FDCx->CH2CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3CTL = SFR_Config(FDCx->CH3CTL, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * 描述: 配置FDC通道产生预触发信号使能。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		n: n<=4
  * 		NewState:   TRUE : 使能CHm产生预触发信号PREn
  * 					FALSE : 不使能CHm产生预触发信号PREn
  * 返回:  无
  */
void FDC_Channel_Pre_Signel_Enable(FDC_SFRmap* FDCx,uint32_t Channel, uint8_t n, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (FDC_CH0CTL_PREN0_POS + n);
	tmask = 1 << (FDC_CH0CTL_PREN0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0CTL = SFR_Config(FDCx->CH0CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1CTL = SFR_Config(FDCx->CH1CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2CTL = SFR_Config(FDCx->CH2CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3CTL = SFR_Config(FDCx->CH3CTL, ~tmask, tmpreg);
		break;
	default:break;
	}
}


/**
  * 描述: 配置 FDC通道m延时寄存器0, 第0个预触发信号延迟。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		Value:   Value<=0xFFFF
  * 返回:  无
  */
void FDC_Channelm_Pre_Triggle_Delay0(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY0_DLY0_0_POS;
	tmask = FDC_CH0DLY0_DLY0;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY0 = SFR_Config(FDCx->CH0DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY0 = SFR_Config(FDCx->CH1DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY0 = SFR_Config(FDCx->CH2DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY0 = SFR_Config(FDCx->CH3DLY0, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * 描述: 配置 FDC通道m延时寄存器0, 第1个预触发信号延迟。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		Value:   Value<=0xFFFF
  * 返回:  无
  */
void FDC_Channelm_Pre_Triggle_Delay1(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY0_DLY1_0_POS;
	tmask = FDC_CH0DLY0_DLY1;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY0 = SFR_Config(FDCx->CH0DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY0 = SFR_Config(FDCx->CH1DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY0 = SFR_Config(FDCx->CH2DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY0 = SFR_Config(FDCx->CH3DLY0, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * 描述: 配置 FDC通道m延时寄存器1, 第2个预触发信号延迟。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		Value:   Value<=0xFFFF
  * 返回:  无
  */
void FDC_Channelm_Pre_Triggle_Delay2(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY1_DLY2_0_POS;
	tmask = FDC_CH0DLY1_DLY2;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY1 = SFR_Config(FDCx->CH0DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY1 = SFR_Config(FDCx->CH1DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY1 = SFR_Config(FDCx->CH2DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY1 = SFR_Config(FDCx->CH3DLY1, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * 描述: 配置 FDC通道m延时寄存器1, 第3个预触发信号延迟。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		Value:   Value<=0xFFFF
  * 返回:  无
  */
void FDC_Channelm_Pre_Triggle_Delay3(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY1_DLY3_0_POS;
	tmask = FDC_CH0DLY1_DLY3;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY1 = SFR_Config(FDCx->CH0DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY1 = SFR_Config(FDCx->CH1DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY1 = SFR_Config(FDCx->CH2DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY1 = SFR_Config(FDCx->CH3DLY1, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * 描述: 配置 FDC通道m延时寄存器2, 第4个预触发信号延迟。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		Value:   Value<=0xFFFF
  * 返回:  无
  */
void FDC_Channelm_Pre_Triggle_Delay4(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY2_DLY4_0_POS;
	tmask = FDC_CH0DLY2_DLY4;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY2 = SFR_Config(FDCx->CH0DLY2, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY2 = SFR_Config(FDCx->CH1DLY2, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY2 = SFR_Config(FDCx->CH2DLY2, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY2 = SFR_Config(FDCx->CH3DLY2, ~tmask, tmpreg);
		break;
	default:break;
	}
}


/**
  * 描述: 配置 FDC脉冲输出延时寄存器的高位。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		Value:   Value<=0xFFFF
  * 返回:  无
  */
void FDC_Pulse_Output_DelayH(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_PULSE_OUTPUT_DELAY(Value));

	tmpreg = Value << FDC_PO0DLY_DLYH0_POS;
	tmask = FDC_PO0DLY_DLYH;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->PO0DLY = SFR_Config(FDCx->PO0DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->PO1DLY = SFR_Config(FDCx->PO1DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->PO2DLY = SFR_Config(FDCx->PO2DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->PO3DLY = SFR_Config(FDCx->PO3DLY, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * 描述: 配置 FDC脉冲输出延时寄存器的低位。
  * 输入: 	FDC: 指向FDC内存结构的指针，取值为FDC0_SFR、FDC1_SFR、FDC2_SFR。
  * 		Channel: 	FDC_CHANNLE_0 : 通道0
  * 					FDC_CHANNLE_1 : 通道1
  * 					FDC_CHANNLE_2 : 通道2
  * 					FDC_CHANNLE_3 : 通道3
  * 		Value:   Value<=0xFFFF
  * 返回:  无
  */
void FDC_Pulse_Output_DelayL(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_PULSE_OUTPUT_DELAY(Value));

	tmpreg = Value << FDC_PO0DLY_DLYL0_POS;
	tmask = FDC_PO0DLY_DLYL;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->PO0DLY = SFR_Config(FDCx->PO0DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->PO1DLY = SFR_Config(FDCx->PO1DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->PO2DLY = SFR_Config(FDCx->PO2DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->PO3DLY = SFR_Config(FDCx->PO3DLY, ~tmask, tmpreg);
		break;
	default:break;
	}
}





