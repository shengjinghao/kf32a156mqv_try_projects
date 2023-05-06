# 1 "../src/kf32a1x6_gpio.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\Release//"
# 1 "<command-line>"
# 1 "../src/kf32a1x6_gpio.c"
# 37 "../src/kf32a1x6_gpio.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio.h" 1



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
# 5 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio.h" 2
# 19 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio.h"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio_156.h" 1
# 48 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio_156.h"
typedef enum
{
    GPIO_NOPULL = 0x00,
    GPIO_PULLUP = 0x01
}GPIOPU_TypeDef, GPIOPD_TypeDef;
# 63 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio_156.h"
typedef enum
{
    GPIO_POD_PP = 0x00,
    GPIO_POD_OD = 0x01
}GPIOPOD_TypeDef;






typedef enum
{
    GPIO_MODE_IN = 0x00,
    GPIO_MODE_OUT = 0x01,
    GPIO_MODE_RMP = 0x02,
    GPIO_MODE_AN = 0x03
}GPIOMode_TypeDef;
# 89 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio_156.h"
typedef enum
{
    GPIO_LOW_SPEED = 0,
    GPIO_HIGH_SPEED = 1
}GPIOSpeed_TypeDef;






typedef struct
{
    uint32_t m_Pin;


    GPIOMode_TypeDef m_Mode;


    GPIOSpeed_TypeDef m_Speed;


    GPIOPOD_TypeDef m_OpenDrain;


    GPIOPU_TypeDef m_PullUp;


    GPIOPD_TypeDef m_PullDown;

}GPIO_InitTypeDef;




typedef enum
{
    Bit_RESET = 0,
    Bit_SET = !Bit_RESET
}BitAction;
# 260 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio_156.h"
void GPIO_Reset (GPIO_SFRmap* GPIOx);
void GPIO_Configuration (GPIO_SFRmap* GPIOx, GPIO_InitTypeDef* gpioInitStruct);
void GPIO_Struct_Init (GPIO_InitTypeDef* gpioInitStruct);
void GPIO_Pin_Lock_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState);
void GPIO_Pull_Up_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState);
void GPIO_Toggle_Pull_Up_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
void GPIO_Pull_Down_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState);
void GPIO_Toggle_Pull_Down_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
void GPIO_Open_Drain_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOPOD_TypeDef NewState);
void GPIO_Toggle_Open_Drain_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
void GPIO_Write_Mode_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOMode_TypeDef NewState);
void GPIO_Speed_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOSpeed_TypeDef NewState);
void GPIO_Toggle_Speed_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);


BitAction GPIO_Read_Input_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
uint16_t GPIO_Read_Input_Data (GPIO_SFRmap* GPIOx);
BitAction GPIO_Read_Output_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
uint16_t GPIO_Read_Output_Data (GPIO_SFRmap* GPIOx);
void GPIO_Set_Output_Data_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, BitAction BitsValue);
void GPIO_Toggle_Output_Data_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);


void GPIO_Pin_RMP_Config(GPIO_SFRmap* GPIOx, uint16_t GpioPinNum, uint32_t PinRemap);

