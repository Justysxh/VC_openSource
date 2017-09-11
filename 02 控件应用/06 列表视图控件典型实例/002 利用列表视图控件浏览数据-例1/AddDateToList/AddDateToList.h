// AddDateToList.h : main header file for the ADDDATETOLIST application
//

#if !defined(AFX_ADDDATETOLIST_H__D11909C8_B03F_4B90_8D4E_48C873658C04__INCLUDED_)
#define AFX_ADDDATETOLIST_H__D11909C8_B03F_4B90_8D4E_48C873658C04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAddDateToListApp:
// See AddDateToList.cpp for the implementation of this class
//

class CAddDateToListApp : public CWinApp
{
public:
	CAddDateToListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddDateToListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAddDateToListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDATETOLIST_H__D11909C8_B03F_4B90_8D4E_48C873658C04__INCLUDED_)
