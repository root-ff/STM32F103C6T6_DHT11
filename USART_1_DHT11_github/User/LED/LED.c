#include "LED.h"
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef InitStruct;
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK,ENABLE);
	//配置引脚//
	InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	InitStruct.GPIO_Pin=LED_GPIO_Pin;
	InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO_Port, &InitStruct);
}



void LED_GPIO_High(void)   
{
		//输出高电平//
	GPIO_SetBits(LED_GPIO_Port, LED_GPIO_Pin);

}
void LED_GPIO_low(void)
{
		//输出低电平//
	GPIO_ResetBits(LED_GPIO_Port, LED_GPIO_Pin);
}
