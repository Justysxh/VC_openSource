// ShowJPG.h : main header file for the SHOWJPG application
//

#if !defined(AFX_SHOWJPG_H__6ECEF7F2_FD9B_40B3_930A_4AEE0B97FF1A__INCLUDED_)
#define AFX_SHOWJPG_H__6ECEF7F2_FD9B_40B3_930A_4AEE0B97FF1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowJPGApp:
// See ShowJPG.cpp for the implementation of this class
//

class CShowJPGApp : public CWinApp
{
public:
	CShowJPGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowJPGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShowJPGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWJPG_H__6ECEF7F2_FD9B_40B3_930A_4AEE0B97FF1A__INCLUDED_)
