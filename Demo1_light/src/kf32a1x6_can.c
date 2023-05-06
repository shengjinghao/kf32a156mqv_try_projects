/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_can.c                                 	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides functions related to the CAN bus   *
 *  					bus (CAN) , including:								  *
 *          			+ CAN Bus(CAN)initialization function                 *
 *          			+ CAN Bus(CAN)function configuration function         *
 *          			+ CAN Bus(CAN)transmit-receive function               *
 *          			+ CAN Bus(CAN)interrupt management function	          *
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

#include "kf32a1x6_can.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"

/**
  *   先初始化RAM区，RAM区全部清零
  */
static void CAN_RAM_ERASE(void)
{
	for(uint16_t i = 0;i< 1024;i++)
	{
		*((uint8_t *)CAN4_RECEIVE_ADDR + i) = 0x00;
	}
}

/**
  *   ##### 控制器局域网总线(CAN)初始化函数 #####
  */
/**
  * 描述  复位CAN外设，使能外设时钟。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  无。
  */
void CAN_Reset(CAN_SFRmap* CANx)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    if(CANx == CAN4_SFR)
    {
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN4RST, TRUE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_CAN4CLKEN, TRUE);//huanglt   clk顺序？？
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN4RST, FALSE);
        CAN_RAM_ERASE();
    }
}

/**
  * 描述  控制器局域网总线(CAN)初始化，该函数会在配置中置一复位模式RSMOD，
  *       但不会在函数结束时清零RSMOD。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       canInitStruct: CAN配置信息结构体。
  * 返回  无。
  */
void CAN_Configuration_With_Reset_Mode(CAN_SFRmap* CANx, CAN_InitTypeDef* canInitStruct)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(canInitStruct->m_Enable));
    CHECK_RESTRICTION(CHECK_CAN_WORK_MODE(canInitStruct->m_Mode));
    CHECK_RESTRICTION(CHECK_CAN_SOURCE(canInitStruct->m_WorkSource));
    CHECK_RESTRICTION(CHECK_CAN_BAUDRATE_PRESET(canInitStruct->m_BaudRate));
    CHECK_RESTRICTION(CHECK_CAN_SYNC_JMP_WIDTH(canInitStruct->m_SyncJumpWidth));
    CHECK_RESTRICTION(CHECK_CAN_TIME_SEGMENT1(canInitStruct->m_TimeSeg1));
    CHECK_RESTRICTION(CHECK_CAN_TIME_SEGMENT2(canInitStruct->m_TimeSeg2));
    CHECK_RESTRICTION(CHECK_CAN_BUS_SAMPLE(canInitStruct->m_BusSample));

    /*---------------- 配置CANx_CTLR寄存器 ----------------*/
    /* 根据结构体成员m_Enable，设置CANEN位域 */
    /* 根据结构体成员m_Mode，设置LBACK和SILENT位域 */
    /* 根据结构体成员m_WorkSource，设置CANCKS位域 */
    /* 配置RSMOD，进入复位模式 */
    tmpreg = ((uint32_t)canInitStruct->m_Enable << CAN_CTLR_CANEN_POS) \
           | canInitStruct->m_Mode \
           | canInitStruct->m_WorkSource \
           | CAN_CTLR_RSMOD;
    CANx->CTLR = SFR_Config (CANx->CTLR, ~CAN_CTLR_INIT_MASK, tmpreg);

    /*---------------- 配置CANx_BRGR寄存器 ----------------*/
    /* 根据结构体成员m_BaudRate，设置CANBRP位域 */
    /* 根据结构体成员m_SyncJumpWidth，设置SJW位域 */
    /* 根据结构体成员m_TimeSeg1，设置TSEG1位域 */
    /* 根据结构体成员m_TimeSeg2，设置TSEG2位域 */
    /* 根据结构体成员m_BusSample，设置SAM位域 */
    tmpreg = ((uint32_t)canInitStruct->m_BaudRate << CAN_BRGR_CANBRP0_POS) \
           | ((uint32_t)canInitStruct->m_SyncJumpWidth << CAN_BRGR_SJW0_POS) \
           | ((uint32_t)canInitStruct->m_TimeSeg1 << CAN_BRGR_TSEG1_0_POS) \
           | ((uint32_t)canInitStruct->m_TimeSeg2 << CAN_BRGR_TSEG2_0_POS) \
           | (canInitStruct->m_BusSample);
    CANx->BRGR = SFR_Config (CANx->BRGR, ~CAN_BRGR_INIT_MASK, tmpreg);
}

