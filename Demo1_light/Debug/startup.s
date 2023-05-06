	.file	"startup.c"
	.stabs	"D:\\\\KungFu32\\\\workspace32\\\\Demo1\\\\Debug/",100,0,2,.Ltext0
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
	SUB	sp,#12
	.stabn	68,0,31,.LM1-.LFBB1
.LM1:
	MOV	r5,#1
	LSL	r5,#30
	MOV	r4,#0
	ST.w	[r5],r4
	.stabn	68,0,33,.LM2-.LFBB1
.LM2:
	LD	r5,#__text_end__
	ST.w	[sp],r5
	.stabn	68,0,34,.LM3-.LFBB1
.LM3:
	LD	r5,#__data_start__
	ST.w	[sp+#1],r5
	.stabn	68,0,35,.LM4-.LFBB1
.LM4:
	LD	r5,#__data_end__
	ST.w	[sp+#2],r5
	.stabn	68,0,36,.LM5-.LFBB1
.LM5:
	JMP	.L2
.L3:
	.stabn	68,0,37,.LM6-.LFBB1
.LM6:
	LD.w	r5,[sp]
	LD.w	r5,[r5]
	LD.w	r4,[sp+#1]
	ST.w	[r4],r5
	.stabn	68,0,38,.LM7-.LFBB1
.LM7:
	LD.w	r5,[sp+#1]
	ADD	r5,r5,#4
	ST.w	[sp+#1],r5
	LD.w	r5,[sp]
	ADD	r5,r5,#4
	ST.w	[sp],r5
.L2:
	.stabn	68,0,36,.LM8-.LFBB1
.LM8:
	LD.w	r5,[sp+#1]
	LD.w	r4,[sp+#2]
	CMP	r4,r5
	JHI	.L3
	.stabn	68,0,52,.LM9-.LFBB1
.LM9:
	LD	r5,#__bss_start__
	ST.w	[sp+#1],r5
	.stabn	68,0,53,.LM10-.LFBB1
.LM10:
	LD	r5,#__bss_end__
	ST.w	[sp+#2],r5
	.stabn	68,0,54,.LM11-.LFBB1
.LM11:
	JMP	.L4
.L5:
	.stabn	68,0,55,.LM12-.LFBB1
.LM12:
	LD.w	r4,[sp+#1]
	MOV	r5,#0
	ST.w	[r4],r5
	LD.w	r5,[sp+#1]
	ADD	r5,r5,#4
	ST.w	[sp+#1],r5
.L4:
	.stabn	68,0,54,.LM13-.LFBB1
.LM13:
	LD.w	r5,[sp+#1]
	LD.w	r4,[sp+#2]
	CMP	r4,r5
	JHI	.L5
	.stabn	68,0,59,.LM14-.LFBB1
.LM14:
	LD	r5,#main
	LJMP	r5
	MOV	r5,r0
	.stabn	68,0,60,.LM15-.LFBB1
.LM15:
	MOV	r0,r5
	ADD	sp,#12
	POP	lr
	JMP	lr
	.size	startup, .-startup
	.stabs	"s:(0,16)=*(0,4)",128,0,23,0
	.stabs	"begin:(0,16)",128,0,24,4
	.stabs	"end:(0,16)",128,0,25,8
	.stabn	192,0,0,.LFBB1-.LFBB1
	.stabn	224,0,0,.Lscope1-.LFBB1
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.text
	.stabs	"",100,0,0,.Letext0
.Letext0:
