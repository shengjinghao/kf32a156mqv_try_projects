/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_epwm.c                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the enhanced pulse width modulation*
 *						(EPWM) peripherals function              		  	  *
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


#include "kf32a1x6_epwm.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### 初始化及配置函数 #####
  */

/**
  * 描述  EPWM外设复位，使能外设时钟。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回  无。
  */
void EPWM_Reset (EPWM_SFRmap* EPWMx)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    if (EPWMx == EPWM11_SFR)
    {
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM11TRST, TRUE);
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM11TRST, FALSE);
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_EPWM11CLKEN, TRUE);
    }
    else if (EPWMx == EPWM12_SFR)
    {
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM12TRST, TRUE);
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM12TRST, FALSE);
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_EPWM12CLKEN, TRUE);
    }
    else if (EPWMx == EPWM13_SFR)
    {
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM13TRST, TRUE);
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM13TRST, FALSE);
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_EPWM13CLKEN, TRUE);
    }
    else if (EPWMx == EPWM16_SFR)
    {
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM16TRST, TRUE);
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM16TRST, FALSE);
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_EPWM16CLKEN, TRUE);
    }
    else
    {
    	;
    }
}
/**
  * 描述  配置32位的Tx定时器的值。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 Value ： Value <= 0xFFFFFFFF;
  * 返回  无。
  */
void EPWM_TxCNT_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
    CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

    EPWMx->CNT = Value;
}
/**
  * 描述  获取32位的Tx定时器的值。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回  32位的值。
  */
uint32_t EPWM_Get_TxCNT_Value(EPWM_SFRmap* EPWMx)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    return EPWMx->CNT;
}
/**
  * 描述  配置32位Tx定时器的相位寄存器的值。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 Value ： Value <= 0xFFFFFFFF;
  * 返回  无。
  */
void EPWM_TxPHS_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
    CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

    EPWMx->PHS = Value;
}
/**
  * 描述  获取32位Tx定时器的相位寄存器的值。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回  32位的值。
  */
uint32_t EPWM_Get_TxPHS_Value(EPWM_SFRmap* EPWMx)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    return EPWMx->PHS;
}
/**
  * 描述  配置32位Tx定时器的周期寄存器的值。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 Value ： Value <= 0xFFFFFFFF;
  * 返回  无。
  */
void EPWM_TxPPX_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
    CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

    EPWMx->PPX = Value;
}
/**
  * 描述  获取32位Tx定时器的周期寄存器的值。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回  32位的值。
  */
uint32_t EPWM_Get_TxPPX_Value(EPWM_SFRmap* EPWMx)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    return EPWMx->PPX;
}
/**
  * 描述  配置32位Tx定时器预分频器的值。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 Value ： Value <= 0xFFFFFFFF;
  * 返回  无。
  * 注：分频值 = Value + 1;
  */
void EPWM_TxPRSC_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
    CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

    EPWMx->PRSC = Value;
}
/**
  * 描述  获取32位Tx定时器预分频器的值。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回  32位的值。
  */
uint32_t EPWM_Get_TxPRSC_Value(EPWM_SFRmap* EPWMx)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    return EPWMx->PRSC;
}


/**
  * 描述  响应上一级EPWM发送的的LINK请求使能。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : TRUE : 允许寄存器使用LINK功能
  * 	 			FALSE : 禁止寄存器使用LINK功能
  * 返回  无。
  */
void EPWM_Response_UpperLevel_LINK_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_BLINKEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_BLINKEN, tmpreg);
}
/**
  * 描述  向下一级PEWM发送LINK请求使能。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : TRUE : 发出LINK请求
  * 	 			FALSE : 不发出LINK请求
  * 返回  无。
  */
void EPWM_NextLevel_LINK_Ask_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_LINKEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_LINKEN, tmpreg);
}
/**
  * 描述  同步信号触发更新使能。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : TRUE : 允许同步输入信号触发更新
  * 	 			FALSE : 禁止同步输入信号触发更新
  * 返回  无。
  */
void EPWM_SYNC_Single_Trigger_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_UDSYNEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_UDSYNEN, tmpreg);
}
/**
  * 描述  子模块寄存器锁配置。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 Select : 	EPWM_SUBMODULE_HRPWM_LOCK 		: HRPWM子模块寄存器
  * 	 			EPWM_SUBMODULE_ET_LOCK 			: ET子模块寄存器
  * 	 			EPWM_SUBMODULE_PC_LOCK 			: PC子模块寄存器
  * 	 			EPWM_SUBMODULE_DB_LOCK 			: DB子模块寄存器
  * 	 			EPWM_SUBMODULE_CHANNELB_AQ_LOCK : 通道B输出AQ子模块寄存器
  * 	 			EPWM_SUBMODULE_CHANNELA_AQ_LOCK : 通道A输出AQ子模块寄存器
  * 	 NewState : TRUE : 禁止xx子模块寄存器写操作
  * 	 			FALSE : 允许xx子模块寄存器写操作
  * 返回  无。
  */
void EPWM_Submodule_Register_Lock_Config(EPWM_SFRmap* EPWMx,
			uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_SUBMODULE_LOCK(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (EPWM_CTL_AQLOCKA_POS + Select);
	tmask = 1 << (EPWM_CTL_AQLOCKA_POS + Select);
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~tmask, tmpreg);
}
/**
  * 描述  捕捉功能使能。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : TRUE : 使能捕捉功能使用
  * 	 			FALSE : 禁止捕捉功能使用
  * 返回  无。
  */
void EPWM_Cap_Function_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_CAPEN_POS;
	tmask = EPWM_CTL_CAPEN;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~tmask, tmpreg);
}
/**
  * 描述  配置捕捉事件选择。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 Select : 	EPWM_CAP_TRIGGER_EVENT_TZ1 : TZ1触发捕捉事件
  * 	 			EPWM_CAP_TRIGGER_EVENT_TZ2 : TZ2触发捕捉事件
  * 	 			EPWM_CAP_TRIGGER_EVENT_TZ3 : TZ3触发捕捉事件
  * 	 			EPWM_CAP_TRIGGER_EVENT_TZ4 : TZ4触发捕捉事件
  * 返回  无。
  */
