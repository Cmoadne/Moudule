#ifndef __KEY_H
#define __KEY_H
#include "stm32f1xx_hal.h"
//1、改驱动，2、按键扫描

#define uchar unsigned char
#define uint  unsigned int
#define KEY_DELAY_MS(n) HAL_Delay (n)

//IO
#define KEY_YES_Pin GPIO_PIN_1
#define KEY_YES_GPIO_Port GPIOB
#define KEY_DOWN_Pin GPIO_PIN_10
#define KEY_DOWN_GPIO_Port GPIOB
#define KEY_UP_Pin GPIO_PIN_11
#define KEY_UP_GPIO_Port GPIOB
#define KEY_FUNCTION_Pin GPIO_PIN_13
#define KEY_FUNCTION_GPIO_Port GPIOB

//输入
#define KEY_FUNCTION HAL_GPIO_ReadPin(KEY_FUNCTION_GPIO_Port,KEY_FUNCTION_Pin)
#define KEY_UP       HAL_GPIO_ReadPin(KEY_UP_GPIO_Port,KEY_UP_Pin)
#define KEY_DOWN     HAL_GPIO_ReadPin(KEY_DOWN_GPIO_Port,KEY_DOWN_Pin)
#define KEY_YES      HAL_GPIO_ReadPin(KEY_YES_GPIO_Port,KEY_YES_Pin)

//返回值宏定义
#define KEY_FUNCTION_PRES 	0x01
#define KEY_UP_PRES	    0x02
#define KEY_DOWN_PRES	0x04
#define KEY_YES_PRES   0x08
#define KEY_IN_PRES    0x10


//按键扫描
uchar KEY_Scan(uchar mode);

#endif

