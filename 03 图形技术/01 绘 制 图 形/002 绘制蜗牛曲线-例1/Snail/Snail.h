// Snail.h : main header file for the SNAIL application
//

#if !defined(AFX_SNAIL_H__8D83C92B_EE7D_4703_9193_4116F8A7374D__INCLUDED_)
#define AFX_SNAIL_H__8D83C92B_EE7D_4703_9193_4116F8A7374D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSnailApp:
// See Snail.cpp for the implementation of this class
//

class CSnailApp : public CWinApp
{
public:
	CSnailApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnailApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSnailApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAIL_H__8D83C92B_EE7D_4703_9193_4116F8A7374D__INCLUDED_)
