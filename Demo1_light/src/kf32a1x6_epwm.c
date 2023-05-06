/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_epwm.c                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the enhanced pulse width modulation*
 *						(EPWM) peripherals function              		  	  *
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


#include "kf32a1x6_epwm.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### ��ʼ�������ú��� #####
  */

/**
  * ����  EPWM���踴λ��ʹ������ʱ�ӡ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����  �ޡ�
  */
void EPWM_Reset (EPWM_SFRmap* EPWMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    if (EPWMx == EPWM11_SFR)
    {
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM11TRST, TRUE);
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM11TRST, FALSE);
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_EPWM11CLKEN, TRUE);
    }
    else if (EPWMx == EPWM12_SFR)
    {
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM12TRST, TRUE);
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM12TRST, FALSE);
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_EPWM12CLKEN, TRUE);
    }
    else if (EPWMx == EPWM13_SFR)
    {
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM13TRST, TRUE);
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM13TRST, FALSE);
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_EPWM13CLKEN, TRUE);
    }
    else if (EPWMx == EPWM16_SFR)
    {
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM16TRST, TRUE);
    	RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_EPWM16TRST, FALSE);
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_EPWM16CLKEN, TRUE);
    }
    else
    {
    	;
    }
}
/**
  * ����  ����32λ��Tx��ʱ����ֵ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 Value �� Value <= 0xFFFFFFFF;
  * ����  �ޡ�
  */
void EPWM_TxCNT_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
    CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

    EPWMx->CNT = Value;
}
/**
  * ����  ��ȡ32λ��Tx��ʱ����ֵ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����  32λ��ֵ��
  */
uint32_t EPWM_Get_TxCNT_Value(EPWM_SFRmap* EPWMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    return EPWMx->CNT;
}
/**
  * ����  ����32λTx��ʱ������λ�Ĵ�����ֵ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 Value �� Value <= 0xFFFFFFFF;
  * ����  �ޡ�
  */
void EPWM_TxPHS_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
    CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

    EPWMx->PHS = Value;
}
/**
  * ����  ��ȡ32λTx��ʱ������λ�Ĵ�����ֵ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����  32λ��ֵ��
  */
uint32_t EPWM_Get_TxPHS_Value(EPWM_SFRmap* EPWMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    return EPWMx->PHS;
}
/**
  * ����  ����32λTx��ʱ�������ڼĴ�����ֵ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 Value �� Value <= 0xFFFFFFFF;
  * ����  �ޡ�
  */
void EPWM_TxPPX_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
    CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

    EPWMx->PPX = Value;
}
/**
  * ����  ��ȡ32λTx��ʱ�������ڼĴ�����ֵ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����  32λ��ֵ��
  */
uint32_t EPWM_Get_TxPPX_Value(EPWM_SFRmap* EPWMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    return EPWMx->PPX;
}
/**
  * ����  ����32λTx��ʱ��Ԥ��Ƶ����ֵ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 Value �� Value <= 0xFFFFFFFF;
  * ����  �ޡ�
  * ע����Ƶֵ = Value + 1;
  */
void EPWM_TxPRSC_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
    CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

    EPWMx->PRSC = Value;
}
/**
  * ����  ��ȡ32λTx��ʱ��Ԥ��Ƶ����ֵ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����  32λ��ֵ��
  */
uint32_t EPWM_Get_TxPRSC_Value(EPWM_SFRmap* EPWMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

    return EPWMx->PRSC;
}


/**
  * ����  ��Ӧ��һ��EPWM���͵ĵ�LINK����ʹ�ܡ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : TRUE : ����Ĵ���ʹ��LINK����
  * 	 			FALSE : ��ֹ�Ĵ���ʹ��LINK����
  * ����  �ޡ�
  */
void EPWM_Response_UpperLevel_LINK_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_BLINKEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_BLINKEN, tmpreg);
}
/**
  * ����  ����һ��PEWM����LINK����ʹ�ܡ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : TRUE : ����LINK����
  * 	 			FALSE : ������LINK����
  * ����  �ޡ�
  */
void EPWM_NextLevel_LINK_Ask_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_LINKEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_LINKEN, tmpreg);
}
/**
  * ����  ͬ���źŴ�������ʹ�ܡ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : TRUE : ����ͬ�������źŴ�������
  * 	 			FALSE : ��ֹͬ�������źŴ�������
  * ����  �ޡ�
  */
void EPWM_SYNC_Single_Trigger_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_UDSYNEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_UDSYNEN, tmpreg);
}
/**
  * ����  ��ģ��Ĵ��������á�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 Select : 	EPWM_SUBMODULE_HRPWM_LOCK 		: HRPWM��ģ��Ĵ���
  * 	 			EPWM_SUBMODULE_ET_LOCK 			: ET��ģ��Ĵ���
  * 	 			EPWM_SUBMODULE_PC_LOCK 			: PC��ģ��Ĵ���
  * 	 			EPWM_SUBMODULE_DB_LOCK 			: DB��ģ��Ĵ���
  * 	 			EPWM_SUBMODULE_CHANNELB_AQ_LOCK : ͨ��B���AQ��ģ��Ĵ���
  * 	 			EPWM_SUBMODULE_CHANNELA_AQ_LOCK : ͨ��A���AQ��ģ��Ĵ���
  * 	 NewState : TRUE : ��ֹxx��ģ��Ĵ���д����
  * 	 			FALSE : ����xx��ģ��Ĵ���д����
  * ����  �ޡ�
  */
void EPWM_Submodule_Register_Lock_Config(EPWM_SFRmap* EPWMx,
			uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_SUBMODULE_LOCK(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (EPWM_CTL_AQLOCKA_POS + Select);
	tmask = 1 << (EPWM_CTL_AQLOCKA_POS + Select);
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~tmask, tmpreg);
}
/**
  * ����  ��׽����ʹ�ܡ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : TRUE : ʹ�ܲ�׽����ʹ��
  * 	 			FALSE : ��ֹ��׽����ʹ��
  * ����  �ޡ�
  */
void EPWM_Cap_Function_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_CAPEN_POS;
	tmask = EPWM_CTL_CAPEN;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~tmask, tmpreg);
}
/**
  * ����  ���ò�׽�¼�ѡ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 Select : 	EPWM_CAP_TRIGGER_EVENT_TZ1 : TZ1������׽�¼�
  * 	 			EPWM_CAP_TRIGGER_EVENT_TZ2 : TZ2������׽�¼�
  * 	 			EPWM_CAP_TRIGGER_EVENT_TZ3 : TZ3������׽�¼�
  * 	 			EPWM_CAP_TRIGGER_EVENT_TZ4 : TZ4������׽�¼�
  * ����  �ޡ�
  */
