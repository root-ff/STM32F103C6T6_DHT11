// ����LED����ϰ//
#include "sys.h"

//��ʱ��3 �ж�LED��״̬ 
 int main(void)
{
	LED_Init_Confit_MD();
	TIM3_Init(9999,7199);

	USART_1_Init();
	delay_init();
	DHT11_Init();
	USART_1_Byte(USART1,"��������\n");
	u8 temp,him,DHT;
	while(1)
	{
		DHT=DHT11_READDATA(&temp,&him);
		if(DHT==0)
		{	
			printf("��ʼ����\n");
			printf("�¶�:%d\n",temp);
			printf("ʪ��:%d\n",him);
			delay_ms(1000);
		}
		else printf("��ȡʧ��\n");
		delay_ms(1000);
	}
		
}		


/*
//ģ�ⰴ����ϰ
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

/*//��ѯ��
int main(void)
{
	LED_Init_Confit_MD();
	delay_init();
	while(1)
	{
		PCout(13)=0;//λ�������������4�ֽڣ�Ч�ʸ���
		//LED_GPIO_low_MD();
		delay_ms(500);
		//LED_GPIO_High_MD();
		PCout(13)=1;
		delay_ms(500);	
	}
}
*/


//#include "timer3.h"
//�жϷ� 
// int main(void)
//{
//	LED_Init_Confit_MD();
//	TIM3_Init(999,719);//����ʱ��3�жϳ�ʼ��
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����NVIC��
//	while(1)
//	{
//		LED_RUN();
//	}
//}
