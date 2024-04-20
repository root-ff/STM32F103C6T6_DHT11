#include "delay.h"
#include "stm32f10x.h"  //������Ҫ��ͷ�ļ�

static u8 fac_us = 0;
static u16 fac_ms = 0;

void delay_init()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//��misc.c�У�ѡ���ⲿʱ��Դ HCLK/8
	fac_us = SystemCoreClock / 8000000;
	fac_ms = (u16)fac_us*1000;

}

void delay_us(u32 nus)
{		
	u32 Time;	    	 
	SysTick->LOAD=nus*fac_us; 					//ʱ�����	  		 
	SysTick->VAL=0x00;        					//��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//��ʼ����	  
	do
	{
		Time=SysTick->CTRL;
	}while((Time&0x01)&&!(Time&(1<<16)));		//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//�رռ�����
	SysTick->VAL =0X00;      					 //��ռ�����	 
}

void delay_ms(u16 nms)
{	 		  	  
	u32 Time;		   
	SysTick->LOAD=(u32)nms*fac_ms;				//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;							//��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//��ʼ����  
	do
	{
		Time=SysTick->CTRL;
	}while((Time&0x01)&&!(Time&(1<<16)));		//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//�رռ�����
	SysTick->VAL =0X00;       					//��ռ�����	  	    
}

