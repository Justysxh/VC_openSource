// bxscfjl.h : main header file for the BXSCFJL application
//

#if !defined(AFX_BXSCFJL_H__806BEEEB_DCD4_4108_8B73_CB7CA364A601__INCLUDED_)
#define AFX_BXSCFJL_H__806BEEEB_DCD4_4108_8B73_CB7CA364A601__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBxscfjlApp:
// See bxscfjl.cpp for the implementation of this class
//

class CBxscfjlApp : public CWinApp
{
public:
	CBxscfjlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBxscfjlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBxscfjlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BXSCFJL_H__806BEEEB_DCD4_4108_8B73_CB7CA364A601__INCLUDED_)