void EPWM_Cap_Trigger_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_CAP_TRIGGER_EVENT(Select));

	tmpreg = Select << EPWM_CTL_CAPSEL0_POS;
	tmask = EPWM_CTL_CAPSEL;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~tmask, tmpreg);
}
/**
  * ����  ��ȡ�����ﵽ���ֵ״̬��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����  0 �� ����ֵû�дﵽ�����ֵ0xFFFF_FFFF
  *      1 �� ����ֵ�ﵽ�����ֵ0xFFFF_FFFF
  */
FlagStatus EPWM_Get_CountValue_MAX_Status(EPWM_SFRmap* EPWMx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return ((EPWMx->CTL & EPWM_CTL_TXMAX) >> EPWM_CTL_TXMAX_POS);
}
/**
  * ����  ��������ﵽ���ֵ״̬��־��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����:  ��������ﵽ���ֵ״̬��־״̬
  */
RetStatus EPWM_Clear_CountValue_MAX_Status(EPWM_SFRmap* EPWMx)
{
	uint32_t wait_flag = 0x0000;
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXMAX, EPWM_CTL_TXMAX);
	while((!(EPWMx->CTL & EPWM_CTL_TXMAX))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * ����  ��λ������ơ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 Direction : 	EPWM_SYNC_TRIGGER_DOWM : ͬ���¼����������¼���
  * 	 				EPWM_SYNC_TRIGGER_UP : ͬ���¼����������ϼ���
  * ����  �ޡ�
  */
void EPWM_Phase_Direction_Config(EPWM_SFRmap* EPWMx, uint32_t Direction)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_SYNC_TRIGGER_DIRECTION(Direction));

	tmpreg = Direction << EPWM_CTL_PHSDIR_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_PHSDIR, tmpreg);
}
/**
  * ����  �����������ͬ���¼�(����һ��ͬ���¼�)��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����  �ޡ�
  */
void EPWM_Software_SYNC_Event(EPWM_SFRmap* EPWMx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_SWFSYNC, EPWM_CTL_SWFSYNC);
}
/**
  * ����  ͬ���¼����ѡ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 Select : 	EPWM_SYNC_EVENT_OUT_EPWM_SWF : EPWMxSYNCI�Լ�SWFSYNC
  * 	 			EPWM_SYNC_EVENT_OUT_COUNT0	 : ����ֵ����0����
  * 	 			EPWM_SYNC_EVENT_OUT_EPWMRB 	 : ����ֵ����EPWMx_RB����
  * 	 			EPWM_SYNC_EVENT_OUT_DISABLE  : ��ֹEPWMxSYNCO���
  * ����  �ޡ�
  */
void EPWM_SYNC_Event_Out_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_SYNC_EVENT_OUT(Select));

	tmpreg = Select << EPWM_CTL_SYNCOSEL0_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_SYNCOSEL, tmpreg);
}
/**
  * ����  ��λ�Ĵ�������ʹ�ܡ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : 	TRUE : �����ⲿͬ���¼�����������ǿ��ͬ��ʱ������λ�Ĵ���TXPHS���붨ʱ����
  * 	 				FALSE : ������λ�Ĵ���TXPHS���붨ʱ��
  * ����  �ޡ�
  */
void EPWM_Phase_Register_Loading_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_PHSEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_PHSEN, tmpreg);
}
/**
  * ����  ��ȡ�ⲿͬ���¼�����״̬��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����  �ޡ�
  */
FlagStatus EPWM_Get_External_SYNC_Event_Status(EPWM_SFRmap* EPWMx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return ((EPWMx->CTL & EPWM_CTL_SYNCI) >> EPWM_CTL_SYNCI_POS);
}
/**
  * ����  �����ⲿͬ���¼�����״̬λ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ����  :FAILURE���ʧ�ܣ�SUCCESS������ɹ���
  */
RetStatus EPWM_Clear_External_SYNC_Event_Status(EPWM_SFRmap* EPWMx)
{
	uint32_t wait_flag = 0x0000;
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_SYNCI, EPWM_CTL_SYNCI);
	while((!(EPWMx->CTL & EPWM_CTL_SYNCI))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  * ����  �����¼�����ʹ�ܡ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : TRUE �� ��ʼ����ʱ��Tx�ļ��������������ڡ�ռ�ձȡ�Ԥ��Ƶ����������ƼĴ���
  * 	 			FALSE �� δʹ��
  * ����  �ޡ�
  */
void EPWM_Updata_Event_Generate_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXUR_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXUR, tmpreg);
}
/**
  * ����  �����¼����ơ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : TRUE �� ���������¼���������TxΪʱ����ռ�ձȡ����ڡ�������ơ�Ԥ��Ƶ�Ĵ���
								���������У�������ʱ����λ��ֻ�ڸ�λ����������Ч�����ڶ�ʱ��
  * 	 			FALSE �� ����ʱ��TxΪ0ʱ�����¼���ΪPPֵʱ��������TxΪʱ����ռ�ձȡ�
  * 	 						���ڡ�������ơ�Ԥ��Ƶ�Ĵ�������������
  * ����  �ޡ�
  */
void EPWM_Updata_Event_Config(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXEUDEVT_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXEUDEVT, tmpreg);
}
/**
  * ����  ����ʹ�ܡ�
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : TRUE �� ������TxΪʱ��ռ�ձȡ����ڡ�������ơ�Ԥ��Ƶ�Ĵ�������
  * 	 			FALSE �� ��ֹ��TxΪʱ��ռ�ձȡ����ڡ�������ơ�Ԥ��Ƶ�Ĵ�������
  * ����  �ޡ�
  */
void EPWM_Updata_Event_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXUDEN_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXUDEN, tmpreg);
}
/**
  * ����  Tx����ģʽѡ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 Select : 	EPWM_COUNT_DOWM_UF �� ���¼���������ʱ�����жϱ�־
  * 	 			EPWM_COUNT_UP_OF �� ���ϼ���������ʱ�����жϱ�־
  * 	 			EPWM_COUNT_UP_DOWM_OF �� ����-���¼���������ʱ�����жϱ�־
  * 	 			EPWM_COUNT_UP_DOWM_UF �� ����-���¼���������ʱ�����жϱ�־
  * 	 			EPWM_COUNT_UP_DOWM_OUF �� ����-���¼��������������ʱ�������жϱ�־
  * ����  �ޡ�
  */
