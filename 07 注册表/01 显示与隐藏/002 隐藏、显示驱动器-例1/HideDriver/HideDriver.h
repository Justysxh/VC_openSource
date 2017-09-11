// HideDriver.h : main header file for the HIDEDRIVER application
//

#if !defined(AFX_HIDEDRIVER_H__877FA91D_4AF6_4486_A63F_17FA97F5AD58__INCLUDED_)
#define AFX_HIDEDRIVER_H__877FA91D_4AF6_4486_A63F_17FA97F5AD58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHideDriverApp:
// See HideDriver.cpp for the implementation of this class
//

class CHideDriverApp : public CWinApp
{
public:
	CHideDriverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideDriverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHideDriverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDEDRIVER_H__877FA91D_4AF6_4486_A63F_17FA97F5AD58__INCLUDED_)
