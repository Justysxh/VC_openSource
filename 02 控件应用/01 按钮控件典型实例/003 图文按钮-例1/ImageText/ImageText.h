// ImageText.h : main header file for the IMAGETEXT application
//

#if !defined(AFX_IMAGETEXT_H__EE5ABC3E_79CA_4200_A263_34CF419508F6__INCLUDED_)
#define AFX_IMAGETEXT_H__EE5ABC3E_79CA_4200_A263_34CF419508F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CImageTextApp:
// See ImageText.cpp for the implementation of this class
//

class CImageTextApp : public CWinApp
{
public:
	CImageTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CImageTextApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETEXT_H__EE5ABC3E_79CA_4200_A263_34CF419508F6__INCLUDED_)
