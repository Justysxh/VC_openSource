// CreateToolbarFromMenu.h : main header file for the CREATETOOLBARFROMMENU application
//

#if !defined(AFX_CREATETOOLBARFROMMENU_H__55FDBF34_4A73_4E0C_B00A_55A611C40E26__INCLUDED_)
#define AFX_CREATETOOLBARFROMMENU_H__55FDBF34_4A73_4E0C_B00A_55A611C40E26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateToolbarFromMenuApp:
// See CreateToolbarFromMenu.cpp for the implementation of this class
//

class CCreateToolbarFromMenuApp : public CWinApp
{
public:
	CCreateToolbarFromMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateToolbarFromMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateToolbarFromMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATETOOLBARFROMMENU_H__55FDBF34_4A73_4E0C_B00A_55A611C40E26__INCLUDED_)
