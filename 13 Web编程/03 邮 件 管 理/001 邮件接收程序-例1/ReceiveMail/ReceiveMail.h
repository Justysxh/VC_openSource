// ReceiveMail.h : main header file for the RECEIVEMAIL application
//

#if !defined(AFX_RECEIVEMAIL_H__F3ECE669_508B_4E8D_AB6C_E1FA2C3AAEF9__INCLUDED_)
#define AFX_RECEIVEMAIL_H__F3ECE669_508B_4E8D_AB6C_E1FA2C3AAEF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReceiveMailApp:
// See ReceiveMail.cpp for the implementation of this class
//

class CReceiveMailApp : public CWinApp
{
public:
	CReceiveMailApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReceiveMailApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReceiveMailApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECEIVEMAIL_H__F3ECE669_508B_4E8D_AB6C_E1FA2C3AAEF9__INCLUDED_)
