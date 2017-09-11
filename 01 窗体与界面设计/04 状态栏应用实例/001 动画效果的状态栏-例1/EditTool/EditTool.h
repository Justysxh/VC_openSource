// EditTool.h : main header file for the EDITTOOL application
//

#if !defined(AFX_EDITTOOL_H__27D2C54E_0590_4550_BF3B_5B21FA9A5B67__INCLUDED_)
#define AFX_EDITTOOL_H__27D2C54E_0590_4550_BF3B_5B21FA9A5B67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEditToolApp:
// See EditTool.cpp for the implementation of this class
//

class CEditToolApp : public CWinApp
{
public:
	CEditToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEditToolApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITTOOL_H__27D2C54E_0590_4550_BF3B_5B21FA9A5B67__INCLUDED_)