/**
  * 描述  初始化CAN配置信息结构体。
  * 输入  canInitStruct: 指向待初始化的结构体指针。
  * 返回  无。
  */
void CAN_Struct_Init (CAN_InitTypeDef* canInitStruct)
{
    /* 初始化 CAN使能选择 */
    canInitStruct->m_Enable = FALSE;

    /* 初始化 CAN工作模式 */
    canInitStruct->m_Mode = CAN_MODE_NORMAL;

    /* 初始化 CAN工作时钟 */
    canInitStruct->m_WorkSource = CAN_SOURCE_SCLK_DIV_2;

    /* 初始化 CAN波特率预设值 */
    canInitStruct->m_BaudRate = 0;

    /* 初始化 CAN同步跳转宽度 */
    canInitStruct->m_SyncJumpWidth = 0;

    /* 初始化 CAN时间段1 */
    canInitStruct->m_TimeSeg1 = 0;

    /* 初始化 CAN时间段2 */
    canInitStruct->m_TimeSeg2 = 0;

    /* 初始化 CAN总线采样次数 */
    canInitStruct->m_BusSample = CAN_BUS_SAMPLE_1_TIME;
}
/**
  *   ##### 控制器局域网总线(CAN)初始化函数定义结束 #####
  */


/**
  *   ##### 控制器局域网总线(CAN)功能配置函数 #####
  */
/**
  * 描述  获取CAN RX信息计数器。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  RX信息计数器，有效值为7位。
  */
uint32_t CAN_Get_Receive_Message_Counter (CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*---------------- 读取CANx_CTLR寄存器CANRMC位 ----------------*/
    tmpreg = CANx->CTLR;
    tmpreg &= CAN_CTLR_CANRMC;
    tmpreg >>= CAN_CTLR_CANRMC0_POS;

    return tmpreg;
}

/**
  * 描述  获取CAN传输事件状态类型。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       Type: CAN传输事件状态类型，取值为:
  *               CAN_BUS_OFF_STATUS: 总线关闭状态
  *               CAN_ERROR_STATUS: 出错状态
  *               CAN_TX_STATUS: 发送状态
  *               CAN_RX_STATUS: 接收状态
  *               CAN_TX_COMPLETE_OFF_STATUS: 发送完毕状态
  *               CAN_TX_BUFFER_STATUS: 发送缓冲器状态
  *               CAN_DATA_OVERFLOW_STATUS: 数据满状态
  *               CAN_RX_BLANK_STATUS: 数据空状态
  * 返回  1: 总线关闭/出错/正在发送/正在接收/发送完毕/CPU可以访问发送缓冲器/
  *          RAM中未读数据满/RAM中有未读信息，
  *       0: 总线开启/无错/发送空闲/接收空闲/发送未完成/CPU不能访问发送缓冲器/
  *          RAM中未读数据未满/RAM中无未读信息。
  */
FlagStatus CAN_Get_Transmit_Status (CAN_SFRmap* CANx, uint32_t Type)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_STATUS(Type));

    /*---------------- 读取CANx_CTLR寄存器对应位 ----------------*/
    tmpreg = CANx->CTLR;

    if (tmpreg & Type)
    {
        /* 状态位为1 */
        return SET;
    }
    else
    {
        /* 状态位为0 */
        return RESET;
    }
}

/**
  * 描述  配置CAN使能。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       NewState: CAN使能状态，取值为TRUE 或 FALSE。
  * 返回  无。
  */
void CAN_Cmd (CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 配置CANx_CTLR寄存器CANEN位 ----------------*/
    if (NewState != FALSE)
    {
        /* CAN使能 */
        SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_CANEN_POS);
    }
    else
    {
        /* CAN禁止 */
        SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_CANEN_POS);
    }
}



/**
  * 描述  配置CAN睡眠模式使能。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       NewState: CAN睡眠模式使能状态，取值为TRUE 或 FALSE。
  * 返回  无。
  */
void CAN_Sleep_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 配置CANx_CTLR寄存器SLEEP位 ----------------*/
    if (NewState != FALSE)
    {
        /* 使能睡眠模式 */
        SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_SLEEP_POS);
    }
    else
    {
        /* 禁止睡眠模式 */
        SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_SLEEP_POS);
    }
}

/**
  * 描述  配置CAN复位模式使能。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       NewState: CAN复位模式使能状态，取值为TRUE 或 FALSE。
  * 返回  无。
  */
