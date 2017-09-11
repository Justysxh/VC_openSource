// DomainName.h : main header file for the DOMAINNAME application
//

#if !defined(AFX_DOMAINNAME_H__530FCD40_6A9D_46FA_8C78_F0846D6C9CDC__INCLUDED_)
#define AFX_DOMAINNAME_H__530FCD40_6A9D_46FA_8C78_F0846D6C9CDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDomainNameApp:
// See DomainName.cpp for the implementation of this class
//

class CDomainNameApp : public CWinApp
{
public:
	CDomainNameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDomainNameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDomainNameApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOMAINNAME_H__530FCD40_6A9D_46FA_8C78_F0846D6C9CDC__INCLUDED_)
