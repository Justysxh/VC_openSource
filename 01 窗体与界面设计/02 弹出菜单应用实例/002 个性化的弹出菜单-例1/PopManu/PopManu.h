// PopManu.h : main header file for the POPMANU application
//

#if !defined(AFX_POPMANU_H__EF5B480B_0B6A_4527_9716_2B4629649C96__INCLUDED_)
#define AFX_POPMANU_H__EF5B480B_0B6A_4527_9716_2B4629649C96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPopManuApp:
// See PopManu.cpp for the implementation of this class
//

class CPopManuApp : public CWinApp
{
public:
	CPopManuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopManuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPopManuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPMANU_H__EF5B480B_0B6A_4527_9716_2B4629649C96__INCLUDED_)
