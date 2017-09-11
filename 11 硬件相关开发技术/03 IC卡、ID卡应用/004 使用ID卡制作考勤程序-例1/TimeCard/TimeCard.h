// TimeCard.h : main header file for the TIMECARD application
//

#if !defined(AFX_TIMECARD_H__5AB540A8_9BD3_42C5_B7E9_903B73B0A841__INCLUDED_)
#define AFX_TIMECARD_H__5AB540A8_9BD3_42C5_B7E9_903B73B0A841__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimeCardApp:
// See TimeCard.cpp for the implementation of this class
//

class CTimeCardApp : public CWinApp
{
public:
	CTimeCardApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeCardApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTimeCardApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECARD_H__5AB540A8_9BD3_42C5_B7E9_903B73B0A841__INCLUDED_)
