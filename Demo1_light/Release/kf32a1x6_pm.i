# 1 "../src/kf32a1x6_pm.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\Release//"
# 1 "<command-line>"
# 1 "../src/kf32a1x6_pm.c"
# 35 "../src/kf32a1x6_pm.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pm.h" 1
# 29 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pm.h"
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
# 30 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pm.h" 2
# 482 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pm.h"
void PM_IO_Latch_Enable (FunctionalState NewState);
FlagStatus PM_Get_IO_Latch_Status (void);
void PM_Internal_Low_Frequency_Enable (FunctionalState NewState);
void PM_External_Low_Frequency_Enable (FunctionalState NewState);
void PM_External_Low_Frequency_Clock_Enable (FunctionalState NewState);
void PM_Main_Bandgap_Enable (FunctionalState NewState);
void PM_LDO18_Enable (FunctionalState NewState);
void PM_Backup_Registers_Reset_Config (uint32_t BkpReset);
void PM_Independent_Watchdog_Reset_Config (uint32_t IWDTReset);
void PM_DPRAM_In_Standby_Work_Mode_Config (uint32_t WorkMode);
void PM_LPRAM_In_Standby_Stop1_Work_Mode_Config (uint32_t WorkMode);
void PM_Backup_POR_Delay_Time_Config (uint32_t DelayTime);
void PM_Main_POR_Delay_Time_Config (uint32_t DelayTime);
void PM_Peripheral_IO_Port_Config (uint32_t PeripheralPort);
void PM_OCAL0LOCK_Enable (FunctionalState NewState);
void PM_MEMSEL_Enable (FunctionalState NewState);
void PM_Flash_Power_Off_Enable (FunctionalState NewState);
void PM_Backup_Write_And_Read_Enable (FunctionalState NewState);
void PM_LPR_Software_Enable (FunctionalState NewState);
void PM_Low_Power_Mode_Config (uint32_t LowPowerMode);
void PM_BOR_Enable (FunctionalState NewState);
void PM_Low_Power_BOR_Enable (FunctionalState NewState);
void PM_Temperature_Sensor_Enable (FunctionalState NewState);
void PM_Temperature_Sensor_Buffer_Enable (FunctionalState NewState);
void PM_Reference_Voltage_Enable (FunctionalState NewState);
void PM_Internal_Test_Buffer_Clock_Enable (FunctionalState NewState);
void PM_Internal_Test_Buffer_Clock_Scaler_Config (uint32_t SclkScaler);
void PM_CCP0LPEN_ENABLE(FunctionalState NewState);
void PM_CCP0CLKLPEN_Enable (FunctionalState NewState);
void PM_PLL0_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL1_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL2_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL0LDO_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL1LDO_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL2LDO_Output_Buffer_Enable (FunctionalState NewState);
void PM_Battery_BOR_Config (uint32_t Voltage);
void PM_Battery_BOR_Enable (FunctionalState NewState);
void PM_Peripheral_Voltage_Monitoring_Enable (FunctionalState NewState);
void PM_Voltage_Detection_Config (uint32_t Voltage);
void PM_Voltage_Detection_Enable (FunctionalState NewState);
void PM_EXTLF_PIN_Selection_Config (uint32_t PeripheralPort);
void PM_EXTHF_PIN_Selection_Config (uint32_t PeripheralPort);
void PM_External_Wakeup_Pin_Enable (uint32_t PinSel, FunctionalState NewState);
void PM_External_Wakeup_Edge_Config (uint32_t PinSel, uint32_t TriggerEdge);
void PM_Stop_Mode_Peripheral_INLF_Enable (uint32_t Peripheral,FunctionalState NewState);
void PM_Peripheral_Reset_Config (uint32_t Peripheral, uint32_t ResetStatus);
void PM_BKP_LPR_Type_Select(uint32_t LPRMODE);
void PM_LP_DEBUG_Enable(FunctionalState NewState);
void PM_LVL_LDO18_Enable(FunctionalState NewState);
void PM_RAM_ECC_Enable(FunctionalState NewState);
void PM_LPCAN_Work_CLK_Select(uint32_t CLK);


