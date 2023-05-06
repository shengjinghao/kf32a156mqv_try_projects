/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd                  *
 ******************************************************************************
 *  $File Name$       : KF32A156_canfd.h                               	      *
 *  $Author$          : ChipON AE/FAE Group                                   *
 *  $Data$            : 2021-07-08                                            *
 *  $AutoSAR Version  : V1.0	                                       	      *
 *  $Description$     : This file contains the headers of the CANFD			  *
 						peripherals.										  *
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

#ifndef KF32A136_CANFD_H_
#define KF32A136_CANFD_H_
#include "stdint.h"
#include "stdlib.h"
#include "math.h"
#include "KF32A1x6.h"


/******************************************************************************
*                      Variables      Declarations                            *
******************************************************************************/


/******************************************************************************
*                      Macro Implementation                                   *
******************************************************************************/
#define CANfd6                  (0U)
#define CANfd7                  (1U)
#define STD_ON 					(1U)
#define STD_OFF 				(0U)
#define FUNCTION_ENABEL_TIME    (0xFF)
#define RAM_STATE_LOOP_TIME     (0xFF)
#define RAM_CONFLICT_LOOP_TIME  (0xFF)
#define CLEAR_FLAG_TIME         (0xF)
#define HARDWARE_RETRANSMIT     STD_ON
//#define HARDWARE_RECOVERY       STD_OFF
#define HARDWARE_RECOVERY       STD_ON 			// 硬件重启
#define HARDWARE_FILTER         STD_OFF
// #define HARDWARE_FILTER         STD_ON

#define WORKSOURCE_HFCLK        STD_ON
#define CAN_BUSOFF_RECOVERY_INTERRUPT   STD_ON  // 做快慢恢复需要关闭
#define WORKSOURCE_DIVIDE_1     STD_ON
#define SOFACK_NORETRANSMIT     STD_OFF
#define AIBITRATE_SOFTRETRANAMIT  STD_ON 		// 不打开可能会有接收丢帧的风险
#if (AIBITRATE_SOFTRETRANAMIT==STD_ON)
#define	AIBITRATE_SOFTRETRANSMITMAILBOX   Mailbox_0
#endif

#define AVOIDERRORARBITRATE_WRITEMAILBOX STD_OFF
#if (AVOIDERRORARBITRATE_WRITEMAILBOX == STD_ON)
#define	ERRORARBITRATE_WRITEMAILBOX   Mailbox_0
#endif

/******************************************************************************
*                      Structure Implementation                               *
******************************************************************************/

typedef	union
{
	volatile unsigned int CS_CODE;
	struct
	{
		volatile unsigned int DLC : 4;
		unsigned int : 2;
		volatile unsigned int RTR : 1;
		volatile unsigned int IDE : 1;
		volatile unsigned int BRS : 1;
		volatile unsigned int ESI : 1;
		volatile unsigned int EDL : 1;
		unsigned int : 1;
		volatile unsigned int CODE : 4;
		volatile unsigned int TIMESTAMP : 16;
	};
}Code_Segment;

typedef union
{
    struct
    {
    	union
    	{
    		volatile unsigned int CS_CODE;
    		struct
    		{
    			volatile unsigned int DLC : 4;
    			volatile unsigned int : 2;
    			volatile unsigned int RTR : 1;
    			volatile unsigned int IDE : 1;
    			volatile unsigned int BRS : 1;
    			volatile unsigned int ESI : 1;
    			volatile unsigned int EDL : 1;
    			volatile unsigned int : 1;
    			volatile unsigned int CODE : 4;
    			volatile unsigned int TIMESTAMP : 16;
    		};
    	};
    	volatile unsigned int DATA1 : 8;
    	volatile unsigned int DATA0 : 8;
    	volatile unsigned int : 4;
    	volatile unsigned int RRTR : 1;
    	volatile unsigned int ID : 11;
    	union
    	{
    		volatile unsigned int DATA3210[2];
    		struct
    		{
    	    	volatile unsigned int DATA5 : 8;
    	    	volatile unsigned int DATA4 : 8;
    	    	volatile unsigned int DATA3 : 8;
    	    	volatile unsigned int DATA2 : 8;

    	    	unsigned int : 8;
    	    	unsigned int : 8;
    	    	volatile unsigned int DATA7 : 8;
    	    	volatile unsigned int DATA6 : 8;
    		};
    	};
    } SFF;

    struct
    {
    	union
    	{
    		volatile unsigned int CS_CODE;
    		struct
    		{
    			volatile unsigned int DLC : 4;
    	        unsigned int : 2;
    	        volatile unsigned int RTR : 1;
    	        volatile unsigned int IDE : 1;
    	        volatile unsigned int BRS : 1;
    	        volatile unsigned int ESI : 1;
    	        volatile unsigned int EDL : 1;
    	        unsigned int : 1;
    	        volatile unsigned int CODE : 4;
    	        volatile unsigned int TIMESTAMP : 16;
    		};
    	};

        unsigned int : 2;
        volatile unsigned int RRTR : 1;
        volatile unsigned int ID : 29;
        union
        {
        	struct
        	{
                volatile unsigned int DATA3210[2];
        	};
        	struct
        	{
                volatile unsigned int DATA3 : 8;
                volatile unsigned int DATA2 : 8;
                volatile unsigned int DATA1 : 8;
                volatile unsigned int DATA0 : 8;
                volatile unsigned int DATA7 : 8;
                volatile unsigned int DATA6 : 8;
                volatile unsigned int DATA5 : 8;
                volatile unsigned int DATA4 : 8;
        	};
        };
    } EFF;
} DataBuffer_8byteType;

typedef union
{
    struct
    {
    	union
    	{
    		volatile unsigned int CS_CODE;
    		struct
    		{
    			volatile unsigned int DLC : 4;
    	        unsigned int : 2;
    	        volatile unsigned int RTR : 1;
    	        volatile unsigned int IDE : 1;
    	        volatile unsigned int BRS : 1;
    	        volatile unsigned int ESI : 1;
    	        volatile unsigned int EDL : 1;
    	        unsigned int : 1;
    	        volatile unsigned int CODE : 4;
    	        volatile unsigned int TIMESTAMP : 16;
    		};
    	};

    	volatile unsigned int DATA1 : 8;
    	volatile unsigned int DATA0 : 8;
        unsigned int : 4;
        volatile unsigned int RRTR : 1;
        volatile unsigned int ID : 11;

    	union
    	{
    		volatile unsigned int DATA3210[4];
    		struct
    		{
    	        volatile unsigned int DATA5 : 8;
    	        volatile unsigned int DATA4 : 8;
    	        volatile unsigned int DATA3 : 8;
    	        volatile unsigned int DATA2 : 8;

    	        volatile unsigned int DATA9 : 8;
    	        volatile unsigned int DATA8 : 8;
    	        volatile unsigned int DATA7 : 8;
    	        volatile unsigned int DATA6 : 8;

    	        volatile unsigned int DATA13 : 8;
    	        volatile unsigned int DATA12 : 8;
    	        volatile unsigned int DATA11 : 8;
    	        volatile unsigned int DATA10 : 8;

    	        unsigned int : 8;
    	        unsigned int : 8;
    	        volatile unsigned int DATA15 : 8;
    	        volatile unsigned int DATA14 : 8;
    		};
    	};
    } SFF;

    struct
    {
    	union
    	{
    		struct
    		{
    			volatile unsigned int DLC : 4;
    	        unsigned int : 2;
    	        volatile unsigned int RTR : 1;
    	        volatile unsigned int IDE : 1;
    	        volatile unsigned int BRS : 1;
    	        volatile unsigned int ESI : 1;
    	        volatile unsigned int EDL : 1;
    	        unsigned int : 1;
    	        volatile unsigned int CODE : 4;
    	        volatile unsigned int TIMESTAMP : 16;
    		};
    		volatile unsigned int CS_CODE;
    	};
        unsigned int : 2;
        volatile unsigned int RRTR : 1;
        volatile unsigned int ID : 29;

        union
        {
        	struct
        	{
                volatile unsigned int DATA3210[4];
        	};
        	struct
        	{
        		volatile unsigned int DATA3 : 8;
				volatile unsigned int DATA2 : 8;
				volatile unsigned int DATA1 : 8;
				volatile unsigned int DATA0 : 8;

				volatile unsigned int DATA7 : 8;
				volatile unsigned int DATA6 : 8;
				volatile unsigned int DATA5 : 8;
				volatile unsigned int DATA4 : 8;

				volatile unsigned int DATA11 : 8;
				volatile unsigned int DATA10 : 8;
				volatile unsigned int DATA9 : 8;
				volatile unsigned int DATA8 : 8;

				volatile unsigned int DATA15 : 8;
				volatile unsigned int DATA14 : 8;
				volatile unsigned int DATA13 : 8;
				volatile unsigned int DATA12 : 8;
        	};
        };
    } EFF;
} DataBuffer_16byteType;

