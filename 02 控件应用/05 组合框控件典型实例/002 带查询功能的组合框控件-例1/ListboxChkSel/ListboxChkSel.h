// ListboxChkSel.h : main header file for the LISTBOXCHKSEL application
//

#if !defined(AFX_LISTBOXCHKSEL_H__E56C0EB7_5D03_49C5_A2A5_32974E76BB0F__INCLUDED_)
#define AFX_LISTBOXCHKSEL_H__E56C0EB7_5D03_49C5_A2A5_32974E76BB0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CListboxChkSelApp:
// See ListboxChkSel.cpp for the implementation of this class
//

class CListboxChkSelApp : public CWinApp
{
public:
	CListboxChkSelApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListboxChkSelApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CListboxChkSelApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBOXCHKSEL_H__E56C0EB7_5D03_49C5_A2A5_32974E76BB0F__INCLUDED_)
