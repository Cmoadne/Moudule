#ifndef __FLASH_H
#define __FLASH_H
//1、改驱动  2、读写

#include "stm32f1xx_hal.h"


#define u8 unsigned char
#define u16 unsigned short
#define vu16 volatile unsigned short
#define u32  unsigned int

//根据需要设置
#define STM32_FLASH_SIZE 64 	 		//所选STM32的FLASH容量大小(单位为K)
#define STM32_FLASH_WREN 1              //使能FLASH写入(0，不是能;1，使能)
//////////////////////////////////////////////////////////////////////////////////////////////////////

#define FLASH_SAVE_ADDR  0X0800f800		//设置FLASH 保存地址(必须为偶数，且其值要大于本代码所占用FLASH的大小+0X08000000)

//FLASH起始地址
#define STM32_FLASH_BASE 0x08000000 	//STM32 FLASH的起始地址

//驱动
#define WRITE_HALF(WriteAddr,pBuffer)     HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,WriteAddr,pBuffer)//写半字
#define FLASH_UNLOCK       HAL_FLASH_Unlock ()//解锁flash
#define FLASH_LOCK         HAL_FLASH_Lock ()//上锁flash

#define ERASE_SUCCESS  HAL_OK//擦除页
inline HAL_StatusTypeDef FLASH_ERASE_PAGE(u32 PageAddr)
{
    //初始化FLASH_EraseInitTypeDef
    FLASH_EraseInitTypeDef f;
    f.TypeErase = FLASH_TYPEERASE_PAGES;
    f.PageAddress = PageAddr;
    f.NbPages = 1;
    //设置PageError
    u32 PageError = 0;
    //调用擦除函数
    return HAL_FLASHEx_Erase(&f, &PageError);

}



u16 STMFLASH_ReadHalfWord(u32 faddr);		  //读出半字  
void STMFLASH_WriteLenByte(u32 WriteAddr,u32 DataToWrite,u16 Len);	//指定地址开始写入指定长度的数据
u32 STMFLASH_ReadLenByte(u32 ReadAddr,u16 Len);						//指定地址开始读取指定长度数据
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//从指定地址开始写入指定长度的数据
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//从指定地址开始读出指定长度的数据

//测试写入
void Test_Write(u32 WriteAddr,u16 WriteData);	

#endif


