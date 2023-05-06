/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_gpio.c                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     :  This file provides the general input/output port 	  *
 *  					(GPIO) peripheral function, including:				  *
 *          			+ General input: Output Port (GPIO) initialization    *
 *          			  and configuration functions						  *
 *          			+ General input:Output port (GPIO) read-write function*
 *          			+ General input:Output port (GPIO) remapping 		  *
 *          			  configuration function 							  *
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


#include "kf32a1x6_gpio.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"

/**
  *   ##### 通用输入输出端口(GPIO)初始化及配置函数 #####
  **/

/**
  * 描述  复位GPIO外设，使能外设时钟。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  * 返回  无。
  **/
void GPIO_Reset (GPIO_SFRmap * GPIOx)
{
	/*参数校验*/
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

	if (GPIOx == GPIOA_SFR)
	{
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOARST, TRUE);
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOARST, FALSE);
		PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOACLKEN, TRUE);
	}
	else if (GPIOx == GPIOB_SFR)
	{
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOBRST, TRUE);
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOBRST, FALSE);
		PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOBCLKEN, TRUE);
	}
	else if (GPIOx == GPIOC_SFR)
	{
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOCRST, TRUE);
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOCRST, FALSE);
		PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOCCLKEN, TRUE);
	}
	else if (GPIOx == GPIOD_SFR)
	{
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIODRST, TRUE);
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIODRST, FALSE);
		PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIODCLKEN, TRUE);
	}
	else if (GPIOx == GPIOE_SFR)
	{
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOERST, TRUE);
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOERST, FALSE);
		PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOECLKEN, TRUE);
	}
	else if (GPIOx == GPIOF_SFR)
	{
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOFRST, TRUE);
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOFRST, FALSE);
		PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOFCLKEN, TRUE);
	}
	else if (GPIOx == GPIOG_SFR)
	{
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOGRST, TRUE);
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOGRST, FALSE);
		PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOGCLKEN, TRUE);
	}
	else if (GPIOx == GPIOH_SFR)
	{
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOHRST, TRUE);
		RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOHRST, FALSE);
		PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOHCLKEN, TRUE);
	}
	else
	{
		;
	}
}

/**
  * 描述  通用输入输出端口(GPIO)初始化配置。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       gpioInitStruct: GPIO配置信息结构体指针。
  * 返回  无。
  **/
void GPIO_Configuration (GPIO_SFRmap* GPIOx, GPIO_InitTypeDef* gpioInitStruct)
{
    uint32_t pinpos;
    uint32_t pos;
    uint32_t currentpin;
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(gpioInitStruct->m_Pin));
    CHECK_RESTRICTION(CHECK_GPIO_MODE(gpioInitStruct->m_Mode));
    CHECK_RESTRICTION(CHECK_GPIO_SPEED(gpioInitStruct->m_Speed));
    CHECK_RESTRICTION(CHECK_GPIO_PU(gpioInitStruct->m_PullUp));
    CHECK_RESTRICTION(CHECK_GPIO_PD(gpioInitStruct->m_PullDown));

    /* 配置一个引脚信息 */
    for (pinpos = 0x00; pinpos < 0x10; pinpos++)
    {
        pos = ((uint32_t)0x01) << pinpos;
        /* 获取引脚位置信息 */
        currentpin = (gpioInitStruct->m_Pin) & pos;

        if (currentpin == pos)
        {
            /*----------- 设置GPIOx_PMOD寄存器 -----------*/
            /* 根据结构体成员m_Mode，设置PXPMDy位域 */
            tmpreg = (((uint32_t)gpioInitStruct->m_Mode) << (pinpos * 2));
            GPIOx->PMOD = SFR_Config (GPIOx->PMOD,
                                  ~(GPIO_PMOD_PXPMD0 << (pinpos * 2)),
                                  tmpreg);

            if ((gpioInitStruct->m_Mode == GPIO_MODE_OUT)
                || (gpioInitStruct->m_Mode == GPIO_MODE_RMP))
            {
                /* GPIO开漏控制参数校验 */
                CHECK_RESTRICTION(CHECK_GPIO_POD(gpioInitStruct->m_OpenDrain));

                /*----------- 设置GPIOx_PODR寄存器 -----------*/
                /* 根据结构体成员m_OpenDrain，设置PXPODR位域 */
                tmpreg = (((uint32_t)gpioInitStruct->m_OpenDrain) << (pinpos));
                GPIOx->PODR = SFR_Config (GPIOx->PODR,
                                      ~(GPIO_PODR_PXPODR0 << pinpos),
                                      tmpreg);
            }
            else
            {
                ;
            }

            /*----------- 设置GPIOx_OMOD寄存器 -----------*/
            /* 根据结构体成员m_Speed，设置PXOMD位域 */
            tmpreg = ((uint32_t)gpioInitStruct->m_Speed) << (pinpos * 2);
            GPIOx->OMOD = SFR_Config (GPIOx->OMOD,
                                  ~(GPIO_OMOD_PXOMD0 << (pinpos * 2)),
                                  tmpreg);

            /*----------- 设置GPIOx_PUR寄存器 -----------*/
            /* 根据结构体成员m_PullUp，设置PXPUR位域 */
            tmpreg = (((uint32_t)gpioInitStruct->m_PullUp) << (pinpos));
            GPIOx->PUR = SFR_Config (GPIOx->PUR,
                                  ~(GPIO_PUR_PXPUR0 << pinpos),
                                  tmpreg);

            /*----------- 设置GPIOx_PDR寄存器 -----------*/
            /* 根据结构体成员m_PullDown，设置PXPDR位域 */
            tmpreg = (((uint32_t)gpioInitStruct->m_PullDown) << (pinpos));
            GPIOx->PDR = SFR_Config (GPIOx->PDR,
                                  ~(GPIO_PDR_PXPDR0 << pinpos),
                                  tmpreg);
        }
        else
        {
            ;
        }
    }
}

