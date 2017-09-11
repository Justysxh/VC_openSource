// ScanManage.h : main header file for the SCANMANAGE application
//

#if !defined(AFX_SCANMANAGE_H__DDA3A691_D264_473B_B0E9_88288C97DF94__INCLUDED_)
#define AFX_SCANMANAGE_H__DDA3A691_D264_473B_B0E9_88288C97DF94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScanManageApp:
// See ScanManage.cpp for the implementation of this class
//

class CScanManageApp : public CWinApp
{
public:
	CScanManageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScanManageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScanManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCANMANAGE_H__DDA3A691_D264_473B_B0E9_88288C97DF94__INCLUDED_)