void EPWM_Cap_Trigger_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_CAP_TRIGGER_EVENT(Select));

	tmpreg = Select << EPWM_CTL_CAPSEL0_POS;
	tmask = EPWM_CTL_CAPSEL;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~tmask, tmpreg);
}
/**
  * 描述  获取计数达到最大值状态。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回  0 ： 计数值没有达到过最大值0xFFFF_FFFF
  *      1 ： 计数值达到了最大值0xFFFF_FFFF
  */
FlagStatus EPWM_Get_CountValue_MAX_Status(EPWM_SFRmap* EPWMx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return ((EPWMx->CTL & EPWM_CTL_TXMAX) >> EPWM_CTL_TXMAX_POS);
}
/**
  * 描述  清除计数达到最大值状态标志。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回:  清除计数达到最大值状态标志状态
  */
RetStatus EPWM_Clear_CountValue_MAX_Status(EPWM_SFRmap* EPWMx)
{
	uint32_t wait_flag = 0x0000;
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXMAX, EPWM_CTL_TXMAX);
	while((!(EPWMx->CTL & EPWM_CTL_TXMAX))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * 描述  相位方向控制。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 Direction : 	EPWM_SYNC_TRIGGER_DOWM : 同步事件触发后向下计数
  * 	 				EPWM_SYNC_TRIGGER_UP : 同步事件触发后向上计数
  * 返回  无。
  */
void EPWM_Phase_Direction_Config(EPWM_SFRmap* EPWMx, uint32_t Direction)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_SYNC_TRIGGER_DIRECTION(Direction));

	tmpreg = Direction << EPWM_CTL_PHSDIR_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_PHSDIR, tmpreg);
}
/**
  * 描述  软件产生触发同步事件(产生一次同步事件)。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回  无。
  */
void EPWM_Software_SYNC_Event(EPWM_SFRmap* EPWMx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_SWFSYNC, EPWM_CTL_SWFSYNC);
}
/**
  * 描述  同步事件输出选择。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 Select : 	EPWM_SYNC_EVENT_OUT_EPWM_SWF : EPWMxSYNCI以及SWFSYNC
  * 	 			EPWM_SYNC_EVENT_OUT_COUNT0	 : 计数值等于0脉冲
  * 	 			EPWM_SYNC_EVENT_OUT_EPWMRB 	 : 计数值等于EPWMx_RB脉冲
  * 	 			EPWM_SYNC_EVENT_OUT_DISABLE  : 禁止EPWMxSYNCO输出
  * 返回  无。
  */
void EPWM_SYNC_Event_Out_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_SYNC_EVENT_OUT(Select));

	tmpreg = Select << EPWM_CTL_SYNCOSEL0_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_SYNCOSEL, tmpreg);
}
/**
  * 描述  相位寄存器载入使能。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : 	TRUE : 当有外部同步事件输入或者软件强制同步时，将相位寄存器TXPHS载入定时器中
  * 	 				FALSE : 不将相位寄存器TXPHS载入定时器
  * 返回  无。
  */
void EPWM_Phase_Register_Loading_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_PHSEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_PHSEN, tmpreg);
}
/**
  * 描述  获取外部同步事件输入状态。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回  无。
  */
FlagStatus EPWM_Get_External_SYNC_Event_Status(EPWM_SFRmap* EPWMx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return ((EPWMx->CTL & EPWM_CTL_SYNCI) >> EPWM_CTL_SYNCI_POS);
}
/**
  * 描述  清零外部同步事件输入状态位。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回  :FAILURE清除失败；SUCCESS：清除成功。
  */
RetStatus EPWM_Clear_External_SYNC_Event_Status(EPWM_SFRmap* EPWMx)
{
	uint32_t wait_flag = 0x0000;
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_SYNCI, EPWM_CTL_SYNCI);
	while((!(EPWMx->CTL & EPWM_CTL_SYNCI))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * 描述  更新事件生成使能。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : TRUE ： 初始化定时器Tx的计数器并更新周期、占空比、预分频器、输出控制寄存器
  * 	 			FALSE ： 未使能
  * 返回  无。
  */
void EPWM_Updata_Event_Generate_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXUR_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXUR, tmpreg);
}
/**
  * 描述  更新事件控制。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : TRUE ： 产生更新事件，更新以Tx为时基的占空比、周期、输出控制、预分频寄存器
								到缓冲器中，并将定时器复位（只在该位的上升沿有效。对于定时器
  * 	 			FALSE ： 当定时器Tx为0时（向下计数为PP值时）更新以Tx为时基的占空比、
  * 	 						周期、输出控制、预分频寄存器到缓冲器中
  * 返回  无。
  */
void EPWM_Updata_Event_Config(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXEUDEVT_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXEUDEVT, tmpreg);
}
/**
  * 描述  更新使能。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : TRUE ： 允许以Tx为时基占空比、周期、输出控制、预分频寄存器更新
  * 	 			FALSE ： 禁止以Tx为时基占空比、周期、输出控制、预分频寄存器更新
  * 返回  无。
  */
void EPWM_Updata_Event_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXUDEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXUDEN, tmpreg);
}
/**
  * 描述  Tx计数模式选择。
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 Select : 	EPWM_COUNT_DOWM_UF ： 向下计数，下溢时产生中断标志
  * 	 			EPWM_COUNT_UP_OF ： 向上计数，上溢时产生中断标志
  * 	 			EPWM_COUNT_UP_DOWM_OF ： 向上-向下计数，上溢时产生中断标志
  * 	 			EPWM_COUNT_UP_DOWM_UF ： 向上-向下计数，下溢时产生中断标志
  * 	 			EPWM_COUNT_UP_DOWM_OUF ： 向上-向下计数，上溢和下溢时都产生中断标志
  * 返回  无。
  */
