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
  *   ##### ͨ����������˿�(GPIO)��ʼ�������ú��� #####
  **/

/**
  * ����  ��λGPIO���裬ʹ������ʱ�ӡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  * ����  �ޡ�
  **/
void GPIO_Reset (GPIO_SFRmap * GPIOx)
{
	/*����У��*/
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
  * ����  ͨ����������˿�(GPIO)��ʼ�����á�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       gpioInitStruct: GPIO������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  **/
void GPIO_Configuration (GPIO_SFRmap* GPIOx, GPIO_InitTypeDef* gpioInitStruct)
{
    uint32_t pinpos;
    uint32_t pos;
    uint32_t currentpin;
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(gpioInitStruct->m_Pin));
    CHECK_RESTRICTION(CHECK_GPIO_MODE(gpioInitStruct->m_Mode));
    CHECK_RESTRICTION(CHECK_GPIO_SPEED(gpioInitStruct->m_Speed));
    CHECK_RESTRICTION(CHECK_GPIO_PU(gpioInitStruct->m_PullUp));
    CHECK_RESTRICTION(CHECK_GPIO_PD(gpioInitStruct->m_PullDown));

    /* ����һ��������Ϣ */
    for (pinpos = 0x00; pinpos < 0x10; pinpos++)
    {
        pos = ((uint32_t)0x01) << pinpos;
        /* ��ȡ����λ����Ϣ */
        currentpin = (gpioInitStruct->m_Pin) & pos;

        if (currentpin == pos)
        {
            /*----------- ����GPIOx_PMOD�Ĵ��� -----------*/
            /* ���ݽṹ���Աm_Mode������PXPMDyλ�� */
            tmpreg = (((uint32_t)gpioInitStruct->m_Mode) << (pinpos * 2));
            GPIOx->PMOD = SFR_Config (GPIOx->PMOD,
                                  ~(GPIO_PMOD_PXPMD0 << (pinpos * 2)),
                                  tmpreg);

            if ((gpioInitStruct->m_Mode == GPIO_MODE_OUT)
                || (gpioInitStruct->m_Mode == GPIO_MODE_RMP))
            {
                /* GPIO��©���Ʋ���У�� */
                CHECK_RESTRICTION(CHECK_GPIO_POD(gpioInitStruct->m_OpenDrain));

                /*----------- ����GPIOx_PODR�Ĵ��� -----------*/
                /* ���ݽṹ���Աm_OpenDrain������PXPODRλ�� */
                tmpreg = (((uint32_t)gpioInitStruct->m_OpenDrain) << (pinpos));
                GPIOx->PODR = SFR_Config (GPIOx->PODR,
                                      ~(GPIO_PODR_PXPODR0 << pinpos),
                                      tmpreg);
            }
            else
            {
                ;
            }

            /*----------- ����GPIOx_OMOD�Ĵ��� -----------*/
            /* ���ݽṹ���Աm_Speed������PXOMDλ�� */
            tmpreg = ((uint32_t)gpioInitStruct->m_Speed) << (pinpos * 2);
            GPIOx->OMOD = SFR_Config (GPIOx->OMOD,
                                  ~(GPIO_OMOD_PXOMD0 << (pinpos * 2)),
                                  tmpreg);

            /*----------- ����GPIOx_PUR�Ĵ��� -----------*/
            /* ���ݽṹ���Աm_PullUp������PXPURλ�� */
            tmpreg = (((uint32_t)gpioInitStruct->m_PullUp) << (pinpos));
            GPIOx->PUR = SFR_Config (GPIOx->PUR,
                                  ~(GPIO_PUR_PXPUR0 << pinpos),
                                  tmpreg);

            /*----------- ����GPIOx_PDR�Ĵ��� -----------*/
            /* ���ݽṹ���Աm_PullDown������PXPDRλ�� */
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
  * ����  ��ʼ��GPIO������Ϣ�ṹ�塣
  * ����  gpioInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void GPIO_Struct_Init (GPIO_InitTypeDef* gpioInitStruct)
{
    /* ��ʼ�� GPIO�˿����� */
    gpioInitStruct->m_Pin  = GPIO_PIN_MASK_All;

    /* ��ʼ�� GPIO���ģʽ */
    gpioInitStruct->m_Mode = GPIO_MODE_AN;

    /* ��ʼ�� GPIO����ٶ� */
    gpioInitStruct->m_Speed = GPIO_LOW_SPEED;

    /* ��ʼ�� GPIO��©���� */
    gpioInitStruct->m_OpenDrain = GPIO_POD_PP;

    /* ��ʼ�� GPIO�������� */
    gpioInitStruct->m_PullUp = GPIO_NOPULL;

    /* ��ʼ�� GPIO�������� */
    gpioInitStruct->m_PullDown = GPIO_NOPULL;
}

/**
  * ����  ����GPIO�˿�������
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO�˿�����״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void GPIO_Pin_Lock_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState)
{
	uint32_t tmpreg = 0x5C5A0000;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	/* ����ԭʼ����״̬ */
	tmpreg |= GPIOx->LOCK;

	/* ��������/����״̬ */
	if(NewState != FALSE)
	{
		/* ���� */
		tmpreg |= (uint32_t)GpioPin;
	}
	else
	{
		/* ���� */
		tmpreg &= ~((uint32_t)GpioPin);
	}

    /*----------- ����GPIOx_LOCK�Ĵ���----------- */
    GPIOx->LOCK = tmpreg;
}

/**
  * ����  ����GPIO�˿�����ʹ�ܡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO�˿�����ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void GPIO_Pull_Up_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState)
{
	/*����У��*/
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	/* ----------- ����GPIOx_PUR�Ĵ��� ----------- */
	if(NewState != FALSE)
	{
		/* ʹ���������� */
		GPIOx->PUR |= (uint32_t)GpioPin;
	}
	else
	{
		/* ��ֹ�������� */
		GPIOx->PUR &= ~((uint32_t)GpioPin);
	}
}

/**
  * ����  ����GPIO�˿�����ʹ��ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void GPIO_Toggle_Pull_Up_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*----------- ����GPIOx_PUR�Ĵ��� -----------*/
	GPIOx->PUR ^= (uint32_t)GpioPin;
}