void CAN_Reset_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 配置CANx_CTLR寄存器RSMOD位 ----------------*/
    if (NewState != FALSE)
    {
        /* 使能复位模式 */
        SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RSMOD_POS);
    }
    else
    {
        /* 禁止复位模式 */
        SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RSMOD_POS);
    }
}

/**
  * 描述  配置CAN工作模式。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       ModeType: CAN四种模式，取值为:
  *                   CAN_MODE_NORMAL: 禁止安静和回环模式
  *                   CAN_MODE_SILENT: 使能安静模式
  *                   CAN_MODE_LOOPBACK: 使能回环模式
  *                   CAN_MODE_SILENT_LOOPBACK: 使能安静和回环模式
  * 返回  无。
  */
void CAN_Work_Mode_Config (CAN_SFRmap* CANx, uint32_t ModeType)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_WORK_MODE(ModeType));

    /*------------ 配置CANx_CTLR寄存器SILENT和LBACK位 ------------*/
    CANx->CTLR = SFR_Config (CANx->CTLR,
                        ~(CAN_CTLR_SILENT | CAN_CTLR_LBACK),
                        ModeType);
}

/**
  * 描述  配置CAN总线采样次数。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       Times: 总线采样次数，取值为:
  *                CAN_BUS_SAMPLE_1_TIME: 总线采样1次
  *                CAN_BUS_SAMPLE_3_TIMES: 总线采样3次
  * 返回  无。
  */
void CAN_Bus_Sample_Times_Config (CAN_SFRmap* CANx, uint32_t Times)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_BUS_SAMPLE(Times));

    /*---------------- 配置CANx_BRGR寄存器SAM位 ----------------*/
    if (Times != CAN_BUS_SAMPLE_1_TIME)
    {
        /* 总线采样3次 */
        SFR_SET_BIT_ASM(CANx->BRGR, CAN_BRGR_SAM_POS);
    }
    else
    {
        /* 总线采样1次 */
        SFR_CLR_BIT_ASM(CANx->BRGR, CAN_BRGR_SAM_POS);
    }
}





/**
  * 描述  获取CAN邮箱接收指针
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  邮箱接收指针，取值为0~63
  */
uint8_t CAN_Get_Point_Of_RAM_Mailbox(CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    tmpreg = (CANx->RCR & CAN_RCR_RAMMB) >> CAN_RCR_RAMMB0_POS;

    return (uint8_t)tmpreg;
}

/**
  * 描述  获取CAN总线错误信息。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       canErrorStruct: CAN总线错误信息结构体，记录错误信息。
  * 返回  无。
  */
void CAN_Get_Error_Code (CAN_SFRmap* CANx, CAN_ErrorTypeDef* canErrorStruct)
{
    uint32_t tmpreg;
    uint32_t tmpreg1;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(canErrorStruct != (CAN_ErrorTypeDef*)0);

    /*---------------- 读取CANx_RCR寄存器 ----------------*/
    tmpreg = CANx->RCR;

    /*---------------- 获取CANx_RCR寄存器CANERRC位 ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANERRC;
    tmpreg1 >>= CAN_RCR_CANERRC0_POS;
    canErrorStruct->m_ErrorCode = tmpreg1;

    /*---------------- 获取CANx_RCR寄存器CANDIR位 ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANDIR;
    tmpreg1 >>= CAN_RCR_CANDIR_POS;
    canErrorStruct->m_ErrorDirection = tmpreg1;

    /*---------------- 获取CANx_RCR寄存器CANSEG位 ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANSEG;
    tmpreg1 >>= CAN_RCR_CANSEG0_POS;
    canErrorStruct->m_ErrorSegment = tmpreg1;

    /*---------------- 获取CANx_RCR寄存器CANALC位 ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANALC;
    tmpreg1 >>= CAN_RCR_CANALC0_POS;
    canErrorStruct->m_ArbitrationLost = tmpreg1;
}

/**
  * 描述  获取CAN错误报警限制。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  错误报警限制，取值为8位数值。
  */
uint8_t CAN_Get_Error_Warning_Limit (CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*---------------- 读取CANx_EROR寄存器CANEWL位 ----------------*/
    tmpreg = CANx->EROR;

    return (uint8_t)tmpreg;
}

/**
  * 描述  获取CAN发送/接收错误计数器。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       Direction: CAN错误传输方向，取值为：
  *                    CAN_ERROR_AT_TX: 发送错误计数器
  *                    CAN_ERROR_AT_RX: 接收错误计数器
  * 返回  错误计数器，取值为8位数值。
  */
uint8_t CAN_Get_Error_Counter (CAN_SFRmap* CANx, uint32_t Direction)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_ERROR_DIR(Direction));

    /*----------- 读取CANx_EROR寄存器 -----------*/
    tmpreg = CANx->EROR;

    if (Direction != CAN_ERROR_AT_TX)
    {
        /*----------- 读取CANRXE位 -----------*/
        tmpreg &= CAN_EROR_CANRXE;
        tmpreg >>= CAN_EROR_CANRXE0_POS;
    }
    else
    {
        /*----------- 读取CANTXE位 -----------*/
        tmpreg &= CAN_EROR_CANTXE;
        tmpreg >>= CAN_EROR_CANTXE0_POS;
    }

    return (uint8_t)tmpreg;
}