void EPWM_Counter_Mode_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_COUNT_MODE(Select));

	tmpreg = Select << EPWM_CTL_TXCMS0_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXCMS, tmpreg);
}
/**
  * 描述  获取Tx计数方向
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 返回 	0 ： 当前计数方向为向下计数
  * 		1 ： 当前计数方向为向上计数
  */
FlagStatus EPWM_Get_Tx_Count_Direction(EPWM_SFRmap* EPWMx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return ((EPWMx->CTL & EPWM_CTL_TTXDIR) >> EPWM_CTL_TTXDIR_POS);
}
/**
  * 描述  Tx工作时钟选择
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 CLK : 	EPWM_CLK_SCLK : 选用SCLK时钟为Tx工作时钟
  * 	 		EPWM_CLK_HFCLK : 选用HFCLK时钟为Tx工作时钟
  * 	 		EPWM_CLK_LFCLK : 选用LFCLK时钟为Tx工作时钟
  * 返回  无。
  */
void EPWM_Work_Clock_Select(EPWM_SFRmap* EPWMx, uint32_t CLK)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_CLK(CLK));

	tmpreg = CLK << EPWM_CTL_TXCLK0_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXCLK, tmpreg);
}
/**
  * 描述  Tx计数模式外部触发脉冲输入同步控制
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : TRUE : 不与外部触发脉冲输入同步
  * 	 			FALSE : 与外部触发脉冲输入同步
  * 返回  无。
  * 注：TXCS=1时该位有效
  */
void EPWM_External_Pulse_Sync_Config(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXSY_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXSY, tmpreg);
}
/**
  * 描述  Tx门控使能
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  * 	 NewState : TRUE : 使能Tx门控，门控信号为TxCK
  * 	 			FALSE : 禁止Tx门控
  * 返回  无。
  */
void EPWM_Gated_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXGATE_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXGATE, tmpreg);
}
/**
  * 描述  Tx定时/计数模式选择
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  *      Mode : 新的定时/计数模式，
  *                EPWM_TIMER_MODE: 定时模式
  *                EPWM_COUNTER_MODE: 计数模式
  * 返回  无。
  */
void EPWM_Work_Mode_Config(EPWM_SFRmap* EPWMx, uint32_t Mode)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_MODE(Mode));

	tmpreg = Mode << EPWM_CTL_TXCS_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXCS, tmpreg);
}
/**
  * 描述  Tx使能位
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  *      NewState : TRUE : 使能Tx
  *      			FALSE : 禁止Tx
  * 返回  无。
  */
void EPWM_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXEN, NewState);
}


/**
  * 描述  配置占空比A/B/C/D寄存器
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  *      Register : EPWM_REGISTER_A : 寄存器A
  *      			EPWM_REGISTER_B ： 寄存器B
  *      			EPWM_REGISTER_C ： 寄存器C
  *      			EPWM_REGISTER_D ： 寄存器D
  *      Value : Value <= 0xFFFFFFFF
  * 返回  无。
  */
void EPWM_Duty_Cycle_RegisterABCD_Config(EPWM_SFRmap* EPWMx, uint32_t Register,uint32_t Value)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->RA = Value;
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->RB = Value;
	}
	else if(Register == EPWM_REGISTER_C)
	{
		EPWMx->RC = Value;
	}
	else if(Register == EPWM_REGISTER_D)
	{
		EPWMx->RD = Value;
	}
}
/**
  * 描述 获取占空比A/B/C/D寄存器的值
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  *      Register : EPWM_REGISTER_A : 寄存器A
  *      			EPWM_REGISTER_B ： 寄存器B
  *      			EPWM_REGISTER_C ： 寄存器C
  *      			EPWM_REGISTER_D ： 寄存器D
  * 返回  32位的值。
  */
uint32_t EPWM_Get_Duty_Cycle_RegisterABCD_Value(EPWM_SFRmap* EPWMx, uint32_t Register)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));

	if(Register == EPWM_REGISTER_A)
	{
		return EPWMx->RA;
	}
	else if(Register == EPWM_REGISTER_B)
	{
		return EPWMx->RB;
	}
	else if(Register == EPWM_REGISTER_C)
	{
		return EPWMx->RC;
	}
	else if(Register == EPWM_REGISTER_D)
	{
		return EPWMx->RD;
	}
}


/**
  * 描述  EPWMxA/EPWMxB单次强制输出使能
  * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
  *      Register : EPWM_REGISTER_A : 寄存器A
  *      			EPWM_REGISTER_B ： 寄存器B
  *      NewState : TRUE : 使能EPWMxA单次强制输出
  *      			FALSE : 禁止EPWMxA单次强制输出
  * 返回  无。
  */
void EPWM_Single_Mandatory_Output_Enable(EPWM_SFRmap* EPWMx,uint32_t Register, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTLA_OTSFA_POS;
	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->CTLA = SFR_Config(EPWMx->CTLA, ~EPWM_CTLA_OTSFA, tmpreg);
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->CTLB = SFR_Config(EPWMx->CTLB, ~EPWM_CTLA_OTSFA, tmpreg);
	}
}
/**
 * 描述  EPWMxA单次强制输出
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Register : 	EPWM_REGISTER_A : 寄存器A
 *      			EPWM_REGISTER_B ： 寄存器B
 *      Select : 	EPWM_OUT_NONE : 无动作（保持电平不变）
 *      			EPWM_OUT_LOW : 低电平
 *      			EPWM_OUT_HIGH : 高电平
 *      			EPWM_OUT_TOGGLE : 翻转
 * 返回  无。
 */
