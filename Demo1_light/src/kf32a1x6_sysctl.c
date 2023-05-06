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
  *   ##### 系统控制(SYSCTL)功能配置函数 #####
  */


/* 系统控制私有定义 ----------------------------------------------------*/
/* SYS_ARCTL寄存器写操作ARKEY编码 */
#define SYS_ARCTL_WRITE_CTL             ((uint32_t)0x05FA \
                                      << SYS_ARCTL_ARKEY0_POS)

/**
  * 描述  获取状态字V位溢出标志。
  * 输入  无。
  * 返回  1:溢出；0:非溢出。
  */
FlagStatus SYSCTL_Get_V_Flag (void)
{
    /*---------------- 读取SYS_PSW寄存器V位 ----------------*/

    if(SYS_PSW & SYS_PSW_V)
    {
        /* 溢出 */
        return SET;
    }
    else
    {
        /* 非溢出 */
        return RESET;
    }
}

/**
  * 描述  获取状态字C位进位或借位标志。
  * 输入  无。
  * 返回  1:加法有进位或减法无借位；0:加法无进位或减法有借位。
  */
FlagStatus SYSCTL_Get_C_Flag (void)
{
    /*---------------- 读取SYS_PSW寄存器C位 ----------------*/
    if (SYS_PSW & SYS_PSW_C)
    {
        /* 加法有进位或减法无借位 */
        return SET;
    }
    else
    {
        /* 加法无进位或减法有借位 */
        return RESET;
    }
}

/**
  * 描述  获取状态字Z位零值标志。
  * 输入  无。
  * 返回  1:零值；0:非零值。
  */
FlagStatus SYSCTL_Get_Z_Flag (void)
{
    /*---------------- 读取SYS_PSW寄存器Z位 ----------------*/
    if (SYS_PSW & SYS_PSW_Z)
    {
        /* 零值 */
        return SET;
    }
    else
    {
        /* 非零值 */
        return RESET;
    }
}

/**
  * 描述  获取状态字N位负值标志。
  * 输入  无。
  * 返回  1:负值；0:非负值。
  */
FlagStatus SYSCTL_Get_N_Flag (void)
{
    /*---------------- 读取SYS_PSW寄存器N位 ----------------*/
    if (SYS_PSW & SYS_PSW_N)
    {
        /* 负值 */
        return SET;
    }
    else
    {
        /* 非负值 */
        return RESET;
    }
}

/**
  * 描述  设置状态字V位溢出标志。
  * 输入  NewState: 状态字V位溢出标志，
  *                 取值范围为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_Set_V_Flag (FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 设置SYS_PSW寄存器V位 ----------------*/
    if (NewState != FALSE)
    {
        /* 设置溢出标志 */
        SFR_SET_BIT_ASM(SYS_PSW, SYS_PSW_V_POS);
    }
    else
    {
        /* 清零溢出标志 */
        SFR_CLR_BIT_ASM(SYS_PSW, SYS_PSW_V_POS);
    }
}

/**
  * 描述  设置状态字C位溢出标志。
  * 输入  NewState: 状态字C位进位或借位标志，
  *                 取值范围为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_Set_C_Flag (FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 设置SYS_PSW寄存器C位 ----------------*/
    if (NewState != FALSE)
    {
        /* 设置进位或借位标志 */
        SFR_SET_BIT_ASM(SYS_PSW, SYS_PSW_C_POS);
    }
    else
    {
        /* 清零进位或借位标志 */
        SFR_CLR_BIT_ASM(SYS_PSW, SYS_PSW_C_POS);
    }
}

/**
  * 描述  设置状态字Z位溢出标志。
  * 输入  NewState: 状态字Z位进位或借位标志，
  *                 取值范围为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_Set_Z_Flag (FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 设置SYS_PSW寄存器Z位 ----------------*/
    if (NewState != FALSE)
    {
        /* 设置进位或借位标志 */
        SFR_SET_BIT_ASM(SYS_PSW, SYS_PSW_Z_POS);
    }
    else
    {
        /* 清零进位或借位标志 */
        SFR_CLR_BIT_ASM(SYS_PSW, SYS_PSW_Z_POS);
    }
}
/**
  * 描述  设置状态字N位负值标志。
  * 输入  NewState: 状态字N位负值或非负值标志，
  *                 取值范围为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_Set_N_Flag (FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 设置SYS_PSW寄存器Z位 ----------------*/
    if (NewState != FALSE)
    {
        /* 设置进位或借位标志 */
        SFR_SET_BIT_ASM(SYS_PSW, SYS_PSW_N_POS);
    }
    else
    {
        /* 清零进位或借位标志 */
        SFR_CLR_BIT_ASM(SYS_PSW, SYS_PSW_N_POS);
    }
}

