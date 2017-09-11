// FetchBmp.h : main header file for the FETCHBMP application
//

#if !defined(AFX_FETCHBMP_H__5F9DC9ED_ABA0_42DA_8988_07A070AB0DFB__INCLUDED_)
#define AFX_FETCHBMP_H__5F9DC9ED_ABA0_42DA_8988_07A070AB0DFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFetchBmpApp:
// See FetchBmp.cpp for the implementation of this class
//

class CFetchBmpApp : public CWinApp
{
public:
	CFetchBmpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchBmpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFetchBmpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHBMP_H__5F9DC9ED_ABA0_42DA_8988_07A070AB0DFB__INCLUDED_)
