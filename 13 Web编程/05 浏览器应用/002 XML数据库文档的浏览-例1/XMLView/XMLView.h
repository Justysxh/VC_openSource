// XMLView.h : main header file for the XMLVIEW application
//

#if !defined(AFX_XMLVIEW_H__85E9FFE4_75D2_4B8F_93F5_57C3735C550F__INCLUDED_)
#define AFX_XMLVIEW_H__85E9FFE4_75D2_4B8F_93F5_57C3735C550F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CXMLViewApp:
// See XMLView.cpp for the implementation of this class
//

class CXMLViewApp : public CWinApp
{
public:
	CXMLViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMLViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CXMLViewApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLVIEW_H__85E9FFE4_75D2_4B8F_93F5_57C3735C550F__INCLUDED_)
