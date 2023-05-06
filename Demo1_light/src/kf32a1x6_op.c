/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_op.c                                 	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the Operational amplifier (OP) 	  *
 *  				    peripherals function                              	  *
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

#include "kf32a1x6_op.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"


/**
  *   ##### ��ʼ�������ú��� #####
  */

/**
  * ���� OP���踴λ��ʹ������ʱ�ӡ�
  * ����  : ��
  * ����  �ޡ�
  */
void OP_Reset(void)
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_OPRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_OPRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_OPCLKEN, TRUE);
}
/**
 *  ����������OP0/1/2/3 ʹ��/ʧ��
 *  ���룺OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  NewState: TRUE/FALSE
 *  ���أ���
 * */
void OP_Enable(uint32_t OPx_NUM, FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_CTL0 = SFR_Config(OP_CTL0, ~(1 << OPx_NUM), NewState << OPx_NUM);
}
/**
 *  ����������OP0/1/2/3 IO���ʹ��/ʧ��
 *  ���룺OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  NewState: TRUE/FALSE
 *  ���أ���
 * */
void OP_OUTPUT_Enable(uint32_t OPx_NUM, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL0_OP0OUTEN_POS + OPx_NUM);
	tmask = 1 << (OP_CTL0_OP0OUTEN_POS + OPx_NUM);
	OP_CTL0 = SFR_Config(OP_CTL0, ~tmask, tmpreg);
}
/**
 *  ����������OP0/1/2/3 �Ŵ���
 *  ���룺OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  GAIN_Value��  OP_GAIN_2dB���˷ŷŴ� 2 ��
 *  	  			   OP_GAIN_4dB���˷ŷŴ� 4 ��
 *  	  			   OP_GAIN_8dB���˷ŷŴ� 8 ��
 *  	  			   OP_GAIN_16dB���˷ŷŴ� 16 ��
 *  	  			   OP_GAIN_32dB���˷ŷŴ� 32 ��
 *  	  			   OP_GAIN_64dB���˷ŷŴ� 64 ��
 *  	  NewState: TRUE/FALSE ���˷ŷŴ���ʹ��/ʧ��
 *  ���أ���
 * */
void OP_GAIN_Select(uint32_t OPx_NUM,
			uint32_t GAIN_Value, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_GAIN_VALUE(GAIN_Value));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL0_OP0GAIN2X_POS + OPx_NUM*6 + GAIN_Value);
	tmask = 1 << (OP_CTL0_OP0GAIN2X_POS + OPx_NUM*6 + GAIN_Value);
	OP_CTL0 = SFR_Config(OP_CTL0, ~tmask, tmpreg);
}
/**
 *  ����������OP0/1/2/3 IO�������10K����ʹ��
 *  ���룺OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  NewState: TRUE��������� 10K�� �ĵ���
					FALSE��������
 *  ���أ���
 * */
void OP_OPUPUT_Parallel_Resistance(uint32_t OPx_NUM, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL1_OP010KSEL_POS + OPx_NUM);
	tmask = 1 << (OP_CTL1_OP010KSEL_POS + OPx_NUM);
	OP_CTL1 = SFR_Config(OP_CTL1, ~tmask, tmpreg);
}
/**
 *  ����������OP0/1/2/3�������ΪOP0/1/2����������
 *  ���룺	OPx_NUM_OUTPUT (�Ǹ�OP�����): OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  		OPx_NUM_PINPUT (�Ǹ�OP����������): OP0_NUM/OP1_NUM/OP2_NUM
 *  	  NewState: TRUE��OPx_NUM_OUTPUT���������ΪOPx_NUM_PINPUT����������
					FALSE��������
 *  ���أ���
 * */
void OP_Positive_INPUT_Selsect(uint32_t OPx_NUM_OUTPUT,uint32_t OPx_NUM_PINPUT, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM_OUTPUT));
	CHECK_RESTRICTION(CHECK_OP_OP012_NUM(OPx_NUM_PINPUT));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL1_OP0TOCU_POS + OPx_NUM_OUTPUT*3 + OPx_NUM_PINPUT);
	tmask = 1 << (OP_CTL1_OP0TOCU_POS + OPx_NUM_OUTPUT*3 + OPx_NUM_PINPUT);
	OP_CTL1 = SFR_Config(OP_CTL1, ~tmask, tmpreg);
}
/**
 *  ����������OP0/1/2/3�����˶̽�
 *  ���룺 OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  NewState: TRUE���̽�ʹ��
 *					FALSE���̽�δʹ��
 *  ���أ���
 * */
