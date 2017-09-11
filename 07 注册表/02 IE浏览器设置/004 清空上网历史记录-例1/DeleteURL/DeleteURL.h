// DeleteURL.h : main header file for the DELETEURL application
//

#if !defined(AFX_DELETEURL_H__551E0432_62C2_4200_9D54_5CA60843D69A__INCLUDED_)
#define AFX_DELETEURL_H__551E0432_62C2_4200_9D54_5CA60843D69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeleteURLApp:
// See DeleteURL.cpp for the implementation of this class
//

class CDeleteURLApp : public CWinApp
{
public:
	CDeleteURLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteURLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeleteURLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEURL_H__551E0432_62C2_4200_9D54_5CA60843D69A__INCLUDED_)
