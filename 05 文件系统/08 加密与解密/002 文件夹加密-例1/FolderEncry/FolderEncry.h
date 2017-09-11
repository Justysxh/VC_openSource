// FolderEncry.h : main header file for the FOLDERENCRY application
//

#if !defined(AFX_FOLDERENCRY_H__5AB9511A_0193_40A1_B353_4028E575CFD1__INCLUDED_)
#define AFX_FOLDERENCRY_H__5AB9511A_0193_40A1_B353_4028E575CFD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFolderEncryApp:
// See FolderEncry.cpp for the implementation of this class
//

class CFolderEncryApp : public CWinApp
{
public:
	CFolderEncryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFolderEncryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFolderEncryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOLDERENCRY_H__5AB9511A_0193_40A1_B353_4028E575CFD1__INCLUDED_)
