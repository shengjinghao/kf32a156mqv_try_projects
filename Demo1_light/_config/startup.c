
#ifndef HWREG
#define HWREG(x) (*((volatile unsigned int *)(x)))
#endif
//#################     auto value variable from tool 	 #############//
extern unsigned int __text_end__;
extern unsigned int __bss_start__;
extern unsigned int __bss_end__;
extern unsigned int __data_start__;
extern unsigned int __data_end__;

//#define Project_Type__cplusplus
#ifdef  Project_Type__cplusplus
extern unsigned int __init_class_start;
extern unsigned int __init_class_end;
#endif
//####################################################################//
int main(void);
int startup(void);
//####################################################################//
int startup(void)
{
	unsigned int *s;
	unsigned int *begin;
	unsigned int *end;
#ifdef  Project_Type__cplusplus
	void (*pf)(void);
#endif
//############# 		init work for the chip 		    #############//
//	HWREG(0x40000000)=1;
	HWREG(0x40000000)=0;	// cppcheck-suppress misra-c2012-11.4
//############# init variable who have initialization	#############//
	s = (unsigned int*)&__text_end__;		
	begin = (unsigned int*)&__data_start__;
	end = (unsigned int*)&__data_end__;
	while( begin <  end) {	// cppcheck-suppress comparePointers
		*begin = *s;
		begin++;s++;
	}
//############# init class who have initialization(C++)	#############//
#ifdef Project_Type__cplusplus
	begin = (unsigned int*)&__init_class_start;
	end = (unsigned int*)&__init_class_end;
	while( begin < end )	// cppcheck-suppress comparePointers
	{
		pf=(void *)(*begin);
		pf();begin++;
	}
#endif		
//############# init variable who have no initialization	#############//
#if 1	 //  0 not init this type variable
	begin = (unsigned int*)&__bss_start__;
	end = (unsigned int*)&__bss_end__;
	while( begin < end ){	// cppcheck-suppress comparePointers
		*begin = 0;begin++;
	}
#endif		
//############# begin to run main function	#############//		
	return main();
}
//####################################################################//