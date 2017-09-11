// SuperConnect.h : main header file for the SUPERCONNECT application
//

#if !defined(AFX_SUPERCONNECT_H__C813EF4D_6AE8_4775_998D_7C8D05415BEA__INCLUDED_)
#define AFX_SUPERCONNECT_H__C813EF4D_6AE8_4775_998D_7C8D05415BEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSuperConnectApp:
// See SuperConnect.cpp for the implementation of this class
//

class CSuperConnectApp : public CWinApp
{
public:
	CSuperConnectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuperConnectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSuperConnectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUPERCONNECT_H__C813EF4D_6AE8_4775_998D_7C8D05415BEA__INCLUDED_)
