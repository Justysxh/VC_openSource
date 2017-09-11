// Overtime.h : main header file for the OVERTIME application
//

#if !defined(AFX_OVERTIME_H__796C894E_490A_4F5B_88E7_3960E7BCFE1D__INCLUDED_)
#define AFX_OVERTIME_H__796C894E_490A_4F5B_88E7_3960E7BCFE1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COvertimeApp:
// See Overtime.cpp for the implementation of this class
//

class COvertimeApp : public CWinApp
{
public:
	COvertimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COvertimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COvertimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OVERTIME_H__796C894E_490A_4F5B_88E7_3960E7BCFE1D__INCLUDED_)
