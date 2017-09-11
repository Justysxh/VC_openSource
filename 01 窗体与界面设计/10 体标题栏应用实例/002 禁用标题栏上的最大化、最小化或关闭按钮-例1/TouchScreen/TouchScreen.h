// TouchScreen.h : main header file for the TOUCHSCREEN application
//

#if !defined(AFX_TOUCHSCREEN_H__7C734671_04DD_45CF_964D_CBB28CA97862__INCLUDED_)
#define AFX_TOUCHSCREEN_H__7C734671_04DD_45CF_964D_CBB28CA97862__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTouchScreenApp:
// See TouchScreen.cpp for the implementation of this class
//

class CTouchScreenApp : public CWinApp
{
public:
	CTouchScreenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTouchScreenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTouchScreenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOUCHSCREEN_H__7C734671_04DD_45CF_964D_CBB28CA97862__INCLUDED_)
