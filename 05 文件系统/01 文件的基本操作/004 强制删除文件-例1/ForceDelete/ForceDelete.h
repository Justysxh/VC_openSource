// ForceDelete.h : main header file for the FORCEDELETE application
//

#if !defined(AFX_FORCEDELETE_H__83D21EE9_1D51_4CBB_A835_F630E7BBE11C__INCLUDED_)
#define AFX_FORCEDELETE_H__83D21EE9_1D51_4CBB_A835_F630E7BBE11C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CForceDeleteApp:
// See ForceDelete.cpp for the implementation of this class
//

class CForceDeleteApp : public CWinApp
{
public:
	CForceDeleteApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CForceDeleteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CForceDeleteApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORCEDELETE_H__83D21EE9_1D51_4CBB_A835_F630E7BBE11C__INCLUDED_)
