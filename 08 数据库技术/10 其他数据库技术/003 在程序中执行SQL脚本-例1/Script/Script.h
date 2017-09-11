// Script.h : main header file for the SCRIPT application
//

#if !defined(AFX_SCRIPT_H__BFBF0A20_6FB1_4E13_8160_BC48B092E76C__INCLUDED_)
#define AFX_SCRIPT_H__BFBF0A20_6FB1_4E13_8160_BC48B092E76C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScriptApp:
// See Script.cpp for the implementation of this class
//

class CScriptApp : public CWinApp
{
public:
	CScriptApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScriptApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScriptApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPT_H__BFBF0A20_6FB1_4E13_8160_BC48B092E76C__INCLUDED_)
