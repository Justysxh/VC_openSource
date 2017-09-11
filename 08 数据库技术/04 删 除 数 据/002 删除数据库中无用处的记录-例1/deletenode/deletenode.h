// deletenode.h : main header file for the DELETENODE application
//

#if !defined(AFX_DELETENODE_H__4EF8A40C_0A36_48AF_82ED_56C9D8DBF2B2__INCLUDED_)
#define AFX_DELETENODE_H__4EF8A40C_0A36_48AF_82ED_56C9D8DBF2B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeletenodeApp:
// See deletenode.cpp for the implementation of this class
//

class CDeletenodeApp : public CWinApp
{
public:
	CDeletenodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeletenodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeletenodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETENODE_H__4EF8A40C_0A36_48AF_82ED_56C9D8DBF2B2__INCLUDED_)
