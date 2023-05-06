/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_op.c                                 	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Operational amplifier (OP) 	  *
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

#include "kf32a1x6_op.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### 初始化及配置函数 #####
  */

/**
  * 描述 OP外设复位，使能外设时钟。
  * 输入  : 无
  * 返回  无。
  */
void OP_Reset(void)
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_OPRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_OPRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_OPCLKEN, TRUE);
}
/**
 *  描述：配置OP0/1/2/3 使能/失能
 *  输入：OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  NewState: TRUE/FALSE
 *  返回：无
 * */
void OP_Enable(uint32_t OPx_NUM, FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_CTL0 = SFR_Config(OP_CTL0, ~(1 << OPx_NUM), NewState << OPx_NUM);
}
/**
 *  描述：配置OP0/1/2/3 IO输出使能/失能
 *  输入：OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  NewState: TRUE/FALSE
 *  返回：无
 * */
void OP_OUTPUT_Enable(uint32_t OPx_NUM, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL0_OP0OUTEN_POS + OPx_NUM);
	tmask = 1 << (OP_CTL0_OP0OUTEN_POS + OPx_NUM);
	OP_CTL0 = SFR_Config(OP_CTL0, ~tmask, tmpreg);
}
/**
 *  描述：配置OP0/1/2/3 放大倍数
 *  输入：OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  GAIN_Value：  OP_GAIN_2dB：运放放大 2 倍
 *  	  			   OP_GAIN_4dB：运放放大 4 倍
 *  	  			   OP_GAIN_8dB：运放放大 8 倍
 *  	  			   OP_GAIN_16dB：运放放大 16 倍
 *  	  			   OP_GAIN_32dB：运放放大 32 倍
 *  	  			   OP_GAIN_64dB：运放放大 64 倍
 *  	  NewState: TRUE/FALSE ：运放放大倍数使能/失能
 *  返回：无
 * */
void OP_GAIN_Select(uint32_t OPx_NUM,
			uint32_t GAIN_Value, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_GAIN_VALUE(GAIN_Value));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL0_OP0GAIN2X_POS + OPx_NUM*6 + GAIN_Value);
	tmask = 1 << (OP_CTL0_OP0GAIN2X_POS + OPx_NUM*6 + GAIN_Value);
	OP_CTL0 = SFR_Config(OP_CTL0, ~tmask, tmpreg);
}
/**
 *  描述：配置OP0/1/2/3 IO输出并联10K电阻使能
 *  输入：OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  NewState: TRUE：输出并联 10KΩ 的电阻
					FALSE：无作用
 *  返回：无
 * */
void OP_OPUPUT_Parallel_Resistance(uint32_t OPx_NUM, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL1_OP010KSEL_POS + OPx_NUM);
	tmask = 1 << (OP_CTL1_OP010KSEL_POS + OPx_NUM);
	OP_CTL1 = SFR_Config(OP_CTL1, ~tmask, tmpreg);
}
/**
 *  描述：配置OP0/1/2/3的输出作为OP0/1/2的正端输入
 *  输入：	OPx_NUM_OUTPUT (那个OP的输出): OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  		OPx_NUM_PINPUT (那个OP的正端输入): OP0_NUM/OP1_NUM/OP2_NUM
 *  	  NewState: TRUE：OPx_NUM_OUTPUT的输出，作为OPx_NUM_PINPUT的正端输入
					FALSE：无作用
 *  返回：无
 * */
void OP_Positive_INPUT_Selsect(uint32_t OPx_NUM_OUTPUT,uint32_t OPx_NUM_PINPUT, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM_OUTPUT));
	CHECK_RESTRICTION(CHECK_OP_OP012_NUM(OPx_NUM_PINPUT));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL1_OP0TOCU_POS + OPx_NUM_OUTPUT*3 + OPx_NUM_PINPUT);
	tmask = 1 << (OP_CTL1_OP0TOCU_POS + OPx_NUM_OUTPUT*3 + OPx_NUM_PINPUT);
	OP_CTL1 = SFR_Config(OP_CTL1, ~tmask, tmpreg);
}
/**
 *  描述：配置OP0/1/2/3正负端短接
 *  输入： OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  NewState: TRUE：短接使能
 *					FALSE：短接未使能
 *  返回：无
 * */
