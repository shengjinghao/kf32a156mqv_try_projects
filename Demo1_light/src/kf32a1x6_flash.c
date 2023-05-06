/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_flash.c                             	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Flash function	  			  *
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
#include "kf32a1x6_flash.h"



/* ��ʱ��˽�ж��� ----------------------------------------------------*/
/* FLASH_ISPCON0���ƼĴ���д������16λֵ */
#define FLASH_ISPCON0_HIGH              ((uint32_t)0x50AF0000)
#define FLASH_ISPCON0_HIGH_MSK          ((uint32_t)0xFFFF0000)

/* FLASH_ISPCON1���ƼĴ���д������16λֵ */
#define FLASH_ISPCON1_HIGH              ((uint32_t)0xA05F0000)
#define FLASH_ISPCON1_HIGH_MSK          ((uint32_t)0xFFFF0000)

/* FLASH_ISPTRG���ƼĴ���д������16λֵ */
#define FLASH_ISPTRG_HIGH               ((uint32_t)0x50AF0000)
#define FLASH_ISPTRG_HIGH_MSK           ((uint32_t)0xFFFF0000)

/**
  *   ##### FLASH����洢��(FLASH)�������ú��� #####
  */

void __attribute__((section(".indata"))) CHECK_RESTRICTION_RAM(int expr)
{
	while(!expr)
		;
}

/* д���⹦�ܼĴ���RAM */
static inline uint32_t   __attribute__((section(".indata"))) SFR_Config_RAM (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}

/**
  * ����  ��FLASH����������״̬��
  * ����  �ޡ�
  * ����  ����״̬��1������״̬��0������״̬��
  */
LockStatus __attribute__((section(".indata"))) FLASH_Get_NonVolatile_Memory_Unlock_Status_RAM (void)
{
    if (FLASH_ISPCON0 & FLASH_ISPCON0_NVMLOCK)
    {
        /* ����״̬ */
        return UNLOCK;
    }
    else
    {
        /* ����״̬ */
        return LOCK;
    }
}

/**
  * ����  ����FLASH����������״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM (void)
{
	uint32_t tmpreg;

    /*---------------- ����FLASH_ISPCON0�Ĵ���NVMLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_NVMLOCK;
    FLASH_ISPCON0 = SFR_Config_RAM (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_NVMLOCK),
                        tmpreg);
}
/**
  * ����  ����FLASH����������״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void FLASH_Clear_NonVolatile_Memory_Unlock_Status (void)
{
	uint32_t tmpreg;

    /*---------------- ����FLASH_ISPCON0�Ĵ���NVMLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_NVMLOCK;
    FLASH_ISPCON0 = SFR_Config (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_NVMLOCK),
                        tmpreg);
}


/**
  * ����  ��FLASH����״̬��
  * ����  �ޡ�
  * ����  ����״̬��1������״̬��0������״̬��
  */
LockStatus __attribute__((section(".indata"))) FLASH_Get_Flash_Unlock_Status_RAM (void)
{
    if (FLASH_ISPCON0 & FLASH_ISPCON0_FLASHLOCK)
    {
        /* ����״̬ */
        return UNLOCK;
    }
    else
    {
        /* ����״̬ */
        return LOCK;
    }
}

/**
  * ����  ����FLASH����״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Clear_Flash_Unlock_Status_RAM (void)
{
	uint32_t tmpreg;

    /*---------------- ����FLASH_ISPCON0�Ĵ���FLASHLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_FLASHLOCK;
    FLASH_ISPCON0 = SFR_Config_RAM (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_FLASHLOCK),
                        tmpreg);
}
/**
  * ����  ����FLASH����״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void FLASH_Clear_Flash_Unlock_Status (void)
{
	uint32_t tmpreg;

    /*---------------- ����FLASH_ISPCON0�Ĵ���FLASHLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_FLASHLOCK;
    FLASH_ISPCON0 = SFR_Config (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_FLASHLOCK),
                        tmpreg);
}


/**
  * ����  ��FLASH����������״̬��
  * ����  �ޡ�
  * ����  ����״̬��1������״̬��0������״̬��
  */
