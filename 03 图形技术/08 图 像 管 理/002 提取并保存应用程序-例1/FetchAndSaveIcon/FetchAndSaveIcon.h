// FetchAndSaveIcon.h : main header file for the FETCHANDSAVEICON application
//

#if !defined(AFX_FETCHANDSAVEICON_H__D69A60B5_E203_4818_9DFA_57FA2189E8E9__INCLUDED_)
#define AFX_FETCHANDSAVEICON_H__D69A60B5_E203_4818_9DFA_57FA2189E8E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFetchAndSaveIconApp:
// See FetchAndSaveIcon.cpp for the implementation of this class
//

class CFetchAndSaveIconApp : public CWinApp
{
public:
	CFetchAndSaveIconApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchAndSaveIconApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFetchAndSaveIconApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHANDSAVEICON_H__D69A60B5_E203_4818_9DFA_57FA2189E8E9__INCLUDED_)