/**
  * 描述  初始化GPIO配置信息结构体。
  * 输入  gpioInitStruct: 指向待初始化的结构体指针。
  * 返回  无。
  */
void GPIO_Struct_Init (GPIO_InitTypeDef* gpioInitStruct)
{
    /* 初始化 GPIO端口掩码 */
    gpioInitStruct->m_Pin  = GPIO_PIN_MASK_All;

    /* 初始化 GPIO输出模式 */
    gpioInitStruct->m_Mode = GPIO_MODE_AN;

    /* 初始化 GPIO输出速度 */
    gpioInitStruct->m_Speed = GPIO_LOW_SPEED;

    /* 初始化 GPIO开漏控制 */
    gpioInitStruct->m_OpenDrain = GPIO_POD_PP;

    /* 初始化 GPIO上拉配置 */
    gpioInitStruct->m_PullUp = GPIO_NOPULL;

    /* 初始化 GPIO下拉配置 */
    gpioInitStruct->m_PullDown = GPIO_NOPULL;
}

/**
  * 描述  配置GPIO端口锁定。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  *       NewState: GPIO端口锁定状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  */
void GPIO_Pin_Lock_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState)
{
	uint32_t tmpreg = 0x5C5A0000;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	/* 保存原始锁定状态 */
	tmpreg |= GPIOx->LOCK;

	/* 配置锁定/解锁状态 */
	if(NewState != FALSE)
	{
		/* 锁定 */
		tmpreg |= (uint32_t)GpioPin;
	}
	else
	{
		/* 解锁 */
		tmpreg &= ~((uint32_t)GpioPin);
	}

    /*----------- 设置GPIOx_LOCK寄存器----------- */
    GPIOx->LOCK = tmpreg;
}

/**
  * 描述  配置GPIO端口上拉使能。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  *       NewState: GPIO端口上拉使能状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  */
void GPIO_Pull_Up_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState)
{
	/*参数校验*/
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	/* ----------- 设置GPIOx_PUR寄存器 ----------- */
	if(NewState != FALSE)
	{
		/* 使能上拉功能 */
		GPIOx->PUR |= (uint32_t)GpioPin;
	}
	else
	{
		/* 禁止上拉功能 */
		GPIOx->PUR &= ~((uint32_t)GpioPin);
	}
}

/**
  * 描述  配置GPIO端口上拉使能取反。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  * 返回  无。
  */
void GPIO_Toggle_Pull_Up_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*----------- 设置GPIOx_PUR寄存器 -----------*/
	GPIOx->PUR ^= (uint32_t)GpioPin;
}

