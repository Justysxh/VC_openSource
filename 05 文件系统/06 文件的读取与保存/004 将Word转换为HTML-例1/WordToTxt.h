// WordToTxt.h : main header file for the WORDTOTXT application
//

#if !defined(AFX_WORDTOTXT_H__FB8BFFB3_FB70_4B51_A8D6_5203F1102C65__INCLUDED_)
#define AFX_WORDTOTXT_H__FB8BFFB3_FB70_4B51_A8D6_5203F1102C65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWordToTxtApp:
// See WordToTxt.cpp for the implementation of this class
//

class CWordToTxtApp : public CWinApp
{
public:
	CWordToTxtApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordToTxtApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWordToTxtApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDTOTXT_H__FB8BFFB3_FB70_4B51_A8D6_5203F1102C65__INCLUDED_)
