/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_osc.c                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the oscillator (OSC) peripheral 	  *
 *  					function, including:								  *
 *          			+ Oscillator (OSC) peripheral initialization function *
 *          			+ Oscillator (OSC) function configuration function    *
 *          			+ Oscillator (OSC) interrupt control function         *
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


#include "kf32a1x6_osc.h"

/**
  *   ##### ����(OSC)�����ʼ������ #####
  */

/**
  * ����  ��������(OSC)ϵͳ��ʱ��SCLK��
  * ����  oscInitStruct: ����(OSC)������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void OSC_SCLK_Configuration (OSC_InitTypeDef* oscInitStruct)
{
	uint32_t tmpreg=0;
	uint32_t tmpmask=0;

	/*����У��*/
    CHECK_RESTRICTION(CHECK_SCLK_SOURCE(oscInitStruct->m_InputSource));
    CHECK_RESTRICTION(CHECK_SCLK_DIVISION(oscInitStruct->m_CLKDivision));
    CHECK_RESTRICTION(CHECK_PLL_INPUT(oscInitStruct->m_PLLInputSource));
    CHECK_RESTRICTION(CHECK_PLL_START_DELAY(oscInitStruct->m_StartDelay));

    switch (oscInitStruct->m_InputSource)
    {
    case SCLK_SOURCE_EXTHF:
    	/* ����EXTHF������ʱ */
    	OSC_CTL2 = SFR_Config(OSC_CTL2, ~OSC_CTL2_EHFDLY, (oscInitStruct->m_StartDelay) << OSC_CTL2_EHFDLY0_POS);
    	break;
    case SCLK_SOURCE_EXTLF:
    	/* ����EXTLF������ʱ */
    	OSC_CTL2 = SFR_Config(OSC_CTL2, ~OSC_CTL2_ELFDLY, (oscInitStruct->m_StartDelay) << OSC_CTL2_ELFDLY0_POS);
    	break;
    case SCLK_SOURCE_PLL:
    	/* ����PLL��ʱ��Դѡ�� */
    	tmpreg |= (oscInitStruct->m_PLLInputSource)<< OSC_CTL0_PLLCKS_POS;
    	tmpmask |= OSC_CTL0_PLLCKS;
    	/* ����PLL������ʱ */
    	OSC_CTL2 = SFR_Config(OSC_CTL2, ~OSC_CTL2_EHFDLY, (oscInitStruct->m_StartDelay));
    	break;
    default:break;
    }
    /* SCK����ʱ��Դ����Ƶ���� */
	tmpreg |= (oscInitStruct->m_InputSource) << OSC_CTL0_SCKS0_POS \
		   | (oscInitStruct->m_CLKDivision) << OSC_CTL0_SCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~(OSC_CTL0_SCKS | OSC_CTL0_SCKDIV | tmpmask), tmpreg);
}

/**
  * ����  ��������(OSC)��Ƶ����ʱ��HFCLK��
  * ����  oscInitStruct: ����(OSC)������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void OSC_HFCK_Configuration (OSC_InitTypeDef* oscInitStruct)
{
	uint32_t tmpreg=0;
	uint32_t tmpmask=0;

	/*����У��*/
    CHECK_RESTRICTION(CHECK_SCLK_SOURCE(oscInitStruct->m_InputSource));
    CHECK_RESTRICTION(CHECK_SCLK_DIVISION(oscInitStruct->m_CLKDivision));
    CHECK_RESTRICTION(CHECK_PLL_INPUT(oscInitStruct->m_PLLInputSource));
    CHECK_RESTRICTION(CHECK_PLL_START_DELAY(oscInitStruct->m_StartDelay));

    switch (oscInitStruct->m_InputSource)
    {
    case HFCK_SOURCE_EXTHF:
    	/* ����EXTHF������ʱ */
    	OSC_CTL2 = SFR_Config(OSC_CTL2, ~OSC_CTL2_EHFDLY, (oscInitStruct->m_StartDelay) << OSC_CTL2_EHFDLY0_POS);
    	break;
    case HFCK_SOURCE_PLL:
    	/* ����PLL��ʱ��Դѡ�� */
    	tmpreg |= (oscInitStruct->m_PLLInputSource)<< OSC_CTL0_PLLCKS_POS;
    	tmpmask |= OSC_CTL0_PLLCKS;
    	/* ����PLL������ʱ */
    	OSC_CTL2 = SFR_Config(OSC_CTL2, ~OSC_CTL2_EHFDLY, (oscInitStruct->m_StartDelay));
    	break;
    default:break;
    }
    /* HFCK����ʱ��Դ����Ƶ���� */
	tmpreg |= (oscInitStruct->m_InputSource) << OSC_CTL0_HFCKS0_POS \
		   | (oscInitStruct->m_CLKDivision) << OSC_CTL0_HFCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~(OSC_CTL0_HFCKS | OSC_CTL0_HFCKDIV | tmpmask), tmpreg);
}