LockStatus __attribute__((section(".indata"))) FLASH_Get_Config_Unlock_Status_RAM (void)
{
    if (FLASH_ISPCON0 & FLASH_ISPCON0_CFGLOCK)
    {
        /* ����״̬ */
        return UNLOCK;
    }
    else
    {
        /* ����״̬ */
        return LOCK;
    }
}

/**
  * ����  ����FLASH����������״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Clear_Config_Unlock_Status_RAM (void)
{
	uint32_t tmpreg;

    /*---------------- ����FLASH_ISPCON0�Ĵ���CFGLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_CFGLOCK;
    FLASH_ISPCON0 = SFR_Config_RAM (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_CFGLOCK),
                        tmpreg);
}
/**
  * ����  ����FLASH����������״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void FLASH_Clear_Config_Unlock_Status (void)
{
	uint32_t tmpreg;

    /*---------------- ����FLASH_ISPCON0�Ĵ���CFGLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_CFGLOCK;
    FLASH_ISPCON0 = SFR_Config (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_CFGLOCK),
                        tmpreg);
}


/**
  * ����  ����FLASHд����ʹ�ܡ�
  * ����  NewState: FLASHд����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void  __attribute__((section(".indata"))) FLASH_Data_Write_Enable_RAM (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_ISPCON0�Ĵ���DWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* FLASHд������Ա�д������ */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_DWEN_POS));
    }
    else
    {
        /* FLASHд�����ֹ��д������ */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_DWEN_POS));
    }
}

/**
  * ����  ����FLASH��Ϣ��ѡ��
  * ����  ZoneSelect: FLASH��Ϣ��ѡ��ȡֵΪ��
  *                     FLASH_NVM_CODE_ZONE: FLASH������
  *                     FLASH_NVM_INFORMATION_ZONE: FLASH_NVM_CODE_ZONE
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Zone_Config_RAM (uint32_t ZoneSelect)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_NVM_ZONE(ZoneSelect));

    /*---------------- ����FLASH_ISPCON0�Ĵ���IFENλ ----------------*/
    if (ZoneSelect != FLASH_NVM_CODE_ZONE)
    {
        /* NVM�����洢��ѡ��FLASH��Ϣ�� */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_IFEN_POS));
    }
    else
    {
        /* NVM�����洢��ѡ��FLASH������ */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_IFEN_POS));
    }
}
/**
  * ����  ����FLASH��Ϣ��ѡ��
  * ����  ZoneSelect: FLASH��Ϣ��ѡ��ȡֵΪ��
  *                     FLASH_NVM_CODE_ZONE: FLASH������
  *                     FLASH_NVM_INFORMATION_ZONE: FLASH_NVM_CODE_ZONE
  * ����  �ޡ�
  */
