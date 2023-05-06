# 1 "../src/kf32a1x6_flash.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\Release//"
# 1 "<command-line>"
# 1 "../src/kf32a1x6_flash.c"
# 29 "../src/kf32a1x6_flash.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_flash.h" 1
# 29 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_flash.h"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6.h" 1



# 1 "D:\\KungFu32\\workspace32\\Demo1_light/__Kungfu32_chipmodel_define.h" 1
# 5 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6.h" 2
# 32 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6.h"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h" 1
# 36 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
# 1 "D:/KungFu32_/ChipONCC32/include/Sys/stdint.h" 1
# 16 "D:/KungFu32_/ChipONCC32/include/Sys/stdint.h"
# 1 "D:/KungFu32_/ChipONCC32/include/Sys/stddef.h" 1
# 24 "D:/KungFu32_/ChipONCC32/include/Sys/stddef.h"
typedef int ptrdiff_t;





typedef unsigned int size_t;




typedef unsigned short wchar_t;
# 17 "D:/KungFu32_/ChipONCC32/include/Sys/stdint.h" 2




typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef int int_least32_t;
typedef unsigned int uint_least32_t;
typedef long long int_least64_t;
typedef unsigned long long uint_least64_t;





typedef char int_fast8_t;
typedef unsigned char uint_fast8_t;
typedef short int_fast16_t;
typedef unsigned short uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
typedef long long int_fast64_t;
typedef unsigned long long uint_fast64_t;
# 60 "D:/KungFu32_/ChipONCC32/include/Sys/stdint.h"
  typedef int intptr_t;
# 69 "D:/KungFu32_/ChipONCC32/include/Sys/stdint.h"
  typedef unsigned int uintptr_t;




typedef long long intmax_t;
typedef unsigned long long uintmax_t;
# 37 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h" 2
# 51 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef enum
{
 FALSE = 0,
 TRUE = !FALSE
}FunctionalState;



typedef enum
{
 RESET = 0,
 SET = !RESET
}FlagStatus, INTStatus;


typedef enum
{
 FAILURE = 0,
 SUCCESS = !FAILURE
}RetStatus;


typedef enum
{
 DISABLE = 0,
 ENABLE = !DISABLE
}AbleStatus;




typedef enum
{
    DIR_DOWN = 0,
    DIR_UP = !DIR_DOWN
} DIRStatus;
# 95 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef enum
{
    INT_Initial_SP = 0,
    INT_Reset = 1,
    INT_NMI = 2,
    INT_HardFault = 3,
    INT_Reserved4 = 4,
    INT_StackFault = 5,
    INT_AriFault = 6,
    INT_Reserved7 = 7,
    INT_Reserved8 = 8,
    INT_Reserved9 = 9,
    INT_Reserved10 = 10,
    INT_SVCAll = 11,
    INT_Reserved12 = 12,
    INT_Reserved13 = 13,
    INT_SoftSV = 14,
    INT_SysTick = 15,
    INT_WWDT = 16,
    INT_EINT16 = 17,
    INT_EINT0 = 18,
    INT_EINT1 = 19,
    INT_EINT2 = 20,
    INT_EINT3 = 21,
    INT_EINT4 = 22,
    INT_EINT9TO5 = 23,
    INT_EINT15TO10 = 24,
    INT_T1 = 25,
    INT_T3 = 26,
    INT_T5 = 27,
    INT_T6 = 28,
    INT_QEI0 = 29,
    INT_QEI1 = 30,
    INT_T7 = INT_QEI0,
    INT_T8 = INT_QEI1,
    INT_ECFGL = 31,
    INT_CAN4 = 32,
    INT_T14 = 33,
    INT_RNG = 34,
    INT_FDC2 = 35,
    INT_EXIC = 36,
    INT_ADC0 = 37,
    INT_ADC1 = 38,
    INT_CFGL = 39,
    INT_T11 = 40,
    INT_T0 = 41,
    INT_DMA0 = 42,
    INT_CMP = 43,
    INT_USART0 = 44,
    INT_USART1 = 45,
    INT_SPI0 = 46,
    INT_SPI1 = 47,
    INT_DMA1 = 48,
    INT_EINT19TO17 = 49,
    INT_CANFD6 = 50,
    INT_CANFD7 = 51,
    INT_FDC0 = 52,
    INT_FDC1 = 53,
    INT_EINT31TO20 = 54,
    INT_ECC = 55,
    INT_OSC = 56,
    INT_CLK = INT_OSC,
    INT_I2C0 = 57,
    INT_I2C1 = 58,
    INT_I2C2 = 59,
    INT_T12 = 60,
    INT_T2 = 61,
    INT_T4 = 62,
    INT_T13 = 63,
    INT_USART2 = 64,
    INT_T16 = 65,
    INT_USART4 = 66,
    INT_SPI2 = 67,
    INT_SPI3 = 68,
    INT_ADC2 = 69,
    INT_T18 = 70,
    INT_T19 = 71,
    INT_HRCAP0 = 72,
    INT_WKP0 = 73,
    INT_WKP1 = INT_WKP0,
    INT_WKP2 = INT_WKP0,
    INT_WKP3 = INT_WKP0,
    INT_WKP4 = INT_WKP0,
    INT_HRCAP1 = 74,
    INT_T21 = 75,
    INT_I2C3 = 76,
    INT_USART5 = 77,
    INT_HRCAP2 = 78,
    INT_USART7 = 79
}InterruptIndex;
# 197 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct GPIO_MenMap
{
 volatile const uint32_t PIR;
 volatile uint32_t POR;
 volatile uint32_t PUR;
 volatile uint32_t PDR;
 volatile uint32_t PODR;
 volatile uint32_t PMOD;
 volatile uint32_t OMOD;
 volatile uint32_t LOCK;
 volatile uint32_t RMP[2];
 volatile uint32_t RESERVED[3];
 volatile uint32_t RMP_MSB;
}GPIO_SFRmap;
# 911 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct OSC_MemMap
{
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t INT;
    volatile uint32_t CTL2;
    volatile uint32_t HFOSCCAL0;
    volatile uint32_t HFOSCCAL1;
}OSC_SFRmap;


