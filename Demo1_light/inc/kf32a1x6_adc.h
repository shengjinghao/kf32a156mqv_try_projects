/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_adc.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                          		  *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the ADC 			  *
 						peripherals.										  *
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

#ifndef KF32A1x6_ADC_H_
#define KF32A1x6_ADC_H_

#include "kf32a1x6.h"


/**
  * 描述  模数转换模块(ADC)配置信息结构体
  */
typedef struct
{
    uint32_t m_Clock;                   /* ADC时钟源选择，
                                           取值为宏“ADC时钟源”中的一个。 */
    uint32_t m_ClockDiv;                /* ADC时钟分频，
                                           取值为宏“ADC时钟分频”中的一个。 */
    FunctionalState m_ScanMode;         /* ADC扫描模式使能，
                                           取值为TRUE或FALSE。 */
    uint32_t m_ContinuousMode;          /* ADC连续转换模式，
                                           取值为宏“ADC连续转换”中的一个。 */
    uint32_t m_DataAlign;               /* ADC转换结果输出格式，
                                           取值为宏“ADC转换结果对齐格式”中的一个。 */
    FunctionalState m_ExternalTrig_EN;  /* ADC常规通道外部触发转换模式使能，
                                           取值为TRUE或FALSE。 */
    uint32_t m_ExternalTrig;            /* ADC常规通道外部触发事件，
                                           取值为宏“ADC常规通道外部触发事件”中的一个。 */
    FunctionalState m_HPExternalTrig_EN;/* ADC高优先级通道外部触发转换模式使能，
                                           取值为TRUE或FALSE。 */
    uint32_t m_HPExternalTrig;          /* 高优先级通道外部触发事件，
                                           取值为宏“ADC高优先级通道外部触发事件”中的一个。 */
    uint32_t m_VoltageRef;              /* 参考电压选择，
                                           取值为宏“ADC参考电压选择”中的一个。 */
    uint32_t m_NumOfConv;               /* ADC常规通道扫描长度，
                                           取值为1~16。 */
    uint32_t m_NumOfHPConv;             /* ADC高优先级通道扫描长度，
                                           取值为1~4。 */
}ADC_InitTypeDef;

/**
  * 描述  模数转换模块(ADC)快慢交叉模式信息结构体
  */
typedef struct
{
    uint32_t m_FastDelay;               /* ADC快速交叉模式延时时间，
                                           取值为1~64。 */
    uint32_t m_SlowDelay;               /* ADC慢速交叉模式延时时间，
                                           取值为1~64。 */
}ADC0_DELAY_InitTypeDef;

/**
  * 描述  模数转换模块(ADC)模拟看门狗信息结构体
  */
typedef struct
{
    uint32_t m_WDSingleCH;              /* ADC模拟看门狗单通道使能，
                                           取值为宏“ADC模拟看门狗单通道使能”中的一个。 */
    FunctionalState m_HPChannelWDEN;    /* ADC高优先级通道上看门狗使能，
                                           取值为TRUE或FALSE。 */
    FunctionalState m_ChannelWDEN;      /* ADC常规通道上看门狗使能，
                                           取值为TRUE或FALSE。 */
    uint32_t m_WDChannel;               /* ADC模拟看门狗通道选择，
                                           取值为宏“ADC模拟看门狗通道选择”中的一个。 */
    uint32_t m_Threshold_H;             /* ADC模拟看门狗高阈值，
                                           取值为0~0xFFF。 */
    uint32_t m_Threshold_L;             /* ADC模拟看门狗低阈值，
                                           取值为0~0xFFF。 */
}ADC_WD_InitTypeDef;


/**
  * ADC内存指针
  */
#define CHECK_ADC_ALL_PERIPH(PERIPH)    (((PERIPH) == ADC0_SFR) \
                                      || ((PERIPH) == ADC1_SFR) \
                                      || ((PERIPH) == ADC2_SFR))

/**
  * ADC时钟源
  */
#define ADC_SCLK                        ((uint32_t)0<<ADC_CTL0_CLKS0_POS)
#define ADC_HFCLK                       ((uint32_t)1<<ADC_CTL0_CLKS0_POS)
#define ADC_LFCLK                       ((uint32_t)2<<ADC_CTL0_CLKS0_POS)
#define CHECK_ADC_CLK(CLK)              (((CLK) == ADC_SCLK) \
                                      || ((CLK) == ADC_HFCLK) \
                                      || ((CLK) == ADC_LFCLK))

/**
  * ADC时钟分频
  */
#define ADC_CLK_DIV_2                   ((uint32_t)0<<ADC_CTL0_ADCCLKS0_POS)
#define ADC_CLK_DIV_4                   ((uint32_t)1<<ADC_CTL0_ADCCLKS0_POS)
#define ADC_CLK_DIV_8                   ((uint32_t)2<<ADC_CTL0_ADCCLKS0_POS)
#define ADC_CLK_DIV_16                  ((uint32_t)3<<ADC_CTL0_ADCCLKS0_POS)
#define ADC_CLK_DIV_32                  ((uint32_t)4<<ADC_CTL0_ADCCLKS0_POS)
#define ADC_CLK_DIV_64                  ((uint32_t)5<<ADC_CTL0_ADCCLKS0_POS)
#define CHECK_ADC_CLK_DIV(CLK)          (((CLK) == ADC_CLK_DIV_2) \
                                      || ((CLK) == ADC_CLK_DIV_4) \
                                      || ((CLK) == ADC_CLK_DIV_8) \
                                      || ((CLK) == ADC_CLK_DIV_16) \
                                      || ((CLK) == ADC_CLK_DIV_32) \
                                      || ((CLK) == ADC_CLK_DIV_64))

/**
  * ADC参考电压选择
  */
#define ADC_REF_INTERNAL                ((uint32_t)4<<ADC_CTL1_REF0_POS)
#define ADC_REF_VREF                    ((uint32_t)2<<ADC_CTL1_REF0_POS)
#define ADC_REF_AVDD                    ((uint32_t)1<<ADC_CTL1_REF0_POS)
#define CHECK_ADC_REF(CLK)              (((CLK) == ADC_REF_INTERNAL) \
                                      || ((CLK) == ADC_REF_VREF) \
                                      || ((CLK) == ADC_REF_AVDD))

/**
  * ADC阈值范围限制
  */
#define CHECK_ADC_THRESHOLD(THRESHOLD)  (((THRESHOLD) >> 12) == 0)

/**
  * ADC模拟看门狗通道选择
  */
