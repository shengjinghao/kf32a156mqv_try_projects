/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_cmp.c                                        *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the comparator (CMP) 			  *
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


#include "kf32a1x6_cmp.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/* CMP˽�ж��� ----------------------------------------------------*/
/* CMP_CTL0�Ĵ����������� */
#define CMP_CTL0_INIT_MASK              (CMP_CTL0_PMOD \
                                       | CMP_CTL0_NMOD \
                                       | CMP_CTL0_IFFEN \
                                       | CMP_CTL0_IFREN \
                                       | CMP_CTL0_FLTCS \
                                       | CMP_CTL0_FLTDIV \
                                       | CMP_CTL0_FLTCNT \
                                       | CMP_CTL0_FLTEN \
                                       | CMP_CTL0_WINEN \
                                       | CMP_CTL0_POL)
/* CMP_CTL1�Ĵ����������� */
#define CMP_CTL1_INIT_MASK              (CMP_CTL1_PMOD \
                                       | CMP_CTL1_NMOD \
                                       | CMP_CTL1_IFFEN \
                                       | CMP_CTL1_IFREN \
                                       | CMP_CTL1_FLTCS \
                                       | CMP_CTL1_FLTDIV \
                                       | CMP_CTL1_FLTCNT \
                                       | CMP_CTL1_FLTEN \
                                       | CMP_CTL1_WINEN \
                                       | CMP_CTL1_POL)
/* CMP_CTL2�Ĵ����������� */
#define CMP_CTL2_INIT_MASK              (CMP_CTL2_PMOD \
                                       | CMP_CTL2_NMOD \
                                       | CMP_CTL2_IFFEN \
                                       | CMP_CTL2_IFREN \
                                       | CMP_CTL2_FLTCS \
                                       | CMP_CTL2_FLTDIV \
                                       | CMP_CTL2_FLTCNT \
                                       | CMP_CTL2_FLTEN \
                                       | CMP_CTL2_WINEN \
                                       | CMP_CTL2_POL)
/* CMP_CTL3�Ĵ����������� */
#define CMP_CTL3_INIT_MASK              (CMP_CTL3_PMOD \
                                       | CMP_CTL3_NMOD \
                                       | CMP_CTL3_FLTCS \
                                       | CMP_CTL3_FLTDIV \
                                       | CMP_CTL3_FLTCNT \
                                       | CMP_CTL3_FLTEN \
                                       | CMP_CTL3_WINEN \
                                       | CMP_CTL3_POL \
                                       | CMP_CTL3_EN_POS)



/**
  *   ##### ��ʼ�������ú��� #####
  */
/**
  * ����  CMP���踴λ��ʹ������ʱ�ӡ�
  * ����  CMPx: ��
  * ����  �ޡ�
  */
void CMP_Reset (void)
{
	RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_CMPRST, TRUE);
	RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_CMPRST, FALSE);
	PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_CMPCLKEN, TRUE);
}

/**
  * ����  CMP�������á�
  * ����  CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  *       CMPInitStruct: CMP������Ϣ
  * ����  �ޡ�
  */
