// PeculiarMenu.h : main header file for the PECULIARMENU application
//

#if !defined(AFX_PECULIARMENU_H__95369BB3_2A69_4104_BF3B_ACC307E08BEF__INCLUDED_)
#define AFX_PECULIARMENU_H__95369BB3_2A69_4104_BF3B_ACC307E08BEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPeculiarMenuApp:
// See PeculiarMenu.cpp for the implementation of this class
//

class CPeculiarMenuApp : public CWinApp
{
public:
	CPeculiarMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPeculiarMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPeculiarMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PECULIARMENU_H__95369BB3_2A69_4104_BF3B_ACC307E08BEF__INCLUDED_)