#define ADC_WDCH_0                      ((uint32_t)0<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_1                      ((uint32_t)1<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_2                      ((uint32_t)2<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_3                      ((uint32_t)3<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_4                      ((uint32_t)4<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_5                      ((uint32_t)5<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_6                      ((uint32_t)6<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_7                      ((uint32_t)7<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_8                      ((uint32_t)8<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_9                      ((uint32_t)9<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_10                     ((uint32_t)0xA<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_11                     ((uint32_t)0xB<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_12                     ((uint32_t)0xC<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_13                     ((uint32_t)0xD<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_14                     ((uint32_t)0xE<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_15                     ((uint32_t)0xF<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_16                     ((uint32_t)0x10<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_17                     ((uint32_t)0x11<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_18                     ((uint32_t)0x12<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_19                     ((uint32_t)0x13<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_20                     ((uint32_t)0x14<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_21                     ((uint32_t)0x15<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_22                     ((uint32_t)0x16<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_23                     ((uint32_t)0x17<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_24                     ((uint32_t)0x18<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_25                     ((uint32_t)0x19<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_26                     ((uint32_t)0x1A<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_27                     ((uint32_t)0x1B<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_28                     ((uint32_t)0x1C<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_29                     ((uint32_t)0x1D<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_30                     ((uint32_t)0x1E<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_31                     ((uint32_t)0x1F<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_32                     ((uint32_t)0x20<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_33                     ((uint32_t)0x21<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_34                     ((uint32_t)0x22<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_35                     ((uint32_t)0x23<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_36                     ((uint32_t)0x24<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_37                     ((uint32_t)0x25<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_38                     ((uint32_t)0x26<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_39                     ((uint32_t)0x27<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_40                     ((uint32_t)0x28<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_41                     ((uint32_t)0x29<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_42                     ((uint32_t)0x2A<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_43                     ((uint32_t)0x2B<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_44                     ((uint32_t)0x2C<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_45                     ((uint32_t)0x2D<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_46                     ((uint32_t)0x2E<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_47                     ((uint32_t)0x2F<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_48                     ((uint32_t)0x30<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_49                     ((uint32_t)0x31<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_50                     ((uint32_t)0x32<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_51                     ((uint32_t)0x33<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_52                     ((uint32_t)0x34<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_53                     ((uint32_t)0x35<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_54                     ((uint32_t)0x36<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_55                     ((uint32_t)0x37<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_56                     ((uint32_t)0x38<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_57                     ((uint32_t)0x39<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_58                     ((uint32_t)0x3A<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_59                     ((uint32_t)0x3B<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_60                     ((uint32_t)0x3C<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_61                     ((uint32_t)0x3D<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_62                     ((uint32_t)0x3E<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_63                     ((uint32_t)0x3F<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_64	                    ((uint32_t)0x40<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_65	                    ((uint32_t)0x41<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_66	                    ((uint32_t)0x42<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_67	                    ((uint32_t)0x43<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_68	                    ((uint32_t)0x44<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_69	                    ((uint32_t)0x45<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_70	                    ((uint32_t)0x46<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_71	                    ((uint32_t)0x47<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_72	                    ((uint32_t)0x48<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_73	                    ((uint32_t)0x49<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_74	                    ((uint32_t)0x4A<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_75	                    ((uint32_t)0x4B<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_76	                    ((uint32_t)0x4C<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_77	                    ((uint32_t)0x4D<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_78	                    ((uint32_t)0x4E<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_79	                    ((uint32_t)0x4F<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_80	                    ((uint32_t)0x50<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_81	                    ((uint32_t)0x51<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_82	                    ((uint32_t)0x52<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_83	                    ((uint32_t)0x53<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_84	                    ((uint32_t)0x54<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_85	                    ((uint32_t)0x55<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_86	                    ((uint32_t)0x56<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_87	                    ((uint32_t)0x57<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_88	                    ((uint32_t)0x58<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_89	                    ((uint32_t)0x59<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_90	                    ((uint32_t)0x5A<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_91	                    ((uint32_t)0x5B<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_92	                    ((uint32_t)0x5C<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_93	                    ((uint32_t)0x5D<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_94	                    ((uint32_t)0x5E<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_95	                    ((uint32_t)0x5F<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_96	                    ((uint32_t)0x60<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_97	                    ((uint32_t)0x61<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_98	                    ((uint32_t)0x62<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_99	                    ((uint32_t)0x63<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_100	                ((uint32_t)0x64<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_101	                ((uint32_t)0x65<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_102	                ((uint32_t)0x66<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_103	                ((uint32_t)0x67<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_104	                ((uint32_t)0x68<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_105	                ((uint32_t)0x69<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_106	                ((uint32_t)0x6A<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_107	                ((uint32_t)0x6B<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_108	                ((uint32_t)0x6C<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_109	                ((uint32_t)0x6D<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_110	                ((uint32_t)0x6E<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_111	                ((uint32_t)0x6F<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_112	                ((uint32_t)0x70<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_113	                ((uint32_t)0x71<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_114	                ((uint32_t)0x72<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_115	                ((uint32_t)0x73<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_116	                ((uint32_t)0x74<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_117	                ((uint32_t)0x75<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_118	                ((uint32_t)0x76<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_119	                ((uint32_t)0x77<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_120	                ((uint32_t)0x78<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_121	                ((uint32_t)0x79<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_122	                ((uint32_t)0x7A<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_123	                ((uint32_t)0x7B<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_124	                ((uint32_t)0x7C<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_125	                ((uint32_t)0x7D<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_126	                ((uint32_t)0x7E<<ADC_SCANCTL_WDCH0_POS)
#define ADC_WDCH_127	                ((uint32_t)0x7F<<ADC_SCANCTL_WDCH0_POS)