typedef union
{
    struct
    {
    	union
    	{
    		volatile unsigned int CS_CODE;
    		struct
    		{
    			volatile unsigned int DLC : 4;
    	        unsigned int : 2;
    	        volatile unsigned int RTR : 1;
    	        volatile unsigned int IDE : 1;
    	        volatile unsigned int BRS : 1;
    	        volatile unsigned int ESI : 1;
    	        volatile unsigned int EDL : 1;
    	        unsigned int : 1;
    	        volatile unsigned int CODE : 4;
    	        volatile unsigned int TIMESTAMP : 16;
    		};
    	};

        volatile unsigned int DATA1 : 8;
        volatile unsigned int DATA0 : 8;
        volatile unsigned int : 4;
        volatile unsigned int RRTR : 1;
        volatile unsigned int ID : 11;

    	union
    	{
    		volatile unsigned int DATA3210[8];
    		struct
    		{
			    volatile unsigned int DATA5 : 8;
				volatile unsigned int DATA4 : 8;
				volatile unsigned int DATA3 : 8;
				volatile unsigned int DATA2 : 8;

				volatile unsigned int DATA9 : 8;
				volatile unsigned int DATA8 : 8;
				volatile unsigned int DATA7 : 8;
				volatile unsigned int DATA6 : 8;

				volatile unsigned int DATA13 : 8;
				volatile unsigned int DATA12 : 8;
				volatile unsigned int DATA11 : 8;
				volatile unsigned int DATA10 : 8;

				volatile unsigned int DATA17 : 8;
				volatile unsigned int DATA16 : 8;
				volatile unsigned int DATA15 : 8;
				volatile unsigned int DATA14 : 8;

				volatile unsigned int DATA21 : 8;
				volatile unsigned int DATA20 : 8;
				volatile unsigned int DATA19 : 8;
				volatile unsigned int DATA18 : 8;

				volatile unsigned int DATA25 : 8;
				volatile unsigned int DATA24 : 8;
				volatile unsigned int DATA23 : 8;
				volatile unsigned int DATA22 : 8;

				volatile unsigned int DATA29 : 8;
				volatile unsigned int DATA28 : 8;
				volatile unsigned int DATA27 : 8;
				volatile unsigned int DATA26 : 8;

				volatile unsigned int : 8;
				volatile unsigned int : 8;
				volatile unsigned int DATA31 : 8;
				volatile unsigned int DATA30 : 8;
    		};
    	};
    } SFF;

    struct
    {
    	union
    	{
    		struct
    		{
    			volatile unsigned int DLC : 4;
    	        unsigned int : 2;
    	        volatile unsigned int RTR : 1;
    	        volatile unsigned int IDE : 1;
    	        volatile unsigned int BRS : 1;
    	        volatile unsigned int ESI : 1;
    	        volatile unsigned int EDL : 1;
    	        unsigned int : 1;
    	        volatile unsigned int CODE : 4;
    	        volatile unsigned int TIMESTAMP : 16;
    		};
    		volatile unsigned int CS_CODE;
    	};
        unsigned int : 2;
        volatile unsigned int RRTR : 1;
        volatile unsigned int ID : 29;

        union
		{
			struct
			{
				 volatile unsigned int DATA3210[8];
			};
			struct
			{
				volatile unsigned int DATA3 : 8;
				volatile unsigned int DATA2 : 8;
				volatile unsigned int DATA1 : 8;
				volatile unsigned int DATA0 : 8;

				volatile unsigned int DATA7 : 8;
				volatile unsigned int DATA6 : 8;
				volatile unsigned int DATA5 : 8;
				volatile unsigned int DATA4 : 8;

				volatile unsigned int DATA11 : 8;
				volatile unsigned int DATA10 : 8;
				volatile unsigned int DATA9 : 8;
				volatile unsigned int DATA8 : 8;

				volatile unsigned int DATA15 : 8;
				volatile unsigned int DATA14 : 8;
				volatile unsigned int DATA13 : 8;
				volatile unsigned int DATA12 : 8;

				volatile unsigned int DATA19 : 8;
				volatile unsigned int DATA18 : 8;
				volatile unsigned int DATA17 : 8;
				volatile unsigned int DATA16 : 8;

				volatile unsigned int DATA23 : 8;
				volatile unsigned int DATA22 : 8;
				volatile unsigned int DATA21 : 8;
				volatile unsigned int DATA20 : 8;

				volatile unsigned int DATA27 : 8;
				volatile unsigned int DATA26 : 8;
				volatile unsigned int DATA25 : 8;
				volatile unsigned int DATA24 : 8;

				volatile unsigned int DATA31 : 8;
				volatile unsigned int DATA30 : 8;
				volatile unsigned int DATA29 : 8;
				volatile unsigned int DATA28 : 8;
			};
		};

    } EFF;
} DataBuffer_32byteType;

typedef union
{
    struct
    {
    	union
    	{
    		volatile unsigned int CS_CODE;
    		struct
    		{
    			volatile unsigned int DLC : 4;
    	        unsigned int : 2;
    	        volatile unsigned int RTR : 1;
    	        volatile unsigned int IDE : 1;
    	        volatile unsigned int BRS : 1;
    	        volatile unsigned int ESI : 1;
    	        volatile unsigned int EDL : 1;
    	        unsigned int : 1;
    	        volatile unsigned int CODE : 4;
    	        volatile unsigned int TIMESTAMP : 16;
    		};
    	};



    	volatile  unsigned int DATA1 : 8;
    	volatile unsigned int DATA0 : 8;
    	volatile unsigned int : 4;
    	volatile unsigned int RRTR : 1;
    	volatile unsigned int ID : 11;

    	union
		{
			volatile unsigned int DATA3210[16];
			struct
			{
				volatile unsigned int DATA5 : 8;
				volatile unsigned int DATA4 : 8;
				volatile unsigned int DATA3 : 8;
				volatile unsigned int DATA2 : 8;

				volatile unsigned int DATA9 : 8;
				volatile unsigned int DATA8 : 8;
				volatile unsigned int DATA7 : 8;
				volatile unsigned int DATA6 : 8;

				volatile unsigned int DATA13 : 8;
				volatile unsigned int DATA12 : 8;
				volatile unsigned int DATA11 : 8;
				volatile unsigned int DATA10 : 8;

				volatile unsigned int DATA17 : 8;
				volatile unsigned int DATA16 : 8;
				volatile unsigned int DATA15 : 8;
				volatile unsigned int DATA14 : 8;

				volatile unsigned int DATA21 : 8;
				volatile unsigned int DATA20 : 8;
				volatile unsigned int DATA19 : 8;
				volatile unsigned int DATA18 : 8;

				volatile unsigned int DATA25 : 8;
				volatile unsigned int DATA24 : 8;
				volatile unsigned int DATA23 : 8;
				volatile unsigned int DATA22 : 8;

				volatile unsigned int DATA29 : 8;
				volatile unsigned int DATA28 : 8;
				volatile unsigned int DATA27 : 8;
				volatile unsigned int DATA26 : 8;

				volatile unsigned int DATA33 : 8;
				volatile unsigned int DATA32 : 8;
				volatile unsigned int DATA31 : 8;
				volatile unsigned int DATA30 : 8;

				volatile unsigned int DATA37 : 8;
				volatile unsigned int DATA36 : 8;
				volatile unsigned int DATA35 : 8;
				volatile unsigned int DATA34 : 8;

				volatile unsigned int DATA41 : 8;
				volatile unsigned int DATA40 : 8;
				volatile unsigned int DATA39 : 8;
				volatile unsigned int DATA38 : 8;

				volatile unsigned int DATA45 : 8;
				volatile unsigned int DATA44 : 8;
				volatile unsigned int DATA43 : 8;
				volatile unsigned int DATA42 : 8;

				volatile unsigned int DATA49 : 8;
				volatile unsigned int DATA48 : 8;
				volatile unsigned int DATA47 : 8;
				volatile unsigned int DATA46 : 8;

				volatile unsigned int DATA53 : 8;
				volatile unsigned int DATA52 : 8;
				volatile unsigned int DATA51 : 8;
				volatile unsigned int DATA50 : 8;

				volatile unsigned int DATA57 : 8;
				volatile unsigned int DATA56 : 8;
				volatile unsigned int DATA55 : 8;
				volatile unsigned int DATA54 : 8;

				volatile unsigned int DATA61 : 8;
				volatile unsigned int DATA60 : 8;
				volatile unsigned int DATA59 : 8;
				volatile unsigned int DATA58 : 8;

		        unsigned int : 8;
		        unsigned int : 8;
		        volatile unsigned int DATA63 : 8;
		        volatile unsigned int DATA62 : 8;
			};
		};
    } SFF;

    struct
    {
    	union
    	{
    		struct
    		{
    			volatile unsigned int DLC : 4;
    	        unsigned int : 2;
    	        volatile unsigned int RTR : 1;
    	        volatile unsigned int IDE : 1;
    	        volatile unsigned int BRS : 1;
    	        volatile unsigned int ESI : 1;
    	        volatile unsigned int EDL : 1;
    	        unsigned int : 1;
    	        volatile unsigned int CODE : 4;
    	        volatile unsigned int TIMESTAMP : 16;
    		};
    		volatile unsigned int CS_CODE;
    	};

    	volatile unsigned int : 2;
    	volatile unsigned int RRTR : 1;
    	volatile unsigned int ID : 29;


    	union
    	{
			struct
			{
				 volatile unsigned int DATA3210[16];
			};

			struct
			{
				volatile unsigned int DATA3 : 8;
				volatile unsigned int DATA2 : 8;
				volatile unsigned int DATA1 : 8;
				volatile unsigned int DATA0 : 8;

				volatile  unsigned int DATA7 : 8;
				volatile unsigned int DATA6 : 8;
				volatile unsigned int DATA5 : 8;
				volatile unsigned int DATA4 : 8;

				volatile unsigned int DATA11 : 8;
				volatile unsigned int DATA10 : 8;
				volatile unsigned int DATA9 : 8;
				volatile unsigned int DATA8 : 8;

				volatile unsigned int DATA15 : 8;
				volatile unsigned int DATA14 : 8;
				volatile unsigned int DATA13 : 8;
				volatile unsigned int DATA12 : 8;

				volatile unsigned int DATA19 : 8;
				volatile unsigned int DATA18 : 8;
				volatile unsigned int DATA17 : 8;
				volatile unsigned int DATA16 : 8;

				volatile unsigned int DATA23 : 8;
				volatile unsigned int DATA22 : 8;
				volatile unsigned int DATA21 : 8;
				volatile unsigned int DATA20 : 8;

				volatile unsigned int DATA27 : 8;
				volatile unsigned int DATA26 : 8;
				volatile unsigned int DATA25 : 8;
				volatile unsigned int DATA24 : 8;

				volatile unsigned int DATA31 : 8;
				volatile unsigned int DATA30 : 8;
				volatile unsigned int DATA29 : 8;
				volatile unsigned int DATA28 : 8;

				volatile unsigned int DATA35 : 8;
				volatile unsigned int DATA34 : 8;
				volatile unsigned int DATA33 : 8;
				volatile unsigned int DATA32 : 8;

				volatile unsigned int DATA39 : 8;
				volatile unsigned int DATA38 : 8;
				volatile unsigned int DATA37 : 8;
				volatile unsigned int DATA36 : 8;

				volatile unsigned int DATA43 : 8;
				volatile unsigned int DATA42 : 8;
				volatile unsigned int DATA41 : 8;
				volatile unsigned int DATA40 : 8;

				volatile unsigned int DATA47 : 8;
				volatile unsigned int DATA46 : 8;
				volatile unsigned int DATA45 : 8;
				volatile unsigned int DATA44 : 8;

				volatile unsigned int DATA51 : 8;
				volatile unsigned int DATA50 : 8;
				volatile unsigned int DATA49 : 8;
				volatile unsigned int DATA48 : 8;

				volatile unsigned int DATA55 : 8;
				volatile unsigned int DATA54 : 8;
				volatile unsigned int DATA53 : 8;
				volatile unsigned int DATA52 : 8;

				volatile unsigned int DATA59 : 8;
				volatile unsigned int DATA58 : 8;
				volatile unsigned int DATA57 : 8;
				volatile unsigned int DATA56 : 8;

				volatile unsigned int DATA63 : 8;
				volatile unsigned int DATA62 : 8;
				volatile unsigned int DATA61 : 8;
				volatile unsigned int DATA60 : 8;
			};
    	};
    } EFF;
} DataBuffer_64byteType;

