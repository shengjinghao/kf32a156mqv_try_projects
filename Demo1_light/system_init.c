/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : system_init.c                                         *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-8                                             *
 *  $Hard Version     : KF32A156-MINI-EVB_V1.2                                *
 *  $Description$     : This file contains the system clock configuration 	  *
 * 						for KF32A156 device                                  *
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
#include "system_init.h"

/*******************************************************************************
**                      	Private Macro Definitions                         **
*******************************************************************************/
/**
 * @brief In the following line adjust the Internal High Speed oscillator (HSI) 
 * Startup Timeout value at least 200us default.
 * */
#if !defined  (HSI_STARTUP_TIMEOUT) 
  #define HSI_STARTUP_TIMEOUT    	((uint16_t)0x0070)   /*!< Time out for HSI start up >*/
#endif /* HSI_STARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) 
 * Startup Timeout value at least 4ms default.
 * */
#if !defined  (HSE_STARTUP_TIMEOUT) 
  #define HSE_STARTUP_TIMEOUT		((uint16_t)0xA39)   /*!< Time out for HSE start up >*/
#endif /* HSE_STARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) 
 * fast startup Timeout value at least 200us default.In fast startup mode, the 
 * OSCIN pin shouldbe temporarily configured  the output mode to ground, then 
 * it should be configured the analog mode.
 * */
#if !defined  (HSE_FASTSTARTUP_TIMEOUT) 
  #define HSE_FASTSTARTUP_TIMEOUT	((uint16_t)0x0070)   /*!< Time out for HSE fast start up mode >*/
#endif /* HSE_FASTSTARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the PLL Startup Timeout value at 
 * least 800us default.
 * */
#if !defined  (PLL_STARTUP_TIMEOUT) 
  #define PLL_STARTUP_TIMEOUT    ((uint16_t)0x0400)   /*!< Time out for PLL startup >*/
#endif /* PLL_STARTUP_TIMEOUT */

/**
 * @brief In the following line define the common clock frequency values.
 * If an external High Speed oscillator (HSE) is not use, EXTHF frequency
 * is 16M default. 
 * */
#define INTHF_FREQ_16MHz	   	16000000	/*!< INTHF frequency is 16M >*/
#define INTLF_FREQ_32KHz	   	32000		/*!< INTLF frequency is 32K >*/
#ifdef 	SYSCLK_FREQ_HSE
#define EXTHF_FREQ_xMHz			SYSCLK_FREQ_HSE
#else
#define EXTHF_FREQ_xMHz			16000000	/*!< EXTHF frequency is 16M default >*/
#endif
#define EXTLF_FREQ_32768Hz	   	32768		/*!< EXTLF frequency is 32.768K default >*/
#define LP4M_FREQ_4MHz		   	4000000		/*!< LP4M frequency is 4M >*/

/*******************************************************************************
**                      	Private Variables Definitions                  	  **
*******************************************************************************/
static uint8_t 	fac_us;
static uint16_t fac_ms;

/*******************************************************************************
**                      	Private Functions 		             	      	  **
*******************************************************************************/
static void SetSysClock(uint8_t SCLK_Value);

/**
 *  @brief :Configure the System clock source,PLL Multiplier and Divider factors.
 * 			If an external High Speed oscillator (HSE) is use, it would be the 
 * 			PLL clock source,otherwise the PLL clock source is HSI.Choose INTHF 
 * 			or EXTHF by define SYSCLK_FREQ_HSI or SYSCLK_FREQ_HSE in "system_init.h".
 *  @param in :SCLK_Value System master clock frequency,MHZ
 *  @param out :None
 *  @retval :None
 */
