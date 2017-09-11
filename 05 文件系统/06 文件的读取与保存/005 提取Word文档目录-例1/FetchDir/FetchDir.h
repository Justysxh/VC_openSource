// FetchDir.h : main header file for the FETCHDIR application
//

#if !defined(AFX_FETCHDIR_H__C7DA064D_023A_40EF_B7DA_BBAF68DE9934__INCLUDED_)
#define AFX_FETCHDIR_H__C7DA064D_023A_40EF_B7DA_BBAF68DE9934__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFetchDirApp:
// See FetchDir.cpp for the implementation of this class
//

class CFetchDirApp : public CWinApp
{
public:
	CFetchDirApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchDirApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFetchDirApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHDIR_H__C7DA064D_023A_40EF_B7DA_BBAF68DE9934__INCLUDED_)
