/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_sysctl.c                             	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the system control related 		  *
 *  					functions, including:								  *
 *          			+ System control (SYSCTL) function configuration 	  *
 *          			  function      								      *
 *          			+ Do directive function configuration	              *
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


#include "kf32a1x6_sysctl.h"


/**
  *   ##### ϵͳ����(SYSCTL)�������ú��� #####
  */


/* ϵͳ����˽�ж��� ----------------------------------------------------*/
/* SYS_ARCTL�Ĵ���д����ARKEY���� */
#define SYS_ARCTL_WRITE_CTL             ((uint32_t)0x05FA \
                                      << SYS_ARCTL_ARKEY0_POS)

/**
  * ����  ��ȡ״̬��Vλ�����־��
  * ����  �ޡ�
  * ����  1:�����0:�������
  */
FlagStatus SYSCTL_Get_V_Flag (void)
{
    /*---------------- ��ȡSYS_PSW�Ĵ���Vλ ----------------*/

    if(SYS_PSW & SYS_PSW_V)
    {
        /* ��� */
        return SET;
    }
    else
    {
        /* ����� */
        return RESET;
    }
}

/**
  * ����  ��ȡ״̬��Cλ��λ���λ��־��
  * ����  �ޡ�
  * ����  1:�ӷ��н�λ������޽�λ��0:�ӷ��޽�λ������н�λ��
  */
FlagStatus SYSCTL_Get_C_Flag (void)
{
    /*---------------- ��ȡSYS_PSW�Ĵ���Cλ ----------------*/
    if (SYS_PSW & SYS_PSW_C)
    {
        /* �ӷ��н�λ������޽�λ */
        return SET;
    }
    else
    {
        /* �ӷ��޽�λ������н�λ */
        return RESET;
    }
}

/**
  * ����  ��ȡ״̬��Zλ��ֵ��־��
  * ����  �ޡ�
  * ����  1:��ֵ��0:����ֵ��
  */
FlagStatus SYSCTL_Get_Z_Flag (void)
{
    /*---------------- ��ȡSYS_PSW�Ĵ���Zλ ----------------*/
    if (SYS_PSW & SYS_PSW_Z)
    {
        /* ��ֵ */
        return SET;
    }
    else
    {
        /* ����ֵ */
        return RESET;
    }
}

/**
  * ����  ��ȡ״̬��Nλ��ֵ��־��
  * ����  �ޡ�
  * ����  1:��ֵ��0:�Ǹ�ֵ��
  */
FlagStatus SYSCTL_Get_N_Flag (void)
{
    /*---------------- ��ȡSYS_PSW�Ĵ���Nλ ----------------*/
    if (SYS_PSW & SYS_PSW_N)
    {
        /* ��ֵ */
        return SET;
    }
    else
    {
        /* �Ǹ�ֵ */
        return RESET;
    }
}

/**
  * ����  ����״̬��Vλ�����־��
  * ����  NewState: ״̬��Vλ�����־��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_Set_V_Flag (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SYS_PSW�Ĵ���Vλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���������־ */
        SFR_SET_BIT_ASM(SYS_PSW, SYS_PSW_V_POS);
    }
    else
    {
        /* ���������־ */
        SFR_CLR_BIT_ASM(SYS_PSW, SYS_PSW_V_POS);
    }
}

/**
  * ����  ����״̬��Cλ�����־��
  * ����  NewState: ״̬��Cλ��λ���λ��־��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_Set_C_Flag (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SYS_PSW�Ĵ���Cλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ý�λ���λ��־ */
        SFR_SET_BIT_ASM(SYS_PSW, SYS_PSW_C_POS);
    }
    else
    {
        /* �����λ���λ��־ */
        SFR_CLR_BIT_ASM(SYS_PSW, SYS_PSW_C_POS);
    }
}

/**
  * ����  ����״̬��Zλ�����־��
  * ����  NewState: ״̬��Zλ��λ���λ��־��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_Set_Z_Flag (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SYS_PSW�Ĵ���Zλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ý�λ���λ��־ */
        SFR_SET_BIT_ASM(SYS_PSW, SYS_PSW_Z_POS);
    }
    else
    {
        /* �����λ���λ��־ */
        SFR_CLR_BIT_ASM(SYS_PSW, SYS_PSW_Z_POS);
    }
}
/**
  * ����  ����״̬��Nλ��ֵ��־��
  * ����  NewState: ״̬��Nλ��ֵ��Ǹ�ֵ��־��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_Set_N_Flag (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SYS_PSW�Ĵ���Zλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ý�λ���λ��־ */
        SFR_SET_BIT_ASM(SYS_PSW, SYS_PSW_N_POS);
    }
    else
    {
        /* �����λ���λ��־ */
        SFR_CLR_BIT_ASM(SYS_PSW, SYS_PSW_N_POS);
    }
}

