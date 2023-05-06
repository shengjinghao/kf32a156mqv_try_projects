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
  *   �ȳ�ʼ��RAM����RAM��ȫ������
  */
static void CAN_RAM_ERASE(void)
{
	for(uint16_t i = 0;i< 1024;i++)
	{
		*((uint8_t *)CAN4_RECEIVE_ADDR + i) = 0x00;
	}
}

/**
  *   ##### ����������������(CAN)��ʼ������ #####
  */
/**
  * ����  ��λCAN���裬ʹ������ʱ�ӡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  �ޡ�
  */
void CAN_Reset(CAN_SFRmap* CANx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    if(CANx == CAN4_SFR)
    {
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN4RST, TRUE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_CAN4CLKEN, TRUE);//huanglt   clk˳�򣿣�
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN4RST, FALSE);
        CAN_RAM_ERASE();
    }
}

/**
  * ����  ����������������(CAN)��ʼ�����ú���������������һ��λģʽRSMOD��
  *       �������ں�������ʱ����RSMOD��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       canInitStruct: CAN������Ϣ�ṹ�塣
  * ����  �ޡ�
  */
void CAN_Configuration_With_Reset_Mode(CAN_SFRmap* CANx, CAN_InitTypeDef* canInitStruct)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(canInitStruct->m_Enable));
    CHECK_RESTRICTION(CHECK_CAN_WORK_MODE(canInitStruct->m_Mode));
    CHECK_RESTRICTION(CHECK_CAN_SOURCE(canInitStruct->m_WorkSource));
    CHECK_RESTRICTION(CHECK_CAN_BAUDRATE_PRESET(canInitStruct->m_BaudRate));
    CHECK_RESTRICTION(CHECK_CAN_SYNC_JMP_WIDTH(canInitStruct->m_SyncJumpWidth));
    CHECK_RESTRICTION(CHECK_CAN_TIME_SEGMENT1(canInitStruct->m_TimeSeg1));
    CHECK_RESTRICTION(CHECK_CAN_TIME_SEGMENT2(canInitStruct->m_TimeSeg2));
    CHECK_RESTRICTION(CHECK_CAN_BUS_SAMPLE(canInitStruct->m_BusSample));

    /*---------------- ����CANx_CTLR�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_Enable������CANENλ�� */
    /* ���ݽṹ���Աm_Mode������LBACK��SILENTλ�� */
    /* ���ݽṹ���Աm_WorkSource������CANCKSλ�� */
    /* ����RSMOD�����븴λģʽ */
    tmpreg = ((uint32_t)canInitStruct->m_Enable << CAN_CTLR_CANEN_POS) \
           | canInitStruct->m_Mode \
           | canInitStruct->m_WorkSource \
           | CAN_CTLR_RSMOD;
    CANx->CTLR = SFR_Config (CANx->CTLR, ~CAN_CTLR_INIT_MASK, tmpreg);

    /*---------------- ����CANx_BRGR�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_BaudRate������CANBRPλ�� */
    /* ���ݽṹ���Աm_SyncJumpWidth������SJWλ�� */
    /* ���ݽṹ���Աm_TimeSeg1������TSEG1λ�� */
    /* ���ݽṹ���Աm_TimeSeg2������TSEG2λ�� */
    /* ���ݽṹ���Աm_BusSample������SAMλ�� */
    tmpreg = ((uint32_t)canInitStruct->m_BaudRate << CAN_BRGR_CANBRP0_POS) \
           | ((uint32_t)canInitStruct->m_SyncJumpWidth << CAN_BRGR_SJW0_POS) \
           | ((uint32_t)canInitStruct->m_TimeSeg1 << CAN_BRGR_TSEG1_0_POS) \
           | ((uint32_t)canInitStruct->m_TimeSeg2 << CAN_BRGR_TSEG2_0_POS) \
           | (canInitStruct->m_BusSample);
    CANx->BRGR = SFR_Config (CANx->BRGR, ~CAN_BRGR_INIT_MASK, tmpreg);
}

