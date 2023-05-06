# 1 "../src/kf32a1x6_canfd_136.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\Release//"
# 1 "<command-line>"
# 1 "../src/kf32a1x6_canfd_136.c"
# 33 "../src/kf32a1x6_canfd_136.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rst.h" 1
# 29 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rst.h"
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
# 30 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rst.h" 2
# 58 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rst.h"
void RST_CTL0_Peripheral_Reset_Enable(uint32_t RST_CTL0Periph,
                    FunctionalState NewState);
void RST_CTL1_Peripheral_Reset_Enable(uint32_t RST_CTL1Periph,
                    FunctionalState NewState);
void RST_CTL2_Peripheral_Reset_Enable(uint32_t RST_CTL2Periph,
                    FunctionalState NewState);
void RST_CTL3_Peripheral_Reset_Enable(uint32_t RST_CTL3Periph,
                    FunctionalState NewState);
# 34 "../src/kf32a1x6_canfd_136.c" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pclk.h" 1
# 57 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pclk.h"
void PCLK_CTL0_Peripheral_Clock_Enable (uint32_t PCLK_CTL0_bit,FunctionalState NewState);
void PCLK_CTL1_Peripheral_Clock_Enable (uint32_t PCLK_CTL1_bit,FunctionalState NewState);
void PCLK_CTL2_Peripheral_Clock_Enable (uint32_t PCLK_CTL2_bit,FunctionalState NewState);
void PCLK_CTL3_Peripheral_Clock_Enable (uint32_t PCLK_CTL3_bit,FunctionalState NewState);
# 35 "../src/kf32a1x6_canfd_136.c" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_canfd.h" 1
# 17 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_canfd.h"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_canfd_156.h" 1
# 58 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_canfd_156.h"
typedef union
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



     volatile unsigned int DATA1 : 8;
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

typedef struct
{

    union
    {
        unsigned int R;
        struct
        {
            unsigned int RSMOD : 1;
            unsigned int SILENT : 1;
            unsigned int LBACK : 1;
            unsigned int SLEEP : 1;
            unsigned int ISOFDCAN : 1;
            unsigned int CANCKS : 2;
            unsigned int CANEN : 1;
            volatile unsigned int TXR : 1;
            volatile unsigned int ATX : 1;
            unsigned int RELRX : 1;
            volatile unsigned int RELF : 1;
            volatile unsigned int MBSIZE : 2;
            unsigned int FULLRXEN : 1;
            unsigned int AMSWEREN : 1;
            unsigned int RXBSTA : 1;
            unsigned int DOSTA : 1;
            unsigned int : 1;
            unsigned int TCSTA : 1;
            volatile unsigned int RXSTA : 1;
            volatile unsigned int TXSTA : 1;
            unsigned int CERROR : 1;
            volatile unsigned int BOFF : 1;
            volatile unsigned int CANRMC : 7;
            unsigned int CANFDEN : 1;

        } B;
    } CANFD_CTLR0;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int CNABRP : 6;
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
            unsigned int : 16;

        } B;
    } CANFD_RCR;


    union
    {
        unsigned int R;
        struct
        {
         volatile unsigned int CANRXE : 8;
         volatile unsigned int CANTXE : 8;
         volatile unsigned int CANEWL : 8;
            unsigned int : 8;

        } B;
    } CANFD_EROR;

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
            unsigned int RELRXALL : 1;
            unsigned int AMCKDIV : 2;
            unsigned int TEST1 : 1;
            unsigned int TEST2 : 1;
            unsigned int TEST3 : 1;
            unsigned int TEST4 : 1;
            unsigned int TEST5 : 1;
        } B;
    } CANFD_CTLR2;


    unsigned int CANFD_MSKR;


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
            unsigned int : 1;

        } B;
    } CANFD_IER;


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


    DataBuffer_RegType CANFD_DATA;


    union
    {
        unsigned int R;
        struct
        {
         volatile unsigned int CANTIMER : 16;
            unsigned int : 16;

        } B;
    } CANFD_TIMER;


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


    unsigned int RESERVED2;


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


    union
    {
        unsigned int R;
        struct
        {
            unsigned int MATWINER : 10;
            unsigned int MATSTA : 1;
            unsigned int : 5;
            unsigned int ARBWINNER : 10;
            unsigned int ARBSTA0 : 1;
            unsigned int ARBSTA1 : 1;
            unsigned int : 4;

        } B;
    } CANFD_AMSTA;

} Kf32a_Canfd_Reg;


