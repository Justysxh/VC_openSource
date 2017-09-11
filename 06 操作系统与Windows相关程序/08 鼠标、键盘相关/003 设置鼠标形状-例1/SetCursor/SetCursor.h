// SetCursor.h : main header file for the SETCURSOR application
//

#if !defined(AFX_SETCURSOR_H__BE2023D9_7784_43BC_8DA7_13B494E24781__INCLUDED_)
#define AFX_SETCURSOR_H__BE2023D9_7784_43BC_8DA7_13B494E24781__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSetCursorApp:
// See SetCursor.cpp for the implementation of this class
//

class CSetCursorApp : public CWinApp
{
public:
	CSetCursorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetCursorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSetCursorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETCURSOR_H__BE2023D9_7784_43BC_8DA7_13B494E24781__INCLUDED_)
