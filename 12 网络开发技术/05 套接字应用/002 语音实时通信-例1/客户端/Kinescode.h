// Kinescode.h : main header file for the KINESCODE application
//

#if !defined(AFX_KINESCODE_H__597E6D79_7647_4E22_BA0A_A299D9D23A9F__INCLUDED_)
#define AFX_KINESCODE_H__597E6D79_7647_4E22_BA0A_A299D9D23A9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKinescodeApp:
// See Kinescode.cpp for the implementation of this class
//


class CKinescodeApp : public CWinApp
{
public:
	CKinescodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKinescodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKinescodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KINESCODE_H__597E6D79_7647_4E22_BA0A_A299D9D23A9F__INCLUDED_)
