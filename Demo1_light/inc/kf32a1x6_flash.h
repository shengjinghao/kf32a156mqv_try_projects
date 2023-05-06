/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_flash.h                               	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the FLASH			  *
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
#ifndef KF32A1x6_FLASH_H_
#define KF32A1x6_FLASH_H_


#include "kf32a1x6.h"


/* ��������״̬ */
typedef enum
{
    LOCK = 0,
    UNLOCK = !LOCK
} LockStatus;
#define CHECK_LOCK_STATUS(STATE)        (((STATE) == LOCK) || ((STATE) == UNLOCK))

/**
  * ����  FLASH CheckSum������ݽṹ��
  */
typedef union CheckSumStruct
{
    uint32_t m_ResultWord[4];     /* CheckSum��128λ������ַ��ʡ� */
    uint32_t m_ResultShort[8];    /* CheckSum��128λ��������ַ��ʡ� */
    uint32_t m_ResultByte[16];    /* CheckSum��128λ������ֽڷ��ʡ� */
}FLASH_CheckSumResult;

/**
  * ����  FLASH�����Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_Mode;                  /* ���ģʽ��
                                         ȡֵ�ꡰFLASH ���ģʽ���е�һ���� */
    uint32_t m_Zone;                  /* �������
                                         ȡֵ�ꡰFLASH ��������е�һ���� */
    uint32_t m_Addr;                  /* ��̵�ַ��
                                         ȡֵΪ0x0~0xFFFFF��Ӳ�����Ե�2λ�� */
    uint32_t m_WriteSize;             /* ��̳��ȣ���λ��˫��(64λ)
                                         ȡֵΪ1~63�� */
    uint32_t * m_Data;                /* �������ָ�룬
                                         ָ���д���ݡ� */
}FLASH_ProgramTypeDef;

/**
  * FLASH ���ģʽ
  */
#define FLASH_PROGRAM_WORD              ((uint32_t)0x15)
#define FLASH_PROGRAM_HALF_PAGE         ((uint32_t)0x05)
#define CHECK_FLASH_PROGRAM_MODE(MODE)  (((MODE) == FLASH_PROGRAM_WORD) \
                                      || ((MODE) == FLASH_PROGRAM_HALF_PAGE))

/**
  * FLASH �������
  */
#define FLASH_PROGRAM_CODE              ((uint32_t)0)
#define FLASH_PROGRAM_CFG           ((uint32_t)1)
#define CHECK_FLASH_PROGRAM_ZONE(ZONE)  (((ZONE) == FLASH_PROGRAM_CODE) \
                                      || ((ZONE) == FLASH_PROGRAM_CFG))

/**
  * FLASH��Ϣ��ѡ��
  */
#define FLASH_NVM_CODE_ZONE             ((uint32_t)0<<FLASH_ISPCON0_IFEN_POS)
#define FLASH_NVM_INFORMATION_ZONE      ((uint32_t)1<<FLASH_ISPCON0_IFEN_POS)
#define CHECK_FLASH_NVM_ZONE(SEL)       (((SEL) == FLASH_NVM_CODE_ZONE) \
                                      || ((SEL) == FLASH_NVM_INFORMATION_ZONE))

/**
  * FLASHģʽ
  */
#define FLASH_MODE_NORMAL               ((uint32_t)0<<FLASH_ISPCON0_STANDBY1_POS)
#define FLASH_MODE_STANDBY1             ((uint32_t)1<<FLASH_ISPCON0_STANDBY1_POS)
#define FLASH_MODE_STANDBY2             ((uint32_t)2<<FLASH_ISPCON0_STANDBY1_POS)
#define FLASH_MODE_STANDBY1_STANDBY2    ((uint32_t)3<<FLASH_ISPCON0_STANDBY1_POS)
#define CHECK_FLASH_MODE(SEL)           (((SEL) == FLASH_MODE_NORMAL) \
                                      || ((SEL) == FLASH_MODE_STANDBY1) \
                                      || ((SEL) == FLASH_MODE_STANDBY2) \
                                      || ((SEL) == FLASH_MODE_STANDBY1_STANDBY2))

/**
  * FLASH-IPѡ��
  */
#define FLASH_IP1                       ((uint32_t)0<<FLASH_ISPCON1_IPSEL_POS)
#define CHECK_FLASH_IP(SEL)             (((SEL) == FLASH_IP1))

/**
  * FLASH��ģʽ
  */
#define FLASH_READ_MODE_NORMAL          ((uint32_t)0<<FLASH_ISPCON1_RECALLEN_POS)
#define FLASH_READ_MODE_RECALL          ((uint32_t)1<<FLASH_ISPCON1_RECALLEN_POS)
#define CHECK_FLASH_READ_MODE(SEL)      (((SEL) == FLASH_READ_MODE_NORMAL) \
                                      || ((SEL) == FLASH_READ_MODE_RECALL))

/**
  * FLASH д�������
  */
#define CHECK_FLASH_WRITE_SIZE(SIZE)    (((uint32_t)(SIZE) >> 6) == 0)

/**
  * FLASH��������
  */
#define CHECK_FLASH_PERIOD(NUM)         (((uint32_t)(NUM) >> 4) == 0)

/**
  * FLASH��̺��в��ڼ�ĵ�ַ
  */
#define CHECK_FLASH_ADDR_20BITS(ADDR)   (((uint32_t)(ADDR) >> 20) == 0)
#define CHECK_FLASH_ADDR_13BITS(ADDR)   (((uint32_t)(ADDR) >> 13) == 0)

/**
  * FLASH����ѡ��
  */