void CMP_Configuration (uint32_t CMPx_ADDR, CMP_InitTypeDef* CMPInitStruct)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));

    if(CMPx_ADDR==CMP0_ADDR)
    {
    	CHECK_RESTRICTION(CHECK_CMP0_PositiveINPUT_PIN(CMPInitStruct->m_PositiveInput));
    	CHECK_RESTRICTION(CHECK_CMP0_NegativeINPUT_PIN(CMPInitStruct->m_NegativeInput));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_FallTriggerEnable));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_RiseTriggerEnable));
    	CHECK_RESTRICTION(CHECK_CMPx_CLKSOURCE_SEL(CMPInitStruct->m_Clock));
    	CHECK_RESTRICTION(CHECK_CMPx_FLT_SampleNumber_SEL(CMPInitStruct->m_SampleNumber));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_FilterEnable));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_ScopecontrolEnable));
    	CHECK_RESTRICTION(CHECK_CMPx_OUTPUT_POLARITY(CMPInitStruct->m_OutputPolarity));
    	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_CmpEnable));
        /*---------------------------- CMP_CTL0�Ĵ�������  -----------------*/
        /* ���ݽṹ���Աm_PositiveInput������PMOD0λ�� */
        /* ���ݽṹ���Աm_NegativeInput������NMOD0λ�� */
        /* ���ݽṹ���Աm_FallTriggerEnable������IFFENλ�� */
        /* ���ݽṹ���Աm_RiseTriggerEnable������IFRENλ�� */
        /* ���ݽṹ���Աm_Clock������FLTCSλ�� */
		/* ���ݽṹ���Աm_FrequencyDivision������FLTDIVλ�� */
        /* ���ݽṹ���Աm_SampleNumber������FLTCNTλ�� */
        /* ���ݽṹ���Աm_FilterEnable������FLTENλ�� */
        /* ���ݽṹ���Աm_ScopecontrolEnable������WINENλ�� */
        /* ���ݽṹ���Աm_OutputPolarity������POLλ�� */

	   tmpreg = ((CMPInitStruct->m_PositiveInput ) | \
				  (CMPInitStruct->m_NegativeInput) | \
				  (CMPInitStruct->m_FallTriggerEnable << CMP_CTL0_IFFEN_POS) | \
				  (CMPInitStruct->m_RiseTriggerEnable << CMP_CTL0_IFREN_POS) | \
				  (CMPInitStruct->m_Clock) | \
				  (CMPInitStruct->m_FrequencyDivision) | \
				  (CMPInitStruct->m_SampleNumber) | \
				  (CMPInitStruct->m_FilterEnable << CMP_CTL0_FLTEN_POS) | \
				  (CMPInitStruct->m_ScopecontrolEnable << CMP_CTL0_WINEN_POS) | \
				  (CMPInitStruct->m_OutputPolarity));
	   CMP_CTL0 = SFR_Config (CMP_CTL0, ~CMP_CTL0_INIT_MASK, tmpreg);

	    if ((CMPInitStruct->m_CmpEnable) != FALSE)
	    {
	        /* ʹ��CMP */
	        SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C0EN_POS);
	    }
	    else
	    {
	        /* ��ֹCMP */
	        SFR_CLR_BIT_ASM(CMP_CTL4, CMP_CTL4_C0EN_POS);
	    }
    }
    else if(CMPx_ADDR==CMP1_ADDR)
    {
    	CHECK_RESTRICTION(CHECK_CMP0_PositiveINPUT_PIN(CMPInitStruct->m_PositiveInput));
    	CHECK_RESTRICTION(CHECK_CMP0_NegativeINPUT_PIN(CMPInitStruct->m_NegativeInput));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_FallTriggerEnable));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_RiseTriggerEnable));
    	CHECK_RESTRICTION(CHECK_CMPx_CLKSOURCE_SEL(CMPInitStruct->m_Clock));
    	CHECK_RESTRICTION(CHECK_CMPx_FLT_SampleNumber_SEL(CMPInitStruct->m_SampleNumber));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_FilterEnable));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_ScopecontrolEnable));
    	CHECK_RESTRICTION(CHECK_CMPx_OUTPUT_POLARITY(CMPInitStruct->m_OutputPolarity));
    	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_CmpEnable));
        /*---------------------------- CMP_CTL0�Ĵ�������  -----------------*/
        /* ���ݽṹ���Աm_PositiveInput������PMOD0λ�� */
        /* ���ݽṹ���Աm_NegativeInput������NMOD0λ�� */
        /* ���ݽṹ���Աm_FallTriggerEnable������IFFENλ�� */
        /* ���ݽṹ���Աm_RiseTriggerEnable������IFRENλ�� */
        /* ���ݽṹ���Աm_Clock������FLTCSλ�� */
		/* ���ݽṹ���Աm_FrequencyDivision������FLTDIVλ�� */
        /* ���ݽṹ���Աm_SampleNumber������FLTCNTλ�� */
        /* ���ݽṹ���Աm_FilterEnable������FLTENλ�� */
        /* ���ݽṹ���Աm_ScopecontrolEnable������WINENλ�� */
        /* ���ݽṹ���Աm_OutputPolarity������POLλ�� */

	   tmpreg = ((CMPInitStruct->m_PositiveInput ) | \
				  (CMPInitStruct->m_NegativeInput) | \
				  (CMPInitStruct->m_FallTriggerEnable << CMP_CTL0_IFFEN_POS) | \
				  (CMPInitStruct->m_RiseTriggerEnable << CMP_CTL0_IFREN_POS) | \
				  (CMPInitStruct->m_Clock) | \
				  (CMPInitStruct->m_FrequencyDivision) | \
				  (CMPInitStruct->m_SampleNumber) | \
				  (CMPInitStruct->m_FilterEnable << CMP_CTL0_FLTEN_POS) | \
				  (CMPInitStruct->m_ScopecontrolEnable << CMP_CTL0_WINEN_POS) | \
				  (CMPInitStruct->m_OutputPolarity));
	   CMP_CTL1 = SFR_Config (CMP_CTL1, ~CMP_CTL1_INIT_MASK, tmpreg);

	    if ((CMPInitStruct->m_CmpEnable) != FALSE)
	    {
	        /* ʹ��CMP */
	        SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C1EN_POS);
	    }
	    else
	    {
	        /* ��ֹCMP */
	        SFR_CLR_BIT_ASM(CMP_CTL4, CMP_CTL4_C1EN_POS);
	    }
    }
    else if(CMPx_ADDR==CMP2_ADDR)
    {
    	CHECK_RESTRICTION(CHECK_CMP0_PositiveINPUT_PIN(CMPInitStruct->m_PositiveInput));
    	CHECK_RESTRICTION(CHECK_CMP0_NegativeINPUT_PIN(CMPInitStruct->m_NegativeInput));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_FallTriggerEnable));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_RiseTriggerEnable));
    	CHECK_RESTRICTION(CHECK_CMPx_CLKSOURCE_SEL(CMPInitStruct->m_Clock));
    	CHECK_RESTRICTION(CHECK_CMPx_FLT_SampleNumber_SEL(CMPInitStruct->m_SampleNumber));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_FilterEnable));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_ScopecontrolEnable));
    	CHECK_RESTRICTION(CHECK_CMPx_OUTPUT_POLARITY(CMPInitStruct->m_OutputPolarity));
    	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_CmpEnable));
        /*---------------------------- CMP_CTL0�Ĵ�������  -----------------*/
        /* ���ݽṹ���Աm_PositiveInput������PMOD0λ�� */
        /* ���ݽṹ���Աm_NegativeInput������NMOD0λ�� */
        /* ���ݽṹ���Աm_FallTriggerEnable������IFFENλ�� */
        /* ���ݽṹ���Աm_RiseTriggerEnable������IFRENλ�� */
        /* ���ݽṹ���Աm_Clock������FLTCSλ�� */
		/* ���ݽṹ���Աm_FrequencyDivision������FLTDIVλ�� */
        /* ���ݽṹ���Աm_SampleNumber������FLTCNTλ�� */
        /* ���ݽṹ���Աm_FilterEnable������FLTENλ�� */
        /* ���ݽṹ���Աm_ScopecontrolEnable������WINENλ�� */
        /* ���ݽṹ���Աm_OutputPolarity������POLλ�� */

	   tmpreg = ((CMPInitStruct->m_PositiveInput ) | \
				  (CMPInitStruct->m_NegativeInput) | \
				  (CMPInitStruct->m_FallTriggerEnable << CMP_CTL0_IFFEN_POS) | \
				  (CMPInitStruct->m_RiseTriggerEnable << CMP_CTL0_IFREN_POS) | \
				  (CMPInitStruct->m_Clock) | \
				  (CMPInitStruct->m_FrequencyDivision) | \
				  (CMPInitStruct->m_SampleNumber) | \
				  (CMPInitStruct->m_FilterEnable << CMP_CTL0_FLTEN_POS) | \
				  (CMPInitStruct->m_ScopecontrolEnable << CMP_CTL0_WINEN_POS) | \
				  (CMPInitStruct->m_OutputPolarity));
	   CMP_CTL2 = SFR_Config (CMP_CTL2, ~CMP_CTL2_INIT_MASK, tmpreg);

	    if ((CMPInitStruct->m_CmpEnable) != FALSE)
	    {
	        /* ʹ��CMP */
	        SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C2EN_POS);
	    }
	    else
	    {
	        /* ��ֹCMP */
	        SFR_CLR_BIT_ASM(CMP_CTL4, CMP_CTL4_C2EN_POS);
	    }
    }
    else if(CMPx_ADDR==CMP3_ADDR)
    {
       	CHECK_RESTRICTION(CHECK_CMP3_PositiveINPUT_PIN(CMPInitStruct->m_PositiveInput));
		CHECK_RESTRICTION(CHECK_CMP3_NegativeINPUT_PIN(CMPInitStruct->m_NegativeInput));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_FallTriggerEnable));
        CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_RiseTriggerEnable));
		CHECK_RESTRICTION(CHECK_CMPx_CLKSOURCE_SEL(CMPInitStruct->m_Clock));
		CHECK_RESTRICTION(CHECK_CMPx_FLT_SampleNumber_SEL(CMPInitStruct->m_SampleNumber));
		CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_FilterEnable));
		CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_ScopecontrolEnable));
		CHECK_RESTRICTION(CHECK_CMPx_OUTPUT_POLARITY(CMPInitStruct->m_OutputPolarity));
		CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(CMPInitStruct->m_CmpEnable));
		/*---------------------------- CMP_CTL3�Ĵ�������  -----------------*/
		/* ���ݽṹ���Աm_PositiveInput������PMOD0λ�� */
		/* ���ݽṹ���Աm_NegativeInput������NMOD0λ�� */
        /* ���ݽṹ���Աm_FallTriggerEnable������IFFENλ�� */
        /* ���ݽṹ���Աm_RiseTriggerEnable������IFRENλ�� */
		/* ���ݽṹ���Աm_Clock������FLTCSλ�� */
		/* ���ݽṹ���Աm_FrequencyDivision������FLTDIVλ�� */
		/* ���ݽṹ���Աm_SampleNumber������FLTCNTλ�� */
		/* ���ݽṹ���Աm_FilterEnable������FLTENλ�� */
		/* ���ݽṹ���Աm_ScopecontrolEnable������WINENλ�� */
		/* ���ݽṹ���Աm_OutputPolarity������POLλ�� */

	   tmpreg = ((CMPInitStruct->m_PositiveInput ) | \
				  (CMPInitStruct->m_NegativeInput) | \
				  (CMPInitStruct->m_FallTriggerEnable << CMP_CTL0_IFFEN_POS) | \
				  (CMPInitStruct->m_RiseTriggerEnable << CMP_CTL0_IFREN_POS) | \
				  (CMPInitStruct->m_Clock) | \
				  (CMPInitStruct->m_FrequencyDivision) | \
				  (CMPInitStruct->m_SampleNumber) | \
				  (CMPInitStruct->m_FilterEnable << CMP_CTL3_FLTEN_POS) | \
				  (CMPInitStruct->m_ScopecontrolEnable << CMP_CTL3_WINEN_POS) | \
				  (CMPInitStruct->m_OutputPolarity) | \
				  (CMPInitStruct->m_CmpEnable << CMP_CTL3_EN_POS));
	   CMP_CTL3 = SFR_Config (CMP_CTL3, ~CMP_CTL3_INIT_MASK, tmpreg);
    }
    else
    {
    	;
    }
    CMP_CTL4 |= (uint32_t)1 << 10;  //CMP��IO���ʹ��
}

