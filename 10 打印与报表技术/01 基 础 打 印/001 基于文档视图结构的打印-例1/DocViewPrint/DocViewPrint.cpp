// DocViewPrint.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DocViewPrint.h"

#include "MainFrm.h"
#include "DocViewPrintDoc.h"
#include "DocViewPrintView.h"
#include "MainDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintApp

BEGIN_MESSAGE_MAP(CDocViewPrintApp, CWinApp)
	//{{AFX_MSG_MAP(CDocViewPrintApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintApp construction

CDocViewPrintApp::CDocViewPrintApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDocViewPrintApp object

CDocViewPrintApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintApp initialization

BOOL CDocViewPrintApp::InitInstance()
{
	AfxEnableControlContainer();

#ifdef _AFXDLL
	Enable3dControls();		
#else
	Enable3dControlsStatic();
#endif


	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CDocViewPrintDoc),
		RUNTIME_CLASS(CMainFrame),
		RUNTIME_CLASS(CDocViewPrintView));
	AddDocTemplate(pDocTemplate);

	CMainDlg m_maindlg;
	this->m_pMainWnd = &m_maindlg;
	tempdlg = &m_maindlg;
	m_maindlg.DoModal();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CDocViewPrintApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintApp message handlers


void CDocViewPrintApp::PrintDlg()
{
	OnFileNew();
}
