// FilmMoveView.h : main header file for the FILMMOVEVIEW application
//

#if !defined(AFX_FILMMOVEVIEW_H__E0B027EB_D09C_423B_870E_29BE3725A170__INCLUDED_)
#define AFX_FILMMOVEVIEW_H__E0B027EB_D09C_423B_870E_29BE3725A170__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewApp:
// See FilmMoveView.cpp for the implementation of this class
//

class CFilmMoveViewApp : public CWinApp
{
public:
	CFilmMoveViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilmMoveViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFilmMoveViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILMMOVEVIEW_H__E0B027EB_D09C_423B_870E_29BE3725A170__INCLUDED_)
