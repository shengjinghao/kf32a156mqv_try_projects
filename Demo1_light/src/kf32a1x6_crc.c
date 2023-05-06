/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_crc.c                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Cyclic Redundancy Check (CRC)  *
 *  				    peripherals function                                  *
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
#include "kf32a1x6_crc.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/*******************************************************************************
**                         (CRC) module private definition       		      **
*******************************************************************************/

/* CRC_CTL�Ĵ����������� */
#define CRC_CTL_INIT_MASK               (CRC_CTL_RSLTREV \
                                       | CRC_CTL_DATAREV \
                                       | CRC_CTL_DATASIZE \
                                       | CRC_CTL_RSET)

/**
  *   ##### ��ʼ�������ú��� #####
  */
/**
  * ���� CRC���踴λ��ʹ������ʱ�ӡ�
  * ����  : ��
  * ����  �ޡ�
  */
void CRC_Reset (void)
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CRCRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CRCRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_CRCCLKEN, TRUE);
}

/**
  * ����  CRC�������á�
  * ����  CRCx: CRCInitStruct: CRC������Ϣ
  * ����  �ޡ�
  */
void CRC_Configuration (CRC_InitTypeDef* CRCInitStruct)
{
    uint32_t tmpreg;

	CHECK_RESTRICTION(CHECK_CRC_CAL_RSET(CRCInitStruct->m_CalUnitReset));
	CHECK_RESTRICTION(CHECK_CRC_INPUT_SEZE(CRCInitStruct->m_InputSize));
	CHECK_RESTRICTION(CHECK_CRC_INPUT_REVERSE(CRCInitStruct->m_InputReverse));
	CHECK_RESTRICTION(CHECK_CRC_RSLTREV_SEL(CRCInitStruct->m_ResultReverse));

	/*---------------------------- CRC_CTL�Ĵ�������  -----------------*/
	/* ���ݽṹ���Աm_CalUnitReset������RSETλ�� */
	/* ���ݽṹ���Աm_InputSize������DATASIZEλ�� */
	/* ���ݽṹ���Աm_InputReverse������DATAREVλ�� */
	/* ���ݽṹ���Աm_ResultReverse������RSLTREVλ�� */

   tmpreg = ((CRCInitStruct->m_CalUnitReset ) | \
			  (CRCInitStruct->m_InputSize) | \
			  (CRCInitStruct->m_InputReverse) | \
			  (CRCInitStruct->m_ResultReverse));
   CRC_SFR->CTL = SFR_Config (CRC_SFR->CTL,
			   ~CRC_CTL_INIT_MASK,
			   tmpreg);
}

/**
  * ����  ��ʼ��CRC������Ϣ�ṹ�塣
  * ����  CRCInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void CRC_Struct_Init (CRC_InitTypeDef* CRCInitStruct)
{
    /* ��ʼ��CRC���㵥Ԫ��λ����λ */
    CRCInitStruct->m_CalUnitReset = CRC_CAL_RSET_DISABLE;
    /* ��ʼ�� CRC�������ݸ�ʽ����λ */
    CRCInitStruct->m_InputSize = CRC_INPUT_SEZE_8;
    /* ��ʼ�� CRC��������λ�������λ */
    CRCInitStruct->m_InputReverse = CRC_INPUT_REVERSE_DISABLE;
    /* ��ʼ�� CRC����������λ */
    CRCInitStruct->m_ResultReverse = CRC_RESULT_REVERSE_DISABLE;
}

/**
  * ����  ��ȡCRC��Ӧ�Ĵ�����ֵ��
  * ����  CRC_Register:  CRC_DATA_REGISTER�� CRC���ݼĴ�����
  * 					CRC_RSLT_REGISTER�� CRC����Ĵ�����
  * 					CRC_INIT_REGISTER�� CRC��ʼֵ�Ĵ�����
  * 					CRC_PLN_REGISTER�� CRC����ʽ�Ĵ�����
  * 					CRC_RXOR_REGISTER�� CRC������ֵ�Ĵ�����
  * 					CRC_IDATA_REGISTER�� CRC�������ݼĴ�����
  * 					CRC_TEMP_REGISTER�� CRC����Ĵ�����
  * ����  32λ�����ݡ�
  */
uint32_t CRC_Get_Register_Value(uint32_t CRC_Register)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CRC_REGISTER1_SEL(CRC_Register));

	return (*((uint32_t *)(CRC_ADDR+4*CRC_Register)));
}

/**
  * ����  ����CRC��Ӧ�Ĵ�����ֵ��
  * ����  CRC_Register:  CRC_DATA_REGISTER�� CRC���ݼĴ�����
  * 					CRC_INIT_REGISTER�� CRC��ʼֵ�Ĵ�����
  * 					CRC_PLN_REGISTER�� CRC����ʽ�Ĵ�����
  * 					CRC_RXOR_REGISTER�� CRC������ֵ�Ĵ�����
  * 					CRC_IDATA_REGISTER�� CRC�������ݼĴ�����
  * ����  �ޡ�
  */