/**
  * ����  ��ʼ��CAN������Ϣ�ṹ�塣
  * ����  canInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void CAN_Struct_Init (CAN_InitTypeDef* canInitStruct)
{
    /* ��ʼ�� CANʹ��ѡ�� */
    canInitStruct->m_Enable = FALSE;

    /* ��ʼ�� CAN����ģʽ */
    canInitStruct->m_Mode = CAN_MODE_NORMAL;

    /* ��ʼ�� CAN����ʱ�� */
    canInitStruct->m_WorkSource = CAN_SOURCE_SCLK_DIV_2;

    /* ��ʼ�� CAN������Ԥ��ֵ */
    canInitStruct->m_BaudRate = 0;

    /* ��ʼ�� CANͬ����ת��� */
    canInitStruct->m_SyncJumpWidth = 0;

    /* ��ʼ�� CANʱ���1 */
    canInitStruct->m_TimeSeg1 = 0;

    /* ��ʼ�� CANʱ���2 */
    canInitStruct->m_TimeSeg2 = 0;

    /* ��ʼ�� CAN���߲������� */
    canInitStruct->m_BusSample = CAN_BUS_SAMPLE_1_TIME;
}
/**
  *   ##### ����������������(CAN)��ʼ������������� #####
  */


/**
  *   ##### ����������������(CAN)�������ú��� #####
  */
/**
  * ����  ��ȡCAN RX��Ϣ��������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  RX��Ϣ����������ЧֵΪ7λ��
  */
uint32_t CAN_Get_Receive_Message_Counter (CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*---------------- ��ȡCANx_CTLR�Ĵ���CANRMCλ ----------------*/
    tmpreg = CANx->CTLR;
    tmpreg &= CAN_CTLR_CANRMC;
    tmpreg >>= CAN_CTLR_CANRMC0_POS;

    return tmpreg;
}

/**
  * ����  ��ȡCAN�����¼�״̬���͡�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       Type: CAN�����¼�״̬���ͣ�ȡֵΪ:
  *               CAN_BUS_OFF_STATUS: ���߹ر�״̬
  *               CAN_ERROR_STATUS: ����״̬
  *               CAN_TX_STATUS: ����״̬
  *               CAN_RX_STATUS: ����״̬
  *               CAN_TX_COMPLETE_OFF_STATUS: �������״̬
  *               CAN_TX_BUFFER_STATUS: ���ͻ�����״̬
  *               CAN_DATA_OVERFLOW_STATUS: ������״̬
  *               CAN_RX_BLANK_STATUS: ���ݿ�״̬
  * ����  1: ���߹ر�/����/���ڷ���/���ڽ���/�������/CPU���Է��ʷ��ͻ�����/
  *          RAM��δ��������/RAM����δ����Ϣ��
  *       0: ���߿���/�޴�/���Ϳ���/���տ���/����δ���/CPU���ܷ��ʷ��ͻ�����/
  *          RAM��δ������δ��/RAM����δ����Ϣ��
  */
FlagStatus CAN_Get_Transmit_Status (CAN_SFRmap* CANx, uint32_t Type)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_STATUS(Type));

    /*---------------- ��ȡCANx_CTLR�Ĵ�����Ӧλ ----------------*/
    tmpreg = CANx->CTLR;

    if (tmpreg & Type)
    {
        /* ״̬λΪ1 */
        return SET;
    }
    else
    {
        /* ״̬λΪ0 */
        return RESET;
    }
}

/**
  * ����  ����CANʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       NewState: CANʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void CAN_Cmd (CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����CANx_CTLR�Ĵ���CANENλ ----------------*/
    if (NewState != FALSE)
    {
        /* CANʹ�� */
        SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_CANEN_POS);
    }
    else
    {
        /* CAN��ֹ */
        SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_CANEN_POS);
    }
}



/**
  * ����  ����CAN˯��ģʽʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       NewState: CAN˯��ģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void CAN_Sleep_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����CANx_CTLR�Ĵ���SLEEPλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��˯��ģʽ */
        SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_SLEEP_POS);
    }
    else
    {
        /* ��ֹ˯��ģʽ */
        SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_SLEEP_POS);
    }
}

/**
  * ����  ����CAN��λģʽʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       NewState: CAN��λģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void CAN_Reset_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����CANx_CTLR�Ĵ���RSMODλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܸ�λģʽ */
        SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RSMOD_POS);
    }
    else
    {
        /* ��ֹ��λģʽ */
        SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RSMOD_POS);
    }
}

