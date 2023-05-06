// important!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// important!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// important!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// space for minimal local libraries with malloc/free/calloc/realloc function
//#define Set_Heap_Size 0x400   // default 0x100 by script file
//extern __attribute__((section(".heap_mem"))) const unsigned char Heap_Mem[Set_Heap_Size];
//__attribute__((section(".heap_mem"))) const unsigned char Heap_Mem[Set_Heap_Size];

// support var for parse SP overflow : __MAX_Stack_LIMITS__  __Logic_Stack_Start__  __Logic_Stack_End__
#define Stack_Size 0x200		// global variable with  initialization + global variable with no initialization + Heap + Stack must less than size of ram 
extern __attribute__((section(".stack_mem"))) unsigned char Stack_Mem[Stack_Size];
__attribute__((section(".stack_mem"))) unsigned char Stack_Mem[Stack_Size];


/*Some Default Interrupt Function Like 	
	_NMI_exception 						
	_HardFault_exception				
	_StackFault_exception 				
	_SVC_exception  					
	_SoftSV_exception 					
	_SysTick_exception					
 is write in file named kf_it.c   		*/

// Here Are The Default Interrupt Function Name,Change or Default and Then Use Them.
//Format of Interrupt Function Must Be : void __attribute__((interrupt)) YourInterruptOrDefaultName (void);
#define V2_0x00000008_VectorFunction   _NMI_exception
#define V3_0x0000000C_VectorFunction   _HardFault_exception
#define V4_0x00000010_VectorFunction   _Soft4_exception
#define V5_0x00000014_VectorFunction   _StackFault_exception
#define V6_0x00000018_VectorFunction   _AriFault_exception

