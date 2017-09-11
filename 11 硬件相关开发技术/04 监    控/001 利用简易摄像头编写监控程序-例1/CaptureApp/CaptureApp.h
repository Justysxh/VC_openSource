// CaptureApp.h : main header file for the CAPTUREAPP application
//

#if !defined(AFX_CAPTUREAPP_H__401A3E96_D0AF_4A0D_B116_F1F2C397B954__INCLUDED_)
#define AFX_CAPTUREAPP_H__401A3E96_D0AF_4A0D_B116_F1F2C397B954__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCaptureAppApp:
// See CaptureApp.cpp for the implementation of this class
//

class CCaptureAppApp : public CWinApp
{
public:
	CCaptureAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptureAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCaptureAppApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTUREAPP_H__401A3E96_D0AF_4A0D_B116_F1F2C397B954__INCLUDED_)
