// delview.h : main header file for the DELVIEW application
//

#if !defined(AFX_DELVIEW_H__8F84101C_1D12_4BF2_9363_7C82B33F8F60__INCLUDED_)
#define AFX_DELVIEW_H__8F84101C_1D12_4BF2_9363_7C82B33F8F60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDelviewApp:
// See delview.cpp for the implementation of this class
//

class CDelviewApp : public CWinApp
{
public:
	CDelviewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelviewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDelviewApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELVIEW_H__8F84101C_1D12_4BF2_9363_7C82B33F8F60__INCLUDED_)
