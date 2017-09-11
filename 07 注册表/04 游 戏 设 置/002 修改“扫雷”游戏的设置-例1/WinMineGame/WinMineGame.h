// WinMineGame.h : main header file for the WINMINEGAME application
//

#if !defined(AFX_WINMINEGAME_H__CB039E9C_7588_4314_9E49_48458657A528__INCLUDED_)
#define AFX_WINMINEGAME_H__CB039E9C_7588_4314_9E49_48458657A528__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWinMineGameApp:
// See WinMineGame.cpp for the implementation of this class
//

class CWinMineGameApp : public CWinApp
{
public:
	CWinMineGameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinMineGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWinMineGameApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINMINEGAME_H__CB039E9C_7588_4314_9E49_48458657A528__INCLUDED_)
