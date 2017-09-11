// ControlCdrom.h : main header file for the CONTROLCDROM application
//

#if !defined(AFX_CONTROLCDROM_H__B8C813AB_A0BA_496D_89DD_7ECC6F8ABE20__INCLUDED_)
#define AFX_CONTROLCDROM_H__B8C813AB_A0BA_496D_89DD_7ECC6F8ABE20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CControlCdromApp:
// See ControlCdrom.cpp for the implementation of this class
//

class CControlCdromApp : public CWinApp
{
public:
	CControlCdromApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlCdromApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CControlCdromApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLCDROM_H__B8C813AB_A0BA_496D_89DD_7ECC6F8ABE20__INCLUDED_)
