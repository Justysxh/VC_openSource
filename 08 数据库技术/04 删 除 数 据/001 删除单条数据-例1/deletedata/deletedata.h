// deletedata.h : main header file for the DELETEDATA application
//

#if !defined(AFX_DELETEDATA_H__27120542_890A_43C8_A1DD_5FD88CCB3424__INCLUDED_)
#define AFX_DELETEDATA_H__27120542_890A_43C8_A1DD_5FD88CCB3424__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeletedataApp:
// See deletedata.cpp for the implementation of this class
//

class CDeletedataApp : public CWinApp
{
public:
	CDeletedataApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeletedataApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeletedataApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEDATA_H__27120542_890A_43C8_A1DD_5FD88CCB3424__INCLUDED_)
