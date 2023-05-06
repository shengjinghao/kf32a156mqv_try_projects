/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_fdc.c                                 	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Flex Delay Controller (FDC) 	  *
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
#include "kf32a1x6_fdc.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### �ɱ����ʱģ��(FDC)��ʼ������ #####
  */

/**
  * ����: ��λFDC���裬ʹ������ʱ�ӡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * ����: �ޡ�
  */
void FDC_Reset(FDC_SFRmap* FDCx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	if(FDCx == FDC0_SFR)
	{
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC0RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC0RST, FALSE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_FDC0CLKEN, TRUE);
	}
	else if(FDCx == FDC1_SFR)
	{
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC1RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC1RST, FALSE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_FDC1CLKEN, TRUE);
	}
	else if(FDCx == FDC2_SFR)
	{
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC2RST, TRUE);
		RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_FDC2RST, FALSE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_FDC2CLKEN, TRUE);
	}
	else
	{
		;
	}
}
/**
  * ����: TRGI/SWTRIG �ź��� FDC ���������������и�λ����ֵʹ�ܡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 	  	NewState:
  * 	  			TRUE: ʹ��
  * 	  			FALSE: ��ʹ��
  * ����: �ޡ�
  */
void FDC_TRGI_Count_Reset_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_TCLR_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_TCLR, tmpreg);
}
/**
  * ����: ����FDC����ʱ��ѡ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 	  	CLK:
  * 	  			FDC_WORK_CLK_SCLK: ѡ��SCLK��ΪFDC�Ĺ���ʱ��
  * 	  			FDC_WORK_CLK_HFCLK: ѡ��HFCLK��ΪFDC�Ĺ���ʱ��
  * 	  			FDC_WORK_CLK_LFCLK: ѡ��LFCLK��ΪFDC�Ĺ���ʱ��
  * ����: �ޡ�
  */
void FDC_Work_Clk_Select(FDC_SFRmap* FDCx, uint32_t CLK)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_WORK_CLK(CLK));

	tmpreg = CLK << FDC_CTL_CLKSEL0_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_CLKSEL, tmpreg);
}
/**
  * ����: MDLIF��־λ�����
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 	  	NewState:
  * 	  			TRUE: ���MDLIF��־λ
  * 	  			FALSE: �����MDLIF��־λ
  * ����: �ޡ�
  */
RetStatus FDC_Clear_MDLIF_Flag(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t wait_flag = 0x0000;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_MDLIC_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_MDLIC, tmpreg);
	while((!(FDCx->CTL & FDC_CTL_MDLIC))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_MDLIC, 0);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * ����: ѭ��ɨ��CHmDLY�Ĵ���ʹ�ܡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 	  	NewState:
  * 	  			TRUE: ʹ��
  * 	  			FALSE: ��ʹ��
  * ����: �ޡ�
  */
void FDC_Cycle_Scan_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_CMODE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_CMODE, tmpreg);
}
/**
  * ����: FDC����ģʽѡ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 	  	MODE:
  * 	  			FDC_WORK_RANDOM: FDC���������ģʽ
  * 	  			FDC_WORK_FIXED: FDC�����ڶ���ģʽ
  * ����: �ޡ�
  */
void FDC_Work_Mode_Select(FDC_SFRmap* FDCx, uint32_t MODE)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_WORK_MODE(MODE));

	tmpreg = MODE << FDC_CTL_BBMODE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_BBMODE, tmpreg);
}
/**
  * ����: ����ģʽѡ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 	  	MODE:
  * 	  			FDC_UPDATA_NOW: ��LDOKдһ��BUF�е�ֵ�������µ��Ĵ�����
  * 	  			FDC_UPDATA_EQUAL_MODA1: ��LDOKдһ��BUF�е�ֵ��FDC����ֵ����MOD+1ʱ�����µ��Ĵ�����
  * 	  			FDC_UPDATA_TRIGGER�� ��LDOKдһ��BUF�е�ֵ�ڼ�⵽���봥������µ��Ĵ�����
  * 	  			FDC_UPDATA_TRIGGER_MODA1: ��LDOKдһ��BUF�е�ֵ�ڼ�⵽���봥������FDC����ֵ����MOD+1ʱ�����ɸ��µ��Ĵ�����
  * ����: �ޡ�
  */
