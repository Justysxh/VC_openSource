// ScreenProtect.h : main header file for the SCREENPROTECT application
//

#if !defined(AFX_SCREENPROTECT_H__86A26592_BB2B_4508_874B_34691D972256__INCLUDED_)
#define AFX_SCREENPROTECT_H__86A26592_BB2B_4508_874B_34691D972256__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScreenProtectApp:
// See ScreenProtect.cpp for the implementation of this class
//

class CScreenProtectApp : public CWinApp
{
public:
	CScreenProtectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenProtectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScreenProtectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENPROTECT_H__86A26592_BB2B_4508_874B_34691D972256__INCLUDED_)
