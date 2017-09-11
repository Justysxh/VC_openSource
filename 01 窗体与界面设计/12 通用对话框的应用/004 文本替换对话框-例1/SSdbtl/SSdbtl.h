// SSdbtl.h : main header file for the SSDBTL application
//

#if !defined(AFX_SSDBTL_H__7F93A0F7_661E_47AA_8F44_D591B7913EB1__INCLUDED_)
#define AFX_SSDBTL_H__7F93A0F7_661E_47AA_8F44_D591B7913EB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSSdbtlApp:
// See SSdbtl.cpp for the implementation of this class
//

class CSSdbtlApp : public CWinApp
{
public:
	CSSdbtlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSSdbtlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSSdbtlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSDBTL_H__7F93A0F7_661E_47AA_8F44_D591B7913EB1__INCLUDED_)
