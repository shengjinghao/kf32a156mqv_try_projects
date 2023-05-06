/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_btim.c                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides timer peripherals function,		  *
 *  					including:											  *
 *          			+ Definition of timer peripheral reset function       *
 *          			+ Basic Timer (BTIM) initialization and configuration *
 *          			  function definition								  *
 *          			+ Basic Timer (BTIM) interrupt and flag management 	  *
 *          			  function definition								  *
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
#include "kf32a1x6_btim.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/*******************************************************************************
**                         Timer private definition                           **
*******************************************************************************/

/* BTIMx_CTL1�Ĵ����������� */
#define BTIM_CTL1_INIT_MASK  (BTIM_CTL1_TXCLK | \
                              BTIM_CTL1_TXCMS | \
                              BTIM_CTL1_TXSY | \
                              BTIM_CTL1_TXCS)

/* BTIMx_CTL2�Ĵ����������� */
#define BTIM_CTL2_INIT_MASK  (BTIM_CTL2_TXMMS | \
                              BTIM_CTL2_TXSMS | \
                              BTIM_CTL2_TXMSSYNC)


/**
  *   ##### ��ʱ�����踴λ�������� #####
  */
/**
  * ����  ��ʱ�����踴λ��ʹ������ʱ�ӡ�
  * ����  TIMx: ��ʱ���ڴ�ṹָ�룬ȡֵΪ T0_SFR/T1_SFR/T2_SFR/T3_SFR/T4_SFR/
  *           T5_SFR/T6_SFR/T14_SFR/T18_SFR/T19_SFR/T21_SFR��
  * ����  ��
  */
void TIM_Reset (void* TIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_TIM_ALL_PERIPH((uint32_t)TIMx));

    if ((uint32_t)TIMx == T0_ADDR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T0RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T0RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_T0CLKEN, TRUE);
    }
    else if ((uint32_t)TIMx == T1_ADDR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T1RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T1RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_T1CLKEN, TRUE);
    }
    else if ((uint32_t)TIMx == T2_ADDR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T2RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T2RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_T2CLKEN, TRUE);
    }
    else if ((uint32_t)TIMx == T3_ADDR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T3RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T3RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_T3CLKEN, TRUE);
    }
    else if ((uint32_t)TIMx == T4_ADDR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T4RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T4RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_T4CLKEN, TRUE);
    }
    else if ((uint32_t)TIMx == T5_ADDR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T5T6RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T5T6RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_T5T6CLKEN, TRUE);
    }
    else if ((uint32_t)TIMx == T6_ADDR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T5T6RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_T5T6RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_T5T6CLKEN, TRUE);
    }
    else if ((uint32_t)TIMx == T14_ADDR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T14RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T14RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_T14CLKEN, TRUE);
    }

    else if ((uint32_t)TIMx == T18_ADDR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T18RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T18RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_T18CLKEN, TRUE);
    }
    else if ((uint32_t)TIMx == T19_ADDR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T19RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T19RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_T19CLKEN, TRUE);
    }
    else if ((uint32_t)TIMx == T21_ADDR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T21RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T21RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_T21CLKEN, TRUE);
    }
    else
    {
        ;
    }
}
/**
  * ����  ��ʱ�����踴λ��ʹ������ʱ�ӡ�
  * ����  TIMx: ��ʱ���ڴ�ṹָ�룬ȡֵΪ T14_SFR��
  * ����  ��
  */
void BTIM_Reset (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    if (BTIMx == T14_SFR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T14RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_T14RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_T14CLKEN, TRUE);
    }
    else
    {
        ;
    }
}

/**
  *   ##### ��ʱ�����踴λ����������� #####
  */

/**
  *   ##### ������ʱ��(BTIM)��ʼ�������ú������� #####
  */

/**
  * ����  ������ʱ��(BTIM)���á�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       btimInitStruct: ������ʱ��������Ϣ�ṹ��ָ�롣
  * ����  ��
  */

/**
  * ����  ������ʱ��(BTIM)���á�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       btimInitStruct: ������ʱ��������Ϣ�ṹ��ָ�롣
  * ����  ��
  */
