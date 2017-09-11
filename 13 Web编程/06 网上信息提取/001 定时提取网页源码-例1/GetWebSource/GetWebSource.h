// GetWebSource.h : main header file for the GETWEBSOURCE application
//

#if !defined(AFX_GETWEBSOURCE_H__F89D7D90_A2C7_4BEA_A1CC_C5F4BB248E7C__INCLUDED_)
#define AFX_GETWEBSOURCE_H__F89D7D90_A2C7_4BEA_A1CC_C5F4BB248E7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetWebSourceApp:
// See GetWebSource.cpp for the implementation of this class
//

class CGetWebSourceApp : public CWinApp
{
public:
	CGetWebSourceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetWebSourceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetWebSourceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETWEBSOURCE_H__F89D7D90_A2C7_4BEA_A1CC_C5F4BB248E7C__INCLUDED_)
