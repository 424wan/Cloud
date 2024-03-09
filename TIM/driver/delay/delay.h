#ifndef _TIMER_H
#define _TIMER_H


#include <stdint.h>
#include "stm32f4xx.h"


/* ÓÃ»§API */

int   Delay_Init(void);
void  Delay_ms(uint32_t us);
void  Delay_ms(uint32_t ms);

#endif