typedef struct PLL_MenMap
{
 volatile uint32_t CTL;
}PLL_SFRmap;
# 1273 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct INT_MemMap
{
    volatile uint32_t CTL0;
    volatile uint32_t EIE0;
             uint32_t RESERVED1;
    volatile uint32_t EIE1;
             uint32_t RESERVED2;
    volatile uint32_t EIE2;
       uint32_t RESERVED3;
    volatile uint32_t EIF0;
             uint32_t RESERVED4;
    volatile uint32_t EIF1;
             uint32_t RESERVED5;
    volatile uint32_t EIF2;
             uint32_t RESERVED6;
    volatile uint32_t IP0;
    volatile uint32_t IP1;
    volatile uint32_t IP2;
    volatile uint32_t IP3;
    volatile uint32_t IP4;
    volatile uint32_t IP5;
    volatile uint32_t IP6;
    volatile uint32_t IP7;
    volatile uint32_t IP8;
    volatile uint32_t IP9;
    volatile uint32_t IP10;
    volatile uint32_t IP11;
    volatile uint32_t IP12;
    volatile uint32_t IP13;
    volatile uint32_t IP14;
    volatile uint32_t IP15;
    volatile uint32_t IP16;
    volatile uint32_t IP17;
    volatile uint32_t IP18;
    volatile uint32_t EINTMASK;
    volatile uint32_t EINTRISE;
    volatile uint32_t EINTFALL;
    volatile uint32_t EINTF;
             uint32_t RESERVED7;
    volatile uint32_t EINTSS0;
    volatile uint32_t EINTSS1;
    volatile uint32_t CTL1;
}INT_SFRmap;
# 2712 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct SYSCTL_MemMap {
    volatile uint32_t PSW;
    volatile uint32_t MCTL;
    volatile uint32_t ARCTL;
    volatile uint32_t VECTOFF;
       uint32_t RESEVRVE1;
    volatile uint32_t RAMSPA;
    volatile uint32_t MEMCTL;
    volatile uint32_t MSPSPA;
    volatile uint32_t PSPSPA;
}SYSCTL_SFRmap;
# 2854 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct DMA_MenMap
{
 union
 {
  struct
  {
            volatile uint32_t CTLR1;
            volatile uint32_t CTLR2;
            volatile uint32_t CTLR3;
            volatile uint32_t CTLR4;
            volatile uint32_t CTLR5;
            volatile uint32_t CTLR6;
            volatile uint32_t CTLR7;
  };
  volatile uint32_t CTLR[7];
 };
 uint32_t RESERVED1;

    union
    {
        struct
        {
            volatile uint32_t PADDR1;
            volatile uint32_t PADDR2;
            volatile uint32_t PADDR3;
            volatile uint32_t PADDR4;
            volatile uint32_t PADDR5;
            volatile uint32_t PADDR6;
            volatile uint32_t PADDR7;
        };
        volatile uint32_t PADDR[7];
    };
    uint32_t RESERVED2;

    union
    {
        struct
        {
            volatile uint32_t MADDR1;
            volatile uint32_t MADDR2;
            volatile uint32_t MADDR3;
            volatile uint32_t MADDR4;
            volatile uint32_t MADDR5;
            volatile uint32_t MADDR6;
            volatile uint32_t MADDR7;
        };
        volatile uint32_t MADDR[7];
    };
    uint32_t RESERVED3;

    union
    {
        struct
        {
            volatile const uint32_t CPAR1;
            volatile const uint32_t CPAR2;
            volatile const uint32_t CPAR3;
            volatile const uint32_t CPAR4;
            volatile const uint32_t CPAR5;
            volatile const uint32_t CPAR6;
            volatile const uint32_t CPAR7;
        };
        volatile const uint32_t CPAR[7];
    };
    uint32_t RESERVED4;

    union
    {
        struct
        {
            volatile const uint32_t CMAR1;
            volatile const uint32_t CMAR2;
            volatile const uint32_t CMAR3;
            volatile const uint32_t CMAR4;
            volatile const uint32_t CMAR5;
            volatile const uint32_t CMAR6;
            volatile const uint32_t CMAR7;
        };
        volatile const uint32_t CMAR[7];
    };
    uint32_t RESERVED5;

    union
    {
        struct
        {
            volatile const uint32_t NCT1;
            volatile const uint32_t NCT2;
            volatile const uint32_t NCT3;
            volatile const uint32_t NCT4;
            volatile const uint32_t NCT5;
            volatile const uint32_t NCT6;
            volatile const uint32_t NCT7;
        };
        volatile const uint32_t NCT[7];
    };
    uint32_t RESERVED6;

    volatile uint32_t LIFR;
    volatile uint32_t LIER;
}DMA_SFRmap;
# 3524 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct SYSTICK_MemMap
{
    volatile uint32_t CTL;
    volatile uint32_t RELOAD;
    volatile uint32_t CV;
    volatile uint32_t CALI;
}SYSTICK_SFRmap;
# 3582 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct BTIM_MemMap
{
    volatile uint32_t CNT;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t PRSC;
    volatile uint32_t PPX;
    volatile uint32_t DIER;
    volatile const uint32_t SR;
    volatile uint32_t SRIC;
}BTIM_SFRmap;
# 3758 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct GPTIM_MemMap
{
    volatile uint32_t CNT;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t PRSC;
    volatile uint32_t PPX;
    volatile uint32_t UDTIM;
                   uint32_t RESERVED1[2];
    volatile const uint32_t CCPXC1;
    volatile const uint32_t CCPXC2;
    volatile const uint32_t CCPXC3;
    volatile const uint32_t CCPXC4;
    volatile uint32_t CCPXSRIC;
    volatile const uint32_t CCPXDF;
                   uint32_t RESERVED2[2];
    volatile uint32_t CCPXCTL1;
    volatile uint32_t CCPXR1;
    volatile uint32_t CCPXR2;
    volatile uint32_t CCPXR3;
    volatile uint32_t CCPXR4;
    volatile uint32_t CCPXCTL2;
    volatile uint32_t CCPXCTL3;
    volatile uint32_t CCPXEGIF;
}GPTIM_SFRmap, CCP_SFRmap;
# 4235 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct ATIM_MemMap
{
    volatile uint32_t TXCNT;
    volatile uint32_t TZCNT;
    volatile uint32_t TXPPX;
    volatile uint32_t TZPPZ;
    volatile uint32_t TXPRSC;
    volatile uint32_t TZPRSC;
    volatile uint32_t TXCCR0;
    volatile uint32_t TXCCR1;
    volatile uint32_t TZCCR0;
    volatile uint32_t TXCTL;
    volatile uint32_t TZCTL;
    volatile uint32_t PXPDCTL;
    volatile uint32_t PXASCTL;
    volatile uint32_t TXCCTCTL;
    volatile uint32_t TZCCTCTL;
          uint32_t RESERVED0;
    volatile uint32_t COMH1;
    volatile uint32_t COML1;
    volatile uint32_t FAUCTL1;
    volatile uint32_t DITCTL;
    volatile uint32_t COMH2;
    volatile uint32_t COML2;
    volatile uint32_t FAUCTL2;
    volatile uint32_t CCRCTL;
    volatile uint32_t COMH3;
    volatile uint32_t COML3;
    volatile uint32_t FAUCTL3;
          uint32_t RESERVED1;
    volatile uint32_t COMH4;
    volatile uint32_t COML4;
    volatile uint32_t FAUCTL4;
          uint32_t RESERVED2;
    volatile uint32_t ECCPXCTL1;
    volatile uint32_t ECCPXR1;
    volatile uint32_t ECCPXR2;
    volatile uint32_t ECCPXR3;
    volatile uint32_t ECCPXR4;
    volatile uint32_t PXUDCTL;
    volatile uint32_t ECCPXCTL2;
    volatile uint32_t PXDTCTL;
    volatile uint32_t PWMXOC;
    volatile uint32_t PXATRCTL;
    volatile uint32_t PXASCTL0;
    volatile uint32_t PXASCTL1;
    volatile uint32_t ZPDCTL0;
    volatile uint32_t ZPDCTL1;
    volatile uint32_t ZPDPORT;
    volatile uint32_t ECCPXIE;
    volatile uint32_t ECCPXEGIF;
    volatile uint32_t TXUDTIM;
    volatile uint32_t TZUDTIM;
    volatile const uint32_t ECCPXDF;
    volatile const uint32_t ECCPXC1;
    volatile const uint32_t ECCPXC2;
    volatile const uint32_t ECCPXC3;
    volatile const uint32_t ECCPXC4;
                   uint32_t RESERVED3;
    volatile uint32_t ECCPXDE;
    volatile uint32_t ECCPXSRIC;
    volatile uint32_t ECCPXCTL3;
}ATIM_SFRmap, ECCP_SFRmap;
# 5110 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct EPWM_MemMap
{
 volatile uint32_t CNT;
 volatile uint32_t PHS;
 volatile uint32_t PPX;
 volatile uint32_t PRSC;
 volatile uint32_t CTL;
 volatile uint32_t RA;
 volatile uint32_t RB;
 volatile uint32_t CTLA;
 volatile uint32_t CTLB;
 volatile uint32_t DBCTL;
 volatile uint32_t DBT;
 volatile uint32_t PCCTL;
 volatile uint32_t PXASCTL;
 volatile uint32_t ETCTL;
 volatile uint32_t IE;
 volatile const uint32_t IF;
 volatile uint32_t IC;
 volatile uint32_t DE;
 volatile const uint32_t DF;
       uint32_t RESERVED0;
 volatile uint32_t HRPWMCTL;
 volatile uint32_t HRCMP;
 volatile const uint32_t CAP;
 volatile uint32_t RC;
 volatile uint32_t RD;
 volatile uint32_t UDCTL;
}EPWM_SFRmap;
# 5768 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct HRCAP_MenMap
{
 volatile uint32_t CTL;
 volatile const uint32_t COUNTER;
 volatile const uint32_t RISE[2];
 volatile const uint32_t FALL[2];
 volatile const uint32_t HRRISE[2];
 volatile const uint32_t HRFALL[2];
 volatile const uint32_t SR;
 volatile uint32_t SRIC;
 volatile uint32_t IFRC;
}HRCAP_SFRmap;
# 5928 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct QEI_MenMap
{
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CNT;
    volatile uint32_t PPX;
    volatile uint32_t PRSC;
    volatile uint32_t DIER;
}QEI_SFRmap;
# 6047 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct ADC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t SCANSQ0;
    volatile uint32_t SCANSQ1;
    volatile uint32_t SCANSQ2;
    volatile uint32_t HSCANSQ;
    volatile uint32_t WDH;
    volatile uint32_t WDL;
    volatile const uint32_t DATA;
    volatile const uint32_t HPDATA0;
    volatile const uint32_t HPDATA1;
    volatile const uint32_t HPDATA2;
    volatile const uint32_t HPDATA3;
    volatile uint32_t HPDOFF0;
    volatile uint32_t HPDOFF1;
    volatile uint32_t HPDOFF2;
    volatile uint32_t HPDOFF3;
    volatile uint32_t SCANSQ3;
                   uint32_t RESERVED[2];
    volatile uint32_t STATE;
    volatile uint32_t DELAY;
    volatile uint32_t SCANCTL;
}ADC_SFRmap;
# 6752 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct DAC_MemMap
{
    volatile uint32_t CTL;
    volatile uint32_t DAHD;
    volatile const uint32_t DATA;
    volatile uint32_t CTL1;
                   uint32_t RESERVED;
    volatile uint32_t CAL;
}DAC_SFRmap;
# 6919 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct CMP_MemMap
{
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
    volatile uint32_t CTL4;
    volatile uint32_t CTL5;
    volatile uint32_t TRIM0;
    volatile uint32_t TRIM1;
    volatile uint32_t TRIM2;
    volatile uint32_t TRIM3;
}CMP_SFRmap;
# 7352 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct OP_MemMap
{
 volatile uint32_t CTL0;
 volatile uint32_t CTL1;
 volatile uint32_t TRIM0;
 volatile uint32_t TRIM1;
 volatile uint32_t TRIM2;
 volatile uint32_t TRIM3;
}OP_SFRmap;
# 7647 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct USART_MemMap
{
    volatile uint32_t CTLR;
    volatile uint32_t BRGR;
    volatile uint32_t STR;
    union
    {
        volatile uint32_t TBUFR;
        volatile const uint32_t RBUFR;
    };
    volatile uint32_t U7816R;
    volatile uint32_t IER;
    volatile uint32_t ADM;
}USART_SFRmap;
# 7968 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct SPI_MemMap
{
    volatile uint32_t BRGR;
    volatile uint32_t CTLR;
    volatile uint32_t BUFR;
    volatile uint32_t STR;
}SPI_SFRmap;
# 8127 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct I2C_MemMap
{
    volatile uint32_t CTLR;
    volatile uint32_t SR;
    volatile uint32_t BUFR;
    volatile uint32_t ADDR0;
    volatile uint32_t BRGR;
    volatile uint32_t ADDR1;
    volatile uint32_t ADDR2;
    volatile uint32_t ADDR3;
    volatile uint32_t IER;
}I2C_SFRmap;
# 8379 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef union
{
 struct
 {
  struct
  {
   volatile uint32_t DLC :4;
   volatile uint32_t RESERVED0:2;
   volatile uint32_t RTR :1;
   volatile uint32_t IDE :1;
   volatile uint32_t RESERVED1:24;

  }TXINFR;
  struct
  {
   volatile uint32_t DATA1:8;
   volatile uint32_t DATA0:8;
   volatile uint32_t RESERVED0:5;
   volatile uint32_t ID:11;
  }TXDATA0;
  struct
  {
   volatile uint32_t DATA5:8;
   volatile uint32_t DATA4:8;
   volatile uint32_t DATA3:8;
   volatile uint32_t DATA2:8;
  }TXDATA1;
  struct
  {
   volatile uint32_t RESERVED0:8;
   volatile uint32_t RESERVED1:8;
   volatile uint32_t DATA7:8;
   volatile uint32_t DATA6:8;
  }TXDATA2;
 }SFF;
 struct
 {
  struct
  {
   volatile uint32_t DLC:4;
   volatile uint32_t RESERVED0:2;
   volatile uint32_t RTR:1;
   volatile uint32_t IDE:1;
   volatile uint32_t RESERVED1:24;
  }TXINFR;
  struct
  {
   volatile uint32_t RESERVED:3;
   volatile uint32_t ID:29;
  }TXDATA0;
  struct
  {
   volatile uint32_t DATA3:8;
   volatile uint32_t DATA2:8;
   volatile uint32_t DATA1:8;
   volatile uint32_t DATA0:8;
  }TXDATA1;
  struct
  {
   volatile uint32_t DATA7:8;
   volatile uint32_t DATA6:8;
   volatile uint32_t DATA5:8;
   volatile uint32_t DATA4:8;
  }TXDATA2;
 }EFF;
}CanTxBufferTypeDef;



