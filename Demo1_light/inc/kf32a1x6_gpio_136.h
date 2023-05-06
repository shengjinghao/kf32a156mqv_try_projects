/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_gpio.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the GPIO 			  *
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

#ifndef KF32A136_GPIO_H_
#define KF32A136_GPIO_H_

#include "kf32a1x6.h"


/**
 *	GPIO内存指针
 **/
#define CHECK_GPIO_ALL_PERIPH(PERIPH)	(((PERIPH) == GPIOA_SFR) \
									  || ((PERIPH) == GPIOB_SFR) \
									  || ((PERIPH) == GPIOC_SFR) \
									  || ((PERIPH) == GPIOD_SFR) \
									  || ((PERIPH) == GPIOE_SFR) \
									  || ((PERIPH) == GPIOF_SFR) \
									  || ((PERIPH) == GPIOG_SFR) \
									  || ((PERIPH) == GPIOH_SFR))

/**
  * GPIO上拉/下拉
  */
typedef enum
{
    GPIO_NOPULL = 0x00,
    GPIO_PULLUP = 0x01
}GPIOPU_TypeDef, GPIOPD_TypeDef;

#define CHECK_GPIO_PU(PU)               (((PU) == GPIO_NOPULL) \
                                      || ((PU) == GPIO_PULLUP))
#define GPIO_PULLDOWN	GPIO_PULLUP
#define CHECK_GPIO_PD(PD)               (((PD) == GPIO_NOPULL) \
                                      || ((PD) == GPIO_PULLDOWN))

/**
  * GPIO开漏输出类型
  */
typedef enum
{
    GPIO_POD_PP = 0x00,
    GPIO_POD_OD = 0x01
}GPIOPOD_TypeDef;
#define CHECK_GPIO_POD(OTYPE)           (((OTYPE) == GPIO_POD_PP) \
                                      || ((OTYPE) == GPIO_POD_OD))

/**
  * GPIO输出模式控制
  */
typedef enum
{
    GPIO_MODE_IN   = 0x00,              /* 通用IO口输入模式 */
    GPIO_MODE_OUT  = 0x01,              /* 通用IO口输出模式 */
    GPIO_MODE_RMP  = 0x02,              /* 重映射IO口功能模式 */
    GPIO_MODE_AN   = 0x03               /* 模拟模式 */
}GPIOMode_TypeDef;
#define CHECK_GPIO_MODE(MODE)           (((MODE) == GPIO_MODE_IN) \
                                      || ((MODE) == GPIO_MODE_OUT) \
                                      || ((MODE) == GPIO_MODE_RMP) \
                                      || ((MODE) == GPIO_MODE_AN))

/**
  * GPIO端口输出速度控制
  */
typedef enum
{
    GPIO_LOW_SPEED  = 0,
    GPIO_HIGH_SPEED = 1
}GPIOSpeed_TypeDef;
#define CHECK_GPIO_SPEED(SPEED)         (((SPEED) == GPIO_LOW_SPEED) \
                                      || ((SPEED) == GPIO_HIGH_SPEED))

/**
  * 描述  GPIO配置信息结构体
  */
typedef struct
{
    uint32_t m_Pin;                     /* GPIO端口掩码，
                                           取值为宏“GPIO端口掩码”中的一个或多个组合 */

    GPIOMode_TypeDef m_Mode;            /* GPIO输出模式，
                                           取值为枚举类型GPIOMode_TypeDef中的一个 */

    GPIOSpeed_TypeDef m_Speed;          /* GPIO输出速度。
                                           取值为枚举类型GPIOSpeed_TypeDef中的一个 */

    GPIOPOD_TypeDef m_OpenDrain;        /* GPIO开漏控制，
                                           取值为枚举类型GPIOPOD_TypeDef中的一个 */

    GPIOPU_TypeDef m_PullUp;            /* GPIO上拉配置，
                                           取值为枚举类型GPIOPU_TypeDef中的一个 */

    GPIOPD_TypeDef m_PullDown;          /* GPIO下拉配置，
                                           取值为枚举类型GPIOPU_TypeDef中的一个 */
}GPIO_InitTypeDef;

