// JXquery.h : main header file for the JXQUERY application
//

#if !defined(AFX_JXQUERY_H__C67C04A7_7994_4E22_95A7_E50D48E0802A__INCLUDED_)
#define AFX_JXQUERY_H__C67C04A7_7994_4E22_95A7_E50D48E0802A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJXqueryApp:
// See JXquery.cpp for the implementation of this class
//

class CJXqueryApp : public CWinApp
{
public:
	CJXqueryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJXqueryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJXqueryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JXQUERY_H__C67C04A7_7994_4E22_95A7_E50D48E0802A__INCLUDED_)
