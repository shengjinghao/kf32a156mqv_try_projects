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

/* CRC_CTL寄存器配置掩码 */
#define CRC_CTL_INIT_MASK               (CRC_CTL_RSLTREV \
                                       | CRC_CTL_DATAREV \
                                       | CRC_CTL_DATASIZE \
                                       | CRC_CTL_RSET)

/**
  *   ##### 初始化及配置函数 #####
  */
/**
  * 描述 CRC外设复位，使能外设时钟。
  * 输入  : 无
  * 返回  无。
  */
void CRC_Reset (void)
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CRCRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CRCRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_CRCCLKEN, TRUE);
}

/**
  * 描述  CRC外设配置。
  * 输入  CRCx: CRCInitStruct: CRC配置信息
  * 返回  无。
  */
void CRC_Configuration (CRC_InitTypeDef* CRCInitStruct)
{
    uint32_t tmpreg;

	CHECK_RESTRICTION(CHECK_CRC_CAL_RSET(CRCInitStruct->m_CalUnitReset));
	CHECK_RESTRICTION(CHECK_CRC_INPUT_SEZE(CRCInitStruct->m_InputSize));
	CHECK_RESTRICTION(CHECK_CRC_INPUT_REVERSE(CRCInitStruct->m_InputReverse));
	CHECK_RESTRICTION(CHECK_CRC_RSLTREV_SEL(CRCInitStruct->m_ResultReverse));

	/*---------------------------- CRC_CTL寄存器配置  -----------------*/
	/* 根据结构体成员m_CalUnitReset，设置RSET位域 */
	/* 根据结构体成员m_InputSize，设置DATASIZE位域 */
	/* 根据结构体成员m_InputReverse，设置DATAREV位域 */
	/* 根据结构体成员m_ResultReverse，设置RSLTREV位域 */

   tmpreg = ((CRCInitStruct->m_CalUnitReset ) | \
			  (CRCInitStruct->m_InputSize) | \
			  (CRCInitStruct->m_InputReverse) | \
			  (CRCInitStruct->m_ResultReverse));
   CRC_SFR->CTL = SFR_Config (CRC_SFR->CTL,
			   ~CRC_CTL_INIT_MASK,
			   tmpreg);
}

/**
  * 描述  初始化CRC配置信息结构体。
  * 输入  CRCInitStruct: 指向待初始化的结构体指针。
  * 返回  无。
  */
void CRC_Struct_Init (CRC_InitTypeDef* CRCInitStruct)
{
    /* 初始化CRC计算单元复位控制位 */
    CRCInitStruct->m_CalUnitReset = CRC_CAL_RSET_DISABLE;
    /* 初始化 CRC输入数据格式控制位 */
    CRCInitStruct->m_InputSize = CRC_INPUT_SEZE_8;
    /* 初始化 CRC输入数据位反序控制位 */
    CRCInitStruct->m_InputReverse = CRC_INPUT_REVERSE_DISABLE;
    /* 初始化 CRC结果反序控制位 */
    CRCInitStruct->m_ResultReverse = CRC_RESULT_REVERSE_DISABLE;
}

/**
  * 描述  获取CRC相应寄存器的值。
  * 输入  CRC_Register:  CRC_DATA_REGISTER： CRC数据寄存器。
  * 					CRC_RSLT_REGISTER： CRC结果寄存器。
  * 					CRC_INIT_REGISTER： CRC初始值寄存器。
  * 					CRC_PLN_REGISTER： CRC多项式寄存器。
  * 					CRC_RXOR_REGISTER： CRC结果异或值寄存器。
  * 					CRC_IDATA_REGISTER： CRC独立数据寄存器。
  * 					CRC_TEMP_REGISTER： CRC缓存寄存器。
  * 返回  32位的数据。
  */
uint32_t CRC_Get_Register_Value(uint32_t CRC_Register)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_CRC_REGISTER1_SEL(CRC_Register));

	return (*((uint32_t *)(CRC_ADDR+4*CRC_Register)));
}

/**
  * 描述  配置CRC相应寄存器的值。
  * 输入  CRC_Register:  CRC_DATA_REGISTER： CRC数据寄存器。
  * 					CRC_INIT_REGISTER： CRC初始值寄存器。
  * 					CRC_PLN_REGISTER： CRC多项式寄存器。
  * 					CRC_RXOR_REGISTER： CRC结果异或值寄存器。
  * 					CRC_IDATA_REGISTER： CRC独立数据寄存器。
  * 返回  无。
  */