void BTIM_Configuration (BTIM_SFRmap* BTIMx,BTIM_InitTypeDef* btimInitStruct)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_BTIM_COUNTER_MODE(btimInitStruct->m_CounterMode));
    CHECK_RESTRICTION(CHECK_BTIM_CLOCK_CONFIG(btimInitStruct->m_Clock));
    CHECK_RESTRICTION(CHECK_BTIM_WORK_MODE(btimInitStruct->m_WorkMode));
    CHECK_RESTRICTION(CHECK_BTIM_MASTER_MODE(btimInitStruct->m_MasterMode));
    CHECK_RESTRICTION(CHECK_BTIM_SLAVE_MODE(btimInitStruct->m_SlaveMode));
    CHECK_RESTRICTION(CHECK_BTIM_SYNC_MODE(btimInitStruct->m_EXPulseSync));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(btimInitStruct->m_MasterSlaveSync));

    /*-------------------- ����TxCNT�Ĵ��� --------------------*/
    BTIMx->CNT = (uint32_t)btimInitStruct->m_Counter;

    /*-------------------- ����PPx���ڼĴ��� --------------------*/
    BTIMx->PPX = (uint32_t)btimInitStruct->m_Period;

    /*-------------------- ����TxԤ��Ƶ�Ĵ��� --------------------*/
    BTIMx->PRSC = (uint32_t)btimInitStruct->m_Prescaler;

    /*-------------------- ����TXCTL1�Ĵ��� --------------------*/
    /* ���ݽṹ���Աm_CounterMode������TXCMSλ�� */
    /* ���ݽṹ���Աm_Clock������TXCLKλ�� */
    /* ���ݽṹ���Աm_WorkMode������TXCSλ�� */
    /* ���ݽṹ���Աm_EXPulseSync������TXSYλ�� */
    tmpreg = ((uint32_t)btimInitStruct->m_CounterMode) | \
             ((uint32_t)btimInitStruct->m_Clock) | \
             ((uint32_t)btimInitStruct->m_WorkMode) | \
             ((uint32_t)btimInitStruct->m_EXPulseSync);
    BTIMx->CTL1 = SFR_Config (BTIMx->CTL1,
                          ~BTIM_CTL1_INIT_MASK,
                          tmpreg);

    /*-------------------- ����TXCTL2�Ĵ��� --------------------*/
    /* ���ݽṹ���Աm_MasterMode������TXMMSλ�� */
    /* ���ݽṹ���Աm_SlaveMode������TXSMSλ�� */
    /* ���ݽṹ���Աm_MasterSlaveSync������TXMSSYNCλ�� */
    tmpreg = ((uint32_t)btimInitStruct->m_MasterMode) | \
             ((uint32_t)btimInitStruct->m_SlaveMode) | \
             ((uint32_t)btimInitStruct->m_MasterSlaveSync << BTIM_CTL2_TXMSSYNC_POS);
    BTIMx->CTL2 = SFR_Config (BTIMx->CTL2,
                          ~BTIM_CTL2_INIT_MASK,
                          tmpreg);
}

/**
  * ����  ��ʼ��������ʱ��������Ϣ�ṹ�塣
  * ����  btimInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  ��
  */
void BTIM_Struct_Init (BTIM_InitTypeDef* btimInitStruct)
{
    /* ����Tx����ֵ */
    btimInitStruct->m_Counter = 0x0000;
    /* ����Tx����ֵ */
    btimInitStruct->m_Period = 0xFFFF;
    /* ����TxԤ��Ƶֵ */
    btimInitStruct->m_Prescaler = 0x0000;
    /* ����Tx����ģʽ */
    btimInitStruct->m_CounterMode = BTIM_COUNT_UP_OF;
    /* ����Tx����ʱ�� */
    btimInitStruct->m_Clock = BTIM_SCLK;
    /* ���ö�ʱ/����ģʽѡ�� */
    btimInitStruct->m_WorkMode = BTIM_TIMER_MODE;
    /* ������ģʽѡ�� */
    btimInitStruct->m_MasterMode = BTIM_MASTER_TXUR_SIGNAL;
    /* ���ô�ģʽѡ�� */
    btimInitStruct->m_SlaveMode = BTIM_SLAVE_FORBIDDEN_MODE;
    /* ����Tx����ģʽ�ⲿ������������ͬ������ */
    btimInitStruct->m_EXPulseSync = BTIM_EX_SYNC_MODE;
    /* ��������ģʽͬ������ */
    btimInitStruct->m_MasterSlaveSync = FALSE;
}


