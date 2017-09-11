// Monthquery.h : main header file for the MONTHQUERY application
//

#if !defined(AFX_MONTHQUERY_H__BD2335CA_56B5_47B9_8F94_8CB8E6CC35E3__INCLUDED_)
#define AFX_MONTHQUERY_H__BD2335CA_56B5_47B9_8F94_8CB8E6CC35E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMonthqueryApp:
// See Monthquery.cpp for the implementation of this class
//

class CMonthqueryApp : public CWinApp
{
public:
	CMonthqueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonthqueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMonthqueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONTHQUERY_H__BD2335CA_56B5_47B9_8F94_8CB8E6CC35E3__INCLUDED_)
