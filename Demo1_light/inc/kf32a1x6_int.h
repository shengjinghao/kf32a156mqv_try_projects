/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_int.h                                	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the interrupt		  *
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
#ifndef KF32A1x6_INT_H_
#define KF32A1x6_INT_H_

#include "kf32a1x6.h"

/**
  * ����  �ⲿ�ж�(EINT)������Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_Line;            /* �ⲿ�жϱ�ţ�
                                   ȡֵΪ�ꡰ�ⲿ�жϱ�š��� */
    FunctionalState m_Mask;     /* �ⲿ�ж�ʹ�ܿ��ƣ�
                                   ȡֵΪTRUE��FALSE�� */
    FunctionalState m_Rise;     /* �ⲿ�ж��������ж�ʹ�ܣ�
                                   ȡֵΪTRUE��FALSE�� */
    FunctionalState m_Fall;     /* �ⲿ�ж��½����ж�ʹ�ܣ�
                                   ȡֵΪTRUE��FALSE�� */
    uint32_t m_Source;          /* �ⲿ�жϵ��ж�Դѡ��
                                   ȡֵΪ�ꡰ�ⲿ�ж�Դ���� */
} EINT_InitTypeDef;


/**
  * �ⲿ�жϱ��
  */
#define INT_EXTERNAL_INTERRUPT_0        ((uint32_t)0)
#define INT_EXTERNAL_INTERRUPT_1        ((uint32_t)1)
#define INT_EXTERNAL_INTERRUPT_2        ((uint32_t)2)
#define INT_EXTERNAL_INTERRUPT_3        ((uint32_t)3)
#define INT_EXTERNAL_INTERRUPT_4        ((uint32_t)4)
#define INT_EXTERNAL_INTERRUPT_5        ((uint32_t)5)
#define INT_EXTERNAL_INTERRUPT_6        ((uint32_t)6)
#define INT_EXTERNAL_INTERRUPT_7        ((uint32_t)7)
#define INT_EXTERNAL_INTERRUPT_8        ((uint32_t)8)
#define INT_EXTERNAL_INTERRUPT_9        ((uint32_t)9)
#define INT_EXTERNAL_INTERRUPT_10       ((uint32_t)10)
#define INT_EXTERNAL_INTERRUPT_11       ((uint32_t)11)
#define INT_EXTERNAL_INTERRUPT_12       ((uint32_t)12)
#define INT_EXTERNAL_INTERRUPT_13       ((uint32_t)13)
#define INT_EXTERNAL_INTERRUPT_14       ((uint32_t)14)
#define INT_EXTERNAL_INTERRUPT_15       ((uint32_t)15)
#define INT_EXTERNAL_INTERRUPT_16       ((uint32_t)16)
#define INT_EXTERNAL_INTERRUPT_17       ((uint32_t)17)
#define INT_EXTERNAL_INTERRUPT_18       ((uint32_t)18)
#define INT_EXTERNAL_INTERRUPT_19       ((uint32_t)19)
#define INT_EXTERNAL_INTERRUPT_20       ((uint32_t)20)
#define INT_EXTERNAL_INTERRUPT_21       ((uint32_t)21)
#define CHECK_INT_EXTERNAL_NUM(NUM)     (((NUM) >= 0) && ((NUM) <= 21))


/**
  * �ⲿ�ж����Ͽ�ѡ����ж�Դ
  */
#define INT_EXTERNAL_SOURCE_PA          ((uint32_t)0)
#define INT_EXTERNAL_SOURCE_PB          ((uint32_t)1)
#define INT_EXTERNAL_SOURCE_PC          ((uint32_t)2)
#define INT_EXTERNAL_SOURCE_PD          ((uint32_t)3)
#define INT_EXTERNAL_SOURCE_PE          ((uint32_t)4)
#define INT_EXTERNAL_SOURCE_PF          ((uint32_t)5)
#define INT_EXTERNAL_SOURCE_PG          ((uint32_t)6)
#define INT_EXTERNAL_SOURCE_PH          ((uint32_t)7)
#define INT_EXTERNAL_SOURCE_PVD			((uint32_t)8)
#define INT_EXTERNAL_SOURCE_RTC			((uint32_t)8)
#define INT_EXTERNAL_SOURCE_TAMPER		((uint32_t)8)
#define INT_EXTERNAL_SOURCE_ALARMCLK	((uint32_t)8)
#define INT_EXTERNAL_SOURCE_AES			((uint32_t)8)
#define INT_EXTERNAL_SOURCE_EINT21TO31	((uint32_t)8)
#define CHECK_INT_EXTERNAL_SOURCE(PIN)  (((PIN) >= INT_EXTERNAL_SOURCE_PA) \
                                      && ((PIN) <= INT_EXTERNAL_SOURCE_RTC))
