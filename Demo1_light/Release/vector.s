	.file	"vector.c"
	.stabs	"D:\\\\KungFu32\\\\workspace32\\\\Demo1_light\\\\Release/",100,0,2,.Ltext0
	.stabs	"../_config/vector.c",100,0,2,.Ltext0
	.text
.Ltext0:
	.stabs	"gcc2_compiled.",60,0,0,0
	.stabs	"int:t(0,1)=r(0,1);-2147483648;2147483647;",128,0,0,0
	.stabs	"char:t(0,2)=@s8;r(0,2);0;255;",128,0,0,0
	.stabs	"long int:t(0,3)=r(0,3);-2147483648;2147483647;",128,0,0,0
	.stabs	"unsigned int:t(0,4)=r(0,4);0;037777777777;",128,0,0,0
	.stabs	"long unsigned int:t(0,5)=r(0,5);0;037777777777;",128,0,0,0
	.stabs	"long long int:t(0,6)=@s64;r(0,6);01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"long long unsigned int:t(0,7)=@s64;r(0,7);0;01777777777777777777777;",128,0,0,0
	.stabs	"short int:t(0,8)=@s16;r(0,8);-32768;32767;",128,0,0,0
	.stabs	"short unsigned int:t(0,9)=@s16;r(0,9);0;65535;",128,0,0,0
	.stabs	"signed char:t(0,10)=@s8;r(0,10);-128;127;",128,0,0,0
	.stabs	"unsigned char:t(0,11)=@s8;r(0,11);0;255;",128,0,0,0
	.stabs	"float:t(0,12)=r(0,1);4;0;",128,0,0,0
	.stabs	"double:t(0,13)=r(0,1);8;0;",128,0,0,0
	.stabs	"long double:t(0,14)=r(0,1);8;0;",128,0,0,0
	.stabs	"void:t(0,15)=(0,15)",128,0,0,0
	.stabs	"interruptVector:t(0,16)=(0,17)=s4Func:(0,18)=*(0,19)=f(0,15),0,32;;",128,0,159,0
	.stabs	"VectorEnter:t(0,20)=(0,21)=s512value:(0,22)=*(0,1),0,32;Reset_Enter:(0,16),32,32;NMI_Enter:(0,16),64,32;HardFault_Enter:(0,16),96,32;Rev4_Enter:(0,16),128,32;StackFault_Enter:(0,16),160,32;AriFault_Enter:(0,16),192,32;Intended_Rev:(0,16),224,32;interrupt:(0,23)=ar(0,24)=r(0,24);0;037777777777;;0;119;(0,16),256,3840;;",128,0,174,0
	.section .rodata$_Default_NULL_exception
	.type	.rodata$_Default_NULL_exception$scode_local_1, @function
	.rodata$_Default_NULL_exception$scode_loacal_1:
	.align	1
	.stabs	"_Default_NULL_exception:F(0,15)",36,0,440,_Default_NULL_exception
	.export	_Default_NULL_exception
	.type	_Default_NULL_exception, @function
_Default_NULL_exception:
	.stabd	46,0,0
	.stabs	"../_config/vector.c",132,0,0,.Ltext1
.Ltext1:
	.stabn	68,0,441,.LM0-.LFBB1
