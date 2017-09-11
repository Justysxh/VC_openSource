// SongManage.h : main header file for the SONGMANAGE application
//

#if !defined(AFX_SONGMANAGE_H__CB53E08E_2AF2_4E70_B3A3_C3B15DD182C6__INCLUDED_)
#define AFX_SONGMANAGE_H__CB53E08E_2AF2_4E70_B3A3_C3B15DD182C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSongManageApp:
// See SongManage.cpp for the implementation of this class
//

class CSongManageApp : public CWinApp
{
public:
	CSongManageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSongManageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSongManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SONGMANAGE_H__CB53E08E_2AF2_4E70_B3A3_C3B15DD182C6__INCLUDED_)
