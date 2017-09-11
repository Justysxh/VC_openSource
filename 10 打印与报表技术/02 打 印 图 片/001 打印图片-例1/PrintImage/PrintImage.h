// PrintImage.h : main header file for the PRINTIMAGE application
//

#if !defined(AFX_PRINTIMAGE_H__374C11F0_8BFF_4B30_8EC2_F82848BC9B1A__INCLUDED_)
#define AFX_PRINTIMAGE_H__374C11F0_8BFF_4B30_8EC2_F82848BC9B1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintImageApp:
// See PrintImage.cpp for the implementation of this class
//

class CPrintImageApp : public CWinApp
{
public:
	CPrintImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintImageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrintImageApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTIMAGE_H__374C11F0_8BFF_4B30_8EC2_F82848BC9B1A__INCLUDED_)
