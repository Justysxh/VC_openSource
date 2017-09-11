// TreeNavi.h : main header file for the TREENAVI application
//

#if !defined(AFX_TREENAVI_H__7957768B_1922_40CB_9B38_C0253FEF34C2__INCLUDED_)
#define AFX_TREENAVI_H__7957768B_1922_40CB_9B38_C0253FEF34C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreeNaviApp:
// See TreeNavi.cpp for the implementation of this class
//

class CTreeNaviApp : public CWinApp
{
public:
	CTreeNaviApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeNaviApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTreeNaviApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREENAVI_H__7957768B_1922_40CB_9B38_C0253FEF34C2__INCLUDED_)
