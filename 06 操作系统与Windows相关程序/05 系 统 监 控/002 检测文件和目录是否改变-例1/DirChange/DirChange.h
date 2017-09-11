// DirChange.h : main header file for the DIRCHANGE application
//

#if !defined(AFX_DIRCHANGE_H__87315C8A_6F15_41DB_9465_4BD34F59BD9A__INCLUDED_)
#define AFX_DIRCHANGE_H__87315C8A_6F15_41DB_9465_4BD34F59BD9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDirChangeApp:
// See DirChange.cpp for the implementation of this class
//

class CDirChangeApp : public CWinApp
{
public:
	CDirChangeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDirChangeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDirChangeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRCHANGE_H__87315C8A_6F15_41DB_9465_4BD34F59BD9A__INCLUDED_)
