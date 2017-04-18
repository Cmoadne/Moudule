#ifndef __NUM_H
#define __NUM_H
//�ײ�����
//1��������
//2����һ��ʱ�����ShoeNum
#include "stm32f1xx_hal.h"

#define uchar unsigned char
#define uint  unsigned int

//����ܸ���
#define TUBE_NUM      4

//IO��
#define DIO_Pin         GPIO_PIN_5
#define DIO_GPIO_Port   GPIOB
#define SCK_Pin         GPIO_PIN_6
#define SCK_GPIO_Port   GPIOB
#define RCK_Pin         GPIO_PIN_7
#define RCK_GPIO_Port   GPIOB

//��ƽ���
#define WRITE_DIO(n) HAL_GPIO_WritePin(DIO_GPIO_Port,DIO_Pin,(GPIO_PinState)(n))
#define WRITE_SCK(n)  HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,(GPIO_PinState)(n))
#define WRITE_RCK(n)  HAL_GPIO_WritePin(RCK_GPIO_Port,RCK_Pin,(GPIO_PinState)(n))


//DELAY����
#define DELAY_MS(x)  HAL_Delay (x)


void ShowNum(uint num);//�������ʾ


#endif