/**
  * 描述  配置GPIO端口下拉使能。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  *       NewState: GPIO端口下拉使能状态，取值范围为TRUE 或 FALSE。
  * 返回  无。
  */
void GPIO_Pull_Down_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*----------- 设置GPIOx_PDR寄存器 -----------*/
	if(NewState != FALSE)
	{
		/* 使能下拉功能 */
		GPIOx->PDR |= (uint32_t)GpioPin;
	}
	else
	{
		/* 禁止下拉功能 */
		GPIOx->PDR &= ~((uint32_t)GpioPin);
	}
}

/**
  * 描述  配置GPIO端口下拉使能取反。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  * 返回  无。
  */
void GPIO_Toggle_Pull_Down_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*----------- 设置GPIOx_PUR寄存器 -----------*/
	GPIOx->PDR ^= (uint32_t)GpioPin;
}

/**
  * 描述  配置GPIO端口开漏输出控制。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  *       NewState: GPIO开漏输出控制状态，取值为：
  *                   GPIO_POD_PP: 推挽输出
  *                   GPIO_POD_OD: 开漏输出
  * 返回  无。
  */
void GPIO_Open_Drain_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOPOD_TypeDef NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_GPIO_POD(NewState));

	/*----------- 设置GPIOx_PODR寄存器 -----------*/
	if(NewState != GPIO_POD_PP)
	{
		/* 开漏输出 */
		GPIOx->PODR |= (uint32_t)GpioPin;
	}
	else
	{
		/* 推挽输出 */
		GPIOx->PODR &= ~((uint32_t)GpioPin);
	}
}

/**
  * 描述  配置GPIO端口开漏输出控制取反。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  * 返回  无。
  */
void GPIO_Toggle_Open_Drain_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

	/*----------- 设置GPIOx_PODR寄存器 -----------*/
	GPIOx->PODR ^= (uint32_t)GpioPin;
}

/**
  * 描述  配置GPIO输出模式控制。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  *       NewState: GPIO输出模式控制状态，取值为：
  *                   GPIO_MODE_IN: 通用IO口输入模式
  *                   GPIO_MODE_OUT: 通用IO口输出模式
  *                   GPIO_MODE_RMP: 重映射IO口功能模式
  *                   GPIO_MODE_AN: 模拟模式
  * 返回  无。
  */
void GPIO_Write_Mode_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOMode_TypeDef NewState)
{
	uint32_t pinpos = 0x00;
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_GPIO_MODE(NewState));

	/*----------- 获取GPIOx_PMOD寄存器 -----------*/
	tmpreg = GPIOx->PMOD;
	while(GpioPin)
	{
		if(GpioPin & (uint16_t)0x01)
		{
            /* 记录配置信息 */
            tmpreg &= ~(GPIO_PMOD_PXPMD0 << pinpos);
            tmpreg |= (uint32_t)NewState << pinpos;
		}
		else
		{
			;
		}
		GpioPin >>= 1;
		pinpos += 2;
	}

    /*----------- 配置GPIOx_PMOD寄存器 -----------*/
    GPIOx->PMOD = tmpreg;
}

/**
  * 描述  配置GPIO端口输出速度控制。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  *       NewState: GPIO端口输出速度控制状态，取值为：
  *                   GPIO_LOW_SPEED: 10MHZ
  *                   GPIO_HIGH_SPEED: 50MHZ
  * 返回  无。
  */
void GPIO_Speed_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOSpeed_TypeDef NewState)
{
	uint32_t pinpos = 0x00;
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_GPIO_SPEED(NewState));

    /*----------- 获取GPIOx_OMOD寄存器 -----------*/
	tmpreg = GPIOx->OMOD;
	while(GpioPin)
	{
		if(GpioPin & (uint16_t)0x01)
		{
			tmpreg &= ~((GPIO_OMOD_PXOMD0) << pinpos);
			tmpreg |= (uint32_t)NewState << pinpos;
		}
		else
		{
			;
		}
		GpioPin >>= 1;
		pinpos += 2;
	}

    /*----------- 配置GPIOx_PMOD寄存器 -----------*/
    GPIOx->OMOD = tmpreg;
}