/**
  * ����  ����CAN����ģʽ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       ModeType: CAN����ģʽ��ȡֵΪ:
  *                   CAN_MODE_NORMAL: ��ֹ�����ͻػ�ģʽ
  *                   CAN_MODE_SILENT: ʹ�ܰ���ģʽ
  *                   CAN_MODE_LOOPBACK: ʹ�ܻػ�ģʽ
  *                   CAN_MODE_SILENT_LOOPBACK: ʹ�ܰ����ͻػ�ģʽ
  * ����  �ޡ�
  */
void CAN_Work_Mode_Config (CAN_SFRmap* CANx, uint32_t ModeType)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_WORK_MODE(ModeType));

    /*------------ ����CANx_CTLR�Ĵ���SILENT��LBACKλ ------------*/
    CANx->CTLR = SFR_Config (CANx->CTLR,
                        ~(CAN_CTLR_SILENT | CAN_CTLR_LBACK),
                        ModeType);
}

/**
  * ����  ����CAN���߲���������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       Times: ���߲���������ȡֵΪ:
  *                CAN_BUS_SAMPLE_1_TIME: ���߲���1��
  *                CAN_BUS_SAMPLE_3_TIMES: ���߲���3��
  * ����  �ޡ�
  */
void CAN_Bus_Sample_Times_Config (CAN_SFRmap* CANx, uint32_t Times)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_BUS_SAMPLE(Times));

    /*---------------- ����CANx_BRGR�Ĵ���SAMλ ----------------*/
    if (Times != CAN_BUS_SAMPLE_1_TIME)
    {
        /* ���߲���3�� */
        SFR_SET_BIT_ASM(CANx->BRGR, CAN_BRGR_SAM_POS);
    }
    else
    {
        /* ���߲���1�� */
        SFR_CLR_BIT_ASM(CANx->BRGR, CAN_BRGR_SAM_POS);
    }
}





/**
  * ����  ��ȡCAN�������ָ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  �������ָ�룬ȡֵΪ0~63
  */
uint8_t CAN_Get_Point_Of_RAM_Mailbox(CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    tmpreg = (CANx->RCR & CAN_RCR_RAMMB) >> CAN_RCR_RAMMB0_POS;

    return (uint8_t)tmpreg;
}

/**
  * ����  ��ȡCAN���ߴ�����Ϣ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       canErrorStruct: CAN���ߴ�����Ϣ�ṹ�壬��¼������Ϣ��
  * ����  �ޡ�
  */
void CAN_Get_Error_Code (CAN_SFRmap* CANx, CAN_ErrorTypeDef* canErrorStruct)
{
    uint32_t tmpreg;
    uint32_t tmpreg1;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(canErrorStruct != (CAN_ErrorTypeDef*)0);

    /*---------------- ��ȡCANx_RCR�Ĵ��� ----------------*/
    tmpreg = CANx->RCR;

    /*---------------- ��ȡCANx_RCR�Ĵ���CANERRCλ ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANERRC;
    tmpreg1 >>= CAN_RCR_CANERRC0_POS;
    canErrorStruct->m_ErrorCode = tmpreg1;

    /*---------------- ��ȡCANx_RCR�Ĵ���CANDIRλ ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANDIR;
    tmpreg1 >>= CAN_RCR_CANDIR_POS;
    canErrorStruct->m_ErrorDirection = tmpreg1;

    /*---------------- ��ȡCANx_RCR�Ĵ���CANSEGλ ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANSEG;
    tmpreg1 >>= CAN_RCR_CANSEG0_POS;
    canErrorStruct->m_ErrorSegment = tmpreg1;

    /*---------------- ��ȡCANx_RCR�Ĵ���CANALCλ ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANALC;
    tmpreg1 >>= CAN_RCR_CANALC0_POS;
    canErrorStruct->m_ArbitrationLost = tmpreg1;
}

/**
  * ����  ��ȡCAN���󱨾����ơ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  ���󱨾����ƣ�ȡֵΪ8λ��ֵ��
  */
uint8_t CAN_Get_Error_Warning_Limit (CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*---------------- ��ȡCANx_EROR�Ĵ���CANEWLλ ----------------*/
    tmpreg = CANx->EROR;

    return (uint8_t)tmpreg;
}

/**
  * ����  ��ȡCAN����/���մ����������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       Direction: CAN�����䷽��ȡֵΪ��
  *                    CAN_ERROR_AT_TX: ���ʹ��������
  *                    CAN_ERROR_AT_RX: ���մ��������
  * ����  �����������ȡֵΪ8λ��ֵ��
  */
uint8_t CAN_Get_Error_Counter (CAN_SFRmap* CANx, uint32_t Direction)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_ERROR_DIR(Direction));

    /*----------- ��ȡCANx_EROR�Ĵ��� -----------*/
    tmpreg = CANx->EROR;

    if (Direction != CAN_ERROR_AT_TX)
    {
        /*----------- ��ȡCANRXEλ -----------*/
        tmpreg &= CAN_EROR_CANRXE;
        tmpreg >>= CAN_EROR_CANRXE0_POS;
    }
    else
    {
        /*----------- ��ȡCANTXEλ -----------*/
        tmpreg &= CAN_EROR_CANTXE;
        tmpreg >>= CAN_EROR_CANTXE0_POS;
    }

    return (uint8_t)tmpreg;
}

