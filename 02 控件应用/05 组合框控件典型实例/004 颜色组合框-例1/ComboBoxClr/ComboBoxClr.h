// ComboBoxClr.h : main header file for the COMBOBOXCLR application
//

#if !defined(AFX_COMBOBOXCLR_H__C49FC7DC_4BE7_42A8_A86C_ED975C7F12C3__INCLUDED_)
#define AFX_COMBOBOXCLR_H__C49FC7DC_4BE7_42A8_A86C_ED975C7F12C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CComboBoxClrApp:
// See ComboBoxClr.cpp for the implementation of this class
//

class CComboBoxClrApp : public CWinApp
{
public:
	CComboBoxClrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboBoxClrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CComboBoxClrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOBOXCLR_H__C49FC7DC_4BE7_42A8_A86C_ED975C7F12C3__INCLUDED_)
