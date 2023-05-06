/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a156_CANFD.c                              	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V1.0	                                              *
 *  $Description$     : This file provides functions related to the CANFD bus *
 *  					bus (CANFD) , including:							  *
 *          			+ CAN Bus(CANFD)initialization function               *
 *          			+ CAN Bus(CANFD)function configuration function       *
 *          			+ CAN Bus(CANFD)transmit-receive function             *
 *          			+ CAN Bus(CANFD)interrupt management function         *
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
 *  2021-07-08 00.02.00 FAE Group     Version 2.0 update                      *
 *                                                                            *
 *                                                                            *
 *****************************************************************************/
/******************************************************************************
**                      		Include Files                                **
******************************************************************************/
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"
#include "kf32a1x6_canfd.h"

#ifdef KF32A136
/******************************************************************************
 *                      Variables      Declarations                            *
 ******************************************************************************/
volatile uint8_t  CANFD_SCLK_MHZ = 0;
volatile uint8_t  CANFD_HFCLK_MHZ = 0;

const Can_ControllerInfoType Can_m_ControllersInfo[2] = {

	{CAN_HW_CONTROLLER_BASEADDRESS_CANFD6,
	 CAN_HW_CONTROLLER_MBADDRESS_CANFD6,
	 CAN_HW_CONTROLLER_FILTERADDRESS_CANFD6,
	 CAN_CONTROLLER_FD},

	{CAN_HW_CONTROLLER_BASEADDRESS_CANFD7,
	 CAN_HW_CONTROLLER_MBADDRESS_CANFD7,
	 CAN_HW_CONTROLLER_FILTERADDRESS_CANFD7,
	 CAN_CONTROLLER_FD}};

Kf32a_Canfd_Reg *const CANFD_PTR[2] = {
    (Kf32a_Canfd_Reg *)CAN_HW_CONTROLLER_BASEADDRESS_CANFD6,
    (Kf32a_Canfd_Reg *)CAN_HW_CONTROLLER_BASEADDRESS_CANFD7,
};

/******************************************************************************
 *                      Private Function Declarations                          *
 ******************************************************************************/
static void Can_m_FdBaudrateSet(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex);
static void Can_m_FdClearAllFlag(const uint8_t Can_Controller_Index);
static void Can_m_FdIntSet(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex);
static void Read_Code(Canfd_MailboxHeaderType *Can_MailboxHeader, DataBuffer_8byteType *DataBuffer);
static void Std_Reverse_Data(Canfd_MailboxHeaderType *Can_MailboxHeader, DataBuffer_8byteType *DataBuffer, uint8_t type);
static uint32_t Reverse_Int(uint32_t DATA32);
static Code_Segment Can_m_FdCsCodeSet(Canfd_MailboxHeaderType *Can_MailboxHeader);
static Can_ReturnType Can_m_FdWaitConfilct(const uint8_t Can_Controller_Index,const uint8_t Loop);
static Can_ReturnType Can_m_FdCopyDataTo8MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader);
static Can_ReturnType Can_m_FdCopyDataFrom8MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBoxType);
static Can_ReturnType Can_m_FdCopyDataTo16MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader);
static Can_ReturnType Can_m_FdCopyDataFrom16MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBoxType);
static Can_ReturnType Can_m_FdCopyDataTo32MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader);
static Can_ReturnType Can_m_FdCopyDataFrom32MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBoxType);
static Can_ReturnType Can_m_FdCopyDataTo64MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader);
static Can_ReturnType Can_m_FdCopyDataFrom64MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBoxType);
#if (HARDWARE_FILTER == STD_ON)
static void Can_m_FdFilterInit(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex);
#endif
#if (TRANSMIT_DELAY_CONPENSATION == STD_ON)
static void Can_m_FdTDCSet(const uint8_t Can_Controller_Index);
#endif
/******************************************************************************
 *                      Private Function Declarations                          *
 ******************************************************************************/
/* Set CAN Default baudrate */
static void Can_m_FdBaudrateSet(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex)
{
	/* Set CAN Default baudrate */
	/* [$Block Start$] */
	/* Set Can Controller Sample time */
	CANFD_PTR[Can_Controller_Index]->CANFD_BRGR.B.SAM = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->SampleTimes;
	/* Set Can Controller Synchronization Jump Width */
	CANFD_PTR[Can_Controller_Index]->CANFD_BRGR.B.SJW = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->Sjw;
	/* Set Can Controller Baud Rate Clock Prescale */
	CANFD_PTR[Can_Controller_Index]->CANFD_BRGR.B.CANBRP = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->PreScale;
	/* Set T Segment 1 */
	CANFD_PTR[Can_Controller_Index]->CANFD_BRGR.B.TSEG1 = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->TSeg1;
	/* Set T Segment 2 */
	CANFD_PTR[Can_Controller_Index]->CANFD_BRGR.B.TSEG2 = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->TSeg2;
	/* [$Block End$] */

	/* [$Block Start$] */
	/* Set Can Controller Baud Rate Switch Prescale */
	CANFD_PTR[Can_Controller_Index]->CANFD_BRGR.B.BRSBRP = Can_ControllerConfig[IntIndex].Canfd_Controller_ALLFdBDRConfig->BrsPrescale;
	/* Set Can Controller Baud Rate Switch T Segment 1 */
	CANFD_PTR[Can_Controller_Index]->CANFD_BRGR.B.HTSEG1 = Can_ControllerConfig[IntIndex].Canfd_Controller_ALLFdBDRConfig->HtSeg1;
	/* Set Can Controller Baud Rate Switch T Segment 2*/
	CANFD_PTR[Can_Controller_Index]->CANFD_BRGR.B.HTSEG2 = Can_ControllerConfig[IntIndex].Canfd_Controller_ALLFdBDRConfig->HtSeg2;
	/* [$Block End$] */
}

/* Clear all interrupt flag */
static void Can_m_FdClearAllFlag(const uint8_t Can_Controller_Index)
{
	volatile uint32_t Rcr_Value = 0;
	volatile uint8_t delay_time = FUNCTION_ENABEL_TIME;

	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.ALIF == STD_ON)
	{
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ALIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.ALIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ALIC = 0x00;
	}
	delay_time = FUNCTION_ENABEL_TIME;
	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.BEIF == STD_ON)
	{
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BEIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.BEIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BEIC = 0x00;
	}
	delay_time = FUNCTION_ENABEL_TIME;
	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.BOFFIF == STD_ON)
	{
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BOFFIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.BOFFIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BOFFIC = 0x00;
	}
	delay_time = FUNCTION_ENABEL_TIME;
	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.EAIF == STD_ON)
	{
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.EAIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.EAIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.EAIC = 0x00;
	}
	delay_time = FUNCTION_ENABEL_TIME;
	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.ENIF == STD_ON)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ENIC = STD_ON;
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.ENIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ENIC = 0x00;
	}
	delay_time = FUNCTION_ENABEL_TIME;
	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.DOVFIF == STD_ON)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.DOVFIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.DOVFIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.DOVFIC = 0x00;
	}
	delay_time = FUNCTION_ENABEL_TIME;
	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.TDCFAILIF == STD_ON)
	{
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.TDCFAILIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.TDCFAILIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.TDCFAILIC = 0x00;
	}
	delay_time = FUNCTION_ENABEL_TIME;
	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.CANTXIF == STD_ON)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANTXIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.CANTXIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANTXIC = 0x00;
	}
	delay_time = FUNCTION_ENABEL_TIME;
	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.CANRXIF == STD_ON)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANRXIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.CANRXIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANRXIC = 0x00;
	}
	delay_time = FUNCTION_ENABEL_TIME;
	if (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.WUIF == STD_ON)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.WUIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.WUIF == STD_ON) &&(delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.WUIC = 0x00;
	}
}