/**
  * ����  ��������(OSC)��Ƶ����ʱ��LFCLK��
  * ����  oscInitStruct: ����(OSC)������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void OSC_LFCK_Configuration (OSC_InitTypeDef* oscInitStruct)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_LFCK_INPUT(oscInitStruct->m_InputSource));
    CHECK_RESTRICTION(CHECK_LFCK_DIVISION(oscInitStruct->m_CLKDivision));

    if (oscInitStruct->m_InputSource == LFCK_INPUT_EXTLF)
    {
    	/* ����У�� */
        CHECK_RESTRICTION(CHECK_EXT_START_DELAY(oscInitStruct->m_StartDelay));
        /* �����ⲿ��Ƶ������ʱ */
        tmpreg = (oscInitStruct->m_StartDelay) << OSC_CTL2_ELFDLY0_POS;
        OSC_CTL2 = SFR_Config (OSC_CTL2, ~OSC_CTL2_ELFDLY, tmpreg);
    }
    else
    {
        ;
    }
    /* ����LFCKʱ��Դ����Ƶ */
    tmpreg = oscInitStruct->m_InputSource << OSC_CTL0_LFCKS_POS \
           | oscInitStruct->m_CLKDivision << OSC_CTL0_LFCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~(OSC_CTL0_LFCKS | OSC_CTL0_LFCKDIV), tmpreg);
}

/**
  * ����  ��ʼ������(OSC)������Ϣ�ṹ�塣
  * ����  oscInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void OSC_Struct_Init (OSC_InitTypeDef* oscInitStruct)
{
    /* ��Դѡ�� */
    oscInitStruct->m_InputSource = SCLK_SOURCE_INTHF;
    /* ʱ�ӷ�Ƶϵ�� */
    oscInitStruct->m_CLKDivision = SCLK_DIVISION_128;
    /* PLL����ʱ��Դѡ�� */
    oscInitStruct->m_PLLInputSource = PLL_INPUT_INTHF;
    /* PLL �� �ⲿ������ʱʱ������ */
    oscInitStruct->m_StartDelay = PLL_START_DELAY_64;
}

/**
  *   ##### ����(OSC)�����ʼ������������� #####
  */

/**
  *   ##### ����(OSC)�������ú��� #####
  */

/**
  * ����  ���õ�Ƶ����ʱ�ӷ�Ƶѡ��
  * ����  LFDivision: ��Ƶ����ʱ�ӷ�Ƶѡ��ȡֵ��ΧΪ��
  *                         LFCK_DIVISION_1: 1/1��Ƶ,
  *                         LFCK_DIVISION_2: 1/2��Ƶ,
  *                         LFCK_DIVISION_4: 1/4��Ƶ,
  *                         LFCK_DIVISION_8: 1/8��Ƶ,
  *                         LFCK_DIVISION_16: 1/16��Ƶ,
  *                         LFCK_DIVISION_32: 1/32��Ƶ,
  *                         LFCK_DIVISION_64: 1/64��Ƶ,
  *                         LFCK_DIVISION_128: 1/128��Ƶ,
  * ����  �ޡ�
  */
void OSC_LFCK_Division_Config (uint32_t LFDivision)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_LFCK_DIVISION(LFDivision));

    /*---------------- ����OSC_CTL0�Ĵ���LFCKDIVλ ----------------*/
    tmpreg = LFDivision << OSC_CTL0_LFCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_LFCKDIV, tmpreg);
}

/**
  * ����  ���ø�Ƶ����ʱ�ӷ�Ƶѡ��
  * ����  HFDivision: ��Ƶ����ʱ�ӷ�Ƶѡ��ȡֵ��ΧΪ��
  *                         HFCK_DIVISION_1: 1/1��Ƶ,
  *                         HFCK_DIVISION_2: 1/2��Ƶ,
  *                         HFCK_DIVISION_4: 1/4��Ƶ,
  *                         HFCK_DIVISION_8: 1/8��Ƶ,
  *                         HFCK_DIVISION_16: 1/16��Ƶ,
  *                         HFCK_DIVISION_32: 1/32��Ƶ,
  *                         HFCK_DIVISION_64: 1/64��Ƶ,
  *                         HFCK_DIVISION_128: 1/128��Ƶ,
  *                         HFCK_DIVISION_256: 1/256��Ƶ,
  *                         HFCK_DIVISION_512: 1/512��Ƶ,
  * ����  �ޡ�
  */
