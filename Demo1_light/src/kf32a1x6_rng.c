/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_rng.c                               	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Random number generator(RNG)   *
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

#include "kf32a1x6_rng.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"

/**
  * ����: ��λRNG���裬ʹ������ʱ�ӡ�
  * ����: �ޡ�
  * ����: �ޡ�
  */
void RNG_Reset(void)
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_RNGRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_RNGRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_RNGCLKEN, TRUE);
}
/**
  * ����: �������ģʽʹ�ܡ�
  * ����: 	NewState:
  * 				TRUE : ģ�鹤�����������ģʽ
  * 				FALSE �� ģ�鹤����α�����ģʽ
  * ����: �ޡ�
  */
void RNG_Real_RNG_Mode_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_TRNGMS, NewState << RNG_CTL_TRNGMS_POS);
}
/**
  * ����: ��������ӽ���ʹ�ܡ�
  * ����: 	NewState:
  * 				TRUE : ʹ������������ӽ���
  * 				FALSE �� ��ֹ����������ӽ���
  * ����: �ޡ�
  */
void RNG_Real_RNG_Seed_Correct_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_RECEN, NewState << RNG_CTL_RECEN_POS);
}
/**
  * ����: ��������ӷ������߹���ʹ�ܡ�
  * ����: 	NewState:
  * 				TRUE : ʹ�ܸ߹���ģʽ
  * 				FALSE ����ֹ�߹���ģʽ
  * ����: �ޡ�
  */
void RNG_Real_RNG_Seed_High_Pow_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_HIPOW, NewState << RNG_CTL_HIPOW_POS);
}
/**
  * ����: ��������ӷ�����Ƶ��У׼��
  * ����: 	Select:
  * 				RNG_FREQUENCY_CALI_GEAR0 : ��λ0
  * 				RNG_FREQUENCY_CALI_GEAR1 : ��λ1
  * 				RNG_FREQUENCY_CALI_GEAR2 : ��λ2
  * 				RNG_FREQUENCY_CALI_GEAR3 : ��λ3
  * ����: �ޡ�
  */
void RNG_Real_RNG_Seed_Frequency_Cail_Select(uint32_t Select)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_RNG_FREQUENCY_CALI_GEAR(Select));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_ADD, Select << RNG_CTL_ADD0_POS);
}
/**
  * ����: ������������ʹ�ܡ�
  * ����: 	NewState:
  * 				TRUE : ʹ������������������
  * 				FALSE ����ֹ����������������
  * ����: �ޡ�
  */
void RNG_Real_RNG_Seed_Output_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_TSEEDGO, NewState << RNG_CTL_TSEEDGO_POS);
}
/**
  * ����: ��������ӷ�����ʹ�ܡ�
  * ����: 	NewState:
  * 				TRUE : ʹ����������ӷ���������
  * 				FALSE ����ֹ��������ӷ���������
  * ����: �ޡ�
  */
void RNG_Real_RNG_Seed_Generator_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_TSEEDEN, NewState << RNG_CTL_TSEEDEN_POS);
}
/**
  * ����: RNG ʱ�ӷ�Ƶ���ơ�
  * ����: 	DIV:
  * 				RNG_CLK_DIV1 : 1��Ƶ
  * 				RNG_CLK_DIV2 : 2��Ƶ
  * 				RNG_CLK_DIV4 : 4��Ƶ
  * 				RNG_CLK_DIV8 : 8��Ƶ
  * 				RNG_CLK_DIV16 : 16��Ƶ
  * 				RNG_CLK_DIV32 : 32��Ƶ
  * 				RNG_CLK_DIV64 : 64��Ƶ
  * 				RNG_CLK_DIV128 : 128��Ƶ
  * 				RNG_CLK_DIV256 : 256��Ƶ
  * 				RNG_CLK_DIV512 : 512��Ƶ
  * 				RNG_CLK_DIV1024 : 1024��Ƶ
  * 				RNG_CLK_DIV2048 : 2048��Ƶ
  * 				RNG_CLK_DIV4096 : 4096��Ƶ
  * 				RNG_CLK_DIV8192 : 8192��Ƶ
  * 				RNG_CLK_DIV16384 : 16384��Ƶ
  * 				RNG_CLK_DIV32768 : 32768��Ƶ
  * ����: �ޡ�
  */
