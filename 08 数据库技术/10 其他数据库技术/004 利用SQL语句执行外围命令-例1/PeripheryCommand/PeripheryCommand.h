// PeripheryCommand.h : main header file for the PERIPHERYCOMMAND application
//

#if !defined(AFX_PERIPHERYCOMMAND_H__0AE8C8E3_F908_45A1_843E_1A75587DABA5__INCLUDED_)
#define AFX_PERIPHERYCOMMAND_H__0AE8C8E3_F908_45A1_843E_1A75587DABA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPeripheryCommandApp:
// See PeripheryCommand.cpp for the implementation of this class
//

class CPeripheryCommandApp : public CWinApp
{
public:
	CPeripheryCommandApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPeripheryCommandApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPeripheryCommandApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERIPHERYCOMMAND_H__0AE8C8E3_F908_45A1_843E_1A75587DABA5__INCLUDED_)