typedef struct CAN_MemMap
{
    volatile uint32_t CTLR;
    volatile uint32_t BRGR;
    volatile uint32_t RCR;
    volatile uint32_t EROR;
    volatile uint32_t ACRR;
    volatile uint32_t MSKR;
    volatile uint32_t IER;
    volatile uint32_t IFR;
    union
    {
     struct
     {
         volatile uint32_t INFR;
         volatile uint32_t TX0R;
         volatile uint32_t TX1R;
         volatile uint32_t TX2R;
     };
     CanTxBufferTypeDef CanTxBuffer;
    };
 volatile uint32_t RXDATA0;
 volatile uint32_t RXDATA1;
 volatile uint32_t RXDATA2;
 volatile uint32_t RXDATA3;

}CAN_SFRmap;

typedef struct CAN_FILTER_Map
{
    volatile uint32_t ACR1R;
    volatile uint32_t MSK1R;
    volatile uint32_t ACR2R;
    volatile uint32_t MSK2R;
    volatile uint32_t ACR3R;
    volatile uint32_t MSK3R;
    volatile uint32_t ACR4R;
    volatile uint32_t MSK4R;
    volatile uint32_t ACR5R;
    volatile uint32_t MSK5R;
    volatile uint32_t ACR6R;
    volatile uint32_t MSK6R;
    volatile uint32_t ACR7R;
    volatile uint32_t MSK7R;
    volatile uint32_t ACR8R;
    volatile uint32_t MSK8R;
}CAN_FILTER_SFRmap;
# 9616 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct CANFD_MenMap
{
 volatile uint32_t CTLR0;
 volatile uint32_t BRGR;
 volatile const uint32_t RCR;
 volatile uint32_t EROR;
 volatile uint32_t NOUSE1;
 volatile uint32_t MSKR;
 volatile uint32_t IER;
 volatile uint32_t IFR;
 volatile const uint32_t RX_SET1;
 union
 {
  struct
  {
   uint8_t RX_SET2_1;
   uint8_t RX_SET2_2;
   uint16_t RX_SET2_34;
  };
  struct
  {
   uint32_t RX_SET2;
  };

 };
 union
 {
  volatile const uint8_t RXDATA[64];
  volatile const uint32_t RXDATA_32[16];
 };
 volatile uint32_t TIMER;
 volatile const uint32_t CRC;
 volatile uint32_t NOUSE2;
 volatile uint32_t CTLR1;
 volatile const uint32_t AMSTA;

}CANFD_SFRMap;
# 10158 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct EXIC_MemMap
{
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t STATE;
       uint32_t RESERVED1;
    volatile uint32_t WRITEBUF;
    volatile uint32_t READBUF;

}EXIC_SFRmap;
# 10252 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct RTC_MemMap
{
    volatile uint32_t CR;
    volatile uint32_t ALRA;
    volatile uint32_t TMR;
    volatile uint32_t DTR;
    volatile uint32_t ALRB;
    volatile uint32_t TMER;
    volatile uint32_t TCR;
    volatile uint32_t IER;
    volatile uint32_t IFR;
    volatile uint32_t TMBR;
    volatile uint32_t DTBR;
}RTC_SFRmap;
# 10788 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct IWDT_MemMap
{
    volatile uint32_t CTL;
    volatile uint32_t FD;
}IWDT_SFRmap;
# 10837 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct WWDT_MemMap
{
    volatile uint32_t CTL;
    volatile uint32_t CNT;
    volatile uint32_t CTL1;
}WWDT_SFRmap;
# 10916 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct EWDT_MenMap
{
 volatile uint32_t CTL;
 volatile uint32_t CNT;
}EWDT_SFRmap;
# 11002 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct CFGL_MemMap
{
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t IFR;
}CFGL_SFRmap;
# 11189 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct ECFGL_MenMap
{
 union
 {
  struct
  {
   volatile uint32_t ECFGL0_CTL;
   volatile uint32_t ECFGL1_CTL;
   volatile uint32_t ECFGL2_CTL;
   volatile uint32_t ECFGL3_CTL;
   volatile uint32_t ECFGL4_CTL;
   volatile uint32_t ECFGL5_CTL;
   volatile uint32_t ECFGL6_CTL;
   volatile uint32_t ECFGL7_CTL;
   volatile uint32_t ECFGL8_CTL;
   volatile uint32_t ECFGL9_CTL;
   volatile uint32_t ECFGL10_CTL;
   volatile uint32_t ECFGL11_CTL;
   volatile uint32_t ECFGL12_CTL;
   volatile uint32_t ECFGL13_CTL;
   volatile uint32_t ECFGL14_CTL;
   volatile uint32_t ECFGL15_CTL;
  };
  volatile uint32_t ECFGL_CTL[16];
 };
 volatile uint32_t SOFTSEL;
 volatile uint32_t FCLK;
 volatile uint32_t IC;
 volatile uint32_t IF;
 volatile uint32_t RFCTL;
 volatile uint32_t FFCTL;
 volatile uint32_t ADC;
 volatile const uint32_t OUT;
}ECFGL_SFRmap;
# 11536 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct RST_MemMap
{
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}RST_SFRmap;
# 11718 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct PCLK_MemMap
{
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}PCLK_SFRmap;
# 11900 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct PM_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile const uint32_t STA0;
    volatile const uint32_t STA1;
    volatile uint32_t STAC;
    volatile uint32_t CTL2;
    volatile uint32_t CAL0;
    volatile uint32_t CAL1;
    volatile uint32_t CAL2;
}PM_SFRmap;
# 12376 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct BKP_MemMap
{
    volatile uint32_t CTL;
    volatile uint32_t INT;
             uint32_t RESERVED[14];
    volatile uint32_t DATA[8];
}BKP_SFRmap;
# 12462 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct FLASH_MemMap
{
    volatile uint32_t ISPCON0;
    volatile uint32_t ISPCON1;
    volatile uint32_t ISPCMD;
    volatile uint32_t ISPTRG;
             uint32_t RESERVED1;
    volatile uint32_t CFG;
             uint32_t RESERVED2;
    volatile uint32_t ISPADDR;
    volatile uint32_t STATE;
             uint32_t RESERVED3;
    volatile uint32_t NVMUNLOCK;
    volatile uint32_t PROUNLOCK;
    volatile uint32_t CFGUNLOCK;
             uint32_t RESERVED4;
    volatile uint32_t CSSTART;
    volatile uint32_t CSSTOP;
    volatile uint32_t CSRES[4];
}FLASH_SFRmap;
# 12663 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct CRC_MemMap
{
 volatile uint32_t CTL;
 volatile uint32_t DATA;
 volatile const uint32_t RSLT;
 volatile uint32_t INIT;
 volatile uint32_t PLN;
 volatile uint32_t RXOR;
 volatile uint32_t IDATA;
 volatile const uint32_t TEMP;

}CRC_SFRmap;
# 12725 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct AES_MenMap
{
 volatile uint32_t CTL;
 volatile uint32_t INT;
       uint32_t RESERVED1;
       uint32_t RESERVED2;
 volatile uint32_t INPUT0;
 volatile uint32_t INPUT1;
 volatile uint32_t INPUT2;
 volatile uint32_t INPUT3;
 volatile const uint32_t OUTPUT0;
 volatile const uint32_t OUTPUT1;
 volatile const uint32_t OUTPUT2;
 volatile const uint32_t OUTPUT3;
}AES_SFRmap;
# 12833 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct RNG_MenMap
{
 volatile uint32_t CTL;
 volatile uint32_t STATE;
 volatile const uint32_t SEED;
 volatile const uint32_t DR;
}RNG_SFRmap;
# 12936 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct FlexMUX_MenMap
{
 volatile uint32_t SOU;
 volatile uint32_t TAR;
}FlexMUX_SFRmap;
# 13091 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct FDC_MenMap
{
 volatile uint32_t CTL;
 volatile uint32_t MOD;
 volatile const uint32_t CNT;
 volatile uint32_t IDLY;
 volatile uint32_t CH0CTL;
 volatile uint32_t CH1CTL;
 volatile uint32_t CH2CTL;
 volatile uint32_t CH3CTL;
       uint32_t RESERVED[4];
 volatile uint32_t CH0DLY0;
 volatile uint32_t CH0DLY1;
 volatile uint32_t CH0DLY2;
       uint32_t RESERVED5;
 volatile uint32_t CH1DLY0;
 volatile uint32_t CH1DLY1;
 volatile uint32_t CH1DLY2;
       uint32_t RESERVED6;
 volatile uint32_t CH2DLY0;
 volatile uint32_t CH2DLY1;
 volatile uint32_t CH2DLY2;
       uint32_t RESERVED7;
 volatile uint32_t CH3DLY0;
 volatile uint32_t CH3DLY1;
 volatile uint32_t CH3DLY2;
       uint32_t RESERVED8;
 volatile uint32_t PO0DLY;
 volatile uint32_t PO1DLY;
 volatile uint32_t PO2DLY;
 volatile uint32_t PO3DLY;
}FDC_SFRmap;
# 13592 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct FlexRM_MenMap
{
 volatile uint32_t CTL;
 volatile uint32_t GPSR0;
 volatile uint32_t GPSR1;
 volatile uint32_t GCSR0;
 volatile uint32_t GCSR1;
 volatile uint32_t GCSR2;
}FlexRM_SFRmap;
# 14015 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
typedef struct CACHE_MenMap
{
 volatile uint32_t CTLR;
}CACHE_SFRmap;
# 14080 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h"
static inline uint32_t
SFR_Config (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}
# 33 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156Config.h" 1
# 34 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6.h" 2
# 30 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_flash.h" 2