void RNG_CLK_DIV_Select(uint32_t DIV)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_RNG_CLK_DIV(DIV));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_CLKDIV, DIV << RNG_CTL_CLKDIV0_POS);
}
/**
  * ����: RNG����ʱ��Դѡ��
  * ����: 	CLK:
  * 				RNG_CLK_SCLK : ѡ��SCLK��ΪRNGģ�鹤��ʱ��
  * 				RNG_CLK_HFCLK : ѡ��HFCLK��ΪRNGģ�鹤��ʱ��
  * 				RNG_CLK_LFCLK : ѡ��LFCLK��ΪRNGģ�鹤��ʱ��
  * 				RNG_CLK_INTLF : ѡ��INTLF��ΪRNGģ�鹤��ʱ��
  * ����: �ޡ�
  */
void RNG_Work_CLK_Select(uint32_t CLK)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_RNG_CLK(CLK));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_CLKS, CLK << RNG_CTL_CLKS0_POS);
}
/**
  * ����: �������ѡ��
  * ����: 	Seed:
  * 				RNG_SEED_CPU : �����������CPUд��
  * 				RNG_SEED_REAL : �������������������ӷ�����
  * ����: �ޡ�
  */
void RNG_Seed_Select(uint32_t Seed)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_RNG_SEED(Seed));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_RNGSEL, Seed << RNG_CTL_RNGSEL_POS);
}
/**
  * ����: RNGʹ�ܡ�
  * ����: 	NewState:
  * 				TRUE : ʹ��RNG
  * 				FALSE : ��ʹ��
  * ����: �ޡ�
  */
void RNG_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	RNG_CTL = SFR_Config(RNG_CTL, ~RNG_CTL_RNGEN, NewState);
}


/**
  * ����: ������ĵ�ǰ����״̬��
  * ����: ��
  * ����: 	0������32��λ������ͬλ��0��1��
  * 		1������32λ���������0��1��0101010...��
  */
FlagStatus RNG_Get_Current_Error_Status(void)
{
	return ((RNG_STATE & RNG_STATE_DEIS) >> RNG_STATE_DEIS_POS);
}
/**
  * ����: �жϱ�־ʹ�ܡ�
  * ����: Select : 	RNG_INT_TSR �� ����������Ӿ����жϱ�־
  * 				RNG_INT_DR �� ��������ݾ����жϱ�־
  * 				RNG_INT_DE �� ����������жϱ�־
  * 	  NewState��TRUE : ʹ��
  * 	  			FALSE : ������
  * ����: ��
  */
void RNG_INT_Enable(uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_RNG_INT(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (RNG_STATE_DEIE_POS + Select);
	tmask = (uint32_t)1 << (RNG_STATE_DEIE_POS + Select);
	RNG_STATE = SFR_Config(RNG_STATE, ~tmask, tmpreg);
}
/**
  * ����: �жϱ�־���㡣
  * ����: Select : 	RNG_INT_TSR �� ����������Ӿ����жϱ�־
  * 				RNG_INT_DR �� ��������ݾ����жϱ�־
  * 				RNG_INT_DE �� ����������жϱ�־
  * ����: �жϱ�־�����Ƿ�ɹ�״̬
  */
RetStatus RNG_Clear_INT_Flag(uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;
	uint32_t wait_flag=0x0000;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_RNG_INT(Select));

	tmpreg = (uint32_t)1 << (RNG_STATE_DEIC_POS + Select);
	tmask = (uint32_t)1 << (RNG_STATE_DEIC_POS + Select);
	RNG_STATE = SFR_Config(RNG_STATE, ~tmask, tmpreg);
	while((RNG_STATE & ((uint32_t)1<<Select))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	RNG_STATE = SFR_Config(RNG_STATE, ~tmask, FALSE);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * ����: ��ȡ�жϱ�־��
  * ����: Select : 	RNG_INT_TSR �� ����������Ӿ����жϱ�־
  * 				RNG_INT_DR �� ��������ݾ����жϱ�־
  * 				RNG_INT_DE �� ����������жϱ�־
  * ����: 0 ��δ������û�д���
  * 	  1 : ����(����)
  */
FlagStatus RNG_Get_INT_Flag(uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_RNG_INT(Select));

	tmask = (uint32_t)1 << Select;
	return ((RNG_STATE & tmask) >> Select);
}
/**
  * ����: ��ȡ��������ӡ�
  * ���룺��
  * ����: 16λ���������
  */
uint16_t RNG_Seed_Value(void)
{
	return (RNG_SEED & 0xFFFF);
}
/**
  * ����: ��ȡ��������ӡ�
  * ���룺��
  * ����: 16λ���������
  */
uint32_t RNG_Data_Value(void)
{
	return RNG_DR;
}



