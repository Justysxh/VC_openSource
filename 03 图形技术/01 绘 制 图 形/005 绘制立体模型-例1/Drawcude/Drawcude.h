// Drawcude.h : main header file for the DRAWCUDE application
//

#if !defined(AFX_DRAWCUDE_H__5060AAC4_C48E_426E_A6AE_D7A82743B6CC__INCLUDED_)
#define AFX_DRAWCUDE_H__5060AAC4_C48E_426E_A6AE_D7A82743B6CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawcudeApp:
// See Drawcude.cpp for the implementation of this class
//

class CDrawcudeApp : public CWinApp
{
public:
	CDrawcudeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawcudeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDrawcudeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCUDE_H__5060AAC4_C48E_426E_A6AE_D7A82743B6CC__INCLUDED_)