#define FLASH_PROGRAM_CMD_WORD          ((uint32_t)0x15<<FLASH_ISPCMD_CMD0_POS)
#define FLASH_PROGRAM_CMD_ALL_CODE      ((uint32_t)0x0A<<FLASH_ISPCMD_CMD0_POS)
#define FLASH_PROGRAM_CMD_PAGE          ((uint32_t)0x1B<<FLASH_ISPCMD_CMD0_POS)
#define FLASH_PROGRAM_CMD_HALF_PAGE     ((uint32_t)0x05<<FLASH_ISPCMD_CMD0_POS)
#define CHECK_FLASH_PROGRAM_CMD(CMD)    (((CMD) == FLASH_PROGRAM_CMD_WORD) \
                                      || ((CMD) == FLASH_PROGRAM_CMD_ALL_CODE) \
                                      || ((CMD) == FLASH_PROGRAM_CMD_PAGE) \
                                      || ((CMD) == FLASH_PROGRAM_CMD_HALF_PAGE))

/**
  * FLASH ����ģʽ
  */
#define FLASH_WIPE_CODE_PAGE            ((uint32_t)0)
#define FLASH_WIPE_CFG_PAGE             ((uint32_t)1)
#define FLASH_WIPE_CODE_ALL             ((uint32_t)2)
#define CHECK_FLASH_WIPE_MODE(MODE)     (((MODE) == FLASH_WIPE_CODE_PAGE) \
                                      || ((MODE) == FLASH_WIPE_CFG_PAGE) \
                                      || ((MODE) == FLASH_WIPE_CODE_ALL))


/* FLASH����洢��(FLASH)�������ú�������**************************/
LockStatus FLASH_Get_NonVolatile_Memory_Unlock_Status_RAM (void);
void FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM (void);
LockStatus FLASH_Get_Flash_Unlock_Status_RAM (void);
void FLASH_Clear_Flash_Unlock_Status_RAM (void);
LockStatus FLASH_Get_Config_Unlock_Status_RAM (void);
void FLASH_Clear_Config_Unlock_Status_RAM (void);
void FLASH_Data_Write_Enable_RAM (FunctionalState NewState);
void FLASH_Zone_Config_RAM (uint32_t ZoneSelect);
void FLASH_Standby_Mode_Config_RAM (uint32_t ModeSelect);
void FLASH_IP_Config_RAM (uint32_t FlashIPSelect);
void FLASH_Read_Mode_Config_RAM (uint32_t ReadMode);
void FLASH_Calibration_Updata_Enable_RAM (FunctionalState NewState);
void FLASH_Information_Zone_Wipe_Unlock_Config_RAM (LockStatus NewState);
void FLASH_Half_Page_Write_Size_Config_RAM (uint32_t WriteSize);
void FLASH_Program_Cmd_Config_RAM (uint32_t CmdSelect);
void FLASH_Executive_Cmd_RAM (void);
void FLASH_NonVolatile_Memory_ECC_Enable_RAM (FunctionalState NewState);
void FLASH_Linear_Prefetch_Enable_RAM (FunctionalState NewState);
void FLASH_Period_Number_Config_RAM (uint32_t PeriodNum);
void FLASH_Program_Addr_Config_RAM (uint32_t ProgramAddr);
FlagStatus FLASH_Get_Program_Status_RAM (void);
FlagStatus FLASH_Get_Wipe_Status_RAM (void);
FlagStatus FLASH_Get_Compute_Complete_Status_RAM (void);
void FLASH_Clear_Compute_Complete_Status_RAM (void);

#if _CLOSE_SERVICE_
FlagStatus FLASH_Get_CFG_Error_Flag_RAM (void);
void FLASH_Clear_CFG_Error_Flag_RAM (void);
#endif /* _CLOSE_SERVICE_ */

void FLASH_CheckSum_Addr_Config_RAM(uint32_t StartAddr, uint32_t StopAddr);
void FLASH_Start_SIG_Compute_Enable_RAM (FunctionalState NewState);
void FLASH_Get_CheckSum_Result_RAM (FLASH_CheckSumResult* CheckSumStruct);
/* FLASH����洢��(FLASH)��̹��ܺ�������**************************/

void FLASH_Clear_NonVolatile_Memory_Unlock_Status (void);
void FLASH_Clear_Flash_Unlock_Status (void);
void FLASH_Clear_Config_Unlock_Status (void);
void FLASH_Zone_Config(uint32_t ZoneSelect);
void FLASH_Executive_Cmd(void);
FlagStatus FLASH_Get_Program_Status (void);
FlagStatus FLASH_Get_Wipe_Status (void);


/* ָ���Ĵ���(CACHE)��̹��ܺ�������**************************/
FlagStatus CACHE_Get_CACHE_ECC_Error_Flag(void);
FlagStatus CACHE_Get_FLASH_ECC_Error_Flag(void);
void CACHE_RAM_Check_ECC_Error_INT_Enable(FunctionalState NewState);
void CACHE_CACHE_Check_ECC_Error_INT_Enable(FunctionalState NewState);
void CACHE_FLASH_Check_ECC_Error_INT_Enable(FunctionalState NewState);
void CACHE_CACHE_Check_ECC_Enable(FunctionalState NewState);
void CACHE_Instruction_CACHE_Read_2Row_Enable(FunctionalState NewState);
void CACHE_Instruction_CACHE_Write_2Row_Enable(FunctionalState NewState);
void CACHE_CACHE_Reset_Enable(FunctionalState NewState);
void CACHE_CACHE_Enable(FunctionalState NewState);



#endif /* KF32A1x6_FLASH_H_ */