.LM0:
.LFBB1:
.L2:
	JMP	.L2
	.size	_Default_NULL_exception, .-_Default_NULL_exception
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.weak	_HardFault_exception
	.set	_HardFault_exception,_Default_NULL_exception
	.weak	_Soft4_exception
	.set	_Soft4_exception,_Default_NULL_exception
	.weak	_StackFault_exception
	.set	_StackFault_exception,_Default_NULL_exception
	.weak	_AriFault_exception
	.set	_AriFault_exception,_Default_NULL_exception
	.weak	_Soft8_exception
	.set	_Soft8_exception,_Default_NULL_exception
	.weak	_Soft9_exception
	.set	_Soft9_exception,_Default_NULL_exception
	.weak	_Soft10_exception
	.set	_Soft10_exception,_Default_NULL_exception
	.weak	_SVC_exception
	.set	_SVC_exception,_Default_NULL_exception
	.weak	_Soft12_exception
	.set	_Soft12_exception,_Default_NULL_exception
	.weak	_Soft13_exception
	.set	_Soft13_exception,_Default_NULL_exception
	.weak	_SoftSV_exception
	.set	_SoftSV_exception,_Default_NULL_exception
	.weak	_SysTick_exception
	.set	_SysTick_exception,_Default_NULL_exception
	.weak	_WWDT_exception
	.set	_WWDT_exception,_Default_NULL_exception
	.weak	_EINT16_exception
	.set	_EINT16_exception,_Default_NULL_exception
	.weak	_EINT0_exception
	.set	_EINT0_exception,_Default_NULL_exception
	.weak	_EINT1_exception
	.set	_EINT1_exception,_Default_NULL_exception
	.weak	_EINT2_exception
	.set	_EINT2_exception,_Default_NULL_exception
	.weak	_EINT3_exception
	.set	_EINT3_exception,_Default_NULL_exception
	.weak	_EINT4_exception
	.set	_EINT4_exception,_Default_NULL_exception
	.weak	_EINT9TO5_exception
	.set	_EINT9TO5_exception,_Default_NULL_exception
	.weak	_EINT15TO10_exception
	.set	_EINT15TO10_exception,_Default_NULL_exception
	.weak	_T1_exception
	.set	_T1_exception,_Default_NULL_exception
	.weak	_T3_exception
	.set	_T3_exception,_Default_NULL_exception
	.weak	_T5_exception
	.set	_T5_exception,_Default_NULL_exception
	.weak	_T6_exception
	.set	_T6_exception,_Default_NULL_exception
	.weak	_T7_QEI0_exception
	.set	_T7_QEI0_exception,_Default_NULL_exception
	.weak	_T8_QEI1_exception
	.set	_T8_QEI1_exception,_Default_NULL_exception
	.weak	_ECFGL_exception
	.set	_ECFGL_exception,_Default_NULL_exception
	.weak	_CAN4_exception
	.set	_CAN4_exception,_Default_NULL_exception
	.weak	_T14_exception
	.set	_T14_exception,_Default_NULL_exception
	.weak	_RNG_exception
	.set	_RNG_exception,_Default_NULL_exception
	.weak	_FDC2_exception
	.set	_FDC2_exception,_Default_NULL_exception
	.weak	_EXIC_exception
	.set	_EXIC_exception,_Default_NULL_exception
	.weak	_ADC0_exception
	.set	_ADC0_exception,_Default_NULL_exception
	.weak	_ADC1_exception
	.set	_ADC1_exception,_Default_NULL_exception
	.weak	_CFGL_exception
	.set	_CFGL_exception,_Default_NULL_exception
	.weak	_T11_exception
	.set	_T11_exception,_Default_NULL_exception
	.weak	_T0_exception
	.set	_T0_exception,_Default_NULL_exception
	.weak	_DMA0_exception
	.set	_DMA0_exception,_Default_NULL_exception
	.weak	_CMP_exception
	.set	_CMP_exception,_Default_NULL_exception
	.weak	_USART0_exception
	.set	_USART0_exception,_Default_NULL_exception
	.weak	_USART1_exception
	.set	_USART1_exception,_Default_NULL_exception
	.weak	_SPI0_exception
	.set	_SPI0_exception,_Default_NULL_exception
	.weak	_SPI1_exception
	.set	_SPI1_exception,_Default_NULL_exception
	.weak	_DMA1_exception
	.set	_DMA1_exception,_Default_NULL_exception
	.weak	_EINT19TO17_exception
	.set	_EINT19TO17_exception,_Default_NULL_exception
	.weak	_CANFD6_exception
	.set	_CANFD6_exception,_Default_NULL_exception
	.weak	_CANFD7_exception
	.set	_CANFD7_exception,_Default_NULL_exception
	.weak	_FDC0_exception
	.set	_FDC0_exception,_Default_NULL_exception
	.weak	_FDC1_exception
	.set	_FDC1_exception,_Default_NULL_exception
	.weak	_EINT31TO20_exception
	.set	_EINT31TO20_exception,_Default_NULL_exception
	.weak	_ECC_exception
	.set	_ECC_exception,_Default_NULL_exception
	.weak	_OSC_CLK_exception
	.set	_OSC_CLK_exception,_Default_NULL_exception
	.weak	_I2C0_exception
	.set	_I2C0_exception,_Default_NULL_exception
	.weak	_I2C1_exception
	.set	_I2C1_exception,_Default_NULL_exception
	.weak	_I2C2_exception
	.set	_I2C2_exception,_Default_NULL_exception
	.weak	_T12_exception
	.set	_T12_exception,_Default_NULL_exception
	.weak	_T2_exception
	.set	_T2_exception,_Default_NULL_exception
	.weak	_T4_exception
	.set	_T4_exception,_Default_NULL_exception
	.weak	_T13_exception
	.set	_T13_exception,_Default_NULL_exception
	.weak	_USART2_exception
	.set	_USART2_exception,_Default_NULL_exception
	.weak	_T16_exception
	.set	_T16_exception,_Default_NULL_exception
	.weak	_USART4_exception
	.set	_USART4_exception,_Default_NULL_exception
	.weak	_SPI2_exception
	.set	_SPI2_exception,_Default_NULL_exception
	.weak	_SPI3_exception
	.set	_SPI3_exception,_Default_NULL_exception
	.weak	_ADC2_exception
	.set	_ADC2_exception,_Default_NULL_exception
	.weak	_T18_exception
	.set	_T18_exception,_Default_NULL_exception
	.weak	_T19_exception
	.set	_T19_exception,_Default_NULL_exception
	.weak	_HRCAP0_exception
	.set	_HRCAP0_exception,_Default_NULL_exception
	.weak	_WKP4TO0_exception
	.set	_WKP4TO0_exception,_Default_NULL_exception
	.weak	_HRCAP1_exception
	.set	_HRCAP1_exception,_Default_NULL_exception
	.weak	_T21_exception
	.set	_T21_exception,_Default_NULL_exception
	.weak	_I2C3_exception
	.set	_I2C3_exception,_Default_NULL_exception
	.weak	_USART5_exception
	.set	_USART5_exception,_Default_NULL_exception
	.weak	_HRCAP2_exception
	.set	_HRCAP2_exception,_Default_NULL_exception
	.weak	_USART7_exception
	.set	_USART7_exception,_Default_NULL_exception
	.weak	_Soft80_exception
	.set	_Soft80_exception,_Default_NULL_exception
	.weak	_Soft81_exception
	.set	_Soft81_exception,_Default_NULL_exception
	.weak	_Soft82_exception
	.set	_Soft82_exception,_Default_NULL_exception
	.weak	_Soft83_exception
	.set	_Soft83_exception,_Default_NULL_exception
	.weak	_Soft84_exception
	.set	_Soft84_exception,_Default_NULL_exception
	.weak	_Soft85_exception
	.set	_Soft85_exception,_Default_NULL_exception
	.weak	_Soft86_exception
	.set	_Soft86_exception,_Default_NULL_exception
	.weak	_Soft87_exception
	.set	_Soft87_exception,_Default_NULL_exception
	.weak	_Soft88_exception
	.set	_Soft88_exception,_Default_NULL_exception
	.weak	_Soft89_exception
	.set	_Soft89_exception,_Default_NULL_exception
	.weak	_Soft90_exception
	.set	_Soft90_exception,_Default_NULL_exception
	.weak	_Soft91_exception
	.set	_Soft91_exception,_Default_NULL_exception
	.weak	_Soft92_exception
	.set	_Soft92_exception,_Default_NULL_exception
	.weak	_Soft93_exception
	.set	_Soft93_exception,_Default_NULL_exception
	.weak	_Soft94_exception
	.set	_Soft94_exception,_Default_NULL_exception
	.weak	_Soft95_exception
	.set	_Soft95_exception,_Default_NULL_exception
	.weak	_Soft96_exception
	.set	_Soft96_exception,_Default_NULL_exception
	.weak	_Soft97_exception
	.set	_Soft97_exception,_Default_NULL_exception
	.weak	_Soft98_exception
	.set	_Soft98_exception,_Default_NULL_exception
	.weak	_Soft99_exception
	.set	_Soft99_exception,_Default_NULL_exception
	.weak	_Soft100_exception
	.set	_Soft100_exception,_Default_NULL_exception
	.weak	_Soft101_exception
	.set	_Soft101_exception,_Default_NULL_exception
	.weak	_Soft102_exception
	.set	_Soft102_exception,_Default_NULL_exception
	.weak	_Soft103_exception
	.set	_Soft103_exception,_Default_NULL_exception
	.weak	_Soft104_exception
	.set	_Soft104_exception,_Default_NULL_exception
	.weak	_Soft105_exception
	.set	_Soft105_exception,_Default_NULL_exception
	.weak	_Soft106_exception
	.set	_Soft106_exception,_Default_NULL_exception
	.weak	_Soft107_exception
	.set	_Soft107_exception,_Default_NULL_exception
	.weak	_Soft108_exception
	.set	_Soft108_exception,_Default_NULL_exception
	.weak	_Soft109_exception
	.set	_Soft109_exception,_Default_NULL_exception
	.weak	_Soft110_exception
	.set	_Soft110_exception,_Default_NULL_exception
	.weak	_Soft111_exception
	.set	_Soft111_exception,_Default_NULL_exception
	.weak	_Soft112_exception
	.set	_Soft112_exception,_Default_NULL_exception
	.weak	_Soft113_exception
	.set	_Soft113_exception,_Default_NULL_exception
	.weak	_Soft114_exception
	.set	_Soft114_exception,_Default_NULL_exception
	.weak	_Soft115_exception
	.set	_Soft115_exception,_Default_NULL_exception
	.weak	_Soft116_exception
	.set	_Soft116_exception,_Default_NULL_exception
	.weak	_Soft117_exception
	.set	_Soft117_exception,_Default_NULL_exception
	.weak	_Soft118_exception
	.set	_Soft118_exception,_Default_NULL_exception
	.weak	_Soft119_exception
	.set	_Soft119_exception,_Default_NULL_exception
	.weak	_Soft120_exception
	.set	_Soft120_exception,_Default_NULL_exception
	.weak	_Soft121_exception
	.set	_Soft121_exception,_Default_NULL_exception
	.weak	_Soft122_exception
	.set	_Soft122_exception,_Default_NULL_exception
	.weak	_Soft123_exception
	.set	_Soft123_exception,_Default_NULL_exception
	.weak	_Soft124_exception
	.set	_Soft124_exception,_Default_NULL_exception
	.weak	_Soft125_exception
	.set	_Soft125_exception,_Default_NULL_exception
	.weak	_Soft126_exception
	.set	_Soft126_exception,_Default_NULL_exception
	.weak	_Soft127_exception
	.set	_Soft127_exception,_Default_NULL_exception
	.weak	_NMI_exception
	.set	_NMI_exception,_Default_NULL_exception
	.export	_start
	.section .text$_start
	.type	.text$_start$scode_local_2, @function
	.text$_start$scode_loacal_2:
	.align	2
	.type	_start, @object
	.size	_start, 512
