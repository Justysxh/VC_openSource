// CardHook.cpp: implementation of the CCardHook class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TimeCard.h"
#include "CardHook.h"
#define WH_KEYBOARD_LL     13

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CallPro  Ghookpro;
static HHOOK hkb=NULL;
_ConnectionPtr pConnection;
char *GIDS = NULL;
int length = 0;
char str[9] = {'\0'};
int index = 0;

LRESULT  CALLBACK KeyboardProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	KBDLLHOOKSTRUCT *pkh = (KBDLLHOOKSTRUCT *) lParam;
	if(HC_ACTION==nCode)
	{

		if (wParam == WM_KEYDOWN)
		{
			if (index == 8 && 
				((pkh->vkCode >= 48 && pkh->vkCode <= 57)
				|| (pkh->vkCode >= VK_NUMPAD0 && pkh->vkCode <=VK_NUMPAD9)))
			{
				for (int i = 0 ; i< 7 ;i++)
					str[i] = str[i + 1];
				index = 7;
			}

			switch (pkh->vkCode)
			{
			case 48:str[index++] = '0';break;
			case 49:str[index++] = '1';break;
			case 50:str[index++] = '2';break;
			case 51:str[index++] = '3';break;
			case 52:str[index++] = '4';break;
			case 53:str[index++] = '5';break;
			case 54:str[index++] = '6';break;
			case 55:str[index++] = '7';break;
			case 56:str[index++] = '8';break;
			case 57:str[index++] = '9';break;
			case VK_NUMPAD0:str[index++] = '0';break;
			case VK_NUMPAD1:str[index++] = '1';break;
			case VK_NUMPAD2:str[index++] = '2';break;
			case VK_NUMPAD3:str[index++] = '3';break;
			case VK_NUMPAD4:str[index++] = '4';break;
			case VK_NUMPAD5:str[index++] = '5';break;
			case VK_NUMPAD6:str[index++] = '6';break;
			case VK_NUMPAD7:str[index++] = '7';break;
			case VK_NUMPAD8:str[index++] = '8';break;
			case VK_NUMPAD9:str[index++] = '9';break;
			}
			if (pkh->vkCode == 13)
			{
				if (Ghookpro != NULL)
				{ 
					str[8] = '\0';
					CString tempstr;
					tempstr.Format("select* from picture where ¿¨ºÅ = '%s'",str);
					_RecordsetPtr RecordSet;
					RecordSet.CreateInstance(__uuidof(Recordset));
					RecordSet->Open((_variant_t)(tempstr),pConnection.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
					if (RecordSet->RecordCount == 1)
						Ghookpro(str);
				}
			}
		}
	}
	LRESULT RetVal = CallNextHookEx( hkb, nCode, wParam, lParam );	
	return  RetVal;
}

BOOL installhook()
{
	index = 0;
	hkb=SetWindowsHookEx(WH_KEYBOARD_LL,(HOOKPROC)KeyboardProc,::AfxGetApp()->m_hInstance,0);
	return TRUE;
}

BOOL  UnHook()
{   	
	BOOL unhooked = UnhookWindowsHookEx(hkb);
	return unhooked;
} 

int initdll(CallPro callpro,_ConnectionPtr Connection)
{
	pConnection = Connection;
	if (callpro != NULL)
		Ghookpro = callpro;
	return 5;
}