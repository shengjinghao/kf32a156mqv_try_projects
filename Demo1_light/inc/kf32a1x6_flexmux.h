/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_flexmux.h                             	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the FLXMUX		  *
 *						peripherals.										  *
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
 *  										                                  *
 *                                                                            *
 *                                                                            *
 *****************************************************************************/
#ifndef KF32A1x6_FlexMUX_H_
#define KF32A1x6_FlexMUX_H_

#include "kf32a1x6.h"


/**
 * 	FlexMUX通道
 * */
#define FMUX_CHANNEL_1									((uint32_t)0)
#define FMUX_CHANNEL_2									((uint32_t)1)
#define FMUX_CHANNEL_3									((uint32_t)2)
#define FMUX_CHANNEL_4									((uint32_t)3)
#define CHECK_FMUX_CHANNEL(CHANNEL)						((CHANNEL) <= FMUX_CHANNEL_4)

/**
 * 	FlexMUX通道触发源选择
 * */
#define FMUX_CHANNEL_TRIGGLE_PF2PB5PA1					((uint32_t)0)
#define FMUX_CHANNEL_TRIGGLE_PF3PF7PA2PA0				((uint32_t)1)
#define FMUX_CHANNEL_TRIGGLE_PE2PE6PB14PB3				((uint32_t)2)
#define FMUX_CHANNEL_TRIGGLE_PB15PE0PE3PD14				((uint32_t)3)
#define FMUX_CHANNEL_TRIGGLE_PF6PA4PF0					((uint32_t)4)
#define FMUX_CHANNEL_TRIGGLE_PF1PF8PA5					((uint32_t)5)
#define FMUX_CHANNEL_TRIGGLE_PH4PH2PA6					((uint32_t)6)
#define FMUX_CHANNEL_TRIGGLE_PA7PE10					((uint32_t)7)
#define FMUX_CHANNEL_TRIGGLE_PE11PA11					((uint32_t)8)
#define FMUX_CHANNEL_TRIGGLE_PE1PE12PA13				((uint32_t)9)
#define FMUX_CHANNEL_TRIGGLE_PB0PE13					((uint32_t)10)
#define FMUX_CHANNEL_TRIGGLE_PB1PB2						((uint32_t)11)
#define FMUX_CHANNEL_TRIGGLE_USART0_RX_FINISH			((uint32_t)12)
#define FMUX_CHANNEL_TRIGGLE_USART0_TX_FINISH			((uint32_t)13)
#define FMUX_CHANNEL_TRIGGLE_USART1_RX_FINISH			((uint32_t)14)
#define FMUX_CHANNEL_TRIGGLE_USART1_TX_FINISH			((uint32_t)15)
#define FMUX_CHANNEL_TRIGGLE_USART2_RX_FINISH			((uint32_t)16)
#define FMUX_CHANNEL_TRIGGLE_USART2_TX_FINISH			((uint32_t)17)
#define FMUX_CHANNEL_TRIGGLE_USART4_RX_FINISH			((uint32_t)18)
#define FMUX_CHANNEL_TRIGGLE_USART4_TX_FINISH			((uint32_t)19)
#define FMUX_CHANNEL_TRIGGLE_USART5_RX_FINISH			((uint32_t)20)
#define FMUX_CHANNEL_TRIGGLE_USART5_TX_FINISH			((uint32_t)21)
#define FMUX_CHANNEL_TRIGGLE_USART7_RX_FINISH			((uint32_t)22)
#define FMUX_CHANNEL_TRIGGLE_USART7_TX_FINISH			((uint32_t)23)
#define FMUX_CHANNEL_TRIGGLE_I2C0_ADDR_MATCH			((uint32_t)24)
#define FMUX_CHANNEL_TRIGGLE_I2C0_ADDR_START			((uint32_t)25)
#define FMUX_CHANNEL_TRIGGLE_I2C0_ADDR_STOP				((uint32_t)26)
#define FMUX_CHANNEL_TRIGGLE_I2C1_ADDR_MATCH			((uint32_t)27)
#define FMUX_CHANNEL_TRIGGLE_I2C1_ADDR_START			((uint32_t)28)
#define FMUX_CHANNEL_TRIGGLE_I2C1_ADDR_STOP				((uint32_t)29)
#define FMUX_CHANNEL_TRIGGLE_I2C2_ADDR_MATCH			((uint32_t)30)
#define FMUX_CHANNEL_TRIGGLE_I2C2_ADDR_START			((uint32_t)31)
#define FMUX_CHANNEL_TRIGGLE_I2C2_ADDR_STOP				((uint32_t)32)
#define FMUX_CHANNEL_TRIGGLE_I2C3_ADDR_MATCH			((uint32_t)33)
#define FMUX_CHANNEL_TRIGGLE_I2C3_ADDR_START			((uint32_t)34)
#define FMUX_CHANNEL_TRIGGLE_I2C3_ADDR_STOP				((uint32_t)35)
#define FMUX_CHANNEL_TRIGGLE_SPI0_RX_FINISH				((uint32_t)42)
#define FMUX_CHANNEL_TRIGGLE_SPI0_TX_FINISH				((uint32_t)43)
#define FMUX_CHANNEL_TRIGGLE_SPI1_RX_FINISH				((uint32_t)44)
#define FMUX_CHANNEL_TRIGGLE_SPI1_TX_FINISH				((uint32_t)45)
#define FMUX_CHANNEL_TRIGGLE_SPI2_RX_FINISH				((uint32_t)46)
#define FMUX_CHANNEL_TRIGGLE_SPI2_TX_FINISH				((uint32_t)47)
#define FMUX_CHANNEL_TRIGGLE_SPI3_RX_FINISH				((uint32_t)48)
#define FMUX_CHANNEL_TRIGGLE_SPI3_TX_FINISH				((uint32_t)49)
#define FMUX_CHANNEL_TRIGGLE_ADC_INT_FLAG				((uint32_t)50)
#define FMUX_CHANNEL_TRIGGLE_ADC_CONVERSION_FINISH		((uint32_t)51)
#define FMUX_CHANNEL_TRIGGLE_CMP0_DIGITAL_OUTPUT			((uint32_t)52)
#define FMUX_CHANNEL_TRIGGLE_CMP1_DIGITAL_OUTPUT			((uint32_t)53)
#define FMUX_CHANNEL_TRIGGLE_CMP2_DIGITAL_OUTPUT			((uint32_t)54)
#define FMUX_CHANNEL_TRIGGLE_CMP3_DIGITAL_OUTPUT			((uint32_t)55)
#define FMUX_CHANNEL_TRIGGLE_FDC0_OUTPUT					((uint32_t)56)
#define FMUX_CHANNEL_TRIGGLE_FDC1_OUTPUT					((uint32_t)57)
#define FMUX_CHANNEL_TRIGGLE_FDC2_OUTPUT					((uint32_t)58)
#define FMUX_CHANNEL_TRIGGLE_CCP5CH1						((uint32_t)59)
#define FMUX_CHANNEL_TRIGGLE_CCP5CH2						((uint32_t)60)
#define FMUX_CHANNEL_TRIGGLE_CCP5CH3						((uint32_t)61)
#define FMUX_CHANNEL_TRIGGLE_CCP5CH4						((uint32_t)62)
#define FMUX_CHANNEL_TRIGGLE_CCP0CH1						((uint32_t)67)
#define FMUX_CHANNEL_TRIGGLE_CCP0CH2						((uint32_t)68)
#define FMUX_CHANNEL_TRIGGLE_CCP0CH3						((uint32_t)69)
#define FMUX_CHANNEL_TRIGGLE_CCP0CH4						((uint32_t)70)
#define FMUX_CHANNEL_TRIGGLE_CCP1CH1						((uint32_t)71)
#define FMUX_CHANNEL_TRIGGLE_CCP1CH2						((uint32_t)72)
#define FMUX_CHANNEL_TRIGGLE_CCP1CH3						((uint32_t)73)
#define FMUX_CHANNEL_TRIGGLE_CCP1CH4						((uint32_t)74)
#define FMUX_CHANNEL_TRIGGLE_CCP2CH1						((uint32_t)75)
#define FMUX_CHANNEL_TRIGGLE_CCP2CH2						((uint32_t)76)
#define FMUX_CHANNEL_TRIGGLE_CCP2CH3						((uint32_t)77)
#define FMUX_CHANNEL_TRIGGLE_CCP2CH4						((uint32_t)78)
#define FMUX_CHANNEL_TRIGGLE_CCP3CH1						((uint32_t)79)
#define FMUX_CHANNEL_TRIGGLE_CCP3CH2						((uint32_t)80)
#define FMUX_CHANNEL_TRIGGLE_CCP3CH3						((uint32_t)81)
#define FMUX_CHANNEL_TRIGGLE_CCP3CH4						((uint32_t)82)
#define FMUX_CHANNEL_TRIGGLE_CCP4CH1						((uint32_t)83)
#define FMUX_CHANNEL_TRIGGLE_CCP4CH2						((uint32_t)84)
#define FMUX_CHANNEL_TRIGGLE_CCP4CH3						((uint32_t)85)
#define FMUX_CHANNEL_TRIGGLE_CCP4CH4						((uint32_t)86)
#define FMUX_CHANNEL_TRIGGLE_CCP18CH1					((uint32_t)87)
#define FMUX_CHANNEL_TRIGGLE_CCP18CH2					((uint32_t)88)
#define FMUX_CHANNEL_TRIGGLE_CCP18CH3					((uint32_t)89)
#define FMUX_CHANNEL_TRIGGLE_CCP18CH4					((uint32_t)90)
#define FMUX_CHANNEL_TRIGGLE_CCP19CH1					((uint32_t)91)
#define FMUX_CHANNEL_TRIGGLE_CCP19CH2					((uint32_t)92)
#define FMUX_CHANNEL_TRIGGLE_CCP19CH3					((uint32_t)93)
#define FMUX_CHANNEL_TRIGGLE_CCP91CH4					((uint32_t)94)
#define FMUX_CHANNEL_TRIGGLE_CCP21CH1					((uint32_t)95)
#define FMUX_CHANNEL_TRIGGLE_CCP21CH2					((uint32_t)96)
#define FMUX_CHANNEL_TRIGGLE_CCP21CH3					((uint32_t)97)
#define FMUX_CHANNEL_TRIGGLE_CCP21CH4					((uint32_t)98)
#define FMUX_CHANNEL_TRIGGLE_FDC0_CH0					((uint32_t)99)
#define FMUX_CHANNEL_TRIGGLE_FDC0_CH1					((uint32_t)100)
#define FMUX_CHANNEL_TRIGGLE_FDC0_CH2					((uint32_t)101)
#define FMUX_CHANNEL_TRIGGLE_FDC0_CH3					((uint32_t)102)
#define FMUX_CHANNEL_TRIGGLE_FDC1_CH0					((uint32_t)103)
#define FMUX_CHANNEL_TRIGGLE_FDC1_CH1					((uint32_t)104)
#define FMUX_CHANNEL_TRIGGLE_FDC1_CH2					((uint32_t)105)
#define FMUX_CHANNEL_TRIGGLE_FDC1_CH3					((uint32_t)106)
#define FMUX_CHANNEL_TRIGGLE_FDC2_CH0					((uint32_t)107)
#define FMUX_CHANNEL_TRIGGLE_FDC2_CH1					((uint32_t)108)
#define FMUX_CHANNEL_TRIGGLE_FDC2_CH2					((uint32_t)109)
#define FMUX_CHANNEL_TRIGGLE_FDC2_CH3					((uint32_t)110)
#define FMUX_CHANNEL_TRIGGLE_EPWM11_SYNC					((uint32_t)112)
#define FMUX_CHANNEL_TRIGGLE_EPWM12_SYNC					((uint32_t)113)
#define FMUX_CHANNEL_TRIGGLE_EPWM13_SYNC					((uint32_t)114)
#define FMUX_CHANNEL_TRIGGLE_EPWM16_SYNC					((uint32_t)115)
#define FMUX_CHANNEL_TRIGGLE_RTC_INT_FLAG				((uint32_t)116)
#define FMUX_CHANNEL_TRIGGLE_RTC_ALARM_INT_FLAG			((uint32_t)117)
#define FMUX_CHANNEL_TRIGGLE_RTC_BEAT_OUTPUT				((uint32_t)118)
#define CHECK_FMUX_CHANNEL_TRIGGLE_SOURCE(SOURCE)		(((SOURCE) <= FMUX_CHANNEL_TRIGGLE_RTC_BEAT_OUTPUT) \
													  && ((SOURCE) != 36) \
													  && ((SOURCE) != 37) \
													  && ((SOURCE) != 38) \
													  && ((SOURCE) != 39) \
													  && ((SOURCE) != 40) \
													  && ((SOURCE) != 41) \
													  && ((SOURCE) != 63) \
													  && ((SOURCE) != 64) \
													  && ((SOURCE) != 65) \
													  && ((SOURCE) != 66) \
													  && ((SOURCE) != 111))

