#include "main.h"


/**************************************************************************
    @版权说明：在不收取他人费用的情况下，可以自由的分发本软件，分发时，保留本版权说明。
    @author  ：梅花七月香，公众号：梅花七月香
    @data    ：2024-2-25
    @brief   ：串口实验
*****************************************************************************/




int main(void)
{
    Debug_Init(115200);
    while((USART1->SR & 0X40) == 0);
    USART_SendData(USART1, 'A');
    while((USART1->SR & 0X40) == 0);
    USART_SendData(USART1, 'B');
    while((USART1->SR & 0X40) == 0);
    USART_SendData(USART1, '\r');
    while((USART1->SR & 0X40) == 0);
    USART_SendData(USART1, '\n');
    printf("usart is ok!\r\n");

    while (1) {
        ;
    }
}

