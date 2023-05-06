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


/* CMP私有定义 ----------------------------------------------------*/
/* CMP_CTL0寄存器配置掩码 */
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
/* CMP_CTL1寄存器配置掩码 */
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
/* CMP_CTL2寄存器配置掩码 */
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
/* CMP_CTL3寄存器配置掩码 */
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
  *   ##### 初始化及配置函数 #####
  */
/**
  * 描述  CMP外设复位，使能外设时钟。
  * 输入  CMPx: 无
  * 返回  无。
  */
void CMP_Reset (void)
{
	RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_CMPRST, TRUE);
	RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_CMPRST, FALSE);
	PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_CMPCLKEN, TRUE);
}

/**
  * 描述  CMP外设配置。
  * 输入  CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  *       CMPInitStruct: CMP配置信息
  * 返回  无。
  */
void CMP_Configuration (uint32_t CMPx_ADDR, CMP_InitTypeDef* CMPInitStruct)
{
    uint32_t tmpreg;

    /* 参数校验 */
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
        /*---------------------------- CMP_CTL0寄存器配置  -----------------*/
        /* 根据结构体成员m_PositiveInput，设置PMOD0位域 */
        /* 根据结构体成员m_NegativeInput，设置NMOD0位域 */
        /* 根据结构体成员m_FallTriggerEnable，设置IFFEN位域 */
        /* 根据结构体成员m_RiseTriggerEnable，设置IFREN位域 */
        /* 根据结构体成员m_Clock，设置FLTCS位域 */
		/* 根据结构体成员m_FrequencyDivision，设置FLTDIV位域 */
        /* 根据结构体成员m_SampleNumber，设置FLTCNT位域 */
        /* 根据结构体成员m_FilterEnable，设置FLTEN位域 */
        /* 根据结构体成员m_ScopecontrolEnable，设置WINEN位域 */
        /* 根据结构体成员m_OutputPolarity，设置POL位域 */

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
	        /* 使能CMP */
	        SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C0EN_POS);
	    }
	    else
	    {
	        /* 禁止CMP */
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
        /*---------------------------- CMP_CTL0寄存器配置  -----------------*/
        /* 根据结构体成员m_PositiveInput，设置PMOD0位域 */
        /* 根据结构体成员m_NegativeInput，设置NMOD0位域 */
        /* 根据结构体成员m_FallTriggerEnable，设置IFFEN位域 */
        /* 根据结构体成员m_RiseTriggerEnable，设置IFREN位域 */
        /* 根据结构体成员m_Clock，设置FLTCS位域 */
		/* 根据结构体成员m_FrequencyDivision，设置FLTDIV位域 */
        /* 根据结构体成员m_SampleNumber，设置FLTCNT位域 */
        /* 根据结构体成员m_FilterEnable，设置FLTEN位域 */
        /* 根据结构体成员m_ScopecontrolEnable，设置WINEN位域 */
        /* 根据结构体成员m_OutputPolarity，设置POL位域 */

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
	        /* 使能CMP */
	        SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C1EN_POS);
	    }
	    else
	    {
	        /* 禁止CMP */
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
        /*---------------------------- CMP_CTL0寄存器配置  -----------------*/
        /* 根据结构体成员m_PositiveInput，设置PMOD0位域 */
        /* 根据结构体成员m_NegativeInput，设置NMOD0位域 */
        /* 根据结构体成员m_FallTriggerEnable，设置IFFEN位域 */
        /* 根据结构体成员m_RiseTriggerEnable，设置IFREN位域 */
        /* 根据结构体成员m_Clock，设置FLTCS位域 */
		/* 根据结构体成员m_FrequencyDivision，设置FLTDIV位域 */
        /* 根据结构体成员m_SampleNumber，设置FLTCNT位域 */
        /* 根据结构体成员m_FilterEnable，设置FLTEN位域 */
        /* 根据结构体成员m_ScopecontrolEnable，设置WINEN位域 */
        /* 根据结构体成员m_OutputPolarity，设置POL位域 */

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
	        /* 使能CMP */
	        SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_C2EN_POS);
	    }
	    else
	    {
	        /* 禁止CMP */
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
		/*---------------------------- CMP_CTL3寄存器配置  -----------------*/
		/* 根据结构体成员m_PositiveInput，设置PMOD0位域 */
		/* 根据结构体成员m_NegativeInput，设置NMOD0位域 */
        /* 根据结构体成员m_FallTriggerEnable，设置IFFEN位域 */
        /* 根据结构体成员m_RiseTriggerEnable，设置IFREN位域 */
		/* 根据结构体成员m_Clock，设置FLTCS位域 */
		/* 根据结构体成员m_FrequencyDivision，设置FLTDIV位域 */
		/* 根据结构体成员m_SampleNumber，设置FLTCNT位域 */
		/* 根据结构体成员m_FilterEnable，设置FLTEN位域 */
		/* 根据结构体成员m_ScopecontrolEnable，设置WINEN位域 */
		/* 根据结构体成员m_OutputPolarity，设置POL位域 */

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
    CMP_CTL4 |= (uint32_t)1 << 10;  //CMP的IO输出使能
}

