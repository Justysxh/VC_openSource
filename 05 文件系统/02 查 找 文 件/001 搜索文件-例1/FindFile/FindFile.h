// FindFile.h : main header file for the FINDFILE application
//

#if !defined(AFX_FINDFILE_H__B3A4B7CA_73C2_4D33_85E3_5ED345524EF2__INCLUDED_)
#define AFX_FINDFILE_H__B3A4B7CA_73C2_4D33_85E3_5ED345524EF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFindFileApp:
// See FindFile.cpp for the implementation of this class
//

class CFindFileApp : public CWinApp
{
public:
	CFindFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFindFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDFILE_H__B3A4B7CA_73C2_4D33_85E3_5ED345524EF2__INCLUDED_)