void OSC_HFCK_Division_Config (uint32_t HFDivision)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_HFCK_DIVISION(HFDivision));

    /*---------------- ����OSC_CTL0�Ĵ���HFCKDIVλ ----------------*/
    tmpreg = HFDivision << OSC_CTL0_HFCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_HFCKDIV, tmpreg);
}

/**
  * ����  ������ʱ��SCLK��Ƶѡ��
  * ����  SclkDivision: ��ʱ��SCLK��Ƶѡ��ȡֵ��ΧΪ��
  *                         SCLK_DIVISION_1: 1/1��Ƶ,
  *                         SCLK_DIVISION_2: 1/2��Ƶ,
  *                         SCLK_DIVISION_4: 1/4��Ƶ,
  *                         SCLK_DIVISION_8: 1/8��Ƶ,
  *                         SCLK_DIVISION_16: 1/16��Ƶ,
  *                         SCLK_DIVISION_32: 1/32��Ƶ,
  *                         SCLK_DIVISION_64: 1/64��Ƶ,
  *                         SCLK_DIVISION_128: 1/128��Ƶ,
  * ����  �ޡ�
  */
void OSC_SCK_Division_Config (uint32_t SclkDivision)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SCLK_DIVISION(SclkDivision));

    /*---------------- ����OSC_CTL0�Ĵ���SCKDIVλ ----------------*/
    tmpreg = SclkDivision << OSC_CTL0_SCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_SCKDIV, tmpreg);
}

/**
  * ����  ����PLL����ʱ��Դѡ��
  * ����  NewState: PLL����ʱ��Դѡ��ȡֵ��ΧΪ��
  *                   PLL_INPUT_INTHF: ѡ��INTHF��ΪPLL����ʱ�ӣ�
  *                   PLL_INPUT_EXTHF: ѡ��EXTHF��ΪPLL����ʱ�ӡ�
  * ����  �ޡ�
  */
void OSC_PLL_Input_Source_Config (uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_PLL_INPUT(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���PLL0CKSλ ----------------*/
    if (NewState != PLL_INPUT_INTHF)
    {
        /* ѡ��EXTHF��ΪPLL����ʱ�� */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PLLCKS_POS);
    }
    else
    {
        /* ѡ��INTHF��ΪPLL����ʱ�� */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_PLLCKS_POS);
    }
}

/**
  * ����  ���ø�Ƶ����ʱ��Դѡ��
  * ����  HFSource: ��Ƶ����ʱ��Դѡ��ȡֵ��ΧΪ��
  *                   HFCK_SOURCE_INTHF: ѡ��INTHF��ΪHFCLKʱ��,
  *                   HFCK_SOURCE_EXTHF: ѡ��EXTHF��ΪHFCLKʱ��,
  *                   HFCK_SOURCE_PLL:   ѡ��PLL�����ΪHFCLKʱ��,
  *                   HFCK_SOURCE_LP4M:  ѡ��LPM�����ΪHFCLKʱ��,
  * ����  �ޡ�
  */
void OSC_HFCK_Source_Config (uint32_t HFSource)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_HFCK_SOURCE(HFSource));

    /*---------------- ����OSC_CTL0�Ĵ���HFCKSλ ----------------*/
    tmpreg = HFSource << OSC_CTL0_HFCKS0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_HFCKS, tmpreg);
}

/**
  * ����  ���ø�Ƶ����ʱ������ʹ�ܡ�
  * ����  NewState: ��Ƶ����ʱ������ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_HFCK_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���HFCKENλ ----------------*/
    if (NewState != FALSE)
    {
        /* HFCLKʱ���ź����� */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_HFCKEN_POS);
    }
    else
    {
        /* HFCLKʱ���źŽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_HFCKEN_POS);
    }
}

/**
  * ����  ���õ�Ƶ����ʱ��Դѡ��
  * ����  NewState: ��Ƶ����ʱ��Դѡ��ȡֵ��ΧΪ��
  *                   LFCK_INPUT_INTLF: ѡ��INTLF��ΪLFCLKʱ�ӣ�
  *                   LFCK_INPUT_EXTLF: ѡ��EXTLF��ΪLFCLKʱ�ӡ�
  * ����  �ޡ�
  */
void OSC_LFCK_Source_Config (uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_LFCK_INPUT(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���LFCKSλ ----------------*/
    if (NewState != LFCK_INPUT_INTLF)
    {
        /* ѡ��EXTLF��ΪLFCLKʱ�� */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_LFCKS_POS);
    }
    else
    {
        /* ѡ��INTLF��ΪLFCLKʱ�� */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_LFCKS_POS);
    }
}

