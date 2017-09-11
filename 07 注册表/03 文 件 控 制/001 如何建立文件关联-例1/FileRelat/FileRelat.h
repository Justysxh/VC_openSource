// FileRelat.h : main header file for the FILERELAT application
//

#if !defined(AFX_FILERELAT_H__DD87DE2B_3781_4549_9497_4FB34F164B3F__INCLUDED_)
#define AFX_FILERELAT_H__DD87DE2B_3781_4549_9497_4FB34F164B3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileRelatApp:
// See FileRelat.cpp for the implementation of this class
//

class CFileRelatApp : public CWinApp
{
public:
	CFileRelatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileRelatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileRelatApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILERELAT_H__DD87DE2B_3781_4549_9497_4FB34F164B3F__INCLUDED_)