void CRC_Register_Value_Config(uint32_t CRC_Register ,uint32_t Value)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CRC_REGISTER2_SEL(CRC_Register));

	*((uint32_t *)(CRC_ADDR+4*CRC_Register)) = Value;
}

/**
  * ����  CRC����������ʹ�ܡ�
  * ����  NewState: TRUE��CRC���λ����
  * 	 		 FALSE����Ӱ��
  * ����  �ޡ�
  */
void CRC_Result_Reverse_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CRC_CTL = SFR_Config(CRC_CTL, ~CRC_CTL_RSLTREV, NewState<<CRC_CTL_RSLTREV_POS);
}

/**
  * ����  CRC��������λ������ơ�
  * ����  NewState: TRUE�����ֽ�Ϊ��λ����λ�������
  * 	 		   FALSE����λ�������
  * ����  �ޡ�
  */
void CRC_Input_Data_Reverse_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CRC_CTL = SFR_Config(CRC_CTL, ~CRC_CTL_DATAREV, NewState<<CRC_CTL_DATAREV_POS);
}

/**
  * ����  CRC�������ݸ�ʽ���ơ�
  * ����  Select:    CRC_INPUT_SEZE_8: 8λ����
  * 				CRC_INPUT_SEZE_16: 16λ����
  * 				CRC_INPUT_SEZE_24: 24λ����
  * 				CRC_INPUT_SEZE_32: 32λ����
  * ����  �ޡ�
  */
void CRC_Input_Data_Format_Config(uint32_t Select)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CRC_INPUT_SEZE(Select));

	CRC_CTL = SFR_Config(CRC_CTL, ~CRC_CTL_DATASIZE, Select);
}

/**
  * ����  CRC���㵥Ԫ���ƿ��ơ�
  * ����  NewState: TRUE����λ״̬
  * 	 		   FALSE��������
  * ����  �ޡ�
  */
void CRC_Calculation_Unit_Reset_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CRC_CTL = SFR_Config(CRC_CTL, ~CRC_CTL_RSET, NewState<<CRC_CTL_RSET_POS);
}





/**
  * ����  CRC���ݼĴ�������
  * ����  DATA: ����ֵ��
  * ����  �ޡ�
  */
void CRC_INPUT_DATA (uint32_t DATA)
{
    /* ����CRC���ݼĴ��� */
	CRC_SFR->DATA = DATA;
}
/**
  * ����  ��ȡCRC���
  * ����  : ��
  * ����  uint32_tλ���ֵ
  */
uint32_t CRC_GET_RESULT (void)
{
    /* ��ȡCRC����Ĵ��� */
	uint32_t DATA;
	DATA=CRC_SFR->RSLT;
	return DATA;
}
/**
  * ����  ����CRC����ĳ�ʼֵ
  * ����  : ��
  * ����  uint32_tλ���ֵ
  */
void CRC_SET_INITVALUE (uint32_t DATA)
{
    /* ����CRC����ĳ�ʼֵ�Ĵ��� */
	CRC_SFR->INIT = DATA;
}
/**
  * ����  ����CRC����ʽ
  * ����  : ��
  * ����  uint32_tλ���ֵ
  */
void CRC_SET_PLN (uint32_t DATA)
{
    /* ����CRC����ʽ�Ĵ��� */
	CRC_SFR->PLN = DATA;
}
/**
  * ����  ����CRC������ֵ
  * ����  : ��
  * ����  uint32_tλ���ֵ
  */
void CRC_SET_RXOR (uint32_t DATA)
{
    /* ���ý�����ֵ�Ĵ��� */
	CRC_SFR->RXOR = DATA;
}
/**
  * ����  ����CRC��������
  * ����  : ��
  * ����  uint32_tλ���ֵ
  */
void CRC_SET_IDATA (uint32_t DATA)
{
    /* ���ö������ݼĴ��� */
	CRC_SFR->IDATA = DATA;
}
/**
  * ����  ����CRC����
  * ����  : ��
  * ����  uint32_tλ���ֵ
  */
uint32_t CRC_GET_TEMP (void)
{
    /* ���û���Ĵ��� */
	uint32_t DATA;
	DATA=CRC_SFR->TEMP;
	return DATA;
}
/**
  * ����  CRC ���㵥Ԫ��λ
  * ����  : ��
  * ����
  */
void CRC_SET_RSET (void)
{
    /* ���û���Ĵ��� */
	CRC_SFR->CTL|=CRC_CTL_RSET;
}
