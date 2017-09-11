// EventSynch.h : main header file for the EVENTSYNCH application
//

#if !defined(AFX_EVENTSYNCH_H__A818798D_7566_4B82_9C63_25A2566F19F9__INCLUDED_)
#define AFX_EVENTSYNCH_H__A818798D_7566_4B82_9C63_25A2566F19F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEventSynchApp:
// See EventSynch.cpp for the implementation of this class
//

class CEventSynchApp : public CWinApp
{
public:
	CEventSynchApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEventSynchApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEventSynchApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EVENTSYNCH_H__A818798D_7566_4B82_9C63_25A2566F19F9__INCLUDED_)
