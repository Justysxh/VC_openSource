// barcode.h : main header file for the BARCODE application
//

#if !defined(AFX_BARCODE_H__8C1E90E3_000A_4147_82BD_1048D353195F__INCLUDED_)
#define AFX_BARCODE_H__8C1E90E3_000A_4147_82BD_1048D353195F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBarcodeApp:
// See barcode.cpp for the implementation of this class
//

class CBarcodeApp : public CWinApp
{
public:
	CBarcodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBarcodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBarcodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BARCODE_H__8C1E90E3_000A_4147_82BD_1048D353195F__INCLUDED_)