/**
  * 描述  设置中断处理返回进入休眠模式使能。
  * 输入  NewState: 中断处理返回进入休眠模式使能状态，取值为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_Sleep_On_Exit_Enable (FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 设置SYS_MCTL寄存器SLEEPONEXIT位 ----------------*/
    if (NewState != FALSE)
    {
        /* 使能中断返回时进入休眠模式 */
        SFR_SET_BIT_ASM(SYS_MCTL, SYS_MCTL_SLEEPONEXIT_POS);
    }
    else
    {
        /* 禁止中断返回时进入休眠模式 */
        SFR_CLR_BIT_ASM(SYS_MCTL, SYS_MCTL_SLEEPONEXIT_POS);
    }
}

/**
  * 描述  设置唤醒模式选择。
  * 输入  NewState: 任意中断唤醒CPU使能状态，取值为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_Interrupt_Awake_Enable (FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 设置SYS_MCTL寄存器SLPONMOD位 ----------------*/
    if (NewState != FALSE)
    {
        /* 任意挂起的中断都能唤醒CPU */
        SFR_SET_BIT_ASM(SYS_MCTL, SYS_MCTL_SLPONMOD_POS);
    }
    else
    {
        /* 只有当挂起的中断优先级比当前优先级高时才能唤醒CPU */
        SFR_CLR_BIT_ASM(SYS_MCTL, SYS_MCTL_SLPONMOD_POS);
    }
}

/**
  * 描述  获取当前中断自动堆栈的对齐方式。
  * 输入  无。
  * 返回  1:双字对齐使能；0:双字对齐未使能。
  */
FlagStatus SYSCTL_Stack_Align_State (void)
{
    /*---------------- 读取SYS_MCTL寄存器STACKALIGN位 ----------------*/
    if (SYS_MCTL & SYS_MCTL_STACKALIGN)
    {
        /* 双字对齐使能 */
        return SET;
    }
    else
    {
        /* 双字对齐未使能 */
        return RESET;
    }
}

/**
  * 描述  设置超级用户控制。
  * 输入  NewState: 选择超级用户标志，取值为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_Super_User_Config (FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 设置SYS_MCTL寄存器SUSTA位 ----------------*/
    if (NewState != FALSE)
    {
        /* 超级用户模式 */
        SFR_SET_BIT_ASM(SYS_MCTL, SYS_MCTL_SUSTA_POS);
    }
    else
    {
        /* 用户模式 */
        SFR_CLR_BIT_ASM(SYS_MCTL, SYS_MCTL_SUSTA_POS);
    }
}

/**
  * 描述  获取当前有效堆栈指针状态标志。
  * 输入  无。
  * 返回  1:PSP是当前的堆栈指针；0:MSP是当前的堆栈指针。
  */
FlagStatus SYSCTL_Stack_Pointer_State (void)
{
    /*---------------- 读取SYS_MCTL寄存器SPSEL位 ----------------*/
    if (SYS_MCTL & SYS_MCTL_SPSEL)
    {
        /* PSP是当前的堆栈指针 */
        return SET;
    }
    else
    {
        /* MSP是当前的堆栈指针 */
        return RESET;
    }
}

/**
  * 描述  设置当前有效堆栈指针。
  * 输入  PresentSP: 当前有效堆栈指针，取值为：
  *                    SYSCTL_SP_IS_MSP: MSP是当前的堆栈指针
  *                    SYSCTL_SP_IS_PSP: PSP是当前的堆栈指针
  * 返回  无。
  */
void SYSCTL_Stack_Pointer_Config (uint32_t PresentSP)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_SYSCTL_SP(PresentSP));

    /*------------------ 设置SYS_MCTL寄存器SPSEL位 -----------------*/
    SYS_MCTL = SFR_Config (SYS_MCTL, ~SYS_MCTL_SPSEL, PresentSP);
}

/**
  * 描述  设置异常活动信息复位请求。
  * 输入  NewState: 异常活动信息复位请求，取值为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_Exception_Reset_Enable (FunctionalState NewState)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*------------------ 设置SYS_ARCTL寄存器VECTRST位 -----------------*/
    tmpreg = SYS_ARCTL_WRITE_CTL | \
            ((uint32_t)NewState << SYS_ARCTL_VECTRST_POS);
    SYS_ARCTL = SFR_Config (SYS_ARCTL,
                        ~(SYS_ARCTL_VECTRST | SYS_ARCTL_ARKEY),
                        tmpreg);
}