typedef union
{
    DataBuffer_8byteType DataBuffer_8byte;
    DataBuffer_16byteType DataBuffer_16byte;
    DataBuffer_32byteType DataBuffer_32byte;
    DataBuffer_64byteType DataBuffer_64byte;

} DataBuffer_RegType;
/*can_fd reg*/
typedef struct
{
    /* offset : 0x000.                              */
    union
    {
        unsigned int R;
        struct
        {
            unsigned int RSMOD : 1;
            unsigned int SILENT : 1;
            unsigned int LBACK : 1;
            unsigned int SLEEP : 1;
            unsigned int ISOFDCANEN : 1;
            unsigned int CANCKS : 2;
            unsigned int CANEN : 1;
            volatile unsigned int TXR : 1;
            volatile unsigned int ATX : 1;
            unsigned int RELRX : 1;
            volatile unsigned int RELF : 1;
            volatile unsigned int MBSIZE : 2;
            unsigned int FULLRXEN : 1;
            unsigned int ANSWEREN : 1;
            unsigned int RXBSTA : 1;
            unsigned int DOSTA : 1;
            unsigned int TXBSTA: 1;
            unsigned int TCSTA : 1;
            volatile unsigned int RXSTA : 1;
            volatile unsigned int TXSTA : 1;
            unsigned int CERROR : 1;
            volatile unsigned int BOFF : 1;
            volatile unsigned int CANRMC : 7;
            unsigned int CANFDEN : 1;

        } B;
    } CANFD_CTLR0;

    /* offset : 0x004.                              */
    union
    {
        unsigned int R;
        struct
        {
            unsigned int CANBRP : 6;
            unsigned int SJW : 2;
            unsigned int TSEG1 : 4;
            unsigned int TSEG2 : 3;
            unsigned int SAM : 1;
            unsigned int BRSBRP : 6;
            unsigned int HTSEG1 : 4;
            unsigned int HTSEG2 : 3;
            unsigned int : 3;

        } B;
    } CANFD_BRGR;

    /* offset : 0x008.                              */
    union
    {
        unsigned int R;
        struct
        {
        	volatile unsigned int CANALC : 5;
            unsigned int : 3;
            volatile unsigned int CANSEG : 5;
            volatile unsigned int CANDIR : 1;
            volatile unsigned int CANERRC : 2;
            unsigned int DPRAMOF: 1;
            unsigned int : 15;
        } B;
    } CANFD_RCR;

    /* offset : 0x00C.                              */
    union
    {
        unsigned int R;
        struct
        {
        	volatile unsigned int CANRXE : 8;
        	volatile unsigned int CANTXE : 8;
        	volatile unsigned int CANEWL : 8;
            unsigned int SOSFD : 5;
            unsigned int SFDEN : 1;
            unsigned int SFDMOD : 1;
            unsigned int DPRAMFEN: 1;
        } B;
    } CANFD_EROR;
    /* offset : 0x010.                              */
    union
    {
        unsigned int R;
        struct
        {
            unsigned int TDCV : 7;
            unsigned int TDCOEN : 1;
            unsigned int TDCEN : 1;
            unsigned int TDCSAUTO : 1;
            unsigned int TDCS : 2;
            unsigned int TDCSR : 2;
            unsigned int TDCO : 2;
            unsigned int TDCVM : 7;
            unsigned int TEST0 : 1;
            unsigned int DESEL : 1;
            unsigned int AMCKDIV : 2;
            unsigned int TEST1 : 1;
            unsigned int TEST2 : 1;
            unsigned int TEST3 : 1;
            unsigned int TEST4 : 1;
            unsigned int TEST5 : 1;
        } B;
    } CANFD_CTLR2;

    /* offset : 0x014.                              */
    unsigned int CANFD_MSKR;

    /* offset : 0x018.                              */
    union
    {
        unsigned int R;
        struct
        {
            unsigned int CANRXIE : 1;
            unsigned int CANTXIE : 1;
            unsigned int EAIE : 1;
            unsigned int DOVFIE : 1;
            unsigned int WUIE : 1;
            unsigned int ENIE : 1;
            unsigned int ALIE : 1;
            unsigned int BEIE : 1;
            unsigned int CTXDE : 1;
            unsigned int CRXDE : 1;
            unsigned int RXBSTAIE : 1;
            unsigned int TRGMBIE : 1;
            unsigned int BOFFIE : 1;
            unsigned int TDCFAILIE : 1;
            unsigned int ARBFAILIE : 1;
            unsigned int MOENDIE : 1;
            unsigned int CANRXIC : 1;
            unsigned int CANTXIC : 1;
            unsigned int EAIC : 1;
            unsigned int DOVFIC : 1;
            unsigned int WUIC : 1;
            unsigned int ENIC : 1;
            unsigned int ALIC : 1;
            unsigned int BEIC : 1;
            unsigned int : 1;
            unsigned int TRANSMITIC : 1;
            unsigned int MOENDIC : 1;
            unsigned int TRGMBIC : 1;
            unsigned int BOFFIC : 1;
            unsigned int TDCFAILIC : 1;
            unsigned int LPCANGPIOSEL0 : 1;
            unsigned int FAILCLR: 1;

        } B;
    } CANFD_IER;

    /* offset : 0x01C.                              */
    union
    {
    	struct
    	{
    		volatile unsigned int Canfd_Interrupt_Flag : 16;
    		volatile unsigned int : 16;
    	}R;

        struct
        {
        	volatile unsigned int CANRXIF : 1;
        	volatile unsigned int CANTXIF : 1;
        	volatile unsigned int EAIF : 1;
        	volatile unsigned int DOVFIF : 1;
        	volatile unsigned int WUIF : 1;
        	volatile unsigned int ENIF : 1;
        	volatile unsigned int ALIF : 1;
        	volatile unsigned int BEIF : 1;
        	volatile unsigned int CTXDF : 1;
        	volatile unsigned int CRXDF : 1;
        	volatile unsigned int RXBSTAIF : 1;
        	volatile unsigned int TRGMBIF : 1;
        	volatile unsigned int BOFFIF : 1;
        	volatile unsigned int TDCFAILIF : 1;
        	volatile unsigned int MOENDIF : 1;
            unsigned int : 17;

        } B;
    } CANFD_IFR;

    /* offset : 0x20-64.                            */
    DataBuffer_RegType CANFD_DATA;

    /* offset : 0x68.                               */
    union
    {
        unsigned int R;
        struct
        {
        	volatile unsigned int CANTIMER : 16;
            unsigned int : 16;

        } B;
    } CANFD_TIMER;

    /* offset : 0x06C.                             */
    union
    {
        unsigned int R;
        struct
        {
            unsigned int CRC : 21;
            unsigned int : 7;
            unsigned int STUFFCNT : 4;

        } B;
    } CANFD_CRC;

    /* offset : 0x070.                             */
    unsigned int RESERVED2;

    /* offset : 0x074.                             */
    union
    {
        unsigned int R;
        struct
        {
            unsigned int AMCKS : 2;
            unsigned int RXMUX : 7;
            unsigned int ST : 1;
            unsigned int FTCLKS : 1;
            unsigned int TSYN : 1;
            unsigned int MBNUM : 1;
            unsigned int MATCHMS : 1;
            unsigned int MBMSKEN : 1;
            unsigned int ARBMS : 1;
            unsigned int ARBSTART : 1;
            unsigned int LBSEL : 1;
            unsigned int BOFFREC : 1;
            unsigned int CKMODE : 1;
            unsigned int TRGNUM : 4;
            unsigned int TRGMBSEL : 7;
            unsigned int TRGMBEN : 1;
        } B;
    } CANFD_CTLR1;

    /* offset : 0x078.                             */
    union
    {
        unsigned int R;
        struct
        {
            unsigned int MATWINNER : 10;
            unsigned int MATSTA : 1;
            unsigned int ROPSTA : 1;
            unsigned int RELRXALL : 1;
            unsigned int IDSELEN : 1;
            unsigned int RTRMEN : 1;
            unsigned int BETEN : 1;
            unsigned int ARBWINNER : 10;
            unsigned int ARBSTA0 : 1;
            unsigned int ARBSTA1 : 1;
            unsigned int TXCODE : 4;

        } B;
    } CANFD_AMSTA;

} Kf32a_Canfd_Reg;