void FDC_Updata_Mode_Select(FDC_SFRmap* FDCx, uint32_t MODE)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_UPDATA_MODE(MODE));

	tmpreg = MODE << FDC_CTL_LDMOD0_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_LDMOD, tmpreg);
}
/**
  * ����: FDC���д����ж�ʹ�ܡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 	  	NewState:
  * 	  			TRUE: ʹ��FDC���д����ж�
  * 	  			FALSE: ��ʹ��FDC���д����ж�
  * ����: �ޡ�
  */
void FDC_Sequence_Error_INT_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_FDCEIE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_FDCEIE, tmpreg);
}
/**
  * ����: ���������
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * ����: �ޡ�
  * ע�� ��FDCʹ�ܲ���ѡ�����������ΪFDC�Ĵ�������Դʱ����SWTRIGдһ����λFDC������ʹ�����¼�����
  */
void FDC_Software_Triggle_Enable(FDC_SFRmap* FDCx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_SWTRIG, FDC_CTL_SWTRIG);
}
/**
  * ����: MDL�ж�DMA����ʹ�ܡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		NewState:
  * 				TRUE: ʹ��MDLIF����DMA����
  * 				FALSE: ��ֹMDLIF����DMA����
  * ����: �ޡ�
  */
void FDC_MDL_INT_DMA_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_FDCDE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_FDCDE, tmpreg);
}
/**
  * ����: Ԥ��Ƶѡ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Select:
  * 				FDC_PRE_SCALER_MUL: ����ʱ��ѡ��1��MUL
  * 				FDC_PRE_SCALER_2MUL: ����ʱ��ѡ��1��2*MUL
  * 				FDC_PRE_SCALER_4MUL: ����ʱ��ѡ��1��4*MUL
  * 				FDC_PRE_SCALER_8MUL: ����ʱ��ѡ��1��8*MUL
  * 				FDC_PRE_SCALER_16MUL: ����ʱ��ѡ��1��16*MUL
  * 				FDC_PRE_SCALER_32MUL: ����ʱ��ѡ��1��32*MUL
  * 				FDC_PRE_SCALER_64MUL: ����ʱ��ѡ��1��64*MUL
  * 				FDC_PRE_SCALER_128MUL: ����ʱ��ѡ��1��128*MUL
  * ����: �ޡ�
  */
void FDC_Prescaler_Select(FDC_SFRmap* FDCx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_PRESCALER(Select));

	tmpreg = Select << FDC_CTL_PRESC0_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_PRESC, tmpreg);
}
/**
  * ����: ��Ƶ���ӡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Value: Value <= 0x3F
  * ����: �ޡ�
  */
void FDC_Scaler_Factor(FDC_SFRmap* FDCx, uint32_t Value)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_SCALER_FACTOR(Value));

	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_MULSEL, Value << FDC_CTL_MULSEL0_POS);
}
/**
  * ����: ��������Դѡ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Select: 	FDC_INPUT_TRIGGLE: ѡ������Դ����
  * 					FDC_SOFTWARE_TRIGGLE: ѡ���������
  * ����: �ޡ�
  */
void FDC_Triggle_Input_Select(FDC_SFRmap* FDCx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_INPUT_TRIGGLE(Select));

	tmpreg = Select << FDC_CTL_TRGSEL_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_TRGSEL, tmpreg);
}
/**
  * ����: MDL�ж�ʹ��λ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		NewState: 	TRUE: ����MDL�ж�ʹ��
  * 					FALSE: ��ֹMDL�ж�ʹ��
  * ����: �ޡ�
  */
void FDC_MDL_INT_Enable(FDC_SFRmap* FDCx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_INPUT_TRIGGLE(Select));

	tmpreg = Select << FDC_CTL_MDLIE_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_MDLIE, tmpreg);
}
/**
  * ����: ��ȡMDL�жϱ�־��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * ����: �ޡ�
  */
