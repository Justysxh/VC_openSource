// LogFile.h : main header file for the LOGFILE application
//

#if !defined(AFX_LOGFILE_H__3530965E_6493_4ADD_92F3_B75C7186CE58__INCLUDED_)
#define AFX_LOGFILE_H__3530965E_6493_4ADD_92F3_B75C7186CE58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLogFileApp:
// See LogFile.cpp for the implementation of this class
//

class CLogFileApp : public CWinApp
{
public:
	CLogFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLogFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGFILE_H__3530965E_6493_4ADD_92F3_B75C7186CE58__INCLUDED_)
