// TestGif.h : main header file for the TESTGIF application
//

#if !defined(AFX_TESTGIF_H__A003B4D4_B5C2_4B37_8C17_F0E3A42519EA__INCLUDED_)
#define AFX_TESTGIF_H__A003B4D4_B5C2_4B37_8C17_F0E3A42519EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestGifApp:
// See TestGif.cpp for the implementation of this class
//

class CTestGifApp : public CWinApp
{
public:
	CTestGifApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestGifApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestGifApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTGIF_H__A003B4D4_B5C2_4B37_8C17_F0E3A42519EA__INCLUDED_)