/**
  * ����  ����CAN���󱨾����ơ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       ErrorLimit: ���󱨾����ƣ�ȡֵΪ8λ��Ч��ֵ��
  * ����  �ޡ�
  */
void CAN_Error_Warning_Limit_Config (CAN_SFRmap* CANx, uint8_t ErrorLimit)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CANx_EROR�Ĵ���CANEWLλ -------------*/
    tmpreg = ErrorLimit << CAN_EROR_CANEWL0_POS;
    CANx->EROR = SFR_Config (CANx->EROR, ~CAN_EROR_CANEWL, tmpreg);
}

/**
  * ����  ����CAN����/���մ����������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       Direction: CAN�����䷽��ȡֵΪ��
  *                    CAN_ERROR_AT_TX: ���ʹ��������
  *                    CAN_ERROR_AT_RX: ���մ��������
  *       ErrorCounter: ���������ȡֵΪ8λ��Ч��ֵ��
  * ����  �ޡ�
  */
void CAN_Error_Counter_Config (CAN_SFRmap* CANx,uint32_t Direction, uint8_t ErrorCounter)
{
    uint32_t tmpreg;
    uint32_t tmpmask;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_ERROR_DIR(Direction));

    if (Direction != CAN_ERROR_AT_TX)
    {
        /*----------- ��ȡCANRXEλ -----------*/
        tmpreg = ErrorCounter << CAN_EROR_CANRXE0_POS;
        tmpmask = CAN_EROR_CANRXE;
    }
    else
    {
        /*----------- ��ȡCANTXEλ -----------*/
        tmpreg = ErrorCounter << CAN_EROR_CANTXE0_POS;
        tmpmask = CAN_EROR_CANTXE;
    }

    /*------------- ����CANx_EROR�Ĵ��� -------------*/
    CANx->EROR = SFR_Config (CANx->EROR, ~tmpmask, tmpreg);
}

/**
  * ����  ����CAN���մ��롣
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       Acceptance: ���մ��룬ȡֵΪ32λ��Ч��ֵ��
  * ����  �ޡ�
  */
void CAN_Acceptance_Config (CAN_SFRmap* CANx, uint32_t Acceptance)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CANx_ACRR�Ĵ���ACRλ -------------*/
    CANx->ACRR = Acceptance;
}

/**
  * ����  ��ȡCAN���մ��롣
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  ���մ��룬ȡֵΪ32λ��Ч��ֵ��
  */
uint32_t CAN_Get_Acceptance (CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ��ȡCANx_ACRR�Ĵ���ACRλ -------------*/
    tmpreg = CANx->ACRR;

    return tmpreg;
}



/**
  *   ##### ����������������(CAN)���ͽ��պ��� #####
  */
