// SemaphoreSynch.h : main header file for the SEMAPHORESYNCH application
//

#if !defined(AFX_SEMAPHORESYNCH_H__899FF657_80E1_471C_91AE_02A87F1B837E__INCLUDED_)
#define AFX_SEMAPHORESYNCH_H__899FF657_80E1_471C_91AE_02A87F1B837E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSemaphoreSynchApp:
// See SemaphoreSynch.cpp for the implementation of this class
//

class CSemaphoreSynchApp : public CWinApp
{
public:
	CSemaphoreSynchApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSemaphoreSynchApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSemaphoreSynchApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEMAPHORESYNCH_H__899FF657_80E1_471C_91AE_02A87F1B837E__INCLUDED_)
