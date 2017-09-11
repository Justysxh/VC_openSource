// HideStartMenu.h : main header file for the HIDESTARTMENU application
//

#if !defined(AFX_HIDESTARTMENU_H__68D7BF22_4A54_4B88_B670_FA7D077FF50A__INCLUDED_)
#define AFX_HIDESTARTMENU_H__68D7BF22_4A54_4B88_B670_FA7D077FF50A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHideStartMenuApp:
// See HideStartMenu.cpp for the implementation of this class
//

class CHideStartMenuApp : public CWinApp
{
public:
	CHideStartMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideStartMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHideStartMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDESTARTMENU_H__68D7BF22_4A54_4B88_B670_FA7D077FF50A__INCLUDED_)
