// zdsjdquery.h : main header file for the ZDSJDQUERY application
//

#if !defined(AFX_ZDSJDQUERY_H__CBD49A3C_2CA1_41CF_A720_F9B1A1C183B6__INCLUDED_)
#define AFX_ZDSJDQUERY_H__CBD49A3C_2CA1_41CF_A720_F9B1A1C183B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CZdsjdqueryApp:
// See zdsjdquery.cpp for the implementation of this class
//

class CZdsjdqueryApp : public CWinApp
{
public:
	CZdsjdqueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZdsjdqueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZdsjdqueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZDSJDQUERY_H__CBD49A3C_2CA1_41CF_A720_F9B1A1C183B6__INCLUDED_)
