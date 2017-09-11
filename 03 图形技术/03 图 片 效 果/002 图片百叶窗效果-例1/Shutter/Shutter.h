// Shutter.h : main header file for the SHUTTER application
//

#if !defined(AFX_SHUTTER_H__3CFBCC86_603F_4125_9091_FE2028C12C1F__INCLUDED_)
#define AFX_SHUTTER_H__3CFBCC86_603F_4125_9091_FE2028C12C1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShutterApp:
// See Shutter.cpp for the implementation of this class
//

class CShutterApp : public CWinApp
{
public:
	CShutterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShutterApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTTER_H__3CFBCC86_603F_4125_9091_FE2028C12C1F__INCLUDED_)
