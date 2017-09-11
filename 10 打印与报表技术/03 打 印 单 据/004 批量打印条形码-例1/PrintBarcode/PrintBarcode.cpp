// PrintBarcode.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PrintBarcode.h"
#include "PrintBarcodeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintBarcodeApp

BEGIN_MESSAGE_MAP(CPrintBarcodeApp, CWinApp)
	//{{AFX_MSG_MAP(CPrintBarcodeApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintBarcodeApp construction

CPrintBarcodeApp::CPrintBarcodeApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPrintBarcodeApp object

CPrintBarcodeApp theApp;

_ConnectionPtr pCon;
_RecordsetPtr pRecord;

/////////////////////////////////////////////////////////////////////////////
// CPrintBarcodeApp initialization

BOOL CPrintBarcodeApp::InitInstance()
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

	pCon.CreateInstance("ADODB.Connection");
	pRecord.CreateInstance(__uuidof(Recordset));

	pCon->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=price.mdb;Persist Security Info=False";
	
	try
	{
		pCon->Open(L"",L"",L"",-1);
	}
	catch(...)
	{
		MessageBox(0,"数据连接失败","提示",0);
		return FALSE;
	}

	CPrintBarcodeDlg dlg;
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