typedef enum
{
    LOCK = 0,
    UNLOCK = !LOCK
} LockStatus;





typedef union CheckSumStruct
{
    uint32_t m_ResultWord[4];
    uint32_t m_ResultShort[8];
    uint32_t m_ResultByte[16];
}FLASH_CheckSumResult;




typedef struct
{
    uint32_t m_Mode;

    uint32_t m_Zone;

    uint32_t m_Addr;

    uint32_t m_WriteSize;

    uint32_t * m_Data;

}FLASH_ProgramTypeDef;
# 157 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_flash.h"
LockStatus FLASH_Get_NonVolatile_Memory_Unlock_Status_RAM (void);
void FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM (void);
LockStatus FLASH_Get_Flash_Unlock_Status_RAM (void);
void FLASH_Clear_Flash_Unlock_Status_RAM (void);
LockStatus FLASH_Get_Config_Unlock_Status_RAM (void);
void FLASH_Clear_Config_Unlock_Status_RAM (void);
void FLASH_Data_Write_Enable_RAM (FunctionalState NewState);
void FLASH_Zone_Config_RAM (uint32_t ZoneSelect);
void FLASH_Standby_Mode_Config_RAM (uint32_t ModeSelect);
void FLASH_IP_Config_RAM (uint32_t FlashIPSelect);
void FLASH_Read_Mode_Config_RAM (uint32_t ReadMode);
void FLASH_Calibration_Updata_Enable_RAM (FunctionalState NewState);
void FLASH_Information_Zone_Wipe_Unlock_Config_RAM (LockStatus NewState);
void FLASH_Half_Page_Write_Size_Config_RAM (uint32_t WriteSize);
void FLASH_Program_Cmd_Config_RAM (uint32_t CmdSelect);
void FLASH_Executive_Cmd_RAM (void);
void FLASH_NonVolatile_Memory_ECC_Enable_RAM (FunctionalState NewState);
void FLASH_Linear_Prefetch_Enable_RAM (FunctionalState NewState);
void FLASH_Period_Number_Config_RAM (uint32_t PeriodNum);
void FLASH_Program_Addr_Config_RAM (uint32_t ProgramAddr);
FlagStatus FLASH_Get_Program_Status_RAM (void);
FlagStatus FLASH_Get_Wipe_Status_RAM (void);
FlagStatus FLASH_Get_Compute_Complete_Status_RAM (void);
void FLASH_Clear_Compute_Complete_Status_RAM (void);