/**
  * 描述  配置CAN错误报警限制。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       ErrorLimit: 错误报警限制，取值为8位有效数值。
  * 返回  无。
  */
void CAN_Error_Warning_Limit_Config (CAN_SFRmap* CANx, uint8_t ErrorLimit)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 配置CANx_EROR寄存器CANEWL位 -------------*/
    tmpreg = ErrorLimit << CAN_EROR_CANEWL0_POS;
    CANx->EROR = SFR_Config (CANx->EROR, ~CAN_EROR_CANEWL, tmpreg);
}

/**
  * 描述  配置CAN发送/接收错误计数器。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       Direction: CAN错误传输方向，取值为：
  *                    CAN_ERROR_AT_TX: 发送错误计数器
  *                    CAN_ERROR_AT_RX: 接收错误计数器
  *       ErrorCounter: 错误计数，取值为8位有效数值。
  * 返回  无。
  */
void CAN_Error_Counter_Config (CAN_SFRmap* CANx,uint32_t Direction, uint8_t ErrorCounter)
{
    uint32_t tmpreg;
    uint32_t tmpmask;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_ERROR_DIR(Direction));

    if (Direction != CAN_ERROR_AT_TX)
    {
        /*----------- 读取CANRXE位 -----------*/
        tmpreg = ErrorCounter << CAN_EROR_CANRXE0_POS;
        tmpmask = CAN_EROR_CANRXE;
    }
    else
    {
        /*----------- 读取CANTXE位 -----------*/
        tmpreg = ErrorCounter << CAN_EROR_CANTXE0_POS;
        tmpmask = CAN_EROR_CANTXE;
    }

    /*------------- 配置CANx_EROR寄存器 -------------*/
    CANx->EROR = SFR_Config (CANx->EROR, ~tmpmask, tmpreg);
}

/**
  * 描述  配置CAN验收代码。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       Acceptance: 验收代码，取值为32位有效数值。
  * 返回  无。
  */
void CAN_Acceptance_Config (CAN_SFRmap* CANx, uint32_t Acceptance)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 配置CANx_ACRR寄存器ACR位 -------------*/
    CANx->ACRR = Acceptance;
}

/**
  * 描述  获取CAN验收代码。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  验收代码，取值为32位有效数值。
  */
uint32_t CAN_Get_Acceptance (CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 读取CANx_ACRR寄存器ACR位 -------------*/
    tmpreg = CANx->ACRR;

    return tmpreg;
}



/**
  *   ##### 控制器局域网总线(CAN)发送接收函数 #####
  */
/**
  * 描述  CAN模块(CAN)发送缓冲配置。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       canInitStruct: CAN模块配置信息结构体指针。
  * 返回  无。
  */