void FlexRM_Reset(void);
void FlexRM_Channel_Direction_Select(uint32_t Channel, FunctionalState NewState);
void FlexRM_Group_Enable(uint32_t Channel, FunctionalState NewState);
void FlexRM_Group_Function_Select(uint32_t Group, uint32_t Port);
void FlexRM_Group_Output_Select(uint32_t Group, uint32_t Channel);
void FlexRM_Group_Input_Select(uint32_t Group, uint32_t Channel);
# 20 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio.h" 2
# 38 "../src/kf32a1x6_gpio.c" 2
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
# 39 "../src/kf32a1x6_gpio.c" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pclk.h" 1
# 57 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pclk.h"
void PCLK_CTL0_Peripheral_Clock_Enable (uint32_t PCLK_CTL0_bit,FunctionalState NewState);
void PCLK_CTL1_Peripheral_Clock_Enable (uint32_t PCLK_CTL1_bit,FunctionalState NewState);
void PCLK_CTL2_Peripheral_Clock_Enable (uint32_t PCLK_CTL2_bit,FunctionalState NewState);
void PCLK_CTL3_Peripheral_Clock_Enable (uint32_t PCLK_CTL3_bit,FunctionalState NewState);
# 40 "../src/kf32a1x6_gpio.c" 2
# 50 "../src/kf32a1x6_gpio.c"
void GPIO_Reset (GPIO_SFRmap * GPIOx)
{

 ((void)0);

 if (GPIOx == ((GPIO_SFRmap *) ((uint32_t)0x50000000)))
 {
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((0))), TRUE);
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((0))), FALSE);
  PCLK_CTL0_Peripheral_Clock_Enable(((uint32_t)1<<((0x0))), TRUE);
 }
 else if (GPIOx == ((GPIO_SFRmap *) ((uint32_t)0x50000040)))
 {
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((1))), TRUE);
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((1))), FALSE);
  PCLK_CTL0_Peripheral_Clock_Enable(((uint32_t)1<<((0x1))), TRUE);
 }
 else if (GPIOx == ((GPIO_SFRmap *) ((uint32_t)0x50000080)))
 {
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((2))), TRUE);
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((2))), FALSE);
  PCLK_CTL0_Peripheral_Clock_Enable(((uint32_t)1<<((0x2))), TRUE);
 }
 else if (GPIOx == ((GPIO_SFRmap *) ((uint32_t)0x500000C0)))
 {
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((3))), TRUE);
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((3))), FALSE);
  PCLK_CTL0_Peripheral_Clock_Enable(((uint32_t)1<<((0x3))), TRUE);
 }
 else if (GPIOx == ((GPIO_SFRmap *) ((uint32_t)0x50000100)))
 {
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((4))), TRUE);
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((4))), FALSE);
  PCLK_CTL0_Peripheral_Clock_Enable(((uint32_t)1<<((0x4))), TRUE);
 }
 else if (GPIOx == ((GPIO_SFRmap *) ((uint32_t)0x50000140)))
 {
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((5))), TRUE);
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((5))), FALSE);
  PCLK_CTL0_Peripheral_Clock_Enable(((uint32_t)1<<((0x5))), TRUE);
 }
 else if (GPIOx == ((GPIO_SFRmap *) ((uint32_t)0x50000180)))
 {
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((6))), TRUE);
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((6))), FALSE);
  PCLK_CTL0_Peripheral_Clock_Enable(((uint32_t)1<<((0x6))), TRUE);
 }
 else if (GPIOx == ((GPIO_SFRmap *) ((uint32_t)0x500001C0)))
 {
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((7))), TRUE);
  RST_CTL0_Peripheral_Reset_Enable(((uint32_t)1<<((7))), FALSE);
  PCLK_CTL0_Peripheral_Clock_Enable(((uint32_t)1<<((0x7))), TRUE);
 }
 else
 {
  ;
 }
}







void GPIO_Configuration (GPIO_SFRmap* GPIOx, GPIO_InitTypeDef* gpioInitStruct)
{
    uint32_t pinpos;
    uint32_t pos;
    uint32_t currentpin;
    uint32_t tmpreg;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    for (pinpos = 0x00; pinpos < 0x10; pinpos++)
    {
        pos = ((uint32_t)0x01) << pinpos;

        currentpin = (gpioInitStruct->m_Pin) & pos;

        if (currentpin == pos)
        {


            tmpreg = (((uint32_t)gpioInitStruct->m_Mode) << (pinpos * 2));
            GPIOx->PMOD = SFR_Config (GPIOx->PMOD,
                                  ~(((uint32_t)3<<((0))) << (pinpos * 2)),
                                  tmpreg);

            if ((gpioInitStruct->m_Mode == GPIO_MODE_OUT)
                || (gpioInitStruct->m_Mode == GPIO_MODE_RMP))
            {

                ((void)0);



                tmpreg = (((uint32_t)gpioInitStruct->m_OpenDrain) << (pinpos));
                GPIOx->PODR = SFR_Config (GPIOx->PODR,
                                      ~(((uint32_t)1<<((0))) << pinpos),
                                      tmpreg);
            }
            else
            {
                ;
            }



            tmpreg = ((uint32_t)gpioInitStruct->m_Speed) << (pinpos * 2);
            GPIOx->OMOD = SFR_Config (GPIOx->OMOD,
                                  ~(((uint32_t)1<<((0))) << (pinpos * 2)),
                                  tmpreg);



            tmpreg = (((uint32_t)gpioInitStruct->m_PullUp) << (pinpos));
            GPIOx->PUR = SFR_Config (GPIOx->PUR,
                                  ~(((uint32_t)1<<((0))) << pinpos),
                                  tmpreg);



            tmpreg = (((uint32_t)gpioInitStruct->m_PullDown) << (pinpos));
            GPIOx->PDR = SFR_Config (GPIOx->PDR,
                                  ~(((uint32_t)1<<((0))) << pinpos),
                                  tmpreg);
        }
        else
        {
            ;
        }
    }
}






