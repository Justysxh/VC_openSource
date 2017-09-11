// OPENGLCube.h : main header file for the OPENGLCUBE application
//

#if !defined(AFX_OPENGLCUBE_H__EC1ADD54_9F27_4CB9_99C6_A9F0D7CE4AC0__INCLUDED_)
#define AFX_OPENGLCUBE_H__EC1ADD54_9F27_4CB9_99C6_A9F0D7CE4AC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeApp:
// See OPENGLCube.cpp for the implementation of this class
//

class COPENGLCubeApp : public CWinApp
{
public:
	COPENGLCubeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COPENGLCubeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COPENGLCubeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLCUBE_H__EC1ADD54_9F27_4CB9_99C6_A9F0D7CE4AC0__INCLUDED_)