void EPWM_Single_Mandatory_Output_Config(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_EPWM_MANDATORY_OUT(Select));

	tmpreg = Select << EPWM_CTLA_ACTSFA0_POS;
	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->CTLA = SFR_Config(EPWMx->CTLA, ~EPWM_CTLA_ACTSFA, tmpreg);
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->CTLB = SFR_Config(EPWMx->CTLB, ~EPWM_CTLA_ACTSFA, tmpreg);
	}
}
/**
 * 描述  EPWMxA连续强制输出
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Register : 	EPWM_REGISTER_A : 寄存器A
 *      			EPWM_REGISTER_B ： 寄存器B
 *      Select : 	EPWM_OUT_NONE : 无动作（保持电平不变）
 *      			EPWM_OUT_LOW : 低电平
 *      			EPWM_OUT_HIGH : 高电平
 *      			EPWM_OUT_PROHIBIT : 禁止
 * 返回  无。
 */
void EPWM_Continuous_Mandatory_Output_Config(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_EPWM_MANDATORY_OUT(Select));

	tmpreg = Select << EPWM_CTLA_CSFA0_POS;
	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->CTLA = SFR_Config(EPWMx->CTLA, ~EPWM_CTLA_CSFA, tmpreg);
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->CTLB = SFR_Config(EPWMx->CTLB, ~EPWM_CTLA_CSFA, tmpreg);
	}
}
/**
 * 描述  当Tx计数值等于EPWMx_RB寄存器且计数方向向下时，EPWMxA输出
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Register : 	EPWM_REGISTER_A : 寄存器A
 *      			EPWM_REGISTER_B ： 寄存器B
 *     	Event : 	EPWM_CERB_DD_EPWMAB_OUT : 当Tx计数值等于EPWMx_RB寄存器且计数方向向下时，EPWMxA/B输出
 *     				EPWM_CERB_DU_EPWMAB_OUT : 当Tx计数值等于EPWMx_RB寄存器且计数方向向上时，EPWMxA/B输出
 *     				EPWM_CERA_DD_EPWMAB_OUT : 当Tx计数值等于EPWMx_RA寄存器且计数方向向下时，EPWMxA/B输出
 *     				EPWM_CERA_DU_EPWMAB_OUT : 当Tx计数值等于EPWMx_RA寄存器且计数方向向上时，EPWMxA/B输出
 *     				EPWM_CEPPX_EPWMAB_OUT : 当Tx计数值等于周期寄存器PPX时，EPWMxA/B输出
 *     				EPWM_CE0_EPWMAB_OUT : 当Tx计数值等于零时，EPWMxA/B输出
 *      Select : 	EPWM_OUT_NONE : 不触发该事件
 *      			EPWM_OUT_LOW : 低电平
 *      			EPWM_OUT_HIGH : 高电平
 *      			EPWM_OUT_TOGGLE : 翻转
 * 返回  无。
 */
void EPWM_EPWMxAB_OUTPUT_Select(EPWM_SFRmap* EPWMx,uint32_t Register, uint32_t Event, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_EPWM_TXCOUNT_EQUAL_XX_EPWMAB_OUT(Event));
	CHECK_RESTRICTION(CHECK_EPWM_MANDATORY_OUT(Select));

	tmpreg = Select << (Event*2);
	tmask = 0x03 << (Event*2);
	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->CTLA = SFR_Config(EPWMx->CTLA, ~tmask, tmpreg);
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->CTLB = SFR_Config(EPWMx->CTLB, ~tmask, tmpreg);
	}
}


/**
 * 描述  死区输入选择
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Select : 	EPWM_EPWMA_UP_EPWMA_DOWM : 	EPWMxA（来自波形发生模块）作为上升/下降沿死区模块的输入
 *      			EPWM_EPWMB_UP_EPWMA_DOWM : 	EPWMxB（来自波形发生模块）作为上升沿死区模块的输入
												EPWMxA（来自波形发生模块）作为下降沿死区模块的输入
 *      			EPWM_EPWMA_UP_EPWMB_DOWM : 	EPWMxA（来自波形发生模块）作为上升沿死区模块的输入
				 	 	 	 	 	 	 	 	EPWMxB（来自波形发生模块）作为下降沿死区模块的输入
 *      			EPWM_EPWMB_UP_EPWMB_DOWM : 	（来自波形发生模块）作为上升/下降沿死区模块的输入
 * 返回  无。
 */
void EPWM_Dead_Zone_Input_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DEAD_ZONE(Select));

	tmpreg = Select << EPWM_DBCTL_INMODE0_POS;
	EPWMx->DBCTL = SFR_Config(EPWMx->DBCTL, ~EPWM_DBCTL_INMODE, tmpreg);
}
/**
 * 描述  死区输出极性选择
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Select : 	EPWM_EPWMA_NTOGGLE_EPWMB_NTOGGLE : 	EPWMxA和EPWMxB（来自上升/下降沿死区模块）都不翻转
 *      			EPWM_EPWMA_TOGGLE_EPWMB_NTOGGLE : 	EPWMxA翻转，EPWMxB不翻转（来自上升/下降沿死区模块）
 *      			EPWM_EPWMA_NTOGGLE_EPWMB_TOGGLE : 	EPWMxB翻转，EPWMxA不翻转（来自上升/下降沿死区模块）
 *      			EPWM_EPWMA_TOGGLE_EPWMB_TOGGLE : 	EPWMxA和EPWMxB（来自上升/下降沿死区模块）都翻转
 * 返回  无。
 */
void EPWM_Dead_Zone_Output_Polarity_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DEAD_ZONE_OUT_POLARITY(Select));

	tmpreg = Select << EPWM_DBCTL_POLSEL0_POS;
	EPWMx->DBCTL = SFR_Config(EPWMx->DBCTL, ~EPWM_DBCTL_POLSEL, tmpreg);
}
/**
 * 描述  死区输出选择
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Select : 	EPWM_UP_BYPASS_DOWN_BYPASS : 	上升/下降沿死区模块都被旁路
 *      			EPWM_UP_BYPASS_DOWN_ENABLE : 	上升沿死区模块被旁路，下降沿死区模块使能
 *      			EPWM_UP_ENABLE_DOWN_BYPASS : 	上升沿死区模块被使能，下降沿死区模块旁路
 *      			EPWM_UP_ENABLE_DOWN_ENABLE : 	上升/下降沿死区模块都使能
 * 返回  无。
 */