void OP_Positive_Negetive_Short(uint32_t OPx_NUM, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL1_ENOP0INSHORT_POS + OPx_NUM);
	tmask = 1 << (OP_CTL1_ENOP0INSHORT_POS + OPx_NUM);
	OP_CTL1 = SFR_Config(OP_CTL1, ~tmask, tmpreg);
}
/**
 *  描述：配置OP共模参考正端输入
 *  输入：Select:   OP_HALF_AVDD：选择 AVDD 的一半作为共模的输入
 *					OP_HALF_2V：选择内部 2V 的参考电压的一半作为共模的输入
 *  返回：无
 * */
void OP_VCOM_Positive_Select(uint32_t Select)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_VCOM_SEL(Select));

	OP_CTL1 = SFR_Config(OP_CTL1, ~OP_CTL1_VCOMPSEL, Select << OP_CTL1_VCOMPSEL0_POS);
}
/**
 *  描述：配置OP共模buffer输出使能
 *  输入：NewState:   	TRUE：OP 的共模 buffer 输出使能
 *						FALSE：OP 的共模 buffer 输出未使能
 *  返回：无
 * */
void OP_VCOM_Buffer_Output_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_CTL1 = SFR_Config(OP_CTL1, ~OP_CTL1_OPVCOMOUTEN, NewState << OP_CTL1_OPVCOMOUTEN_POS);
}
/**
 *  描述：配置OP共模buffer使能
 *  输入：NewState:   	TRUE：OP 的共模 buffer 使能
 *						FALSE：OP 的共模 buffer 未使能
 *  返回：无
 * */
void OP_VCOM_Buffer_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_CTL1 = SFR_Config(OP_CTL1, ~OP_CTL1_ENOPVCOM, NewState << OP_CTL1_ENOPVCOM_POS);
}
/**
 *  描述：配置CMP3使能/失能
 *  输入：NewState:   	TRUE：CMP3使能
 *						FALSE：CMP3失能
 *  返回：无
 * */
void CMP3_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_CTL1 = SFR_Config(OP_CTL1, ~OP_CTL1_ENCMP3, NewState);
}

/**
 * 	OP初始化配置函数完毕
 * */

/**
 * 	OP校准配置函数
 * */

/**
 *  描述：配置OP0/1/2/3校准 PMOS管使能
 *  输入：NewState:   	TRUE：使能
 *						FALSE：失能
 *  返回：无
 * */
void OP_TRIM_PMOS_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OPTRIMLOWEN, NewState << OP_TRIM_OPTRIMLOWEN_POS);
}
/**
 *  描述：配置OP0/1/2/3校准 NMOS管使能
 *  输入：NewState:   	TRUE：使能
 *						FALSE：失能
 *  返回：无
 * */
void OP_TRIM_NMOS_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OPTRIMHIEN, NewState << OP_TRIM_OPTRIMHIEN_POS);
}
/**
 *  描述：读取OP0/1/2/3校准输出指示位
 *  输入：OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  返回：RetStatus：0表示 OP的负端权重大于正端权重， 需要增加正端权重
 *  				 1表示 OP0 的正端权重大于负端权重， 需要增加负端权重
 * */
RetStatus
OP_TRIM_OUT_Flag(uint32_t OPx_NUM)
{
	uint8_t Value = 0;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));

	switch (OPx_NUM)
	{
	case OP0_NUM:
		Value = ((OP_TRIM0 & OP_TRIM_OP0TRIMOUT) >> OP_TRIM_OP0TRIMOUT_POS);
		break;
	case OP1_NUM:
		Value = ((OP_TRIM1 & OP_TRIM_OP0TRIMOUT) >> OP_TRIM_OP0TRIMOUT_POS);
		break;
	case OP2_NUM:
		Value = ((OP_TRIM2 & OP_TRIM_OP0TRIMOUT) >> OP_TRIM_OP0TRIMOUT_POS);
		break;
	case OP3_NUM:
		Value = ((OP_TRIM3 & OP_TRIM_OP0TRIMOUT) >> OP_TRIM_OP0TRIMOUT_POS);
		break;
	default:break;
	}
	return Value;
}
/**
 *  描述：配置OP0/1/2/3 PMOS管失调校准值
 *  输入：OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  Value： 失调校准值
 *  返回：无
 * */
