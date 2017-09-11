// COUNTquery.h : main header file for the COUNTQUERY application
//

#if !defined(AFX_COUNTQUERY_H__608AC628_0BFB_41EB_A274_90E71B6D8C25__INCLUDED_)
#define AFX_COUNTQUERY_H__608AC628_0BFB_41EB_A274_90E71B6D8C25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCOUNTqueryApp:
// See COUNTquery.cpp for the implementation of this class
//

class CCOUNTqueryApp : public CWinApp
{
public:
	CCOUNTqueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCOUNTqueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCOUNTqueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COUNTQUERY_H__608AC628_0BFB_41EB_A274_90E71B6D8C25__INCLUDED_)
