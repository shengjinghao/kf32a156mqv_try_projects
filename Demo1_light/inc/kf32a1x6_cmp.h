/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_cmp.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the CMP 			  *
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
#ifndef KF32A1x6_CMP_H_
#define KF32A1x6_CMP_H_

#include "kf32a1x6.h"



/**
  * CMP外设判断
  */
#define CHECK_CMP_ALL_PERIPH(PERIPH)    (((PERIPH) == CMP0_ADDR) || \
										((PERIPH) == CMP1_ADDR)  || \
										((PERIPH) == CMP2_ADDR)  || \
										((PERIPH) == CMP3_ADDR))

/**
  * 描述  CMP配置信息结构体
  */
typedef struct
{
	uint32_t m_PositiveInput;    /* CMP的正端输出选择位
                                           取值为宏“CMP正端输入选择”中的一个 */
    uint32_t m_NegativeInput;     /* CMP的负端输出选择位
                                           取值为宏“CMP负端输入选择”中的一个 */
    FunctionalState m_FallTriggerEnable; /* CMP下降沿触发中断使能
                                           取值为TRUE或FALSE */
    FunctionalState m_RiseTriggerEnable; /* CMP上升沿触发中断使能
                                             取值为TRUE或FALSE */
    uint32_t m_Clock;                   /* CMP滤波器滤波时钟源
                                           取值为宏“CMP滤波器滤波时钟源选择位”中的一个 */
    uint32_t m_FrequencyDivision;        /* CMP滤波器滤波时钟分频
                                           取值为  8位数据，0-255 中的一个 */
    uint32_t m_SampleNumber;     /* CMP取样数量选择
                                            取值为宏“CMP滤波器取样数量选择”中的一个 */
    FunctionalState m_FilterEnable;   /* CMP滤波器使能位，
                                           取值为TRUE或FALSE */
    FunctionalState m_ScopecontrolEnable;  /* CMP范围控制使能位，
                                           取值为TRUE或FALSE */
    uint32_t m_OutputPolarity;        /* CMP输出极性选择
                                           取值为宏“CMP输出极性选择”中的一个 */
    FunctionalState m_CmpEnable;     /* CMP比较器使能
                                            取值为TRUE或FALSE */
}CMP_InitTypeDef;//	CMP0/CMP1/CMP2/CMP3



/**
  * CMP0正端输入选择
  */
#define CMP0_PositiveINPUT_PIN_PA0                ((uint32_t)0 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PA9                ((uint32_t)1 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PB2                ((uint32_t)2 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PB9                ((uint32_t)3 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PC11               ((uint32_t)4 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_AGND               ((uint32_t)5 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_DAC0OUT            ((uint32_t)6 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_DAC1OUT            ((uint32_t)7 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PA3                ((uint32_t)8 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PA4            	  ((uint32_t)9 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PA5            	  ((uint32_t)10 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PD9           	  ((uint32_t)11 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PG1           	  ((uint32_t)12 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PG2           	  ((uint32_t)13 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PD14           	  ((uint32_t)14 << CMP_CTL0_PMOD0_POS)
#define CMP0_PositiveINPUT_PIN_PE7           	  ((uint32_t)15 << CMP_CTL0_PMOD0_POS)
#define CHECK_CMP0_PositiveINPUT_PIN(SEL)       (((SEL) == CMP0_PositiveINPUT_PIN_PA0) \
										|| ((SEL) == CMP0_PositiveINPUT_PIN_PA9)\
										|| ((SEL) == CMP0_PositiveINPUT_PIN_PB2)\
										|| ((SEL) == CMP0_PositiveINPUT_PIN_PB9)\
										|| ((SEL) == CMP0_PositiveINPUT_PIN_PC11)\
										|| ((SEL) == CMP0_PositiveINPUT_PIN_AGND)\
										|| ((SEL) == CMP0_PositiveINPUT_PIN_DAC0OUT)\
                                        || ((SEL) == CMP0_PositiveINPUT_PIN_DAC1OUT)\
                                        || ((SEL) == CMP0_PositiveINPUT_PIN_PA3)\
                                        || ((SEL) == CMP0_PositiveINPUT_PIN_PA4)\
                                        || ((SEL) == CMP0_PositiveINPUT_PIN_PA5)\
                                        || ((SEL) == CMP0_PositiveINPUT_PIN_PD9)\
                                        || ((SEL) == CMP0_PositiveINPUT_PIN_PG1)\
                                        || ((SEL) == CMP0_PositiveINPUT_PIN_PG2)\
                                        || ((SEL) == CMP0_PositiveINPUT_PIN_PD14)\
                                        || ((SEL) == CMP0_PositiveINPUT_PIN_PE7))

