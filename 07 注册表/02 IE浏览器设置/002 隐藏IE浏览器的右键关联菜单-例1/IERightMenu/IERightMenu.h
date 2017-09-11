// IERightMenu.h : main header file for the IERIGHTMENU application
//

#if !defined(AFX_IERIGHTMENU_H__8912C96A_6A16_46D4_8FA5_C96E9B285FEC__INCLUDED_)
#define AFX_IERIGHTMENU_H__8912C96A_6A16_46D4_8FA5_C96E9B285FEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIERightMenuApp:
// See IERightMenu.cpp for the implementation of this class
//

class CIERightMenuApp : public CWinApp
{
public:
	CIERightMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIERightMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIERightMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IERIGHTMENU_H__8912C96A_6A16_46D4_8FA5_C96E9B285FEC__INCLUDED_)
