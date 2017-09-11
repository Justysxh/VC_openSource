// UseTab.h : main header file for the USETAB application
//

#if !defined(AFX_USETAB_H__7034163B_98AA_4384_9346_92CE582691AF__INCLUDED_)
#define AFX_USETAB_H__7034163B_98AA_4384_9346_92CE582691AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseTabApp:
// See UseTab.cpp for the implementation of this class
//

class CUseTabApp : public CWinApp
{
public:
	CUseTabApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseTabApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseTabApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USETAB_H__7034163B_98AA_4384_9346_92CE582691AF__INCLUDED_)
