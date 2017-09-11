// SQLframe.h : main header file for the SQLFRAME application
//

#if !defined(AFX_SQLFRAME_H__EC888016_0310_4E3F_BBED_89A09C3A3470__INCLUDED_)
#define AFX_SQLFRAME_H__EC888016_0310_4E3F_BBED_89A09C3A3470__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSQLframeApp:
// See SQLframe.cpp for the implementation of this class
//

class CSQLframeApp : public CWinApp
{
public:
	CSQLframeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSQLframeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSQLframeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQLFRAME_H__EC888016_0310_4E3F_BBED_89A09C3A3470__INCLUDED_)
