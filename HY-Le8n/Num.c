#include "Num.h"



uchar  const dofly_DuanMa[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88};
// 显示段码值012345679.
uchar  const dofly_WeiMa[]={0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80};
//分别对应相应的数码管点亮,即位码

/*------------------------------------------------
发送字节程序
------------------------------------------------*/
static void SendByte(unsigned char dat)
{    
    unsigned char i; 

    for(i=0;i<8;i++)
    {
        WRITE_SCK(0);
        WRITE_DIO((dat&0x80));
        dat<<=1;
        WRITE_SCK(1);
    }
}

/*------------------------------------------------
发送双字节程序
595级联，n个595，就需要发送n字节后锁存
------------------------------------------------*/
static void Send2Byte(unsigned char dat1,unsigned char dat2)
{    
    SendByte(dat1);
    SendByte(dat2);      
}	  
/*------------------------------------------------
595锁存程序
595级联发送数据后，锁存有效
------------------------------------------------*/
static void Out595(void)
{
    WRITE_RCK(0);
    __ASM("NOP");
    WRITE_RCK(1);
}

void ShowNum(uint num)
{

#if  1
    static uchar index = 0;
    uchar one_num = 0;
    
    switch(index)
    {
    case 0: one_num = num/1000;
        break;
    case 1: one_num = (num/100)%10;
        break;
    case 2: one_num = (num/10)%10;
        break;
    case 3: one_num = num%10;
        break;
    default:    break;
    }


    Send2Byte(dofly_WeiMa[index],dofly_DuanMa[one_num]);// .位码,段码
    Out595();	 // 595锁存程序

    index++;
    if (index == TUBE_NUM)
        index = 0;
#else
    char index = 0;
    uchar one_num = 0;

    for (index = (TUBE_NUM - 1);index != -1;index--)
    {
        one_num = num%10;
        num = num/10;
        Send2Byte(dofly_WeiMa[index],dofly_DuanMa[one_num]);// .位码,段码
        Out595();	 // 595锁存程序
        DELAY_MS(1);
    }


#endif
}