void GPIO_Struct_Init (GPIO_InitTypeDef* gpioInitStruct)
{

    gpioInitStruct->m_Pin = ((uint16_t)0xFFFF);


    gpioInitStruct->m_Mode = GPIO_MODE_AN;


    gpioInitStruct->m_Speed = GPIO_LOW_SPEED;


    gpioInitStruct->m_OpenDrain = GPIO_POD_PP;


    gpioInitStruct->m_PullUp = GPIO_NOPULL;


    gpioInitStruct->m_PullDown = GPIO_NOPULL;
}
# 226 "../src/kf32a1x6_gpio.c"
void GPIO_Pin_Lock_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState)
{
 uint32_t tmpreg = 0x5C5A0000;


 ((void)0);
 ((void)0);
 ((void)0);


 tmpreg |= GPIOx->LOCK;


 if(NewState != FALSE)
 {

  tmpreg |= (uint32_t)GpioPin;
 }
 else
 {

  tmpreg &= ~((uint32_t)GpioPin);
 }


    GPIOx->LOCK = tmpreg;
}
# 262 "../src/kf32a1x6_gpio.c"
void GPIO_Pull_Up_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState)
{

 ((void)0);
 ((void)0);
 ((void)0);


 if(NewState != FALSE)
 {

  GPIOx->PUR |= (uint32_t)GpioPin;
 }
 else
 {

  GPIOx->PUR &= ~((uint32_t)GpioPin);
 }
}
# 289 "../src/kf32a1x6_gpio.c"
void GPIO_Toggle_Pull_Up_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{

 ((void)0);
 ((void)0);


 GPIOx->PUR ^= (uint32_t)GpioPin;
}
# 307 "../src/kf32a1x6_gpio.c"
void GPIO_Pull_Down_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, FunctionalState NewState)
{

 ((void)0);
 ((void)0);
 ((void)0);


 if(NewState != FALSE)
 {

  GPIOx->PDR |= (uint32_t)GpioPin;
 }
 else
 {

  GPIOx->PDR &= ~((uint32_t)GpioPin);
 }
}
# 334 "../src/kf32a1x6_gpio.c"
void GPIO_Toggle_Pull_Down_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{

 ((void)0);
 ((void)0);


 GPIOx->PDR ^= (uint32_t)GpioPin;
}
# 354 "../src/kf32a1x6_gpio.c"
void GPIO_Open_Drain_Enable (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOPOD_TypeDef NewState)
{

 ((void)0);
 ((void)0);
 ((void)0);


 if(NewState != GPIO_POD_PP)
 {

  GPIOx->PODR |= (uint32_t)GpioPin;
 }
 else
 {

  GPIOx->PODR &= ~((uint32_t)GpioPin);
 }
}
# 381 "../src/kf32a1x6_gpio.c"
void GPIO_Toggle_Open_Drain_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{

 ((void)0);
 ((void)0);


 GPIOx->PODR ^= (uint32_t)GpioPin;
}
# 403 "../src/kf32a1x6_gpio.c"
void GPIO_Write_Mode_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOMode_TypeDef NewState)
{
 uint32_t pinpos = 0x00;
 uint32_t tmpreg;


 ((void)0);
 ((void)0);
 ((void)0);


 tmpreg = GPIOx->PMOD;
 while(GpioPin)
 {
  if(GpioPin & (uint16_t)0x01)
  {

            tmpreg &= ~(((uint32_t)3<<((0))) << pinpos);
            tmpreg |= (uint32_t)NewState << pinpos;
  }
  else
  {
   ;
  }
  GpioPin >>= 1;
  pinpos += 2;
 }


    GPIOx->PMOD = tmpreg;
}
# 445 "../src/kf32a1x6_gpio.c"
void GPIO_Speed_Config (GPIO_SFRmap* GPIOx,uint16_t GpioPin, GPIOSpeed_TypeDef NewState)
{
 uint32_t pinpos = 0x00;
 uint32_t tmpreg;


 ((void)0);
 ((void)0);
 ((void)0);


 tmpreg = GPIOx->OMOD;
 while(GpioPin)
 {
  if(GpioPin & (uint16_t)0x01)
  {
   tmpreg &= ~((((uint32_t)1<<((0)))) << pinpos);
   tmpreg |= (uint32_t)NewState << pinpos;
  }
  else
  {
   ;
  }
  GpioPin >>= 1;
  pinpos += 2;
 }


    GPIOx->OMOD = tmpreg;
}
# 483 "../src/kf32a1x6_gpio.c"
void GPIO_Toggle_Speed_Config(GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
 uint32_t pinpos = 0x00;
 uint32_t tmpreg;


 ((void)0);
 ((void)0);


 tmpreg = GPIOx->OMOD;
 while(GpioPin)
 {
  if(GpioPin & (uint16_t)0x01)
  {
   tmpreg ^= ((uint32_t)1<<((0))) << pinpos;
  }
  else
  {
   ;
  }
  GpioPin >>= 1;
  pinpos += 2;
 }


    GPIOx->OMOD = tmpreg;
}
# 527 "../src/kf32a1x6_gpio.c"
BitAction GPIO_Read_Input_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)GpioPin;
    if ((GPIOx->PIR & tmpreg) != Bit_RESET)
    {

        return Bit_SET;
    }
    else
    {

        return Bit_RESET;
    }
}