/**
  * ����  ����GPIO�˿�����ʹ�ܡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO�˿�����ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void GPIO_Pull_Down_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*----------- ����GPIOx_PDR�Ĵ��� -----------*/
	if(NewState != FALSE)
	{
		/* ʹ���������� */
		GPIOx->PDR |= (uint32_t)GpioPin;
	}
	else
	{
		/* ��ֹ�������� */
		GPIOx->PDR &= ~((uint32_t)GpioPin);
	}
}

/**
  * ����  ����GPIO�˿�����ʹ��ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void GPIO_Toggle_Pull_Down_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*----------- ����GPIOx_PUR�Ĵ��� -----------*/
	GPIOx->PDR ^= (uint32_t)GpioPin;
}

/**
  * ����  ����GPIO�˿ڿ�©������ơ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO��©�������״̬��ȡֵΪ��
  *                   GPIO_POD_PP: �������
  *                   GPIO_POD_OD: ��©���
  * ����  �ޡ�
  */
void GPIO_Open_Drain_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOPOD_TypeDef NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_GPIO_POD(NewState));

	/*----------- ����GPIOx_PODR�Ĵ��� -----------*/
	if(NewState != GPIO_POD_PP)
	{
		/* ��©��� */
		GPIOx->PODR |= (uint32_t)GpioPin;
	}
	else
	{
		/* ������� */
		GPIOx->PODR &= ~((uint32_t)GpioPin);
	}
}

/**
  * ����  ����GPIO�˿ڿ�©�������ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void GPIO_Toggle_Open_Drain_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

	/*----------- ����GPIOx_PODR�Ĵ��� -----------*/
	GPIOx->PODR ^= (uint32_t)GpioPin;
}

/**
  * ����  ����GPIO���ģʽ���ơ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO���ģʽ����״̬��ȡֵΪ��
  *                   GPIO_MODE_IN: ͨ��IO������ģʽ
  *                   GPIO_MODE_OUT: ͨ��IO�����ģʽ
  *                   GPIO_MODE_RMP: ��ӳ��IO�ڹ���ģʽ
  *                   GPIO_MODE_AN: ģ��ģʽ
  * ����  �ޡ�
  */