/**
  * GPIO端口配置
  */
typedef enum
{
    Bit_RESET = 0,
    Bit_SET = !Bit_RESET
}BitAction;
#define CHECK_GPIO_BIT_ACTION(ACTION)   (((ACTION) == Bit_RESET) \
                                      || ((ACTION) == Bit_SET))

/**
  * GPIO端口编号
  */
#define GPIO_Pin_Num_0                  ((uint32_t)0x0)
#define GPIO_Pin_Num_1                  ((uint32_t)0x1)
#define GPIO_Pin_Num_2                  ((uint32_t)0x2)
#define GPIO_Pin_Num_3                  ((uint32_t)0x3)
#define GPIO_Pin_Num_4                  ((uint32_t)0x4)
#define GPIO_Pin_Num_5                  ((uint32_t)0x5)
#define GPIO_Pin_Num_6                  ((uint32_t)0x6)
#define GPIO_Pin_Num_7                  ((uint32_t)0x7)
#define GPIO_Pin_Num_8                  ((uint32_t)0x8)
#define GPIO_Pin_Num_9                  ((uint32_t)0x9)
#define GPIO_Pin_Num_10                 ((uint32_t)0xA)
#define GPIO_Pin_Num_11                 ((uint32_t)0xB)
#define GPIO_Pin_Num_12                 ((uint32_t)0xC)
#define GPIO_Pin_Num_13                 ((uint32_t)0xD)
#define GPIO_Pin_Num_14                 ((uint32_t)0xE)
#define GPIO_Pin_Num_15                 ((uint32_t)0xF)
#define CHECK_GPIO_PIN_NUM(PIN)         ((PIN) <= GPIO_Pin_Num_15)

/**
  * GPIO端口掩码
  */
#define GPIO_PIN_MASK_0                  ((uint16_t)0x0001)
#define GPIO_PIN_MASK_1                  ((uint16_t)0x0002)
#define GPIO_PIN_MASK_2                  ((uint16_t)0x0004)
#define GPIO_PIN_MASK_3                  ((uint16_t)0x0008)
#define GPIO_PIN_MASK_4                  ((uint16_t)0x0010)
#define GPIO_PIN_MASK_5                  ((uint16_t)0x0020)
#define GPIO_PIN_MASK_6                  ((uint16_t)0x0040)
#define GPIO_PIN_MASK_7                  ((uint16_t)0x0080)
#define GPIO_PIN_MASK_8                  ((uint16_t)0x0100)
#define GPIO_PIN_MASK_9                  ((uint16_t)0x0200)
#define GPIO_PIN_MASK_10                 ((uint16_t)0x0400)
#define GPIO_PIN_MASK_11                 ((uint16_t)0x0800)
#define GPIO_PIN_MASK_12                 ((uint16_t)0x1000)
#define GPIO_PIN_MASK_13                 ((uint16_t)0x2000)
#define GPIO_PIN_MASK_14                 ((uint16_t)0x4000)
#define GPIO_PIN_MASK_15                 ((uint16_t)0x8000)
#define GPIO_PIN_MASK_All                ((uint16_t)0xFFFF)
#define CHECK_GPIO_PIN_MASK(PIN)         (((PIN) >> 16 ) == (uint32_t)0x00)

/**
  * GPIO引脚重映射
  */
