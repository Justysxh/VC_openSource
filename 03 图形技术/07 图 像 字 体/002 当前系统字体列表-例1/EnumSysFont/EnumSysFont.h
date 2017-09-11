// EnumSysFont.h : main header file for the ENUMSYSFONT application
//

#if !defined(AFX_ENUMSYSFONT_H__77E848B4_54A7_40DF_864E_9CA97892C9AE__INCLUDED_)
#define AFX_ENUMSYSFONT_H__77E848B4_54A7_40DF_864E_9CA97892C9AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnumSysFontApp:
// See EnumSysFont.cpp for the implementation of this class
//

class CEnumSysFontApp : public CWinApp
{
public:
	CEnumSysFontApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumSysFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEnumSysFontApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMSYSFONT_H__77E848B4_54A7_40DF_864E_9CA97892C9AE__INCLUDED_)
