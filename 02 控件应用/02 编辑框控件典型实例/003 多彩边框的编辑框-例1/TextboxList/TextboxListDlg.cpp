// TextboxListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TextboxList.h"
#include "TextboxListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int i=0;
bool enter=false;
/////////////////////////////////////////////////////////////////////////////
// CTextboxListDlg dialog

CTextboxListDlg::CTextboxListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTextboxListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTextboxListDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTextboxListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextboxListDlg)
	DDX_Control(pDX, IDC_EDOBJ, m_edobj);
	DDX_Control(pDX, IDC_TIPLIST, m_tiplist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTextboxListDlg, CDialog)
	//{{AFX_MSG_MAP(CTextboxListDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDOBJ, OnChangeEdobj)
	ON_NOTIFY(NM_DBLCLK, IDC_TIPLIST, OnDblclkTiplist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextboxListDlg message handlers

BOOL CTextboxListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_tiplist.ModifyStyle(0L,LVS_REPORT);
	m_tiplist.ModifyStyle(0L,LVS_SHOWSELALWAYS);
	m_tiplist.ModifyStyle(0L,LVS_NOSORTHEADER);
	m_tiplist.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_tiplist.InsertColumn(0,"姓名");
	m_tiplist.InsertColumn(1,"性别");
	m_tiplist.InsertColumn(2,"出生日期");

	m_tiplist.SetColumnWidth(0,50);
	m_tiplist.SetColumnWidth(1,50);
	m_tiplist.SetColumnWidth(2,100);
	m_edobj.MoveWindow(15,15,150,21);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTextboxListDlg::OnPaint() 
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
HCURSOR CTextboxListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CTextboxListDlg::SetDataBase(CString sql)
{


	::CoInitialize(NULL);
	m_pConnection=NULL;
	m_pConnection.CreateInstance(__uuidof(Connection));
	m_pConnection->ConnectionString="uid=;pwd=;DRIVER={Microsoft Access Driver (*.mdb)};DBQ=mrdb.mdb;";
	m_pConnection->Open(L"",L"",L"",adCmdUnspecified);
	CString text;
	text.Format("select * from info where xm like '%s%%'",sql);
   	m_pRecordset=m_pConnection->Execute((_bstr_t)text,NULL,adCmdText);
	if(m_pRecordset->GetRecordCount()==0)
	{m_tiplist.ShowWindow(SW_HIDE);}
	int i=0;
	while(!m_pRecordset->adoEOF)
	{
	xm=(char*)(_bstr_t)m_pRecordset->GetCollect("xm");
	xb=(char*)(_bstr_t)m_pRecordset->GetCollect("xb");
	csrq=(char*)(_bstr_t)m_pRecordset->GetCollect("csrq");
	gzdw=(char*)(_bstr_t)m_pRecordset->GetCollect("gzdw");
	yddh=(char*)(_bstr_t)m_pRecordset->GetCollect("yddh");
	gddh=(char*)(_bstr_t)m_pRecordset->GetCollect("gddh");
	m_tiplist.InsertItem(i,"");
	m_tiplist.SetItemText(i,0,xm);
	m_tiplist.SetItemText(i,1,xb);
	m_tiplist.SetItemText(i,2,csrq);
	m_tiplist.SetItemText(i,3,gzdw);
	m_tiplist.SetItemText(i,4,yddh);
	m_tiplist.SetItemText(i,5,gddh);
	i+=1;
	m_pRecordset->MoveNext();
	}
	m_pRecordset->Close();
	m_pConnection->Close();
	m_pRecordset=NULL;
	m_pConnection=NULL;
	::CoUninitialize();
}

BOOL CTextboxListDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE)
	{
		m_tiplist.ShowWindow(SW_HIDE);
		IsShowing=false;
		pMsg->wParam=VK_CONTROL;
	}
	if (pMsg->message==WM_LBUTTONDOWN)
	{
		if (pMsg->hwnd!= m_tiplist.m_hWnd)
		{m_tiplist.ShowWindow(SW_HIDE);
		IsShowing=false;}
	}
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
	{	
		if(IsShowing)
		
		m_edobj.SetWindowText(xm);
		m_tiplist.ShowWindow(SW_HIDE);
		IsShowing=false;
		i=0;
		pMsg->wParam=VK_CONTROL;
	}
		if(pMsg->hwnd==m_tiplist.m_hWnd&& pMsg->message==WM_LBUTTONDBLCLK)
		{
			m_edobj.SetWindowText(xm);
			m_tiplist.ShowWindow(SW_HIDE);
			IsShowing=false;
		}
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_DOWN)
	{
		if(IsShowing)
		{
	
			if(i==m_tiplist.GetItemCount())
			i=0;
	
			m_tiplist.SetHotItem(i);
			xm=m_tiplist.GetItemText(i,0);
			i+=1;
			}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
void CTextboxListDlg::AutoPostion()
{
	this->m_tiplist.MoveWindow(15,36,210,100);
}

void CTextboxListDlg::OnChangeEdobj() 
{
	CString edit;
	m_edobj.GetWindowText(edit);
	if(!edit.IsEmpty())
	{
		this->AutoPostion();
		m_tiplist.DeleteAllItems();
		this->SetDataBase(edit);
		if(m_tiplist.GetItemCount()>0)
		{
			m_tiplist.ShowWindow(SW_SHOW);
			IsShowing=true;
		}
	}
	else
	{
		m_tiplist.ShowWindow(SW_HIDE);
			IsShowing=false;
	}
}

void CTextboxListDlg::OnDblclkTiplist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i=m_tiplist.GetHotItem();
	CString text;
	xm=m_tiplist.GetItemText(i,1);
	*pResult = 0;
}
