// PopManu.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PopManu.h"
#include "PopManuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopManuApp

BEGIN_MESSAGE_MAP(CPopManuApp, CWinApp)
	//{{AFX_MSG_MAP(CPopManuApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopManuApp construction

CPopManuApp::CPopManuApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPopManuApp object

CPopManuApp theApp;
_ConnectionPtr m_pCon;
_RecordsetPtr m_pRecord;

/////////////////////////////////////////////////////////////////////////////
// CPopManuApp initialization

BOOL CPopManuApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	AfxOleInit();
	m_pCon.CreateInstance(__uuidof(Connection));
	m_pRecord.CreateInstance(__uuidof(Recordset));

	m_pCon->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0; \
		Data Source=./Menu.mdb;Persist Security Info=False";

	try
	{
		m_pCon->Open("","","",-1);
	}
	catch(...)
	{
		AfxMessageBox("数据库连接错误",0,0);
		exit;
	}

	CPopManuDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