struct Kf32a_Int_Reg{
    /* offset : 0x000.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int AIE:                       1;
		    unsigned int PRIGROUP:                  2;
		    unsigned int :                          1;
		    unsigned int INTPENDING:                1;
		    unsigned int INTPREEMPT:                1;
		    unsigned int FAULTMASK:                 1;
		    unsigned int DSALIGN:                   1;
		    unsigned int :                          4;
		    unsigned int PRIBASE:                   4;
		    unsigned int INTPEND:                   7;
		    unsigned int :                          1;
		    unsigned int INTACT:                    7;
		    unsigned int :                          1;
        }B;
    }CTL0;

    /* offset : 0x004.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int :                          3;
		    unsigned int HADRFAULTIE:               1;
		    unsigned int :                          1;
		    unsigned int STACKIE:                   1;
		    unsigned int ARIFAULTIE:                1;
		    unsigned int :                          1;
		    unsigned int :                          3;
		    unsigned int SVCIE:                     1;
		    unsigned int :                          2;
		    unsigned int SOFTSVIE:                  1;
		    unsigned int SYSTICKIE:                 1;
		    unsigned int :                          16;
        }B;
    }EIE0;

    /* offset : 0x008.                                                       */
    unsigned int RESERVED0;
    /* offset : 0x00C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int WWDTIE:                    1;
		    unsigned int EINT16IE:                  1;
		    unsigned int EINT0IE:                   1;
		    unsigned int EINT1IE:                   1;
		    unsigned int EINT2IE:                   1;
		    unsigned int EINT3IE:                   1;
		    unsigned int EINT4IE:                   1;
		    unsigned int EINT9TO5IE:                1;
		    unsigned int EINT15TO10IE:              1;
		    unsigned int T1IE:                      1;
		    unsigned int T3IE:                      1;
		    unsigned int T5IE:                      1;
		    unsigned int T6IE:                      1;
		    unsigned int QEI0IE:                    1;
		    unsigned int QEII1E:                    1;
		    unsigned int ECFGLIE:                   1;
		    unsigned int CAN4IE:                    1;
		    unsigned int T14IE:                     1;
		    unsigned int :                          1;
		    unsigned int FDC2IE:                    1;
		    unsigned int EXICIE:                    1;
		    unsigned int ADC0IE:                    1;
		    unsigned int ADC1IE:                    1;
		    unsigned int CFGLIE:                    1;
		    unsigned int T11IE:                     1;
		    unsigned int T0IE:                      1;
		    unsigned int DMA0IE:                    1;
		    unsigned int CMPIE:                     1;
		    unsigned int USART0IE:                  1;
		    unsigned int USART1IE:                  1;
		    unsigned int SPI0IE:                    1;
		    unsigned int SPI1IE:                    1;
        }B;
    }EIE1;

    /* offset : 0x010.                                                       */
    unsigned int RESERVED1;

    /* offset : 0x014.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int DMA1IE:                    1;
		    unsigned int EINT19TO17IE:              1;
		    unsigned int CANFD6IE:                  1;
    	    unsigned int CANFD7IE:                  1;
		    unsigned int T9IE:                      1;
		    unsigned int T10IE:                     1;
		    unsigned int EINT20IE:                  1;
		    unsigned int :                          1;
		    unsigned int OSCIE:                     1;
		    unsigned int I2C0IE:                    1;
		    unsigned int I2C1IE:                    1;
		    unsigned int I2C2IE:                    1;
		    unsigned int :                          1;
		    unsigned int T2IE:                      1;
		    unsigned int T4IE:                      1;
		    unsigned int CTOUCHIE:                  1;
		    unsigned int USART2IE:                  1;
		    unsigned int USART3IE:                  1;
		    unsigned int :                          1;
		    unsigned int :                          1;
		    unsigned int :                          1;
		    unsigned int ADC2IE:                    1;
		    unsigned int T18IE:                     1;
		    unsigned int T19IE:                     1;
		    unsigned int T22T23IE:                  1;
		    unsigned int WKPIE:                     1;
		    unsigned int T20IE:                     1;
		    unsigned int T21IE:                     1;
		    unsigned int :                          1;
		    unsigned int :                          1;
		    unsigned int :                          1;
		    unsigned int :                          1;
        }B;
    }EIE2;

    /* offset : 0x018.                                                       */
    unsigned int RESERVED2;

    /* offset : 0x01C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int :                          2;
		    unsigned int NMIIF:                     1;
		    unsigned int HARDFAULTIF:               1;
		    unsigned int :                          1;
		    unsigned int STACKIF:                   1;
		    unsigned int ARIFAULTIF:                1;
		    unsigned int :                          3;
		    unsigned int :                          1;
		    unsigned int SVCIF:                     1;
		    unsigned int :                          1;
		    unsigned int :                          1;
		    unsigned int SOFTSVIF:                  1;
		    unsigned int SYSTICKIF:                 1;
		    unsigned int :                          16;
        }B;
    }EIF0;

    /* offset : 0x020.                                                       */
    unsigned int RESERVED3;

    /* offset : 0x024.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int WWDTIF:                    1;
		    unsigned int EINT16IF:                  1;
		    unsigned int EINT0IF:                   1;
		    unsigned int EINT1IF:                   1;
		    unsigned int EINT2IF:                   1;
		    unsigned int EINT3IF:                   1;
		    unsigned int EINT4IF:                   1;
		    unsigned int EINT9TO5IF:                1;
		    unsigned int EINT15TO10IF:              1;
		    unsigned int T1IF:                      1;
		    unsigned int T3IF:                      1;
		    unsigned int T5IF:                      1;
		    unsigned int T6IF:                      1;
		    unsigned int QEI0IF:                    1;
		    unsigned int QEI1IF:                    1;
		    unsigned int PLAIF:                     1;
		    unsigned int CAN4IF:                    1;
		    unsigned int T14IF:                     1;
		    unsigned int RNGIF:                     1;
		    unsigned int PDB2IF:                    1;
		    unsigned int EXICIF:                    1;
		    unsigned int ADC0IF:                    1;
		    unsigned int ADC1IF:                    1;
		    unsigned int CFGLIF:                    1;
		    unsigned int T11IF:                     1;
		    unsigned int T0IF:                      1;
		    unsigned int DMA0IF:                    1;
		    unsigned int CMPIF:                     1;
		    unsigned int USART0IF:                  1;
		    unsigned int USART1IF:                  1;
		    unsigned int SPI0IF:                    1;
		    unsigned int SPI1IF:                    1;
        }B;
    }EIF1;

    /* offset : 0x028.                                                       */
    unsigned int RESERVED4;

    /* offset : 0x02C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int DMA1IF:                    1;
		    unsigned int EINT19TO17IF:              1;
		    unsigned int FLEXCAN6IF:                1;
		    unsigned int FLEXCAN7IF:                1;
		    unsigned int PDB0IF:                    1;
		    unsigned int PDB1IF:                    1;
		    unsigned int EINT31TO20IF:              1;
		    unsigned int ECCIF:                     1;
		    unsigned int OSCIF:                     1;
		    unsigned int I2C0IF:                    1;
		    unsigned int I2C1IF:                    1;
		    unsigned int I2C2IF:                    1;
		    unsigned int T12IF:                     1;
		    unsigned int T2IF:                      1;
		    unsigned int T4IF:                      1;
		    unsigned int T13IF:                     1;
		    unsigned int USART2IF:                  1;
		    unsigned int T16IF:                     1;
		    unsigned int USART4IF:                  1;
		    unsigned int SPI2IF:                    1;
		    unsigned int SPI3IF:                    1;
		    unsigned int ADC2IF:                    1;
		    unsigned int T18IF:                     1;
		    unsigned int T19IF:                     1;
		    unsigned int HRCAP0IF:                  1;
		    unsigned int WKPIF:                     1;
		    unsigned int HRCAP1IF:                  1;
		    unsigned int T21IF:                     1;
		    unsigned int I2C3IF:                    1;
		    unsigned int USART5IF:                  1;
		    unsigned int HRCAP2IF:                  1;
		    unsigned int USART7IF:                  1;
        }B;
    }EIF2;

     /* offset : 0x030.                                                       */
    unsigned int RESERVED5;