void EPWM_Dead_Zone_Output_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DEAD_ZONE_OUT(Select));

	tmpreg = Select << EPWM_DBCTL_OUTMODE0_POS;
	EPWMx->DBCTL = SFR_Config(EPWMx->DBCTL, ~EPWM_DBCTL_OUTMODE, tmpreg);
}
/**
 * 描述  死区时间设置
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Select : 	EPWM_UP_EDGE_DEAD_ZONE : 上升沿死区时间设置
 *      			EPWM_DOWM_EDGE_DEAD_ZONE : 下降沿死区时间设置
 *      Value : 死区时间 Value <= 0xFFFF
 * 返回  无。
 */
void EPWM_Dead_Zone_Time_Config(EPWM_SFRmap* EPWMx, uint32_t Select, uint32_t Value)
{

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_UP_DOWN_EDGE_DEAD_ZONE(Select));
	CHECK_RESTRICTION(CHECK_EPWM_16BIT_LIMIT(Value));

	if(Select == EPWM_UP_EDGE_DEAD_ZONE)
	{
		EPWMx->DBT = SFR_Config(EPWMx->DBT, ~EPWM_DBT_RDBT, Value << EPWM_DBT_RDBT0_POS);
	}
	else if(Select == EPWM_DOWM_EDGE_DEAD_ZONE)
	{
		EPWMx->DBT = SFR_Config(EPWMx->DBT, ~EPWM_DBT_FDBT, Value);
	}
}


/**
 * 描述  PCLK频率设置
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Select : 	EPWM_PCLK_DIV1 : 1分频
 *      			EPWM_PCLK_DIV2 : 2分频
 *      			EPWM_PCLK_DIV3 : 3分频
 *      			EPWM_PCLK_DIV4 : 4分频
 *      			EPWM_PCLK_DIV5 : 5分频
 *      			EPWM_PCLK_DIV6 : 6分频
 *      			EPWM_PCLK_DIV7 : 7分频
 *      			EPWM_PCLK_DIV8 : 8分频
 * 返回  无。
 */
void EPWM_PCLK_Frequency_Config(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_PCLK_DIV(Select));

	tmpreg = Select << EPWM_PCCTL_CHPFREQ0_POS;
	EPWMx->PCCTL = SFR_Config(EPWMx->PCCTL, ~EPWM_PCCTL_CHPFREQ, tmpreg);
}
/**
 * 描述  PCLK占空比设置
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Select : 	EPWM_PCLK_DUTY_CYCLE78 : 7/8占空比
 *      			EPWM_PCLK_DUTY_CYCLE68 : 6/8占空比
 *      			EPWM_PCLK_DUTY_CYCLE58 : 5/8占空比
 *      			EPWM_PCLK_DUTY_CYCLE48 : 4/8占空比
 *      			EPWM_PCLK_DUTY_CYCLE38 : 3/8占空比
 *      			EPWM_PCLK_DUTY_CYCLE28 : 2/8占空比
 *      			EPWM_PCLK_DUTY_CYCLE18 : 1/8占空比
 * 返回  无。
 */
void EPWM_PCLK_Duty_Cycle_Config(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_PCLK_DUTY_CYCLE(Select));

	tmpreg = Select << EPWM_PCCTL_CHPDUTY0_POS;
	EPWMx->PCCTL = SFR_Config(EPWMx->PCCTL, ~EPWM_PCCTL_CHPDUTY, tmpreg);
}
/**
 * 描述  斩波第一个脉冲宽度选择
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Select : 	EPWM_CHOPPING_PULSE_WIDTH1 : 1个斩波时钟周期（斩波时钟等于1/8工作时钟）
 *      			EPWM_CHOPPING_PULSE_WIDTH2 : 2个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH3 : 3个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH4 : 4个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH5 : 5个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH6 : 6个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH7 : 7个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH8 : 8个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH9 : 9个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH10 : 10个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH11 : 11个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH12 : 12个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH13 : 13个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH14 : 14个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH15 : 15个斩波时钟周期
 *      			EPWM_CHOPPING_PULSE_WIDTH16 : 16个斩波时钟周期
 * 返回  无。
 */
void EPWM_Chopping_Pulse_Width_Config(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_CHOPPING_PULSE_WIDTH(Select));

	tmpreg = Select << EPWM_PCCTL_OSHTWTH0_POS;
	EPWMx->PCCTL = SFR_Config(EPWMx->PCCTL, ~EPWM_PCCTL_OSHTWTH, tmpreg);
}
/**
 * 描述  斩波模块使能
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      NewState : 	TRUE : 使能斩波
 *      			FALSE : 禁止斩波
 * 返回  无。
 */
void EPWM_Chopping_Pulse_Mode_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	EPWMx->PCCTL = SFR_Config(EPWMx->PCCTL, ~EPWM_PCCTL_CHPEN, NewState);
}


/**
 * 描述  EPWMx自动重启使能
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      NewState : 	EPWM_PXASE_SOFTWARE_CLEAR_RESET : 自动关闭时，PXASE由软件清零，以重启EPWM
 *      			EPWM_PXASE_AUTO_CLEAR_RESET : 自动关闭时，当关闭事件消失，PXASE位将自动清零，EPWM自动重启
 * 返回  无。
 */
void EPWM_Auto_Reset_Enable(EPWM_SFRmap* EPWMx, uint32_t NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_PXASE_CLEAR_RESET(NewState));

	tmpreg = NewState << EPWM_PXASCTL_PXRSEN_POS;
	EPWMx->PXASCTL = SFR_Config(EPWMx->PXASCTL, ~EPWM_PXASCTL_PXRSEN, tmpreg);
}
/**
 * 描述  引脚EPWMxA关闭状态控制
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Status ： 	EPWM_DRIVER_PIN_EPWMAB_LOW : 驱动引脚EPWMxA/B为低电平
 *      			EPWM_DRIVER_PIN_EPWMAB_HIGH : 驱动引脚EPWMxA/B为高电平
 *      			EPWM_DRIVER_PIN_EPWMAB_3STATUS   :	驱动引脚EPWMxA/B为三态
 * 返回  无。
 */
