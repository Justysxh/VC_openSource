// SizeStatusbar.h : main header file for the SIZESTATUSBAR application
//

#if !defined(AFX_SIZESTATUSBAR_H__CB0BE946_9726_4CEE_879D_9DA98466AF59__INCLUDED_)
#define AFX_SIZESTATUSBAR_H__CB0BE946_9726_4CEE_879D_9DA98466AF59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSizeStatusbarApp:
// See SizeStatusbar.cpp for the implementation of this class
//

class CSizeStatusbarApp : public CWinApp
{
public:
	CSizeStatusbarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSizeStatusbarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSizeStatusbarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIZESTATUSBAR_H__CB0BE946_9726_4CEE_879D_9DA98466AF59__INCLUDED_)