#define CHECK_ADC_WDCHANNEL(CHANNEL)    (((CHANNEL) == ADC_WDCH_0) \
                                      || ((CHANNEL) == ADC_WDCH_1) \
                                      || ((CHANNEL) == ADC_WDCH_2) \
                                      || ((CHANNEL) == ADC_WDCH_3) \
                                      || ((CHANNEL) == ADC_WDCH_4) \
                                      || ((CHANNEL) == ADC_WDCH_5) \
                                      || ((CHANNEL) == ADC_WDCH_6) \
                                      || ((CHANNEL) == ADC_WDCH_7) \
                                      || ((CHANNEL) == ADC_WDCH_8) \
                                      || ((CHANNEL) == ADC_WDCH_9) \
                                      || ((CHANNEL) == ADC_WDCH_10) \
                                      || ((CHANNEL) == ADC_WDCH_11) \
                                      || ((CHANNEL) == ADC_WDCH_12) \
                                      || ((CHANNEL) == ADC_WDCH_13) \
                                      || ((CHANNEL) == ADC_WDCH_14) \
                                      || ((CHANNEL) == ADC_WDCH_15) \
                                      || ((CHANNEL) == ADC_WDCH_16) \
                                      || ((CHANNEL) == ADC_WDCH_17) \
                                      || ((CHANNEL) == ADC_WDCH_18) \
                                      || ((CHANNEL) == ADC_WDCH_19) \
                                      || ((CHANNEL) == ADC_WDCH_20) \
                                      || ((CHANNEL) == ADC_WDCH_21) \
                                      || ((CHANNEL) == ADC_WDCH_22) \
                                      || ((CHANNEL) == ADC_WDCH_23) \
                                      || ((CHANNEL) == ADC_WDCH_24) \
                                      || ((CHANNEL) == ADC_WDCH_25) \
                                       || ((CHANNEL) == ADC_WDCH_26) \
                                       || ((CHANNEL) == ADC_WDCH_27) \
                                       || ((CHANNEL) == ADC_WDCH_28) \
                                       || ((CHANNEL) == ADC_WDCH_29) \
                                       || ((CHANNEL) == ADC_WDCH_30) \
                                       || ((CHANNEL) == ADC_WDCH_31) \
                                       || ((CHANNEL) == ADC_WDCH_32) \
                                       || ((CHANNEL) == ADC_WDCH_33) \
                                       || ((CHANNEL) == ADC_WDCH_34) \
                                       || ((CHANNEL) == ADC_WDCH_35) \
                                       || ((CHANNEL) == ADC_WDCH_36) \
                                       || ((CHANNEL) == ADC_WDCH_37) \
                                       || ((CHANNEL) == ADC_WDCH_38) \
                                       || ((CHANNEL) == ADC_WDCH_39) \
                                       || ((CHANNEL) == ADC_WDCH_40) \
                                       || ((CHANNEL) == ADC_WDCH_41) \
                                       || ((CHANNEL) == ADC_WDCH_42) \
                                       || ((CHANNEL) == ADC_WDCH_43) \
                                       || ((CHANNEL) == ADC_WDCH_44) \
                                       || ((CHANNEL) == ADC_WDCH_45) \
                                       || ((CHANNEL) == ADC_WDCH_46) \
                                       || ((CHANNEL) == ADC_WDCH_47) \
                                       || ((CHANNEL) == ADC_WDCH_48) \
                                       || ((CHANNEL) == ADC_WDCH_49) \
                                       || ((CHANNEL) == ADC_WDCH_50) \
                                       || ((CHANNEL) == ADC_WDCH_51) \
                                       || ((CHANNEL) == ADC_WDCH_52) \
                                       || ((CHANNEL) == ADC_WDCH_53) \
                                       || ((CHANNEL) == ADC_WDCH_54) \
                                       || ((CHANNEL) == ADC_WDCH_55) \
                                       || ((CHANNEL) == ADC_WDCH_56) \
                                       || ((CHANNEL) == ADC_WDCH_57) \
                                       || ((CHANNEL) == ADC_WDCH_58) \
                                       || ((CHANNEL) == ADC_WDCH_59) \
                                       || ((CHANNEL) == ADC_WDCH_60) \
                                       || ((CHANNEL) == ADC_WDCH_61) \
                                       || ((CHANNEL) == ADC_WDCH_62) \
                                       || ((CHANNEL) == ADC_WDCH_63) \
                                       || ((CHANNEL) == ADC_WDCH_64) \
                                       || ((CHANNEL) == ADC_WDCH_65) \
                                       || ((CHANNEL) == ADC_WDCH_66) \
                                       || ((CHANNEL) == ADC_WDCH_67) \
                                       || ((CHANNEL) == ADC_WDCH_68) \
                                       || ((CHANNEL) == ADC_WDCH_69) \
                                       || ((CHANNEL) == ADC_WDCH_70) \
                                       || ((CHANNEL) == ADC_WDCH_71) \
                                       || ((CHANNEL) == ADC_WDCH_72) \
                                       || ((CHANNEL) == ADC_WDCH_73) \
                                       || ((CHANNEL) == ADC_WDCH_74) \
                                       || ((CHANNEL) == ADC_WDCH_75) \
                                       || ((CHANNEL) == ADC_WDCH_76) \
                                       || ((CHANNEL) == ADC_WDCH_77) \
                                       || ((CHANNEL) == ADC_WDCH_78) \
                                       || ((CHANNEL) == ADC_WDCH_79) \
                                       || ((CHANNEL) == ADC_WDCH_80) \
                                       || ((CHANNEL) == ADC_WDCH_81) \
                                       || ((CHANNEL) == ADC_WDCH_82) \
                                       || ((CHANNEL) == ADC_WDCH_83) \
                                       || ((CHANNEL) == ADC_WDCH_84) \
                                       || ((CHANNEL) == ADC_WDCH_85) \
                                       || ((CHANNEL) == ADC_WDCH_86) \
                                       || ((CHANNEL) == ADC_WDCH_87) \
                                       || ((CHANNEL) == ADC_WDCH_88) \
                                       || ((CHANNEL) == ADC_WDCH_89) \
                                       || ((CHANNEL) == ADC_WDCH_90) \
                                       || ((CHANNEL) == ADC_WDCH_91) \
                                       || ((CHANNEL) == ADC_WDCH_92) \
                                       || ((CHANNEL) == ADC_WDCH_93) \
                                       || ((CHANNEL) == ADC_WDCH_94) \
                                       || ((CHANNEL) == ADC_WDCH_95) \
                                       || ((CHANNEL) == ADC_WDCH_96) \
                                       || ((CHANNEL) == ADC_WDCH_97) \
                                       || ((CHANNEL) == ADC_WDCH_98) \
                                       || ((CHANNEL) == ADC_WDCH_99) \
                                       || ((CHANNEL) == ADC_WDCH_100) \
                                       || ((CHANNEL) == ADC_WDCH_101) \
                                       || ((CHANNEL) == ADC_WDCH_102) \
                                       || ((CHANNEL) == ADC_WDCH_103) \
                                       || ((CHANNEL) == ADC_WDCH_104) \
                                       || ((CHANNEL) == ADC_WDCH_105) \
                                       || ((CHANNEL) == ADC_WDCH_106) \
                                       || ((CHANNEL) == ADC_WDCH_107) \
                                       || ((CHANNEL) == ADC_WDCH_108) \
                                       || ((CHANNEL) == ADC_WDCH_109) \
                                       || ((CHANNEL) == ADC_WDCH_110) \
                                       || ((CHANNEL) == ADC_WDCH_111) \
                                       || ((CHANNEL) == ADC_WDCH_112) \
                                       || ((CHANNEL) == ADC_WDCH_113) \
                                       || ((CHANNEL) == ADC_WDCH_114) \
                                       || ((CHANNEL) == ADC_WDCH_115) \
                                       || ((CHANNEL) == ADC_WDCH_116) \
                                       || ((CHANNEL) == ADC_WDCH_117) \
                                       || ((CHANNEL) == ADC_WDCH_118) \
                                       || ((CHANNEL) == ADC_WDCH_119) \
                                       || ((CHANNEL) == ADC_WDCH_120) \
                                       || ((CHANNEL) == ADC_WDCH_121) \
                                       || ((CHANNEL) == ADC_WDCH_122) \
                                       || ((CHANNEL) == ADC_WDCH_123) \
                                       || ((CHANNEL) == ADC_WDCH_124) \
                                       || ((CHANNEL) == ADC_WDCH_125) \
                                       || ((CHANNEL) == ADC_WDCH_126) \
                                       || ((CHANNEL) == ADC_WDCH_127))

/**
 * ADC额外采样时间
 * */
#define ADC_EXTRA_TIME0					((uint32_t)0)
#define ADC_EXTRA_TIME1					((uint32_t)1)
#define ADC_EXTRA_TIME2					((uint32_t)2)
#define ADC_EXTRA_TIME4					((uint32_t)3)
#define ADC_EXTRA_TIME8					((uint32_t)4)
#define ADC_EXTRA_TIME16				((uint32_t)5)
#define ADC_EXTRA_TIME32				((uint32_t)6)
#define ADC_EXTRA_TIME64				((uint32_t)7)
#define ADC_EXTRA_TIME128				((uint32_t)8)
#define ADC_EXTRA_TIME256				((uint32_t)9)
#define ADC_EXTRA_TIME512				((uint32_t)10)
#define CHECK_ADC_ADC_EXTRA_TIME(TIME)	((TIME) <= ADC_EXTRA_TIME512)

/**
  * ADC通道编号
  */