#define V8_0x00000020_VectorFunction   _Soft8_exception
#define V9_0x00000024_VectorFunction   _Soft9_exception
#define V10_0x00000028_VectorFunction   _Soft10_exception
#define V11_0x0000002C_VectorFunction   _SVC_exception
#define V12_0x00000030_VectorFunction   _Soft12_exception
#define V13_0x00000034_VectorFunction   _Soft13_exception
#define V14_0x00000038_VectorFunction   _SoftSV_exception
#define V15_0x0000003C_VectorFunction   _SysTick_exception
#define V16_0x00000040_VectorFunction   _WWDT_exception
#define V17_0x00000044_VectorFunction   _EINT16_exception
#define V18_0x00000048_VectorFunction   _EINT0_exception
#define V19_0x0000004C_VectorFunction   _EINT1_exception
#define V20_0x00000050_VectorFunction   _EINT2_exception
#define V21_0x00000054_VectorFunction   _EINT3_exception
#define V22_0x00000058_VectorFunction   _EINT4_exception
#define V23_0x0000005C_VectorFunction   _EINT9TO5_exception
#define V24_0x00000060_VectorFunction   _EINT15TO10_exception
#define V25_0x00000064_VectorFunction   _T1_exception
#define V26_0x00000068_VectorFunction   _T3_exception
#define V27_0x0000006C_VectorFunction   _T5_exception
#define V28_0x00000070_VectorFunction   _T6_exception
#define V29_0x00000074_VectorFunction   _T7_QEI0_exception
#define V30_0x00000078_VectorFunction   _T8_QEI1_exception
#define V31_0x0000007C_VectorFunction   _ECFGL_exception
#define V32_0x00000080_VectorFunction   _CAN4_exception
#define V33_0x00000084_VectorFunction   _T14_exception
#define V34_0x00000088_VectorFunction   _RNG_exception
#define V35_0x0000008C_VectorFunction   _FDC2_exception
#define V36_0x00000090_VectorFunction   _EXIC_exception
#define V37_0x00000094_VectorFunction   _ADC0_exception
#define V38_0x00000098_VectorFunction   _ADC1_exception
#define V39_0x0000009C_VectorFunction   _CFGL_exception
#define V40_0x000000A0_VectorFunction   _T11_exception
#define V41_0x000000A4_VectorFunction   _T0_exception
#define V42_0x000000A8_VectorFunction   _DMA0_exception
#define V43_0x000000AC_VectorFunction   _CMP_exception
#define V44_0x000000B0_VectorFunction   _USART0_exception
#define V45_0x000000B4_VectorFunction   _USART1_exception
#define V46_0x000000B8_VectorFunction   _SPI0_exception
#define V47_0x000000BC_VectorFunction   _SPI1_exception
#define V48_0x000000C0_VectorFunction   _DMA1_exception
#define V49_0x000000C4_VectorFunction   _EINT19TO17_exception
#define V50_0x000000C8_VectorFunction   _CANFD6_exception
#define V51_0x000000CC_VectorFunction   _CANFD7_exception
#define V52_0x000000D0_VectorFunction   _FDC0_exception
#define V53_0x000000D4_VectorFunction   _FDC1_exception
#define V54_0x000000D8_VectorFunction   _EINT31TO20_exception
#define V55_0x000000DC_VectorFunction   _ECC_exception
#define V56_0x000000E0_VectorFunction   _OSC_CLK_exception
#define V57_0x000000E4_VectorFunction   _I2C0_exception
#define V58_0x000000E8_VectorFunction   _I2C1_exception
#define V59_0x000000EC_VectorFunction   _I2C2_exception
#define V60_0x000000F0_VectorFunction   _T12_exception
#define V61_0x000000F4_VectorFunction   _T2_exception
#define V62_0x000000F8_VectorFunction   _T4_exception
#define V63_0x000000FC_VectorFunction   _T13_exception
#define V64_0x00000100_VectorFunction   _USART2_exception
#define V65_0x00000104_VectorFunction   _T16_exception
#define V66_0x00000108_VectorFunction   _USART4_exception
#define V67_0x0000010C_VectorFunction   _SPI2_exception
#define V68_0x00000110_VectorFunction   _SPI3_exception
#define V69_0x00000114_VectorFunction   _ADC2_exception
#define V70_0x00000118_VectorFunction   _T18_exception
#define V71_0x0000011C_VectorFunction   _T19_exception
#define V72_0x00000120_VectorFunction   _HRCAP0_exception
#define V73_0x00000124_VectorFunction   _WKP4TO0_exception
#define V74_0x00000128_VectorFunction   _HRCAP1_exception
#define V75_0x0000012C_VectorFunction   _T21_exception
#define V76_0x00000130_VectorFunction   _I2C3_exception
#define V77_0x00000134_VectorFunction   _USART5_exception
#define V78_0x00000138_VectorFunction   _HRCAP2_exception
#define V79_0x0000013C_VectorFunction   _USART7_exception
#define V80_0x00000140_VectorFunction   _Soft80_exception
#define V81_0x00000144_VectorFunction   _Soft81_exception
#define V82_0x00000148_VectorFunction   _Soft82_exception
#define V83_0x0000014C_VectorFunction   _Soft83_exception
#define V84_0x00000150_VectorFunction   _Soft84_exception
#define V85_0x00000154_VectorFunction   _Soft85_exception
#define V86_0x00000158_VectorFunction   _Soft86_exception
#define V87_0x0000015C_VectorFunction   _Soft87_exception
#define V88_0x00000160_VectorFunction   _Soft88_exception
#define V89_0x00000164_VectorFunction   _Soft89_exception
#define V90_0x00000168_VectorFunction   _Soft90_exception
#define V91_0x0000016C_VectorFunction   _Soft91_exception
#define V92_0x00000170_VectorFunction   _Soft92_exception
#define V93_0x00000174_VectorFunction   _Soft93_exception
#define V94_0x00000178_VectorFunction   _Soft94_exception
#define V95_0x0000017C_VectorFunction   _Soft95_exception
#define V96_0x00000180_VectorFunction   _Soft96_exception
#define V97_0x00000184_VectorFunction   _Soft97_exception
#define V98_0x00000188_VectorFunction   _Soft98_exception
#define V99_0x0000018C_VectorFunction   _Soft99_exception
#define V100_0x00000190_VectorFunction   _Soft100_exception
#define V101_0x00000194_VectorFunction   _Soft101_exception
#define V102_0x00000198_VectorFunction   _Soft102_exception
#define V103_0x0000019C_VectorFunction   _Soft103_exception
#define V104_0x000001A0_VectorFunction   _Soft104_exception
#define V105_0x000001A4_VectorFunction   _Soft105_exception
#define V106_0x000001A8_VectorFunction   _Soft106_exception
#define V107_0x000001AC_VectorFunction   _Soft107_exception
#define V108_0x000001B0_VectorFunction   _Soft108_exception
#define V109_0x000001B4_VectorFunction   _Soft109_exception
#define V110_0x000001B8_VectorFunction   _Soft110_exception
#define V111_0x000001BC_VectorFunction   _Soft111_exception
#define V112_0x000001C0_VectorFunction   _Soft112_exception
#define V113_0x000001C4_VectorFunction   _Soft113_exception
#define V114_0x000001C8_VectorFunction   _Soft114_exception
#define V115_0x000001CC_VectorFunction   _Soft115_exception
#define V116_0x000001D0_VectorFunction   _Soft116_exception
#define V117_0x000001D4_VectorFunction   _Soft117_exception
#define V118_0x000001D8_VectorFunction   _Soft118_exception
#define V119_0x000001DC_VectorFunction   _Soft119_exception
#define V120_0x000001E0_VectorFunction   _Soft120_exception
#define V121_0x000001E4_VectorFunction   _Soft121_exception
#define V122_0x000001E8_VectorFunction   _Soft122_exception
#define V123_0x000001EC_VectorFunction   _Soft123_exception
#define V124_0x000001F0_VectorFunction   _Soft124_exception
#define V125_0x000001F4_VectorFunction   _Soft125_exception
#define V126_0x000001F8_VectorFunction   _Soft126_exception
#define V127_0x000001FC_VectorFunction   _Soft127_exception


