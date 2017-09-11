// CheckAttendance.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CheckAttendance.h"
#include "CheckAttendanceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckAttendanceApp

BEGIN_MESSAGE_MAP(CCheckAttendanceApp, CWinApp)
	//{{AFX_MSG_MAP(CCheckAttendanceApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckAttendanceApp construction

CCheckAttendanceApp::CCheckAttendanceApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCheckAttendanceApp object
CCheckAttendanceApp theApp;
_ConnectionPtr m_pCon;
_RecordsetPtr m_pRecord;

/////////////////////////////////////////////////////////////////////////////
// CCheckAttendanceApp initialization

BOOL CCheckAttendanceApp::InitInstance()
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
	m_pCon.CreateInstance("ADODB.Connection");
	m_pRecord.CreateInstance("ADODB.Recordset");

	m_pCon->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source= \
	price.mdb;Persist Security Info=False";

	try
	{
		m_pCon->Open(L"",L"",L"",-1);
	}
	catch(...)
	{
		MessageBox(0,"数据库连接失败","提示",64);
		return FALSE;
	}

	CCheckAttendanceDlg dlg;
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
