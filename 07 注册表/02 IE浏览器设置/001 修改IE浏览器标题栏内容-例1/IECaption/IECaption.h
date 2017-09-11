// IECaption.h : main header file for the IECAPTION application
//

#if !defined(AFX_IECAPTION_H__E0DC1DBB_48F3_4F65_A4D0_EA57B23E95E6__INCLUDED_)
#define AFX_IECAPTION_H__E0DC1DBB_48F3_4F65_A4D0_EA57B23E95E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIECaptionApp:
// See IECaption.cpp for the implementation of this class
//

class CIECaptionApp : public CWinApp
{
public:
	CIECaptionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIECaptionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIECaptionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IECAPTION_H__E0DC1DBB_48F3_4F65_A4D0_EA57B23E95E6__INCLUDED_)
