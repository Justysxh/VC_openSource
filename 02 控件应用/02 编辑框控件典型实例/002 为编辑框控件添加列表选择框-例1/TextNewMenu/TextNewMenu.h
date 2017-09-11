// TextNewMenu.h : main header file for the TEXTNEWMENU application
//

#if !defined(AFX_TEXTNEWMENU_H__7E1D1A38_9AC8_4283_9674_F3B810FDE875__INCLUDED_)
#define AFX_TEXTNEWMENU_H__7E1D1A38_9AC8_4283_9674_F3B810FDE875__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextNewMenuApp:
// See TextNewMenu.cpp for the implementation of this class
//

class CTextNewMenuApp : public CWinApp
{
public:
	CTextNewMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextNewMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTextNewMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTNEWMENU_H__7E1D1A38_9AC8_4283_9674_F3B810FDE875__INCLUDED_)
