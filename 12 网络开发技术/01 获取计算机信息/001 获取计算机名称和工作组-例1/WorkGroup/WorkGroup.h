// WorkGroup.h : main header file for the WORKGROUP application
//

#if !defined(AFX_WORKGROUP_H__480982B9_6627_4BD7_A71E_BB895BD3507A__INCLUDED_)
#define AFX_WORKGROUP_H__480982B9_6627_4BD7_A71E_BB895BD3507A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWorkGroupApp:
// See WorkGroup.cpp for the implementation of this class
//

class CWorkGroupApp : public CWinApp
{
public:
	CWorkGroupApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkGroupApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWorkGroupApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKGROUP_H__480982B9_6627_4BD7_A71E_BB895BD3507A__INCLUDED_)
