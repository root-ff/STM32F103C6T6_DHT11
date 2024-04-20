#ifndef __LED_modularization__
#define __LED_modularization__

#include "sys.h"

#define LED_GPIO_Pin GPIO_Pin_13
#define LED_GPIO_Port GPIOC
#define LED_GPIO_CLK RCC_APB2Periph_GPIOC

void LED_Init_Confit_MD(void);
void LED_GPIO_High_MD(void);
void LED_GPIO_low_MD(void);
void LED_RUN(void);
void LED_CHANGE(void);
#endif