void FLASH_Zone_Config(uint32_t ZoneSelect)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FLASH_NVM_ZONE(ZoneSelect));

    /*---------------- ����FLASH_ISPCON0�Ĵ���IFENλ ----------------*/
    if (ZoneSelect != FLASH_NVM_CODE_ZONE)
    {
        /* NVM�����洢��ѡ��FLASH��Ϣ�� */
        SFR_SET_BIT_ASM(FLASH_ISPCON0, FLASH_ISPCON0_IFEN_POS);
    }
    else
    {
        /* NVM�����洢��ѡ��FLASH������ */
        SFR_CLR_BIT_ASM(FLASH_ISPCON0, FLASH_ISPCON0_IFEN_POS);
    }
}
/**
  * ����  ����FLASHģʽ��
  * ����  ModeSelect: FLASH��Ϣ��ѡ��ȡֵΪ��
  *                     FLASH_MODE_NORMAL: ��Ϊ����ģʽ
  *                     FLASH_MODE_STANDBY1: STANDBY1 ����Stanbyģʽ
  *                     FLASH_MODE_STANDBY2: STANDBY2 ��������ģʽ
  *                     FLASH_MODE_STANDBY1_STANDBY2: ������Stanbyģʽ
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Standby_Mode_Config_RAM (uint32_t ModeSelect)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_MODE(ModeSelect));

    /*---------------- ����FLASH_ISPCON0�Ĵ���CFGLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | ModeSelect;
    FLASH_ISPCON0 = SFR_Config_RAM (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_STANDBY1),
                        tmpreg);
}



/**
  * ����  ����FLASH��ģʽ��
  * ����  ReadMode: FLASH��ģʽѡ��ȡֵΪ��
  *                   FLASH_READ_MODE_NORMAL: ����ģʽ
  *                   FLASH_READ_MODE_RECALL: RECALLģʽ
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Read_Mode_Config_RAM (uint32_t ReadMode)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_READ_MODE(ReadMode));

    /*---------------- ����FLASH_ISPCON1�Ĵ���RECALLENλ ----------------*/
    if (ReadMode != FLASH_IP1)
    {
        /* FLASH��������Ϊ����ģʽ */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_ISPCON1)),"i"(FLASH_ISPCON1_RECALLEN_POS));
    }
    else
    {
        /* FLASH��������ΪRECALLģʽ */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_ISPCON1)),"i"(FLASH_ISPCON1_RECALLEN_POS));
    }
}

/**
  * ����  ����FLASHУ׼��Ϣ����ʹ�ܡ�
  * ����  NewState: FLASHУ׼��Ϣ����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Calibration_Updata_Enable_RAM (FunctionalState NewState)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_ISPCON1�Ĵ���CONFENλ ----------------*/
    tmpreg = FLASH_ISPCON1_HIGH \
           | (NewState << FLASH_ISPCON1_CONFEN_POS);
    FLASH_ISPCON1 = SFR_Config_RAM (FLASH_ISPCON1,
                        ~(FLASH_ISPCON1_HIGH_MSK | FLASH_ISPCON1_CONFEN),
                        tmpreg);
}

/**
  * ����  ����FLASHоƬ��Ϣ����д����״̬��
  * ����  NewState: FLASHоƬ��Ϣ����д����״̬��ȡֵΪ��
  *                   LOCK: ����״̬
  *                   UNLOCK: ����״̬
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Information_Zone_Wipe_Unlock_Config_RAM (LockStatus NewState)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_LOCK_STATUS(NewState));

    /*---------------- ����FLASH_ISPCON1�Ĵ���CONFENλ ----------------*/
    tmpreg = FLASH_ISPCON1_HIGH \
           | (NewState << FLASH_ISPCON1_CHIPONEN_POS);
    FLASH_ISPCON1 = SFR_Config_RAM (FLASH_ISPCON1,
                        ~(FLASH_ISPCON1_HIGH_MSK | FLASH_ISPCON1_CHIPONEN),
                        tmpreg);
}

/**
  * ����  ����FLASH��ҳ���ģʽ����Ҫд���������
  * ����  WriteSize: ��Ҫд���������ȡֵ6λ��ֵ��
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Half_Page_Write_Size_Config_RAM (uint32_t WriteSize)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_WRITE_SIZE(WriteSize));

    /*---------------- ����FLASH_ISPCMD�Ĵ���WSIZEλ ----------------*/
    tmpreg = WriteSize << FLASH_ISPCMD_WSIZE0_POS;
    FLASH_ISPCMD = SFR_Config_RAM (FLASH_ISPCMD,
                        ~FLASH_ISPCMD_WSIZE,
                        tmpreg);
}

/**
  * ����  ����FLASH����ѡ��
  * ����  CmdSelect: FLASH����ѡ��ȡֵΪ��
  *                    FLASH_PROGRAM_CMD_WORD: ���ֱ��
  *                    FLASH_PROGRAM_CMD_ALL_CODE: Ƭ��
  *                    FLASH_PROGRAM_CMD_PAGE: ҳ��
  *                    FLASH_PROGRAM_CMD_HALF_PAGE: ��ҳ���
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Program_Cmd_Config_RAM (uint32_t CmdSelect)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_PROGRAM_CMD(CmdSelect));

    /*---------------- ����FLASH_ISPCMD�Ĵ���CMDλ ----------------*/
    FLASH_ISPCMD = SFR_Config_RAM (FLASH_ISPCMD,
                        ~FLASH_ISPCMD_CMD,
                        CmdSelect);
}