void EPWM_Pin_EPWMA_ShouDown_Status_Config(EPWM_SFRmap* EPWMx, uint32_t Status)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DRIVER_PIN_EPWMAB(Status));

	tmpreg = Status << EPWM_PXASCTL_PXSSA0_POS;
	EPWMx->PXASCTL = SFR_Config(EPWMx->PXASCTL, ~EPWM_PXASCTL_PXSSA, tmpreg);
}
/**
 * 描述  引脚EPWMxB关闭状态控制
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 *      Status ： 	EPWM_DRIVER_PIN_EPWMAB_LOW : 驱动引脚EPWMxA/B为低电平
 *      			EPWM_DRIVER_PIN_EPWMAB_HIGH : 驱动引脚EPWMxA/B为高电平
 *      			EPWM_DRIVER_PIN_EPWMAB_3STATUS   :	驱动引脚EPWMxA/B为三态
 * 返回  无。
 */
void EPWM_Pin_EPWMB_ShouDown_Status_Config(EPWM_SFRmap* EPWMx, uint32_t Status)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DRIVER_PIN_EPWMAB(Status));

	tmpreg = Status << EPWM_PXASCTL_PXSSB0_POS;
	EPWMx->PXASCTL = SFR_Config(EPWMx->PXASCTL, ~EPWM_PXASCTL_PXSSB, tmpreg);
}
/**
 * 描述  获取EPWMx自动关闭事件状态
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 返回  0 ：  EPWMx正常工作
 * 		1 ：  发生了关闭事件；EPWMx为关闭状态。
 */
FlagStatus EPWM_Get_Auto_ShowDown_Event_Status(EPWM_SFRmap* EPWMx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return ((EPWMx->PXASCTL & EPWM_PXASCTL_PXASE) >> EPWM_PXASCTL_PXASE_POS);
}
/**
 * 描述  清除EPWMx自动关闭事件状态
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 返回 无
 */
void EPWM_Claer_Auto_ShowDown_Event_Status(EPWM_SFRmap* EPWMx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	EPWMx->PXASCTL &= ~EPWM_PXASCTL_PXASE;
}
/**
 * 描述  EPWMx自动关闭源选择
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Select :  EPWM_AUTO_SHOWDOWN_SOURCE_NO : 禁止自动关断
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_TZ1_HIGH :  TZ1引脚输入高电平
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_TZ2_HIGH :  TZ2引脚输入高电平
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_TZ3_HIGH :  TZ3引脚输入高电平
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_TZ4_HIGH :  TZ4引脚输入高电平
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_CLKIF :  振荡器模块错误中断
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_QEIIF :  QEI错误中断
 * 返回  无。
 */
void EPWM_Auto_ShowDown_Source_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_AUTO_SHOWDOWN_SOURCE(Select));

	tmpreg = Select << EPWM_PXASCTL_PXASS0_POS;
	EPWMx->PXASCTL = SFR_Config(EPWMx->PXASCTL, ~EPWM_PXASCTL_PXASS, tmpreg);
}


/**
 * 描述  触发AD事件触发模式选择
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : 触发AD事件0
 * 				  EPWM_TRIGGER_AD_EVENT1 : 触发AD事件1
 * 		Select :  EPWM_TRIGGER_AD_UP : 		选择在向上计数方式下触发AD
 * 				  EPWM_TRIGGER_AD_DOWM :  	选择在向下计数方式下触发AD
 * 				  EPWM_TRIGGER_AD_UD :  	选择在向上向下计数方式下触发AD
 * 返回  无。
 */
void EPWM_Trigger_AD_Event_Mode_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_UD(Select));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = Select << EPWM_ETCTL_BTSEL0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_BTSEL, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = Select << EPWM_ETCTL_ATSEL0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_ATSEL, tmpreg);
	}
}
/**
 * 描述  触发AD事件触发信号计数
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : 触发AD事件0
 * 				  EPWM_TRIGGER_AD_EVENT1 : 触发AD事件1
 * 返回  触发AD次数。
 */
uint8_t
EPWM_Get_Trigger_AD_Event_Single(EPWM_SFRmap* EPWMx, uint32_t Event)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		return ((EPWMx->ETCTL & EPWM_ETCTL_BT) >> EPWM_ETCTL_BT0_POS);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		return ((EPWMx->ETCTL & EPWM_ETCTL_AT) >> EPWM_ETCTL_AT0_POS);
	}
}
/**
 * 描述  触发AD事件周期选择
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : 触发AD事件0
 * 				  EPWM_TRIGGER_AD_EVENT1 : 触发AD事件1
 * 		Select :  EPWM_1_TRIGGER_EVENT_TRIGGER_AD : 每一次触发信号都能产生触发AD事件（其中包括软件触发）
 * 				  EPWM_2_TRIGGER_EVENT_TRIGGER_AD : 每二次触发信号产生触发AD事件
 * 				  EPWM_3_TRIGGER_EVENT_TRIGGER_AD : 每三次触发信号产生触发AD事件
 * 				  EPWM_4_TRIGGER_EVENT_TRIGGER_AD : 每四次触发信号产生触发AD事件
 * 返回  无。
 */
void EPWM_Trigger_Event_Cycle_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_EVENT_TRIGGER_AD(Select));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = Select << EPWM_ETCTL_BPP0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_BPP, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = Select << EPWM_ETCTL_APP0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_APP, tmpreg);
	}
}
/**
 * 描述  软件触发AD事件
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : 触发AD事件0
 * 				  EPWM_TRIGGER_AD_EVENT1 : 触发AD事件1
 * 		NewState :  TRUE : 产生一次触发AD事件脉冲
 * 					FALSE : 不使用软件产生触发AD事件
 * 返回  无。
 */
