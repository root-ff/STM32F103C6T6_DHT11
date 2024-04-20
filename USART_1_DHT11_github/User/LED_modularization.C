#include "sys.h"
u16 LEDnum=0;
static u8 i=0;
extern u8 flag;

void LED_Init_Confit_MD(void)
{
	GPIO_InitTypeDef InitStruct;
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK,ENABLE);
	//配置引脚//
	InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	InitStruct.GPIO_Pin=LED_GPIO_Pin;
	InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO_Port, &InitStruct);
}

void LED_GPIO_High_MD(void)   
{
		//输出高电平//
	GPIO_SetBits(LED_GPIO_Port, LED_GPIO_Pin);//BSRR

}
void LED_GPIO_low_MD(void)
{
		//输出低电平//
	GPIO_ResetBits(LED_GPIO_Port, LED_GPIO_Pin);//BRR
}
//中断法使用的函数
void LED_RUN()
{

		switch(i)
	{
		
		case 0:
			if(LEDnum==0)
			{
				LED_GPIO_low_MD();i++;
				LEDnum=1000;break;
			}
		case 1:
			if(LEDnum==0)
			{
			LED_GPIO_High_MD();i=0;
				LEDnum=1000;break;	
			}
	}
			
}
void LED_CHANGE()
{
	static u8 j=0;
	if(flag==1)
	{
		flag=0;
		switch(j)
		{
			case 0:PCout(13)=1;j++;break;
			case 1:PCout(13)=0;j=0;break;
		}
	}
	
}
