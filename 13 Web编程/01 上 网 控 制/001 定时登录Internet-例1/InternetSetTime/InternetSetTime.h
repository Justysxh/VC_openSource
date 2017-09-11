// InternetSetTime.h : main header file for the INTERNETSETTIME application
//

#if !defined(AFX_INTERNETSETTIME_H__D9FE08CB_5FF2_4841_BD6D_A98D33793AD1__INCLUDED_)
#define AFX_INTERNETSETTIME_H__D9FE08CB_5FF2_4841_BD6D_A98D33793AD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CInternetSetTimeApp:
// See InternetSetTime.cpp for the implementation of this class
//

class CInternetSetTimeApp : public CWinApp
{
public:
	CInternetSetTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInternetSetTimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CInternetSetTimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERNETSETTIME_H__D9FE08CB_5FF2_4841_BD6D_A98D33793AD1__INCLUDED_)
