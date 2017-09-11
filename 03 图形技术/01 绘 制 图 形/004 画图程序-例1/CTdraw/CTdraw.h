// CTdraw.h : main header file for the CTDRAW application
//

#if !defined(AFX_CTDRAW_H__08C0B98F_1926_43C5_8A27_C92FB0B26B6F__INCLUDED_)
#define AFX_CTDRAW_H__08C0B98F_1926_43C5_8A27_C92FB0B26B6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCTdrawApp:
// See CTdraw.cpp for the implementation of this class
//

class CCTdrawApp : public CWinApp
{
public:
	CCTdrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTdrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCTdrawApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTDRAW_H__08C0B98F_1926_43C5_8A27_C92FB0B26B6F__INCLUDED_)