/* Set The Can Intterrupt  Enable And Clear The Interrupt Flag*/
static void Can_m_FdIntSet(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex)
{

	/* CAN Receive Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANRXIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->RxIntEnableSet;
	/* CAN Transmit Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANTXIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->TxIntEnableSet;
	/* CAN Bus Off Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BOFFIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->BusOffEnableSet;
	/* CAN Wake Up Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.WUIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->WakeUpIntEnableSet;
	/* CAN Error Alarm Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.EAIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->ErrorAlarmIntEnableSet;
	/* CAN Receive Over Flow Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.DOVFIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->OverFlowIntEnableSet;
	/* CAN Error Negative Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ENIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->ErrorNegativeIntEnableSet;
	/* CAN Error Arbitrate Lose Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ALIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->ArbitrateLoseIntEnableSet;
	/* CAN Bus Error Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BEIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->BusErrorIntEnableSet;
	/* CAN DMA Transmit Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CTXDE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->DmaTXDEnableSet;
	/* CAN DMA Receive Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CRXDE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->DmaRXDEnableSet;
	/* CAN MailBox Receive Triger Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.TRGMBIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->TrigerMBEnableSet;
	/* Disable CAN Receive Not Empty Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.RXBSTAIE = STD_OFF;
	/* Disable CAN Transmit Delay Offset Fail Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.TDCFAILIE = STD_OFF;
	/* Disable CAN Transmit Arbitrate Fail Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ARBFAILIE = STD_OFF;
	/* Disable CAN Move Out End Interrupt Set */
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.MOENDIE = STD_OFF;

	/* Set Default Interrupt Priority Group 3V1 */
	INTERRUPT_REG.CTL0.B.PRIGROUP = 0x00;

	/* Enable Can Controller Module Interrrupt  */
	if (Can_Controller_Index == 0)
	{
		INTERRUPT_REG.EIE2.B.CANFD6IE = STD_ON;
		/* Set Preemption Priority */
		INTERRUPT_REG.IP11.B.PRI50P = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->PreemptionPriority;
		/* Set Sub Priority */
		INTERRUPT_REG.IP11.B.PRI50S = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->SubPriority;
	}
	else if (Can_Controller_Index == 1)
	{
		INTERRUPT_REG.EIE2.B.CANFD7IE = STD_ON;
		/* Set Preemption Priority */
		INTERRUPT_REG.IP11.B.PRI51P = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->PreemptionPriority;
		/* Set Sub Priority */
		INTERRUPT_REG.IP11.B.PRI51S = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->SubPriority;
	}
	else
	{
	}
	/* Enable interrupts */
	INTERRUPT_REG.CTL0.B.AIE = STD_ON;
}



/**
 * ����   ���ݹ���ʱ��ԴƵ��/���߲�����/�����㣬����CAN֡���������ò�����
 * ����   Clk_Frequency: ����ʱ��ԴƵ�ʣ���λHZ��
 *      Bit_rate :���߲����ʣ���λbit/s��
 *      Samp_point �������㣨��λ%��
 *      Can_BDRConfig :CAN֡���������ýṹ��ָ��
 * ����   �����ʲ�������Χ����λ�룩
 */

uint8_t Can_BitrateToTimeSeg(uint32_t Clk_Frequency ,uint32_t Bit_Rate,uint8_t Samp_Point, Can_BDRConfigType *Can_BDRConfig)
{
	uint32_t tembitrate = 0 ,temsample = 0;
	double tseg_1 = 0,tseg1_int = 0;
	uint8_t tem_sam_diff = 0,min_sam_diff = 100U;
	uint32_t tem_bitrate_diff = 0;
	uint8_t temsap = 0,tempre = 0,temtseg1 = 0,temtseg2 = 0,temtqnum = 0,tseg1 = 0,tseg2 = 0;
	uint8_t ret = 100;
	for(tempre = 1;tempre<MAX_CAN_PRESDIV_NUMBER+1;tempre++)
	{
		 /* Compute the number of time quanta in 1 bit time */
		temtqnum = Clk_Frequency/(Bit_Rate*tempre);
		/* Compute the real bitrate resulted */
		tembitrate = Clk_Frequency/(temtqnum*tempre);
		if((temtqnum >= Min_TQ_NUMBER) && (temtqnum <= MAX_TQ_NUMBER))
		{
			tseg_1 = (double)(temtqnum*Samp_Point)/100 - 1;
			modf(tseg_1,&tseg1_int);
			if(abs((tseg1_int+1)*100/temtqnum - Samp_Point) >abs(tseg1_int*100/temtqnum - Samp_Point))
			{
				tseg1 = tseg1_int;
			}else
			{
				tseg1 = tseg1_int+1;
			}
			tseg2 = temtqnum - tseg1 - 1;
			while((tseg1 > MAX_TSEG1_NUMBER) || (tseg2 < MIN_TSEG2_NUMBER))
			{
				tseg1 -=1;
				tseg2 +=1;
			}
			if((tseg1 > MAX_TSEG1_NUMBER) || (tseg2 > MAX_TSEG1_NUMBER) || \
			   (tseg1 < MIN_TSEG1_NUMBER) || (tseg2 < MIN_TSEG2_NUMBER))
			{
				continue;
			}
			temsample = ((1+tseg1)*1000)/temtqnum;
			tem_sam_diff = abs(Samp_Point*10 - temsample);
			tem_bitrate_diff = abs(Bit_Rate - tembitrate);
			if(tem_bitrate_diff == 0)
			{
				if(tem_sam_diff <= min_sam_diff)
				{
					min_sam_diff = tem_sam_diff;

					Can_BDRConfig->PreScale = tempre -1;
					Can_BDRConfig->TSeg1 = tseg1 -1;
					Can_BDRConfig->TSeg2 = tseg2 -1;
					Can_BDRConfig->SampleTimes = CAN_SAMPLE_ONCE;
					Can_BDRConfig->Sjw = 1U;
					ret = min_sam_diff;
					if(ret <=10)
					{
						break;
					}
				}
			}
		}
	}
	return ret;
}




static void Read_Code(Canfd_MailboxHeaderType *Can_MailboxHeader, DataBuffer_8byteType *DataBuffer)
{
	if(DataBuffer->SFF.IDE == 0x00)
	{
		if(DataBuffer->SFF.RRTR == 0x00)
		{
			Can_MailboxHeader->Can_id  = CAN_DATA_STANDARD;
		}else
		{
			Can_MailboxHeader->Can_id  = CAN_REMOTE_STANDARD;
		}
	}else if(DataBuffer->SFF.IDE == STD_ON)
	{
		if(DataBuffer->EFF.RRTR == 0x00)
		{
			Can_MailboxHeader->Can_id  = CAN_DATA_EXTENDED;
		}else
		{
			Can_MailboxHeader->Can_id  = CAN_REMOTE_EXTENDED;
		}
	}
	Can_MailboxHeader->Can_frame = DataBuffer->SFF.EDL;
	Can_MailboxHeader->Timestamp = DataBuffer->SFF.TIMESTAMP;
	Can_MailboxHeader->BRS = DataBuffer->SFF.BRS;
	Can_MailboxHeader->FrameData.Data_Length = DataBuffer->SFF.DLC;
}

static void Std_Reverse_Data(Canfd_MailboxHeaderType *Can_MailboxHeader, DataBuffer_8byteType *DataBuffer, uint8_t type)
{
	if (type == 0x00)
	{
		DataBuffer->SFF.ID = Can_MailboxHeader->Id;
		DataBuffer->SFF.RRTR = (Can_MailboxHeader->Can_id>1)?1:0;
		DataBuffer->SFF.DATA0 = Can_MailboxHeader->FrameData.U8Data[0];
		DataBuffer->SFF.DATA1 = Can_MailboxHeader->FrameData.U8Data[1];
	}
	else
	{
		Can_MailboxHeader->Id = DataBuffer->SFF.ID;
		Can_MailboxHeader->FrameData.U8Data[0] = DataBuffer->SFF.DATA0;
		Can_MailboxHeader->FrameData.U8Data[1] = DataBuffer->SFF.DATA1;
	}
}

static uint32_t Reverse_Int(uint32_t DATA32)
{
	uint32_t temp = 0x00;
	temp = ((DATA32 & 0x000000FF) << 24) + ((DATA32 & 0x0000FF00) << 8) + ((DATA32 & 0x00FF0000) >> 8) + ((DATA32 & 0xFF000000) >> 24);
	return temp;
}


