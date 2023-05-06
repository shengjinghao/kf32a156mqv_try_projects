/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_systick.h                             	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the SYSTICK		  *
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
#ifndef KF32A1x6_SYSTICK_H_
#define KF32A1x6_SYSTICK_H_

#include "kf32a1x6.h"

/* ���Ķ�ʱ��ָ�붨�� */
#define CHECK_SYSTICK_PERIPH(PERIPH)    ((PERIPH) == SYSTICK_SFR)

/**
  * ����  ���Ķ�ʱ��(SYSTICK)������Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_Period;          /* ���Ķ�ʱ���ؼ��ؼĴ�����ֵ��ȡֵ24λ���ݡ� */
    uint32_t m_Clock;           /* ���Ķ�ʱ����ʱ��Դѡ��
                                   ȡֵΪ�ꡰSYSTICK��ʱ��ʱ��Դ���е�һ���� */
    uint32_t m_SysTickINT;      /* ��ʱ��SysTick�ж�ʹ�����ã�
                                   ȡֵΪTRUE��FALSE�� */
} SYSTICK_InitTypeDef;


/**
  * SYSTICK��ʱ��ʱ��Դ
  */
#define SYSTICK_SYS_CLOCK_DIV_2         ((uint32_t)0x0 << ST_CTL_STCLKS_POS)
#define SYSTICK_SYS_CLOCK_DIV_1         ((uint32_t)0x1 << ST_CTL_STCLKS_POS)
#define CHECK_SYSTICK_CLOCK(SCLK)       (((SCLK) == SYSTICK_SYS_CLOCK_DIV_2) \
                                      || ((SCLK) == SYSTICK_SYS_CLOCK_DIV_1))

/**
  * SYSTICK��ʱ���ؼ��ؼĴ�����ֵ
  */
#define CHECK_SYSTICK_RELOAD(SYS)       (((SYS) >> 24) == 0)

/* ���Ķ�ʱ��(SYSTICK)�����ʼ����������************************************/
void SYSTICK_Configuration (uint32_t Clock, uint32_t SysTickINT,uint32_t Reload);

/* ���Ķ�ʱ��(SYSTICK)�������ú�������**************************************/
void SYSTICK_Cmd (FunctionalState NewState);
void SYSTICK_Clock_Config (uint32_t SysClock);
void SYSTICK_Systick_INT_Enable (uint32_t SysClock);
FlagStatus SYSTICK_Get_Count_Zero_Flag (void);
void SYSTICK_Reload_Config (uint32_t Reload);
void SYSTICK_Counter_Updata (void);
uint32_t SYSTICK_Get_Reload (void);
uint32_t SYSTICK_Get_Counter (void);

#endif /* KF32A1x6_SYSTICK_H_ */