void PM_Vdd_Por_Enable (FunctionalState NewState);
void PM_Low_Power_Bandgap_Enable (FunctionalState NewState);
void PM_Power_Dissipation_Mode_Config (uint32_t Mode);
void PM_Power_Dissipation_Mode_Delay_Config (uint32_t DelayTime);
void PM_Internal_Test_Buffer_Enable (FunctionalState NewState);




RetStatus PM_Clear_Reset_And_Wakeup_Flag (uint32_t EventSel);
FlagStatus PM_Get_Reset_Flag (uint32_t EventSel);
RetStatus PM_Clear_External_Wakeup_Pin_Flag (uint32_t EventSel);
FlagStatus PM_Get_Low_Power_Running_State (void);
FlagStatus PM_Get_LPR_Status (void);
FlagStatus PM_Get_Peripheral_Voltage_Detection_Status (void);
FlagStatus PM_Stop_Mode_Error_Falg(void);
FlagStatus PM_PD_PMC_Error_Falg(void);
FlagStatus PM_POR18_Finish_Falg(void);
FlagStatus PM_Get_PMC_Error_INT_Falg(void);
void PM_Clear_PMCIF_Flag(void);
void PM_QEI0_Reset_Control(FunctionalState NewState);
void PM_GPIOA_Reset_Control(FunctionalState NewState);
void PM_RTC_Reset_Control(FunctionalState NewState);
void PM_QEI0_Work_Stop_INTLF_Enable(FunctionalState NewState);
void PM_RTC_Work_Stop_INTLF_Enable(FunctionalState NewState);
void PM_Reset_Pin_Config(uint32_t NRSTPIN, FunctionalState NewState);


void PM_Zero_Drift_Current_Config (uint32_t Calibration);
void PM_BOR_Voltage_Config (uint32_t Voltage);
void PM_Main_Regulator_Voltage_Config (uint32_t MRSel, uint32_t Voltage);
void PM_Main_Regulator_HV_Enable (FunctionalState NewState);
void PM_Reference_Calibration_Config (uint32_t Reference,
                    uint32_t Calibration);
void PM_INTLF_Bias_Current_Config (uint32_t Calibration);
void PM_EXTLF_Bias_Current_Config (uint32_t Calibration);
void PM_INTLF_Capacitance_Calibration_Config (uint32_t Calibration);
void PM_LP_Bias_Calibration_Config (uint32_t Calibration);
void PM_LPBG_Pump_Calibration_Config (uint32_t Calibration);
void PM_EXTLF_N_Bias_Current_Config (uint32_t Calibration);
void PM_IWDT_Enable(FunctionalState NewState);


void PM_LDO18_Module_Config (uint32_t LDO18Config);
void PM_Main_Regulator_Bandgap_Config (uint32_t ModeSel);
void PM_LPR_Module_Config (uint32_t ModeSel);
void PM_VREF_SELECT (uint32_t Voltage);
void PM_VREF_Software_Enable (FunctionalState NewState);
# 36 "../src/kf32a1x6_pm.c" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_osc.h" 1
# 35 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_osc.h"
typedef struct
{
    uint32_t m_InputSource;


    uint32_t m_CLKDivision;


    uint32_t m_PLLInputSource;


    uint32_t m_StartDelay;

} OSC_InitTypeDef;
# 276 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_osc.h"
void OSC_SCLK_Configuration (OSC_InitTypeDef* oscInitStruct);
void OSC_HFCK_Configuration (OSC_InitTypeDef* oscInitStruct);
void OSC_LFCK_Configuration (OSC_InitTypeDef* oscInitStruct);
void OSC_Struct_Init (OSC_InitTypeDef* oscInitStruct);