void OP_TRIM_PMOS_Value_Config(uint32_t OPx_NUM, uint8_t Value)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_TRIM_VALUE(Value));

	tmpreg = Value << OP_TRIM_OP0TRIMP0_POS;
	switch (OPx_NUM)
	{
	case OP0_NUM:
		OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OP0TRIMP, tmpreg);
		break;
	case OP1_NUM:
		OP_TRIM1 = SFR_Config(OP_TRIM1, ~OP_TRIM_OP0TRIMP, tmpreg);
		break;
	case OP2_NUM:
		OP_TRIM2 = SFR_Config(OP_TRIM2, ~OP_TRIM_OP0TRIMP, tmpreg);
		break;
	case OP3_NUM:
		OP_TRIM3 = SFR_Config(OP_TRIM3, ~OP_TRIM_OP0TRIMP, tmpreg);
		break;
	default:break;
	}
}
/**
 *  描述：配置OP0/1/2/3 PMOS管失调校准方向
 *  输入：OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  Direction：  OP_TRIM_DIRECTION_POSITIVE: OPx MOS 管选择正向校准
 *  	  			  OP_TRIM_DIRECTION_NEGETIVE: OPx MOS 管选择负向校准
 *  返回：无
 * */
void OP_TRIM_PMOS_Direction_Select(uint32_t OPx_NUM, uint32_t Direction)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_TRIM_DIRECTION(Direction));

	tmpreg = Direction << OP_TRIM_OP0TRIMPPOL_POS;
	switch (OPx_NUM)
	{
	case OP0_NUM:
		OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OP0TRIMPPOL, tmpreg);
		break;
	case OP1_NUM:
		OP_TRIM1 = SFR_Config(OP_TRIM1, ~OP_TRIM_OP0TRIMPPOL, tmpreg);
		break;
	case OP2_NUM:
		OP_TRIM2 = SFR_Config(OP_TRIM2, ~OP_TRIM_OP0TRIMPPOL, tmpreg);
		break;
	case OP3_NUM:
		OP_TRIM3 = SFR_Config(OP_TRIM3, ~OP_TRIM_OP0TRIMPPOL, tmpreg);
		break;
	default:break;
	}
}
/**
 *  描述：配置OP0/1/2/3 NMOS管失调校准值
 *  输入：OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  Value： 失调校准值
 *  返回：无
 * */
void OP_TRIM_NMOS_Value_Config(uint32_t OPx_NUM, uint8_t Value)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_TRIM_VALUE(Value));

	tmpreg = Value << OP_TRIM_OP0TRIMN0_POS;
	switch (OPx_NUM)
	{
	case OP0_NUM:
		OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP1_NUM:
		OP_TRIM1 = SFR_Config(OP_TRIM1, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP2_NUM:
		OP_TRIM2 = SFR_Config(OP_TRIM2, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP3_NUM:
		OP_TRIM3 = SFR_Config(OP_TRIM3, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	default:break;
	}
}
/**
 *  描述：配置OP0/1/2/3 NMOS管失调校准方向
 *  输入：OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  Direction：  OP_TRIM_DIRECTION_POSITIVE: OPx MOS 管选择正向校准
 *  	  			  OP_TRIM_DIRECTION_NEGETIVE: OPx MOS 管选择负向校准
 *  返回：无
 * */
void OP_TRIM_NMOS_Direction_Select(uint32_t OPx_NUM, uint32_t Direction)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_TRIM_DIRECTION(Direction));

	tmpreg = Direction << OP_TRIM_OP0TRIMNPOL_POS;
	switch (OPx_NUM)
	{
	case OP0_NUM:
		OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP1_NUM:
		OP_TRIM1 = SFR_Config(OP_TRIM1, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP2_NUM:
		OP_TRIM2 = SFR_Config(OP_TRIM2, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP3_NUM:
		OP_TRIM3 = SFR_Config(OP_TRIM3, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	default:break;
	}
}

/**
 * 	OP校准配置函数结束
 * */