void EPWM_Counter_Mode_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_COUNT_MODE(Select));

	tmpreg = Select << EPWM_CTL_TXCMS0_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXCMS, tmpreg);
}
/**
  * ����  ��ȡTx��������
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * ���� 	0 �� ��ǰ��������Ϊ���¼���
  * 		1 �� ��ǰ��������Ϊ���ϼ���
  */
FlagStatus EPWM_Get_Tx_Count_Direction(EPWM_SFRmap* EPWMx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return ((EPWMx->CTL & EPWM_CTL_TTXDIR) >> EPWM_CTL_TTXDIR_POS);
}
/**
  * ����  Tx����ʱ��ѡ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 CLK : 	EPWM_CLK_SCLK : ѡ��SCLKʱ��ΪTx����ʱ��
  * 	 		EPWM_CLK_HFCLK : ѡ��HFCLKʱ��ΪTx����ʱ��
  * 	 		EPWM_CLK_LFCLK : ѡ��LFCLKʱ��ΪTx����ʱ��
  * ����  �ޡ�
  */
void EPWM_Work_Clock_Select(EPWM_SFRmap* EPWMx, uint32_t CLK)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_CLK(CLK));

	tmpreg = CLK << EPWM_CTL_TXCLK0_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXCLK, tmpreg);
}
/**
  * ����  Tx����ģʽ�ⲿ������������ͬ������
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : TRUE : �����ⲿ������������ͬ��
  * 	 			FALSE : ���ⲿ������������ͬ��
  * ����  �ޡ�
  * ע��TXCS=1ʱ��λ��Ч
  */
void EPWM_External_Pulse_Sync_Config(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXSY_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXSY, tmpreg);
}
/**
  * ����  Tx�ſ�ʹ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  * 	 NewState : TRUE : ʹ��Tx�ſأ��ſ��ź�ΪTxCK
  * 	 			FALSE : ��ֹTx�ſ�
  * ����  �ޡ�
  */
void EPWM_Gated_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTL_TXGATE_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXGATE, tmpreg);
}
/**
  * ����  Tx��ʱ/����ģʽѡ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  *      Mode : �µĶ�ʱ/����ģʽ��
  *                EPWM_TIMER_MODE: ��ʱģʽ
  *                EPWM_COUNTER_MODE: ����ģʽ
  * ����  �ޡ�
  */
void EPWM_Work_Mode_Config(EPWM_SFRmap* EPWMx, uint32_t Mode)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_MODE(Mode));

	tmpreg = Mode << EPWM_CTL_TXCS_POS;
	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXCS, tmpreg);
}
/**
  * ����  Txʹ��λ
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  *      NewState : TRUE : ʹ��Tx
  *      			FALSE : ��ֹTx
  * ����  �ޡ�
  */
void EPWM_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	EPWMx->CTL = SFR_Config(EPWMx->CTL, ~EPWM_CTL_TXEN, NewState);
}


/**
  * ����  ����ռ�ձ�A/B/C/D�Ĵ���
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  *      Register : EPWM_REGISTER_A : �Ĵ���A
  *      			EPWM_REGISTER_B �� �Ĵ���B
  *      			EPWM_REGISTER_C �� �Ĵ���C
  *      			EPWM_REGISTER_D �� �Ĵ���D
  *      Value : Value <= 0xFFFFFFFF
  * ����  �ޡ�
  */
void EPWM_Duty_Cycle_RegisterABCD_Config(EPWM_SFRmap* EPWMx, uint32_t Register,uint32_t Value)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_EPWM_32BIT_LIMIT(Value));

	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->RA = Value;
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->RB = Value;
	}
	else if(Register == EPWM_REGISTER_C)
	{
		EPWMx->RC = Value;
	}
	else if(Register == EPWM_REGISTER_D)
	{
		EPWMx->RD = Value;
	}
}
/**
  * ���� ��ȡռ�ձ�A/B/C/D�Ĵ�����ֵ
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  *      Register : EPWM_REGISTER_A : �Ĵ���A
  *      			EPWM_REGISTER_B �� �Ĵ���B
  *      			EPWM_REGISTER_C �� �Ĵ���C
  *      			EPWM_REGISTER_D �� �Ĵ���D
  * ����  32λ��ֵ��
  */
uint32_t EPWM_Get_Duty_Cycle_RegisterABCD_Value(EPWM_SFRmap* EPWMx, uint32_t Register)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));

	if(Register == EPWM_REGISTER_A)
	{
		return EPWMx->RA;
	}
	else if(Register == EPWM_REGISTER_B)
	{
		return EPWMx->RB;
	}
	else if(Register == EPWM_REGISTER_C)
	{
		return EPWMx->RC;
	}
	else if(Register == EPWM_REGISTER_D)
	{
		return EPWMx->RD;
	}
}


/**
  * ����  EPWMxA/EPWMxB����ǿ�����ʹ��
  * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
  *      Register : EPWM_REGISTER_A : �Ĵ���A
  *      			EPWM_REGISTER_B �� �Ĵ���B
  *      NewState : TRUE : ʹ��EPWMxA����ǿ�����
  *      			FALSE : ��ֹEPWMxA����ǿ�����
  * ����  �ޡ�
  */
void EPWM_Single_Mandatory_Output_Enable(EPWM_SFRmap* EPWMx,uint32_t Register, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_CTLA_OTSFA_POS;
	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->CTLA = SFR_Config(EPWMx->CTLA, ~EPWM_CTLA_OTSFA, tmpreg);
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->CTLB = SFR_Config(EPWMx->CTLB, ~EPWM_CTLA_OTSFA, tmpreg);
	}
}
/**
 * ����  EPWMxA����ǿ�����
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Register : 	EPWM_REGISTER_A : �Ĵ���A
 *      			EPWM_REGISTER_B �� �Ĵ���B
 *      Select : 	EPWM_OUT_NONE : �޶��������ֵ�ƽ���䣩
 *      			EPWM_OUT_LOW : �͵�ƽ
 *      			EPWM_OUT_HIGH : �ߵ�ƽ
 *      			EPWM_OUT_TOGGLE : ��ת
 * ����  �ޡ�
 */
