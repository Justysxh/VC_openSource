// DJtree.h : main header file for the DJTREE application
//

#if !defined(AFX_DJTREE_H__D7DCAB23_7234_4D4B_AB74_8941744FA9C1__INCLUDED_)
#define AFX_DJTREE_H__D7DCAB23_7234_4D4B_AB74_8941744FA9C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDJtreeApp:
// See DJtree.cpp for the implementation of this class
//

class CDJtreeApp : public CWinApp
{
public:
	CDJtreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDJtreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDJtreeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DJTREE_H__D7DCAB23_7234_4D4B_AB74_8941744FA9C1__INCLUDED_)
