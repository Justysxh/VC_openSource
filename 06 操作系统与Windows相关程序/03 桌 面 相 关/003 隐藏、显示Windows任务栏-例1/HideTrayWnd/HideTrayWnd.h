// HideTrayWnd.h : main header file for the HIDETRAYWND application
//

#if !defined(AFX_HIDETRAYWND_H__EF4FEF17_6663_499E_AC01_CAC43B71129B__INCLUDED_)
#define AFX_HIDETRAYWND_H__EF4FEF17_6663_499E_AC01_CAC43B71129B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHideTrayWndApp:
// See HideTrayWnd.cpp for the implementation of this class
//

class CHideTrayWndApp : public CWinApp
{
public:
	CHideTrayWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideTrayWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHideTrayWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDETRAYWND_H__EF4FEF17_6663_499E_AC01_CAC43B71129B__INCLUDED_)