/**
  * 描述  初始化CMP配置信息结构体。
  * 输入  CMPInitStruct: 指向待初始化的结构体指针。
  * 返回  无。
  */
void CMP_Struct_Init (CMP_InitTypeDef* CMPInitStruct)
{
    /* 初始化 CMP的正端输入选择位 */
    CMPInitStruct->m_PositiveInput = CMP0_PositiveINPUT_PIN_PA0;
    /* 初始化 CMP的负端输入选择位 */
    CMPInitStruct->m_NegativeInput = CMP0_NegativeINPUT_PIN_PA1;
    /* 初始化 CMP下降沿触发中断使能 */
    CMPInitStruct->m_FallTriggerEnable = FALSE;
    /* 初始化 CMP上升沿触发中断使能 */
    CMPInitStruct->m_RiseTriggerEnable = FALSE;
    /* 初始化CMP滤波器滤波时钟源 */
    CMPInitStruct->m_Clock = CMPx_CLKSOURCE_SCLK;
    /* 初始化CMP滤波器滤波时钟分频*/
    CMPInitStruct->m_FrequencyDivision = 0x00;//1分频（值范围0-255）
    /* 初始化 CMP取样数量选择 */
    CMPInitStruct->m_SampleNumber = CMPx_FLT_OFF;
    /* 初始化CMP滤波器使能位 */
    CMPInitStruct->m_FilterEnable = FALSE;
    /* 初始化CMP范围控制使能位*/
    CMPInitStruct->m_ScopecontrolEnable = FALSE;
    /* 初始化 CMP输出极性选择*/
    CMPInitStruct->m_OutputPolarity =CMPx_OUTPUT_Normal;
    /* 初始化CMP比较器使能 */
    CMPInitStruct->m_CmpEnable =FALSE;
}

/**
  * 描述  CMP的IO通道使能。
  * 输入  NewState: 取值范围为：TRUE 或 FALSE。
  * 返回  无。
  * 注：置1后，PMOD<3:0>和 NMOD<3:0>才有效
  */
void CMP_IO_Channel_Enable(FunctionalState NewState)
{
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CMP_CTL4 |= (uint32_t)NewState << CMP_CTL4_IOEN_POS;
}

/**
  * 描述  CMP0正端输入端口信号选择。
  * 输入选择:
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
  * 返回  无。
  */
void CMP0_POSITIVE_INPUT_SELECT (uint32_t Select)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP0_PositiveINPUT_PIN(Select));
    /*------------- 设置CMP_CTL0寄存器PMOD位 -------------*/
    CMP_CTL0 = SFR_Config (CMP_CTL0,
                               ~CMP_CTL0_PMOD,
                               Select);
}

/**
  * 描述  CMP0负端输入端口信号选择。
  * 输入选择:
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
  * 返回  无。
  */
void CMP0_NEGATIVE_INPUT_SELECT (uint32_t Select)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP0_NegativeINPUT_PIN(Select));
    /*------------- 设置CMP_CTL0寄存器NMOD位 -------------*/
    CMP_CTL0 = SFR_Config (CMP_CTL0,
                               ~CMP_CTL0_NMOD,
                               Select);
}

