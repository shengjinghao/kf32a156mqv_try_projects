# 1 "../src/kf32a1x6_atim.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\Release//"
# 1 "<command-line>"
# 1 "../src/kf32a1x6_atim.c"
# 40 "../src/kf32a1x6_atim.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_atim.h" 1
# 31 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_atim.h"
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
# 32 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_atim.h" 2
# 52 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_atim.h"
typedef struct
{
    uint16_t m_Counter;
    uint16_t m_Period;
    uint16_t m_Prescaler;
    uint16_t m_Postscaler;

    uint32_t m_CounterMode;

    uint16_t m_Clock;

    uint16_t m_WorkMode;

    uint16_t m_EXPulseSync;

} ATIM_InitTypeDef;




typedef struct
{
    uint32_t m_Channel;

    uint32_t m_Mode;

    FunctionalState m_PWMInput;

    FunctionalState m_XORMode;

} ECCP_CaptureInitTypeDef;




typedef struct
{
    uint32_t m_Channel;

    uint32_t m_Mode;

    uint16_t m_DutyRatio;

    uint8_t m_DeadTime;

    uint8_t m_OutputMode;

    uint16_t m_HOutputCtl;

    uint16_t m_LOutputCtl;

    FunctionalState m_PhaseMove;

    FunctionalState m_SinglePWM;

    FunctionalState m_CloseTimer;

} ECCP_PWMInitTypeDef;
# 492 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_atim.h"
void ATIM_Reset (ATIM_SFRmap* ATIMx);
void ATIM_X_Configuration(ATIM_SFRmap* ATIMx, ATIM_InitTypeDef* atimInitStruct);
void ATIM_Z_Configuration(ATIM_SFRmap* ATIMx, ATIM_InitTypeDef* atimInitStruct);
void ATIM_Struct_Init (ATIM_InitTypeDef* atimInitStruct);
void ATIM_X_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Updata_Configuration (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter,uint32_t UpdataOutput, uint32_t UpdataImmediately);
void ATIM_Z_Updata_Configuration (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter,uint32_t UpdataOutput, uint32_t UpdataImmediately);
void ATIM_X_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter);
void ATIM_Z_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter);
void ATIM_X_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period);
void ATIM_Z_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period);
void ATIM_X_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler);
void ATIM_Z_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler);
void ATIM_X_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode);
void ATIM_Z_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode);
void ATIM_X_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock);
void ATIM_Z_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock);
void ATIM_X_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler);
void ATIM_Z_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler);
void ATIM_X_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync);
void ATIM_Z_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync);
void ATIM_X_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState);
void ATIM_Z_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState);
DIRStatus ATIM_X_Get_Direction (ATIM_SFRmap* ATIMx);
DIRStatus ATIM_Z_Get_Direction (ATIM_SFRmap* ATIMx);
void ATIM_X_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx,uint16_t CompareAD0, uint16_t CompareAD1);
void ATIM_Z_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx, uint16_t CompareAD);
void ATIM_X_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,FunctionalState NewState);
void ATIM_Z_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,FunctionalState NewState);
void ATIM_X_Updata_Output_Ctl (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_Output_Ctl (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter);
void ATIM_Z_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter);
void ATIM_X_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode);
void ATIM_Z_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode);
void ATIM_Master_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t MasterMode);
void ATIM_Master_Slave_Snyc_Enable (ATIM_SFRmap* ATIMx,FunctionalState NewState);
void ATIM_Trigger_Select_Config (ATIM_SFRmap* ATIMx,FunctionalState TriggerSelect);
void ATIM_Timer_Unite_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
uint16_t ATIM_X_Get_Counter (ATIM_SFRmap* ATIMx);
uint16_t ATIM_Z_Get_Counter (ATIM_SFRmap* ATIMx);
uint16_t ATIM_X_Get_Period (ATIM_SFRmap* ATIMx);
uint16_t ATIM_Z_Get_Period (ATIM_SFRmap* ATIMx);
uint16_t ATIM_X_Get_Prescaler (ATIM_SFRmap* ATIMx);
uint16_t ATIM_Z_Get_Prescaler (ATIM_SFRmap* ATIMx);
RetStatus ATIM_X_Cmp_Clear_Tim_Enable(ATIM_SFRmap* ATIMx, FunctionalState NewState);
RetStatus ATIM_Z_Cmp_Clear_Tim_Enable(ATIM_SFRmap* ATIMx, FunctionalState NewState);
RetStatus ATIM_X_Cmp_Clear_Tim_Edge_Choose(ATIM_SFRmap* ATIMx, uint8_t Edge);
RetStatus ATIM_Z_Cmp_Clear_Tim_Edge_Choose(ATIM_SFRmap* ATIMx, uint8_t Edge);
RetStatus ATIM_X_Cmp_Clear_Tim_Choose(ATIM_SFRmap* ATIMx, uint8_t Cmpnum);
RetStatus ATIM_Z_Cmp_Clear_Tim_Choose(ATIM_SFRmap* ATIMx, uint8_t Cmpnum);



void ATIM_X_Updata_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Trigger_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Trigger_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
FlagStatus ATIM_X_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_Z_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_X_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_Z_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_X_Get_Trigger_INT_Flag (ATIM_SFRmap* ATIMx);
void ATIM_X_Generate_Trigger_Config (ATIM_SFRmap* ATIMx,FunctionalState NewState);
FlagStatus ATIM_X_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_Z_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_X_Get_Trigger_DMA_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_X_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_Z_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_X_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_Z_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
RetStatus ATIM_X_Clear_Trigger_INT_Flag (ATIM_SFRmap* ATIMx);

