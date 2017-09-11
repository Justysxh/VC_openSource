// PathFont.h : main header file for the PATHFONT application
//

#if !defined(AFX_PATHFONT_H__033549E0_B00F_4362_89FE_3621C1AC2115__INCLUDED_)
#define AFX_PATHFONT_H__033549E0_B00F_4362_89FE_3621C1AC2115__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPathFontApp:
// See PathFont.cpp for the implementation of this class
//

class CPathFontApp : public CWinApp
{
public:
	CPathFontApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPathFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPathFontApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATHFONT_H__033549E0_B00F_4362_89FE_3621C1AC2115__INCLUDED_)