void CAN_Transmit_Message_Configuration (CAN_SFRmap* CANx,CAN_MessageTypeDef* canInitStruct)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_FRAME_FORMAT(canInitStruct->m_FrameFormat));
    CHECK_RESTRICTION(CHECK_CAN_REMOTE_REQUEST(canInitStruct->m_RemoteTransmit));
    CHECK_RESTRICTION(CHECK_CAN_DATA_LENGTH(canInitStruct->m_DataLength));
    if(canInitStruct->m_RemoteTransmit == CAN_REMOTE_FRAME)
    {
    	return;
    }else
    {
        /*---------------- 设置CANx_INFR寄存器 ----------------*/
        /* 根据结构体成员m_FrameFormat，设置IDE位域 */
        /* 根据结构体成员m_RemoteTransmit，设置RTR位域 */
        /* 根据结构体成员m_DataLength，设置DLC位域 */
        tmpreg = (canInitStruct->m_FrameFormat << CAN_INFR_IDE_POS) \
               | (canInitStruct->m_RemoteTransmit << CAN_INFR_RTR_POS) \
               | (canInitStruct->m_DataLength << CAN_INFR_DLC0_POS);
        CANx->INFR = SFR_Config (CANx->INFR, ~CAN_INFR_INIT_MASK, tmpreg);

        /*----------- 设置CANx_TX0R/CANx_TX1R/CANx_TX2R寄存器 -----------*/
        /* 根据结构体成员m_FrameFormat，选择帧格式 */
        /* 根据结构体成员m_StandardID，设置IDx位域 */
        /* 根据结构体成员m_ExtendedID，设置IDx位域 */
        /* 根据结构体成员m_Data，设置CANTXDTx位域 */
        if (canInitStruct->m_FrameFormat != CAN_FRAME_FORMAT_EFF)
        {
            /*----------- 设置CANx_TX0R寄存器 -----------*/
            tmpreg = (canInitStruct->m_Can_ID << CAN_TX0R_ID18_POS) \
                   | ((uint32_t)canInitStruct->m_Data[0] << CAN_TX0R_CANTX0_8_POS) \
                   | ((uint32_t)canInitStruct->m_Data[1] << CAN_TX0R_CANTX0_0_POS);
            CANx->TX0R = SFR_Config (CANx->TX0R, ~CAN_TX0R_SFF_MASK, tmpreg);

            /*----------- 设置CANx_TX1R寄存器 -----------*/
            tmpreg = ((uint32_t)canInitStruct->m_Data[2] << CAN_TX1R_CANTX1_24_POS) \
                   | ((uint32_t)canInitStruct->m_Data[3] << CAN_TX1R_CANTX1_16_POS) \
                   | ((uint32_t)canInitStruct->m_Data[4] << CAN_TX1R_CANTX1_8_POS) \
                   | ((uint32_t)canInitStruct->m_Data[5] << CAN_TX1R_CANTX1_0_POS);
            CANx->TX1R = tmpreg;

            /*----------- 设置CANx_TX2R寄存器 -----------*/
            tmpreg = ((uint32_t)canInitStruct->m_Data[6] << CAN_TX2R_CANTX2_24_POS) \
                   | ((uint32_t)canInitStruct->m_Data[7] << CAN_TX2R_CANTX2_16_POS);
            CANx->TX2R = SFR_Config (CANx->TX2R, ~CAN_TX2R_SFF_MASK, tmpreg);
        }
        else
        {
            /*----------- 设置CANx_TX0R寄存器 -----------*/
            tmpreg = canInitStruct->m_Can_ID << CAN_TX0R_ID0_POS;
            CANx->TX0R = SFR_Config (CANx->TX0R, ~CAN_TX0R_EFF_MASK, tmpreg);

            /*----------- 设置CANx_TX1R寄存器 -----------*/
            tmpreg = ((uint32_t)canInitStruct->m_Data[0] << CAN_TX1R_CANTX1_24_POS) \
                   | ((uint32_t)canInitStruct->m_Data[1] << CAN_TX1R_CANTX1_16_POS) \
                   | ((uint32_t)canInitStruct->m_Data[2] << CAN_TX1R_CANTX1_8_POS) \
                   | ((uint32_t)canInitStruct->m_Data[3] << CAN_TX1R_CANTX1_0_POS);
            CANx->TX1R = tmpreg;

            /*----------- 设置CANx_TX2R寄存器 -----------*/
            tmpreg = ((uint32_t)canInitStruct->m_Data[4] << CAN_TX2R_CANTX2_24_POS) \
                   | ((uint32_t)canInitStruct->m_Data[5] << CAN_TX2R_CANTX2_16_POS) \
                   | ((uint32_t)canInitStruct->m_Data[6] << CAN_TX2R_CANTX2_8_POS) \
                   | ((uint32_t)canInitStruct->m_Data[7] << CAN_TX2R_CANTX2_0_POS);
            CANx->TX2R = tmpreg;
        }
    }
}


/**
  * 描述  配置CAN验收屏蔽。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       Acceptance: 验收屏蔽，取值为32位有效数值。
  * 返回  无。
  */
void CAN_Acceptance_Mask_Config (CAN_SFRmap* CANx, uint32_t Acceptance)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 配置CANx_MSKR寄存器MSK位 -------------*/
    CANx->MSKR = Acceptance;
}

/**
  * 描述  获取CAN验收屏蔽。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  验收屏蔽，取值为32位有效数值。
  */
uint32_t CAN_Get_Acceptance_Mask (CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 读取CANx_MSKR寄存器MSK位 -------------*/
    tmpreg = CANx->MSKR;

    return tmpreg;
}