/**
  * ����  ���õ�Ƶ����ʱ������ʹ�ܡ�
  * ����  NewState: ��Ƶ����ʱ������ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_LFCK_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���LFCKENλ ----------------*/
    if (NewState != FALSE)
    {
        /* LFCLKʱ���ź����� */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_LFCKEN_POS);
    }
    else
    {
        /* LFCLKʱ���źŽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_LFCKEN_POS);
    }
}

/**
  * ����  ����SCLK��ʱ��ѡ��
  * ����  SclkSource: SCLK��ʱ��ѡ��ȡֵ��ΧΪ��
  *                     SCLK_SOURCE_INTHF: ѡ��INTHF��Ϊϵͳʱ��,
  *                     SCLK_SOURCE_INTLF: ѡ��INTLF��Ϊϵͳʱ��,
  *                     SCLK_SOURCE_EXTHF: ѡ��EXTHF��Ϊϵͳʱ��,
  *                     SCLK_SOURCE_EXTLF: ѡ��EXTLF��Ϊϵͳʱ��,
  *                     SCLK_SOURCE_PLL:   ѡ��PLL�����Ϊϵͳʱ��,
  *                     SCLK_SOURCE_LP4M:  ѡ�� LP4M �����Ϊϵͳʱ��
  * ����  �ޡ�
  */
void OSC_SCK_Source_Config (uint32_t SclkSource)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SCLK_SOURCE(SclkSource));

    /*---------------- ����OSC_CTL0�Ĵ���SCKSλ ----------------*/
    tmpreg = SclkSource << OSC_CTL0_SCKS0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_SCKS, tmpreg);
}

/**
  * ����  ���ñ������Ĵ�����д����
  * ����  NewState: �������Ĵ�����д����״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_Backup_Write_Read_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���PMWRENλ ----------------*/
    if (NewState != FALSE)
    {
        /* �������ɶ�д */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);
    }
    else
    {
        /* ���������ɶ�д */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);
    }
}

/**
  * ����  ����ʱ�����ʹ�ܡ�
  * ����  NewState: ϵͳʱ�����ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_SCLK_Output_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL1�Ĵ���CLKOEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ����ʱ�Ӵ�IO�������CLKOUT�� */
        SFR_SET_BIT_ASM(OSC_CTL1, OSC_CTL1_CLKOE_POS);
    }
    else
    {
        /* ��ֹʱ�Ӵ�IO�������CLKOUT�� */
        SFR_CLR_BIT_ASM(OSC_CTL1, OSC_CTL1_CLKOE_POS);
    }
}

/**
  * ����  ���ô����� CLKOUT ���ʱ��ѡ��
  * ����  SclkSource: ���ʱ��ѡ��
  *                     CLKOUT_SCLK:  ѡ�� SCLK ��Ϊ���ʱ��
  *                     CLKOUT_EXTLF: ѡ�� EXTLF ��Ϊ���ʱ��
  *                     CLKOUT_EXTHF: ѡ�� EXTHF ��Ϊ���ʱ��
  *                     CLKOUT_INTLF: ѡ�� INTLF ��Ϊ���ʱ��
  *                     CLKOUT_INTHF: ѡ�� INTHF ��Ϊ���ʱ��
  *                     CLKOUT_PLL:   ѡ�� PLL ��Ϊ���ʱ��
  *                     CLKOUT_LP4M:  ѡ�� LP4M ��Ϊ���ʱ��
  * ����  �ޡ�
  */
void OSC_SCLK_Output_Select (uint32_t SclkSource)
{
    uint32_t tmpreg;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CLKOUT_SEL(SclkSource));

    /*---------------- ����OSC_CTL0�Ĵ���CLKOUTSλ ----------------*/
    tmpreg = SclkSource << OSC_CTL1_CLKOUTS0_POS;
    OSC_CTL1 = SFR_Config (OSC_CTL1, ~OSC_CTL1_CLKOUTS, tmpreg);
}

/**
  * ����  �������ʱ�ӷ�Ƶѡ��
  * ����  OutputDivision: CLK���ʱ�ӷ�Ƶѡ��λ��ȡֵ��ΧΪ��
  *                         CLKOUT_DIVISION_1: 1/1��Ƶ,
  *                         CLKOUT_DIVISION_2: 1/2��Ƶ,
  *                         CLKOUT_DIVISION_4: 1/4��Ƶ,
  *                         CLKOUT_DIVISION_8: 1/8��Ƶ,
  *                         CLKOUT_DIVISION_16: 1/16��Ƶ,
  *                         CLKOUT_DIVISION_32: 1/32��Ƶ,
  *                         CLKOUT_DIVISION_64: 1/64��Ƶ,
  *                         CLKOUT_DIVISION_128: 1/128��Ƶ,
  * ����  �ޡ�
  */
void OSC_SCLK_Output_Division_Config (uint32_t OutputDivision)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SCLK_DIVISION(OutputDivision));

    /*---------------- ����OSC_CTL1�Ĵ���CLKOUTDIVλ ----------------*/
    tmpreg = OutputDivision << OSC_CTL1_CLKOUTDIV0_POS;
    OSC_CTL1 = SFR_Config (OSC_CTL1, ~OSC_CTL1_CLKOUTDIV, tmpreg);
}