FlagStatus FDC_Get_MDL_INT_Flag(FDC_SFRmap* FDCx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	return ((FDCx->CTL & FDC_CTL_MDLIF) >> FDC_CTL_MDLIF_POS);
}
/**
  * ����: ����ģʽʹ�ܡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		NewState: 	TRUE: FDCѡ�񵥴�ģʽ
  * 					FALSE: FDCѡ������ģʽ
  * ����: �ޡ�
  */
void FDC_Single_Mode_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_CONT_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_CONT, tmpreg);
}
/**
  * ����: LDOKλд1��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * ����: �ޡ�
  */
void FDC_Ldok_Write1(FDC_SFRmap* FDCx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_LDOK, FDC_CTL_LDOK);
}
/**
  * ����: �������ʹ���źš�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		NewState: 	TRUE: ʹ�������������
  * 					FALSE: ��ʹ�������������
  * ����: �ޡ�
  */
void FDC_Pulse_Output_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << FDC_CTL_POEN_POS;
	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_POEN, tmpreg);
}
/**
  * ����: FDCģ��ʹ�ܡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		NewState: 	TRUE: ʹ�������������
  * 					FALSE: ��ʹ�������������
  * ����: �ޡ�
  */
void FDC_Enable(FDC_SFRmap* FDCx, FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	FDCx->CTL = SFR_Config(FDCx->CTL, ~FDC_CTL_FDCEN, FDC_CTL_FDCEN);
}


/**
  * ����: ����FDC�������ڡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Value: Value <= 0xFFFF
  * ����: �ޡ�
  */
void FDC_Set_Count_Cycle(FDC_SFRmap* FDCx, uint32_t Value)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_COUNT_CYCLE(Value));

	FDCx->MOD = Value;
}
/**
  * ����: ��ȡFDC�������ڡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * ����:  16λ�ļ������ڡ�
  */
uint16_t FDC_Get_Count_Cycle(FDC_SFRmap* FDCx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	return (FDCx->MOD & 0xFFFF);
}
/**
  * ����: ��ȡFDC��ǰ�ļ���ֵ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * ����:  16λ�ļ���ֵ��
  */
uint16_t FDC_Get_Count_Value(FDC_SFRmap* FDCx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	return (FDCx->CNT & 0xFFFF);
}
/**
  * ����: ��ȡFDC�ж���ʱ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * ����:  16λֵ��
  */
uint16_t FDC_Get_INT_Delay_Value(FDC_SFRmap* FDCx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));

	return (FDCx->IDLY & 0xFFFF);
}
/**
  * ����: FDCͨ�����д����־���㡣
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		n: n<=4
  * 		NewState:  	TRUE: ����ERRICn��־λ
  * 				   	FALSE: ������ERRICn��־λ
  * ����:  ��
  */