/**
  * CMP1正端输入选择
  */
#define CMP1_PositiveINPUT_PIN_PA0                ((uint32_t)0 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_PA9                ((uint32_t)1 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_PB2                ((uint32_t)2 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_PB11               ((uint32_t)3 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_PG7                ((uint32_t)4 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_AGND               ((uint32_t)5 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_DAC0OUT            ((uint32_t)6 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_DAC1OUT            ((uint32_t)7 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_PG0            	  ((uint32_t)8 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_PD7            	  ((uint32_t)10 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_PC15               ((uint32_t)11 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_PD10               ((uint32_t)12 << CMP_CTL1_PMOD0_POS)
#define CMP1_PositiveINPUT_PIN_PD14               ((uint32_t)14 << CMP_CTL1_PMOD0_POS)
#define CHECK_CMP1_PositiveINPUT_PIN(SEL)       (((SEL) == CMP1_PositiveINPUT_PIN_PA0) \
										|| ((SEL) == CMP1_PositiveINPUT_PIN_PA9)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_PB2)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_PB11)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_PG7)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_AGND)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_DAC0OUT)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_DAC1OUT)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_PG0)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_PD7)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_PC15)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_PD10)\
										|| ((SEL) == CMP1_PositiveINPUT_PIN_PD14))

/**
  * CMP2正端输入选择
  */
#define CMP2_PositiveINPUT_PIN_PA0                ((uint32_t)0 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_PA9                ((uint32_t)1 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_PB2                ((uint32_t)2 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_PB13               ((uint32_t)3 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_PC7                ((uint32_t)4 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_AGND               ((uint32_t)5 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_DAC0OUT            ((uint32_t)6 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_DAC1OUT            ((uint32_t)7 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_PC0            	  ((uint32_t)10 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_PD5            	  ((uint32_t)11 << CMP_CTL2_PMOD0_POS)
#define CMP2_PositiveINPUT_PIN_PD14            	  ((uint32_t)14 << CMP_CTL2_PMOD0_POS)
#define CHECK_CMP2_PositiveINPUT_PIN(SEL)         (((SEL) == CMP2_PositiveINPUT_PIN_PA0) \
										|| ((SEL) == CMP2_PositiveINPUT_PIN_PA9)\
										|| ((SEL) == CMP2_PositiveINPUT_PIN_PB2)\
										|| ((SEL) == CMP2_PositiveINPUT_PIN_PB13)\
										|| ((SEL) == CMP2_PositiveINPUT_PIN_PC7)\
										|| ((SEL) == CMP2_PositiveINPUT_PIN_AGND)\
										|| ((SEL) == CMP2_PositiveINPUT_PIN_DAC0OUT)\
										|| ((SEL) == CMP2_PositiveINPUT_PIN_DAC1OUT)\
										|| ((SEL) == CMP2_PositiveINPUT_PIN_PC0)\
										|| ((SEL) == CMP2_PositiveINPUT_PIN_PD5)\
										|| ((SEL) == CMP2_PositiveINPUT_PIN_PD14))

/**
  * CMP3正端输入选择
  */
#define CMP3_PositiveINPUT_PIN_PA0                ((uint32_t)0 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_PA9                ((uint32_t)1 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_PB2                ((uint32_t)2 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_PB15               ((uint32_t)3 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_PC5                ((uint32_t)4 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_AGND               ((uint32_t)5 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_DAC0OUT            ((uint32_t)6 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_DAC1OUT            ((uint32_t)7 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_PE8            	  ((uint32_t)8 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_PG4            	  ((uint32_t)9 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_PA6            	  ((uint32_t)10 << CMP_CTL3_PMOD0_POS)
#define CMP3_PositiveINPUT_PIN_PD14            	  ((uint32_t)14 << CMP_CTL3_PMOD0_POS)
#define CHECK_CMP3_PositiveINPUT_PIN(SEL)       (((SEL) == CMP3_PositiveINPUT_PIN_PA0) \
										|| ((SEL) == CMP3_PositiveINPUT_PIN_PA9)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_PB2)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_PB15)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_PC5)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_AGND)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_DAC0OUT)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_DAC1OUT)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_PE8)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_PG4)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_PA6)\
										|| ((SEL) == CMP3_PositiveINPUT_PIN_PD14))

