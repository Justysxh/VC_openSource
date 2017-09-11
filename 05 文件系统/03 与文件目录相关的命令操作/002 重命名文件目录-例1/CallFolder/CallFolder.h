// CallFolder.h : main header file for the CALLFOLDER application
//

#if !defined(AFX_CALLFOLDER_H__B317A770_C8B7_4601_B31D_DFD1BCC52C56__INCLUDED_)
#define AFX_CALLFOLDER_H__B317A770_C8B7_4601_B31D_DFD1BCC52C56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCallFolderApp:
// See CallFolder.cpp for the implementation of this class
//

class CCallFolderApp : public CWinApp
{
public:
	CCallFolderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallFolderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCallFolderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLFOLDER_H__B317A770_C8B7_4601_B31D_DFD1BCC52C56__INCLUDED_)
