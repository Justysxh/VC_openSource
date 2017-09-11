// BuildAvi.h : main header file for the BUILDAVI application
//

#if !defined(AFX_BUILDAVI_H__5636A272_EA0A_43E1_B061_7034EE7E5DD8__INCLUDED_)
#define AFX_BUILDAVI_H__5636A272_EA0A_43E1_B061_7034EE7E5DD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBuildAviApp:
// See BuildAvi.cpp for the implementation of this class
//

class CBuildAviApp : public CWinApp
{
public:
	CBuildAviApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBuildAviApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBuildAviApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUILDAVI_H__5636A272_EA0A_43E1_B061_7034EE7E5DD8__INCLUDED_)