void CRC_Register_Value_Config(uint32_t CRC_Register ,uint32_t Value)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_CRC_REGISTER2_SEL(CRC_Register));

	*((uint32_t *)(CRC_ADDR+4*CRC_Register)) = Value;
}

/**
  * 描述  CRC结果反序控制使能。
  * 输入  NewState: TRUE：CRC结果位反序
  * 	 		 FALSE：无影响
  * 返回  无。
  */
void CRC_Result_Reverse_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CRC_CTL = SFR_Config(CRC_CTL, ~CRC_CTL_RSLTREV, NewState<<CRC_CTL_RSLTREV_POS);
}

/**
  * 描述  CRC输入数据位反序控制。
  * 输入  NewState: TRUE：按字节为单位进行位反序操作
  * 	 		   FALSE：无位反序操作
  * 返回  无。
  */
void CRC_Input_Data_Reverse_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CRC_CTL = SFR_Config(CRC_CTL, ~CRC_CTL_DATAREV, NewState<<CRC_CTL_DATAREV_POS);
}

/**
  * 描述  CRC输入数据格式控制。
  * 输入  Select:    CRC_INPUT_SEZE_8: 8位数据
  * 				CRC_INPUT_SEZE_16: 16位数据
  * 				CRC_INPUT_SEZE_24: 24位数据
  * 				CRC_INPUT_SEZE_32: 32位数据
  * 返回  无。
  */
void CRC_Input_Data_Format_Config(uint32_t Select)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_CRC_INPUT_SEZE(Select));

	CRC_CTL = SFR_Config(CRC_CTL, ~CRC_CTL_DATASIZE, Select);
}

/**
  * 描述  CRC计算单元控制控制。
  * 输入  NewState: TRUE：复位状态
  * 	 		   FALSE：无作用
  * 返回  无。
  */
void CRC_Calculation_Unit_Reset_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CRC_CTL = SFR_Config(CRC_CTL, ~CRC_CTL_RSET, NewState<<CRC_CTL_RSET_POS);
}





/**
  * 描述  CRC数据寄存器配置
  * 输入  DATA: 数据值。
  * 返回  无。
  */
void CRC_INPUT_DATA (uint32_t DATA)
{
    /* 配置CRC数据寄存器 */
	CRC_SFR->DATA = DATA;
}
/**
  * 描述  读取CRC结果
  * 输入  : 无
  * 返回  uint32_t位宽的值
  */
uint32_t CRC_GET_RESULT (void)
{
    /* 读取CRC结果寄存器 */
	uint32_t DATA;
	DATA=CRC_SFR->RSLT;
	return DATA;
}
/**
  * 描述  设置CRC计算的初始值
  * 输入  : 无
  * 返回  uint32_t位宽的值
  */
void CRC_SET_INITVALUE (uint32_t DATA)
{
    /* 设置CRC计算的初始值寄存器 */
	CRC_SFR->INIT = DATA;
}
/**
  * 描述  设置CRC多项式
  * 输入  : 无
  * 返回  uint32_t位宽的值
  */
void CRC_SET_PLN (uint32_t DATA)
{
    /* 设置CRC多项式寄存器 */
	CRC_SFR->PLN = DATA;
}
/**
  * 描述  设置CRC结果异或值
  * 输入  : 无
  * 返回  uint32_t位宽的值
  */
void CRC_SET_RXOR (uint32_t DATA)
{
    /* 设置结果异或值寄存器 */
	CRC_SFR->RXOR = DATA;
}
/**
  * 描述  设置CRC独立数据
  * 输入  : 无
  * 返回  uint32_t位宽的值
  */
void CRC_SET_IDATA (uint32_t DATA)
{
    /* 设置独立数据寄存器 */
	CRC_SFR->IDATA = DATA;
}
/**
  * 描述  设置CRC缓存
  * 输入  : 无
  * 返回  uint32_t位宽的值
  */
uint32_t CRC_GET_TEMP (void)
{
    /* 设置缓存寄存器 */
	uint32_t DATA;
	DATA=CRC_SFR->TEMP;
	return DATA;
}
/**
  * 描述  CRC 计算单元复位
  * 输入  : 无
  * 返回
  */
void CRC_SET_RSET (void)
{
    /* 设置缓存寄存器 */
	CRC_SFR->CTL|=CRC_CTL_RSET;
}
