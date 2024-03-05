#ifndef __TIMER_H__
#define __TIMER_H__

#include "stm32f4xx.h" // Device header
#include <stdint.h>

void TIM2_Init(uint16_t ARR, uint16_t PSC);
int Delay_Init(void);
int Delay_us(uint32_t us);
void Delay_ms(uint32_t ms);
    
#endif
