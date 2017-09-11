// IFS.h : main header file for the IFS application
//

#if !defined(AFX_IFS_H__1A475B21_D5A5_4078_9382_CE3A981D7B39__INCLUDED_)
#define AFX_IFS_H__1A475B21_D5A5_4078_9382_CE3A981D7B39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CIFSApp:
// See IFS.cpp for the implementation of this class
//

class CIFSApp : public CWinApp
{
public:
	CIFSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIFSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CIFSApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFS_H__1A475B21_D5A5_4078_9382_CE3A981D7B39__INCLUDED_)