/**
  * ����  ִ�е�ǰFLASH_ISPCMD�Ĵ����趨�������FLASH_Program_Cmd_Config����
  *       ���õ����
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Executive_Cmd_RAM(void)
{
	uint32_t tmpreg;

    /*---------------- ����FLASH_ISPTRG�Ĵ���ISPGOλ ----------------*/
    tmpreg = FLASH_ISPTRG_HIGH | FLASH_ISPTRG_ISPGO;
    FLASH_ISPTRG = SFR_Config_RAM (FLASH_ISPTRG,
                        ~(FLASH_ISPTRG_HIGH_MSK | FLASH_ISPTRG_ISPGO),
                        tmpreg);
}

/**
  * ����  ִ�е�ǰFLASH_ISPCMD�Ĵ����趨�������FLASH_Program_Cmd_Config����
  *       ���õ����
  * ����  �ޡ�
  * ����  �ޡ�
  */
void FLASH_Executive_Cmd(void)
{
	uint32_t tmpreg;

    /*---------------- ����FLASH_ISPTRG�Ĵ���ISPGOλ ----------------*/
    tmpreg = FLASH_ISPTRG_HIGH | FLASH_ISPTRG_ISPGO;
    FLASH_ISPTRG = SFR_Config_RAM (FLASH_ISPTRG,
                        ~(FLASH_ISPTRG_HIGH_MSK | FLASH_ISPTRG_ISPGO),
                        tmpreg);
}

/**
  * ����  ����FLASH����ʧ�Դ洢��ECCʹ�ܡ�
  * ����  NewState: FLASH����ʧ�Դ洢��ECCʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_NonVolatile_Memory_ECC_Enable_RAM (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_CFG�Ĵ���ECCREADENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��ECCУ�� */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_CFG)),"i"(FLASH_CFG_ECCREADEN_POS));
    }
    else
    {
        /* ��ʹ��ECCУ�� */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_CFG)),"i"(FLASH_CFG_ECCREADEN_POS));
    }
}

/**
  * ����  ����FLASH����Ԥȡʹ�ܡ�
  * ����  NewState: FLASH����Ԥȡʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Linear_Prefetch_Enable_RAM (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_CFG�Ĵ���PREFETCHENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ������Ԥȡ */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_CFG)),"i"(FLASH_CFG_PREFETCHEN_POS));
    }
    else
    {
        /* ��ʹ������Ԥȡ */
    	__asm volatile("CLR [%0], #%1"::"r"(&(FLASH_CFG)),"i"(FLASH_CFG_PREFETCHEN_POS));
    }
}

/**
  * ����  ����FLASH�������ڡ�
  * ����  PeriodNum: FLASH����ϵͳ���ڸ�����ȡֵΪ1~16��
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Period_Number_Config_RAM (uint32_t PeriodNum)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_PERIOD(PeriodNum));

    /*---------------- ����FLASH_CFG�Ĵ���TCFGλ ----------------*/
    tmpreg = (PeriodNum - 1) << FLASH_CFG_TCFG0_POS;
    FLASH_CFG = SFR_Config_RAM (FLASH_CFG,
                        ~FLASH_CFG_TCFG,
                        tmpreg);
}

/**
  * ����  ����FLASH��̺��в��ڼ�ĵ�ַ��
  * ����  ProgramAddr: FLASH��̵�ַ��ȡֵΪ0x0~0xFFFFF��Ӳ�����Ե�2λ��
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Program_Addr_Config_RAM (uint32_t ProgramAddr)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_ADDR_20BITS(ProgramAddr));

    /*---------------- ����FLASH_ISPADDR�Ĵ���SADDRλ ----------------*/
    tmpreg = ProgramAddr << FLASH_ISPADDR_SADDR0_POS;
    FLASH_ISPADDR = SFR_Config_RAM (FLASH_ISPADDR,
                        ~FLASH_ISPADDR_SADDR,
                        tmpreg);
}

