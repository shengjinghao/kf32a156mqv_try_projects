/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_flexmux.c                             	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the FlexMUX function				  *
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

#include "kf32a1x6_flexmux.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  * 描述: 复位FlexMUX外设，使能外设时钟。
  * 输入: 无。
  * 返回: 无。
  */
void FMUX_Reset(void)
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FlexMUXRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FlexMUXRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_FlexMUXCLKEN, TRUE);
}
/**
  * 描述: 通道x选择使能。
  * 输入: Channel ： FMUX_CHANNEL_1 : FlexMUX通道1
  * 				FMUX_CHANNEL_2 : FlexMUX通道2
  * 				FMUX_CHANNEL_3 : FlexMUX通道3
  * 				FMUX_CHANNEL_4 : FlexMUX通道4
  * 	  NewState:	TRUE : 使能该通道
  * 	  			FALSE : 不使能该通道
  * 返回: 无。
  */
void FMUX_Channel_Enable(uint32_t Channel, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FMUX_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (FMUX_SOU_CH1EN_POS + Channel*8);
	tmask = 1 << (FMUX_SOU_CH1EN_POS + Channel*8);
	FMUX_SOU = SFR_Config(FMUX_SOU, ~tmask, tmpreg);
}
/**
  * 描述: 通道x的触发源选择。
  * 输入: Channel ： FMUX_CHANNEL_1 : FlexMUX通道1
  * 				FMUX_CHANNEL_2 : FlexMUX通道2
  * 				FMUX_CHANNEL_3 : FlexMUX通道3
  * 				FMUX_CHANNEL_4 : FlexMUX通道4
  *
  * 	  Source:	FMUX_CHANNEL_TRIGGLE_PF2PB5PA1
  * 	  			FMUX_CHANNEL_TRIGGLE_PF3PF7PA2PA0
  * 	  			FMUX_CHANNEL_TRIGGLE_PE2PE6PB14PB3
  * 	  			FMUX_CHANNEL_TRIGGLE_PB15PE0PE3PD14
  * 	  			FMUX_CHANNEL_TRIGGLE_PF6PA4PF0
  * 	  			FMUX_CHANNEL_TRIGGLE_PF1PF8PA5
  * 	  			FMUX_CHANNEL_TRIGGLE_PH4PH2PA6
  * 	  			FMUX_CHANNEL_TRIGGLE_PA7PE10
  * 	  			FMUX_CHANNEL_TRIGGLE_PE11PA11
  * 	  			FMUX_CHANNEL_TRIGGLE_PE1PE12PA13
  * 	  			FMUX_CHANNEL_TRIGGLE_PB0PE13
  * 	  			FMUX_CHANNEL_TRIGGLE_PB1PB2
  * 	  			FMUX_CHANNEL_TRIGGLE_USART0_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART0_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART1_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART1_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART2_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART2_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART4_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART4_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART5_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART5_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART7_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_USART7_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C0_ADDR_MATCH
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C0_ADDR_START
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C0_ADDR_STOP
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C1_ADDR_MATCH
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C1_ADDR_START
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C1_ADDR_STOP
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C2_ADDR_MATCH
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C2_ADDR_START
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C2_ADDR_STOP
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C3_ADDR_MATCH
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C3_ADDR_START
  * 	  			FMUX_CHANNEL_TRIGGLE_I2C3_ADDR_STOP
  * 	  			FMUX_CHANNEL_TRIGGLE_SPI0_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_SPI0_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_SPI1_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_SPI1_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_SPI2_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_SPI2_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_SPI3_RX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_SPI3_TX_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_ADC_INT_FLAG
  * 	  			FMUX_CHANNEL_TRIGGLE_ADC_CONVERSION_FINISH
  * 	  			FMUX_CHANNEL_TRIGGLE_CMP0_DIGITAL_OUTPUT
  * 	  			FMUX_CHANNEL_TRIGGLE_CMP1_DIGITAL_OUTPUT
  * 	  			FMUX_CHANNEL_TRIGGLE_CMP2_DIGITAL_OUTPUT
  * 	  			FMUX_CHANNEL_TRIGGLE_CMP3_DIGITAL_OUTPUT
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC0_OUTPUT
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC1_OUTPUT
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC2_OUTPUT
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP5CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP5CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP5CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP5CH4
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP0CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP0CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP0CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP0CH4
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP1CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP1CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP1CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP1CH4
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP2CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP2CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP2CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP2CH4
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP3CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP3CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP3CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP3CH4
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP4CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP4CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP4CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP4CH4
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP18CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP18CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP18CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP18CH4
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP19CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP19CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP19CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP91CH4
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP21CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP21CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP21CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_CCP21CH4
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC0_CH0
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC0_CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC0_CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC0_CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC1_CH0
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC1_CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC1_CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC1_CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC2_CH0
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC2_CH1
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC2_CH2
  * 	  			FMUX_CHANNEL_TRIGGLE_FDC2_CH3
  * 	  			FMUX_CHANNEL_TRIGGLE_EPWM11_SYNC
  * 	  			FMUX_CHANNEL_TRIGGLE_EPWM12_SYNC
  * 	  			FMUX_CHANNEL_TRIGGLE_EPWM13_SYNC
  * 	  			FMUX_CHANNEL_TRIGGLE_EPWM16_SYNC
  * 	  			FMUX_CHANNEL_TRIGGLE_RTC_INT_FLAG
  * 	  			FMUX_CHANNEL_TRIGGLE_RTC_ALARM_INT_FLAG
  * 	  			FMUX_CHANNEL_TRIGGLE_RTC_BEAT_OUTPUT
  * 返回: 无。
  */