void EPWM_Single_Mandatory_Output_Config(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_EPWM_MANDATORY_OUT(Select));

	tmpreg = Select << EPWM_CTLA_ACTSFA0_POS;
	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->CTLA = SFR_Config(EPWMx->CTLA, ~EPWM_CTLA_ACTSFA, tmpreg);
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->CTLB = SFR_Config(EPWMx->CTLB, ~EPWM_CTLA_ACTSFA, tmpreg);
	}
}
/**
 * ����  EPWMxA����ǿ�����
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Register : 	EPWM_REGISTER_A : �Ĵ���A
 *      			EPWM_REGISTER_B �� �Ĵ���B
 *      Select : 	EPWM_OUT_NONE : �޶��������ֵ�ƽ���䣩
 *      			EPWM_OUT_LOW : �͵�ƽ
 *      			EPWM_OUT_HIGH : �ߵ�ƽ
 *      			EPWM_OUT_PROHIBIT : ��ֹ
 * ����  �ޡ�
 */
void EPWM_Continuous_Mandatory_Output_Config(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_EPWM_MANDATORY_OUT(Select));

	tmpreg = Select << EPWM_CTLA_CSFA0_POS;
	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->CTLA = SFR_Config(EPWMx->CTLA, ~EPWM_CTLA_CSFA, tmpreg);
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->CTLB = SFR_Config(EPWMx->CTLB, ~EPWM_CTLA_CSFA, tmpreg);
	}
}
/**
 * ����  ��Tx����ֵ����EPWMx_RB�Ĵ����Ҽ�����������ʱ��EPWMxA���
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Register : 	EPWM_REGISTER_A : �Ĵ���A
 *      			EPWM_REGISTER_B �� �Ĵ���B
 *     	Event : 	EPWM_CERB_DD_EPWMAB_OUT : ��Tx����ֵ����EPWMx_RB�Ĵ����Ҽ�����������ʱ��EPWMxA/B���
 *     				EPWM_CERB_DU_EPWMAB_OUT : ��Tx����ֵ����EPWMx_RB�Ĵ����Ҽ�����������ʱ��EPWMxA/B���
 *     				EPWM_CERA_DD_EPWMAB_OUT : ��Tx����ֵ����EPWMx_RA�Ĵ����Ҽ�����������ʱ��EPWMxA/B���
 *     				EPWM_CERA_DU_EPWMAB_OUT : ��Tx����ֵ����EPWMx_RA�Ĵ����Ҽ�����������ʱ��EPWMxA/B���
 *     				EPWM_CEPPX_EPWMAB_OUT : ��Tx����ֵ�������ڼĴ���PPXʱ��EPWMxA/B���
 *     				EPWM_CE0_EPWMAB_OUT : ��Tx����ֵ������ʱ��EPWMxA/B���
 *      Select : 	EPWM_OUT_NONE : ���������¼�
 *      			EPWM_OUT_LOW : �͵�ƽ
 *      			EPWM_OUT_HIGH : �ߵ�ƽ
 *      			EPWM_OUT_TOGGLE : ��ת
 * ����  �ޡ�
 */
void EPWM_EPWMxAB_OUTPUT_Select(EPWM_SFRmap* EPWMx,uint32_t Register, uint32_t Event, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_REGISTER_AB(Register));
	CHECK_RESTRICTION(CHECK_EPWM_TXCOUNT_EQUAL_XX_EPWMAB_OUT(Event));
	CHECK_RESTRICTION(CHECK_EPWM_MANDATORY_OUT(Select));

	tmpreg = Select << (Event*2);
	tmask = 0x03 << (Event*2);
	if(Register == EPWM_REGISTER_A)
	{
		EPWMx->CTLA = SFR_Config(EPWMx->CTLA, ~tmask, tmpreg);
	}
	else if(Register == EPWM_REGISTER_B)
	{
		EPWMx->CTLB = SFR_Config(EPWMx->CTLB, ~tmask, tmpreg);
	}
}


/**
 * ����  ��������ѡ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Select : 	EPWM_EPWMA_UP_EPWMA_DOWM : 	EPWMxA�����Բ��η���ģ�飩��Ϊ����/�½�������ģ�������
 *      			EPWM_EPWMB_UP_EPWMA_DOWM : 	EPWMxB�����Բ��η���ģ�飩��Ϊ����������ģ�������
												EPWMxA�����Բ��η���ģ�飩��Ϊ�½�������ģ�������
 *      			EPWM_EPWMA_UP_EPWMB_DOWM : 	EPWMxA�����Բ��η���ģ�飩��Ϊ����������ģ�������
				 	 	 	 	 	 	 	 	EPWMxB�����Բ��η���ģ�飩��Ϊ�½�������ģ�������
 *      			EPWM_EPWMB_UP_EPWMB_DOWM : 	�����Բ��η���ģ�飩��Ϊ����/�½�������ģ�������
 * ����  �ޡ�
 */
void EPWM_Dead_Zone_Input_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DEAD_ZONE(Select));

	tmpreg = Select << EPWM_DBCTL_INMODE0_POS;
	EPWMx->DBCTL = SFR_Config(EPWMx->DBCTL, ~EPWM_DBCTL_INMODE, tmpreg);
}
/**
 * ����  �����������ѡ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Select : 	EPWM_EPWMA_NTOGGLE_EPWMB_NTOGGLE : 	EPWMxA��EPWMxB����������/�½�������ģ�飩������ת
 *      			EPWM_EPWMA_TOGGLE_EPWMB_NTOGGLE : 	EPWMxA��ת��EPWMxB����ת����������/�½�������ģ�飩
 *      			EPWM_EPWMA_NTOGGLE_EPWMB_TOGGLE : 	EPWMxB��ת��EPWMxA����ת����������/�½�������ģ�飩
 *      			EPWM_EPWMA_TOGGLE_EPWMB_TOGGLE : 	EPWMxA��EPWMxB����������/�½�������ģ�飩����ת
 * ����  �ޡ�
 */
void EPWM_Dead_Zone_Output_Polarity_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DEAD_ZONE_OUT_POLARITY(Select));

	tmpreg = Select << EPWM_DBCTL_POLSEL0_POS;
	EPWMx->DBCTL = SFR_Config(EPWMx->DBCTL, ~EPWM_DBCTL_POLSEL, tmpreg);
}
/**
 * ����  �������ѡ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Select : 	EPWM_UP_BYPASS_DOWN_BYPASS : 	����/�½�������ģ�鶼����·
 *      			EPWM_UP_BYPASS_DOWN_ENABLE : 	����������ģ�鱻��·���½�������ģ��ʹ��
 *      			EPWM_UP_ENABLE_DOWN_BYPASS : 	����������ģ�鱻ʹ�ܣ��½�������ģ����·
 *      			EPWM_UP_ENABLE_DOWN_ENABLE : 	����/�½�������ģ�鶼ʹ��
 * ����  �ޡ�
 */
