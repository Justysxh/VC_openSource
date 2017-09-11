// IconMenu.h : main header file for the ICONMENU application
//

#if !defined(AFX_ICONMENU_H__33500928_4C0D_4F49_BAE1_CEA4E8B2E936__INCLUDED_)
#define AFX_ICONMENU_H__33500928_4C0D_4F49_BAE1_CEA4E8B2E936__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CIconMenuApp:
// See IconMenu.cpp for the implementation of this class
//

class CIconMenuApp : public CWinApp
{
public:
	CIconMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CIconMenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONMENU_H__33500928_4C0D_4F49_BAE1_CEA4E8B2E936__INCLUDED_)
