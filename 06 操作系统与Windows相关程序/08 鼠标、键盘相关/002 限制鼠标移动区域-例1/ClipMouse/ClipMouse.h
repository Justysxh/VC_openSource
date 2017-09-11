// ClipMouse.h : main header file for the CLIPMOUSE application
//

#if !defined(AFX_CLIPMOUSE_H__4177D9A6_D34A_4901_B6B2_173615D51FC6__INCLUDED_)
#define AFX_CLIPMOUSE_H__4177D9A6_D34A_4901_B6B2_173615D51FC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClipMouseApp:
// See ClipMouse.cpp for the implementation of this class
//

class CClipMouseApp : public CWinApp
{
public:
	CClipMouseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipMouseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClipMouseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPMOUSE_H__4177D9A6_D34A_4901_B6B2_173615D51FC6__INCLUDED_)