uint16_t GPIO_Read_Input_Data (GPIO_SFRmap* GPIOx)
{
 uint32_t tmpreg;


    ((void)0);


    tmpreg = GPIOx->PIR;

    return (uint16_t)tmpreg;
}







BitAction GPIO_Read_Output_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
 uint32_t tmpreg;


    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)GpioPin;
    if ((GPIOx->POR & tmpreg) != Bit_RESET)
    {

        return Bit_SET;
    }
    else
    {

        return Bit_RESET;
    }
}






uint16_t
GPIO_Read_Output_Data (GPIO_SFRmap* GPIOx)
{
 uint32_t tmpreg;


    ((void)0);


    tmpreg = GPIOx->POR;

    return (uint16_t)tmpreg;
}
# 624 "../src/kf32a1x6_gpio.c"
void GPIO_Set_Output_Data_Bits (GPIO_SFRmap* GPIOx,uint16_t GpioPin, BitAction BitsValue)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (BitsValue != Bit_RESET)
    {

        GPIOx->POR |= (uint32_t)GpioPin;
    }
    else
    {

        GPIOx->POR &= ~((uint32_t)GpioPin);
    }
}
# 651 "../src/kf32a1x6_gpio.c"
void GPIO_Toggle_Output_Data_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{

    ((void)0);


    GPIOx->POR ^= (uint32_t)GpioPin;
}
# 692 "../src/kf32a1x6_gpio.c"
void GPIO_Pin_RMP_Config(GPIO_SFRmap* GPIOx, uint16_t GpioPinNum, uint32_t PinRemap)
{
    uint32_t tmask;
 uint32_t tmpreg;
    uint32_t PageNum = (PinRemap&0x300)>>8;


    ((void)0);
    ((void)0);


    tmask = ((uint32_t)1 << (GpioPinNum+16)) + ((uint32_t)1 << GpioPinNum);
    tmpreg = ((uint32_t)((PageNum-1)/2) << (GpioPinNum+16)) + ((uint32_t)((PageNum-1)%2) << GpioPinNum);
    GPIOx->RMP_MSB = SFR_Config(GPIOx->RMP_MSB,~tmask,tmpreg);


    if(GpioPinNum <= ((uint32_t)0x7))
    {
     tmask = 0xF << (GpioPinNum*4);
     tmpreg = (PinRemap&0xF) << (GpioPinNum*4);
     GPIOx->RMP[0] = SFR_Config(GPIOx->RMP[0],~tmask,tmpreg);
    }
    else if(GpioPinNum <= ((uint32_t)0xF))
    {
     tmask = 0xF << ((GpioPinNum - 8)*4);
     tmpreg = (PinRemap&0xF) << ((GpioPinNum - 8)*4);
     GPIOx->RMP[1] = SFR_Config(GPIOx->RMP[1],~tmask,tmpreg);
    }
}
# 736 "../src/kf32a1x6_gpio.c"
void FlexRM_Reset(void)
{
 RST_CTL3_Peripheral_Reset_Enable(((uint32_t)1<<((25))), TRUE);
 RST_CTL3_Peripheral_Reset_Enable(((uint32_t)1<<((25))), FALSE);
 PCLK_CTL3_Peripheral_Clock_Enable(((uint32_t)1<<((25))), TRUE);
}
# 762 "../src/kf32a1x6_gpio.c"
void FlexRM_Channel_Direction_Select(uint32_t Channel, uint32_t Direction)
{
 uint32_t tmpreg;
 uint32_t tmask;


 ((void)0);
 ((void)0);

 tmpreg = Direction << (Channel+(12));
 tmask = 1 << (Channel+(12));
 (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->CTL) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->CTL), ~tmask, tmpreg);
}
# 795 "../src/kf32a1x6_gpio.c"
void FlexRM_Group_Enable(uint32_t Group, FunctionalState NewState)
{
 uint32_t tmpreg;
 uint32_t tmask;


 ((void)0);
 ((void)0);

 tmpreg = NewState << Group;
 tmask = 1 << Group;
 (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->CTL) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->CTL), ~tmask, tmpreg);
}
# 841 "../src/kf32a1x6_gpio.c"
void FlexRM_Group_Function_Select(uint32_t Group, uint32_t Port)
{
 uint32_t tmpreg;
 uint32_t tmask;


 ((void)0);
 ((void)0);

 if(Group <= ((uint32_t)7))
 {
  tmpreg = Port << Group*4;
  tmask = 0xF << Group*4;
  (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GPSR0) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GPSR0), ~tmask, tmpreg);
 }
 else
 {
  tmpreg = Port << (Group - 8)*4;
  tmask = 0xF << (Group - 8)*4;
  (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GPSR1) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GPSR1), ~tmask, tmpreg);
 }
}
# 894 "../src/kf32a1x6_gpio.c"
void FlexRM_Group_Output_Select(uint32_t Group, uint32_t Channel)
{
 uint32_t tmpreg;
 uint32_t tmask;


 ((void)0);
 ((void)0);

 if(Channel <= 3)
 {
  tmpreg = Group << Channel*8;
  tmask = 0xF << Channel*8;
  (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR0) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR0), ~tmask, tmpreg);
 }
 else if(Channel <= 7)
 {
  tmpreg = Group << (Channel - 4)*8;
  tmask = 0xF << (Channel - 4)*8;
  (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR1) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR1), ~tmask, tmpreg);
 }
 else
 {
  tmpreg = Group << (Channel - 8)*8;
  tmask = 0xF << (Channel - 8)*8;
  (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR2) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR2), ~tmask, tmpreg);
 }
}
# 953 "../src/kf32a1x6_gpio.c"
void FlexRM_Group_Input_Select(uint32_t Group, uint32_t Channel)
{
 uint32_t tmpreg;
 uint32_t tmask;


 ((void)0);
 ((void)0);

 if(Group <= 3)
 {
  tmpreg = Channel << ((4) + Group*8);
  tmask = 0xF0 << ((4) + Group*8);
  (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR0) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR0), ~tmask, tmpreg);
 }
 else if(Group <= 7)
 {
  tmpreg = Channel << ((4) + (Group - 4)*8);
  tmask = 0xF0 << ((4) + (Group - 4)*8);
  (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR1) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR1), ~tmask, tmpreg);
 }
 else
 {
  tmpreg = Channel << ((4) + (Group - 8)*8);
  tmask = 0xF0 << ((4) + (Group - 8)*8);
  (((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR2) = SFR_Config((((FlexRM_SFRmap *) ((uint32_t) 0x40002D80))->GCSR2), ~tmask, tmpreg);
 }
}
