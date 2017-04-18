#ifndef __MUSIC_H
#define __MUSIC_H

//波特率9600
//改驱动

#include "stm32f1xx_hal.h"
#define uchar unsigned char     //定义一下方便后面使用
#define uint  unsigned int	    //定义一下方便后面使用
#define u16   unsigned short
#define ulong unsigned long	    //定义一下方便后面使用		

#define DELAY_MS_MUSIC(n)  HAL_Delay (n)


//调用.C 函数    函数再回调内联函数
//不完全命令
#define START_MUSIC SendCmd(5,0)    //播放
#define STOP_MUSIC  SendCmd(5,1)
#define NEXT_MUSIC  SendCmd(5,2)  
#define LAST_MUSIC  SendCmd(5,3)
#define ADD_VOICE   SendCmd(5,4)
#define DOWN_VOICE  SendCmd(5,5)
#define FAST_FRONT_MUSIC  SendCmd(5,6)  //快进
#define FAST_BACK_MUSIC  SendCmd(5,7)
#define START_STOP_SWITCH  SendCmd(5,8) //播放 暂停切换

#define EQ_SETTING SendCmd(6,0)  //设置EQ
#define FILE_SWITCH SendCmd(6,1)  //切换文件
#define DEVICE_SWITCH SendCmd(6,2)  //切换设备

#define INSERT_MUSIC SendCmd(7,0)  //插播


extern UART_HandleTypeDef huart2;


//inline void SEND_CMD(uchar * pdata,u16 size)
//{
//    HAL_UART_Transmit(&huart2,pdata,size,0xffff);
//}

//串口发送数据
#define SEND_CMD(x,y)  HAL_UART_Transmit(&huart2,x,y,0xffff);

//命令在哪个分类，在分类中顺序
void SendCmd(uchar CmdClass,uchar CmdOrder);
#endif

