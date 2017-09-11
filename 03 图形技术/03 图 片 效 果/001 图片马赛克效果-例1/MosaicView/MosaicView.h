// MosaicView.h : main header file for the MOSAICVIEW application
//

#if !defined(AFX_MOSAICVIEW_H__D5500A18_3B76_448B_8086_8E70C3C810B0__INCLUDED_)
#define AFX_MOSAICVIEW_H__D5500A18_3B76_448B_8086_8E70C3C810B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewApp:
// See MosaicView.cpp for the implementation of this class
//

class CMosaicViewApp : public CWinApp
{
public:
	CMosaicViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMosaicViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMosaicViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOSAICVIEW_H__D5500A18_3B76_448B_8086_8E70C3C810B0__INCLUDED_)
