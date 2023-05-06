/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_EWDT.c                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the External Watchdog (EWDT) 	  *
 *  				    peripherals function                          		  *
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

#include "kf32a1x6_ewdt.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### ��Χ���Ź�(EWDT)���ƹ��ܺ��� #####
  */
/**
  * ����  ��λEWDTģ�飬ʹ������ʱ�ӡ�
  * ����  �ޡ�
  * ����  �ޡ�
  */
void EWDT_Reset (void)
{
    /* ��λEWDTģ�� */
    RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_EWDTRST, TRUE);
    RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_EWDTRST, FALSE);
    /* ʹ��EWDTʱ�� */
    PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_EWDTCLKEN, TRUE);
}

/**
  * ����  EWDT����ʱ��ѡ��
  * ����  CLK �� 	EWDT_CLK_INTLF �� ѡ��INTLFΪ����ʱ��
  * 			EWDT_CLK_SCLK �� ѡ��SCLKΪ����ʱ��
  * 			EWDT_CLK_LFCLK �� ѡ��LFCLKΪ����ʱ��
  * 			EWDT_CLK_LP4M �� ѡ��LP4MΪ����ʱ��
  * ����  ��
  * ע�� �͹���ģʽ�½�����ѡ��INTLF��LP4M
  */
void EWDT_CLK_Select(uint32_t CLK)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EWDT_CLK(CLK));

	tmpreg = CLK << EWDT_CTL_CLKS0_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_CLKS, tmpreg);
}

/**
  * ����  ��Χ���Ź�Ԥ��Ƶ��
  * ����  DIV : 	EWDT_CLK_DIV1 		: EWDTCLKΪ��ѡʱ��
  * 			EWDT_CLK_DIV2 		: EWDTCLKΪ��ѡʱ��/2
  * 			EWDT_CLK_DIV4 		: EWDTCLKΪ��ѡʱ��/4
  * 			EWDT_CLK_DIV8 		: EWDTCLKΪ��ѡʱ��/8
  * 			EWDT_CLK_DIV16 		: EWDTCLKΪ��ѡʱ��/16
  * 			EWDT_CLK_DIV32 		: EWDTCLKΪ��ѡʱ��/32
  * 			EWDT_CLK_DIV64 		: EWDTCLKΪ��ѡʱ��/64
  * 			EWDT_CLK_DIV128 	: EWDTCLKΪ��ѡʱ��/128
  * 			EWDT_CLK_DIV256 	: EWDTCLKΪ��ѡʱ��/256
  * 			EWDT_CLK_DIV512 	: EWDTCLKΪ��ѡʱ��/512
  * 			EWDT_CLK_DIV1024 	: EWDTCLKΪ��ѡʱ��/1024
  * 			EWDT_CLK_DIV2048 	: EWDTCLKΪ��ѡʱ��/2048
  * 			EWDT_CLK_DIV4096 	: EWDTCLKΪ��ѡʱ��/4096
  * 			EWDT_CLK_DIV8192 	: EWDTCLKΪ��ѡʱ��/8192
  * 			EWDT_CLK_DIV16384 	: EWDTCLKΪ��ѡʱ��/16384
  * 			EWDT_CLK_DIV32768 	: EWDTCLKΪ��ѡʱ��/32768
  * 			EWDT_CLK_DIV65536 	: EWDTCLKΪ��ѡʱ��/65536
  * 			EWDT_CLK_DIV131072 	: EWDTCLKΪ��ѡʱ��/131072
  * 			EWDT_CLK_DIV262144 	: EWDTCLKΪ��ѡʱ��/262144
  * ����  ��
  */
void EWDT_Clock_Div_Select(uint32_t CLK_DIV)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EWDT_CLK_DIV(CLK_DIV));

	tmpreg = CLK_DIV << EWDT_CTL_WPS0_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_WPS, tmpreg);
}

/**
  * ���� EWDTIN�����źż���ѡ��
  * ����  Select : 	EWDT_INTPUT_EFFECTIVE_LOW : EWDTIN�����źŵ���Ч
  * 	 			EWDT_INTPUT_EFFECTIVE_HIGH : EWDTIN�����źŸ���Ч
  * ����  �ޡ�
  */
void EWDT_Input_Effective_Single_Select(uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EWDT_INTPUT_EFFECTIVE(Select));

	tmpreg = Select << EWDT_CTL_EWDTIN_POL_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_EWDTIN_POL, tmpreg);
}

/**
  * ���� EWDTIN�����ź�ʹ�ܡ�
  * ����  NewState : 	TRUE : EWDTIN�����ź�δʹ��
  * 	 			FALSE : EWDTIN�����ź�δʹ��
  * ����  �ޡ�
  */
void EWDT_Input_Single_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EWDT_CTL_EWDTIN_EN_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_EWDTIN_EN, tmpreg);
}

