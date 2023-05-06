/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_bkp.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the BKP 			  *
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

#ifndef KF32A1x6_BKP_H_
#define KF32A1x6_BKP_H_

#include "kf32a1x6.h"


/**
  * 侵入检测引脚选择
  */
#define BKP_PIN_RTC_TAMP1               ((uint32_t)0)
#define BKP_PIN_RTC_TAMP2               ((uint32_t)1)
#define BKP_PIN_RTC_TAMP3               ((uint32_t)2)
#define CHECK_BKP_PIN_RTC_TAMP(SEL)     (((SEL) == BKP_PIN_RTC_TAMP1) \
                                      || ((SEL) == BKP_PIN_RTC_TAMP2) \
                                      || ((SEL) == BKP_PIN_RTC_TAMP3))

/**
  * 有效电平
  */
#define BKP_HIGH_LEVEL_EFFECTIVE        ((uint32_t)0)
#define BKP_LOW_LEVEL_EFFECTIVE         ((uint32_t)1)
#define CHECK_BKP_EFFECTIVE_LEVEL(SEL)  (((SEL) == BKP_HIGH_LEVEL_EFFECTIVE) \
                                      || ((SEL) == BKP_LOW_LEVEL_EFFECTIVE))

/**
  * 时钟源选择
  */
#define BKP_EXTHF                       ((uint32_t)0)
#define BKP_EXTLF                       ((uint32_t)1)
#define CHECK_BKP_CLOCK_SOURCE(SEL)     (((SEL) == BKP_EXTLF) \
                                      || ((SEL) == BKP_EXTHF))

/**
  * 备份数据寄存器编号
  */
#define CHECK_BKP_DATA_NUMBER(NUM)      ((uint32_t)(NUM) <= 7)

/**
 * 	侵入检测同步/异步
 * */
#define BKP_TAMP_ASYNC					((uint32_t)0)
#define BKP_TAMP_SYNC					((uint32_t)1)
#define CHECK_BKP_TAMP_MODE(MODE)		((MODE) <= BKP_TAMP_SYNC)

/**
 * 	侵入检测采样时钟
 * */
#define BKP_TAMP_SCK_SCLK				((uint32_t)0)
#define BKP_TAMP_SCK_INTLF				((uint32_t)1)
#define CHECK_BKP_TAMP_SCK(CLK)			((CLK) <= BKP_TAMP_SCK_INTLF)


/* 备份域(BKP)复位及读写允许函数定义****************************************/
void BKP_Reset (void);
void BKP_Write_And_Read_Enable (FunctionalState NewState);

/* 备份域(BKP)功能配置函数定义**********************************************/
void BKP_Reset_Enable (FunctionalState NewState);
void BKP_Pin_Effective_Level_Config (uint32_t PinSel, uint32_t Effective);
void BKP_Pin_Enable (uint32_t PinSel, FunctionalState NewState);
void BKP_External_Clock_Bypass_Enable (uint32_t Source,FunctionalState NewState);
void BKP_Data_Config (uint32_t OrderNumber, uint32_t WriteData);
uint32_t BKP_Get_Data (uint32_t OrderNumber);
void BKP_TAMP_SYNC_Mode_Select(uint32_t Mode);
void BKP_TAMP_SCK_Select(uint32_t CLK);

/* 备份域(BKP)中断管理函数定义**********************************************/
void BKP_Pin_TAMP_INT_Enable (uint32_t PinSel, FunctionalState NewState);
FlagStatus BKP_Get_Pin_TAMP_INT_Flag (uint32_t PinSel);
RetStatus BKP_Clear_Pin_TAMP_INT_Flag (uint32_t PinSel);


#endif /* KF32A1x6_BKP_H_ */
