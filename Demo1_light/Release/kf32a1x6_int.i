# 1 "../src/kf32a1x6_int.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\Release//"
# 1 "<command-line>"
# 1 "../src/kf32a1x6_int.c"
# 36 "../src/kf32a1x6_int.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_int.h" 1
# 28 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_int.h"
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
# 29 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_int.h" 2




typedef struct
{
    uint32_t m_Line;

    FunctionalState m_Mask;

    FunctionalState m_Rise;

    FunctionalState m_Fall;

    uint32_t m_Source;

} EINT_InitTypeDef;
# 143 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_int.h"
uint8_t INT_Get_Interrupt_Action (void);
uint8_t INT_Get_Priority_Pending_Action (void);
void INT_Priority_Base (uint8_t PriBase);
uint8_t INT_Get_Priority_Base (void);
void INT_Stack_Align_Config (uint32_t StackAlign);
void INT_Fault_Masking_Config (FunctionalState NewState);
FlagStatus INT_Get_Pre_Empty (void);
FlagStatus INT_Get_Pending_Flag (void);
void INT_Priority_Group_Config (uint32_t PriorityGroup);
uint32_t INT_Get_Priority_Group (void);
void INT_All_Enable (FunctionalState NewState);
void INT_Interrupt_Enable (InterruptIndex Peripheral, FunctionalState NewState);
void INT_Set_Systick_Flag (void);
void INT_Set_SOFTSV_Flag (void);
FlagStatus INT_Get_Interrupt_Flag (InterruptIndex Peripheral);
void INT_Clear_Interrupt_Flag (InterruptIndex Peripheral);
void INT_Interrupt_Priority_Config (InterruptIndex Peripheral, uint32_t Preemption, uint32_t SubPriority);
void INT_Stack_Delay_Enable (uint8_t IntDelay);
void INT_External_Configuration (EINT_InitTypeDef* eintInitStruct);
void INT_External_Struct_Init (EINT_InitTypeDef* eintInitStruct);
void INT_External_Mask_Enable (uint32_t EintMask, FunctionalState NewState);
void INT_External_Rise_Enable (uint32_t EintMask, FunctionalState NewState);
void INT_External_Fall_Enable (uint32_t EintMask, FunctionalState NewState);
FlagStatus INT_Get_External_Flag (uint32_t EintNum);
RetStatus INT_External_Clear_Flag (uint32_t EintNum);
void INT_External_Source_Enable (uint32_t EintNum, uint32_t PeripheralSource);
# 37 "../src/kf32a1x6_int.c" 2
# 46 "../src/kf32a1x6_int.c"
uint8_t INT_Get_Interrupt_Action (void)
{
    uint32_t tmpreg;


    tmpreg = ((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0) & ((uint32_t)0x7F<<((24)))) >> (24);

    return (uint8_t)tmpreg;
}






uint8_t INT_Get_Priority_Pending_Action (void)
{
    uint32_t tmpreg;


    tmpreg = ((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0) & ((uint32_t)0x7F<<((16)))) >> (16);

    return (uint8_t)tmpreg;
}






void INT_Priority_Base (uint8_t PriBase)
{
    uint32_t tmpreg;

    ((void)0);



    tmpreg = (uint32_t)PriBase << (12);
    (((INT_SFRmap *)((uint32_t)0x40200000))->CTL0) = SFR_Config((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0), ~((uint32_t)0xF<<((12))), tmpreg);
}






uint8_t INT_Get_Priority_Base (void)
{
    uint32_t tmpreg;


    tmpreg = ((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0) & ((uint32_t)0xF<<((12)))) >> (12);

    return (uint8_t)tmpreg;
}
# 111 "../src/kf32a1x6_int.c"
void INT_Stack_Align_Config (uint32_t StackAlign)
{
    ((void)0);


    if (StackAlign != ((uint32_t)0<<((7))))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0))),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0))),"i"((7)));
    }
}







void INT_Fault_Masking_Config (FunctionalState NewState)
{
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0))),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0))),"i"((6)));
    }
}






