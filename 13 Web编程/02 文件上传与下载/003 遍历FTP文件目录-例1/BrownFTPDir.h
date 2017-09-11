// BrownFTPDir.h : main header file for the BROWNFTPDIR application
//

#if !defined(AFX_BROWNFTPDIR_H__418A7684_8BCE_4162_8E9A_4605199BFC72__INCLUDED_)
#define AFX_BROWNFTPDIR_H__418A7684_8BCE_4162_8E9A_4605199BFC72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBrownFTPDirApp:
// See BrownFTPDir.cpp for the implementation of this class
//

class CBrownFTPDirApp : public CWinApp
{
public:
	CBrownFTPDirApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrownFTPDirApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBrownFTPDirApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWNFTPDIR_H__418A7684_8BCE_4162_8E9A_4605199BFC72__INCLUDED_)
