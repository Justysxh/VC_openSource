// CPUAndDiskReg.h : main header file for the CPUANDDISKREG application
//

#if !defined(AFX_CPUANDDISKREG_H__F9426664_9879_4872_A9C9_57DC406EC9C3__INCLUDED_)
#define AFX_CPUANDDISKREG_H__F9426664_9879_4872_A9C9_57DC406EC9C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCPUAndDiskRegApp:
// See CPUAndDiskReg.cpp for the implementation of this class
//

class CCPUAndDiskRegApp : public CWinApp
{
public:
	CCPUAndDiskRegApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPUAndDiskRegApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCPUAndDiskRegApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUANDDISKREG_H__F9426664_9879_4872_A9C9_57DC406EC9C3__INCLUDED_)
