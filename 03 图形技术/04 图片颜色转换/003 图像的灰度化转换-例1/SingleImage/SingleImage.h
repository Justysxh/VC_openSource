// SingleImage.h : main header file for the SINGLEIMAGE application
//

#if !defined(AFX_SINGLEIMAGE_H__B22C89FE_D310_4CA0_8E2B_EFBB5EBB0DEF__INCLUDED_)
#define AFX_SINGLEIMAGE_H__B22C89FE_D310_4CA0_8E2B_EFBB5EBB0DEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSingleImageApp:
// See SingleImage.cpp for the implementation of this class
//

class CSingleImageApp : public CWinApp
{
public:
	CSingleImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleImageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSingleImageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEIMAGE_H__B22C89FE_D310_4CA0_8E2B_EFBB5EBB0DEF__INCLUDED_)
