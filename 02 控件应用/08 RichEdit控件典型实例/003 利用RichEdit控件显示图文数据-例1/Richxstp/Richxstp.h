// Richxstp.h : main header file for the RICHXSTP application
//

#if !defined(AFX_RICHXSTP_H__3687D4E1_3D4C_45E7_95DD_E98FEDFE54DD__INCLUDED_)
#define AFX_RICHXSTP_H__3687D4E1_3D4C_45E7_95DD_E98FEDFE54DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRichxstpApp:
// See Richxstp.cpp for the implementation of this class
//

class CRichxstpApp : public CWinApp
{
public:
	CRichxstpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRichxstpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRichxstpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RICHXSTP_H__3687D4E1_3D4C_45E7_95DD_E98FEDFE54DD__INCLUDED_)
