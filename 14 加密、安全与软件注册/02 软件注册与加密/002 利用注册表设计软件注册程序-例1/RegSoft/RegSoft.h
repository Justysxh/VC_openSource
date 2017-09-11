// RegSoft.h : main header file for the REGSOFT application
//

#if !defined(AFX_REGSOFT_H__900AB352_8F8E_49AF_B11C_CCBA8532CA0A__INCLUDED_)
#define AFX_REGSOFT_H__900AB352_8F8E_49AF_B11C_CCBA8532CA0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRegSoftApp:
// See RegSoft.cpp for the implementation of this class
//

class CRegSoftApp : public CWinApp
{
public:
	CRegSoftApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegSoftApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRegSoftApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGSOFT_H__900AB352_8F8E_49AF_B11C_CCBA8532CA0A__INCLUDED_)