/**
  * ����  CANģ��(CAN)���ͻ������á�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       canInitStruct: CANģ��������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void CAN_Transmit_Message_Configuration (CAN_SFRmap* CANx,CAN_MessageTypeDef* canInitStruct)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_FRAME_FORMAT(canInitStruct->m_FrameFormat));
    CHECK_RESTRICTION(CHECK_CAN_REMOTE_REQUEST(canInitStruct->m_RemoteTransmit));
    CHECK_RESTRICTION(CHECK_CAN_DATA_LENGTH(canInitStruct->m_DataLength));
    if(canInitStruct->m_RemoteTransmit == CAN_REMOTE_FRAME)
    {
    	return;
    }else
    {
        /*---------------- ����CANx_INFR�Ĵ��� ----------------*/
        /* ���ݽṹ���Աm_FrameFormat������IDEλ�� */
        /* ���ݽṹ���Աm_RemoteTransmit������RTRλ�� */
        /* ���ݽṹ���Աm_DataLength������DLCλ�� */
        tmpreg = (canInitStruct->m_FrameFormat << CAN_INFR_IDE_POS) \
               | (canInitStruct->m_RemoteTransmit << CAN_INFR_RTR_POS) \
               | (canInitStruct->m_DataLength << CAN_INFR_DLC0_POS);
        CANx->INFR = SFR_Config (CANx->INFR, ~CAN_INFR_INIT_MASK, tmpreg);

        /*----------- ����CANx_TX0R/CANx_TX1R/CANx_TX2R�Ĵ��� -----------*/
        /* ���ݽṹ���Աm_FrameFormat��ѡ��֡��ʽ */
        /* ���ݽṹ���Աm_StandardID������IDxλ�� */
        /* ���ݽṹ���Աm_ExtendedID������IDxλ�� */
        /* ���ݽṹ���Աm_Data������CANTXDTxλ�� */
        if (canInitStruct->m_FrameFormat != CAN_FRAME_FORMAT_EFF)
        {
            /*----------- ����CANx_TX0R�Ĵ��� -----------*/
            tmpreg = (canInitStruct->m_Can_ID << CAN_TX0R_ID18_POS) \
                   | ((uint32_t)canInitStruct->m_Data[0] << CAN_TX0R_CANTX0_8_POS) \
                   | ((uint32_t)canInitStruct->m_Data[1] << CAN_TX0R_CANTX0_0_POS);
            CANx->TX0R = SFR_Config (CANx->TX0R, ~CAN_TX0R_SFF_MASK, tmpreg);

            /*----------- ����CANx_TX1R�Ĵ��� -----------*/
            tmpreg = ((uint32_t)canInitStruct->m_Data[2] << CAN_TX1R_CANTX1_24_POS) \
                   | ((uint32_t)canInitStruct->m_Data[3] << CAN_TX1R_CANTX1_16_POS) \
                   | ((uint32_t)canInitStruct->m_Data[4] << CAN_TX1R_CANTX1_8_POS) \
                   | ((uint32_t)canInitStruct->m_Data[5] << CAN_TX1R_CANTX1_0_POS);
            CANx->TX1R = tmpreg;

            /*----------- ����CANx_TX2R�Ĵ��� -----------*/
            tmpreg = ((uint32_t)canInitStruct->m_Data[6] << CAN_TX2R_CANTX2_24_POS) \
                   | ((uint32_t)canInitStruct->m_Data[7] << CAN_TX2R_CANTX2_16_POS);
            CANx->TX2R = SFR_Config (CANx->TX2R, ~CAN_TX2R_SFF_MASK, tmpreg);
        }
        else
        {
            /*----------- ����CANx_TX0R�Ĵ��� -----------*/
            tmpreg = canInitStruct->m_Can_ID << CAN_TX0R_ID0_POS;
            CANx->TX0R = SFR_Config (CANx->TX0R, ~CAN_TX0R_EFF_MASK, tmpreg);

            /*----------- ����CANx_TX1R�Ĵ��� -----------*/
            tmpreg = ((uint32_t)canInitStruct->m_Data[0] << CAN_TX1R_CANTX1_24_POS) \
                   | ((uint32_t)canInitStruct->m_Data[1] << CAN_TX1R_CANTX1_16_POS) \
                   | ((uint32_t)canInitStruct->m_Data[2] << CAN_TX1R_CANTX1_8_POS) \
                   | ((uint32_t)canInitStruct->m_Data[3] << CAN_TX1R_CANTX1_0_POS);
            CANx->TX1R = tmpreg;

            /*----------- ����CANx_TX2R�Ĵ��� -----------*/
            tmpreg = ((uint32_t)canInitStruct->m_Data[4] << CAN_TX2R_CANTX2_24_POS) \
                   | ((uint32_t)canInitStruct->m_Data[5] << CAN_TX2R_CANTX2_16_POS) \
                   | ((uint32_t)canInitStruct->m_Data[6] << CAN_TX2R_CANTX2_8_POS) \
                   | ((uint32_t)canInitStruct->m_Data[7] << CAN_TX2R_CANTX2_0_POS);
            CANx->TX2R = tmpreg;
        }
    }
}


