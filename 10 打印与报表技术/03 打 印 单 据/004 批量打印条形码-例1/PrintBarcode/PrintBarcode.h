// PrintBarcode.h : main header file for the PRINTBARCODE application
//

#if !defined(AFX_PRINTBARCODE_H__D1656DB6_0269_4310_8BE7_9365E4A432CE__INCLUDED_)
#define AFX_PRINTBARCODE_H__D1656DB6_0269_4310_8BE7_9365E4A432CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintBarcodeApp:
// See PrintBarcode.cpp for the implementation of this class
//

class CPrintBarcodeApp : public CWinApp
{
public:
	CPrintBarcodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintBarcodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrintBarcodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTBARCODE_H__D1656DB6_0269_4310_8BE7_9365E4A432CE__INCLUDED_)
