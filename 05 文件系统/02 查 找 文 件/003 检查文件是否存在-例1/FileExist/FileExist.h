// FileExist.h : main header file for the FILEEXIST application
//

#if !defined(AFX_FILEEXIST_H__1D598A0F_3B9C_4052_9C27_87357E30AAD7__INCLUDED_)
#define AFX_FILEEXIST_H__1D598A0F_3B9C_4052_9C27_87357E30AAD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileExistApp:
// See FileExist.cpp for the implementation of this class
//

class CFileExistApp : public CWinApp
{
public:
	CFileExistApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileExistApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileExistApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEEXIST_H__1D598A0F_3B9C_4052_9C27_87357E30AAD7__INCLUDED_)
