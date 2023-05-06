/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : kf32a1x6_aes.h                              	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $Hard Version     : kf32a1x6-MINI-EVB_V1.2                                *
 *  $Description$     : This file provides the system control related function*
 *                    	declaration and related macro definition.	          *
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

#include "kf32a1x6_aes.h"
#include "kf32a1x6_rst.h"
#include "kf32a1x6_pclk.h"

/**
  *   ##### ��ʼ�������ú��� #####
  */
/**
  * ����AES���踴λ��ʹ������ʱ�ӡ�
  * ����  : ��
  * ����  �ޡ�
  */
void AES_Reset ()
{
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_AESRST, TRUE);
	RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_AESRST, FALSE);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_AESCLKEN, TRUE);
}

/**
  * ������ AES ����ʹ�ܡ�
  * ���룺 NewState:
  * 	  		TRUE:���� AES ������
  * 	 		FALSE: ��Ӱ��
  * ���أ� �ޡ�
  * ע�ͣ���������Ч�� ��Ҫ�ֶ����㣻
  */
void AES_Run_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_AESRUN, NewState << AES_CTL_AESRUN_POS);
}

/**
  * ������ AES ����ģʽʹ�ܡ�
  * ���룺 NewState:
  * 	  		TRUE:����ģʽʹ��λ��
  * 	 		FALSE: ��Ӱ��
  * ���أ� �ޡ�
  */
void AES_High_Speed_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_HSMODE, NewState << AES_CTL_HSMODE_POS);
}

/**
  * ������ CBCģʽʹ��λ��
  * ���룺 Mode:
  * 	  		AES_WORK_ECB_MODE: ������ECBģʽ
  * 	 		AES_WORK_CBC_MODE: ������CBCģʽ
  * ���أ� �ޡ�
  */
void AES_CBC_Mode_Select(uint32_t Mode)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_AES_WORK_MODE(Mode));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_CBCEN, Mode << AES_CTL_CBCEN_POS);
}

/**
  * ������ AES����ʱ��Դѡ��
  * ���룺 Source:
  * 	  		AES_TRNG_SCK_SCLK: ѡ��SCLKΪTRNG����ʱ��
  * 	 		AES_TRNG_SCK_HFCLK: ѡ��SCLKΪTRNG����ʱ��
  * 	 		AES_TRNG_SCK_LFCLK: ѡ��SCLKΪTRNG����ʱ��
  * ���أ� �ޡ�
  */
void AES_TRNG_SCK_Select(uint32_t Source)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_AES_TRNG_SCK(Source));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_CKS, Source << AES_CTL_CKS0_POS);
}

/**
  * ������ AES����ʱ�ӷ�Ƶѡ��
  * ���룺 CLKDIV:
  * 	  		AES_SCK_DIV0:    ����Ƶ
  * 	 		AES_SCK_DIV2:    2��Ƶ
  * 	 		AES_SCK_DIV4:    4��Ƶ
  * 	 		AES_SCK_DIV8:  	 8��Ƶ
  * 	 		AES_SCK_DIV16:   16��Ƶ
  * 	 		AES_SCK_DIV32:   32��Ƶ
  * 	 		AES_SCK_DIV64:   64��Ƶ
  * 	 		AES_SCK_DIV128:  128��Ƶ
  * ���أ� �ޡ�
  */
void AES_SCK_DIV_Select(uint32_t CLKDIV)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_AES_SCK_DIV(CLKDIV));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_DIV, CLKDIV << AES_CTL_DIV0_POS);
}

/**
  * ������ AES��Կ��չ����ѡ��
  * ���룺 RNG_NUM:  RNG_NUM <= 0x1F
  * ���أ� �ޡ�
  */
void AES_RND_NUM_Config(uint32_t RNG_NUM)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_AES_RNG_NUM(RNG_NUM));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_RND_NUM, RNG_NUM << AES_CTL_RND_NUM0_POS);
}

/**
  * ������ AES��Կ����ѡ��
  * ���룺 KEY_LEN:  KEY_LEN <= 0x07
  * ���أ� �ޡ�
  * ע�ͣ� ��Կ�ֳ� =��KEY_LEN+1��/4
  */
void AES_KEY_LEN_Config(uint32_t KEY_LEN)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_KEY_LEN(KEY_LEN));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_KEY_LEN, KEY_LEN << AES_CTL_KEY_LEN0_POS);
}

