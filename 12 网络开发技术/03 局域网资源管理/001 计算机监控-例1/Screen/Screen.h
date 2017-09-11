// Screen.h : main header file for the SCREEN application
//

#if !defined(AFX_SCREEN_H__1141ED47_1E96_4C04_B767_6555BE0E67B4__INCLUDED_)
#define AFX_SCREEN_H__1141ED47_1E96_4C04_B767_6555BE0E67B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScreenApp:
// See Screen.cpp for the implementation of this class
//

class CScreenApp : public CWinApp
{
public:
	CScreenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScreenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREEN_H__1141ED47_1E96_4C04_B767_6555BE0E67B4__INCLUDED_)
