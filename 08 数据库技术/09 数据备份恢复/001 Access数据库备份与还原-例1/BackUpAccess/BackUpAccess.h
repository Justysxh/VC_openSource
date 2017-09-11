// BackUpAccess.h : main header file for the BACKUPACCESS application
//

#if !defined(AFX_BACKUPACCESS_H__051E4D6A_58BF_45B6_8971_6EE34CF7EF76__INCLUDED_)
#define AFX_BACKUPACCESS_H__051E4D6A_58BF_45B6_8971_6EE34CF7EF76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBackUpAccessApp:
// See BackUpAccess.cpp for the implementation of this class
//

class CBackUpAccessApp : public CWinApp
{
public:
	CBackUpAccessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackUpAccessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBackUpAccessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKUPACCESS_H__051E4D6A_58BF_45B6_8971_6EE34CF7EF76__INCLUDED_)
