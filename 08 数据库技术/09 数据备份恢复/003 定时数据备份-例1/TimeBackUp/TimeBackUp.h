// TimeBackUp.h : main header file for the TIMEBACKUP application
//

#if !defined(AFX_TIMEBACKUP_H__E4BE4582_2C39_4F34_A4DF_DC4E5CEE51EE__INCLUDED_)
#define AFX_TIMEBACKUP_H__E4BE4582_2C39_4F34_A4DF_DC4E5CEE51EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimeBackUpApp:
// See TimeBackUp.cpp for the implementation of this class
//

class CTimeBackUpApp : public CWinApp
{
public:
	CTimeBackUpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeBackUpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTimeBackUpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEBACKUP_H__E4BE4582_2C39_4F34_A4DF_DC4E5CEE51EE__INCLUDED_)