FlagStatus FLASH_Get_CFG_Error_Flag_RAM (void);
void FLASH_Clear_CFG_Error_Flag_RAM (void);


void FLASH_CheckSum_Addr_Config_RAM(uint32_t StartAddr, uint32_t StopAddr);
void FLASH_Start_SIG_Compute_Enable_RAM (FunctionalState NewState);
void FLASH_Get_CheckSum_Result_RAM (FLASH_CheckSumResult* CheckSumStruct);


void FLASH_Clear_NonVolatile_Memory_Unlock_Status (void);
void FLASH_Clear_Flash_Unlock_Status (void);
void FLASH_Clear_Config_Unlock_Status (void);
void FLASH_Zone_Config(uint32_t ZoneSelect);
void FLASH_Executive_Cmd(void);
FlagStatus FLASH_Get_Program_Status (void);
FlagStatus FLASH_Get_Wipe_Status (void);



FlagStatus CACHE_Get_CACHE_ECC_Error_Flag(void);
FlagStatus CACHE_Get_FLASH_ECC_Error_Flag(void);
void CACHE_RAM_Check_ECC_Error_INT_Enable(FunctionalState NewState);
void CACHE_CACHE_Check_ECC_Error_INT_Enable(FunctionalState NewState);
void CACHE_FLASH_Check_ECC_Error_INT_Enable(FunctionalState NewState);
void CACHE_CACHE_Check_ECC_Enable(FunctionalState NewState);
void CACHE_Instruction_CACHE_Read_2Row_Enable(FunctionalState NewState);
void CACHE_Instruction_CACHE_Write_2Row_Enable(FunctionalState NewState);
void CACHE_CACHE_Reset_Enable(FunctionalState NewState);
void CACHE_CACHE_Enable(FunctionalState NewState);
# 30 "../src/kf32a1x6_flash.c" 2
# 50 "../src/kf32a1x6_flash.c"
void __attribute__((section(".indata"))) CHECK_RESTRICTION_RAM(int expr)
{
 while(!expr)
  ;
}