_start:
	.long	__initial_sp
	.long	startup
	.long	_NMI_exception
	.long	_HardFault_exception
	.long	_Soft4_exception
	.long	_StackFault_exception
	.long	_AriFault_exception
	.long	0
	.long	_Soft8_exception
	.long	_Soft9_exception
	.long	_Soft10_exception
	.long	_SVC_exception
	.long	_Soft12_exception
	.long	_Soft13_exception
	.long	_SoftSV_exception
	.long	_SysTick_exception
	.long	_WWDT_exception
	.long	_EINT16_exception
	.long	_EINT0_exception
	.long	_EINT1_exception
	.long	_EINT2_exception
	.long	_EINT3_exception
	.long	_EINT4_exception
	.long	_EINT9TO5_exception
	.long	_EINT15TO10_exception
	.long	_T1_exception
	.long	_T3_exception
	.long	_T5_exception
	.long	_T6_exception
	.long	_T7_QEI0_exception
	.long	_T8_QEI1_exception
	.long	_ECFGL_exception
	.long	_CAN4_exception
	.long	_T14_exception
	.long	_RNG_exception
	.long	_FDC2_exception
	.long	_EXIC_exception
	.long	_ADC0_exception
	.long	_ADC1_exception
	.long	_CFGL_exception
	.long	_T11_exception
	.long	_T0_exception
	.long	_DMA0_exception
	.long	_CMP_exception
	.long	_USART0_exception
	.long	_USART1_exception
	.long	_SPI0_exception
	.long	_SPI1_exception
	.long	_DMA1_exception
	.long	_EINT19TO17_exception
	.long	_CANFD6_exception
	.long	_CANFD7_exception
	.long	_FDC0_exception
	.long	_FDC1_exception
	.long	_EINT31TO20_exception
	.long	_ECC_exception
	.long	_OSC_CLK_exception
	.long	_I2C0_exception
	.long	_I2C1_exception
	.long	_I2C2_exception
	.long	_T12_exception
	.long	_T2_exception
	.long	_T4_exception
	.long	_T13_exception
	.long	_USART2_exception
	.long	_T16_exception
	.long	_USART4_exception
	.long	_SPI2_exception
	.long	_SPI3_exception
	.long	_ADC2_exception
	.long	_T18_exception
	.long	_T19_exception
	.long	_HRCAP0_exception
	.long	_WKP4TO0_exception
	.long	_HRCAP1_exception
	.long	_T21_exception
	.long	_I2C3_exception
	.long	_USART5_exception
	.long	_HRCAP2_exception
	.long	_USART7_exception
	.long	_Soft80_exception
	.long	_Soft81_exception
	.long	_Soft82_exception
	.long	_Soft83_exception
	.long	_Soft84_exception
	.long	_Soft85_exception
	.long	_Soft86_exception
	.long	_Soft87_exception
	.long	_Soft88_exception
	.long	_Soft89_exception
	.long	_Soft90_exception
	.long	_Soft91_exception
	.long	_Soft92_exception
	.long	_Soft93_exception
	.long	_Soft94_exception
	.long	_Soft95_exception
	.long	_Soft96_exception
	.long	_Soft97_exception
	.long	_Soft98_exception
	.long	_Soft99_exception
	.long	_Soft100_exception
	.long	_Soft101_exception
	.long	_Soft102_exception
	.long	_Soft103_exception
	.long	_Soft104_exception
	.long	_Soft105_exception
	.long	_Soft106_exception
	.long	_Soft107_exception
	.long	_Soft108_exception
	.long	_Soft109_exception
	.long	_Soft110_exception
	.long	_Soft111_exception
	.long	_Soft112_exception
	.long	_Soft113_exception
	.long	_Soft114_exception
	.long	_Soft115_exception
	.long	_Soft116_exception
	.long	_Soft117_exception
	.long	_Soft118_exception
	.long	_Soft119_exception
	.long	_Soft120_exception
	.long	_Soft121_exception
	.long	_Soft122_exception
	.long	_Soft123_exception
	.long	_Soft124_exception
	.long	_Soft125_exception
	.long	_Soft126_exception
	.long	_Soft127_exception
	.export	Stack_Mem
	.section .stack_mem$Stack_Mem
	.type	.stack_mem$Stack_Mem$scode_local_3, @function
	.stack_mem$Stack_Mem$scode_loacal_3:
	.align	2
	.type	Stack_Mem, @object
	.size	Stack_Mem, 512
Stack_Mem:
	.fill 512, 1
	.stabs	"Stack_Mem:G(0,25)=ar(0,24);0;511;(0,11)",32,0,13,0
	.stabs	"_start:G(0,26)=k(0,20)",32,0,307,0
	.text
	.stabs	"",100,0,0,.Letext0
.Letext0:
