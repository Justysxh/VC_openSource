// StartAutoRun.h : main header file for the STARTAUTORUN application
//

#if !defined(AFX_STARTAUTORUN_H__2B733257_A7A0_4059_96C3_B9CE7368EFB6__INCLUDED_)
#define AFX_STARTAUTORUN_H__2B733257_A7A0_4059_96C3_B9CE7368EFB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStartAutoRunApp:
// See StartAutoRun.cpp for the implementation of this class
//

class CStartAutoRunApp : public CWinApp
{
public:
	CStartAutoRunApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartAutoRunApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStartAutoRunApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTAUTORUN_H__2B733257_A7A0_4059_96C3_B9CE7368EFB6__INCLUDED_)
