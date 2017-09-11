// dtcjview.h : main header file for the DTCJVIEW application
//

#if !defined(AFX_DTCJVIEW_H__3A08A89D_CC8B_4337_B930_0CEFF8D62A75__INCLUDED_)
#define AFX_DTCJVIEW_H__3A08A89D_CC8B_4337_B930_0CEFF8D62A75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDtcjviewApp:
// See dtcjview.cpp for the implementation of this class
//

class CDtcjviewApp : public CWinApp
{
public:
	CDtcjviewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDtcjviewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDtcjviewApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DTCJVIEW_H__3A08A89D_CC8B_4337_B930_0CEFF8D62A75__INCLUDED_)
