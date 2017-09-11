// ReadWriteXML.h : main header file for the READWRITEXML application
//

#if !defined(AFX_READWRITEXML_H__EF3C5104_31B1_4B03_B059_06922E58892F__INCLUDED_)
#define AFX_READWRITEXML_H__EF3C5104_31B1_4B03_B059_06922E58892F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReadWriteXMLApp:
// See ReadWriteXML.cpp for the implementation of this class
//

class CReadWriteXMLApp : public CWinApp
{
public:
	CReadWriteXMLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadWriteXMLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReadWriteXMLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READWRITEXML_H__EF3C5104_31B1_4B03_B059_06922E58892F__INCLUDED_)
