/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_sysctl.h                              	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V2.0                                          	      *
 *  $Description$     : This file contains the headers of the SYSCTL		  *
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
#ifndef KF32A1x6_SYSCTL_H_
#define KF32A1x6_SYSCTL_H_

#include "kf32a1x6.h"

/**
  * 当前有效堆栈指针选择
  */
#define SYSCTL_SP_IS_MSP                ((uint32_t)0<<SYS_MCTL_SPSEL_POS)
#define SYSCTL_SP_IS_PSP                ((uint32_t)1<<SYS_MCTL_SPSEL_POS)
#define CHECK_SYSCTL_SP(SP)             (((SP) == SYSCTL_SP_IS_MSP) \
                                      || ((SP) == SYSCTL_SP_IS_PSP))

/**
  * 当前有效堆栈指针选择
  */
#define SYSCTL_FAST_MODE                ((uint32_t)0<<SYS_ARCTL_CDMAAM_POS)
#define SYSCTL_EFFICIENT_MODE           ((uint32_t)1<<SYS_ARCTL_CDMAAM_POS)
#define CHECK_SYSCTL_MODE(MODE)         (((MODE) == SYSCTL_FAST_MODE) \
                                      || ((MODE) == SYSCTL_EFFICIENT_MODE))

/**
  * 读写外设长周期模式选择
  */
#define SYSCTL_RW_PER_2CYCLE          ((uint32_t)0<<SYS_ARCTL_CRWDC_POS)
#define SYSCTL_RW_PER_1CYCLE          ((uint32_t)1<<SYS_ARCTL_CRWDC_POS)
#define CHECK_SYSCTL_RW_PER_CYCLE(CYCLE)         (((CYCLE) == SYSCTL_RW_PER_2CYCLE) \
                                      	  	  || ((CYCLE) == SYSCTL_RW_PER_1CYCLE))

/**
  * 读写外设周期模式选择
  */
#define SYSCTL_RW_DMA_4CYCLE          ((uint32_t)0<<SYS_ARCTL_CDMADC_POS)
#define SYSCTL_RW_DMA_1CYCLE          ((uint32_t)1<<SYS_ARCTL_CDMADC_POS)
#define CHECK_SYSCTL_RW_DMA_CYCLE(CYCLE)         (((CYCLE) == SYSCTL_RW_DMA_4CYCLE) \
                                      	  	  || ((CYCLE) == SYSCTL_RW_DMA_1CYCLE))

/**
  * 读写外设长周期模式选择
  */
#define SYSCTL_RW_DMA_CDMADC           ((uint32_t)0<<SYS_ARCTL_CDMALDC0_POS)
#define SYSCTL_RW_DMA_16CYCLE          ((uint32_t)1<<SYS_ARCTL_CDMALDC0_POS)
#define SYSCTL_RW_DMA_32CYCLE          ((uint32_t)2<<SYS_ARCTL_CDMALDC0_POS)
#define SYSCTL_RW_DMA_64CYCLE          ((uint32_t)3<<SYS_ARCTL_CDMALDC0_POS)
#define CHECK_SYSCTL_RW_DMA_LONG_CYCLE(CYCLE)       (((CYCLE) <= SYSCTL_RW_DMA_64CYCLE) \
												  && ((CYCLE) >= SYSCTL_RW_DMA_CDMADC))

/**
  * RAM空间长度
  */
#define CHECK_RAM_SPACE(LENGTH)         ((uint32_t)(LENGTH) <= SYS_RAMSPA_RAMSPA)


/**
  * FLASH开始512字节空间映射控制
  */
#define SYSCTL_FLASH_REMAP_FOR_ROM      ((uint32_t)0 << SYS_MEMCTL_MEMM0_POS)
#define SYSCTL_FLASH_REMAP_FOR_RAM      ((uint32_t)1 << SYS_MEMCTL_MEMM0_POS)
#define SYSCTL_FLASH_REMAP_FOR_FLASH    ((uint32_t)2 << SYS_MEMCTL_MEMM0_POS)
#define SYSCTL_FLASH_REMAP_STOP_CPU     ((uint32_t)3 << SYS_MEMCTL_MEMM0_POS)
#define CHECK_SYSCTL_FLASH_REMAP(CTL)   (((CTL) <= SYSCTL_FLASH_REMAP_STOP_CPU) \
									  && ((CTL) >= SYSCTL_FLASH_REMAP_FOR_ROM))
/**
 * 堆栈指针空间指示寄存器
 * */
#define CHECK_SPA_Threshold(Threshold)	(((Threshold) >> 0x10) == 0x00)


/* 系统控制(SYSCTL)功能配置函数定义*****************************************/
FlagStatus SYSCTL_Get_V_Flag (void);
FlagStatus SYSCTL_Get_C_Flag (void);
FlagStatus SYSCTL_Get_Z_Flag (void);
FlagStatus SYSCTL_Get_N_Flag (void);
void SYSCTL_Set_V_Flag (FunctionalState NewState);
void SYSCTL_Set_C_Flag (FunctionalState NewState);
void SYSCTL_Set_Z_Flag (FunctionalState NewState);
void SYSCTL_Set_N_Flag (FunctionalState NewState);
void SYSCTL_Sleep_On_Exit_Enable (FunctionalState NewState);
void SYSCTL_Interrupt_Awake_Enable (FunctionalState NewState);
FlagStatus SYSCTL_Stack_Align_State (void);
void SYSCTL_Super_User_Config (FunctionalState NewState);
FlagStatus SYSCTL_Stack_Pointer_State (void);
void SYSCTL_Stack_Pointer_Config (uint32_t PresentSP);
void SYSCTL_Exception_Reset_Enable (FunctionalState NewState);
void SYSCTL_System_Reset_Enable (FunctionalState NewState);
void SYSCTL_Core_Dma_Clear_Enable(FunctionalState NewState);
void SYSCTL_Cdmaam_Config(uint32_t Mode);
void SYSCTL_RW_Per_Cycle_Config(uint32_t Cycle);
void SYSCTL_RW_Dma_Cycle_Config(uint32_t Cycle);
void SYSCTL_RW_Dma_Long_Cycle_Config(uint32_t Cycle);
void SYSCTL_Vector_Offset_Config (uint32_t VectorOffset);
void SYSCTL_Ram_Space_Config (uint32_t RamSpace);
void SYSCTL_Flash_Start_Remap_Config (uint32_t MemCtl);
void SYSCTL_MSPSPAH_Threshold_Config (uint16_t Mspspah);
void SYSCTL_MSPSPAL_Threshold_Config (uint16_t Mspspal);
void SYSCTL_PSPSPAH_Threshold_Config (uint16_t Pspspah);
void SYSCTL_PSPSPAL_Threshold_Config (uint16_t Pspspal);

#endif /* KF32A1x6_SYSCTL_H_ */
