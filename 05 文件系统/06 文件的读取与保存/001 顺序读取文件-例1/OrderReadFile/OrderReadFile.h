// OrderReadFile.h : main header file for the ORDERREADFILE application
//

#if !defined(AFX_ORDERREADFILE_H__823B7418_B055_4F3F_950E_25F35F94867A__INCLUDED_)
#define AFX_ORDERREADFILE_H__823B7418_B055_4F3F_950E_25F35F94867A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COrderReadFileApp:
// See OrderReadFile.cpp for the implementation of this class
//

class COrderReadFileApp : public CWinApp
{
public:
	COrderReadFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderReadFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COrderReadFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERREADFILE_H__823B7418_B055_4F3F_950E_25F35F94867A__INCLUDED_)