void OSC_LFCK_Division_Config (uint32_t LFDivision);
void OSC_HFCK_Division_Config (uint32_t HFDivision);
void OSC_SCK_Division_Config (uint32_t SclkDivision);
void OSC_PLL_Input_Source_Config (uint32_t NewState);
void OSC_HFCK_Source_Config (uint32_t HFSource);
void OSC_HFCK_Enable (FunctionalState NewState);
void OSC_LFCK_Source_Config (uint32_t NewState);
void OSC_LFCK_Enable (FunctionalState NewState);
void OSC_SCK_Source_Config (uint32_t SclkSource);
void OSC_Backup_Write_Read_Enable (FunctionalState NewState);
void OSC_SCLK_Output_Enable (FunctionalState NewState);
void OSC_SCLK_Output_Select (uint32_t ClkSource);
void OSC_SCLK_Output_Division_Config (uint32_t OutputDivision);
void OSC_Clock_Failure_Check_Enable (FunctionalState NewState);
void OSC_Clock_Failure_Check_Division_Config (uint32_t FSCM_DIV);
void OSC_PLL_Multiple_Value_Select (uint32_t PLLmultiple_M,uint32_t PLLmultiple_N,uint32_t PLLmultiple_NO);
void OSC_PLL_RST(void);
void OSC_PLL_Start_Delay_Config (uint32_t PLLDelay);
void OSC_EXTHF_Start_Delay_Config (uint32_t ExternalDelay);
void OSC_EXTLF_Start_Delay_Config (uint32_t ExternalDelay);
void OSC_LP4M_Software_Enable (FunctionalState NewState);
void OSC_PLL_Software_Enable (FunctionalState NewState);
void OSC_EXTHF_Software_Enable (FunctionalState NewState);
void OSC_EXTLF_Software_Enable (FunctionalState NewState);
void OSC_INTHF_Software_Enable (FunctionalState NewState);
void OSC_INTLF_Software_Enable (FunctionalState NewState);
void OSC_Zero_Drift_Config (uint32_t Scale, FunctionalState NewState);
void OSC_Positive_Drift_Config (uint32_t PositiveDrift);
void OSC_Negative_Drift_Config (uint32_t PositiveDrift);
void OSC_Current_Gain_Config (uint32_t PositiveDrift);
void OSC_High_Speed_Enable (FunctionalState NewState);
void OSC_External_Input_Enable (FunctionalState NewState);
void OSC_Feedback_Resistance_Config (uint32_t NewState);

void OSC_LP4M_INT_Enable (FunctionalState NewState);
void OSC_PLL_INT_Enable (FunctionalState NewState);
void OSC_EXTHF_INT_Enable (FunctionalState NewState);
void OSC_EXTLF_INT_Enable (FunctionalState NewState);
void OSC_INTHF_INT_Enable (FunctionalState NewState);
void OSC_INTLF_INT_Enable (FunctionalState NewState);
FlagStatus OSC_Get_Clock_Failure_INT_Flag (void);
FlagStatus OSC_Get_LP4MIF_INT_Flag (void);
FlagStatus OSC_Get_PLL_INT_Flag (void);
FlagStatus OSC_Get_EXTHF_INT_Flag (void);
FlagStatus OSC_Get_EXTLF_INT_Flag (void);
FlagStatus OSC_Get_INTHF_INT_Flag (void);
FlagStatus OSC_Get_INTLF_INT_Flag (void);
# 37 "../src/kf32a1x6_pm.c" 2
# 47 "../src/kf32a1x6_pm.c"
void PM_IO_Latch_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((31)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((31)));
    }
}






FlagStatus PM_Get_IO_Latch_Status (void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0) & ((uint32_t)1<<((31))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






void PM_Internal_Low_Frequency_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((29)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((29)));
    }
}






void PM_External_Low_Frequency_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((28)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((28)));
    }
}