/**
  * CMP0负端输入选择
  */
#define CMP0_NegativeINPUT_PIN_PA1                ((uint32_t)0 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PA10               ((uint32_t)1 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PB3                ((uint32_t)2 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PB10               ((uint32_t)3 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PC12               ((uint32_t)4 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_AGND               ((uint32_t)5 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_DAC0OUT            ((uint32_t)6 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_DAC1OUT            ((uint32_t)7 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PA3            	  ((uint32_t)8 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PA4            	  ((uint32_t)9 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PA5            	 ((uint32_t)10 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PG1           	 ((uint32_t)12 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PG2            	 ((uint32_t)13 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PD15           	 ((uint32_t)14 << CMP_CTL0_NMOD0_POS)
#define CMP0_NegativeINPUT_PIN_PE7            	 ((uint32_t)15 << CMP_CTL0_NMOD0_POS)
#define CHECK_CMP0_NegativeINPUT_PIN(SEL)        (((SEL) == CMP0_NegativeINPUT_PIN_PA1) \
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PA10)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PB3)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PB10)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PC12)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_AGND)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_DAC0OUT)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_DAC1OUT)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PA3)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PA4)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PA5)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PG1)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PG2)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PD15)\
										|| ((SEL) == CMP0_NegativeINPUT_PIN_PE7))

/**
  * CMP1负端输入选择
  */
#define CMP1_NegativeINPUT_PIN_PA1                ((uint32_t)0 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_PA10               ((uint32_t)1 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_PB3                ((uint32_t)2 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_PB12               ((uint32_t)3 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_PC9                ((uint32_t)4 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_AGND               ((uint32_t)5 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_DAC0OUT            ((uint32_t)6 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_DAC1OUT            ((uint32_t)7 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_PH10            	  ((uint32_t)9 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_PD6                ((uint32_t)10 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_PC15               ((uint32_t)11 << CMP_CTL1_NMOD0_POS)
#define CMP1_NegativeINPUT_PIN_PD15               ((uint32_t)14 << CMP_CTL1_NMOD0_POS)
#define CHECK_CMP1_NegativeINPUT_PIN(SEL)       (((SEL) == CMP1_NegativeINPUT_PIN_PA1) \
										|| ((SEL) == CMP1_NegativeINPUT_PIN_PA10)\
										|| ((SEL) == CMP1_NegativeINPUT_PIN_PB3)\
										|| ((SEL) == CMP1_NegativeINPUT_PIN_PB12)\
										|| ((SEL) == CMP1_NegativeINPUT_PIN_PC9)\
										|| ((SEL) == CMP1_NegativeINPUT_PIN_AGND)\
										|| ((SEL) == CMP1_NegativeINPUT_PIN_DAC0OUT)\
										|| ((SEL) == CMP1_NegativeINPUT_PIN_DAC1OUT)\
										|| ((SEL) == CMP1_NegativeINPUT_PIN_PH10)\
										|| ((SEL) == CMP1_NegativeINPUT_PIN_PD6)\
										|| ((SEL) == CMP1_NegativeINPUT_PIN_PC15)\
                                        || ((SEL) == CMP1_NegativeINPUT_PIN_PD15))

/**
  * CMP2负端输入选择
  */
#define CMP2_NegativeINPUT_PIN_PA1                ((uint32_t)0 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_PA10               ((uint32_t)1 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_PB3                ((uint32_t)2 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_PB14               ((uint32_t)3 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_PC8                ((uint32_t)4 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_AGND               ((uint32_t)5 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_DAC0OUT            ((uint32_t)6 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_DAC1OUT            ((uint32_t)7 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_PC0            	  ((uint32_t)10 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_PD4            	  ((uint32_t)11 << CMP_CTL2_NMOD0_POS)
#define CMP2_NegativeINPUT_PIN_PD15            	  ((uint32_t)14 << CMP_CTL2_NMOD0_POS)
#define CHECK_CMP2_NegativeINPUT_PIN(SEL)       (((SEL) == CMP2_NegativeINPUT_PIN_PA1) \
										|| ((SEL) == CMP2_NegativeINPUT_PIN_PA10)\
										|| ((SEL) == CMP2_NegativeINPUT_PIN_PB3)\
										|| ((SEL) == CMP2_NegativeINPUT_PIN_PB14)\
										|| ((SEL) == CMP2_NegativeINPUT_PIN_PC8)\
										|| ((SEL) == CMP2_NegativeINPUT_PIN_AGND)\
										|| ((SEL) == CMP2_NegativeINPUT_PIN_DAC0OUT)\
										|| ((SEL) == CMP2_NegativeINPUT_PIN_DAC1OUT)\
										|| ((SEL) == CMP2_NegativeINPUT_PIN_PC0)\
										|| ((SEL) == CMP2_NegativeINPUT_PIN_PD4)\
                                        || ((SEL) == CMP2_NegativeINPUT_PIN_PD15))

