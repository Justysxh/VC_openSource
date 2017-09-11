// ToolHint.h : main header file for the TOOLHINT application
//

#if !defined(AFX_TOOLHINT_H__F41E4085_5FE5_4DDF_94A3_B3AD58089741__INCLUDED_)
#define AFX_TOOLHINT_H__F41E4085_5FE5_4DDF_94A3_B3AD58089741__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CToolHintApp:
// See ToolHint.cpp for the implementation of this class
//

class CToolHintApp : public CWinApp
{
public:
	CToolHintApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolHintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CToolHintApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLHINT_H__F41E4085_5FE5_4DDF_94A3_B3AD58089741__INCLUDED_)
