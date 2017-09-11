// PictureOverturn.h : main header file for the PICTUREOVERTURN application
//

#if !defined(AFX_PICTUREOVERTURN_H__2C519D87_19F1_401B_A998_4E3227CB969A__INCLUDED_)
#define AFX_PICTUREOVERTURN_H__2C519D87_19F1_401B_A998_4E3227CB969A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnApp:
// See PictureOverturn.cpp for the implementation of this class
//

class CPictureOverturnApp : public CWinApp
{
public:
	CPictureOverturnApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureOverturnApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPictureOverturnApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREOVERTURN_H__2C519D87_19F1_401B_A998_4E3227CB969A__INCLUDED_)
