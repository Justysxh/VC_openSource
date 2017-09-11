// testDll.h : main header file for the TESTDLL application
//

#if !defined(AFX_TESTDLL_H__39C889DA_ABAE_49DC_9030_47E50468FC2C__INCLUDED_)
#define AFX_TESTDLL_H__39C889DA_ABAE_49DC_9030_47E50468FC2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestDllApp:
// See testDll.cpp for the implementation of this class
//

class CTestDllApp : public CWinApp
{
public:
	CTestDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDllApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLL_H__39C889DA_ABAE_49DC_9030_47E50468FC2C__INCLUDED_)
