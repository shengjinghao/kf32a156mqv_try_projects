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
  *	##### ��λģ��(RST)�������ú��� #####
  **/

/**
  * ����  ����RST_CTL0���Ƶ����踴λ״̬��
  * ����  RST_CTL0_bit: ָ�����踴λ����λ�����룬ȡֵΪ��
  *                       RST_CTL0_GPIOARST: GPIOA��λ
  *                       RST_CTL0_GPIOBRST: GPIOB��λ
  *                       RST_CTL0_GPIOCRST: GPIOC��λ
  *                       RST_CTL0_GPIODRST: GPIOD��λ
  *                       RST_CTL0_GPIOERST: GPIOE��λ
  *                       RST_CTL0_GPIOFRST: GPIOF��λ
  *                       RST_CTL0_GPIOGRST: GPIOG��λ
  *                       RST_CTL0_GPIOHRST: GPIOH��λ
  *                       RST_CTL0_GPIOIRST: GPIOI��λ
  * NewState: ���踴λ״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  **/
void RST_CTL0_Peripheral_Reset_Enable (uint32_t RST_CTL0_bit,FunctionalState NewState)
{
	/* ����У�� */
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
  * ����  ����RST_CTL1���Ƶ����踴λ״̬��
  * ����  RST_CTL1_bit: ָ�����踴λ����λ�����룬ȡֵΪ��
  *                       RST_CTL1_QEI1RST��QEI1��λ
  *                       RST_CTL1_T1RST��T1��λ
  *                       RST_CTL1_T2RST��T2��λ
  *                       RST_CTL1_T3RST��T3��λ
  *                       RST_CTL1_T4RST��T4��λ
  *                       RST_CTL1_T5T6RST��T5T6��λ
  *                       RST_CTL1_QEI0RST��QEI0��λ
  *                       RST_CTL1_ADC0RST��ADC0��λ
  *                       RST_CTL1_ADC1RST��ADC1��λ
  *                       RST_CTL1_ADC2RST��ADC2��λ
  *                       RST_CTL1_DAC0RST��DAC0��λ
  *                       RST_CTL1_DAC1RST��DAC1��λ
  *                       RST_CTL1_CMPRST��CMP��λ
  *                       RST_CTL1_T0RST��T0��λ
  *                       RST_CTL1_USART0RST��USART0��λ
  *                       RST_CTL1_USART1RST��USART1��λ
  *                       RST_CTL1_USART2RST��USART2��λ
  *                       RST_CTL1_USART4RST��USART4��λ
  *                       RST_CTL1_SPI0RST��SPI0��λ
  *                       RST_CTL1_SPI1RST��SPI1��λ
  *                       RST_CTL1_I2C0RST��I2C0��λ
  *                       RST_CTL1_I2C1RST��I2C1��λ
  *                       RST_CTL1_I2C2RST��I2C2��λ
  * NewState: ���踴λ״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  **/
void RST_CTL1_Peripheral_Reset_Enable (uint32_t RST_CTL1_bit,FunctionalState NewState)
{
	/* ����У�� */
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
  * ����  ����RST_CTL2���Ƶ����踴λ״̬��
  * ����  RST_CTL2_bit: ָ�����踴λ����λ�����룬ȡֵΪ��
  *                       RST_CTL2_I2C4RST��I2C4��λ
  *                       RST_CTL2_I2C5RST��I2C5��λ
  *                       RST_CTL2_WWDTRST��WWDT��λ
  *                       RST_CTL2_EPWM11TRST��EPWM11��λ
  *                       RST_CTL2_EPWM12TRST��EPWM12��λ
  *                       RST_CTL2_EPWM13TRST��EPWM13��λ
  *                       RST_CTL2_EPWM16TRST��EPWM16��λ
  *                       RST_CTL2_DMA0RST��DMA0��λ
  *                       RST_CTL2_DMA1RST��DMA1��λ
  *                       RST_CTL2_T14RST��T14��λ
  *                       RST_CTL2_T18RST��T18��λ
  *                       RST_CTL2_T19RST��T19��λ
  *                       RST_CTL2_T21RST��T21��λ
  *                       RST_CTL2_DAC2RST��DAC2��λ
  *                       RST_CTL2_DAC3RST��DAC3��λ
  *                       RST_CTL2_USART5RST��USART5��λ
  *                       RST_CTL2_USART7RST��USART7��λ
  * NewState: ���踴λ״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void RST_CTL2_Peripheral_Reset_Enable (uint32_t RST_CTL2_bit,FunctionalState NewState)
{
    /* ����У�� */
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
  * ����  ����RST_CTL3���Ƶ����踴λ״̬��
  * ����  RST_CTL3_bit: ָ�����踴λ����λ�����룬ȡֵΪ��
  *                       RST_CTL3_SPI2RST��SPI2��λ
  *                       RST_CTL3_SPI3RST��SPI3��λ
  *                       RST_CTL3_I2C3RST��I2C3��λ
  *                       RST_CTL3_HRCAP0RST��HRCAP0��λ
  *                       RST_CTL3_HRCAP1RST��HRCAP1��λ
  *                       RST_CTL3_HRCAP2RST��HRCAP2��λ
  *                       RST_CTL3_CRCRST��CRC��λ
  *                       RST_CTL3_AESRST��AES��λ
  *                       RST_CTL3_EXICRST��EXIC��λ
  *                       RST_CTL3_CAN4RST��CAN4��λ
  *                       RST_CTL3_CFGLRST��CFGL��λ
  *                       RST_CTL3_OPRST��OP��λ
  *                       RST_CTL3_TRGMUXRST��TRGMUX��λ
  *                       RST_CTL3_PDB0RST��PDB0��λ
  *                       RST_CTL3_PDB1RST��PDB1��λ
  *                       RST_CTL3_PDB2RST��PDB2��λ
  *                       RST_CTL3_FLEXRPRST��FLEXRP��λ
  *                       RST_CTL3_PLARST��PLA��λ
  *                       RST_CTL3_EWDTRST��EWDT��λ
  *                       RST_CTL3_RNGRST��RNG��λ
  *                       RST_CTL3_CAN6RST ��CAN6��λ
  *                       RST_CTL3_CAN7RST��CAN7��λ
  *                       RST_CTL3_RTCRST��RTC��λ
  * NewState: ���踴λ״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void RST_CTL3_Peripheral_Reset_Enable (uint32_t RST_CTL3_bit,FunctionalState NewState)
{
    /* ����У�� */
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
  *	##### ��λģ��(RST)�������ú���������� #####
  */