/**
  * ����  ����ʱ�ӹ��ϼ��ʹ�ܡ�
  * ����  NewState: ʱ�ӹ��ϼ��ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_Clock_Failure_Check_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL1�Ĵ���FSCMλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʱ�ӹ��ϼ��ʹ�� */
        SFR_SET_BIT_ASM(OSC_CTL1, OSC_CTL1_FSCM_POS);
    }
    else
    {
        /* ʱ�ӹ��ϼ���ֹ */
        SFR_CLR_BIT_ASM(OSC_CTL1, OSC_CTL1_FSCM_POS);
    }
}

/**
  * ����  ����ʱ�ӹ��ϼ������
  * ����  FSCM_DIV: ʱ�ӹ��ϼ���Ƶѡ��ȡֵ��ΧΪ��
  * 								FSCM_DIVISION_8��INTLF/8
  * 								FSCM_DIVISION_16��INTLF/16
  * 								FSCM_DIVISION_32��INTLF/32
  * 								FSCM_DIVISION_64��INTLF/64
  * 								FSCM_DIVISION_128��INTLF/128
  * ����  �ޡ�
  */
void OSC_Clock_Failure_Check_Division_Config (uint32_t FSCM_DIV)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FSMC_DIVISION(FSCM_DIV));

    /* ����FSMC�ķ�Ƶ */
    tmpreg = FSCM_DIV << OSC_CTL1_FSCMGAP0_POS;
    OSC_CTL1 = SFR_Config(OSC_CTL1, ~(OSC_CTL1_FSCMGAP), tmpreg);
}

/**
  * ����  ����ʱ�ӹ��ϼ��Դ��
  * ����  NewState: ʱ�ӹ��ϼ��ʹ��״̬��ȡֵ��ΧΪ��
  * 							FSCM_SOURCE_EXTHF�����EXTHF
  * 							FSCM_SOURCE_EXTLF�����EXTLF
  * 							FSCM_SOURCE_SCLK������Ƶǰ��SCLK
  * 							FSCM_SOURCE_INTLF�����INTLF
  * 							FSCM_SOURCE_INTHF�����INTHF
  * 							FSCM_SOURCE_PLL�����PLL
  * 							FSCM_SOURCE_LP4M�����LP4M
  * 							FSCM_SOURCE_SCLK_DIV������Ƶ���SCLK
  * ����  �ޡ�
  */
void OSC_Clock_Failure_Check_Source_Config (uint32_t FSCM_Source)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FSCM_SOURCE(FSCM_Source));

    /* ����FSMCS */
    tmpreg = FSCM_Source << OSC_CTL1_FSCMS0_POS;
    OSC_CTL1 = SFR_Config(OSC_CTL1, ~(OSC_CTL1_FSCMS), tmpreg);
}

/**
  * ����  ����PLL��Ƶѡ��
  * ����  PLLmultiple: PLL��Ƶ��ȡֵ��ΧΪ��
  *                PLLmultiple_M 0X04-0X3FFF��Χ(MҪ���ڵ���4, ��������200MHZ<��M*����ο�Ƶ��/N��<400MHZ)
  *                PLLmultiple_N 0X01-0XF��Χ,��������1MHZ<������ο�Ƶ��/N��<50MHZ
  *                PLLmultiple_NO ȡֵ��1/2/4/8ѡ����1����
  *
  *					�Ŵ���=PLLmultiple_M/��PLLmultiple_N*PLLmultiple_NO��
  * ����  �ޡ�
  */
void OSC_PLL_Multiple_Value_Select (uint32_t PLLmultiple_M,uint32_t PLLmultiple_N,uint32_t PLLmultiple_NO)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_PLL_MULTIPLE_MValue(PLLmultiple_M));
    CHECK_RESTRICTION(CHECK_PLL_MULTIPLE_NValue(PLLmultiple_N));
    CHECK_RESTRICTION(CHECK_PLL_MULTIPLE_NOValue(PLLmultiple_NO));

    if(PLLmultiple_NO==8){PLLmultiple_NO=3;}
    else if(PLLmultiple_NO==4){PLLmultiple_NO=2;}
    else if(PLLmultiple_NO==2){PLLmultiple_NO=1;}
    else if(PLLmultiple_NO==1){PLLmultiple_NO=0;}

    /*---------------- ����PLL_CTL�Ĵ���ODλNλMλ ----------------*/
    tmpreg = ((PLLmultiple_M << PLL_CTL_M0_POS) \
    		 | (PLLmultiple_N << PLL_CTL_N0_POS) \
    		 | (PLLmultiple_NO << PLL_CTL_OD0_POS));

    PLL_CTL = SFR_Config (PLL_CTL, ~(PLL_CTL_M | PLL_CTL_N | PLL_CTL_OD), tmpreg);
}

