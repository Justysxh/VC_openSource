/**************************************************************************************
* Copyright (c) 2007 Senselock Data Security Centre.
* All rights reserved.
*
* filename: EleT2.h
*
* brief: EleT2 library interface declaration, return value and some constant definition.
* 
* history:
*
***************************************************************************************/



#ifndef __ELET2_H__
#define __ELET2_H__

#ifdef __cplusplus
extern "C" {
#endif

// 错误返回值
#define ELE_T2_SUCCESS                           0x00020000  // 成功
#define ELE_T2_NO_MORE_DEVICE                    0x00020001  // 没有找到相应的模板设备
#define ELE_T2_INVALID_PASSWORD                  0x00020002  // 无效的密码
#define ELE_T2_INSUFFICIENT_BUFFER               0x00020003  // 缓冲区不足
#define ELE_T2_BEYOND_DATA_SIZE                  0x00020004  // 读写数据区越界

unsigned long EleT2Read(
    unsigned short usOffset, 
    unsigned char* pucOutbuffer, 
    unsigned short usOutbufferLen, 
    unsigned short* usReadLen
    );
    
unsigned long EleT2Write(
    unsigned short usOffset, 
    char* pcPassword, 
    unsigned char *pucInbuffer, 
    unsigned short usInbufferLen, 
    unsigned short*usWrittenLen
    );

unsigned long EleT2ChangePassword(
    char* pcOldPass,
    char* pcNewPass
    );

#ifdef __cplusplus
}
#endif
#endif  // __ELET2_H__





















