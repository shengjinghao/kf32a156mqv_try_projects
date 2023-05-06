/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_CANFD.c                              	      *
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
#include "kf32a1x6_canfd.h"
/******************************************************************************
 *                      Variables      Declarations                            *
 ******************************************************************************/
#ifndef KF32A136
uint32_t Transmitcount  = 0x00;
/******************************************************************************
 *                      Private Function Declarations                          *
 ******************************************************************************/
static void Can_m_FdBaudrateSet(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex);
static void Can_m_FdClearAllFlag(const uint8_t Can_Controller_Index);
static void Can_m_FdIntSet(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex);
#if (HARDWARE_FILTER == STD_ON)
static void Can_m_FdFilterInit(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex);
#endif
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

/******************************************************************************
 *                      Private Function Declarations                          *
 ******************************************************************************/

const Can_ControllerInfoType Can_m_ControllersInfo[3] = {
	{CAN_HW_CONTROLLER_BASEADDRESS_CAN4,
	 CAN_HW_CONTROLLER_MBADDRESS_CAN4,
	 CAN_HW_CONTROLLER_FILTERADDRESS_CAN4,
	 CAN_CONTROLLER_CLASSICAL},

	{CAN_HW_CONTROLLER_BASEADDRESS_CANFD6,
	 CAN_HW_CONTROLLER_MBADDRESS_CANFD6,
	 CAN_HW_CONTROLLER_FILTERADDRESS_CANFD6,
	 CAN_CONTROLLER_FD},

	{CAN_HW_CONTROLLER_BASEADDRESS_CANFD7,
	 CAN_HW_CONTROLLER_MBADDRESS_CANFD7,
	 CAN_HW_CONTROLLER_FILTERADDRESS_CANFD7,
	 CAN_CONTROLLER_FD}};

/* Set CAN Default baudrate */
static void Can_m_FdBaudrateSet(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	/* Set CAN Default baudrate */
	/* [$Block Start$] */
	/* Set Can Controller Sample time */
	ControllerRegPtr->CANFD_BRGR.B.SAM = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->SampleTimes;
	/* Set Can Controller Synchronization Jump Width */
	ControllerRegPtr->CANFD_BRGR.B.SJW = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->Sjw;
	/* Set Can Controller Baud Rate Clock Prescale */
	ControllerRegPtr->CANFD_BRGR.B.CNABRP = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->PreScale;
	/* Set T Segment 1 */
	ControllerRegPtr->CANFD_BRGR.B.TSEG1 = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->TSeg1;
	/* Set T Segment 2 */
	ControllerRegPtr->CANFD_BRGR.B.TSEG2 = Can_ControllerConfig[IntIndex].Canfd_Controller_AllClockAndBDRConfig->TSeg2;
	/* [$Block End$] */

	/* [$Block Start$] */
	/* Set Can Controller Baud Rate Switch Prescale */
	ControllerRegPtr->CANFD_BRGR.B.BRSBRP = Can_ControllerConfig[IntIndex].Canfd_Controller_ALLFdBDRConfig->BrsPrescale;
	/* Set Can Controller Baud Rate Switch T Segment 1 */
	ControllerRegPtr->CANFD_BRGR.B.HTSEG1 = Can_ControllerConfig[IntIndex].Canfd_Controller_ALLFdBDRConfig->HtSeg1;
	/* Set Can Controller Baud Rate Switch T Segment 2*/
	ControllerRegPtr->CANFD_BRGR.B.HTSEG2 = Can_ControllerConfig[IntIndex].Canfd_Controller_ALLFdBDRConfig->HtSeg2;
	/* [$Block End$] */
}

