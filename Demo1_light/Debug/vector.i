# 1 "../_config/vector.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1\\Debug//"
# 1 "<command-line>"
# 1 "../_config/vector.c"
# 12 "../_config/vector.c"
extern __attribute__((section(".stack_mem"))) unsigned char Stack_Mem[0x200];
__attribute__((section(".stack_mem"))) unsigned char Stack_Mem[0x200];
# 156 "../_config/vector.c"
typedef struct
{
  void (*Func)(void);
}interruptVector;

typedef struct
{
  int *value;
  interruptVector Reset_Enter;

  interruptVector NMI_Enter;
  interruptVector HardFault_Enter;
  interruptVector Rev4_Enter;
  interruptVector StackFault_Enter;
  interruptVector AriFault_Enter;
  interruptVector Intended_Rev;

  interruptVector interrupt[120] ;
}VectorEnter;

extern int __initial_sp ;
extern void startup(void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _NMI_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _HardFault_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft4_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _StackFault_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _AriFault_exception (void);

void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft8_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft9_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft10_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _SVC_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft12_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft13_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _SoftSV_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _SysTick_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _WWDT_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT16_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT2_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT3_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT4_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT9TO5_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT15TO10_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T3_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T5_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T6_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T7_QEI0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T8_QEI1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _ECFGL_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _CAN4_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T14_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _RNG_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _FDC2_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EXIC_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _ADC0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _ADC1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _CFGL_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T11_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _DMA0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _CMP_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _USART0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _USART1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _SPI0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _SPI1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _DMA1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT19TO17_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _CANFD6_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _CANFD7_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _FDC0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _FDC1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _EINT31TO20_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _ECC_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _OSC_CLK_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _I2C0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _I2C1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _I2C2_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T12_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T2_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T4_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T13_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _USART2_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T16_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _USART4_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _SPI2_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _SPI3_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _ADC2_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T18_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T19_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _HRCAP0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _WKP4TO0_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _HRCAP1_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _T21_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _I2C3_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _USART5_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _HRCAP2_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _USART7_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft80_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft81_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft82_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft83_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft84_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft85_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft86_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft87_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft88_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft89_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft90_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft91_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft92_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft93_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft94_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft95_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft96_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft97_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft98_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft99_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft100_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft101_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft102_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft103_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft104_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft105_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft106_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft107_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft108_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft109_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft110_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft111_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft112_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft113_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft114_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft115_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft116_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft117_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft118_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft119_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft120_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft121_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft122_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft123_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft124_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft125_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft126_exception (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) _Soft127_exception (void);


extern const VectorEnter _start __attribute__((section(".text")));
const VectorEnter _start __attribute__((section(".text"))) =
{
  &__initial_sp,
  startup,
  _NMI_exception,
  _HardFault_exception,
  _Soft4_exception,
  _StackFault_exception,
  _AriFault_exception,
  {0},
  _Soft8_exception,
  _Soft9_exception,
  _Soft10_exception,
  _SVC_exception,
  _Soft12_exception,
  _Soft13_exception,
  _SoftSV_exception,
  _SysTick_exception,
  _WWDT_exception,
  _EINT16_exception,
  _EINT0_exception,
  _EINT1_exception,
  _EINT2_exception,
  _EINT3_exception,
  _EINT4_exception,
  _EINT9TO5_exception,
  _EINT15TO10_exception,
  _T1_exception,
  _T3_exception,
  _T5_exception,
  _T6_exception,
  _T7_QEI0_exception,
  _T8_QEI1_exception,
  _ECFGL_exception,
  _CAN4_exception,
  _T14_exception,
  _RNG_exception,
  _FDC2_exception,
  _EXIC_exception,
  _ADC0_exception,
  _ADC1_exception,
  _CFGL_exception,
  _T11_exception,
  _T0_exception,
  _DMA0_exception,
  _CMP_exception,
  _USART0_exception,
  _USART1_exception,
  _SPI0_exception,
  _SPI1_exception,
  _DMA1_exception,
  _EINT19TO17_exception,
  _CANFD6_exception,
  _CANFD7_exception,
  _FDC0_exception,
  _FDC1_exception,
  _EINT31TO20_exception,
  _ECC_exception,
  _OSC_CLK_exception,
  _I2C0_exception,
  _I2C1_exception,
  _I2C2_exception,
  _T12_exception,
  _T2_exception,
  _T4_exception,
  _T13_exception,
  _USART2_exception,
  _T16_exception,
  _USART4_exception,
  _SPI2_exception,
  _SPI3_exception,
  _ADC2_exception,
  _T18_exception,
  _T19_exception,
  _HRCAP0_exception,
  _WKP4TO0_exception,
  _HRCAP1_exception,
  _T21_exception,
  _I2C3_exception,
  _USART5_exception,
  _HRCAP2_exception,
  _USART7_exception,
  _Soft80_exception,
  _Soft81_exception,
  _Soft82_exception,
  _Soft83_exception,
  _Soft84_exception,
  _Soft85_exception,
  _Soft86_exception,
  _Soft87_exception,
  _Soft88_exception,
  _Soft89_exception,
  _Soft90_exception,
  _Soft91_exception,
  _Soft92_exception,
  _Soft93_exception,
  _Soft94_exception,
  _Soft95_exception,
  _Soft96_exception,
  _Soft97_exception,
  _Soft98_exception,
  _Soft99_exception,
  _Soft100_exception,
  _Soft101_exception,
  _Soft102_exception,
  _Soft103_exception,
  _Soft104_exception,
  _Soft105_exception,
  _Soft106_exception,
  _Soft107_exception,
  _Soft108_exception,
  _Soft109_exception,
  _Soft110_exception,
  _Soft111_exception,
  _Soft112_exception,
  _Soft113_exception,
  _Soft114_exception,
  _Soft115_exception,
  _Soft116_exception,
  _Soft117_exception,
  _Soft118_exception,
  _Soft119_exception,
  _Soft120_exception,
  _Soft121_exception,
  _Soft122_exception,
  _Soft123_exception,
  _Soft124_exception,
  _Soft125_exception,
  _Soft126_exception,
  _Soft127_exception
};

void __attribute__((interrupt,section(".rodata"))) _Default_NULL_exception (void);
void __attribute__((interrupt,section(".rodata"))) _Default_NULL_exception (void)
{
 while(1){};
}
