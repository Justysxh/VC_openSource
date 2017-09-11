//////////////////////////////////////////////////////////////////
//NewSig.h
#ifndef __NEWSIG_H__
#define __NEWSIG_H__

#include <windows.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define		SIG_CADENCE_BUSY		1	//√¶“Ù
#define		SIG_CADENCE_RINGBACK	2   //ªÿ¡Â“Ù


//0 not debug 1 debug dial 2 debug dial and busy check
int	WINAPI Sig_Init ( int );

int WINAPI Sig_CheckBusy(WORD wChNo);
int WINAPI Sig_StartDial(WORD wChNo,char* DialNum,char* PreDialNum,WORD wMode);
int WINAPI Sig_CheckDial(WORD wChNo);
int WINAPI Sig_GetDialStep(WORD wChNo);
int WINAPI Sig_GetCadenceCount(WORD wChNo,int nCadenceType);
void WINAPI Sig_ResetCheck(WORD wChNo);
//add for test only 

// add in 2004.09.18
#define		CNT_REASON_POLARITY			1
#define		CNT_REASON_VOICE			2
#define		CNT_REASON_CADENCE_BREAK	3

int WINAPI Sig_CheckBusy_New ( WORD wChNo, long *plBusyType, long *plBusyCount );
int WINAPI Sig_CheckDial_New ( WORD wChNo, long *plConnectReason );

// add for test only


//add in 2005.10.09 by yezhimin.
int WINAPI Sig_StartDialEx(WORD wChNo, char *PreDialNum, WORD wMode);
int WINAPI Sig_CheckDialTone(WORD wChNo);
//end add

#ifdef	__cplusplus
}
#endif

#endif
