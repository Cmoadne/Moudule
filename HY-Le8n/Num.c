#include "Num.h"



uchar  const dofly_DuanMa[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88};
// ��ʾ����ֵ012345679.
uchar  const dofly_WeiMa[]={0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80};
//�ֱ��Ӧ��Ӧ������ܵ���,��λ��

/*------------------------------------------------
�����ֽڳ���
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
����˫�ֽڳ���
595������n��595������Ҫ����n�ֽں�����
------------------------------------------------*/
static void Send2Byte(unsigned char dat1,unsigned char dat2)
{    
    SendByte(dat1);
    SendByte(dat2);      
}	  
/*------------------------------------------------
595�������
595�����������ݺ�������Ч
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


    Send2Byte(dofly_WeiMa[index],dofly_DuanMa[one_num]);// .λ��,����
    Out595();	 // 595�������

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
        Send2Byte(dofly_WeiMa[index],dofly_DuanMa[one_num]);// .λ��,����
        Out595();	 // 595�������
        DELAY_MS(1);
    }


#endif
}


