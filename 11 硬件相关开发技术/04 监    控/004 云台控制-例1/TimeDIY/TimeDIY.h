// TimeDIY.h : main header file for the TIMEDIY application
//

#if !defined(AFX_TIMEDIY_H__9557A45A_2013_4B5A_B39B_5911F973FE17__INCLUDED_)
#define AFX_TIMEDIY_H__9557A45A_2013_4B5A_B39B_5911F973FE17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimeDIYApp:
// See TimeDIY.cpp for the implementation of this class
//

class CTimeDIYApp : public CWinApp
{
public:
	CTimeDIYApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeDIYApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTimeDIYApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEDIY_H__9557A45A_2013_4B5A_B39B_5911F973FE17__INCLUDED_)