/**
  * ����  ����CAN�������Ρ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       Acceptance: �������Σ�ȡֵΪ32λ��Ч��ֵ��
  * ����  �ޡ�
  */
void CAN_Acceptance_Mask_Config (CAN_SFRmap* CANx, uint32_t Acceptance)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CANx_MSKR�Ĵ���MSKλ -------------*/
    CANx->MSKR = Acceptance;
}

/**
  * ����  ��ȡCAN�������Ρ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  �������Σ�ȡֵΪ32λ��Ч��ֵ��
  */
uint32_t CAN_Get_Acceptance_Mask (CAN_SFRmap* CANx)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ��ȡCANx_MSKR�Ĵ���MSKλ -------------*/
    tmpreg = CANx->MSKR;

    return tmpreg;
}

/**
  * ����  ���������˲�����չʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * 	 NewState�� TRUE/FALSE
  * ����  �ޡ�
  */
void CAN_Expand_Acceptance_Enable(CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*------------- ����CANx_CTLR�Ĵ���FILTEREXTλ -------------*/
    CANx->CTLR = SFR_Config(CANx->CTLR, ~CAN_CTLR_FILTEREXT, NewState<<CAN_CTLR_FILTEREXT_POS);
}

/**
  * ����  ����CAN���մ�����չ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * 	  FILTER_Group�� CAN_Filter_G1~CAN_Filter_G8��
  *       Acceptance: ���մ��룬ȡֵΪ32λ��Ч��ֵ��
  * ����  �ޡ�
  */
void CAN_Acceptance_FILTER_Config (CAN_SFRmap* CANx, uint8_t FILTER_Group, uint32_t Acceptance)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CAN�����˲�������չ -------------*/
    *((uint32_t *)(CAN4_FILTER_ADDR+FILTER_Group*0x08)) = Acceptance;
}

/**
  * ����  ��ȡCAN���մ�����չ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * 	 FILTER_Group�� CAN_Filter_G1~CAN_Filter_G8��
  * ����  ���մ��룬ȡֵΪ32λ��Ч��ֵ��
  */
uint32_t CAN_Get_Acceptance_FILTER (CAN_SFRmap* CANx, uint8_t FILTER_Group)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ��ȡCAN�����˲�������չ  -------------*/
    tmpreg = *((uint32_t *)(CAN4_FILTER_ADDR+FILTER_Group*0x08));

    return tmpreg;
}

/**
  * ����  ����CAN����������չ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * 	  FILTER_Group�� CAN_Filter_G1~CAN_Filter_G8��
  *       Acceptance: �������Σ�ȡֵΪ32λ��Ч��ֵ��
  * ����  �ޡ�
  */
void CAN_Acceptance_FILTER_Mask_Config (CAN_SFRmap* CANx, uint8_t FILTER_Group, uint32_t Acceptance)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CAN�����˲�������չ -------------*/
    *((uint32_t *)(CAN4_FILTER_ADDR+FILTER_Group*0x08+0x04)) = Acceptance;
}

/**
  * ����  ��ȡCAN����������չ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * 	 FILTER_Group�� CAN_Filter_G1~CAN_Filter_G8��
  * ����  �������Σ�ȡֵΪ32λ��Ч��ֵ��
  */
uint32_t CAN_Get_Acceptance_FILTER_Mask (CAN_SFRmap* CANx, uint8_t FILTER_Group)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ��ȡCAN�����˲�������չ  -------------*/
    tmpreg = *((uint32_t *)(CAN4_FILTER_ADDR+FILTER_Group*0x08+0x04));

    return tmpreg;
}

/**
  * ����  ����RX��Ϣ��������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����    :���״̬��
  */
