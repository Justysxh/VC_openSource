// FetchPage.h : main header file for the FETCHPAGE application
//

#if !defined(AFX_FETCHPAGE_H__93ED96B0_E9C5_4085_9A04_FEBF4C26E919__INCLUDED_)
#define AFX_FETCHPAGE_H__93ED96B0_E9C5_4085_9A04_FEBF4C26E919__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFetchPageApp:
// See FetchPage.cpp for the implementation of this class
//

class CFetchPageApp : public CWinApp
{
public:
	CFetchPageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchPageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFetchPageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHPAGE_H__93ED96B0_E9C5_4085_9A04_FEBF4C26E919__INCLUDED_)
