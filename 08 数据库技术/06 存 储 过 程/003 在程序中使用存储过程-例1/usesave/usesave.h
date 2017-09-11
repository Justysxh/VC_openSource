// usesave.h : main header file for the USESAVE application
//

#if !defined(AFX_USESAVE_H__7CA9112D_8F4F_4CB5_94E5_41FB305F7C66__INCLUDED_)
#define AFX_USESAVE_H__7CA9112D_8F4F_4CB5_94E5_41FB305F7C66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUsesaveApp:
// See usesave.cpp for the implementation of this class
//

class CUsesaveApp : public CWinApp
{
public:
	CUsesaveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUsesaveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUsesaveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USESAVE_H__7CA9112D_8F4F_4CB5_94E5_41FB305F7C66__INCLUDED_)
