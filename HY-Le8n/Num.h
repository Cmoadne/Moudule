#ifndef __NUM_H
#define __NUM_H
//底层驱动
//1、改驱动
//2、隔一段时间调用ShoeNum
#include "stm32f1xx_hal.h"

#define uchar unsigned char
#define uint  unsigned int

//数码管个数
#define TUBE_NUM      4

//IO口
#define DIO_Pin         GPIO_PIN_5
#define DIO_GPIO_Port   GPIOB
#define SCK_Pin         GPIO_PIN_6
#define SCK_GPIO_Port   GPIOB
#define RCK_Pin         GPIO_PIN_7
#define RCK_GPIO_Port   GPIOB

//电平输出
#define WRITE_DIO(n) HAL_GPIO_WritePin(DIO_GPIO_Port,DIO_Pin,(GPIO_PinState)(n))
#define WRITE_SCK(n)  HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,(GPIO_PinState)(n))
#define WRITE_RCK(n)  HAL_GPIO_WritePin(RCK_GPIO_Port,RCK_Pin,(GPIO_PinState)(n))


//DELAY函数
#define DELAY_MS(x)  HAL_Delay (x)


void ShowNum(uint num);//数码管显示


#endif
