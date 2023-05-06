/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_hrcap.c                            	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the High precision capture 		  *
 *  				    peripherals function                              	  *
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

#include "kf32a1x6_hrcap.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### �߾��Ȳ�׽(HRCAP)���ƹ��ܺ��� #####
  */
/**
  * ���� : ��λHRCAPģ�飬ʹ������ʱ�ӡ�
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * ���� : �ޡ�
  */
void HRCAP_Reset (HRCAP_SFRmap* HRCAPx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));

	if(HRCAPx == HRCAP0_SFR)
	{
		/* ��λPLAģ�� */
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP0RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP0RST, FALSE);
		/* ʹ��PLAʱ�� */
		PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_HRCAP0CLKEN, TRUE);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		/* ��λPLAģ�� */
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP1RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP1RST, FALSE);
		/* ʹ��PLAʱ�� */
		PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_HRCAP1CLKEN, TRUE);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		/* ��λPLAģ�� */
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP2RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_HRCAP2RST, FALSE);
		/* ʹ��PLAʱ�� */
		PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_HRCAP2CLKEN, TRUE);
	}
	else
	{
		;
	}
}

/**
  * ���� : HRCAPxģ�鹤��ʱ��ѡ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  CLK : 	HRCAP_CLK_SCLK : SCLK
  * 	  			HRCAP_CLK_HFCLK : HFCLK
  * 	  			HRCAP_CLK_LFCLK : LFCLK
  * ���� : �ޡ�
  */
void HRCAP_CLK_Select(HRCAP_SFRmap* HRCAPx, uint32_t CLK)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CLK(CLK));

	tmpreg = CLK << HRCAP_CTL_CLKSEL0_POS;
	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_CTL = SFR_Config(HC0_CTL, ~HRCAP_CTL_CLKSEL, tmpreg);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_CTL = SFR_Config(HC1_CTL, ~HRCAP_CTL_CLKSEL, tmpreg);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_CTL = SFR_Config(HC2_CTL, ~HRCAP_CTL_CLKSEL, tmpreg);
	}
	else
	{
		;
	}
}

/**
  * ���� : HRCAPx�����λʹ�ܡ�
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  NewState : 	TRUE : ʹ��HRCAPx�����λ
  * 	  				FALSE : ��ֹHRCAPx�����λ
  * ���� : �ޡ�
  */
void HRCAP_Software_Reset_Enable(HRCAP_SFRmap* HRCAPx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << HRCAP_CTL_SOFTRESET_POS;
	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_CTL = SFR_Config(HC0_CTL, ~HRCAP_CTL_SOFTRESET, tmpreg);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_CTL = SFR_Config(HC1_CTL, ~HRCAP_CTL_SOFTRESET, tmpreg);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_CTL = SFR_Config(HC2_CTL, ~HRCAP_CTL_SOFTRESET, tmpreg);
	}
	else
	{
		;
	}
}

/**
  * ���� : HRCAPx�ж�ʹ�ܡ�
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  Select : 		HRCAP_COUNTOVER_INT : HRCAPx��������ж�
  * 	  				HRCAP_FALL_INT : HRCAPx�½��ز�׽�ж�
  * 	  				HRCAP_RISE_INT : HRCAPx�����ز�׽�ж�
  * 	  NewState : 	TRUE : ʹ��HRCAPx�����λ
  * 	  				FALSE : ��ֹHRCAPx�����λ
  * ���� : �ޡ�
  */
void HRCAP_INT_Enable(HRCAP_SFRmap* HRCAPx,uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_INT(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (HRCAP_CTL_RISEINTE_POS + Select);
	tmask = 1 << (HRCAP_CTL_RISEINTE_POS + Select);
	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_CTL = SFR_Config(HC0_CTL, ~tmask, tmpreg);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_CTL = SFR_Config(HC1_CTL, ~tmask, tmpreg);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_CTL = SFR_Config(HC2_CTL, ~tmask, tmpreg);
	}
	else
	{
		;
	}
}

/**
  * ���� : HRCAPx��׽����ѡ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  Select : 		HRCAP_EXTERNAL_INPUT : ѡ��ר�õ�HRCAPx�ⲿ��������
  * 	  				HRCAP_HRPWMX_OUTPUT : ѡ���Ӧ��HRPWMx����ź�
  * ���� : �ޡ�
  */
