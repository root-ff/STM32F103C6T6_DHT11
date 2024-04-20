// 点亮LED灯练习//
#include "sys.h"

//定时器3 中断LED灯状态 
 int main(void)
{
	LED_Init_Confit_MD();
	TIM3_Init(9999,7199);

	USART_1_Init();
	delay_init();
	DHT11_Init();
	USART_1_Byte(USART1,"开启串口\n");
	u8 temp,him,DHT;
	while(1)
	{
		DHT=DHT11_READDATA(&temp,&him);
		if(DHT==0)
		{	
			printf("开始读入\n");
			printf("温度:%d\n",temp);
			printf("湿度:%d\n",him);
			delay_ms(1000);
		}
		else printf("读取失败\n");
		delay_ms(1000);
	}
		
}		


/*
//模拟按键练习
int main(void)
{
	LED_Init_Confit_MD();
	KEY_Init_Confit();
	delay_init();
	while(1)
	{
		KEY_Scan();
		LED_CHANGE();
	}
}
*/

/*//查询法
int main(void)
{
	LED_Init_Confit_MD();
	delay_init();
	while(1)
	{
		PCout(13)=0;//位带操作，扩大大4字节，效率更高
		//LED_GPIO_low_MD();
		delay_ms(500);
		//LED_GPIO_High_MD();
		PCout(13)=1;
		delay_ms(500);	
	}
}
*/


//#include "timer3.h"
//中断法 
// int main(void)
//{
//	LED_Init_Confit_MD();
//	TIM3_Init(999,719);//配置时钟3中断初始化
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//配置NVIC组
//	while(1)
//	{
//		LED_RUN();
//	}
//}
