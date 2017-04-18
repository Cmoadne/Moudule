#ifndef __FLASH_H
#define __FLASH_H
//1��������  2����д

#include "stm32f1xx_hal.h"


#define u8 unsigned char
#define u16 unsigned short
#define vu16 volatile unsigned short
#define u32  unsigned int

//������Ҫ����
#define STM32_FLASH_SIZE 64 	 		//��ѡSTM32��FLASH������С(��λΪK)
#define STM32_FLASH_WREN 1              //ʹ��FLASHд��(0��������;1��ʹ��)
//////////////////////////////////////////////////////////////////////////////////////////////////////

#define FLASH_SAVE_ADDR  0X0800f800		//����FLASH �����ַ(����Ϊż��������ֵҪ���ڱ�������ռ��FLASH�Ĵ�С+0X08000000)

//FLASH��ʼ��ַ
#define STM32_FLASH_BASE 0x08000000 	//STM32 FLASH����ʼ��ַ

//����
#define WRITE_HALF(WriteAddr,pBuffer)     HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,WriteAddr,pBuffer)//д����
#define FLASH_UNLOCK       HAL_FLASH_Unlock ()//����flash
#define FLASH_LOCK         HAL_FLASH_Lock ()//����flash

#define ERASE_SUCCESS  HAL_OK//����ҳ
inline HAL_StatusTypeDef FLASH_ERASE_PAGE(u32 PageAddr)
{
    //��ʼ��FLASH_EraseInitTypeDef
    FLASH_EraseInitTypeDef f;
    f.TypeErase = FLASH_TYPEERASE_PAGES;
    f.PageAddress = PageAddr;
    f.NbPages = 1;
    //����PageError
    u32 PageError = 0;
    //���ò�������
    return HAL_FLASHEx_Erase(&f, &PageError);

}



u16 STMFLASH_ReadHalfWord(u32 faddr);		  //��������  
void STMFLASH_WriteLenByte(u32 WriteAddr,u32 DataToWrite,u16 Len);	//ָ����ַ��ʼд��ָ�����ȵ�����
u32 STMFLASH_ReadLenByte(u32 ReadAddr,u16 Len);						//ָ����ַ��ʼ��ȡָ����������
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//��ָ����ַ��ʼд��ָ�����ȵ�����
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//��ָ����ַ��ʼ����ָ�����ȵ�����

//����д��
void Test_Write(u32 WriteAddr,u16 WriteData);	

#endif


