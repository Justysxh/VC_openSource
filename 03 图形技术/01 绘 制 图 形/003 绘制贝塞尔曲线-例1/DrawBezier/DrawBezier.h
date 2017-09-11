// DrawBezier.h : main header file for the DRAWBEZIER application
//

#if !defined(AFX_DRAWBEZIER_H__7919C495_6EBD_4059_B6E6_ABAB9BC032D3__INCLUDED_)
#define AFX_DRAWBEZIER_H__7919C495_6EBD_4059_B6E6_ABAB9BC032D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawBezierApp:
// See DrawBezier.cpp for the implementation of this class
//

class CDrawBezierApp : public CWinApp
{
public:
	CDrawBezierApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawBezierApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDrawBezierApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWBEZIER_H__7919C495_6EBD_4059_B6E6_ABAB9BC032D3__INCLUDED_)
