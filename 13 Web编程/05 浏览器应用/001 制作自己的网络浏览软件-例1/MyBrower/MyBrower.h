// MyBrower.h : main header file for the MYBROWER application
//

#if !defined(AFX_MYBROWER_H__A8CE0F44_25D9_4DDE_B9D6_94FA29281C34__INCLUDED_)
#define AFX_MYBROWER_H__A8CE0F44_25D9_4DDE_B9D6_94FA29281C34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyBrowerApp:
// See MyBrower.cpp for the implementation of this class
//

class CMyBrowerApp : public CWinApp
{
public:
	CMyBrowerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyBrowerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyBrowerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBROWER_H__A8CE0F44_25D9_4DDE_B9D6_94FA29281C34__INCLUDED_)
