// CustomPopMenu.h : main header file for the CUSTOMPOPMENU application
//

#if !defined(AFX_CUSTOMPOPMENU_H__A909FDF9_03D3_4ED9_804D_04AB903C611A__INCLUDED_)
#define AFX_CUSTOMPOPMENU_H__A909FDF9_03D3_4ED9_804D_04AB903C611A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCustomPopMenuApp:
// See CustomPopMenu.cpp for the implementation of this class
//

class CCustomPopMenuApp : public CWinApp
{
public:
	CCustomPopMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomPopMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCustomPopMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMPOPMENU_H__A909FDF9_03D3_4ED9_804D_04AB903C611A__INCLUDED_)
