// TextboxList.h : main header file for the TEXTBOXLIST application
//

#if !defined(AFX_TEXTBOXLIST_H__5CF65AD5_1E88_4B50_BE2F_1FB5CCC010ED__INCLUDED_)
#define AFX_TEXTBOXLIST_H__5CF65AD5_1E88_4B50_BE2F_1FB5CCC010ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextboxListApp:
// See TextboxList.cpp for the implementation of this class
//

class CTextboxListApp : public CWinApp
{
public:
	CTextboxListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextboxListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTextboxListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTBOXLIST_H__5CF65AD5_1E88_4B50_BE2F_1FB5CCC010ED__INCLUDED_)
