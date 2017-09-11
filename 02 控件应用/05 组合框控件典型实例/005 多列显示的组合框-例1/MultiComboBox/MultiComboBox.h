// MultiComboBox.h : main header file for the MULTICOMBOBOX application
//

#if !defined(AFX_MULTICOMBOBOX_H__1DA877AB_1BF2_40FF_8D08_DC66047CE13B__INCLUDED_)
#define AFX_MULTICOMBOBOX_H__1DA877AB_1BF2_40FF_8D08_DC66047CE13B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiComboBoxApp:
// See MultiComboBox.cpp for the implementation of this class
//

class CMultiComboBoxApp : public CWinApp
{
public:
	CMultiComboBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiComboBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiComboBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTICOMBOBOX_H__1DA877AB_1BF2_40FF_8D08_DC66047CE13B__INCLUDED_)
