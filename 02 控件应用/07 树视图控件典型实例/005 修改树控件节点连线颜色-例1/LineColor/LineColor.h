// LineColor.h : main header file for the LINECOLOR application
//

#if !defined(AFX_LINECOLOR_H__ED1D93B4_5E36_417B_A596_2F966A3B080B__INCLUDED_)
#define AFX_LINECOLOR_H__ED1D93B4_5E36_417B_A596_2F966A3B080B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLineColorApp:
// See LineColor.cpp for the implementation of this class
//

class CLineColorApp : public CWinApp
{
public:
	CLineColorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineColorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLineColorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINECOLOR_H__ED1D93B4_5E36_417B_A596_2F966A3B080B__INCLUDED_)
