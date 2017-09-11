// ControlPanel.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>
#include "resource.h"
#include "wtypes.h"
#include "cpl.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


static AFX_EXTENSION_MODULE ControlPanelDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("CONTROLPANEL.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(ControlPanelDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		new CDynLinkLibrary(ControlPanelDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("CONTROLPANEL.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(ControlPanelDLL);
	}
	return 1;   // ok
}

long CALLBACK CPlApplet(HWND hParent,UINT msg,long wParam,long lParam)
{
	switch (msg)
	{
	case CPL_INIT:
		{
			return TRUE;
		}
	case CPL_GETCOUNT:
		{
			return 1;
		}

	case CPL_INQUIRE:
		{
			LPCPLINFO pInfo = (LPCPLINFO)lParam;
			pInfo->idIcon = IDI_ICON1;
			pInfo->idInfo = IDS_COMMENT;
			pInfo->idName = IDS_APPNAME;
			break;
		}
	case CPL_DBLCLK:
		{
			MessageBox(0,"明日科技欢迎您!","提示",64);
			break;
		}
	case CPL_STOP:
	case CPL_EXIT:
		break;
	}
	return 0;
}