#define ADC_CHANNEL_0                   ((uint32_t)0x00000000)
#define ADC_CHANNEL_1                   ((uint32_t)0x00000001)
#define ADC_CHANNEL_2                   ((uint32_t)0x00000002)
#define ADC_CHANNEL_3                   ((uint32_t)0x00000003)
#define ADC_CHANNEL_4                   ((uint32_t)0x00000004)
#define ADC_CHANNEL_5                   ((uint32_t)0x00000005)
#define ADC_CHANNEL_6                   ((uint32_t)0x00000006)
#define ADC_CHANNEL_7                   ((uint32_t)0x00000007)
#define ADC_CHANNEL_8                   ((uint32_t)0x00000008)
#define ADC_CHANNEL_9                   ((uint32_t)0x00000009)
#define ADC_CHANNEL_10                  ((uint32_t)0x0000000A)
#define ADC_CHANNEL_11                  ((uint32_t)0x0000000B)
#define ADC_CHANNEL_12                  ((uint32_t)0x0000000C)
#define ADC_CHANNEL_13                  ((uint32_t)0x0000000D)
#define ADC_CHANNEL_14                  ((uint32_t)0x0000000E)
#define ADC_CHANNEL_15                  ((uint32_t)0x0000000F)
#define ADC_CHANNEL_16                  ((uint32_t)0x00000010)
#define ADC_CHANNEL_17                  ((uint32_t)0x00000011)
#define ADC_CHANNEL_18                  ((uint32_t)0x00000012)
#define ADC_CHANNEL_19                  ((uint32_t)0x00000013)
#define ADC_CHANNEL_20                  ((uint32_t)0x00000014)
#define ADC_CHANNEL_21                  ((uint32_t)0x00000015)
#define ADC_CHANNEL_22                  ((uint32_t)0x00000016)
#define ADC_CHANNEL_23                  ((uint32_t)0x00000017)
#define ADC_CHANNEL_24                  ((uint32_t)0x00000018)
#define ADC_CHANNEL_25                  ((uint32_t)0x00000019)
#define ADC_CHANNEL_26                  ((uint32_t)0x0000001A)
#define ADC_CHANNEL_27                  ((uint32_t)0x0000001B)
#define ADC_CHANNEL_28                  ((uint32_t)0x0000001C)
#define ADC_CHANNEL_29                  ((uint32_t)0x0000001D)
#define ADC_CHANNEL_30                  ((uint32_t)0x0000001E)
#define ADC_CHANNEL_31                  ((uint32_t)0x0000001F)
#define ADC_CHANNEL_32                  ((uint32_t)0x00000020)
#define ADC_CHANNEL_33                  ((uint32_t)0x00000021)
#define ADC_CHANNEL_34                  ((uint32_t)0x00000022)
#define ADC_CHANNEL_35                  ((uint32_t)0x00000023)
#define ADC_CHANNEL_36                  ((uint32_t)0x00000024)
#define ADC_CHANNEL_37                  ((uint32_t)0x00000025)
#define ADC_CHANNEL_38                  ((uint32_t)0x00000026)
#define ADC_CHANNEL_39                  ((uint32_t)0x00000027)
#define ADC_CHANNEL_40                  ((uint32_t)0x00000028)
#define ADC_CHANNEL_41                  ((uint32_t)0x00000029)
#define ADC_CHANNEL_42                  ((uint32_t)0x0000002A)
#define ADC_CHANNEL_43                  ((uint32_t)0x0000002B)
#define ADC_CHANNEL_44                  ((uint32_t)0x0000002C)
#define ADC_CHANNEL_45                  ((uint32_t)0x0000002D)
#define ADC_CHANNEL_46                  ((uint32_t)0x0000002E)
#define ADC_CHANNEL_47                  ((uint32_t)0x0000002F)
#define ADC_CHANNEL_48                  ((uint32_t)0x00000030)
#define ADC_CHANNEL_49                  ((uint32_t)0x00000031)
#define ADC_CHANNEL_50                  ((uint32_t)0x00000032)
#define ADC_CHANNEL_51                  ((uint32_t)0x00000033)
#define ADC_CHANNEL_52                  ((uint32_t)0x00000034)
#define ADC_CHANNEL_53                  ((uint32_t)0x00000035)
#define ADC_CHANNEL_54                  ((uint32_t)0x00000036)
#define ADC_CHANNEL_55                  ((uint32_t)0x00000037)
#define ADC_CHANNEL_56                  ((uint32_t)0x00000038)
#define ADC_CHANNEL_57                  ((uint32_t)0x00000039)
#define ADC_CHANNEL_58                  ((uint32_t)0x0000003A)
#define ADC_CHANNEL_59                  ((uint32_t)0x0000003B)
#define ADC_CHANNEL_60                  ((uint32_t)0x0000003C)
#define ADC_CHANNEL_61                  ((uint32_t)0x0000003D)
#define ADC_CHANNEL_62                  ((uint32_t)0x0000003E)
#define ADC_CHANNEL_63                  ((uint32_t)0x0000003F)
#define ADC_CHANNEL_64                 	((uint32_t)0x00000040)
#define ADC_CHANNEL_65                 	((uint32_t)0x00000041)
#define ADC_CHANNEL_66                 	((uint32_t)0x00000042)
#define ADC_CHANNEL_67                 	((uint32_t)0x00000043)
#define ADC_CHANNEL_68                 	((uint32_t)0x00000044)
#define ADC_CHANNEL_69                 	((uint32_t)0x00000045)
#define ADC_CHANNEL_70                 	((uint32_t)0x00000046)
#define ADC_CHANNEL_71                 	((uint32_t)0x00000047)
#define ADC_CHANNEL_72                 	((uint32_t)0x00000048)
#define ADC_CHANNEL_73                 	((uint32_t)0x00000049)
#define ADC_CHANNEL_74                 	((uint32_t)0x0000004A)
#define ADC_CHANNEL_75                 	((uint32_t)0x0000004B)
#define ADC_CHANNEL_76                 	((uint32_t)0x0000004C)
#define ADC_CHANNEL_77                 	((uint32_t)0x0000004D)
#define ADC_CHANNEL_78                 	((uint32_t)0x0000004E)
#define ADC_CHANNEL_79                 	((uint32_t)0x0000004F)
#define ADC_CHANNEL_80                 	((uint32_t)0x00000050)
#define ADC_CHANNEL_81                 	((uint32_t)0x00000051)
#define ADC_CHANNEL_82                 	((uint32_t)0x00000052)
#define ADC_CHANNEL_83                 	((uint32_t)0x00000053)
#define ADC_CHANNEL_84                 	((uint32_t)0x00000054)
#define ADC_CHANNEL_85                 	((uint32_t)0x00000055)
#define ADC_CHANNEL_86                 	((uint32_t)0x00000056)
#define ADC_CHANNEL_87                 	((uint32_t)0x00000057)
#define ADC_CHANNEL_88                 	((uint32_t)0x00000058)
#define ADC_CHANNEL_89                 	((uint32_t)0x00000059)
#define ADC_CHANNEL_90                 	((uint32_t)0x0000005A)
#define ADC_CHANNEL_91                 	((uint32_t)0x0000005B)
#define ADC_CHANNEL_92                 	((uint32_t)0x0000005C)
#define ADC_CHANNEL_93                 	((uint32_t)0x0000005D)
#define ADC_CHANNEL_94                 	((uint32_t)0x0000005E)
#define ADC_CHANNEL_95                 	((uint32_t)0x0000005F)
#define ADC_CHANNEL_96                 	((uint32_t)0x00000060)
#define ADC_CHANNEL_97                 	((uint32_t)0x00000061)
#define ADC_CHANNEL_98                 	((uint32_t)0x00000062)
#define ADC_CHANNEL_99                 	((uint32_t)0x00000063)
#define ADC_CHANNEL_100                 ((uint32_t)0x00000064)
#define ADC_CHANNEL_101                 ((uint32_t)0x00000065)
#define ADC_CHANNEL_102                 ((uint32_t)0x00000066)
#define ADC_CHANNEL_103                 ((uint32_t)0x00000067)
#define ADC_CHANNEL_104                 ((uint32_t)0x00000068)
#define ADC_CHANNEL_105                 ((uint32_t)0x00000069)
#define ADC_CHANNEL_106                 ((uint32_t)0x0000006A)
#define ADC_CHANNEL_107                 ((uint32_t)0x0000006B)
#define ADC_CHANNEL_108                 ((uint32_t)0x0000006C)
#define ADC_CHANNEL_109                 ((uint32_t)0x0000006D)
#define ADC_CHANNEL_110                 ((uint32_t)0x0000006E)
#define ADC_CHANNEL_111                 ((uint32_t)0x0000006F)
#define ADC_CHANNEL_112                 ((uint32_t)0x00000070)
#define ADC_CHANNEL_113                 ((uint32_t)0x00000071)
#define ADC_CHANNEL_114                 ((uint32_t)0x00000072)
#define ADC_CHANNEL_115                 ((uint32_t)0x00000073)
#define ADC_CHANNEL_116                 ((uint32_t)0x00000074)
#define ADC_CHANNEL_117                 ((uint32_t)0x00000075)
#define ADC_CHANNEL_118                 ((uint32_t)0x00000076)
#define ADC_CHANNEL_119                 ((uint32_t)0x00000077)
#define ADC_CHANNEL_120                 ((uint32_t)0x00000078)
#define ADC_CHANNEL_121                 ((uint32_t)0x00000079)
#define ADC_CHANNEL_122                 ((uint32_t)0x0000007A)
#define ADC_CHANNEL_123                 ((uint32_t)0x0000007B)
#define ADC_CHANNEL_124                 ((uint32_t)0x0000007C)
#define ADC_CHANNEL_125                 ((uint32_t)0x0000007D)
#define ADC_CHANNEL_126                 ((uint32_t)0x0000007E)
#define ADC_CHANNEL_127                 ((uint32_t)0x0000007F)

