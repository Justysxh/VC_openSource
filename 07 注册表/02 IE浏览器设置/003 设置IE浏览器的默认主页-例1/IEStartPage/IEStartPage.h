// IEStartPage.h : main header file for the IESTARTPAGE application
//

#if !defined(AFX_IESTARTPAGE_H__F288224B_8C60_4974_8055_3D551DE30F26__INCLUDED_)
#define AFX_IESTARTPAGE_H__F288224B_8C60_4974_8055_3D551DE30F26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIEStartPageApp:
// See IEStartPage.cpp for the implementation of this class
//

class CIEStartPageApp : public CWinApp
{
public:
	CIEStartPageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIEStartPageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIEStartPageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IESTARTPAGE_H__F288224B_8C60_4974_8055_3D551DE30F26__INCLUDED_)
