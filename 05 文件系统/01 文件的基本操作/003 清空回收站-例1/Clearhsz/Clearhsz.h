// Clearhsz.h : main header file for the CLEARHSZ application
//

#if !defined(AFX_CLEARHSZ_H__2338DA49_B38F_43D4_A259_DDEAF40D53EF__INCLUDED_)
#define AFX_CLEARHSZ_H__2338DA49_B38F_43D4_A259_DDEAF40D53EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClearhszApp:
// See Clearhsz.cpp for the implementation of this class
//

class CClearhszApp : public CWinApp
{
public:
	CClearhszApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClearhszApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClearhszApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLEARHSZ_H__2338DA49_B38F_43D4_A259_DDEAF40D53EF__INCLUDED_)