/**
  * 描述  CMP1正端输入端口信号选择。
  * 输入选择:
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
  * 返回  无。
  */
void CMP1_POSITIVE_INPUT_SELECT (uint32_t Select)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP1_PositiveINPUT_PIN(Select));
    /*------------- 设置CMP_CTL1寄存器PMOD位 -------------*/
    CMP_CTL1 = SFR_Config (CMP_CTL1,
                               ~CMP_CTL1_PMOD,
                               Select);
}

/**
  * 描述  CMP1负端输入端口信号选择。
  * 输入选择:
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
  * 返回  无。
  */
void CMP1_NEGATIVE_INPUT_SELECT (uint32_t Select)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP1_NegativeINPUT_PIN(Select));
    /*------------- 设置CMP_CTL1寄存器NMOD位 -------------*/
    CMP_CTL1 = SFR_Config (CMP_CTL1,
                               ~CMP_CTL1_NMOD,
                               Select);
}

/**
  * 描述  CMP2正端输入端口信号选择。
  * 输入选择:
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
  * 返回  无。
  */
void CMP2_POSITIVE_INPUT_SELECT (uint32_t Select)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP2_PositiveINPUT_PIN(Select));
    /*------------- 设置CMP_CTL2寄存器PMOD位 -------------*/
    CMP_CTL2 = SFR_Config (CMP_CTL2,
                               ~CMP_CTL2_PMOD,
                               Select);
}

/**
  * 描述  CMP2负端输入端口信号选择。
  * 输入选择:
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
  * 返回  无。
  */
void CMP2_NEGATIVE_INPUT_SELECT (uint32_t Select)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP2_NegativeINPUT_PIN(Select));
    /*------------- 设置CMP_CTL2寄存器NMOD位 -------------*/
    CMP_CTL2 = SFR_Config (CMP_CTL2,
                               ~CMP_CTL2_NMOD,
                               Select);
}

/**
  * 描述  CMP3正端输入端口信号选择。
  * 输入选择:
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
  * 返回  无。
  */
void CMP3_POSITIVE_INPUT_SELECT (uint32_t Select)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP3_PositiveINPUT_PIN(Select));

    /*------------- 设置CMP_CTL3寄存器PMOD位 -------------*/
    CMP_CTL3 = SFR_Config (CMP_CTL3,
                               ~CMP_CTL3_PMOD,
                               Select);
}

/**
  * 描述  CMP3负端输入端口信号选择。
  * 输入选择:
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
  * 返回  无。
  */
void CMP3_NEGATIVE_INPUT_SELECT (uint32_t Select)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP3_NegativeINPUT_PIN(Select));
    /*------------- 设置CMP_CTL3寄存器NMOD位 -------------*/
    CMP_CTL3 = SFR_Config (CMP_CTL3,
                               ~CMP_CTL3_NMOD,
                               Select);
}

/**
  * 描述  CMPx输出极性选择。
  * 输入 	CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 		Polarity:
  * 			CMPx_OUTPUT_Normal: 负向校准
  * 			CMPx_OUTPUT_Opposite: 正向校准
  */
void CMP_OUTPUT_POL_SELECT(uint32_t CMPx_ADDR, uint32_t Polarity)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_CMP_ALL_PERIPH(CMPx_ADDR));
	CHECK_RESTRICTION(CHECK_CMPx_OUTPUT_POLARITY(Polarity));
	 /*------------- 设置CMP_CTLx寄存器POL位 -------------*/
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
  * 描述  CMP输出到IO口选择。
  * 输入选择:
  * 		  NONE
  *           CMP0_OUTPUT
  *           CMP1_OUTPUT
  *           CMP2_OUTPUT
  * 返回  无。
  */
void CMP_OUTPUT_SELECT (uint32_t Select)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP_OUTPUT(Select));
    /*------------- 设置CMP_CTL2寄存器POL位 -------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4,
                               ~CMP_CTL4_CMPOUTASEL,
                               Select);
}

/**
  * 描述  控制CMP0使能位。
  * 输入 	CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 		NewState: 取值为 TRUE 或 FALSE。
  * 返回  无。
  */