void EPWM_Dead_Zone_Output_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DEAD_ZONE_OUT(Select));

	tmpreg = Select << EPWM_DBCTL_OUTMODE0_POS;
	EPWMx->DBCTL = SFR_Config(EPWMx->DBCTL, ~EPWM_DBCTL_OUTMODE, tmpreg);
}
/**
 * ����  ����ʱ������
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Select : 	EPWM_UP_EDGE_DEAD_ZONE : ����������ʱ������
 *      			EPWM_DOWM_EDGE_DEAD_ZONE : �½�������ʱ������
 *      Value : ����ʱ�� Value <= 0xFFFF
 * ����  �ޡ�
 */
void EPWM_Dead_Zone_Time_Config(EPWM_SFRmap* EPWMx, uint32_t Select, uint32_t Value)
{

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_UP_DOWN_EDGE_DEAD_ZONE(Select));
	CHECK_RESTRICTION(CHECK_EPWM_16BIT_LIMIT(Value));

	if(Select == EPWM_UP_EDGE_DEAD_ZONE)
	{
		EPWMx->DBT = SFR_Config(EPWMx->DBT, ~EPWM_DBT_RDBT, Value << EPWM_DBT_RDBT0_POS);
	}
	else if(Select == EPWM_DOWM_EDGE_DEAD_ZONE)
	{
		EPWMx->DBT = SFR_Config(EPWMx->DBT, ~EPWM_DBT_FDBT, Value);
	}
}


/**
 * ����  PCLKƵ������
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Select : 	EPWM_PCLK_DIV1 : 1��Ƶ
 *      			EPWM_PCLK_DIV2 : 2��Ƶ
 *      			EPWM_PCLK_DIV3 : 3��Ƶ
 *      			EPWM_PCLK_DIV4 : 4��Ƶ
 *      			EPWM_PCLK_DIV5 : 5��Ƶ
 *      			EPWM_PCLK_DIV6 : 6��Ƶ
 *      			EPWM_PCLK_DIV7 : 7��Ƶ
 *      			EPWM_PCLK_DIV8 : 8��Ƶ
 * ����  �ޡ�
 */
void EPWM_PCLK_Frequency_Config(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_PCLK_DIV(Select));

	tmpreg = Select << EPWM_PCCTL_CHPFREQ0_POS;
	EPWMx->PCCTL = SFR_Config(EPWMx->PCCTL, ~EPWM_PCCTL_CHPFREQ, tmpreg);
}
/**
 * ����  PCLKռ�ձ�����
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Select : 	EPWM_PCLK_DUTY_CYCLE78 : 7/8ռ�ձ�
 *      			EPWM_PCLK_DUTY_CYCLE68 : 6/8ռ�ձ�
 *      			EPWM_PCLK_DUTY_CYCLE58 : 5/8ռ�ձ�
 *      			EPWM_PCLK_DUTY_CYCLE48 : 4/8ռ�ձ�
 *      			EPWM_PCLK_DUTY_CYCLE38 : 3/8ռ�ձ�
 *      			EPWM_PCLK_DUTY_CYCLE28 : 2/8ռ�ձ�
 *      			EPWM_PCLK_DUTY_CYCLE18 : 1/8ռ�ձ�
 * ����  �ޡ�
 */
void EPWM_PCLK_Duty_Cycle_Config(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_PCLK_DUTY_CYCLE(Select));

	tmpreg = Select << EPWM_PCCTL_CHPDUTY0_POS;
	EPWMx->PCCTL = SFR_Config(EPWMx->PCCTL, ~EPWM_PCCTL_CHPDUTY, tmpreg);
}
/**
 * ����  ն����һ��������ѡ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Select : 	EPWM_CHOPPING_PULSE_WIDTH1 : 1��ն��ʱ�����ڣ�ն��ʱ�ӵ���1/8����ʱ�ӣ�
 *      			EPWM_CHOPPING_PULSE_WIDTH2 : 2��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH3 : 3��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH4 : 4��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH5 : 5��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH6 : 6��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH7 : 7��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH8 : 8��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH9 : 9��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH10 : 10��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH11 : 11��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH12 : 12��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH13 : 13��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH14 : 14��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH15 : 15��ն��ʱ������
 *      			EPWM_CHOPPING_PULSE_WIDTH16 : 16��ն��ʱ������
 * ����  �ޡ�
 */
void EPWM_Chopping_Pulse_Width_Config(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_CHOPPING_PULSE_WIDTH(Select));

	tmpreg = Select << EPWM_PCCTL_OSHTWTH0_POS;
	EPWMx->PCCTL = SFR_Config(EPWMx->PCCTL, ~EPWM_PCCTL_OSHTWTH, tmpreg);
}
/**
 * ����  ն��ģ��ʹ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      NewState : 	TRUE : ʹ��ն��
 *      			FALSE : ��ֹն��
 * ����  �ޡ�
 */
void EPWM_Chopping_Pulse_Mode_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	EPWMx->PCCTL = SFR_Config(EPWMx->PCCTL, ~EPWM_PCCTL_CHPEN, NewState);
}


/**
 * ����  EPWMx�Զ�����ʹ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      NewState : 	EPWM_PXASE_SOFTWARE_CLEAR_RESET : �Զ��ر�ʱ��PXASE��������㣬������EPWM
 *      			EPWM_PXASE_AUTO_CLEAR_RESET : �Զ��ر�ʱ�����ر��¼���ʧ��PXASEλ���Զ����㣬EPWM�Զ�����
 * ����  �ޡ�
 */
void EPWM_Auto_Reset_Enable(EPWM_SFRmap* EPWMx, uint32_t NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_PXASE_CLEAR_RESET(NewState));

	tmpreg = NewState << EPWM_PXASCTL_PXRSEN_POS;
	EPWMx->PXASCTL = SFR_Config(EPWMx->PXASCTL, ~EPWM_PXASCTL_PXRSEN, tmpreg);
}
/**
 * ����  ����EPWMxA�ر�״̬����
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Status �� 	EPWM_DRIVER_PIN_EPWMAB_LOW : ��������EPWMxA/BΪ�͵�ƽ
 *      			EPWM_DRIVER_PIN_EPWMAB_HIGH : ��������EPWMxA/BΪ�ߵ�ƽ
 *      			EPWM_DRIVER_PIN_EPWMAB_3STATUS   :	��������EPWMxA/BΪ��̬
 * ����  �ޡ�
 */
