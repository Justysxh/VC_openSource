// DataManage.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DataManage.h"
#include "DataManageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataManageApp

BEGIN_MESSAGE_MAP(CDataManageApp, CWinApp)
	//{{AFX_MSG_MAP(CDataManageApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataManageApp construction

CDataManageApp::CDataManageApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDataManageApp object

CDataManageApp theApp;
CString cmd;

_ConnectionPtr pCon;
_RecordsetPtr  pRecord;


/////////////////////////////////////////////////////////////////////////////
// CDataManageApp initialization

BOOL CDataManageApp::InitInstance()
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

	cmd = GetCommandLine();  //获得命令行信息

	pCon.CreateInstance("ADODB.Connection");
	pRecord.CreateInstance(__uuidof(Recordset));
	
	pCon->ConnectionString = "Provider=SQLOLEDB.1;Persist Security Info=False; \
		User ID=sa;Initial Catalog=master;Data Source=.";

	try
	{
		pCon->Open(L"",L"",L"",-1);
	}
	catch(_com_error e)
	{
		CString str;
		str.Format("数据库连接失败,错误信息: %s",e.ErrorMessage());
		AfxMessageBox(str, 0,0);

		return FALSE;
	
	}


	CDataManageDlg dlg;
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
