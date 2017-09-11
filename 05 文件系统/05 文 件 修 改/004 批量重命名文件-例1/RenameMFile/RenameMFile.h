// RenameMFile.h : main header file for the RENAMEMFILE application
//

#if !defined(AFX_RENAMEMFILE_H__E05C06AE_5A74_4A0F_BD7A_FEB6D7533A3A__INCLUDED_)
#define AFX_RENAMEMFILE_H__E05C06AE_5A74_4A0F_BD7A_FEB6D7533A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRenameMFileApp:
// See RenameMFile.cpp for the implementation of this class
//

class CRenameMFileApp : public CWinApp
{
public:
	CRenameMFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRenameMFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRenameMFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RENAMEMFILE_H__E05C06AE_5A74_4A0F_BD7A_FEB6D7533A3A__INCLUDED_)