void FDC_Clear_Channel_List_Error_Flag(FDC_SFRmap* FDCx,uint32_t Channel, uint8_t n, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (FDC_CH0CTL_ERRIC0_POS + n);
	tmask = 1 << (FDC_CH0CTL_ERRIC0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0CTL = SFR_Config(FDCx->CH0CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1CTL = SFR_Config(FDCx->CH1CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2CTL = SFR_Config(FDCx->CH2CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3CTL = SFR_Config(FDCx->CH3CTL, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * ����: ��ȡFDCͨ�����д����־��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		n: n<=4
  * ����:  FDCͨ�����д����־
  */
FlagStatus FDC_Get_Channel_List_Error_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));

	tmpreg = FDC_CH0CTL_ERR0_POS + n;
	tmask = (uint32_t)1 << (FDC_CH0CTL_ERR0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		return ((FDCx->CH0CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_1:
		return ((FDCx->CH1CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_2:
		return ((FDCx->CH2CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_3:
		return ((FDCx->CH3CTL & tmask) >> tmpreg);
		break;
	default:break;
	}
}
/**
  * ����: ��ȡCFn��־��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		n: n<=4
  * ����:  CFn��־״̬
  */
FlagStatus FDC_Get_CFn_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));

	tmpreg = FDC_CH0CTL_CF0_POS + n;
	tmask = (uint32_t)1 << (FDC_CH0CTL_CF0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		return ((FDCx->CH0CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_1:
		return ((FDCx->CH1CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_2:
		return ((FDCx->CH2CTL & tmask) >> tmpreg);
		break;
	case FDC_CHANNLE_3:
		return ((FDCx->CH3CTL & tmask) >> tmpreg);
		break;
	default:break;
	}
}
/**
  * ����: ����FDCͨ��Ԥ�������ѡ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		n: n<=4
  * 		Select:     FDC_PRE_TRIGGLE_MODE0 :Ԥ�����ź��ڼ�⵽FDC�����ź������ػ���SWTRIG����һ��	��CNT����DLYnֵ�����
  * 					FDC_PRE_TRIGGLE_BYPASS :Ԥ�����ź��ڼ�⵽FDC�����ź������ػ���SWTRIG	����һ����������
  * ����:  ��
  */
void FDC_Channel_Pre_Triggle_Select(FDC_SFRmap* FDCx,uint32_t Channel, uint8_t n, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));
	CHECK_RESTRICTION(CHECK_FDC_PRE_TRIGGLE(Select));

	tmpreg = Select << (FDC_CH0CTL_TOS0_POS + n);
	tmask = 1 << (FDC_CH0CTL_TOS0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0CTL = SFR_Config(FDCx->CH0CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1CTL = SFR_Config(FDCx->CH1CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2CTL = SFR_Config(FDCx->CH2CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3CTL = SFR_Config(FDCx->CH3CTL, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * ����: ����FDCͨ������Ԥ�����ź�ʹ�ܡ�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		n: n<=4
  * 		NewState:   TRUE : ʹ��CHm����Ԥ�����ź�PREn
  * 					FALSE : ��ʹ��CHm����Ԥ�����ź�PREn
  * ����:  ��
  */
void FDC_Channel_Pre_Signel_Enable(FDC_SFRmap* FDCx,uint32_t Channel, uint8_t n, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_LIST_ERROR(n));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (FDC_CH0CTL_PREN0_POS + n);
	tmask = 1 << (FDC_CH0CTL_PREN0_POS + n);
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0CTL = SFR_Config(FDCx->CH0CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1CTL = SFR_Config(FDCx->CH1CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2CTL = SFR_Config(FDCx->CH2CTL, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3CTL = SFR_Config(FDCx->CH3CTL, ~tmask, tmpreg);
		break;
	default:break;
	}
}


/**
  * ����: ���� FDCͨ��m��ʱ�Ĵ���0, ��0��Ԥ�����ź��ӳ١�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		Value:   Value<=0xFFFF
  * ����:  ��
  */
void FDC_Channelm_Pre_Triggle_Delay0(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY0_DLY0_0_POS;
	tmask = FDC_CH0DLY0_DLY0;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY0 = SFR_Config(FDCx->CH0DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY0 = SFR_Config(FDCx->CH1DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY0 = SFR_Config(FDCx->CH2DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY0 = SFR_Config(FDCx->CH3DLY0, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * ����: ���� FDCͨ��m��ʱ�Ĵ���0, ��1��Ԥ�����ź��ӳ١�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		Value:   Value<=0xFFFF
  * ����:  ��
  */
void FDC_Channelm_Pre_Triggle_Delay1(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY0_DLY1_0_POS;
	tmask = FDC_CH0DLY0_DLY1;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY0 = SFR_Config(FDCx->CH0DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY0 = SFR_Config(FDCx->CH1DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY0 = SFR_Config(FDCx->CH2DLY0, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY0 = SFR_Config(FDCx->CH3DLY0, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * ����: ���� FDCͨ��m��ʱ�Ĵ���1, ��2��Ԥ�����ź��ӳ١�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		Value:   Value<=0xFFFF
  * ����:  ��
  */
void FDC_Channelm_Pre_Triggle_Delay2(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY1_DLY2_0_POS;
	tmask = FDC_CH0DLY1_DLY2;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY1 = SFR_Config(FDCx->CH0DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY1 = SFR_Config(FDCx->CH1DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY1 = SFR_Config(FDCx->CH2DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY1 = SFR_Config(FDCx->CH3DLY1, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * ����: ���� FDCͨ��m��ʱ�Ĵ���1, ��3��Ԥ�����ź��ӳ١�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		Value:   Value<=0xFFFF
  * ����:  ��
  */
void FDC_Channelm_Pre_Triggle_Delay3(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY1_DLY3_0_POS;
	tmask = FDC_CH0DLY1_DLY3;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY1 = SFR_Config(FDCx->CH0DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY1 = SFR_Config(FDCx->CH1DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY1 = SFR_Config(FDCx->CH2DLY1, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY1 = SFR_Config(FDCx->CH3DLY1, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * ����: ���� FDCͨ��m��ʱ�Ĵ���2, ��4��Ԥ�����ź��ӳ١�
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		Value:   Value<=0xFFFF
  * ����:  ��
  */
void FDC_Channelm_Pre_Triggle_Delay4(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL_PRE_TRIGGLE_DELAY(Value));

	tmpreg = Value << FDC_CH0DLY2_DLY4_0_POS;
	tmask = FDC_CH0DLY2_DLY4;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->CH0DLY2 = SFR_Config(FDCx->CH0DLY2, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->CH1DLY2 = SFR_Config(FDCx->CH1DLY2, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->CH2DLY2 = SFR_Config(FDCx->CH2DLY2, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->CH3DLY2 = SFR_Config(FDCx->CH3DLY2, ~tmask, tmpreg);
		break;
	default:break;
	}
}


/**
  * ����: ���� FDC���������ʱ�Ĵ����ĸ�λ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		Value:   Value<=0xFFFF
  * ����:  ��
  */
void FDC_Pulse_Output_DelayH(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_PULSE_OUTPUT_DELAY(Value));

	tmpreg = Value << FDC_PO0DLY_DLYH0_POS;
	tmask = FDC_PO0DLY_DLYH;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->PO0DLY = SFR_Config(FDCx->PO0DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->PO1DLY = SFR_Config(FDCx->PO1DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->PO2DLY = SFR_Config(FDCx->PO2DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->PO3DLY = SFR_Config(FDCx->PO3DLY, ~tmask, tmpreg);
		break;
	default:break;
	}
}
/**
  * ����: ���� FDC���������ʱ�Ĵ����ĵ�λ��
  * ����: 	FDC: ָ��FDC�ڴ�ṹ��ָ�룬ȡֵΪFDC0_SFR��FDC1_SFR��FDC2_SFR��
  * 		Channel: 	FDC_CHANNLE_0 : ͨ��0
  * 					FDC_CHANNLE_1 : ͨ��1
  * 					FDC_CHANNLE_2 : ͨ��2
  * 					FDC_CHANNLE_3 : ͨ��3
  * 		Value:   Value<=0xFFFF
  * ����:  ��
  */
void FDC_Pulse_Output_DelayL(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FDC_ALL_PERPH(FDCx));
	CHECK_RESTRICTION(CHECK_FDC_CHANNEL(Channel));
	CHECK_RESTRICTION(CHECK_FDC_PULSE_OUTPUT_DELAY(Value));

	tmpreg = Value << FDC_PO0DLY_DLYL0_POS;
	tmask = FDC_PO0DLY_DLYL;
	switch (Channel)
	{
	case FDC_CHANNLE_0:
		FDCx->PO0DLY = SFR_Config(FDCx->PO0DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_1:
		FDCx->PO1DLY = SFR_Config(FDCx->PO1DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_2:
		FDCx->PO2DLY = SFR_Config(FDCx->PO2DLY, ~tmask, tmpreg);
		break;
	case FDC_CHANNLE_3:
		FDCx->PO3DLY = SFR_Config(FDCx->PO3DLY, ~tmask, tmpreg);
		break;
	default:break;
	}
}





