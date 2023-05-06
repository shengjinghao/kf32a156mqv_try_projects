	.file	"kf_it.c"
	.stabs	"D:\\\\KungFu32\\\\workspace32\\\\Demo1\\\\Debug/",100,0,2,.Ltext0
	.stabs	"../kf_it.c",100,0,2,.Ltext0
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
	.section .text$_NMI_exception
	.type	.text$_NMI_exception$scode_local_1, @function
	.text$_NMI_exception$scode_loacal_1:
	.align	1
	.stabs	"_NMI_exception:F(0,15)",36,0,19,_NMI_exception
	.export	_NMI_exception
	.type	_NMI_exception, @function
_NMI_exception:
	.stabd	46,0,0
	.stabs	"../kf_it.c",132,0,0,.Ltext1
.Ltext1:
	.stabn	68,0,20,.LM0-.LFBB1
.LM0:
.LFBB1:
	.stabn	68,0,22,.LM1-.LFBB1
.LM1:
	CLR PSW,#29
	JMP	lr
	.size	_NMI_exception, .-_NMI_exception
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.section .text$_HardFault_exception
	.type	.text$_HardFault_exception$scode_local_2, @function
	.text$_HardFault_exception$scode_loacal_2:
	.align	1
	.stabs	"_HardFault_exception:F(0,15)",36,0,28,_HardFault_exception
	.export	_HardFault_exception
	.type	_HardFault_exception, @function
_HardFault_exception:
	.stabd	46,0,0
	.stabs	"../kf_it.c",132,0,0,.Ltext2
.Ltext2:
	.stabn	68,0,29,.LM2-.LFBB2
.LM2:
.LFBB2:
	.stabn	68,0,31,.LM3-.LFBB2
.LM3:
	CLR PSW,#29
	JMP	lr
	.size	_HardFault_exception, .-_HardFault_exception
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
	.section .text$_StackFault_exception
	.type	.text$_StackFault_exception$scode_local_3, @function
	.text$_StackFault_exception$scode_loacal_3:
	.align	1
	.stabs	"_StackFault_exception:F(0,15)",36,0,37,_StackFault_exception
	.export	_StackFault_exception
	.type	_StackFault_exception, @function
_StackFault_exception:
	.stabd	46,0,0
	.stabs	"../kf_it.c",132,0,0,.Ltext3
.Ltext3:
	.stabn	68,0,38,.LM4-.LFBB3
.LM4:
.LFBB3:
	.stabn	68,0,40,.LM5-.LFBB3
.LM5:
	CLR PSW,#29
	JMP	lr
	.size	_StackFault_exception, .-_StackFault_exception
.Lscope3:
	.stabs	"",36,0,0,.Lscope3-.LFBB3
	.stabd	78,0,0
	.section .text$_AriFault_exception
	.type	.text$_AriFault_exception$scode_local_4, @function
	.text$_AriFault_exception$scode_loacal_4:
	.align	1
	.stabs	"_AriFault_exception:F(0,15)",36,0,46,_AriFault_exception
	.export	_AriFault_exception
	.type	_AriFault_exception, @function
_AriFault_exception:
	.stabd	46,0,0
	.stabs	"../kf_it.c",132,0,0,.Ltext4
.Ltext4:
	.stabn	68,0,47,.LM6-.LFBB4
.LM6:
.LFBB4:
	.stabn	68,0,49,.LM7-.LFBB4
.LM7:
	CLR PSW,#29
	JMP	lr
	.size	_AriFault_exception, .-_AriFault_exception
.Lscope4:
	.stabs	"",36,0,0,.Lscope4-.LFBB4
	.stabd	78,0,0
	.section .text$_SVC_exception
	.type	.text$_SVC_exception$scode_local_5, @function
	.text$_SVC_exception$scode_loacal_5:
	.align	1
	.stabs	"_SVC_exception:F(0,15)",36,0,55,_SVC_exception
	.export	_SVC_exception
	.type	_SVC_exception, @function
_SVC_exception:
	.stabd	46,0,0
	.stabs	"../kf_it.c",132,0,0,.Ltext5
.Ltext5:
	.stabn	68,0,56,.LM8-.LFBB5
.LM8:
.LFBB5:
	.stabn	68,0,58,.LM9-.LFBB5
.LM9:
	CLR PSW,#29
	JMP	lr
	.size	_SVC_exception, .-_SVC_exception
.Lscope5:
	.stabs	"",36,0,0,.Lscope5-.LFBB5
	.stabd	78,0,0
	.section .text$_SoftSV_exception
	.type	.text$_SoftSV_exception$scode_local_6, @function
	.text$_SoftSV_exception$scode_loacal_6:
	.align	1
	.stabs	"_SoftSV_exception:F(0,15)",36,0,64,_SoftSV_exception
	.export	_SoftSV_exception
	.type	_SoftSV_exception, @function
_SoftSV_exception:
	.stabd	46,0,0
	.stabs	"../kf_it.c",132,0,0,.Ltext6
.Ltext6:
	.stabn	68,0,65,.LM10-.LFBB6
.LM10:
.LFBB6:
	.stabn	68,0,67,.LM11-.LFBB6
.LM11:
	CLR PSW,#29
	JMP	lr
	.size	_SoftSV_exception, .-_SoftSV_exception
.Lscope6:
	.stabs	"",36,0,0,.Lscope6-.LFBB6
	.stabd	78,0,0
	.section .text$_SysTick_exception
	.type	.text$_SysTick_exception$scode_local_7, @function
	.text$_SysTick_exception$scode_loacal_7:
	.align	1
	.stabs	"_SysTick_exception:F(0,15)",36,0,73,_SysTick_exception
	.export	_SysTick_exception
	.type	_SysTick_exception, @function
_SysTick_exception:
	.stabd	46,0,0
	.stabs	"../kf_it.c",132,0,0,.Ltext7
.Ltext7:
	.stabn	68,0,74,.LM12-.LFBB7
.LM12:
.LFBB7:
	.stabn	68,0,76,.LM13-.LFBB7
.LM13:
	CLR PSW,#29
	JMP	lr
	.size	_SysTick_exception, .-_SysTick_exception
.Lscope7:
	.stabs	"",36,0,0,.Lscope7-.LFBB7
	.stabd	78,0,0
	.text
	.stabs	"",100,0,0,.Letext0
.Letext0:
