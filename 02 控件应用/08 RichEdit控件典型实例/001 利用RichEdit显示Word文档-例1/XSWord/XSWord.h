// XSWord.h : main header file for the XSWORD application
//

#if !defined(AFX_XSWORD_H__0CE5B5A4_F6B6_450C_9803_1651D2A149B4__INCLUDED_)
#define AFX_XSWORD_H__0CE5B5A4_F6B6_450C_9803_1651D2A149B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CXSWordApp:
// See XSWord.cpp for the implementation of this class
//

class CXSWordApp : public CWinApp
{
public:
	CXSWordApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXSWordApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CXSWordApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XSWORD_H__0CE5B5A4_F6B6_450C_9803_1651D2A149B4__INCLUDED_)