void ECCP_Compare_Configuration(ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t CompareMode, uint16_t CompareValue);
void ECCP_Capture_Configuration (ECCP_SFRmap* ECCPx,ECCP_CaptureInitTypeDef* eccpInitStruct);
void ECCP_Capture_Struct_Init (ECCP_CaptureInitTypeDef* eccpInitStruct);
void ECCP_PWM_Configuration (ECCP_SFRmap* ECCPx,ECCP_PWMInitTypeDef* ECCP_InitStruct);
void ECCP_PWM_Struct_Init (ECCP_PWMInitTypeDef* ECCP_InitStruct);
void ECCP_Capture_Mode_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t EdgeConfig);
void ECCP_Compare_Mode_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t CmpConfig);
void ECCP_PWM_Mode_Config (ECCP_SFRmap* ECCPx, uint32_t PWMConfig);
uint16_t ECCP_Get_Capture_Result (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_Set_Compare_Result (ECCP_SFRmap* ECCPx,uint32_t Channel, uint16_t Value);
void ECCP_Generate_Trigger_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState);
void ECCP_PWM_Input_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Input_XOR_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Single_Pulse_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Single_Pulse_Shut_Enable (ECCP_SFRmap* ECCPx,FunctionalState NewState);
void ECCP_PWM_Restart_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Dead_Time_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint8_t DeadTime);
void ECCP_Channel_Output_Control (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t Port, uint32_t ChannelOutputCtl);
void ECCP_Channel_Output_Mode (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t ChannelOutputMode);
void ECCP_Channel_Work_State_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t WorkingState);
void ECCP_TZ_Showdown_SEL(ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal);
void ECCP_TX_Showdown_SEL(ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal);
void ECCP_CHANNEL4_Shutdown_SEL (ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal);
void ECCP_CHANNEL123_Shutdown_SEL (ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal);
FlagStatus ECCP_Get_Channel_Work_State (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_Channel_Shutdown_Signal (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t ShutDownSignal);
void ECCP_Channel_Pin_Ctl (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t Port, uint32_t ChannelPinCtl);
void ECCP_Zero_Clock_Config (ECCP_SFRmap* ECCPx, uint32_t ZeroClock);
void ECCP_Channel_Pin_Tristate_Enable (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t Port, uint32_t PinTristateCtl);
void ECCP_FlexMUX_CHANNEL_SEL (ECCP_SFRmap* ECCPx,uint32_t FlexMUXSignal);
void ECCP_Channel_Modulation_SEL (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t ChannelState);
void ECCP_GTB_OUTPUT_Config (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_GTB_MODE_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_CAPTEST_MODE_Config(ECCP_SFRmap* ECCPx, uint32_t CAPTEST);
void ECCP_UNION_SINGEL_EFFECTIVE_Config(ECCP_SFRmap* ECCPx, uint32_t UnionOutputSingel);
void ECCP_UNION_SINGEL_OUTPUT_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_COMH_Value_Config(ECCP_SFRmap* ECCPx, uint32_t Channel, uint16_t COMHValue);
void ECCP_COML_Value_Config(ECCP_SFRmap* ECCPx, uint32_t Channel, uint16_t COMLValue);
void ECCP_Fault_Contral_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel, FunctionalState NewState);
void ECCP_Fault_Output_Polarity_Select (ECCP_SFRmap* ECCPx, uint32_t Channel, uint32_t OutPolarity);
void ECCP_Filter_PulseWidth_Config(ECCP_SFRmap* ECCPx, uint32_t Channel, uint32_t PulseWidth);
void ECCP_Filter_Function_Enable(ECCP_SFRmap* ECCPx, uint32_t Channel, FunctionalState NewState);
void ECCP_Filter_CLKDIV_Config(ECCP_SFRmap* ECCPx, uint32_t Channel, uint32_t ClkDiv);
void ECCP_Fault_Function_Enable(ECCP_SFRmap* ECCPx, uint32_t Channel, FunctionalState NewState);
FlagStatus ECCP_Get_Fault_INT_Flag(ECCP_SFRmap* ECCPx,uint32_t Channel);
RetStatus ECCP_Clear_Fault_INT_Flag(ECCP_SFRmap* ECCPx,uint32_t Channel);
void ECCP_Fault_INT_Enable(ECCP_SFRmap* ECCPx, uint32_t Channel, FunctionalState NewState);
void ECCP_UNION_jitter_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_CYCLE_jitter_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_EDGE_jitter_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_FRCVAL_Value_Config(ECCP_SFRmap* ECCPx, uint8_t Value);
void ECCP_Tz_Triggle_AD_Driction_SEL(ECCP_SFRmap* ECCPx, FunctionalState Direction);
void ECCP_Tx_Triggle_AD_Driction_SEL(ECCP_SFRmap* ECCPx,uint8_t CCRx, FunctionalState Direction);
void ECCP_Tz_Triggle_AD_Driction_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Tx_Triggle_AD_Driction_Enable(ECCP_SFRmap* ECCPx, uint8_t CCRx, FunctionalState NewState);



void ECCP_Channel_INT_Enable (ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState);
void ECCP_X_Turn_off_DMA_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Channel_DMA_Enable (ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState);
FlagStatus ECCP_Get_Channel_Trigger_INT_Flag (ECCP_SFRmap* ECCPx,uint32_t Channel);
FlagStatus ECCP_X_Get_Turn_off_DMA_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ECCP_Get_Trigger_DMA_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel);
RetStatus ECCP_Clear_Channel_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_PWM_Move_Phase_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Channel_Zero_Detect_Sequential_Ctl (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t NewState);
FlagStatus ECCP_Get_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,uint32_t Channel);
void ECCP_Clear_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,uint32_t Channel);
void ECCP_Channel_Zero_Detect_Enable (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t NewState);
void ECCP_Channel_Zero_Voltage_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t ZeroDetectVoltage);
# 659 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_atim.h"
typedef struct
{
    uint32_t m_Counter;
    uint32_t m_Period;
    uint32_t m_Prescaler;
    uint32_t m_Phase;
    uint32_t m_CounterMode;

    uint32_t m_Sync;

    uint32_t m_Clock;

    uint32_t m_WorkMode;

    FunctionalState m_PhaseEn;

    uint32_t m_PhaseDirection;

    FunctionalState m_GateEn;

} ETIM_InitTypeDef;
# 41 "../src/kf32a1x6_atim.c" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rst.h" 1
# 58 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rst.h"
void RST_CTL0_Peripheral_Reset_Enable(uint32_t RST_CTL0Periph,
                    FunctionalState NewState);
void RST_CTL1_Peripheral_Reset_Enable(uint32_t RST_CTL1Periph,
                    FunctionalState NewState);
void RST_CTL2_Peripheral_Reset_Enable(uint32_t RST_CTL2Periph,
                    FunctionalState NewState);
void RST_CTL3_Peripheral_Reset_Enable(uint32_t RST_CTL3Periph,
                    FunctionalState NewState);
# 42 "../src/kf32a1x6_atim.c" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pclk.h" 1
# 57 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pclk.h"
void PCLK_CTL0_Peripheral_Clock_Enable (uint32_t PCLK_CTL0_bit,FunctionalState NewState);
void PCLK_CTL1_Peripheral_Clock_Enable (uint32_t PCLK_CTL1_bit,FunctionalState NewState);
void PCLK_CTL2_Peripheral_Clock_Enable (uint32_t PCLK_CTL2_bit,FunctionalState NewState);
void PCLK_CTL3_Peripheral_Clock_Enable (uint32_t PCLK_CTL3_bit,FunctionalState NewState);
# 43 "../src/kf32a1x6_atim.c" 2
# 90 "../src/kf32a1x6_atim.c"
void ATIM_Reset (ATIM_SFRmap* ATIMx)
{

    ((void)0);

    if (ATIMx == ((ATIM_SFRmap *) ((uint32_t)0x40000300)))
    {
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((6))), TRUE);
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((6))), FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(((uint32_t)1<<((6))), TRUE);
    }
    else if (ATIMx == ((ATIM_SFRmap *) ((uint32_t)0x40000300)))
    {
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((6))), TRUE);
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((6))), FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(((uint32_t)1<<((6))), TRUE);
    }
    else
    {
        ;
    }
}
# 127 "../src/kf32a1x6_atim.c"
void ATIM_X_Configuration(ATIM_SFRmap* ATIMx,
                    ATIM_InitTypeDef* atimInitStruct)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    ATIMx->TXCNT = (uint32_t)atimInitStruct->m_Counter;


    ATIMx->TXPPX = (uint32_t)atimInitStruct->m_Period;


    ATIMx->TXPRSC = (uint32_t)atimInitStruct->m_Prescaler;







    tmpreg = ((uint32_t)atimInitStruct->m_Postscaler << (3))
             | (atimInitStruct->m_CounterMode)
             | ((uint32_t)atimInitStruct->m_Clock)
             | ((uint32_t)atimInitStruct->m_WorkMode)
             | ((uint32_t)atimInitStruct->m_EXPulseSync);
    ATIMx->TXCTL = SFR_Config (ATIMx->TXCTL,
                          ~(((uint32_t)1<<((0))) | ((uint32_t)1<<((1))) | ((uint32_t)0xF<<((3))) | ((uint32_t)3<<((8))) | ((uint32_t)7<<((13)))),
                          tmpreg);
}







void ATIM_Z_Configuration(ATIM_SFRmap* ATIMx,
                    ATIM_InitTypeDef* atimInitStruct)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    ATIMx->TZCNT = (uint32_t)atimInitStruct->m_Counter;


    ATIMx->TZPPZ = (uint32_t)atimInitStruct->m_Period;


    ATIMx->TZPRSC = (uint32_t)atimInitStruct->m_Prescaler;







    tmpreg = ((uint32_t)atimInitStruct->m_Postscaler << (3))
             | (atimInitStruct->m_CounterMode)
             | ((uint32_t)atimInitStruct->m_Clock)
             | ((uint32_t)atimInitStruct->m_WorkMode)
             | ((uint32_t)atimInitStruct->m_EXPulseSync);
    ATIMx->TZCTL = SFR_Config (ATIMx->TZCTL,
                          ~(((uint32_t)1<<((0))) | ((uint32_t)1<<((1))) | ((uint32_t)0xF<<((3))) | ((uint32_t)3<<((8))) | ((uint32_t)7<<((13)))),
                          tmpreg);
}






void ATIM_Struct_Init (ATIM_InitTypeDef* atimInitStruct)
{

    atimInitStruct->m_Counter = 0x00000000;

    atimInitStruct->m_Period = 0x0000FFFF;

    atimInitStruct->m_Prescaler = 0x00000000;

    atimInitStruct->m_Postscaler = 0x0;

    atimInitStruct->m_CounterMode = ((uint32_t)0x4 << (13));

    atimInitStruct->m_Clock = ((uint32_t)0x0 << (8));

    atimInitStruct->m_WorkMode = ((uint32_t)0 << (0));

    atimInitStruct->m_EXPulseSync = ((uint32_t)0x0 << (1));
}
# 241 "../src/kf32a1x6_atim.c"
void ATIM_X_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((2)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((2)));
    }
}
# 267 "../src/kf32a1x6_atim.c"
void ATIM_Z_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((2)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((2)));
    }
}
# 296 "../src/kf32a1x6_atim.c"
void ATIM_X_Updata_Configuration (ATIM_SFRmap* ATIMx,
                    uint8_t UpdataCounter,
                    uint32_t UpdataOutput,
                    uint32_t UpdataImmediately)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    ATIMx->TXUDTIM = UpdataCounter;




    tmpreg = (UpdataOutput << (2))
             | (UpdataImmediately << (3));
    ATIMx->PXUDCTL = SFR_Config (ATIMx->PXUDCTL,
                          ~(((uint32_t)1<<((2))) | ((uint32_t)1<<((3)))),
                          tmpreg);
}
# 331 "../src/kf32a1x6_atim.c"
void ATIM_Z_Updata_Configuration (ATIM_SFRmap* ATIMx,
                    uint8_t UpdataCounter,
                    uint32_t UpdataOutput,
                    uint32_t UpdataImmediately)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    ATIMx->TZUDTIM = UpdataCounter;




    tmpreg = (UpdataOutput << (4))
             | (UpdataImmediately << (5));
    ATIMx->PXUDCTL = SFR_Config (ATIMx->PXUDCTL,
                          ~(((uint32_t)1<<((4))) | ((uint32_t)1<<((5)))),
                          tmpreg);
}
# 363 "../src/kf32a1x6_atim.c"
void ATIM_X_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((0)));
    }
}
# 389 "../src/kf32a1x6_atim.c"
void ATIM_Z_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((1)));
    }
}







