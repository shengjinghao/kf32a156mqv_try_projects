/****************************************************************************************
 *
 * File Name: main 
 * Project Name: Demo1
 * Version: v1.0
 * Date: 2023-04-26- 15:27:29
 * Author: PC
 * 
 ****************************************************************************************/
//#include<KF32A156MQV.h>
#include "system_init.h"
//asm(".include		\"KF32A156MQV.inc\"	");	 
static volatile uint32_t TimingDelay;
void BoardGpioInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Configure PD12 LED1 output */
	GPIO_InitStructure.m_Mode = GPIO_MODE_OUT;
	GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	GPIO_InitStructure.m_Speed = GPIO_LOW_SPEED;
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_12;
	GPIO_Configuration(GPIOD_SFR , &GPIO_InitStructure);

	//��PD12���Ϊ�ߵ�ƽ  ǰ����PD12�Ѿ�����Ϊ�����
	GPIO_Set_Output_Data_Bits(GPIOD_SFR, GPIO_PIN_MASK_12, Bit_SET);

//	//������PD12Ϊ�����Ϊ��
//	GPIO_Write_Mode_Bits (GPIOD_SFR,GPIO_PIN_MASK_12,GPIO_MODE_IN);
//	//������PD12Ϊ�����Ϊ��
//	GPIO_Write_Mode_Bits (GPIOD_SFR,GPIO_PIN_MASK_12,GPIO_MODE_OUT);
//	//������PD12Ϊģ���Ϊ��
//	GPIO_Write_Mode_Bits (GPIOD_SFR,GPIO_PIN_MASK_12,GPIO_MODE_AN);
//	//������PD12Ϊ��ӳ���Ϊ��
//	GPIO_Write_Mode_Bits (GPIOD_SFR,GPIO_PIN_MASK_12,GPIO_MODE_RMP);
//	//��PD12��ӳ�䵽AF3ͨ����Ҳ����USART2_TX1
//	GPIO_Pin_RMP_Config(GPIOD_SFR, GPIO_Pin_Num_12, GPIO_RMP_AF3);
//	//�Ի�ȡPD12���ŵ�ƽ״̬Ϊ��
//	GPIO_Read_Input_Data_Bit (GPIOD_SFR, GPIO_Pin_Num_12);
//	//��PD12���Ϊ�ߵ�ƽ  ǰ����PD12�Ѿ�����Ϊ�����
//	GPIO_Set_Output_Data_Bits (GPIOD_SFR,GPIO_PIN_MASK_12, Bit_SET);
//	//��PD12���Ϊ�͵�ƽ  ǰ����PD12�Ѿ�����Ϊ�����
//	GPIO_Set_Output_Data_Bits (GPIOD_SFR,GPIO_PIN_MASK_12, Bit_RESET);
//	//��PD12�����ƽȡ��  ǰ����PD12�Ѿ�����Ϊ�����
//	 GPIO_Toggle_Output_Data_Config (GPIOD_SFR,GPIO_PIN_MASK_12);
}

void BoardUserKeyInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EINT_InitTypeDef EINT_InitStructure;

	/* Configure the external interrupt */
	EINT_InitStructure.m_Fall = TRUE;
	EINT_InitStructure.m_Line = INT_EXTERNAL_INTERRUPT_0;
	EINT_InitStructure.m_Mask = TRUE;
	EINT_InitStructure.m_Rise = TRUE;
	EINT_InitStructure.m_Source = INT_EXTERNAL_SOURCE_PC;
	INT_External_Configuration(&EINT_InitStructure);
}

//Main Function
int main()
{
	/*initialize system clock *********/
	/* Initialize the system clock is 120M*/
	SystemInit(120);
	/* Setup SysTick Timer as delay function, and input frequency is 120M */
	systick_delay_init(120);
	/* Initialize the LED IOs */
	BoardGpioInit();
	/* Configure PC0 in interrupt mode */
	BoardUserKeyInit();
	 /* Enable and set EXTI0 Interrupt to the lowest priority */
	INT_Interrupt_Enable(INT_EINT0, TRUE);
	INT_Interrupt_Priority_Config(INT_EINT0, 7, 1);
	/* Configure interrupt priority group, default is 3VS1 */
	INT_Priority_Group_Config(INT_PRIORITY_GROUP_3VS1);
	/* Enable the global interrupt */
	INT_All_Enable(TRUE);

	while(1)
	{
//		GPIO_Set_Output_Data_Bits(GPIOD_SFR, GPIO_PIN_MASK_12, Bit_SET);
//		systick_delay_ms(500);
//		GPIO_Set_Output_Data_Bits(GPIOD_SFR, GPIO_PIN_MASK_12, Bit_RESET);
//		systick_delay_ms(500);

//		/* Toggle LED1 */
		/* Turn ON/OFF the LED1 every 500ms */
		if (++TimingDelay >= 10)
		{
			TimingDelay = 0;
			GPIO_Toggle_Output_Data_Config(GPIOD_SFR, GPIO_PIN_MASK_12);
		}
		systick_delay_ms(50);
//		read(&buf) if ((buf[0] == 0x12) && ...())
//		{
//			uart_send_data(BUF, 10);
//		}
	}
}





void check_failed(uint8_t* File, uint32_t Line)
{
	/* User can add his own implementation to report the file name and line number,
		ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	 if ((File == NULL) || (Line == 0))
	 {
//	 	printf("Wrong parameters value: file %s on line %d\r\n", File, Line);
	 }
	/* Infinite loop */
	while(1)
	{
		;
	}
};
