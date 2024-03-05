#include "main.h"

void Delay(int time)
{
    for (int i = time; i > 0; i--) {
        for (int j = 0xffff; j > 0; j--) {
            ;
        }
    }
}

int main(void)
{
    LED_Init();
    
    while (1)
    {
        LED_On();
        Delay(1000);
        
        LED_Off();
        Delay(1000);
    }
}