void ATIM_X_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter)
{

    ((void)0);


    ATIMx->TXCNT = Counter;
}







void ATIM_Z_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter)
{

    ((void)0);


    ATIMx->TZCNT = Counter;
}







void ATIM_X_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period)
{

    ((void)0);


    ATIMx->TXPPX = Period;
}







void ATIM_Z_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period)
{

    ((void)0);


    ATIMx->TZPPZ = Period;
}







void ATIM_X_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler)
{

    ((void)0);


    ATIMx->TXPRSC = Prescaler;
}







void ATIM_Z_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler)
{

    ((void)0);


    ATIMx->TZPRSC = Prescaler;
}
# 510 "../src/kf32a1x6_atim.c"
void ATIM_X_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode)
{

    ((void)0);
    ((void)0);


    ATIMx->TXCTL = SFR_Config (ATIMx->TXCTL,
                          ~((uint32_t)7<<((13))),
                          CounterMode);
}
# 534 "../src/kf32a1x6_atim.c"
void ATIM_Z_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode)
{

    ((void)0);
    ((void)0);


    ATIMx->TZCTL = SFR_Config (ATIMx->TZCTL,
                          ~((uint32_t)7<<((13))),
                          CounterMode);
}
# 556 "../src/kf32a1x6_atim.c"
void ATIM_X_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock)
{

    ((void)0);
    ((void)0);


    ATIMx->TXCTL = SFR_Config (ATIMx->TXCTL,
                          ~((uint32_t)3<<((8))),
                          NewClock);
}
# 578 "../src/kf32a1x6_atim.c"
void ATIM_Z_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock)
{

    ((void)0);
    ((void)0);


    ATIMx->TZCTL = SFR_Config (ATIMx->TZCTL,
                          ~((uint32_t)3<<((8))),
                          NewClock);
}
# 612 "../src/kf32a1x6_atim.c"
void ATIM_X_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler)
{
 uint32_t tmpreg;

    ((void)0);
    ((void)0);


    tmpreg = NewPostscaler << (3);
    ATIMx->TXCTL = SFR_Config (ATIMx->TXCTL,
                          ~((uint32_t)0xF<<((3))),
                          tmpreg);
}
# 648 "../src/kf32a1x6_atim.c"
void ATIM_Z_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler)
{
 uint32_t tmpreg;

    ((void)0);
    ((void)0);


    tmpreg = NewPostscaler << (3);
    ATIMx->TZCTL = SFR_Config (ATIMx->TZCTL,
                          ~((uint32_t)0xF<<((3))),
                          tmpreg);
}
# 671 "../src/kf32a1x6_atim.c"
void ATIM_X_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync)
{

    ((void)0);
    ((void)0);


    if (PulseSync != ((uint32_t)0x0 << (1)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((1)));
    }
}
# 699 "../src/kf32a1x6_atim.c"
void ATIM_Z_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync)
{

    ((void)0);
    ((void)0);


    if (PulseSync != ((uint32_t)0x0 << (1)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((1)));
    }
}
# 727 "../src/kf32a1x6_atim.c"
void ATIM_X_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != ((uint32_t)0 << (0)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((0)));
    }
}
# 755 "../src/kf32a1x6_atim.c"
void ATIM_Z_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != ((uint32_t)0 << (0)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((0)));
    }
}






DIRStatus ATIM_X_Get_Direction (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->TXCTL & ((uint32_t)1<<((7))))
    {

        return DIR_UP;
    }
    else
    {

        return DIR_DOWN;
    }
}






DIRStatus ATIM_Z_Get_Direction (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->TZCTL & ((uint32_t)1<<((7))))
    {

        return DIR_UP;
    }
    else
    {

        return DIR_DOWN;
    }
}
# 827 "../src/kf32a1x6_atim.c"
void ATIM_X_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((12)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((12)));
    }
}
# 853 "../src/kf32a1x6_atim.c"
void ATIM_Z_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((12)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((12)));
    }
}
# 879 "../src/kf32a1x6_atim.c"
void ATIM_X_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((11)));
    }
}
# 905 "../src/kf32a1x6_atim.c"
void ATIM_Z_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((11)));
    }
}
# 931 "../src/kf32a1x6_atim.c"
void ATIM_X_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((10)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((10)));
    }
}
# 957 "../src/kf32a1x6_atim.c"
void ATIM_Z_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((10)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((10)));
    }
}
# 983 "../src/kf32a1x6_atim.c"
void ATIM_X_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx,uint16_t CompareAD0, uint16_t CompareAD1)
{

    ((void)0);


    ATIMx->TXCCR0 = CompareAD0;
    ATIMx->TXCCR1 = CompareAD1;
}







void ATIM_Z_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx,uint16_t CompareAD)
{

    ((void)0);


    ATIMx->TZCCR0 = CompareAD;
}
# 1015 "../src/kf32a1x6_atim.c"
void ATIM_X_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((3)));
    }
}
# 1041 "../src/kf32a1x6_atim.c"
void ATIM_Z_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((5)));
    }
}
# 1067 "../src/kf32a1x6_atim.c"
void ATIM_X_Updata_Output_Ctl (ATIM_SFRmap* ATIMx,FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((2)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((2)));
    }
}
# 1094 "../src/kf32a1x6_atim.c"
void ATIM_Z_Updata_Output_Ctl (ATIM_SFRmap* ATIMx,FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((4)));
    }
}
# 1120 "../src/kf32a1x6_atim.c"
void ATIM_X_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((0)));
    }
}
# 1146 "../src/kf32a1x6_atim.c"
void ATIM_Z_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((1)));
    }
}







void ATIM_X_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter)
{

    ((void)0);


    ATIMx->TXUDTIM = UpdataCounter;
}







void ATIM_Z_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter)
{

    ((void)0);


    ATIMx->TZUDTIM = UpdataCounter;
}
# 1207 "../src/kf32a1x6_atim.c"
void ATIM_X_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = SlaveMode << (3);
    ATIMx->ECCPXCTL2 = SFR_Config (ATIMx->ECCPXCTL2,
                          ~((uint32_t)7<<((3))),
                          tmpreg);
}
# 1234 "../src/kf32a1x6_atim.c"
void ATIM_Z_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = SlaveMode << (13);
    ATIMx->ECCPXCTL2 = SFR_Config (ATIMx->ECCPXCTL2,
                          ~((uint32_t)7<<((13))),
                          tmpreg);
}
# 1262 "../src/kf32a1x6_atim.c"
void ATIM_Master_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t MasterMode)
{

    ((void)0);
    ((void)0);


    ATIMx->ECCPXCTL2 = SFR_Config (ATIMx->ECCPXCTL2,
                          ~((uint32_t)7<<((0))),
                          MasterMode);
}
# 1281 "../src/kf32a1x6_atim.c"
void ATIM_Master_Slave_Snyc_Enable (ATIM_SFRmap* ATIMx,FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXCTL2)),"i"((9)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXCTL2)),"i"((9)));
    }
}
# 1315 "../src/kf32a1x6_atim.c"
void ATIM_Trigger_Select_Config (ATIM_SFRmap* ATIMx,uint32_t TriggerSelect)
{

    ((void)0);
    ((void)0);


    ATIMx->ECCPXCTL2 = SFR_Config (ATIMx->ECCPXCTL2,
                          ~((uint32_t)7<<((6))),
                          TriggerSelect);
}
# 1334 "../src/kf32a1x6_atim.c"
void ATIM_Timer_Unite_Enable (ATIM_SFRmap* ATIMx,FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXCTL3)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXCTL3)),"i"((1)));
    }
}






uint16_t ATIM_X_Get_Counter (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg;


    ((void)0);


    tmpreg = ATIMx->TXCNT;

    return tmpreg;
}






