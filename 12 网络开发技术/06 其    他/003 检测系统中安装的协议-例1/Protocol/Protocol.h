// Protocol.h : main header file for the PROTOCOL application
//

#if !defined(AFX_PROTOCOL_H__DE7F6174_38E1_4F68_A838_1C49F966B5A7__INCLUDED_)
#define AFX_PROTOCOL_H__DE7F6174_38E1_4F68_A838_1C49F966B5A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProtocolApp:
// See Protocol.cpp for the implementation of this class
//

class CProtocolApp : public CWinApp
{
public:
	CProtocolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProtocolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProtocolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROTOCOL_H__DE7F6174_38E1_4F68_A838_1C49F966B5A7__INCLUDED_)