//#define ADC_CHANNEL_TEMPSENSOR          ADC_CHANNEL_52
//#define ADC_CHANNEL_VREFINT             ADC_CHANNEL_53
#define CHECK_ADC_CHANNEL(CHANNEL)      (((CHANNEL) == ADC_CHANNEL_0) \
                                      || ((CHANNEL) == ADC_CHANNEL_1) \
                                      || ((CHANNEL) == ADC_CHANNEL_2) \
                                      || ((CHANNEL) == ADC_CHANNEL_3) \
                                      || ((CHANNEL) == ADC_CHANNEL_4) \
                                      || ((CHANNEL) == ADC_CHANNEL_5) \
                                      || ((CHANNEL) == ADC_CHANNEL_6) \
                                      || ((CHANNEL) == ADC_CHANNEL_7) \
                                      || ((CHANNEL) == ADC_CHANNEL_8) \
                                      || ((CHANNEL) == ADC_CHANNEL_9) \
                                      || ((CHANNEL) == ADC_CHANNEL_10) \
                                      || ((CHANNEL) == ADC_CHANNEL_11) \
                                      || ((CHANNEL) == ADC_CHANNEL_12) \
                                      || ((CHANNEL) == ADC_CHANNEL_13) \
                                      || ((CHANNEL) == ADC_CHANNEL_14) \
                                      || ((CHANNEL) == ADC_CHANNEL_15) \
                                      || ((CHANNEL) == ADC_CHANNEL_16) \
                                      || ((CHANNEL) == ADC_CHANNEL_17) \
                                      || ((CHANNEL) == ADC_CHANNEL_18) \
                                      || ((CHANNEL) == ADC_CHANNEL_19) \
                                      || ((CHANNEL) == ADC_CHANNEL_20) \
                                      || ((CHANNEL) == ADC_CHANNEL_21) \
                                      || ((CHANNEL) == ADC_CHANNEL_22) \
                                      || ((CHANNEL) == ADC_CHANNEL_23) \
                                      || ((CHANNEL) == ADC_CHANNEL_24) \
                                      || ((CHANNEL) == ADC_CHANNEL_25) \
                                      || ((CHANNEL) == ADC_CHANNEL_26) \
                                      || ((CHANNEL) == ADC_CHANNEL_27) \
                                      || ((CHANNEL) == ADC_CHANNEL_28) \
                                      || ((CHANNEL) == ADC_CHANNEL_29) \
                                      || ((CHANNEL) == ADC_CHANNEL_30) \
                                      || ((CHANNEL) == ADC_CHANNEL_31) \
                                      || ((CHANNEL) == ADC_CHANNEL_32) \
                                      || ((CHANNEL) == ADC_CHANNEL_33) \
                                      || ((CHANNEL) == ADC_CHANNEL_34) \
                                      || ((CHANNEL) == ADC_CHANNEL_35) \
                                      || ((CHANNEL) == ADC_CHANNEL_36) \
                                      || ((CHANNEL) == ADC_CHANNEL_37) \
                                      || ((CHANNEL) == ADC_CHANNEL_38) \
                                      || ((CHANNEL) == ADC_CHANNEL_39) \
                                      || ((CHANNEL) == ADC_CHANNEL_40) \
                                      || ((CHANNEL) == ADC_CHANNEL_41) \
                                      || ((CHANNEL) == ADC_CHANNEL_42) \
                                      || ((CHANNEL) == ADC_CHANNEL_43) \
                                      || ((CHANNEL) == ADC_CHANNEL_44) \
                                      || ((CHANNEL) == ADC_CHANNEL_45) \
                                      || ((CHANNEL) == ADC_CHANNEL_46) \
                                      || ((CHANNEL) == ADC_CHANNEL_47) \
                                      || ((CHANNEL) == ADC_CHANNEL_48) \
                                      || ((CHANNEL) == ADC_CHANNEL_49) \
                                      || ((CHANNEL) == ADC_CHANNEL_50) \
                                      || ((CHANNEL) == ADC_CHANNEL_51) \
                                      || ((CHANNEL) == ADC_CHANNEL_52) \
                                      || ((CHANNEL) == ADC_CHANNEL_53) \
                                      || ((CHANNEL) == ADC_CHANNEL_54) \
                                      || ((CHANNEL) == ADC_CHANNEL_55) \
                                      || ((CHANNEL) == ADC_CHANNEL_56) \
                                      || ((CHANNEL) == ADC_CHANNEL_57) \
                                      || ((CHANNEL) == ADC_CHANNEL_58) \
                                      || ((CHANNEL) == ADC_CHANNEL_59) \
                                      || ((CHANNEL) == ADC_CHANNEL_60) \
                                      || ((CHANNEL) == ADC_CHANNEL_61) \
                                      || ((CHANNEL) == ADC_CHANNEL_62) \
                                      || ((CHANNEL) == ADC_CHANNEL_63) \
                                      || ((CHANNEL) == ADC_CHANNEL_64) \
                                      || ((CHANNEL) == ADC_CHANNEL_65) \
                                      || ((CHANNEL) == ADC_CHANNEL_66) \
                                      || ((CHANNEL) == ADC_CHANNEL_67) \
                                      || ((CHANNEL) == ADC_CHANNEL_68) \
                                      || ((CHANNEL) == ADC_CHANNEL_69) \
                                      || ((CHANNEL) == ADC_CHANNEL_70) \
                                      || ((CHANNEL) == ADC_CHANNEL_71) \
                                      || ((CHANNEL) == ADC_CHANNEL_72) \
                                      || ((CHANNEL) == ADC_CHANNEL_73) \
                                      || ((CHANNEL) == ADC_CHANNEL_74) \
                                      || ((CHANNEL) == ADC_CHANNEL_75) \
                                      || ((CHANNEL) == ADC_CHANNEL_76) \
                                      || ((CHANNEL) == ADC_CHANNEL_77) \
                                      || ((CHANNEL) == ADC_CHANNEL_78) \
                                      || ((CHANNEL) == ADC_CHANNEL_79) \
                                      || ((CHANNEL) == ADC_CHANNEL_80) \
                                      || ((CHANNEL) == ADC_CHANNEL_81) \
                                      || ((CHANNEL) == ADC_CHANNEL_82) \
                                      || ((CHANNEL) == ADC_CHANNEL_83) \
                                      || ((CHANNEL) == ADC_CHANNEL_84) \
                                      || ((CHANNEL) == ADC_CHANNEL_85) \
                                      || ((CHANNEL) == ADC_CHANNEL_86) \
                                      || ((CHANNEL) == ADC_CHANNEL_87) \
                                      || ((CHANNEL) == ADC_CHANNEL_88) \
                                      || ((CHANNEL) == ADC_CHANNEL_89) \
                                      || ((CHANNEL) == ADC_CHANNEL_90) \
                                      || ((CHANNEL) == ADC_CHANNEL_91) \
                                      || ((CHANNEL) == ADC_CHANNEL_92) \
                                      || ((CHANNEL) == ADC_CHANNEL_93) \
                                      || ((CHANNEL) == ADC_CHANNEL_94) \
                                      || ((CHANNEL) == ADC_CHANNEL_95) \
                                      || ((CHANNEL) == ADC_CHANNEL_96) \
                                      || ((CHANNEL) == ADC_CHANNEL_97) \
                                      || ((CHANNEL) == ADC_CHANNEL_98) \
                                      || ((CHANNEL) == ADC_CHANNEL_99) \
                                      || ((CHANNEL) == ADC_CHANNEL_100) \
                                      || ((CHANNEL) == ADC_CHANNEL_101) \
                                      || ((CHANNEL) == ADC_CHANNEL_102) \
                                      || ((CHANNEL) == ADC_CHANNEL_103) \
                                      || ((CHANNEL) == ADC_CHANNEL_104) \
                                      || ((CHANNEL) == ADC_CHANNEL_105) \
                                      || ((CHANNEL) == ADC_CHANNEL_106) \
                                      || ((CHANNEL) == ADC_CHANNEL_107) \
                                      || ((CHANNEL) == ADC_CHANNEL_108) \
                                      || ((CHANNEL) == ADC_CHANNEL_109) \
                                      || ((CHANNEL) == ADC_CHANNEL_110) \
                                      || ((CHANNEL) == ADC_CHANNEL_111) \
                                      || ((CHANNEL) == ADC_CHANNEL_112) \
                                      || ((CHANNEL) == ADC_CHANNEL_113) \
                                      || ((CHANNEL) == ADC_CHANNEL_114) \
                                      || ((CHANNEL) == ADC_CHANNEL_115) \
                                      || ((CHANNEL) == ADC_CHANNEL_116) \
                                      || ((CHANNEL) == ADC_CHANNEL_117) \
                                      || ((CHANNEL) == ADC_CHANNEL_118) \
                                      || ((CHANNEL) == ADC_CHANNEL_119) \
                                      || ((CHANNEL) == ADC_CHANNEL_120) \
                                      || ((CHANNEL) == ADC_CHANNEL_121) \
                                      || ((CHANNEL) == ADC_CHANNEL_122) \
                                      || ((CHANNEL) == ADC_CHANNEL_123) \
                                      || ((CHANNEL) == ADC_CHANNEL_124) \
                                      || ((CHANNEL) == ADC_CHANNEL_125) \
                                      || ((CHANNEL) == ADC_CHANNEL_126) \
                                      || ((CHANNEL) == ADC_CHANNEL_127))
