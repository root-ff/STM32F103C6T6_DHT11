#ifndef __KEY__
#define __KEY__

#include "sys.h"
extern u8 flag;

#define KEY_GPIO_Pin GPIO_Pin_2
#define KEY_GPIO_Port GPIOB
#define KEY_GPIO_CLK RCC_APB2Periph_GPIOB

void KEY_Init_Confit(void);
void KEY_Scan(void);
#endif