/**
  * �ж����ȼ���Ӧ����
  */
#define CHECK_INT_PRIORITY_BASE(BASE)   ((BASE) <= 0xF)

/**
  * �ж��Զ���ջ����ѡ��
  */
#define INT_STACK_DOUBLE_ALIGN          ((uint32_t)0<<(INT_CTL0_DSALIGN_POS))
#define INT_STACK_SINGLE_ALIGN          ((uint32_t)1<<(INT_CTL0_DSALIGN_POS))
#define CHECK_INT_STACK_ALIGN(Align)    (((Align) == INT_STACK_DOUBLE_ALIGN) \
                                      || ((Align) == INT_STACK_SINGLE_ALIGN))

/**
  * �������ȼ�����
  */
#define INT_PRIORITY_GROUP_3VS1         ((uint32_t)0<<(INT_CTL0_PRIGROUP0_POS))
#define INT_PRIORITY_GROUP_2VS2         ((uint32_t)1<<(INT_CTL0_PRIGROUP0_POS))
#define INT_PRIORITY_GROUP_1VS3         ((uint32_t)2<<(INT_CTL0_PRIGROUP0_POS))
#define INT_PRIORITY_GROUP_0VS4         ((uint32_t)3<<(INT_CTL0_PRIGROUP0_POS))
#define CHECK_INT_PRIORITY_GROUP(NUM)   (((NUM) == INT_PRIORITY_GROUP_3VS1) \
                                      || ((NUM) == INT_PRIORITY_GROUP_2VS2) \
                                      || ((NUM) == INT_PRIORITY_GROUP_1VS3) \
                                      || ((NUM) == INT_PRIORITY_GROUP_0VS4))

/**
  * �ں˻������ж��������
  */
#define CHECK_PERIPHERAL_INTERRUPT_INDEX(NUM)   ((NUM) <= INT_USART7)

/**
  * �ж����ȼ�����У��
  */
#define CHECK_PRIORITY_CONFIG(GROUP, PREEMPT, SUB) \
                ((((GROUP) == INT_PRIORITY_GROUP_3VS1) \
                  && ((PREEMPT) <= 7) && ((SUB) <= 1)) \
              || (((GROUP) == INT_PRIORITY_GROUP_2VS2) \
                  && ((PREEMPT) <= 3) && ((SUB) <= 3)) \
              || (((GROUP) == INT_PRIORITY_GROUP_1VS3) \
                  && ((PREEMPT) <= 1) && ((SUB) <= 7)) \
              || (((GROUP) == INT_PRIORITY_GROUP_0VS4) \
                  && ((PREEMPT) <= 0) && ((SUB) <= 15)))

/**
 * �ж���ʱ���ò���У��
 */
#define CHECK_INT_INTDELY(TIME)   					(((TIME) >> 0x08) == 0x00)

uint8_t INT_Get_Interrupt_Action (void);
uint8_t INT_Get_Priority_Pending_Action (void);
void INT_Priority_Base (uint8_t PriBase);
uint8_t INT_Get_Priority_Base (void);
void INT_Stack_Align_Config (uint32_t StackAlign);
void INT_Fault_Masking_Config (FunctionalState NewState);
FlagStatus INT_Get_Pre_Empty (void);
FlagStatus INT_Get_Pending_Flag (void);
void INT_Priority_Group_Config (uint32_t PriorityGroup);
uint32_t INT_Get_Priority_Group (void);
void INT_All_Enable (FunctionalState NewState);
void INT_Interrupt_Enable (InterruptIndex Peripheral, FunctionalState NewState);
void INT_Set_Systick_Flag (void);
void INT_Set_SOFTSV_Flag (void);
FlagStatus INT_Get_Interrupt_Flag (InterruptIndex Peripheral);
void INT_Clear_Interrupt_Flag (InterruptIndex Peripheral);
void INT_Interrupt_Priority_Config (InterruptIndex Peripheral, uint32_t Preemption, uint32_t SubPriority);
void INT_Stack_Delay_Enable (uint8_t IntDelay);
void INT_External_Configuration (EINT_InitTypeDef* eintInitStruct);
void INT_External_Struct_Init (EINT_InitTypeDef* eintInitStruct);
void INT_External_Mask_Enable (uint32_t EintMask, FunctionalState NewState);
void INT_External_Rise_Enable (uint32_t EintMask, FunctionalState NewState);
void INT_External_Fall_Enable (uint32_t EintMask, FunctionalState NewState);
FlagStatus INT_Get_External_Flag (uint32_t EintNum);
RetStatus INT_External_Clear_Flag (uint32_t EintNum);
void INT_External_Source_Enable (uint32_t EintNum, uint32_t PeripheralSource);



#endif /* KF32A1x6_INT_H_ */
