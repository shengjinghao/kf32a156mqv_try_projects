/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_ecfgl.c                               	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Enhance Configurable logic 	  *
 *						unit (ECFGL) peripherals function              		  *
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

#include "kf32a1x6_ecfgl.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### �ɱ���߼�����(ECFGL)���ƹ��ܺ��� #####
  */
/**
  * ���� : ��λECFGLģ�飬ʹ������ʱ�ӡ�
  * ���� : �ޡ�
  * ���� : �ޡ�
  */
void ECFGL_Reset (void)
{
    /* ��λECFGLģ�� */
    RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_ECFGLRST, TRUE);
    RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_ECFGLRST, FALSE);
    /* ʹ��ECFGLʱ�� */
    PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_ECFGLPCLKEN, TRUE);
}
/**
  * ���� : ECFGL���ʹ�ܡ�
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 	 	NewState :
  * 	 				TRUE : ʹ��ECFGL���
  * 	 				FALSE : ��ֹECFGL���
  * ���� : �ޡ�
  */
void ECFGL_Output_Enable(uint32_t ECFGLx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << ECFGL_CTL_EN_POS;
	tmask = ECFGL_CTL_EN;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * ���� : �ɱ���߼����ӹ���ѡ��
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 	 	Function �� 	ECFGL_FUNCTION_0
  * 	 				ECFGL_FUNCTION_NOR
  * 	 				ECFGL_FUNCTION_B_AND_notA
  * 	 				ECFGL_FUNCTION_notA
  * 	 				ECFGL_FUNCTION_A_AND_notB
  * 	 				ECFGL_FUNCTION_notB
  * 	 				ECFGL_FUNCTION_EXOR
  * 	 				ECFGL_FUNCTION_NAND
  * 	 				ECFGL_FUNCTION_AND
  * 	 				ECFGL_FUNCTION_EXNOR
  * 	 				ECFGL_FUNCTION_B
  * 	 				ECFGL_FUNCTION_notA_OR_B
  * 	 				ECFGL_FUNCTION_A
  * 	 				ECFGL_FUNCTION_A_OR_notB
  * 	 				ECFGL_FUNCTION_OR
  * 	 				ECFGL_FUNCTION_1
  * ���� : �ޡ�
  */
void ECFGL_Function_Select(uint32_t ECFGLx, uint32_t Function)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_FUNCTION(Function));

	tmpreg = Function << ECFGL_CTL_FUNSEL0_POS;
	tmask = ECFGL_CTL_FUNSEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * ���� : MUX4����ѡ��
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 	 	Select �� 	ECFGL_MUX4IN_ECFGL_OUTPUT : ѡ��ɱ���߼����ӵ����
  * 	 				ECFGL_MUX4IN_ECFGL_OUTPUT_FLTER : ѡ��ɱ���߼����ӵ�������˲���������ź�
  * ���� : �ޡ�
  */
void ECFGL_MUX4IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX4IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX4SEL_POS;
	tmask = ECFGL_CTL_MUX4SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * ���� : MUX3����ѡ��
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 	 	Select �� 	ECFGL_MUX3IN_EXTERNAL_SINGLE : ѡ���ⲿ�ź�
  * 	 				ECFGL_MUX3IN_MUX1_OUTPUT : ѡ��MUX1�����
  * ���� : �ޡ�
  */
void ECFGL_MUX3IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX3IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX3SEL_POS;
	tmask = ECFGL_CTL_MUX3SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * ���� : MUX2����ѡ��
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 	 	Select �� 	ECFGL_MUX2IN_SOFTWARE : ѡ�����λ
  * 	 				ECFGL_MUX2IN_MUX0_OUTPUT : ѡ��MUX0�����
  * ���� : �ޡ�
  */
void ECFGL_MUX2IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX2IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX2SEL_POS;
	tmask = ECFGL_CTL_MUX2SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * ���� : MUX1����ѡ��
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 	 	Select �� 	ECFGL_MUX1IN_00 : ��ϸ���ü��û��ֲ�
  * 	 				ECFGL_MUX1IN_01 : ��ϸ���ü��û��ֲ�
  * 	 				ECFGL_MUX1IN_10 : ��ϸ���ü��û��ֲ�
  * 	 				ECFGL_MUX1IN_11 : ��ϸ���ü��û��ֲ�
  * ���� : �ޡ�
  */
void ECFGL_MUX1IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX1IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX1SEL0_POS;
	tmask = ECFGL_CTL_MUX1SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}
/**
  * ���� : MUX0����ѡ��
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 	 	Select �� 	ECFGL_MUX0IN_00 : ��ϸ���ü��û��ֲ�
  * 	 				ECFGL_MUX0IN_01 : ��ϸ���ü��û��ֲ�
  * 	 				ECFGL_MUX0IN_10 : ��ϸ���ü��û��ֲ�
  * 	 				ECFGL_MUX0IN_11 : ��ϸ���ü��û��ֲ�
  * ���� : �ޡ�
  */
void ECFGL_MUX0IN_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_ECFGL_MUX0IN(Select));

	tmpreg = Select << ECFGL_CTL_MUX0SEL0_POS;
	tmask = ECFGL_CTL_MUX0SEL;
	ECFGL_SFR->ECFGL_CTL[ECFGLx] = SFR_Config(ECFGL_SFR->ECFGL_CTL[ECFGLx], ~tmask, tmpreg);
}


/**
  * ���� : MUX2���ѡ��λʱ�����롣
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 	 	Select �� 	ECFGL_MUX2IN_0 : ��Ӧ��ģ��MUX2SEL=0ʱ��ѡ�����λ��MUX2����0
  * 	 				ECFGL_MUX2IN_1 : ��Ӧ��ģ��MUX2SEL=0ʱ��ѡ�����λ��MUX2����1
  * ���� : �ޡ�
  */
