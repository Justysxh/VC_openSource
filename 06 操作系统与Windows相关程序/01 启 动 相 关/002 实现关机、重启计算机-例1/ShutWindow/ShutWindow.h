// ShutWindow.h : main header file for the SHUTWINDOW application
//

#if !defined(AFX_SHUTWINDOW_H__1A178E10_4AE5_4794_B167_3533EDB5B435__INCLUDED_)
#define AFX_SHUTWINDOW_H__1A178E10_4AE5_4794_B167_3533EDB5B435__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShutWindowApp:
// See ShutWindow.cpp for the implementation of this class
//

class CShutWindowApp : public CWinApp
{
public:
	CShutWindowApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutWindowApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShutWindowApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTWINDOW_H__1A178E10_4AE5_4794_B167_3533EDB5B435__INCLUDED_)
