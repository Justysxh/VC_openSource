// KeyboardNumLamp.h : main header file for the KEYBOARDNUMLAMP application
//

#if !defined(AFX_KEYBOARDNUMLAMP_H__885962A0_38F0_46E1_B955_F2EAF6567DD9__INCLUDED_)
#define AFX_KEYBOARDNUMLAMP_H__885962A0_38F0_46E1_B955_F2EAF6567DD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKeyboardNumLampApp:
// See KeyboardNumLamp.cpp for the implementation of this class
//

class CKeyboardNumLampApp : public CWinApp
{
public:
	CKeyboardNumLampApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyboardNumLampApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKeyboardNumLampApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYBOARDNUMLAMP_H__885962A0_38F0_46E1_B955_F2EAF6567DD9__INCLUDED_)
