// SniffApp.h : main header file for the SNIFFAPP application
//

#if !defined(AFX_SNIFFAPP_H__2D147315_8DFA_4AD1_9CA1_7C609AB716B0__INCLUDED_)
#define AFX_SNIFFAPP_H__2D147315_8DFA_4AD1_9CA1_7C609AB716B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSniffAppApp:
// See SniffApp.cpp for the implementation of this class
//
#include "winsock2.h"
#pragma comment (lib,"ws2_32.lib")
#include "AFXSOCK.H"

class CSniffAppApp : public CWinApp
{
public:
	CSniffAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSniffAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSniffAppApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNIFFAPP_H__2D147315_8DFA_4AD1_9CA1_7C609AB716B0__INCLUDED_)