void EPWM_Software_Trigger_AD_Event_Enable(EPWM_SFRmap* EPWMx, uint32_t Event, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = NewState << EPWM_ETCTL_BPP0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_FRCB, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = NewState << EPWM_ETCTL_FRCB_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_FRCA, tmpreg);
	}
}
/**
 * 描述  触发AD事件选择
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : 触发AD事件0
 * 				  EPWM_TRIGGER_AD_EVENT1 : 触发AD事件1
 * 		Select :  EPWM_TIMER_EQUAL_0PULSE : 定时器值等于零脉冲
 * 				  EPWM_TIMER_EQUAL_PPPULSE : 定时器值等于PP脉冲
 * 				  EPWM_TIMER_EQUAL_DUTYA : 定时器值等于占空比A寄存器脉冲
 * 				  EPWM_TIMER_EQUAL_DUTYB : 定时器值等于占空比B寄存器脉冲
 * 返回  无。
 */
void EPWM_Trigger_AD_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CEHCK_EPWM_TRIGGER_AD_EVENT(Select));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = Select << EPWM_ETCTL_SELB0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_SELB, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = Select << EPWM_ETCTL_SELA0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_SELA, tmpreg);
	}
}
/**
 * 描述  触发AD事件使能
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : 触发AD事件0
 * 				  EPWM_TRIGGER_AD_EVENT1 : 触发AD事件1
 * 		NewState :  TRUE : 使能触发AD事件
 * 					FALSE : 禁止触发AD事件
 * 返回  无。
 */
void EPWM_Trigger_AD_Event_Enable(EPWM_SFRmap* EPWMx, uint32_t Event, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = NewState << EPWM_ETCTL_TOADENB_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_TOADENB, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = NewState << EPWM_ETCTL_TOADENA_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_TOADENA, tmpreg);
	}
}



/**
 * 描述  中断使能
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx计数值等于EPWMx_RD触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx计数值等于EPWMx_RC触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx计数值等于EPWMx_RA触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx计数值等于EPWMx_RB触发中断
 * 				   EPWM_COUNT_OVERFLOW : Tx计数溢出中断
 * 				   EPWM_UPDATA_EVENT : Tx更新事件中断
 * 				   EPWM_SHOTDOWN_EVENT : Tx关断事件中断
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx触发AD事件1中断
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx触发AD事件0中断
 * 		NewState :  TRUE : 使能该事件触发中断
 * 					FALSE : 禁止该事件触发中断
 * 返回  无。
 */
void EPWM_INT_Enable(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << Select;
	tmask = 1 << Select;
	EPWMx->IE = SFR_Config(EPWMx->IE, ~tmask, tmpreg);
}
/**
 * 描述  获取中断标志
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx计数值等于EPWMx_RD触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx计数值等于EPWMx_RC触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx计数值等于EPWMx_RA触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx计数值等于EPWMx_RB触发中断
 * 				   EPWM_COUNT_OVERFLOW : Tx计数溢出中断
 * 				   EPWM_UPDATA_EVENT : Tx更新事件中断
 * 				   EPWM_SHOTDOWN_EVENT : Tx关断事件中断
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx触发AD事件1中断
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx触发AD事件0中断
 * 返回  0 ： 未发生该事件触发中断。
 *      1 ： 发生该事件触发中断
 */
FlagStatus EPWM_Get_INT_Flag(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));

	tmask = 1 << Select;
	return ((EPWMx->IF & tmask) >> Select);
}
/**
 * 描述  清除中断标志
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx计数值等于EPWMx_RD触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx计数值等于EPWMx_RC触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx计数值等于EPWMx_RA触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx计数值等于EPWMx_RB触发中断
 * 				   EPWM_COUNT_OVERFLOW : Tx计数溢出中断
 * 				   EPWM_UPDATA_EVENT : Tx更新事件中断
 * 				   EPWM_SHOTDOWN_EVENT : Tx关断事件中断
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx触发AD事件1中断
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx触发AD事件0中断
 * 返回  中断标志清除状态，FAILURE清除失败；SUCCESS：清除成功。
 */
RetStatus EPWM_Clear_INT_Flag(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmask;
	uint32_t wait_flag = 0x0000;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));

	tmask = 1 << Select;
	EPWMx->IC = SFR_Config(EPWMx->IC, ~tmask, tmask);
	while((EPWMx->IF & tmask)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	EPWMx->IC = SFR_Config(EPWMx->IC, ~tmask, 0);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
 * 描述  触发DMA
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx计数值等于EPWMx_RD触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx计数值等于EPWMx_RC触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx计数值等于EPWMx_RA触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx计数值等于EPWMx_RB触发中断
 * 				   EPWM_COUNT_OVERFLOW : Tx计数溢出中断
 * 				   EPWM_UPDATA_EVENT : Tx更新事件中断
 * 				   EPWM_SHOTDOWN_EVENT : Tx关断事件中断
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx触发AD事件1中断
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx触发AD事件0中断
 * 		NewState :  TRUE : 使能该事件触发DMA
 * 					FALSE : 禁止该事件触发DMA
 * 返回  无。
 */
void EPWM_Trigger_DMA_Enable(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << Select;
	tmask = 1 << Select;
	EPWMx->DE = SFR_Config(EPWMx->DE, ~tmask, tmpreg);
}
/**
 * 描述  获取触发DMA标志
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx计数值等于EPWMx_RD触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx计数值等于EPWMx_RC触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx计数值等于EPWMx_RA触发中断
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx计数值等于EPWMx_RB触发中断
 * 				   EPWM_COUNT_OVERFLOW : Tx计数溢出中断
 * 				   EPWM_UPDATA_EVENT : Tx更新事件中断
 * 				   EPWM_SHOTDOWN_EVENT : Tx关断事件中断
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx触发AD事件1中断
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx触发AD事件0中断
 * 返回  0 ： 未发生该事件触发DMA
 *      1 ： 发生该事件触发DMA
 */
FlagStatus EPWM_Get_Trigger_DMA_Flag(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));

	tmask = 1 << Select;
	return ((EPWMx->DF & tmask) >> Select);
}
/**
 * 描述  HRPWM输出B端控制
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Select :   EPWM_EPWMB_NORMAL_OUTPUT : EPWMxB端口正常输出
 * 				   EPWM_EPWMB_REVERSE_OUTPUT_EPWMA : EPWMxB端口反向输出EPWMxA
 * 返回  无
 */
