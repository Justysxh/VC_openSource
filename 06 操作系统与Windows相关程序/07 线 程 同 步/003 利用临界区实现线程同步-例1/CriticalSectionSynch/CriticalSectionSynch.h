// CriticalSectionSynch.h : main header file for the CRITICALSECTIONSYNCH application
//

#if !defined(AFX_CRITICALSECTIONSYNCH_H__8B705C14_602C_41D1_A045_42CCA8904ED6__INCLUDED_)
#define AFX_CRITICALSECTIONSYNCH_H__8B705C14_602C_41D1_A045_42CCA8904ED6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCriticalSectionSynchApp:
// See CriticalSectionSynch.cpp for the implementation of this class
//

class CCriticalSectionSynchApp : public CWinApp
{
public:
	CCriticalSectionSynchApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCriticalSectionSynchApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCriticalSectionSynchApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRITICALSECTIONSYNCH_H__8B705C14_602C_41D1_A045_42CCA8904ED6__INCLUDED_)
