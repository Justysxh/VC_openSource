// HuodeDK.h : main header file for the HUODEDK application
//

#if !defined(AFX_HUODEDK_H__AFD884E9_86C7_432A_ABDC_6DF069F437C5__INCLUDED_)
#define AFX_HUODEDK_H__AFD884E9_86C7_432A_ABDC_6DF069F437C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHuodeDKApp:
// See HuodeDK.cpp for the implementation of this class
//

class CHuodeDKApp : public CWinApp
{
public:
	CHuodeDKApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuodeDKApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHuodeDKApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUODEDK_H__AFD884E9_86C7_432A_ABDC_6DF069F437C5__INCLUDED_)