void EPWM_Pin_EPWMA_ShouDown_Status_Config(EPWM_SFRmap* EPWMx, uint32_t Status)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DRIVER_PIN_EPWMAB(Status));

	tmpreg = Status << EPWM_PXASCTL_PXSSA0_POS;
	EPWMx->PXASCTL = SFR_Config(EPWMx->PXASCTL, ~EPWM_PXASCTL_PXSSA, tmpreg);
}
/**
 * ����  ����EPWMxB�ر�״̬����
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 *      Status �� 	EPWM_DRIVER_PIN_EPWMAB_LOW : ��������EPWMxA/BΪ�͵�ƽ
 *      			EPWM_DRIVER_PIN_EPWMAB_HIGH : ��������EPWMxA/BΪ�ߵ�ƽ
 *      			EPWM_DRIVER_PIN_EPWMAB_3STATUS   :	��������EPWMxA/BΪ��̬
 * ����  �ޡ�
 */
void EPWM_Pin_EPWMB_ShouDown_Status_Config(EPWM_SFRmap* EPWMx, uint32_t Status)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_DRIVER_PIN_EPWMAB(Status));

	tmpreg = Status << EPWM_PXASCTL_PXSSB0_POS;
	EPWMx->PXASCTL = SFR_Config(EPWMx->PXASCTL, ~EPWM_PXASCTL_PXSSB, tmpreg);
}
/**
 * ����  ��ȡEPWMx�Զ��ر��¼�״̬
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * ����  0 ��  EPWMx��������
 * 		1 ��  �����˹ر��¼���EPWMxΪ�ر�״̬��
 */
FlagStatus EPWM_Get_Auto_ShowDown_Event_Status(EPWM_SFRmap* EPWMx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return ((EPWMx->PXASCTL & EPWM_PXASCTL_PXASE) >> EPWM_PXASCTL_PXASE_POS);
}
/**
 * ����  ���EPWMx�Զ��ر��¼�״̬
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * ���� ��
 */
void EPWM_Claer_Auto_ShowDown_Event_Status(EPWM_SFRmap* EPWMx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	EPWMx->PXASCTL &= ~EPWM_PXASCTL_PXASE;
}
/**
 * ����  EPWMx�Զ��ر�Դѡ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Select :  EPWM_AUTO_SHOWDOWN_SOURCE_NO : ��ֹ�Զ��ض�
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_TZ1_HIGH :  TZ1��������ߵ�ƽ
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_TZ2_HIGH :  TZ2��������ߵ�ƽ
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_TZ3_HIGH :  TZ3��������ߵ�ƽ
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_TZ4_HIGH :  TZ4��������ߵ�ƽ
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_CLKIF :  ����ģ������ж�
 * 				  EPWM_AUTO_SHOWDOWN_SOURCE_QEIIF :  QEI�����ж�
 * ����  �ޡ�
 */
void EPWM_Auto_ShowDown_Source_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_AUTO_SHOWDOWN_SOURCE(Select));

	tmpreg = Select << EPWM_PXASCTL_PXASS0_POS;
	EPWMx->PXASCTL = SFR_Config(EPWMx->PXASCTL, ~EPWM_PXASCTL_PXASS, tmpreg);
}


/**
 * ����  ����AD�¼�����ģʽѡ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : ����AD�¼�0
 * 				  EPWM_TRIGGER_AD_EVENT1 : ����AD�¼�1
 * 		Select :  EPWM_TRIGGER_AD_UP : 		ѡ�������ϼ�����ʽ�´���AD
 * 				  EPWM_TRIGGER_AD_DOWM :  	ѡ�������¼�����ʽ�´���AD
 * 				  EPWM_TRIGGER_AD_UD :  	ѡ�����������¼�����ʽ�´���AD
 * ����  �ޡ�
 */
void EPWM_Trigger_AD_Event_Mode_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_UD(Select));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = Select << EPWM_ETCTL_BTSEL0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_BTSEL, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = Select << EPWM_ETCTL_ATSEL0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_ATSEL, tmpreg);
	}
}
/**
 * ����  ����AD�¼������źż���
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : ����AD�¼�0
 * 				  EPWM_TRIGGER_AD_EVENT1 : ����AD�¼�1
 * ����  ����AD������
 */
uint8_t
EPWM_Get_Trigger_AD_Event_Single(EPWM_SFRmap* EPWMx, uint32_t Event)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		return ((EPWMx->ETCTL & EPWM_ETCTL_BT) >> EPWM_ETCTL_BT0_POS);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		return ((EPWMx->ETCTL & EPWM_ETCTL_AT) >> EPWM_ETCTL_AT0_POS);
	}
}
/**
 * ����  ����AD�¼�����ѡ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : ����AD�¼�0
 * 				  EPWM_TRIGGER_AD_EVENT1 : ����AD�¼�1
 * 		Select :  EPWM_1_TRIGGER_EVENT_TRIGGER_AD : ÿһ�δ����źŶ��ܲ�������AD�¼������а������������
 * 				  EPWM_2_TRIGGER_EVENT_TRIGGER_AD : ÿ���δ����źŲ�������AD�¼�
 * 				  EPWM_3_TRIGGER_EVENT_TRIGGER_AD : ÿ���δ����źŲ�������AD�¼�
 * 				  EPWM_4_TRIGGER_EVENT_TRIGGER_AD : ÿ�Ĵδ����źŲ�������AD�¼�
 * ����  �ޡ�
 */
void EPWM_Trigger_Event_Cycle_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_EVENT_TRIGGER_AD(Select));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = Select << EPWM_ETCTL_BPP0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_BPP, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = Select << EPWM_ETCTL_APP0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_APP, tmpreg);
	}
}
/**
 * ����  �������AD�¼�
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : ����AD�¼�0
 * 				  EPWM_TRIGGER_AD_EVENT1 : ����AD�¼�1
 * 		NewState :  TRUE : ����һ�δ���AD�¼�����
 * 					FALSE : ��ʹ�������������AD�¼�
 * ����  �ޡ�
 */
