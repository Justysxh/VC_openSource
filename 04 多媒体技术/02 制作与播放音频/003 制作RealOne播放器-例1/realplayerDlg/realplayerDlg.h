// realplayerDlg.h : main header file for the REALPLAYERDLG application
//

#if !defined(AFX_REALPLAYERDLG_H__F1AF1F97_2A18_40E0_A8C6_CCE06BC35C3C__INCLUDED_)
#define AFX_REALPLAYERDLG_H__F1AF1F97_2A18_40E0_A8C6_CCE06BC35C3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRealplayerDlgApp:
// See realplayerDlg.cpp for the implementation of this class
//

class CRealplayerDlgApp : public CWinApp
{
public:
	CRealplayerDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRealplayerDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRealplayerDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REALPLAYERDLG_H__F1AF1F97_2A18_40E0_A8C6_CCE06BC35C3C__INCLUDED_)
