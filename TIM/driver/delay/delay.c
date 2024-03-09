#include "delay.h"

void TIM2_Init(uint16_t arr, uint16_t psc)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Down;
    TIM_TimeBaseInitStructure.TIM_Period = arr;
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
}

/**
  *@brief   初始化延时函数，定时1us
  *@param   无
  *@retval  无
  */
int Delay_Init(void)
{
    TIM2_Init(100 - 1, 84 - 1);
    return 0;
}

void Delay_us(uint32_t us)
{
    TIM2->ARR = us;
    TIM2->CNT = TIM2->ARR;
    TIM_Cmd(TIM2, ENABLE);
    while (TIM2->CNT);
    TIM_Cmd(TIM2, DISABLE);
}

/**
  *@brief   毫秒级延时，不建议在OS中使用
  *@param   无
  *@retval  无
  */
void Delay_ms(uint32_t ms)
{
    for (int i = 0; i < ms; i++){
        Delay_us(1000);
    }
}

