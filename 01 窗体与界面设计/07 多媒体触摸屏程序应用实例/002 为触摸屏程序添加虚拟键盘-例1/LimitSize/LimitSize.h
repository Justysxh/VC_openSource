// LimitSize.h : main header file for the LIMITSIZE application
//

#if !defined(AFX_LIMITSIZE_H__BDFF6E0A_1D9E_489A_A9E3_34E9C9F3531E__INCLUDED_)
#define AFX_LIMITSIZE_H__BDFF6E0A_1D9E_489A_A9E3_34E9C9F3531E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLimitSizeApp:
// See LimitSize.cpp for the implementation of this class
//

class CLimitSizeApp : public CWinApp
{
public:
	CLimitSizeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLimitSizeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLimitSizeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIMITSIZE_H__BDFF6E0A_1D9E_489A_A9E3_34E9C9F3531E__INCLUDED_)