void EPWM_HRPWM_OUTPUTB_CONTRAL_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_EPWMB_OUTPUT(Select));

	tmpreg = Select << EPWM_HRPWMCTL_HRPOUTB_POS;
	EPWMx->HRPWMCTL = SFR_Config(EPWMx->HRPWMCTL, ~EPWM_HRPWMCTL_HRPOUTB, tmpreg);
}
/**
 * 描述  高精度PWM功能使能
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		NewState :   TRUE : 使能HRPWM功能
 * 				     FALSE : 禁止HRPWM功能
 * 返回  无
 */
void EPWM_HRPWM_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	EPWMx->HRPWMCTL = SFR_Config(EPWMx->HRPWMCTL, ~EPWM_HRPWMCTL_HRPEN, NewState);
}
/**
 * 描述  8位高精度PWM占空比
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Value : Value <= 0xFF
 * 返回  无
 */
void EPWM_8Bit_HRPWM_Duty_Cycle(EPWM_SFRmap* EPWMx, uint8_t Value)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_8BIT_LIMIT(Value));

	EPWMx->HRCMP = Value;
}
/**
 * 描述  获取捕捉计数器的当前计数值
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 返回  32位捕捉计数器的当前计数值
 */
uint32_t EPWM_Get_Cap_Register_Current_Value(EPWM_SFRmap* EPWMx)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return EPWMx->CAP;
}
/**
 * 描述  EPWMx_UDCTL更新事件
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Mode : 	EPWM_UDCTL_PPUD : Tx_PPX周期寄存器更新
 * 				EPWM_UDCTL_PRUD : Tx_PRSC寄存器更新
 * 				EPWM_UDCTL_CMAUD : EPWMx_RA寄存器更新
 * 				EPWM_UDCTL_CMBUD : EPWMx_RB寄存器更新
 * 				EPWM_UDCTL_CMCUD : EPWMx_RC寄存器更新
 * 				EPWM_UDCTL_CMDUD : EPWMx_RD寄存器更新
 * 				EPWM_UDCTL_EAUD : EPWMx_CTLA寄存器更新
 * 				EPWM_UDCTL_EBUD : EPWMx_CTLB寄存器更新
 * 				EPWM_UDCTL_HRPUD :  EPWMx_HRCMP寄存器更新
 * 		NewState : 	TRUE : 使能
 * 					FALSE : 禁止
 * 返回  无
 */
void EPWM_UDCTL_Updata_Enable(EPWM_SFRmap* EPWMx, uint32_t Mode, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_UDCTL_UD(Mode));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (Mode*3);
	tmask = 1 << (Mode*3);
	EPWMx->UDCTL = SFR_Config(EPWMx->UDCTL, ~tmask, tmpreg);
}
/**
 * 描述  EPWMx_UDCTL更新事件选择
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		Mode : 	EPWM_UDCTL_PPUD : Tx_PPX周期寄存器更新
 * 				EPWM_UDCTL_PRUD : Tx_PRSC寄存器更新
 * 				EPWM_UDCTL_CMAUD : EPWMx_RA寄存器更新
 * 				EPWM_UDCTL_CMBUD : EPWMx_RB寄存器更新
 * 				EPWM_UDCTL_CMCUD : EPWMx_RC寄存器更新
 * 				EPWM_UDCTL_CMDUD : EPWMx_RD寄存器更新
 * 				EPWM_UDCTL_EAUD : EPWMx_CTLA寄存器更新
 * 				EPWM_UDCTL_EBUD : EPWMx_CTLB寄存器更新
 * 				EPWM_UDCTL_HRPUD :  EPWMx_HRCMP寄存器更新
 * 		Select : 	EPWM_COUNT_VALUE_EQUAL_0 : 计数器计数值等于0时更新
 * 					EPWM_COUNT_VALUE_EQUAL_TxPPX : 计数器计数值等于Tx_PPX值时更新
 * 					EPWM_COUNT_VALUE_EQUAL_0_TxPPX : 计数器计数值等于0或者等于Tx_PPX值时更新
 * 					EPWM_INPUT_SYCN_SINGLE : 输入同步信号时更新
 * 返回  无
 */
void EPWM_UDCTL_Register_Updata_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Mode, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_UDCTL_UD(Mode));
	CHECK_RESTRICTION(CEHCK_EPWM_TXPPX_CYCLE_UPDATA_EVENT(Select));

	tmpreg = Select << (EPWM_UDCTL_PPUDSEL0_POS + Mode*3);
	tmask = 0x03 << (EPWM_UDCTL_PPUDSEL0_POS + Mode*3);
	EPWMx->UDCTL = SFR_Config(EPWMx->UDCTL, ~tmask, tmpreg);
}
/**
 * 描述  全局加载使能
 * 输入  EPWMx: 指向EPWM内存结构的指针，取值为EPWM11_SFR、EPWM12_SFR、EPWM13_SFR、EPWM16_SFR。
 * 		NewState : 	TRUE :	不选择全局加载
 * 					FALSE : 选择全局加载
 * 返回  无
 */
void EPWM_Global_Loading_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_UDCTL_GBUDEN_POS;
	EPWMx->UDCTL = SFR_Config(EPWMx->UDCTL, ~EPWM_UDCTL_GBUDEN, tmpreg);
}




