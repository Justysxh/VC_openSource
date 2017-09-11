// SerialInterface.h : main header file for the SERIALINTERFACE application
//

#if !defined(AFX_SERIALINTERFACE_H__8FA67D34_3AF3_4368_BDED_3154689BFBD8__INCLUDED_)
#define AFX_SERIALINTERFACE_H__8FA67D34_3AF3_4368_BDED_3154689BFBD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSerialInterfaceApp:
// See SerialInterface.cpp for the implementation of this class
//

class CSerialInterfaceApp : public CWinApp
{
public:
	CSerialInterfaceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialInterfaceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSerialInterfaceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALINTERFACE_H__8FA67D34_3AF3_4368_BDED_3154689BFBD8__INCLUDED_)
