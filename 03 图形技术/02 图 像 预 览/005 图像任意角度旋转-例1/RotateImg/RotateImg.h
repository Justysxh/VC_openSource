// RotateImg.h : main header file for the ROTATEIMG application
//

#if !defined(AFX_ROTATEIMG_H__35E782CD_D52B_4860_A64A_EEBF69BBA638__INCLUDED_)
#define AFX_ROTATEIMG_H__35E782CD_D52B_4860_A64A_EEBF69BBA638__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRotateImgApp:
// See RotateImg.cpp for the implementation of this class
//

class CRotateImgApp : public CWinApp
{
public:
	CRotateImgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotateImgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRotateImgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEIMG_H__35E782CD_D52B_4860_A64A_EEBF69BBA638__INCLUDED_)
