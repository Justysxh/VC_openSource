// HideDesktop.h : main header file for the HIDEDESKTOP application
//

#if !defined(AFX_HIDEDESKTOP_H__16C241E3_95AA_4943_89B1_9E34621C6E6F__INCLUDED_)
#define AFX_HIDEDESKTOP_H__16C241E3_95AA_4943_89B1_9E34621C6E6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHideDesktopApp:
// See HideDesktop.cpp for the implementation of this class
//

class CHideDesktopApp : public CWinApp
{
public:
	CHideDesktopApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideDesktopApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHideDesktopApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDEDESKTOP_H__16C241E3_95AA_4943_89B1_9E34621C6E6F__INCLUDED_)