static inline uint32_t __attribute__((section(".indata"))) SFR_Config_RAM (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}






LockStatus __attribute__((section(".indata"))) FLASH_Get_NonVolatile_Memory_Unlock_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) & ((uint32_t)1<<((0))))
    {

        return UNLOCK;
    }
    else
    {

        return LOCK;
    }
}






void __attribute__((section(".indata"))) FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM (void)
{
 uint32_t tmpreg;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((0)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((0)))),
                        tmpreg);
}





void FLASH_Clear_NonVolatile_Memory_Unlock_Status (void)
{
 uint32_t tmpreg;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((0)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((0)))),
                        tmpreg);
}







LockStatus __attribute__((section(".indata"))) FLASH_Get_Flash_Unlock_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) & ((uint32_t)1<<((1))))
    {

        return UNLOCK;
    }
    else
    {

        return LOCK;
    }
}






void __attribute__((section(".indata"))) FLASH_Clear_Flash_Unlock_Status_RAM (void)
{
 uint32_t tmpreg;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((1)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((1)))),
                        tmpreg);
}





void FLASH_Clear_Flash_Unlock_Status (void)
{
 uint32_t tmpreg;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((1)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((1)))),
                        tmpreg);
}







LockStatus __attribute__((section(".indata"))) FLASH_Get_Config_Unlock_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) & ((uint32_t)1<<((2))))
    {

        return UNLOCK;
    }
    else
    {

        return LOCK;
    }
}






