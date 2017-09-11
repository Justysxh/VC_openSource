// CreateIniMenu.h : main header file for the CREATEINIMENU application
//

#if !defined(AFX_CREATEINIMENU_H__0483EB09_7F3B_418F_8E7E_711CD7A10F55__INCLUDED_)
#define AFX_CREATEINIMENU_H__0483EB09_7F3B_418F_8E7E_711CD7A10F55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateIniMenuApp:
// See CreateIniMenu.cpp for the implementation of this class
//

class CCreateIniMenuApp : public CWinApp
{
public:
	CCreateIniMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateIniMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateIniMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEINIMENU_H__0483EB09_7F3B_418F_8E7E_711CD7A10F55__INCLUDED_)
