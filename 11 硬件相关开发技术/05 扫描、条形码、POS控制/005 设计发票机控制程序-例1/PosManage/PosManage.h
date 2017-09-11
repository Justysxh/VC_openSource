// PosManage.h : main header file for the POSMANAGE application
//

#if !defined(AFX_POSMANAGE_H__0E75F9C6_8AA1_4BE8_981B_5A92E6FE0ED3__INCLUDED_)
#define AFX_POSMANAGE_H__0E75F9C6_8AA1_4BE8_981B_5A92E6FE0ED3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPosManageApp:
// See PosManage.cpp for the implementation of this class
//

class CPosManageApp : public CWinApp
{
public:
	CPosManageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPosManageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPosManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POSMANAGE_H__0E75F9C6_8AA1_4BE8_981B_5A92E6FE0ED3__INCLUDED_)