/* Make The MailBox Code Segment Configuration Into Integer Number*/
static Code_Segment Can_m_FdCsCodeSet(Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	Code_Segment Ret_Code_Seg = {0};
	if (Can_MailboxHeader->BRS == STD_ON)
	{
		Ret_Code_Seg.BRS = STD_ON;
	}

	if (Can_MailboxHeader->Can_frame == CAN_FRAME_FD)
	{
		Ret_Code_Seg.EDL = STD_ON;
	}

	Ret_Code_Seg.DLC = Can_MailboxHeader->FrameData.Data_Length;
	Ret_Code_Seg.CODE = Can_MailboxHeader->TransceiveType;

	switch (Can_MailboxHeader->Can_id)
	{
		case CAN_DATA_STANDARD:
		{
			Ret_Code_Seg.IDE = 0x00;
			Ret_Code_Seg.RTR = 0x00;
			break;
		}
		case CAN_DATA_EXTENDED:
		{
			Ret_Code_Seg.IDE = STD_ON;
			Ret_Code_Seg.RTR = 0x00;
			break;
		}
		case CAN_REMOTE_STANDARD:
		{
			Ret_Code_Seg.IDE = 0x00;
			Ret_Code_Seg.RTR = STD_ON;
			break;
		}
		case CAN_REMOTE_EXTENDED:
		{
			Ret_Code_Seg.IDE = STD_ON;
			Ret_Code_Seg.RTR = STD_ON;
			break;
		}
	}
	return Ret_Code_Seg;
}

/* Avoid Cpu And Hardware Can Module Conflict */
static Can_ReturnType Can_m_FdWaitConfilct(const uint8_t Can_Controller_Index,const uint8_t Loop)
{
	volatile uint32_t conflict_loop_count = Loop;
	Can_ReturnType ret = CAN_UNINITIALIZED;
	while (1)
	{
		if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.BOFF == 0x00)
		{
			if((CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.ROPSTA == 0) || ((conflict_loop_count--) == 0))
			{
				ret = CAN_OK;
				break;
			}
		}
		else
		{
			ret = CAN_ERROR_BUSOFF;
			break;
		}
	}
	return ret;
}

/* Set Configuration Infor To Ram */
static Can_ReturnType Can_m_FdCopyDataTo8MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint8_t delay_time1 = FUNCTION_ENABEL_TIME;
	volatile uint8_t delay_time2 = FUNCTION_ENABEL_TIME;
	Can_IdFrameType can_id = Can_MailboxHeader->Can_id;
	Code_Segment Ret_Code_Segment = {0};
	Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK)
	{
		if (((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE == MAIL_TRANSMIT)
		{
			ret = CAN_BUSY_TRANSMIT_MAILBOX;
		}
		else if (((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE == MAIL_RECEIVE)
		{
			ret = CAN_BUSY_RECEIVE_MAILBOX;
		}
		else
		{
			do{
					if(CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)
					{
						CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 1;
						while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1) && (delay_time1--));
						CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 0;
					}
					if (can_id %2 == 0)
					{
						/* standard frame format */
						Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number, 0);
						((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[0] = Reverse_Int(Can_MailboxHeader->FrameData.SU32Data[0]);
						((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[1] = Reverse_Int(Can_MailboxHeader->FrameData.SU32Data[1]);
					}
					else if (can_id %2 == 1)
					{
						/* extended frame format */
						((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.RRTR =  (Can_MailboxHeader->Can_id>1)?1:0;
						((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID = Can_MailboxHeader->Id;
						((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[0] = Reverse_Int(Can_MailboxHeader->FrameData.U32Data[0]);
						((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[1] = Reverse_Int(Can_MailboxHeader->FrameData.U32Data[1]);
					}
					((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
			}while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)&&(delay_time2--));
		}
	}
	return ret;
};

/* Get Message Infor From Ram */
static Can_ReturnType Can_m_FdCopyDataFrom8MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint8_t delay_time1 = FUNCTION_ENABEL_TIME;
	volatile uint8_t delay_time2 = FUNCTION_ENABEL_TIME;
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK)
	{
		do{
			if(CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)
			{
				CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 1;
				while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1) && (delay_time1--));
				CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 0;
			}
			Read_Code(Can_MailboxHeader, (DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number);
			if (Can_MailboxHeader->Can_id == CAN_DATA_STANDARD)
			{
				Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number, 1);
				Can_MailboxHeader->FrameData.SU32Data[0] = Reverse_Int(((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[0]);
				Can_MailboxHeader->FrameData.SU32Data[1] = Reverse_Int(((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[1]);
			}
			else
			{
				Can_MailboxHeader->Id = ((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID;
				Can_MailboxHeader->FrameData.U32Data[0] = Reverse_Int(((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[0]);
				Can_MailboxHeader->FrameData.U32Data[1] = Reverse_Int(((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[1]);
			}
			((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE = Can_MailBox;
		}while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)&&(delay_time2--));
	}
	return ret;
}

/* Set Configuration Infor To Ram */
static Can_ReturnType Can_m_FdCopyDataTo16MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	volatile uint8_t delay_time1 = FUNCTION_ENABEL_TIME;
	volatile uint8_t delay_time2 = FUNCTION_ENABEL_TIME;
	Can_IdFrameType can_id = Can_MailboxHeader->Can_id;
	Code_Segment Ret_Code_Segment = {0};
	Can_ReturnType ret = CAN_UNINITIALIZED;
	Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK)
	{
		if (((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE == MAIL_TRANSMIT)
		{
			ret = CAN_BUSY_TRANSMIT_MAILBOX;
		}
		else if (((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE == MAIL_RECEIVE)
		{
			ret = CAN_BUSY_RECEIVE_MAILBOX;
		}
		else
		{
			do{
				if(CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)
				{
					CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 1;
					while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1) && (delay_time1--));
					CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 0;
				}
				if (can_id %2 == 0)
				{
					Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number), 0);
					for (uint8_t i = 0; i < 4; i++)
					{
						((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.SU32Data[i]);
					}
				}
				else if (can_id %2 == 1)
				{
					((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.RRTR =  (Can_MailboxHeader->Can_id>1)?1:0;
					((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID = Can_MailboxHeader->Id;
					for (uint8_t i = 0; i < 4; i++)
					{
						((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.U32Data[i]);
					}
				}
				((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;

			}while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)&&(delay_time2--));
		}
	}
	return ret;
}

/* Get Message Infor From Ram */
static Can_ReturnType Can_m_FdCopyDataFrom16MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint8_t delay_time1 = FUNCTION_ENABEL_TIME;
	volatile uint8_t delay_time2 = FUNCTION_ENABEL_TIME;
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK)
	{
		do{
			if(CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)
			{
				CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 1;
				while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1) && (delay_time1--));
				CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 0;
			}
			Read_Code(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number));
			if (Can_MailboxHeader->Can_id == CAN_DATA_STANDARD)
			{
				Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number), 1);
				for (uint8_t i = 0; i < 4; i++)
				{
					Can_MailboxHeader->FrameData.SU32Data[i] = Reverse_Int(((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[i]);
				}
			}
			else
			{
				Can_MailboxHeader->Id = ((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID;
				for (uint8_t i = 0; i < 4; i++)
				{
					Can_MailboxHeader->FrameData.U32Data[i] = Reverse_Int(((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[i]);
				}
			}
			((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE = Can_MailBox;
		}while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)&&(delay_time2--));
	}
	return ret;
}

/* Set Configuration Infor To Ram */
static Can_ReturnType Can_m_FdCopyDataTo32MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint8_t delay_time1 = FUNCTION_ENABEL_TIME;
	volatile uint8_t delay_time2 = FUNCTION_ENABEL_TIME;
	Can_IdFrameType can_id = Can_MailboxHeader->Can_id;
	Code_Segment Ret_Code_Segment = {0};
	Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK)
	{
		if (((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE == MAIL_TRANSMIT)
		{
			ret = CAN_BUSY_TRANSMIT_MAILBOX;
		}
		else if (((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE == MAIL_RECEIVE)
		{
			ret = CAN_BUSY_RECEIVE_MAILBOX;
		}
		else
		{
			do{
				if(CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)
				{
					CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 1;
					while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1) && (delay_time1--));
					CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 0;
				}
				if (can_id %2 == 0)
				{
					Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number), 0);
					for (uint8_t i = 0; i < 8; i++)
					{
						((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.SU32Data[i]);
					}
				}
				else if (can_id %2 == 1)
				{
					((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.RRTR =  (Can_MailboxHeader->Can_id>1)?1:0;
					((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID = Can_MailboxHeader->Id;
					for (uint8_t i = 0; i < 8; i++)
					{
						((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.U32Data[i]);
					}
				}
				((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
			}while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)&&(delay_time2--));
		}
	}
	return ret;
}

/* Get Configuration Infor From Ram */
static Can_ReturnType Can_m_FdCopyDataFrom32MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint8_t delay_time1 = FUNCTION_ENABEL_TIME;
	volatile uint8_t delay_time2 = FUNCTION_ENABEL_TIME;
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK)
	{
		do{
			if(CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)
			{
				CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 1;
				while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1) && (delay_time1--));
				CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 0;
			}
			Read_Code(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number));
			if (Can_MailboxHeader->Can_id == CAN_DATA_STANDARD)
			{
				Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number), 1);
				for (uint8_t i = 0; i < 8; i++)
				{
					Can_MailboxHeader->FrameData.SU32Data[i] = Reverse_Int(((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[i]);
				}
			}
			else
			{
				Can_MailboxHeader->Id = ((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID;
				for (uint8_t i = 0; i < 8; i++)
				{
					Can_MailboxHeader->FrameData.U32Data[i] = Reverse_Int(((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[i]);
				}
			}
			((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE = Can_MailBox;
		}while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)&&(delay_time2--));
	}
	return ret;
}

/* Set Configuration Infor To Ram */
static Can_ReturnType Can_m_FdCopyDataTo64MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	Code_Segment Ret_Code_Segment = {0};
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint8_t delay_time1 = FUNCTION_ENABEL_TIME;
	volatile uint8_t delay_time2 = FUNCTION_ENABEL_TIME;
	Can_IdFrameType can_id = Can_MailboxHeader->Can_id;
	Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK)
	{
		if (((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE == MAIL_TRANSMIT)
		{
			ret = CAN_BUSY_TRANSMIT_MAILBOX;
		}
		else if (((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE == MAIL_RECEIVE)
		{
			ret = CAN_BUSY_RECEIVE_MAILBOX;
		}
		else
		{
			do{
				if(CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)
				{
					CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 1;
					while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1) && (delay_time1--));
					CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 0;
				}
				if (can_id %2 == 0)
				{
					Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number), 0);
					for (uint8_t i = 0; i < 15; i++)
					{
						((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.SU32Data[i]);
					}
					((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA62 = Can_MailboxHeader->FrameData.EU8Data[0];
					((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA63 = Can_MailboxHeader->FrameData.EU8Data[1];
				}
				else if (can_id %2 == 1)
				{
					((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.RRTR =  (Can_MailboxHeader->Can_id>1)?1:0;
					((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID = Can_MailboxHeader->Id;
					for (uint8_t i = 0; i < 16; i++)
					{
						((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.U32Data[i]);
					}
				}
				((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
			}while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)&&(delay_time2--));
		}
	}
	return ret;
}

/* Get Configuration Infor From Ram */
static Can_ReturnType Can_m_FdCopyDataFrom64MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint8_t delay_time1 = FUNCTION_ENABEL_TIME;
	volatile uint8_t delay_time2 = FUNCTION_ENABEL_TIME;
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK)
	{
		do{
			if(CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)
			{
				CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 1;
				while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1) && (delay_time1--));
				CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.FAILCLR = 0;
			}
			Read_Code(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number));
			if (Can_MailboxHeader->Can_id == CAN_DATA_STANDARD)
			{
				Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number), 1);
				for (uint8_t i = 0; i < 15; i++)
				{
					Can_MailboxHeader->FrameData.SU32Data[i] = Reverse_Int(((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[i]);
				}
				Can_MailboxHeader->FrameData.EU8Data[0] = ((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA62;
				Can_MailboxHeader->FrameData.EU8Data[1] = ((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA63;
			}
			else
			{
				Can_MailboxHeader->Id = ((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID;
				for (uint8_t i = 0; i < 16; i++)
				{
					Can_MailboxHeader->FrameData.U32Data[i] = Reverse_Int(((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[i]);
				}
			}
			((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE = Can_MailBox;
		}while((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.DPRAMOF == 1)&&(delay_time2--));
	}
	return ret;
}


#if (HARDWARE_FILTER == STD_ON)
/* Set The Can Filter Code And Mask Code) */
static void Can_m_FdFilterInit(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex)
{
	uint8_t MailBoxCount = 0;
	Can_m_FdMailBoxMaskErase(Can_Controller_Index);
	/* Enable MailBox Mask */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.B.MBMSKEN = STD_ON;

	if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
	{
		for (uint8_t mailbox_count = 0; mailbox_count < MAX_8MAILBOX_NUMBER; mailbox_count++)
		{
			if (Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_STANDARD)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 21);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x1FFFFB;
			}
			else if(Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_EXTENDED)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 3);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x03;
			}
		}
	}
	else if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
	{
		for (uint8_t mailbox_count = 0; mailbox_count < MAX_16MAILBOX_NUMBER; mailbox_count++)
		{
			if (Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_STANDARD)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 21);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x1FFFFB;
			}
			else if(Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_EXTENDED)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 3);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x03;
			}
		}
	}
	else if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
	{
		for (uint8_t mailbox_count = 0; mailbox_count < MAX_32MAILBOX_NUMBER; mailbox_count++)
		{
			if (Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_STANDARD)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 21);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x1FFFFB;
			}
			else if(Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_EXTENDED)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 3);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x03;
			}
		}
	}
	else if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
	{
		for (uint8_t mailbox_count = 0; mailbox_count < MAX_64MAILBOX_NUMBER; mailbox_count++)
		{
			if (Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_STANDARD)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 21);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x1FFFFB;
			}
			else if(Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_EXTENDED)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 3);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x03;
			}
		}
	}
}
#endif




#if (TRANSMIT_DELAY_CONPENSATION == STD_ON)
static void Can_m_FdTDCSet(const uint8_t Can_Controller_Index)
{
	uint8_t tq_ns = 0;
	uint8_t delay_tq = 0;
	uint8_t prescale = 0;
	uint16_t delay_ns = 0;
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR2.B.TDCEN  = STD_ON;
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR2.B.DESEL = STD_ON;
	CANFD_PTR[Can_Controller_Index]->CANFD_EROR.B.SFDEN = STD_ON;
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR2.B.TEST0  = STD_OFF;
#if (CONPENSATION_AUTO == STD_OFF)
#if (WORKSOURCE_HFCLK == STD_ON)
	tq_ns = 1000/CANFD_HFCLK_MHZ+1;
#else
	tq_ns = 1000/CANFD_SCLK_MHZ+1;
#endif
	delay_ns = (Can_Controller_Index == CANfd6)?CANFD6_TRANSMIT_DELAY_NS:CANFD7_TRANSMIT_DELAY_NS;
	prescale = (CANFD_PTR[Can_Controller_Index]->CANFD_BRGR.B.BRSBRP+1);
	delay_tq  = (delay_ns+50)/(tq_ns);
	delay_tq  = delay_tq/(prescale);
	/* enable sample point deviation */
	CANFD_PTR[Can_Controller_Index]->CANFD_EROR.B.SFDMOD = STD_ON;
	CANFD_PTR[Can_Controller_Index]->CANFD_EROR.B.SOSFD = delay_tq;

#else
	CANFD_PTR[Can_Controller_Index]->CANFD_EROR.B.SFDMOD = STD_OFF;
	CANFD_PTR[Can_Controller_Index]->CANFD_EROR.B.SOSFD = 0;
#endif
}
#endif


/**
 * ����   дCANFD���䡣
 * ����   Can_Controller_Index: CANFD��������ţ�ȡֵΪ CANfd6��CANfd7��
 *      Mailbox_Number������ţ�ȡֵΪMailbox_0~Mailbox_50
 *      Can_MailboxHeader��CANFD����ͷ�������ýṹ����
 * ����   ret�� CAN_OK    					���
 * 		  CAN_BUSY  					����æµ
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     ��������æµ
 *			  CAN_BUSY_RECEIVE_MAILBOX      ��������æµ
 *	          CAN_ERROR_TIMEOUT_ARBITRATE   ���������ٲù����޷�����
 *		      CAN_ERROR_ARBITRATE_FAIL      ���������ڲ��ٲ�ʧ��
 *		 	  CAN_ERROR_ARBITRATE_LOSE      ���ͱ������߸����ȼ�������ռ
 *		 	  CAN_ERROR_BUSOFF              CAN�������ڵ㴦��BUSOFF״̬
 *		 	  CAN_RAM_RXSTA           		RAM���ڽ���״̬�쳣
 *		 	  CAN_RAM_TXSTA          		RAM���ڷ���״̬�쳣
 *	 		  CAN_UNINITIALIZED             ״̬λ����δ��ʼ��״̬
 *           CAN_ERROR_CONFIGURATE          CAN��������ʼ�����ô���
 */
Can_ReturnType Can_m_FdMailBox_Write(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	Can_ReturnType (*func)(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader) = NULL_PTR;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CANFD_MESSAGE_DLC(Can_MailboxHeader->FrameData.Data_Length));
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_MAILBOX_TYPE(Can_MailboxHeader->TransceiveType));
	switch(CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE)
	{
	case CAN_8_BYTE_DATALENGTH:
		func = &Can_m_FdCopyDataTo8MailBox;
		break;
	case CAN_16_BYTE_DATALENGTH:
		func = &Can_m_FdCopyDataTo16MailBox;
		break;
	case CAN_32_BYTE_DATALENGTH:
		func = &Can_m_FdCopyDataTo32MailBox;
		break;
	case CAN_64_BYTE_DATALENGTH:
		func = &Can_m_FdCopyDataTo64MailBox;
		break;
	default:
		break;
	}
	ret = func(Can_Controller_Index, Mailbox_Number, Can_MailboxHeader);
	return ret;
}

/**
 * ����   ��CANFD���� ,����֮������������������
 * ����   Can_Controller_Index: CANFD��������ţ�ȡֵΪ CANfd6��CANfd7��
 *      Mailbox_Number������ţ�ȡֵΪMailbox_0~Mailbox_50
 *      Can_MailboxHeader��CANFD����ͷ�������ýṹ����
 * ����   ret�� CAN_OK    ���
 * 		  CAN_BUSY  ����æµ
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     ��������æµ
 *			  CAN_BUSY_RECEIVE_MAILBOX      ��������æµ
 *	          CAN_ERROR_TIMEOUT_ARBITRATE   ���������ٲù����޷�����
 *		      CAN_ERROR_ARBITRATE_FAIL      ���������ڲ��ٲ�ʧ��
 *		 	  CAN_ERROR_ARBITRATE_LOSE      ���ͱ������߸����ȼ�������ռ
 *		 	  CAN_ERROR_BUSOFF              CAN�������ڵ㴦��BUSOFF״̬
 *		 	  CAN_RAM_RXSTA           RAM���ڽ���״̬�쳣
 *		 	  CAN_RAM_TXSTA           RAM���ڷ���״̬�쳣
 *	 		  CAN_UNINITIALIZED             ״̬λ����δ��ʼ��״̬
 *           CAN_ERROR_CONFIGURATE         CAN��������ʼ�����ô���
 */
Can_ReturnType Can_m_FdMailBox_Read(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	Can_ReturnType (*func)(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox) = NULL_PTR;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	switch(CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE)
	{
	case CAN_8_BYTE_DATALENGTH:
		func = &Can_m_FdCopyDataFrom8MailBox;
		break;
	case CAN_16_BYTE_DATALENGTH:
		func = &Can_m_FdCopyDataFrom16MailBox;
		break;
	case CAN_32_BYTE_DATALENGTH:
		func = &Can_m_FdCopyDataFrom32MailBox;
		break;
	case CAN_64_BYTE_DATALENGTH:
		func = &Can_m_FdCopyDataFrom64MailBox;
		break;
	default:
		break;
	}
	ret = func(Can_Controller_Index, Mailbox_Number, Can_MailboxHeader, Can_MailBox);
	return ret;
}


/**
 * ����   CANFD���䷢�͡�
 * ����   Can_Controller_Index: CANFD��������ţ�ȡֵΪ CANfd6��CANfd7��
 * ����   ret�� CAN_OK    ���
 * 		  CAN_BUSY  ����æµ
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     	��������æµ
 *			  CAN_BUSY_RECEIVE_MAILBOX      ��������æµ
 *	          CAN_ERROR_TIMEOUT_ARBITRATE   ���������ٲù����޷�����
 *		      CAN_ERROR_ARBITRATE_FAIL      ���������ڲ��ٲ�ʧ��
 *		 	  CAN_ERROR_ARBITRATE_LOSE      ���ͱ��ı����߸����ȼ�������ռ
 *		 	  CAN_ERROR_ARBITRATE_DELAY     ���ͱ��ı����߸����ȼ�������ռ�����ȵ����߿��лᷢ����
 *		 	  CAN_ERROR_BUSOFF              CAN�������ڵ㴦��BUSOFF״̬
 *		 	  CAN_RAM_RXSTA           		RAM���ڽ���״̬�쳣
 *		 	  CAN_RAM_TXSTA           		RAM���ڷ���״̬�쳣
 *	 		  CAN_UNINITIALIZED             ״̬λ����δ��ʼ��״̬
 *           CAN_ERROR_CONFIGURATE          CAN��������ʼ�����ô���
 */

Can_ReturnType Can_m_FdTransmit(const uint8_t Can_Controller_Index)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.BOFF == 0x00)
	{
		if (CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.ARBSTA1 == STD_ON)
		{
			CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.B.ARBSTART = STD_ON;
			CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.B.ARBSTART = 0x00;
		}
		ret = CAN_OK;
	}
	else
	{
		/* CAN BUSOFF */
		ret = CAN_ERROR_BUSOFF;
	}
	return ret;
}

/**
 * ����  CANFD��ȡ�жϱ�־λ��
 * ����   Can_Controller_Index : CANFD��������ţ�ȡֵΪCANfd6��CANfd7��
 *      Can_Controller_InterruptFlag ��CANFD�жϱ�־λ
 *      			RxIntFlag�������жϱ�־λ
 *      			TxIntFlag�������жϱ�־λ
 *      			BusOffFlag�����߹ر��жϱ�־λ
 *      			WakeUpFlag�������жϱ�־λ
 *      			ErrorAlarmFlag�����󱨾��жϱ�־λ
 *      			OverFlowFlag����������жϱ�־λ
 *					ErrorNegativeFlag�����������жϱ�־λ
 *					ArbitrateLoseFlag����ռ��ʧ�жϱ�־λ
 *					BusErrorFlag�����ߴ����жϱ�־λ
 *					DmaTXDFlag��DMA�����жϱ�־λ
 *					DmaRXDFlag��DMA�����жϱ�־λ
 *				    rmc_count����ֵ
 * ����  �ޡ�
 */
void Can_m_FdGetIntFlag(const uint8_t Can_Controller_Index, Can_Controller_InterruptFlagType *Can_Controller_InterruptFlag, uint8_t *rmc_count)
{
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	Can_Controller_InterruptFlag->EntireFlag = CANFD_PTR[Can_Controller_Index]->CANFD_IFR.R.Canfd_Interrupt_Flag;
	/* get canfd controller receive message number */
	*rmc_count = CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.CANRMC;
}

/**CANFD_PTR[Can_Controller_Index]
 * ����  CANFD��ȡ�жϱ�־λ,�����ڷ��ж���ʹ��
 * ����   Can_Controller_Index : CANFD��������š�
 *      Can_Controller_InterruptFlag ��
 *      			Rx_Flag�����ձ�־λ
 *      			Tx_Flag�����ͱ�־λ
 *      			BusOff_Flag�����߹رձ�־λ
 *      			WakeUp_Flag�����ѱ�־λ
 *      			ErrorAlarm_Flag�����󱨾���־λ
 *      			OverFlow_Flag�����������־λ
 *					ErrorNegative_Flag������������־λ
 *					ArbitrateLose_Flag����ռ��ʧ��־λ
 *					BusError_Flag�����ߴ����־λ
 *					DmaTXD_Flag: DMA���ͱ�־λ
 *					DmaRXD_Flag��DMA���ձ�־λ
 * ����  �ޡ�
 */
FlagStatus Can_m_FdGetFlag(const uint8_t Can_Controller_Index, const Can_Controller_InterruptType Can_Controller_Interrupt)
{
    /* Controller Index Number Verification */
    CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
    return (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.R.Canfd_Interrupt_Flag & Can_Controller_Interrupt);
}

/**
 * ����  CANFD����жϱ�־λ��
 * ����   Can_Controller_Index : CANFD��������ţ�ȡֵΪCANfd6��CANfd7��
 *      Can_Controller_InterruptFlag ��CANFD�жϱ�־λ
 *      			RxIntFlag�������жϱ�־λ
 *      			TxIntFlag�������жϱ�־λ
 *      			BusOffFlag�����߹ر��жϱ�־
 *      			WakeUpFlag�������жϱ�־λ
 *      			ErrorAlarmFlag�����󱨾��жϱ�־λ
 *      			OverFlowFlag����������жϱ�־λ
 *					ErrorNegativeFlag�����������жϱ�־λ
 *					ArbitrateLoseFlag����ռ��ʧ�жϱ�־λ
 *					BusErrorFlag�����ߴ����жϱ�־λ
 *					DmaTXDFlag��DMA�����жϱ�־λ
 *					DmaRXDFlag��DMA�����жϱ�־λ
 *				    rmc_count����ֵ
 * ����  �ޡ�
 */
ClearFlag_ReturnType Can_m_FdClearIntFlag(const uint8_t Can_Controller_Index, Can_Controller_InterruptFlagType *Can_Controller_InterruptFlag, uint8_t rmc_count)
{
	ClearFlag_ReturnType ret = {0};
	volatile uint32_t delay_time = CLEAR_FLAG_TIME;
	volatile uint32_t Rcr_Value = 0;

	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	/* Clear Arbitrate Lose Flag */
	if ((Can_Controller_InterruptFlag->ArbitrateLoseFlag == STD_ON) && (CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ALIE == STD_ON))
	{
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ALIC = STD_ON;
		while ((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.ALIF == STD_ON) && (delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ALIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Arbitrateloseclear_Timeout = STD_ON;
		}
#if (AIBITRATE_SOFTRETRANAMIT ==STD_ON)
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.TXR = 0x00;
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.ATX = STD_ON;
		asm("nop");		asm("nop");		asm("nop");
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.ATX = 0x00;
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.TXR = STD_ON;
//		((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + AIBITRATE_SOFTRETRANSMITMAILBOX)->SFF.CS_CODE = 0xC008;
#endif
	}

	/* Clear Recevie Success Flag */
	if ((Can_Controller_InterruptFlag->RxIntFlag == STD_ON) && (CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANRXIE == STD_ON))
	{
		// if(CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.BETEN == STD_OFF)
		// {
		// 	CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.BETEN = STD_ON;
		// }
		delay_time = CLEAR_FLAG_TIME;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANRXIC = STD_ON;
		while (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.CANRXIF == STD_ON && (delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANRXIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Receiveclear_Timeout = STD_ON;
		}
	}else if(Can_Controller_InterruptFlag->RxIntFlag == STD_ON)
	{
		if(CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.BETEN = STD_OFF)
		{
			CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.BETEN = STD_ON;
		}
	}

	/* Clear Bus Error Flag */
	if ((Can_Controller_InterruptFlag->BusErrorFlag == STD_ON) && (CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BEIE == STD_ON))
	{
#if (AVOIDERRORARBITRATE_WRITEMAILBOX == STD_ON)
		((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + ERRORARBITRATE_WRITEMAILBOX)->SFF.CS_CODE = 0xC008;
#endif
#if (HARDWARE_RETRANSMIT == STD_OFF)
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.TXR = 0x00;
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.ATX = STD_ON;
		asm("nop");		asm("nop");		asm("nop");
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.ATX = 0x00;
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.TXR = STD_ON;
#elif (SOFACK_NORETRANSMIT == STD_ON)
		/* Disable Hardware Aotu ReTransmmit */
		if (CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.CANDIR == 0x00)
		{
			if ((CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.CANSEG == 0x03) || (CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.CANSEG == 0x19))
			{
				CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.TXR = 0x00;
				CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.ATX = STD_ON;
				asm("nop");		asm("nop");		asm("nop");
				CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.ATX = 0x00;
				CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.TXR = STD_ON;
			}
		}
#endif
		// if(CANFD_PTR[Can_Controller_Index]->CANFD_RCR.B.CANDIR == STD_OFF)
		// {
		// 	CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.BETEN = STD_OFF;
		// }
		delay_time = CLEAR_FLAG_TIME;
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BEIC = STD_ON;
		while (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.BEIF == STD_ON && (delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BEIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Buserrorclear_Timeout = STD_ON;
		}
	}

	/* Clear Bus Off Flag */
	if ((Can_Controller_InterruptFlag->BusOffFlag == STD_ON) && (CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BOFFIE == STD_ON))
	{
		delay_time = CLEAR_FLAG_TIME;
#if (CAN_BUSOFF_RECOVERY_INTERRUPT == STD_ON)
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.RSMOD = STD_ON;
		while(delay_time--);
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.RSMOD = 0x00;
#endif
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BOFFIC = STD_ON;
		while (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.BOFFIF == STD_ON && (delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.BOFFIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Busoffclear_Timeout = STD_ON;
		}
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.TXR = STD_ON;
	}

	/* Clear Error Alarm Flag */
	if ((Can_Controller_InterruptFlag->ErrorAlarmFlag == STD_ON) && (CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.EAIE == STD_ON))
	{
		delay_time = CLEAR_FLAG_TIME;
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.EAIC = STD_ON;
		while (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.EAIF == STD_ON && (delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.EAIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Erroralarmclear_Timeout = STD_ON;
		}
	}

	/* Clear Wake Up Flag */
	if ((Can_Controller_InterruptFlag->ErrorNegativeFlag == STD_ON) && (CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ENIE == STD_ON))
	{
		delay_time = CLEAR_FLAG_TIME;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ENIC = STD_ON;
		Rcr_Value = CANFD_PTR[Can_Controller_Index]->CANFD_RCR.R;
		while (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.ENIF == STD_ON && (delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.ENIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Errornegativeclear_Timeout = STD_ON;
		}
	}

	/* Clear OverFlow  Flag */
	if ((Can_Controller_InterruptFlag->OverFlowFlag == STD_ON) && (CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.DOVFIE == STD_ON))
	{
		delay_time = CLEAR_FLAG_TIME;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.DOVFIC = STD_ON;
		while (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.DOVFIF == STD_ON && (delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.DOVFIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Overflowclear_Timeout = STD_ON;
		}
	}

	/* Clear Transmit Success Flag */
	if ((Can_Controller_InterruptFlag->TxIntFlag == STD_ON) && (CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANTXIE == STD_ON))
	{
		delay_time = CLEAR_FLAG_TIME;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANTXIC = STD_ON;
		while (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.CANTXIF == STD_ON && (delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.CANTXIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Transmitclear_Timeout = STD_ON;
		}
	}

	/* Clear Wake Up Flag */
	if ((Can_Controller_InterruptFlag->WakeUpFlag == STD_ON) && (CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.WUIE == STD_ON))
	{
		delay_time = CLEAR_FLAG_TIME;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.WUIC = STD_ON;
		while (CANFD_PTR[Can_Controller_Index]->CANFD_IFR.B.WUIF == STD_ON && (delay_time--))
			;
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.B.WUIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Wakeupclear_Timeout = STD_ON;
		}
	}
	/* Clear Receive Message Count */
	for (uint8_t release_count = 0; release_count < rmc_count; release_count++)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.RELRX = STD_ON;
		asm("NOP");		asm("NOP");		asm("NOP");
	}
}

/**
 * ����  CANFD�������жϻ�ȡ�������ڷ��ж���ʹ��
 * ����   Can_Controller_Index: CANFD���������.
 * 	 Can_Controller_Interrupt��
 * 	       			Rx_Flag�����ձ�־λ
 *      			Tx_Flag�����ͱ�־λ
 *      			BusOff_Flag�����߹رձ�־λ
 *      			WakeUp_Flag�����ѱ�־λ
 *      			ErrorAlarm_Flag�����󱨾���־λ
 *      			OverFlow_Flag�����������־λ
 *					ErrorNegative_Flag������������־λ
 *					ArbitrateLose_Flag����ռ��ʧ��־λ
 *					BusError_Flag�����ߴ����־λ
 *					DmaTXD_Flag: DMA���ͱ�־λ
 *					DmaRXD_Flag��DMA���ձ�־λ
 * ����  �ޡ�
 */

void Can_m_FdClearFlag(const uint8_t Can_Controller_Index,\
					const Can_Controller_InterruptType Can_Controller_Interrupt)
{
	ClearFlag_ReturnType ret = {0};
	volatile uint8_t delay_time = CLEAR_FLAG_TIME;
	while((CANFD_PTR[Can_Controller_Index]->CANFD_IFR.R.Canfd_Interrupt_Flag & Can_Controller_Interrupt) && (delay_time--))
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_IER.R |= (Can_Controller_Interrupt<<16);
	}
	CANFD_PTR[Can_Controller_Index]->CANFD_IER.R &= ~(Can_Controller_Interrupt<<16);
    CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.RELRX = (Can_Controller_Interrupt == Rx_Flag)? STD_ON:STD_OFF;
}

/**
 * ����  ���䴥���������á�
 * ����   Can_Controller_Index: CANFD��������ţ�ȡֵΪCANfd6��CANfd7��
 * 	 Can_MailboxNumType: ���������š�
 * 	 Triger_Count���������������
 * ����  �ޡ�
 */
void Can_m_MailboxTrigerSet(const uint8_t Can_Controller_Index,\
					const Can_MailboxNumType MailBox_Number,uint8_t Triger_Count)
{
	volatile uint16_t trigersel = 0;
	switch(CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE)
	{
	case CAN_8_BYTE_DATALENGTH:
		trigersel = sizeof(DataBuffer_8byteType)*MailBox_Number;
		break;
	case CAN_16_BYTE_DATALENGTH:
		trigersel = sizeof(DataBuffer_16byteType)*MailBox_Number;
		break;
	case CAN_32_BYTE_DATALENGTH:
		trigersel = sizeof(DataBuffer_32byteType)*MailBox_Number;
		break;
	case CAN_64_BYTE_DATALENGTH:
		trigersel = sizeof(DataBuffer_64byteType)*MailBox_Number;
		break;
	default:
		break;
	}
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.B.TRGNUM = Triger_Count;
	*((uint8_t *)(&CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.R)+3) = (uint8_t)(trigersel>>3)|(0x01<<7);
}

/**
 * ����   CANFD�����������á�
 * ����   Can_Controller_Index : CANFD��������ţ�ȡֵΪCANfd6��CANfd7��
 *      Mailbox_Number������ţ�ȡֵΪMailbox_0~Mailbox_50��
 *      Can_MailboxHeader������ͷ���ýṹ������
 * ����   ret�� CAN_OK    ���
 * 		  CAN_BUSY  ����æµ
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     ��������æµ
 *			  CAN_BUSY_RECEIVE_MAILBOX      ��������æµ
 *	          CAN_ERROR_TIMEOUT_ARBITRATE   ���������ٲù����޷�����
 *		      CAN_ERROR_ARBITRATE_FAIL      ���������ڲ��ٲ�ʧ��
 *		 	  CAN_ERROR_ARBITRATE_LOSE      ���ͱ������߸����ȼ�������ռ
 *		 	  CAN_ERROR_BUSOFF              CAN�������ڵ㴦��BUSOFF״̬
 *		 	  CAN_RAM_RXSTA                 RAM���ڽ���״̬�쳣
 *		 	  CAN_RAM_TXSTA                 RAM���ڷ���״̬�쳣
 *	 		  CAN_UNINITIALIZED             ״̬λ����δ��ʼ��״̬
 *           CAN_ERROR_CONFIGURATE         CAN��������ʼ�����ô���
 */
Can_ReturnType Can_m_FdMailBoxCode_Set(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	Code_Segment Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if ((ret == CAN_OK) || (ret == CAN_RAM_TXSTA) || (ret == CAN_RAM_RXSTA))
	{
		if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
		{
			((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
		else if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
		{
			((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
		else if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
		{
			((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
		else if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
		{
			((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
	}
	else
	{
	}
	return ret;
}

/**
 * ����   ��ȡCANFD����״̬��
 * ����   Can_Controller_Index : CANFD��������ţ�ȡֵΪCANfd6��CANfd7��
 *      Mailbox_Number������ţ�ȡֵΪMailbox_0~Mailbox_50��
 * ����   Ret_State�� MAIL_UNDEFINED ����δ����
 *     			MAIL_RECEIVE �������
 *     			MAIL_RECEIVE_SUCCESS ������ճɹ�
 *     			MAIL_TRANSMIT ���䷢��
 *     			MAIL_TRANSMIT_SUCCESS ���䷢�ͳɹ�
 *     			MAIL_RTR_REQUEST ����Զ��֡����
 *     			MAIL_RTR_ANSWER ����Զ��֡�ظ�
 */
Can_MailBoxType Can_m_FdGetMailBoxState(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number)
{
	Can_MailBoxType Ret_State = MAIL_UNDEFINED;
	Can_ReturnType ret = CAN_UNINITIALIZED;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_STATE_LOOP_TIME);
	if (ret == CAN_OK)
	{
		if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
		{
			Ret_State = (Can_MailBoxType)(((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE);
		}
		else if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
		{
			Ret_State = (Can_MailBoxType)(((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE);
		}
		else if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
		{
			Ret_State = (Can_MailBoxType)(((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE);
		}
		else if (CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
		{
			Ret_State = (Can_MailBoxType)(((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE);
		}
	}
	return Ret_State;
}

/**
 * ����   ��ȡ������״̬��
 * ����   Can_Controller_Index: CANFD��������š�
 * Can_Controller_StatusType: ��������ǰ״̬,
 *	CANFD_STATUS_OFF:������BUSOFF״̬
 *	CANFD_STATUS_ERROR������������֡״̬
 *	CANFD_STATUS_TRANSMITING�����������ڷ���״̬
 *	CANFD_STATUS_RECEIVEING�����������ڽ���״̬
 *	CANFD_STATUS_TRANSMITED���������������״̬
 *	CANFD_STATUS_TBUFFER�����ͻ�����״̬
 *	CANFD_STATUS_RVOERFLOW��������״̬
 *	CANFD_STATUS_REMPTY�����ݿ�״̬
 *
 * ����  SET: ���߹ر�/����/���ڷ���/���ڽ���/�������/CPU���Է��ʷ��ͻ�����/
 *          RAM��δ��������/RAM����δ����Ϣ��
 *      RESET: ���߿���/�޴�/���Ϳ���/���տ���/����δ���/CPU���ܷ��ʷ��ͻ�����/
 *          RAM��δ������δ��/RAM����δ����Ϣ��
 */
FlagStatus Can_m_FdGetCtrStatus(const uint8_t Can_Controller_Index,Can_Controller_StatusType Can_Controller_Status)
{
	return CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.R & (Can_Controller_Status);
}

/**
 * ����  CANFD���������
 * ����  Can_Controller_Index: CANFD��������ţ�ȡֵΪCANfd6��CANfd7��
 * ����  �ޡ�
 */
void Can_m_FdMailBoxErase(const uint8_t Can_Controller_Index)
{
	uint8_t erase_length = 0;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	switch(CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE)
	{
	case CAN_8_BYTE_DATALENGTH:
		erase_length = 204;
		break;
	case CAN_16_BYTE_DATALENGTH:
		erase_length = 216;
		break;
	case CAN_32_BYTE_DATALENGTH:
		erase_length = 230;
		break;
	case CAN_64_BYTE_DATALENGTH:
		erase_length = 234;
		break;
	default:
		break;
	}

	for (uint8_t erase_count = 0; erase_count < erase_length; erase_count++)
	{
		*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + erase_count) = 0x00000000;
	}
}

/**
 * ����  CANFD�������������
 * ����  Can_Controller_Index: CANFD��������ţ�ȡֵΪCANfd6��CANfd7��
 * ����  �ޡ�
 */
void Can_m_FdMailBoxMaskErase(const uint8_t Can_Controller_Index)
{
	uint8_t erase_length = 0;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	switch(CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE)
	{
	case CAN_8_BYTE_DATALENGTH:
		erase_length = 204;
		break;
	case CAN_16_BYTE_DATALENGTH:
		erase_length = 216;
		break;
	case CAN_32_BYTE_DATALENGTH:
		erase_length = 230;
		break;
	case CAN_64_BYTE_DATALENGTH:
		erase_length = 234;
		break;
	default:
		break;
	}
	for (uint16_t erase_count = erase_length; erase_count < 256; erase_count++)
	{
		*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + erase_count) = 0x00000000;
	}
}

/**
 * ����  CANFD��������λ��
 * ����   Can_Controller_Index: CANFD��������ţ�ȡֵΪ CANfd6��CANfd7��
 * ����  �ޡ�
 */
void Can_m_FdControllerDeInit(const uint8_t Can_Controller_Index)
{
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	if (Can_m_ControllersInfo[Can_Controller_Index].BaseAddress == CAN_HW_CONTROLLER_BASEADDRESS_CANFD6)
	{
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN6RST, TRUE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_CAN6CLKEN, TRUE);
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN6RST, FALSE);
	}
	else if (Can_m_ControllersInfo[Can_Controller_Index].BaseAddress == CAN_HW_CONTROLLER_BASEADDRESS_CANFD7)
	{
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN7RST, TRUE);
        PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_CAN7CLKEN, TRUE);
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN7RST, FALSE);
	}
}

/**
 * ����  CANFD��������ʼ����
 * ����   Can_Controller_Index: CANFD��������ţ�ȡֵΪCANfd6��CANfd7��
 * 	 Can_ControllerConfig��CANFD�������������ͽṹ�塣
 * 	 InitIndex�������ţ�ȡֵΪInitindex_0~Initindex_4��
 * ����  �ޡ�
 */
void Can_m_FdControllerInit(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const Can_InitIndexType InitIndex)
{
	volatile uint8_t delay_count = 0xff;
	SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);
	SFR_SET_BIT_ASM(PM_CAL0, PM_CTL0_VDDPORON_POS);
	SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	/* Disable CAN controller */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.CANEN = STD_OFF;
	/* Set CAN controller to reset work mode */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.RSMOD = CAN_CONTROLLER_RUN_MODE_RESET;
	/* Waitting For Can Controller Go to reset mode */
	while (delay_count--)
		; /*  compound statement  */
	/* Disable Listen-only mode */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.SILENT = CAN_CONTROLLER_MODE_DISABLE_LISTENONLY;
	/* Disable sleep mode */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.SLEEP = CAN_CONTROLLER_MODE_DISABLE_SLEEP;
	/*Canfd Mode Verification*/
	CHECK_RESTRICTION(CHECK_CONTROLLER_MODE(Can_ControllerConfig[InitIndex].CanfdMode));
	if (Can_ControllerConfig[InitIndex].CanfdMode == CANFD_LOOP_INTERNAL_MODE)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.LBACK = CAN_CONTROLLER_MODE_ENABLE_LOOP;
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.B.LBSEL = CAN_CONTROLLER_MODE_ENABLE_INTERLOOP;
	}
	else if (Can_ControllerConfig[InitIndex].CanfdMode == CANFD_LOOP_EXTERNAL_MODE)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.LBACK = CAN_CONTROLLER_MODE_ENABLE_LOOP;
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.B.LBSEL = CAN_CONTROLLER_MODE_DISABLE_INTERLOOP;
	}
	else if (Can_ControllerConfig[InitIndex].CanfdMode == CANFD_SILENT_MODE)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.LBACK = CAN_CONTROLLER_MODE_DISABLE_INTERLOOP;
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.SILENT = CAN_CONTROLLER_MODE_ENABLE_LISTENONLY;
	}
	else if (Can_ControllerConfig[InitIndex].CanfdMode == CANFD_NORMAL_MODE)
	{
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.LBACK = CAN_CONTROLLER_MODE_DISABLE_INTERLOOP;
		CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.SILENT = CAN_CONTROLLER_MODE_DISABLE_LISTENONLY;
	}
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.B.CKMODE = WORKSOURCE_DIVIDE_1;
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.B.BOFFREC = HARDWARE_RECOVERY;
	/* Set Arbitrate Clock Divide */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR2.B.AMCKDIV = Clock_Divide_1;
	/* Canfd Protocal Verification */
	CHECK_RESTRICTION(CHECK_CANFD_PROTOCAL(Can_ControllerConfig[InitIndex].FdFrameType));
	/* Set Canfd Frame type */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.ISOFDCANEN = Can_ControllerConfig[InitIndex].FdFrameType;
	/*Canfd Mailbox Block Size Verification*/
	CHECK_RESTRICTION(CHECK_CONTROLLER_MBSIZE(Can_ControllerConfig[InitIndex].MailBoxBlockSize));
	/* Set Canfd MailBox Block Size */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.MBSIZE = Can_ControllerConfig[InitIndex].MailBoxBlockSize;
	/*Canfd Full Mailbox Receive Or Not Receive Verification */
	CHECK_RESTRICTION(CHECK_CANFD_MAILBOX_FULLSTATE(Can_ControllerConfig[InitIndex].MBFullReceiveEnableSet));
	/* Set Whether Full Canfd MailBox Participate the Receive Match*/
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.FULLRXEN = Can_ControllerConfig[InitIndex].MBFullReceiveEnableSet;
	/*Canfd Work Clock Source Verification*/
	CHECK_RESTRICTION(CHECK_CONTROLLER_WORKCLOCK(CHECK_CONTROLLER_WORKCLOCK(Can_ControllerConfig[InitIndex].ClockSource)));
	/* Set Can Controller Work Clock Source */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.CANCKS = Can_ControllerConfig[InitIndex].ClockSource;
	/*Canfd Arbitrate Clock Source Verification*/
	CHECK_RESTRICTION(CHECK_CONTROLLER_ARBCLOCK(CHECK_CONTROLLER_ARBCLOCK(Can_ControllerConfig[InitIndex].FdArbitrateClockSource)));
	/* Set Can Controller Arbitrate Clock Source */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR1.B.AMCKS = Can_ControllerConfig[InitIndex].FdArbitrateClockSource;
	/* Set Can Controller Global Mask Code */
	CANFD_PTR[Can_Controller_Index]->CANFD_MSKR = Can_ControllerConfig[InitIndex].GlobalMask;
	CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.RTRMEN = STD_ON;
	CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.IDSELEN = STD_ON;
	CANFD_PTR[Can_Controller_Index]->CANFD_AMSTA.B.BETEN = STD_ON;
	CANFD_PTR[Can_Controller_Index]->CANFD_EROR.B.DPRAMFEN = STD_ON;
	/* Set CAN Default baudrate */
	Can_m_FdBaudrateSet(Can_Controller_Index, Can_ControllerConfig, Initindex_0);
	/* Clear Can Intterrupt Flag */
	Can_m_FdClearAllFlag(Can_Controller_Index);
	/* Set The Can Intterrupt  Enable And Clear The Interrupt Flag */
	Can_m_FdIntSet(Can_Controller_Index, Can_ControllerConfig, Initindex_0);
	/* Clear Ram Area Data */
	Can_m_FdMailBoxErase(Can_Controller_Index);
#if (TRANSMIT_DELAY_CONPENSATION == STD_ON)
	Can_m_FdTDCSet(Can_Controller_Index);
#endif
#if (HARDWARE_FILTER == STD_ON)
	/* Set The Can Filter Code */
	Can_m_FdFilterInit(Can_Controller_Index, Can_ControllerConfig, Initindex_0);
#endif
	/* Enable CANFD Mode */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.CANFDEN = STD_OFF;
	/* Enable The Can Controller Module */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.CANEN = STD_ON;
	/* Set CAN Controller to work mode */
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.RSMOD = CAN_CONTROLLER_RUN_MODE_RUN;
	/* CAN  Controller Interrupt Settings */
    delay_count =0xFF;
	while (delay_count--)
		;
	CANFD_PTR[Can_Controller_Index]->CANFD_CTLR0.B.TXR = STD_ON;
}

/**
 * @brief This function handles transmit busy or transmit error
 */
void Can_m_FdTransmiterrorHandler(void)
{
	/*
	 *
	 * */
}

/**
 * @brief This function handles busoff recovery
 */
void Can_m_FdBusoffHandler(void)
{
	/*
	 *
	 * */
}

/**
 * @brief This function handles Flag clear timeout
 */
void Can_m_FdFlagclearHandler(void)
{
	/*
	 *
	 * */
}

#endif

