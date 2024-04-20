#include "sys.h"
u8 flag;
void KEY_Init_Confit(void)
{
	GPIO_InitTypeDef KEY;
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK,ENABLE);
	//≈‰÷√“˝Ω≈//
	KEY.GPIO_Mode=GPIO_Mode_IPD;
	KEY.GPIO_Pin=KEY_GPIO_Pin;
//	KEY.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(KEY_GPIO_Port, &KEY);
}
void KEY_Scan()
{
	if(PBin(2)==1)
	{
		delay_ms(5);
		if(PBin(2)==1)
		{
			flag=1;
		}
		while(PBin(2));
	}
}
