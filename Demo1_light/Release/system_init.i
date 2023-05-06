# 1 "../system_init.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\Release//"
# 1 "<command-line>"
# 1 "../system_init.c"
# 30 "../system_init.c"
# 1 "../system_init.h" 1
# 32 "../system_init.h"
# 1 "D:/KungFu32_/ChipONCC32/include/Sys/string.h" 1
# 17 "D:/KungFu32_/ChipONCC32/include/Sys/string.h"
typedef unsigned int size_t;






extern int ffs (int);
extern int ffsl (long);
extern int ffsll (long long);
extern void * memchr(const void *, int, size_t);
extern int memcmp(const void *, const void *, size_t);
extern void * memcpy(void *, const void *, size_t);
extern void * memmove(void *, const void *, size_t);
extern void * memset(void *, int, size_t);
extern int strcasecmp (const char *, const char *);
extern char * strcat(char *, const char *);
extern char * strchr(const char *, int);
extern int strcmp(const char *, const char *);
extern int strcoll(const char *, const char *);
extern char * strcpy(char *, const char *);
extern size_t strcspn(const char *, const char *);

extern size_t strlen(const char *);
extern int strncasecmp (const char *, const char *, size_t);
extern char * strncat(char *, const char *, size_t);
extern int strncmp(const char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern char * strpbrk(const char *, const char *);
extern char * strrchr(const char *, int);
extern size_t strspn(const char *, const char *);
extern char * strstr(const char *, const char *);
extern char * strtok(char *, const char *);
extern size_t strxfrm(char *, const char *, size_t);


extern char * strdup(const char *);
# 33 "../system_init.h" 2
# 1 "D:/KungFu32_/ChipONCC32/include/Sys/stdint.h" 1
# 16 "D:/KungFu32_/ChipONCC32/include/Sys/stdint.h"
# 1 "D:/KungFu32_/ChipONCC32/include/Sys/stddef.h" 1
# 24 "D:/KungFu32_/ChipONCC32/include/Sys/stddef.h"
typedef int ptrdiff_t;
# 35 "D:/KungFu32_/ChipONCC32/include/Sys/stddef.h"
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
# 34 "../system_init.h" 2
# 1 "D:/KungFu32_/ChipONCC32/include/Sys/stdio.h" 1
# 10 "D:/KungFu32_/ChipONCC32/include/Sys/stdio.h"
# 1 "D:/KungFu32_/ChipONCC32/include/Sys/stdarg.h" 1
# 9 "D:/KungFu32_/ChipONCC32/include/Sys/stdarg.h"
typedef unsigned char * va_list;
# 11 "D:/KungFu32_/ChipONCC32/include/Sys/stdio.h" 2
# 25 "D:/KungFu32_/ChipONCC32/include/Sys/stdio.h"
typedef void *STREAM;
# 55 "D:/KungFu32_/ChipONCC32/include/Sys/stdio.h"
extern char getchar (void);
extern char fgetchar (STREAM *stream);

extern int putchar (int c);
extern int fputchar (int c,STREAM *stream);
# 102 "D:/KungFu32_/ChipONCC32/include/Sys/stdio.h"
extern int puts (const char *);
extern int fputs(const char *str,STREAM *stream);




extern char _scanf_buf_[256];

extern char getche(void);





extern char * gets(char * s);
extern char * cgets(char * s);

extern int scanf (const char * fmt, ...);
extern int vscanf (const char * fmt, va_list ap);

extern int fscanf (const char * str,const char * fmt, ...);
extern int sscanf (const char * str,const char * fmt, ...);

extern int vsscanf(const char * str,const char * fmt, va_list ap);




extern int printf (const char *fmt, ...);

extern int fprintf (STREAM *stream, const char *fmt, ...);
extern int sprintf (char *str, const char *fmt, ...);




extern int vprintf (const char *fmt, va_list ap);
extern int vfprintf (STREAM *stream, const char *fmt, va_list ap);
extern int vsprintf (char *str, const char *fmt, va_list ap);





extern void printf_small (const char *fmt, ...);
extern void printf_tiny (const char *fmt, ...);
# 35 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6.h" 1



# 1 "D:\\KungFu32\\workspace32\\Demo1_light/__Kungfu32_chipmodel_define.h" 1
# 5 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6.h" 2
# 32 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6.h"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/KF32A156.h" 1
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
# 36 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_adc.h" 1
# 30 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_adc.h"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6.h" 1
# 31 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_adc.h" 2





typedef struct
{
    uint32_t m_Clock;

    uint32_t m_ClockDiv;

    FunctionalState m_ScanMode;

    uint32_t m_ContinuousMode;

    uint32_t m_DataAlign;

    FunctionalState m_ExternalTrig_EN;

    uint32_t m_ExternalTrig;

    FunctionalState m_HPExternalTrig_EN;

    uint32_t m_HPExternalTrig;

    uint32_t m_VoltageRef;

    uint32_t m_NumOfConv;

    uint32_t m_NumOfHPConv;

}ADC_InitTypeDef;




typedef struct
{
    uint32_t m_FastDelay;

    uint32_t m_SlowDelay;

}ADC0_DELAY_InitTypeDef;




typedef struct
{
    uint32_t m_WDSingleCH;

    FunctionalState m_HPChannelWDEN;

    FunctionalState m_ChannelWDEN;

    uint32_t m_WDChannel;

    uint32_t m_Threshold_H;

    uint32_t m_Threshold_L;

}ADC_WD_InitTypeDef;
# 987 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_adc.h"
void ADC_Reset (ADC_SFRmap* ADCx);
void ADC_Configuration (ADC_SFRmap* ADCx, ADC_InitTypeDef* adcInitStruct);
void ADC_Delay_Configuration (ADC0_DELAY_InitTypeDef* adc0Delay);
void ADC_Delay_Struct_Init (ADC0_DELAY_InitTypeDef* adc0Delay);
void ADC_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);

void ADC_Analog_Watchdog_Configuration (ADC_SFRmap* ADCx,ADC_WD_InitTypeDef * adcAnalogWatchdog);
void ADC_Analog_Watchdog_Struct_Init (ADC_WD_InitTypeDef* adcAnalogWatchdog);