#define CHECK_ADC_HP_CHANNEL(CHANNEL)   CHECK_ADC_CHANNEL(CHANNEL)

/**
  * ADC_HPDOFFy寄存器偏移地址
  */
#define ADC_HPDOFF_0                    ((uint8_t)0x34)
#define ADC_HPDOFF_1                    ((uint8_t)0x38)
#define ADC_HPDOFF_2                    ((uint8_t)0x3C)
#define ADC_HPDOFF_3                    ((uint8_t)0x40)
#define CHECK_ADC_HPDOFF_OFFSET(OFFSET) (((OFFSET) == ADC_HPDOFF_0) \
                                      || ((OFFSET) == ADC_HPDOFF_1) \
                                      || ((OFFSET) == ADC_HPDOFF_2) \
                                      || ((OFFSET) == ADC_HPDOFF_3))

#define ADC_HPCH0                    ((uint32_t)0x00400000)
#define ADC_HPCH1                    ((uint32_t)0x00800000)
#define ADC_HPCH2                    ((uint32_t)0x01000000)
#define ADC_HPCH3                    ((uint32_t)0x02000000)
#define CHECK_ADC_HPCH(SELECT) (((SELECT) == ADC_HPCH0) \
                                      || ((SELECT) == ADC_HPCH1) \
                                      || ((SELECT) == ADC_HPCH2) \
                                      || ((SELECT) == ADC_HPCH3))


/**
  * ADC_HPDATAy寄存器偏移地址
  */
#define ADC_HPDATA_0                    ((uint8_t)0x24)
#define ADC_HPDATA_1                    ((uint8_t)0x28)
#define ADC_HPDATA_2                    ((uint8_t)0x2C)
#define ADC_HPDATA_3                    ((uint8_t)0x30)
#define CHECK_ADC_HPDATA_OFFSET(OFFSET) (((OFFSET) == ADC_HPDATA_0) \
                                      || ((OFFSET) == ADC_HPDATA_1) \
                                      || ((OFFSET) == ADC_HPDATA_2) \
                                      || ((OFFSET) == ADC_HPDATA_3))

/**
 *  ADC_HPCHy
 * */
#define ADC_HPCH_0						((uint32_t)0)
#define ADC_HPCH_1						((uint32_t)1)
#define ADC_HPCH_2						((uint32_t)2)
#define ADC_HPCH_3						((uint32_t)3)
#define CHECK_ADC_HPCHX(CHANNEL)			((CHANNEL) <= 0x03)

/**
  * ADC中断事件管理 0x00_IC_IF_IE
  */
#define ADC_INT_EOC                     ((uint32_t)0x000C0B0D)
#define ADC_INT_AWD                     ((uint32_t)0x0007040A)
#define ADC_INT_HPEND                   ((uint32_t)0x00060309)
#define ADC_INT_END                     ((uint32_t)0x00050208)
#define CHECK_ADC_INT(INT)              (((INT) == ADC_INT_EOC) \
                                      || ((INT) == ADC_INT_AWD) \
                                      || ((INT) == ADC_INT_HPEND) \
                                      || ((INT) == ADC_INT_END))

/**
  * ADC高优先级通道转换结果数据偏移
  */
#define CHECK_ADC_OFFSET(OFFSET)        ((uint32_t)(OFFSET) <= 0xFFF)

/**
  * 常规通道扫描的转换个数
  */
#define CHECK_ADC_REGULAR_RANK(RANK)    (((RANK) - 1) < 16)

/**
  * 高优先级通道扫描的转换个数
  */
#define CHECK_ADC_HP_RANK(RANK)         (((RANK) >= 0x1) && ((RANK) <= 0x4))

/**
  * ADC模拟看门狗单通道使能
  */
#define ADC_WD_ALL_CH                   ((uint32_t)0<<ADC_CTL0_WDSCH_POS)
#define ADC_WD_SINGLE_CH                ((uint32_t)1<<ADC_CTL0_WDSCH_POS)
#define CHECK_ADC_WDSCH(EN)             (((EN) == ADC_WD_SINGLE_CH) \
                                      || ((EN) == ADC_WD_ALL_CH))

/**
  * ADC快慢交叉延时时间
  */
#define CHECK_ADC_FDELAY_MODE(MODE)     (((MODE) - 1) < 64)
#define CHECK_ADC_SDELAY_MODE(MODE)     (((MODE) - 1) < 64)

/**
  * ADC转换结果对齐格式
  */
#define ADC_DATAALIGN_LEFT              ((uint32_t)0<<ADC_CTL0_LR_POS)
#define ADC_DATAALIGN_RIGHT             ((uint32_t)1<<ADC_CTL0_LR_POS)
#define CHECK_ADC_DATA_ALIGN(ALIGN)     (((ALIGN) == ADC_DATAALIGN_RIGHT) \
                                      || ((ALIGN) == ADC_DATAALIGN_LEFT))

/**
  * ADC连续转换
  */
#define ADC_SINGLE_MODE                 ((uint32_t)0<<ADC_CTL0_CONT_POS)
#define ADC_CONTINUOUS_MODE             ((uint32_t)1<<ADC_CTL0_CONT_POS)
#define CHECK_ADC_CONV_MODE(MODE)       (((MODE) == ADC_CONTINUOUS_MODE) \
                                      || ((MODE) == ADC_SINGLE_MODE))

/**
  * ADC常规通道扫描长度
  */
#define CHECK_ADC_REGULAR_LENGTH(LENGTH) (((LENGTH) >= 0x1) \
                                       && ((LENGTH) <= 0x10))
/**
  * ADC高优先级通道扫描长度
  */
#define CHECK_ADC_HIGH_PRIORITY_LENGTH(LENGTH) (((LENGTH) >= 0x1) \
                                             && ((LENGTH) <= 0x4))

/**
  * ADC间隔模式通道计数
  */
