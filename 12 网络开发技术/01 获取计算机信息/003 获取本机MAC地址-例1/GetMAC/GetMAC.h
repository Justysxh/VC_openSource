// GetMAC.h : main header file for the GETMAC application
//

#if !defined(AFX_GETMAC_H__D7E2D4D3_D328_42A8_9CCC_B1CEAB7919C6__INCLUDED_)
#define AFX_GETMAC_H__D7E2D4D3_D328_42A8_9CCC_B1CEAB7919C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetMACApp:
// See GetMAC.cpp for the implementation of this class
//

class CGetMACApp : public CWinApp
{
public:
	CGetMACApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetMACApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetMACApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETMAC_H__D7E2D4D3_D328_42A8_9CCC_B1CEAB7919C6__INCLUDED_)