void OP_Positive_Negetive_Short(uint32_t OPx_NUM, FunctionalState NewState)
{
	uint32_t tmpreg;
	uint32_t tmask;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	tmpreg = NewState << (OP_CTL1_ENOP0INSHORT_POS + OPx_NUM);
	tmask = 1 << (OP_CTL1_ENOP0INSHORT_POS + OPx_NUM);
	OP_CTL1 = SFR_Config(OP_CTL1, ~tmask, tmpreg);
}
/**
 *  ����������OP��ģ�ο���������
 *  ���룺Select:   OP_HALF_AVDD��ѡ�� AVDD ��һ����Ϊ��ģ������
 *					OP_HALF_2V��ѡ���ڲ� 2V �Ĳο���ѹ��һ����Ϊ��ģ������
 *  ���أ���
 * */
void OP_VCOM_Positive_Select(uint32_t Select)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_VCOM_SEL(Select));

	OP_CTL1 = SFR_Config(OP_CTL1, ~OP_CTL1_VCOMPSEL, Select << OP_CTL1_VCOMPSEL0_POS);
}
/**
 *  ����������OP��ģbuffer���ʹ��
 *  ���룺NewState:   	TRUE��OP �Ĺ�ģ buffer ���ʹ��
 *						FALSE��OP �Ĺ�ģ buffer ���δʹ��
 *  ���أ���
 * */
void OP_VCOM_Buffer_Output_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_CTL1 = SFR_Config(OP_CTL1, ~OP_CTL1_OPVCOMOUTEN, NewState << OP_CTL1_OPVCOMOUTEN_POS);
}
/**
 *  ����������OP��ģbufferʹ��
 *  ���룺NewState:   	TRUE��OP �Ĺ�ģ buffer ʹ��
 *						FALSE��OP �Ĺ�ģ buffer δʹ��
 *  ���أ���
 * */
void OP_VCOM_Buffer_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_CTL1 = SFR_Config(OP_CTL1, ~OP_CTL1_ENOPVCOM, NewState << OP_CTL1_ENOPVCOM_POS);
}
/**
 *  ����������CMP3ʹ��/ʧ��
 *  ���룺NewState:   	TRUE��CMP3ʹ��
 *						FALSE��CMP3ʧ��
 *  ���أ���
 * */
void CMP3_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_CTL1 = SFR_Config(OP_CTL1, ~OP_CTL1_ENCMP3, NewState);
}

/**
 * 	OP��ʼ�����ú������
 * */

/**
 * 	OPУ׼���ú���
 * */

/**
 *  ����������OP0/1/2/3У׼ PMOS��ʹ��
 *  ���룺NewState:   	TRUE��ʹ��
 *						FALSE��ʧ��
 *  ���أ���
 * */
void OP_TRIM_PMOS_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OPTRIMLOWEN, NewState << OP_TRIM_OPTRIMLOWEN_POS);
}
/**
 *  ����������OP0/1/2/3У׼ NMOS��ʹ��
 *  ���룺NewState:   	TRUE��ʹ��
 *						FALSE��ʧ��
 *  ���أ���
 * */
void OP_TRIM_NMOS_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OPTRIMHIEN, NewState << OP_TRIM_OPTRIMHIEN_POS);
}
/**
 *  ��������ȡOP0/1/2/3У׼���ָʾλ
 *  ���룺OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  ���أ�RetStatus��0��ʾ OP�ĸ���Ȩ�ش�������Ȩ�أ� ��Ҫ��������Ȩ��
 *  				 1��ʾ OP0 ������Ȩ�ش��ڸ���Ȩ�أ� ��Ҫ���Ӹ���Ȩ��
 * */
RetStatus
OP_TRIM_OUT_Flag(uint32_t OPx_NUM)
{
	uint8_t Value = 0;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));

	switch (OPx_NUM)
	{
	case OP0_NUM:
		Value = ((OP_TRIM0 & OP_TRIM_OP0TRIMOUT) >> OP_TRIM_OP0TRIMOUT_POS);
		break;
	case OP1_NUM:
		Value = ((OP_TRIM1 & OP_TRIM_OP0TRIMOUT) >> OP_TRIM_OP0TRIMOUT_POS);
		break;
	case OP2_NUM:
		Value = ((OP_TRIM2 & OP_TRIM_OP0TRIMOUT) >> OP_TRIM_OP0TRIMOUT_POS);
		break;
	case OP3_NUM:
		Value = ((OP_TRIM3 & OP_TRIM_OP0TRIMOUT) >> OP_TRIM_OP0TRIMOUT_POS);
		break;
	default:break;
	}
	return Value;
}
/**
 *  ����������OP0/1/2/3 PMOS��ʧ��У׼ֵ
 *  ���룺OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  Value�� ʧ��У׼ֵ
 *  ���أ���
 * */
