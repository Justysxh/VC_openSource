// Course.h : main header file for the COURSE application
//

#if !defined(AFX_COURSE_H__CACA11C3_5CB1_4C15_BE3B_EC8A70216CF3__INCLUDED_)
#define AFX_COURSE_H__CACA11C3_5CB1_4C15_BE3B_EC8A70216CF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCourseApp:
// See Course.cpp for the implementation of this class
//

class CCourseApp : public CWinApp
{
public:
	CCourseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCourseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSE_H__CACA11C3_5CB1_4C15_BE3B_EC8A70216CF3__INCLUDED_)
