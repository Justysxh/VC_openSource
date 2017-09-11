// modview.h : main header file for the MODVIEW application
//

#if !defined(AFX_MODVIEW_H__E94CA70E_CA9B_4099_830E_4ECB89F4A76C__INCLUDED_)
#define AFX_MODVIEW_H__E94CA70E_CA9B_4099_830E_4ECB89F4A76C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CModviewApp:
// See modview.cpp for the implementation of this class
//

class CModviewApp : public CWinApp
{
public:
	CModviewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModviewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CModviewApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODVIEW_H__E94CA70E_CA9B_4099_830E_4ECB89F4A76C__INCLUDED_)
