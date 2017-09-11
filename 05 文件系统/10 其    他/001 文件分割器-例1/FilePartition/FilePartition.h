// FilePartition.h : main header file for the FILEPARTITION application
//

#if !defined(AFX_FILEPARTITION_H__D3BA4185_84AF_4798_9C34_5F8FC3D52619__INCLUDED_)
#define AFX_FILEPARTITION_H__D3BA4185_84AF_4798_9C34_5F8FC3D52619__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFilePartitionApp:
// See FilePartition.cpp for the implementation of this class
//

class CFilePartitionApp : public CWinApp
{
public:
	CFilePartitionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilePartitionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFilePartitionApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEPARTITION_H__D3BA4185_84AF_4798_9C34_5F8FC3D52619__INCLUDED_)
