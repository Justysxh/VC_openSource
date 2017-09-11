// ShareMem.h : main header file for the SHAREMEM application
//

#if !defined(AFX_SHAREMEM_H__AD3162B1_E79D_4582_8D9C_14A4750C722D__INCLUDED_)
#define AFX_SHAREMEM_H__AD3162B1_E79D_4582_8D9C_14A4750C722D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShareMemApp:
// See ShareMem.cpp for the implementation of this class
//

class CShareMemApp : public CWinApp
{
public:
	CShareMemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShareMemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShareMemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAREMEM_H__AD3162B1_E79D_4582_8D9C_14A4750C722D__INCLUDED_)
