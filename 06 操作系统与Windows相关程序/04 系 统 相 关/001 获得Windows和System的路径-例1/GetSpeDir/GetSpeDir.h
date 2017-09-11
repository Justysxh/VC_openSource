// GetSpeDir.h : main header file for the GETSPEDIR application
//

#if !defined(AFX_GETSPEDIR_H__B9A75D0F_2980_4E26_A1FE_33C1BAA9F124__INCLUDED_)
#define AFX_GETSPEDIR_H__B9A75D0F_2980_4E26_A1FE_33C1BAA9F124__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetSpeDirApp:
// See GetSpeDir.cpp for the implementation of this class
//

class CGetSpeDirApp : public CWinApp
{
public:
	CGetSpeDirApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetSpeDirApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetSpeDirApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETSPEDIR_H__B9A75D0F_2980_4E26_A1FE_33C1BAA9F124__INCLUDED_)
