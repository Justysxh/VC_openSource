// CardHook.h: interface for the CCardHook class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARDHOOK_H__D4D8D92E_374E_4792_978E_217A4C4DD5BF__INCLUDED_)
#define AFX_CARDHOOK_H__D4D8D92E_374E_4792_978E_217A4C4DD5BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef void (*CallPro)(char str[9]);


typedef struct tagKBDLLHOOKSTRUCT {
    DWORD vkCode;      
    DWORD scanCode;   
    DWORD flags;      
    DWORD time;       
    DWORD dwExtraInfo; 
} KBDLLHOOKSTRUCT, FAR *LPKBDLLHOOKSTRUCT, *PKBDLLHOOKSTRUCT;

BOOL installhook();
BOOL  UnHook();
int initdll(CallPro callpro,_ConnectionPtr Connection);

#endif // !defined(AFX_CARDHOOK_H__D4D8D92E_374E_4792_978E_217A4C4DD5BF__INCLUDED_)