/**
  * ����  ��ʼ��CMP������Ϣ�ṹ�塣
  * ����  CMPInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void CMP_Struct_Init (CMP_InitTypeDef* CMPInitStruct)
{
    /* ��ʼ�� CMP����������ѡ��λ */
    CMPInitStruct->m_PositiveInput = CMP0_PositiveINPUT_PIN_PA0;
    /* ��ʼ�� CMP�ĸ�������ѡ��λ */
    CMPInitStruct->m_NegativeInput = CMP0_NegativeINPUT_PIN_PA1;
    /* ��ʼ�� CMP�½��ش����ж�ʹ�� */
    CMPInitStruct->m_FallTriggerEnable = FALSE;
    /* ��ʼ�� CMP�����ش����ж�ʹ�� */
    CMPInitStruct->m_RiseTriggerEnable = FALSE;
    /* ��ʼ��CMP�˲����˲�ʱ��Դ */
    CMPInitStruct->m_Clock = CMPx_CLKSOURCE_SCLK;
    /* ��ʼ��CMP�˲����˲�ʱ�ӷ�Ƶ*/
    CMPInitStruct->m_FrequencyDivision = 0x00;//1��Ƶ��ֵ��Χ0-255��
    /* ��ʼ�� CMPȡ������ѡ�� */
    CMPInitStruct->m_SampleNumber = CMPx_FLT_OFF;
    /* ��ʼ��CMP�˲���ʹ��λ */
    CMPInitStruct->m_FilterEnable = FALSE;
    /* ��ʼ��CMP��Χ����ʹ��λ*/
    CMPInitStruct->m_ScopecontrolEnable = FALSE;
    /* ��ʼ�� CMP�������ѡ��*/
    CMPInitStruct->m_OutputPolarity =CMPx_OUTPUT_Normal;
    /* ��ʼ��CMP�Ƚ���ʹ�� */
    CMPInitStruct->m_CmpEnable =FALSE;
}

/**
  * ����  CMP��IOͨ��ʹ�ܡ�
  * ����  NewState: ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  * ע����1��PMOD<3:0>�� NMOD<3:0>����Ч
  */
void CMP_IO_Channel_Enable(FunctionalState NewState)
{
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CMP_CTL4 |= (uint32_t)NewState << CMP_CTL4_IOEN_POS;
}

/**
  * ����  CMP0��������˿��ź�ѡ��
  * ����ѡ��:
  *           CMP0_PositiveINPUT_PIN_PA0
  *           CMP0_PositiveINPUT_PIN_PA9
  *           CMP0_PositiveINPUT_PIN_PB2
  *           CMP0_PositiveINPUT_PIN_PB9
  *           CMP0_PositiveINPUT_PIN_PC11
  *           CMP0_PositiveINPUT_PIN_AGND
  *           CMP0_PositiveINPUT_PIN_DAC0OUT
  *           CMP0_PositiveINPUT_PIN_DAC1OUT
  *           CMP0_PositiveINPUT_PIN_PA3
  *           CMP0_PositiveINPUT_PIN_PA4
  *           CMP0_PositiveINPUT_PIN_PA5
  *           CMP0_PositiveINPUT_PIN_PD9
  *           CMP0_PositiveINPUT_PIN_PG1
  *           CMP0_PositiveINPUT_PIN_PG2
  *           CMP0_PositiveINPUT_PIN_PD14
  *           CMP0_PositiveINPUT_PIN_PE7
  *
  * ����  �ޡ�
  */
void CMP0_POSITIVE_INPUT_SELECT (uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP0_PositiveINPUT_PIN(Select));
    /*------------- ����CMP_CTL0�Ĵ���PMODλ -------------*/
    CMP_CTL0 = SFR_Config (CMP_CTL0,
                               ~CMP_CTL0_PMOD,
                               Select);
}

/**
  * ����  CMP0��������˿��ź�ѡ��
  * ����ѡ��:
  *           CMP0_NegativeINPUT_PIN_PA1
  *           CMP0_NegativeINPUT_PIN_PA10
  *           CMP0_NegativeINPUT_PIN_PB3
  *           CMP0_NegativeINPUT_PIN_PB10
  *           CMP0_NegativeINPUT_PIN_PC12
  *           CMP0_NegativeINPUT_PIN_AGND
  *           CMP0_NegativeINPUT_PIN_DAC0OUT
  *           CMP0_NegativeINPUT_PIN_DAC1OUT
  *           CMP0_NegativeINPUT_PIN_PA3
  *           CMP0_NegativeINPUT_PIN_PA4
  *           CMP0_NegativeINPUT_PIN_PA5
  *           CMP0_NegativeINPUT_PIN_PG1
  *           CMP0_NegativeINPUT_PIN_PG2
  *           CMP0_NegativeINPUT_PIN_PD15
  *           CMP0_NegativeINPUT_PIN_PE7
  *
  * ����  �ޡ�
  */
