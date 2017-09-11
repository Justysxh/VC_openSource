// CDAutoRun.h : main header file for the CDAUTORUN application
//

#if !defined(AFX_CDAUTORUN_H__37E270BB_2378_4098_B48A_B910FDEF7233__INCLUDED_)
#define AFX_CDAUTORUN_H__37E270BB_2378_4098_B48A_B910FDEF7233__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCDAutoRunApp:
// See CDAutoRun.cpp for the implementation of this class
//

class CCDAutoRunApp : public CWinApp
{
public:
	CCDAutoRunApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDAutoRunApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCDAutoRunApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDAUTORUN_H__37E270BB_2378_4098_B48A_B910FDEF7233__INCLUDED_)
