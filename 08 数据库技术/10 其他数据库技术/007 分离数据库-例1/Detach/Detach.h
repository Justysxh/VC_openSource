// Detach.h : main header file for the DETACH application
//

#if !defined(AFX_DETACH_H__AEA0D107_B65C_4AFF_8889_3A10DD40D766__INCLUDED_)
#define AFX_DETACH_H__AEA0D107_B65C_4AFF_8889_3A10DD40D766__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDetachApp:
// See Detach.cpp for the implementation of this class
//

class CDetachApp : public CWinApp
{
public:
	CDetachApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDetachApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDetachApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETACH_H__AEA0D107_B65C_4AFF_8889_3A10DD40D766__INCLUDED_)