/**
  * ����  EWDT�������Ч�źż���ѡ��
  * ����  Select : 	EWDT_RESET_EFFECTIVE_LOW : EWDT�����ĸ�λ�źŵ���Ч
  * 	 			EWDT_RESET_EFFECTIVE_HIGH : EWDT�����ĸ�λ�źŸ���Ч
  * ����  �ޡ�
  */
void EWDT_Output_Effective_Single_Select(uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EWDT_RESET_EFFECTIVE(Select));

	tmpreg = Select << EWDT_CTL_OUTSEL_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_OUTSEL, tmpreg);
}

/**
  * ����  ��Χ���Ź��´������á�
  * ����  Threshold : Threshold <= 0x3F
  * ����  ��
  */
void EWDT_Threshold_Config(uint32_t Threshold)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EWDT_THRESHOLD(Threshold));

	tmpreg = Threshold << EWDT_CTL_WW0_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_WW, tmpreg);
}

/**
  * ���� ��Χ���Ź�ʹ�ܡ�
  * ����  NewState : 	TRUE : ʹ����Χ���Ź�����
  * 	 			FALSE : ��ֹ��Χ���Ź�����
  * ����  �ޡ�
  */
void EWDT_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_EWDTEN, NewState);
}

/**
  * ���� ��ȡ��Χ���Ź�����ֵ��
  * ���� ��
  * ����  EWDT�ļ���ֵ��
  */
uint8_t
EWDT_Get_Count_Value(void)
{
	return (EWDT_CNT & EWDT_CNT_WT0);
}

/**
  * ���� ������Χ���Ź�����ֵ��
  * ���� Value �� Value <= 0x3F
  * ����  �ޡ�
  */
void EWDT_Set_Count_Value(uint8_t Value)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EWDT_COUNT_VALUE(Value));

	EWDT_CNT = SFR_Config(EWDT_CNT, ~EWDT_CNT_WT0, Value);
}


/**
  *   ##### ��Χ���Ź�(EWDT)�жϺ��� #####
  */


/**
  * ����  EWDT������λ�ź��ж�ʹ�ܡ�
  * ����  NewState �� 	TRUE �� ʹ��EWDT������λ�źŴ����ж�
  * 					FALSE �� ��ֹEWDT������λ�źŴ����ж�
  * ����  ��
  */
void EWDT_Reset_Single_INT_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EWDT_CTL_EWDTRSTIE_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_EWDTRSTIE, tmpreg);
}

/**
  * ���� ������������40ʱ�ж�ʹ�ܡ�
  * ����  NewState : 	TRUE : ������������40ʱ�����ж�
  * 	 			FALSE : ��ֹ������������40ʱ�����ж�
  * ����  �ޡ�
  */
void EWDT_Count40_INT_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EWDT_CTL_WT40IE_POS;
	EWDT_CTL = SFR_Config(EWDT_CTL, ~EWDT_CTL_WT40IE, tmpreg);
}

/**
  * ����  ��ȡEWDT������λʱ���жϱ�־��
  * ����  ��
  * ����  0 �� EWDTδ������λ
  * 	 1 : EWDT������λ��
  */
FlagStatus EWDT_Get_Reset_INT_Flag(void)
{
	return ((EWDT_CTL & EWDT_CTL_EWDTRSTIF) >> EWDT_CTL_EWDTRSTIF_POS);
}

/**
  * ����  ��ȡ��Χ���Ź�������40�жϱ�־��
  * ����  ��
  * ����  ��
  */
FlagStatus EWDT_Get_Count40_INT_Flag(void)
{
	return ((EWDT_CTL & EWDT_CTL_WT40IF) >> EWDT_CTL_WT40IF_POS);
}

/**
  * ����  ����EWDT������λʱ�жϱ�־��
  * ����  ��
  * ����:���EWDT������λʱ�жϱ�־״̬
  */
RetStatus EWDT_Clear_Reset_INT_Flag(void)
{
	uint32_t wait_flag = 0x0000;
	SFR_SET_BIT_ASM(EWDT_CTL, EWDT_CTL_EWDTRSTIC_POS);
	while((EWDT_CTL & EWDT_CTL_EWDTRSTIF)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	SFR_CLR_BIT_ASM(EWDT_CTL, EWDT_CTL_EWDTRSTIC_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * ����  ���������������40ʱ�жϱ�־λ��
  * ����  ��
  * ����  :��������������жϱ�־״̬
  */
RetStatus EWDT_Clear_Count40_INT_Flag(void)
{
	uint32_t wait_flag = 0x0000;
	SFR_SET_BIT_ASM(EWDT_CTL, EWDT_CTL_WW40IC_POS);
	while((EWDT_CTL & EWDT_CTL_WT40IF)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	SFR_CLR_BIT_ASM(EWDT_CTL, EWDT_CTL_WW40IC_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}


