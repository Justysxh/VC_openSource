// delsave.h : main header file for the DELSAVE application
//

#if !defined(AFX_DELSAVE_H__61C84454_8F86_46F0_AFFF_0E1B05F099F4__INCLUDED_)
#define AFX_DELSAVE_H__61C84454_8F86_46F0_AFFF_0E1B05F099F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDelsaveApp:
// See delsave.cpp for the implementation of this class
//

class CDelsaveApp : public CWinApp
{
public:
	CDelsaveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelsaveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDelsaveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELSAVE_H__61C84454_8F86_46F0_AFFF_0E1B05F099F4__INCLUDED_)