/**
  * CMP3负端输入选择
  */
#define CMP3_NegativeINPUT_PIN_PA1                ((uint32_t)0 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_PA10               ((uint32_t)1 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_PB3                ((uint32_t)2 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_PF0                ((uint32_t)3 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_PC6                ((uint32_t)4 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_AGND               ((uint32_t)5 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_DAC0OUT            ((uint32_t)6 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_DAC1OUT            ((uint32_t)7 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_PE9            	  ((uint32_t)8 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_PG4            	  ((uint32_t)9 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_PA6            	  ((uint32_t)10 << CMP_CTL3_NMOD0_POS)
#define CMP3_NegativeINPUT_PIN_PD15            	  ((uint32_t)14 << CMP_CTL3_NMOD0_POS)
#define CHECK_CMP3_NegativeINPUT_PIN(SEL)       (((SEL) == CMP3_NegativeINPUT_PIN_PA1) \
										|| ((SEL) == CMP3_NegativeINPUT_PIN_PA10)\
										|| ((SEL) == CMP3_NegativeINPUT_PIN_PB3)\
										|| ((SEL) == CMP3_NegativeINPUT_PIN_PF0)\
										|| ((SEL) == CMP3_NegativeINPUT_PIN_PC6)\
										|| ((SEL) == CMP3_NegativeINPUT_PIN_AGND)\
										|| ((SEL) == CMP3_NegativeINPUT_PIN_DAC0OUT)\
										|| ((SEL) == CMP3_NegativeINPUT_PIN_DAC1OUT)\
										|| ((SEL) == CMP3_NegativeINPUT_PIN_PE9)\
										|| ((SEL) == CMP3_NegativeINPUT_PIN_PG4)\
										|| ((SEL) == CMP3_NegativeINPUT_PIN_PA6)\
                                        || ((SEL) == CMP3_NegativeINPUT_PIN_PD15))

/**
  * CMP0滤波器滤波时钟源选择
  */
#define CMPx_CLKSOURCE_SCLK              ((uint32_t)0x0 << CMP_CTL0_FLTCS0_POS)
#define CMPx_CLKSOURCE_HFCLK             ((uint32_t)0x1 << CMP_CTL0_FLTCS0_POS)
#define CMPx_CLKSOURCE_LFCLK             ((uint32_t)0x2 << CMP_CTL0_FLTCS0_POS)
#define CHECK_CMPx_CLKSOURCE_SEL(SEL)   (((SEL) == CMPx_CLKSOURCE_SCLK) \
										|| ((SEL) == CMPx_CLKSOURCE_HFCLK)\
										|| ((SEL) == CMPx_CLKSOURCE_LFCLK))

/**
 * CMP上升沿/下降沿触发中断
 * */
#define CMPx_UD_EDGE_INT					(CMP_CTL0_IFREN_POS)
#define CMPx_DOWN_EDGE_INT					(CMP_CTL0_IFFEN_POS)
#define CHECK_CMPx_EDGE_INT_SEL(SEL)		(((SEL) == CMPx_UD_EDGE_INT) \
									      || ((SEL) == CMPx_DOWN_EDGE_INT))

/**
  * CMP0滤波器取样数量选择
  */