    /* offset : 0x034.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI4:                      8;
		    unsigned int PRI5:                      8;
		    unsigned int PRI6:                      8;
		    unsigned int PRI7:                      8;
        }B;
    }IP0;

    /* offset : 0x038.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI8:                      8;
		    unsigned int PRI9:                      8;
		    unsigned int PRI10:                     8;
		    unsigned int PRI11:                     8;
        }B;
    }IP1;

    /* offset : 0x03C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI12:                     8;
		    unsigned int PRI13:                     8;
		    unsigned int PRI14:                     8;
		    unsigned int PRI15:                     8;
        }B;
    }IP2;

    /* offset : 0x040.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PR16:                      8;
		    unsigned int PRI17:                     8;
		    unsigned int PRI18:                     8;
		    unsigned int PRI19:                     8;
        }B;
    }IP3;

    /* offset : 0x044.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI20:                     8;
		    unsigned int PRI21:                     8;
		    unsigned int PRI22:                     8;
		    unsigned int PRI23:                     8;
        }B;
    }IP4;

    /* offset : 0x048.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI24:                     8;
		    unsigned int PRI25:                     8;
		    unsigned int PRI26:                     8;
		    unsigned int PRI27:                     8;
        }B;
    }IP5;

    /* offset : 0x04C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI28:                     8;
		    unsigned int PRI29:                     8;
		    unsigned int PRI30:                     8;
		    unsigned int PRI31:                     8;
        }B;
    }IP6;

    /* offset : 0x050.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI32U:                    4;
            unsigned int PRI32S:                    1;
            unsigned int PRI32P:                    3;
		    unsigned int PRI33:                     8;
		    unsigned int PRI34:                     8;
		    unsigned int PRI35:                     8;
        }B;
    }IP7;

    /* offset : 0x054.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI36:                     8;
		    unsigned int PRI37:                     8;
		    unsigned int PRI38:                     8;
		    unsigned int PRI39:                     8;
        }B;
    }IP8;

    /* offset : 0x058.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI40:                     8;
		    unsigned int PRI41:                     8;
		    unsigned int PRI42:                     8;
		    unsigned int PRI43:                     8;
        }B;
    }IP9;

    /* offset : 0x05C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI44:                     8;
		    unsigned int PRI45:                     8;
		    unsigned int PRI46:                     8;
		    unsigned int PRI47:                     8;
        }B;
    }IP10;

    /* offset : 0x060.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI48:                     8;
		    unsigned int PRI49:                     8;
		    unsigned int PRI50U:                    4;
		    unsigned int PRI50S:                    1;
		    unsigned int PRI50P:                    3;
		    unsigned int PRI51U:                    4;
		    unsigned int PRI51S:                    1;
		    unsigned int PRI51P:                    3;
        }B;
    }IP11;

    /* offset : 0x064.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI52:                     8;
		    unsigned int PRI53:                     8;
		    unsigned int PRI54:                     8;
		    unsigned int PRI55:                     8;
        }B;
    }IP12;

    /* offset : 0x068.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI56:                     8;
		    unsigned int PRI57:                     8;
		    unsigned int PRI58:                     8;
		    unsigned int PRI59:                     8;
        }B;
    }IP13;

    /* offset : 0x06C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI60:                     8;
		    unsigned int PRI61:                     8;
		    unsigned int PRI62:                     8;
		    unsigned int PRI63:                     8;
        }B;
    }IP14;

    /* offset : 0x070.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI64:                     8;
		    unsigned int PRI65:                     8;
		    unsigned int PRI66:                     8;
		    unsigned int PRI67:                     8;
        }B;
    }IP15;

    /* offset : 0x074.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI68:                     8;
		    unsigned int PRI69:                     8;
		    unsigned int PRI70:                     8;
		    unsigned int PRI71:                     8;
        }B;
    }IP16;

    /* offset : 0x078.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI72:8;
		    unsigned int PRI73:8;
		    unsigned int PRI74:8;
		    unsigned int PRI75:8;
        }B;
    }IP17;

    /* offset : 0x07C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int PRI76:8;
		    unsigned int PRI77:8;
		    unsigned int PRI78:8;
		    unsigned int PRI79:8;
        }B;
    }IP18;


    /* offset : 0x080.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int EINTM:21;
		    unsigned int :10;
		    unsigned int :1;
        }B;
    }EINTMASK;

    /* offset : 0x084.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int EINTRI:21;
		    unsigned int :10;
		    unsigned int :1;
        }B;
    }EINTRISE;


    /* offset : 0x088.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int EINTFA:21;
		    unsigned int :10;
		    unsigned int :1;
        }B;
    }EINTFALL;

    /* offset : 0x08C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int EINTIF:21;
		    unsigned int :11;
        }B;
    }EINTF;

    /* offset : 0x090.                                                       */
    unsigned int RESERVED6;

    /* offset : 0x094.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int EINTSOU0:4;
		    unsigned int EINTSOU1:4;
		    unsigned int EINTSOU2:4;
		    unsigned int EINTSOU3:4;
		    unsigned int EINTSOU4:4;
		    unsigned int EINTSOU5:4;
		    unsigned int EINTSOU6:4;
		    unsigned int EINTSOU7:4;
        }B;
    }EINTSS0;

    /* offset : 0x098.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int EINTSOU8:4;
		    unsigned int EINTSOU9:4;
		    unsigned int EINTSOU10:4;
		    unsigned int EINTSOU11:4;
		    unsigned int EINTSOU12:4;
		    unsigned int EINTSOU13:4;
		    unsigned int EINTSOU14:4;
		    unsigned int EINTSOU15:4;
        }B;
    }EINTSS1;

    /* offset : 0x09C.                                                       */
    union
    {
        unsigned int        R;
        struct
        {
            unsigned int INTDELY:8;
		    unsigned int :24;
        }B;
    }CTL1;
};


#define INTERRUPT_REG (*((volatile struct Kf32a_Int_Reg *)0x40200000))
#define INT_BASE_ADDRESS (volatile struct Kf32a_Int_Reg *)0x40200000



struct Kf32a_Mcu_Pclk_Reg
{
	/* offset  : 0x0.    reserved                      */
	unsigned int RESERVED[16];
	/* offset  : 0x40.    Peripheral clock control register 0                      */
	union
	{
		unsigned int R;
		struct
		{
			unsigned int GPIOACLKEN : 1;
			unsigned int GPIOBCLKEN : 1;
			unsigned int GPIOCCLKEN : 1;
			unsigned int GPIODCLKEN : 1;
			unsigned int GPIOECLKEN : 1;
			unsigned int GPIOFCLKEN : 1;
			unsigned int GPIOGCLKEN : 1;
			unsigned int GPIOHCLKEN : 1;
			unsigned int : 23;
			unsigned int : 1;
		} B;
	} CTL0;

	/* offset  : 0x44.    Peripheral clock control register 1.                      */
	union
	{
		unsigned int R;
		struct
		{
			unsigned int : 2;
			unsigned int T1CLKEN : 1;
			unsigned int T2CLKEN : 1;
			unsigned int T3CLKEN : 1;
			unsigned int T4CLKEN : 1;
			unsigned int T5T6CLKEN : 1;
			unsigned int : 1;
			unsigned int T9T10CLKEN : 1;
			unsigned int : 1;
			unsigned int QEI0CLKEN : 1;
			unsigned int ADC0CLKEN : 1;
			unsigned int ADC1CLKEN : 1;
			unsigned int ADC2CLKEN : 1;
			unsigned int DAC0CLKEN : 1;
			unsigned int DAC1CLKEN : 1;
			unsigned int CMPCLKEN : 1;
			unsigned int T0CLKEN : 1;
			unsigned int CTOUCHCLKEN : 1;
			unsigned int USART0CLKEN : 1;
			unsigned int USART1CLKEN : 1;
			unsigned int USART2CLKEN : 1;
			unsigned int USART3CLKEN : 1;
			unsigned int USART4CLKEN : 1;
			unsigned int SPI0CLKEN : 1;
			unsigned int SPI1CLKEN : 1;
			unsigned int I2C0CLKEN : 1;
			unsigned int I2C1CLKEN : 1;
			unsigned int I2C2CLKEN : 1;
			unsigned int LCDCLKEN : 1;
			unsigned int : 1;
			unsigned int USBCLKEN : 1;
		} B;
	} CTL1;

	/* offset  : 0x48.    Peripheral clock control register 2                      */
	union
	{
		unsigned int R;
		struct
		{
			unsigned int : 2;
			unsigned int CAN0CLKEN : 1;
			unsigned int CAN1CLKEN : 1;
			unsigned int : 1;
			unsigned int WWDTCLKEN : 1;
			unsigned int : 6;
			unsigned int DMA0CLKEN : 1;
			unsigned int : 1;
			unsigned int DMA1CLKEN : 1;
			unsigned int : 1;
			unsigned int T14CLKEN : 1;
			unsigned int T15CLKEN : 1;
			unsigned int CAN2CLKEN : 1;
			unsigned int CAN3CLKEN : 1;
			unsigned int : 1;
			unsigned int T18CLKEN : 1;
			unsigned int T19CLKEN : 1;
			unsigned int T20CLKEN : 1;
			unsigned int T21CLKEN : 1;
			unsigned int T22CLKEN : 1;
			unsigned int T23CLKEN : 1;
			unsigned int : 2;
			unsigned int USART5CLKEN : 1;
			unsigned int USART6CLKEN : 1;
			unsigned int UASRT7CLKEN : 1;
		} B;
	} CTL2;

