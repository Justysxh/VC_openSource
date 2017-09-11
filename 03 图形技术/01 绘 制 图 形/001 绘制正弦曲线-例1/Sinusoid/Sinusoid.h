// Sinusoid.h : main header file for the SINUSOID application
//

#if !defined(AFX_SINUSOID_H__5EBC3622_307E_4BE6_A1E4_CE04CEF8E763__INCLUDED_)
#define AFX_SINUSOID_H__5EBC3622_307E_4BE6_A1E4_CE04CEF8E763__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSinusoidApp:
// See Sinusoid.cpp for the implementation of this class
//

class CSinusoidApp : public CWinApp
{
public:
	CSinusoidApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinusoidApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSinusoidApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINUSOID_H__5EBC3622_307E_4BE6_A1E4_CE04CEF8E763__INCLUDED_)