#define CHECK_ADC_REGULAR_DISC_NUMBER(NUMBER) (((NUMBER) >= 0x1) \
                                            && ((NUMBER) <= 0x8))

/**
  * 双ADC模式
  */
#define ADC_SINGLE                      ((uint32_t)0<<ADC_CTL1_DOUMOD0_POS)
#define ADC_REGULAR_HPRIORITY           ((uint32_t)1<<ADC_CTL1_DOUMOD0_POS)
#define ADC_REGULAR_ALTERNATELY         ((uint32_t)2<<ADC_CTL1_DOUMOD0_POS)
#define ADC_HPRIORITY_FAST_ALTERNATELY  ((uint32_t)3<<ADC_CTL1_DOUMOD0_POS)
#define ADC_HPRIORITY_SYNC              ((uint32_t)4<<ADC_CTL1_DOUMOD0_POS)
#define ADC_REGULAR_SYNC                ((uint32_t)5<<ADC_CTL1_DOUMOD0_POS)
#define ADC_FAST_ALTERNATELY_SYNC       ((uint32_t)6<<ADC_CTL1_DOUMOD0_POS)
#define ADC_SLOW_ALTERNATELY_SYNC       ((uint32_t)7<<ADC_CTL1_DOUMOD0_POS)
#define ADC_ALTERNATELY_TRIGGER         ((uint32_t)8<<ADC_CTL1_DOUMOD0_POS)
#define CHECK_ADC_DOUBLE_MODE(MODE)     (((MODE) == ADC_SINGLE) \
                                      || ((MODE) == ADC_REGULAR_HPRIORITY) \
                                      || ((MODE) == ADC_REGULAR_ALTERNATELY) \
                                      || ((MODE) == ADC_HPRIORITY_FAST_ALTERNATELY) \
                                      || ((MODE) == ADC_HPRIORITY_SYNC) \
                                      || ((MODE) == ADC_REGULAR_SYNC) \
                                      || ((MODE) == ADC_FAST_ALTERNATELY_SYNC) \
                                      || ((MODE) == ADC_SLOW_ALTERNATELY_SYNC) \
                                      || ((MODE) == ADC_ALTERNATELY_TRIGGER))

/**
  * ADC高优先级通道外部触发事件TxCCRy
  */
#define ADC_HPEXTERNALTRIG_T6_CCR0      ADC_STATE_CCR2H_POS
#define ADC_HPEXTERNALTRIG_T5_CCR1      ADC_STATE_CCR1H_POS
#define ADC_HPEXTERNALTRIG_T5_CCR0      ADC_STATE_CCR0H_POS
#define CHECK_HPChannel_TxCCRy_Trig(SELECT)     (((SELECT) == ADC_STATE_CCR2H_POS) \
                                      || ((SELECT) == ADC_STATE_CCR1H_POS) \
                                      || ((SELECT) == ADC_STATE_CCR0H_POS))
/**
  * ADC常规优先级通道外部触发事件TxCCRy
  */
#define ADC_EXTERNALTRIG_T6_CCR0      ADC_STATE_CCR2N_POS
#define ADC_EXTERNALTRIG_T5_CCR1      ADC_STATE_CCR1N_POS
#define ADC_EXTERNALTRIG_T5_CCR0      ADC_STATE_CCR0N_POS
#define CHECK_RegularChannel_TxCCRy_Trig(SELECT)     (((SELECT) == ADC_STATE_CCR2N_POS) \
                                      || ((SELECT) == ADC_STATE_CCR1N_POS) \
                                      || ((SELECT) == ADC_STATE_CCR0N_POS))
/**
  * ADC高优先级通道外部触发事件
  */
#define ADC_HPEXTERNALTRIG_CCP1_CH1     ((uint32_t)0x0<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP1_CH2     ((uint32_t)0x1<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP1_CH3     ((uint32_t)0x2<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP1_CH4     ((uint32_t)0x3<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP2_CH1     ((uint32_t)0x4<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP2_CH2     ((uint32_t)0x5<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP2_CH3     ((uint32_t)0x6<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP2_CH4     ((uint32_t)0x7<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP3_CH1     ((uint32_t)0x8<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP3_CH2     ((uint32_t)0x9<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP3_CH3     ((uint32_t)0xA<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP3_CH4     ((uint32_t)0xB<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP4_CH1     ((uint32_t)0xC<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP4_CH2     ((uint32_t)0xD<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP4_CH3     ((uint32_t)0xE<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP4_CH4     ((uint32_t)0xF<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP18_CH1    ((uint32_t)0x10<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP18_CH2    ((uint32_t)0x11<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP18_CH3    ((uint32_t)0x12<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP18_CH4    ((uint32_t)0x13<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP19_CH1    ((uint32_t)0x14<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP19_CH2    ((uint32_t)0x15<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP19_CH3    ((uint32_t)0x16<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP19_CH4    ((uint32_t)0x17<<ADC_CTL1_HCH0_POS)

#define ADC_HPEXTERNALTRIG_CCP21_CH1    ((uint32_t)0x1C<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP21_CH2    ((uint32_t)0x1D<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP21_CH3    ((uint32_t)0x1E<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP21_CH4    ((uint32_t)0x1F<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP5_CH1     ((uint32_t)0x20<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP5_CH2     ((uint32_t)0x21<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP5_CH3     ((uint32_t)0x22<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP5_CH4     ((uint32_t)0x23<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_FDC0		    ((uint32_t)0x24<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_FDC1     	((uint32_t)0x25<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_FDC2     	((uint32_t)0x26<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_PLA     		((uint32_t)0x27<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T1TRGO       ((uint32_t)0x28<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T2TRGO       ((uint32_t)0x29<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T3TRGO       ((uint32_t)0x2A<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T4TRGO       ((uint32_t)0x2B<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T18TRGO      ((uint32_t)0x2C<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T19TRGO      ((uint32_t)0x2D<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T21TRGO      ((uint32_t)0x2F<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T5TRGO       ((uint32_t)0x30<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T14TRGO      ((uint32_t)0x32<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T5_OVERFLOW  ((uint32_t)0x34<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_T6_OVERFLOW  ((uint32_t)0x35<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EPWM11_AD0  	((uint32_t)0x36<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EPWM11_AD1  	((uint32_t)0x37<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EPWM12_AD0 	((uint32_t)0x38<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EPWM12_AD1    ((uint32_t)0x39<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EPWM13_AD0    ((uint32_t)0x3A<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EPWM13_AD1    ((uint32_t)0x3B<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EPWM16_AD0    ((uint32_t)0x3C<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EPWM16_AD1    ((uint32_t)0x3D<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EINT7        ((uint32_t)0x3E<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_EINT15       ((uint32_t)0x3F<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP0_CH1     ((uint32_t)0x40<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP0_CH2     ((uint32_t)0x41<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP0_CH3     ((uint32_t)0x42<<ADC_CTL1_HCH0_POS)
#define ADC_HPEXTERNALTRIG_CCP0_CH4     ((uint32_t)0x43<<ADC_CTL1_HCH0_POS)
#define CHECK_ADC_HPEXT_TRIG(REGTRIG)   ((((REGTRIG) >> ADC_CTL1_HCH0_POS) \
                                          <= 0x47) \
                                      && (((REGTRIG) << (32 - ADC_CTL1_HCH0_POS)) \
                                          == 0))

/**
  * ADC常规通道外部触发事件
  */