void __attribute__((section(".indata"))) FLASH_Clear_Config_Unlock_Status_RAM (void)
{
 uint32_t tmpreg;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((2)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((2)))),
                        tmpreg);
}





void FLASH_Clear_Config_Unlock_Status (void)
{
 uint32_t tmpreg;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((2)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((2)))),
                        tmpreg);
}







void __attribute__((section(".indata"))) FLASH_Data_Write_Enable_RAM (FunctionalState NewState)
{

    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || (NewState) == TRUE));


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((3)));
    }
}
# 245 "../src/kf32a1x6_flash.c"
void __attribute__((section(".indata"))) FLASH_Zone_Config_RAM (uint32_t ZoneSelect)
{

    CHECK_RESTRICTION_RAM((((ZoneSelect) == ((uint32_t)0<<(4))) || ((ZoneSelect) == ((uint32_t)1<<(4)))));


    if (ZoneSelect != ((uint32_t)0<<(4)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
    }
}







void FLASH_Zone_Config(uint32_t ZoneSelect)
{

    ((void)0);


    if (ZoneSelect != ((uint32_t)0<<(4)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
    }
}
# 295 "../src/kf32a1x6_flash.c"
void __attribute__((section(".indata"))) FLASH_Standby_Mode_Config_RAM (uint32_t ModeSelect)
{
 uint32_t tmpreg;


    CHECK_RESTRICTION_RAM((((ModeSelect) == ((uint32_t)0<<(5))) || ((ModeSelect) == ((uint32_t)1<<(5))) || ((ModeSelect) == ((uint32_t)2<<(5))) || ((ModeSelect) == ((uint32_t)3<<(5)))));


    tmpreg = ((uint32_t)0x50AF0000) | ModeSelect;
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((5)))),
                        tmpreg);
}
# 318 "../src/kf32a1x6_flash.c"
void __attribute__((section(".indata"))) FLASH_Read_Mode_Config_RAM (uint32_t ReadMode)
{

    CHECK_RESTRICTION_RAM((((ReadMode) == ((uint32_t)0<<(1))) || ((ReadMode) == ((uint32_t)1<<(1)))));


    if (ReadMode != ((uint32_t)0<<(0)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1))),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1))),"i"((1)));
    }
}






void __attribute__((section(".indata"))) FLASH_Calibration_Updata_Enable_RAM (FunctionalState NewState)
{
 uint32_t tmpreg;


    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || (NewState) == TRUE));


    tmpreg = ((uint32_t)0xA05F0000)
           | (NewState << (2));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<((2)))),
                        tmpreg);
}
# 363 "../src/kf32a1x6_flash.c"
void __attribute__((section(".indata"))) FLASH_Information_Zone_Wipe_Unlock_Config_RAM (LockStatus NewState)
{
 uint32_t tmpreg;


    CHECK_RESTRICTION_RAM((((NewState) == LOCK) || ((NewState) == UNLOCK)));


    tmpreg = ((uint32_t)0xA05F0000)
           | (NewState << (15));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<((15)))),
                        tmpreg);
}






void __attribute__((section(".indata"))) FLASH_Half_Page_Write_Size_Config_RAM (uint32_t WriteSize)
{
 uint32_t tmpreg;


    CHECK_RESTRICTION_RAM((((uint32_t)(WriteSize) >> 6) == 0));


    tmpreg = WriteSize << (5);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                        ~((uint32_t)0x3F<<((5))),
                        tmpreg);
}
# 406 "../src/kf32a1x6_flash.c"
void __attribute__((section(".indata"))) FLASH_Program_Cmd_Config_RAM (uint32_t CmdSelect)
{

    CHECK_RESTRICTION_RAM((((CmdSelect) == ((uint32_t)0x15<<(0))) || ((CmdSelect) == ((uint32_t)0x0A<<(0))) || ((CmdSelect) == ((uint32_t)0x1B<<(0))) || ((CmdSelect) == ((uint32_t)0x05<<(0)))));


    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                        ~((uint32_t)0x1F<<((0))),
                        CmdSelect);
}







void __attribute__((section(".indata"))) FLASH_Executive_Cmd_RAM(void)
{
 uint32_t tmpreg;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((0)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPTRG) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPTRG),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((0)))),
                        tmpreg);
}







void FLASH_Executive_Cmd(void)
{
 uint32_t tmpreg;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((0)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPTRG) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPTRG),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((0)))),
                        tmpreg);
}






void __attribute__((section(".indata"))) FLASH_NonVolatile_Memory_ECC_Enable_RAM (FunctionalState NewState)
{

    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || (NewState) == TRUE));


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG))),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG))),"i"((7)));
    }
}






void __attribute__((section(".indata"))) FLASH_Linear_Prefetch_Enable_RAM (FunctionalState NewState)
{

    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || (NewState) == TRUE));


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG))),"i"((6)));
    }
    else
    {

     __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG))),"i"((6)));
    }
}






