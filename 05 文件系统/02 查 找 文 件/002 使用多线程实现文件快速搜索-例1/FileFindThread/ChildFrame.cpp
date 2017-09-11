// ChildFrame.cpp : implementation file
//

#include "stdafx.h"
#include "FileFindThread.h"
#include "ChildFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WMFINDFILE (WM_USER + 10)
/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CFormView)

CChildFrame::CChildFrame()
	: CFormView(CChildFrame::IDD)
{
	//{{AFX_DATA_INIT(CChildFrame)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CChildFrame::~CChildFrame()
{
}

void CChildFrame::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChildFrame)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChildFrame, CFormView)
	//{{AFX_MSG_MAP(CChildFrame)
	ON_BN_CLICKED(IDC_BUTTON2, OnFindFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CFormView::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers

void CChildFrame::OnFindFile() 
{
	m_list.DeleteAllItems();
	GetParent()->GetParent()->
		SendMessage(WMFINDFILE,(WPARAM)&m_edit,(LPARAM)&m_list);
}

void CChildFrame::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	m_list.InsertColumn(0,"文件名");
	m_list.SetColumnWidth(0,100);
	m_list.InsertColumn(1,"文件路径");
	m_list.SetColumnWidth(1,300);

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
}