/**
  * ����  ��FLASH���״̬��   RAM
  * ����  �ޡ�
  * ����  ���״̬��1��FLASH�����ڱ��״̬��0��FLASH���ڱ��״̬��
  */
FlagStatus  __attribute__((section(".indata"))) FLASH_Get_Program_Status_RAM (void)
{
    if (FLASH_STATE & FLASH_STATE_TBUSY)
    {
        /* ���״̬ */
        return SET;
    }
    else
    {
        /* ���ڱ��״̬ */
        return RESET;
    }
}

/**
  * ����  ��FLASH���״̬��   RAM
  * ����  �ޡ�
  * ����  ���״̬��1��FLASH�����ڱ��״̬��0��FLASH���ڱ��״̬��
  */
FlagStatus FLASH_Get_Program_Status (void)
{
    if (FLASH_STATE & FLASH_STATE_TBUSY)
    {
        /* ���״̬ */
        return SET;
    }
    else
    {
        /* ���ڱ��״̬ */
        return RESET;
    }
}



/**
  * ����  ��FLASH��д״̬��
  * ����  �ޡ�
  * ����  ���״̬��1��ISP����ִ�в�������д���0��ISP���ڿ���״̬��
  */
FlagStatus   __attribute__((section(".indata"))) FLASH_Get_Wipe_Status_RAM (void)
{
    if (FLASH_STATE & FLASH_STATE_TBIT)
    {
        /* ����ִ�в�������д���� */
        return SET;
    }
    else
    {
        /* ���ڿ���״̬ */
        return RESET;
    }
}

/**
  * ����  ��FLASH��д״̬��
  * ����  �ޡ�
  * ����  ���״̬��1��ISP����ִ�в�������д���0��ISP���ڿ���״̬��
  */
FlagStatus FLASH_Get_Wipe_Status (void)
{
    if (FLASH_STATE & FLASH_STATE_TBIT)
    {
        /* ����ִ�в�������д���� */
        return SET;
    }
    else
    {
        /* ���ڿ���״̬ */
        return RESET;
    }
}
/**
  * ����  ��FLASH�������״̬��
  * ����  �ޡ�
  * ����  ���״̬��1��������ɣ�0��δ������߼����С�
  */
FlagStatus __attribute__((section(".indata"))) FLASH_Get_Compute_Complete_Status_RAM (void)
{
    if (FLASH_STATE & FLASH_STATE_SIGDONE)
    {
        /* ������� */
        return SET;
    }
    else
    {
        /* δ������߼����� */
        return RESET;
    }
}

/**
  * ����  ����FLASH�������״̬��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Clear_Compute_Complete_Status_RAM (void)
{
    /* д 1 ���� */
    while((FLASH_STATE & FLASH_STATE_SIGDONE)>>FLASH_STATE_SIGDONE_POS)
    {
    	__asm volatile("SET [%0], #%1"::"r"(&(FLASH_STATE)),"i"(FLASH_STATE_SIGDONE_POS));
    }
}

#if _CLOSE_SERVICE_

/**
  * ����  ��FLASH CFG��̴����־��
  * ����  �ޡ�
  * ����  ��̴����־��1��CFG��������̴���0��������
  */
FlagStatus  __attribute__((section(".indata"))) FLASH_Get_CFG_Error_Flag_RAM (void)
{
    if (FLASH_STATE & FLASH_STATE_CFGERROR)
    {
        /* CFG��������̴��� */
        return SET;
    }
    else
    {
        /* ���� */
        return RESET;
    }
}

