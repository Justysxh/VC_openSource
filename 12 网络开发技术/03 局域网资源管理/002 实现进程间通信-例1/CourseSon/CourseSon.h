// CourseSon.h : main header file for the COURSESON application
//

#if !defined(AFX_COURSESON_H__3BB59DA8_637E_481B_B855_051FAC3A530E__INCLUDED_)
#define AFX_COURSESON_H__3BB59DA8_637E_481B_B855_051FAC3A530E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCourseSonApp:
// See CourseSon.cpp for the implementation of this class
//

class CCourseSonApp : public CWinApp
{
public:
	CCourseSonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseSonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCourseSonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSESON_H__3BB59DA8_637E_481B_B855_051FAC3A530E__INCLUDED_)
