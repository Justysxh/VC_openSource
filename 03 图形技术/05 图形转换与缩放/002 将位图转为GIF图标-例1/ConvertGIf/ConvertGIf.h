// ConvertGIf.h : main header file for the CONVERTGIF application
//

#if !defined(AFX_CONVERTGIF_H__43D2C321_F99B_404A_8B92_8AD063C47CD4__INCLUDED_)
#define AFX_CONVERTGIF_H__43D2C321_F99B_404A_8B92_8AD063C47CD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CConvertGIfApp:
// See ConvertGIf.cpp for the implementation of this class
//

class CConvertGIfApp : public CWinApp
{
public:
	CConvertGIfApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertGIfApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CConvertGIfApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTGIF_H__43D2C321_F99B_404A_8B92_8AD063C47CD4__INCLUDED_)
