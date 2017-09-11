// savecourse.h : main header file for the SAVECOURSE application
//

#if !defined(AFX_SAVECOURSE_H__DE69B936_1F1E_45BC_B453_36936FE62560__INCLUDED_)
#define AFX_SAVECOURSE_H__DE69B936_1F1E_45BC_B453_36936FE62560__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSavecourseApp:
// See savecourse.cpp for the implementation of this class
//

class CSavecourseApp : public CWinApp
{
public:
	CSavecourseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSavecourseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSavecourseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVECOURSE_H__DE69B936_1F1E_45BC_B453_36936FE62560__INCLUDED_)
