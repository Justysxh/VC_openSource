//###########################################################################
//
//       Module:  SOFTDOG.H
//
//  Decriptions:  This is header file of SoftDog's Win32 API module.
//
//  Copyright (C) SafeNet China Ltd. All Rights Reserved.
//
//###########################################################################

#ifndef _SOFTDOG_H_
#define _SOFTDOG_H_


#ifdef  __cplusplus
extern "C" {
#endif

extern short int DogBytes,DogAddr;
extern void * DogData;

extern unsigned long ReadDog(void);
extern unsigned long WriteDog(void);

#ifdef  __cplusplus
}
#endif


#endif //_SOFTDOG_H_
