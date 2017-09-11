// FileEncry.h : main header file for the FILEENCRY application
//

#if !defined(AFX_FILEENCRY_H__A3903D0D_8A0F_460D_94E3_73785047A654__INCLUDED_)
#define AFX_FILEENCRY_H__A3903D0D_8A0F_460D_94E3_73785047A654__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileEncryApp:
// See FileEncry.cpp for the implementation of this class
//

class CFileEncryApp : public CWinApp
{
public:
	CFileEncryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileEncryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileEncryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEENCRY_H__A3903D0D_8A0F_460D_94E3_73785047A654__INCLUDED_)
