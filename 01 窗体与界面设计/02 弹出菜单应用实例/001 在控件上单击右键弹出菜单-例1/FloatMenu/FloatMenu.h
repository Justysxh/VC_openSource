// FloatMenu.h : main header file for the FLOATMENU application
//

#if !defined(AFX_FLOATMENU_H__EC8FBDE6_7371_47A4_ACE5_EB2D0603C401__INCLUDED_)
#define AFX_FLOATMENU_H__EC8FBDE6_7371_47A4_ACE5_EB2D0603C401__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuApp:
// See FloatMenu.cpp for the implementation of this class
//

class CFloatMenuApp : public CWinApp
{
public:
	CFloatMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFloatMenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATMENU_H__EC8FBDE6_7371_47A4_ACE5_EB2D0603C401__INCLUDED_)
