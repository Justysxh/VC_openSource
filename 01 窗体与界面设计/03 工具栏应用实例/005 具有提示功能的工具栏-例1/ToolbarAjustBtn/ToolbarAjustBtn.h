// ToolbarAjustBtn.h : main header file for the TOOLBARAJUSTBTN application
//

#if !defined(AFX_TOOLBARAJUSTBTN_H__D90B16D5_2287_487A_A34F_3B6A8ECC38D5__INCLUDED_)
#define AFX_TOOLBARAJUSTBTN_H__D90B16D5_2287_487A_A34F_3B6A8ECC38D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnApp:
// See ToolbarAjustBtn.cpp for the implementation of this class
//

class CToolbarAjustBtnApp : public CWinApp
{
public:
	CToolbarAjustBtnApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbarAjustBtnApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CToolbarAjustBtnApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARAJUSTBTN_H__D90B16D5_2287_487A_A34F_3B6A8ECC38D5__INCLUDED_)
