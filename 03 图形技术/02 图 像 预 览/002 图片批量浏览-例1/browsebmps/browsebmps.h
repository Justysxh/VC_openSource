// browsebmps.h : main header file for the BROWSEBMPS application
//

#if !defined(AFX_BROWSEBMPS_H__177C1260_9C0E_4322_9ECC_07A6C1427EDD__INCLUDED_)
#define AFX_BROWSEBMPS_H__177C1260_9C0E_4322_9ECC_07A6C1427EDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBrowsebmpsApp:
// See browsebmps.cpp for the implementation of this class
//

class CBrowsebmpsApp : public CWinApp
{
public:
	CBrowsebmpsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowsebmpsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBrowsebmpsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSEBMPS_H__177C1260_9C0E_4322_9ECC_07A6C1427EDD__INCLUDED_)
