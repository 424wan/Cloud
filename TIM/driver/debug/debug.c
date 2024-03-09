#include "debug.h"


/* 标准库需要的支持函数 */
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

/* 重定义fputc函数 */
int fputc(int ch, FILE *f)
{
    while((USART1->SR & 0X40) == 0); //循环发送,直到发送完毕
    USART1->DR = (uint8_t)ch;
    return ch;
}

/******************************************************************************
 * @brief     初始化串口1作为调试端口
 *
 * @param[in]  bound_rate   :  波特率
 *
 * @return     无
 *
 ******************************************************************************/
void Debug_Init(uint32_t bound_rate)
{
    /* GPIO端口设置 */
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //使能GPIOA时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//使能USART1时钟
 
    /*串口1对应引脚复用映射 */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);  //PA9复用为USART1_TX
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); //PA10复用为USART1_RX
    
    /* USART1端口配置 */
    GPIO_InitStructure.GPIO_Pin    = GPIO_Pin_9 | GPIO_Pin_10;  //GPIOA9与GPIOA10
    GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_AF;              //复用功能
    GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;          //速度50MHz
    GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;             //推挽复用输出
    GPIO_InitStructure.GPIO_PuPd   = GPIO_PuPd_UP;              //上拉
    GPIO_Init(GPIOA, &GPIO_InitStructure);                      //初始化PA9，PA10

    /* USART1 初始化设置 */
    USART_InitStructure.USART_BaudRate              = bound_rate;                       //波特率设置
    USART_InitStructure.USART_WordLength            = USART_WordLength_8b;              //8位数据位长
    USART_InitStructure.USART_StopBits              = USART_StopBits_1;                 //一个停止位
    USART_InitStructure.USART_Parity                = USART_Parity_No;                  //无奇偶校验位
    USART_InitStructure.USART_HardwareFlowControl   = USART_HardwareFlowControl_None;   //无硬件数据流控制
    USART_InitStructure.USART_Mode                  = USART_Mode_Rx | USART_Mode_Tx;    //收发模式
    USART_Init(USART1, &USART_InitStructure);                                           //初始化串口
    USART_Cmd(USART1, ENABLE);                                                          //使能串口
}