void CMP0_NEGATIVE_INPUT_SELECT (uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP0_NegativeINPUT_PIN(Select));
    /*------------- ����CMP_CTL0�Ĵ���NMODλ -------------*/
    CMP_CTL0 = SFR_Config (CMP_CTL0,
                               ~CMP_CTL0_NMOD,
                               Select);
}

/**
  * ����  CMP1��������˿��ź�ѡ��
  * ����ѡ��:
  *           CMP1_PositiveINPUT_PIN_PA0
  *           CMP1_PositiveINPUT_PIN_PA9
  *           CMP1_PositiveINPUT_PIN_PB2
  *           CMP1_PositiveINPUT_PIN_PB11
  *           CMP1_PositiveINPUT_PIN_PG7
  *           CMP1_PositiveINPUT_PIN_AGND
  *           CMP1_PositiveINPUT_PIN_DAC0OUT
  *           CMP1_PositiveINPUT_PIN_DAC1OUT
  *           CMP1_PositiveINPUT_PIN_PG0
  *           CMP1_PositiveINPUT_PIN_PD7
  *           CMP1_PositiveINPUT_PIN_PC15
  *           CMP1_PositiveINPUT_PIN_PD10
  *           CMP1_PositiveINPUT_PIN_PD14
  * ����  �ޡ�
  */
void CMP1_POSITIVE_INPUT_SELECT (uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP1_PositiveINPUT_PIN(Select));
    /*------------- ����CMP_CTL1�Ĵ���PMODλ -------------*/
    CMP_CTL1 = SFR_Config (CMP_CTL1,
                               ~CMP_CTL1_PMOD,
                               Select);
}

/**
  * ����  CMP1��������˿��ź�ѡ��
  * ����ѡ��:
  *           CMP1_NegativeINPUT_PIN_PA1
  *           CMP1_NegativeINPUT_PIN_PA10
  *           CMP1_NegativeINPUT_PIN_PB3
  *           CMP1_NegativeINPUT_PIN_PB12
  *           CMP1_NegativeINPUT_PIN_PC9
  *           CMP1_NegativeINPUT_PIN_AGND
  *           CMP1_NegativeINPUT_PIN_DAC0OUT
  *           CMP1_NegativeINPUT_PIN_DAC1OUT
  *           CMP1_NegativeINPUT_PIN_PH10
  *           CMP1_NegativeINPUT_PIN_PD6
  *           CMP1_NegativeINPUT_PIN_PC15
  *           CMP1_NegativeINPUT_PIN_PD15
  *
  * ����  �ޡ�
  */
void CMP1_NEGATIVE_INPUT_SELECT (uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP1_NegativeINPUT_PIN(Select));
    /*------------- ����CMP_CTL1�Ĵ���NMODλ -------------*/
    CMP_CTL1 = SFR_Config (CMP_CTL1,
                               ~CMP_CTL1_NMOD,
                               Select);
}

/**
  * ����  CMP2��������˿��ź�ѡ��
  * ����ѡ��:
  *           CMP2_PositiveINPUT_PIN_PA0
  *           CMP2_PositiveINPUT_PIN_PA9
  *           CMP2_PositiveINPUT_PIN_PB2
  *           CMP2_PositiveINPUT_PIN_PB13
  *           CMP2_PositiveINPUT_PIN_PC7
  *           CMP2_PositiveINPUT_PIN_AGND
  *           CMP2_PositiveINPUT_PIN_DAC0OUT
  *           CMP2_PositiveINPUT_PIN_DAC1OUT
  *           CMP2_PositiveINPUT_PIN_PC0
  *           CMP2_PositiveINPUT_PIN_PD5
  *           CMP2_PositiveINPUT_PIN_PD14
  *
  * ����  �ޡ�
  */
void CMP2_POSITIVE_INPUT_SELECT (uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP2_PositiveINPUT_PIN(Select));
    /*------------- ����CMP_CTL2�Ĵ���PMODλ -------------*/
    CMP_CTL2 = SFR_Config (CMP_CTL2,
                               ~CMP_CTL2_PMOD,
                               Select);
}

/**
  * ����  CMP2��������˿��ź�ѡ��
  * ����ѡ��:
  *           CMP2_NegativeINPUT_PIN_PA1
  *           CMP2_NegativeINPUT_PIN_PA10
  *           CMP2_NegativeINPUT_PIN_PB3
  *           CMP2_NegativeINPUT_PIN_PB14
  *           CMP2_NegativeINPUT_PIN_PC8
  *           CMP2_NegativeINPUT_PIN_AGND
  *           CMP2_NegativeINPUT_PIN_DAC0OUT
  *           CMP2_NegativeINPUT_PIN_DAC1OUT
  *           CMP2_NegativeINPUT_PIN_PC0
  *           CMP2_NegativeINPUT_PIN_PD4
  *           CMP2_NegativeINPUT_PIN_PD15
  *
  * ����  �ޡ�
  */
void CMP2_NEGATIVE_INPUT_SELECT (uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP2_NegativeINPUT_PIN(Select));
    /*------------- ����CMP_CTL2�Ĵ���NMODλ -------------*/
    CMP_CTL2 = SFR_Config (CMP_CTL2,
                               ~CMP_CTL2_NMOD,
                               Select);
}

/**
  * ����  CMP3��������˿��ź�ѡ��
  * ����ѡ��:
  * 		  CMP3_PositiveINPUT_PIN_PA0
  *           CMP3_PositiveINPUT_PIN_PA9
  *           CMP3_PositiveINPUT_PIN_PB2
  *           CMP3_PositiveINPUT_PIN_PB15
  *           CMP3_PositiveINPUT_PIN_PC5
  *           CMP3_PositiveINPUT_PIN_AGND
  *           CMP3_PositiveINPUT_PIN_DAC0OUT
  *           CMP3_PositiveINPUT_PIN_DAC1OUT
  *           CMP3_PositiveINPUT_PIN_PE8
  *           CMP3_PositiveINPUT_PIN_PG4
  *           CMP3_PositiveINPUT_PIN_PA6
  *           CMP3_PositiveINPUT_PIN_PD14
  *
  * ����  �ޡ�
  */
void CMP3_POSITIVE_INPUT_SELECT (uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP3_PositiveINPUT_PIN(Select));

    /*------------- ����CMP_CTL3�Ĵ���PMODλ -------------*/
    CMP_CTL3 = SFR_Config (CMP_CTL3,
                               ~CMP_CTL3_PMOD,
                               Select);
}