/**
  * ����  ����FLASH CFG��̴����־��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void  __attribute__((section(".indata"))) FLASH_Clear_CFG_Error_Flag_RAM (void)
{
    /* д 1 ���� */

    while((FLASH_STATE & FLASH_STATE_CFGERROR)>>FLASH_STATE_CFGERROR_POS)
    {
    	__asm volatile("SET [%0], #%1"::"r"(&(FLASH_STATE)),"i"(FLASH_STATE_CFGERROR_POS));
    }
}
#endif /* _CLOSE_SERVICE_ */

/**
  * ����  ����FLASH CheckSum��β��ַ��
  * ����  StartAddr: FLASH CheckSum���׵�ַ����ַ����Ϊ0x0~0xFFFFF��Ӳ�����Ե�4λ��
  *       StopAddr: FLASH CheckSum��β��ַ����ַ����Ϊ0x0~0xFFFFF��Ӳ�����Ե�4λ��
  * ����  �ޡ�
  */
void  __attribute__((section(".indata"))) FLASH_CheckSum_Addr_Config_RAM(uint32_t StartAddr, uint32_t StopAddr)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_ADDR_20BITS(StartAddr));
    CHECK_RESTRICTION_RAM(CHECK_FLASH_ADDR_20BITS(StopAddr));

    FLASH_CSSTART = StartAddr;
    FLASH_CSSTOP = StopAddr;
}

/**
  * ����  ����FLASH����SIG����ʹ�ܡ�
  * ����  NewState: FLASH����SIG����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void  __attribute__((section(".indata"))) FLASH_Start_SIG_Compute_Enable_RAM (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_CSSTOP�Ĵ���SIGGOλ ----------------*/
    if (NewState != FALSE)
    {
        /* ����SIG���� */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_CSSTOP)),"i"(FLASH_CSSTOP_SIGGO_POS));
    }
    else
    {
        /* ������SIG���� */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_CSSTOP)),"i"(FLASH_CSSTOP_SIGGO_POS));
    }
}

/**
  * ����  ��ȡFLASH CheckSum�Ľ����
  * ����  CheckSumStruct: FLASH CheckSum��Ϣ�ṹ��ָ�룬
  *                       ָ�����ָ���д�ĵ�ַ�ռ䡣
  * ����  �ޡ�
  */
void __attribute__((section(".indata"))) FLASH_Get_CheckSum_Result_RAM (FLASH_CheckSumResult* CheckSumStruct)
{
	uint32_t tmpreg;

    /*---------------- ����FLASH_CSRESx�Ĵ���CKSPRESλ ----------------*/
    tmpreg = FLASH_CSRES0;
    CheckSumStruct->m_ResultWord[0] = tmpreg;

    tmpreg = FLASH_CSRES1;
    CheckSumStruct->m_ResultWord[1] = tmpreg;

    tmpreg = FLASH_CSRES2;
    CheckSumStruct->m_ResultWord[2] = tmpreg;

    tmpreg = FLASH_CSRES3;
    CheckSumStruct->m_ResultWord[3] = tmpreg;
}

/**
  * ����: ��ȡCACHE��ECC�����־
  * ���룺 �ޡ�
  * ���أ� 	0��CACHE��ECC�����ȷ
  * 	  	1��CACHE��ECC�������
  **/
FlagStatus CACHE_Get_CACHE_ECC_Error_Flag(void)
{
	return ((CACHE_CTLR & PCLK_CTL3_CECCERRFLAG) >> PCLK_CTL3_CECCERRFLAG_POS);
}
/**
  * ����: ��ȡFLASH��ECC�����־
  * ���룺 �ޡ�
  * ���أ� 	0��FLASH��ECC�����ȷ
  * 	  	1��FLASH��ECC�������
  **/
FlagStatus CACHE_Get_FLASH_ECC_Error_Flag(void)
{
	return ((CACHE_CTLR & PCLK_CTL3_FECCERRFLAG) >> PCLK_CTL3_FECCERRFLAG_POS);
}
/**
  * ����: RAM��ECCУ������ж�ʹ��
  * ���룺 	NewState : 	TRUE : RAM��ECCУ������ж�ʹ��
  * 					FALSE : RAM��ECCУ������жϽ�ֹ��
  * ���أ� �ޡ�
  **/
