// ToolTip.h : main header file for the TOOLTIP application
//

#if !defined(AFX_TOOLTIP_H__09733A2E_E90A_4027_9F94_CFF15CF30E9F__INCLUDED_)
#define AFX_TOOLTIP_H__09733A2E_E90A_4027_9F94_CFF15CF30E9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CToolTipApp:
// See ToolTip.cpp for the implementation of this class
//

class CToolTipApp : public CWinApp
{
public:
	CToolTipApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolTipApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CToolTipApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLTIP_H__09733A2E_E90A_4027_9F94_CFF15CF30E9F__INCLUDED_)