/**
  * 描述  配置GPIO端口输出速度控制取反。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  * 返回  无。
  */
void GPIO_Toggle_Speed_Config(GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	uint32_t pinpos = 0x00;
	uint32_t tmpreg;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

	/*----------- 获取GPIOx_OMOD寄存器 -----------*/
	tmpreg = GPIOx->OMOD;
	while(GpioPin)
	{
		if(GpioPin & (uint16_t)0x01)
		{
			tmpreg ^= GPIO_OMOD_PXOMD0 << pinpos;
		}
		else
		{
			;
		}
		GpioPin >>= 1;
		pinpos += 2;
	}

    /*----------- 配置GPIOx_PMOD寄存器 -----------*/
    GPIOx->OMOD = tmpreg;
}

/**
  *   ##### 通用输入输出端口(GPIO)初始化及配置函数定义结束 #####
  */


/**
  *   ##### 通用输入输出端口(GPIO)读写函数 #####
  */

/**
  * 描述  获取GPIO端口指定引脚的输入数据。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 指定端口引脚，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的一个。
  * 返回  指定引脚的信息，1：逻辑高电平，0：逻辑低电平。
  */
BitAction GPIO_Read_Input_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*---------------- 获取GPIOx_PIR寄存器PXPIRy位 ----------------*/
    tmpreg = (uint32_t)GpioPin;
    if ((GPIOx->PIR & tmpreg) != Bit_RESET)
    {
        /* 逻辑高电平 */
        return Bit_SET;
    }
    else
    {
        /* 逻辑低电平 */
        return Bit_RESET;
    }
}

/**
  * 描述  获取GPIO端口输入数据。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  * 返回  输入数据，16位有效数据。
  */
uint16_t GPIO_Read_Input_Data (GPIO_SFRmap* GPIOx)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    /*---------------- 获取GPIOx_PIR寄存器 ----------------*/
    tmpreg = GPIOx->PIR;

    return (uint16_t)tmpreg;
}

/**
  * 描述  获取GPIO端口指定引脚的输出数据。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 指定端口引脚，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的一个。
  * 返回  指定引脚的信息，1：逻辑高电平，0：逻辑低电平。
  */
BitAction GPIO_Read_Output_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*---------------- 获取GPIOx_POR寄存器PXPORy位 ----------------*/
    tmpreg = (uint32_t)GpioPin;
    if ((GPIOx->POR & tmpreg) != Bit_RESET)
    {
        /* 逻辑高电平 */
        return Bit_SET;
    }
    else
    {
        /* 逻辑低电平 */
        return Bit_RESET;
    }
}

/**
  * 描述  获取GPIO端口输出数据。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  * 返回  输出数据，16位有效数据。
  */
uint16_t
GPIO_Read_Output_Data (GPIO_SFRmap* GPIOx)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    /*---------------- 获取GPIOx_POR寄存器 ----------------*/
    tmpreg = GPIOx->POR;

    return (uint16_t)tmpreg;
}

/**
  * 描述  配置GPIO端口指定引脚的输出数据。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  *       BitsValue: 引脚的配置值，取值为：
  *                    Bit_RESET: 逻辑低电平
  *                    Bit_SET: 逻辑高电平
  * 返回  无。
  */
void GPIO_Set_Output_Data_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, BitAction BitsValue)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
    CHECK_RESTRICTION(CHECK_GPIO_BIT_ACTION(BitsValue));

    /*----------- 设置GPIOx_POR寄存器 -----------*/
    if (BitsValue != Bit_RESET)
    {
        /* 逻辑高电平 */
        GPIOx->POR |= (uint32_t)GpioPin;
    }
    else
    {
        /* 逻辑低电平 */
        GPIOx->POR &= ~((uint32_t)GpioPin);
    }
}

/**
  * 描述  配置GPIO端口指定引脚的输出数据取反。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
  *                一个或多个组合。
  * 返回  无。
  */
void GPIO_Toggle_Output_Data_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    /*----------- 设置GPIOx_POR寄存器 -----------*/
    GPIOx->POR ^= (uint32_t)GpioPin;
}

/**
  *   ##### 通用输入输出端口(GPIO)读写函数定义结束 #####
  */


/**
  *   ##### 通用输入输出端口(GPIO)重映射配置函数 #####
  */