/**
  * ����  �����жϴ����ؽ�������ģʽʹ�ܡ�
  * ����  NewState: �жϴ����ؽ�������ģʽʹ��״̬��ȡֵΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_Sleep_On_Exit_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SYS_MCTL�Ĵ���SLEEPONEXITλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���жϷ���ʱ��������ģʽ */
        SFR_SET_BIT_ASM(SYS_MCTL, SYS_MCTL_SLEEPONEXIT_POS);
    }
    else
    {
        /* ��ֹ�жϷ���ʱ��������ģʽ */
        SFR_CLR_BIT_ASM(SYS_MCTL, SYS_MCTL_SLEEPONEXIT_POS);
    }
}

/**
  * ����  ���û���ģʽѡ��
  * ����  NewState: �����жϻ���CPUʹ��״̬��ȡֵΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_Interrupt_Awake_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SYS_MCTL�Ĵ���SLPONMODλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���������ж϶��ܻ���CPU */
        SFR_SET_BIT_ASM(SYS_MCTL, SYS_MCTL_SLPONMOD_POS);
    }
    else
    {
        /* ֻ�е�������ж����ȼ��ȵ�ǰ���ȼ���ʱ���ܻ���CPU */
        SFR_CLR_BIT_ASM(SYS_MCTL, SYS_MCTL_SLPONMOD_POS);
    }
}

/**
  * ����  ��ȡ��ǰ�ж��Զ���ջ�Ķ��뷽ʽ��
  * ����  �ޡ�
  * ����  1:˫�ֶ���ʹ�ܣ�0:˫�ֶ���δʹ�ܡ�
  */
FlagStatus SYSCTL_Stack_Align_State (void)
{
    /*---------------- ��ȡSYS_MCTL�Ĵ���STACKALIGNλ ----------------*/
    if (SYS_MCTL & SYS_MCTL_STACKALIGN)
    {
        /* ˫�ֶ���ʹ�� */
        return SET;
    }
    else
    {
        /* ˫�ֶ���δʹ�� */
        return RESET;
    }
}

/**
  * ����  ���ó����û����ơ�
  * ����  NewState: ѡ�񳬼��û���־��ȡֵΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_Super_User_Config (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����SYS_MCTL�Ĵ���SUSTAλ ----------------*/
    if (NewState != FALSE)
    {
        /* �����û�ģʽ */
        SFR_SET_BIT_ASM(SYS_MCTL, SYS_MCTL_SUSTA_POS);
    }
    else
    {
        /* �û�ģʽ */
        SFR_CLR_BIT_ASM(SYS_MCTL, SYS_MCTL_SUSTA_POS);
    }
}

/**
  * ����  ��ȡ��ǰ��Ч��ջָ��״̬��־��
  * ����  �ޡ�
  * ����  1:PSP�ǵ�ǰ�Ķ�ջָ�룻0:MSP�ǵ�ǰ�Ķ�ջָ�롣
  */
FlagStatus SYSCTL_Stack_Pointer_State (void)
{
    /*---------------- ��ȡSYS_MCTL�Ĵ���SPSELλ ----------------*/
    if (SYS_MCTL & SYS_MCTL_SPSEL)
    {
        /* PSP�ǵ�ǰ�Ķ�ջָ�� */
        return SET;
    }
    else
    {
        /* MSP�ǵ�ǰ�Ķ�ջָ�� */
        return RESET;
    }
}

/**
  * ����  ���õ�ǰ��Ч��ջָ�롣
  * ����  PresentSP: ��ǰ��Ч��ջָ�룬ȡֵΪ��
  *                    SYSCTL_SP_IS_MSP: MSP�ǵ�ǰ�Ķ�ջָ��
  *                    SYSCTL_SP_IS_PSP: PSP�ǵ�ǰ�Ķ�ջָ��
  * ����  �ޡ�
  */
void SYSCTL_Stack_Pointer_Config (uint32_t PresentSP)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SYSCTL_SP(PresentSP));

    /*------------------ ����SYS_MCTL�Ĵ���SPSELλ -----------------*/
    SYS_MCTL = SFR_Config (SYS_MCTL, ~SYS_MCTL_SPSEL, PresentSP);
}

/**
  * ����  �����쳣���Ϣ��λ����
  * ����  NewState: �쳣���Ϣ��λ����ȡֵΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_Exception_Reset_Enable (FunctionalState NewState)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*------------------ ����SYS_ARCTL�Ĵ���VECTRSTλ -----------------*/
    tmpreg = SYS_ARCTL_WRITE_CTL | \
            ((uint32_t)NewState << SYS_ARCTL_VECTRST_POS);
    SYS_ARCTL = SFR_Config (SYS_ARCTL,
                        ~(SYS_ARCTL_VECTRST | SYS_ARCTL_ARKEY),
                        tmpreg);
}

