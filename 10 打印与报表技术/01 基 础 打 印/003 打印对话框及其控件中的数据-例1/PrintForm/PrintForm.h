// PrintForm.h : main header file for the PRINTFORM application
//

#if !defined(AFX_PRINTFORM_H__E13269D9_62BC_422C_B60E_4AF0330F2E07__INCLUDED_)
#define AFX_PRINTFORM_H__E13269D9_62BC_422C_B60E_4AF0330F2E07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintFormApp:
// See PrintForm.cpp for the implementation of this class
//

class CPrintFormApp : public CWinApp
{
public:
	CPrintFormApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintFormApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrintFormApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTFORM_H__E13269D9_62BC_422C_B60E_4AF0330F2E07__INCLUDED_)
