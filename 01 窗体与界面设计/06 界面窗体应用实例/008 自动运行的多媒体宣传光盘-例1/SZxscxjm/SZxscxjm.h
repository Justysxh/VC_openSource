// SZxscxjm.h : main header file for the SZXSCXJM application
//

#if !defined(AFX_SZXSCXJM_H__6FDF9A8A_E667_41FB_85E6_83C1740C49CF__INCLUDED_)
#define AFX_SZXSCXJM_H__6FDF9A8A_E667_41FB_85E6_83C1740C49CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmApp:
// See SZxscxjm.cpp for the implementation of this class
//

class CSZxscxjmApp : public CWinApp
{
public:
	CSZxscxjmApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSZxscxjmApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSZxscxjmApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SZXSCXJM_H__6FDF9A8A_E667_41FB_85E6_83C1740C49CF__INCLUDED_)
