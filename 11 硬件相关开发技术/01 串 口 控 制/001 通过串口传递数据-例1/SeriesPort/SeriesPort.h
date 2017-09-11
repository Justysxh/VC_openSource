// SeriesPort.h : main header file for the SERIESPORT application
//

#if !defined(AFX_SERIESPORT_H__91095520_222C_498A_AC1E_5FF9720D7BDD__INCLUDED_)
#define AFX_SERIESPORT_H__91095520_222C_498A_AC1E_5FF9720D7BDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSeriesPortApp:
// See SeriesPort.cpp for the implementation of this class
//

class CSeriesPortApp : public CWinApp
{
public:
	CSeriesPortApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeriesPortApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSeriesPortApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIESPORT_H__91095520_222C_498A_AC1E_5FF9720D7BDD__INCLUDED_)
