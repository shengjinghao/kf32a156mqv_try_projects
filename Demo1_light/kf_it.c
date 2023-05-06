/****************************************************************************************
 *
 * File Name: kf_it.c
 * Project Name: Demo1
 * Version: v1.0
 * Date: 2023-04-26- 15:27:29
 * Author: PC
 * 
 ****************************************************************************************/
//#include<KF32A156MQV.h>

//asm(".include		\"KF32A156MQV.inc\"	");	 

//Note:
//*****************************************************************************************
//                                 NMI Interrupt Course
//*****************************************************************************************	
void __attribute__((interrupt)) _NMI_exception (void);
void __attribute__((interrupt)) _NMI_exception (void)
{	

}

//*****************************************************************************************
//                               HardFault Interrupt Course
//*****************************************************************************************	
void __attribute__((interrupt)) _HardFault_exception (void);
void __attribute__((interrupt)) _HardFault_exception (void)
{

}

//*****************************************************************************************
//                               StackFault Interrupt Course
//*****************************************************************************************	
void __attribute__((interrupt)) _StackFault_exception (void);
void __attribute__((interrupt)) _StackFault_exception (void)
{

}

//*****************************************************************************************
//                               AriFault Interrupt Course
//*****************************************************************************************	
void __attribute__((interrupt)) _AriFault_exception (void);
void __attribute__((interrupt)) _AriFault_exception (void)
{

}

//*****************************************************************************************
//                               SVC Interrupt Course
//*****************************************************************************************	
void __attribute__((interrupt)) _SVC_exception (void);
void __attribute__((interrupt)) _SVC_exception (void)
{

}

//*****************************************************************************************
//                              SoftSV Interrupt Course
//*****************************************************************************************	
void __attribute__((interrupt)) _SoftSV_exception (void);
void __attribute__((interrupt)) _SoftSV_exception (void)
{

}

//*****************************************************************************************
//                              SysTick Interrupt Course
//*****************************************************************************************	
void __attribute__((interrupt)) _SysTick_exception (void);
void __attribute__((interrupt)) _SysTick_exception (void)
{
	
}