/* Clear all interrupt flag */
static void Can_m_FdClearAllFlag(const uint8_t Can_Controller_Index)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	volatile uint32_t Rcr_Value = 0;
	volatile uint8_t delay_time = CLEAR_FLAG_TIME;
	if (ControllerRegPtr->CANFD_IFR.B.ALIF == 0x01)
	{
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		ControllerRegPtr->CANFD_IER.B.ALIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.ALIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.ALIC = 0x00;
	}

	if (ControllerRegPtr->CANFD_IFR.B.BEIF == 0x01)
	{
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		ControllerRegPtr->CANFD_IER.B.BEIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.BEIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.BEIC = 0x00;
	}

	if (ControllerRegPtr->CANFD_IFR.B.BOFFIF == 0x01)
	{
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		ControllerRegPtr->CANFD_IER.B.BOFFIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.BOFFIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.BOFFIC = 0x00;
	}

	if (ControllerRegPtr->CANFD_IFR.B.EAIF == 0x01)
	{
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		ControllerRegPtr->CANFD_IER.B.EAIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.EAIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.EAIC = 0x00;
	}

	if (ControllerRegPtr->CANFD_IFR.B.ENIF == 0x01)
	{
		ControllerRegPtr->CANFD_IER.B.ENIC = 0x01;
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		while ((ControllerRegPtr->CANFD_IFR.B.ENIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.ENIC = 0x00;
	}

	if (ControllerRegPtr->CANFD_IFR.B.DOVFIF == 0x01)
	{
		ControllerRegPtr->CANFD_IER.B.DOVFIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.DOVFIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.DOVFIC = 0x00;
	}

	if (ControllerRegPtr->CANFD_IFR.B.TDCFAILIF == 0x01)
	{
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		ControllerRegPtr->CANFD_IER.B.TDCFAILIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.TDCFAILIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.TDCFAILIC = 0x00;
	}

	if (ControllerRegPtr->CANFD_IFR.B.CANTXIF == 0x01)
	{
		ControllerRegPtr->CANFD_IER.B.CANTXIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.CANTXIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.CANTXIC = 0x00;
	}

	if (ControllerRegPtr->CANFD_IFR.B.CANRXIF == 0x01)
	{
		ControllerRegPtr->CANFD_IER.B.CANRXIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.CANRXIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.CANRXIC = 0x00;
	}

	if (ControllerRegPtr->CANFD_IFR.B.WUIF == 0x01)
	{
		ControllerRegPtr->CANFD_IER.B.WUIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.WUIF == STD_ON) &&(delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.WUIC = 0x00;
	}
}

/* Set The Can Intterrupt  Enable And Clear The Interrupt Flag*/
static void Can_m_FdIntSet(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	ControllerRegPtr->CANFD_IER.B.TRANSMITIC = 0x01;
	/* CAN Receive Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.CANRXIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->RxIntEnableSet;
	/* CAN Transmit Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.CANTXIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->TxIntEnableSet;
	/* CAN Bus Off Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.BOFFIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->BusOffEnableSet;
	/* CAN Wake Up Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.WUIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->WakeUpIntEnableSet;
	/* CAN Error Alarm Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.EAIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->ErrorAlarmIntEnableSet;
	/* CAN Receive Over Flow Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.DOVFIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->OverFlowIntEnableSet;
	/* CAN Error Negative Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.ENIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->ErrorNegativeIntEnableSet;
	/* CAN Error Arbitrate Lose Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.ALIE = STD_ON;
	/* CAN Bus Error Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.BEIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->BusErrorIntEnableSet;
	/* CAN DMA Transmit Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.CTXDE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->DmaTXDEnableSet;
	/* CAN DMA Receive Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.CRXDE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->DmaRXDEnableSet;
	/* CAN MailBox Receive Triger Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.TRGMBIE = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->TrigerMBEnableSet;
	/* Disable CAN Receive Not Empty Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.RXBSTAIE = STD_OFF;
	/* Disable CAN Transmit Delay Offset Fail Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.TDCFAILIE = STD_OFF;
	/* Disable CAN Transmit Arbitrate Fail Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.ARBFAILIE = STD_OFF;
	/* Disable CAN Move Out End Interrupt Set */
	ControllerRegPtr->CANFD_IER.B.MOENDIE = STD_OFF;

	/* Set Default Interrupt Priority Group 3V1 */
	INTERRUPT_REG.CTL0.B.PRIGROUP = 0x00;

	/* Enable Can Controller Module Interrrupt  */
	if (Can_Controller_Index == 0)
	{
		INTERRUPT_REG.EIE1.B.CAN4IE = 0x01;
		/* Set Preemption Priority */
		INTERRUPT_REG.IP7.B.PRI32P = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->PreemptionPriority;
		/* Set Sub Priority */
		INTERRUPT_REG.IP7.B.PRI32S = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->SubPriority;
	}
	else if (Can_Controller_Index == 1)
	{
		INTERRUPT_REG.EIE2.B.CANFD6IE = 0x01;
		/* Set Preemption Priority */
		INTERRUPT_REG.IP11.B.PRI50P = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->PreemptionPriority;
		/* Set Sub Priority */
		INTERRUPT_REG.IP11.B.PRI50S = Can_ControllerConfig[IntIndex].Can_Controller_InterruptConfig->SubPriority;
	}
	else if (Can_Controller_Index == 2)
	{
		INTERRUPT_REG.EIE2.B.CANFD7IE = 0x01;
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
	}else if(DataBuffer->SFF.IDE == 0x01)
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

#if (HARDWARE_FILTER == STD_ON)
/* Set The Can Filter Code And Mask Code) */
static void Can_m_FdFilterInit(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const uint8_t IntIndex)
{
	uint8_t MailBoxCount = 0;
	Can_m_FdMailBoxMaskErase(Can_Controller_Index);
	/* Configuration settings Addresses */
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	/* Enable MailBox Mask */
	ControllerRegPtr->CANFD_CTLR1.B.MBMSKEN = STD_ON;

	if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
	{
		for (uint8_t mailbox_count = 0; mailbox_count < MAX_8MAILBOX_NUMBER; mailbox_count++)
		{
			if (Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_STANDARD)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 21);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0xFFFFF;
			}
			else if(Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_EXTENDED)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 3);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x03;
			}
		}
	}
	else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
	{
		for (uint8_t mailbox_count = 0; mailbox_count < MAX_16MAILBOX_NUMBER; mailbox_count++)
		{
			if (Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_STANDARD)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 21);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0xFFFFF;
			}
			else if(Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_EXTENDED)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 3);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x03;
			}
		}
	}
	else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
	{
		for (uint8_t mailbox_count = 0; mailbox_count < MAX_32MAILBOX_NUMBER; mailbox_count++)
		{
			if (Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_STANDARD)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 21);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0xFFFFF;
			}
			else if(Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_EXTENDED)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 3);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0x03;
			}
		}
	}
	else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
	{
		for (uint8_t mailbox_count = 0; mailbox_count < MAX_64MAILBOX_NUMBER; mailbox_count++)
		{
			if (Can_ControllerConfig[IntIndex].Can_HwFilter[0].Can_IdFilterFrame[mailbox_count] == CAN_FILTER_STANDARD)
			{
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) = ((Can_ControllerConfig[IntIndex].Can_HwFilter[0].MaskCode[mailbox_count]) << 21);
				*(((uint32_t *)Can_m_ControllersInfo[Can_Controller_Index].FilterBaseAddress) - mailbox_count) |= 0xFFFFF;
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

/* Make The MailBox Code Segment Configuration Into Integer Number*/
static Code_Segment Can_m_FdCsCodeSet(Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	Code_Segment Ret_Code_Seg = {0};
	if (Can_MailboxHeader->BRS == 0x01)
	{
		Ret_Code_Seg.BRS = 0x01;
	}

	if (Can_MailboxHeader->Can_frame == CAN_FRAME_FD)
	{
		Ret_Code_Seg.EDL = 0x01;
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
			Ret_Code_Seg.IDE = 0x01;
			Ret_Code_Seg.RTR = 0x00;
			break;
		}
		case CAN_REMOTE_STANDARD:
		{
			Ret_Code_Seg.IDE = 0x00;
			Ret_Code_Seg.RTR = 0x01;
			break;
		}
		case CAN_REMOTE_EXTENDED:
		{
			Ret_Code_Seg.IDE = 0x01;
			Ret_Code_Seg.RTR = 0x01;
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
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	while (1)
	{
		if (ControllerRegPtr->CANFD_CTLR0.B.BOFF == 0x00)
		{
			if (ControllerRegPtr->CANFD_CTLR0.B.TXSTA == 0x01)
			{
				if ((ControllerRegPtr->CANFD_CTLR0.B.TCSTA == 0x00) && (ControllerRegPtr->CANFD_AMSTA.B.ARBSTA0 == 0x00) && (ControllerRegPtr->CANFD_IFR.B.MOENDIF == 0x00))
				{
					ret = CAN_OK;
					break;
				}

				if ((ControllerRegPtr->CANFD_IFR.B.MOENDIF == 0x01) && ((ControllerRegPtr->CANFD_AMSTA.B.ARBSTA0 == 0x01) || (ControllerRegPtr->CANFD_AMSTA.B.ARBSTA1 == 0x01)))
				{
					ControllerRegPtr->CANFD_IER.B.MOENDIC = 0x01;
					while (ControllerRegPtr->CANFD_IFR.B.MOENDIF == 0x01)
						;
					ControllerRegPtr->CANFD_IER.B.MOENDIC = 0x00;
					ret = CAN_OK;
					break;
				}

				if ((conflict_loop_count--) > RAM_CONFLICT_LOOP_TIME)
				{
					ret = CAN_RAM_TXSTA;
					break;
				}
			}
			else if (ControllerRegPtr->CANFD_CTLR0.B.RXSTA == 0x01)
			{
				if (ControllerRegPtr->CANFD_AMSTA.B.MATSTA == 0x01)
				{
					ret = CAN_OK;
					break;
				}

				if ((conflict_loop_count--) > RAM_CONFLICT_LOOP_TIME)
				{
					ret = CAN_RAM_RXSTA;
					break;
				}
			}
			else
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
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	Can_IdFrameType can_id = Can_MailboxHeader->Can_id;
	Code_Segment Ret_Code_Segment = {0};
	Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK || ret == CAN_RAM_TXSTA || ret == CAN_RAM_RXSTA)
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
		}
	}
	return ret;
}

/* Get Message Infor From Ram */
static Can_ReturnType Can_m_FdCopyDataFrom8MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	Can_ReturnType ret = CAN_UNINITIALIZED;
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK || ret == CAN_RAM_TXSTA || ret == CAN_RAM_RXSTA)
	{
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
	}
	return ret;
}

