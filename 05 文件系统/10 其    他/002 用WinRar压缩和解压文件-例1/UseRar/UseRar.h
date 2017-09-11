// UseRar.h : main header file for the USERAR application
//

#if !defined(AFX_USERAR_H__50599614_9CAB_4AE3_9DC0_EBBC26CA537A__INCLUDED_)
#define AFX_USERAR_H__50599614_9CAB_4AE3_9DC0_EBBC26CA537A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseRarApp:
// See UseRar.cpp for the implementation of this class
//

class CUseRarApp : public CWinApp
{
public:
	CUseRarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseRarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseRarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERAR_H__50599614_9CAB_4AE3_9DC0_EBBC26CA537A__INCLUDED_)