void HRCAP_Cap_Input_Select(HRCAP_SFRmap* HRCAPx, uint32_t Select)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_INPUT(Select));

	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_CTL = SFR_Config(HC0_CTL, ~HRCAP_CTL_HCINSEL, Select);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_CTL = SFR_Config(HC1_CTL, ~HRCAP_CTL_HCINSEL, Select);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_CTL = SFR_Config(HC2_CTL, ~HRCAP_CTL_HCINSEL, Select);
	}
	else
	{
		;
	}
}

/**
  * ���� : ��ȡ16λ�ľ�������֮���HRCAPx��������ֵ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * ���� : 16λ�ļ���ֵ��
  * ע���Ƽ�ʹ�ô˺�����ȡHRCAPx��������ֵ��
  */
uint16_t HRCAP_Read_Latch_Count_Value(HRCAP_SFRmap* HRCAPx)
{
	uint32_t Value = 0;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));

	if(HRCAPx == HRCAP0_SFR)
	{
		Value = (HC0_COUNTER & HRCAP_COUNTER_COUNTERSR) >> HRCAP_COUNTER_COUNTERSR0_POS;
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		Value = (HC1_COUNTER & HRCAP_COUNTER_COUNTERSR) >> HRCAP_COUNTER_COUNTERSR0_POS;
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		Value = (HC2_COUNTER & HRCAP_COUNTER_COUNTERSR) >> HRCAP_COUNTER_COUNTERSR0_POS;
	}
	else
	{
		;
	}

	return Value;
}

/**
  * ���� : ��ȡ16λ��HRCAPx��������ֵ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * ���� : 16λ�ļ���ֵ��
  */
uint16_t HRCAP_Read_Count_Value(HRCAP_SFRmap* HRCAPx)
{
	uint32_t Value = 0;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));

	if(HRCAPx == HRCAP0_SFR)
	{
		Value = HC0_COUNTER & HRCAP_COUNTER_COUNTER;
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		Value = HC1_COUNTER & HRCAP_COUNTER_COUNTER;
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		Value = HC2_COUNTER & HRCAP_COUNTER_COUNTER;
	}
	else
	{
		;
	}

	return Value;
}

/**
  * ���� : ��ȡ16λ��HRCAPx������������׽�Ĵ�����ֵ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  HRCAP_REG ��    HRCAP_REGISTER0 : �Ĵ���0
  * 	  				HRCAP_REGISTER1 : �Ĵ���1
  * ���� : 16λ��ֵ��
  */
uint16_t HRCAP_Read_Rise_Integer_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG)
{
	uint32_t Value = 0;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_REGISTER(HRCAP_REG));

	Value = HRCAPx->RISE[HRCAP_REG] & HRCAP_RISE0_RISE0;

	return Value;
}

/**
  * ���� : ��ȡ16λ��HRCAPx�½���������׽�Ĵ�����ֵ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  HRCAP_REG ��    HRCAP_REGISTER0 : �Ĵ���0
  * 	  				HRCAP_REGISTER1 : �Ĵ���1
  * ���� : 16λ��ֵ��
  */
uint16_t HRCAP_Read_Fall_Integer_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG)
{
	uint32_t Value = 0;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_REGISTER(HRCAP_REG));

	Value = HRCAPx->FALL[HRCAP_REG] & HRCAP_FALL0_FALL0;

	return Value;
}

/**
  * ���� : ��ȡ16λ��HRCAPx������С����׽�Ĵ�����ֵ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  HRCAP_REG ��    HRCAP_REGISTER0 : �Ĵ���0
  * 	  				HRCAP_REGISTER1 : �Ĵ���1
  * ���� : 16λ��ֵ��
  */
uint16_t HRCAP_Read_Rise_Decimal_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG)
{
	uint32_t Value = 0;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_REGISTER(HRCAP_REG));

	Value = HRCAPx->HRRISE[HRCAP_REG] & HRCAP_HRRISE0_HRRISE0;

	return Value;
}