void ADC_Watchdog_Single_Channel_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_Scan_Mode_Enable (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_Bosssel_Comparator_Calibration (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_Bosssel_Calibration (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_Trim_Current_Intensity_Bias (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_Analog_Clock_Config (ADC_SFRmap* ADCx, uint32_t ClockSelect);
void ADC_Data_Align_Config (ADC_SFRmap* ADCx, uint32_t DataAlign);
void ADC_Clock_Source_Config (ADC_SFRmap* ADCx, uint32_t ClockSource);
void ADC_Regular_Channel_DMA_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_High_Priority_Channel_DMA_Cmd (ADC_SFRmap* ADCx,uint32_t HPChannel,FunctionalState NewState);
void ADC_Double_Mode_Config (uint32_t WorkMode);
void ADC_Reference_Voltage_Config (ADC_SFRmap* ADCx, uint32_t RefVoltage);
void ADC_Analog_Watchdog_Channel_Config (ADC_SFRmap* ADCx, uint32_t Channel);
void ADC_Extra_Sampling_Time(ADC_SFRmap* ADCx, uint32_t ExTime);

void ADC_Regular_Channel_Watchdog_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_External_Trig_Conv_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_External_Trig_Conv_Config (ADC_SFRmap* ADCx,uint32_t ExternalTrigEvent);
void ADC_Regular_Channel_Config (ADC_SFRmap* ADCx,uint32_t Channel, uint32_t Rank);
void ADC_Regular_Sequencer_Length_Config (ADC_SFRmap* ADCx, uint32_t Length);
void ADC_Regular_Channel_TxCCRy_Trig_Enable (ADC_SFRmap* ADCx,uint32_t ExternalTrigEvent, FunctionalState NewState);
void ADC_Software_Start_Conv(ADC_SFRmap* ADCx);
void ADC_Continuous_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_Disc_Mode_Channel_Count_Config (ADC_SFRmap* ADCx, uint8_t Number);
void ADC_Disc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
uint16_t ADC_Get_Conversion_Value (ADC_SFRmap* ADCx);

void ADC_High_Priority_Watchdog_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_HPExternal_Trig_Conv_Enable (ADC_SFRmap* ADCx,FunctionalState NewState);
void ADC_High_Priority_Channel_Config (ADC_SFRmap* ADCx,uint32_t Channel, uint32_t Rank);
void ADC_High_Priority_Sequencer_Length_Config (ADC_SFRmap* ADCx,uint32_t Length);
void ADC_High_Priority_TxCCRy_Trig_Enable (ADC_SFRmap* ADCx,uint32_t ExternalTrigEvent, FunctionalState NewState);
void ADC_Set_HPChannel_Conv_Value_Offset (ADC_SFRmap* ADCx,uint32_t HPDoffChannel, uint32_t Offset);
void ADC_HPExternal_Trig_Conv_Config (ADC_SFRmap* ADCx,uint32_t HPExternalTrigEvent);
void ADC_Software_HPStart_Conv (ADC_SFRmap* ADCx);
void ADC_HPAuto_Conv_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_HPDisc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
uint16_t ADC_Get_HPConversion_Data (ADC_SFRmap* ADCx, uint8_t HPDataChannel);

void ADC_Set_INT_Enable (ADC_SFRmap* ADCx,uint32_t InterruptType, FunctionalState NewState);
FlagStatus ADC_Get_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType);
RetStatus ADC_Clear_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType);
INTStatus ADC_Get_INT_Status (ADC_SFRmap* ADCx, uint32_t InterruptType);
# 37 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_aes.h" 1
# 92 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_aes.h"
void AES_Reset ();
void AES_Run_Enable(FunctionalState NewState);
void AES_High_Speed_Enable(FunctionalState NewState);
void AES_CBC_Mode_Select(uint32_t Mode);
void AES_TRNG_SCK_Select(uint32_t Source);
void AES_SCK_DIV_Select(uint32_t CLKDIV);
void AES_RND_NUM_Config(uint32_t RNG_NUM);
void AES_KEY_LEN_Config(uint32_t KEY_LEN);
void AES_SBOX_INV_Enable(uint32_t SBOXMODE);
void AES_ENCRYPT_Function_Enable(uint32_t EN_DECRYPT);
void AES_CUSTOMIZE_ALGORITHM_Enable(uint32_t ALGORITHM);
void AES_Enable(FunctionalState NewState);


FlagStatus AES_Get_INT_Flag(void);
void AES_Clear_INT_Flag(void);
void AES_INT_Enable(AbleStatus NewState);


void AES_INPUT0_DATA (uint32_t DATA);
void AES_INPUT1_DATA (uint32_t DATA);
void AES_INPUT2_DATA (uint32_t DATA);
void AES_INPUT3_DATA (uint32_t DATA);

uint32_t GET_AES_OUTPUT0_DATA (void);
uint32_t GET_AES_OUTPUT1_DATA (void);
uint32_t GET_AES_OUTPUT2_DATA (void);
uint32_t GET_AES_OUTPUT3_DATA (void);
# 38 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_atim.h" 1
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
# 39 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_bkp.h" 1
# 80 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_bkp.h"
void BKP_Reset (void);
void BKP_Write_And_Read_Enable (FunctionalState NewState);


void BKP_Reset_Enable (FunctionalState NewState);
void BKP_Pin_Effective_Level_Config (uint32_t PinSel, uint32_t Effective);
void BKP_Pin_Enable (uint32_t PinSel, FunctionalState NewState);
void BKP_External_Clock_Bypass_Enable (uint32_t Source,FunctionalState NewState);
void BKP_Data_Config (uint32_t OrderNumber, uint32_t WriteData);
uint32_t BKP_Get_Data (uint32_t OrderNumber);
void BKP_TAMP_SYNC_Mode_Select(uint32_t Mode);
void BKP_TAMP_SCK_Select(uint32_t CLK);


void BKP_Pin_TAMP_INT_Enable (uint32_t PinSel, FunctionalState NewState);
FlagStatus BKP_Get_Pin_TAMP_INT_Flag (uint32_t PinSel);
RetStatus BKP_Clear_Pin_TAMP_INT_Flag (uint32_t PinSel);
# 40 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_btim.h" 1
# 64 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_btim.h"
typedef struct
{
    uint16_t m_Counter;
    uint16_t m_Period;
    uint16_t m_Prescaler;
    uint16_t m_CounterMode;

    uint16_t m_Clock;

    uint16_t m_WorkMode;

    uint16_t m_MasterMode;

    uint16_t m_SlaveMode;

    uint16_t m_EXPulseSync;

    uint16_t m_MasterSlaveSync;

} BTIM_InitTypeDef;
# 172 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_btim.h"
void TIM_Reset (void* TIMx);
void BTIM_Reset (BTIM_SFRmap* BTIMx);


void BTIM_Configuration (BTIM_SFRmap* BTIMx,BTIM_InitTypeDef* btimInitStruct);
void BTIM_Struct_Init (BTIM_InitTypeDef* btimInitStruct);
void BTIM_Cmd (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Set_Counter (BTIM_SFRmap* BTIMx, uint16_t Counter);
void BTIM_Set_Period (BTIM_SFRmap* BTIMx, uint16_t Period);
void BTIM_Set_Prescaler (BTIM_SFRmap* BTIMx, uint16_t Prescaler);
void BTIM_Counter_Mode_Config (BTIM_SFRmap* BTIMx, uint32_t CounterMode);
void BTIM_Clock_Config (BTIM_SFRmap* BTIMx, uint32_t NewClock);
void BTIM_External_Pulse_Sync_Config (BTIM_SFRmap* BTIMx, uint32_t PulseSync);
void BTIM_Work_Mode_Config (BTIM_SFRmap* BTIMx, uint32_t NewState);
void BTIM_Generate_Trigger_Config (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Single_Pulse_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Single_Pulse_Shut_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Updata_Immediately_Config (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Master_Slave_Snyc_Config (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Trigger_Select_Config (BTIM_SFRmap* BTIMx,uint32_t TriggerSelect);
void BTIM_Slave_Mode_Config (BTIM_SFRmap* BTIMx,uint32_t SlaveMode);
void BTIM_Master_Mode_Config (BTIM_SFRmap* BTIMx,uint32_t MasterMode);
void BTIM_Updata_Rising_Edge_Config (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Updata_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState);
DIRStatus BTIM_Get_Direction (BTIM_SFRmap* BTIMx);
uint16_t BTIM_Get_Counter (BTIM_SFRmap* BTIMx);
uint16_t BTIM_Get_Period (BTIM_SFRmap* BTIMx);
uint16_t BTIM_Get_Prescaler (BTIM_SFRmap* BTIMx);


void BTIM_Trigger_DMA_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Updata_DMA_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Overflow_INT_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Trigger_INT_Enable (BTIM_SFRmap* BTIMx,FunctionalState NewState);
void BTIM_Updata_INT_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState);
INTStatus BTIM_Get_Trigger_DMA_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Updata_DMA_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Overflow_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Trigger_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Updata_INT_Status (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Trigger_DMA_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Updata_DMA_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Overflow_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Trigger_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Updata_INT_Flag (BTIM_SFRmap* BTIMx);
RetStatus BTIM_Clear_Overflow_INT_Flag (BTIM_SFRmap* BTIMx);
RetStatus BTIM_Clear_Trigger_INT_Flag (BTIM_SFRmap* BTIMx);
RetStatus BTIM_Clear_Updata_INT_Flag (BTIM_SFRmap* BTIMx);
# 41 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_can.h" 1
# 33 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_can.h"
typedef enum
{
 Standard_Frame,
 Extended_Frame
}Frame_Typedef;

typedef struct
{
 uint32_t Acceptance_Code;
 uint32_t Mask_Code;
 Frame_Typedef Frame_Type;
}Filter_Group_Typedef;





typedef struct
{
    FunctionalState m_Enable;

    uint32_t m_Mode;

    uint32_t m_WorkSource;

    uint8_t m_BaudRate;

    uint8_t m_SyncJumpWidth;

    uint8_t m_TimeSeg1;

    uint8_t m_TimeSeg2;

    uint32_t m_BusSample;

    Filter_Group_Typedef *Filter_Group_Ptr;

}CAN_InitTypeDef;




typedef struct
{
    uint8_t m_ErrorCode;

    uint8_t m_ErrorDirection;

    uint8_t m_ErrorSegment;

    uint8_t m_ArbitrationLost;

}CAN_ErrorTypeDef;




typedef struct
{
    uint32_t m_FrameFormat;

    uint32_t m_RemoteTransmit;

    uint32_t m_DataLength;

    uint32_t m_Can_ID;

    uint8_t m_Data[8];

}CAN_MessageTypeDef;



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

  }RXDATA0;
  struct
  {
   volatile uint32_t DATA1:8;
   volatile uint32_t DATA0:8;
   volatile uint32_t RESERVED0:4;
   volatile uint32_t RTR:1;
   volatile uint32_t ID:11;
  }RXDATA1;
  struct
  {
   volatile uint32_t DATA5:8;
   volatile uint32_t DATA4:8;
   volatile uint32_t DATA3:8;
   volatile uint32_t DATA2:8;
  }RXDATA2;
  struct
  {
   volatile uint32_t RESERVED0:8;
   volatile uint32_t RESERVED1:8;
   volatile uint32_t DATA7:8;
   volatile uint32_t DATA6:8;
  }RXDATA3;
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
  }RXDATA0;
  struct
  {
   volatile uint32_t RESERVED:2;
   volatile uint32_t RTR:1;
   volatile uint32_t ID:29;
  }RXDATA1;
  struct
  {
   volatile uint32_t DATA3:8;
   volatile uint32_t DATA2:8;
   volatile uint32_t DATA1:8;
   volatile uint32_t DATA0:8;
  }RXDATA2;
  struct
  {
   volatile uint32_t DATA7:8;
   volatile uint32_t DATA6:8;
   volatile uint32_t DATA5:8;
   volatile uint32_t DATA4:8;
  }RXDATA3;
 }EFF;
}CanRxBufferTypeDef;
# 436 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_can.h"
void CAN_Reset(CAN_SFRmap* CANx);
void CAN_Configuration_With_Reset_Mode(CAN_SFRmap* CANx, CAN_InitTypeDef* canInitStruct);
void CAN_Struct_Init (CAN_InitTypeDef* canInitStruct);

uint32_t CAN_Get_Receive_Message_Counter (CAN_SFRmap* CANx);
FlagStatus CAN_Get_Transmit_Status (CAN_SFRmap* CANx, uint32_t Type);
void CAN_Cmd (CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Clock_Source_Config (CAN_SFRmap* CANx, uint32_t ClockSource);
void CAN_Sleep_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Reset_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Work_Mode_Config (CAN_SFRmap* CANx, uint32_t ModeType);
void CAN_Bus_Sample_Times_Config (CAN_SFRmap* CANx, uint32_t Times);
void CAN_Time_Segment_Config (CAN_SFRmap* CANx,uint32_t TimeSeg1, uint32_t TimeSeg2);
void CAN_Sync_Jump_Width_Config (CAN_SFRmap* CANx, uint32_t JumpWidth);
void CAN_Baud_Rate_Preset_Config (CAN_SFRmap* CANx, uint32_t BaudRate);
void CAN_Get_Error_Code (CAN_SFRmap* CANx, CAN_ErrorTypeDef* canErrorStruct);
uint8_t CAN_Get_Error_Warning_Limit (CAN_SFRmap* CANx);
uint8_t CAN_Get_Error_Counter (CAN_SFRmap* CANx, uint32_t Direction);
void CAN_Error_Warning_Limit_Config (CAN_SFRmap* CANx, uint8_t ErrorLimit);
void CAN_Error_Counter_Config (CAN_SFRmap* CANx,uint32_t Direction, uint8_t ErrorCounter);
void CAN_Acceptance_Config (CAN_SFRmap* CANx, uint32_t Acceptance);
uint32_t CAN_Get_Acceptance (CAN_SFRmap* CANx);
void CAN_Acceptance_Mask_Config (CAN_SFRmap* CANx, uint32_t Acceptance);
uint32_t CAN_Get_Acceptance_Mask (CAN_SFRmap* CANx);

void CAN_Transmit_Message_Configuration (CAN_SFRmap* CANx,CAN_MessageTypeDef* canInitStruct);
void CAN_Message_Struct_Init (CAN_MessageTypeDef* canInitStruct);
RetStatus CAN_Clear_Buffer_Overflow_Flag (CAN_SFRmap* CANx);
void CAN_Release_Receive_Buffer (CAN_SFRmap* CANx, uint32_t ReleaseCount);
RetStatus CAN_Transmit_Single (CAN_SFRmap* CANx);
RetStatus CAN_Transmit_Repeat (CAN_SFRmap* CANx);
void CAN_Frame_Format_Config (CAN_SFRmap* CANx, uint32_t FrameFormat);
void CAN_Remote_Request_Config (CAN_SFRmap* CANx, uint32_t RemoteRequest);
void CAN_Data_Length_Config (CAN_SFRmap* CANx, uint32_t Length);
void CAN_Identification_Code_Config (CAN_SFRmap* CANx,uint32_t FrameFormat, uint32_t IDCode);

FlagStatus CAN_Get_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType);
void CAN_Clear_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType);
void CAN_Set_INT_Enable (CAN_SFRmap* CANx,uint32_t InterruptType, FunctionalState NewState);
void CAN_Set_Reseive_DMA_Enable(CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Set_Send_DMA_Enable(CAN_SFRmap* CANx, FunctionalState NewState);
FlagStatus CAN_Get_Receive_DMA_Flag(CAN_SFRmap* CANx);
FlagStatus CAN_Get_Send_DMA_Flag(CAN_SFRmap* CANx);
# 42 "../system_init.h" 2
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
# 43 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_cfgl.h" 1
# 40 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_cfgl.h"
typedef struct
{
 uint32_t m_Module_EN;

 uint32_t m_Output_EN;

 uint32_t m_RaiseINT_EN;

 uint32_t m_FallINT_EN;

 uint32_t m_Mode_Sel;

 uint32_t m_Output_Pol;

 uint32_t m_G4Output_POL;

 uint32_t m_G3Output_POL;

 uint32_t m_G2Output_POL;

 uint32_t m_G1Output_POL;

 uint32_t m_G4Input_Sel;

 uint32_t m_G3Input_Sel;

 uint32_t m_G2Input_Sel;

 uint32_t m_G1Input_Sel;

 uint32_t m_CH4Data_Sel;

 uint32_t m_CH5CH6Data_Sel;

 FunctionalState m_G4D4_Inphase_EN;

 FunctionalState m_G4D4_Inverse_EN;

 FunctionalState m_G4D3_Inphase_EN;

 FunctionalState m_G4D3_Inverse_EN;

 FunctionalState m_G4D2_Inphase_EN;

 FunctionalState m_G4D2_Inverse_EN;

 FunctionalState m_G4D1_Inphase_EN;

 FunctionalState m_G4D1_Inverse_EN;

 FunctionalState m_G3D4_Inphase_EN;

 FunctionalState m_G3D4_Inverse_EN;

 FunctionalState m_G3D3_Inphase_EN;

 FunctionalState m_G3D3_Inverse_EN;

 FunctionalState m_G3D2_Inphase_EN;

 FunctionalState m_G3D2_Inverse_EN;

 FunctionalState m_G3D1_Inphase_EN;

 FunctionalState m_G3D1_Inverse_EN;

 FunctionalState m_G2D4_Inphase_EN;

 FunctionalState m_G2D4_Inverse_EN;

 FunctionalState m_G2D3_Inphase_EN;

 FunctionalState m_G2D3_Inverse_EN;

 FunctionalState m_G2D2_Inphase_EN;

 FunctionalState m_G2D2_Inverse_EN;

 FunctionalState m_G2D1_Inphase_EN;

 FunctionalState m_G2D1_Inverse_EN;

 FunctionalState m_G1D4_Inphase_EN;

 FunctionalState m_G1D4_Inverse_EN;

 FunctionalState m_G1D3_Inphase_EN;

 FunctionalState m_G1D3_Inverse_EN;

 FunctionalState m_G1D2_Inphase_EN;

 FunctionalState m_G1D2_Inverse_EN;

 FunctionalState m_G1D1_Inphase_EN;

 FunctionalState m_G1D1_Inverse_EN;

} CFGL_InitTypeDef;
# 353 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_cfgl.h"
FlagStatus CFGL1_OUT_STATE (void);
FlagStatus CFGL2_OUT_STATE (void);
FlagStatus CFGL2_Get_INT_Flag (void);
FlagStatus CFGL1_Get_INT_Flag (void);
void CFGL1_FALLINT_Enable (FunctionalState NewState);
void CFGL1_RISEINT_Enable (FunctionalState NewState);
void CFGL2_FALLINT_Enable (FunctionalState NewState);
void CFGL2_RISEINT_Enable (FunctionalState NewState);
void CFGL1_OUT_SYNCHRO_Enable (FunctionalState NewState);
void CFGL2_OUT_SYNCHRO_Enable (FunctionalState NewState);
void CFGL_Configuration (CFGL_SFRmap* CFGLx, CFGL_InitTypeDef* CFGLInitStruct);
void CFGL_Reset (void);
RetStatus CFGL1_Clear_RISEINT_Flag (void);
RetStatus CFGL1_Clear_FALLINT_Flag (void);
RetStatus CFGL1_Clear_RISEFALLINT_Flag (void);
RetStatus CFGL2_Clear_RISEINT_Flag (void);
RetStatus CFGL2_Clear_FALLINT_Flag (void);
RetStatus CFGL2_Clear_RISEFALLINT_Flag (void);
void CFGL_Struct_Init (CFGL_InitTypeDef* CFGLInitStruct);
void CFGL_Clear_INT_Flag(void);
# 44 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_cmp.h" 1
# 44 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_cmp.h"
typedef struct
{
 uint32_t m_PositiveInput;

    uint32_t m_NegativeInput;

    FunctionalState m_FallTriggerEnable;

    FunctionalState m_RiseTriggerEnable;

    uint32_t m_Clock;

    uint32_t m_FrequencyDivision;

    uint32_t m_SampleNumber;

    FunctionalState m_FilterEnable;

    FunctionalState m_ScopecontrolEnable;

    uint32_t m_OutputPolarity;

    FunctionalState m_CmpEnable;

}CMP_InitTypeDef;
# 433 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_cmp.h"
void CMP_Reset (void);
void CMP_Configuration (uint32_t CMPx_ADDR, CMP_InitTypeDef* CMPInitStruct);
void CMP_Struct_Init (CMP_InitTypeDef* CMPInitStruct);
void CMP_IO_Channel_Enable(FunctionalState NewState);
void CMP0_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP0_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP1_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP1_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP2_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP2_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP3_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP3_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP_Up_Down_Edge_INT_Enable(uint32_t CMPx_ADDR, uint32_t UDEdge, uint32_t NewState);
void CMP_OUTPUT_POL_SELECT(uint32_t CMPx_ADDR, uint32_t Polarity);
void CMP_OUTPUT_SELECT (uint32_t Select);
void CMP_Cmd(uint32_t CMPx_ADDR, uint32_t NewState);
void CMP_Trigger_Select_Config (uint32_t TriSelect);
FlagStatus CMP_Get_Output_State(uint32_t CMPx_ADDR);
FlagStatus CMP_Get_INT_Flag(uint32_t CMPx_ADDR);
RetStatus CMP_Clear_INT_Flag(uint32_t CMPx_ADDR);
void CMP_INT_Enable(uint32_t CMPx_ADDR, uint32_t NewState);
void CMP_SluggishVoltage_Select (uint32_t Select);
void CMP_HALLMODE_Select (uint32_t Select);
void CMP_BEMF_Enable (FunctionalState NewState);
void CMP_FLTINSEL_Select (uint32_t Select);
void CMP_Win_Control_TRGMUX_CH_Select (uint32_t CMPx_ADDR, uint32_t Select);
void CMP_LP_Enable(FunctionalState NewState);
void CMP_TRIM_PMOS_Enable(FunctionalState NewState);
void CMP_TRIM_NMOS_Enable(FunctionalState NewState);
void CMP_TRIM_PMOS_Cail(uint32_t CMPx_ADDR, uint8_t Value);
void CMP_TRIM_PMOS_Direction_Select(uint32_t CMPx_ADDR, uint32_t Direction);
void CMP_TRIM_NMOS_Cail(uint32_t CMPx_ADDR, uint8_t Value);
void CMP_TRIM_NMOS_Direction_Select(uint32_t CMPx_ADDR, uint32_t Direction);
void CMP_WIN_Control_CLK_Select(uint32_t CMPx_ADDR, uint32_t Select);
void CMP_Filter_SampleNumber_Select(uint32_t CMPx_ADDR, uint32_t Select);
void CMP_Filter_CLKSource_Select(uint32_t CMPx_ADDR, uint32_t Select);
# 45 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_crc.h" 1
# 39 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_crc.h"
typedef struct
{
  uint32_t m_CalUnitReset;

  uint32_t m_InputSize;

  uint32_t m_InputReverse;

  uint32_t m_ResultReverse;

} CRC_InitTypeDef;
# 107 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_crc.h"
void CRC_Reset (void);
void CRC_Configuration (CRC_InitTypeDef* CRCInitStruct);
void CRC_Struct_Init (CRC_InitTypeDef* CRCInitStruct);
uint32_t CRC_Get_Register_Value(uint32_t CRC_Register);
void CRC_Register_Value_Config(uint32_t CRC_Register ,uint32_t Value);
void CRC_Result_Reverse_Enable(FunctionalState NewState);
void CRC_Input_Data_Reverse_Enable(FunctionalState NewState);
void CRC_Input_Data_Format_Config(uint32_t Select);
void CRC_Calculation_Unit_Reset_Enable(FunctionalState NewState);
void CRC_INPUT_DATA (uint32_t DATA);
uint32_t CRC_GET_RESULT (void);
void CRC_SET_INITVALUE (uint32_t DATA);
void CRC_SET_PLN (uint32_t DATA);
void CRC_SET_RXOR (uint32_t DATA);
void CRC_SET_IDATA (uint32_t DATA);
uint32_t CRC_GET_TEMP (void);
void CRC_SET_RSET (void);
# 46 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_dac.h" 1
# 43 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_dac.h"
typedef struct
{
    FunctionalState m_TriggerEnable;

    uint32_t m_TriggerEvent;

    FunctionalState m_TriggerDMAEnable;

    uint32_t m_Wave;

    uint32_t m_Mas;

    uint32_t m_Clock;

    uint32_t m_ClockDiv;

    uint32_t m_ReferenceVoltage;

    FunctionalState m_OutputBuffer;

    uint32_t m_OutputPin;

    uint32_t m_Output;

}DAC_InitTypeDef;
# 207 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_dac.h"
void DAC_Reset (DAC_SFRmap* DACx);
void DAC_Configuration (DAC_SFRmap* DACx, DAC_InitTypeDef* dacInitStruct);
void DAC_Struct_Init (DAC_InitTypeDef* dacInitStruct);
void DAC_Cmd (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Software_Trigger_Cmd (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_DMA_Cmd (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Output_Buffer_Config (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Output_Port_Config (DAC_SFRmap* DACx, FunctionalState NewState);

void DAC_Write_Output_Data (DAC_SFRmap* DACx, uint32_t Value);
uint32_t DAC_Read_Output_Data (DAC_SFRmap* DACx);

void DAC_PCalibration_Direction_Config (DAC_SFRmap* DACx, uint32_t Direction);
void DAC_PCalibration_Value_Config (DAC_SFRmap* DACx, uint32_t Value);
uint16_t DAC_PCalibration_Value_Read (DAC_SFRmap* DACx);
void DAC_NCalibration_Direction_Config (DAC_SFRmap* DACx, uint32_t Direction);
void DAC_NCalibration_Value_Config (DAC_SFRmap* DACx, uint32_t Value);
uint16_t DAC_NCalibration_Value_Read (DAC_SFRmap* DACx);
uint8_t DAC_TRIM_STATE_Value_Read (DAC_SFRmap* DACx);
void DAC_TRIMHI_Enable(DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_TRIMLO_Enable(DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Test_Group_Config(DAC_SFRmap* DACx, uint32_t TestGroup);
void DAC_Test_Group_Enable(DAC_SFRmap* DACx, FunctionalState NewState);
# 47 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_dma.h" 1
# 35 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_dma.h"
typedef struct
{
    uint8_t m_Channel;

    uint8_t m_Direction;

    uint8_t m_PeripheralDataSize;

    uint8_t m_MemoryDataSize;

    uint16_t m_Priority;

    uint16_t m_Number;

    FunctionalState m_PeripheralInc;

    FunctionalState m_MemoryInc;

    FunctionalState m_LoopMode;

    uint32_t m_BlockMode;

    uint32_t m_PeriphAddr;

    uint32_t m_MemoryAddr;

}DMA_InitTypeDef;
# 140 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_dma.h"
void DMA_Reset (DMA_SFRmap* DMAx);
void DMA_Configuration (DMA_SFRmap* DMAx, DMA_InitTypeDef* dmaInitStruct);
void DMA_Struct_Init (DMA_InitTypeDef* dmaInitStruct);


void DMA_Transfer_Number_Config (DMA_SFRmap* DMAx, uint32_t Channel, uint16_t Number);
void DMA_Memory_To_Memory_Enable (DMA_SFRmap* DMAx, uint32_t Channel, FunctionalState NewState);
void DMA_Channel_Priority_Config (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t Priority);
void DMA_Peripheral_Data_Width_Config (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t Width);
void DMA_Memory_Data_Width_Config (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t Width);
void DMA_Peripheral_addr_increase_Enable (DMA_SFRmap* DMAx, uint32_t Channel, FunctionalState NewState);
void DMA_Memory_addr_increase_Enable (DMA_SFRmap* DMAx, uint32_t Channel, FunctionalState NewState);
void DMA_Loop_Mode_Enable (DMA_SFRmap* DMAx, uint32_t Channel, FunctionalState NewState);
void DMA_Transfer_Direction_Config (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t Direction);
void DMA_Transfer_Mode_Config (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t BlockMode);
void DMA_Oneshot_Enable (DMA_SFRmap* DMAx, uint32_t Channel, FunctionalState NewState);
void DMA_Channel_Enable (DMA_SFRmap* DMAx, uint32_t Channel, FunctionalState NewState);
void DMA_Peripheral_Start_Address_Config (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t Address);
void DMA_Memory_Start_Address_Config (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t Address);
uint32_t DMA_Get_Peripheral_Current_Address (DMA_SFRmap* DMAx, uint32_t Channel);
uint32_t DMA_Get_Memory_Current_Address (DMA_SFRmap* DMAx, uint32_t Channel);
uint16_t DMA_Get_Transfer_Number_Remain (DMA_SFRmap* DMAx, uint32_t Channel);


FlagStatus DMA_Get_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t InterruptType);
void DMA_Clear_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t InterruptType);
void DMA_Set_INT_Enable (DMA_SFRmap* DMAx, uint32_t Channel,uint32_t InterruptType, FunctionalState NewState);
FlagStatus DMA_Get_Error_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel);
FlagStatus DMA_Get_Half_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel);
FlagStatus DMA_Get_Finish_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel);
void DMA_Error_Transfer_INT_Enable (DMA_SFRmap* DMAx, uint32_t Channel, FunctionalState NewState);
void DMA_Half_Transfer_INT_Enable (DMA_SFRmap* DMAx, uint32_t Channel, FunctionalState NewState);
void DMA_Finish_Transfer_INT_Enable (DMA_SFRmap* DMAx, uint32_t Channel, FunctionalState NewState);
# 48 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_ecfgl.h" 1
# 143 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_ecfgl.h"
void ECFGL_Reset (void);
void ECFGL_Output_Enable(uint32_t ECFGLx, FunctionalState NewState);
void ECFGL_Function_Select(uint32_t ECFGLx, uint32_t Function);
void ECFGL_MUX4IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX3IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX2IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX1IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX0IN_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_MUX2IN_Software_Bit_Select(uint32_t ECFGLx, uint32_t Select);
void ECFGL_Fliter_Clock_Div_Select(uint32_t ECFGL_DIV);
void ECFGL_Fliter_Clock_Select(uint32_t CLK);
RetStatus ECFGLx_Clear_INT_Flag(uint32_t ECFGLx);
FlagStatus ECFGLx_Get_INT_Flag(uint32_t ECFGLx);
void ECFGLx_Rise_INT_Enable(uint32_t ECFGLx, FunctionalState NewState);
void ECFGLx_Fall_INT_Enable(uint32_t ECFGLx, FunctionalState NewState);
void ECFGLx_Trigger_ADC_Enable(FunctionalState NewState);
void ECFGLx_Trigger_ADC_Source_Select(uint32_t ECFGLx);
FlagStatus ECFGLx_Get_ECFGLx_Output_Status(uint32_t ECFGLx);
# 49 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_epwm.h" 1
# 324 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_epwm.h"
void EPWM_Reset (EPWM_SFRmap* EPWMx);
void EPWM_TxCNT_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value);
uint32_t EPWM_Get_TxCNT_Value(EPWM_SFRmap* EPWMx);
void EPWM_TxPHS_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value);
uint32_t EPWM_Get_TxPHS_Value(EPWM_SFRmap* EPWMx);
void EPWM_TxPPX_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value);
uint32_t EPWM_Get_TxPPX_Value(EPWM_SFRmap* EPWMx);
void EPWM_TxPRSC_Value_Config(EPWM_SFRmap* EPWMx, uint32_t Value);
uint32_t EPWM_Get_TxPRSC_Value(EPWM_SFRmap* EPWMx);
void EPWM_Response_UpperLevel_LINK_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_NextLevel_LINK_Ask_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_SYNC_Single_Trigger_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Submodule_Register_Lock_Config(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState);
void EPWM_Cap_Function_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Cap_Trigger_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
FlagStatus EPWM_Get_CountValue_MAX_Status(EPWM_SFRmap* EPWMx);
RetStatus EPWM_Clear_CountValue_MAX_Status(EPWM_SFRmap* EPWMx);
void EPWM_Phase_Direction_Config(EPWM_SFRmap* EPWMx, uint32_t Direction);
void EPWM_Software_SYNC_Event(EPWM_SFRmap* EPWMx);
void EPWM_SYNC_Event_Out_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Phase_Register_Loading_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
FlagStatus EPWM_Get_External_SYNC_Event_Status(EPWM_SFRmap* EPWMx);
RetStatus EPWM_Clear_External_SYNC_Event_Status(EPWM_SFRmap* EPWMx);
void EPWM_Updata_Event_Generate_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Updata_Event_Config(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Updata_Event_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Counter_Mode_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
FlagStatus EPWM_Get_Tx_Count_Direction(EPWM_SFRmap* EPWMx);
void EPWM_Work_Clock_Select(EPWM_SFRmap* EPWMx, uint32_t CLK);
void EPWM_External_Pulse_Sync_Config(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Gated_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Work_Mode_Config(EPWM_SFRmap* EPWMx, uint32_t Mode);
void EPWM_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Duty_Cycle_RegisterABCD_Config(EPWM_SFRmap* EPWMx, uint32_t Register,uint32_t Value);
uint32_t EPWM_Get_Duty_Cycle_RegisterABCD_Value(EPWM_SFRmap* EPWMx, uint32_t Register);
void EPWM_Single_Mandatory_Output_Enable(EPWM_SFRmap* EPWMx, uint32_t Register, FunctionalState NewState);
void EPWM_Single_Mandatory_Output_Config(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Select);
void EPWM_Continuous_Mandatory_Output_Config(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Select);
void EPWM_EPWMxAB_OUTPUT_Select(EPWM_SFRmap* EPWMx, uint32_t Register, uint32_t Event, uint32_t Select);
void EPWM_Dead_Zone_Input_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Dead_Zone_Output_Polarity_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Dead_Zone_Output_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Dead_Zone_Time_Config(EPWM_SFRmap* EPWMx, uint32_t Select, uint32_t Value);
void EPWM_PCLK_Frequency_Config(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_PCLK_Duty_Cycle_Config(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Chopping_Pulse_Width_Config(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Chopping_Pulse_Mode_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_Auto_Reset_Enable(EPWM_SFRmap* EPWMx, uint32_t NewState);
void EPWM_Pin_EPWMA_ShouDown_Status_Config(EPWM_SFRmap* EPWMx, uint32_t Status);
void EPWM_Pin_EPWMB_ShouDown_Status_Config(EPWM_SFRmap* EPWMx, uint32_t Status);
FlagStatus EPWM_Get_Auto_ShowDown_Event_Status(EPWM_SFRmap* EPWMx);
void EPWM_Claer_Auto_ShowDown_Event_Status(EPWM_SFRmap* EPWMx);
void EPWM_Auto_ShowDown_Source_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Trigger_AD_Event_Mode_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select);
uint8_t EPWM_Get_Trigger_AD_Event_Single(EPWM_SFRmap* EPWMx, uint32_t Event);
void EPWM_Trigger_Event_Cycle_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select);
void EPWM_Software_Trigger_AD_Event_Enable(EPWM_SFRmap* EPWMx, uint32_t Event, FunctionalState NewState);
void EPWM_Trigger_AD_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Event, uint32_t Select);
void EPWM_Trigger_AD_Event_Enable(EPWM_SFRmap* EPWMx, uint32_t Event, FunctionalState NewState);
void EPWM_INT_Enable(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState);
FlagStatus EPWM_Get_INT_Flag(EPWM_SFRmap* EPWMx, uint32_t Select);
RetStatus EPWM_Clear_INT_Flag(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_Trigger_DMA_Enable(EPWM_SFRmap* EPWMx, uint32_t Select, FunctionalState NewState);
FlagStatus EPWM_Get_Trigger_DMA_Flag(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_HRPWM_OUTPUTB_CONTRAL_Select(EPWM_SFRmap* EPWMx, uint32_t Select);
void EPWM_HRPWM_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
void EPWM_8Bit_HRPWM_Duty_Cycle(EPWM_SFRmap* EPWMx, uint8_t Value);
uint32_t EPWM_Get_Cap_Register_Current_Value(EPWM_SFRmap* EPWMx);
void EPWM_UDCTL_Updata_Enable(EPWM_SFRmap* EPWMx, uint32_t Mode, FunctionalState NewState);
void EPWM_UDCTL_Register_Updata_Event_Select(EPWM_SFRmap* EPWMx, uint32_t Mode, uint32_t Select);
void EPWM_Global_Loading_Enable(EPWM_SFRmap* EPWMx, FunctionalState NewState);
# 50 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_ewdt.h" 1
# 92 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_ewdt.h"
void EWDT_Reset (void);
void EWDT_Output_Effective_Single_Select(uint32_t Select);
FlagStatus EWDT_Get_Reset_INT_Flag(void);
RetStatus EWDT_Clear_Reset_INT_Flag(void);
void EWDT_Reset_Single_INT_Enable(FunctionalState NewState);
void EWDT_CLK_Select(uint32_t CLK);
void EWDT_Input_Effective_Single_Select(uint32_t Select);
void EWDT_Input_Single_Enable(FunctionalState NewState);
RetStatus EWDT_Clear_Count40_INT_Flag(void);
void EWDT_Threshold_Config(uint32_t Threshold);
void EWDT_Clock_Div_Select(uint32_t DIV);
FlagStatus EWDT_Get_Count40_INT_Flag(void);
void EWDT_Count40_INT_Enable(FunctionalState NewState);
void EWDT_Enable(FunctionalState NewState);
uint8_t EWDT_Get_Count_Value(void);
void EWDT_Set_Count_Value(uint8_t Value);
# 51 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_exic.h" 1
# 34 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_exic.h"
typedef struct
{
 FunctionalState m_Module_Enable;

 FunctionalState m_CS_Enable;

 uint32_t m_Data_Control_Sel;

 FunctionalState m_Write_Enable;

 FunctionalState m_Read_Enable;

    FunctionalState m_DMA_Write_EN;

    FunctionalState m_DMA_Read_EN;

    FunctionalState m_WriteFnish_INT_EN;

    FunctionalState m_ReadFnish_INT_EN;

    FunctionalState m_WriteData_EN;

    FunctionalState m_ReadData_EN;

    uint32_t m_Data_Direction_Sel;

    uint32_t m_Mode_Sel;

    uint32_t m_Source_Clock_Sel;

    uint32_t m_Pulse_Width_Sel;


}EXIC_InitTypeDef;
# 137 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_exic.h"
void EXIC_Struct_Init (EXIC_InitTypeDef* EXICInitStruct);
uint32_t EXIC_Read_Buff (void);
void EXIC_Write_Buff (uint32_t DATA);
RetStatus EXIC_Clear_Write_Finish_INT_Flag (void);
RetStatus EXIC_Clear_Read_Finish_INT_Flag (void);
FlagStatus EXIC_Get_Read_Finish_INT_Flag (void);
FlagStatus EXIC_Get_Write_Finish_INT_Flag (void);
void EXIC_Configuration (EXIC_InitTypeDef* EXICInitStruct);
void EXIC_Reset (void);
# 52 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_fdc.h" 1
# 125 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_fdc.h"
void FDC_Reset(FDC_SFRmap* FDCx);
void FDC_TRGI_Count_Reset_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Work_Clk_Select(FDC_SFRmap* FDCx, uint32_t CLK);
RetStatus FDC_Clear_MDLIF_Flag(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Cycle_Scan_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Work_Mode_Select(FDC_SFRmap* FDCx, uint32_t MODE);
void FDC_Updata_Mode_Select(FDC_SFRmap* FDCx, uint32_t MODE);
void FDC_Sequence_Error_INT_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Software_Triggle_Enable(FDC_SFRmap* FDCx);
void FDC_MDL_INT_DMA_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Prescaler_Select(FDC_SFRmap* FDCx, uint32_t Select);
void FDC_Scaler_Factor(FDC_SFRmap* FDCx, uint32_t Value);
void FDC_Triggle_Input_Select(FDC_SFRmap* FDCx, uint32_t Select);
void FDC_MDL_INT_Enable(FDC_SFRmap* FDCx, uint32_t Select);
FlagStatus FDC_Get_MDL_INT_Flag(FDC_SFRmap* FDCx);
void FDC_Single_Mode_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Ldok_Write1(FDC_SFRmap* FDCx);
void FDC_Pulse_Output_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Enable(FDC_SFRmap* FDCx, FunctionalState NewState);
void FDC_Set_Count_Cycle(FDC_SFRmap* FDCx, uint32_t Value);
uint16_t FDC_Get_Count_Cycle(FDC_SFRmap* FDCx);
uint16_t FDC_Get_Count_Value(FDC_SFRmap* FDCx);
uint16_t FDC_Get_INT_Delay_Value(FDC_SFRmap* FDCx);
void FDC_Clear_Channel_List_Error_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n, FunctionalState NewState);
FlagStatus FDC_Get_Channel_List_Error_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n);
FlagStatus FDC_Get_CFn_Flag(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n);
void FDC_Channel_Pre_Triggle_Select(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n, uint32_t Select);
void FDC_Channel_Pre_Signel_Enable(FDC_SFRmap* FDCx, uint32_t Channel, uint8_t n, FunctionalState NewState);
void FDC_Channelm_Pre_Triggle_Delay0(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Channelm_Pre_Triggle_Delay1(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Channelm_Pre_Triggle_Delay2(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Channelm_Pre_Triggle_Delay3(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Channelm_Pre_Triggle_Delay4(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Pulse_Output_DelayH(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
void FDC_Pulse_Output_DelayL(FDC_SFRmap* FDCx, uint32_t Channel, uint32_t Value);
# 53 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_flash.h" 1
# 33 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_flash.h"
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
# 54 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_flexmux.h" 1
# 192 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_flexmux.h"
void FMUX_Reset(void);
void FMUX_Channel_Enable(uint32_t Channel, FunctionalState NewState);
void FMUX_Channel_Triggle_Source_Select(uint32_t Channel, uint32_t Source);
void FMUX_Enable(FunctionalState NewState);
void FMUX_Output_Channel_DMA_Enable(uint32_t Channel, FunctionalState NewState);
void FMUX_Triggle_Single_Maintain_Time_Select(uint32_t Channel, uint32_t DIV);
void FMUX_Output_Select(uint32_t Channel, uint32_t MODE);
void FMUX_Work_CLK_Select(uint32_t CLK);
# 55 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gpio.h" 1
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
# 56 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gtim.h" 1
# 47 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gtim.h"
typedef struct
{
    uint32_t m_Counter;
    uint32_t m_Period;
    uint32_t m_Prescaler;
    uint16_t m_CounterMode;

    uint16_t m_Clock;

    uint16_t m_WorkMode;

    uint16_t m_MasterMode;

    uint16_t m_SlaveMode;

    uint16_t m_EXPulseSync;

    uint16_t m_MasterSlaveSync;

} GPTIM_InitTypeDef;




typedef struct
{
    uint16_t m_Channel;

    uint16_t m_CompareMode;

    uint32_t m_CompareValue;

} CCP_CompareInitTypeDef;




typedef struct
{
    uint16_t m_Channel;

    uint16_t m_CaptureMode;

    FunctionalState m_PWMInput;

    FunctionalState m_XORMode;

    FunctionalState m_ChannelCompare4;

} CCP_CaptureInitTypeDef;




typedef struct
{
    uint16_t m_Channel;

    uint16_t m_PwmMode;

    uint32_t m_DutyRatio;

    uint32_t m_OutputCtl;

    uint32_t m_SinglePWM;

    uint32_t m_CloseTimer;

} CCP_PWMInitTypeDef;
# 285 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_gtim.h"
void GPTIM_Reset (GPTIM_SFRmap* GPTIMx);
void GPTIM_Configuration(GPTIM_SFRmap* GPTIMx,
                    GPTIM_InitTypeDef* gptimInitStruct);
void GPTIM_Struct_Init (GPTIM_InitTypeDef* gptimInitStruct);
void GPTIM_Cmd (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Set_Counter (GPTIM_SFRmap* GPTIMx, uint32_t Counter);
void GPTIM_Set_Period (GPTIM_SFRmap* GPTIMx, uint32_t Period);
void GPTIM_Set_Prescaler (GPTIM_SFRmap* GPTIMx, uint32_t Prescaler);
void GPTIM_Counter_Mode_Config (GPTIM_SFRmap* GPTIMx, uint32_t CounterMode);
void GPTIM_Clock_Config (GPTIM_SFRmap* GPTIMx, uint32_t NewClock);
void GPTIM_External_Pulse_Sync_Config (GPTIM_SFRmap* GPTIMx,
                    uint32_t PulseSync);
void GPTIM_Work_Mode_Config (GPTIM_SFRmap* GPTIMx, uint32_t NewState);
void GPTIM_Updata_Immediately_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
void GPTIM_Master_Slave_Snyc_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
void GPTIM_Trigger_Select_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState TriggerSelect);
void GPTIM_Slave_Mode_Config (GPTIM_SFRmap* GPTIMx, FunctionalState SlaveMode);
void GPTIM_Master_Mode_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState MasterMode);
void GPTIM_Updata_Rising_Edge_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
void GPTIM_Updata_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Trigger_DMA_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Updata_DMA_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Updata_INT_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Trigger_INT_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Generate_Trigger_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
DIRStatus GPTIM_Get_Direction (GPTIM_SFRmap* GPTIMx);
uint32_t GPTIM_Get_Counter (GPTIM_SFRmap* GPTIMx);
uint32_t GPTIM_Get_Period (GPTIM_SFRmap* GPTIMx);
uint32_t GPTIM_Get_Prescaler (GPTIM_SFRmap* GPTIMx);

void GPTIM_Overflow_INT_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
RetStatus GPTIM_Clear_Overflow_INT_Flag (GPTIM_SFRmap* GPTIMx);
RetStatus GPTIM_Clear_Updata_INT_Flag (GPTIM_SFRmap* GPTIMx);
RetStatus GPTIM_Clear_Trigger_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Overflow_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Updata_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Trigger_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Updata_DMA_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Trigger_DMA_INT_Flag (GPTIM_SFRmap* GPTIMx);

void CCP_Compare_Configuration(CCP_SFRmap* CCPx,
                    CCP_CompareInitTypeDef* ccpInitStruct);
void CCP_Compare_Struct_Init (CCP_CompareInitTypeDef* ccpInitStruct);
void CCP_Capture_Configuration (CCP_SFRmap* CCPx,
                    CCP_CaptureInitTypeDef* ccpInitStruct);
void CCP_Capture_Struct_Init (CCP_CaptureInitTypeDef* ccpInitStruct);
void CCP_PWM_Configuration (CCP_SFRmap* CCPx,
                    CCP_PWMInitTypeDef* ccpInitStruct);
void CCP_PWM_Struct_Init (CCP_PWMInitTypeDef* ccpInitStruct);
void CCP_Capture_Mode_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t EdgeConfig);
void CCP_Compare_Mode_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t EdgeConfig);
void CCP_PWM_Mode_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t EdgeConfig);
uint32_t CCP_Get_Capture_Result (CCP_SFRmap* CCPx, uint32_t Channel);
void CCP_Set_Compare_Result (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t Value);


uint32_t CCP_Get_Compare_Result (CCP_SFRmap* CCPx, uint32_t Channel);


void CCP_Compare_PWM_Signal_Clear (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_Compare_Check_Config (CCP_SFRmap* CCPx, uint32_t CompareSelect);
void CCP_Channel_Output_Control (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t ChannelOutputCtl);
void CCP_Single_Pulse_Shut_Enable (CCP_SFRmap* CCPx, FunctionalState NewState);
void CCP_Single_Pulse_Enable (CCP_SFRmap* CCPx, FunctionalState NewState);
void CCP_PWM_Input_Measurement_Config (CCP_SFRmap* CCPx,
                    FunctionalState NewState);
void CCP_Input_XOR_Config (CCP_SFRmap* CCPx, FunctionalState NewState);
void CCP_Channel_DMA_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_Generate_Trigger_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_USART_Receive_Config (CCP_SFRmap* CCPx, FunctionalState NewState);

FlagStatus CCP_Get_Channel_Trigger_INT_Flag (CCP_SFRmap* CCPx, uint32_t Channel);
FlagStatus CCP_Get_Trigger_DMA_INT_Flag (CCP_SFRmap* CCPx, uint32_t Channel);
void CCP_Channel_INT_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
RetStatus CCP_Clear_Channel_INT_Flag (CCP_SFRmap* CCPx, uint32_t Channel);
# 57 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_hrcap.h" 1
# 83 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_hrcap.h"
void HRCAP_Reset (HRCAP_SFRmap* HRCAPx);
void HRCAP_CLK_Select(HRCAP_SFRmap* HRCAPx, uint32_t CLK);
void HRCAP_Software_Reset_Enable(HRCAP_SFRmap* HRCAPx, FunctionalState NewState);
void HRCAP_INT_Enable(HRCAP_SFRmap* HRCAPx, uint32_t Select, FunctionalState NewState);
void HRCAP_Cap_Input_Select(HRCAP_SFRmap* HRCAPx, uint32_t Select);
uint16_t HRCAP_Read_Latch_Count_Value(HRCAP_SFRmap* HRCAPx);
uint16_t HRCAP_Read_Count_Value(HRCAP_SFRmap* HRCAPx);
uint16_t HRCAP_Read_Rise_Integer_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG);
uint16_t HRCAP_Read_Fall_Integer_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG);
uint16_t HRCAP_Read_Rise_Decimal_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG);
uint16_t HRCAP_Read_Fall_Decimal_Value(HRCAP_SFRmap* HRCAPx, uint32_t HRCAP_REG);
FlagStatus HRCAP_Get_INT_Flag(HRCAP_SFRmap* HRCAPx, uint32_t Select);
RetStatus HRCAP_Clear_INT_Flag(HRCAP_SFRmap* HRCAPx, uint32_t Select);
void HRCAP_INT_Mandatory_Enable(HRCAP_SFRmap* HRCAPx, uint32_t Select, FunctionalState NewState);
# 58 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_i2c.h" 1
# 40 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_i2c.h"
typedef struct
{
    uint32_t m_Mode;

    uint32_t m_ClockSource;

    uint32_t m_BADR10;

    uint32_t m_MasterSlave;

    uint16_t m_BaudRateL;

    uint16_t m_BaudRateH;

    FunctionalState m_AckEn;

    uint32_t m_AckData;

}I2C_InitTypeDef;
# 224 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_i2c.h"
void I2C_Reset (I2C_SFRmap* I2Cx);
void I2C_Configuration (I2C_SFRmap* I2Cx,I2C_InitTypeDef* i2cInitStruct);
void I2C_Struct_Init (I2C_InitTypeDef* I2C_InitStruct);


void I2C_Cmd(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Bufr_Address_Config(I2C_SFRmap* I2Cx,uint32_t NewState);
void I2C_Generate_START(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Generate_STOP(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Ack_Config (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Ack_DATA_Config (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Call_Cmd (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Clock_Config (I2C_SFRmap* I2Cx,uint32_t ClkSource);
void I2C_MATCH_ADDRESS_Config (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SCL_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_NMENA_Enable(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SMBUS_Enable(I2C_SFRmap* I2Cx,uint32_t NewState);
void I2C_SMBT_Config(I2C_SFRmap* I2Cx,uint32_t NewState);
void I2C_SMBus_ALERT_Config(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SendData (I2C_SFRmap* I2Cx,uint32_t Data);
uint32_t I2C_ReceiveData(I2C_SFRmap* I2Cx);
void I2C_ARP_Enable(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_ADDR_Config(I2C_SFRmap* I2Cx, uint32_t AddrSelect, uint32_t Data);
void I2C_MSK_Config(I2C_SFRmap* I2Cx, uint32_t AddrSelect, uint32_t DataMask);
void I2C_BRGH_Config (I2C_SFRmap* I2Cx,uint16_t Period);
void I2C_BRGL_Config (I2C_SFRmap* I2Cx,uint16_t Period);
void I2C_Keep_Data_Time_Config(I2C_SFRmap* I2Cx, uint32_t Time);


void I2C_Start_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Stop_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Ack_Fail_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Arbitration_Lost_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SMBus_Alert_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SMBus_HostHead_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SMBus_Device_Defaultaddress_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_ISIE_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Receive_DMA_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Transmit_DMA_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Bus_Error_INT_Enable(I2C_SFRmap* I2Cx,FunctionalState NewState);
FlagStatus I2C_Get_Start_Flag (I2C_SFRmap* I2Cx);
RetStatus I2C_Clear_Start_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Stop_Flag (I2C_SFRmap* I2Cx);
RetStatus I2C_Clear_Stop_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Address_Match_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_HighAddress_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Data_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Ack_Fail_Flag (I2C_SFRmap* I2Cx);
RetStatus I2C_Clear_Ack_Fail_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Arbitration_Lost_Flag (I2C_SFRmap* I2Cx);
RetStatus I2C_Clear_Arbitration_Lost_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Write_Read_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_SMBus_Alert_Flag (I2C_SFRmap* I2Cx);
RetStatus I2C_Clear_SMBus_Alert_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_SMBus_Host_Header_Flag (I2C_SFRmap* I2Cx);
RetStatus I2C_Clear_SMBus_Host_Header_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_SMBus_Device_Default_Flag (I2C_SFRmap* I2Cx);
RetStatus I2C_Clear_SMBus_Device_Default_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_INTERRUPT_Flag (I2C_SFRmap* I2Cx);
RetStatus I2C_Clear_INTERRUPT_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Receive_Buff_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Transmit_Buff_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Receive_DMA_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Transmit_DMA_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Bus_Error_Flag (I2C_SFRmap* I2Cx);
void I2C_SendData8 (I2C_SFRmap* I2Cx, uint8_t Data);
# 59 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_int.h" 1
# 33 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_int.h"
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
# 60 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_iwdt.h" 1
# 73 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_iwdt.h"
void IWDT_Prescaler_Config (uint32_t Prescaler);
void IWDT_SCK_Source_Select(uint32_t Source);
void IWDT_Overflow_Config (uint32_t Overflow);
void IWDT_Enable (uint32_t NewState);
void IWDT_Feed_The_Dog (void);
# 61 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_op.h" 1
# 76 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_op.h"
void OP_Reset(void);
void OP_Enable(uint32_t OPx_NUM, FunctionalState NewState);
void OP_OUTPUT_Enable(uint32_t OPx_NUM, FunctionalState NewState);
void OP_GAIN_Select(uint32_t OPx_NUM,uint32_t GAIN_Value, FunctionalState NewState);
void OP_OPUPUT_Parallel_Resistance(uint32_t OPx_NUM, FunctionalState NewState);
void OP_Positive_INPUT_Selsect(uint32_t OPx_NUM_OUTPUT, uint32_t OPx_NUM_PINPUT, FunctionalState NewState);
void OP_Positive_Negetive_Short(uint32_t OPx_NUM, FunctionalState NewState);
void OP_VCOM_Positive_Select(uint32_t Select);
void OP_VCOM_Buffer_Output_Enable(FunctionalState NewState);
void OP_VCOM_Buffer_Enable(FunctionalState NewState);
void CMP3_Enable(FunctionalState NewState);
void OP_TRIM_PMOS_Enable(FunctionalState NewState);
void OP_TRIM_NMOS_Enable(FunctionalState NewState);
RetStatus OP_TRIM_OUT_Flag(uint32_t OPx_NUM);
void OP_TRIM_PMOS_Value_Config(uint32_t OPx_NUM, uint8_t Value);
void OP_TRIM_PMOS_Direction_Select(uint32_t OPx_NUM, uint32_t Direction);
void OP_TRIM_NMOS_Value_Config(uint32_t OPx_NUM, uint8_t Value);
void OP_TRIM_NMOS_Direction_Select(uint32_t OPx_NUM, uint32_t Direction);
# 62 "../system_init.h" 2
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
# 63 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pclk.h" 1
# 57 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pclk.h"
void PCLK_CTL0_Peripheral_Clock_Enable (uint32_t PCLK_CTL0_bit,FunctionalState NewState);
void PCLK_CTL1_Peripheral_Clock_Enable (uint32_t PCLK_CTL1_bit,FunctionalState NewState);
void PCLK_CTL2_Peripheral_Clock_Enable (uint32_t PCLK_CTL2_bit,FunctionalState NewState);
void PCLK_CTL3_Peripheral_Clock_Enable (uint32_t PCLK_CTL3_bit,FunctionalState NewState);
# 64 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_pm.h" 1
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
# 65 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_qei.h" 1
# 34 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_qei.h"
typedef struct
{
    FunctionalState m_IndexReset;

    FunctionalState m_DirectionEn;

    uint32_t m_WorkClock;

    FunctionalState m_DigitalFilterEn;

    uint32_t m_DigitalFilterPrescaler;

    FunctionalState m_SwapABEn;

    uint16_t m_Counter;

    uint16_t m_Period;

    uint16_t m_Prescaler;

}QEI_InitTypeDef;




typedef struct
{
    uint16_t m_Counter;

    uint16_t m_Period;

    uint16_t m_Prescaler;

    uint32_t m_CounterMode;

    uint32_t m_ClockSource;

}QEI_TimerTypeDef;
# 163 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_qei.h"
void QEI_Reset (QEI_SFRmap* QEIx);
void QEI_Configuration(QEI_SFRmap* QEIx, QEI_InitTypeDef* qeiInitStruct);
void QEI_Timer_Configuration(QEI_SFRmap* QEIx,
                    QEI_TimerTypeDef* qeiTimerInitStruct);
void QEI_Struct_Init (QEI_InitTypeDef* qeiInitStruct);
void QEI_Timer_Struct_Init (QEI_TimerTypeDef* qeiTimerInitStruct);

void QEI_Encoder_Mode_Config (QEI_SFRmap* QEIx, uint32_t PortMode);
void QEI_Location_Counter_Reset_Enable (QEI_SFRmap* QEIx,FunctionalState NewState);
void QEI_Timer_Source_Clock_Config (QEI_SFRmap* QEIx, uint32_t TimerClock);
FlagStatus QEI_Get_Index_Pin_State (QEI_SFRmap* QEIx);
void QEI_Location_Counter_Output_Enable (QEI_SFRmap* QEIx,FunctionalState NewState);
void QEI_Location_Counter_Direction_Config (QEI_SFRmap* QEIx,uint32_t Direction);
FlagStatus QEI_Get_Location_Counter_Direction (QEI_SFRmap* QEIx);
void QEI_Source_Clock_Config (QEI_SFRmap* QEIx, uint32_t PeripheralClock);
void QEI_Digital_Filter_Output_Enable (QEI_SFRmap* QEIx,FunctionalState NewState);
void QEI_Digital_Filter_Clock_Config (QEI_SFRmap* QEIx,uint32_t PeripheralClock);
void QEI_Swap_Phase_AB_Enable (QEI_SFRmap* QEIx, FunctionalState NewState);
void QEI_Timer_Counter_Config (QEI_SFRmap* QEIx, uint16_t Counter);
uint16_t QEI_Get_Timer_Counter (QEI_SFRmap* QEIx);
void QEI_Timer_Period_Config (QEI_SFRmap* QEIx, uint16_t Period);
uint16_t QEI_Get_Timer_Period (QEI_SFRmap* QEIx);
void QEI_Timer_Prescaler_Config (QEI_SFRmap* QEIx, uint16_t Prescaler);

FlagStatus QEI_Get_INT_Flag (QEI_SFRmap* QEIx, uint32_t InterruptType);
RetStatus QEI_Clear_INT_Flag (QEI_SFRmap* QEIx, uint32_t InterruptType);
void QEI_Set_INT_Enable (QEI_SFRmap* QEIx,uint32_t InterruptType, FunctionalState NewState);
FlagStatus QEI_Get_Counter_Overflow_INT_Flag (QEI_SFRmap* QEIx);
FlagStatus QEI_Get_Phase_Error_INT_Flag (QEI_SFRmap* QEIx);
FlagStatus QEI_Get_Count_Error_INT_Flag (QEI_SFRmap* QEIx);
RetStatus QEI_Clear_Timer_Overflow_INT_Flag (QEI_SFRmap* QEIx);
RetStatus QEI_Clear_Phase_Error_INT_Flag (QEI_SFRmap* QEIx);
RetStatus QEI_Clear_Counter_Error_INT_Flag (QEI_SFRmap* QEIx);
void QEI_Timer_Overflow_INT_Enable (QEI_SFRmap* QEIx,FunctionalState NewState);
void QEI_Phase_Error_INT_Enable (QEI_SFRmap* QEIx, FunctionalState NewState);
void QEI_Counter_Error_INT_Enable (QEI_SFRmap* QEIx, FunctionalState NewState);
# 66 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rng.h" 1
# 87 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rng.h"
void RNG_Reset(void);
void RNG_Real_RNG_Mode_Enable(FunctionalState NewState);
void RNG_Real_RNG_Seed_Correct_Enable(FunctionalState NewState);
void RNG_Real_RNG_Seed_High_Pow_Enable(FunctionalState NewState);
void RNG_Real_RNG_Seed_Frequency_Cail_Select(uint32_t Select);
void RNG_Real_RNG_Seed_Output_Enable(FunctionalState NewState);
void RNG_Real_RNG_Seed_Generator_Enable(FunctionalState NewState);
void RNG_CLK_DIV_Select(uint32_t DIV);
void RNG_Work_CLK_Select(uint32_t CLK);
void RNG_Seed_Select(uint32_t Seed);
void RNG_Enable(FunctionalState NewState);
FlagStatus RNG_Get_Current_Error_Status(void);
void RNG_INT_Enable(uint32_t Select, FunctionalState NewState);
RetStatus RNG_Clear_INT_Flag(uint32_t Select);
FlagStatus RNG_Get_INT_Flag(uint32_t Select);
uint16_t RNG_Seed_Value(void);
uint32_t RNG_Data_Value(void);
# 67 "../system_init.h" 2
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
# 68 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rtc.h" 1
# 35 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rtc.h"
typedef struct
{
    uint8_t m_Hours;

    uint8_t m_Minutes;

    uint8_t m_Seconds;

    uint8_t m_AMPM;

}RTC_TimeTypeDef;




typedef struct
{
    uint8_t m_WeekDay;

    uint8_t m_Day;

    uint8_t m_Month;

    uint8_t m_Year;

}RTC_DateTypeDef;




typedef struct
{
    uint32_t m_ClockSource;

    uint32_t m_HourFormat;

    RTC_TimeTypeDef m_TimeStruct;
    RTC_DateTypeDef m_DateStruct;
}RTC_InitTypeDef;




typedef struct
{
    uint8_t m_WeekDay;

    uint8_t m_Hours;

    uint8_t m_Minutes;

    uint8_t m_Seconds;

    uint8_t m_AMPM;

    uint32_t m_WeekDayEnable;

    uint32_t m_HoursEnable;

    uint32_t m_MinutesEnable;

    uint32_t m_SecondsEnable;

}RTC_AlarmTypeDef;
# 308 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_rtc.h"
void RTC_Reset (void);
void RTC_Configuration (uint32_t TimeFormat,RTC_InitTypeDef * rtcInitStruct);
void RTC_Time_Struct_Init (RTC_TimeTypeDef* rtcTimeInitStruct);
void RTC_Date_Struct_Init (RTC_DateTypeDef* rtcDateInitStruct);
void RTC_Struct_Init (RTC_InitTypeDef * rtcInitStruct);
void RTC_Get_Time_Configuration (uint32_t TimeFormat,RTC_TimeTypeDef* rtcTimeStruct);
void RTC_Get_Date_Configuration (uint32_t TimeFormat,RTC_DateTypeDef* rtcDateStruct);
void RTC_Alarm_Configuration (uint32_t AlarmSelect,uint32_t TimeFormat,RTC_AlarmTypeDef* rtcAlarmInitStruct);
void RTC_Alarm_Struct_Init (RTC_AlarmTypeDef* rtcAlarmInitStruct);

void RTC_Clock_Calibration_Config (int8_t Calibration);
void RTC_Time_Tick_Output_Enable (FunctionalState NewState);
void RTC_Time_Stamp_Channel_Enable (uint32_t TimeStampChannel,FunctionalState NewState);
void RTC_Time_Stamp_Edge_Config (uint32_t TimeStamp);
void RTC_Time_Stamp_Edge_Enable (FunctionalState NewState);
void RTC_Add_One_Hour_Enable (FunctionalState NewState);
void RTC_Sub_One_Hour_Enable (FunctionalState NewState);
void RTC_Time_Tick_Config (uint32_t Calibration);
void RTC_Reset_Config (void);
FlagStatus RTC_Get_Leap_Year_Flag (void);
void RTC_Hour_Format_Config (uint32_t HourFormat);
void RTC_Config_Mode_Enable (uint32_t ConfigMode);
FlagStatus RTC_Get_Operation_Off_Flag (void);
FlagStatus RTC_Get_Action_State_Flag (void);
void RTC_Work_Clock_Config (uint32_t Source);
void RTC_Enable (FunctionalState NewState);

void RTC_Alarm_A_Enable (FunctionalState NewState);
void RTC_Alarm_A_Weekday_Enable (FunctionalState NewState);
void RTC_Alarm_A_Weekday_Config (uint8_t Weekday);
void RTC_Alarm_A_Hours_Enable (FunctionalState NewState);
void RTC_Alarm_A_AMPM_Config (uint32_t NewSelect);
void RTC_Alarm_A_Hours_Config (uint32_t Hour);
void RTC_Alarm_A_Minutes_Enable (FunctionalState NewState);
void RTC_Alarm_A_Minutes_Config (uint32_t Minutes);
void RTC_Alarm_A_Seconds_Enable (FunctionalState NewState);
void RTC_Alarm_A_Seconds_Config (uint32_t Seconds);
void RTC_Alarm_B_Enable (FunctionalState NewState);
void RTC_Alarm_B_Weekday_Enable (FunctionalState NewState);
void RTC_Alarm_B_Weekday_Config (uint8_t Weekday);
void RTC_Alarm_B_Hours_Enable (FunctionalState NewState);
void RTC_Alarm_B_AMPM_Config (uint32_t NewSelect);
void RTC_Alarm_B_Hours_Config (uint32_t Hour);
void RTC_Alarm_B_Minutes_Enable (FunctionalState NewState);
void RTC_Alarm_B_Minutes_Config (uint32_t Minutes);
void RTC_Alarm_B_Seconds_Enable (FunctionalState NewState);
void RTC_Alarm_B_Seconds_Config (uint32_t Seconds);

void RTC_Weekday_Config (uint8_t Weekday);
void RTC_AMPM_Config (uint32_t NewSelect);
void RTC_Hours_Config (uint32_t Hour);
void RTC_Minutes_Config (uint32_t Minutes);
void RTC_Seconds_Config (uint32_t Seconds);
void RTC_Year_Config (uint32_t Year);
void RTC_Month_Config (uint32_t Month);
void RTC_Day_Config (uint32_t Day);
void RTC_Weekday_Backup_Config (uint8_t Weekday);
void RTC_AMPM_Backup_Config (uint32_t NewSelect);
void RTC_Hours_Backup_Config (uint32_t Hour);
void RTC_Minutes_Backup_Config (uint32_t Minutes);
void RTC_Seconds_Backup_Config (uint32_t Seconds);
void RTC_Year_Backup_Config (uint32_t Year);
void RTC_Month_Backup_Config (uint32_t Month);
void RTC_Day_Backup_Config (uint32_t Day);

void RTC_Timer1_Config (uint16_t Counter);
void RTC_Timer0_Config (uint16_t Counter);
void RTC_Timer1_Enable (uint32_t TimerEnable);
void RTC_Timer0_Enable (uint32_t TimerEnable);
void RTC_Timer1_Source_Config (uint16_t Counter);
void RTC_Timer0_Source_Config (uint16_t Counter);

void RTC_Time_Stamp_INT_Enable (FunctionalState NewState);
void RTC_Time_Stamp_Overflow_INT_Enable (FunctionalState NewState);
void RTC_Timer1_INT_Enable (FunctionalState NewState);
void RTC_Timer0_INT_Enable (FunctionalState NewState);
void RTC_Time_Tick_INT_Enable (FunctionalState NewState);
void RTC_Alarm_B_INT_Enable (FunctionalState NewState);
void RTC_Alarm_A_INT_Enable (FunctionalState NewState);
void RTC_Days_INT_Enable (FunctionalState NewState);
void RTC_Hours_INT_Enable (FunctionalState NewState);
void RTC_Minutes_INT_Enable (FunctionalState NewState);
void RTC_Seconds_INT_Enable (FunctionalState NewState);
FlagStatus RTC_Get_Time_Stamp_INT_Flag (void);
FlagStatus RTC_Get_Time_Stamp_Overflow_INT_Flag (void);
FlagStatus RTC_Get_Timer1_INT_Flag (void);
FlagStatus RTC_Get_Timer0_INT_Flag (void);
FlagStatus RTC_Get_Time_Tick_INT_Flag (void);
FlagStatus RTC_Get_Alarm_B_INT_Flag (void);
FlagStatus RTC_Get_Alarm_A_INT_Flag (void);
FlagStatus RTC_Get_Days_INT_Flag (void);
FlagStatus RTC_Get_Hours_INT_Flag (void);
FlagStatus RTC_Get_Minutes_INT_Flag (void);
FlagStatus RTC_Get_Seconds_INT_Flag (void);
RetStatus RTC_Clear_Time_Stamp_INT_Flag (void);
RetStatus RTC_Clear_Time_Stamp_Overflow_INT_Flag (void);
RetStatus RTC_Clear_Timer1_INT_Flag (void);
RetStatus RTC_Clear_Timer0_INT_Flag (void);
RetStatus RTC_Clear_Time_Tick_INT_Flag (void);
RetStatus RTC_Clear_Alarm_B_INT_Flag (void);
RetStatus RTC_Clear_Alarm_A_INT_Flag (void);
RetStatus RTC_Clear_Days_INT_Flag (void);
RetStatus RTC_Clear_Hours_INT_Flag (void);
RetStatus RTC_Clear_Minutes_INT_Flag (void);
RetStatus RTC_Clear_Seconds_INT_Flag (void);
# 69 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_spi.h" 1
# 42 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_spi.h"
typedef struct
{
    uint32_t m_Mode;

    uint32_t m_Clock;

    uint32_t m_FirstBit;

    uint32_t m_CKP;

    uint32_t m_CKE;

    uint32_t m_DataSize;

    uint16_t m_BaudRate;

}SPI_InitTypeDef;




typedef struct
{
    uint32_t m_Mode;

    uint32_t m_Standard;

    uint32_t m_PCM;

    uint32_t m_Clock;

    uint8_t m_Prescaler;

}I2S_InitTypeDef;
# 239 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_spi.h"
void SPI_Reset(SPI_SFRmap* SPIx);
void SPI_Configuration(SPI_SFRmap* SPIx, SPI_InitTypeDef* spiInitStruct);
void I2S_Configuration(SPI_SFRmap* SPIx, I2S_InitTypeDef* i2sInitStruct);
void SPI_Struct_Init(SPI_InitTypeDef* SPI_InitStruct);
void I2S_Struct_Init(I2S_InitTypeDef* I2S_InitStruct);


void SPI_Cmd (SPI_SFRmap* SPIx, FunctionalState NewState);
void I2S_Mode_Select(SPI_SFRmap* SPIx, FunctionalState NewState);
uint32_t SPI_I2S_ReceiveData(SPI_SFRmap* SPIx);
void SPI_I2S_SendData32(SPI_SFRmap* SPIx, uint32_t Data);
void SPI_I2S_SendData8(SPI_SFRmap* SPIx, uint8_t Data);
void SPI_BaudRate_Config (SPI_SFRmap* SPIx, uint16_t BAUDRATE);
void I2S_DIV_Config (SPI_SFRmap* SPIx, uint8_t DIV);
void SPI_MODE_Config (SPI_SFRmap* SPIx, uint32_t MODE);
void SPI_CLK_Config (SPI_SFRmap* SPIx, uint32_t ClockSource);
void SPI_Data_Direction_Config(SPI_SFRmap* SPIx, uint32_t DataDirection);
void SPI_Slave_PIN_Config (SPI_SFRmap* SPIx,uint32_t Select);
void SPI_Port_Connection_Mode (SPI_SFRmap* SPIx,uint32_t Mode);
void SPI_Clock_Polarity_Config (SPI_SFRmap* SPIx, uint32_t Polarity);
void SPI_Clock_Edge_Config (SPI_SFRmap* SPIx, uint32_t ClockEdge);
void SPI_BIT_SELECT_Config(SPI_SFRmap* SPIx, uint32_t DataSize);
void SPI_I2S_MODE_Config (SPI_SFRmap* SPIx, uint32_t Mode);
void SPI_I2S_STANDARD_Config(SPI_SFRmap* SPIx, uint32_t Standard);
void SPI_PCM_Config (SPI_SFRmap* SPIx, uint32_t NewState);
void SPI_CHLEN_Config (SPI_SFRmap* SPIx, uint32_t NewState);
void SPI_MAIN_CLOCK_OUT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_I2S_Idle_MCK_Outpue_Select(SPI_SFRmap* SPIx,FunctionalState NewState);

void SPI_Receive_Overflow_INT_Enable (SPI_SFRmap* SPIx,
                    FunctionalState NewState);
void SPI_Transmit_Overflow_INT_Enable (SPI_SFRmap* SPIx,
                    FunctionalState NewState);
void SPI_RNEIE_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_TNEIE_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_Receive_DMA_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_Transmit_DMA_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_Transmit_CHSIDE_INT_Enable (SPI_SFRmap* SPIx,
                    FunctionalState NewState);
FlagStatus SPI_Get_BUSY_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Receive_Overflow_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Transmit_Overflow_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Receive_Buf_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Transmit_Buf_Flag (SPI_SFRmap* SPIx);
RetStatus SPI_Clear_Receive_Overflow_INT_Flag (SPI_SFRmap* SPIx);
RetStatus SPI_Clear_Transmit_Overflow_INT_Flag (SPI_SFRmap* SPIx);
# 70 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_sysctl.h" 1
# 95 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_sysctl.h"
FlagStatus SYSCTL_Get_V_Flag (void);
FlagStatus SYSCTL_Get_C_Flag (void);
FlagStatus SYSCTL_Get_Z_Flag (void);
FlagStatus SYSCTL_Get_N_Flag (void);
void SYSCTL_Set_V_Flag (FunctionalState NewState);
void SYSCTL_Set_C_Flag (FunctionalState NewState);
void SYSCTL_Set_Z_Flag (FunctionalState NewState);
void SYSCTL_Set_N_Flag (FunctionalState NewState);
void SYSCTL_Sleep_On_Exit_Enable (FunctionalState NewState);
void SYSCTL_Interrupt_Awake_Enable (FunctionalState NewState);
FlagStatus SYSCTL_Stack_Align_State (void);
void SYSCTL_Super_User_Config (FunctionalState NewState);
FlagStatus SYSCTL_Stack_Pointer_State (void);
void SYSCTL_Stack_Pointer_Config (uint32_t PresentSP);
void SYSCTL_Exception_Reset_Enable (FunctionalState NewState);
void SYSCTL_System_Reset_Enable (FunctionalState NewState);
void SYSCTL_Core_Dma_Clear_Enable(FunctionalState NewState);
void SYSCTL_Cdmaam_Config(uint32_t Mode);
void SYSCTL_RW_Per_Cycle_Config(uint32_t Cycle);
void SYSCTL_RW_Dma_Cycle_Config(uint32_t Cycle);
void SYSCTL_RW_Dma_Long_Cycle_Config(uint32_t Cycle);
void SYSCTL_Vector_Offset_Config (uint32_t VectorOffset);
void SYSCTL_Ram_Space_Config (uint32_t RamSpace);
void SYSCTL_Flash_Start_Remap_Config (uint32_t MemCtl);
void SYSCTL_MSPSPAH_Threshold_Config (uint16_t Mspspah);
void SYSCTL_MSPSPAL_Threshold_Config (uint16_t Mspspal);
void SYSCTL_PSPSPAH_Threshold_Config (uint16_t Pspspah);
void SYSCTL_PSPSPAL_Threshold_Config (uint16_t Pspspal);
# 71 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_systick.h" 1
# 37 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_systick.h"
typedef struct
{
    uint32_t m_Period;
    uint32_t m_Clock;

    uint32_t m_SysTickINT;

} SYSTICK_InitTypeDef;
# 61 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_systick.h"
void SYSTICK_Configuration (uint32_t Clock, uint32_t SysTickINT,uint32_t Reload);


void SYSTICK_Cmd (FunctionalState NewState);
void SYSTICK_Clock_Config (uint32_t SysClock);
void SYSTICK_Systick_INT_Enable (uint32_t SysClock);
FlagStatus SYSTICK_Get_Count_Zero_Flag (void);
void SYSTICK_Reload_Config (uint32_t Reload);
void SYSTICK_Counter_Updata (void);
uint32_t SYSTICK_Get_Reload (void);
uint32_t SYSTICK_Get_Counter (void);
# 72 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_usart.h" 1
# 39 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_usart.h"
typedef struct
{
    uint32_t m_Mode;

    uint32_t m_HalfDuplexClkSource;
    uint32_t m_TransferDir;
    uint32_t m_WordLength;
    uint32_t m_StopBits;
    uint32_t m_Bit9SEL;
    uint32_t m_Parity;
    uint32_t m_ReceiveOrder;
    uint32_t m_TransmitOrder;
    uint32_t m_BRAutoDetect;
    uint32_t m_HardwareFlowControl;
    uint16_t m_BaudRateBRCKS;
    uint16_t m_BaudRateInteger;
    uint16_t m_BaudRateNumerator;
    uint16_t m_BaudRateDenominator;
} USART_InitTypeDef;




typedef struct
{
    uint32_t m_ErrorSignal;

    uint32_t m_PassagewaySelect;

    uint32_t m_TransmitRepeat;

    uint32_t m_ReceiveRepeat;

    FunctionalState m_Clkout;

    uint8_t m_ClkDiv;

    uint8_t m_Egt;

} U7816R_InitTypeDef;
# 324 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_usart.h"
void USART_Reset (USART_SFRmap* USARTx);
void USART_Configuration (USART_SFRmap* USARTx,
                    USART_InitTypeDef* usartInitStruct);
void USART_U7816R_Configuration (USART_SFRmap* USARTx,
                    U7816R_InitTypeDef* usartInitStruct);
void USART_Struct_Init(USART_InitTypeDef* usartInitStruct);
void USART_U7816R_Struct_Init(U7816R_InitTypeDef* usartInitStruct);


void USART_Cmd (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_BaudRate_Clock_Config(USART_SFRmap* USARTx, uint32_t CLK);
void USART_HalfDuplex_ClockPolarity_Config(USART_SFRmap* USARTx,
                    uint32_t NewState);
void USART_Transmit_Order_Config (USART_SFRmap* USARTx, uint32_t NewState);
void USART_Receive_Order_Config (USART_SFRmap* USARTx, uint32_t NewState);
void USART_Infrare_Detector_Voltage_Config (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_WeakUP_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Clock_Source_Config(USART_SFRmap* USARTx, uint32_t ClockSource);
void USART_Address_Detection_Enable(USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Auto_BaudRate_Detection_Enable(USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Send_Blank_Length_Config(USART_SFRmap* USARTx, uint32_t UBLength);
void USART_Send_Blank_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_SYNC_Choice_Config(USART_SFRmap* USARTx, uint32_t NewMode);
void USART_Transmit_Data_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Receive_Data_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_STOP_Word_Config(USART_SFRmap* USARTx, uint32_t NewLength);
void USART_Transmit_9Word_Select_Config (USART_SFRmap* USARTx,
                    uint32_t NewState);
void USART_Parity_Select_Config(USART_SFRmap* USARTx, uint32_t NewState);
void USART_9Data_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_CTS_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_RTS_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Infrare_Detector_Enable(USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Singlet_LINe_Mode_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_BaudRate_Integer_Config(USART_SFRmap* USARTx, uint16_t DIV);
void USART_BaudRate_Decimal1_Config(USART_SFRmap* USARTx, uint32_t DIV);
void USART_BaudRate_Decimal2_Config(USART_SFRmap* USARTx, uint32_t DIV);
RetStatus USART_SendData(USART_SFRmap* USARTx, uint8_t Data);
uint32_t USART_ReceiveData(USART_SFRmap* USARTx);
void USART_Address_Match_Config(USART_SFRmap* USARTx, uint8_t DIV);
void USART_Send_Idle_Frame_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Receive_Idle_Frame_Config(USART_SFRmap* USARTx, FunctionalState NewState);


void USART_7816_Cmd(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_7816_CLKOUT_Enable (USART_SFRmap* USARTx,FunctionalState NewState);
void USART_7816_Error_Signal_Config (USART_SFRmap* USARTx,uint32_t ERRORSIGNAL);
void USART_Passageway_Select_Config(USART_SFRmap* USARTx, uint32_t NewState);
void USART_BGT_Config(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Transmit_Repeat_Enable(USART_SFRmap* USARTx,FunctionalState NewState);
void USART_Receive_Repeat_Enable(USART_SFRmap* USARTx,FunctionalState NewState);
void USART_Transmit_Repeat_Times_Config(USART_SFRmap* USARTx, uint32_t SELECT);
void USART_Receive_Repeat_Times_Config(USART_SFRmap* USARTx, uint32_t SELECT);
void USART_7816_CLKDIV_Config (USART_SFRmap* USARTx, uint8_t DIV);
void USART_7816_EGT_Config(USART_SFRmap* USARTx, uint8_t EGT);
void USART_7816_Resend_Mode_Select(USART_SFRmap* USARTx, FunctionalState NewState);


void USART_Receive_Overflow_INT_Enable (USART_SFRmap* USARTx,FunctionalState NewState);
void USART_Parity_ERROR_INT_Enable (USART_SFRmap* USARTx,FunctionalState NewState);
void USART_Frame_ERROE_INT_Enable (USART_SFRmap* USARTx,FunctionalState NewState);
void USART_Blank_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Auto_BaudRate_TimeOver_INT_Enable (USART_SFRmap* USARTx,FunctionalState NewState);
void USART_WeakUP_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Transmit_ERROR_INT_Enable (USART_SFRmap* USARTx,FunctionalState NewState);
void USART_Receive_ERROR_INT_Enable (USART_SFRmap* USARTx,FunctionalState NewState);
void USART_CTS_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_RDR_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_TFE_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_TXE_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_DMA_Read_Receive_Enable (USART_SFRmap* USARTx,FunctionalState NewState);
void USART_DMA_Write_Transmit_Enable (USART_SFRmap* USARTx,FunctionalState NewState);
void USART_IDLE_INT_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
FlagStatus USART_Get_Receive_Overflow_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Parity_ERROR_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Frame_ERROR_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Blank_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Auto_Baudrate_TimeOver_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_WeakUP_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_7816Transmit_ERROR_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_7816Receive_ERROR_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_CTS_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Receive_BUFR_Ready_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Transmit_BUFR_Empty_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Transmitter_Empty_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Receive_Frame_Idel_Flag(USART_SFRmap* USARTx);
RetStatus USART_Clear_Idle_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_Receive_Overflow_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_Parity_ERROR_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_Frame_ERROR_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_Blank_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_Auto_BaudRate_TimeOver_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_WeakUP_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_Transmit_ERROR_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_Receive_ERROR_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_CTS_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_Receive_BUFR_INT_Flag (USART_SFRmap* USARTx);
RetStatus USART_Clear_Transmit_BUFR_INT_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_WUEN_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Auto_BaudRate_Detection_Flag(USART_SFRmap* USARTx);
void USART_RESHD_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
# 73 "../system_init.h" 2
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_wwdt.h" 1
# 89 "D:\\KungFu32\\workspace32\\Demo1_light\\inc/kf32a1x6_wwdt.h"
void WWDT_Reset (void);
void WWDT_Threshold_Config (uint32_t Threshold);
void WWDT_Prescaler_Config (uint32_t Prescaler);
void WWDT_Work_CLK_Selest(uint32_t Source);
void WWDT_Enable (uint32_t NewState);
void WWDT_Counter_Config (uint32_t Counter);
uint32_t WWDT_Get_Counter (void);

void WWDT_INT_Enable (uint32_t NewState);
FlagStatus WWDT_Get_INT_Flag (void);
RetStatus WWDT_Clear_INT_Flag (void);
# 74 "../system_init.h" 2
# 105 "../system_init.h"
static const uint8_t PLL_Value_Select[][3] = {
  {25,2,8},{13,1,8},{27,2,8},{14,1,8},{29,2,8},{15,1,8},{31,2,8},{16,1,8},{33,2,8},
  {17,1,8},{35,2,8},{18,1,8},{37,2,8},{19,1,8},{39,2,8},{20,1,8},{41,2,8},{21,1,8},
  {43,2,8},{22,1,8},{45,2,8},{23,1,8},{47,2,8},{24,1,8},{49,2,8},{25,1,8},{51,4,4},
  {13,1,4},{53,4,4},{27,2,4},{55,4,4},{14,1,4},{57,4,4},{29,2,4},{59,4,4},{15,1,4},
  {61,4,4},{31,2,4},{63,4,4},{16,1,4},{65,4,4},{33,2,4},{67,4,4},{17,1,4},{69,4,4},
  {35,2,4},{71,4,4},{18,1,4},{73,4,4},{37,2,4},{75,4,4},{19,1,4},{77,4,4},{39,2,4},
  {79,4,4},{20,1,4},{81,4,4},{41,2,4},{83,4,4},{21,1,4},{85,4,4},{43,2,4},{87,4,4},
  {22,1,4},{89,4,4},{45,2,4},{91,4,4},{23,1,4},{93,4,4},{47,2,4},{95,4,4},{24,1,4},
  {97,4,4},{49,2,4},{99,4,4},{25,1,4},{101,8,2},{51,4,2},{103,8,2},{13,1,2},{105,8,2},
  {53,4,2},{107,8,2},{27,2,2},{109,8,2},{55,4,2},{111,8,2},{14,1,2},{113,8,2},{57,4,2},
  {115,8,2},{29,2,2},{117,8,2},{59,4,2},{119,8,2},{15,1,2}
};
# 169 "../system_init.h"
void SystemInit(uint8_t SCLK_Value);
void systick_delay_init(uint32_t SystemCoreClock);
void systick_delay_us(unsigned int nus);
void systick_delay_ms(unsigned int nms);
uint32_t SystemCoreClockUpdate(void);
# 31 "../system_init.c" 2
# 87 "../system_init.c"
static uint8_t fac_us;
static uint16_t fac_ms;




static void SetSysClock(uint8_t SCLK_Value);
# 104 "../system_init.c"
static void SetSysClock(uint8_t SCLK_Value)
{
 volatile uint32_t StartUpCounter;






 OSC_INTLF_Software_Enable(TRUE);
 OSC_INTHF_Software_Enable(TRUE);
 (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG) = 0xC7;

 OSC_SCK_Division_Config(((uint32_t)0x0));
 OSC_SCK_Source_Config(((uint32_t)0x0));
 StartUpCounter = ((uint16_t)0x0070);
 while (--StartUpCounter);
 while (OSC_Get_INTHF_INT_Flag() != SET);
# 134 "../system_init.c"
 __asm volatile("SET [%0], #%1"::"r"(&((((OSC_SFRmap *)((uint32_t)0x40000000))->CTL0))),"i"((0)));
 __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((22)));
 __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((7)));
    __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1))),"i"((15)));



 {
  __asm volatile("SET [%0], #%1"::"r"(&((((OSC_SFRmap *)((uint32_t)0x40000000))->HFOSCCAL1))),"i"((0)));
 }
# 162 "../system_init.c"
 GPIO_Write_Mode_Bits(((GPIO_SFRmap *) ((uint32_t)0x500001C0)), ((uint16_t)0x0800), GPIO_MODE_OUT);
 GPIO_Set_Output_Data_Bits(((GPIO_SFRmap *) ((uint32_t)0x500001C0)), ((uint16_t)0x0800), Bit_RESET);
 StartUpCounter = ((uint16_t)0x0070);
 while (--StartUpCounter);
 GPIO_Write_Mode_Bits(((GPIO_SFRmap *) ((uint32_t)0x500001C0)), ((uint16_t)0x0800), GPIO_MODE_AN);

 OSC_EXTHF_Software_Enable(TRUE);
 OSC_EXTHF_Start_Delay_Config(((uint32_t)0x00));
 StartUpCounter = ((uint16_t)0xA39);
 while (StartUpCounter--);
 while(OSC_Get_EXTHF_INT_Flag() != SET);
 OSC_SCK_Source_Config(((uint32_t)0x2));
 OSC_PLL_Input_Source_Config(((uint32_t)0x1));
# 186 "../system_init.c"
if((SCLK_Value >= 25) && (SCLK_Value <= 120))
{
 OSC_PLL_Multiple_Value_Select(PLL_Value_Select[SCLK_Value-25][0],
    PLL_Value_Select[SCLK_Value-25][1],PLL_Value_Select[SCLK_Value-25][2]);







  OSC_PLL_Start_Delay_Config(((uint32_t)0x07));




 OSC_PLL_Software_Enable(TRUE);
 OSC_PLL_RST();
 while (OSC_Get_PLL_INT_Flag() != SET);
 if(SCLK_Value <= 48)
  (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG) = 0xC2;
 else if(SCLK_Value <= 96)
  (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG) = 0xC4;
 else if(SCLK_Value <= 120)
  (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG) = 0xC5;

 OSC_SCK_Division_Config(((uint32_t)0x0));
 OSC_SCK_Source_Config(((uint32_t)0x4));
}
else
{
 OSC_SCK_Division_Config(((uint32_t)0x0));



 OSC_SCK_Source_Config(((uint32_t)0x2));

}

 OSC_HFCK_Division_Config(((uint32_t)0x0));



 OSC_HFCK_Source_Config(((uint32_t)0x2));

 OSC_HFCK_Enable(TRUE);


 OSC_LFCK_Division_Config(((uint32_t)0x0));
 OSC_LFCK_Source_Config(((uint32_t)0x0));
 OSC_LFCK_Enable(TRUE);
# 249 "../system_init.c"
}
# 261 "../system_init.c"
void SystemInit(uint8_t SCLK_Value)
{



 SetSysClock(SCLK_Value);






}
# 282 "../system_init.c"
void systick_delay_init(uint32_t InputClock)
{
 SYSTICK_Cmd(FALSE);
 SYSTICK_Clock_Config(((uint32_t)0x0 << (2)));
 __asm volatile("CLR [%0], #%1"::"r"(&((((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CALI))),"i"((31)));
 fac_us = InputClock >> 1;
 fac_ms = fac_us * 1000;
}
# 303 "../system_init.c"
void systick_delay_us(unsigned int nus)
{
 uint32_t temp;
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->RELOAD = fac_us * nus;
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CV = 0;
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CTL |= ((uint32_t)1<<((0)));
 do
 {
  temp = (((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CTL);
 } while ((temp & 0x01) && !(temp & (1 << 16)));
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CTL &= ~((uint32_t)1<<((0)));
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CV = 0;
}
# 329 "../system_init.c"
void systick_delay_ms(unsigned int nms)
{
 uint32_t temp;
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->RELOAD = (uint32_t)nms * fac_ms;
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CV = 0;
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CTL |= ((uint32_t)1<<((0)));
 do
 {
  temp = (((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CTL);
 } while ((temp & 0x01) && !(temp & (1 << 16)));
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CTL &= ~((uint32_t)1<<((0)));
 ((SYSTICK_SFRmap *) ((uint32_t)0x402000A0))->CV = 0;
}
# 352 "../system_init.c"
uint32_t SystemCoreClockUpdate(void)
{
 uint32_t SystemCoreClock;
    uint32_t tmp = 0, pll_n = 1, pll_m = 0, pll_no = 1;
 uint32_t sckdivfactor = 1;
 uint32_t pllsource = 16000000;
 tmp = (((((OSC_SFRmap *)((uint32_t)0x40000000))->CTL0) >> (1)) & 0x07);
 switch (tmp) {
  case ((uint32_t)0x0):
   SystemCoreClock = 16000000;
   break;
  case ((uint32_t)0x1):
   SystemCoreClock = 32000;
   break;
  case ((uint32_t)0x2):
   SystemCoreClock = 16000000;
   break;
  case ((uint32_t)0x3):
   SystemCoreClock = 32768;
   break;
  case ((uint32_t)0x6):
   SystemCoreClock = 4000000;
   break;
  case ((uint32_t)0x4):
   if (((((OSC_SFRmap *)((uint32_t)0x40000000))->CTL0) >> (12)) & 0x01) {
    pllsource = 16000000;
   } else {
    pllsource = 16000000;
   }
   pll_m = (((((PLL_SFRmap *)((uint32_t)0x40002580))->CTL) >> (2)) & 0x3fff);
   pll_n = (((((PLL_SFRmap *)((uint32_t)0x40002580))->CTL) >> (16)) & 0x0f);
   pll_no = (0x01 << (((((PLL_SFRmap *)((uint32_t)0x40002580))->CTL) >> (20)) & 0x03));
   sckdivfactor = (0x01 << (((((OSC_SFRmap *)((uint32_t)0x40000000))->CTL0) >> (16)) & 0x07));
   SystemCoreClock = pllsource * pll_m / (pll_n * pll_no * sckdivfactor);
   break;
  default:
   SystemCoreClock = 16000000;
   break;
 }
 return SystemCoreClock;
}