void CMP_Cmd(uint32_t CMPx_ADDR, uint32_t NewState)
{
	/* 参数校验 */
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
  * 描述 CMP0/1/2/3 window control时钟选择
  * 输入 CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 	Select:
  * 			CMP_WIN_CONTROL_SYS_CLK: 选择系统时钟
  * 			CMP_WIN_CONTROL_TRGMUX_CLK:  选择 TRGMUX 的输出信号
  * 返回  无
  */
void CMP_WIN_Control_CLK_Select(uint32_t CMPx_ADDR, uint32_t Select)
{
	/* 参数校验 */
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
  * 描述 CMP0/1/2/3 滤波时钟选择
  * 输入 CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 	Select:
  * 			CMPx_CLKSOURCE_SCLK:  滤波时钟源为SCLK系统时钟
  * 			CMPx_CLKSOURCE_HFCLK: 滤波时钟源为 HFCLK 高频外设时钟
  * 			CMPx_CLKSOURCE_LFCLK: 滤波时钟源为 LFCLK 低频外设时钟
  * 返回  无
  */
void CMP_Filter_CLKSource_Select(uint32_t CMPx_ADDR, uint32_t Select)
{
	/* 参数校验 */
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
  * 描述 CMP0/1/2/3 滤波器取样数量选择
  * 输入 CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 	Select:
  * 			CMPx_FLT_OFF:  滤波器不采样，滤波功能被禁止
  * 			CMPx_FLT_SampleNumber_1: 滤除脉宽小于1个FILT_CLK周期的输入噪声比较器输出延时 0~1 个 FILT_CLK周期时间
  * 			CMPx_FLT_SampleNumber_2: 滤除脉宽小于2个FILT_CLK周期的输入噪声比较器输出延时 1~2 个 FILT_CLK周期时间
  * 			CMPx_FLT_SampleNumber_3: 滤除脉宽小于3个FILT_CLK周期的输入噪声比较器输出延时 2~3 个 FILT_CLK周期时间
  * 			CMPx_FLT_SampleNumber_4: 滤除脉宽小于4个FILT_CLK周期的输入噪声比较器输出延时 3~4 个 FILT_CLK周期时间
  * 			CMPx_FLT_SampleNumber_5: 滤除脉宽小于5个FILT_CLK周期的输入噪声比较器输出延时 4~5 个 FILT_CLK周期时间
  * 			CMPx_FLT_SampleNumber_6: 滤除脉宽小于6个FILT_CLK周期的输入噪声比较器输出延时 5~6 个 FILT_CLK周期时间
  * 			CMPx_FLT_SampleNumber_7: 滤除脉宽小于7个FILT_CLK周期的输入噪声比较器输出延时 6~7 个 FILT_CLK周期时间
  * 返回  无
  */
void CMP_Filter_SampleNumber_Select(uint32_t CMPx_ADDR, uint32_t Select)
{
	/* 参数校验 */
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
  *   ##### 初始化及配置函数结束 #####
  */

/**
  * 描述  配置CMPx上升沿/下降沿中断使能。
  * 输入 	CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 		UDEdge ： CMPx_UD_EDGE_INT： 比较器 x上升沿触发中断
  * 				 CMPx_DOWN_EDGE_INT: 比较器 x下降沿触发中断
  * 		NewState : TRUE/FALSE
  * 返回  CMPx输出状态。
  */
void CMP_Up_Down_Edge_INT_Enable(uint32_t CMPx_ADDR, uint32_t UDEdge, uint32_t NewState)
{
	/* 参数校验 */
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
  * 描述  获取CMPx的输出状态。
  * 输入 	CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 返回  CMPx输出状态。
  */
FlagStatus CMP_Get_Output_State(uint32_t CMPx_ADDR)
{
	/* 参数校验 */
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
  * 描述  获取CMPx中断标志状态。
  * 输入 	CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 返回  CMPx中断标志状态。
  */
FlagStatus CMP_Get_INT_Flag(uint32_t CMPx_ADDR)
{
	/* 参数校验 */
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
  * 描述  配置触发选择位。
  * 输入 TriSelect: 触发选择，
  *                     CMP_CMPOUT_FlipLatch_INT :通过比较器输出与锁存状态比较触发中断标志
  *                     CMP_CMPOUT_Change_INT :通过检测比较器输出变化沿触发中断标志
  * 返回  无
  */
void CMP_Trigger_Select_Config (uint32_t TriSelect)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CMP_TriggerINT_MODE(TriSelect));

    /*-------------------- 设置CMP_CTL4寄存器CIFMS位 --------------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4, ~CMP_CTL4_CIFMS, TriSelect);
}

/**
  * 描述  清除CMPx中断标志。
  * 输入 	CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 返回  :是否成功清除状态。
  */
RetStatus CMP_Clear_INT_Flag(uint32_t CMPx_ADDR)
{
	uint32_t wait_flag = 0x0000;
	/* 参数校验 */
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
  * 描述  配置CMPx中断使能。
  * 输入 	CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 		NewState: 取值为 TRUE 或 FALSE。
  * 返回  无。
  */
void CMP_INT_Enable(uint32_t CMPx_ADDR, uint32_t NewState)
{
	/* 参数校验 */
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
  * 描述  配置CMP迟滞电压选择位
  * 输入 Select: 取值范围为：
  * CMP_SluggishVoltage_OFF
  * CMP_SluggishVoltage_7p5mV
  * CMP_SluggishVoltage_12mV
  * CMP_SluggishVoltage_30mV
  * 返回  无
  */
void CMP_SluggishVoltage_Select (uint32_t Select)
{
    CHECK_RESTRICTION(CHECK_CMP_SluggishVoltage_SEL(Select));

    /*-------------------- 设置CMP_CTL4寄存器TRIM位 --------------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4,
                          ~CMP_CTL4_DELAYVOL,
                          Select);
}

/**
  * 描述  霍尔模式选择位
  * 输入 Select: 取值范围为：
  * CMP_HALLMODE_SINGLE
  * CMP_HALLMODE_BOTH
  * 返回  无
  */
void CMP_HALLMODE_Select (uint32_t Select)
{
    CHECK_RESTRICTION(CHECK_CMP_HALLMODE_SEL(Select));

    /*-------------------- 设置CMP_CTL4寄存器TRIM位 --------------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4,
                          ~CMP_CTL4_HALSEL,
                          Select);
}

/**
  * 描述  反向电动势模式使能
  * 输入 NewState: 中断取值范围为：TRUE 或 FALSE
  * 返回  无
  */
void CMP_BEMF_Enable (FunctionalState NewState)
{
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- 设置CMP_CTL4寄存器BEMFEN位 --------------------*/
    if (NewState != FALSE)
    {
        /* 允许反向电动势模式使能 */
        SFR_SET_BIT_ASM(CMP_CTL4, CMP_CTL4_BEMFEN_POS);
    }
    else
    {
        /* 禁止反向电动势模式使能 */
        SFR_CLR_BIT_ASM(CMP_CTL4, CMP_CTL4_BEMFEN_POS);
    }
}

/**
  * 描述  滤波器输入选择位
  * 输入 Select: 取值范围为：
  * CMP_FLTINSEL_CMPOUT
  * CMP_FLTINSEL_IO
  * 返回  无
  */
void CMP_FLTINSEL_Select (uint32_t Select)
{
    CHECK_RESTRICTION(CHECK_CMP_FLTINSEL(Select));

    /*-------------------- 设置CMP_CTL4寄存器FLTINSEL位 --------------------*/
    CMP_CTL4 = SFR_Config (CMP_CTL4,
                          ~CMP_CTL4_FLTINSEL,
                          Select);
}

/**
  * 描述  TRGMUX输出通道选择位
  * 输入 CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 	Select: 取值范围为：
  * 			CMP_WIN_CONTROL_TRGMUX_CH1: 选择 TRGMUX通道1的输出CH1_TROUT作为CMP的 window control信号
  * 			CMP_WIN_CONTROL_TRGMUX_CH2: 选择 TRGMUX通道2的输出CH2_TROUT作为CMP的 window control信号
  * 			CMP_WIN_CONTROL_TRGMUX_CH3: 选择 TRGMUX通道3的输出CH3_TROUT作为CMP的 window control信号
  * 			CMP_WIN_CONTROL_TRGMUX_CH4: 选择 TRGMUX通道4的输出CH4_TROUT作为CMP的 window control信号
  * 返回  无
  */
void CMP_Win_Control_TRGMUX_CH_Select (uint32_t CMPx_ADDR, uint32_t Select)
{
	 /* 参数校验 */
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
  * 描述 CMP0/1/2/3低功耗使能
  * 输入 NewState:
  * 			TRUE:CMP工作时使能低功耗模式
  * 			FALSE:CMP工作时未使能低功耗模式
  * 返回  无
  */
void CMP_LP_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CMP_CTL5 = SFR_Config(CMP_CTL5, ~CMP_CTL5_CMPLPEN, NewState << CMP_CTL5_CMPLPEN_POS);
}

/**
  * 描述 CMP0/1/2/3校准 PMOS管总使能位
  * 输入 NewState:
  * 			TRUE:CMP0/1/2/3 校准 PMOS 管总使能位使能
  * 			FALSE:CMP0/1/2/3 校准 PMOS 管总使能位未使能
  * 返回  无
  */
void CMP_TRIM_PMOS_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CMP_TRIM0 = SFR_Config(CMP_TRIM0, ~CMP_TRIM0_CMPTRIMLOWEN, NewState << CMP_TRIM0_CMPTRIMLOWEN_POS);
}

/**
  * 描述 CMP0/1/2/3校准 NMOS管总使能位
  * 输入 NewState:
  * 			TRUE:CMP0/1/2/3 校准 NMOS 管总使能位使能
  * 			FALSE:CMP0/1/2/3 校准 NMOS 管总使能位未使能
  * 返回  无
  */
void CMP_TRIM_NMOS_Enable(FunctionalState NewState)
{
	/* 参数校验 */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	CMP_TRIM0 = SFR_Config(CMP_TRIM0, ~CMP_TRIM0_CMPTRIMHIEN, NewState << CMP_TRIM0_CMPTRIMHIEN_POS);
}

/**
  * 描述 CMP0/1/2/3 PMOS管失调校准位
  * 输入  CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 	 Value: Value <= 0x3F
  * 返回  无
  */
void CMP_TRIM_PMOS_Cail(uint32_t CMPx_ADDR, uint8_t Value)
{
	/* 参数校验 */
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
  * 描述 CMP0/1/2/3 PMOS管失调校准方向选择
  * 输入 	CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 		Direction:
  * 			CMP_TRIM_DIRECTION_NEGETIVE: 负向校准
  * 			CMP_TRIM_DIRECTION_POSITIVE: 正向校准
  * 返回  无
  */
void CMP_TRIM_PMOS_Direction_Select(uint32_t CMPx_ADDR, uint32_t Direction)
{
	/* 参数校验 */
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
  * 描述 CMP0/1/2/3 NMOS管失调校准位
  * 输入 CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 	Value: Value <= 0x3F
  * 返回  无
  */
void CMP_TRIM_NMOS_Cail(uint32_t CMPx_ADDR, uint8_t Value)
{
	/* 参数校验 */
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
  * 描述 CMP0/1/2/3 NMOS管失调校准方向选择
  * 输入 CMPx_ADDR: 取值为CMP0_ADDR、CMP1_ADDR、CMP2_ADDR、CMP3_ADDR。
  * 	Direction:
  * 			CMP_TRIM_DIRECTION_NEGETIVE: 负向校准
  * 			CMP_TRIM_DIRECTION_POSITIVE: 正向校准
  * 返回  无
  */
void CMP_TRIM_NMOS_Direction_Select(uint32_t CMPx_ADDR, uint32_t Direction)
{
	/* 参数校验 */
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












