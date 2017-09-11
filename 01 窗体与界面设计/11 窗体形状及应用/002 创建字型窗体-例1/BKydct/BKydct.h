// BKydct.h : main header file for the BKYDCT application
//

#if !defined(AFX_BKYDCT_H__A9A38319_24F5_4A8B_BB7B_66FED57A93C3__INCLUDED_)
#define AFX_BKYDCT_H__A9A38319_24F5_4A8B_BB7B_66FED57A93C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBKydctApp:
// See BKydct.cpp for the implementation of this class
//

class CBKydctApp : public CWinApp
{
public:
	CBKydctApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBKydctApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBKydctApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BKYDCT_H__A9A38319_24F5_4A8B_BB7B_66FED57A93C3__INCLUDED_)
