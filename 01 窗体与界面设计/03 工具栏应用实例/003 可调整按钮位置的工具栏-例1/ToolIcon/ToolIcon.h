// ToolIcon.h : main header file for the TOOLICON application
//

#if !defined(AFX_TOOLICON_H__D3B31842_E904_47D5_ADCE_CC9062004348__INCLUDED_)
#define AFX_TOOLICON_H__D3B31842_E904_47D5_ADCE_CC9062004348__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CToolIconApp:
// See ToolIcon.cpp for the implementation of this class
//

class CToolIconApp : public CWinApp
{
public:
	CToolIconApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolIconApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CToolIconApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLICON_H__D3B31842_E904_47D5_ADCE_CC9062004348__INCLUDED_)