FlagStatus INT_Get_Pre_Empty (void)
{

    if ((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0) & ((uint32_t)1<<((5))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus INT_Get_Pending_Flag (void)
{

    if ((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0) & ((uint32_t)1<<((4))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 201 "../src/kf32a1x6_int.c"
void INT_Priority_Group_Config (uint32_t PriorityGroup)
{

    ((void)0);



    (((INT_SFRmap *)((uint32_t)0x40200000))->CTL0) = SFR_Config ((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0), ~((uint32_t)3<<((1))), PriorityGroup);
}






uint32_t INT_Get_Priority_Group (void)
{
    uint32_t tmpreg;


    tmpreg = ((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0) & ((uint32_t)3<<((1)))) >> (1);

    return tmpreg;
}







void INT_All_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0))),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((INT_SFRmap *)((uint32_t)0x40200000))->CTL0))),"i"((0)));
    }
}
# 259 "../src/kf32a1x6_int.c"
void INT_Interrupt_Enable (InterruptIndex Peripheral, FunctionalState NewState)
{
 uint32_t tmask = 0x00;
 uint32_t tmpreg = 0x00;


    ((void)0);
    ((void)0);

    if(Peripheral <= INT_SysTick)
    {

     tmask = ((uint32_t)1 << Peripheral);
     tmpreg = ((uint32_t)NewState << Peripheral);
     (((INT_SFRmap *)((uint32_t)0x40200000))->EIE0) = SFR_Config((((INT_SFRmap *)((uint32_t)0x40200000))->EIE0), ~tmask, tmpreg);
    }
    else if(Peripheral <= INT_SPI1)
    {

     tmask = ((uint32_t)1 << (Peripheral - INT_WWDT));
     tmpreg = ((uint32_t)NewState << (Peripheral - INT_WWDT));
     (((INT_SFRmap *)((uint32_t)0x40200000))->EIE1) = SFR_Config((((INT_SFRmap *)((uint32_t)0x40200000))->EIE1), ~tmask, tmpreg);
    }
    else if(Peripheral <= INT_USART7)
    {

     tmask = ((uint32_t)1 << (Peripheral - INT_DMA1));
     tmpreg = ((uint32_t)NewState << (Peripheral - INT_DMA1));
     (((INT_SFRmap *)((uint32_t)0x40200000))->EIE2) = SFR_Config((((INT_SFRmap *)((uint32_t)0x40200000))->EIE2), ~tmask, tmpreg);
    }
    else
    {
     ;
    }
}






void INT_Set_Systick_Flag (void)
{
    __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *)((uint32_t)0x40200000))->EIF0))),"i"((15)));
}






