// insertdates.h : main header file for the INSERTDATES application
//

#if !defined(AFX_INSERTDATES_H__BB0F0F6F_4636_4F8C_910A_684D2432DEED__INCLUDED_)
#define AFX_INSERTDATES_H__BB0F0F6F_4636_4F8C_910A_684D2432DEED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CInsertdatesApp:
// See insertdates.cpp for the implementation of this class
//

class CInsertdatesApp : public CWinApp
{
public:
	CInsertdatesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInsertdatesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CInsertdatesApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSERTDATES_H__BB0F0F6F_4636_4F8C_910A_684D2432DEED__INCLUDED_)