/**
  * ����  ��ʱ����������ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: ��ʱ��ʹ�ܿ��ƣ�
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Cmd (BTIM_SFRmap* BTIMx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXCTL1�Ĵ���TXENλ --------------------*/
    if (NewState != FALSE)
    {
        /* ����ģʽ */
        SFR_SET_BIT_ASM(BTIMx->CTL1, BTIM_CTL1_TXEN_POS);
    }
    else
    {
        /* ��ʱģʽ */
        SFR_CLR_BIT_ASM(BTIMx->CTL1, BTIM_CTL1_TXEN_POS);
    }
}

/**
  * ����  ���¶�ʱ������ֵ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       Counter: �µļ���ֵ��ȡֵ16λ���ݡ�
  * ����  ��
  */
void BTIM_Set_Counter (BTIM_SFRmap* BTIMx, uint16_t Counter)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /* ���¶�ʱ������ֵ */
    BTIMx->CNT = Counter;
}

/**
  * ����  ���¶�ʱ������ֵ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       Period: �µ�����ֵ��ȡֵ16λ���ݡ�
  * ����  ��
  */
void BTIM_Set_Period (BTIM_SFRmap* BTIMx, uint16_t Period)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /* ���¶�ʱ������ֵ */
    BTIMx->PPX = Period;
}

/**
  * ����  ���¶�ʱ��Ԥ��Ƶֵ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       Prescaler: �µ�Ԥ��Ƶ��ȡֵ16λ���ݡ�
  * ����  ��
  */
void BTIM_Set_Prescaler (BTIM_SFRmap* BTIMx, uint16_t Prescaler)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /* ���¶�ʱ������ֵ */
    BTIMx->PRSC = Prescaler;
}

/**
  * ����  ���¶�ʱ������ģʽ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       CounterMode: �µļ���ģʽ��
  *                    ȡֵ��ΧΪ��
  *                      BTIM_COUNT_DOWN_UF: ���¼���,��������жϱ�־
  *                      BTIM_COUNT_UP_OF: ���ϼ���,��������жϱ�־
  *                      BTIM_COUNT_UP_DOWN_OF: ����-���¼���,��������жϱ�־
  *                      BTIM_COUNT_UP_DOWN_UF: ����-���¼���,��������жϱ�־
  *                      BTIM_COUNT_UP_DOWN_OUF: ����-���¼���,�������������жϱ�־
  * ����  ��
  */
void BTIM_Counter_Mode_Config (BTIM_SFRmap* BTIMx, uint32_t CounterMode)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_BTIM_COUNTER_MODE(CounterMode));

    /*-------------------- ����TXCTL1�Ĵ���TXCMSλ --------------------*/
    BTIMx->CTL1 = SFR_Config (BTIMx->CTL1,
                          ~BTIM_CTL1_TXCMS,
                          CounterMode);
}

/**
  * ����  ���¶�ʱ������ʱ�ӡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewClock: �µĹ���ʱ�ӣ�
  *                 ȡֵ��ΧΪ��
  *                   BTIM_SCLK: ѡ��SCLKʱ��
  *                   BTIM_HFCLK: ѡ��HFCLKʱ��
  *                   BTIM_LFCLK: ѡ��LFCLKʱ��
  * ����  ��
  */
void BTIM_Clock_Config (BTIM_SFRmap* BTIMx, uint32_t NewClock)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_BTIM_CLOCK_CONFIG(NewClock));

    /*-------------------- ����TXCTL1�Ĵ���TXCLKλ --------------------*/
    BTIMx->CTL1 = SFR_Config (BTIMx->CTL1,
                          ~BTIM_CTL1_TXCLK,
                          NewClock);
}