static void SetSysClock(uint8_t SCLK_Value)
{
	volatile uint32_t StartUpCounter;
/**
 * ******************************************************************************
 * 	Enable INTHF & INTLF,and set the INTHF as the SCLK.
 * 	Wait till INTHF is ready and if Time out is reached exit.
 * ******************************************************************************
 */
	OSC_INTLF_Software_Enable(TRUE);
	OSC_INTHF_Software_Enable(TRUE);
	FLASH_CFG = 0xC7;                        
	/* Set the INTHF as the SCLK DIV<1:1> */
	OSC_SCK_Division_Config(SCLK_DIVISION_1); 
	OSC_SCK_Source_Config(SCLK_SOURCE_INTHF);
	StartUpCounter = HSI_STARTUP_TIMEOUT;
	while (--StartUpCounter);
	while (OSC_Get_INTHF_INT_Flag() != SET);
/**
 * ******************************************************************************
 * Configure the PLL clock source is HES or HEI by define SYSCLK_FREQ_HSI or 
 * SYSCLK_FREQ_HSE in "system_init.h".
 * If an external clock source is used, must be wait till EXTHF is ready and if 
 * Time out is reached exit.
 * ******************************************************************************
 */
#ifdef SYSCLK_FREQ_HSI
	OSC_PLL_Input_Source_Config(PLL_INPUT_INTHF);
#else
	/* Config the BKP area is enable, BKP register and data can be write and read,and enable EXTHF pins */
	SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPREGCLR_POS);
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPWR_POS);
    SFR_CLR_BIT_ASM(PM_CAL1, PM_CAL1_HSE_SEL_POS);
	/* If an external clock frequency is more than 20M, should be set the HSFSEN bit 
	   in OSC_HFOSCCAL1 register */
	#if (SYSCLK_FREQ_HSE < 20000000)
	{
		SFR_SET_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HLSW_POS);
	}
	#endif
#if defined (KF32A136)
		SFR_SET_BIT_ASM(PM_CAL1, PM_CAL1_HSE_SEL_POS);
		GPIO_Write_Mode_Bits(GPIOD_SFR, GPIO_PIN_MASK_14, GPIO_MODE_OUT);
		GPIO_Set_Output_Data_Bits(GPIOD_SFR, GPIO_PIN_MASK_14, Bit_RESET);
		StartUpCounter = HSE_FASTSTARTUP_TIMEOUT;
		while (--StartUpCounter);
		GPIO_Write_Mode_Bits(GPIOD_SFR, GPIO_PIN_MASK_14, GPIO_MODE_AN);
		/* Must be wait till EXTHF is ready and if Time out is reached exit */
		OSC_EXTHF_Software_Enable(TRUE);
		OSC_EXTHF_Start_Delay_Config(EXT_START_DELAY_256);
		StartUpCounter = HSE_STARTUP_TIMEOUT;
		while (StartUpCounter--);
		while(OSC_Get_EXTHF_INT_Flag() != SET);
		OSC_SCK_Source_Config(SCLK_SOURCE_EXTHF);
		OSC_PLL_Input_Source_Config(PLL_INPUT_EXTHF);
#else
	/* External oscillator default working  in fast startup mode */
	GPIO_Write_Mode_Bits(GPIOH_SFR, GPIO_PIN_MASK_11, GPIO_MODE_OUT);
	GPIO_Set_Output_Data_Bits(GPIOH_SFR, GPIO_PIN_MASK_11, Bit_RESET);
	StartUpCounter = HSE_FASTSTARTUP_TIMEOUT;
	while (--StartUpCounter);
	GPIO_Write_Mode_Bits(GPIOH_SFR, GPIO_PIN_MASK_11, GPIO_MODE_AN);
	/* Must be wait till EXTHF is ready and if Time out is reached exit */
	OSC_EXTHF_Software_Enable(TRUE);         
	OSC_EXTHF_Start_Delay_Config(EXT_START_DELAY_256);
	StartUpCounter = HSE_STARTUP_TIMEOUT;
	while (StartUpCounter--);    
	while(OSC_Get_EXTHF_INT_Flag() != SET);	
	OSC_SCK_Source_Config(SCLK_SOURCE_EXTHF);
	OSC_PLL_Input_Source_Config(PLL_INPUT_EXTHF);
#endif
#endif
/**
 * ******************************************************************************
 * Configure the System clock source,PLL Multiplier and Divider factors,must be 
 * wait till PLL is ready and if Time out is reached exit.
 * Enable HFCLK and if EXTHF is invalid configure the HFCLK default clock source 
 * is HSI.
 * Enable LFCLK and if configure the LFCLK default clock source is LSI.
 * ******************************************************************************
 */
