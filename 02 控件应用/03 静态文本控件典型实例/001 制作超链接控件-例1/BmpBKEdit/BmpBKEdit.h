// BmpBKEdit.h : main header file for the BMPBKEDIT application
//

#if !defined(AFX_BMPBKEDIT_H__7E1BF27C_77AA_43FF_A27D_67E0CC7080CA__INCLUDED_)
#define AFX_BMPBKEDIT_H__7E1BF27C_77AA_43FF_A27D_67E0CC7080CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBmpBKEditApp:
// See BmpBKEdit.cpp for the implementation of this class
//

class CBmpBKEditApp : public CWinApp
{
public:
	CBmpBKEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpBKEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBmpBKEditApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBKEDIT_H__7E1BF27C_77AA_43FF_A27D_67E0CC7080CA__INCLUDED_)
