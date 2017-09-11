// AVGquery.h : main header file for the AVGQUERY application
//

#if !defined(AFX_AVGQUERY_H__B829707E_75A6_4C95_9D2E_F9541E14A3EB__INCLUDED_)
#define AFX_AVGQUERY_H__B829707E_75A6_4C95_9D2E_F9541E14A3EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAVGqueryApp:
// See AVGquery.cpp for the implementation of this class
//

class CAVGqueryApp : public CWinApp
{
public:
	CAVGqueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVGqueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAVGqueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVGQUERY_H__B829707E_75A6_4C95_9D2E_F9541E14A3EB__INCLUDED_)
