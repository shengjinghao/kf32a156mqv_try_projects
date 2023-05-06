/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_rst.c                                 	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Reset module (RST) peripheral  *
 *                    	function, including:                                  *
 *          			+ Reset module(RST) function configuration function	  *
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


#include "kf32a1x6_rst.h"


/**
  *	##### 复位模块(RST)功能配置函数 #####
  **/

/**
  * 描述  配置RST_CTL0控制的外设复位状态。
  * 输入  RST_CTL0_bit: 指定外设复位功能位的掩码，取值为：
  *                       RST_CTL0_GPIOARST: GPIOA复位
  *                       RST_CTL0_GPIOBRST: GPIOB复位
  *                       RST_CTL0_GPIOCRST: GPIOC复位
  *                       RST_CTL0_GPIODRST: GPIOD复位
  *                       RST_CTL0_GPIOERST: GPIOE复位
  *                       RST_CTL0_GPIOFRST: GPIOF复位
  *                       RST_CTL0_GPIOGRST: GPIOG复位
  *                       RST_CTL0_GPIOHRST: GPIOH复位
  *                       RST_CTL0_GPIOIRST: GPIOI复位
  * NewState: 外设复位状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  **/
void RST_CTL0_Peripheral_Reset_Enable (uint32_t RST_CTL0_bit,FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_RST_CTL0_RESET_PERIPH(RST_CTL0_bit));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	if(NewState != FALSE)
	{
		RST_CTL0 |= RST_CTL0_bit;
	}
	else
	{
		RST_CTL0 &= ~RST_CTL0_bit;
	}
}

/**
  * 描述  配置RST_CTL1控制的外设复位状态。
  * 输入  RST_CTL1_bit: 指定外设复位功能位的掩码，取值为：
  *                       RST_CTL1_QEI1RST：QEI1复位
  *                       RST_CTL1_T1RST：T1复位
  *                       RST_CTL1_T2RST：T2复位
  *                       RST_CTL1_T3RST：T3复位
  *                       RST_CTL1_T4RST：T4复位
  *                       RST_CTL1_T5T6RST：T5T6复位
  *                       RST_CTL1_QEI0RST：QEI0复位
  *                       RST_CTL1_ADC0RST：ADC0复位
  *                       RST_CTL1_ADC1RST：ADC1复位
  *                       RST_CTL1_ADC2RST：ADC2复位
  *                       RST_CTL1_DAC0RST：DAC0复位
  *                       RST_CTL1_DAC1RST：DAC1复位
  *                       RST_CTL1_CMPRST：CMP复位
  *                       RST_CTL1_T0RST：T0复位
  *                       RST_CTL1_USART0RST：USART0复位
  *                       RST_CTL1_USART1RST：USART1复位
  *                       RST_CTL1_USART2RST：USART2复位
  *                       RST_CTL1_USART4RST：USART4复位
  *                       RST_CTL1_SPI0RST：SPI0复位
  *                       RST_CTL1_SPI1RST：SPI1复位
  *                       RST_CTL1_I2C0RST：I2C0复位
  *                       RST_CTL1_I2C1RST：I2C1复位
  *                       RST_CTL1_I2C2RST：I2C2复位
  * NewState: 外设复位状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  **/
void RST_CTL1_Peripheral_Reset_Enable (uint32_t RST_CTL1_bit,FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_RST_CTL1_RESET_PERIPH(RST_CTL1_bit));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	if(NewState != FALSE)
	{
		RST_CTL1 |= RST_CTL1_bit;
	}
	else
	{
		RST_CTL1 &= ~RST_CTL1_bit;
	}
}

/**
  * 描述  配置RST_CTL2控制的外设复位状态。
  * 输入  RST_CTL2_bit: 指定外设复位功能位的掩码，取值为：
  *                       RST_CTL2_I2C4RST：I2C4复位
  *                       RST_CTL2_I2C5RST：I2C5复位
  *                       RST_CTL2_WWDTRST：WWDT复位
  *                       RST_CTL2_EPWM11TRST：EPWM11复位
  *                       RST_CTL2_EPWM12TRST：EPWM12复位
  *                       RST_CTL2_EPWM13TRST：EPWM13复位
  *                       RST_CTL2_EPWM16TRST：EPWM16复位
  *                       RST_CTL2_DMA0RST：DMA0复位
  *                       RST_CTL2_DMA1RST：DMA1复位
  *                       RST_CTL2_T14RST：T14复位
  *                       RST_CTL2_T18RST：T18复位
  *                       RST_CTL2_T19RST：T19复位
  *                       RST_CTL2_T21RST：T21复位
  *                       RST_CTL2_DAC2RST：DAC2复位
  *                       RST_CTL2_DAC3RST：DAC3复位
  *                       RST_CTL2_USART5RST：USART5复位
  *                       RST_CTL2_USART7RST：USART7复位
  * NewState: 外设复位状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  */
void RST_CTL2_Peripheral_Reset_Enable (uint32_t RST_CTL2_bit,FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_RST_CTL2_RESET_PERIPH(RST_CTL2_bit));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        RST_CTL2 |= RST_CTL2_bit;
    }
    else
    {
        RST_CTL2 &= ~RST_CTL2_bit;
    }
}

/**
  * 描述  配置RST_CTL3控制的外设复位状态。
  * 输入  RST_CTL3_bit: 指定外设复位功能位的掩码，取值为：
  *                       RST_CTL3_SPI2RST：SPI2复位
  *                       RST_CTL3_SPI3RST：SPI3复位
  *                       RST_CTL3_I2C3RST：I2C3复位
  *                       RST_CTL3_HRCAP0RST：HRCAP0复位
  *                       RST_CTL3_HRCAP1RST：HRCAP1复位
  *                       RST_CTL3_HRCAP2RST：HRCAP2复位
  *                       RST_CTL3_CRCRST：CRC复位
  *                       RST_CTL3_AESRST：AES复位
  *                       RST_CTL3_EXICRST：EXIC复位
  *                       RST_CTL3_CAN4RST：CAN4复位
  *                       RST_CTL3_CFGLRST：CFGL复位
  *                       RST_CTL3_OPRST：OP复位
  *                       RST_CTL3_TRGMUXRST：TRGMUX复位
  *                       RST_CTL3_PDB0RST：PDB0复位
  *                       RST_CTL3_PDB1RST：PDB1复位
  *                       RST_CTL3_PDB2RST：PDB2复位
  *                       RST_CTL3_FLEXRPRST：FLEXRP复位
  *                       RST_CTL3_PLARST：PLA复位
  *                       RST_CTL3_EWDTRST：EWDT复位
  *                       RST_CTL3_RNGRST：RNG复位
  *                       RST_CTL3_CAN6RST ：CAN6复位
  *                       RST_CTL3_CAN7RST：CAN7复位
  *                       RST_CTL3_RTCRST：RTC复位
  * NewState: 外设复位状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  */
void RST_CTL3_Peripheral_Reset_Enable (uint32_t RST_CTL3_bit,FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_RST_CTL3_RESET_PERIPH(RST_CTL3_bit));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        RST_CTL3 |= RST_CTL3_bit;
    }
    else
    {
        RST_CTL3 &= ~RST_CTL3_bit;
    }
}

/**
  *	##### 复位模块(RST)功能配置函数定义结束 #####
  */
