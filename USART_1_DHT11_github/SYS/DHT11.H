#ifndef __DHT11__
#define __DHT11__

#include "sys.h"

#define DHT11_WRITE PAout(5)
#define DHT11_READ PAin(5)

#define DHT11_OUT() {GPIOA->CRL&=0XFF0FFFFF;GPIOA->CRL|= 3<<5*4;}
#define DHT11_IN() {GPIOA->CRL&=0XFF0FFFFF;GPIOA->CRL|= 8<<5*4;}

void DHT11_Init(void);
u8 DHT11_READDATA(u8 *temperature,u8 *humidity);
u8 DHT11_byte(void);
u8 DHT11_bit(void);
u8 DHT11RST(void);


#endif