void OP_TRIM_PMOS_Value_Config(uint32_t OPx_NUM, uint8_t Value)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_TRIM_VALUE(Value));

	tmpreg = Value << OP_TRIM_OP0TRIMP0_POS;
	switch (OPx_NUM)
	{
	case OP0_NUM:
		OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OP0TRIMP, tmpreg);
		break;
	case OP1_NUM:
		OP_TRIM1 = SFR_Config(OP_TRIM1, ~OP_TRIM_OP0TRIMP, tmpreg);
		break;
	case OP2_NUM:
		OP_TRIM2 = SFR_Config(OP_TRIM2, ~OP_TRIM_OP0TRIMP, tmpreg);
		break;
	case OP3_NUM:
		OP_TRIM3 = SFR_Config(OP_TRIM3, ~OP_TRIM_OP0TRIMP, tmpreg);
		break;
	default:break;
	}
}
/**
 *  ����������OP0/1/2/3 PMOS��ʧ��У׼����
 *  ���룺OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  Direction��  OP_TRIM_DIRECTION_POSITIVE: OPx MOS ��ѡ������У׼
 *  	  			  OP_TRIM_DIRECTION_NEGETIVE: OPx MOS ��ѡ����У׼
 *  ���أ���
 * */
void OP_TRIM_PMOS_Direction_Select(uint32_t OPx_NUM, uint32_t Direction)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_TRIM_DIRECTION(Direction));

	tmpreg = Direction << OP_TRIM_OP0TRIMPPOL_POS;
	switch (OPx_NUM)
	{
	case OP0_NUM:
		OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OP0TRIMPPOL, tmpreg);
		break;
	case OP1_NUM:
		OP_TRIM1 = SFR_Config(OP_TRIM1, ~OP_TRIM_OP0TRIMPPOL, tmpreg);
		break;
	case OP2_NUM:
		OP_TRIM2 = SFR_Config(OP_TRIM2, ~OP_TRIM_OP0TRIMPPOL, tmpreg);
		break;
	case OP3_NUM:
		OP_TRIM3 = SFR_Config(OP_TRIM3, ~OP_TRIM_OP0TRIMPPOL, tmpreg);
		break;
	default:break;
	}
}
/**
 *  ����������OP0/1/2/3 NMOS��ʧ��У׼ֵ
 *  ���룺OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  Value�� ʧ��У׼ֵ
 *  ���أ���
 * */
void OP_TRIM_NMOS_Value_Config(uint32_t OPx_NUM, uint8_t Value)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_TRIM_VALUE(Value));

	tmpreg = Value << OP_TRIM_OP0TRIMN0_POS;
	switch (OPx_NUM)
	{
	case OP0_NUM:
		OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP1_NUM:
		OP_TRIM1 = SFR_Config(OP_TRIM1, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP2_NUM:
		OP_TRIM2 = SFR_Config(OP_TRIM2, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP3_NUM:
		OP_TRIM3 = SFR_Config(OP_TRIM3, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	default:break;
	}
}
/**
 *  ����������OP0/1/2/3 NMOS��ʧ��У׼����
 *  ���룺OPx_NUM: OP0_NUM/OP1_NUM/OP2_NUM/OP3_NUM
 *  	  Direction��  OP_TRIM_DIRECTION_POSITIVE: OPx MOS ��ѡ������У׼
 *  	  			  OP_TRIM_DIRECTION_NEGETIVE: OPx MOS ��ѡ����У׼
 *  ���أ���
 * */
void OP_TRIM_NMOS_Direction_Select(uint32_t OPx_NUM, uint32_t Direction)
{
	uint32_t tmpreg;

	/* ����У�� */
	CHECK_RESTRICTION(CHECK_OP_ALL_NUM(OPx_NUM));
	CHECK_RESTRICTION(CHECK_OP_TRIM_DIRECTION(Direction));

	tmpreg = Direction << OP_TRIM_OP0TRIMNPOL_POS;
	switch (OPx_NUM)
	{
	case OP0_NUM:
		OP_TRIM0 = SFR_Config(OP_TRIM0, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP1_NUM:
		OP_TRIM1 = SFR_Config(OP_TRIM1, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP2_NUM:
		OP_TRIM2 = SFR_Config(OP_TRIM2, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	case OP3_NUM:
		OP_TRIM3 = SFR_Config(OP_TRIM3, ~OP_TRIM_OP0TRIMN, tmpreg);
		break;
	default:break;
	}
}

/**
 * 	OPУ׼���ú�������
 * */

