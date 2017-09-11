// DocViewPrint.h : main header file for the DOCVIEWPRINT application
//

#if !defined(AFX_DOCVIEWPRINT_H__AC303160_6F74_4E00_8B35_94EC0A227CB9__INCLUDED_)
#define AFX_DOCVIEWPRINT_H__AC303160_6F74_4E00_8B35_94EC0A227CB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "MainDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintApp:
// See DocViewPrint.cpp for the implementation of this class
//

class CDocViewPrintApp : public CWinApp
{
public:
	void PrintDlg();
	CDocViewPrintApp();
	CMainDlg* tempdlg;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocViewPrintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDocViewPrintApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCVIEWPRINT_H__AC303160_6F74_4E00_8B35_94EC0A227CB9__INCLUDED_)