#define CMPx_FLT_OFF              			((uint32_t)0x0 << CMP_CTL0_FLTCNT0_POS)
#define CMPx_FLT_SampleNumber_1             ((uint32_t)0x1 << CMP_CTL0_FLTCNT0_POS)
#define CMPx_FLT_SampleNumber_2             ((uint32_t)0x2 << CMP_CTL0_FLTCNT0_POS)
#define CMPx_FLT_SampleNumber_3             ((uint32_t)0x3 << CMP_CTL0_FLTCNT0_POS)
#define CMPx_FLT_SampleNumber_4             ((uint32_t)0x4 << CMP_CTL0_FLTCNT0_POS)
#define CMPx_FLT_SampleNumber_5             ((uint32_t)0x5 << CMP_CTL0_FLTCNT0_POS)
#define CMPx_FLT_SampleNumber_6             ((uint32_t)0x6 << CMP_CTL0_FLTCNT0_POS)
#define CMPx_FLT_SampleNumber_7             ((uint32_t)0x7 << CMP_CTL0_FLTCNT0_POS)
#define CHECK_CMPx_FLT_SampleNumber_SEL(SEL)     (((SEL) == CMPx_FLT_OFF) \
										|| ((SEL) == CMPx_FLT_SampleNumber_1)\
										|| ((SEL) == CMPx_FLT_SampleNumber_2)\
										|| ((SEL) == CMPx_FLT_SampleNumber_3)\
										|| ((SEL) == CMPx_FLT_SampleNumber_4)\
										|| ((SEL) == CMPx_FLT_SampleNumber_5)\
										|| ((SEL) == CMPx_FLT_SampleNumber_6)\
										|| ((SEL) == CMPx_FLT_SampleNumber_7))

/**
  * CMPx输出极性选择
  */
#define CMPx_OUTPUT_Normal                   ((uint32_t)0<<CMP_CTL0_POL_POS)
#define CMPx_OUTPUT_Opposite                 ((uint32_t)1<<CMP_CTL0_POL_POS)
#define CHECK_CMPx_OUTPUT_POLARITY(SEL)      (((SEL) == CMPx_OUTPUT_Normal) \
        							    || ((SEL) == CMPx_OUTPUT_Opposite))

/**
  * CMP输出选择
  */
#define NONE                   		  ((uint32_t)0<<CMP_CTL4_CMPOUTASEL0_POS)
#define CMP0_OUTPUT                   ((uint32_t)1<<CMP_CTL4_CMPOUTASEL0_POS)
#define CMP1_OUTPUT                   ((uint32_t)2<<CMP_CTL4_CMPOUTASEL0_POS)
#define CMP2_OUTPUT                   ((uint32_t)3<<CMP_CTL4_CMPOUTASEL0_POS)
#define CHECK_CMP_OUTPUT(SEL)            (((SEL) == NONE) \
										|| ((SEL) == CMP0_OUTPUT) \
										|| ((SEL) == CMP1_OUTPUT) \
        							    || ((SEL) == CMP2_OUTPUT))

/**
  * 比较器中断标志位触发模式选择位
  */
#define CMP_CMPOUT_FlipLatch_INT            ((uint32_t)0<<CMP_CTL4_CIFMS_POS)
#define CMP_CMPOUT_Change_INT               ((uint32_t)1<<CMP_CTL4_CIFMS_POS)
#define CHECK_CMP_TriggerINT_MODE(SEL)   (((SEL) == CMP_CMPOUT_FlipLatch_INT) \
        							    || ((SEL) == CMP_CMPOUT_Change_INT))

/**
  * 比较器迟滞电压校准选择
  */
#define CMP_SluggishVoltage_OFF                ((uint32_t)0<<CMP_CTL4_DELAYVOL0_POS)
#define CMP_SluggishVoltage_7p5mV              ((uint32_t)1<<CMP_CTL4_DELAYVOL0_POS)
#define CMP_SluggishVoltage_15mV               ((uint32_t)2<<CMP_CTL4_DELAYVOL0_POS)
#define CMP_SluggishVoltage_30mV               ((uint32_t)3<<CMP_CTL4_DELAYVOL0_POS)
#define CHECK_CMP_SluggishVoltage_SEL(SEL)   (((SEL) == CMP_SluggishVoltage_OFF) \
											|| ((SEL) == CMP_SluggishVoltage_7p5mV) \
											|| ((SEL) == CMP_SluggishVoltage_15mV) \
											|| ((SEL) == CMP_SluggishVoltage_30mV))

/**
/**
  * 霍尔模式选择
  */
#define CMP_HALLMODE_SINGLE              ((uint32_t)0<<CMP_CTL4_HALSEL_POS)
#define CMP_HALLMODE_BOTH                ((uint32_t)1<<CMP_CTL4_HALSEL_POS)
#define CHECK_CMP_HALLMODE_SEL(SEL)   		(((SEL) == CMP_HALLMODE_SINGLE) \
											|| ((SEL) == CMP_HALLMODE_BOTH))

/**
  * 滤波器输入选择
  */
#define CMP_FLTINSEL_CMPOUT              ((uint32_t)0<<CMP_CTL4_FLTINSEL_POS)
#define CMP_FLTINSEL_IO                ((uint32_t)1<<CMP_CTL4_FLTINSEL_POS)
#define CHECK_CMP_FLTINSEL(SEL)   		(((SEL) == CMP_FLTINSEL_CMPOUT) \
										 || ((SEL) == CMP_FLTINSEL_IO))

