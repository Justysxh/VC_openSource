// sumquery.h : main header file for the SUMQUERY application
//

#if !defined(AFX_SUMQUERY_H__2948C14D_90BC_41C7_B2B0_9B6AD56FD812__INCLUDED_)
#define AFX_SUMQUERY_H__2948C14D_90BC_41C7_B2B0_9B6AD56FD812__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSumqueryApp:
// See sumquery.cpp for the implementation of this class
//

class CSumqueryApp : public CWinApp
{
public:
	CSumqueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSumqueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSumqueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUMQUERY_H__2948C14D_90BC_41C7_B2B0_9B6AD56FD812__INCLUDED_)
