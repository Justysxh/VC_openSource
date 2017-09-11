// updateempty.h : main header file for the UPDATEEMPTY application
//

#if !defined(AFX_UPDATEEMPTY_H__E825E1B5_AD8C_41B3_BC46_67A811A9CF24__INCLUDED_)
#define AFX_UPDATEEMPTY_H__E825E1B5_AD8C_41B3_BC46_67A811A9CF24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUpdateemptyApp:
// See updateempty.cpp for the implementation of this class
//

class CUpdateemptyApp : public CWinApp
{
public:
	CUpdateemptyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdateemptyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUpdateemptyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATEEMPTY_H__E825E1B5_AD8C_41B3_BC46_67A811A9CF24__INCLUDED_)