/**
 * 	TRGMUX输出通道选择位
 * */
#define CMP_WIN_CONTROL_TRGMUX_CH1			((uint32_t)0)
#define CMP_WIN_CONTROL_TRGMUX_CH2			((uint32_t)1)
#define CMP_WIN_CONTROL_TRGMUX_CH3			((uint32_t)2)
#define CMP_WIN_CONTROL_TRGMUX_CH4			((uint32_t)3)
#define CHECK_CMP_WIN_CONTRAL_TRGMUX_CH(CHANNEL)\
											((CHANNEL) <= CMP_WIN_CONTROL_TRGMUX_CH4)

/**
 *  CMP失调校准位校验
 * */
#define CHECK_CMP_TRIM_VALUE(Value)			(Value <= 0x3F)

/**
 * 	CMP失调校准方向选择
 * */
#define CMP_TRIM_DIRECTION_NEGETIVE			((uint32_t)0)
#define CMP_TRIM_DIRECTION_POSITIVE			((uint32_t)1)
#define CHECK_TRIM_DIRECTION(DIRECTION)		((DIRECTION) <= CMP_TRIM_DIRECTION_POSITIVE)

/**
 * 	 CMP WIN CONTROL 时钟选择
 * */
#define CMP_WIN_CONTROL_SYS_CLK				((uint32_t)0)
#define CMP_WIN_CONTROL_TRGMUX_CLK			((uint32_t)1)
#define CHECK_WIN_CONTROL_CLK(CLK)			((CLK) <= CMP_WIN_CONTROL_TRGMUX_CLK)

/** 初始化及配置函数 ************************************************/
void CMP_Reset (void);
void CMP_Configuration (uint32_t CMPx_ADDR, CMP_InitTypeDef* CMPInitStruct);
void CMP_Struct_Init (CMP_InitTypeDef* CMPInitStruct);
void CMP_IO_Channel_Enable(FunctionalState NewState);
void CMP0_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP0_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP1_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP1_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP2_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP2_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP3_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP3_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP_Up_Down_Edge_INT_Enable(uint32_t CMPx_ADDR, uint32_t UDEdge, uint32_t NewState);
void CMP_OUTPUT_POL_SELECT(uint32_t CMPx_ADDR, uint32_t Polarity);
void CMP_OUTPUT_SELECT (uint32_t Select);
void CMP_Cmd(uint32_t CMPx_ADDR, uint32_t NewState);
void CMP_Trigger_Select_Config (uint32_t TriSelect);
FlagStatus CMP_Get_Output_State(uint32_t CMPx_ADDR);
FlagStatus CMP_Get_INT_Flag(uint32_t CMPx_ADDR);
RetStatus CMP_Clear_INT_Flag(uint32_t CMPx_ADDR);
void CMP_INT_Enable(uint32_t CMPx_ADDR, uint32_t NewState);
void CMP_SluggishVoltage_Select (uint32_t Select);
void CMP_HALLMODE_Select (uint32_t Select);
void CMP_BEMF_Enable (FunctionalState NewState);
void CMP_FLTINSEL_Select (uint32_t Select);
void CMP_Win_Control_TRGMUX_CH_Select (uint32_t CMPx_ADDR, uint32_t Select);
void CMP_LP_Enable(FunctionalState NewState);
void CMP_TRIM_PMOS_Enable(FunctionalState NewState);
void CMP_TRIM_NMOS_Enable(FunctionalState NewState);
void CMP_TRIM_PMOS_Cail(uint32_t CMPx_ADDR, uint8_t Value);
void CMP_TRIM_PMOS_Direction_Select(uint32_t CMPx_ADDR, uint32_t Direction);
void CMP_TRIM_NMOS_Cail(uint32_t CMPx_ADDR, uint8_t Value);
void CMP_TRIM_NMOS_Direction_Select(uint32_t CMPx_ADDR, uint32_t Direction);
void CMP_WIN_Control_CLK_Select(uint32_t CMPx_ADDR, uint32_t Select);
void CMP_Filter_SampleNumber_Select(uint32_t CMPx_ADDR, uint32_t Select);
void CMP_Filter_CLKSource_Select(uint32_t CMPx_ADDR, uint32_t Select);



#endif /* KF32A1x6_CMP_H_ */
