// ThreadSynch.h : main header file for the THREADSYNCH application
//

#if !defined(AFX_THREADSYNCH_H__D7F879CA_90DE_42AB_899A_403F3EDEBD17__INCLUDED_)
#define AFX_THREADSYNCH_H__D7F879CA_90DE_42AB_899A_403F3EDEBD17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreadSynchApp:
// See ThreadSynch.cpp for the implementation of this class
//

class CThreadSynchApp : public CWinApp
{
public:
	CThreadSynchApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSynchApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreadSynchApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSYNCH_H__D7F879CA_90DE_42AB_899A_403F3EDEBD17__INCLUDED_)
