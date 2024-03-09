#include "debug.h"


/* ��׼����Ҫ��֧�ֺ��� */
#pragma import(__use_no_semihosting)

struct __FILE
{
    int handle;
};

FILE __stdout;

void _sys_exit(int x)
{ 
    x = x;
}

/* �ض���fputc���� */
int fputc(int ch, FILE *f)
{
    while((USART1->SR & 0X40) == 0); //ѭ������,ֱ���������
    USART1->DR = (uint8_t)ch;
    return ch;
}

/******************************************************************************
 * @brief     ��ʼ������1��Ϊ���Զ˿�
 *
 * @param[in]  bound_rate   :  ������
 *
 * @return     ��
 *
 ******************************************************************************/
void Debug_Init(uint32_t bound_rate)
{
    /* GPIO�˿����� */
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //ʹ��GPIOAʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//ʹ��USART1ʱ��
 
    /*����1��Ӧ���Ÿ���ӳ�� */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);  //PA9����ΪUSART1_TX
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); //PA10����ΪUSART1_RX
    
    /* USART1�˿����� */
    GPIO_InitStructure.GPIO_Pin    = GPIO_Pin_9 | GPIO_Pin_10;  //GPIOA9��GPIOA10
    GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_AF;              //���ù���
    GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;          //�ٶ�50MHz
    GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;             //���츴�����
    GPIO_InitStructure.GPIO_PuPd   = GPIO_PuPd_UP;              //����
    GPIO_Init(GPIOA, &GPIO_InitStructure);                      //��ʼ��PA9��PA10

    /* USART1 ��ʼ������ */
    USART_InitStructure.USART_BaudRate              = bound_rate;                       //����������
    USART_InitStructure.USART_WordLength            = USART_WordLength_8b;              //8λ����λ��
    USART_InitStructure.USART_StopBits              = USART_StopBits_1;                 //һ��ֹͣλ
    USART_InitStructure.USART_Parity                = USART_Parity_No;                  //����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl   = USART_HardwareFlowControl_None;   //��Ӳ������������
    USART_InitStructure.USART_Mode                  = USART_Mode_Rx | USART_Mode_Tx;    //�շ�ģʽ
    USART_Init(USART1, &USART_InitStructure);                                           //��ʼ������
    USART_Cmd(USART1, ENABLE);                                                          //ʹ�ܴ���
}