void PM_External_Low_Frequency_Clock_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((27)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((27)));
    }
}






void PM_Main_Bandgap_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((25)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((25)));
    }
}






void PM_LDO18_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((24)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((24)));
    }
}
# 207 "../src/kf32a1x6_pm.c"
void PM_Backup_Registers_Reset_Config (uint32_t BkpReset)
{

    ((void)0);


    if (BkpReset != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((22)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((22)));
    }
}
# 232 "../src/kf32a1x6_pm.c"
void PM_Independent_Watchdog_Reset_Config (uint32_t IWDTReset)
{

    ((void)0);


    if (IWDTReset != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((21)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((21)));
    }
}
# 257 "../src/kf32a1x6_pm.c"
void PM_DPRAM_In_Standby_Work_Mode_Config (uint32_t WorkMode)
{

    ((void)0);


    if (WorkMode != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((20)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((20)));
    }
}
# 282 "../src/kf32a1x6_pm.c"
void PM_LPRAM_In_Standby_Stop1_Work_Mode_Config (uint32_t WorkMode)
{

    ((void)0);


    if (WorkMode != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((19)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((19)));
    }
}
# 307 "../src/kf32a1x6_pm.c"
void PM_Backup_POR_Delay_Time_Config (uint32_t DelayTime)
{

    ((void)0);


    if (DelayTime != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((15)));
    }
}
# 332 "../src/kf32a1x6_pm.c"
void PM_Main_POR_Delay_Time_Config (uint32_t DelayTime)
{

    ((void)0);


    if (DelayTime != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((14)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((14)));
    }
}
# 357 "../src/kf32a1x6_pm.c"
void PM_Peripheral_IO_Port_Config (uint32_t PeripheralPort)
{

    ((void)0);


    if (PeripheralPort != ((uint32_t)0<<(13)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((13)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((13)));
    }
}






void PM_OCAL0LOCK_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((6)));
    }
}






void PM_MEMSEL_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((3)));
    }
}






void PM_Flash_Power_Off_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((11)));
    }
    else
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((11)));
    }
}







void PM_CCP0LPEN_ENABLE(FunctionalState NewState)
{

 ((void)0);
 if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((1)));
    }
}






void PM_CCP0CLKLPEN_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((5)));
    }
}






void PM_Backup_Write_And_Read_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((7)));
    }
}






void PM_VREF_Software_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
}
# 544 "../src/kf32a1x6_pm.c"
void PM_VREF_SELECT (uint32_t Voltage)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)0x03<<((6))), Voltage);
}






void PM_LPR_Software_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((5)));
    }
}
# 585 "../src/kf32a1x6_pm.c"
void PM_Low_Power_Mode_Config (uint32_t LowPowerMode)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0), ~((uint32_t)0x07<<((0))), LowPowerMode);
}






void PM_BOR_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((31)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((31)));
    }
}






void PM_Low_Power_BOR_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((30)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((30)));
    }
}






void PM_Temperature_Sensor_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((29)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((29)));
    }
}






void PM_Temperature_Sensor_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((28)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((28)));
    }
}






void PM_Reference_Voltage_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
}






void PM_Internal_Test_Buffer_Clock_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((25)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((25)));
    }
}
# 745 "../src/kf32a1x6_pm.c"
void PM_Internal_Test_Buffer_Clock_Scaler_Config (uint32_t SclkScaler)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)0x07<<((22))), SclkScaler);
}
# 765 "../src/kf32a1x6_pm.c"
void PM_Battery_BOR_Config (uint32_t Voltage)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)0x07<<((12))), Voltage);
}






void PM_Battery_BOR_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((15)));
    }
}