uint16_t ATIM_Z_Get_Counter (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg;


    ((void)0);


    tmpreg = ATIMx->TZCNT;

    return tmpreg;
}






uint16_t ATIM_X_Get_Period (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg;


    ((void)0);


    tmpreg = ATIMx->TXPPX;

    return tmpreg;
}






uint16_t ATIM_Z_Get_Period (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg;


    ((void)0);


    tmpreg = ATIMx->TZPPZ;

    return tmpreg;
}






uint16_t ATIM_X_Get_Prescaler (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg;


    ((void)0);


    tmpreg = ATIMx->TXPRSC;

    return tmpreg;
}






uint16_t ATIM_Z_Get_Prescaler (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg;


    ((void)0);


    tmpreg = ATIMx->TZPRSC;

    return tmpreg;
}
# 1468 "../src/kf32a1x6_atim.c"
RetStatus ATIM_X_Cmp_Clear_Tim_Enable(ATIM_SFRmap* ATIMx, FunctionalState NewState)
{
 if(ATIMx == ((ATIM_SFRmap *) ((uint32_t)0x40000300)))
 {
  (((ATIM_SFRmap *) ((uint32_t)0x40000300))->TXCCTCTL) = SFR_Config((((ATIM_SFRmap *) ((uint32_t)0x40000300))->TXCCTCTL), ~(((uint32_t)1<<((0)))), NewState);
 }
 else
 {
  ((void)0);
  return FAILURE;
 }
 return SUCCESS;
}
# 1489 "../src/kf32a1x6_atim.c"
RetStatus ATIM_Z_Cmp_Clear_Tim_Enable(ATIM_SFRmap* ATIMx, FunctionalState NewState)
{
 if(ATIMx == ((ATIM_SFRmap *) ((uint32_t)0x40000300)))
 {
  (((ATIM_SFRmap *) ((uint32_t)0x40000300))->TZCCTCTL) = SFR_Config((((ATIM_SFRmap *) ((uint32_t)0x40000300))->TZCCTCTL), ~(((uint32_t)1<<((0)))), NewState);
 }
 else
 {
  ((void)0);
  return FAILURE;
 }
 return SUCCESS;
}
# 1511 "../src/kf32a1x6_atim.c"
RetStatus ATIM_X_Cmp_Clear_Tim_Edge_Choose(ATIM_SFRmap* ATIMx, uint8_t Edge)
{
 if(ATIMx == ((ATIM_SFRmap *) ((uint32_t)0x40000300)))
 {
  (((ATIM_SFRmap *) ((uint32_t)0x40000300))->TXCCTCTL) = SFR_Config((((ATIM_SFRmap *) ((uint32_t)0x40000300))->TXCCTCTL), ~(((uint32_t)1<<((1)))), Edge);
 }
 else
 {
  ((void)0);
  return FAILURE;
 }
 return SUCCESS;
}
# 1533 "../src/kf32a1x6_atim.c"
RetStatus ATIM_Z_Cmp_Clear_Tim_Edge_Choose(ATIM_SFRmap* ATIMx, uint8_t Edge)
{

 ((void)0);

 if(ATIMx == ((ATIM_SFRmap *) ((uint32_t)0x40000300)))
 {
  (((ATIM_SFRmap *) ((uint32_t)0x40000300))->TZCCTCTL) = SFR_Config((((ATIM_SFRmap *) ((uint32_t)0x40000300))->TZCCTCTL), ~(((uint32_t)1<<((1)))), Edge);
 }
 else
 {
  ((void)0);
  return FAILURE;
 }
 return SUCCESS;
}
# 1560 "../src/kf32a1x6_atim.c"
RetStatus ATIM_X_Cmp_Clear_Tim_Choose(ATIM_SFRmap* ATIMx, uint8_t Cmpnum)
{

 ((void)0);

 if(ATIMx == ((ATIM_SFRmap *) ((uint32_t)0x40000300)))
 {
  (((ATIM_SFRmap *) ((uint32_t)0x40000300))->TXCCTCTL) = SFR_Config((((ATIM_SFRmap *) ((uint32_t)0x40000300))->TXCCTCTL), ~(((uint32_t)0x03<<((2)))), Cmpnum);
 }
 else
 {
  ((void)0);
  return FAILURE;
 }
 return SUCCESS;
}
# 1587 "../src/kf32a1x6_atim.c"
RetStatus ATIM_Z_Cmp_Clear_Tim_Choose(ATIM_SFRmap* ATIMx, uint8_t Cmpnum)
{

 ((void)0);

 if(ATIMx == ((ATIM_SFRmap *) ((uint32_t)0x40000300)))
 {
  (((ATIM_SFRmap *) ((uint32_t)0x40000300))->TZCCTCTL) = SFR_Config((((ATIM_SFRmap *) ((uint32_t)0x40000300))->TZCCTCTL), ~(((uint32_t)0x03<<((2)))), Cmpnum);
 }
 else
 {
  ((void)0);
  return FAILURE;
 }
 return SUCCESS;
}
# 1620 "../src/kf32a1x6_atim.c"
void ATIM_X_Updata_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((8)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((8)));
    }
}
# 1647 "../src/kf32a1x6_atim.c"
void ATIM_Z_Updata_INT_Enable (ATIM_SFRmap* ATIMx,FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((7)));
    }
}
# 1674 "../src/kf32a1x6_atim.c"
void ATIM_X_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((6)));
    }
}
# 1701 "../src/kf32a1x6_atim.c"
void ATIM_Z_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((5)));
    }
}
# 1728 "../src/kf32a1x6_atim.c"
void ATIM_X_Trigger_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((4)));
    }
}
# 1755 "../src/kf32a1x6_atim.c"
void ATIM_X_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((7)));
    }
}
# 1782 "../src/kf32a1x6_atim.c"
void ATIM_Z_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((6)));
    }
}
# 1809 "../src/kf32a1x6_atim.c"
void ATIM_X_Trigger_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((5)));
    }
}







FlagStatus ATIM_X_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((14))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus ATIM_Z_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((13))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus ATIM_X_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((12))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus ATIM_Z_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((11))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus ATIM_X_Get_Trigger_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((10))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 1955 "../src/kf32a1x6_atim.c"
void ATIM_X_Generate_Trigger_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXEGIF)),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXEGIF)),"i"((5)));
    }
}







FlagStatus ATIM_X_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXDF & ((uint32_t)1<<((7))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus ATIM_Z_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXDF & ((uint32_t)1<<((6))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus ATIM_X_Get_Trigger_DMA_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXDF & ((uint32_t)1<<((5))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 2053 "../src/kf32a1x6_atim.c"
RetStatus ATIM_X_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx)
{
 uint32_t wait_flag = 0x0000;

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((8)));
    while(((ATIMx->ECCPXEGIF & ((uint32_t)1<<((14))))>>(14))&&(wait_flag != (0xFFFF)))
 {
  wait_flag++;
 }
 __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((8)));
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}
# 2080 "../src/kf32a1x6_atim.c"
RetStatus ATIM_Z_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx)
{
 uint32_t wait_flag = 0x0000;

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((7)));
    while(((ATIMx->ECCPXEGIF & ((uint32_t)1<<((13))))>>(13))&&(wait_flag != (0xFFFF)))
 {
  wait_flag++;
 }
    __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((7)));
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}







RetStatus ATIM_X_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx)
{
 uint32_t wait_flag = 0x0000;

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((6)));
    while(((ATIMx->ECCPXEGIF & ((uint32_t)1<<((12))))>>(12))&&(wait_flag != (0xFFFF)))
 {
  wait_flag++;
 }
    __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((6)));
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}







RetStatus ATIM_Z_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx)
{
 uint32_t wait_flag = 0x0000;

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((5)));
    while(((ATIMx->ECCPXEGIF & ((uint32_t)1<<((11))))>>(11))&&(wait_flag != (0xFFFF)))
 {
  wait_flag++;
 }
    __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((5)));
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}







