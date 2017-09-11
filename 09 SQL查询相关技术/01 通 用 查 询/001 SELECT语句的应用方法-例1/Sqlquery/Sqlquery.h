// Sqlquery.h : main header file for the SQLQUERY application
//

#if !defined(AFX_SQLQUERY_H__55246554_E538_4D70_B8DE_7B47D25731A8__INCLUDED_)
#define AFX_SQLQUERY_H__55246554_E538_4D70_B8DE_7B47D25731A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSqlqueryApp:
// See Sqlquery.cpp for the implementation of this class
//

class CSqlqueryApp : public CWinApp
{
public:
	CSqlqueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSqlqueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSqlqueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQLQUERY_H__55246554_E538_4D70_B8DE_7B47D25731A8__INCLUDED_)