void FMUX_Channel_Triggle_Source_Select(uint32_t Channel, uint32_t Source)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FMUX_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FMUX_CHANNEL_TRIGGLE_SOURCE(Source));

	tmpreg = Source << Channel*8;
	tmask = FMUX_SOU_SEL1 << Channel*8;
	FMUX_SOU = SFR_Config(FMUX_SOU, ~tmask, tmpreg);
}


  /**
    * 描述: FlexMUX 使能。
    * 输入: NewState:	TRUE : 使能该通道
    * 	  				FALSE : 不使能该通道
    * 返回: 无。
    */
void FMUX_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	FMUX_TAR = SFR_Config(FMUX_TAR, ~FMUX_TAR_TRGEN, NewState);
}
/**
  * 描述: FlexMUX 输出通道 x 事件的 DMA 请求使能。
  * 输入: 	Channel ：	FMUX_CHANNEL_1 : FlexMUX通道1
  * 					FMUX_CHANNEL_2 : FlexMUX通道2
  * 					FMUX_CHANNEL_3 : FlexMUX通道3
  * 					FMUX_CHANNEL_4 : FlexMUX通道4
  * 		NewState:	TRUE : 使能该通道
  * 	  				FALSE : 不使能该通道
  * 返回: 无。
  */
void FMUX_Output_Channel_DMA_Enable(uint32_t Channel, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FMUX_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (Channel + 1);
	tmask = 1 << (Channel + 1);
	FMUX_TAR = SFR_Config(FMUX_TAR, ~tmask, tmpreg);
}
/**
  * 描述: 通道 x 触发信号维持有效时间选择。
  * 输入: 	Channel ：	FMUX_CHANNEL_1 : FlexMUX通道1
  * 					FMUX_CHANNEL_2 : FlexMUX通道2
  * 					FMUX_CHANNEL_3 : FlexMUX通道3
  * 					FMUX_CHANNEL_4 : FlexMUX通道4
  * 		DIV:		FMUX_CHANNEL_DIV1 : CHxSEL<1:0>为 11 时，触发信号维持 1 个时钟周期
  * 	  				FMUX_CHANNEL_DIV2 : CHxSEL<1:0>为 11 时，触发信号维持 2 个时钟周期
  * 	  				FMUX_CHANNEL_DIV4 : CHxSEL<1:0>为 11 时，触发信号维持 4 个时钟周期
  * 	  				FMUX_CHANNEL_DIV8 : CHxSEL<1:0>为 11 时，触发信号维持 8 个时钟周期
  * 返回: 无。
  */
void FMUX_Triggle_Single_Maintain_Time_Select(uint32_t Channel, uint32_t DIV)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FMUX_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FMUX_CHANNEL_DIV(DIV));

	tmpreg = DIV << (FMUX_TAR_CH1DIV0_POS + Channel*2);
	tmask = 0x03 << (FMUX_TAR_CH1DIV0_POS + Channel*2);
	FMUX_TAR = SFR_Config(FMUX_TAR, ~tmask, tmpreg);
}
/**
  * 描述: 输出选择。
  * 输入: 	Channel ：	FMUX_CHANNEL_1 : FlexMUX通道1
  * 					FMUX_CHANNEL_2 : FlexMUX通道2
  * 					FMUX_CHANNEL_3 : FlexMUX通道3
  * 					FMUX_CHANNEL_4 : FlexMUX通道4
  * 		MODE:		FMUX_INPUT_OUTPUT : 输入直接输出
  * 	  				FMUX_INPUT_SCK_SYNC_OUTPUT : 输入与FlexMUX工作时钟同步输出
  * 	  				FMUX_INPUT_SCK_DIV_SYNC_OUTPUT : 输入与FlexMUX工作时钟分频后的时钟同步输出
  * 	  				FMUX_INPUT_MAINTAIN_OUTPUT : 输入维持指定时钟周期后输出
  * 返回: 无。
  */
void FMUX_Output_Select(uint32_t Channel, uint32_t MODE)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FMUX_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FMUX_OUTPUT_SEL(MODE));

	tmpreg = MODE << (FMUX_TAR_CH1SEL0_POS + Channel*2);
	tmask = 0x03 << (FMUX_TAR_CH1SEL0_POS + Channel*2);
	FMUX_TAR = SFR_Config(FMUX_TAR, ~tmask, tmpreg);
}
/**
  * 描述: 工作时钟源选择。
  * 输入: 	CLK ：	FMUX_CLK_SCLK : 选择SCLK作为FlexMUX的工作时钟
  * 				FMUX_CLK_HFCLK : 选择HFCLK作为FlexMUX的工作时钟
  * 				FMUX_CLK_LFCLK : 选择LFCLK作为FlexMUX的工作时钟
  * 返回: 无。
  */
void FMUX_Work_CLK_Select(uint32_t CLK)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FMUX_CLK(CLK));

	FMUX_TAR = SFR_Config(FMUX_TAR, ~FMUX_TAR_TCKS, CLK << FMUX_TAR_TCKS0_POS);
}




