// ReverseColor.h : main header file for the REVERSECOLOR application
//

#if !defined(AFX_REVERSECOLOR_H__ABA74A88_8E4A_42C1_A4F7_40FD87D51A5D__INCLUDED_)
#define AFX_REVERSECOLOR_H__ABA74A88_8E4A_42C1_A4F7_40FD87D51A5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReverseColorApp:
// See ReverseColor.cpp for the implementation of this class
//

class CReverseColorApp : public CWinApp
{
public:
	CReverseColorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReverseColorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReverseColorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REVERSECOLOR_H__ABA74A88_8E4A_42C1_A4F7_40FD87D51A5D__INCLUDED_)
