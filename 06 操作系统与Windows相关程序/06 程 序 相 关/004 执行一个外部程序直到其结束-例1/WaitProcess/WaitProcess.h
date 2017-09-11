// WaitProcess.h : main header file for the WAITPROCESS application
//

#if !defined(AFX_WAITPROCESS_H__A374CCB0_573B_47D9_A8E9_7EE1FBCEC7F9__INCLUDED_)
#define AFX_WAITPROCESS_H__A374CCB0_573B_47D9_A8E9_7EE1FBCEC7F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWaitProcessApp:
// See WaitProcess.cpp for the implementation of this class
//

class CWaitProcessApp : public CWinApp
{
public:
	CWaitProcessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaitProcessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWaitProcessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAITPROCESS_H__A374CCB0_573B_47D9_A8E9_7EE1FBCEC7F9__INCLUDED_)
