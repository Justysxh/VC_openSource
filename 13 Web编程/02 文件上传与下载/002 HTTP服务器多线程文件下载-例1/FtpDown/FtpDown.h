// FtpDown.h : main header file for the FTPDOWN application
//

#if !defined(AFX_FTPDOWN_H__C90EF29D_8E0C_4C6D_8C5A_BFBDE1A0881F__INCLUDED_)
#define AFX_FTPDOWN_H__C90EF29D_8E0C_4C6D_8C5A_BFBDE1A0881F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFtpDownApp:
// See FtpDown.cpp for the implementation of this class
//

class CFtpDownApp : public CWinApp
{
public:
	CFtpDownApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpDownApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFtpDownApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPDOWN_H__C90EF29D_8E0C_4C6D_8C5A_BFBDE1A0881F__INCLUDED_)
