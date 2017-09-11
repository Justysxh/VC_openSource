// Media.h : main header file for the MEDIA application
//

#if !defined(AFX_MEDIA_H__582EB9F4_FD8B_47D1_8365_27C18FEDDC7A__INCLUDED_)
#define AFX_MEDIA_H__582EB9F4_FD8B_47D1_8365_27C18FEDDC7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMediaApp:
// See Media.cpp for the implementation of this class
//

class CMediaApp : public CWinApp
{
public:
	CMediaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMediaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIA_H__582EB9F4_FD8B_47D1_8365_27C18FEDDC7A__INCLUDED_)
