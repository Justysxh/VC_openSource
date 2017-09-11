// Affair.h : main header file for the AFFAIR application
//

#if !defined(AFX_AFFAIR_H__E6D66F59_170E_44E3_B886_48AF17C38511__INCLUDED_)
#define AFX_AFFAIR_H__E6D66F59_170E_44E3_B886_48AF17C38511__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAffairApp:
// See Affair.cpp for the implementation of this class
//

class CAffairApp : public CWinApp
{
public:
	CAffairApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAffairApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAffairApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AFFAIR_H__E6D66F59_170E_44E3_B886_48AF17C38511__INCLUDED_)