/**
  * 描述  设置系统复位请求。
  * 输入  NewState: 系统复位请求，取值为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_System_Reset_Enable (FunctionalState NewState)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*------------------ 设置SYS_ARCTL寄存器SYSTEMRST位 -----------------*/
    tmpreg = SYS_ARCTL_WRITE_CTL | \
            ((uint32_t)NewState << SYS_ARCTL_SYSTEMRST_POS);
    SYS_ARCTL = SFR_Config (SYS_ARCTL,
                        ~(SYS_ARCTL_SYSTEMRST | SYS_ARCTL_ARKEY),
                        tmpreg);
}

/**
  * 描述  清零内核DMA控制状态。
  * 输入  NewState: 清零内核DMA控制状态，取值为：TRUE 或 FALSE。
  * 返回  无。
  */
void SYSCTL_Core_Dma_Clear_Enable(FunctionalState NewState)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)NewState << SYS_ARCTL_CDMAR_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CDMAR | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * 描述  内核 DMA与 CPU读写冲突仲裁模式选择。
  * 输入  Mode: 仲裁模式选择，取值为：
  * 				SYSCTL_FAST_MODE: 高速模式
  * 				SYSCTL_EFFICIENT_MODE： 高效模式
  * 返回  无。
  */
void SYSCTL_Cdmaam_Config(uint32_t Mode)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_SYSCTL_MODE(Mode));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)Mode << SYS_ARCTL_CDMAAM_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CDMAAM | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * 描述  CORE 读写外设长周期模式控制。
  * 输入  Cycle: 仲裁模式选择，取值为：
  * 				SYSCTL_READ_PER_2CYCLE: CORE 对外设读/写分别为 2 周期，对 RAM 读/写为分别 1 周期
  * 				SYSCTL_READ_PER_1CYCLE： CORE 对外设所有区域读/写分别为 1 个周期
  * 返回  无。
  */
void SYSCTL_RW_Per_Cycle_Config(uint32_t Cycle)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_SYSCTL_RW_PER_CYCLE(Cycle));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)Cycle << SYS_ARCTL_CRWDC_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CRWDC | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * 描述  CORE 和 DMA 读写 BKP 域长周期模式控制。
  * 输入  Cycle: CORE 和 DMA 读写 BKP 域长周期模式控制，取值为：
  * 				SYSCTL_RW_DMA_4CYCLE: CORE 和 DMA 对 BKP 域读/写分别为 4 个周期
  * 				SYSCTL_RW_DMA_1CYCLE： CORE 和 DMA 对 BKP 域读/写分别为 1 个周期
  * 返回  无。
  */
void SYSCTL_RW_Dma_Cycle_Config(uint32_t Cycle)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_SYSCTL_RW_DMA_CYCLE(Cycle));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)Cycle << SYS_ARCTL_CDMADC_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CDMADC | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * 描述 CORE 和 DMA 读写 BKP 域加长周期模式控制。
  * 输入  Cycle 取值为：
  * 				SYSCTL_RW_DMA_CDMADC: CORE 和 DMA 对 BKP 读周期由 CDMADC 控制
  * 				SYSCTL_RW_DMA_16CYCLE： CORE 和 DMA 对 BKP 域读/写分别为 16 个周期
  * 				SYSCTL_RW_DMA_32CYCLE: CORE 和 DMA 对 BKP 域读/写分别为 32 个周期
  * 				SYSCTL_RW_DMA_64CYCLE: CORE 和 DMA 对 BKP 域读/写分别为 64 个周期
  * 返回  无。
  */
void SYSCTL_RW_Dma_Long_Cycle_Config(uint32_t Cycle)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_SYSCTL_RW_DMA_LONG_CYCLE(Cycle));

    tmpreg = SYS_ARCTL_WRITE_CTL | ((uint32_t)Cycle << SYS_ARCTL_CDMALDC0_POS);
    SYS_ARCTL = SFR_Config(SYS_ARCTL, ~(SYS_ARCTL_CDMALDC | SYS_ARCTL_ARKEY), tmpreg);
}

/**
  * 描述  中断向量表重映射地址配置。
  * 输入  VectorOffset: 中断向量表重映射地址，取值32位数据，低两位硬件忽略。
  * 返回  无。
  */