/**
  * ���� : ��ȡ16λ��HRCAPx�½���С����׽�Ĵ�����ֵ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  HRCAP_REG ��    HRCAP_REGISTER0 : �Ĵ���0
  * 	  				HRCAP_REGISTER1 : �Ĵ���1
  * ���� : 16λ��ֵ��
  */
uint16_t HRCAP_Read_Fall_Decimal_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG)
{
	uint32_t Value = 0;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_CAP_REGISTER(HRCAP_REG));

	Value = HRCAPx->HRFALL[HRCAP_REG] & HRCAP_HRFALL0_HRFALL0;

	return Value;
}

/**
  * ���� : ��ȡHRCAPx�жϱ�־λ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  Select : 	HRCAP_RISEOVER_INT : �����ز�׽�ж�����¼�
  * 	  			HRCAP_COUNTOVER_INT : ��������¼�
  * 	  			HRCAP_FALL_INT : �½��ز�׽�ж��¼�
  * 	  			HRCAP_RISE_INT : �����ز�׽�ж��¼�
  * ���� : 0 : ���ж��¼�����
  * 	  1  �� �����ж��¼���
  */
FlagStatus HRCAP_Get_INT_Flag(HRCAP_SFRmap* HRCAPx, uint32_t Select)
{
	uint32_t Value = 0;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_INT_FLAG(Select));

	Select += HRCAP_SR_RISEIF_POS;
	tmask = 1 << Select;
	if(HRCAPx == HRCAP0_SFR)
	{
		Value = (HC0_SR & tmask) >> Select;
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		Value = (HC1_SR & tmask) >> Select;
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		Value = (HC2_SR & tmask) >> Select;
	}
	else
	{
		;
	}

	return Value;
}

/**
  * ���� : ���HRCAPx�жϱ�־λ��
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  Select : 	HRCAP_RISEOVER_INT : �����ز�׽�ж�����¼�
  * 	  			HRCAP_COUNTOVER_INT : ��������¼�
  * 	  			HRCAP_FALL_INT : �½��ز�׽�ж��¼�
  * 	  			HRCAP_RISE_INT : �����ز�׽�ж��¼�
  * ���� : ���HRCAPx�жϱ�־λ�Ƿ�ɹ�
  */
RetStatus HRCAP_Clear_INT_Flag(HRCAP_SFRmap* HRCAPx, uint32_t Select)
{
	uint32_t tmask;
	uint32_t wait_flag=0x0000;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_INT_FLAG(Select));


	tmask = 1 << (Select+HRCAP_SRIC_RISEIC_POS);

	HRCAPx->SRIC = SFR_Config(HRCAPx->SRIC, ~tmask, tmask);
	while((HRCAPx->SR & tmask)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	HRCAPx->SRIC = SFR_Config(HRCAPx->SRIC, ~tmask, 0);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * ���� : HRCAPx�жϱ�־λǿ����λʹ�ܡ�
  * ���� : HRCAPx : 	HRCAP0_SFR��HRCAP1_SFR��HRCAP2_SFR
  * 	  Select : 	HRCAP_COUNTOVER_INT : ��������¼�
  * 	  			HRCAP_FALL_INT : �½��ز�׽�ж��¼�
  * 	  			HRCAP_RISE_INT : �����ز�׽�ж��¼�
  * 	  NewState : TRUE : ǿ����λ
  * 	  			 FALSE : �޶���
  */
void HRCAP_INT_Mandatory_Enable(HRCAP_SFRmap* HRCAPx, uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_HRCAP_ALL_PERIPH(HRCAPx));
	CHECK_RESTRICTION(CHECK_HRCAP_MANDATORY_INT(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (Select + HRCAP_IFRC_RISEIFRC_POS);
	tmask = 1 << (Select + HRCAP_IFRC_RISEIFRC_POS);

	if(HRCAPx == HRCAP0_SFR)
	{
		HC0_IFRC = SFR_Config(HC0_IFRC, ~tmask, tmpreg);
	}
	else if(HRCAPx == HRCAP1_SFR)
	{
		HC1_IFRC = SFR_Config(HC1_IFRC, ~tmask, tmpreg);
	}
	else if(HRCAPx == HRCAP2_SFR)
	{
		HC2_IFRC = SFR_Config(HC2_IFRC, ~tmask, tmpreg);
	}
	else
	{
		;
	}
}