/**
  * ������ S �������滻ʹ��λ
  * ���룺 SBOXMODE:
					AES_SBOX_NOR_REPLACE: S���������滻
					AES_SBOX_INV_REPLACE: S�������滻
  * ���أ� �ޡ�
  */
void AES_SBOX_INV_Enable(uint32_t SBOXMODE)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_AES_SBOX_INV(SBOXMODE));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_SB0X_INV, SBOXMODE << AES_CTL_SB0X_INV_POS);
}

/**
  * ������ ���ܹ���ʹ��λ
  * ���룺 EN_DECRYPT:
					AES_DECRYPT: ѡ�� AES ���ܹ���
					AES_ENCRYPT: ѡ�� AES ���ܹ���
  * ���أ� �ޡ�
  */
void AES_ENCRYPT_Function_Enable(uint32_t EN_DECRYPT)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_AES_DE_ENCRYPT(EN_DECRYPT));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_ENCRYPT, EN_DECRYPT << AES_CTL_ENCRYPT_POS);
}

/**
  * ������ �㷨�Զ���ʹ��
  * ���룺 ALGORITHM:
					AES_STANDARD_ALGORITHM: AES ���ñ�׼�㷨
					AES_CUSTOMIZE_ALGORITHM: AES �����Զ����㷨
  * ���أ� �ޡ�
  */
void AES_CUSTOMIZE_ALGORITHM_Enable(uint32_t ALGORITHM)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_AES_ALGORITHM(ALGORITHM));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_AESLIKE, ALGORITHM << AES_CTL_AESLIKE_POS);
}

/**
  * ������ AES ʹ��
  * ���룺 NewState:
					TRUE: AES ʹ��
					FALSE: AES ��ֹ
  * ���أ� �ޡ�
  */
void AES_Enable(FunctionalState NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	AES_CTL = SFR_Config(AES_CTL, ~AES_CTL_AESEN, NewState);
}


/**
  * ������ AES ��/��������жϱ�־
  * ���룺 ��
  * ���أ� 0�����ڼӽ��ܹ��̻���δ��ʼ�ӽ���
  *		  1��1 �μ���/�������
  */
FlagStatus AES_Get_INT_Flag(void)
{
	if(AES_INT & AES_INT_AESIF)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/**
  * ������ AES �жϱ�־����
  * ���룺 ��
  * ���أ� �ޡ�
  */
void AES_Clear_INT_Flag(void)
{
	SFR_SET_BIT_ASM(AES_INT, AES_INT_AESIC_POS);//huanglt
	while(AES_INT & AES_INT_AESIF);
	SFR_CLR_BIT_ASM(AES_INT, AES_INT_AESIC_POS);
}

/**
  * ������ AES �ж�ʹ��λ
  * ���룺 NewState:
  * 				ENABLE: AES �ж�ʹ��
  * 				DISABLE: AES �жϽ�ֹ
  * ���أ� �ޡ�
  */
void AES_INT_Enable(AbleStatus NewState)
{
	/* ����У�� */
	CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

	AES_INT = SFR_Config(AES_INT, ~AES_INT_AESIE, NewState);
}


/**
  * ���� AES����Ĵ�����
  * ����  INPUTDATA:λ��bit32
  * ����  �ޡ�
  */
void AES_INPUT0_DATA (uint32_t DATA)
{

	AES_SFR->INPUT0=DATA;
}
void AES_INPUT1_DATA (uint32_t DATA)
{

	AES_SFR->INPUT1=DATA;
}
void AES_INPUT2_DATA (uint32_t DATA)
{

	AES_SFR->INPUT2=DATA;
}
void AES_INPUT3_DATA (uint32_t DATA)
{

	AES_SFR->INPUT3=DATA;
}
/**
  * ���� AES����Ĵ�����
  * ���� :��
  * ���أ� OUTPUTDATA:λ��bit32
  */
uint32_t GET_AES_OUTPUT0_DATA (void)
{
	uint32_t DATA;
	DATA=AES_SFR->OUTPUT0;

	return	DATA;
}
uint32_t GET_AES_OUTPUT1_DATA (void)
{
	uint32_t DATA;
	DATA=AES_SFR->OUTPUT1;

	return	DATA;
}
uint32_t GET_AES_OUTPUT2_DATA (void)
{
	uint32_t DATA;
	DATA=AES_SFR->OUTPUT2;

	return	DATA;
}
uint32_t GET_AES_OUTPUT3_DATA (void)
{
	uint32_t DATA;
	DATA=AES_SFR->OUTPUT3;

	return	DATA;
}