/* Set Configuration Infor To Ram */
static Can_ReturnType Can_m_FdCopyDataTo16MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	Can_IdFrameType can_id = Can_MailboxHeader->Can_id;
	Code_Segment Ret_Code_Segment = {0};
	Can_ReturnType ret = CAN_UNINITIALIZED;
	Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK || ret == CAN_RAM_TXSTA || ret == CAN_RAM_RXSTA)
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
			if (can_id == CAN_DATA_STANDARD)
			{
				Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number), 0);
				for (uint8_t i = 0; i < 4; i++)
				{
					((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.SU32Data[i]);
				}
			}
			else if (can_id == CAN_DATA_EXTENDED)
			{
				((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.RRTR =  (Can_MailboxHeader->Can_id>1)?1:0;
				((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID = Can_MailboxHeader->Id;
				for (uint8_t i = 0; i < 4; i++)
				{
					((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.U32Data[i]);
				}
			}
			((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
	}
	return ret;
}

/* Get Message Infor From Ram */
static Can_ReturnType Can_m_FdCopyDataFrom16MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	Can_ReturnType ret = CAN_UNINITIALIZED;
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK || ret == CAN_RAM_TXSTA || ret == CAN_RAM_RXSTA)
	{
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
	}
	return ret;
}

/* Set Configuration Infor To Ram */
static Can_ReturnType Can_m_FdCopyDataTo32MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	Can_ReturnType ret = CAN_UNINITIALIZED;
	Can_IdFrameType can_id = Can_MailboxHeader->Can_id;
	Code_Segment Ret_Code_Segment = {0};
	Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK || ret == CAN_RAM_TXSTA || ret == CAN_RAM_RXSTA)
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
			if (can_id == CAN_DATA_STANDARD)
			{
				Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number), 0);
				for (uint8_t i = 0; i < 8; i++)
				{
					((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.SU32Data[i]);
				}
			}
			else if (can_id == CAN_DATA_EXTENDED)
			{
				((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.RRTR =  (Can_MailboxHeader->Can_id>1)?1:0;
				((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID = Can_MailboxHeader->Id;
				for (uint8_t i = 0; i < 8; i++)
				{
					((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.U32Data[i]);
				}
			}
			((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
	}
	return ret;
}

/* Get Configuration Infor From Ram */
static Can_ReturnType Can_m_FdCopyDataFrom32MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	Can_ReturnType ret = CAN_UNINITIALIZED;
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK || ret == CAN_RAM_TXSTA || ret == CAN_RAM_RXSTA)
	{
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
	}
	return ret;
}

/* Set Configuration Infor To Ram */
static Can_ReturnType Can_m_FdCopyDataTo64MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	Can_ReturnType ret = CAN_UNINITIALIZED;
	Can_IdFrameType can_id = Can_MailboxHeader->Can_id;
	Code_Segment Ret_Code_Segment = {0};
	Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if (ret == CAN_OK || ret == CAN_RAM_TXSTA || ret == CAN_RAM_RXSTA)
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
			if (can_id == CAN_DATA_STANDARD)
			{
				Std_Reverse_Data(Can_MailboxHeader, (DataBuffer_8byteType *)((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number), 0);
				for (uint8_t i = 0; i < 16; i++)
				{
					((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.SU32Data[i]);
				}
			}
			else if (can_id == CAN_DATA_EXTENDED)
			{
				((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.RRTR =  (Can_MailboxHeader->Can_id>1)?1:0;
				((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.ID = Can_MailboxHeader->Id;
				for (uint8_t i = 0; i < 16; i++)
				{
					((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->EFF.DATA3210[i] = Reverse_Int(Can_MailboxHeader->FrameData.U32Data[i]);
				}
			}
			((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
	}
	return ret;
}

/* Get Configuration Infor From Ram */
static Can_ReturnType Can_m_FdCopyDataFrom64MailBox(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	if (ret == CAN_OK || ret == CAN_RAM_TXSTA || ret == CAN_RAM_RXSTA)
	{
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
	}
	return ret;
}

/**
 * 描述   写CANFD邮箱。
 * 输入   Can_Controller_Index: CANFD控制器编号，取值为 CANfd6、CANfd7。
 *      Mailbox_Number：邮箱号，取值为Mailbox_0~Mailbox_50
 *      Can_MailboxHeader：CANFD邮箱头类型配置结构体名
 * 返回   ret： CAN_OK    					完成
 * 		  CAN_BUSY  					总线忙碌
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     发送邮箱忙碌
 *			  CAN_BUSY_RECEIVE_MAILBOX      接收邮箱忙碌
 *	          CAN_ERROR_TIMEOUT_ARBITRATE   发送邮箱仲裁过程无法结束
 *		      CAN_ERROR_ARBITRATE_FAIL      发送邮箱内部仲裁失败
 *		 	  CAN_ERROR_ARBITRATE_LOSE      发送报文总线高优先级报文抢占
 *		 	  CAN_ERROR_BUSOFF              CAN控制器节点处于BUSOFF状态
 *		 	  CAN_RAM_RXSTA           		RAM处于接收状态异常
 *		 	  CAN_RAM_TXSTA          		RAM处于发送状态异常
 *	 		  CAN_UNINITIALIZED             状态位处于未初始化状态
 *           CAN_ERROR_CONFIGURATE          CAN控制器初始化配置错误
 */
Can_ReturnType Can_m_FdMailBox_Write(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	Can_ReturnType (*func)(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader) = NULL_PTR;
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CANFD_MESSAGE_DLC(Can_MailboxHeader->FrameData.Data_Length));
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_MAILBOX_TYPE(Can_MailboxHeader->TransceiveType));

	if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
	{
		/* Canfd 8byte Load Mailbox Number Verification */
		CHECK_RESTRICTION(CHECK_8CANFD_MAILBOX_NUMBER(Mailbox_Number));
		func = &Can_m_FdCopyDataTo8MailBox;
		ret = CAN_OK;
	}
	else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
	{
		/* Canfd 16byte Load Mailbox Number Verification */
		CHECK_RESTRICTION(CHECK_16CANFD_MAILBOX_NUMBER(Mailbox_Number));
		func = &Can_m_FdCopyDataTo16MailBox;
		ret = CAN_OK;
	}
	else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
	{
		/* Canfd 32byte Load Mailbox Number Verification */
		CHECK_RESTRICTION(CHECK_32CANFD_MAILBOX_NUMBER(Mailbox_Number));
		func = &Can_m_FdCopyDataTo32MailBox;
		ret = CAN_OK;
	}
	else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
	{
		/* Canfd 64byte Load Mailbox Number Verification */
		CHECK_RESTRICTION(CHECK_64CANFD_MAILBOX_NUMBER(Mailbox_Number));
		func = &Can_m_FdCopyDataTo64MailBox;
		ret = CAN_OK;
	}
	else
	{
		ret = CAN_ERROR_CONFIGURATE;
	}
	if (ret == CAN_OK)
	{
		ret = func(Can_Controller_Index, Mailbox_Number, Can_MailboxHeader);
	}
	return ret;
}

/**
 * 描述   读CANFD邮箱 ,读完之后重新设置邮箱属性
 * 输入   Can_Controller_Index: CANFD控制器编号，取值为 CANfd6、CANfd7。
 *      Mailbox_Number：邮箱号，取值为Mailbox_0~Mailbox_50
 *      Can_MailboxHeader：CANFD邮箱头类型配置结构体名
 * 返回   ret： CAN_OK    完成
 * 		  CAN_BUSY  总线忙碌
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     发送邮箱忙碌
 *			  CAN_BUSY_RECEIVE_MAILBOX      接收邮箱忙碌
 *	          CAN_ERROR_TIMEOUT_ARBITRATE   发送邮箱仲裁过程无法结束
 *		      CAN_ERROR_ARBITRATE_FAIL      发送邮箱内部仲裁失败
 *		 	  CAN_ERROR_ARBITRATE_LOSE      发送报文总线高优先级报文抢占
 *		 	  CAN_ERROR_BUSOFF              CAN控制器节点处于BUSOFF状态
 *		 	  CAN_RAM_RXSTA           RAM处于接收状态异常
 *		 	  CAN_RAM_TXSTA           RAM处于发送状态异常
 *	 		  CAN_UNINITIALIZED             状态位处于未初始化状态
 *           CAN_ERROR_CONFIGURATE         CAN控制器初始化配置错误
 */
Can_ReturnType Can_m_FdMailBox_Read(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	Can_ReturnType (*func)(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader, Can_MailBoxType Can_MailBox) = NULL_PTR;
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
	{
		/* Canfd 8byte Load Mailbox Number Verification */
		CHECK_RESTRICTION(CHECK_8CANFD_MAILBOX_NUMBER(Mailbox_Number));
		func = &Can_m_FdCopyDataFrom8MailBox;
		ret = CAN_OK;
	}
	else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
	{
		/* Canfd 16byte Load Mailbox Number Verification */
		CHECK_RESTRICTION(CHECK_16CANFD_MAILBOX_NUMBER(Mailbox_Number));
		func = &Can_m_FdCopyDataFrom16MailBox;
		ret = CAN_OK;
	}
	else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
	{
		/* Canfd 32byte Load Mailbox Number Verification */
		CHECK_RESTRICTION(CHECK_32CANFD_MAILBOX_NUMBER(Mailbox_Number));
		func = &Can_m_FdCopyDataFrom32MailBox;
		ret = CAN_OK;
	}
	else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
	{
		/* Canfd 64byte Load Mailbox Number Verification */
		CHECK_RESTRICTION(CHECK_64CANFD_MAILBOX_NUMBER(Mailbox_Number));
		func = &Can_m_FdCopyDataFrom64MailBox;
		ret = CAN_OK;
	}
	else
	{
		ret = CAN_ERROR_CONFIGURATE;
	}

	if (ret == CAN_OK)
	{
		ret = func(Can_Controller_Index, Mailbox_Number, Can_MailboxHeader, Can_MailBox);
	}
	else
	{
	}
	return ret;
}

/**
 * 描述   CANFD邮箱整包发送，直到所有发送邮箱发送完成。
 * 输入   Can_Controller_Index: CANFD控制器编号，取值为 CANfd6、CANfd7。
 * 返回   ret： CAN_OK    完成
 * 		  CAN_BUSY  总线忙碌
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     发送邮箱忙碌
 *			  CAN_BUSY_RECEIVE_MAILBOX      接收邮箱忙碌
 *	          CAN_ERROR_TIMEOUT_ARBITRATE   发送邮箱仲裁过程无法结束
 *		      CAN_ERROR_ARBITRATE_FAIL      发送邮箱内部仲裁失败
 *		 	  CAN_ERROR_ARBITRATE_LOSE      发送报文总线高优先级报文抢占
 *		 	  CAN_ERROR_ARBITRATE_DELAY     发送报文被总线高优先级报文抢占，但等到总线空闲会发出。
 *		 	  CAN_ERROR_BUSOFF              CAN控制器节点处于BUSOFF状态
 *		 	  CAN_RAM_RXSTA           RAM处于接收状态异常
 *		 	  CAN_RAM_TXSTA           RAM处于发送状态异常
 *	 		  CAN_UNINITIALIZED             状态位处于未初始化状态
 *           CAN_ERROR_CONFIGURATE         CAN控制器初始化配置错误
 */
Can_ReturnType Can_m_FdTransmitpack(const uint8_t Can_Controller_Index)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint32_t delay_count = MAIL_ARBITRATE_TIME;
	uint8_t Mail_Box_Number = 0x00;
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	/* waiting for arbitration  end */
	while ((ControllerRegPtr->CANFD_AMSTA.B.ARBSTA0 == 0x00) && (ControllerRegPtr->CANFD_AMSTA.B.ARBSTA1 == 0x00) && (delay_count--))
		;
	if (delay_count > MAIL_ARBITRATE_TIME)
	{
		ret = CAN_ERROR_TIMEOUT_ARBITRATE;
	}
	else if (ControllerRegPtr->CANFD_AMSTA.B.ARBSTA1 == 0x01)
	{
		/* arbitration  end  and not found  the mailbox */
		ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x01;
		ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x00;
	}

	if (ControllerRegPtr->CANFD_AMSTA.B.ARBSTA1 == 0x01)
	{ /* arbitrate fail */
		ret = CAN_ERROR_ARBITRATE_FAIL;
	}
	else
	{
		delay_count = TRANSMIT_ENABEL_TIME;
		ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x01;
		if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
		{
			Mail_Box_Number = 51;
			for (uint8_t mail_box_count = 0; mail_box_count < Mail_Box_Number; mail_box_count++)
			{
				while (1)
				{
					volatile DataBuffer_8byteType *MailBox = ((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + mail_box_count);
					if (MailBox->SFF.CODE != MAIL_TRANSMIT || (!(delay_count--)))
					{
						if (MailBox->SFF.CODE == MAIL_TRANSMIT)
						{
							ret = CAN_ERROR_ARBITRATE_LOSE;
							return ret;
						}
						else
						{
							break;
						}
					}
				}
			}
			ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
			ret = CAN_OK;
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
		{
			Mail_Box_Number = 36;
			for (uint8_t mail_box_count = 0; mail_box_count < Mail_Box_Number; mail_box_count++)
			{
				while (1)
				{
					volatile DataBuffer_16byteType *MailBox = ((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + mail_box_count);
					if (MailBox->SFF.CODE != MAIL_TRANSMIT || (!(delay_count--)))
					{
						if (MailBox->SFF.CODE == MAIL_TRANSMIT)
						{
							ret = CAN_ERROR_ARBITRATE_LOSE;
							return ret;
						}
						else
						{
							break;
						}
					}
				}
			}
			ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
			ret = CAN_OK;
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
		{
			Mail_Box_Number = 23;
			for (uint8_t mail_box_count = 0; mail_box_count < Mail_Box_Number; mail_box_count++)
			{
				while (1)
				{
					volatile DataBuffer_32byteType *MailBox = ((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + mail_box_count);
					if (MailBox->SFF.CODE != MAIL_TRANSMIT || (!(delay_count--)))
					{
						if (MailBox->SFF.CODE == MAIL_TRANSMIT)
						{
							ret = CAN_ERROR_ARBITRATE_LOSE;
							return ret;
						}
						else
						{
							break;
						}
					}
				}
			}
			ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
			ret = CAN_OK;
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
		{
			Mail_Box_Number = 13;
			for (uint8_t mail_box_count = 0; mail_box_count < Mail_Box_Number; mail_box_count++)
			{
				while (1)
				{
					volatile DataBuffer_64byteType *MailBox = ((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + mail_box_count);
					if (MailBox->SFF.CODE != MAIL_TRANSMIT || (!(delay_count--)))
					{
						if (MailBox->SFF.CODE == MAIL_TRANSMIT)
						{
							ret = CAN_ERROR_ARBITRATE_LOSE;
							return ret;
						}
						else
						{
							break;
						}
					}
				}
			}
			ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
			ret = CAN_OK;
		}
		else
		{
			ret = CAN_ERROR_CONFIGURATE;
		}
	}
	return ret;
}

/**
 * 描述   CANFD邮箱单次发送。
 * 输入   Can_Controller_Index: CANFD控制器编号，取值为 CANfd6、CANfd7。
 * 返回   ret： CAN_OK    完成
 * 		  CAN_BUSY  总线忙碌
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     	发送邮箱忙碌
 *			  CAN_BUSY_RECEIVE_MAILBOX      接收邮箱忙碌
 *	          CAN_ERROR_TIMEOUT_ARBITRATE   发送邮箱仲裁过程无法结束
 *		      CAN_ERROR_ARBITRATE_FAIL      发送邮箱内部仲裁失败
 *		 	  CAN_ERROR_ARBITRATE_LOSE      发送报文被总线高优先级报文抢占
 *		 	  CAN_ERROR_ARBITRATE_DELAY     发送报文被总线高优先级报文抢占，但等到总线空闲会发出。
 *		 	  CAN_ERROR_BUSOFF              CAN控制器节点处于BUSOFF状态
 *		 	  CAN_RAM_RXSTA           		RAM处于接收状态异常
 *		 	  CAN_RAM_TXSTA           		RAM处于发送状态异常
 *	 		  CAN_UNINITIALIZED             状态位处于未初始化状态
 *           CAN_ERROR_CONFIGURATE          CAN控制器初始化配置错误
 */

Can_ReturnType Can_m_FdTransmitonce(const uint8_t Can_Controller_Index)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint32_t delay_count = MAIL_ARBITRATE_TIME;
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	if (ControllerRegPtr->CANFD_CTLR0.B.BOFF == 0x00)
	{
		if (ControllerRegPtr->CANFD_AMSTA.B.ARBSTA1 == 0x01)
		{
			/* arbitration  end  and not found  the mailbox */
			ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x01;
			ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x00;
		}
		ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
		ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x01;
		ret = CAN_OK;
	}
	else
	{
		/* CAN BUSOFF */
		/* NOT ENABLE TRANSMIT */
		ret = CAN_ERROR_BUSOFF;
	}
	return ret;
}
/**
 * 描述   CANFD发送目标邮箱，直到目标发送邮箱发送完成。
 * 输入   Can_Controller_Index: CANFD控制器编号，取值为 CANfd6、CANfd7。
 * 返回   ret： CAN_OK    完成
 * 		  CAN_BUSY  总线忙碌
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     发送邮箱忙碌
 *		  CAN_BUSY_RECEIVE_MAILBOX      接收邮箱忙碌
 *	      CAN_ERROR_TIMEOUT_ARBITRATE   发送邮箱仲裁过程无法结束
 *		  CAN_ERROR_ARBITRATE_FAIL      发送邮箱内部仲裁失败
 *		  CAN_ERROR_ARBITRATE_LOSE      发送报文总线高优先级报文抢占
 *		  CAN_ERROR_ARBITRATE_DELAY     发送报文被总线高优先级报文抢占，但等到总线空闲会发出。
 *		  CAN_ERROR_BUSOFF              CAN控制器节点处于BUSOFF状态
 *		  CAN_RAM_RXSTA                 RAM处于接收状态异常
 *		  CAN_RAM_TXSTA                 RAM处于发送状态异常
 *	 	  CAN_UNINITIALIZED             状态位处于未初始化状态
 *        CAN_ERROR_CONFIGURATE         CAN控制器初始化配置错误
 */

Can_ReturnType Can_m_FdTransmituntil(const uint8_t Can_Controller_Index, const uint8_t Mailbox_Number)
{
	Can_ReturnType ret = CAN_UNINITIALIZED;
	volatile uint32_t delay_count = MAIL_ARBITRATE_TIME;
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	/* waiting for arbitration  end */
	while ((ControllerRegPtr->CANFD_AMSTA.B.ARBSTA0 == 0x00) && (ControllerRegPtr->CANFD_AMSTA.B.ARBSTA1 == 0x00) && (delay_count--))
		;
	if (delay_count > MAIL_ARBITRATE_TIME)
	{
		ret = CAN_ERROR_TIMEOUT_ARBITRATE;
	}
	else if (ControllerRegPtr->CANFD_AMSTA.B.ARBSTA1 == 0x01)
	{
		/* arbitration  end  and not found  the mailbox */
		ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x01;
		ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x00;
	}

	if (ControllerRegPtr->CANFD_AMSTA.B.ARBSTA1 == 0x01)
	{ /* arbitrate fail */
		ret = CAN_ERROR_ARBITRATE_FAIL;
	}
	else
	{
		/* arbitration end and found arbitration success mailbox */
		ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x01;
		if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
		{
			volatile DataBuffer_8byteType *MailBox = ((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number);
			while (MailBox->SFF.CODE != MAIL_TRANSMIT_SUCCESS)
				;
			ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
			if (MailBox->SFF.CODE == MAIL_TRANSMIT_SUCCESS)
			{
				ret = CAN_OK;
			}
			else
			{
				ret = CAN_ERROR_CONFIGURATE;
			}
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
		{
			volatile DataBuffer_16byteType *MailBox = ((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number);
			while (MailBox->SFF.CODE != MAIL_TRANSMIT_SUCCESS)
				;
			ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
			if (MailBox->SFF.CODE == MAIL_TRANSMIT_SUCCESS)
			{
				ret = CAN_OK;
			}
			else
			{
				ret = CAN_ERROR_CONFIGURATE;
			}
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
		{
			volatile DataBuffer_32byteType *MailBox = ((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number);
			while (MailBox->SFF.CODE != MAIL_TRANSMIT_SUCCESS)
				;
			ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
			if (MailBox->SFF.CODE == MAIL_TRANSMIT_SUCCESS)
			{
				ret = CAN_OK;
			}
			else
			{
				ret = CAN_ERROR_CONFIGURATE;
			}
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
		{
			volatile DataBuffer_64byteType *MailBox = ((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number);
			while (MailBox->SFF.CODE != MAIL_TRANSMIT_SUCCESS)
				;
			ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
			if (MailBox->SFF.CODE == MAIL_TRANSMIT_SUCCESS)
			{
				ret = CAN_OK;
			}
			else
			{
				ret = CAN_ERROR_CONFIGURATE;
			}
		}
	}
	return ret;
}

/**
 * 描述  CANFD获取中断标志位。
 * 输入   Can_Controller_Index : CANFD控制器编号，取值为CANfd6、CANfd7。
 *      Can_Controller_InterruptFlag ：CANFD中断标志位
 *      			RxIntFlag：接收中断标志位
 *      			TxIntFlag：发送中断标志位
 *      			BusOffFlag：总线关闭中断标志位
 *      			WakeUpFlag：唤醒中断标志位
 *      			ErrorAlarmFlag：错误报警中断标志位
 *      			OverFlowFlag：数据溢出中断标志位
 *					ErrorNegativeFlag：错误消极中断标志位
 *					ArbitrateLoseFlag：抢占丢失中断标志位
 *					BusErrorFlag：总线错误中断标志位
 *					DmaTXDFlag：DMA发送中断标志位
 *					DmaRXDFlag：DMA接收中断标志位
 *				    rmc_count：赋值
 * 返回  无。
 */
void Can_m_FdGetIntFlag(const uint8_t Can_Controller_Index, Can_Controller_InterruptFlagType *Can_Controller_InterruptFlag, uint8_t *rmc_count)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	Can_Controller_InterruptFlag->EntireFlag = ControllerRegPtr->CANFD_IFR.R.Canfd_Interrupt_Flag;
	/* get canfd controller receive message number */
	*rmc_count = ControllerRegPtr->CANFD_CTLR0.B.CANRMC;
}

/**
 * 描述  CANFD清除中断标志位。
 * 输入   Can_Controller_Index : CANFD控制器编号，取值为CANfd6、CANfd7。
 *      Can_Controller_InterruptFlag ：CANFD中断标志位
 *      			RxIntFlag：接收中断标志位
 *      			TxIntFlag：发送中断标志位
 *      			BusOffFlag：总线关闭中断标志
 *      			WakeUpFlag：唤醒中断标志位
 *      			ErrorAlarmFlag：错误报警中断标志位
 *      			OverFlowFlag：数据溢出中断标志位
 *					ErrorNegativeFlag：错误消极中断标志位
 *					ArbitrateLoseFlag：抢占丢失中断标志位
 *					BusErrorFlag：总线错误中断标志位
 *					DmaTXDFlag：DMA发送中断标志位
 *					DmaRXDFlag：DMA接收中断标志位
 *				    rmc_count：赋值
 * 返回  无。
 */
ClearFlag_ReturnType Can_m_FdClearIntFlag(const uint8_t Can_Controller_Index, Can_Controller_InterruptFlagType *Can_Controller_InterruptFlag, uint8_t rmc_count)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	ClearFlag_ReturnType ret = {0};
	volatile uint32_t delay_time = CLEAR_FLAG_TIME;
	volatile uint32_t Rcr_Value = 0;

	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	/* Clear Arbitrate Lose Flag */
	if (Can_Controller_InterruptFlag->ArbitrateLoseFlag == 0x01)
	{
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		ControllerRegPtr->CANFD_IER.B.ALIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.ALIF == 0x01) && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.ALIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Arbitrateloseclear_Timeout = 0x01;
		}

		/* Disable Transmitting Message */
		ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
		/* this is important */
		ControllerRegPtr->CANFD_CTLR0.B.ATX = 0x01;
		for (uint16_t i = 0; i < 10; i++)
		{
			asm("nop");
		}

		/* this is important */
		ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x01;
		for (uint16_t i = 0; i < 10; i++)
		{
			asm("nop");
		}
		ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x00;
		ControllerRegPtr->CANFD_CTLR0.B.ATX = 0x00;
		/* Retransmit Message */
		ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x01;
	}

	/* Clear Recevie Success Flag */
	if (Can_Controller_InterruptFlag->RxIntFlag == 0x01)
	{
		delay_time = CLEAR_FLAG_TIME;
		ControllerRegPtr->CANFD_IER.B.CANRXIC = 0x01;
		while (ControllerRegPtr->CANFD_IFR.B.CANRXIF == 0x01 && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.CANRXIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Receiveclear_Timeout = 0x01;
		}
	}

	/* Clear Bus Error Flag */
	if (Can_Controller_InterruptFlag->BusErrorFlag == 0x01)
	{
		delay_time = CLEAR_FLAG_TIME;
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;

		/* Disable Hardware Aotu ReTransmmit */
		if (ControllerRegPtr->CANFD_RCR.B.CANDIR == 0x00)
		{
			if ((ControllerRegPtr->CANFD_RCR.B.CANSEG == 0x03) || (ControllerRegPtr->CANFD_RCR.B.CANSEG == 0x19))
			{
				ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
				ControllerRegPtr->CANFD_CTLR0.B.ATX = 0x01;
				for (uint16_t i = 0; i < 10; i++)
				{
					asm("nop");
				}
				ControllerRegPtr->CANFD_CTLR0.B.ATX = 0x00;
			}
		}
#if (HARDWARE_RETRANSMIT == STD_OFF)
		ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
		ControllerRegPtr->CANFD_CTLR0.B.ATX = 0x01;
		ControllerRegPtr->CANFD_CTLR0.B.ATX = 0x00;
#endif
		ControllerRegPtr->CANFD_IER.B.BEIC = 0x01;
		while (ControllerRegPtr->CANFD_IFR.B.BEIF == 0x01 && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.BEIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Buserrorclear_Timeout = 0x01;
		}
	}

	/* Clear Bus Off Flag */
	if (Can_Controller_InterruptFlag->BusOffFlag == 0x01)
	{
		delay_time = CLEAR_FLAG_TIME;
#if (CAN_BUSOFF_RECOVERY_INTERRUPT == STD_ON)
		ControllerRegPtr->CANFD_CTLR0.B.RSMOD = 0x01;
		while(delay_time--);
		ControllerRegPtr->CANFD_CTLR0.B.RSMOD = 0x00;
#endif
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		ControllerRegPtr->CANFD_IER.B.BOFFIC = 0x01;
		while (ControllerRegPtr->CANFD_IFR.B.BOFFIF == 0x01 && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.BOFFIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Busoffclear_Timeout = 0x01;
		}
	}

	/* Clear Error Alarm Flag */
	if (Can_Controller_InterruptFlag->ErrorAlarmFlag == 0x01)
	{
		delay_time = CLEAR_FLAG_TIME;
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		ControllerRegPtr->CANFD_IER.B.EAIC = 0x01;
		while (ControllerRegPtr->CANFD_IFR.B.EAIF == 0x01 && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.EAIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Erroralarmclear_Timeout = 0x01;
		}
	}

	/* Clear Wake Up Flag */
	if (Can_Controller_InterruptFlag->ErrorNegativeFlag == 0x01)
	{
		delay_time = CLEAR_FLAG_TIME;
		ControllerRegPtr->CANFD_IER.B.ENIC = 0x01;
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		while (ControllerRegPtr->CANFD_IFR.B.ENIF == 0x01 && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.ENIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Errornegativeclear_Timeout = 0x01;
		}
	}

	/* Clear OverFlow  Flag */
	if (Can_Controller_InterruptFlag->OverFlowFlag == 0x01)
	{
		delay_time = CLEAR_FLAG_TIME;
		ControllerRegPtr->CANFD_IER.B.DOVFIC = 0x01;
		while (ControllerRegPtr->CANFD_IFR.B.DOVFIF == 0x01 && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.DOVFIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Overflowclear_Timeout = 0x01;
		}
	}

	/* Clear Transmit Success Flag */
	if (Can_Controller_InterruptFlag->TxIntFlag == 0x01)
	{
		delay_time = CLEAR_FLAG_TIME;
		ControllerRegPtr->CANFD_IER.B.CANTXIC = 0x01;
		while (ControllerRegPtr->CANFD_IFR.B.CANTXIF == 0x01 && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.CANTXIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Transmitclear_Timeout = 0x01;
		}
	}

	/* Clear Wake Up Flag */
	if (Can_Controller_InterruptFlag->WakeUpFlag == 0x01)
	{
		delay_time = CLEAR_FLAG_TIME;
		ControllerRegPtr->CANFD_IER.B.WUIC = 0x01;
		while (ControllerRegPtr->CANFD_IFR.B.WUIF == 0x01 && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.WUIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Wakeupclear_Timeout = 0x01;
		}
	}

	/* Clear Mailbox Trigger Flag */
	if (Can_Controller_InterruptFlag->MaillboxTriggerFlag == 0x01)
	{
		delay_time = CLEAR_FLAG_TIME;
		ControllerRegPtr->CANFD_IER.B.TRGMBIC = 0x01;
		while (ControllerRegPtr->CANFD_IFR.B.TRGMBIF == 0x01 && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.TRGMBIC = 0x00;
		if (delay_time > CLEAR_FLAG_TIME)
		{
			ret.Wakeupclear_Timeout = 0x01;
		}
	}

	/* Clear Receive Message Count */
	for (uint8_t release_count = 0; release_count < rmc_count; release_count++)
	{
		ControllerRegPtr->CANFD_CTLR0.B.RELRX = 0x01;
		asm("NOP");
		asm("NOP");
	}
}



/**
 * 描述  邮箱触发功能设置。
 * 输入   Can_Controller_Index: CANFD控制器编号，取值为CANfd6、CANfd7。
 * 	 Can_MailboxNumType: 触发邮箱编号。
 * 	 Triger_Count：触发邮箱次数。
 * 返回  无。
 */
void Can_m_MailboxTriggerSet(const uint8_t Can_Controller_Index,\
					const Can_MailboxNumType MailBox_Number,uint8_t Triger_Count)
{
	volatile uint16_t trigersel = 0;
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	switch(ControllerRegPtr->CANFD_CTLR0.B.MBSIZE)
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
	ControllerRegPtr->CANFD_CTLR1.B.TRGNUM = Triger_Count;
	*((uint8_t *)(&ControllerRegPtr->CANFD_CTLR1.R)+3) = (uint8_t)(trigersel>>3)|(0x01<<7);
}



/**
 * 描述   CANFD邮箱掩码设置。
 * 输入   Can_Controller_Index : CANFD控制器编号，取值为CANfd6、CANfd7。
 *      Mailbox_Number：邮箱号，取值为Mailbox_0~Mailbox_50。
 *      Can_MailboxHeader：邮箱头配置结构体名。
 * 返回   ret： CAN_OK    完成
 * 		  CAN_BUSY  总线忙碌
 * 		  CAN_BUSY_TRANSMIT_MAILBOX     发送邮箱忙碌
 *			  CAN_BUSY_RECEIVE_MAILBOX      接收邮箱忙碌
 *	          CAN_ERROR_TIMEOUT_ARBITRATE   发送邮箱仲裁过程无法结束
 *		      CAN_ERROR_ARBITRATE_FAIL      发送邮箱内部仲裁失败
 *		 	  CAN_ERROR_ARBITRATE_LOSE      发送报文总线高优先级报文抢占
 *		 	  CAN_ERROR_BUSOFF              CAN控制器节点处于BUSOFF状态
 *		 	  CAN_RAM_RXSTA                 RAM处于接收状态异常
 *		 	  CAN_RAM_TXSTA                 RAM处于发送状态异常
 *	 		  CAN_UNINITIALIZED             状态位处于未初始化状态
 *           CAN_ERROR_CONFIGURATE         CAN控制器初始化配置错误
 */
Can_ReturnType Can_m_FdMailBoxCode_Set(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number, Canfd_MailboxHeaderType *Can_MailboxHeader)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	Can_ReturnType ret = CAN_UNINITIALIZED;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	Code_Segment Ret_Code_Segment = Can_m_FdCsCodeSet(Can_MailboxHeader);
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_CONFLICT_LOOP_TIME);
	if ((ret == CAN_OK) || (ret == CAN_RAM_TXSTA) || (ret == CAN_RAM_RXSTA))
	{
		if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
		{
			((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
		{
			((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
		{
			((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CS_CODE = Ret_Code_Segment.CS_CODE;
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
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
 * 描述   获取CANFD邮箱状态。
 * 输入   Can_Controller_Index : CANFD控制器编号，取值为CANfd6、CANfd7。
 *      Mailbox_Number：邮箱号，取值为Mailbox_0~Mailbox_50。
 * 返回   Ret_State： MAIL_UNDEFINED 邮箱未定义
 *     			MAIL_RECEIVE 邮箱接收
 *     			MAIL_RECEIVE_SUCCESS 邮箱接收成功
 *     			MAIL_TRANSMIT 邮箱发送
 *     			MAIL_TRANSMIT_SUCCESS 邮箱发送成功
 *     			MAIL_RTR_REQUEST 邮箱远程帧请求
 *     			MAIL_RTR_ANSWER 邮箱远程帧回复
 */
Can_MailBoxType Can_m_FdGetMailBoxState(const uint8_t Can_Controller_Index, const Can_MailboxNumType Mailbox_Number)
{
	Can_MailBoxType Ret_State = MAIL_UNDEFINED;
	Can_ReturnType ret = CAN_UNINITIALIZED;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	ret = Can_m_FdWaitConfilct(Can_Controller_Index,RAM_STATE_LOOP_TIME);
	if (ret == CAN_OK || ret == CAN_RAM_TXSTA || ret == CAN_RAM_RXSTA)
	{
		if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_8_BYTE_DATALENGTH)
		{
			Ret_State = (Can_MailBoxType)(((DataBuffer_8byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE);
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_16_BYTE_DATALENGTH)
		{
			Ret_State = (Can_MailBoxType)(((DataBuffer_16byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE);
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_32_BYTE_DATALENGTH)
		{
			Ret_State = (Can_MailBoxType)(((DataBuffer_32byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE);
		}
		else if (ControllerRegPtr->CANFD_CTLR0.B.MBSIZE == CAN_64_BYTE_DATALENGTH)
		{
			Ret_State = (Can_MailBoxType)(((DataBuffer_64byteType *)(Can_m_ControllersInfo[Can_Controller_Index].MBBaseAddress) + Mailbox_Number)->SFF.CODE);
		}
	}
	return Ret_State;
}

/**
 * 描述  CANFD邮箱擦除。
 * 输入  Can_Controller_Index: CANFD控制器编号，取值为CANfd6、CANfd7。
 * 返回  无。
 */
void Can_m_FdMailBoxErase(const uint8_t Can_Controller_Index)
{
	uint8_t erase_length = 0;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	switch(ControllerRegPtr->CANFD_CTLR0.B.MBSIZE)
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
 * 描述  CANFD邮箱掩码擦除。
 * 输入  Can_Controller_Index: CANFD控制器编号，取值为CANfd6、CANfd7。
 * 返回  无。
 */
void Can_m_FdMailBoxMaskErase(const uint8_t Can_Controller_Index)
{
	uint8_t erase_length = 0;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	switch(ControllerRegPtr->CANFD_CTLR0.B.MBSIZE)
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
 * 描述  CANFD控制器复位。
 * 输入   Can_Controller_Index: CANFD控制器编号，取值为 CANfd6、CANfd7。
 * 返回  无。
 */
void Can_m_FdControllerDeInit(const uint8_t Can_Controller_Index)
{
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	if (Can_m_ControllersInfo[Can_Controller_Index].BaseAddress == CAN_HW_CONTROLLER_BASEADDRESS_CANFD6)
	{
		RST.CTL3.B.CANFD6RST = 0x01;
		PCLK.CTL3.B.CANFD6CLKEN = 0x01;
		RST.CTL3.B.CANFD6RST = 0x00;
	}
	else if (Can_m_ControllersInfo[Can_Controller_Index].BaseAddress == CAN_HW_CONTROLLER_BASEADDRESS_CANFD7)
	{
		RST.CTL3.B.CANFD7RST = 0x01;
		PCLK.CTL3.B.CANFD7CLKEN = 0x01;
		RST.CTL3.B.CANFD7RST = 0x00;
	}
	else
	{
	}
}

/**
 * 描述  CANFD控制器初始化。
 * 输入   Can_Controller_Index: CANFD控制器编号，取值为CANfd6、CANfd7。
 * 	 Can_ControllerConfig：CANFD控制器配置类型结构体。
 * 	 InitIndex：索引号，取值为Initindex_0~Initindex_4。
 * 返回  无。
 */
void Can_m_FdControllerInit(const uint8_t Can_Controller_Index, const Can_ControllerConfigType *Can_ControllerConfig, const Can_InitIndexType InitIndex)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	volatile uint8_t delay_count = 0xff;
	/* Controller Index Number Verification */
	CHECK_RESTRICTION(CHECK_CONTROLLER_INDEX(Can_Controller_Index));
	/* Disable CAN controller */
	ControllerRegPtr->CANFD_CTLR0.B.CANEN = STD_OFF;
	/* Set CAN controller to reset work mode */
	ControllerRegPtr->CANFD_CTLR0.B.RSMOD = CAN_CONTROLLER_RUN_MODE_RESET;
	/* Waitting For Can Controller Go to reset mode */
	while (delay_count--)
		; /*  compound statement  */
	/* Disable Listen-only mode */
	ControllerRegPtr->CANFD_CTLR0.B.SILENT = CAN_CONTROLLER_MODE_DISABLE_LISTENONLY;
	/* Disable sleep mode */
	ControllerRegPtr->CANFD_CTLR0.B.SLEEP = CAN_CONTROLLER_MODE_DISABLE_SLEEP;
	/*Canfd Mode Verification*/
	CHECK_RESTRICTION(CHECK_CONTROLLER_MODE(Can_ControllerConfig[InitIndex].CanfdMode));
	if (Can_ControllerConfig[InitIndex].CanfdMode == CANFD_LOOP_INTERNAL_MODE)
	{
		ControllerRegPtr->CANFD_CTLR0.B.LBACK = CAN_CONTROLLER_MODE_ENABLE_LOOP;
		ControllerRegPtr->CANFD_CTLR1.B.LBSEL = CAN_CONTROLLER_MODE_ENABLE_INTERLOOP;
	}
	else if (Can_ControllerConfig[InitIndex].CanfdMode == CANFD_LOOP_EXTERNAL_MODE)
	{
		ControllerRegPtr->CANFD_CTLR0.B.LBACK = CAN_CONTROLLER_MODE_ENABLE_LOOP;
		ControllerRegPtr->CANFD_CTLR1.B.LBSEL = CAN_CONTROLLER_MODE_DISABLE_INTERLOOP;
	}
	else if (Can_ControllerConfig[InitIndex].CanfdMode == CANFD_SILENT_MODE)
	{
		ControllerRegPtr->CANFD_CTLR0.B.LBACK = CAN_CONTROLLER_MODE_DISABLE_INTERLOOP;
		ControllerRegPtr->CANFD_CTLR0.B.SILENT = CAN_CONTROLLER_MODE_ENABLE_LISTENONLY;
	}
	else if (Can_ControllerConfig[InitIndex].CanfdMode == CANFD_NORMAL_MODE)
	{
		ControllerRegPtr->CANFD_CTLR0.B.LBACK = CAN_CONTROLLER_MODE_DISABLE_INTERLOOP;
		ControllerRegPtr->CANFD_CTLR0.B.SILENT = CAN_CONTROLLER_MODE_DISABLE_LISTENONLY;
	}

#if (WORKSOURCE_DIVIDE_1 == STD_ON)
	ControllerRegPtr->CANFD_CTLR1.B.CKMODE = STD_ON;
#else
	ControllerRegPtr->CANFD_CTLR1.B.CKMODE = STD_OFF;
#endif

#if (TRANSMIT_DELAY_CONPENSATION == STD_ON)
#if (TRANSMIT_DELAY_CONPENSATION_HARDWARE == STD_ON)
	/* Enable Transmiter Delay Conpensation */
	ControllerRegPtr->CANFD_CTLR2.B.TDCEN = 0x01;
	ControllerRegPtr->CANFD_CTLR2.B.TDCOEN = 0x01;
	ControllerRegPtr->CANFD_CTLR2.B.TDCSAUTO = 0x01;

#else
	ControllerRegPtr->CANFD_CTLR2.B.TDCEN = 0x01;
	ControllerRegPtr->CANFD_CTLR2.B.TDCOEN = 0x01;
	ControllerRegPtr->CANFD_CTLR2.B.TDCO = 0x03;
	ControllerRegPtr->CANFD_CTLR2.B.TDCS = 0x03;
#endif

#endif

	ControllerRegPtr->CANFD_CTLR2.B.TEST1 = 0x00;
	ControllerRegPtr->CANFD_CTLR2.B.TEST2 = 0x00;
	ControllerRegPtr->CANFD_CTLR2.B.TEST3 = 0x00;
	ControllerRegPtr->CANFD_CTLR2.B.TEST4 = 0x00;
	/* Set Arbitrate Clock Divide */
	ControllerRegPtr->CANFD_CTLR2.B.AMCKDIV = Clock_Divide_1;
	/* Canfd Protocal Verification */
	CHECK_RESTRICTION(CHECK_CANFD_PROTOCAL(Can_ControllerConfig[InitIndex].FdFrameType));
	/* Set Canfd Frame type */
	ControllerRegPtr->CANFD_CTLR0.B.ISOFDCAN = Can_ControllerConfig[InitIndex].FdFrameType;
	/*Canfd Mailbox Block Size Verification*/
	CHECK_RESTRICTION(CHECK_CONTROLLER_MBSIZE(Can_ControllerConfig[InitIndex].MailBoxBlockSize));
	/* Set Canfd MailBox Block Size */
	ControllerRegPtr->CANFD_CTLR0.B.MBSIZE = Can_ControllerConfig[InitIndex].MailBoxBlockSize;
	/*Canfd Full Mailbox Receive Or Not Receive Verification */
	CHECK_RESTRICTION(CHECK_CANFD_MAILBOX_FULLSTATE(Can_ControllerConfig[InitIndex].MBFullReceiveEnableSet));
	/* Set Whether Full Canfd MailBox Participate the Receive Match*/
	ControllerRegPtr->CANFD_CTLR0.B.FULLRXEN = Can_ControllerConfig[InitIndex].MBFullReceiveEnableSet;
	/*Canfd Work Clock Source Verification*/
	CHECK_RESTRICTION(CHECK_CONTROLLER_WORKCLOCK(CHECK_CONTROLLER_WORKCLOCK(Can_ControllerConfig[InitIndex].ClockSource)));
	/* Set Can Controller Work Clock Source */
	ControllerRegPtr->CANFD_CTLR0.B.CANCKS = Can_ControllerConfig[InitIndex].ClockSource;
	/*Canfd Arbitrate Clock Source Verification*/
	CHECK_RESTRICTION(CHECK_CONTROLLER_ARBCLOCK(CHECK_CONTROLLER_ARBCLOCK(Can_ControllerConfig[InitIndex].FdArbitrateClockSource)));
	/* Set Can Controller Arbitrate Clock Source */
	ControllerRegPtr->CANFD_CTLR1.B.AMCKS = Can_ControllerConfig[InitIndex].FdArbitrateClockSource;
	/* Set Can Controller Global Mask Code */
	ControllerRegPtr->CANFD_MSKR = Can_ControllerConfig[InitIndex].GlobalMask;
	/* Disable Can Bus Off Hardware Recovery */
	ControllerRegPtr->CANFD_CTLR1.B.BOFFREC = 0x00;
	/* Enable CANFD Mode */
	ControllerRegPtr->CANFD_CTLR0.B.CANFDEN = 0x01;
	/* Set CAN Default baudrate */
	Can_m_FdBaudrateSet(Can_Controller_Index, Can_ControllerConfig, Initindex_0);
	/* Clear Can Intterrupt Flag */
	Can_m_FdClearAllFlag(Can_Controller_Index);
	/* Set The Can Intterrupt  Enable And Clear The Interrupt Flag */
	Can_m_FdIntSet(Can_Controller_Index, Can_ControllerConfig, Initindex_0);
	/* Clear Ram Area Data */
	Can_m_FdMailBoxErase(Can_Controller_Index);
#if (HARDWARE_FILTER == STD_ON)
	/* Set The Can Filter Code */
	Can_m_FdFilterInit(Can_Controller_Index, Can_ControllerConfig, Initindex_0);
#endif
	/* Enable The Can Controller Module */
	ControllerRegPtr->CANFD_CTLR0.B.CANEN = STD_ON;
	/* Set CAN Controller to work mode */
	ControllerRegPtr->CANFD_CTLR0.B.RSMOD = CAN_CONTROLLER_RUN_MODE_RUN;
	/* CAN  Controller Interrupt Settings */
	while (delay_count--)
		;
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


void Arbitrate_Handle(const uint8_t Can_Controller_Index)
{
	volatile Kf32a_Canfd_Reg *ControllerRegPtr = (Kf32a_Canfd_Reg *)Can_m_ControllersInfo[Can_Controller_Index].BaseAddress;
	volatile uint32_t delay_time = CLEAR_FLAG_TIME;
	volatile uint32_t Rcr_Value = 0x00;
	if (ControllerRegPtr->CANFD_IFR.B.ALIF == 0x01)
	{
		Rcr_Value = ControllerRegPtr->CANFD_RCR.R;
		ControllerRegPtr->CANFD_IER.B.ALIC = 0x01;
		while ((ControllerRegPtr->CANFD_IFR.B.ALIF == 0x01) && (delay_time--))
			;
		ControllerRegPtr->CANFD_IER.B.ALIC = 0x00;

		/* Disable Transmitting Message */
		ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x00;
		/* this is important */
		ControllerRegPtr->CANFD_CTLR0.B.ATX = 0x01;
		for (uint16_t i = 0; i < 10; i++)
		{
			asm("nop");
		}
		ControllerRegPtr->CANFD_CTLR0.B.ATX = 0x00;

		/* this is important */
		ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x01;
		for (uint16_t i = 0; i < 10; i++)
		{
			asm("nop");
		}
		ControllerRegPtr->CANFD_CTLR1.B.ARBSTART = 0x00;
		/* Retransmit Message */
		ControllerRegPtr->CANFD_CTLR0.B.TXR = 0x01;
	}
}
#endif
