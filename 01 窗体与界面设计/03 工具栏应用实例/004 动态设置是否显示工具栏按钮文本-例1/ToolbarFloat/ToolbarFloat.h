// ToolbarFloat.h : main header file for the TOOLBARFLOAT application
//

#if !defined(AFX_TOOLBARFLOAT_H__D4999FE4_BD3C_4FA5_BAED_D93BD49B7A25__INCLUDED_)
#define AFX_TOOLBARFLOAT_H__D4999FE4_BD3C_4FA5_BAED_D93BD49B7A25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatApp:
// See ToolbarFloat.cpp for the implementation of this class
//

class CToolbarFloatApp : public CWinApp
{
public:
	CToolbarFloatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbarFloatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CToolbarFloatApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARFLOAT_H__D4999FE4_BD3C_4FA5_BAED_D93BD49B7A25__INCLUDED_)
