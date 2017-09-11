// Report.h : main header file for the REPORT application
//

#if !defined(AFX_REPORT_H__5A65AFC6_685C_4CAE_BC3F_40E777FD1863__INCLUDED_)
#define AFX_REPORT_H__5A65AFC6_685C_4CAE_BC3F_40E777FD1863__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReportApp:
// See Report.cpp for the implementation of this class
//

class CReportApp : public CWinApp
{
public:
	CReportApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReportApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReportApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPORT_H__5A65AFC6_685C_4CAE_BC3F_40E777FD1863__INCLUDED_)