RetStatus CAN_Clear_CANRMC(CAN_SFRmap* CANx)
{
	volatile uint32_t wait_flag = 0x0000;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CANx_CTLR�Ĵ���RELRXALLλ -------------*/
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
  * ����  ����BUS OFFʱ�Զ��ָ�ʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * 	 NewState�� TRUE/FALSE
  * ����  �ޡ�
  */
void CAN_BUSS_OFF_Auto_Reset_Enable(CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*------------- ����CANx_CTLR�Ĵ���BOFFRXEλ -------------*/
    CANx->CTLR = SFR_Config(CANx->CTLR, ~CAN_CTLR_BOFFREC, NewState<<CAN_CTLR_BOFFREC_POS);
}

/**
  * ����  ���ûػ�ģʽѡ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * 	 LB_MODE:  CAN_Extern_LoopBack:�ⲿ�ػ�
  * 	 		   CAN_Intern_LoopBack:�ڲ��ػ�
  * ����  �ޡ�
  */
void CAN_LoopBack_Mode_Select(CAN_SFRmap* CANx, uint32_t LB_MODE)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CANx_CTLR�Ĵ���LBSELλ -------------*/
    CANx->CTLR = SFR_Config(CANx->CTLR, ~LB_MODE, LB_MODE);
}


/**
  *   ##### ����������������(CAN)�������ú���������� #####
  */


/**
  * ����  ���CAN �������������־��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  :���״̬��
  */
RetStatus CAN_Clear_Buffer_Overflow_Flag (CAN_SFRmap* CANx)
{
	volatile uint32_t wait_flag = 0x0000;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- ����CANx_CTLR�Ĵ���RELFλ --------------------*/
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
  * ����  �ͷ�CAN ���ջ�������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *    	ReleaseCount: �ͷŻ���������
  * ����  �ޡ�
  */
void CAN_Release_Receive_Buffer (CAN_SFRmap* CANx, uint32_t ReleaseCount)//add release status  huanglt
{
	uint32_t i,tmprmc;
	volatile uint32_t delaytime;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- ����CANx_CTLR�Ĵ���RELRXλ --------------------*/
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
  * ����  ���η��ͣ���������������ٲö�ʧʱ��������ط������η��ͣ���
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  ���ѷ���״̬����ȷ�����ͳɹ���
  * ��ע������֮ǰ��ȷ�����߿����������ڿ���״̬
  */
RetStatus CAN_Transmit_Single (CAN_SFRmap* CANx)
{
	volatile uint32_t wait_flag = 0x0000;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- ����CANx_CTLR�Ĵ���TXRλ --------------------*/
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
  * ����  ���ͣ����������ٲö�ʧ���ͽ���ʱ������ط����������ͣ���
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ���أ��ѷ���״̬���������Ͳ��ɹ��Զ��ط����ܡ�
  * ��ע������֮ǰ��ȷ�����߿����������ڿ���״̬
  */
RetStatus CAN_Transmit_Repeat (CAN_SFRmap* CANx)
{
	volatile uint32_t wait_flag = 0x0000;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- ����CANx_CTLR�Ĵ���TXRλ --------------------*/
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
  * ����  ��ȡCAN�жϱ�־��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       InterruptType: CAN�ж����ͣ�ȡֵ��ΧΪ�����ṩ��һ��:
  *                        CAN_INT_RECEIVE: �����ж�
  *                        CAN_INT_TRANSMIT: �����ж�
  *                        CAN_INT_ERROR_ALARM: ���󱨾��ж�
  *                        CAN_INT_DATA_OVERFLOW: ��������ж�
  *                        CAN_INT_WAKE_UP: �����ж�
  *                        CAN_INT_ERROR_NEGATIVE: ���������ж�
  *                        CAN_INT_ARBITRATION_LOST: �ٲö�ʧ�ж�
  *                        CAN_INT_BUS_ERROR: ���ߴ����ж�
  *                        CAN_INT_RECEIVED_SUCCESSFULLY: �ɹ������ж�
  *                        CAN_INT_BUSS_OFF: ���߹ر��ж�
  * ����  1:�����жϣ�0:δ�����жϡ�
  */
FlagStatus CAN_Get_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType)
{
    uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_INT_ONE_EVENT(InterruptType));

    /* �����жϱ�־���� */
    tmpreg = InterruptType << CAN_IFR_CANRXIF_POS;
    /*---------------- ��ȡCAN_IFR�Ĵ����жϱ�־λ ----------------*/
    if (CANx->IFR & tmpreg)
    {
        /* �����ж� */
        return SET;
    }
    else
    {
        /* δ�����ж� */
        return RESET;
    }
}

/**
  * ����  ����CAN�жϱ�־��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       InterruptType: CAN�ж����ͣ�ȡֵ��ΧΪ�����ṩ��һ���������:
  *                        CAN_INT_TRANSMIT: �����ж�
  *                        CAN_INT_ERROR_ALARM: ���󱨾��ж�
  *                        CAN_INT_DATA_OVERFLOW: ��������ж�
  *                        CAN_INT_WAKE_UP: �����ж�
  *                        CAN_INT_ERROR_NEGATIVE: ���������ж�
  *                        CAN_INT_ARBITRATION_LOST: �ٲö�ʧ�ж�
  *                        CAN_INT_BUS_ERROR: ���ߴ����ж�
  *                        CAN_INT_RECEIVED_SUCCESSFULLY���ɹ������ж�
  *                        CAN_INT_BUSS_OFF: ���߹ر��ж�
  * ����  �ޡ�
  */
void CAN_Clear_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType)
{
	uint32_t tmpreg;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_INT_EVENT(InterruptType));

    /*---------------- ����CAN_IER�Ĵ����жϱ�־λ ----------------*/
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
  * ����  ����CAN�ж�ʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *       InterruptType: CAN�ж����ͣ�ȡֵ��ΧΪ�����ṩ��һ���������:
  *                        CAN_INT_RECEIVE: �����ж�
  *                        CAN_INT_TRANSMIT: �����ж�
  *                        CAN_INT_ERROR_ALARM: ���󱨾��ж�
  *                        CAN_INT_DATA_OVERFLOW: ��������ж�
  *                        CAN_INT_WAKE_UP: �����ж�
  *                        CAN_INT_ERROR_NEGATIVE: ���������ж�
  *                        CAN_INT_ARBITRATION_LOST: �ٲö�ʧ�ж�
  *                        CAN_INT_BUS_ERROR: ���ߴ����ж�
  *                        CAN_INT_RECEIVED_SUCCESSFULLY: �ɹ������ж�
  *                        CAN_INT_BUSS_OFF: ���߹ر��ж�
  *       NewState: DMAͨ���������ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void CAN_Set_INT_Enable (CAN_SFRmap* CANx,uint32_t InterruptType, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_INT_EVENT(InterruptType));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����CAN_IER�Ĵ����ж�ʹ��λ ----------------*/
	if (NewState != FALSE)
	{
		/* ʹ���ж� */
		CANx->IER |= InterruptType << CAN_IER_CANRXIE_POS;
	}
	else
	{
		/* ��ֹ�ж� */
		CANx->IER &= ~(InterruptType << CAN_IER_CANRXIE_POS);
	}
}

