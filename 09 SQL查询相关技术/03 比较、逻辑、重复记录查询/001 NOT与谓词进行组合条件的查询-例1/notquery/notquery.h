// notquery.h : main header file for the NOTQUERY application
//

#if !defined(AFX_NOTQUERY_H__1901AFEE_908F_4734_87AA_BD6BF08808DD__INCLUDED_)
#define AFX_NOTQUERY_H__1901AFEE_908F_4734_87AA_BD6BF08808DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNotqueryApp:
// See notquery.cpp for the implementation of this class
//

class CNotqueryApp : public CWinApp
{
public:
	CNotqueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotqueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNotqueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTQUERY_H__1901AFEE_908F_4734_87AA_BD6BF08808DD__INCLUDED_)
