// OutInterface.h : main header file for the OUTINTERFACE application
//

#if !defined(AFX_OUTINTERFACE_H__830A182F_4286_4C20_9FAE_CC7C205ED481__INCLUDED_)
#define AFX_OUTINTERFACE_H__830A182F_4286_4C20_9FAE_CC7C205ED481__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COutInterfaceApp:
// See OutInterface.cpp for the implementation of this class
//

class COutInterfaceApp : public CWinApp
{
public:
	COutInterfaceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutInterfaceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COutInterfaceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTINTERFACE_H__830A182F_4286_4C20_9FAE_CC7C205ED481__INCLUDED_)