	/* offset  : 0x4C.    Peripheral clock control register 3                      */
	union
	{
		unsigned int R;
		struct
		{
			unsigned int : 1;
			unsigned int SPI2CLKEN : 1;
			unsigned int SPI3CLKEN : 1;
			unsigned int : 4;
			unsigned int I2C3CLKEN : 1;
			unsigned int : 5;
			unsigned int CRCCLKEN : 1;
			unsigned int : 2;
			unsigned int EXICCLKEN : 1;
			unsigned int CAN4CLKEN : 1;
			unsigned int : 1;
			unsigned int CFGLCLKEN : 1;
			unsigned int : 1;
			unsigned int FLEXMUXCLKEN : 1;
			unsigned int FDC0CLKEN : 1;
			unsigned int FDC1CLKEN : 1;
			unsigned int FDC2CLKEN : 1;
			unsigned int FLEXRMCLKEN : 1;
			unsigned int ECFGLCLKEN : 1;
			unsigned int EWDTCLKEN : 1;
			unsigned int : 1;
			unsigned int CANFD6CLKEN : 1;
			unsigned int CANFD7CLKEN : 1;
			unsigned int RTCCLKEN : 1;
		} B;
	} CTL3;
};

#define PCLK (*((volatile struct Kf32a_Mcu_Pclk_Reg *)0x40002600))



struct Kf32a_Mcu_Rst_Reg
{
	/* offset  : 0x0.    Reset control register 0.                      */
	union
	{
		unsigned int   R;
		struct
		{
			unsigned int GPIOARST:                     1;
			unsigned int GPIOBRST:                     1;
			unsigned int GPIOCRST:                     1;
			unsigned int GPIODRST:                     1;
			unsigned int GPIOERST:                     1;
			unsigned int GPIOFRST:                     1;
			unsigned int GPIOGRST:                     1;
			unsigned int GPIOHRST:                     1;
			unsigned int :                            23;
			unsigned int :                             1;
		}B;
	}CTL0;

	/* offset  : 0x4.    Reset control register 1.                      */
	union
	{
		unsigned int   R;
		struct
		{
			unsigned int :                            1;
			unsigned int QEI1RST:                     1;
			unsigned int T1RST:                       1;
			unsigned int T2RST:                       1;
			unsigned int T3RST:                       1;
			unsigned int T4RST:                       1;
			unsigned int T5T6RST:                     1;
			unsigned int :                            1;
			unsigned int T9T10RST:                    1;
			unsigned int :                            1;
			unsigned int QEI0RST:                     1;
			unsigned int ADC0RST:                     1;
			unsigned int ADC1RST:                     1;
			unsigned int ADC2RST:                     1;
			unsigned int DAC0RST:                     1;
			unsigned int DAC1RST:                     1;
			unsigned int CMPRST:                      1;
			unsigned int T0RST:                       1;
			unsigned int CTOUCHRST:                   1;
			unsigned int USART0RST:                   1;
			unsigned int USART1RST:                   1;
			unsigned int USART2RST:                   1;
			unsigned int USART3RST:                   1;
			unsigned int USART4RST:                   1;
			unsigned int SPI0RST:                     1;
			unsigned int SPI1RST:                     1;
			unsigned int I2C0RST:                     1;
			unsigned int I2C1RST:                     1;
			unsigned int I2C2RST:                     1;
			unsigned int LCDRST:                      1;
			unsigned int :                            1;
			unsigned int USBRST:                      1;
		}B;
	}CTL1;

	/* offset  : 0x8.    Reset control register 2.                      */
	union
	{
		unsigned int   R;
		struct
		{
			unsigned int :                           1;
			unsigned int :                           1;
			unsigned int CAN0RST:                    1;
			unsigned int CAN1RST:                    1;
			unsigned int :                           1;
			unsigned int WWDTRST:                    1;
			unsigned int :                           5;
			unsigned int :                           1;
			unsigned int DMA0RST:                    1;
			unsigned int :                           1;
			unsigned int DMA1RST:                    1;
			unsigned int :                           1;
			unsigned int T14RST:                     1;
			unsigned int T15RST:                     1;
			unsigned int CAN2RST:                    1;
			unsigned int CAN3RST:                    1;
			unsigned int :                           1;
			unsigned int T18RST:                     1;
			unsigned int T19RST:                     1;
			unsigned int T20RST:                     1;
			unsigned int T21RST:                     1;
			unsigned int T22RST:                     1;
			unsigned int T23RST:                     1;
			unsigned int :                           1;
			unsigned int :                           1;
			unsigned int USART5RST:                  1;
			unsigned int USART6RST:                  1;
			unsigned int USART7RST:                  1;
		}B;
	}CTL2;

	/* offset  : 0xc.    Reset control register 3.                      */
	union
	{
		unsigned int   R;
		struct
		{
			unsigned int :                          1;
			unsigned int SPI2RST:                   1;
			unsigned int SPI3RST:                   1;
			unsigned int :                          4;
			unsigned int I2C3RST:                   1;
			unsigned int :                          5;
			unsigned int CRCRST:                    1;
			unsigned int :                          2;
			unsigned int EXICRST:                   1;
			unsigned int CAN4RST:                   1;
			unsigned int :                          1;
			unsigned int CFGLRST:                   1;
			unsigned int :                          1;
			unsigned int FLEXMUXRST:                1;
			unsigned int FDC0RST:                   1;
			unsigned int FDC1RST:                   1;
			unsigned int FDC2RST:                   1;
			unsigned int FLEXRMRST:                 1;
			unsigned int ECFGLRST:                  1;
			unsigned int EWDTRST:                   1;
			unsigned int :            			    1;
			unsigned int CNAFD6RST:                 1;
			unsigned int CNAFD7RST:                 1;
			unsigned int RTCRST:                    1;
		}B;
	}CTL3;

};

#define RST (*((volatile struct Kf32a_Mcu_Rst_Reg *)0x40001500))



typedef enum
{
    CAN_CONTROLLER_CLASSICAL,
    CAN_CONTROLLER_FD
} Can_ControllerType;


typedef struct
{
    uint32_t BaseAddress;
    uint32_t MBBaseAddress;
    uint32_t FilterBaseAddress;
    Can_ControllerType Type;
} Can_ControllerInfoType;

/* Define CAN controller hardware register basic address
   [$Strong Relationship$]@MCU
   */
#define CAN_HW_CONTROLLER_BASEADDRESS_CAN4 (0x40002880U)
#define CAN_HW_CONTROLLER_BASEADDRESS_CANFD6 (0x40002E80U)
#define CAN_HW_CONTROLLER_BASEADDRESS_CANFD7 (0x40002F00U)

/* Define CAN controller hardware message buffer basic address
   [$Strong Relationship$]@MCU
   */
#define CAN_HW_CONTROLLER_MBADDRESS_CAN4 (0x1FFEF800U)
#define CAN_HW_CONTROLLER_MBADDRESS_CANFD6 (0x1FFEF000U)
#define CAN_HW_CONTROLLER_MBADDRESS_CANFD7 (0x1FFEF400U)

/* Define CAN controller hardware Filter basic address */
#define CAN_HW_CONTROLLER_FILTERADDRESS_CAN4 (0x40002900U)
#define CAN_HW_CONTROLLER_FILTERADDRESS_CANFD6 (0x1FFEF3FCU)
#define CAN_HW_CONTROLLER_FILTERADDRESS_CANFD7 (0x1FFEF7FCU)


extern const Can_ControllerInfoType Can_m_ControllersInfo[2];

#define CAN_SAMPLE_ONCE (0U)
#define CAN_SAMPLE_THREE_TIMES (1U)

#define CAN_INTERRUPT_ENABLE (1U)
#define CAN_INTERRUPT_DISABLE (0U)

#define CAN_CONTROLLER_RUN_MODE_RESET (1U)
#define CAN_CONTROLLER_RUN_MODE_RUN (0U)

#define CAN_CONTROLLER_MODE_ENABLE_LISTENONLY (1U)
#define CAN_CONTROLLER_MODE_DISABLE_LISTENONLY (0U)

#define CAN_CONTROLLER_MODE_ENABLE_SLEEP (1U)
#define CAN_CONTROLLER_MODE_DISABLE_SLEEP (0U)

#define CAN_CONTROLLER_MODE_ENABLE_LOOP (1U)
#if(CAN_CONTROLLER_MODE_ENABLE_LOOP == 1U)
#define CAN_CONTROLLER_MODE_ENABLE_INTERLOOP (1U)
#define CAN_CONTROLLER_MODE_DISABLE_INTERLOOP (0U)
#else
#endif
#define CAN_CONTROLLER_MODE_DISABLE_LOOP (0U)

#define MAX_8MAILBOX_NUMBER (51U)
#define MAX_16MAILBOX_NUMBER (36U)
#define MAX_32MAILBOX_NUMBER (23U)
#define MAX_64MAILBOX_NUMBER (13U)


#define MAX_CAN_PRESDIV_NUMBER (64U)
#define MAX_TQ_NUMBER (25U)
#define Min_TQ_NUMBER (3U)
#define MAX_TSEG1_NUMBER (16U)
#define MIN_TSEG1_NUMBER (1U)
#define MAX_TSEG2_NUMBER (8U)
#define MIN_TSEG2_NUMBER (1U)


#define NULL_PTR  ((void *)0U)


typedef union
{
	volatile uint16_t S;
	struct
	{
		volatile uint16_t PreScale : 6;
		volatile uint16_t Sjw : 2;
		volatile uint16_t TSeg1 : 4;
		volatile uint16_t TSeg2 : 3;
		volatile uint16_t SampleTimes : 1;
	};
} Can_BDRConfigType;


