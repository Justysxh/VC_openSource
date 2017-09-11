// GraspBmp.h : main header file for the GRASPBMP application
//

#if !defined(AFX_GRASPBMP_H__1D9F793F_AD79_43A8_976D_BE6B256C8739__INCLUDED_)
#define AFX_GRASPBMP_H__1D9F793F_AD79_43A8_976D_BE6B256C8739__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGraspBmpApp:
// See GraspBmp.cpp for the implementation of this class
//

class CGraspBmpApp : public CWinApp
{
public:
	CGraspBmpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraspBmpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGraspBmpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRASPBMP_H__1D9F793F_AD79_43A8_976D_BE6B256C8739__INCLUDED_)