/**
  * ����  PLL��λ���ơ�
  * ���� :��
  * ���� ����
  */
void OSC_PLL_RST(void)
{
    /*---------------- ����PLL_CTL�Ĵ���PDRSTλ ----------------*/
    SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_PDRST_POS);
}

/**
  * ����  ����PLL�����ӳٿ��ơ�
  * ����  PLLDelay: PLL�����ӳٿ��ƣ�ȡֵ��ΧΪ��
  *                   PLL_START_DELAY_64: �ӳ�64��ʱ��
  *                   PLL_START_DELAY_128: �ӳ�128��ʱ��
  *                   PLL_START_DELAY_256: �ӳ�256��ʱ��
  *                   PLL_START_DELAY_512: �ӳ�512��ʱ��
  *                   PLL_START_DELAY_1024: �ӳ�1024��ʱ��
  *                   PLL_START_DELAY_2048: �ӳ�2048��ʱ��
  *                   PLL_START_DELAY_4096: �ӳ�4096��ʱ��
  *                   PLL_START_DELAY_8192: �ӳ�8192��ʱ��
  *                   PLL_START_DELAY_16384: �ӳ�16384��ʱ��
  *                   PLL_START_DELAY_32768: �ӳ�32768��ʱ��
  * ����  �ޡ�
  */
void OSC_PLL_Start_Delay_Config (uint32_t PLLDelay)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_PLL_START_DELAY(PLLDelay));

    /*---------------- ����OSC_CTL2�Ĵ���PLLDLYλ ----------------*/
    tmpreg = PLLDelay << OSC_CTL2_PLLDLY0_POS;
    OSC_CTL2 = SFR_Config (OSC_CTL2, ~OSC_CTL2_PLLDLY, tmpreg);
}

/**
  * ����  �����ⲿ��Ƶ�����ӳٿ��ơ�
  * ����  ExternalDelay: �ⲿ��Ƶ�����ӳٿ��ƣ�ȡֵ��ΧΪ��
  *                        EXT_START_DELAY_256: �ӳ�256��ʱ��
  *                        EXT_START_DELAY_512: �ӳ�512��ʱ��
  *                        EXT_START_DELAY_1024: �ӳ�1024��ʱ��
  *                        EXT_START_DELAY_2048: �ӳ�2048��ʱ��
  *                        EXT_START_DELAY_4096: �ӳ�4096��ʱ��
  *                        EXT_START_DELAY_8192: �ӳ�8192��ʱ��
  *                        EXT_START_DELAY_16384: �ӳ�16384��ʱ��
  *                        EXT_START_DELAY_32768: �ӳ�32768��ʱ��
  *                        EXT_START_DELAY_65536: �ӳ�65536��ʱ��
  *                        EXT_START_DELAY_131072: �ӳ�131072��ʱ��
  * ����  �ޡ�
  */
void OSC_EXTHF_Start_Delay_Config (uint32_t ExternalDelay)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EXT_START_DELAY(ExternalDelay));

    /*---------------- ����OSC_CTL2�Ĵ���EHFDLYλ ----------------*/
    tmpreg = ExternalDelay << OSC_CTL2_EHFDLY0_POS;
    OSC_CTL2 = SFR_Config (OSC_CTL2, ~OSC_CTL2_EHFDLY, tmpreg);
}

/**
  * ����  �����ⲿ��Ƶ�����ӳٿ��ơ�
  * ����  ExternalDelay: �ⲿ��Ƶ�����ӳٿ��ƣ�ȡֵ��ΧΪ��
  *                        EXT_START_DELAY_256: �ӳ�256��ʱ��
  *                        EXT_START_DELAY_512: �ӳ�512��ʱ��
  *                        EXT_START_DELAY_1024: �ӳ�1024��ʱ��
  *                        EXT_START_DELAY_2048: �ӳ�2048��ʱ��
  *                        EXT_START_DELAY_4096: �ӳ�4096��ʱ��
  *                        EXT_START_DELAY_8192: �ӳ�8192��ʱ��
  *                        EXT_START_DELAY_16384: �ӳ�16384��ʱ��
  *                        EXT_START_DELAY_32768: �ӳ�32768��ʱ��
  *                        EXT_START_DELAY_65536: �ӳ�65536��ʱ��
  *                        EXT_START_DELAY_131072: �ӳ�131072��ʱ��
  * ����  �ޡ�
  */