RetStatus ATIM_X_Clear_Trigger_INT_Flag (ATIM_SFRmap* ATIMx)
{
 uint32_t wait_flag = 0x0000;

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((4)));
    while(((ATIMx->ECCPXEGIF & ((uint32_t)1<<((10))))>>(10))&&(wait_flag != (0xFFFF)))
 {
  wait_flag++;
 }
    __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((4)));
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}
# 2205 "../src/kf32a1x6_atim.c"
void ECCP_Compare_Configuration(ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t CompareMode, uint16_t CompareValue)
{
    uint32_t tmpreg;
    uint32_t tmpreg1;


    ((void)0);
    ((void)0);
    ((void)0);



    tmpreg = 4 * Channel;
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << tmpreg),
                          CompareMode << tmpreg);



    tmpreg1 = (uint32_t)ECCPx;
    tmpreg1 = tmpreg1 + ((uint32_t)0x84) + tmpreg;

    *(volatile uint32_t*)tmpreg1 = CompareValue;
}
# 2237 "../src/kf32a1x6_atim.c"
void ECCP_Capture_Configuration (ECCP_SFRmap* ECCPx,ECCP_CaptureInitTypeDef* eccpInitStruct)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);



    tmpreg = 4 * eccpInitStruct->m_Channel;
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << tmpreg),
                          eccpInitStruct->m_Mode << tmpreg);




    tmpreg = (eccpInitStruct->m_PWMInput << (12))
           | (eccpInitStruct->m_XORMode << (11));
    ECCPx->ECCPXCTL2 = SFR_Config (ECCPx->ECCPXCTL2,
                          ~(((uint32_t)1<<((12))) | ((uint32_t)1<<((11)))),
                          tmpreg);
}






void ECCP_Capture_Struct_Init (ECCP_CaptureInitTypeDef* eccpInitStruct)
{

    eccpInitStruct->m_Channel = ((uint32_t)0x0);

    eccpInitStruct->m_Mode = ((uint32_t)0x0);

    eccpInitStruct->m_PWMInput = FALSE;

    eccpInitStruct->m_XORMode = FALSE;
}
# 2289 "../src/kf32a1x6_atim.c"
void ECCP_PWM_Configuration (ECCP_SFRmap* ECCPx,ECCP_PWMInitTypeDef* eccpInitStruct)
{
    uint32_t tmpreg;
    uint32_t tmpreg1;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);



    tmpreg = 4 * eccpInitStruct->m_Channel;
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << tmpreg),
                          eccpInitStruct->m_Mode << tmpreg);



    tmpreg1 = (uint32_t)ECCPx;
    tmpreg1 = tmpreg1 + ((uint32_t)0x84) + tmpreg;

    *(volatile uint32_t*)tmpreg1
        = (uint32_t)eccpInitStruct->m_DutyRatio;



    ECCPx->PXUDCTL = SFR_Config (ECCPx->PXUDCTL,
                        ~((uint32_t)1<<((6))),
                        eccpInitStruct->m_PhaseMove);



    if (((uint32_t)0x3) == eccpInitStruct->m_Channel)
    {
        tmpreg = ((uint32_t)eccpInitStruct->m_DeadTime
                    << (8));
        ECCPx->PXDTCTL = SFR_Config (ECCPx->PXDTCTL,
                            ~((uint32_t)0xFF<<((8))),
                            tmpreg);
    }
    else
    {
        tmpreg = ((uint32_t)eccpInitStruct->m_DeadTime
                    << (0));
        ECCPx->PXDTCTL = SFR_Config (ECCPx->PXDTCTL,
                            ~((uint32_t)0xFF<<((0))),
                            tmpreg);
    }



    tmpreg = eccpInitStruct->m_Channel;
    ECCPx->PXATRCTL = SFR_Config (ECCPx->PXATRCTL,
                          ~(((uint32_t)1<<((8))) << tmpreg),
                          (uint32_t)eccpInitStruct->m_OutputMode << tmpreg);




    tmpreg = 4 * eccpInitStruct->m_Channel;
    tmpreg1 = ((uint32_t)eccpInitStruct->m_HOutputCtl << (2))
            | ((uint32_t)eccpInitStruct->m_LOutputCtl << (0));
    ECCPx->PWMXOC = SFR_Config (ECCPx->PWMXOC,
                          ~((((uint32_t)3<<((0))) | ((uint32_t)3<<((2))))
                            << tmpreg),
                          tmpreg1 << tmpreg);



    tmpreg = (eccpInitStruct->m_SinglePWM << (10));
    ECCPx->ECCPXCTL2 = SFR_Config (ECCPx->ECCPXCTL2,
                          ~(((uint32_t)1<<((10)))),
                          tmpreg);



    tmpreg = (eccpInitStruct->m_CloseTimer << (0));
    ECCPx->ECCPXCTL3 = SFR_Config (ECCPx->ECCPXCTL3,
                          ~((uint32_t)1<<((0))),
                          tmpreg);
}






