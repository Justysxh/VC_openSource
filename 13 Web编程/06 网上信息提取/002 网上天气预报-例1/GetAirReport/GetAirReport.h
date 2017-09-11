// GetAirReport.h : main header file for the GETAIRREPORT application
//

#if !defined(AFX_GETAIRREPORT_H__CE929E15_A119_4258_AE9E_99817C0DBC12__INCLUDED_)
#define AFX_GETAIRREPORT_H__CE929E15_A119_4258_AE9E_99817C0DBC12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetAirReportApp:
// See GetAirReport.cpp for the implementation of this class
//

class CGetAirReportApp : public CWinApp
{
public:
	CGetAirReportApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetAirReportApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetAirReportApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETAIRREPORT_H__CE929E15_A119_4258_AE9E_99817C0DBC12__INCLUDED_)