void PM_Peripheral_Voltage_Monitoring_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
}
# 832 "../src/kf32a1x6_pm.c"
void PM_Voltage_Detection_Config (uint32_t Voltage)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)0x07<<((2))), Voltage);
}
# 848 "../src/kf32a1x6_pm.c"
void PM_BKP_LPR_Type_Select(uint32_t LPRMODE)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)1<<((1))), LPRMODE << (1));
}
# 863 "../src/kf32a1x6_pm.c"
void PM_LP_DEBUG_Enable(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)1<<((8))), NewState << (8));
}
# 878 "../src/kf32a1x6_pm.c"
void PM_LVL_LDO18_Enable(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)1<<((9))), (!NewState) << (9));
}
# 893 "../src/kf32a1x6_pm.c"
void PM_RAM_ECC_Enable(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)1<<((10))), NewState << (10));
}
# 908 "../src/kf32a1x6_pm.c"
void PM_LPCAN_Work_CLK_Select(uint32_t CLK)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)1<<((11))), CLK << (11));
}






void PM_Voltage_Detection_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((0)));
    }
}
# 950 "../src/kf32a1x6_pm.c"
void PM_External_Wakeup_Pin_Enable (uint32_t PinSel, FunctionalState NewState)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((27))) << PinSel;
    if (NewState != FALSE)
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) |= tmpreg;
    }
    else
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) &= ~tmpreg;
    }
}
# 985 "../src/kf32a1x6_pm.c"
void PM_External_Wakeup_Edge_Config (uint32_t PinSel, uint32_t TriggerEdge)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((22))) << PinSel;
    if (TriggerEdge != ((uint32_t)0))
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) |= tmpreg;
    }
    else
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) &= ~tmpreg;
    }
}
# 1017 "../src/kf32a1x6_pm.c"
void PM_Stop_Mode_Peripheral_INLF_Enable (uint32_t Peripheral,FunctionalState NewState)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((4))) << Peripheral;
    if (NewState != FALSE)
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) |= tmpreg;
    }
    else
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) &= ~tmpreg;
    }
}
# 1051 "../src/kf32a1x6_pm.c"
void PM_Peripheral_Reset_Config (uint32_t Peripheral, uint32_t ResetStatus)
{
    uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Peripheral;
    if (ResetStatus != ((uint32_t)0))
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) |= tmpreg;
    }
    else
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) &= ~tmpreg;
    }
}
# 1080 "../src/kf32a1x6_pm.c"
void PM_PMC_Error_Status_INT_Enable(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2), ~((uint32_t)1<<((19))), NewState << (19));
}
# 1095 "../src/kf32a1x6_pm.c"
void PM_QEI0_Reset_Control(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2), ~((uint32_t)1<<((18))), NewState << (18));
}
# 1110 "../src/kf32a1x6_pm.c"
void PM_GPIOA_Reset_Control(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2), ~((uint32_t)1<<((17))), NewState << (17));
}
# 1125 "../src/kf32a1x6_pm.c"
void PM_RTC_Reset_Control(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2), ~((uint32_t)1<<((14))), NewState << (14));
}
# 1140 "../src/kf32a1x6_pm.c"
void PM_QEI0_Work_Stop_INTLF_Enable(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2), ~((uint32_t)1<<((16))), NewState << (16));
}
# 1155 "../src/kf32a1x6_pm.c"
void PM_RTC_Work_Stop_INTLF_Enable(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2), ~((uint32_t)1<<((15))), NewState << (15));
}
# 1170 "../src/kf32a1x6_pm.c"
void PM_Vdd_Por_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((30)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((30)));
    }
}






void PM_Low_Power_Bandgap_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((23)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((23)));
    }
}
# 1218 "../src/kf32a1x6_pm.c"
void PM_Power_Dissipation_Mode_Config (uint32_t Mode)
{

    ((void)0);


    if (Mode != ((uint32_t)0<<(11)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((11)));
    }
}
# 1244 "../src/kf32a1x6_pm.c"
void PM_Power_Dissipation_Mode_Delay_Config (uint32_t DelayTime)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0), ~((uint32_t)0x03<<((9))), DelayTime);
}