/**
  * 描述  配置验收滤波器扩展使能。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 	 NewState： TRUE/FALSE
  * 返回  无。
  */
void CAN_Expand_Acceptance_Enable(CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*------------- 配置CANx_CTLR寄存器FILTEREXT位 -------------*/
    CANx->CTLR = SFR_Config(CANx->CTLR, ~CAN_CTLR_FILTEREXT, NewState<<CAN_CTLR_FILTEREXT_POS);
}

/**
  * 描述  配置CAN验收代码扩展。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 	  FILTER_Group： CAN_Filter_G1~CAN_Filter_G8。
  *       Acceptance: 验收代码，取值为32位有效数值。
  * 返回  无。
  */
void CAN_Acceptance_FILTER_Config (CAN_SFRmap* CANx, uint8_t FILTER_Group, uint32_t Acceptance)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 配置CAN验收滤波器组扩展 -------------*/
    *((uint32_t *)(CAN4_FILTER_ADDR+FILTER_Group*0x08)) = Acceptance;
}

/**
  * 描述  获取CAN验收代码扩展。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 	 FILTER_Group： CAN_Filter_G1~CAN_Filter_G8。
  * 返回  验收代码，取值为32位有效数值。
  */
uint32_t CAN_Get_Acceptance_FILTER (CAN_SFRmap* CANx, uint8_t FILTER_Group)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 读取CAN验收滤波器组扩展  -------------*/
    tmpreg = *((uint32_t *)(CAN4_FILTER_ADDR+FILTER_Group*0x08));

    return tmpreg;
}

/**
  * 描述  配置CAN验收屏蔽扩展。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 	  FILTER_Group： CAN_Filter_G1~CAN_Filter_G8。
  *       Acceptance: 验收屏蔽，取值为32位有效数值。
  * 返回  无。
  */
void CAN_Acceptance_FILTER_Mask_Config (CAN_SFRmap* CANx, uint8_t FILTER_Group, uint32_t Acceptance)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 配置CAN验收滤波器组扩展 -------------*/
    *((uint32_t *)(CAN4_FILTER_ADDR+FILTER_Group*0x08+0x04)) = Acceptance;
}

/**
  * 描述  获取CAN验收屏蔽扩展。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 	 FILTER_Group： CAN_Filter_G1~CAN_Filter_G8。
  * 返回  验收屏蔽，取值为32位有效数值。
  */
uint32_t CAN_Get_Acceptance_FILTER_Mask (CAN_SFRmap* CANx, uint8_t FILTER_Group)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 读取CAN验收滤波器组扩展  -------------*/
    tmpreg = *((uint32_t *)(CAN4_FILTER_ADDR+FILTER_Group*0x08+0x04));

    return tmpreg;
}

/**
  * 描述  清零RX信息计数器。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回    :清除状态。
  */
RetStatus CAN_Clear_CANRMC(CAN_SFRmap* CANx)
{
	volatile uint32_t wait_flag = 0x0000;
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 配置CANx_CTLR寄存器RELRXALL位 -------------*/
    SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RELRXALL_POS);
    while((!((CANx->CTLR & CAN_CTLR_RELRXALL)>>CAN_CTLR_RELRXALL_POS))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RELRXALL_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}



/**
  * 描述  配置BUS OFF时自动恢复使能。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 	 NewState： TRUE/FALSE
  * 返回  无。
  */
void CAN_BUSS_OFF_Auto_Reset_Enable(CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*------------- 配置CANx_CTLR寄存器BOFFRXE位 -------------*/
    CANx->CTLR = SFR_Config(CANx->CTLR, ~CAN_CTLR_BOFFREC, NewState<<CAN_CTLR_BOFFREC_POS);
}

/**
  * 描述  配置回环模式选择。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 	 LB_MODE:  CAN_Extern_LoopBack:外部回环
  * 	 		   CAN_Intern_LoopBack:内部回环
  * 返回  无。
  */
void CAN_LoopBack_Mode_Select(CAN_SFRmap* CANx, uint32_t LB_MODE)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- 配置CANx_CTLR寄存器LBSEL位 -------------*/
    CANx->CTLR = SFR_Config(CANx->CTLR, ~LB_MODE, LB_MODE);
}


/**
  *   ##### 控制器局域网总线(CAN)功能配置函数定义结束 #####
  */


/**
  * 描述  清除CAN 清除缓冲器满标志。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  :清除状态。
  */
