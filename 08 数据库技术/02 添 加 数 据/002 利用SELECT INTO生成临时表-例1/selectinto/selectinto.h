// selectinto.h : main header file for the SELECTINTO application
//

#if !defined(AFX_SELECTINTO_H__AFD0316E_2D14_4F6F_BB59_6303F5A99041__INCLUDED_)
#define AFX_SELECTINTO_H__AFD0316E_2D14_4F6F_BB59_6303F5A99041__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSelectintoApp:
// See selectinto.cpp for the implementation of this class
//

class CSelectintoApp : public CWinApp
{
public:
	CSelectintoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectintoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSelectintoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTINTO_H__AFD0316E_2D14_4F6F_BB59_6303F5A99041__INCLUDED_)
