#include "Key.h"



//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//按键有优先级!
uchar KEY_Scan(uchar mode)
{	 
    static uchar key_up=1;//按键按松开标志
    if(mode)key_up=1;  //支持连按		  
    if(key_up&&(KEY_FUNCTION==0||KEY_UP==0||KEY_DOWN==0||KEY_YES==0))
    {
        KEY_DELAY_MS(10);
        if(key_up&&(KEY_FUNCTION==0||KEY_UP==0||KEY_DOWN==0||KEY_YES==0))
        {
            key_up=0;
            if(KEY_FUNCTION==0)return KEY_FUNCTION_PRES;
            else if(KEY_UP==0)return KEY_UP_PRES;
            else if(KEY_DOWN==0)return KEY_DOWN_PRES;
            else if(KEY_YES==0)return KEY_YES_PRES;
        }
    }else if(KEY_FUNCTION==1&&KEY_UP==1&&KEY_DOWN==1&&KEY_YES==1)key_up=1; 	    
    return 0x00;// 无按键按下
}