/**
  * ����  CMP3��������˿��ź�ѡ��
  * ����ѡ��:
  *           CMP3_NegativeINPUT_PIN_PA1
  *           CMP3_NegativeINPUT_PIN_PA10
  *           CMP3_NegativeINPUT_PIN_PB3
  *           CMP3_NegativeINPUT_PIN_PF0
  *           CMP3_NegativeINPUT_PIN_PC6
  *           CMP3_NegativeINPUT_PIN_AGND
  *           CMP3_NegativeINPUT_PIN_DAC0OUT
  *           CMP3_NegativeINPUT_PIN_DAC1OUT
  *           CMP3_NegativeINPUT_PIN_PE9
  *           CMP3_NegativeINPUT_PIN_PG4
  *           CMP3_NegativeINPUT_PIN_PA6
  *           CMP3_NegativeINPUT_PIN_PD15
  *
  * ����  �ޡ�
  */
void CMP3_NEGATIVE_INPUT_SELECT (uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP3_NegativeINPUT_PIN(Select));
    /*------------- ����CMP_CTL3�Ĵ���NMODλ -------------*/
    CMP_CTL3 = SFR_Config (CMP_CTL3,
                               ~CMP_CTL3_NMOD,
                               Select);
}

/**
  * ����  CMPx�������ѡ��
  * ���� 	CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 		Polarity:
  * 			CMPx_OUTPUT_Normal: ����У׼
  * 			CMPx_OUTPUT_Opposite: ����У׼
  */
void CMP_OUTPUT_POL_SELECT(uint32_t CMPx_ADDR, uint32_t Polarity)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_CMPx_OUTPUT_POLARITY(Polarity));
	 /*------------- ����CMP_CTLx�Ĵ���POLλ -------------*/
	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
	    CMP_CTL0 = SFR_Config (CMP_CTL0, ~CMP_CTL0_POL, Polarity);
		break;
	case CMP1_ADDR:
		CMP_CTL1 = SFR_Config (CMP_CTL1, ~CMP_CTL0_POL, Polarity);
		break;
	case CMP2_ADDR:
		CMP_CTL2 = SFR_Config (CMP_CTL2, ~CMP_CTL0_POL, Polarity);
		break;
	case CMP3_ADDR:
		CMP_CTL3 = SFR_Config (CMP_CTL3, ~CMP_CTL0_POL, Polarity);
		break;
	default:break;
	}
}

/**
  * ����  CMP�����IO��ѡ��
  * ����ѡ��:
  * 		  NONE
  *           CMP0_OUTPUT
  *           CMP1_OUTPUT
  *           CMP2_OUTPUT
  * ����  �ޡ�
  */
void CMP_OUTPUT_SELECT (uint32_t Select)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP_OUTPUT(Select));
    /*------------- ����CMP_CTL2�Ĵ���POLλ -------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4,
                               ~CMP_CTL4_CMPOUTASEL,
                               Select);
}

/**
  * ����  ����CMP0ʹ��λ��
  * ���� 	CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 		NewState: ȡֵΪ TRUE �� FALSE��
  * ����  �ޡ�
  */
void CMP_Cmd(uint32_t CMPx_ADDR, uint32_t NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
	    CMP_CTL4 = SFR_Config (CMP_CTL4, ~CMP_CTL4_C0EN, NewState << CMP_CTL4_C0EN_POS);
		break;
	case CMP1_ADDR:
		CMP_CTL4 = SFR_Config (CMP_CTL4, ~CMP_CTL4_C1EN, NewState << CMP_CTL4_C1EN_POS);
		break;
	case CMP2_ADDR:
		CMP_CTL4 = SFR_Config (CMP_CTL4, ~CMP_CTL4_C2EN, NewState << CMP_CTL4_C2EN_POS);
		break;
	case CMP3_ADDR:
		CMP_CTL3 = SFR_Config (CMP_CTL3, ~CMP_CTL3_EN, NewState << CMP_CTL3_EN_POS);
		break;
	default:break;
	}
}

/**
  * ���� CMP0/1/2/3 window controlʱ��ѡ��
  * ���� CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 	Select:
  * 			CMP_WIN_CONTROL_SYS_CLK: ѡ��ϵͳʱ��
  * 			CMP_WIN_CONTROL_TRGMUX_CLK:  ѡ�� TRGMUX ������ź�
  * ����  ��
  */
void CMP_WIN_Control_CLK_Select(uint32_t CMPx_ADDR, uint32_t Select)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_WIN_CONTROL_CLK(Select));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_CTL0 = SFR_Config(CMP_CTL0, ~CMP_CTL0_WINCLKSEL, Select << CMP_CTL0_WINCLKSEL_POS);
		break;
	case CMP1_ADDR:
		CMP_CTL1 = SFR_Config(CMP_CTL1, ~CMP_CTL0_WINCLKSEL, Select << CMP_CTL0_WINCLKSEL_POS);
		break;
	case CMP2_ADDR:
		CMP_CTL2 = SFR_Config(CMP_CTL2, ~CMP_CTL0_WINCLKSEL, Select << CMP_CTL0_WINCLKSEL_POS);
		break;
	case CMP3_ADDR:
		CMP_CTL3 = SFR_Config(CMP_CTL3, ~CMP_CTL0_WINCLKSEL, Select << CMP_CTL0_WINCLKSEL_POS);
		break;
	default:break;
	}
}

/**
  * ���� CMP0/1/2/3 �˲�ʱ��ѡ��
  * ���� CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 	Select:
  * 			CMPx_CLKSOURCE_SCLK:  �˲�ʱ��ԴΪSCLKϵͳʱ��
  * 			CMPx_CLKSOURCE_HFCLK: �˲�ʱ��ԴΪ HFCLK ��Ƶ����ʱ��
  * 			CMPx_CLKSOURCE_LFCLK: �˲�ʱ��ԴΪ LFCLK ��Ƶ����ʱ��
  * ����  ��
  */
void CMP_Filter_CLKSource_Select(uint32_t CMPx_ADDR, uint32_t Select)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_CMPx_CLKSOURCE_SEL(Select));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_CTL0 = SFR_Config(CMP_CTL0, ~CMP_CTL0_FLTCS, Select);
		break;
	case CMP1_ADDR:
		CMP_CTL1 = SFR_Config(CMP_CTL1, ~CMP_CTL1_FLTCS, Select);
		break;
	case CMP2_ADDR:
		CMP_CTL2 = SFR_Config(CMP_CTL2, ~CMP_CTL2_FLTCS, Select);
		break;
	case CMP3_ADDR:
		CMP_CTL3 = SFR_Config(CMP_CTL3, ~CMP_CTL3_FLTCS, Select);
		break;
	default:break;
	}
}