typedef union
{
	volatile uint16_t S;
	struct
	{
		volatile uint16_t BrsPrescale : 6;
		volatile uint16_t HtSeg1 : 4;
		volatile uint16_t HtSeg2 : 3;
		volatile uint16_t :3;
	};
} Can_FdBDRConfigType;

typedef enum
{
	CANFD_NORMAL_MODE,
	CANFD_LOOP_INTERNAL_MODE,
	CANFD_LOOP_EXTERNAL_MODE,
	CANFD_SILENT_MODE,
}Can_WorkModeType;
typedef enum
{
    CAN_CLOCKSOURCE_SCLK,
    CAN_CLOCKSOURCE_HFCLK,
    CAN_CLOCKSOURCE_LFCLK
} Can_ClockSourceType;


typedef enum
{
    CAN_8_BYTE_DATALENGTH,
    CAN_16_BYTE_DATALENGTH,
    CAN_32_BYTE_DATALENGTH,
    CAN_64_BYTE_DATALENGTH
} Can_MailboxBlockSizeType;


typedef enum
{
    CAN_FD_NON_ISOMODE,
    CAN_FD_ISOMODE
} Can_FdFrameType;


typedef enum
{
    CAN_MBFULLRECEIVE_DISABLE,
    CAN_MBFULLRECEIVE_ENABLE
} Can_MBFullReceiveEnableType;


typedef struct
{
    /* CAN Receive Interrupt Set */
	uint16_t RxIntEnableSet : 1;
    /* CAN Transmit Interrupt Set */
	uint16_t TxIntEnableSet : 1;
    /* CAN Bus Off Interrupt Set */
	uint16_t BusOffEnableSet : 1;
    /* CAN Wake Up Interrupt Set */
	uint16_t WakeUpIntEnableSet : 1;
    /* CAN Error Alarm Interrupt Set */
	uint16_t ErrorAlarmIntEnableSet : 1;
    /* CAN Receive Over Flow Interrupt Set */
	uint16_t OverFlowIntEnableSet : 1;
    /* CAN Error Negative Interrupt Set */
	uint16_t ErrorNegativeIntEnableSet : 1;
    /* CAN Error Arbitrate Lose Interrupt Set */
	uint16_t ArbitrateLoseIntEnableSet : 1;
    /* CAN Bus Error Interrupt Set */
	uint16_t BusErrorIntEnableSet : 1;
    /* CAN DMA Transmit Interrupt Set */
	uint16_t DmaTXDEnableSet : 1;
    /* CAN DMA Receive Interrupt Set */
	uint16_t DmaRXDEnableSet : 1;
    /* CAN MailBox Receive Triger Interrupt Set */
	uint16_t TrigerMBEnableSet : 1;
	/* 3 bit Preemption Priority */
	uint16_t PreemptionPriority : 3;
	/* 1 bit Sub Priority */
	uint16_t SubPriority : 1;
} Can_Controller_InterruptConfigType;

typedef enum
{
    /* CAN Receive Interrupt Flag */
	Rx_Flag = 0x00000001,
    /* CAN Transmit Interrupt Flag */
	Tx_Flag = 0x00000002,
	/* CAN Error Alarm Interrupt Flag */
    ErrorAlarm_Flag = 0x00000004,
    /* CAN OverFlow Interrupt Flag */
    OverFlow_Flag = 0x00000008,
    /* CAN Wake Up Interrupt Flag */
    WakeUp_Flag = 0x00000010,
    /* CAN Error Negative Interrupt Flag */
    ErrorNegative_Flag = 0x00000020,
    /* CAN Error Arbitrate Lose Interrupt Flag */
    ArbitrateLose_Flag = 0x00000040,
    /* CAN Bus Error Interrupt Flag */
    BusError_Flag = 0x00000080,
    /* CAN DMA Transmit Interrupt Flag Cleared By Hardware */
    DmaTXD_Flag = 0x00000100,
    /* CAN DMA Receive Interrupt Flag Cleared By Hardware */
    DmaRXD_Flag = 0x00000200,
    /* CAN Bus Off Interrupt Flag */
    BusOff_Flag = 0x00001000,
}Can_Controller_InterruptType;

typedef enum
{
	CANFD_STATUS_OFF = 0x800000,
	CANFD_STATUS_ERROR = 0x400000,
	CANFD_STATUS_TRANSMITING = 0x200000,
	CANFD_STATUS_RECEIVEING = 0x100000,
	CANFD_STATUS_TRANSMITED = 0x80000,
	CANFD_STATUS_TBUFFER = 0x40000,
	CANFD_STATUS_RVOERFLOW = 0x20000,
	CANFD_STATUS_REMPTY = 0x10000,
} Can_Controller_StatusType;

typedef union
{
	volatile uint16_t EntireFlag;
	struct
	{
	    /* CAN Receive Interrupt Flag */
		volatile uint16_t RxIntFlag : 1;
	    /* CAN Transmit Interrupt Flag */
		volatile uint16_t TxIntFlag : 1;
	    /* CAN Bus Off Interrupt Flag */
	    volatile uint16_t ErrorAlarmFlag : 1;
	    /* CAN Wake Up Interrupt Flag */
	    volatile uint16_t OverFlowFlag : 1;
	    /* CAN Error Alarm Interrupt Flag */
	    volatile uint16_t WakeUpFlag : 1;
	    /* CAN Receive Over Flow Interrupt Flag */
	    volatile uint16_t ErrorNegativeFlag : 1;
	    /* CAN Error Negative Interrupt Flag */
	    volatile uint16_t ArbitrateLoseFlag : 1;
	    /* CAN Error Arbitrate Lose Interrupt Flag */
	    volatile uint16_t BusErrorFlag : 1;
	    /* CAN Bus Error Interrupt Flag */
	    volatile uint16_t DmaTXDFlag : 1;
	    /* CAN DMA Transmit Interrupt Flag Cleared By Hardware */
	    volatile uint16_t DmaRXDFlag : 1;
	    /* CAN DMA Receive Interrupt Flag Cleared By HardwaCan_Controller_InterruptFlagTypere */
	    volatile uint16_t  : 2;
	    /* CAN MailBox Receive Triger Interrupt Flag */
	    volatile uint16_t  BusOffFlag : 1;
	    volatile uint16_t : 3;
	};
}Can_Controller_InterruptFlagType;


typedef enum
{
	Clock_Divide_1,
	Clock_Divide_2,
	Clock_Divide_4,
	Clock_Divide_8
}Clock_Divide_Number;


typedef enum
{
    CAN_RECEIVE,
    CAN_TRANSMIT
} Can_ObjectType;


typedef enum
{
	Data_Length_0,
	Data_Length_1,
	Data_Length_2,
	Data_Length_3,
	Data_Length_4,
	Data_Length_5,
	Data_Length_6,
	Data_Length_7,
	Data_Length_8,
	Data_Length_12,
	Data_Length_16,
	Data_Length_20,
	Data_Length_24,
	Data_Length_32,
	Data_Length_48,
	Data_Length_64,
}Data_LengthType;


typedef struct
{
	union
	{
	    uint8_t U8Data[64];
	    uint32_t U32Data[16];
	    struct
	    {
	    	uint8_t SU8Data[2];
	    	uint32_t SU32Data[15];
	    	uint8_t EU8Data[2];
	    }__attribute__((packed));
	};
    Data_LengthType Data_Length;
} Canfd_MailboxDataType;

typedef enum
{
    CANFD_BRS_DISABLE,
    CANFD_BRS_ENABLE
} Can_FdBrsConfigType;

typedef enum
{
    CAN_FRAME_CLASSICAL,
    CAN_FRAME_FD
} Can_FrameType;

typedef enum
{
    CAN_DATA_STANDARD,
    CAN_DATA_EXTENDED,
    CAN_REMOTE_STANDARD,
    CAN_REMOTE_EXTENDED,
} Can_IdFrameType;


typedef enum
{
    CAN_FILTER_STANDARD,
    CAN_FILTER_EXTENDED,
} Can_IdFilterType;


typedef enum
{
	Mailbox_0,
	Mailbox_1,
	Mailbox_2,
	Mailbox_3,
	Mailbox_4,
	Mailbox_5,
	Mailbox_6,
	Mailbox_7,
	Mailbox_8,
	Mailbox_9,
	Mailbox_10,
	Mailbox_11,
	Mailbox_12,
	Mailbox_13,
	Mailbox_14,
	Mailbox_15,
	Mailbox_16,
	Mailbox_17,
	Mailbox_18,
	Mailbox_19,
	Mailbox_20,
	Mailbox_21,
	Mailbox_22,
	Mailbox_23,
	Mailbox_24,
	Mailbox_25,
	Mailbox_26,
	Mailbox_27,
	Mailbox_28,
	Mailbox_29,
	Mailbox_30,
	Mailbox_31,
	Mailbox_32,
	Mailbox_33,
	Mailbox_34,
	Mailbox_35,
	Mailbox_36,
	Mailbox_37,
	Mailbox_38,
	Mailbox_39,
	Mailbox_40,
	Mailbox_41,
	Mailbox_42,
	Mailbox_43,
	Mailbox_44,
	Mailbox_45,
	Mailbox_46,
	Mailbox_47,
	Mailbox_48,
	Mailbox_49,
	Mailbox_50,
}Can_MailboxNumType;


typedef enum
{
	Initindex_0,
	Initindex_1,
	Initindex_2,
	Initindex_3,
	Initindex_4,
}Can_InitIndexType;


