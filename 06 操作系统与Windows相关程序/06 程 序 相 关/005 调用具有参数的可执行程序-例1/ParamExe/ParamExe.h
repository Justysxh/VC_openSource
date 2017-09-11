// ParamExe.h : main header file for the PARAMEXE application
//

#if !defined(AFX_PARAMEXE_H__CAE837C2_E8C9_4D1E_A998_E9F5DEADD31A__INCLUDED_)
#define AFX_PARAMEXE_H__CAE837C2_E8C9_4D1E_A998_E9F5DEADD31A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CParamExeApp:
// See ParamExe.cpp for the implementation of this class
//

class CParamExeApp : public CWinApp
{
public:
	CParamExeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParamExeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CParamExeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMEXE_H__CAE837C2_E8C9_4D1E_A998_E9F5DEADD31A__INCLUDED_)
