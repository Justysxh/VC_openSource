// EditShow.h : main header file for the EDITSHOW application
//

#if !defined(AFX_EDITSHOW_H__8C93EFE1_0FCC_4278_992D_84F776A59626__INCLUDED_)
#define AFX_EDITSHOW_H__8C93EFE1_0FCC_4278_992D_84F776A59626__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEditShowApp:
// See EditShow.cpp for the implementation of this class
//

class CEditShowApp : public CWinApp
{
public:
	CEditShowApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditShowApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEditShowApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITSHOW_H__8C93EFE1_0FCC_4278_992D_84F776A59626__INCLUDED_)
