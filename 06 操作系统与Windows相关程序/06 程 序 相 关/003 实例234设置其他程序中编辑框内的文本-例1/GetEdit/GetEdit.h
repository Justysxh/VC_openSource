// GetEdit.h : main header file for the GETEDIT application
//

#if !defined(AFX_GETEDIT_H__DCD18EF4_1752_4809_BD40_ADC037B148F0__INCLUDED_)
#define AFX_GETEDIT_H__DCD18EF4_1752_4809_BD40_ADC037B148F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetEditApp:
// See GetEdit.cpp for the implementation of this class
//

class CGetEditApp : public CWinApp
{
public:
	CGetEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetEditApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETEDIT_H__DCD18EF4_1752_4809_BD40_ADC037B148F0__INCLUDED_)
