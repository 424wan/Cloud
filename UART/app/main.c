#include "main.h"


/**************************************************************************
    @��Ȩ˵�����ڲ���ȡ���˷��õ�����£��������ɵķַ���������ַ�ʱ����������Ȩ˵����
    @author  ��÷�������㣬���ںţ�÷��������
    @data    ��2024-2-25
    @brief   ������ʵ��
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