/**
  * ����  ���¶�ʱ������ģʽ�ⲿ������������ͬ������λ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewClock: �µĶ�ʱ������ģʽ�ⲿ������������ͬ������λʹ��״̬��
  *                 ȡֵ��ΧΪ��
  *                   BTIM_EX_SYNC_MODE: ���ⲿ������������ͬ��
  *                   BTIM_NO_SYNC_MODE: �����ⲿ������������ͬ��
  * ����  ��
  */
void BTIM_External_Pulse_Sync_Config (BTIM_SFRmap* BTIMx, uint32_t PulseSync)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_BTIM_SYNC_MODE(PulseSync));

    /*-------------------- ����TXCTL1�Ĵ���TXSYλ --------------------*/
    if (PulseSync != BTIM_EX_SYNC_MODE)
    {
        /* �����ⲿ������������ͬ�� */
        SFR_SET_BIT_ASM(BTIMx->CTL1, BTIM_CTL1_TXSY_POS);
    }
    else
    {
        /* ���ⲿ������������ͬ�� */
        SFR_CLR_BIT_ASM(BTIMx->CTL1, BTIM_CTL1_TXSY_POS);
    }
}

/**
  * ����  ���¶�ʱ/����ģʽѡ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: �µĶ�ʱ/����ģʽ��
  *                 ȡֵ��ΧΪ��
  *                   BTIM_TIMER_MODE: ��ʱģʽ
  *                   BTIM_COUNTER_MODE: ����ģʽ
  * ����  ��
  */
void BTIM_Work_Mode_Config (BTIM_SFRmap* BTIMx, uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_BTIM_WORK_MODE(NewState));

    /*-------------------- ����TXCTL1�Ĵ���TXCSλ --------------------*/
    if (NewState != BTIM_TIMER_MODE)
    {
        /* ����ģʽ */
        SFR_SET_BIT_ASM(BTIMx->CTL1, BTIM_CTL1_TXCS_POS);
    }
    else
    {
        /* ��ʱģʽ */
        SFR_CLR_BIT_ASM(BTIMx->CTL1, BTIM_CTL1_TXCS_POS);
    }
}

/**
  * ����  ���²��������¼�����λ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: ��ʱ��ʹ�ܿ���״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Generate_Trigger_Config (BTIM_SFRmap* BTIMx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXCTL2�Ĵ���TXTRGλ --------------------*/
    if (NewState != FALSE)
    {
        /* ����������Ӧ */
        SFR_SET_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXTRG_POS);
    }
    else
    {
        /* �޶��� */
        SFR_CLR_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXTRG_POS);
    }
}

/**
  * ����  ���õ��������ģʽ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: ���������ģʽʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Single_Pulse_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXCTL2�Ĵ���PXSPMλ --------------------*/
    if (NewState != FALSE)
    {
        /* ���������ģʽʹ�� */
        SFR_SET_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_PXSPM_POS);
    }
    else
    {
        /* ���������ģʽδʹ�� */
        SFR_CLR_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_PXSPM_POS);
    }
}

/**
  * ����  ���õ��������ģʽ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: ���������ģʽѡ��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Single_Pulse_Shut_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXCTL2�Ĵ���PXSPMSTλ --------------------*/
    if (NewState != FALSE)
    {
        /* �����������رն�ʱ��ʹ��λ */
        SFR_SET_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_PXSPMST_POS);
    }
    else
    {
        /* ����������󲻹رն�ʱ��ʹ��λ */
        SFR_CLR_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_PXSPMST_POS);
    }
}

/**
  * ����  �����������¿���λ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: ��������ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Updata_Immediately_Config (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXCTL2�Ĵ���TXURλ --------------------*/
    if (NewState != FALSE)
    {
        /* ��������ʹ�� */
        SFR_SET_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXUR_POS);
    }
    else
    {
        /* ��������δʹ�� */
        SFR_CLR_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXUR_POS);
    }
}

