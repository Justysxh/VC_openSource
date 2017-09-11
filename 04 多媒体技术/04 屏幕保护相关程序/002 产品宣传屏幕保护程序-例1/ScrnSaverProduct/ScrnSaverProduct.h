// ScrnSaverProduct.h : main header file for the SCRNSAVERPRODUCT application
//

#if !defined(AFX_SCRNSAVERPRODUCT_H__D3ECA257_B611_4B29_A39B_C822DDA4B040__INCLUDED_)
#define AFX_SCRNSAVERPRODUCT_H__D3ECA257_B611_4B29_A39B_C822DDA4B040__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScrnSaverProductApp:
// See ScrnSaverProduct.cpp for the implementation of this class
//

class CScrnSaverProductApp : public CWinApp
{
public:
	CScrnSaverProductApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrnSaverProductApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScrnSaverProductApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRNSAVERPRODUCT_H__D3ECA257_B611_4B29_A39B_C822DDA4B040__INCLUDED_)
