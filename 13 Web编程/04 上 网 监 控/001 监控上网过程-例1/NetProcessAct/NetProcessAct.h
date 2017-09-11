// NetProcessAct.h : main header file for the NETPROCESSACT application
//

#if !defined(AFX_NETPROCESSACT_H__609A88F8_DD7F_409F_BA0B_F4A89B520EDB__INCLUDED_)
#define AFX_NETPROCESSACT_H__609A88F8_DD7F_409F_BA0B_F4A89B520EDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetProcessActApp:
// See NetProcessAct.cpp for the implementation of this class
//

class CNetProcessActApp : public CWinApp
{
public:
	CNetProcessActApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetProcessActApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetProcessActApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETPROCESSACT_H__609A88F8_DD7F_409F_BA0B_F4A89B520EDB__INCLUDED_)
