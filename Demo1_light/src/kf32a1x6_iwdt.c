/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_iwdt.c                             	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : The file provides functions related to the independent*
 *                  	watchdog (IWDT) , including:                          *
 *          			+ Independent Watchdog (IWDT) control function	      *
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

#include "kf32a1x6_iwdt.h"

/*******************************************************************************
**         		    (IDWT) Moudle private macro definition 		              **
*******************************************************************************/

/* IWDT_FD�Ĵ���ι��ֵ */
#define FEED_THE_DOG                    ((uint32_t)0x55AA55AA)

/**
  *   ##### �������Ź�(IWDT)���ƹ��ܺ��� #####
  */
/**
  * ����  ���ö������Ź�Ԥ��Ƶ���������Ź�����ʱ�ӽ��з�Ƶ��
  * ����  Prescaler: �������Ź�����ʱ�ӵ�Ԥ��Ƶֵ��ȡֵΪ��
  *                    IWDT_PRESCALER_32: 32��Ƶ
  *                    IWDT_PRESCALER_64: 64��Ƶ
  *                    IWDT_PRESCALER_128: 128��Ƶ
  *                    IWDT_PRESCALER_256: 256��Ƶ
  *                    IWDT_PRESCALER_512: 512��Ƶ
  *                    IWDT_PRESCALER_1024: 1024��Ƶ
  *                    IWDT_PRESCALER_2048: 2048��Ƶ
  *                    IWDT_PRESCALER_4096: 4096��Ƶ
  *                    IWDT_PRESCALER_8192: 8192��Ƶ
  *                    IWDT_PRESCALER_16384: 16384��Ƶ
  *                    IWDT_PRESCALER_32768: 32768��Ƶ
  *                    IWDT_PRESCALER_65536: 65536��Ƶ
  * ����  �ޡ�
  */
void IWDT_Prescaler_Config (uint32_t Prescaler)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_IWDT_PRESCALER(Prescaler));

    /*---------------- ����IWDT_CTL�Ĵ���IWDTPSλ ----------------*/
    IWDT_CTL = SFR_Config (IWDT_CTL, ~IWDT_CTL_IWDTPS, Prescaler);
}

/**
  * ����  ���ö������Ź��Ĺ���ʱ�ӡ�
  * ����  Source: �������Ź�����ʱ�ӣ�ȡֵΪ
  * 			IWDT_SCK_INTLF
  * 			IWDT_SCK_EXTLF
  * ����  �ޡ�
  */
void IWDT_SCK_Source_Select(uint32_t Source)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_IWDT_SCK(Source));

	IWDT_CTL = SFR_Config(IWDT_CTL, ~IWDT_CTL_CLKS, Source << IWDT_CTL_CLKS_POS);
}

/**
  * ����  ���ö������Ź����ֵ�����ʱ��λ��
  * ����  Overflow: �������Ź����ֵ��ȡֵΪ0~0xFFF��
  * ����  �ޡ�
  */
void IWDT_Overflow_Config (uint32_t Overflow)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_IWDTPS_OVERFLOW(Overflow));

    /*---------------- ����IWDT_CTL�Ĵ���IWDTOVFλ ----------------*/
    tmpreg = Overflow << IWDT_CTL_IWDTOVF0_POS;
    IWDT_CTL = SFR_Config (IWDT_CTL, ~IWDT_CTL_IWDTOVF, tmpreg);
}

/**
  * ����  ���ö������Ź�ʹ�ܡ�
  * ����  NewState: �������Ź�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void IWDT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����IWDT_CTL�Ĵ���IWDTENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܶ������Ź���ʱ�� */
        SFR_SET_BIT_ASM(IWDT_CTL, IWDT_CTL_IWDTEN_POS);
    }
    else
    {
        /* δʹ�ܶ������Ź� */
        SFR_CLR_BIT_ASM(IWDT_CTL, IWDT_CTL_IWDTEN_POS);
    }
}

/**
  * ����  �������Ź�ι����
  * ����  �ޡ�
  * ����  �ޡ�
  */
void IWDT_Feed_The_Dog (void)
{
    IWDT_FD = FEED_THE_DOG;
}
/**
  *   ##### �������Ź�(IWDT)���ƹ��ܺ���������� #####
  */
