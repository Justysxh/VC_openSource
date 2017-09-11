// DiskSpace.h : main header file for the DISKSPACE application
//

#if !defined(AFX_DISKSPACE_H__5BB75BAA_0003_463D_A403_D6E60437420E__INCLUDED_)
#define AFX_DISKSPACE_H__5BB75BAA_0003_463D_A403_D6E60437420E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDiskSpaceApp:
// See DiskSpace.cpp for the implementation of this class
//

class CDiskSpaceApp : public CWinApp
{
public:
	CDiskSpaceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskSpaceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDiskSpaceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKSPACE_H__5BB75BAA_0003_463D_A403_D6E60437420E__INCLUDED_)