void INT_Set_SOFTSV_Flag (void)
{
    __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *)((uint32_t)0x40200000))->EIF0))),"i"((14)));
}
# 322 "../src/kf32a1x6_int.c"
FlagStatus INT_Get_Interrupt_Flag (InterruptIndex Peripheral)
{
    uint32_t tmpreg=0;
    uint32_t tmpreg1=0;


    ((void)0);

    if (Peripheral <= INT_SysTick)
    {

        tmpreg = ((uint32_t)1<<((2))) << (Peripheral - INT_NMI);
        tmpreg1 = (((INT_SFRmap *)((uint32_t)0x40200000))->EIF0);
        if ((((INT_SFRmap *)((uint32_t)0x40200000))->EIF0) & tmpreg)
        {

            return SET;
        }
        else
        {

            return RESET;
        }
    }
    else if (Peripheral <= INT_SPI1)
    {

        tmpreg = ((uint32_t)1<<((0))) << (Peripheral - INT_WWDT);
        tmpreg1 = (((INT_SFRmap *)((uint32_t)0x40200000))->EIF1);
        if ((((INT_SFRmap *)((uint32_t)0x40200000))->EIF1) & tmpreg)
        {

            return SET;
        }
        else
        {

            return RESET;
        }
    }
    else if (Peripheral <= INT_USART7)
    {

        tmpreg = ((uint32_t)1<<((0))) << (Peripheral - INT_DMA1);
        tmpreg1 = (((INT_SFRmap *)((uint32_t)0x40200000))->EIF2);

    }
    else
    {


    }


    if ((*(volatile uint32_t*)tmpreg1) & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







void INT_Clear_Interrupt_Flag (InterruptIndex Peripheral)
{
    uint32_t tmask = 0;


    ((void)0);

    if(Peripheral <= INT_SysTick)
    {

     tmask = ((uint32_t)1 << Peripheral);
     (((INT_SFRmap *)((uint32_t)0x40200000))->EIF0) = SFR_Config((((INT_SFRmap *)((uint32_t)0x40200000))->EIF0),~tmask,0);
    }
    else if(Peripheral <= INT_SPI1)
    {

     tmask = ((uint32_t)1 << (Peripheral - INT_WWDT));
     (((INT_SFRmap *)((uint32_t)0x40200000))->EIF1) = SFR_Config((((INT_SFRmap *)((uint32_t)0x40200000))->EIF1),~tmask,0);
    }
    else if(Peripheral <= INT_USART7)
    {

     tmask = ((uint32_t)1 << (Peripheral - INT_DMA1));
     (((INT_SFRmap *)((uint32_t)0x40200000))->EIF2) = SFR_Config((((INT_SFRmap *)((uint32_t)0x40200000))->EIF2),~tmask,0);
    }
    else
    {
     ;
    }
}
# 439 "../src/kf32a1x6_int.c"
void INT_Interrupt_Priority_Config (InterruptIndex Peripheral,uint32_t Preemption, uint32_t SubPriority)
{
    uint32_t tmpreg;
    uint32_t regoffset = 0;
    uint32_t bitoffset = 0;
    uint32_t priorityconfig = 0;


    tmpreg = (((INT_SFRmap *)((uint32_t)0x40200000))->CTL0);
    tmpreg &= ((uint32_t)3<<((1)));


    ((void)0);
    ((void)0);


    switch (tmpreg)
    {
    case ((uint32_t)0<<((1))):
        priorityconfig = (Preemption << 1) | (SubPriority & 0x1);
        break;
    case ((uint32_t)1<<((1))):
        priorityconfig = (Preemption << 2) | (SubPriority & 0x3);
        break;
    case ((uint32_t)2<<((1))):
        priorityconfig = (Preemption << 3) | (SubPriority & 0x7);
        break;
    case ((uint32_t)3<<((1))):
        priorityconfig = SubPriority & 0xF;
        break;
    default:
        ((void)0);
        break;
    }


    if (Peripheral <= INT_USART7)
    {


        regoffset = (Peripheral - INT_Reserved4) >> 2;
        tmpreg = (uint32_t)&(((INT_SFRmap *)((uint32_t)0x40200000))->IP0);
        tmpreg = tmpreg + (regoffset << 2);
    }
    else
    {
     ;
    }


    bitoffset = ((Peripheral & 0x3) * 8) + 4;
    *(volatile uint32_t*)tmpreg
          = SFR_Config (*(volatile uint32_t*)tmpreg,
                      ~(0xF << bitoffset),
                      priorityconfig << bitoffset);
}






void INT_Stack_Delay_Enable (uint8_t IntDelay)
{

 ((void)0);


    (((INT_SFRmap *)((uint32_t)0x40200000))->CTL1) = SFR_Config ((((INT_SFRmap *)((uint32_t)0x40200000))->CTL1),
                      ~(((uint32_t)0xFF<<((0)))),

                      (uint32_t)IntDelay << (0));
}
# 527 "../src/kf32a1x6_int.c"
void INT_External_Configuration (EINT_InitTypeDef* eintInitStruct)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);




    (((INT_SFRmap *)((uint32_t)0x40200000))->EINTRISE) = SFR_Config((((INT_SFRmap *)((uint32_t)0x40200000))->EINTRISE),
      ~(((uint32_t)1<<((0))) << eintInitStruct->m_Line),
      eintInitStruct->m_Rise << eintInitStruct->m_Line);




    (((INT_SFRmap *)((uint32_t)0x40200000))->EINTFALL) = SFR_Config((((INT_SFRmap *)((uint32_t)0x40200000))->EINTFALL),
      ~(((uint32_t)1<<((0))) << eintInitStruct->m_Line),
      eintInitStruct->m_Fall << eintInitStruct->m_Line);




    tmpreg = (eintInitStruct->m_Line % 8) * 4;
    if(eintInitStruct->m_Line <= 0x07)
    {
     (((INT_SFRmap *)((uint32_t)0x40200000))->EINTSS0) = SFR_Config ((((INT_SFRmap *)((uint32_t)0x40200000))->EINTSS0), ~(0x07 << tmpreg), eintInitStruct->m_Source << tmpreg);
    }
    else if(eintInitStruct->m_Line <= 0x0F)
    {
     (((INT_SFRmap *)((uint32_t)0x40200000))->EINTSS1) = SFR_Config ((((INT_SFRmap *)((uint32_t)0x40200000))->EINTSS1), ~(0x07 << tmpreg), eintInitStruct->m_Source << tmpreg);
    }
    else
    {
     ;
    }




    (((INT_SFRmap *)((uint32_t)0x40200000))->EINTMASK) = SFR_Config ((((INT_SFRmap *)((uint32_t)0x40200000))->EINTMASK),
                          ~(((uint32_t)1<<((0))) << eintInitStruct->m_Line),
                          eintInitStruct->m_Mask << eintInitStruct->m_Line);
}






