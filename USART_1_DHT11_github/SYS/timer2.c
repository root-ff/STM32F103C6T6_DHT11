#include "sys.h"
// u8 i=0;
/********************
���ܶ�ʱ��ʱ�ӡ�
RCC_APB1PeriphClockCmd();
��  ��ʼ����ʱ��������ARR,PSC��
TIM_TimeBaseInit();
�ۿ�����ʱ���жϣ�����NVIC��
void TIM_ITConfig();
NVIC_Init();
��ʹ�ܶ�ʱ����
TIM_Cmd();
�ޱ�д�жϷ�������
TIMx_IRQHandler();
*****************/
void TIM2_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��
	
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 ������5000Ϊ500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  10Khz�ļ���Ƶ��  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
			
	NVIC_InitStruct.NVIC_IRQChannel=TIM2_IRQn; //����NVIC����ʱ���ն�3
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);	//��ʼ������

	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIMx����
	
}