if((SCLK_Value >= 25) && (SCLK_Value <= 120))
{
	OSC_PLL_Multiple_Value_Select(PLL_Value_Select[SCLK_Value-25][0],	\
				PLL_Value_Select[SCLK_Value-25][1],PLL_Value_Select[SCLK_Value-25][2]);

#ifdef SYSCLK_FREQ_HSI
	OSC_PLL_Start_Delay_Config(PLL_START_DELAY_8192);
#else
	#if (SYSCLK_FREQ_HSE <= 8000000)
		OSC_PLL_Start_Delay_Config(PLL_START_DELAY_4096);
	#elif (SYSCLK_FREQ_HSE <= 16000000)
		OSC_PLL_Start_Delay_Config(PLL_START_DELAY_8192);
	#else
		OSC_PLL_Start_Delay_Config(PLL_START_DELAY_16384);
	#endif
#endif
	OSC_PLL_Software_Enable(TRUE);
	OSC_PLL_RST(); 
	while (OSC_Get_PLL_INT_Flag() != SET);
	if(SCLK_Value <= 48)
		FLASH_CFG = 0xC2;
	else if(SCLK_Value <= 96)
		FLASH_CFG = 0xC4;
	else if(SCLK_Value <= 120)
		FLASH_CFG = 0xC5;
	/* Configure the System clock source is PLL */
	OSC_SCK_Division_Config(SCLK_DIVISION_1);
	OSC_SCK_Source_Config(SCLK_SOURCE_PLL);
}
else
{
	OSC_SCK_Division_Config(SCLK_DIVISION_1);
#ifdef SYSCLK_FREQ_HSI
	OSC_SCK_Source_Config(SCLK_SOURCE_INTHF);
#else
	OSC_SCK_Source_Config(SCLK_SOURCE_EXTHF);
#endif
}
	/* Enable HFCLK and if EXTHF is invalid configure the HFCLK default clock source is HSI DIV<1:1> */
	OSC_HFCK_Division_Config(HFCK_DIVISION_1);
#ifdef SYSCLK_FREQ_HSI
	OSC_HFCK_Source_Config(HFCK_SOURCE_INTHF);
#else
	OSC_HFCK_Source_Config(HFCK_SOURCE_EXTHF);
#endif
	OSC_HFCK_Enable(TRUE);
#ifdef SYSCLK_FREQ_INTLF
	/* Enable LFCLK and if configure the LFCLK default clock source is LSI DIV<1:1> */
	OSC_LFCK_Division_Config(LFCK_DIVISION_1);
	OSC_LFCK_Source_Config(LFCK_INPUT_INTLF);
	OSC_LFCK_Enable(TRUE);
#else
	/* Config the BKP area is enable, BKP register and data can be write and read,and enable EXTHF pins */
	SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPREGCLR_POS);
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPWR_POS);
	PM_EXTLF_PIN_Selection_Config(PM_EXTLF_PIN1_IO_PORT);
	PM_CAL1 |=(uint32_t)3;	//choose most driver current
	OSC_EXTLF_Software_Enable(TRUE);
	OSC_EXTLF_Start_Delay_Config(EXT_START_DELAY_1024);
	while(OSC_Get_EXTLF_INT_Flag() != SET);

#endif
}

/*******************************************************************************
**                      	Global Functions 		             	      	  **
*******************************************************************************/
/**
 *  @brief :Setup the microcontroller system.
 * 			Initialize PLL, HFCLK, LFCLK, and the PLL and update the systemFrequency variable.	
 *  @param in :SCLK_Value System master clock frequency,MHZ
 *  @param out :None
 *  @retval :None
 */
void SystemInit(uint8_t SCLK_Value)
{
	/*set A02 features*/
//	SFR_SET_BIT_ASM(PM_CAL0,PM_CAL0_A01TOA02EN_POS);
    /* Configure the System clock source, PLL Multiplier and Divider factors */
	SetSysClock(SCLK_Value);
// 	CANFD_SCLK_MHZ = SCLK_Value;
// 	#if !defined (SYSCLK_FREQ_HSE)
// 	CANFD_HFCLK_MHZ = (uint8_t)(SYSCLK_FREQ_HSI/1000000) ;
// 	#else
// 	CANFD_HFCLK_MHZ = (uint8_t)(SYSCLK_FREQ_HSE/1000000);
// 	#endif
}

/**
 *  @brief :Initialize the systick timer for delay function without interrupt.
 * 			Must be Initialized before use "systick_delay_us" and "systick_delay_ms".
 *  @param in :SCLK_Value System master clock frequency,MHZ
 *  @param out :None
 *  @retval :None
 */
void systick_delay_init(uint32_t InputClock)
{
	SYSTICK_Cmd(FALSE);
	SYSTICK_Clock_Config(SYSTICK_SYS_CLOCK_DIV_2);
	SFR_CLR_BIT_ASM(ST_CALI, ST_CALII_STCLKREF_POS);
	fac_us = InputClock >> 1;
	fac_ms = fac_us * 1000;
}