void OSC_EXTLF_Start_Delay_Config (uint32_t ExternalDelay)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EXT_START_DELAY(ExternalDelay));

    /*---------------- ����OSC_CTL2�Ĵ���ELFDLYλ ----------------*/
    tmpreg = ExternalDelay << OSC_CTL2_ELFDLY0_POS;
    OSC_CTL2 = SFR_Config (OSC_CTL2, ~OSC_CTL2_ELFDLY, tmpreg);
}

/**
  * ����  ����LP4M���ʹ�ܡ�
  * ����  NewState: LP4M���ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_LP4M_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���LP4MSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��LP4M���� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_LP4MSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_LP4MSWEN_POS);
    }
}

/**
  * ����  ����PLL���ʹ�ܡ�
  * ����  NewState: PLL���ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_PLL_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���PLLSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��PLL���� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_PLLSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_PLLSWEN_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ�������ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ�������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_EXTHF_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���EXTHFSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ⲿ��Ƶ�������� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_EXTHFSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_EXTHFSWEN_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ�������ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ�������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_EXTLF_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���EXTLFSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ⲿ��Ƶ�������� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_EXTLFSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_EXTLFSWEN_POS);
    }
}

/**
  * ����  �����ڲ���Ƶ�������ʹ�ܡ�
  * ����  NewState: �ڲ���Ƶ�������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_INTHF_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���INTHFSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ڲ���Ƶ�������� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_INTHFSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_INTHFSWEN_POS);
    }
}

/**
  * ����  �����ڲ���Ƶ�������ʹ�ܡ�
  * ����  NewState: �ڲ���Ƶ�������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_INTLF_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���INTLFSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ڲ���Ƶ�������� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_INTLFSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_INTLFSWEN_POS);
    }
}

/**
  * ����  ��������Ư�ľ���ֵУ׼Ȩ��λ��
  * ����  Scale: ����Ư������ѡ��ȡֵΪ���к��һ��������ϣ�
  *                ZERO_DRIFT_SCALEDIV32: 1/32uA������
  *                ZERO_DRIFT_SCALEDIV16: 1/16uA������
  *                ZERO_DRIFT_SCALEDIV8: 1/8uA������
  *                ZERO_DRIFT_SCALEDIV4: 1/4uA������
  *                ZERO_DRIFT_SCALEDIV2: 1/2uA������
  *                ZERO_DRIFT_SCALE1X: 1uA������
  *                ZERO_DRIFT_SCALE2X: 2uA������
  *                ZERO_DRIFT_SCALE4X: 4uA������
  *                ZERO_DRIFT_SCALE8X: 8uA������
  *                ZERO_DRIFT_SCALE16X0: 16uA������
  *                ZERO_DRIFT_SCALE16X1: 16uA������
  *                ZERO_DRIFT_SCALE16X2: 16uA������
  *                ZERO_DRIFT_SCALE16X3: 16uA������
  *                ZERO_DRIFT_SCALE16X4: 16uA������
  *                ZERO_DRIFT_SCALE32X: 32uA������
  *       NewState: ����Ư������״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_Zero_Drift_Config (uint32_t Scale, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ZERO_DRIFT(Scale));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_HFOSCCAL0�Ĵ��� ----------------*/
    if (NewState != FALSE)
    {
        /* ָ������������ */
        OSC_HFOSCCAL0 |= Scale;
    }
    else
    {
        /* ָ���������ر� */
        OSC_HFOSCCAL0 &= ~Scale;
    }
}

/**
  * ����  �����ڲ���Ƶ���������µ��ڡ�
  * ����  PositiveDrift: �ڲ���Ƶ���������µ��ڣ�ȡֵ��ΧΪ��0~31��
  * ����  �ޡ�
  */
void OSC_Positive_Drift_Config (uint32_t PositiveDrift)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_POSITIVE_DRIFT(PositiveDrift));

    /*---------------- ����OSC_HFOSCCAL0�Ĵ���PTATλ ----------------*/
    tmpreg = PositiveDrift << OSC_HFOSCCAL0_PTAT0_POS;
    OSC_HFOSCCAL0 = SFR_Config (OSC_HFOSCCAL0, ~OSC_HFOSCCAL0_PTAT, tmpreg);
}

/**
  * ����  �����ڲ���Ƶ�����ĸ��µ��ڡ�
  * ����  NegativeDrift: �ڲ���Ƶ�����ĸ��µ��ڣ�ȡֵ��ΧΪ��0~31��
  * ����  �ޡ�
  */
void OSC_Negative_Drift_Config (uint32_t PositiveDrift)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_NEGATIVE_DRIFT(PositiveDrift));

    /*---------------- ����OSC_HFOSCCAL0�Ĵ���CTATλ ----------------*/
    tmpreg = PositiveDrift << OSC_HFOSCCAL0_CTAT0_POS;
    OSC_HFOSCCAL0 = SFR_Config (OSC_HFOSCCAL0, ~OSC_HFOSCCAL0_CTAT, tmpreg);
}

