#include "main.h"


/**************************************************************************
    @版权说明：在不收取他人费用的情况下，可以自由的分发本软件，分发时，保留本版权说明。
    @author  ：梅花七月香，公众号：梅花七月香
    @data    ：2024-2-25
    @brief   ：定时器实验
*****************************************************************************/




LED_t gLed[3];
int main(void)
{
    Debug_Init(115200);
    Delay_Init();
    printf("timer start\r\n");

    /* 初始化3个板载LED */
    LED_Init(&gLed[0], GPIOE, GPIO_Pin_5);
    LED_Init(&gLed[1], GPIOE, GPIO_Pin_6);
    LED_Init(&gLed[2], GPIOC, GPIO_Pin_13);
    
    int i = 0;
    while (1) {
        printf("%d\r\n", i++);
        Delay_ms(500);
        //打开所有的LED灯
        LED_On(&gLed[0]);
        LED_On(&gLed[1]);
        LED_On(&gLed[2]);
        Delay_ms(500);
        //关闭所有的LED灯
        LED_Off(&gLed[0]);
        LED_Off(&gLed[1]);
        LED_Off(&gLed[2]);
    }
}