void ECFGL_MUX2IN_Software_Bit_Select(uint32_t ECFGLx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CEHCK_ECFGL_MUX2IN(Select));

	tmpreg = Select << ECFGLx;
	tmask = 1 << ECFGLx;
	ECFGL_SOFTSEL = SFR_Config(ECFGL_SOFTSEL, ~tmask, tmpreg);
}
/**
  * ���� : �˲�ʱ�ӷ�Ƶѡ��
  * ���� : 	ECFGL_DIV �� 	ECFGL_FLITER_DIV1 : 1��Ƶ
  *  			 		ECFGL_FLITER_DIV2 : 2��Ƶ
  *  			 		ECFGL_FLITER_DIV4 : 4��Ƶ
  *  			 		ECFGL_FLITER_DIV8 : 8��Ƶ
  *  			 		ECFGL_FLITER_DIV16 : 16��Ƶ
  * ���� : �ޡ�
  */
void ECFGL_Fliter_Clock_Div_Select(uint32_t ECFGL_DIV)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_FLITER_DIV(ECFGL_DIV));

	tmpreg = ECFGL_DIV << ECFGL_FCLK_FCLKDIV0_POS;
	ECFGL_FCLK = SFR_Config(ECFGL_FCLK, ~ECFGL_FCLK_FCLKDIV, tmpreg);
}
/**
  * ���� : �˲�ʱ��ѡ��
  * ���� : 	CLK �� 	ECFGL_CLK_SCLK : SCLK
  *  			 	ECFGL_CLK_HFCLK : HFCLK
  *  			 	ECFGL_CLK_LFCLK : LFCLK
  *  			 	ECFGL_CLK_CH1_TROUT : TRGMUX��CH1_TROUT
  *  			 	ECFGL_CLK_INTLF : INTLF
  * ���� : �ޡ�
  */
void ECFGL_Fliter_Clock_Select(uint32_t CLK)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_FLITER_CLK(CLK));

	ECFGL_FCLK = SFR_Config(ECFGL_FCLK, ~ECFGL_FCLK_FCLKSEL, CLK);
}
/**
  * ���� : ECFGLx�ж����㡣
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * ���� : ECFGLx�ж�����״̬��
  */
RetStatus ECFGLx_Clear_INT_Flag(uint32_t ECFGLx)
{
	uint32_t tmask;
	uint32_t wait_flag = 0x0000;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));

	tmask = 1 << ECFGLx;
	ECFGL_IC = SFR_Config(ECFGL_IC, ~tmask, tmask);
	while((ECFGL_IF & tmask)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	ECFGL_IC = SFR_Config(ECFGL_IC, ~tmask, 0);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * ���� : ��ȡECFGLx�жϱ�־��
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * ���� : 	0 �� ������
  *			1 �� ��Ӧ����ģ��	�������ж�
  */
FlagStatus ECFGLx_Get_INT_Flag(uint32_t ECFGLx)
{
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));

	tmask = 1 << ECFGLx;
	return ((ECFGL_IF & tmask) >> ECFGLx);
}
/**
  * ���� : ECFGLx���������ж�����
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 		Select :
  * 				TRUE : ECFGLx_IF ����ECFGLx_OUT����������ʱ��1
  * 				FALSE : ECFGLx_IF ������ECFGLx_OUT����������ʱ��1
  * ���� : 	�ޡ�
  */
void ECFGLx_Rise_INT_Enable(uint32_t ECFGLx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << ECFGLx;
	tmask = 1 << ECFGLx;
	ECFGL_RFCTL = SFR_Config(ECFGL_RFCTL, ~tmask, tmpreg);
}
/**
  * ���� : ECFGLx�½������ж�����
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * 		NewState :
  * 				TRUE : ECFGLx_IF ����ECFGLx_OUT�����½���ʱ��1
  * 				FALSE : ECFGLx_IF ������ECFGLx_OUT�����½���ʱ��1
  * ���� : 	�ޡ�
  */
void ECFGLx_Fall_INT_Enable(uint32_t ECFGLx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << ECFGLx;
	tmask = 1 << ECFGLx;
	ECFGL_FFCTL = SFR_Config(ECFGL_FFCTL, ~tmask, tmpreg);
}
/**
  * ���� :  ADC����ʹ�ܡ�
  * ���� : 	NewState :
  * 				TRUE �� ʹ��ECFGL����ADC�Ĺ���
  * 				FALSE : ������
  * ���� : 	�ޡ�
  */
void ECFGLx_Trigger_ADC_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << ECFGL_ADC_ADCTRIEN_POS;
	ECFGL_ADC = SFR_Config(ECFGL_ADC, ~ECFGL_ADC_ADCTRIEN, tmpreg);
}
/**
  * ���� :  ����Դѡ��
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * ���� : 	�ޡ�
  */
void ECFGLx_Trigger_ADC_Source_Select(uint32_t ECFGLx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));

	ECFGL_ADC = SFR_Config(ECFGL_ADC, ~ECFGL_ADC_ADCTRISEL, ECFGLx);
}
/**
  * ���� : ��ȡECFGLx���״̬��
  * ���� : 	ECFGLx : ��ΧECFGL0~ECFGL15��
  * ���� : 	0 �� ECFGLx���0
  *			1 �� ECFGLx���1
  */
FlagStatus ECFGLx_Get_ECFGLx_Output_Status(uint32_t ECFGLx)
{
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_ECFGL_ALL_MODULE(ECFGLx));

	tmask = 1 << ECFGLx;
	return ((ECFGL_OUT & tmask) >> ECFGLx);
}