/**
  * ���� CMP0/1/2/3 �˲���ȡ������ѡ��
  * ���� CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 	Select:
  * 			CMPx_FLT_OFF:  �˲������������˲����ܱ���ֹ
  * 			CMPx_FLT_SampleNumber_1: �˳�����С��1��FILT_CLK���ڵ����������Ƚ��������ʱ 0~1 �� FILT_CLK����ʱ��
  * 			CMPx_FLT_SampleNumber_2: �˳�����С��2��FILT_CLK���ڵ����������Ƚ��������ʱ 1~2 �� FILT_CLK����ʱ��
  * 			CMPx_FLT_SampleNumber_3: �˳�����С��3��FILT_CLK���ڵ����������Ƚ��������ʱ 2~3 �� FILT_CLK����ʱ��
  * 			CMPx_FLT_SampleNumber_4: �˳�����С��4��FILT_CLK���ڵ����������Ƚ��������ʱ 3~4 �� FILT_CLK����ʱ��
  * 			CMPx_FLT_SampleNumber_5: �˳�����С��5��FILT_CLK���ڵ����������Ƚ��������ʱ 4~5 �� FILT_CLK����ʱ��
  * 			CMPx_FLT_SampleNumber_6: �˳�����С��6��FILT_CLK���ڵ����������Ƚ��������ʱ 5~6 �� FILT_CLK����ʱ��
  * 			CMPx_FLT_SampleNumber_7: �˳�����С��7��FILT_CLK���ڵ����������Ƚ��������ʱ 6~7 �� FILT_CLK����ʱ��
  * ����  ��
  */
void CMP_Filter_SampleNumber_Select(uint32_t CMPx_ADDR, uint32_t Select)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_CMPx_FLT_SampleNumber_SEL(Select));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_CTL0 = SFR_Config(CMP_CTL0, ~CMP_CTL0_FLTCNT, Select);
		break;
	case CMP1_ADDR:
		CMP_CTL1 = SFR_Config(CMP_CTL1, ~CMP_CTL1_FLTCNT, Select);
		break;
	case CMP2_ADDR:
		CMP_CTL2 = SFR_Config(CMP_CTL2, ~CMP_CTL2_FLTCNT, Select);
		break;
	case CMP3_ADDR:
		CMP_CTL3 = SFR_Config(CMP_CTL3, ~CMP_CTL3_FLTCNT, Select);
		break;
	default:break;
	}
}



/**
  *   ##### ��ʼ�������ú������� #####
  */

/**
  * ����  ����CMPx������/�½����ж�ʹ�ܡ�
  * ���� 	CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 		UDEdge �� CMPx_UD_EDGE_INT�� �Ƚ��� x�����ش����ж�
  * 				 CMPx_DOWN_EDGE_INT: �Ƚ��� x�½��ش����ж�
  * 		NewState : TRUE/FALSE
  * ����  CMPx���״̬��
  */
void CMP_Up_Down_Edge_INT_Enable(uint32_t CMPx_ADDR, uint32_t UDEdge, uint32_t NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_CMPx_EDGE_INT_SEL(UDEdge));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_CTL0 = SFR_Config (CMP_CTL0, ~(1<<UDEdge), NewState<<UDEdge);
		break;
	case CMP1_ADDR:
		CMP_CTL1 = SFR_Config (CMP_CTL1, ~(1<<UDEdge), NewState<<UDEdge);
		break;
	case CMP2_ADDR:
		CMP_CTL2 = SFR_Config (CMP_CTL2, ~(1<<UDEdge), NewState<<UDEdge);
		break;
	case CMP3_ADDR:
		CMP_CTL3 = SFR_Config (CMP_CTL3, ~(1<<UDEdge), NewState<<UDEdge);
		break;
	default:break;
	}
}

/**
  * ����  ��ȡCMPx�����״̬��
  * ���� 	CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * ����  CMPx���״̬��
  */
FlagStatus CMP_Get_Output_State(uint32_t CMPx_ADDR)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
	    return ((CMP_CTL4 & CMP_CTL4_C0OUT) >> CMP_CTL4_C0OUT_POS);
		break;
	case CMP1_ADDR:
		return ((CMP_CTL4 & CMP_CTL4_C1OUT) >> CMP_CTL4_C1OUT_POS);
		break;
	case CMP2_ADDR:
		return ((CMP_CTL4 & CMP_CTL4_C2OUT) >> CMP_CTL4_C2OUT_POS);
		break;
	case CMP3_ADDR:
		return ((CMP_CTL4 & CMP_CTL4_C3OUT) >> CMP_CTL4_C3OUT_POS);
		break;
	default:break;
	}
}

/**
  * ����  ��ȡCMPx�жϱ�־״̬��
  * ���� 	CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * ����  CMPx�жϱ�־״̬��
  */
FlagStatus CMP_Get_INT_Flag(uint32_t CMPx_ADDR)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
	    return ((CMP_CTL4 & CMP_CTL4_C0IF) >> CMP_CTL4_C0IF_POS);
		break;
	case CMP1_ADDR:
		return ((CMP_CTL4 & CMP_CTL4_C1IF) >> CMP_CTL4_C1IF_POS);
		break;
	case CMP2_ADDR:
		return ((CMP_CTL4 & CMP_CTL4_C2IF) >> CMP_CTL4_C2IF_POS);
		break;
	case CMP3_ADDR:
		return ((CMP_CTL4 & CMP_CTL4_C3IF) >> CMP_CTL4_C3IF_POS);
		break;
	default:break;
	}
}

/**
  * ����  ���ô���ѡ��λ��
  * ���� TriSelect: ����ѡ��
  *                     CMP_CMPOUT_FlipLatch_INT :ͨ���Ƚ������������״̬�Ƚϴ����жϱ�־
  *                     CMP_CMPOUT_Change_INT :ͨ�����Ƚ�������仯�ش����жϱ�־
  * ����  ��
  */
void CMP_Trigger_Select_Config (uint32_t TriSelect)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CMP_TriggerINT_MODE(TriSelect));

    /*-------------------- ����CMP_CTL4�Ĵ���CIFMSλ --------------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4, ~CMP_CTL4_CIFMS, TriSelect);
}

/**
  * ����  ���CMPx�жϱ�־��
  * ���� 	CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * ����  :�Ƿ�ɹ����״̬��
  */
