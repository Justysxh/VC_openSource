// ODBCDSN.h : main header file for the ODBCDSN application
//

#if !defined(AFX_ODBCDSN_H__ABC84D73_D27A_4FDA_AA04_3816CFB992E2__INCLUDED_)
#define AFX_ODBCDSN_H__ABC84D73_D27A_4FDA_AA04_3816CFB992E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CODBCDSNApp:
// See ODBCDSN.cpp for the implementation of this class
//

class CODBCDSNApp : public CWinApp
{
public:
	CODBCDSNApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDSNApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CODBCDSNApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDSN_H__ABC84D73_D27A_4FDA_AA04_3816CFB992E2__INCLUDED_)
