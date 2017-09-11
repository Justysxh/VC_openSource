// MoneyBox.h : main header file for the MONEYBOX application
//

#if !defined(AFX_MONEYBOX_H__1BD27471_48A8_4F29_A9C1_2B7528EC8BD0__INCLUDED_)
#define AFX_MONEYBOX_H__1BD27471_48A8_4F29_A9C1_2B7528EC8BD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMoneyBoxApp:
// See MoneyBox.cpp for the implementation of this class
//

class CMoneyBoxApp : public CWinApp
{
public:
	CMoneyBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoneyBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMoneyBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONEYBOX_H__1BD27471_48A8_4F29_A9C1_2B7528EC8BD0__INCLUDED_)