/**
  * 描述  配置GPIO端口引脚重映射。
  * 输入  GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *      GpioPinNum: 指定端口引脚，取值为GPIO_Pin_Num_0~GPIO_Pin_Num_15中的一个。
  *      PinRemap: 引脚重映射选择，取值为：
  *          GPIO_RMP_AF0
  *          GPIO_RMP_AF1
  *          GPIO_RMP_AF2
  *          GPIO_RMP_AF3
  *          GPIO_RMP_AF4
  *          GPIO_RMP_AF5
  *          GPIO_RMP_AF6
  *          GPIO_RMP_AF7
  *          GPIO_RMP_AF8
  *          GPIO_RMP_AF9
  *          GPIO_RMP_AF10	 
  *          GPIO_RMP_AF11	 
  *          GPIO_RMP_AF12	 
  *          GPIO_RMP_AF13	 
  *          GPIO_RMP_AF14	 
  *          GPIO_RMP_AF15
  * 返回  无。
  */
void GPIO_Pin_RMP_Config(GPIO_SFRmap* GPIOx, uint16_t GpioPinNum, uint32_t PinRemap)
{
    uint32_t tmask;
	uint32_t tmpreg;
    uint32_t PageNum = (PinRemap&0x300)>>8;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_NUM(GpioPinNum));

    /* 配置GPIOx_RMP_MSB寄存器 */
    tmask = ((uint32_t)1 << (GpioPinNum+16)) + ((uint32_t)1 << GpioPinNum);
    tmpreg = ((uint32_t)((PageNum-1)/2) << (GpioPinNum+16)) + ((uint32_t)((PageNum-1)%2) << GpioPinNum);
    GPIOx->RMP_MSB = SFR_Config(GPIOx->RMP_MSB,~tmask,tmpreg);

    /* 配置GPIOx_RMPH\L寄存器 */
    if(GpioPinNum <= GPIO_Pin_Num_7)
    {
    	tmask = 0xF << (GpioPinNum*4);
    	tmpreg = (PinRemap&0xF) << (GpioPinNum*4);
    	GPIOx->RMP[0] = SFR_Config(GPIOx->RMP[0],~tmask,tmpreg);
    }
    else if(GpioPinNum <= GPIO_Pin_Num_15)
    {
    	tmask = 0xF << ((GpioPinNum - 8)*4);
    	tmpreg = (PinRemap&0xF) << ((GpioPinNum - 8)*4);
    	GPIOx->RMP[1] = SFR_Config(GPIOx->RMP[1],~tmask,tmpreg);
    }
}

/**
  *   ##### 通用输入输出端口(GPIO)重映射配置函数定义结束 #####
  */


/**
  *   ##### 接口映射管理(FlexRM)初始化及配置函数 #####
  **/

/**
  * 描述: 复位FlexRM外设，使能外设时钟。
  * 输入: 无。
  * 返回: 无。
  */
void FlexRM_Reset(void)
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FlexRMRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FlexRMRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_FlexRMCLKEN, TRUE);
}

/**
  * 描述: CHx通道方向选择。
  * 输入: Channel:
  * 			   FlexRM_CHANNEL_0
  * 		       FlexRM_CHANNEL_1
  * 		       FlexRM_CHANNEL_2
  * 		       FlexRM_CHANNEL_3
  * 		       FlexRM_CHANNEL_4
  * 		       FlexRM_CHANNEL_5
  * 		       FlexRM_CHANNEL_6
  * 		       FlexRM_CHANNEL_7
  * 		       FlexRM_CHANNEL_8
  * 		       FlexRM_CHANNEL_9
  * 		       FlexRM_CHANNEL_10
  * 		       FlexRM_CHANNEL_11
  * 	 Direction: FlexRM_AUTO ： CHx的输入/输出功能由硬件自动选择
  * 	  			FlexRM_ONLY_INPUT ： CHx仅能用作输入
  * 返回: 无。
  */
void FlexRM_Channel_Direction_Select(uint32_t Channel, uint32_t Direction)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FlexRM_CHANNEL_NUM(Channel));
	CHECK_RESTRICTION(CHECK_FlexRM_CHX_DIRECTION(Direction));

	tmpreg = Direction << (Channel+FlexRM_CTL_CH0TRSEL_POS);
	tmask = 1 << (Channel+FlexRM_CTL_CH0TRSEL_POS);
	FlexRM_CTL = SFR_Config(FlexRM_CTL, ~tmask, tmpreg);
}

