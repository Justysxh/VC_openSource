// NameAndIP.h : main header file for the NAMEANDIP application
//

#if !defined(AFX_NAMEANDIP_H__F9E9E49C_4BB4_4EA4_BEC7_DA1DCB273CC9__INCLUDED_)
#define AFX_NAMEANDIP_H__F9E9E49C_4BB4_4EA4_BEC7_DA1DCB273CC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNameAndIPApp:
// See NameAndIP.cpp for the implementation of this class
//

class CNameAndIPApp : public CWinApp
{
public:
	CNameAndIPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNameAndIPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNameAndIPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEANDIP_H__F9E9E49C_4BB4_4EA4_BEC7_DA1DCB273CC9__INCLUDED_)
