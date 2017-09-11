// TabCtrl.h : main header file for the TABCTRL application
//

#if !defined(AFX_TABCTRL_H__16534289_EF30_495A_B689_85676658E743__INCLUDED_)
#define AFX_TABCTRL_H__16534289_EF30_495A_B689_85676658E743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTabCtrlApp:
// See TabCtrl.cpp for the implementation of this class
//

class CTabCtrlApp : public CWinApp
{
public:
	CTabCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTabCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABCTRL_H__16534289_EF30_495A_B689_85676658E743__INCLUDED_)
