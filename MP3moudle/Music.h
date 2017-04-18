#ifndef __MUSIC_H
#define __MUSIC_H

//������9600
//������

#include "stm32f1xx_hal.h"
#define uchar unsigned char     //����һ�·������ʹ��
#define uint  unsigned int	    //����һ�·������ʹ��
#define u16   unsigned short
#define ulong unsigned long	    //����һ�·������ʹ��		

#define DELAY_MS_MUSIC(n)  HAL_Delay (n)


//����.C ����    �����ٻص���������
//����ȫ����
#define START_MUSIC SendCmd(5,0)    //����
#define STOP_MUSIC  SendCmd(5,1)
#define NEXT_MUSIC  SendCmd(5,2)  
#define LAST_MUSIC  SendCmd(5,3)
#define ADD_VOICE   SendCmd(5,4)
#define DOWN_VOICE  SendCmd(5,5)
#define FAST_FRONT_MUSIC  SendCmd(5,6)  //���
#define FAST_BACK_MUSIC  SendCmd(5,7)
#define START_STOP_SWITCH  SendCmd(5,8) //���� ��ͣ�л�

#define EQ_SETTING SendCmd(6,0)  //����EQ
#define FILE_SWITCH SendCmd(6,1)  //�л��ļ�
#define DEVICE_SWITCH SendCmd(6,2)  //�л��豸

#define INSERT_MUSIC SendCmd(7,0)  //�岥


extern UART_HandleTypeDef huart2;


//inline void SEND_CMD(uchar * pdata,u16 size)
//{
//    HAL_UART_Transmit(&huart2,pdata,size,0xffff);
//}

//���ڷ�������
#define SEND_CMD(x,y)  HAL_UART_Transmit(&huart2,x,y,0xffff);

//�������ĸ����࣬�ڷ�����˳��
void SendCmd(uchar CmdClass,uchar CmdOrder);
#endif