/**
  * ����  ����ϵͳ��λ����
  * ����  NewState: ϵͳ��λ����ȡֵΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_System_Reset_Enable (FunctionalState NewState)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*------------------ ����SYS_ARCTL�Ĵ���SYSTEMRSTλ -----------------*/
    tmpreg = SYS_ARCTL_WRITE_CTL | \
            ((uint32_t)NewState << SYS_ARCTL_SYSTEMRST_POS);
    SYS_ARCTL = SFR_Config (SYS_ARCTL,
                        ~(SYS_ARCTL_SYSTEMRST | SYS_ARCTL_ARKEY),
                        tmpreg);
}

/**
  * ����  �����ں�DMA����״̬��
  * ����  NewState: �����ں�DMA����״̬��ȡֵΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void SYSCTL_Core_Dma_Clear_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)NewState << SYS_ARCTL_CDMAR_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CDMAR | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * ����  �ں� DMA�� CPU��д��ͻ�ٲ�ģʽѡ��
  * ����  Mode: �ٲ�ģʽѡ��ȡֵΪ��
  * 				SYSCTL_FAST_MODE: ����ģʽ
  * 				SYSCTL_EFFICIENT_MODE�� ��Чģʽ
  * ����  �ޡ�
  */
void SYSCTL_Cdmaam_Config(uint32_t Mode)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SYSCTL_MODE(Mode));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)Mode << SYS_ARCTL_CDMAAM_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CDMAAM | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * ����  CORE ��д���賤����ģʽ���ơ�
  * ����  Cycle: �ٲ�ģʽѡ��ȡֵΪ��
  * 				SYSCTL_READ_PER_2CYCLE: CORE �������/д�ֱ�Ϊ 2 ���ڣ��� RAM ��/дΪ�ֱ� 1 ����
  * 				SYSCTL_READ_PER_1CYCLE�� CORE ���������������/д�ֱ�Ϊ 1 ������
  * ����  �ޡ�
  */
void SYSCTL_RW_Per_Cycle_Config(uint32_t Cycle)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SYSCTL_RW_PER_CYCLE(Cycle));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)Cycle << SYS_ARCTL_CRWDC_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CRWDC | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * ����  CORE �� DMA ��д BKP ������ģʽ���ơ�
  * ����  Cycle: CORE �� DMA ��д BKP ������ģʽ���ƣ�ȡֵΪ��
  * 				SYSCTL_RW_DMA_4CYCLE: CORE �� DMA �� BKP ���/д�ֱ�Ϊ 4 ������
  * 				SYSCTL_RW_DMA_1CYCLE�� CORE �� DMA �� BKP ���/д�ֱ�Ϊ 1 ������
  * ����  �ޡ�
  */
void SYSCTL_RW_Dma_Cycle_Config(uint32_t Cycle)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SYSCTL_RW_DMA_CYCLE(Cycle));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)Cycle << SYS_ARCTL_CDMADC_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CDMADC | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * ���� CORE �� DMA ��д BKP ��ӳ�����ģʽ���ơ�
  * ����  Cycle ȡֵΪ��
  * 				SYSCTL_RW_DMA_CDMADC: CORE �� DMA �� BKP �������� CDMADC ����
  * 				SYSCTL_RW_DMA_16CYCLE�� CORE �� DMA �� BKP ���/д�ֱ�Ϊ 16 ������
  * 				SYSCTL_RW_DMA_32CYCLE: CORE �� DMA �� BKP ���/д�ֱ�Ϊ 32 ������
  * 				SYSCTL_RW_DMA_64CYCLE: CORE �� DMA �� BKP ���/д�ֱ�Ϊ 64 ������
  * ����  �ޡ�
  */
void SYSCTL_RW_Dma_Long_Cycle_Config(uint32_t Cycle)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SYSCTL_RW_DMA_LONG_CYCLE(Cycle));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)Cycle << SYS_ARCTL_CDMALDC0_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CDMALDC | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * ����  �ж���������ӳ���ַ���á�
  * ����  VectorOffset: �ж���������ӳ���ַ��ȡֵ32λ���ݣ�����λӲ�����ԡ�
  * ����  �ޡ�
  */