/**
 *  @brief :Using SysTick timer to realize microsecond delay
 * 			nus<=0xffffff*1000*1000/SYSCLK/2
 *  @param in : nus
 * 			 	In the following line describe the max time at different frequencies
 * 			 	48M�� 699050us
 * 			 	72M�� 466033us
 * 			 	96M�� 349525us
 * 			 	120M��279620us
 *  @param out :None
 *  @retval :None
 */
void systick_delay_us(unsigned int nus)
{
	uint32_t temp;
	SYSTICK_SFR->RELOAD = fac_us * nus;
	SYSTICK_SFR->CV = 0;
	SYSTICK_SFR->CTL |= ST_CTL_STEN;
	do
	{
		temp = ST_CTL;
	} while ((temp & 0x01) && !(temp & (1 << 16)));
	SYSTICK_SFR->CTL &= ~ST_CTL_STEN;
	SYSTICK_SFR->CV = 0;
}

/**
 *  @brief :Using SysTick timer to realize millisecond delay
 * 			nus<=0xffffff*1000/SYSCLK/2
 *  @param in :	nus
 * 			 	In the following line describe the max time at different frequencies
 * 			 	48M�� 699ms
 * 			 	72M�� 466ms
 * 			 	96M�� 349ms
 * 			 	120M��279ms
 *  @param out :None
 *  @retval :None
 */
void systick_delay_ms(unsigned int nms)
{
	uint32_t temp;
	SYSTICK_SFR->RELOAD = (uint32_t)nms * fac_ms;
	SYSTICK_SFR->CV = 0;
	SYSTICK_SFR->CTL |= ST_CTL_STEN;
	do
	{
		temp = ST_CTL;
	} while ((temp & 0x01) && !(temp & (1 << 16)));
	SYSTICK_SFR->CTL &= ~ST_CTL_STEN;
	SYSTICK_SFR->CV = 0;
}

/**
 *  @brief :Update SCLK value variable according to Clock Register Values.
 * 			The SystemCoreClock variable contains the core clock (SCLK), it can
 *          be used by the user application to setup the SysTick timer or configure
 *          other parameters.
 *  @param in :None
 *  @param out :None
 *  @retval :None
 */
uint32_t SystemCoreClockUpdate(void)
{
	uint32_t SystemCoreClock;
    uint32_t tmp = 0, pll_n = 1, pll_m = 0, pll_no = 1;
	uint32_t sckdivfactor = 1;
	uint32_t pllsource = INTHF_FREQ_16MHz;
	tmp = ((OSC_CTL0 >> OSC_CTL0_SCKS0_POS) & 0x07);
	switch (tmp) {
		case SCLK_SOURCE_INTHF:
			SystemCoreClock = INTHF_FREQ_16MHz;
			break;
		case SCLK_SOURCE_INTLF:
			SystemCoreClock = INTLF_FREQ_32KHz;
			break;
		case SCLK_SOURCE_EXTHF:
			SystemCoreClock = EXTHF_FREQ_xMHz;
			break;
		case SCLK_SOURCE_EXTLF:
			SystemCoreClock = EXTLF_FREQ_32768Hz;
			break;
		case SCLK_SOURCE_LP4M:
			SystemCoreClock = LP4M_FREQ_4MHz;
			break;
		case SCLK_SOURCE_PLL:
			if ((OSC_CTL0 >> OSC_CTL0_PLLCKS_POS) & 0x01) {
				pllsource = EXTHF_FREQ_xMHz;
			} else {
				pllsource = INTHF_FREQ_16MHz;
			}
			pll_m = ((PLL_CTL >> PLL_CTL_M0_POS) & 0x3fff);
			pll_n = ((PLL_CTL >> PLL_CTL_N0_POS) & 0x0f);
			pll_no = (0x01 << ((PLL_CTL >> PLL_CTL_OD0_POS) & 0x03));
			sckdivfactor = (0x01 << ((OSC_CTL0 >> OSC_CTL0_SCKDIV0_POS) & 0x07));
			SystemCoreClock = pllsource * pll_m / (pll_n * pll_no * sckdivfactor);
			break;
		default:
			SystemCoreClock = INTHF_FREQ_16MHz;
			break;
	}
	return SystemCoreClock;
}
