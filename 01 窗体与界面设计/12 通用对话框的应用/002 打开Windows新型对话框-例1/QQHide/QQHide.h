// QQHide.h : main header file for the QQHIDE application
//

#if !defined(AFX_QQHIDE_H__E723769D_56F7_4DB9_82DF_7F83FE385F70__INCLUDED_)
#define AFX_QQHIDE_H__E723769D_56F7_4DB9_82DF_7F83FE385F70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQQHideApp:
// See QQHide.cpp for the implementation of this class
//

class CQQHideApp : public CWinApp
{
public:
	CQQHideApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQHideApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQQHideApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQHIDE_H__E723769D_56F7_4DB9_82DF_7F83FE385F70__INCLUDED_)
