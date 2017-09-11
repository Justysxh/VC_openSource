// ADOdatabase.h : main header file for the ADODATABASE application
//

#if !defined(AFX_ADODATABASE_H__4E4277A3_F586_40B7_A00D_543BA5FA2984__INCLUDED_)
#define AFX_ADODATABASE_H__4E4277A3_F586_40B7_A00D_543BA5FA2984__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CADOdatabaseApp:
// See ADOdatabase.cpp for the implementation of this class
//

class CADOdatabaseApp : public CWinApp
{
public:
	CADOdatabaseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOdatabaseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADOdatabaseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATABASE_H__4E4277A3_F586_40B7_A00D_543BA5FA2984__INCLUDED_)
