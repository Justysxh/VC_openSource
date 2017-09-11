// OPENGLNURBS.h : main header file for the OPENGLNURBS application
//

#if !defined(AFX_OPENGLNURBS_H__F9E7AF9C_8306_43F3_AEE6_8B7046FF287D__INCLUDED_)
#define AFX_OPENGLNURBS_H__F9E7AF9C_8306_43F3_AEE6_8B7046FF287D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSApp:
// See OPENGLNURBS.cpp for the implementation of this class
//

class COPENGLNURBSApp : public CWinApp
{
public:
	COPENGLNURBSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COPENGLNURBSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COPENGLNURBSApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLNURBS_H__F9E7AF9C_8306_43F3_AEE6_8B7046FF287D__INCLUDED_)
