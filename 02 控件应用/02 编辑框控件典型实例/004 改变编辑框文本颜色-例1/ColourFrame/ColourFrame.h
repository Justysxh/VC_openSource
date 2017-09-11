// ColourFrame.h : main header file for the COLOURFRAME application
//

#if !defined(AFX_COLOURFRAME_H__C4E8A745_9D3F_48B6_8110_529FBE530D0C__INCLUDED_)
#define AFX_COLOURFRAME_H__C4E8A745_9D3F_48B6_8110_529FBE530D0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CColourFrameApp:
// See ColourFrame.cpp for the implementation of this class
//

class CColourFrameApp : public CWinApp
{
public:
	CColourFrameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColourFrameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CColourFrameApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOURFRAME_H__C4E8A745_9D3F_48B6_8110_529FBE530D0C__INCLUDED_)
