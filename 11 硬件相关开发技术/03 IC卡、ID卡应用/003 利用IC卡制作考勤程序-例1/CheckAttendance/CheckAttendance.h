// CheckAttendance.h : main header file for the CHECKATTENDANCE application
//

#if !defined(AFX_CHECKATTENDANCE_H__5C127637_5F71_49C3_8C04_BEC00D7C7A92__INCLUDED_)
#define AFX_CHECKATTENDANCE_H__5C127637_5F71_49C3_8C04_BEC00D7C7A92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCheckAttendanceApp:
// See CheckAttendance.cpp for the implementation of this class
//

class CCheckAttendanceApp : public CWinApp
{
public:
	CCheckAttendanceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckAttendanceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCheckAttendanceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKATTENDANCE_H__5C127637_5F71_49C3_8C04_BEC00D7C7A92__INCLUDED_)