void SYSCTL_Vector_Offset_Config (uint32_t VectorOffset)
{
	uint32_t tmpreg;
    /*---------------- ����SYS_VECTOFF�Ĵ���TBLOFFλ ----------------*/
	tmpreg = VectorOffset << SYS_VECTOFF_TBLOFF0_POS;
    SYS_VECTOFF = SFR_Config (SYS_VECTOFF,
                      ~(SYS_VECTOFF_TBLOFF),
                      tmpreg);
}

/**
  * ����  ����RAM�ռ䳤�ȣ�ָʾRAM�ռ������ַ��
  * ����  RamSpace: RAM�ռ䳤�ȣ�ȡֵΪ26λ��Ч��ֵ��
  * ����  �ޡ�
  */
void SYSCTL_Ram_Space_Config (uint32_t RamSpace)
{
	uint32_t tmpreg;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_RAM_SPACE(RamSpace));

    /*---------------- ����SYS_RAMSPA�Ĵ���RAMSPAλ ----------------*/
    tmpreg = RamSpace << SYS_RAMSPA_RAMSPA0_POS;
    SYS_RAMSPA = SFR_Config (SYS_RAMSPA,
                      ~SYS_RAMSPA_RAMSPA,
                      tmpreg);
}

/**
  * ����  ����FLASH��ʼ512�ֽڿռ�ӳ����ơ�
  * ����  MemCtl: ӳ����ƣ�ȡֵ��ΧΪ:
  *                 SYSCTL_FLASH_REMAP_FOR_ROM: ΪROM��ӳ��
  *                 SYSCTL_FLASH_REMAP_FOR_RAM: ΪRAM��ӳ��
  *                 SYSCTL_FLASH_REMAP_FOR_FLASH: ΪFLASH��ӳ��
  *                 SYSCTL_FLASH_REMAP_STOP_CPU: ֹͣCPU����
  * ����  �ޡ�
  */
void SYSCTL_Flash_Start_Remap_Config (uint32_t MemCtl)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SYSCTL_FLASH_REMAP(MemCtl));

    /*---------------- ����SYS_MEMCTL�Ĵ���MEMMλ ----------------*/
    SYS_MEMCTL = SFR_Config (SYS_MEMCTL, ~SYS_MEMCTL_MEMM, MemCtl);
}

/**
  * ����  ����SYS_MSPSPA��ջָ�����ޡ�
  * ����   Mspspah: ��ջָ�� MSP �ռ�����ֵָʾ��ȡֵ��ΧΪ:0~0xFFFF
  * ����  �ޡ�
  */
void SYSCTL_MSPSPAH_Threshold_Config (uint16_t Mspspah)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPA_Threshold(Mspspah));

    SYS_MSPSPA = SFR_Config(SYS_MSPSPA, ~(SYS_MSPSPA_MSPSPAH), Mspspah << SYS_MSPSPA_MSPSPAH0_POS);
}

/**
  * ����  ����SYS_MSPSPA��ջָ�� MSP�ռ�ָʾ�Ĵ�����
  * ����   Mspspal: ��ջָ�� MSP ������ֵָʾ��ȡֵ��ΧΪ:0~0xFFFF
  * ����  �ޡ�
  */
void SYSCTL_MSPSPAL_Threshold_Config (uint16_t Mspspal)
{
    /* ����У�� */
	CHECK_RESTRICTION(CHECK_SPA_Threshold(Mspspal));

    SYS_MSPSPA = SFR_Config(SYS_MSPSPA, ~(SYS_MSPSPA_MSPSPAL), Mspspal << SYS_MSPSPA_MSPSPAL0_POS);
}

/**
  * ����  ����SYS_PSPSPA��ջָ�����ޡ�
  * ����   Pspspah: ��ջָ�� PSP �ռ�����ֵָʾ��ȡֵ��ΧΪ:0~0xFFFF
  * ����  �ޡ�
  */
void SYSCTL_PSPSPAH_Threshold_Config (uint16_t Pspspah)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPA_Threshold(Pspspah));

    SYS_PSPSPA = SFR_Config(SYS_PSPSPA, ~(SYS_PSPSPA_PSPSPAH), Pspspah << SYS_PSPSPA_PSPSPAH0_POS);
}

/**
  * ����  ����SYS_PSPSPA��ջָ�����ޡ�
  * ����   Pspspah: ��ջָ�� PSP �ռ�����ֵָʾ��ȡֵ��ΧΪ:0~0xFFFF
  * ����  �ޡ�
  */
void SYSCTL_PSPSPAL_Threshold_Config (uint16_t Pspspal)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SPA_Threshold(Pspspal));

    SYS_PSPSPA = SFR_Config(SYS_PSPSPA, ~(SYS_PSPSPA_PSPSPAL), Pspspal << SYS_PSPSPA_PSPSPAL0_POS);
}

/**
  *   ##### ϵͳ����(SYSCTL)�������ú���������� #####
  */
