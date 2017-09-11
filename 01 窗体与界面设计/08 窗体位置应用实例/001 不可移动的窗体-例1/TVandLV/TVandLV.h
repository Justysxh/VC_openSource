// TVandLV.h : main header file for the TVANDLV application
//

#if !defined(AFX_TVANDLV_H__C23E84D5_7426_4408_AD31_CC03EFB3C878__INCLUDED_)
#define AFX_TVANDLV_H__C23E84D5_7426_4408_AD31_CC03EFB3C878__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTVandLVApp:
// See TVandLV.cpp for the implementation of this class
//

class CTVandLVApp : public CWinApp
{
public:
	CTVandLVApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTVandLVApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTVandLVApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TVANDLV_H__C23E84D5_7426_4408_AD31_CC03EFB3C878__INCLUDED_)