void PM_Internal_Test_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((26)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((26)));
    }
}
# 1294 "../src/kf32a1x6_pm.c"
RetStatus PM_Clear_Reset_And_Wakeup_Flag (uint32_t EventSel)
{
    uint32_t tmpmask;
 uint32_t wait_flag=0x0000;


    ((void)0);
    tmpmask = (uint32_t)1 << EventSel;

    __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0))),"i"((31)));
    while(((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0) & tmpmask)&& (wait_flag != (0xFFFF)))
 {
  wait_flag++;
 }
    __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0))),"i"((31)));
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}
# 1332 "../src/kf32a1x6_pm.c"
FlagStatus PM_Get_Reset_Flag (uint32_t EventSel)
{
    uint32_t tmpreg;
    uint32_t tmpmask;


    ((void)0);

    if (EventSel < 32)
    {
        tmpreg = (((PM_SFRmap *) ((uint32_t)0x40001580))->STA0);
        tmpmask = (uint32_t)1 << EventSel;
    }
    else
    {
        tmpreg = (((PM_SFRmap *) ((uint32_t)0x40001580))->STA1);
        tmpmask = (uint32_t)1 << (EventSel - 32);
    }


    if (tmpreg & tmpmask)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 1374 "../src/kf32a1x6_pm.c"
RetStatus PM_Clear_External_Wakeup_Pin_Flag (uint32_t EventSel)
{
    uint32_t tmpreg;
    uint32_t tmpmask;
 uint32_t wait_flag=0x0000;

    ((void)0);
    tmpmask = (uint32_t)1 << (EventSel - 32);

    (((PM_SFRmap *) ((uint32_t)0x40001580))->STAC) |= tmpmask;
    while(((((PM_SFRmap *) ((uint32_t)0x40001580))->STA1) & tmpmask)&& (wait_flag != (0xFFFF)))
 {
  wait_flag++;
 }
    (((PM_SFRmap *) ((uint32_t)0x40001580))->STAC) &= ~tmpmask;
 if(wait_flag==(0xFFFF))
 {
  return FAILURE;
 }
 return SUCCESS;
}






void PM_Clear_PMCIF_Flag(void)
{
 (((PM_SFRmap *) ((uint32_t)0x40001580))->STAC) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->STAC), ~((uint32_t)1<<((26))), ((uint32_t)1<<((26))));
}






FlagStatus PM_Get_Low_Power_Running_State (void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0) & ((uint32_t)1<<((1))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus PM_Get_LPR_Status (void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0) & ((uint32_t)1<<((0))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus PM_Get_Peripheral_Voltage_Detection_Status (void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA1) & ((uint32_t)1<<((0))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus PM_Get_PMC_Error_INT_Falg(void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA1) & ((uint32_t)1<<((26))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus PM_POR18_Finish_Falg(void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA1) & ((uint32_t)1<<((22))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus PM_PD_PMC_Error_Falg(void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA1) & ((uint32_t)1<<((19))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus PM_Stop_Mode_Error_Falg(void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA1) & ((uint32_t)1<<((18))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 1570 "../src/kf32a1x6_pm.c"
void PM_Zero_Drift_Current_Config (uint32_t Calibration)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~((uint32_t)0x03<<((24))), Calibration);
}
# 1588 "../src/kf32a1x6_pm.c"
void PM_BOR_Voltage_Config (uint32_t Voltage)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~((uint32_t)0x03<<((20))), Voltage);
}
# 1609 "../src/kf32a1x6_pm.c"
void PM_Main_Regulator_Voltage_Config (uint32_t MRSel, uint32_t Voltage)
{
    uint32_t tmpreg;
    uint32_t tmpmask;


    ((void)0);
    ((void)0);


    tmpreg = Voltage << MRSel;
    tmpmask = (uint32_t)0xF << MRSel;
    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~tmpmask, tmpreg);
}






void PM_Main_Regulator_HV_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((15)));
    }
}
# 1657 "../src/kf32a1x6_pm.c"
void PM_Reference_Calibration_Config (uint32_t Reference, uint32_t Calibration)
{
    uint32_t tmpreg=0;
    uint32_t tmpmask=0;


    switch (Reference)
    {
        case ((5)):
            ((void)0);
            tmpreg = Calibration << ((5));
            tmpmask = ((uint32_t)0x1F<<((5)));
            break;
        case ((0)):
            ((void)0);
            tmpreg = Calibration << ((0));
            tmpmask = ((uint32_t)0x1F<<((0)));
            break;
        default:
            ((void)0);
            break;
    }


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~tmpmask, tmpreg);
}
# 1697 "../src/kf32a1x6_pm.c"
void PM_INTLF_Bias_Current_Config (uint32_t Calibration)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0x07<<((29))), Calibration);
}
# 1719 "../src/kf32a1x6_pm.c"
void PM_EXTLF_Bias_Current_Config (uint32_t Calibration)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0x0F<<((2))), Calibration);
}