void EPWM_Software_Trigger_AD_Event_Enable(EPWM_SFRmap* EPWMx, uint32_t Event, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = NewState << EPWM_ETCTL_BPP0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_FRCB, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = NewState << EPWM_ETCTL_FRCB_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_FRCA, tmpreg);
	}
}
/**
 * ����  ����AD�¼�ѡ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : ����AD�¼�0
 * 				  EPWM_TRIGGER_AD_EVENT1 : ����AD�¼�1
 * 		Select :  EPWM_TIMER_EQUAL_0PULSE : ��ʱ��ֵ����������
 * 				  EPWM_TIMER_EQUAL_PPPULSE : ��ʱ��ֵ����PP����
 * 				  EPWM_TIMER_EQUAL_DUTYA : ��ʱ��ֵ����ռ�ձ�A�Ĵ�������
 * 				  EPWM_TIMER_EQUAL_DUTYB : ��ʱ��ֵ����ռ�ձ�B�Ĵ�������
 * ����  �ޡ�
 */
void EPWM_Trigger_AD_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CEHCK_EPWM_TRIGGER_AD_EVENT(Select));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = Select << EPWM_ETCTL_SELB0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_SELB, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = Select << EPWM_ETCTL_SELA0_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_SELA, tmpreg);
	}
}
/**
 * ����  ����AD�¼�ʹ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Event :   EPWM_TRIGGER_AD_EVENT0 : ����AD�¼�0
 * 				  EPWM_TRIGGER_AD_EVENT1 : ����AD�¼�1
 * 		NewState :  TRUE : ʹ�ܴ���AD�¼�
 * 					FALSE : ��ֹ����AD�¼�
 * ����  �ޡ�
 */
void EPWM_Trigger_AD_Event_Enable(EPWM_SFRmap* EPWMx, uint32_t Event, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_TRIGGER_AD_EVENT(Event));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	if(Event == EPWM_TRIGGER_AD_EVENT1)
	{
		tmpreg = NewState << EPWM_ETCTL_TOADENB_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_TOADENB, tmpreg);
	}
	else if(Event == EPWM_TRIGGER_AD_EVENT0)
	{
		tmpreg = NewState << EPWM_ETCTL_TOADENA_POS;
		EPWMx->ETCTL = SFR_Config(EPWMx->ETCTL, ~EPWM_ETCTL_TOADENA, tmpreg);
	}
}



/**
 * ����  �ж�ʹ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx����ֵ����EPWMx_RD�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx����ֵ����EPWMx_RC�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx����ֵ����EPWMx_RA�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx����ֵ����EPWMx_RB�����ж�
 * 				   EPWM_COUNT_OVERFLOW : Tx��������ж�
 * 				   EPWM_UPDATA_EVENT : Tx�����¼��ж�
 * 				   EPWM_SHOTDOWN_EVENT : Tx�ض��¼��ж�
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx����AD�¼�1�ж�
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx����AD�¼�0�ж�
 * 		NewState :  TRUE : ʹ�ܸ��¼������ж�
 * 					FALSE : ��ֹ���¼������ж�
 * ����  �ޡ�
 */
void EPWM_INT_Enable(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << Select;
	tmask = 1 << Select;
	EPWMx->IE = SFR_Config(EPWMx->IE, ~tmask, tmpreg);
}
/**
 * ����  ��ȡ�жϱ�־
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx����ֵ����EPWMx_RD�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx����ֵ����EPWMx_RC�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx����ֵ����EPWMx_RA�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx����ֵ����EPWMx_RB�����ж�
 * 				   EPWM_COUNT_OVERFLOW : Tx��������ж�
 * 				   EPWM_UPDATA_EVENT : Tx�����¼��ж�
 * 				   EPWM_SHOTDOWN_EVENT : Tx�ض��¼��ж�
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx����AD�¼�1�ж�
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx����AD�¼�0�ж�
 * ����  0 �� δ�������¼������жϡ�
 *      1 �� �������¼������ж�
 */
FlagStatus EPWM_Get_INT_Flag(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));

	tmask = 1 << Select;
	return ((EPWMx->IF & tmask) >> Select);
}
/**
 * ����  ����жϱ�־
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx����ֵ����EPWMx_RD�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx����ֵ����EPWMx_RC�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx����ֵ����EPWMx_RA�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx����ֵ����EPWMx_RB�����ж�
 * 				   EPWM_COUNT_OVERFLOW : Tx��������ж�
 * 				   EPWM_UPDATA_EVENT : Tx�����¼��ж�
 * 				   EPWM_SHOTDOWN_EVENT : Tx�ض��¼��ж�
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx����AD�¼�1�ж�
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx����AD�¼�0�ж�
 * ����  �жϱ�־���״̬��FAILURE���ʧ�ܣ�SUCCESS������ɹ���
 */
RetStatus EPWM_Clear_INT_Flag(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmask;
	uint32_t wait_flag = 0x0000;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));

	tmask = 1 << Select;
	EPWMx->IC = SFR_Config(EPWMx->IC, ~tmask, tmask);
	while((EPWMx->IF & tmask)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
	EPWMx->IC = SFR_Config(EPWMx->IC, ~tmask, 0);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
 * ����  ����DMA
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx����ֵ����EPWMx_RD�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx����ֵ����EPWMx_RC�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx����ֵ����EPWMx_RA�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx����ֵ����EPWMx_RB�����ж�
 * 				   EPWM_COUNT_OVERFLOW : Tx��������ж�
 * 				   EPWM_UPDATA_EVENT : Tx�����¼��ж�
 * 				   EPWM_SHOTDOWN_EVENT : Tx�ض��¼��ж�
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx����AD�¼�1�ж�
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx����AD�¼�0�ж�
 * 		NewState :  TRUE : ʹ�ܸ��¼�����DMA
 * 					FALSE : ��ֹ���¼�����DMA
 * ����  �ޡ�
 */
void EPWM_Trigger_DMA_Enable(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << Select;
	tmask = 1 << Select;
	EPWMx->DE = SFR_Config(EPWMx->DE, ~tmask, tmpreg);
}
/**
 * ����  ��ȡ����DMA��־
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Select :   EPWM_COUNT_EQUAL_EPWMRD : Tx����ֵ����EPWMx_RD�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRC : Tx����ֵ����EPWMx_RC�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRA : Tx����ֵ����EPWMx_RA�����ж�
 * 				   EPWM_COUNT_EQUAL_EPWMRB : Tx����ֵ����EPWMx_RB�����ж�
 * 				   EPWM_COUNT_OVERFLOW : Tx��������ж�
 * 				   EPWM_UPDATA_EVENT : Tx�����¼��ж�
 * 				   EPWM_SHOTDOWN_EVENT : Tx�ض��¼��ж�
 * 				   EPWM_TRIGGER_AD_EVENT1 : Tx����AD�¼�1�ж�
 * 				   EPWM_TRIGGER_AD_EVENT0 : Tx����AD�¼�0�ж�
 * ����  0 �� δ�������¼�����DMA
 *      1 �� �������¼�����DMA
 */
FlagStatus EPWM_Get_Trigger_DMA_Flag(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_FALG(Select));

	tmask = 1 << Select;
	return ((EPWMx->DF & tmask) >> Select);
}
/**
 * ����  HRPWM���B�˿���
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Select :   EPWM_EPWMB_NORMAL_OUTPUT : EPWMxB�˿��������
 * 				   EPWM_EPWMB_REVERSE_OUTPUT_EPWMA : EPWMxB�˿ڷ������EPWMxA
 * ����  ��
 */
