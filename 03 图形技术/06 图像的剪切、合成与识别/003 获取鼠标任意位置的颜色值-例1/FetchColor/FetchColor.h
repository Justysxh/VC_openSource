// FetchColor.h : main header file for the FETCHCOLOR application
//

#if !defined(AFX_FETCHCOLOR_H__BD3C7F64_2EFA_4033_BB67_B4298E50CE16__INCLUDED_)
#define AFX_FETCHCOLOR_H__BD3C7F64_2EFA_4033_BB67_B4298E50CE16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFetchColorApp:
// See FetchColor.cpp for the implementation of this class
//

class CFetchColorApp : public CWinApp
{
public:
	CFetchColorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchColorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFetchColorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHCOLOR_H__BD3C7F64_2EFA_4033_BB67_B4298E50CE16__INCLUDED_)
