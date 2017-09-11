// DataManage.h : main header file for the DATAMANAGE application
//

#if !defined(AFX_DATAMANAGE_H__51F2458B_E7CC_4D0A_8F7B_89D4FFAD436E__INCLUDED_)
#define AFX_DATAMANAGE_H__51F2458B_E7CC_4D0A_8F7B_89D4FFAD436E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDataManageApp:
// See DataManage.cpp for the implementation of this class
//

class CDataManageApp : public CWinApp
{
public:
	CDataManageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataManageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDataManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAMANAGE_H__51F2458B_E7CC_4D0A_8F7B_89D4FFAD436E__INCLUDED_)
