#include "sys.h"  //包含需要的头文件

void USART_1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART1_InitStruct;
	NVIC_InitTypeDef NVIC_InitStructent;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1 , ENABLE);
	
	// PA9
	GPIO_InitStruct.GPIO_Pin =	USART1_GPIO_PinTX;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART1_GPIO_Port,&GPIO_InitStruct);
	
	// PA10 
	GPIO_InitStruct.GPIO_Pin = USART1_GPIO_PinRX;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART1_GPIO_Port,&GPIO_InitStruct);
	//USART
	USART1_InitStruct.USART_BaudRate =9600;
	USART1_InitStruct.USART_HardwareFlowControl= USART_HardwareFlowControl_None;
	USART1_InitStruct.USART_Mode= USART_Mode_Rx|USART_Mode_Tx;
	USART1_InitStruct.USART_Parity= USART_Parity_No;
	USART1_InitStruct.USART_StopBits= USART_StopBits_1;
	USART1_InitStruct.USART_WordLength= USART_WordLength_8b;
	
	
	NVIC_InitStructent.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStructent.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructent.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructent.NVIC_IRQChannelSubPriority=2;
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Init(USART1,&USART1_InitStruct);
	USART_Cmd(USART1, ENABLE);
	NVIC_Init(&NVIC_InitStructent);
}



void USART_1_Bit(USART_TypeDef* USARTx, uint16_t Data)
{
  /* Check the parameters */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_DATA(Data)); 
    
  /* Transmit Data */
	USARTx->DR = (Data & (uint16_t)0x01FF);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TXE)==RESET);
}




void USART_1_Byte(USART_TypeDef* USARTx,char *STR)
{
  /* Check the parameters */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
	while(*STR!='\0')
	{
		USART_1_Bit(USARTx,*STR++);
	}
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==RESET);
	
    
}
 uint16_t USART_ReceiveByte(USART_TypeDef* USARTx)
{
  /* Check the parameters */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  
	while(USART_GetFlagStatus(USARTx,USART_FLAG_RXNE)==RESET)
	{};
	 return USART_ReceiveData(USARTx);
}
#pragma import(__use_no_semihosting)             
                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;          
void _sys_exit(int x) 
{ 
	x = x; 
} 

int fputc(int ch, FILE *f)
{
		
		USART_SendData(USART1, (uint8_t) ch);			
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);			
		return (ch);
}


int fgetc(FILE *f)
{		
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
		return (int)USART_ReceiveData(USART1);

}

