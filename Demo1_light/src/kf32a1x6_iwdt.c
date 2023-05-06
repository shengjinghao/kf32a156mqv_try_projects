/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_iwdt.c                             	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : The file provides functions related to the independent*
 *                  	watchdog (IWDT) , including:                          *
 *          			+ Independent Watchdog (IWDT) control function	      *
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

#include "kf32a1x6_iwdt.h"

/*******************************************************************************
**         		    (IDWT) Moudle private macro definition 		              **
*******************************************************************************/

/* IWDT_FD寄存器喂狗值 */
#define FEED_THE_DOG                    ((uint32_t)0x55AA55AA)

/**
  *   ##### 独立看门狗(IWDT)控制功能函数 #####
  */
/**
  * 描述  设置独立看门狗预分频，对立看门狗工作时钟进行分频。
  * 输入  Prescaler: 独立看门狗工作时钟的预分频值，取值为：
  *                    IWDT_PRESCALER_32: 32分频
  *                    IWDT_PRESCALER_64: 64分频
  *                    IWDT_PRESCALER_128: 128分频
  *                    IWDT_PRESCALER_256: 256分频
  *                    IWDT_PRESCALER_512: 512分频
  *                    IWDT_PRESCALER_1024: 1024分频
  *                    IWDT_PRESCALER_2048: 2048分频
  *                    IWDT_PRESCALER_4096: 4096分频
  *                    IWDT_PRESCALER_8192: 8192分频
  *                    IWDT_PRESCALER_16384: 16384分频
  *                    IWDT_PRESCALER_32768: 32768分频
  *                    IWDT_PRESCALER_65536: 65536分频
  * 返回  无。
  */
void IWDT_Prescaler_Config (uint32_t Prescaler)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_IWDT_PRESCALER(Prescaler));

    /*---------------- 配置IWDT_CTL寄存器IWDTPS位 ----------------*/
    IWDT_CTL = SFR_Config (IWDT_CTL, ~IWDT_CTL_IWDTPS, Prescaler);
}

/**
  * 描述  设置独立看门狗的工作时钟。
  * 输入  Source: 独立看门狗工作时钟，取值为
  * 			IWDT_SCK_INTLF
  * 			IWDT_SCK_EXTLF
  * 返回  无。
  */
void IWDT_SCK_Source_Select(uint32_t Source)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_IWDT_SCK(Source));

	IWDT_CTL = SFR_Config(IWDT_CTL, ~IWDT_CTL_CLKS, Source << IWDT_CTL_CLKS_POS);
}

/**
  * 描述  设置独立看门狗溢出值，溢出时复位。
  * 输入  Overflow: 独立看门狗溢出值，取值为0~0xFFF。
  * 返回  无。
  */
void IWDT_Overflow_Config (uint32_t Overflow)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_IWDTPS_OVERFLOW(Overflow));

    /*---------------- 配置IWDT_CTL寄存器IWDTOVF位 ----------------*/
    tmpreg = Overflow << IWDT_CTL_IWDTOVF0_POS;
    IWDT_CTL = SFR_Config (IWDT_CTL, ~IWDT_CTL_IWDTOVF, tmpreg);
}

/**
  * 描述  设置独立看门狗使能。
  * 输入  NewState: 独立看门狗使能状态，取值为TRUE 或 FALSE。
  * 返回  无。
  */
void IWDT_Enable (FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 设置IWDT_CTL寄存器IWDTEN位 ----------------*/
    if (NewState != FALSE)
    {
        /* 使能独立看门狗定时器 */
        SFR_SET_BIT_ASM(IWDT_CTL, IWDT_CTL_IWDTEN_POS);
    }
    else
    {
        /* 未使能独立看门狗 */
        SFR_CLR_BIT_ASM(IWDT_CTL, IWDT_CTL_IWDTEN_POS);
    }
}

/**
  * 描述  独立看门狗喂狗。
  * 输入  无。
  * 返回  无。
  */
void IWDT_Feed_The_Dog (void)
{
    IWDT_FD = FEED_THE_DOG;
}
/**
  *   ##### 独立看门狗(IWDT)控制功能函数定义结束 #####
  */
