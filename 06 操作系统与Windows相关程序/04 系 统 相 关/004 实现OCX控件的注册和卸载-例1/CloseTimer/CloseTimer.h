// CloseTimer.h : main header file for the CLOSETIMER application
//

#if !defined(AFX_CLOSETIMER_H__09FA44B2_2B46_45C9_B9EF_97793692E5E7__INCLUDED_)
#define AFX_CLOSETIMER_H__09FA44B2_2B46_45C9_B9EF_97793692E5E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCloseTimerApp:
// See CloseTimer.cpp for the implementation of this class
//

class CCloseTimerApp : public CWinApp
{
public:
	CCloseTimerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCloseTimerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCloseTimerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOSETIMER_H__09FA44B2_2B46_45C9_B9EF_97793692E5E7__INCLUDED_)
