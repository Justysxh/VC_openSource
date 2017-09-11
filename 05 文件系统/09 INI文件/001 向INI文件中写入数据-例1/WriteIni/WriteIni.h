// WriteIni.h : main header file for the WRITEINI application
//

#if !defined(AFX_WRITEINI_H__6903262C_4A0C_475F_BA0B_D19FCD8FA941__INCLUDED_)
#define AFX_WRITEINI_H__6903262C_4A0C_475F_BA0B_D19FCD8FA941__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWriteIniApp:
// See WriteIni.cpp for the implementation of this class
//

class CWriteIniApp : public CWinApp
{
public:
	CWriteIniApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWriteIniApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWriteIniApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WRITEINI_H__6903262C_4A0C_475F_BA0B_D19FCD8FA941__INCLUDED_)
