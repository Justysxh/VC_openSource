// DiskCata.h : main header file for the DISKCATA application
//

#if !defined(AFX_DISKCATA_H__8B5D2E67_D42A_4327_BDCB_8875B0C6BE85__INCLUDED_)
#define AFX_DISKCATA_H__8B5D2E67_D42A_4327_BDCB_8875B0C6BE85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDiskCataApp:
// See DiskCata.cpp for the implementation of this class
//

class CDiskCataApp : public CWinApp
{
public:
	CDiskCataApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskCataApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDiskCataApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKCATA_H__8B5D2E67_D42A_4327_BDCB_8875B0C6BE85__INCLUDED_)
