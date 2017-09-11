// AddDateToListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AddDateToList.h"
#include "AddDateToListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddDateToListDlg dialog

CAddDateToListDlg::CAddDateToListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddDateToListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddDateToListDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAddDateToListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddDateToListDlg)
	DDX_Control(pDX, IDC_DATALIST, m_datalist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAddDateToListDlg, CDialog)
	//{{AFX_MSG_MAP(CAddDateToListDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddDateToListDlg message handlers

BOOL CAddDateToListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_datalist.ModifyStyle(0L,LVS_REPORT);
	m_datalist.ModifyStyle(0L,LVS_SINGLESEL);
	m_datalist.ModifyStyle(0L,LVS_SHOWSELALWAYS);
	m_datalist.ModifyStyle(0L,LVS_NOSORTHEADER);
	m_datalist.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_datalist.InsertColumn(0,"姓名");
	m_datalist.InsertColumn(1,"性别");
	m_datalist.InsertColumn(2,"出生日期");
	m_datalist.InsertColumn(3,"工作单位");
	m_datalist.InsertColumn(4,"移动电话");
	m_datalist.InsertColumn(4,"固定电话");
	m_datalist.SetColumnWidth(0,100);
	m_datalist.SetColumnWidth(1,50);
	m_datalist.SetColumnWidth(2,100);
	m_datalist.SetColumnWidth(3,100);
	m_datalist.SetColumnWidth(4,100);
	m_datalist.SetColumnWidth(5,100);
	::CoInitialize(NULL);
	m_pConnection=NULL;
	m_pConnection.CreateInstance(__uuidof(Connection));
	m_pConnection->ConnectionString="uid=;pwd=;DRIVER={Microsoft Access Driver (*.mdb)};DBQ=mrdb.mdb;";
	m_pConnection->Open(L"",L"",L"",adCmdUnspecified);
	_bstr_t bstrSQL="select * from info";
   	m_pRecordset=m_pConnection->Execute(bstrSQL,NULL,adCmdText);
	int i=0;
	while(!m_pRecordset->adoEOF)
	{
	xm=(char*)(_bstr_t)m_pRecordset->GetCollect("xm");
	xb=(char*)(_bstr_t)m_pRecordset->GetCollect("xb");
	csrq=(char*)(_bstr_t)m_pRecordset->GetCollect("csrq");
	gzdw=(char*)(_bstr_t)m_pRecordset->GetCollect("gzdw");
	yddh=(char*)(_bstr_t)m_pRecordset->GetCollect("yddh");
	gddh=(char*)(_bstr_t)m_pRecordset->GetCollect("gddh");
	m_datalist.InsertItem(i,"");
	m_datalist.SetItemText(i,0,xm);
	m_datalist.SetItemText(i,1,xb);
	m_datalist.SetItemText(i,2,csrq);
	m_datalist.SetItemText(i,3,gzdw);
	m_datalist.SetItemText(i,4,yddh);
	m_datalist.SetItemText(i,5,gddh);
	i+=1;
	m_pRecordset->MoveNext();
	}
	m_pRecordset->Close();
	m_pConnection->Close();
	m_pRecordset=NULL;
	m_pConnection=NULL;
	::CoUninitialize();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAddDateToListDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAddDateToListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