void EPWM_HRPWM_OUTPUTB_CONTRAL_Select(EPWM_SFRmap* EPWMx, uint32_t Select)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_EPWMB_OUTPUT(Select));

	tmpreg = Select << EPWM_HRPWMCTL_HRPOUTB_POS;
	EPWMx->HRPWMCTL = SFR_Config(EPWMx->HRPWMCTL, ~EPWM_HRPWMCTL_HRPOUTB, tmpreg);
}
/**
 * ����  �߾���PWM����ʹ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		NewState :   TRUE : ʹ��HRPWM����
 * 				     FALSE : ��ֹHRPWM����
 * ����  ��
 */
void EPWM_HRPWM_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	EPWMx->HRPWMCTL = SFR_Config(EPWMx->HRPWMCTL, ~EPWM_HRPWMCTL_HRPEN, NewState);
}
/**
 * ����  8λ�߾���PWMռ�ձ�
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Value : Value <= 0xFF
 * ����  ��
 */
void EPWM_8Bit_HRPWM_Duty_Cycle(EPWM_SFRmap* EPWMx, uint8_t Value)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_8BIT_LIMIT(Value));

	EPWMx->HRCMP = Value;
}
/**
 * ����  ��ȡ��׽�������ĵ�ǰ����ֵ
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * ����  32λ��׽�������ĵ�ǰ����ֵ
 */
uint32_t EPWM_Get_Cap_Register_Current_Value(EPWM_SFRmap* EPWMx)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));

	return EPWMx->CAP;
}
/**
 * ����  EPWMx_UDCTL�����¼�
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Mode : 	EPWM_UDCTL_PPUD : Tx_PPX���ڼĴ�������
 * 				EPWM_UDCTL_PRUD : Tx_PRSC�Ĵ�������
 * 				EPWM_UDCTL_CMAUD : EPWMx_RA�Ĵ�������
 * 				EPWM_UDCTL_CMBUD : EPWMx_RB�Ĵ�������
 * 				EPWM_UDCTL_CMCUD : EPWMx_RC�Ĵ�������
 * 				EPWM_UDCTL_CMDUD : EPWMx_RD�Ĵ�������
 * 				EPWM_UDCTL_EAUD : EPWMx_CTLA�Ĵ�������
 * 				EPWM_UDCTL_EBUD : EPWMx_CTLB�Ĵ�������
 * 				EPWM_UDCTL_HRPUD :  EPWMx_HRCMP�Ĵ�������
 * 		NewState : 	TRUE : ʹ��
 * 					FALSE : ��ֹ
 * ����  ��
 */
void EPWM_UDCTL_Updata_Enable(EPWM_SFRmap* EPWMx, uint32_t Mode, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_UDCTL_UD(Mode));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (Mode*3);
	tmask = 1 << (Mode*3);
	EPWMx->UDCTL = SFR_Config(EPWMx->UDCTL, ~tmask, tmpreg);
}
/**
 * ����  EPWMx_UDCTL�����¼�ѡ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		Mode : 	EPWM_UDCTL_PPUD : Tx_PPX���ڼĴ�������
 * 				EPWM_UDCTL_PRUD : Tx_PRSC�Ĵ�������
 * 				EPWM_UDCTL_CMAUD : EPWMx_RA�Ĵ�������
 * 				EPWM_UDCTL_CMBUD : EPWMx_RB�Ĵ�������
 * 				EPWM_UDCTL_CMCUD : EPWMx_RC�Ĵ�������
 * 				EPWM_UDCTL_CMDUD : EPWMx_RD�Ĵ�������
 * 				EPWM_UDCTL_EAUD : EPWMx_CTLA�Ĵ�������
 * 				EPWM_UDCTL_EBUD : EPWMx_CTLB�Ĵ�������
 * 				EPWM_UDCTL_HRPUD :  EPWMx_HRCMP�Ĵ�������
 * 		Select : 	EPWM_COUNT_VALUE_EQUAL_0 : ����������ֵ����0ʱ����
 * 					EPWM_COUNT_VALUE_EQUAL_TxPPX : ����������ֵ����Tx_PPXֵʱ����
 * 					EPWM_COUNT_VALUE_EQUAL_0_TxPPX : ����������ֵ����0���ߵ���Tx_PPXֵʱ����
 * 					EPWM_INPUT_SYCN_SINGLE : ����ͬ���ź�ʱ����
 * ����  ��
 */
void EPWM_UDCTL_Register_Updata_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Mode, uint32_t Select)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_EPWM_UDCTL_UD(Mode));
	CHECK_RESTRICTION(CEHCK_EPWM_TXPPX_CYCLE_UPDATA_EVENT(Select));

	tmpreg = Select << (EPWM_UDCTL_PPUDSEL0_POS + Mode*3);
	tmask = 0x03 << (EPWM_UDCTL_PPUDSEL0_POS + Mode*3);
	EPWMx->UDCTL = SFR_Config(EPWMx->UDCTL, ~tmask, tmpreg);
}
/**
 * ����  ȫ�ּ���ʹ��
 * ����  EPWMx: ָ��EPWM�ڴ�ṹ��ָ�룬ȡֵΪEPWM11_SFR��EPWM12_SFR��EPWM13_SFR��EPWM16_SFR��
 * 		NewState : 	TRUE :	��ѡ��ȫ�ּ���
 * 					FALSE : ѡ��ȫ�ּ���
 * ����  ��
 */
void EPWM_Global_Loading_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_EPWM_ALL_PERIPH(EPWMx));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << EPWM_UDCTL_GBUDEN_POS;
	EPWMx->UDCTL = SFR_Config(EPWMx->UDCTL, ~EPWM_UDCTL_GBUDEN, tmpreg);
}




