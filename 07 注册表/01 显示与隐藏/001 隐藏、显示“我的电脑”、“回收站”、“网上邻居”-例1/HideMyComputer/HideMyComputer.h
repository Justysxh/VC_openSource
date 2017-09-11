// HideMyComputer.h : main header file for the HIDEMYCOMPUTER application
//

#if !defined(AFX_HIDEMYCOMPUTER_H__8A6E9E25_04CD_4D86_BDDA_32ABB03A36AC__INCLUDED_)
#define AFX_HIDEMYCOMPUTER_H__8A6E9E25_04CD_4D86_BDDA_32ABB03A36AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHideMyComputerApp:
// See HideMyComputer.cpp for the implementation of this class
//

class CHideMyComputerApp : public CWinApp
{
public:
	CHideMyComputerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideMyComputerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHideMyComputerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDEMYCOMPUTER_H__8A6E9E25_04CD_4D86_BDDA_32ABB03A36AC__INCLUDED_)
