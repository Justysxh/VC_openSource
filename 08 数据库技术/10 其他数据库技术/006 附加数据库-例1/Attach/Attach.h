// Attach.h : main header file for the ATTACH application
//

#if !defined(AFX_ATTACH_H__01511FDC_C5B2_43BD_9F9B_124172C92751__INCLUDED_)
#define AFX_ATTACH_H__01511FDC_C5B2_43BD_9F9B_124172C92751__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAttachApp:
// See Attach.cpp for the implementation of this class
//

class CAttachApp : public CWinApp
{
public:
	CAttachApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttachApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAttachApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTACH_H__01511FDC_C5B2_43BD_9F9B_124172C92751__INCLUDED_)