void SYSCTL_Vector_Offset_Config (uint32_t VectorOffset)
{
	uint32_t tmpreg;
    /*---------------- 设置SYS_VECTOFF寄存器TBLOFF位 ----------------*/
	tmpreg = VectorOffset << SYS_VECTOFF_TBLOFF0_POS;
    SYS_VECTOFF = SFR_Config (SYS_VECTOFF,
                      ~(SYS_VECTOFF_TBLOFF),
                      tmpreg);
}

/**
  * 描述  配置RAM空间长度，指示RAM空间结束地址。
  * 输入  RamSpace: RAM空间长度，取值为26位有效数值。
  * 返回  无。
  */
void SYSCTL_Ram_Space_Config (uint32_t RamSpace)
{
	uint32_t tmpreg;
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_RAM_SPACE(RamSpace));

    /*---------------- 配置SYS_RAMSPA寄存器RAMSPA位 ----------------*/
    tmpreg = RamSpace << SYS_RAMSPA_RAMSPA0_POS;
    SYS_RAMSPA = SFR_Config (SYS_RAMSPA,
                      ~SYS_RAMSPA_RAMSPA,
                      tmpreg);
}

/**
  * 描述  配置FLASH开始512字节空间映射控制。
  * 输入  MemCtl: 映射控制，取值范围为:
  *                 SYSCTL_FLASH_REMAP_FOR_ROM: 为ROM的映射
  *                 SYSCTL_FLASH_REMAP_FOR_RAM: 为RAM的映射
  *                 SYSCTL_FLASH_REMAP_FOR_FLASH: 为FLASH的映射
  *                 SYSCTL_FLASH_REMAP_STOP_CPU: 停止CPU运行
  * 返回  无。
  */
void SYSCTL_Flash_Start_Remap_Config (uint32_t MemCtl)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_SYSCTL_FLASH_REMAP(MemCtl));

    /*---------------- 配置SYS_MEMCTL寄存器MEMM位 ----------------*/
    SYS_MEMCTL = SFR_Config (SYS_MEMCTL, ~SYS_MEMCTL_MEMM, MemCtl);
}

/**
  * 描述  配置SYS_MSPSPA堆栈指针上限。
  * 输入   Mspspah: 堆栈指针 MSP 空间上限值指示，取值范围为:0~0xFFFF
  * 返回  无。
  */
void SYSCTL_MSPSPAH_Threshold_Config (uint16_t Mspspah)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_SPA_Threshold(Mspspah));

    SYS_MSPSPA = SFR_Config(SYS_MSPSPA, ~(SYS_MSPSPA_MSPSPAH), Mspspah << SYS_MSPSPA_MSPSPAH0_POS);
}

/**
  * 描述  配置SYS_MSPSPA堆栈指针 MSP空间指示寄存器。
  * 输入   Mspspal: 堆栈指针 MSP 空下限值指示，取值范围为:0~0xFFFF
  * 返回  无。
  */
void SYSCTL_MSPSPAL_Threshold_Config (uint16_t Mspspal)
{
    /* 参数校验 */
	CHECK_RESTRICTION(CHECK_SPA_Threshold(Mspspal));

    SYS_MSPSPA = SFR_Config(SYS_MSPSPA, ~(SYS_MSPSPA_MSPSPAL), Mspspal << SYS_MSPSPA_MSPSPAL0_POS);
}

/**
  * 描述  配置SYS_PSPSPA堆栈指针上限。
  * 输入   Pspspah: 堆栈指针 PSP 空间上限值指示，取值范围为:0~0xFFFF
  * 返回  无。
  */
void SYSCTL_PSPSPAH_Threshold_Config (uint16_t Pspspah)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_SPA_Threshold(Pspspah));

    SYS_PSPSPA = SFR_Config(SYS_PSPSPA, ~(SYS_PSPSPA_PSPSPAH), Pspspah << SYS_PSPSPA_PSPSPAH0_POS);
}

/**
  * 描述  配置SYS_PSPSPA堆栈指针下限。
  * 输入   Pspspah: 堆栈指针 PSP 空间下限值指示，取值范围为:0~0xFFFF
  * 返回  无。
  */
void SYSCTL_PSPSPAL_Threshold_Config (uint16_t Pspspal)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_SPA_Threshold(Pspspal));

    SYS_PSPSPA = SFR_Config(SYS_PSPSPA, ~(SYS_PSPSPA_PSPSPAL), Pspspal << SYS_PSPSPA_PSPSPAL0_POS);
}

/**
  *   ##### 系统控制(SYSCTL)功能配置函数定义结束 #####
  */