/**
  * ����  ����CAN����DMAʹ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *      NewState: TRUE/FALSE
  * ����  �ޡ�
  */
void CAN_Set_Reseive_DMA_Enable(CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    CANx->IER = SFR_Config(CANx->IER, ~CAN_IER_CANRXDE, NewState<<CAN_IER_CANRXDE_POS);
}

/**
  * ����  ����CAN����DMAʹ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  *      NewState: TRUE/FALSE
  * ����  �ޡ�
  */
void CAN_Set_Send_DMA_Enable(CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    CANx->IER = SFR_Config(CANx->IER, ~CAN_IER_CANTXDE, NewState<<CAN_IER_CANTXDE_POS);
}

/**
  * ����  ��ȡCAN���� DMA��־λ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  1:��������0:δ��������
  */
FlagStatus CAN_Get_Receive_DMA_Flag(CAN_SFRmap* CANx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    if (CANx->IFR & CAN_IFR_CANRXDE)
    {
        /* �������� */
        return SET;
    }
    else
    {
        /* δ�������� */
        return RESET;
    }
}

/**
  * ����  ��ȡCAN���� DMA��־λ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN4_SFR��
  * ����  1:��������0:δ��������
  */
FlagStatus CAN_Get_Send_DMA_Flag(CAN_SFRmap* CANx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    if (CANx->IFR & CAN_IFR_CANTXDE)
    {
        /* �������� */
        return SET;
    }
    else
    {
        /* δ�������� */
        return RESET;
    }
}

/**
  *   ##### ����������������(CAN)�жϹ������������ #####
  */