void GPIO_Write_Mode_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOMode_TypeDef NewState)
{
	uint32_t pinpos = 0x00;
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_GPIO_MODE(NewState));

	/*----------- ��ȡGPIOx_PMOD�Ĵ��� -----------*/
	tmpreg = GPIOx->PMOD;
	while(GpioPin)
	{
		if(GpioPin & (uint16_t)0x01)
		{
            /* ��¼������Ϣ */
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

    /*----------- ����GPIOx_PMOD�Ĵ��� -----------*/
    GPIOx->PMOD = tmpreg;
}

/**
  * ����  ����GPIO�˿�����ٶȿ��ơ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO�˿�����ٶȿ���״̬��ȡֵΪ��
  *                   GPIO_LOW_SPEED: 10MHZ
  *                   GPIO_HIGH_SPEED: 50MHZ
  * ����  �ޡ�
  */
void GPIO_Speed_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOSpeed_TypeDef NewState)
{
	uint32_t pinpos = 0x00;
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
	CHECK_RESTRICTION(CHECK_GPIO_SPEED(NewState));

    /*----------- ��ȡGPIOx_OMOD�Ĵ��� -----------*/
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

    /*----------- ����GPIOx_PMOD�Ĵ��� -----------*/
    GPIOx->OMOD = tmpreg;
}

/**
  * ����  ����GPIO�˿�����ٶȿ���ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void GPIO_Toggle_Speed_Config(GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	uint32_t pinpos = 0x00;
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
	CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

	/*----------- ��ȡGPIOx_OMOD�Ĵ��� -----------*/
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

    /*----------- ����GPIOx_PMOD�Ĵ��� -----------*/
    GPIOx->OMOD = tmpreg;
}

/**
  *   ##### ͨ����������˿�(GPIO)��ʼ�������ú���������� #####
  */


/**
  *   ##### ͨ����������˿�(GPIO)��д���� #####
  */

/**
  * ����  ��ȡGPIO�˿�ָ�����ŵ��������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: ָ���˿����ţ�ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�һ����
  * ����  ָ�����ŵ���Ϣ��1���߼��ߵ�ƽ��0���߼��͵�ƽ��
  */
BitAction GPIO_Read_Input_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*---------------- ��ȡGPIOx_PIR�Ĵ���PXPIRyλ ----------------*/
    tmpreg = (uint32_t)GpioPin;
    if ((GPIOx->PIR & tmpreg) != Bit_RESET)
    {
        /* �߼��ߵ�ƽ */
        return Bit_SET;
    }
    else
    {
        /* �߼��͵�ƽ */
        return Bit_RESET;
    }
}

/**
  * ����  ��ȡGPIO�˿��������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  * ����  �������ݣ�16λ��Ч���ݡ�
  */
uint16_t GPIO_Read_Input_Data (GPIO_SFRmap* GPIOx)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    /*---------------- ��ȡGPIOx_PIR�Ĵ��� ----------------*/
    tmpreg = GPIOx->PIR;

    return (uint16_t)tmpreg;
}

/**
  * ����  ��ȡGPIO�˿�ָ�����ŵ�������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: ָ���˿����ţ�ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�һ����
  * ����  ָ�����ŵ���Ϣ��1���߼��ߵ�ƽ��0���߼��͵�ƽ��
  */
BitAction GPIO_Read_Output_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*---------------- ��ȡGPIOx_POR�Ĵ���PXPORyλ ----------------*/
    tmpreg = (uint32_t)GpioPin;
    if ((GPIOx->POR & tmpreg) != Bit_RESET)
    {
        /* �߼��ߵ�ƽ */
        return Bit_SET;
    }
    else
    {
        /* �߼��͵�ƽ */
        return Bit_RESET;
    }
}

/**
  * ����  ��ȡGPIO�˿�������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  * ����  ������ݣ�16λ��Ч���ݡ�
  */
uint16_t
GPIO_Read_Output_Data (GPIO_SFRmap* GPIOx)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    /*---------------- ��ȡGPIOx_POR�Ĵ��� ----------------*/
    tmpreg = GPIOx->POR;

    return (uint16_t)tmpreg;
}

/**
  * ����  ����GPIO�˿�ָ�����ŵ�������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       BitsValue: ���ŵ�����ֵ��ȡֵΪ��
  *                    Bit_RESET: �߼��͵�ƽ
  *                    Bit_SET: �߼��ߵ�ƽ
  * ����  �ޡ�
  */
void GPIO_Set_Output_Data_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, BitAction BitsValue)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
    CHECK_RESTRICTION(CHECK_GPIO_BIT_ACTION(BitsValue));

    /*----------- ����GPIOx_POR�Ĵ��� -----------*/
    if (BitsValue != Bit_RESET)
    {
        /* �߼��ߵ�ƽ */
        GPIOx->POR |= (uint32_t)GpioPin;
    }
    else
    {
        /* �߼��͵�ƽ */
        GPIOx->POR &= ~((uint32_t)GpioPin);
    }
}

