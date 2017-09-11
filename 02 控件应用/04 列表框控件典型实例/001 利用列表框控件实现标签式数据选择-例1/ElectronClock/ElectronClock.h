// ElectronClock.h : main header file for the ELECTRONCLOCK application
//

#if !defined(AFX_ELECTRONCLOCK_H__87DF7F7A_6AB1_42A9_8997_2672F5DFBFAB__INCLUDED_)
#define AFX_ELECTRONCLOCK_H__87DF7F7A_6AB1_42A9_8997_2672F5DFBFAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CElectronClockApp:
// See ElectronClock.cpp for the implementation of this class
//

class CElectronClockApp : public CWinApp
{
public:
	CElectronClockApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElectronClockApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CElectronClockApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELECTRONCLOCK_H__87DF7F7A_6AB1_42A9_8997_2672F5DFBFAB__INCLUDED_)
