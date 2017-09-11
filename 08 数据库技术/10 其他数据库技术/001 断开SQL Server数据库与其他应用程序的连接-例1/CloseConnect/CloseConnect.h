// CloseConnect.h : main header file for the CLOSECONNECT application
//

#if !defined(AFX_CLOSECONNECT_H__25CC9A6E_4AC1_4631_82C7_08C17A9D2965__INCLUDED_)
#define AFX_CLOSECONNECT_H__25CC9A6E_4AC1_4631_82C7_08C17A9D2965__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCloseConnectApp:
// See CloseConnect.cpp for the implementation of this class
//

class CCloseConnectApp : public CWinApp
{
public:
	CCloseConnectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCloseConnectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCloseConnectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOSECONNECT_H__25CC9A6E_4AC1_4631_82C7_08C17A9D2965__INCLUDED_)
