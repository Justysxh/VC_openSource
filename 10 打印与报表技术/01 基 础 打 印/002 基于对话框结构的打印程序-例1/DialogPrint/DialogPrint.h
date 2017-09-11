// DialogPrint.h : main header file for the DIALOGPRINT application
//

#if !defined(AFX_DIALOGPRINT_H__57EF3FC2_A0B7_4B0E_9C7C_14D0AF9CD930__INCLUDED_)
#define AFX_DIALOGPRINT_H__57EF3FC2_A0B7_4B0E_9C7C_14D0AF9CD930__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogPrintApp:
// See DialogPrint.cpp for the implementation of this class
//

class CDialogPrintApp : public CWinApp
{
public:
	CDialogPrintApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogPrintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialogPrintApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGPRINT_H__57EF3FC2_A0B7_4B0E_9C7C_14D0AF9CD930__INCLUDED_)
