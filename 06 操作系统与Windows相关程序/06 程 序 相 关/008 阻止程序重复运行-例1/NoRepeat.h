// NoRepeat.h : main header file for the NOREPEAT application
//

#if !defined(AFX_NOREPEAT_H__14EE9E9F_D65F_4686_B9CD_5944E87C541D__INCLUDED_)
#define AFX_NOREPEAT_H__14EE9E9F_D65F_4686_B9CD_5944E87C541D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNoRepeatApp:
// See NoRepeat.cpp for the implementation of this class
//

class CNoRepeatApp : public CWinApp
{
public:
	CNoRepeatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoRepeatApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNoRepeatApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOREPEAT_H__14EE9E9F_D65F_4686_B9CD_5944E87C541D__INCLUDED_)
