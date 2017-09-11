// RenameFile.h : main header file for the RENAMEFILE application
//

#if !defined(AFX_RENAMEFILE_H__E91A0AD3_AC66_4352_AD7B_40C7EDA4B0F2__INCLUDED_)
#define AFX_RENAMEFILE_H__E91A0AD3_AC66_4352_AD7B_40C7EDA4B0F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRenameFileApp:
// See RenameFile.cpp for the implementation of this class
//

class CRenameFileApp : public CWinApp
{
public:
	CRenameFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRenameFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRenameFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RENAMEFILE_H__E91A0AD3_AC66_4352_AD7B_40C7EDA4B0F2__INCLUDED_)