RetStatus CMP_Clear_INT_Flag(uint32_t CMPx_ADDR)
{
	uint32_t wait_flag = 0x0000;
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
	    SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C0IC_POS);
	    while((CMP_CTL4 & CMP_CTL4_C0IF)&& (wait_flag != FLAG_TIMEOUT))
		{
			wait_flag++;
		}
	    SFR_CLR_BIT_ASM(CMP_CTL4, CMP_CTL4_C0IC_POS);
		break;
	case CMP1_ADDR:
	    SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C1IC_POS);
	    while((CMP_CTL4 & CMP_CTL4_C1IF)&& (wait_flag != FLAG_TIMEOUT))
		{
			wait_flag++;
		}
	    SFR_CLR_BIT_ASM(CMP_CTL4, CMP_CTL4_C1IC_POS);
		break;
	case CMP2_ADDR:
	    SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C2IC_POS);
	    while((CMP_CTL4 & CMP_CTL4_C2IF)&& (wait_flag != FLAG_TIMEOUT))
		{
			wait_flag++;
		}
	    SFR_CLR_BIT_ASM(CMP_CTL4, CMP_CTL4_C2IC_POS);
		break;
	case CMP3_ADDR:
	    SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C3IC_POS);
	    while((CMP_CTL4 & CMP_CTL4_C3IF)&& (wait_flag != FLAG_TIMEOUT))
		{
			wait_flag++;
		}
	    SFR_CLR_BIT_ASM(CMP_CTL4, CMP_CTL4_C3IC_POS);
		break;
	default:break;
	}
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * ����  ����CMPx�ж�ʹ�ܡ�
  * ���� 	CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 		NewState: ȡֵΪ TRUE �� FALSE��
  * ����  �ޡ�
  */
void CMP_INT_Enable(uint32_t CMPx_ADDR, uint32_t NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_CTL4 = SFR_Config (CMP_CTL4, ~CMP_CTL4_C0IE, NewState << CMP_CTL4_C0IE_POS);
		break;
	case CMP1_ADDR:
		CMP_CTL4 = SFR_Config (CMP_CTL4, ~CMP_CTL4_C1IE, NewState << CMP_CTL4_C1IE_POS);
		break;
	case CMP2_ADDR:
		CMP_CTL4 = SFR_Config (CMP_CTL4, ~CMP_CTL4_C2IE, NewState << CMP_CTL4_C2IE_POS);
		break;
	case CMP3_ADDR:
		CMP_CTL4 = SFR_Config (CMP_CTL4, ~CMP_CTL4_C3IE, NewState << CMP_CTL4_C3IE_POS);
		break;
	default:break;
	}
}

/**
  * ����  ����CMP���͵�ѹѡ��λ
  * ���� Select: ȡֵ��ΧΪ��
  * CMP_SluggishVoltage_OFF
  * CMP_SluggishVoltage_7p5mV
  * CMP_SluggishVoltage_12mV
  * CMP_SluggishVoltage_30mV
  * ����  ��
  */
void CMP_SluggishVoltage_Select (uint32_t Select)
{
    CHECK_RESTRICTION(CHECK_CMP_SluggishVoltage_SEL(Select));

    /*-------------------- ����CMP_CTL4�Ĵ���TRIMλ --------------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4,
                          ~CMP_CTL4_DELAYVOL,
                          Select);
}

/**
  * ����  ����ģʽѡ��λ
  * ���� Select: ȡֵ��ΧΪ��
  * CMP_HALLMODE_SINGLE
  * CMP_HALLMODE_BOTH
  * ����  ��
  */
void CMP_HALLMODE_Select (uint32_t Select)
{
    CHECK_RESTRICTION(CHECK_CMP_HALLMODE_SEL(Select));

    /*-------------------- ����CMP_CTL4�Ĵ���TRIMλ --------------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4,
                          ~CMP_CTL4_HALSEL,
                          Select);
}

/**
  * ����  ����綯��ģʽʹ��
  * ���� NewState: �ж�ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void CMP_BEMF_Enable (FunctionalState NewState)
{
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����CMP_CTL4�Ĵ���BEMFENλ --------------------*/
    if (NewState != FALSE)
    {
        /* ������綯��ģʽʹ�� */
        SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_BEMFEN_POS);
    }
    else
    {
        /* ��ֹ����綯��ģʽʹ�� */
        SFR_CLR_BIT_ASM(CMP_CTL4, CMP_CTL4_BEMFEN_POS);
    }
}

/**
  * ����  �˲�������ѡ��λ
  * ���� Select: ȡֵ��ΧΪ��
  * CMP_FLTINSEL_CMPOUT
  * CMP_FLTINSEL_IO
  * ����  ��
  */
void CMP_FLTINSEL_Select (uint32_t Select)
{
    CHECK_RESTRICTION(CHECK_CMP_FLTINSEL(Select));

    /*-------------------- ����CMP_CTL4�Ĵ���FLTINSELλ --------------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4,
                          ~CMP_CTL4_FLTINSEL,
                          Select);
}

/**
  * ����  TRGMUX���ͨ��ѡ��λ
  * ���� CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 	Select: ȡֵ��ΧΪ��
  * 			CMP_WIN_CONTROL_TRGMUX_CH1: ѡ�� TRGMUXͨ��1�����CH1_TROUT��ΪCMP�� window control�ź�
  * 			CMP_WIN_CONTROL_TRGMUX_CH2: ѡ�� TRGMUXͨ��2�����CH2_TROUT��ΪCMP�� window control�ź�
  * 			CMP_WIN_CONTROL_TRGMUX_CH3: ѡ�� TRGMUXͨ��3�����CH3_TROUT��ΪCMP�� window control�ź�
  * 			CMP_WIN_CONTROL_TRGMUX_CH4: ѡ�� TRGMUXͨ��4�����CH4_TROUT��ΪCMP�� window control�ź�
  * ����  ��
  */
void CMP_Win_Control_TRGMUX_CH_Select (uint32_t CMPx_ADDR, uint32_t Select)
{
	 /* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_CMP_WIN_CONTRAL_TRGMUX_CH(Select));
	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_CTL5 = SFR_Config(CMP_CTL5, ~CMP_CTL5_C0TRGSEL, Select << CMP_CTL5_C0TRGSEL0_POS);
		break;
	case CMP1_ADDR:
		CMP_CTL5 = SFR_Config(CMP_CTL5, ~CMP_CTL5_C1TRGSEL, Select << CMP_CTL5_C1TRGSEL0_POS);
		break;
	case CMP2_ADDR:
		CMP_CTL5 = SFR_Config(CMP_CTL5, ~CMP_CTL5_C2TRGSEL, Select << CMP_CTL5_C2TRGSEL0_POS);
		break;
	case CMP3_ADDR:
		CMP_CTL5 = SFR_Config(CMP_CTL5, ~CMP_CTL5_C3TRGSEL, Select << CMP_CTL5_C3TRGSEL0_POS);
		break;
	default:break;
	}
}

/**
  * ���� CMP0/1/2/3�͹���ʹ��
  * ���� NewState:
  * 			TRUE:CMP����ʱʹ�ܵ͹���ģʽ
  * 			FALSE:CMP����ʱδʹ�ܵ͹���ģʽ
  * ����  ��
  */
void CMP_LP_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CMP_CTL5 = SFR_Config(CMP_CTL5, ~CMP_CTL5_CMPLPEN, NewState << CMP_CTL5_CMPLPEN_POS);
}

/**
  * ���� CMP0/1/2/3У׼ PMOS����ʹ��λ
  * ���� NewState:
  * 			TRUE:CMP0/1/2/3 У׼ PMOS ����ʹ��λʹ��
  * 			FALSE:CMP0/1/2/3 У׼ PMOS ����ʹ��λδʹ��
  * ����  ��
  */
void CMP_TRIM_PMOS_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CMP_TRIM0 = SFR_Config(CMP_TRIM0, ~CMP_TRIM0_CMPTRIMLOWEN, NewState << CMP_TRIM0_CMPTRIMLOWEN_POS);
}

