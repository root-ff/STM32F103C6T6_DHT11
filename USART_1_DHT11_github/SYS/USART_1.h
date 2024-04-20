#ifndef __USART_1_H
#define __USART_1_H
#include "sys.h"
void USART_1_Init(void);
#define USART1_GPIO_PinTX GPIO_Pin_9
#define USART1_GPIO_PinRX GPIO_Pin_10
#define USART1_GPIO_Port GPIOA
void USART_1_Bit(USART_TypeDef* USARTx, uint16_t Data);
void USART_1_Byte(USART_TypeDef* USARTx, char *STR);
uint16_t USART_ReceiveByte(USART_TypeDef* USARTx);

#endif