/**
  * ����  ��������ģʽͬ��λ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: ����ģʽͬ��λ״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Master_Slave_Snyc_Config (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXCTL2�Ĵ���TXMSSYNCλ --------------------*/
    if (NewState != FALSE)
    {
        /* ��������ʹ�� */
        SFR_SET_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXMSSYNC_POS);
    }
    else
    {
        /* ��������δʹ�� */
        SFR_CLR_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXMSSYNC_POS);
    }
}

/**
  * ����  ���ô���ѡ��λ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       TriggerSelect: ����ѡ��
  *                      ȡֵ��ΧΪ��
  *                         BTIM_TRIGGER_T1
  *                         BTIM_TRIGGER_T2
  *                         BTIM_TRIGGER_T3
  *                         BTIM_TRIGGER_T4
  *                         BTIM_TRIGGER_T5
  *                         BTIM_TRIGGER_T9
  *                         BTIM_TRIGGER_T14
  *                         BTIM_TRIGGER_T15
  *                         BTIM_TRIGGER_T18
  *                         BTIM_TRIGGER_T19
  *                         BTIM_TRIGGER_T20
  *                         BTIM_TRIGGER_T21
  *                         BTIM_TRIGGER_TXCK
  * ����  ��
  */
void BTIM_Trigger_Select_Config (BTIM_SFRmap* BTIMx,uint32_t TriggerSelect)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_BTIM_TRIGGER_MODE(TriggerSelect));

    /*-------------------- ����TXCTL2�Ĵ���TXTSλ --------------------*/
    BTIMx->CTL2 = SFR_Config (BTIMx->CTL2,
                          ~BTIM_CTL2_TXTS,
                          TriggerSelect);
}

/**
  * ����  ���ô�ģʽѡ��λ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       SlaveSelect: ��ģʽѡ��
  *                    ȡֵ��ΧΪ��
  *                      BTIM_SLAVE_FORBIDDEN_MODE: ��ģʽ��ֹ
  *                      BTIM_SLAVE_TRIGGER_MODE: ����ģʽ
  *                      BTIM_SLAVE_GATED_MODE: �ſ�ģʽ
  *                      BTIM_SLAVE_RESET_MODE: ��λģʽ
  *                      BTIM_SLAVE_COUNTER_MODE: ����ģʽ2
  * ����  ��
  */
void BTIM_Slave_Mode_Config (BTIM_SFRmap* BTIMx,uint32_t SlaveMode)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_BTIM_SLAVE_MODE(SlaveMode));

    /*-------------------- ����TXCTL2�Ĵ���TXSMSλ --------------------*/
    BTIMx->CTL2 = SFR_Config (BTIMx->CTL2,
                          ~BTIM_CTL2_TXSMS,
                          SlaveMode);
}

/**
  * ����  ������ģʽѡ��λ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       MasterMode: ��ģʽѡ��
  *                   ȡֵ��ΧΪ��
  *                     BTIM_MASTER_TXUR_SIGNAL: URλ��Ϊ����
  *                     BTIM_MASTER_TXEN_SIGNAL: TXEN��Ϊ����
  *                     BTIM_MASTER_TXIF_SIGNAL: TXIF��Ϊ����
  * ����  ��
  */
void BTIM_Master_Mode_Config (BTIM_SFRmap* BTIMx,uint32_t MasterMode)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_BTIM_MASTER_MODE(MasterMode));

    /*-------------------- ����TXCTL2�Ĵ���TXMMSλ --------------------*/
    BTIMx->CTL2 = SFR_Config (BTIMx->CTL2,
                          ~BTIM_CTL2_TXMMS,
                          MasterMode);
}

/**
  * ����  ���������ظ����¼�����λ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: �����¼�����״̬��
  *                 ȡֵ��ΧΪ��
  *                   TRUE: ��������������
  *                   FALSE: ÿ���ڸ���
  * ����  ��
  */