void ECCP_PWM_Struct_Init (ECCP_PWMInitTypeDef* eccpInitStruct)
{

    eccpInitStruct->m_Channel = ((uint32_t)0x0);

    eccpInitStruct->m_Mode = ((uint32_t)0x0);

    eccpInitStruct->m_DutyRatio = 0x0000;

    eccpInitStruct->m_DeadTime = 0x00;

    eccpInitStruct->m_OutputMode = ((uint8_t)0x0);

    eccpInitStruct->m_HOutputCtl = ((uint16_t)0x0);

    eccpInitStruct->m_LOutputCtl = ((uint16_t)0x0);

    eccpInitStruct->m_PhaseMove = FALSE;

    eccpInitStruct->m_SinglePWM = FALSE;

    eccpInitStruct->m_CloseTimer = FALSE;
}
# 2424 "../src/kf32a1x6_atim.c"
void ECCP_Capture_Mode_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t EdgeConfig)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = EdgeConfig << (Channel * 4);
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << (4 * Channel)),
                          tmpreg);
}
# 2458 "../src/kf32a1x6_atim.c"
void ECCP_Compare_Mode_Config (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t CmpConfig)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = CmpConfig << (4 * Channel);
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << (4 * Channel)),
                          tmpreg);
}
# 2485 "../src/kf32a1x6_atim.c"
void ECCP_PWM_Mode_Config (ECCP_SFRmap* ECCPx, uint32_t PWMConfig)
{
 uint32_t tmpreg;

    ((void)0);
    ((void)0);


    tmpreg = PWMConfig << (0);
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,~((uint32_t)0xF<<((0))),tmpreg);
}
# 2508 "../src/kf32a1x6_atim.c"
uint16_t ECCP_Get_Capture_Result (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)ECCPx;
    tmpreg = tmpreg + ((uint32_t)0xD0) + (4 * Channel);


    return (*(volatile const uint16_t*) tmpreg);
}
# 2536 "../src/kf32a1x6_atim.c"
 uint16_t ECCP_Get_Compare_Result (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg;


      ((void)0);
      ((void)0);



    tmpreg = (uint32_t)ECCPx;
    tmpreg = tmpreg + ((uint32_t)0x84) + (4 * Channel);


    return (*(volatile const uint16_t*) tmpreg);
}
# 2565 "../src/kf32a1x6_atim.c"
void ECCP_Set_Compare_Result (ECCP_SFRmap* ECCPx, uint32_t Channel, uint16_t Value)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)ECCPx;
    tmpreg = tmpreg + ((uint32_t)0x84) + (4 * Channel);


    *(volatile uint32_t*)tmpreg = (uint16_t)Value;
}
# 2594 "../src/kf32a1x6_atim.c"
void ECCP_Generate_Trigger_Config (ECCP_SFRmap* ECCPx, uint32_t Channel,FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        ECCPx->ECCPXEGIF |= ((uint32_t)1<<((1))) << Channel;
    }
    else
    {

        ECCPx->ECCPXEGIF &= ~(((uint32_t)1<<((1))) << Channel);
    }
}
# 2622 "../src/kf32a1x6_atim.c"
void ECCP_PWM_Input_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((12)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((12)));
    }
}
# 2649 "../src/kf32a1x6_atim.c"
void ECCP_Input_XOR_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((11)));
    }
}
# 2676 "../src/kf32a1x6_atim.c"
void ECCP_Single_Pulse_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((10)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((10)));
    }
}
# 2703 "../src/kf32a1x6_atim.c"
void ECCP_Single_Pulse_Shut_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL3)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL3)),"i"((0)));
    }
}
# 2730 "../src/kf32a1x6_atim.c"
void ECCP_PWM_Restart_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL3)),"i"((2)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL3)),"i"((2)));
    }
}
# 2761 "../src/kf32a1x6_atim.c"
void ECCP_Dead_Time_Config (ECCP_SFRmap* ECCPx, uint32_t Channel,uint8_t DeadTime)
{
    uint32_t tmpreg;

    ((void)0);
    ((void)0);


    if (((uint32_t)0x3) == Channel)
    {

        tmpreg = (uint32_t)DeadTime << (8);
        ECCPx->PXDTCTL = SFR_Config (ECCPx->PXDTCTL,
                             ~((uint32_t)0xFF<<((8))),
                             tmpreg);
    }
    else
    {

        tmpreg = (uint32_t)DeadTime << (0);
        ECCPx->PXDTCTL = SFR_Config (ECCPx->PXDTCTL,
                             ~((uint32_t)0xFF<<((0))),
                             tmpreg);
    }
}
# 2806 "../src/kf32a1x6_atim.c"
void ECCP_Channel_Output_Control (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t Port, uint32_t ChannelOutputCtl)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ChannelOutputCtl << (Port + Channel * 4);
    ECCPx->PWMXOC = SFR_Config (ECCPx->PWMXOC,
                          ~(((uint32_t)3<<((0))) << (Port + Channel * 4)),
                          tmpreg);
}
# 2837 "../src/kf32a1x6_atim.c"
void ECCP_Channel_Output_Mode (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t ChannelOutputMode)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ChannelOutputMode << ((8) + Channel);
    ECCPx->PXATRCTL = SFR_Config (ECCPx->PXATRCTL,
                          ~(((uint32_t)1<<((8))) << Channel),
                          tmpreg);
}
# 2867 "../src/kf32a1x6_atim.c"
void ECCP_Channel_Work_State_Config (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t WorkingState)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = WorkingState << ((8) + Channel);
    ECCPx->PXASCTL0 = SFR_Config (ECCPx->PXASCTL0,
                          ~(((uint32_t)1<<((8))) << Channel),
                          tmpreg);
}
# 2894 "../src/kf32a1x6_atim.c"
FlagStatus ECCP_Get_Channel_Work_State (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((8))) << Channel;
    if (ECCPx->PXASCTL0 & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 2925 "../src/kf32a1x6_atim.c"
void ECCP_TZ_Showdown_SEL(ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);

    if(ShutDownSignal != ((uint32_t)0))
    {
     __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->PXASCTL)),"i"((5)));
    }
    else
    {
     __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->PXASCTL)),"i"((5)));
    }
}
# 2952 "../src/kf32a1x6_atim.c"
void ECCP_TX_Showdown_SEL(ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);

    if(ShutDownSignal != ((uint32_t)0))
    {
     __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->PXASCTL)),"i"((4)));
    }
    else
    {
     __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->PXASCTL)),"i"((4)));
    }
}
# 2981 "../src/kf32a1x6_atim.c"
void ECCP_CHANNEL4_Shutdown_SEL (ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = ShutDownSignal << (2);
    ECCPx->PXASCTL = SFR_Config(ECCPx->PXASCTL, ~((uint32_t)0x03<<((2))), tmpreg);
}
# 3005 "../src/kf32a1x6_atim.c"
void ECCP_CHANNEL123_Shutdown_SEL (ECCP_SFRmap* ECCPx,uint32_t ShutDownSignal)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = ShutDownSignal << (0);
    ECCPx->PXASCTL = SFR_Config(ECCPx->PXASCTL, ~((uint32_t)0x03<<((0))), tmpreg);
}
# 3036 "../src/kf32a1x6_atim.c"
void ECCP_Channel_Shutdown_Signal (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t ShutDownSignal)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ShutDownSignal << (Channel * 2);
    ECCPx->PXASCTL0 = SFR_Config (ECCPx->PXASCTL0,
                          ~(((uint32_t)3<<((0))) << (Channel * 2)),
                          tmpreg);
}
# 3070 "../src/kf32a1x6_atim.c"
void ECCP_Channel_Pin_Ctl (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t Port, uint32_t ChannelPinCtl)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ChannelPinCtl << (Port + Channel * 4);
    ECCPx->PXASCTL1 = SFR_Config (ECCPx->PXASCTL1,
                          ~(((uint32_t)3<<((0))) << (Port + Channel * 2)),
                          tmpreg);
}
# 3104 "../src/kf32a1x6_atim.c"
void ECCP_Zero_Clock_Config (ECCP_SFRmap* ECCPx,uint32_t ZeroClock)
{

    ((void)0);
    ((void)0);


    ECCPx->ZPDCTL0 = SFR_Config (ECCPx->ZPDCTL0,
                          ~(((uint32_t)0xF<<((8)))),
                          ZeroClock);
}
# 3134 "../src/kf32a1x6_atim.c"
void ECCP_Channel_Pin_Tristate_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t Port, uint32_t PinTristateCtl)
{
    uint32_t tmpreg;
    uint32_t tmpreg1;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = (Port / 2) + (Channel * 2);
    tmpreg1 = PinTristateCtl << tmpreg;
    ECCPx->ZPDPORT = SFR_Config (ECCPx->ZPDPORT,
                          ~(((uint32_t)0xFF<<((0))) << tmpreg),
                          tmpreg1);
}
# 3164 "../src/kf32a1x6_atim.c"
void ECCP_FlexMUX_CHANNEL_SEL (ECCP_SFRmap* ECCPx,uint32_t FlexMUXSignal)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = FlexMUXSignal << (13);
    ECCPx->ECCPXCTL3 = SFR_Config(ECCPx->ECCPXCTL3, ~((uint32_t)0x03<<((13))), tmpreg);
}
# 3191 "../src/kf32a1x6_atim.c"
void ECCP_Channel_Modulation_SEL (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t ChannelState)
{
    uint32_t tmpreg;
    uint32_t mask;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ChannelState << ((9) + Channel);
    mask = 0x01 << ((9) + Channel);
    ECCPx->ECCPXCTL3 = SFR_Config(ECCPx->ECCPXCTL3, ~mask, tmpreg);
}
# 3214 "../src/kf32a1x6_atim.c"
void ECCP_GTB_OUTPUT_Config (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = NewState << (8);
    ECCPx->ECCPXCTL3 = SFR_Config(ECCPx->ECCPXCTL3, ~((uint32_t)1<<((8))), tmpreg);
}
# 3234 "../src/kf32a1x6_atim.c"
void ECCP_GTB_MODE_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = NewState << (7);
    ECCPx->ECCPXCTL3 = SFR_Config(ECCPx->ECCPXCTL3, ~((uint32_t)1<<((7))), tmpreg);
}
# 3256 "../src/kf32a1x6_atim.c"
void ECCP_CAPTEST_MODE_Config(ECCP_SFRmap* ECCPx, uint32_t CAPTEST)
{
 uint32_t tmpreg;


    ((void)0);
 ((void)0);


    tmpreg = CAPTEST << (6);
    ECCPx->ECCPXCTL3 = SFR_Config(ECCPx->ECCPXCTL3, ~((uint32_t)1<<((6))), tmpreg);
}
# 3280 "../src/kf32a1x6_atim.c"
void ECCP_UNION_SINGEL_EFFECTIVE_Config(ECCP_SFRmap* ECCPx,uint32_t UnionOutputSingel)
{
 uint32_t tmpreg;


    ((void)0);
 ((void)0);


 tmpreg = UnionOutputSingel << (4);
    ECCPx->ECCPXCTL3 = SFR_Config(ECCPx->ECCPXCTL3, ~((uint32_t)0x03<<((4))), tmpreg);
}
# 3300 "../src/kf32a1x6_atim.c"
void ECCP_UNION_SINGEL_OUTPUT_Enable(ECCP_SFRmap* ECCPx,FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
 ((void)0);


 tmpreg = NewState << (3);
    ECCPx->ECCPXCTL3 = SFR_Config(ECCPx->ECCPXCTL3, ~((uint32_t)1<<((3))), tmpreg);
}
# 3325 "../src/kf32a1x6_atim.c"
void ECCP_COMH_Value_Config(ECCP_SFRmap* ECCPx,uint32_t Channel, uint16_t COMHValue)
{

    ((void)0);
    ((void)0);
    ((void)0);


    switch (Channel)
    {
    case ((uint32_t)0x0):
     ECCPx->COMH1 = SFR_Config(ECCPx->COMH1, ~((uint32_t)0xFFFF<<((0))), COMHValue);
     break;
    case ((uint32_t)0x1):
     ECCPx->COMH2 = SFR_Config(ECCPx->COMH2, ~((uint32_t)0xFFFF<<((0))), COMHValue);
     break;
    case ((uint32_t)0x2):
     ECCPx->COMH3 = SFR_Config(ECCPx->COMH3, ~((uint32_t)0xFFFF<<((0))), COMHValue);
     break;
    case ((uint32_t)0x3):
     ECCPx->COMH4 = SFR_Config(ECCPx->COMH4, ~((uint32_t)0xFFFF<<((0))), COMHValue);
     break;
    default:break;
    }
}
# 3363 "../src/kf32a1x6_atim.c"
void ECCP_COML_Value_Config(ECCP_SFRmap* ECCPx,uint32_t Channel, uint16_t COMLValue)
{

    ((void)0);
    ((void)0);
    ((void)0);


    switch (Channel)
    {
    case ((uint32_t)0x0):
     ECCPx->COML1 = SFR_Config(ECCPx->COMH1, ~((uint32_t)0xFFFF<<((0))), COMLValue);
     break;
    case ((uint32_t)0x1):
     ECCPx->COML2 = SFR_Config(ECCPx->COML2, ~((uint32_t)0xFFFF<<((0))), COMLValue);
     break;
    case ((uint32_t)0x2):
     ECCPx->COML3 = SFR_Config(ECCPx->COML3, ~((uint32_t)0xFFFF<<((0))), COMLValue);
     break;
    case ((uint32_t)0x3):
     ECCPx->COML4 = SFR_Config(ECCPx->COML4, ~((uint32_t)0xFFFF<<((0))), COMLValue);
     break;
    default:break;
    }
}
# 3403 "../src/kf32a1x6_atim.c"
void ECCP_Fault_Contral_Enable (ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = NewState << (14);
    switch (Channel)
    {
    case ((uint32_t)0x0):
     ECCPx->FAUCTL1 = SFR_Config(ECCPx->FAUCTL1, ~((uint32_t)1<<((14))), tmpreg);
     break;
    case ((uint32_t)0x1):
     ECCPx->FAUCTL2 = SFR_Config(ECCPx->FAUCTL2, ~((uint32_t)1<<((14))), tmpreg);
     break;
    case ((uint32_t)0x2):
     ECCPx->FAUCTL3 = SFR_Config(ECCPx->FAUCTL3, ~((uint32_t)1<<((14))), tmpreg);
     break;
    case ((uint32_t)0x3):
     ECCPx->FAUCTL4 = SFR_Config(ECCPx->FAUCTL4, ~((uint32_t)1<<((14))), tmpreg);
     break;
    default:break;
    }
}
# 3448 "../src/kf32a1x6_atim.c"
void ECCP_Fault_Output_Polarity_Select (ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t OutPolarity)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = OutPolarity << (12);
    switch (Channel)
    {
    case ((uint32_t)0x0):
     ECCPx->FAUCTL1 = SFR_Config(ECCPx->FAUCTL1, ~((uint32_t)0x03<<((12))), tmpreg);
     break;
    case ((uint32_t)0x1):
     ECCPx->FAUCTL2 = SFR_Config(ECCPx->FAUCTL2, ~((uint32_t)0x03<<((12))), tmpreg);
     break;
    case ((uint32_t)0x2):
     ECCPx->FAUCTL3 = SFR_Config(ECCPx->FAUCTL3, ~((uint32_t)0x03<<((12))), tmpreg);
     break;
    case ((uint32_t)0x3):
     ECCPx->FAUCTL4 = SFR_Config(ECCPx->FAUCTL4, ~((uint32_t)0x03<<((12))), tmpreg);
     break;
    default:break;
    }
}
# 3493 "../src/kf32a1x6_atim.c"
void ECCP_Filter_PulseWidth_Config(ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t PulseWidth)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = PulseWidth << (9);
    switch (Channel)
    {
    case ((uint32_t)0x0):
     ECCPx->FAUCTL1 = SFR_Config(ECCPx->FAUCTL1, ~((uint32_t)0x07<<((9))), tmpreg);
     break;
    case ((uint32_t)0x1):
     ECCPx->FAUCTL2 = SFR_Config(ECCPx->FAUCTL2, ~((uint32_t)0x07<<((9))), tmpreg);
     break;
    case ((uint32_t)0x2):
     ECCPx->FAUCTL3 = SFR_Config(ECCPx->FAUCTL3, ~((uint32_t)0x07<<((9))), tmpreg);
     break;
    case ((uint32_t)0x3):
     ECCPx->FAUCTL4 = SFR_Config(ECCPx->FAUCTL4, ~((uint32_t)0x07<<((9))), tmpreg);
     break;
    default:break;
    }
}
# 3536 "../src/kf32a1x6_atim.c"
void ECCP_Filter_Function_Enable(ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = NewState << (5);
    switch (Channel)
    {
    case ((uint32_t)0x0):
     ECCPx->FAUCTL1 = SFR_Config(ECCPx->FAUCTL1, ~((uint32_t)1<<((5))), tmpreg);
     break;
    case ((uint32_t)0x1):
     ECCPx->FAUCTL2 = SFR_Config(ECCPx->FAUCTL2, ~((uint32_t)1<<((5))), tmpreg);
     break;
    case ((uint32_t)0x2):
     ECCPx->FAUCTL3 = SFR_Config(ECCPx->FAUCTL3, ~((uint32_t)1<<((5))), tmpreg);
     break;
    case ((uint32_t)0x3):
     ECCPx->FAUCTL4 = SFR_Config(ECCPx->FAUCTL4, ~((uint32_t)1<<((5))), tmpreg);
     break;
    default:break;
    }
}
# 3583 "../src/kf32a1x6_atim.c"
void ECCP_Filter_CLKDIV_Config(ECCP_SFRmap* ECCPx,uint32_t Channel, uint32_t ClkDiv)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ClkDiv << ((uint32_t)1<<((1)));
    switch (Channel)
    {
    case ((uint32_t)0x0):
     ECCPx->FAUCTL1 = SFR_Config(ECCPx->FAUCTL1, ~((uint32_t)0x0F<<((1))), tmpreg);
     break;
    case ((uint32_t)0x1):
     ECCPx->FAUCTL2 = SFR_Config(ECCPx->FAUCTL2, ~((uint32_t)0x0F<<((1))), tmpreg);
     break;
    case ((uint32_t)0x2):
     ECCPx->FAUCTL3 = SFR_Config(ECCPx->FAUCTL3, ~((uint32_t)0x0F<<((1))), tmpreg);
     break;
    case ((uint32_t)0x3):
     ECCPx->FAUCTL4 = SFR_Config(ECCPx->FAUCTL4, ~((uint32_t)0x0F<<((1))), tmpreg);
     break;
    default:break;
    }
}
# 3626 "../src/kf32a1x6_atim.c"
void ECCP_Fault_Function_Enable(ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState)
{
 uint32_t tmpreg;

    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = NewState << (0);
    switch (Channel)
    {
    case ((uint32_t)0x0):
     ECCPx->FAUCTL1 = SFR_Config(ECCPx->FAUCTL1, ~((uint32_t)1<<((0))), tmpreg);
     break;
    case ((uint32_t)0x1):
     ECCPx->FAUCTL2 = SFR_Config(ECCPx->FAUCTL2, ~((uint32_t)1<<((0))), tmpreg);
     break;
    case ((uint32_t)0x2):
     ECCPx->FAUCTL3 = SFR_Config(ECCPx->FAUCTL3, ~((uint32_t)1<<((0))), tmpreg);
     break;
    case ((uint32_t)0x3):
     ECCPx->FAUCTL4 = SFR_Config(ECCPx->FAUCTL4, ~((uint32_t)1<<((0))), tmpreg);
     break;
    default:break;
    }
}
# 3665 "../src/kf32a1x6_atim.c"
FlagStatus ECCP_Get_Fault_INT_Flag(ECCP_SFRmap* ECCPx,uint32_t Channel)
{
    ((void)0);
    ((void)0);

    switch (Channel)
    {
    case ((uint32_t)0x0):
     return ((ECCPx->FAUCTL1 & ((uint32_t)1<<((8)))) >> (8));
     break;
    case ((uint32_t)0x1):
     return ((ECCPx->FAUCTL2 & ((uint32_t)1<<((8)))) >> (8));
     break;
    case ((uint32_t)0x2):
     return ((ECCPx->FAUCTL3 & ((uint32_t)1<<((8)))) >> (8));
     break;
    case ((uint32_t)0x3):
     return ((ECCPx->FAUCTL4 & ((uint32_t)1<<((8)))) >> (8));
     break;
    default:break;
    }
}
# 3699 "../src/kf32a1x6_atim.c"
RetStatus ECCP_Clear_Fault_INT_Flag(ECCP_SFRmap* ECCPx,uint32_t Channel)
{
 uint32_t wait_flag=0x0000;
    ((void)0);
    ((void)0);

    switch (Channel)
    {
    case ((uint32_t)0x0):
     __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->FAUCTL1)),"i"((7)));
     while(((ECCPx->FAUCTL1 & ((uint32_t)1<<((8)))))&& (wait_flag != (0xFFFF)))
  {
   wait_flag++;
  }
     __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->FAUCTL1)),"i"((7)));
     break;
    case ((uint32_t)0x1):
     __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->FAUCTL2)),"i"((7)));
     while(((ECCPx->FAUCTL2 & ((uint32_t)1<<((8)))))&& (wait_flag != (0xFFFF)))
  {
   wait_flag++;
  }
     __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->FAUCTL2)),"i"((7)));
     break;
    case ((uint32_t)0x2):
     __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->FAUCTL3)),"i"((7)));
     while(((ECCPx->FAUCTL3 & ((uint32_t)1<<((8)))))&& (wait_flag != (0xFFFF)))
  {
   wait_flag++;
  }
     __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->FAUCTL3)),"i"((7)));
     break;
    case ((uint32_t)0x3):
     __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->FAUCTL4)),"i"((7)));
     while(((ECCPx->FAUCTL4 & ((uint32_t)1<<((8)))))&& (wait_flag != (0xFFFF)))
  {
   wait_flag++;
  }
     __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->FAUCTL4)),"i"((7)));
     break;
    default:break;
    }
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}
# 3762 "../src/kf32a1x6_atim.c"
void ECCP_Fault_INT_Enable(ECCP_SFRmap* ECCPx,uint32_t Channel, FunctionalState NewState)
{
 uint32_t tmpreg;

    ((void)0);
    ((void)0);
    ((void)0);

    tmpreg = NewState << (6);
    switch (Channel)
    {
    case ((uint32_t)0x0):
     ECCPx->FAUCTL1 = SFR_Config(ECCPx->FAUCTL1, ~((uint32_t)1<<((6))), tmpreg);
     break;
    case ((uint32_t)0x1):
     ECCPx->FAUCTL2 = SFR_Config(ECCPx->FAUCTL2, ~((uint32_t)1<<((6))), tmpreg);
     break;
    case ((uint32_t)0x2):
     ECCPx->FAUCTL3 = SFR_Config(ECCPx->FAUCTL3, ~((uint32_t)1<<((6))), tmpreg);
     break;
    case ((uint32_t)0x3):
     ECCPx->FAUCTL4 = SFR_Config(ECCPx->FAUCTL4, ~((uint32_t)1<<((6))), tmpreg);
     break;
    default:break;
    }
}
# 3798 "../src/kf32a1x6_atim.c"
void ECCP_UNION_jitter_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = NewState << (7);
    ECCPx->DITCTL = SFR_Config(ECCPx->DITCTL, ~((uint32_t)1<<((7))), tmpreg);
}
# 3820 "../src/kf32a1x6_atim.c"
void ECCP_CYCLE_jitter_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = NewState << (6);
    ECCPx->DITCTL = SFR_Config(ECCPx->DITCTL, ~((uint32_t)1<<((6))), tmpreg);
}
# 3842 "../src/kf32a1x6_atim.c"
void ECCP_EDGE_jitter_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = NewState << (5);
    ECCPx->DITCTL = SFR_Config(ECCPx->DITCTL, ~((uint32_t)1<<((5))), tmpreg);
}
# 3862 "../src/kf32a1x6_atim.c"
void ECCP_FRCVAL_Value_Config(ECCP_SFRmap* ECCPx, uint8_t Value)
{

    ((void)0);
    ((void)0);


    ECCPx->DITCTL = SFR_Config(ECCPx->DITCTL, ~((uint32_t)0x1F<<((0))), Value);
}
# 3880 "../src/kf32a1x6_atim.c"
void ECCP_Tz_Triggle_AD_Driction_SEL(ECCP_SFRmap* ECCPx, FunctionalState Direction)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = Direction << (5);
    ECCPx->CCRCTL = SFR_Config(ECCPx->CCRCTL, ~((uint32_t)1<<((5))), tmpreg);
}
# 3904 "../src/kf32a1x6_atim.c"
void ECCP_Tx_Triggle_AD_Driction_SEL(ECCP_SFRmap* ECCPx,uint8_t CCRx, FunctionalState Direction)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    if(CCRx == ((uint32_t)0))
    {
  tmpreg = Direction << (3);
  ECCPx->CCRCTL = SFR_Config(ECCPx->CCRCTL, ~((uint32_t)1<<((3))), tmpreg);
    }
    else
    {
  tmpreg = Direction << (4);
  ECCPx->CCRCTL = SFR_Config(ECCPx->CCRCTL, ~((uint32_t)1<<((4))), tmpreg);
    }
}
# 3935 "../src/kf32a1x6_atim.c"
void ECCP_Tz_Triggle_AD_Driction_Enable(ECCP_SFRmap* ECCPx, FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = NewState << (2);
    ECCPx->CCRCTL = SFR_Config(ECCPx->CCRCTL, ~((uint32_t)1<<((2))), tmpreg);
}
# 3960 "../src/kf32a1x6_atim.c"
void ECCP_Tx_Triggle_AD_Driction_Enable(ECCP_SFRmap* ECCPx,uint8_t CCRx, FunctionalState NewState)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    if(CCRx == ((uint32_t)0))
    {
  tmpreg = NewState << (0);
  ECCPx->CCRCTL = SFR_Config(ECCPx->CCRCTL, ~((uint32_t)1<<((0))), tmpreg);
    }
    else
    {
  tmpreg = NewState << (1);
  ECCPx->CCRCTL = SFR_Config(ECCPx->CCRCTL, ~((uint32_t)1<<((1))), tmpreg);
    }
}
# 4004 "../src/kf32a1x6_atim.c"
void ECCP_Channel_INT_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel,FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        ECCPx->ECCPXIE |= ((uint32_t)1<<((0))) << Channel;
    }
    else
    {

        ECCPx->ECCPXIE &= ~(((uint32_t)1<<((0))) << Channel);
    }
}
# 4032 "../src/kf32a1x6_atim.c"
void ECCP_X_Turn_off_DMA_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXDE)),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXDE)),"i"((4)));
    }
}
# 4064 "../src/kf32a1x6_atim.c"
void ECCP_Channel_DMA_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel,FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        ECCPx->ECCPXDE |= (((uint32_t)1<<((0))) << Channel);
    }
    else
    {

        ECCPx->ECCPXDE &= (~(((uint32_t)1<<((0))) << Channel));
    }
}
# 4095 "../src/kf32a1x6_atim.c"
FlagStatus ECCP_Get_Channel_Trigger_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg;


    ((void)0);


    tmpreg = ((uint32_t)1<<((6))) << Channel;
    if (ECCPx->ECCPXEGIF & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus ECCP_X_Get_Turn_off_DMA_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXDF & ((uint32_t)1<<((4))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 4151 "../src/kf32a1x6_atim.c"
FlagStatus ECCP_Get_Trigger_DMA_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg;


    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Channel;
    if (ECCPx->ECCPXDF & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 4183 "../src/kf32a1x6_atim.c"
RetStatus ECCP_Clear_Channel_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg;
    uint32_t tmpreg1;
 uint32_t wait_flag=0x0000;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Channel;
    tmpreg1 = ((uint32_t)1<<((6))) << Channel;
    ECCPx->ECCPXSRIC |= tmpreg;

    while(((ECCPx->ECCPXEGIF & tmpreg1)>>((6)+Channel))&& (wait_flag != (0xFFFF)))
 {
  wait_flag++;
 }
    ECCPx->ECCPXSRIC &= ~tmpreg;
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}
# 4218 "../src/kf32a1x6_atim.c"
void ECCP_PWM_Move_Phase_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->PXUDCTL)),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->PXUDCTL)),"i"((6)));
    }
}
# 4250 "../src/kf32a1x6_atim.c"
void ECCP_Channel_Zero_Detect_Sequential_Ctl (ECCP_SFRmap* ECCPx, uint32_t Channel,FunctionalState NewState)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = NewState << (Channel + (4));
    ECCPx->ZPDCTL0 = SFR_Config (ECCPx->ZPDCTL0,
                          ~(((uint32_t)1<<((4))) << Channel),
                          tmpreg);
}
# 4279 "../src/kf32a1x6_atim.c"
FlagStatus ECCP_Get_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,uint32_t Channel)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Channel;
    if (ECCPx->ZPDCTL0 & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 4312 "../src/kf32a1x6_atim.c"
void ECCP_Clear_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,uint32_t Channel)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Channel;
    ECCPx->ZPDCTL0 &= ~tmpreg;
}
# 4338 "../src/kf32a1x6_atim.c"
void
ECCP_Channel_Zero_Detect_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel,FunctionalState NewState)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = NewState << (Channel + (12));
    ECCPx->ZPDCTL1 = SFR_Config (ECCPx->ZPDCTL1,
                          ~(((uint32_t)1<<((12))) << Channel),
                          tmpreg);
}
# 4372 "../src/kf32a1x6_atim.c"
void ECCP_Channel_Zero_Voltage_Config (ECCP_SFRmap* ECCPx, uint32_t Channel,uint32_t ZeroDetectVoltage)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ZeroDetectVoltage
             << (Channel * 3 + (0));
    ECCPx->ZPDCTL1 = SFR_Config (ECCPx->ZPDCTL1,
                          ~(((uint32_t)7<<((0))) << (Channel * 3)),
                          tmpreg);
}
