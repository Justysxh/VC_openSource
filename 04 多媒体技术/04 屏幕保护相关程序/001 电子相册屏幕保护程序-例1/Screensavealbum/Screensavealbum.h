// Screensavealbum.h : main header file for the SCREENSAVEALBUM application
//

#if !defined(AFX_SCREENSAVEALBUM_H__412B8D2C_590A_4C75_8199_DDB62E4E0D4A__INCLUDED_)
#define AFX_SCREENSAVEALBUM_H__412B8D2C_590A_4C75_8199_DDB62E4E0D4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScreensavealbumApp:
// See Screensavealbum.cpp for the implementation of this class
//

class CScreensavealbumApp : public CWinApp
{
public:
	CScreensavealbumApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreensavealbumApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScreensavealbumApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENSAVEALBUM_H__412B8D2C_590A_4C75_8199_DDB62E4E0D4A__INCLUDED_)
