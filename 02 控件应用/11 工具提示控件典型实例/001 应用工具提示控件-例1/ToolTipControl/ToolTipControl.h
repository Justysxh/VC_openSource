// ToolTipControl.h : main header file for the TOOLTIPCONTROL application
//

#if !defined(AFX_TOOLTIPCONTROL_H__4DEA2216_6FD3_4CFA_B021_23918DC89EDA__INCLUDED_)
#define AFX_TOOLTIPCONTROL_H__4DEA2216_6FD3_4CFA_B021_23918DC89EDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CToolTipControlApp:
// See ToolTipControl.cpp for the implementation of this class
//

class CToolTipControlApp : public CWinApp
{
public:
	CToolTipControlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolTipControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CToolTipControlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLTIPCONTROL_H__4DEA2216_6FD3_4CFA_B021_23918DC89EDA__INCLUDED_)
