// ResShare.h : main header file for the RESSHARE application
//

#if !defined(AFX_RESSHARE_H__A2720A04_3529_4749_8242_0793A4016492__INCLUDED_)
#define AFX_RESSHARE_H__A2720A04_3529_4749_8242_0793A4016492__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CResShareApp:
// See ResShare.cpp for the implementation of this class
//

class CResShareApp : public CWinApp
{
public:
	CResShareApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResShareApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CResShareApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESSHARE_H__A2720A04_3529_4749_8242_0793A4016492__INCLUDED_)
