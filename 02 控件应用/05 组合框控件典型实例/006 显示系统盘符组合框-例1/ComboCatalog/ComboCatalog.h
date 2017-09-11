// ComboCatalog.h : main header file for the COMBOCATALOG application
//

#if !defined(AFX_COMBOCATALOG_H__3EC6AB0C_63B1_477F_AC9C_9E854E395B8E__INCLUDED_)
#define AFX_COMBOCATALOG_H__3EC6AB0C_63B1_477F_AC9C_9E854E395B8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CComboCatalogApp:
// See ComboCatalog.cpp for the implementation of this class
//

class CComboCatalogApp : public CWinApp
{
public:
	CComboCatalogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboCatalogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CComboCatalogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOCATALOG_H__3EC6AB0C_63B1_477F_AC9C_9E854E395B8E__INCLUDED_)
