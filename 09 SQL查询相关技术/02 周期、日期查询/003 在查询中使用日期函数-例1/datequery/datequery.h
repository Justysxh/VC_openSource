// datequery.h : main header file for the DATEQUERY application
//

#if !defined(AFX_DATEQUERY_H__C2493F7B_1330_4A75_B4F4_50F3C4490E43__INCLUDED_)
#define AFX_DATEQUERY_H__C2493F7B_1330_4A75_B4F4_50F3C4490E43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDatequeryApp:
// See datequery.cpp for the implementation of this class
//

class CDatequeryApp : public CWinApp
{
public:
	CDatequeryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatequeryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDatequeryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATEQUERY_H__C2493F7B_1330_4A75_B4F4_50F3C4490E43__INCLUDED_)
