// MemoryState.h : main header file for the MEMORYSTATE application
//

#if !defined(AFX_MEMORYSTATE_H__62A89F9F_AFB0_4916_BDE3_54759C69EB91__INCLUDED_)
#define AFX_MEMORYSTATE_H__62A89F9F_AFB0_4916_BDE3_54759C69EB91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMemoryStateApp:
// See MemoryState.cpp for the implementation of this class
//

class CMemoryStateApp : public CWinApp
{
public:
	CMemoryStateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemoryStateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMemoryStateApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMORYSTATE_H__62A89F9F_AFB0_4916_BDE3_54759C69EB91__INCLUDED_)
