#include "sys.h"

// DHT11 主机从机初始化
u8 DHT11RST(void)
{
	u8 cnt=0;
	DHT11_OUT();
	DHT11_WRITE =0;
	delay_ms(20);
	DHT11_WRITE =1;
	delay_us(30);
	DHT11_IN();
	while(!DHT11_READ&&cnt<100)
	{
		cnt++;
		delay_us(1);
	};
	if(cnt>=100)
	{
		return 1;
	}
	else cnt =0;
	while(DHT11_READ&&cnt<100)
	{
		cnt++;
		delay_us(1);
	};
	if(cnt>=100)
	{
		return 1;
	}
	else 
		return 0;
}
u8 DHT11_bit(void)
{
	while(DHT11_READ);//从机检测是否收到信号
	while(!DHT11_READ);
	delay_us(35);
	if(DHT11_READ)	return 1;
	else return 0;
}
u8 DHT11_byte(void)
{
	u8 mask,data;
	for(mask=0x80;mask!=0;mask>>=1)
	{
		if(DHT11_bit())
		{
			data|=mask;
		}
		else data &= ~mask;
	}
	return data;
}


// 该函数返回0 表示读取成功 返回1 表示读取不成功
u8 DHT11_READDATA(u8 *temperature,u8 *humidity)
{
	u8 i,buf[5];
	if(DHT11RST()==0)
	{
		
		for(i=0;i<5;i++)
		{
			buf[i]=DHT11_byte();
		}
		
		if(buf[0]+buf[1]+buf[2]+buf[3]==buf[4])
		{
			*humidity = buf[0];
			*temperature = buf[2];
			return 0;
		}
		else 
		{
			return 1;
		}
	}
	else 
		return 1;
}





void DHT11_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
}