RetStatus CAN_Clear_Buffer_Overflow_Flag (CAN_SFRmap* CANx)
{
	volatile uint32_t wait_flag = 0x0000;
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- 设置CANx_CTLR寄存器RELF位 --------------------*/
    SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RELRX_POS);
    while((!((CANx->CTLR & CAN_CTLR_RXBSTA)>>CAN_CTLR_RXBSTA_POS))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RELRX_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	
	wait_flag = 0x0000;
    SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RELF_POS);
    while(((CANx->CTLR & CAN_CTLR_DOSTA)>>CAN_CTLR_DOSTA_POS)&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RELF_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * 描述  释放CAN 接收缓冲器。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *    	ReleaseCount: 释放缓冲器次数
  * 返回  无。
  */
void CAN_Release_Receive_Buffer (CAN_SFRmap* CANx, uint32_t ReleaseCount)//add release status  huanglt
{
	uint32_t i,tmprmc;
	volatile uint32_t delaytime;
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- 设置CANx_CTLR寄存器RELRX位 --------------------*/
    for(i=0;i<ReleaseCount;i++)
    {
        tmprmc = (CANx->CTLR&CAN_CTLR_CANRMC)>>CAN_CTLR_CANRMC0_POS;
        if(tmprmc == 0)
        {
        	return ;
        }else
        {
    		SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RELRX_POS);
    		delaytime = 0x50;
    		while(delaytime--)
    		{
    			asm("nop");
    		}
    	}
    }
}

/**
  * 描述  单次发送，当发生错误或者仲裁丢失时不会进行重发（单次发送）。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  ：已发送状态，不确保发送成功。
  * 备注：调用之前需确保总线开启，并处于空闲状态
  */
RetStatus CAN_Transmit_Single (CAN_SFRmap* CANx)
{
	volatile uint32_t wait_flag = 0x0000;
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- 设置CANx_CTLR寄存器TXR位 --------------------*/
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_ATX_POS);
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
    CANx->CTLR = CANx->CTLR | 0x300;
    while((!(CANx->CTLR & CAN_CTLR_TXSTA))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_ATX_POS);
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;
}

/**
  * 描述  发送，发生错误、仲裁丢失或发送结束时会进行重发（连续发送）。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回：已发送状态，并带发送不成功自动重发功能。
  * 备注：调用之前需确保总线开启，并处于空闲状态
  */
RetStatus CAN_Transmit_Repeat (CAN_SFRmap* CANx)
{
	volatile uint32_t wait_flag = 0x0000;
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- 设置CANx_CTLR寄存器TXR位 --------------------*/
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_ATX_POS);
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
    SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
    while((!(CANx->CTLR & CAN_CTLR_TXSTA))&& (wait_flag != FLAG_TIMEOUT))
	{
		wait_flag++;
	}
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
	if(wait_flag==FLAG_TIMEOUT)
	{
		return FAILURE;
	}
	return SUCCESS;

}







/**
  * 描述  获取CAN中断标志。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       InterruptType: CAN中断类型，取值范围为下面提供的一个:
  *                        CAN_INT_RECEIVE: 接收中断
  *                        CAN_INT_TRANSMIT: 发送中断
  *                        CAN_INT_ERROR_ALARM: 错误报警中断
  *                        CAN_INT_DATA_OVERFLOW: 数据溢出中断
  *                        CAN_INT_WAKE_UP: 唤醒中断
  *                        CAN_INT_ERROR_NEGATIVE: 错误消极中断
  *                        CAN_INT_ARBITRATION_LOST: 仲裁丢失中断
  *                        CAN_INT_BUS_ERROR: 总线错误中断
  *                        CAN_INT_RECEIVED_SUCCESSFULLY: 成功接收中断
  *                        CAN_INT_BUSS_OFF: 总线关闭中断
  * 返回  1:发生中断，0:未发生中断。
  */
FlagStatus CAN_Get_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType)
{
    uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_INT_ONE_EVENT(InterruptType));

    /* 配置中断标志掩码 */
    tmpreg = InterruptType << CAN_IFR_CANRXIF_POS;
    /*---------------- 读取CAN_IFR寄存器中断标志位 ----------------*/
    if (CANx->IFR & tmpreg)
    {
        /* 发生中断 */
        return SET;
    }
    else
    {
        /* 未发生中断 */
        return RESET;
    }
}

