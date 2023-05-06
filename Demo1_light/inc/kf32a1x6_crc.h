/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_crc.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the CRC 			  *
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
#ifndef KF32A1x6_CRC_H_
#define KF32A1x6_CRC_H_

#include "kf32a1x6.h"

/**
  * ѭ������У�鵥Ԫ(CRC)ָ�붨��
  */
#define CHECK_CRC_PERIPH(PERIPH)     ((PERIPH) == CRC_SFR)

/**
 * CRC ������Ϣ�ṹ��
 */
typedef struct
{
	 uint32_t m_CalUnitReset;       /*  CRC ���㵥Ԫ��λ����
										ȡ��Ϊ��CRC���㵥Ԫ��λ���ơ��е�һ�� */
	 uint32_t m_InputSize;          /*  CRC �������ݸ�ʽ����λ
										ȡ��Ϊ��CRC�������ݸ�ʽ����λ���е�һ�� */
	 uint32_t m_InputReverse;       /*  CRC �������ݷ������λ
										ȡ��Ϊ��CRC�������ݷ������λ���е�һ�� */
	 uint32_t m_ResultReverse;      /*  CRC ����������
										ȡ��Ϊ��CRC���������ơ��е�һ�� */
} CRC_InitTypeDef;

/**
 * CRC���㵥Ԫ��λ����
 */
#define CRC_CAL_RSET_ENABLE         ((uint32_t) 0x1 << CRC_CTL_RSET_POS)
#define CRC_CAL_RSET_DISABLE        ((uint32_t) 0x0 << CRC_CTL_RSET_POS)
#define CHECK_CRC_CAL_RSET(SEL)     (((SEL) == CRC_CAL_RSET_ENABLE) \
                                    || ((SEL) == CRC_CAL_RSET_DISABLE) )

/**
 * CRC�������ݸ�ʽ����λ
 */
#define CRC_INPUT_SEZE_8                ((uint32_t) 0X0 << CRC_CTL_DATASIZE0_POS)
#define CRC_INPUT_SEZE_16               ((uint32_t) 0X1 << CRC_CTL_DATASIZE0_POS)
#define CRC_INPUT_SEZE_24               ((uint32_t) 0X2 << CRC_CTL_DATASIZE0_POS)
#define CRC_INPUT_SEZE_32               ((uint32_t) 0X3 << CRC_CTL_DATASIZE0_POS)
#define CHECK_CRC_INPUT_SEZE(SIZE)      (((SIZE) == CRC_INPUT_SEZE_8) \
                                        || ((SIZE) == CRC_INPUT_SEZE_16) \
                                        || ((SIZE) == CRC_INPUT_SEZE_24) \
                                        || ((SIZE) == CRC_INPUT_SEZE_32) )

/**
 * CRC�������ݷ������λ
 */
#define CRC_INPUT_REVERSE_ENABLE        ( (uint32_t) 0x1 << CRC_CTL_DATAREV_POS )
#define CRC_INPUT_REVERSE_DISABLE       ( (uint32_t) 0x0 << CRC_CTL_DATAREV_POS )
#define CHECK_CRC_INPUT_REVERSE(SEL)    (((SEL) == CRC_INPUT_REVERSE_ENABLE) \
                                        || ((SEL) == CRC_INPUT_REVERSE_DISABLE) )

/**
 * CRC����������
 */
#define CRC_RESULT_REVERSE_ENABLE       ((uint32_t) 0x1 << CRC_CTL_RSLTREV_POS)
#define CRC_RESULT_REVERSE_DISABLE      ((uint32_t) 0x0 << CRC_CTL_RSLTREV_POS)
#define CHECK_CRC_RSLTREV_SEL(SEL)      (((SEL) == CRC_RESULT_REVERSE_ENABLE) \
                                        || ((SEL) == CRC_RESULT_REVERSE_DISABLE))

/**
 * CRC�Ĵ������
 * */
#define CRC_DATA_REGISTER				((uint32_t)1)
#define CRC_RSLT_REGISTER				((uint32_t)2)
#define CRC_INIT_REGISTER				((uint32_t)3)
#define CRC_PLN_REGISTER				((uint32_t)4)
#define CRC_RXOR_REGISTER				((uint32_t)5)
#define CRC_IDATA_REGISTER				((uint32_t)6)
#define CRC_TEMP_REGISTER				((uint32_t)7)
#define CHECK_CRC_REGISTER1_SEL(SEL)	(((SEL) >= CRC_DATA_REGISTER) \
        							  && ((SEL) <= CRC_TEMP_REGISTER))
#define CHECK_CRC_REGISTER2_SEL(SEL)	(((SEL) == CRC_DATA_REGISTER) \
									  || ((SEL) == CRC_INIT_REGISTER) \
									  || ((SEL) == CRC_PLN_REGISTER) \
									  || ((SEL) == CRC_RXOR_REGISTER) \
									  || ((SEL) == CRC_IDATA_REGISTER) )



void CRC_Reset (void);
void CRC_Configuration (CRC_InitTypeDef* CRCInitStruct);
void CRC_Struct_Init (CRC_InitTypeDef* CRCInitStruct);
uint32_t CRC_Get_Register_Value(uint32_t CRC_Register);
void CRC_Register_Value_Config(uint32_t CRC_Register ,uint32_t Value);
void CRC_Result_Reverse_Enable(FunctionalState NewState);
void CRC_Input_Data_Reverse_Enable(FunctionalState NewState);
void CRC_Input_Data_Format_Config(uint32_t Select);
void CRC_Calculation_Unit_Reset_Enable(FunctionalState NewState);
void CRC_INPUT_DATA (uint32_t DATA);
uint32_t CRC_GET_RESULT (void);
void CRC_SET_INITVALUE (uint32_t DATA);
void CRC_SET_PLN (uint32_t DATA);
void CRC_SET_RXOR (uint32_t DATA);
void CRC_SET_IDATA (uint32_t DATA);
uint32_t CRC_GET_TEMP (void);
void CRC_SET_RSET (void);


#endif /* KF32A1x6_CRC_H_ */