#define	GPIO_RMP_PG1_AF0			     ((uint32_t)0x0100)
#define	GPIO_RMP_PG1_AF1			     ((uint32_t)0x0101)
#define	GPIO_RMP_PG1_AF2			     ((uint32_t)0x0102)
#define	GPIO_RMP_PG1_AF3			     ((uint32_t)0x0103)
#define	GPIO_RMP_PG1_AF4			     ((uint32_t)0x0104)
#define	GPIO_RMP_PG1_AF5			     ((uint32_t)0x0105)
#define	GPIO_RMP_PG1_AF6			     ((uint32_t)0x0106)
#define	GPIO_RMP_PG1_AF7			     ((uint32_t)0x0107)
#define	GPIO_RMP_PG1_AF8			     ((uint32_t)0x0108)
#define	GPIO_RMP_PG1_AF9			     ((uint32_t)0x0109)
#define	GPIO_RMP_PG1_AF10			     ((uint32_t)0x010A)
#define	GPIO_RMP_PG1_AF11			     ((uint32_t)0x010B)
#define	GPIO_RMP_PG1_AF12			     ((uint32_t)0x010C)
#define	GPIO_RMP_PG1_AF13			     ((uint32_t)0x010D)
#define	GPIO_RMP_PG1_AF14			     ((uint32_t)0x010E)
#define CHECK_GPIO_REMAP(RMP)		 (((RMP) <= GPIO_RMP_PG1_AF14) && ((RMP) >= GPIO_RMP_PG1_AF0))

#define	GPIO_RMP_PG2_AF0			     ((uint32_t)0x0200)
#define	GPIO_RMP_PG2_AF1			     ((uint32_t)0x0201)
#define	GPIO_RMP_PG2_AF2			     ((uint32_t)0x0202)
#define	GPIO_RMP_PG2_AF3			     ((uint32_t)0x0203)
#define	GPIO_RMP_PG2_AF4			     ((uint32_t)0x0204)
#define	GPIO_RMP_PG2_AF5			     ((uint32_t)0x0205)
#define	GPIO_RMP_PG2_AF6			     ((uint32_t)0x0206)
#define	GPIO_RMP_PG2_AF7			     ((uint32_t)0x0207)
#define	GPIO_RMP_PG2_AF8			     ((uint32_t)0x0208)
#define	GPIO_RMP_PG2_AF9			     ((uint32_t)0x0209)
#define	GPIO_RMP_PG2_AF10			     ((uint32_t)0x020A)
#define	GPIO_RMP_PG2_AF11			     ((uint32_t)0x020B)
#define	GPIO_RMP_PG2_AF12			     ((uint32_t)0x020C)
#define	GPIO_RMP_PG2_AF13			     ((uint32_t)0x020D)
#define	GPIO_RMP_PG2_AF14			     ((uint32_t)0x020E)
#define CHECK_GPIO_REMAP(RMP)		 (((RMP) <= GPIO_RMP_PG1_AF14) && ((RMP) >= GPIO_RMP_PG1_AF0))
/**
 * 	CHx输入输出选择
 * */
#define FlexRM_ONLY_INPUT								((uint32_t)0)
#define FlexRM_AUTO										((uint32_t)1)
#define CHECK_FlexRM_CHX_DIRECTION(SELECT)				((SELECT) <= FlexRM_AUTO)

/**
 * Groupx 功能选择位
 * */
#define FlexRM_GROUPX_PORT0								((uint32_t)0)
#define FlexRM_GROUPX_PORT1								((uint32_t)1)
#define FlexRM_GROUPX_PORT2								((uint32_t)2)
#define FlexRM_GROUPX_PORT3								((uint32_t)3)
#define FlexRM_GROUPX_PORT4								((uint32_t)4)
#define FlexRM_GROUPX_PORT5								((uint32_t)5)
#define FlexRM_GROUPX_PORT6								((uint32_t)6)
#define FlexRM_GROUPX_PORT7								((uint32_t)7)
#define FlexRM_GROUPX_PORT8								((uint32_t)8)
#define FlexRM_GROUPX_PORT9								((uint32_t)9)
#define FlexRM_GROUPX_PORT10							((uint32_t)10)
#define FlexRM_GROUPX_PORT11							((uint32_t)11)
#define FlexRM_GROUPX_PORT12							((uint32_t)12)
#define FlexRM_GROUPX_PORT13							((uint32_t)13)
#define FlexRM_GROUPX_PORT14							((uint32_t)14)
#define FlexRM_GROUPX_PORT15							((uint32_t)15)
#define CHECK_FlexRM_GROUPX_PORT(PORT)					((PORT) <= FlexRM_GROUPX_PORT15)

/**
 * 	Groupx
 * */