void BTIM_Updata_Rising_Edge_Config (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXCTL2�Ĵ���TXMSSYNCλ --------------------*/
    if (NewState != FALSE)
    {
        /* �������������� */
        SFR_SET_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXUDEVT_POS);
    }
    else
    {
        /* ÿ���ڸ��� */
        SFR_CLR_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXUDEVT_POS);
    }
}

/**
  * ����  ���ø���ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: ����ʹ��״̬��
  *                 ȡֵ��ΧΪ��
  *                   TRUE: �������
  *                   FALSE: ��ֹ����
  * ����  ��
  */
void BTIM_Updata_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXCTL2�Ĵ���TXUDENλ --------------------*/
    if (NewState != FALSE)
    {
        /* �������������� */
        SFR_SET_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXUDEN_POS);
    }
    else
    {
        /* ÿ���ڸ��� */
        SFR_CLR_BIT_ASM(BTIMx->CTL2, BTIM_CTL2_TXUDEN_POS);
    }
}

/**
  * ����  ��TX��������
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  TX��������0�����£�1�����ϡ�
  */
DIRStatus BTIM_Get_Direction (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ��ȡTXCTL1�Ĵ���TXDIRλ --------------------*/
    if (BTIMx->CTL1 & BTIM_CTL1_TXDIR)
    {
        /* ��ǰ��������Ϊ���ϼ��� */
        return DIR_UP;
    }
    else
    {
        /* ��ǰ��������Ϊ���¼��� */
        return DIR_DOWN;
    }
}

/**
  * ����  ����ʱ������ֵ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  Tx����ֵ��16λ
  */
uint16_t BTIM_Get_Counter (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /* ����ʱ������ֵ */
    return BTIMx->CNT;
}

/**
  * ����  ����ʱ������ֵ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  Tx����ֵ��16λ
  */
uint16_t BTIM_Get_Period (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /* ����ʱ������ֵ */
    return BTIMx->PPX;
}

/**
  * ����  ����ʱ��Ԥ��Ƶֵ��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  TxԤ��Ƶֵ��16λ
  */
uint16_t BTIM_Get_Prescaler (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /* ����ʱ������ֵ */
    return BTIMx->PRSC;
}

/**
  *   ##### ������ʱ��(BTIM)��ʼ�������ú���������� #####
  */


/**
  *   ##### ������ʱ��(BTIM)�жϼ���־���������� #####
  */
/**
  * ����  ���ô����¼���DMA����ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: �����¼���DMA����
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Trigger_DMA_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXDIER�Ĵ���TXTDEλ --------------------*/
    if (NewState != FALSE)
    {
        /* �������¼���DMA���� */
        SFR_SET_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXTDE_POS);
    }
    else
    {
        /* ��ֹ�����¼���DMA���� */
        SFR_CLR_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXTDE_POS);
    }
}

/**
  * ����  ���ø����¼���DMA����ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: �����¼���DMA����
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Updata_DMA_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXDIER�Ĵ���TXUDEλ --------------------*/
    if (NewState != FALSE)
    {
        /* ��������¼���DMA���� */
        SFR_SET_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXUDE_POS);
    }
    else
    {
        /* ��ֹ�����¼���DMA���� */
        SFR_CLR_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXUDE_POS);
    }
}

/**
  * ����  ����Tx��������ж�ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: Tx��������жϣ�
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Overflow_INT_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXDIER�Ĵ���TXIEλ --------------------*/
    if (NewState != FALSE)
    {
        /* ����Tx������������ж� */
        SFR_SET_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXIE_POS);
    }
    else
    {
        /* ��ֹTx������������ж� */
        SFR_CLR_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXIE_POS);
    }
}

/**
  * ����  ����Tx�����¼��ж�ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: Tx�����¼��жϣ�
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Trigger_INT_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXDIER�Ĵ���TXTIEλ --------------------*/
    if (NewState != FALSE)
    {
        /* ����Tx�����¼������ж� */
        SFR_SET_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXTIE_POS);
    }
    else
    {
        /* ��ֹTx�����¼������ж� */
        SFR_CLR_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXTIE_POS);
    }
}