#define pFunc void (*Func)(void)
typedef struct
{
  pFunc;
}interruptVector;

typedef struct
{
  int  			 *value;				//auto variable by tool ,value is default sp
  interruptVector Reset_Enter;			//Enter Function,design lead function and run to main

  interruptVector NMI_Enter;
  interruptVector HardFault_Enter;
  interruptVector Rev4_Enter;
  interruptVector StackFault_Enter;
  interruptVector AriFault_Enter;
  interruptVector Intended_Rev;   		// create characteristic by linker,code write 0 here

  interruptVector interrupt[120] ;		// other
}VectorEnter;

extern int  __initial_sp  ;
extern void  startup(void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V2_0x00000008_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V3_0x0000000C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V4_0x00000010_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V5_0x00000014_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V6_0x00000018_VectorFunction (void);

void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V8_0x00000020_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V9_0x00000024_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V10_0x00000028_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V11_0x0000002C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V12_0x00000030_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V13_0x00000034_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V14_0x00000038_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V15_0x0000003C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V16_0x00000040_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V17_0x00000044_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V18_0x00000048_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V19_0x0000004C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V20_0x00000050_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V21_0x00000054_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V22_0x00000058_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V23_0x0000005C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V24_0x00000060_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V25_0x00000064_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V26_0x00000068_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V27_0x0000006C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V28_0x00000070_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V29_0x00000074_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V30_0x00000078_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V31_0x0000007C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V32_0x00000080_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V33_0x00000084_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V34_0x00000088_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V35_0x0000008C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V36_0x00000090_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V37_0x00000094_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V38_0x00000098_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V39_0x0000009C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V40_0x000000A0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V41_0x000000A4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V42_0x000000A8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V43_0x000000AC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V44_0x000000B0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V45_0x000000B4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V46_0x000000B8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V47_0x000000BC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V48_0x000000C0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V49_0x000000C4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V50_0x000000C8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V51_0x000000CC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V52_0x000000D0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V53_0x000000D4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V54_0x000000D8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V55_0x000000DC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V56_0x000000E0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V57_0x000000E4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V58_0x000000E8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V59_0x000000EC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V60_0x000000F0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V61_0x000000F4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V62_0x000000F8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V63_0x000000FC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V64_0x00000100_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V65_0x00000104_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V66_0x00000108_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V67_0x0000010C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V68_0x00000110_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V69_0x00000114_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V70_0x00000118_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V71_0x0000011C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V72_0x00000120_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V73_0x00000124_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V74_0x00000128_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V75_0x0000012C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V76_0x00000130_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V77_0x00000134_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V78_0x00000138_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V79_0x0000013C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V80_0x00000140_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V81_0x00000144_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V82_0x00000148_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V83_0x0000014C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V84_0x00000150_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V85_0x00000154_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V86_0x00000158_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V87_0x0000015C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V88_0x00000160_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V89_0x00000164_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V90_0x00000168_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V91_0x0000016C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V92_0x00000170_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V93_0x00000174_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V94_0x00000178_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V95_0x0000017C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V96_0x00000180_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V97_0x00000184_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V98_0x00000188_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V99_0x0000018C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V100_0x00000190_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V101_0x00000194_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V102_0x00000198_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V103_0x0000019C_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V104_0x000001A0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V105_0x000001A4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V106_0x000001A8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V107_0x000001AC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V108_0x000001B0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V109_0x000001B4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V110_0x000001B8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V111_0x000001BC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V112_0x000001C0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V113_0x000001C4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V114_0x000001C8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V115_0x000001CC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V116_0x000001D0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V117_0x000001D4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V118_0x000001D8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V119_0x000001DC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V120_0x000001E0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V121_0x000001E4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V122_0x000001E8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V123_0x000001EC_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V124_0x000001F0_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V125_0x000001F4_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V126_0x000001F8_VectorFunction (void);
void __attribute__((weak,interrupt,alias("_Default_NULL_exception"))) V127_0x000001FC_VectorFunction (void);


extern const VectorEnter _start __attribute__((section(".text")));
const VectorEnter _start __attribute__((section(".text"))) =
{
		&__initial_sp,
		startup,
		V2_0x00000008_VectorFunction,
		V3_0x0000000C_VectorFunction,
		V4_0x00000010_VectorFunction,
		V5_0x00000014_VectorFunction,
		V6_0x00000018_VectorFunction,
		{0},
		V8_0x00000020_VectorFunction,
		V9_0x00000024_VectorFunction,
		V10_0x00000028_VectorFunction,
		V11_0x0000002C_VectorFunction,
		V12_0x00000030_VectorFunction,
		V13_0x00000034_VectorFunction,
		V14_0x00000038_VectorFunction,
		V15_0x0000003C_VectorFunction,
		V16_0x00000040_VectorFunction,
		V17_0x00000044_VectorFunction,
		V18_0x00000048_VectorFunction,
		V19_0x0000004C_VectorFunction,
		V20_0x00000050_VectorFunction,
		V21_0x00000054_VectorFunction,
		V22_0x00000058_VectorFunction,
		V23_0x0000005C_VectorFunction,
		V24_0x00000060_VectorFunction,
		V25_0x00000064_VectorFunction,
		V26_0x00000068_VectorFunction,
		V27_0x0000006C_VectorFunction,
		V28_0x00000070_VectorFunction,
		V29_0x00000074_VectorFunction,
		V30_0x00000078_VectorFunction,
		V31_0x0000007C_VectorFunction,
		V32_0x00000080_VectorFunction,
		V33_0x00000084_VectorFunction,
		V34_0x00000088_VectorFunction,
		V35_0x0000008C_VectorFunction,
		V36_0x00000090_VectorFunction,
		V37_0x00000094_VectorFunction,
		V38_0x00000098_VectorFunction,
		V39_0x0000009C_VectorFunction,
		V40_0x000000A0_VectorFunction,
		V41_0x000000A4_VectorFunction,
		V42_0x000000A8_VectorFunction,
		V43_0x000000AC_VectorFunction,
		V44_0x000000B0_VectorFunction,
		V45_0x000000B4_VectorFunction,
		V46_0x000000B8_VectorFunction,
		V47_0x000000BC_VectorFunction,
		V48_0x000000C0_VectorFunction,
		V49_0x000000C4_VectorFunction,
		V50_0x000000C8_VectorFunction,
		V51_0x000000CC_VectorFunction,
		V52_0x000000D0_VectorFunction,
		V53_0x000000D4_VectorFunction,
		V54_0x000000D8_VectorFunction,
		V55_0x000000DC_VectorFunction,
		V56_0x000000E0_VectorFunction,
		V57_0x000000E4_VectorFunction,
		V58_0x000000E8_VectorFunction,
		V59_0x000000EC_VectorFunction,
		V60_0x000000F0_VectorFunction,
		V61_0x000000F4_VectorFunction,
		V62_0x000000F8_VectorFunction,
		V63_0x000000FC_VectorFunction,
		V64_0x00000100_VectorFunction,
		V65_0x00000104_VectorFunction,
		V66_0x00000108_VectorFunction,
		V67_0x0000010C_VectorFunction,
		V68_0x00000110_VectorFunction,
		V69_0x00000114_VectorFunction,
		V70_0x00000118_VectorFunction,
		V71_0x0000011C_VectorFunction,
		V72_0x00000120_VectorFunction,
		V73_0x00000124_VectorFunction,
		V74_0x00000128_VectorFunction,
		V75_0x0000012C_VectorFunction,
		V76_0x00000130_VectorFunction,
		V77_0x00000134_VectorFunction,
		V78_0x00000138_VectorFunction,
		V79_0x0000013C_VectorFunction,
		V80_0x00000140_VectorFunction,
		V81_0x00000144_VectorFunction,
		V82_0x00000148_VectorFunction,
		V83_0x0000014C_VectorFunction,
		V84_0x00000150_VectorFunction,
		V85_0x00000154_VectorFunction,
		V86_0x00000158_VectorFunction,
		V87_0x0000015C_VectorFunction,
		V88_0x00000160_VectorFunction,
		V89_0x00000164_VectorFunction,
		V90_0x00000168_VectorFunction,
		V91_0x0000016C_VectorFunction,
		V92_0x00000170_VectorFunction,
		V93_0x00000174_VectorFunction,
		V94_0x00000178_VectorFunction,
		V95_0x0000017C_VectorFunction,
		V96_0x00000180_VectorFunction,
		V97_0x00000184_VectorFunction,
		V98_0x00000188_VectorFunction,
		V99_0x0000018C_VectorFunction,
		V100_0x00000190_VectorFunction,
		V101_0x00000194_VectorFunction,
		V102_0x00000198_VectorFunction,
		V103_0x0000019C_VectorFunction,
		V104_0x000001A0_VectorFunction,
		V105_0x000001A4_VectorFunction,
		V106_0x000001A8_VectorFunction,
		V107_0x000001AC_VectorFunction,
		V108_0x000001B0_VectorFunction,
		V109_0x000001B4_VectorFunction,
		V110_0x000001B8_VectorFunction,
		V111_0x000001BC_VectorFunction,
		V112_0x000001C0_VectorFunction,
		V113_0x000001C4_VectorFunction,
		V114_0x000001C8_VectorFunction,
		V115_0x000001CC_VectorFunction,
		V116_0x000001D0_VectorFunction,
		V117_0x000001D4_VectorFunction,
		V118_0x000001D8_VectorFunction,
		V119_0x000001DC_VectorFunction,
		V120_0x000001E0_VectorFunction,
		V121_0x000001E4_VectorFunction,
		V122_0x000001E8_VectorFunction,
		V123_0x000001EC_VectorFunction,
		V124_0x000001F0_VectorFunction,
		V125_0x000001F4_VectorFunction,
		V126_0x000001F8_VectorFunction,
		V127_0x000001FC_VectorFunction
};

void __attribute__((interrupt,section(".rodata"))) _Default_NULL_exception (void);
void __attribute__((interrupt,section(".rodata"))) _Default_NULL_exception (void)
{
	while(1){};
}
