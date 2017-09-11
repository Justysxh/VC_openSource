// CreateFolder.h : main header file for the CREATEFOLDER application
//

#if !defined(AFX_CREATEFOLDER_H__9638A940_450F_4C58_A6B8_4D5E6C89684C__INCLUDED_)
#define AFX_CREATEFOLDER_H__9638A940_450F_4C58_A6B8_4D5E6C89684C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateFolderApp:
// See CreateFolder.cpp for the implementation of this class
//

class CCreateFolderApp : public CWinApp
{
public:
	CCreateFolderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateFolderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateFolderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEFOLDER_H__9638A940_450F_4C58_A6B8_4D5E6C89684C__INCLUDED_)