void INT_External_Struct_Init (EINT_InitTypeDef* eintInitStruct)
{

    eintInitStruct->m_Line = ((uint32_t)0);

    eintInitStruct->m_Mask = FALSE;

    eintInitStruct->m_Rise = FALSE;

    eintInitStruct->m_Fall = FALSE;

    eintInitStruct->m_Source = ((uint32_t)0);
}
# 611 "../src/kf32a1x6_int.c"
void INT_External_Mask_Enable (uint32_t EintMask, FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {
        (((INT_SFRmap *)((uint32_t)0x40200000))->EINTMASK) |= EintMask;
    }
    else
    {
        (((INT_SFRmap *)((uint32_t)0x40200000))->EINTMASK) &= ~EintMask;
    }
}
# 635 "../src/kf32a1x6_int.c"
void INT_External_Rise_Enable (uint32_t EintMask, FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {
        (((INT_SFRmap *)((uint32_t)0x40200000))->EINTRISE) |= EintMask;
    }
    else
    {
        (((INT_SFRmap *)((uint32_t)0x40200000))->EINTRISE) &= ~EintMask;
    }
}
# 659 "../src/kf32a1x6_int.c"
void INT_External_Fall_Enable (uint32_t EintMask, FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {
        (((INT_SFRmap *)((uint32_t)0x40200000))->EINTFALL) |= EintMask;
    }
    else
    {
        (((INT_SFRmap *)((uint32_t)0x40200000))->EINTFALL) &= ~EintMask;
    }
}
# 683 "../src/kf32a1x6_int.c"
FlagStatus INT_Get_External_Flag (uint32_t EintNum)
{

    ((void)0);


    if ((((INT_SFRmap *)((uint32_t)0x40200000))->EINTF) & (((uint32_t)1<<((0))) << EintNum))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 709 "../src/kf32a1x6_int.c"
RetStatus INT_External_Clear_Flag (uint32_t EintNum)
{
    uint32_t tmpreg;
 uint32_t wait_flag=0x0000;


    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << EintNum;
    while((((((INT_SFRmap *)((uint32_t)0x40200000))->EINTF) & tmpreg)>>(EintNum))&& (wait_flag != (0xFFFF)))
    {
     (((INT_SFRmap *)((uint32_t)0x40200000))->EINTF) &= ~tmpreg;
  wait_flag++;
    }
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}
# 755 "../src/kf32a1x6_int.c"
void INT_External_Source_Enable (uint32_t EintNum, uint32_t PeripheralSource)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = (EintNum % 8) * 4;
    if (EintNum <= 0x07)
    {
        (((INT_SFRmap *)((uint32_t)0x40200000))->EINTSS0) = SFR_Config ((((INT_SFRmap *)((uint32_t)0x40200000))->EINTSS0),
                          ~(0x07 << tmpreg),
                          PeripheralSource << tmpreg);
    }
    else if (EintNum <= 0x0F)
    {
        (((INT_SFRmap *)((uint32_t)0x40200000))->EINTSS1) = SFR_Config ((((INT_SFRmap *)((uint32_t)0x40200000))->EINTSS1),
                          ~(0x07 << tmpreg),
                          PeripheralSource << tmpreg);
    }
    else
    {
     ;
    }
}