/**
  * ���� CMP0/1/2/3У׼ NMOS����ʹ��λ
  * ���� NewState:
  * 			TRUE:CMP0/1/2/3 У׼ NMOS ����ʹ��λʹ��
  * 			FALSE:CMP0/1/2/3 У׼ NMOS ����ʹ��λδʹ��
  * ����  ��
  */
void CMP_TRIM_NMOS_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CMP_TRIM0 = SFR_Config(CMP_TRIM0, ~CMP_TRIM0_CMPTRIMHIEN, NewState << CMP_TRIM0_CMPTRIMHIEN_POS);
}

/**
  * ���� CMP0/1/2/3 PMOS��ʧ��У׼λ
  * ����  CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 	 Value: Value <= 0x3F
  * ����  ��
  */
void CMP_TRIM_PMOS_Cail(uint32_t CMPx_ADDR, uint8_t Value)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_CMP_TRIM_VALUE(Value));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_TRIM0 = SFR_Config(CMP_TRIM0, ~CMP_TRIM0_C0TRIMP, Value << CMP_TRIM0_C0TRIMP0_POS);
		break;
	case CMP1_ADDR:
		CMP_TRIM1 = SFR_Config(CMP_TRIM1, ~CMP_TRIM0_C0TRIMP, Value << CMP_TRIM0_C0TRIMP0_POS);
		break;
	case CMP2_ADDR:
		CMP_TRIM2 = SFR_Config(CMP_TRIM2, ~CMP_TRIM0_C0TRIMP, Value << CMP_TRIM0_C0TRIMP0_POS);
		break;
	case CMP3_ADDR:
		CMP_TRIM3 = SFR_Config(CMP_TRIM3, ~CMP_TRIM0_C0TRIMP, Value << CMP_TRIM0_C0TRIMP0_POS);
		break;
	default:break;
	}
}

/**
  * ���� CMP0/1/2/3 PMOS��ʧ��У׼����ѡ��
  * ���� 	CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 		Direction:
  * 			CMP_TRIM_DIRECTION_NEGETIVE: ����У׼
  * 			CMP_TRIM_DIRECTION_POSITIVE: ����У׼
  * ����  ��
  */
void CMP_TRIM_PMOS_Direction_Select(uint32_t CMPx_ADDR, uint32_t Direction)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_TRIM_DIRECTION(Direction));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_TRIM0 = SFR_Config(CMP_TRIM0, ~CMP_TRIM0_C0TRIMPPOL, Direction << CMP_TRIM0_C0TRIMPPOL_POS);
		break;
	case CMP1_ADDR:
		CMP_TRIM1 = SFR_Config(CMP_TRIM1, ~CMP_TRIM0_C0TRIMPPOL, Direction << CMP_TRIM0_C0TRIMPPOL_POS);
		break;
	case CMP2_ADDR:
		CMP_TRIM2 = SFR_Config(CMP_TRIM2, ~CMP_TRIM0_C0TRIMPPOL, Direction << CMP_TRIM0_C0TRIMPPOL_POS);
		break;
	case CMP3_ADDR:
		CMP_TRIM3 = SFR_Config(CMP_TRIM3, ~CMP_TRIM0_C0TRIMPPOL, Direction << CMP_TRIM0_C0TRIMPPOL_POS);
		break;
	default:break;
	}
}

/**
  * ���� CMP0/1/2/3 NMOS��ʧ��У׼λ
  * ���� CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 	Value: Value <= 0x3F
  * ����  ��
  */
void CMP_TRIM_NMOS_Cail(uint32_t CMPx_ADDR, uint8_t Value)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_CMP_TRIM_VALUE(Value));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_TRIM0 = SFR_Config(CMP_TRIM0, ~CMP_TRIM0_C0TRIMN, Value << CMP_TRIM0_C0TRIMN0_POS);
		break;
	case CMP1_ADDR:
		CMP_TRIM1 = SFR_Config(CMP_TRIM1, ~CMP_TRIM0_C0TRIMN, Value << CMP_TRIM0_C0TRIMN0_POS);
		break;
	case CMP2_ADDR:
		CMP_TRIM2 = SFR_Config(CMP_TRIM2, ~CMP_TRIM0_C0TRIMN, Value << CMP_TRIM0_C0TRIMN0_POS);
		break;
	case CMP3_ADDR:
		CMP_TRIM3 = SFR_Config(CMP_TRIM3, ~CMP_TRIM0_C0TRIMN, Value << CMP_TRIM0_C0TRIMN0_POS);
		break;
	default:break;
	}
}

/**
  * ���� CMP0/1/2/3 NMOS��ʧ��У׼����ѡ��
  * ���� CMPx_ADDR: ȡֵΪCMP0_ADDR��CMP1_ADDR��CMP2_ADDR��CMP3_ADDR��
  * 	Direction:
  * 			CMP_TRIM_DIRECTION_NEGETIVE: ����У׼
  * 			CMP_TRIM_DIRECTION_POSITIVE: ����У׼
  * ����  ��
  */
void CMP_TRIM_NMOS_Direction_Select(uint32_t CMPx_ADDR, uint32_t Direction)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_TRIM_DIRECTION(Direction));

	switch (CMPx_ADDR)
	{
	case CMP0_ADDR:
		CMP_TRIM0 = SFR_Config(CMP_TRIM0, ~CMP_TRIM0_C0TRIMNPOL, Direction << CMP_TRIM0_C0TRIMNPOL_POS);
		break;
	case CMP1_ADDR:
		CMP_TRIM1 = SFR_Config(CMP_TRIM1, ~CMP_TRIM0_C0TRIMNPOL, Direction << CMP_TRIM0_C0TRIMNPOL_POS);
		break;
	case CMP2_ADDR:
		CMP_TRIM2 = SFR_Config(CMP_TRIM2, ~CMP_TRIM0_C0TRIMNPOL, Direction << CMP_TRIM0_C0TRIMNPOL_POS);
		break;
	case CMP3_ADDR:
		CMP_TRIM3 = SFR_Config(CMP_TRIM3, ~CMP_TRIM0_C0TRIMNPOL, Direction << CMP_TRIM0_C0TRIMNPOL_POS);
		break;
	default:break;
	}
}