/**
  * ����  ����Tx�����¼��ж�ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  *       NewState: Tx�����¼��жϣ�
  *                 ȡֵ��ΧΪ��TRUE �� FALSE
  * ����  ��
  */
void BTIM_Updata_INT_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*-------------------- ����TXDIER�Ĵ���TXUIEλ --------------------*/
    if (NewState != FALSE)
    {
        /* ����Tx�����¼������ж� */
        SFR_SET_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXUIE_POS);
    }
    else
    {
        /* ��ֹTx�����¼������ж� */
        SFR_CLR_BIT_ASM(BTIMx->DIER, BTIM_DIER_TXUIE_POS);
    }
}

/**
  * ����  ���ô����¼���DMA����ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�ʹ��״̬��0��δʹ�ܣ�1��ʹ��
  */
INTStatus BTIM_Get_Trigger_DMA_INT_Status (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXDIER�Ĵ���TXTDEλ --------------------*/
    if (BTIMx->DIER & BTIM_DIER_TXTDE)
    {
        /* ��ǰ��������Ϊ���ϼ��� */
        return SET;
    }
    else
    {
        /* ��ǰ��������Ϊ���¼��� */
        return RESET;
    }
}

/**
  * ����  ���ø����¼���DMA����ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�ʹ��״̬��0��δʹ�ܣ�1��ʹ��
  */
INTStatus BTIM_Get_Updata_DMA_INT_Status (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXDIER�Ĵ���TXUDEλ --------------------*/
    if (BTIMx->DIER & BTIM_DIER_TXUDE)
    {
        /* ��ǰ��������Ϊ���ϼ��� */
        return SET;
    }
    else
    {
        /* ��ǰ��������Ϊ���¼��� */
        return RESET;
    }
}

/**
  * ����  ����Tx��������ж�ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�ʹ��״̬��0��δʹ�ܣ�1��ʹ��
  */
INTStatus BTIM_Get_Overflow_INT_Status (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXDIER�Ĵ���TXIEλ --------------------*/
    if (BTIMx->DIER & BTIM_DIER_TXIE)
    {
        /* ��ǰ��������Ϊ���ϼ��� */
        return SET;
    }
    else
    {
        /* ��ǰ��������Ϊ���¼��� */
        return RESET;
    }
}

/**
  * ����  ����Tx�����¼��ж�ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�ʹ��״̬��0��δʹ�ܣ�1��ʹ��
  */
INTStatus BTIM_Get_Trigger_INT_Status (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXDIER�Ĵ���TXTIEλ --------------------*/
    if (BTIMx->DIER & BTIM_DIER_TXTIE)
    {
        /* ��ǰ��������Ϊ���ϼ��� */
        return SET;
    }
    else
    {
        /* ��ǰ��������Ϊ���¼��� */
        return RESET;
    }
}

/**
  * ����  ����Tx�����¼��ж�ʹ�ܡ�
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�ʹ��״̬��0��δʹ�ܣ�1��ʹ��
  */
