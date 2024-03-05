#include "Timer.h"

void TIM2_Init(uint16_t ARR, uint16_t PSC)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = ARR;
    TIM_TimeBaseInitStructure.TIM_Prescaler = PSC;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
}

int Delay_Init(void)
{
    TIM2_Init(100 - 1, 84 - 1);
    return 0;
}

int Delay_us(uint32_t us)
{
    TIM2->ARR = us;
    TIM2->CNT = TIM2->ARR;
    TIM_Cmd(TIM2, ENABLE);
    while (TIM2->CNT);
    TIM_Cmd(TIM2, DISABLE);
}

void Delay_ms(uint32_t ms)
{
    for (int i = 0; i < ms; i++)
    {
        Delay_us(1000);
    }
}