void __attribute__((section(".indata"))) FLASH_Period_Number_Config_RAM (uint32_t PeriodNum)
{
 uint32_t tmpreg;


    CHECK_RESTRICTION_RAM((((uint32_t)(PeriodNum) >> 4) == 0));


    tmpreg = (PeriodNum - 1) << (0);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG),
                        ~((uint32_t)0xF<<((0))),
                        tmpreg);
}






void __attribute__((section(".indata"))) FLASH_Program_Addr_Config_RAM (uint32_t ProgramAddr)
{
 uint32_t tmpreg;


    CHECK_RESTRICTION_RAM((((uint32_t)(ProgramAddr) >> 20) == 0));


    tmpreg = ProgramAddr << (0);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPADDR) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPADDR),
                        ~((uint32_t)0x3FFFF<<((2))),
                        tmpreg);
}






FlagStatus __attribute__((section(".indata"))) FLASH_Get_Program_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((3))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus FLASH_Get_Program_Status (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((3))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 580 "../src/kf32a1x6_flash.c"
FlagStatus __attribute__((section(".indata"))) FLASH_Get_Wipe_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((2))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus FLASH_Get_Wipe_Status (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((2))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}





FlagStatus __attribute__((section(".indata"))) FLASH_Get_Compute_Complete_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((1))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






void __attribute__((section(".indata"))) FLASH_Clear_Compute_Complete_Status_RAM (void)
{

    while(((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((1))))>>(1))
    {
     __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE))),"i"((1)));
    }
}
# 652 "../src/kf32a1x6_flash.c"
FlagStatus __attribute__((section(".indata"))) FLASH_Get_CFG_Error_Flag_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((0))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






void __attribute__((section(".indata"))) FLASH_Clear_CFG_Error_Flag_RAM (void)
{


    while(((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((0))))>>(0))
    {
     __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE))),"i"((0)));
    }
}
# 688 "../src/kf32a1x6_flash.c"
void __attribute__((section(".indata"))) FLASH_CheckSum_Addr_Config_RAM(uint32_t StartAddr, uint32_t StopAddr)
{

    CHECK_RESTRICTION_RAM((((uint32_t)(StartAddr) >> 20) == 0));
    CHECK_RESTRICTION_RAM((((uint32_t)(StopAddr) >> 20) == 0));

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSSTART) = StartAddr;
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSSTOP) = StopAddr;
}






void __attribute__((section(".indata"))) FLASH_Start_SIG_Compute_Enable_RAM (FunctionalState NewState)
{

    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || (NewState) == TRUE));


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSSTOP))),"i"((20)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSSTOP))),"i"((20)));
    }
}







void __attribute__((section(".indata"))) FLASH_Get_CheckSum_Result_RAM (FLASH_CheckSumResult* CheckSumStruct)
{
 uint32_t tmpreg;


    tmpreg = (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSRES[0]);
    CheckSumStruct->m_ResultWord[0] = tmpreg;

    tmpreg = (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSRES[1]);
    CheckSumStruct->m_ResultWord[1] = tmpreg;

    tmpreg = (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSRES[2]);
    CheckSumStruct->m_ResultWord[2] = tmpreg;

    tmpreg = (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSRES[3]);
    CheckSumStruct->m_ResultWord[3] = tmpreg;
}







FlagStatus CACHE_Get_CACHE_ECC_Error_Flag(void)
{
 return (((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) & ((uint32_t)1<<((9)))) >> (9));
}






FlagStatus CACHE_Get_FLASH_ECC_Error_Flag(void)
{
 return (((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) & ((uint32_t)1<<((8)))) >> (8));
}






void CACHE_RAM_Check_ECC_Error_INT_Enable(FunctionalState NewState)
{
 uint32_t tmpreg;


 ((void)0);

 tmpreg = NewState << (7);
 (((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) = SFR_Config((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR), ~((uint32_t)1<<((7))), tmpreg);
}






void CACHE_CACHE_Check_ECC_Error_INT_Enable(FunctionalState NewState)
{
 uint32_t tmpreg;


 ((void)0);

 tmpreg = NewState << (6);
 (((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) = SFR_Config((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR), ~((uint32_t)1<<((6))), tmpreg);
}






void CACHE_FLASH_Check_ECC_Error_INT_Enable(FunctionalState NewState)
{
 uint32_t tmpreg;


 ((void)0);

 tmpreg = NewState << (5);
 (((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) = SFR_Config((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR), ~((uint32_t)1<<((5))), tmpreg);
}






void CACHE_CACHE_Check_ECC_Enable(FunctionalState NewState)
{
 uint32_t tmpreg;


 ((void)0);

 tmpreg = NewState << (4);
 (((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) = SFR_Config((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR), ~((uint32_t)1<<((4))), tmpreg);
}






void CACHE_Instruction_CACHE_Read_2Row_Enable(FunctionalState NewState)
{
 uint32_t tmpreg;


 ((void)0);

 tmpreg = NewState << (3);
 (((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) = SFR_Config((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR), ~((uint32_t)1<<((3))), tmpreg);
}






void CACHE_Instruction_CACHE_Write_2Row_Enable(FunctionalState NewState)
{
 uint32_t tmpreg;


 ((void)0);

 tmpreg = NewState << (2);
 (((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) = SFR_Config((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR), ~((uint32_t)1<<((2))), tmpreg);
}






void CACHE_CACHE_Reset_Enable(FunctionalState NewState)
{
 uint32_t tmpreg;


 ((void)0);

 tmpreg = NewState << (1);
 (((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) = SFR_Config((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR), ~((uint32_t)1<<((1))), tmpreg);
}






void CACHE_CACHE_Enable(FunctionalState NewState)
{
 uint32_t tmpreg;


 ((void)0);

 tmpreg = NewState << (0);
 (((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR) = SFR_Config((((CACHE_SFRmap *) ((uint32_t)0x402000C0))->CTLR), ~((uint32_t)1<<((0))), tmpreg);
}