/**
  * 描述: Group使能。
  * 输入: Group:
  * 			   FlexRM_GROUP_0
  * 		       FlexRM_GROUP_1
  * 		       FlexRM_GROUP_2
  * 		       FlexRM_GROUP_3
  * 		       FlexRM_GROUP_4
  * 		       FlexRM_GROUP_5
  * 		       FlexRM_GROUP_6
  * 		       FlexRM_GROUP_7
  * 		       FlexRM_GROUP_8
  * 		       FlexRM_GROUP_9
  * 		       FlexRM_GROUP_10
  * 		       FlexRM_GROUP_11
  * 	  NewState: TRUE ： Groupx使能
  * 	  			FALSE ： 不使能
  * 返回: 无。
  */
void FlexRM_Group_Enable(uint32_t Group, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FlexRM_GROUP_NUM(Group));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << Group;
	tmask = 1 << Group;
	FlexRM_CTL = SFR_Config(FlexRM_CTL, ~tmask, tmpreg);
}

/**
  * 描述: Group 功能选择位。
  * 输入: Group:   FlexRM_GROUP_0
  *                FlexRM_GROUP_1
  *                FlexRM_GROUP_2
  *                FlexRM_GROUP_3
  *                FlexRM_GROUP_4
  *                FlexRM_GROUP_5
  *                FlexRM_GROUP_6
  *                FlexRM_GROUP_7
  *                FlexRM_GROUP_8
  *                FlexRM_GROUP_9
  *                FlexRM_GROUP_10
  *                FlexRM_GROUP_11
  * 	  Port:    FlexRM_GROUPX_PORT0
  * 		       FlexRM_GROUPX_PORT1
  * 		       FlexRM_GROUPX_PORT2
  * 		       FlexRM_GROUPX_PORT3
  * 		       FlexRM_GROUPX_PORT4
  * 		       FlexRM_GROUPX_PORT5
  * 		       FlexRM_GROUPX_PORT6
  * 		       FlexRM_GROUPX_PORT7
  * 		       FlexRM_GROUPX_PORT8
  * 		       FlexRM_GROUPX_PORT9
  * 		       FlexRM_GROUPX_PORT10
  * 		       FlexRM_GROUPX_PORT11
  * 		       FlexRM_GROUPX_PORT12
  * 		       FlexRM_GROUPX_PORT13
  * 		       FlexRM_GROUPX_PORT14
  * 		       FlexRM_GROUPX_PORT15
  * 返回: 无。
  */
void FlexRM_Group_Function_Select(uint32_t Group, uint32_t Port)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FlexRM_GROUP_NUM(Group));
	CHECK_RESTRICTION(CHECK_FlexRM_GROUPX_PORT(Port));

	if(Group <= FlexRM_GROUP_7)
	{
		tmpreg = Port << Group*4;
		tmask = 0xF << Group*4;
		FlexRM_GPSR0 = SFR_Config(FlexRM_GPSR0, ~tmask, tmpreg);
	}
	else
	{
		tmpreg = Port << (Group - 8)*4;
		tmask = 0xF << (Group - 8)*4;
		FlexRM_GPSR1 = SFR_Config(FlexRM_GPSR1, ~tmask, tmpreg);
	}
}

/**
  * 描述: Group输出通道选择(CHx选择将Groupy输出)。
  * 输入:
  *   	  Group:   FlexRM_GROUP_0
  * 		       FlexRM_GROUP_1
  * 		       FlexRM_GROUP_2
  * 		       FlexRM_GROUP_3
  * 		       FlexRM_GROUP_4
  * 		       FlexRM_GROUP_5
  * 		       FlexRM_GROUP_6
  * 		       FlexRM_GROUP_7
  * 		       FlexRM_GROUP_8
  * 		       FlexRM_GROUP_9
  * 		       FlexRM_GROUP_10
  * 		       FlexRM_GROUP_11
  *
  * 	Channel:   FlexRM_CHANNEL_0
  *                FlexRM_CHANNEL_1
  *                FlexRM_CHANNEL_2
  *                FlexRM_CHANNEL_3
  *                FlexRM_CHANNEL_4
  *                FlexRM_CHANNEL_5
  *                FlexRM_CHANNEL_6
  *                FlexRM_CHANNEL_7
  *                FlexRM_CHANNEL_8
  *                FlexRM_CHANNEL_9
  *                FlexRM_CHANNEL_10
  *                FlexRM_CHANNEL_11
  * 返回: 无。
  */