/**
  * 描述  清零CAN中断标志。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       InterruptType: CAN中断类型，取值范围为下面提供的一个或多个组合:
  *                        CAN_INT_TRANSMIT: 发送中断
  *                        CAN_INT_ERROR_ALARM: 错误报警中断
  *                        CAN_INT_DATA_OVERFLOW: 数据溢出中断
  *                        CAN_INT_WAKE_UP: 唤醒中断
  *                        CAN_INT_ERROR_NEGATIVE: 错误消极中断
  *                        CAN_INT_ARBITRATION_LOST: 仲裁丢失中断
  *                        CAN_INT_BUS_ERROR: 总线错误中断
  *                        CAN_INT_RECEIVED_SUCCESSFULLY：成功接收中断
  *                        CAN_INT_BUSS_OFF: 总线关闭中断
  * 返回  无。
  */
void CAN_Clear_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType)
{
	uint32_t tmpreg;

    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_INT_EVENT(InterruptType));

    /*---------------- 清零CAN_IER寄存器中断标志位 ----------------*/
    tmpreg = InterruptType << CAN_IFR_CANRXIF_POS;

    if(InterruptType == CAN_INT_RECEIVED_SUCCESSFULLY)
    {
    	 CANx->IER |= InterruptType << 6;
    }else
    {
    	 CANx->IER |= InterruptType << CAN_IER_CANRXIC_POS;
    }
    while((CANx->IFR & tmpreg)>0);
    CANx->IER &= ~(InterruptType << CAN_IER_CANRXIC_POS);
}

/**
  * 描述  配置CAN中断使能。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *       InterruptType: CAN中断类型，取值范围为下面提供的一个或多个组合:
  *                        CAN_INT_RECEIVE: 接收中断
  *                        CAN_INT_TRANSMIT: 发送中断
  *                        CAN_INT_ERROR_ALARM: 错误报警中断
  *                        CAN_INT_DATA_OVERFLOW: 数据溢出中断
  *                        CAN_INT_WAKE_UP: 唤醒中断
  *                        CAN_INT_ERROR_NEGATIVE: 错误消极中断
  *                        CAN_INT_ARBITRATION_LOST: 仲裁丢失中断
  *                        CAN_INT_BUS_ERROR: 总线错误中断
  *                        CAN_INT_RECEIVED_SUCCESSFULLY: 成功接收中断
  *                        CAN_INT_BUSS_OFF: 总线关闭中断
  *       NewState: DMA通道错误传输中断使能状态，取值为TRUE 或 FALSE。
  * 返回  无。
  */
void CAN_Set_INT_Enable (CAN_SFRmap* CANx,uint32_t InterruptType, FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_INT_EVENT(InterruptType));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- 配置CAN_IER寄存器中断使能位 ----------------*/
	if (NewState != FALSE)
	{
		/* 使能中断 */
		CANx->IER |= InterruptType << CAN_IER_CANRXIE_POS;
	}
	else
	{
		/* 禁止中断 */
		CANx->IER &= ~(InterruptType << CAN_IER_CANRXIE_POS);
	}
}

/**
  * 描述  配置CAN接收DMA使能
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *      NewState: TRUE/FALSE
  * 返回  无。
  */
void CAN_Set_Reseive_DMA_Enable(CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    CANx->IER = SFR_Config(CANx->IER, ~CAN_IER_CANRXDE, NewState<<CAN_IER_CANRXDE_POS);
}

/**
  * 描述  配置CAN发送DMA使能
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  *      NewState: TRUE/FALSE
  * 返回  无。
  */
void CAN_Set_Send_DMA_Enable(CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    CANx->IER = SFR_Config(CANx->IER, ~CAN_IER_CANTXDE, NewState<<CAN_IER_CANTXDE_POS);
}

/**
  * 描述  获取CAN接收 DMA标志位。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  1:发生请求，0:未发生请求。
  */
FlagStatus CAN_Get_Receive_DMA_Flag(CAN_SFRmap* CANx)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    if (CANx->IFR & CAN_IFR_CANRXDE)
    {
        /* 发生请求 */
        return SET;
    }
    else
    {
        /* 未发生请求 */
        return RESET;
    }
}

/**
  * 描述  获取CAN发送 DMA标志位。
  * 输入  CANx: 指向CAN内存结构的指针，取值为CAN4_SFR。
  * 返回  1:发生请求，0:未发生请求。
  */
FlagStatus CAN_Get_Send_DMA_Flag(CAN_SFRmap* CANx)
{
    /* 参数校验 */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    if (CANx->IFR & CAN_IFR_CANTXDE)
    {
        /* 发生请求 */
        return SET;
    }
    else
    {
        /* 未发生请求 */
        return RESET;
    }
}

/**
  *   ##### 控制器局域网总线(CAN)中断管理函数定义结束 #####
  */


