// GetIP.h : main header file for the GETIP application
//

#if !defined(AFX_GETIP_H__698919E2_0F35_4489_A499_0802E063B57F__INCLUDED_)
#define AFX_GETIP_H__698919E2_0F35_4489_A499_0802E063B57F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetIPApp:
// See GetIP.cpp for the implementation of this class
//

class CGetIPApp : public CWinApp
{
public:
	CGetIPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetIPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetIPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETIP_H__698919E2_0F35_4489_A499_0802E063B57F__INCLUDED_)
