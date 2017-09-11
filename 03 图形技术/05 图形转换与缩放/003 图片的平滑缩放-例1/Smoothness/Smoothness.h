// Smoothness.h : main header file for the SMOOTHNESS application
//

#if !defined(AFX_SMOOTHNESS_H__535604E4_46B3_46B4_8992_F878D3355DB9__INCLUDED_)
#define AFX_SMOOTHNESS_H__535604E4_46B3_46B4_8992_F878D3355DB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSmoothnessApp:
// See Smoothness.cpp for the implementation of this class
//

class CSmoothnessApp : public CWinApp
{
public:
	CSmoothnessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSmoothnessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSmoothnessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMOOTHNESS_H__535604E4_46B3_46B4_8992_F878D3355DB9__INCLUDED_)
