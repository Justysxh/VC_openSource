// mohuquery.h : main header file for the MOHUQUERY application
//

#if !defined(AFX_MOHUQUERY_H__8C2FBD1F_8B6E_42CD_85E7_DEF8D4F9764B__INCLUDED_)
#define AFX_MOHUQUERY_H__8C2FBD1F_8B6E_42CD_85E7_DEF8D4F9764B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMohuqueryApp:
// See mohuquery.cpp for the implementation of this class
//

class CMohuqueryApp : public CWinApp
{
public:
	CMohuqueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMohuqueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMohuqueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOHUQUERY_H__8C2FBD1F_8B6E_42CD_85E7_DEF8D4F9764B__INCLUDED_)