#define FlexRM_GROUP_0									((uint32_t)0)
#define FlexRM_GROUP_1									((uint32_t)1)
#define FlexRM_GROUP_2									((uint32_t)2)
#define FlexRM_GROUP_3									((uint32_t)3)
#define FlexRM_GROUP_4									((uint32_t)4)
#define FlexRM_GROUP_5									((uint32_t)5)
#define FlexRM_GROUP_6									((uint32_t)6)
#define FlexRM_GROUP_7									((uint32_t)7)
#define FlexRM_GROUP_8									((uint32_t)8)
#define FlexRM_GROUP_9									((uint32_t)9)
#define FlexRM_GROUP_10									((uint32_t)10)
#define FlexRM_GROUP_11									((uint32_t)11)
#define CHECK_FlexRM_GROUP_NUM(NUM)						((NUM) <= FlexRM_GROUP_11)

/**
 * 	CHANNELx
 * */
#define FlexRM_CHANNEL_0									((uint32_t)0)
#define FlexRM_CHANNEL_1									((uint32_t)1)
#define FlexRM_CHANNEL_2									((uint32_t)2)
#define FlexRM_CHANNEL_3									((uint32_t)3)
#define FlexRM_CHANNEL_4									((uint32_t)4)
#define FlexRM_CHANNEL_5									((uint32_t)5)
#define FlexRM_CHANNEL_6									((uint32_t)6)
#define FlexRM_CHANNEL_7									((uint32_t)7)
#define FlexRM_CHANNEL_8									((uint32_t)8)
#define FlexRM_CHANNEL_9									((uint32_t)9)
#define FlexRM_CHANNEL_10									((uint32_t)10)
#define FlexRM_CHANNEL_11									((uint32_t)11)
#define CHECK_FlexRM_CHANNEL_NUM(NUM)						((NUM) <= FlexRM_CHANNEL_11)


/* 通用输入输出端口(GPIO)初始化及配置函数定义*******************************/
void GPIO_Reset (GPIO_SFRmap* GPIOx);
void GPIO_Configuration (GPIO_SFRmap* GPIOx, GPIO_InitTypeDef* gpioInitStruct);
void GPIO_Struct_Init (GPIO_InitTypeDef* gpioInitStruct);
void GPIO_Pin_Lock_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState);
void GPIO_Pull_Up_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState);
void GPIO_Toggle_Pull_Up_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
void GPIO_Pull_Down_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState);
void GPIO_Toggle_Pull_Down_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
void GPIO_Open_Drain_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOPOD_TypeDef NewState);
void GPIO_Toggle_Open_Drain_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
void GPIO_Write_Mode_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOMode_TypeDef NewState);
void GPIO_Speed_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOSpeed_TypeDef NewState);
void GPIO_Toggle_Speed_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);

/* 通用输入输出端口(GPIO)读写函数定义***************************************/
BitAction GPIO_Read_Input_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
uint16_t GPIO_Read_Input_Data (GPIO_SFRmap* GPIOx);
BitAction GPIO_Read_Output_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
uint16_t GPIO_Read_Output_Data (GPIO_SFRmap* GPIOx);
void GPIO_Set_Output_Data_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, BitAction BitsValue);
void GPIO_Toggle_Output_Data_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);

/* 通用输入输出端口(GPIO)重映射配置函数定义*********************************/
void GPIO_Pin_RMP_Config(GPIO_SFRmap* GPIOx, uint16_t GpioPinNum, uint32_t PinRemap);
/* 接口映射管理(FlexRM)配置函数定义***************************************/
void FlexRM_Reset(void);
void FlexRM_Channel_Direction_Select(uint32_t Channel, FunctionalState NewState);
void FlexRM_Group_Enable(uint32_t Channel, FunctionalState NewState);
void FlexRM_Group_Function_Select(uint32_t Group, uint32_t Port);
void FlexRM_Group_Output_Select(uint32_t Group, uint32_t Channel);
void FlexRM_Group_Input_Select(uint32_t Group, uint32_t Channel);


#endif /* KF32A136_GPIO_H_ */
