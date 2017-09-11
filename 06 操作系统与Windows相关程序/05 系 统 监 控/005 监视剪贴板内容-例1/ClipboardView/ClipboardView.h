// ClipboardView.h : main header file for the CLIPBOARDVIEW application
//

#if !defined(AFX_CLIPBOARDVIEW_H__4EC63C63_465E_46FC_AE25_A12F0261DFBE__INCLUDED_)
#define AFX_CLIPBOARDVIEW_H__4EC63C63_465E_46FC_AE25_A12F0261DFBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClipboardViewApp:
// See ClipboardView.cpp for the implementation of this class
//

class CClipboardViewApp : public CWinApp
{
public:
	CClipboardViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipboardViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClipboardViewApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPBOARDVIEW_H__4EC63C63_465E_46FC_AE25_A12F0261DFBE__INCLUDED_)
