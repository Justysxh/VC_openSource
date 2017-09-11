// ConfigINI.h : main header file for the CONFIGINI application
//

#if !defined(AFX_CONFIGINI_H__420EEFF0_D268_42D3_BECD_7C4566DE3127__INCLUDED_)
#define AFX_CONFIGINI_H__420EEFF0_D268_42D3_BECD_7C4566DE3127__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CConfigINIApp:
// See ConfigINI.cpp for the implementation of this class
//

class CConfigINIApp : public CWinApp
{
public:
	CConfigINIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigINIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CConfigINIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIGINI_H__420EEFF0_D268_42D3_BECD_7C4566DE3127__INCLUDED_)