/**
  * ����  ����GPIO�˿�ָ�����ŵ��������ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void GPIO_Toggle_Output_Data_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    /*----------- ����GPIOx_POR�Ĵ��� -----------*/
    GPIOx->POR ^= (uint32_t)GpioPin;
}

/**
  *   ##### ͨ����������˿�(GPIO)��д����������� #####
  */


/**
  *   ##### ͨ����������˿�(GPIO)��ӳ�����ú��� #####
  */

/**
  * ����  ����GPIO�˿�������ӳ�䡣
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *      GpioPinNum: ָ���˿����ţ�ȡֵΪGPIO_Pin_Num_0~GPIO_Pin_Num_15�е�һ����
  *      PinRemap: ������ӳ��ѡ��ȡֵΪ��
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
  * ����  �ޡ�
  */
void GPIO_Pin_RMP_Config(GPIO_SFRmap* GPIOx, uint16_t GpioPinNum, uint32_t PinRemap)
{
    uint32_t tmask;
	uint32_t tmpreg;
    uint32_t PageNum = (PinRemap&0x300)>>8;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_NUM(GpioPinNum));

    /* ����GPIOx_RMP_MSB�Ĵ��� */
    tmask = ((uint32_t)1 << (GpioPinNum+16)) + ((uint32_t)1 << GpioPinNum);
    tmpreg = ((uint32_t)((PageNum-1)/2) << (GpioPinNum+16)) + ((uint32_t)((PageNum-1)%2) << GpioPinNum);
    GPIOx->RMP_MSB = SFR_Config(GPIOx->RMP_MSB,~tmask,tmpreg);

    /* ����GPIOx_RMPH\L�Ĵ��� */
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
  *   ##### ͨ����������˿�(GPIO)��ӳ�����ú���������� #####
  */


/**
  *   ##### �ӿ�ӳ�����(FlexRM)��ʼ�������ú��� #####
  **/

/**
  * ����: ��λFlexRM���裬ʹ������ʱ�ӡ�
  * ����: �ޡ�
  * ����: �ޡ�
  */
void FlexRM_Reset(void)
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FlexRMRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FlexRMRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_FlexRMCLKEN, TRUE);
}

/**
  * ����: CHxͨ������ѡ��
  * ����: Channel:
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
  * 	 Direction: FlexRM_AUTO �� CHx������/���������Ӳ���Զ�ѡ��
  * 	  			FlexRM_ONLY_INPUT �� CHx������������
  * ����: �ޡ�
  */
void FlexRM_Channel_Direction_Select(uint32_t Channel, uint32_t Direction)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FlexRM_CHANNEL_NUM(Channel));
	CHECK_RESTRICTION(CHECK_FlexRM_CHX_DIRECTION(Direction));

	tmpreg = Direction << (Channel+FlexRM_CTL_CH0TRSEL_POS);
	tmask = 1 << (Channel+FlexRM_CTL_CH0TRSEL_POS);
	FlexRM_CTL = SFR_Config(FlexRM_CTL, ~tmask, tmpreg);
}

/**
  * ����: Groupʹ�ܡ�
  * ����: Group:
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
  * 	  NewState: TRUE �� Groupxʹ��
  * 	  			FALSE �� ��ʹ��
  * ����: �ޡ�
  */
void FlexRM_Group_Enable(uint32_t Group, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FlexRM_GROUP_NUM(Group));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << Group;
	tmask = 1 << Group;
	FlexRM_CTL = SFR_Config(FlexRM_CTL, ~tmask, tmpreg);
}

/**
  * ����: Group ����ѡ��λ��
  * ����: Group:   FlexRM_GROUP_0
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
  * ����: �ޡ�
  */
void FlexRM_Group_Function_Select(uint32_t Group, uint32_t Port)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
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
  * ����: Group���ͨ��ѡ��(CHxѡ��Groupy���)��
  * ����:
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
  * ����: �ޡ�
  */
void FlexRM_Group_Output_Select(uint32_t Group, uint32_t Channel)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
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
  * ����: Group����ͨ��ѡ��(CH0��ΪGroupx�������ź�)��
  * ����:
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
  * ����: �ޡ�
  */
void FlexRM_Group_Input_Select(uint32_t Group, uint32_t Channel)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
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
  *   ##### �ӿ�ӳ�����(FlexRM)���ú���������� #####
  */