void CACHE_RAM_Check_ECC_Error_INT_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << PCLK_CTL3_RECCERRIE_POS;
	CACHE_CTLR = SFR_Config(CACHE_CTLR, ~PCLK_CTL3_RECCERRIE, tmpreg);
}
/**
  * ����: CACHE��ECCУ������ж�ʹ��
  * ���룺 	NewState : 	TRUE : CACHE��ECCУ������ж�ʹ��
  * 					FALSE : CACHE��ECCУ������жϽ�ֹ��
  * ���أ� �ޡ�
  **/
void CACHE_CACHE_Check_ECC_Error_INT_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << PCLK_CTL3_CECCERRIE_POS;
	CACHE_CTLR = SFR_Config(CACHE_CTLR, ~PCLK_CTL3_CECCERRIE, tmpreg);
}
/**
  * ����: FLASH��ECCУ������ж�ʹ��
  * ���룺 	NewState : 	TRUE : FLASH��ECCУ������ж�ʹ��
  * 					FALSE : FLASH��ECCУ������жϽ�ֹ��
  * ���أ� �ޡ�
  **/
void CACHE_FLASH_Check_ECC_Error_INT_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << PCLK_CTL3_FECCERRIE_POS;
	CACHE_CTLR = SFR_Config(CACHE_CTLR, ~PCLK_CTL3_FECCERRIE, tmpreg);
}
/**
  * ����: CACHE��ECCУ��ʹ��
  * ���룺 	NewState : 	TRUE : CACHE��ECCУ��ʹ��
  * 					FALSE : CACHE��ECCУ��رա�
  * ���أ� �ޡ�
  **/
void CACHE_CACHE_Check_ECC_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << PCLK_CTL3_CECCEN_POS;
	CACHE_CTLR = SFR_Config(CACHE_CTLR, ~PCLK_CTL3_CECCEN, tmpreg);
}
/**
  * ����: ָ��CACHE��2��ʹ��
  * ���룺 	NewState : 	TRUE : ��ת����ʱ������ת��ַλ<2>Ϊ1ʱʹ�ܶ�2��CACHE
  * 					FALSE : ��ת����ʱֻ��1�С�
  * ���أ� �ޡ�
  **/
void CACHE_Instruction_CACHE_Read_2Row_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << PCLK_CTL3_ICRD2LEN_POS;
	CACHE_CTLR = SFR_Config(CACHE_CTLR, ~PCLK_CTL3_ICRD2LEN, tmpreg);
}
/**
  * ����: ָ��CACHEд2��ʹ��
  * ���룺 	NewState : 	TRUE : ��ת����ʱ������ת��ַλ<2>Ϊ1ʱʹ��д2��CACHE
  * 					FALSE : ��ת����ʱֻд1�С�
  * ���أ� �ޡ�
  **/
void CACHE_Instruction_CACHE_Write_2Row_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << PCLK_CTL3_ICWR2LEN_POS;
	CACHE_CTLR = SFR_Config(CACHE_CTLR, ~PCLK_CTL3_ICWR2LEN, tmpreg);
}
/**
  * ����: CACHE��λ
  * ���룺 	NewState : 	TRUE : ��λCACHE��ֻ����CACHE�ر�ʱ�Ը�λ��1��
  * 					FALSE : ����λCACHE��
  * ���أ� �ޡ�
  **/
void CACHE_CACHE_Reset_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << PCLK_CTL3_CACHERST_POS;
	CACHE_CTLR = SFR_Config(CACHE_CTLR, ~PCLK_CTL3_CACHERST, tmpreg);
}
/**
  * ����: CACHEʹ��
  * ���룺 	NewState : 	TRUE : CACHEʹ��
  * 					FALSE : CACHE�رա�
  * ���أ� �ޡ�
  **/
void CACHE_CACHE_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << PCLK_CTL3_CACHEEN_POS;
	CACHE_CTLR = SFR_Config(CACHE_CTLR, ~PCLK_CTL3_CACHEEN, tmpreg);
}