struct Kf32a_Int_Reg{

    union
    {
        unsigned int R;
        struct
        {
            unsigned int AIE: 1;
      unsigned int PRIGROUP: 2;
      unsigned int : 1;
      unsigned int INTPENDING: 1;
      unsigned int INTPREEMPT: 1;
      unsigned int FAULTMASK: 1;
      unsigned int DSALIGN: 1;
      unsigned int : 4;
      unsigned int PRIBASE: 4;
      unsigned int INTPEND: 7;
      unsigned int : 1;
      unsigned int INTACT: 7;
      unsigned int : 1;
        }B;
    }CTL0;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int : 3;
      unsigned int HADRFAULTIE: 1;
      unsigned int : 1;
      unsigned int STACKIE: 1;
      unsigned int ARIFAULTIE: 1;
      unsigned int : 1;
      unsigned int : 3;
      unsigned int SVCIE: 1;
      unsigned int : 2;
      unsigned int SOFTSVIE: 1;
      unsigned int SYSTICKIE: 1;
      unsigned int : 16;
        }B;
    }EIE0;


    unsigned int RESERVED0;

    union
    {
        unsigned int R;
        struct
        {
            unsigned int WWDTIE: 1;
      unsigned int EINT16IE: 1;
      unsigned int EINT0IE: 1;
      unsigned int EINT1IE: 1;
      unsigned int EINT2IE: 1;
      unsigned int EINT3IE: 1;
      unsigned int EINT4IE: 1;
      unsigned int EINT9TO5IE: 1;
      unsigned int EINT15TO10IE: 1;
      unsigned int T1IE: 1;
      unsigned int T3IE: 1;
      unsigned int T5IE: 1;
      unsigned int T6IE: 1;
      unsigned int QEI0IE: 1;
      unsigned int QEII1E: 1;
      unsigned int ECFGLIE: 1;
      unsigned int CAN4IE: 1;
      unsigned int T14IE: 1;
      unsigned int : 1;
      unsigned int FDC2IE: 1;
      unsigned int EXICIE: 1;
      unsigned int ADC0IE: 1;
      unsigned int ADC1IE: 1;
      unsigned int CFGLIE: 1;
      unsigned int T11IE: 1;
      unsigned int T0IE: 1;
      unsigned int DMA0IE: 1;
      unsigned int CMPIE: 1;
      unsigned int USART0IE: 1;
      unsigned int USART1IE: 1;
      unsigned int SPI0IE: 1;
      unsigned int SPI1IE: 1;
        }B;
    }EIE1;


    unsigned int RESERVED1;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int DMA1IE: 1;
      unsigned int EINT19TO17IE: 1;
      unsigned int CANFD6IE: 1;
         unsigned int CANFD7IE: 1;
      unsigned int T9IE: 1;
      unsigned int T10IE: 1;
      unsigned int EINT20IE: 1;
      unsigned int : 1;
      unsigned int OSCIE: 1;
      unsigned int I2C0IE: 1;
      unsigned int I2C1IE: 1;
      unsigned int I2C2IE: 1;
      unsigned int : 1;
      unsigned int T2IE: 1;
      unsigned int T4IE: 1;
      unsigned int CTOUCHIE: 1;
      unsigned int USART2IE: 1;
      unsigned int USART3IE: 1;
      unsigned int : 1;
      unsigned int : 1;
      unsigned int : 1;
      unsigned int ADC2IE: 1;
      unsigned int T18IE: 1;
      unsigned int T19IE: 1;
      unsigned int T22T23IE: 1;
      unsigned int WKPIE: 1;
      unsigned int T20IE: 1;
      unsigned int T21IE: 1;
      unsigned int : 1;
      unsigned int : 1;
      unsigned int : 1;
      unsigned int : 1;
        }B;
    }EIE2;


    unsigned int RESERVED2;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int : 2;
      unsigned int NMIIF: 1;
      unsigned int HARDFAULTIF: 1;
      unsigned int : 1;
      unsigned int STACKIF: 1;
      unsigned int ARIFAULTIF: 1;
      unsigned int : 3;
      unsigned int : 1;
      unsigned int SVCIF: 1;
      unsigned int : 1;
      unsigned int : 1;
      unsigned int SOFTSVIF: 1;
      unsigned int SYSTICKIF: 1;
      unsigned int : 16;
        }B;
    }EIF0;


    unsigned int RESERVED3;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int WWDTIF: 1;
      unsigned int EINT16IF: 1;
      unsigned int EINT0IF: 1;
      unsigned int EINT1IF: 1;
      unsigned int EINT2IF: 1;
      unsigned int EINT3IF: 1;
      unsigned int EINT4IF: 1;
      unsigned int EINT9TO5IF: 1;
      unsigned int EINT15TO10IF: 1;
      unsigned int T1IF: 1;
      unsigned int T3IF: 1;
      unsigned int T5IF: 1;
      unsigned int T6IF: 1;
      unsigned int QEI0IF: 1;
      unsigned int QEI1IF: 1;
      unsigned int PLAIF: 1;
      unsigned int CAN4IF: 1;
      unsigned int T14IF: 1;
      unsigned int RNGIF: 1;
      unsigned int PDB2IF: 1;
      unsigned int EXICIF: 1;
      unsigned int ADC0IF: 1;
      unsigned int ADC1IF: 1;
      unsigned int CFGLIF: 1;
      unsigned int T11IF: 1;
      unsigned int T0IF: 1;
      unsigned int DMA0IF: 1;
      unsigned int CMPIF: 1;
      unsigned int USART0IF: 1;
      unsigned int USART1IF: 1;
      unsigned int SPI0IF: 1;
      unsigned int SPI1IF: 1;
        }B;
    }EIF1;


    unsigned int RESERVED4;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int DMA1IF: 1;
      unsigned int EINT19TO17IF: 1;
      unsigned int FLEXCAN6IF: 1;
      unsigned int FLEXCAN7IF: 1;
      unsigned int PDB0IF: 1;
      unsigned int PDB1IF: 1;
      unsigned int EINT31TO20IF: 1;
      unsigned int ECCIF: 1;
      unsigned int OSCIF: 1;
      unsigned int I2C0IF: 1;
      unsigned int I2C1IF: 1;
      unsigned int I2C2IF: 1;
      unsigned int T12IF: 1;
      unsigned int T2IF: 1;
      unsigned int T4IF: 1;
      unsigned int T13IF: 1;
      unsigned int USART2IF: 1;
      unsigned int T16IF: 1;
      unsigned int USART4IF: 1;
      unsigned int SPI2IF: 1;
      unsigned int SPI3IF: 1;
      unsigned int ADC2IF: 1;
      unsigned int T18IF: 1;
      unsigned int T19IF: 1;
      unsigned int HRCAP0IF: 1;
      unsigned int WKPIF: 1;
      unsigned int HRCAP1IF: 1;
      unsigned int T21IF: 1;
      unsigned int I2C3IF: 1;
      unsigned int USART5IF: 1;
      unsigned int HRCAP2IF: 1;
      unsigned int USART7IF: 1;
        }B;
    }EIF2;


    unsigned int RESERVED5;



    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI4: 8;
      unsigned int PRI5: 8;
      unsigned int PRI6: 8;
      unsigned int PRI7: 8;
        }B;
    }IP0;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI8: 8;
      unsigned int PRI9: 8;
      unsigned int PRI10: 8;
      unsigned int PRI11: 8;
        }B;
    }IP1;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI12: 8;
      unsigned int PRI13: 8;
      unsigned int PRI14: 8;
      unsigned int PRI15: 8;
        }B;
    }IP2;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PR16: 8;
      unsigned int PRI17: 8;
      unsigned int PRI18: 8;
      unsigned int PRI19: 8;
        }B;
    }IP3;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI20: 8;
      unsigned int PRI21: 8;
      unsigned int PRI22: 8;
      unsigned int PRI23: 8;
        }B;
    }IP4;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI24: 8;
      unsigned int PRI25: 8;
      unsigned int PRI26: 8;
      unsigned int PRI27: 8;
        }B;
    }IP5;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI28: 8;
      unsigned int PRI29: 8;
      unsigned int PRI30: 8;
      unsigned int PRI31: 8;
        }B;
    }IP6;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI32U: 4;
            unsigned int PRI32S: 1;
            unsigned int PRI32P: 3;
      unsigned int PRI33: 8;
      unsigned int PRI34: 8;
      unsigned int PRI35: 8;
        }B;
    }IP7;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI36: 8;
      unsigned int PRI37: 8;
      unsigned int PRI38: 8;
      unsigned int PRI39: 8;
        }B;
    }IP8;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI40: 8;
      unsigned int PRI41: 8;
      unsigned int PRI42: 8;
      unsigned int PRI43: 8;
        }B;
    }IP9;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI44: 8;
      unsigned int PRI45: 8;
      unsigned int PRI46: 8;
      unsigned int PRI47: 8;
        }B;
    }IP10;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI48: 8;
      unsigned int PRI49: 8;
      unsigned int PRI50U: 4;
      unsigned int PRI50S: 1;
      unsigned int PRI50P: 3;
      unsigned int PRI51U: 4;
      unsigned int PRI51S: 1;
      unsigned int PRI51P: 3;
        }B;
    }IP11;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI52: 8;
      unsigned int PRI53: 8;
      unsigned int PRI54: 8;
      unsigned int PRI55: 8;
        }B;
    }IP12;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI56: 8;
      unsigned int PRI57: 8;
      unsigned int PRI58: 8;
      unsigned int PRI59: 8;
        }B;
    }IP13;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI60: 8;
      unsigned int PRI61: 8;
      unsigned int PRI62: 8;
      unsigned int PRI63: 8;
        }B;
    }IP14;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI64: 8;
      unsigned int PRI65: 8;
      unsigned int PRI66: 8;
      unsigned int PRI67: 8;
        }B;
    }IP15;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI68: 8;
      unsigned int PRI69: 8;
      unsigned int PRI70: 8;
      unsigned int PRI71: 8;
        }B;
    }IP16;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI72:8;
      unsigned int PRI73:8;
      unsigned int PRI74:8;
      unsigned int PRI75:8;
        }B;
    }IP17;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int PRI76:8;
      unsigned int PRI77:8;
      unsigned int PRI78:8;
      unsigned int PRI79:8;
        }B;
    }IP18;



    union
    {
        unsigned int R;
        struct
        {
            unsigned int EINTM:21;
      unsigned int :10;
      unsigned int :1;
        }B;
    }EINTMASK;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int EINTRI:21;
      unsigned int :10;
      unsigned int :1;
        }B;
    }EINTRISE;



    union
    {
        unsigned int R;
        struct
        {
            unsigned int EINTFA:21;
      unsigned int :10;
      unsigned int :1;
        }B;
    }EINTFALL;


    union
    {
        unsigned int R;
        struct
        {
            unsigned int EINTIF:21;
      unsigned int :11;
        }B;
    }EINTF;


    unsigned int RESERVED6;


    union
    {
        unsigned int R;
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


    union
    {
        unsigned int R;
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


    union
    {
        unsigned int R;
        struct
        {
            unsigned int INTDELY:8;
      unsigned int :24;
        }B;
    }CTL1;
};







struct Kf32a_Mcu_Pclk_Reg
{

 unsigned int RESERVED[16];

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





struct Kf32a_Mcu_Rst_Reg
{

 union
 {
  unsigned int R;
  struct
  {
   unsigned int GPIOARST: 1;
   unsigned int GPIOBRST: 1;
   unsigned int GPIOCRST: 1;
   unsigned int GPIODRST: 1;
   unsigned int GPIOERST: 1;
   unsigned int GPIOFRST: 1;
   unsigned int GPIOGRST: 1;
   unsigned int GPIOHRST: 1;
   unsigned int : 23;
   unsigned int : 1;
  }B;
 }CTL0;


 union
 {
  unsigned int R;
  struct
  {
   unsigned int : 1;
   unsigned int QEI1RST: 1;
   unsigned int T1RST: 1;
   unsigned int T2RST: 1;
   unsigned int T3RST: 1;
   unsigned int T4RST: 1;
   unsigned int T5T6RST: 1;
   unsigned int : 1;
   unsigned int T9T10RST: 1;
   unsigned int : 1;
   unsigned int QEI0RST: 1;
   unsigned int ADC0RST: 1;
   unsigned int ADC1RST: 1;
   unsigned int ADC2RST: 1;
   unsigned int DAC0RST: 1;
   unsigned int DAC1RST: 1;
   unsigned int CMPRST: 1;
   unsigned int T0RST: 1;
   unsigned int CTOUCHRST: 1;
   unsigned int USART0RST: 1;
   unsigned int USART1RST: 1;
   unsigned int USART2RST: 1;
   unsigned int USART3RST: 1;
   unsigned int USART4RST: 1;
   unsigned int SPI0RST: 1;
   unsigned int SPI1RST: 1;
   unsigned int I2C0RST: 1;
   unsigned int I2C1RST: 1;
   unsigned int I2C2RST: 1;
   unsigned int LCDRST: 1;
   unsigned int : 1;
   unsigned int USBRST: 1;
  }B;
 }CTL1;


 union
 {
  unsigned int R;
  struct
  {
   unsigned int : 1;
   unsigned int : 1;
   unsigned int CAN0RST: 1;
   unsigned int CAN1RST: 1;
   unsigned int : 1;
   unsigned int WWDTRST: 1;
   unsigned int : 5;
   unsigned int : 1;
   unsigned int DMA0RST: 1;
   unsigned int : 1;
   unsigned int DMA1RST: 1;
   unsigned int : 1;
   unsigned int T14RST: 1;
   unsigned int T15RST: 1;
   unsigned int CAN2RST: 1;
   unsigned int CAN3RST: 1;
   unsigned int : 1;
   unsigned int T18RST: 1;
   unsigned int T19RST: 1;
   unsigned int T20RST: 1;
   unsigned int T21RST: 1;
   unsigned int T22RST: 1;
   unsigned int T23RST: 1;
   unsigned int : 1;
   unsigned int : 1;
   unsigned int USART5RST: 1;
   unsigned int USART6RST: 1;
   unsigned int USART7RST: 1;
  }B;
 }CTL2;


 union
 {
  unsigned int R;
  struct
  {
   unsigned int : 1;
   unsigned int SPI2RST: 1;
   unsigned int SPI3RST: 1;
   unsigned int : 4;
   unsigned int I2C3RST: 1;
   unsigned int : 5;
   unsigned int CRCRST: 1;
   unsigned int : 2;
   unsigned int EXICRST: 1;
   unsigned int CAN4RST: 1;
   unsigned int : 1;
   unsigned int CFGLRST: 1;
   unsigned int : 1;
   unsigned int FLEXMUXRST: 1;
   unsigned int FDC0RST: 1;
   unsigned int FDC1RST: 1;
   unsigned int FDC2RST: 1;
   unsigned int FLEXRMRST: 1;
   unsigned int ECFGLRST: 1;
   unsigned int EWDTRST: 1;
   unsigned int : 1;
   unsigned int CANFD6RST: 1;
   unsigned int CANFD7RST: 1;
   unsigned int RTCRST: 1;
  }B;
 }CTL3;

};





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
# 1847 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_canfd_156.h"
extern const Can_ControllerInfoType Can_m_ControllersInfo[3];
# 1880 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_canfd_156.h"
typedef struct
{
    uint16_t PreScale : 6;
    uint16_t Sjw : 2;
    uint16_t TSeg1 : 4;
    uint16_t TSeg2 : 3;
    uint16_t SampleTimes : 1;
} Can_Controller_BDRConfigType;


typedef struct Can_FdBDRConfigType
{
 uint16_t BrsPrescale : 6;
 uint16_t HtSeg1 : 4;
    uint16_t HtSeg2 : 3;
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

 uint16_t RxIntEnableSet : 1;

 uint16_t TxIntEnableSet : 1;

 uint16_t BusOffEnableSet : 1;

 uint16_t WakeUpIntEnableSet : 1;

 uint16_t ErrorAlarmIntEnableSet : 1;

 uint16_t OverFlowIntEnableSet : 1;

 uint16_t ErrorNegativeIntEnableSet : 1;

 uint16_t ArbitrateLoseIntEnableSet : 1;

 uint16_t BusErrorIntEnableSet : 1;

 uint16_t DmaTXDEnableSet : 1;

 uint16_t DmaRXDEnableSet : 1;

 uint16_t TrigerMBEnableSet : 1;

 uint16_t PreemptionPriority : 3;

 uint16_t SubPriority : 1;
} Can_Controller_InterruptConfigType;



typedef union
{
 volatile uint16_t EntireFlag;
 struct
 {

  volatile uint16_t RxIntFlag : 1;

  volatile uint16_t TxIntFlag : 1;

     volatile uint16_t ErrorAlarmFlag : 1;

     volatile uint16_t OverFlowFlag : 1;

     volatile uint16_t WakeUpFlag : 1;

     volatile uint16_t ErrorNegativeFlag : 1;

     volatile uint16_t ArbitrateLoseFlag : 1;

     volatile uint16_t BusErrorFlag : 1;

     volatile uint16_t DmaTXDFlag : 1;

     volatile uint16_t DmaRXDFlag : 1;
     volatile uint16_t : 1;

     volatile uint16_t MaillboxTriggerFlag : 1;

     volatile uint16_t BusOffFlag : 1;
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

    Can_FdFrameType FdFrameType;

    uint32_t GlobalMask;

    Can_MBFullReceiveEnableType MBFullReceiveEnableSet;
    const Can_Controller_InterruptConfigType *Can_Controller_InterruptConfig;

    const Can_HwFilterType * Can_HwFilter;

    const Can_Controller_BDRConfigType *Canfd_Controller_AllClockAndBDRConfig;
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
  volatile uint16_t MailboxTrigger_Timeout:1;
  volatile uint16_t :6;
 };
}ClearFlag_ReturnType;

typedef struct
{
 Canfd_MailboxHeaderType Can_MailboxHeader[20];
    uint8_t Sdu_Length;

} Canfd_Sdu_Type;
# 2305 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_canfd_156.h"
void Can_m_FdMailBoxErase(const uint8_t Can_Controller_Index);
void Can_m_FdMailBoxMaskErase(const uint8_t Can_Controller_Index);
void Can_m_FdControllerDeInit(const uint8_t Can_Controller_Index);
void Can_m_FdControllerInit(const uint8_t Can_Controller_Index,const Can_ControllerConfigType *Can_ControllerConfig, const Can_InitIndexType InitIndex);
void Can_m_FdGetIntFlag(const uint8_t Can_Controller_Index, Can_Controller_InterruptFlagType *Can_Controller_InterruptFlag, uint8_t *rmc_count);
ClearFlag_ReturnType Can_m_FdClearIntFlag(const uint8_t Can_Controller_Index, Can_Controller_InterruptFlagType *Can_Controller_InterruptFlag,uint8_t rmc_count);
void Can_m_MailboxTriggerSet(const uint8_t Can_Controller_Index,const Can_MailboxNumType MailBox_Number,uint8_t Triger_Count);
Can_ReturnType Can_m_FdMailBoxCode_Set(const uint8_t Can_Controller_Index, const Can_MailboxNumType MailBox_Number,Canfd_MailboxHeaderType *Can_MailboxHeader);
Can_MailBoxType Can_m_FdGetMailBoxState(const uint8_t Can_Controller_Index, const Can_MailboxNumType MailBox_Number);
Can_ReturnType Can_m_FdMailBox_Write(const uint8_t Can_Controller_Index, const Can_MailboxNumType MailBox_Number,Canfd_MailboxHeaderType *Can_MailboxHeader);
Can_ReturnType Can_m_FdMailBox_Read(const uint8_t Can_Controller_Index, const Can_MailboxNumType MailBox_Number,Canfd_MailboxHeaderType *Can_MailboxHeader,Can_MailBoxType Can_MailBoxType);
Can_ReturnType Can_m_FdTransmitpack(const uint8_t Can_Controller_Index);
Can_ReturnType Can_m_FdTransmitonce(const uint8_t Can_Controller_Index);
Can_ReturnType Can_m_FdTransmituntil(const uint8_t Can_Controller_Index,const uint8_t Mailbox_Number);
void Can_m_FdTransmiterrorHandler(void);
void Can_m_FdBusoffHandler(void);
void Can_m_FdFlagclearHandler(void);
void Arbitrate_Handle(const uint8_t Can_Controller_Index);
# 18 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_canfd.h" 2
# 36 "../src/kf32a1x6_canfd_136.c" 2
