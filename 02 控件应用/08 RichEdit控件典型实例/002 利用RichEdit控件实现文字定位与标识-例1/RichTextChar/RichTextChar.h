// RichTextChar.h : main header file for the RICHTEXTCHAR application
//

#if !defined(AFX_RICHTEXTCHAR_H__BE93CF54_5D31_48EA_8BAD_238E4BD849AE__INCLUDED_)
#define AFX_RICHTEXTCHAR_H__BE93CF54_5D31_48EA_8BAD_238E4BD849AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRichTextCharApp:
// See RichTextChar.cpp for the implementation of this class
//

class CRichTextCharApp : public CWinApp
{
public:
	CRichTextCharApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRichTextCharApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRichTextCharApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RICHTEXTCHAR_H__BE93CF54_5D31_48EA_8BAD_238E4BD849AE__INCLUDED_)