#define ADC_EXTERNALTRIG_CCP1_CH1       ((uint32_t)0x0<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP1_CH2       ((uint32_t)0x1<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP1_CH3       ((uint32_t)0x2<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP1_CH4       ((uint32_t)0x3<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP2_CH1       ((uint32_t)0x4<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP2_CH2       ((uint32_t)0x5<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP2_CH3       ((uint32_t)0x6<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP2_CH4       ((uint32_t)0x7<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP3_CH1       ((uint32_t)0x8<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP3_CH2       ((uint32_t)0x9<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP3_CH3       ((uint32_t)0xA<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP3_CH4       ((uint32_t)0xB<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP4_CH1       ((uint32_t)0xC<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP4_CH2       ((uint32_t)0xD<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP4_CH3       ((uint32_t)0xE<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP4_CH4       ((uint32_t)0xF<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP18_CH1      ((uint32_t)0x10<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP18_CH2      ((uint32_t)0x11<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP18_CH3      ((uint32_t)0x12<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP18_CH4      ((uint32_t)0x13<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP19_CH1      ((uint32_t)0x14<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP19_CH2      ((uint32_t)0x15<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP19_CH3      ((uint32_t)0x16<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP19_CH4      ((uint32_t)0x17<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP21_CH1      ((uint32_t)0x1C<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP21_CH2      ((uint32_t)0x1D<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP21_CH3      ((uint32_t)0x1E<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP21_CH4      ((uint32_t)0x1F<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP5_CH1       ((uint32_t)0x20<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP5_CH2       ((uint32_t)0x21<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP5_CH3       ((uint32_t)0x22<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP5_CH4       ((uint32_t)0x23<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_FDC0      		((uint32_t)0x24<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_FDC1      		((uint32_t)0x25<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_FDC2	   	    ((uint32_t)0x26<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_PLA	    	((uint32_t)0x27<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T1TRGO         ((uint32_t)0x28<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T2TRGO         ((uint32_t)0x29<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T3TRGO         ((uint32_t)0x2A<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T4TRGO         ((uint32_t)0x2B<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T18TRGO        ((uint32_t)0x2C<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T19TRGO        ((uint32_t)0x2D<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T21TRGO        ((uint32_t)0x2F<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T5TRGO         ((uint32_t)0x30<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T14TRGO        ((uint32_t)0x32<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T5_OVERFLOW    ((uint32_t)0x34<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_T6_OVERFLOW    ((uint32_t)0x35<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EPWM11_AD0    	((uint32_t)0x36<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EPWM11_AD1    	((uint32_t)0x37<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EPWM12_AD0    	((uint32_t)0x38<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EPWM12_AD1   	((uint32_t)0x39<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EPWM13_AD0     ((uint32_t)0x3A<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EPWM13_AD1     ((uint32_t)0x3B<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EPWM16_AD0     ((uint32_t)0x3C<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EPWM16_AD1     ((uint32_t)0x3D<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EINT7          ((uint32_t)0x3E<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_EINT15         ((uint32_t)0x3F<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP0_CH1       ((uint32_t)0x40<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP0_CH2       ((uint32_t)0x41<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP0_CH3       ((uint32_t)0x42<<ADC_CTL1_NCH0_POS)
#define ADC_EXTERNALTRIG_CCP0_CH4       ((uint32_t)0x43<<ADC_CTL1_NCH0_POS)
#define CHECK_ADC_EXT_TRIG(REGTRIG)     ((((REGTRIG) >> ADC_CTL1_NCH0_POS) \
                                          <= 0x47) \
                                      && (((REGTRIG) << (32 - ADC_CTL1_NCH0_POS)) \
                                          == 0))

/**
 * 	ADC高优先级数据失调寄存器
 * */
#define CHECK_ADC_DISORDER(VALUE)		((VALUE) <= 0xFFF)


/* 模数转换模块(ADC)初始化函数定义******************************************/
void ADC_Reset (ADC_SFRmap* ADCx);
void ADC_Configuration (ADC_SFRmap* ADCx, ADC_InitTypeDef* adcInitStruct);
void ADC_Delay_Configuration (ADC0_DELAY_InitTypeDef* adc0Delay);
void ADC_Delay_Struct_Init (ADC0_DELAY_InitTypeDef* adc0Delay);
void ADC_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
/* 模数转换模块(ADC)模拟看门狗初始化函数定义********************************/
void ADC_Analog_Watchdog_Configuration (ADC_SFRmap* ADCx,ADC_WD_InitTypeDef * adcAnalogWatchdog);
void ADC_Analog_Watchdog_Struct_Init (ADC_WD_InitTypeDef* adcAnalogWatchdog);
/* 模数转换模块(ADC)控制功能配置函数定义************************************/
void ADC_Watchdog_Single_Channel_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_Scan_Mode_Enable (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_Bosssel_Comparator_Calibration (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_Bosssel_Calibration (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_Trim_Current_Intensity_Bias (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_Analog_Clock_Config (ADC_SFRmap* ADCx, uint32_t ClockSelect);
void ADC_Data_Align_Config (ADC_SFRmap* ADCx, uint32_t DataAlign);
void ADC_Clock_Source_Config (ADC_SFRmap* ADCx, uint32_t ClockSource);
void ADC_Regular_Channel_DMA_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_High_Priority_Channel_DMA_Cmd (ADC_SFRmap* ADCx,uint32_t HPChannel,FunctionalState NewState);
void ADC_Double_Mode_Config (uint32_t WorkMode);
void ADC_Reference_Voltage_Config (ADC_SFRmap* ADCx, uint32_t RefVoltage);
void ADC_Analog_Watchdog_Channel_Config (ADC_SFRmap* ADCx, uint32_t Channel);
void ADC_Extra_Sampling_Time(ADC_SFRmap* ADCx, uint32_t ExTime);
/* 模数转换模块(ADC)常规通道功能配置函数定义********************************/
void ADC_Regular_Channel_Watchdog_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_External_Trig_Conv_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_External_Trig_Conv_Config (ADC_SFRmap* ADCx,uint32_t ExternalTrigEvent);
void ADC_Regular_Channel_Config (ADC_SFRmap* ADCx,uint32_t Channel, uint32_t Rank);
void ADC_Regular_Sequencer_Length_Config (ADC_SFRmap* ADCx, uint32_t Length);
void ADC_Regular_Channel_TxCCRy_Trig_Enable (ADC_SFRmap* ADCx,uint32_t ExternalTrigEvent, FunctionalState NewState);
void ADC_Software_Start_Conv(ADC_SFRmap* ADCx);
void ADC_Continuous_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_Disc_Mode_Channel_Count_Config (ADC_SFRmap* ADCx, uint8_t Number);
void ADC_Disc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
uint16_t ADC_Get_Conversion_Value (ADC_SFRmap* ADCx);
/* 模数转换模块(ADC)高优先级通道功能配置函数定义****************************/
void ADC_High_Priority_Watchdog_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_HPExternal_Trig_Conv_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_High_Priority_Channel_Config (ADC_SFRmap* ADCx,uint32_t Channel, uint32_t Rank);
void ADC_High_Priority_Sequencer_Length_Config (ADC_SFRmap* ADCx,uint32_t Length);
void ADC_High_Priority_TxCCRy_Trig_Enable (ADC_SFRmap* ADCx,uint32_t ExternalTrigEvent, FunctionalState NewState);
void ADC_Set_HPChannel_Conv_Value_Offset (ADC_SFRmap* ADCx,uint32_t HPDoffChannel, uint32_t Offset);
void ADC_HPExternal_Trig_Conv_Config (ADC_SFRmap* ADCx,uint32_t HPExternalTrigEvent);
void ADC_Software_HPStart_Conv (ADC_SFRmap* ADCx);
void ADC_HPAuto_Conv_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_HPDisc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
uint16_t ADC_Get_HPConversion_Data (ADC_SFRmap* ADCx, uint8_t HPDataChannel);
/* 模数转换模块(ADC)中断管理函数定义****************************************/
void ADC_Set_INT_Enable (ADC_SFRmap* ADCx,uint32_t InterruptType, FunctionalState NewState);
FlagStatus ADC_Get_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType);
RetStatus ADC_Clear_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType);
INTStatus ADC_Get_INT_Status (ADC_SFRmap* ADCx, uint32_t InterruptType);

#endif /* KF32A1x6_ADC_H_ */