/**
  * ����  ���õ�������ѡ��
  * ����  CurrentGain: ��������ѡ��ȡֵ��ΧΪ��0~3��
  * ����  �ޡ�
  */
void OSC_Current_Gain_Config (uint32_t PositiveDrift)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CURRENT_GAIN(PositiveDrift));

    /*---------------- ����OSC_HFOSCCAL1�Ĵ���SELGAINλ ----------------*/
    tmpreg = PositiveDrift << OSC_HFOSCCAL1_SELGAIN0_POS;
    OSC_HFOSCCAL1 = SFR_Config (OSC_HFOSCCAL1, ~OSC_HFOSCCAL1_SELGAIN, tmpreg);
}

/**
  * ����  ���ø���ѡ��
  * ����  NewState: ����ѡ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_High_Speed_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_HFOSCCAL1�Ĵ���HSFSENλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HSFSEN_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HSFSEN_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ��������ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ��������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_External_Input_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_HFOSCCAL1�Ĵ���HSXTALEXENλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HSXTALEXEN_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HSXTALEXEN_POS);
    }
}

/**
  * ����  ���÷���������ڡ�
  * ����  NewState: ����������ڣ�ȡֵ��ΧΪ��
  *                   FREQUENCY_MORE_THAN_10M: Ƶ�ʴ���10MHz��
  *                   FREQUENCY_LESS_THAN_10M: Ƶ��С��10MHz��
  * ����  �ޡ�
  */
void OSC_Feedback_Resistance_Config (uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FEEDBACK_RESISTANCE(NewState));

    /*---------------- ����OSC_HFOSCCAL1�Ĵ���HLSWλ ----------------*/
    if (NewState != FREQUENCY_MORE_THAN_10M)
    {
        /* Ƶ��С��10MHz */
        SFR_SET_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HLSW_POS);
    }
    else
    {
        /* Ƶ�ʴ���10MHz */
        SFR_CLR_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HLSW_POS);
    }
}

/**
  *   ##### ����(OSC)�жϿ��ƺ������� #####
  */

/**
  * ����  ����LP4M�ж�ʹ�ܡ�
  * ����  NewState: �ڲ���Ƶ�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_LP4M_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���LP4MIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_LP4MIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_LP4MIE_POS);
    }
}

/**
  * ����  ����PLL�ж�ʹ�ܡ�
  * ����  NewState: PLL�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_PLL_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���PLLIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_PLLIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_PLLIE_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ�ж�ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_EXTHF_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���EHFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_EHFIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_EHFIE_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ�ж�ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_EXTLF_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���ELFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_ELFIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_ELFIE_POS);
    }
}

/**
  * ����  �����ڲ���Ƶ�ж�ʹ�ܡ�
  * ����  NewState: �ڲ���Ƶ�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_INTHF_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���IHFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_IHFIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_IHFIE_POS);
    }
}

/**
  * ����  �����ڲ���Ƶ�ж�ʹ�ܡ�
  * ����  NewState: �ڲ���Ƶ�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void OSC_INTLF_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���ILFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_ILFIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_ILFIE_POS);
    }
}

/**
  * ����  ��ȡʱ�ӹ��ϱ�־��
  * ����  �ޡ�
  * ����  ʱ�ӹ���״̬��0��û��ʱ�ӹ��ϣ�1����⵽ʱ�ӹ��ϡ�
  */
FlagStatus OSC_Get_Clock_Failure_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���CKFIFλ ----------------*/
    if (OSC_INT & OSC_INT_CKFIF)
    {
        /* ��⵽ʱ�ӹ��� */
        return SET;
    }
    else
    {
        /* û��ʱ�ӹ��� */
        return RESET;
    }
}

/**
  * ����  ��ȡLP4M�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus OSC_Get_LP4MIF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���ILFIFλ ----------------*/
    if (OSC_INT & OSC_INT_LP4MIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  * ����  ��ȡPLL�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus OSC_Get_PLL_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���PLLIFλ ----------------*/
    if (OSC_INT & OSC_INT_PLLIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�ⲿ��Ƶ�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus OSC_Get_EXTHF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���EHFIFλ ----------------*/
    if (OSC_INT & OSC_INT_EHFIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�ⲿ��Ƶ�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus OSC_Get_EXTLF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���ELFIFλ ----------------*/
    if (OSC_INT & OSC_INT_ELFIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�ڲ���Ƶ�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus OSC_Get_INTHF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���IHFIFλ ----------------*/
    if (OSC_INT & OSC_INT_IHFIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�ڲ���Ƶ�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus OSC_Get_INTLF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���ILFIFλ ----------------*/
    if (OSC_INT & OSC_INT_ILFIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  *   ##### ����(OSC)�жϿ��ƺ���������� #####
  */
