// WinResManager.h : main header file for the WINRESMANAGER application
//

#if !defined(AFX_WINRESMANAGER_H__3884ACC0_E27C_4BAB_9F20_498947970CE6__INCLUDED_)
#define AFX_WINRESMANAGER_H__3884ACC0_E27C_4BAB_9F20_498947970CE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWinResManagerApp:
// See WinResManager.cpp for the implementation of this class
//

class CWinResManagerApp : public CWinApp
{
public:
	CWinResManagerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinResManagerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWinResManagerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINRESMANAGER_H__3884ACC0_E27C_4BAB_9F20_498947970CE6__INCLUDED_)