INTStatus BTIM_Get_Updata_INT_Status (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXDIER�Ĵ���TXUIEλ --------------------*/
    if (BTIMx->DIER & BTIM_DIER_TXUIE)
    {
        /* ��ǰ��������Ϊ���ϼ��� */
        return SET;
    }
    else
    {
        /* ��ǰ��������Ϊ���¼��� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�����¼�����DMA�жϱ�־��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�״̬��0��δ�����жϣ�1�������ж�
  */
FlagStatus BTIM_Get_Trigger_DMA_INT_Flag (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXSR�Ĵ���TXTDFλ --------------------*/
    if (BTIMx->SR & BTIM_SR_TXTDF)
    {
        /* ���������¼�����DMA�ж� */
        return SET;
    }
    else
    {
        /* δ���������¼�����DMA�ж� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�����¼�����DMA�жϱ�־��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�״̬��0��δ�����жϣ�1�������ж�
  */
FlagStatus BTIM_Get_Updata_DMA_INT_Flag (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXSR�Ĵ���TXUDFλ --------------------*/
    if (BTIMx->SR & BTIM_SR_TXUDF)
    {
        /* ���������¼�����DMA�ж� */
        return SET;
    }
    else
    {
        /* δ���������¼�����DMA�ж� */
        return RESET;
    }
}

/**
  * ����  ��ȡTx��������жϱ�־��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�״̬��0��δ�����жϣ�1�������ж�
  */
FlagStatus BTIM_Get_Overflow_INT_Flag (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXSR�Ĵ���TXIFλ --------------------*/
    if (BTIMx->SR & BTIM_SR_TXIF)
    {
        /* ����Tx��������ж� */
        return SET;
    }
    else
    {
        /* δ����Tx��������ж� */
        return RESET;
    }
}

/**
  * ����  ��ȡTx�����¼��жϱ�־��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�״̬��0��δ�����жϣ�1�������ж�
  */
FlagStatus BTIM_Get_Trigger_INT_Flag (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXSR�Ĵ���TXTIFλ --------------------*/
    if (BTIMx->SR & BTIM_SR_TXTIF)
    {
        /* ����Tx�����¼��ж� */
        return SET;
    }
    else
    {
        /* δ����Tx�����¼��ж� */
        return RESET;
    }
}

/**
  * ����  ��ȡTx�����¼��жϱ�־��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  �ж�״̬��0��δ�����жϣ�1�������ж�
  */
FlagStatus BTIM_Get_Updata_INT_Flag (BTIM_SFRmap* BTIMx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXSR�Ĵ���TXUIFλ --------------------*/
    if (BTIMx->SR & BTIM_SR_TXUIF)
    {
        /* ����Tx�����¼��ж� */
        return SET;
    }
    else
    {
        /* δ����Tx�����¼��ж� */
        return RESET;
    }
}

/**
  * ����  ���Tx��������жϱ�־��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����:�����־λ״̬
  */
RetStatus BTIM_Clear_Overflow_INT_Flag (BTIM_SFRmap* BTIMx)
{
	uint32_t wait_flag = 0x0000;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXSRIC�Ĵ���TXICλ --------------------*/
    SFR_SET_BIT_ASM(BTIMx->SRIC, BTIM_SRIC_TXIC_POS);
    while(((BTIMx->SR & BTIM_SR_TXIF)>>BTIM_SR_TXIF_POS)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(BTIMx->SRIC, BTIM_SRIC_TXIC_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * ����  ���Tx�����¼��жϱ�־��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����  :�����־λ״̬
  */
RetStatus BTIM_Clear_Trigger_INT_Flag (BTIM_SFRmap* BTIMx)
{
	uint32_t wait_flag = 0x0000;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXSRIC�Ĵ���TXTICλ --------------------*/
    SFR_SET_BIT_ASM(BTIMx->SRIC, BTIM_SRIC_TXTIC_POS);
    while(((BTIMx->SR & BTIM_SR_TXTIF)>>BTIM_SR_TXTIF_POS)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(BTIMx->SRIC, BTIM_SRIC_TXTIC_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * ����  ���Tx�����¼��жϱ�־��
  * ����  BTIMx: ָ��ʱ���ڴ�ṹ��ָ�룬ȡֵT14_SFR��
  * ����    :�����־λ״̬
  * ����˵��������ñ�־λ����ʹ�ܶ�Ӧ��ʱ��������½��У�����ᵼ�����ʧ�ܡ�
  */
RetStatus BTIM_Clear_Updata_INT_Flag (BTIM_SFRmap* BTIMx)
{
	uint32_t wait_flag = 0x0000;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_BTIM_PERIPH(BTIMx));

    /*-------------------- ����TXSRIC�Ĵ���TXUICλ --------------------*/
    SFR_SET_BIT_ASM(BTIMx->SRIC, BTIM_SRIC_TXUIC_POS);
    while(((BTIMx->SR & BTIM_SR_TXUIF)>>BTIM_SR_TXUIF_POS)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(BTIMx->SRIC, BTIM_SRIC_TXUIC_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}
/**
  *   ##### ������ʱ��(BTIM)�жϼ���־������������� #####
  */
