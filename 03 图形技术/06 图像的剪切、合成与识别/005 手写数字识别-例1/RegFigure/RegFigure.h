// RegFigure.h : main header file for the REGFIGURE application
//

#if !defined(AFX_REGFIGURE_H__48A22B2B_BE11_43EF_BE38_07725EE510DD__INCLUDED_)
#define AFX_REGFIGURE_H__48A22B2B_BE11_43EF_BE38_07725EE510DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRegFigureApp:
// See RegFigure.cpp for the implementation of this class
//

class CRegFigureApp : public CWinApp
{
public:
	CRegFigureApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegFigureApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRegFigureApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGFIGURE_H__48A22B2B_BE11_43EF_BE38_07725EE510DD__INCLUDED_)
