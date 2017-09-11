// StartXP.h : main header file for the STARTXP application
//

#if !defined(AFX_STARTXP_H__31313A45_7F58_4777_8C1F_C1044F152F3A__INCLUDED_)
#define AFX_STARTXP_H__31313A45_7F58_4777_8C1F_C1044F152F3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStartXPApp:
// See StartXP.cpp for the implementation of this class
//

class CStartXPApp : public CWinApp
{
public:
	CStartXPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartXPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStartXPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTXP_H__31313A45_7F58_4777_8C1F_C1044F152F3A__INCLUDED_)