typedef struct
{
    uint32_t MaskCode[51];
    Can_IdFilterType Can_IdFilterFrame[51];
} Can_HwFilterType;



typedef struct
{
	Can_WorkModeType CanfdMode;
    Can_ClockSourceType ClockSource;
    Can_ClockSourceType FdArbitrateClockSource;
    Can_MailboxBlockSizeType MailBoxBlockSize;
    /* Iso mode or non-iso mode config */
    Can_FdFrameType FdFrameType;

    uint32_t GlobalMask;
    /* Enable/disable mailbox full receive */
    Can_MBFullReceiveEnableType MBFullReceiveEnableSet;
    const Can_Controller_InterruptConfigType *Can_Controller_InterruptConfig;
#if (HARDWARE_FILTER == STD_ON)
    const Can_HwFilterType * Can_HwFilter;
#endif
    const Can_BDRConfigType *Canfd_Controller_AllClockAndBDRConfig;
    const Can_FdBDRConfigType *Canfd_Controller_ALLFdBDRConfig;
} Can_ControllerConfigType;



typedef enum
{
	MAIL_UNDEFINED = 0x00,
    MAIL_RECEIVE = 0x04,
    MAIL_RECEIVE_SUCCESS = 0x02,
    MAIL_TRANSMIT = 0x0C,
    MAIL_TRANSMIT_SUCCESS = 0x08,
    MAIL_RTR_ANSWER = 0x0A,
} Can_MailBoxType;

typedef struct
{
	Canfd_MailboxDataType FrameData;
    uint32_t Id;
    uint16_t Timestamp;
    Can_FdBrsConfigType BRS;

    Can_FrameType Can_frame;
    Can_IdFrameType Can_id;

    Can_MailBoxType TransceiveType;
} Canfd_MailboxHeaderType;


typedef enum {
    CAN_OK = 0,
    CAN_BUSY_TRANSMIT_MAILBOX = 1,
    CAN_BUSY_RECEIVE_MAILBOX = 2,
    CAN_RAM_RXSTA = 0,
    CAN_RAM_TXSTA = 0,
    CAN_ERROR_TIMEOUT_ARBITRATE = 3,
    CAN_ERROR_ARBITRATE_FAIL = 4,
    CAN_ERROR_ARBITRATE_LOSE = 5,
    CAN_ERROR_ARBITRATE_DELAY = 0,
    CAN_ERROR_BUSERROR = 7,
    CAN_ERROR_BUSOFF = 8,
    CAN_ERROR_CONFIGURATE = 9,
	CAN_UNINITIALIZED = 10,
}Can_ReturnType;


typedef union
{
	volatile uint16_t flagclear_result;
	struct
	{
		volatile uint16_t Arbitrateloseclear_Timeout:1;
		volatile uint16_t Receiveclear_Timeout:1;
		volatile uint16_t Buserrorclear_Timeout:1;
		volatile uint16_t Busoffclear_Timeout:1;
		volatile uint16_t Erroralarmclear_Timeout:1;
		volatile uint16_t Errornegativeclear_Timeout:1;
		volatile uint16_t Overflowclear_Timeout:1;
		volatile uint16_t Transmitclear_Timeout:1;
		volatile uint16_t Wakeupclear_Timeout:1;
		volatile uint16_t :7;
	};
}ClearFlag_ReturnType;

typedef struct
{
	Canfd_MailboxHeaderType Can_MailboxHeader[20];
    uint8_t Sdu_Length;

} Canfd_Sdu_Type;


/* Check Controller Index */
#define CHECK_CONTROLLER_INDEX(INDEX)  ((INDEX == CANfd6)|| \
										(INDEX == CANfd7))
/* Check Controller Work Mode */
#define CHECK_CONTROLLER_MODE(MODE)    ((MODE == CANFD_NORMAL_MODE)|| \
										(MODE == CANFD_LOOP_INTERNAL_MODE)|| \
										(MODE == CNAFD_LOOP_EXTERNAL_MODE)||\
										(MODE == CANFD_SILENT_MODE))
/* Check Controller Work Clock Source */
#define CHECK_CONTROLLER_WORKCLOCK(SOURCE)  ((SOURCE == CAN_CLOCKSOURCE_SCLK) || \
											 (SOURCE == CAN_CLOCKSOURCE_HFCLK) || \
											 (SOURCE == CAN_CLOCKSOURCE_LFCLK))
/* Check Controller Arbitrate Clock Source */
#define CHECK_CONTROLLER_ARBCLOCK(SOURCE)    ((SOURCE == CAN_CLOCKSOURCE_SCLK) || \
											 (SOURCE == CAN_CLOCKSOURCE_HFCLK) || \
											 (SOURCE == CAN_CLOCKSOURCE_LFCLK))
/* Check Controller Mailbox Size */
#define CHECK_CONTROLLER_MBSIZE(SIZE)        ((SIZE == CAN_8_BYTE_DATALENGTH) || \
											  (SIZE == CAN_16_BYTE_DATALENGTH) || \
											  (SIZE == CAN_32_BYTE_DATALENGTH) || \
											  (SIZE == CAN_64_BYTE_DATALENGTH))
/* Check Canfd Protocal Mode   */
#define CHECK_CANFD_PROTOCAL(PROTOCAL)       ((PROTOCAL == CAN_FD_NON_ISOMODE) || \
											  (PROTOCAL == CAN_FD_ISOMODE))

/* Check Canfd Full MailBox State */
#define CHECK_CANFD_MAILBOX_FULLSTATE(STATE) ((STATE == CAN_MBFULLRECEIVE_DISABLE)|| \
											   (STATE == CAN_MBFULLRECEIVE_ENABLE))
/* Check Message DLC */
#define CHECK_CANFD_MESSAGE_DLC(DATALENGTH)  ((DATALENGTH >= Data_Length_0) && \
										 	   (DATALENGTH <= Data_Length_64))

/* Check 8Byte Mailbox Number */
#define CHECK_8CANFD_MAILBOX_NUMBER(MAILBOX_NUMBER)  ((MAILBOX_NUMBER >= Mailbox_0) && \
														(MAILBOX_NUMBER < MAX_8MAILBOX_NUMBER))
/* Check 16Byte Mailbox Number */
#define CHECK_16CANFD_MAILBOX_NUMBER(MAILBOX_NUMBER)  ((MAILBOX_NUMBER >= Mailbox_0) && \
														(MAILBOX_NUMBER < MAX_16MAILBOX_NUMBER))

/* Check 32Byte Mailbox Number */
#define CHECK_32CANFD_MAILBOX_NUMBER(MAILBOX_NUMBER)	((MAILBOX_NUMBER >= Mailbox_0) && \
														  (MAILBOX_NUMBER < MAX_32MAILBOX_NUMBER))

/* Check 64Byte Mailbox Number */
#define CHECK_64CANFD_MAILBOX_NUMBER(MAILBOX_NUMBER)    ((MAILBOX_NUMBER >= Mailbox_0) && \
														  (MAILBOX_NUMBER < MAX_64MAILBOX_NUMBER))

/* Check Mailbox Type */
#define CHECK_MAILBOX_TYPE(MAILBOX_TYPE)                ((MAILBOX_TYPE == MAIL_UNDEFINED) || \
														 (MAILBOX_TYPE == MAIL_RECEIVE) || \
														 (MAILBOX_TYPE == MAIL_RECEIVE_SUCCESS) || \
														 (MAILBOX_TYPE == MAIL_TRANSMIT) || \
														 (MAILBOX_TYPE == MAIL_TRANSMIT_SUCCESS) || \
														 (MAILBOX_TYPE == MAIL_RTR_ANSWER))


void Can_m_FdMailBoxErase(const uint8_t Can_Controller_Index);
void Can_m_FdMailBoxMaskErase(const uint8_t Can_Controller_Index);
void Can_m_FdControllerDeInit(const uint8_t Can_Controller_Index);
void Can_m_FdControllerInit(const uint8_t Can_Controller_Index,const Can_ControllerConfigType *Can_ControllerConfig, const Can_InitIndexType InitIndex);
void Can_m_FdGetIntFlag(const uint8_t Can_Controller_Index, Can_Controller_InterruptFlagType *Can_Controller_InterruptFlag, uint8_t *rmc_count);
ClearFlag_ReturnType Can_m_FdClearIntFlag(const uint8_t Can_Controller_Index, Can_Controller_InterruptFlagType *Can_Controller_InterruptFlag,uint8_t rmc_count);
Can_ReturnType Can_m_FdMailBoxCode_Set(const uint8_t Can_Controller_Index, const Can_MailboxNumType MailBox_Number,Canfd_MailboxHeaderType *Can_MailboxHeader);
Can_MailBoxType Can_m_FdGetMailBoxState(const uint8_t Can_Controller_Index, const Can_MailboxNumType MailBox_Number);
Can_ReturnType Can_m_FdMailBox_Write(const uint8_t Can_Controller_Index, const Can_MailboxNumType MailBox_Number,Canfd_MailboxHeaderType *Can_MailboxHeader);
Can_ReturnType Can_m_FdMailBox_Read(const uint8_t Can_Controller_Index, const Can_MailboxNumType MailBox_Number,Canfd_MailboxHeaderType *Can_MailboxHeader,Can_MailBoxType Can_MailBox);
Can_ReturnType Can_m_FdTransmit(const uint8_t Can_Controller_Index);
void Can_m_FdTransmiterrorHandler(void);
void Can_m_FdBusoffHandler(void);
void Can_m_FdFlagclearHandler(void);
#endif
