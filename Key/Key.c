#include "Key.h"



//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//���������ȼ�!
uchar KEY_Scan(uchar mode)
{	 
    static uchar key_up=1;//�������ɿ���־
    if(mode)key_up=1;  //֧������		  
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
    return 0x00;// �ް�������
}