/**
 * 	通道 x 触发信号维持有效时间选择
 * */
#define FMUX_CHANNEL_DIV1								((uint32_t)0)
#define FMUX_CHANNEL_DIV2								((uint32_t)1)
#define FMUX_CHANNEL_DIV4								((uint32_t)2)
#define FMUX_CHANNEL_DIV8								((uint32_t)3)
#define CHECK_FMUX_CHANNEL_DIV(DIV)						((DIV) <= FMUX_CHANNEL_DIV8)

/**
 * 	输出选择
 * */
#define FMUX_INPUT_OUTPUT								((uint32_t)0)
#define FMUX_INPUT_SCK_SYNC_OUTPUT						((uint32_t)1)
#define FMUX_INPUT_SCK_DIV_SYNC_OUTPUT					((uint32_t)2)
#define FMUX_INPUT_MAINTAIN_OUTPUT						((uint32_t)3)
#define CHECK_FMUX_OUTPUT_SEL(SELECT)					((SELECT) <= FMUX_INPUT_MAINTAIN_OUTPUT)

/**
 * 	工作时钟源选择
 * */
#define FMUX_CLK_SCLK									((uint32_t)0)
#define FMUX_CLK_HFCLK									((uint32_t)1)
#define FMUX_CLK_LFCLK									((uint32_t)3)
#define CHECK_FMUX_CLK(CLK)								((CLK) <= FMUX_CLK_LFCLK)


void FMUX_Reset(void);
void FMUX_Channel_Enable(uint32_t Channel, FunctionalState NewState);
void FMUX_Channel_Triggle_Source_Select(uint32_t Channel, uint32_t Source);
void FMUX_Enable(FunctionalState NewState);
void FMUX_Output_Channel_DMA_Enable(uint32_t Channel, FunctionalState NewState);
void FMUX_Triggle_Single_Maintain_Time_Select(uint32_t Channel, uint32_t DIV);
void FMUX_Output_Select(uint32_t Channel, uint32_t MODE);
void FMUX_Work_CLK_Select(uint32_t CLK);


#endif /* KF32A1x6_FlexMUX_H_ */
