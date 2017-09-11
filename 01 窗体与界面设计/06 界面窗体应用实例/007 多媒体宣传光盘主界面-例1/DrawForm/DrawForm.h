// DrawForm.h : main header file for the DRAWFORM application
//

#if !defined(AFX_DRAWFORM_H__61089531_AABC_476F_802C_8A29A17D1F0E__INCLUDED_)
#define AFX_DRAWFORM_H__61089531_AABC_476F_802C_8A29A17D1F0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawFormApp:
// See DrawForm.cpp for the implementation of this class
//

class CDrawFormApp : public CWinApp
{
public:
	CDrawFormApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawFormApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDrawFormApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWFORM_H__61089531_AABC_476F_802C_8A29A17D1F0E__INCLUDED_)
