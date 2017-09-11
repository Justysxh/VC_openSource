// TreeTip.h : main header file for the TREETIP application
//

#if !defined(AFX_TREETIP_H__F0C2F6B3_CE31_4437_8873_4AA19FD73031__INCLUDED_)
#define AFX_TREETIP_H__F0C2F6B3_CE31_4437_8873_4AA19FD73031__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreeTipApp:
// See TreeTip.cpp for the implementation of this class
//

class CTreeTipApp : public CWinApp
{
public:
	CTreeTipApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeTipApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTreeTipApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREETIP_H__F0C2F6B3_CE31_4437_8873_4AA19FD73031__INCLUDED_)
