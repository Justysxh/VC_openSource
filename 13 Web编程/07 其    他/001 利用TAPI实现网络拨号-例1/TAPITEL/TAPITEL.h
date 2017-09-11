// TAPITEL.h : main header file for the TAPITEL application
//

#if !defined(AFX_TAPITEL_H__70935C44_95D0_43FA_8D82_27024525052A__INCLUDED_)
#define AFX_TAPITEL_H__70935C44_95D0_43FA_8D82_27024525052A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTAPITELApp:
// See TAPITEL.cpp for the implementation of this class
//

class CTAPITELApp : public CWinApp
{
public:
	CTAPITELApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTAPITELApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTAPITELApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAPITEL_H__70935C44_95D0_43FA_8D82_27024525052A__INCLUDED_)
