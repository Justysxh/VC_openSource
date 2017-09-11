// FtpUpLoad.h : main header file for the FTPUPLOAD application
//

#if !defined(AFX_FTPUPLOAD_H__8D9300BB_24A2_4C3C_B226_9AB59CE5B12C__INCLUDED_)
#define AFX_FTPUPLOAD_H__8D9300BB_24A2_4C3C_B226_9AB59CE5B12C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFtpUpLoadApp:
// See FtpUpLoad.cpp for the implementation of this class
//

class CFtpUpLoadApp : public CWinApp
{
public:
	CFtpUpLoadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpUpLoadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFtpUpLoadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPUPLOAD_H__8D9300BB_24A2_4C3C_B226_9AB59CE5B12C__INCLUDED_)
