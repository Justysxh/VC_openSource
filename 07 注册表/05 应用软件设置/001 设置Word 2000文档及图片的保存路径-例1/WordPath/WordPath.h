// WordPath.h : main header file for the WORDPATH application
//

#if !defined(AFX_WORDPATH_H__60BEFB36_DF6D_4AC7_AC31_708FBADE5470__INCLUDED_)
#define AFX_WORDPATH_H__60BEFB36_DF6D_4AC7_AC31_708FBADE5470__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWordPathApp:
// See WordPath.cpp for the implementation of this class
//

class CWordPathApp : public CWinApp
{
public:
	CWordPathApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordPathApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWordPathApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDPATH_H__60BEFB36_DF6D_4AC7_AC31_708FBADE5470__INCLUDED_)
