#ifndef __LED_H__
#define __LED_H__
#include "stm32f10x.h"


#define LED_GPIO_Pin GPIO_Pin_13
#define LED_GPIO_Port GPIOC
#define LED_GPIO_CLK RCC_APB2Periph_GPIOC



void LED_GPIO_Config(void);
void LED_GPIO_High(void);
void LED_GPIO_low(void);
#endif
