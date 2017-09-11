// FXtree.h : main header file for the FXTREE application
//

#if !defined(AFX_FXTREE_H__3C8E7E2B_696E_413A_BFB5_3073AB97477E__INCLUDED_)
#define AFX_FXTREE_H__3C8E7E2B_696E_413A_BFB5_3073AB97477E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFXtreeApp:
// See FXtree.cpp for the implementation of this class
//

class CFXtreeApp : public CWinApp
{
public:
	CFXtreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFXtreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFXtreeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FXTREE_H__3C8E7E2B_696E_413A_BFB5_3073AB97477E__INCLUDED_)
