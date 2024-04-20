#include "LED.h"
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef InitStruct;
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK,ENABLE);
	//��������//
	InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	InitStruct.GPIO_Pin=LED_GPIO_Pin;
	InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO_Port, &InitStruct);
}



void LED_GPIO_High(void)   
{
		//����ߵ�ƽ//
	GPIO_SetBits(LED_GPIO_Port, LED_GPIO_Pin);

}
void LED_GPIO_low(void)
{
		//����͵�ƽ//
	GPIO_ResetBits(LED_GPIO_Port, LED_GPIO_Pin);
}
