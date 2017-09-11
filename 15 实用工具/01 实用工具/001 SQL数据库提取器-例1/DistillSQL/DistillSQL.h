// DistillSQL.h : main header file for the DISTILLSQL application
//

#if !defined(AFX_DISTILLSQL_H__C93D0640_13C4_4A93_BE9C_AE29915A7A3F__INCLUDED_)
#define AFX_DISTILLSQL_H__C93D0640_13C4_4A93_BE9C_AE29915A7A3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDistillSQLApp:
// See DistillSQL.cpp for the implementation of this class
//

class CDistillSQLApp : public CWinApp
{
public:
	CDistillSQLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDistillSQLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDistillSQLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISTILLSQL_H__C93D0640_13C4_4A93_BE9C_AE29915A7A3F__INCLUDED_)