void PM_INTLF_Capacitance_Calibration_Config (uint32_t Calibration)
{
 uint32_t tmpreg;

    ((void)0);


    tmpreg = Calibration << (24);
    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0x1F<<((24))), tmpreg);
}






void PM_LP_Bias_Calibration_Config (uint32_t Calibration)
{
 uint32_t tmpreg;

    ((void)0);


    tmpreg = Calibration << (20);
    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0x07<<((20))), tmpreg);
}






void PM_LPBG_Pump_Calibration_Config (uint32_t Calibration)
{
 uint32_t tmpreg;

    ((void)0);


    tmpreg = Calibration << (16);
    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0x07<<((16))), tmpreg);

}
# 1786 "../src/kf32a1x6_pm.c"
void PM_EXTLF_N_Bias_Current_Config (uint32_t Calibration)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0x03<<((0))), Calibration);
}
# 1802 "../src/kf32a1x6_pm.c"
void PM_EXTLF_PIN_Selection_Config (uint32_t PeripheralPort)
{

    ((void)0);


    if (PeripheralPort != ((uint32_t)0<<(19)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1))),"i"((19)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1))),"i"((19)));
    }
}
# 1827 "../src/kf32a1x6_pm.c"
void PM_EXTHF_PIN_Selection_Config (uint32_t PeripheralPort)
{

    ((void)0);


    if (PeripheralPort != ((uint32_t)0<<(15)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1))),"i"((15)));
    }
}
# 1852 "../src/kf32a1x6_pm.c"
void PM_LPR_Module_Config (uint32_t ModeSel)
{

    ((void)0);


    if (ModeSel != ((uint32_t)0<<(29)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((30)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((30)));
    }
}







void PM_Reset_Pin_Config(uint32_t NRSTPIN, FunctionalState NewState)
{
 uint32_t tmpreg;
 uint32_t tmask;


 ((void)0);
 ((void)0);

 tmpreg = NewState << ((10) + NRSTPIN);
 tmask = 1 << ((10) + NRSTPIN);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~tmask, tmpreg);
}
# 1899 "../src/kf32a1x6_pm.c"
void PM_IWDT_Enable(FunctionalState NewState)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~((uint32_t)1<<((19))), NewState << (19));
}






void PM_LPR12_CAPLESS_I_Config(uint32_t Calibration)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL2) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL2), ~((uint32_t)0x1F<<((24))), Calibration << (24));
}
# 1928 "../src/kf32a1x6_pm.c"
void PM_MR12_Capless_PC_Config(uint32_t Calibration)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL2) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL2), ~((uint32_t)0x03<<((22))), Calibration << (22));
}






void PM_BGTRIMREBUF_Config(uint32_t Calibration)
{

 ((void)0);

 (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL2) = SFR_Config((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL2), ~((uint32_t)0x3F<<((16))), Calibration << (16));
}