void FlexRM_Group_Output_Select(uint32_t Group, uint32_t Channel)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FlexRM_CHANNEL_NUM(Channel));
	CHECK_RESTRICTION(CHECK_FlexRM_GROUP_NUM(Group));

	if(Channel <= 3)
	{
		tmpreg = Group << Channel*8;
		tmask = 0xF << Channel*8;
		FlexRM_GCSR0 = SFR_Config(FlexRM_GCSR0, ~tmask, tmpreg);
	}
	else if(Channel <= 7)
	{
		tmpreg = Group << (Channel - 4)*8;
		tmask = 0xF << (Channel - 4)*8;
		FlexRM_GCSR1 = SFR_Config(FlexRM_GCSR1, ~tmask, tmpreg);
	}
	else
	{
		tmpreg = Group << (Channel - 8)*8;
		tmask = 0xF << (Channel - 8)*8;
		FlexRM_GCSR2 = SFR_Config(FlexRM_GCSR2, ~tmask, tmpreg);
	}
}

/**
  * 描述: Group输入通道选择(CH0作为Groupx的输入信号)。
  * 输入:
  *   	  Group:   FlexRM_GROUP_0
  * 		       FlexRM_GROUP_1
  * 		       FlexRM_GROUP_2
  * 		       FlexRM_GROUP_3
  * 		       FlexRM_GROUP_4
  * 		       FlexRM_GROUP_5
  * 		       FlexRM_GROUP_6
  * 		       FlexRM_GROUP_7
  * 		       FlexRM_GROUP_8
  * 		       FlexRM_GROUP_9
  * 		       FlexRM_GROUP_10
  * 		       FlexRM_GROUP_11
  *
  * 	Channel:   FlexRM_CHANNEL_0
  *                FlexRM_CHANNEL_1
  *                FlexRM_CHANNEL_2
  *                FlexRM_CHANNEL_3
  *                FlexRM_CHANNEL_4
  *                FlexRM_CHANNEL_5
  *                FlexRM_CHANNEL_6
  *                FlexRM_CHANNEL_7
  *                FlexRM_CHANNEL_8
  *                FlexRM_CHANNEL_9
  *                FlexRM_CHANNEL_10
  *                FlexRM_CHANNEL_11
  * 返回: 无。
  */
void FlexRM_Group_Input_Select(uint32_t Group, uint32_t Channel)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FlexRM_CHANNEL_NUM(Channel));
	CHECK_RESTRICTION(CHECK_FlexRM_GROUP_NUM(Group));

	if(Group <= 3)
	{
		tmpreg = Channel << (FlexRM_GCSR0_G0CIS0_POS + Group*8);
		tmask = 0xF0 << (FlexRM_GCSR0_G0CIS0_POS + Group*8);
		FlexRM_GCSR0 = SFR_Config(FlexRM_GCSR0, ~tmask, tmpreg);
	}
	else if(Group <= 7)
	{
		tmpreg = Channel << (FlexRM_GCSR0_G0CIS0_POS + (Group - 4)*8);
		tmask = 0xF0 << (FlexRM_GCSR0_G0CIS0_POS + (Group - 4)*8);
		FlexRM_GCSR1 = SFR_Config(FlexRM_GCSR1, ~tmask, tmpreg);
	}
	else
	{
		tmpreg = Channel << (FlexRM_GCSR0_G0CIS0_POS + (Group - 8)*8);
		tmask = 0xF0 << (FlexRM_GCSR0_G0CIS0_POS + (Group - 8)*8);
		FlexRM_GCSR2 = SFR_Config(FlexRM_GCSR2, ~tmask, tmpreg);
	}
}


/**
  *   ##### 接口映射管理(FlexRM)配置函数定义结束 #####
  */
