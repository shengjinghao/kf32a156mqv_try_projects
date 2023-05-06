	.file	"startup.c"
	.stabs	"D:\\\\KungFu32\\\\workspace32\\\\Demo1_light\\\\Release/",100,0,2,.Ltext0
	.stabs	"../_config/startup.c",100,0,2,.Ltext0
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
	.section .text$startup
	.type	.text$startup$scode_local_1, @function
	.text$startup$scode_loacal_1:
	.align	2
	.stabs	"startup:F(0,1)",36,0,21,startup
	.export	startup
	.type	startup, @function
startup:
	.stabd	46,0,0
	.stabs	"../_config/startup.c",132,0,0,.Ltext1
.Ltext1:
	.stabn	68,0,22,.LM0-.LFBB1
.LM0:
.LFBB1:
	PUSH	lr
	.stabn	68,0,31,.LM1-.LFBB1
.LM1:
	MOV	r4,#0
	MOV	r5,#1
	LSL	r5,#30
	ST.w	[r5],r4
	.stabn	68,0,36,.LM2-.LFBB1
.LM2:
	LD	r5,#__data_start__
	LD	r4,#__data_end__
	CMP	r4,r5
	JLS	.L6
	LD	r4,#__text_end__
	.stabn	68,0,21,.LM3-.LFBB1
.LM3:
	LD	r3,#__data_start__+4
	LD	r2,#__data_end__+3
	SUB	r2,r2,r3
	LSR	r2,#2
	ADD	r2,r2,#1
	LSL	r2,#2
	ADD	r2,r2,r5
.L5:
	.stabn	68,0,37,.LM4-.LFBB1
.LM4:
	LD.w	r3,[r4++]
	ST.w	[r5++],r3
	.stabn	68,0,36,.LM5-.LFBB1
.LM5:
	CMP	r5,r2
	JNZ	.L5
.L6:
	.stabn	68,0,54,.LM6-.LFBB1
.LM6:
	LD	r5,#__bss_start__
	LD	r4,#__bss_end__
	CMP	r4,r5
	JLS	.L4
	.stabn	68,0,21,.LM7-.LFBB1
.LM7:
	LD	r4,#__bss_start__+4
	LD	r3,#__bss_end__+3
	SUB	r3,r3,r4
	LSR	r3,#2
	ADD	r3,r3,#1
	LSL	r3,#2
	ADD	r3,r3,r5
	.stabn	68,0,55,.LM8-.LFBB1
.LM8:
	MOV	r4,#0
.L7:
	ST.w	[r5++],r4
	.stabn	68,0,54,.LM9-.LFBB1
.LM9:
	CMP	r5,r3
	JNZ	.L7
.L4:
	.stabn	68,0,59,.LM10-.LFBB1
.LM10:
	LD	r0,#main
	LJMP	r0
	.stabn	68,0,60,.LM11-.LFBB1
.LM11:
	POP	lr
	JMP	lr
	.size	startup, .-startup
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.text
	.stabs	"",100,0,0,.Letext0
.Letext0:
