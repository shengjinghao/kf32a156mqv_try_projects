/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_pclk.c                              	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the peripheral clock enable module *
 *                      (PCLK) peripheral functions, including:               *
 *     					+ Peripheral clock enable module (PCLK) function 	  *
 *     					  configuration function							  *
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

#include "kf32a1x6_pclk.h"


/**
  *   ##### 外设时钟使能模块(PCLK)功能配置函数 #####
  **/

/**
  * 描述  配置PCLK_CTL0控制的外设时钟使能。
  * 输入  PCLK_CTL0_bit: 指定外设时钟使能位的掩码，取值为：
  *                        PCLK_CTL0_GPIOACLKEN: GPIOA
  *                        PCLK_CTL0_GPIOBCLKEN: GPIOB
  *                        PCLK_CTL0_GPIOCCLKEN: GPIOC
  *                        PCLK_CTL0_GPIODCLKEN: GPIOD
  *                        PCLK_CTL0_GPIOECLKEN: GPIOE
  *                        PCLK_CTL0_GPIOFCLKEN: GPIOF
  *                        PCLK_CTL0_GPIOGCLKEN: GPIOG
  *                        PCLK_CTL0_GPIOHCLKEN: GPIOH
  * NewState: 外设时钟使能状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  **/
void PCLK_CTL0_Peripheral_Clock_Enable (uint32_t PCLK_CTL0_bit,FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_PCLK_CTL0_PERIPH(PCLK_CTL0_bit));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        PCLK_CTL0 |= PCLK_CTL0_bit;
    }
    else
    {
        PCLK_CTL0 &= ~PCLK_CTL0_bit;
    }
}

/**
  * 描述  配置PCLK_CTL1控制的外设时钟使能。
  * 输入  PCLK_CTL1_bit: 指定外设时钟使能位的掩码，取值为：
  *                        PCLK_CTL1_QEI1CLKEN：QEI1
  *                        PCLK_CTL1_T1CLKEN：T1
  *                        PCLK_CTL1_T2CLKEN：T2
  *                        PCLK_CTL1_T3CLKEN：T3
  *                        PCLK_CTL1_T4CLKEN：T4
  *                        PCLK_CTL1_T5T6CLKEN：T5T6
  *                        PCLK_CTL1_QEI0CLKEN：QEI0
  *                        PCLK_CTL1_ADC0CLKEN：ADC0
  *                        PCLK_CTL1_ADC1CLKEN：ADC1
  *                        PCLK_CTL1_ADC2CLKEN：ADC2
  *                        PCLK_CTL1_DAC0CLKEN：DAC0
  *                        PCLK_CTL1_DAC1CLKEN：DAC1
  *                        PCLK_CTL1_CMPCLKEN：CMP
  *                        PCLK_CTL1_T0CLKEN：T0
  *                        PCLK_CTL1_USART0CLKEN：USART0
  *                        PCLK_CTL1_USART1CLKEN：USART1
  *                        PCLK_CTL1_USART2CLKEN：USART2
  *                        PCLK_CTL1_USART4CLKEN：USART4
  *                        PCLK_CTL1_SPI0CLKEN：SPI0
  *                        PCLK_CTL1_SPI1CLKEN：SPI1
  *                        PCLK_CTL1_I2C0CLKEN：I2C0
  *                        PCLK_CTL1_I2C1CLKEN：I2C1
  *                        PCLK_CTL1_I2C2CLKEN：I2C2
  * NewState: 外设时钟使能状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  **/
void PCLK_CTL1_Peripheral_Clock_Enable (uint32_t PCLK_CTL1_bit,FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_PCLK_CTL1_PERIPH(PCLK_CTL1_bit));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        PCLK_CTL1 |= PCLK_CTL1_bit;
    }
    else
    {
        PCLK_CTL1 &= ~PCLK_CTL1_bit;
    }
}

/**
  * 描述  配置PCLK_CTL2控制的外设时钟使能。
  * 输入  PCLK_CTL2_bit: 指定外设时钟使能位的掩码，取值为：
  *                        PCLK_CTL2_I2C4CLKEN：I2C4
  *                        PCLK_CTL2_I2C5CLKEN：I2C5
  *                        PCLK_CTL2_WWDTCLKEN：WWDT
  *                        PCLK_CTL2_EPWM11CLKEN：EPWM11
  *                        PCLK_CTL2_EPWM12CLKEN：EPWM12
  *                        PCLK_CTL2_EPWM13CLKEN：EPWM13
  *                        PCLK_CTL2_EPWM16CLKEN：PWM16
  *                        PCLK_CTL2_DMA0CLKEN：DMA0
  *                        PCLK_CTL2_DMA1CLKEN：DMA1
  *                        PCLK_CTL2_T14CLKEN：T14
  *                        PCLK_CTL2_T18CLKEN：T18
  *                        PCLK_CTL2_T19CLKEN：T19
  *                        PCLK_CTL2_T21CLKEN：T21
  *                        PCLK_CTL2_DAC2CLKEN：DAC2
  *                        PCLK_CTL2_DAC3CLKEN：DAC3
  *                        PCLK_CTL2_USART5CLKEN：USART5
  *                        PCLK_CTL2_USART7CLKEN：USART7
  * NewState: 外设时钟使能状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  **/
void PCLK_CTL2_Peripheral_Clock_Enable (uint32_t PCLK_CTL2_bit,FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_PCLK_CTL2_PERIPH(PCLK_CTL2_bit));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	if(NewState != FALSE)
	{
		PCLK_CTL2 |= PCLK_CTL2_bit;
	}
	else
	{
		PCLK_CTL2 &= ~PCLK_CTL2_bit;
	}
}

/**
  * 描述  配置PCLK_CTL3控制的外设时钟使能。
  * 输入  PCLK_CTL3_bit: 指定外设时钟使能位的掩码，取值为：
  *                        PCLK_CTL3_SPI2CLKEN：	SPI2
  *                        PCLK_CTL3_SPI3CLKEN：	SPI3
  *                        PCLK_CTL3_I2C3CLKEN：	I2C3
  *                        PCLK_CTL3_HRCAP0CLKEN：HRCAP0
  *                        PCLK_CTL3_HRCAP1CLKEN：HRCAP1
  *                        PCLK_CTL3_HRCAP2CLKEN：HRCAP2
  *                        PCLK_CTL3_CRCCLKEN：CRC
  *                        PCLK_CTL3_AESCLKEN：AES
  *                        PCLK_CTL3_EXICCLKEN：EXIC
  *                        PCLK_CTL3_CAN4CLKEN：CAN4
  *                        PCLK_CTL3_CFGLCLKEN：	CFGL
  *                        PCLK_CTL3_OPCLKEN：OP
  *                        PCLK_CTL3_TRGMUXCLKEN：TRGMUX
  *                        PCLK_CTL3_PDB0CLKEN：PDB0
  *                        PCLK_CTL3_PDB1CLKEN：PDB1
  *                        PCLK_CTL3_PDB2CLKEN：PDB2
  *                        PCLK_CTL3_FLEXRPCLKEN：FLEXRP
  *                        PCLK_CTL3_PLAPCLKEN：PLAP
  *                        PCLK_CTL3_EWMCLKEN：EWM
  *                        PCLK_CTL3_RNGCLKEN：RNG
  *                        PCLK_CTL3_CAN6CLKEN：CAN6
  *                        PCLK_CTL3_CAN7CLKEN：CAN7
  *                        PCLK_CTL3_RTCCLKEN：RTC
  *
  *
  * NewState: 外设时钟使能状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  **/
void PCLK_CTL3_Peripheral_Clock_Enable (uint32_t PCLK_CTL3_bit,FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_PCLK_CTL3_PERIPH(PCLK_CTL3_bit));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	if(NewState != FALSE)
	{
		PCLK_CTL3 |= PCLK_CTL3_bit;
	}
	else
	{
		PCLK_CTL3 &= ~PCLK_CTL3_bit;
	}
}
/**
  *   ##### 外设时钟使能模块(PCLK)功能配置函数定义结束 #####
  **/
