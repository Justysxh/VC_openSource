// GetProp.h : main header file for the GETPROP application
//

#if !defined(AFX_GETPROP_H__9AC49977_9C49_4989_8828_7DA0EA22524B__INCLUDED_)
#define AFX_GETPROP_H__9AC49977_9C49_4989_8828_7DA0EA22524B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetPropApp:
// See GetProp.cpp for the implementation of this class
//

class CGetPropApp : public CWinApp
{
public:
	CGetPropApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPropApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetPropApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPROP_H__9AC49977_9C49_4989_8828_7DA0EA22524B__INCLUDED_)
