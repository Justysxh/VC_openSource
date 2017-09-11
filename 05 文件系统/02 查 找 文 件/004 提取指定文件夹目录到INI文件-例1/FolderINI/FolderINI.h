// FolderINI.h : main header file for the FOLDERINI application
//

#if !defined(AFX_FOLDERINI_H__A1BCE77F_AE0C_4B56_B32F_2D38BF50E64C__INCLUDED_)
#define AFX_FOLDERINI_H__A1BCE77F_AE0C_4B56_B32F_2D38BF50E64C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFolderINIApp:
// See FolderINI.cpp for the implementation of this class
//

class CFolderINIApp : public CWinApp
{
public:
	CFolderINIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFolderINIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFolderINIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOLDERINI_H__A1BCE77F_AE0C_4B56_B32F_2D38BF50E64C__INCLUDED_)
