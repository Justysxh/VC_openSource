// FormatDriver.h : main header file for the FORMATDRIVER application
//

#if !defined(AFX_FORMATDRIVER_H__291A7D93_5412_4B92_98D8_568DD3AADA73__INCLUDED_)
#define AFX_FORMATDRIVER_H__291A7D93_5412_4B92_98D8_568DD3AADA73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFormatDriverApp:
// See FormatDriver.cpp for the implementation of this class
//

class CFormatDriverApp : public CWinApp
{
public:
	CFormatDriverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormatDriverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFormatDriverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMATDRIVER_H__291A7D93_5412_4B92_98D8_568DD3AADA73__INCLUDED_)
