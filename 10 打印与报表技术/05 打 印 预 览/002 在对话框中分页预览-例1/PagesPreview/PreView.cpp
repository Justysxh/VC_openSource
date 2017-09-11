// PreView.cpp : implementation file
//

#include "stdafx.h"
#include "PagesPreview.h"
#include "PreView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreView dialog


CPreView::CPreView(CWnd* pParent /*=NULL*/)
	: CDialog(CPreView::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPreView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreView, CDialog)
	//{{AFX_MSG_MAP(CPreView)
	ON_COMMAND(ID_PAGESETUP, OnPagesetup)
	ON_COMMAND(ID_PRINTSETUP, OnPrintsetup)
	ON_WM_SIZE()
	ON_COMMAND(ID_NEXT, OnNext)
	ON_COMMAND(ID_FIRST, OnFirst)
	ON_COMMAND(ID_CLOSE, OnClose)
	ON_COMMAND(ID_ZOOMOUT, OnZoomout)
	ON_COMMAND(ID_ZOOMIN, OnZoomin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreView message handlers

BOOL CPreView::OnInitDialog() 
{
	CDialog::OnInitDialog();

	MainBar.Create(this);
	MainBar.LoadToolBar(IDR_TOOLBAR1);
	MainBar.ModifyStyle(0,TBSTYLE_FLAT | TBSTYLE_LIST,0);
	MainBar.SetButtonText(0,"打印对话框");
	MainBar.SetButtonText(1,"页面设置");
	MainBar.SetButtonText(2,"上一页");
	MainBar.SetButtonText(3,"下一页");
	MainBar.SetButtonText(4,"放大");
	MainBar.SetButtonText(5,"缩小");
	MainBar.SetButtonText(6,"关闭");

	UINT parts[] = {100,101,102,103,104,105};
	StatusBar.Create(this);
	StatusBar.SetIndicators(parts,6);
	StatusBar.SetPaneInfo(0,0,0,60);
	StatusBar.SetPaneInfo(1,0,0,60);
	StatusBar.SetPaneInfo(2,0,0,60);
	StatusBar.SetPaneInfo(3,0,0,60);
	StatusBar.SetPaneInfo(4,0,0,60);
	StatusBar.SetPaneInfo(5,0,0,60);


	StatusBar.SetPaneText(0,"总页数：");
	StatusBar.SetPaneText(2,"当前页：");
	StatusBar.SetPaneText(4,"缩放比例：");

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,
			AFX_IDW_CONTROLBAR_LAST,0);	

	PreviewDlg.Create(IDD_PreviewView,this);
	PreviewDlg.StatusBar = &StatusBar;
	PreviewDlg.ShowWindow(SW_SHOW);
	CalcPreviewRect();
	PreviewDlg.UpdateStatusBar();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPreView::OnPagesetup() 
{
	PreviewDlg.OnPagesetup();	
}

void CPreView::OnPrintsetup() 
{
	PreviewDlg.OnPrintsetup();	
}

void CPreView::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,
			AFX_IDW_CONTROLBAR_LAST,0);	
	if (IsWindow(MainBar.GetSafeHwnd()) &
		IsWindow(StatusBar.GetSafeHwnd()) & 
		IsWindow(PreviewDlg.GetSafeHwnd()))
	{
		CalcPreviewRect();
	}
	
}

void CPreView::CalcPreviewRect()
{
	CRect BarRect,StatusRect,PreviewRect;
	MainBar.GetWindowRect(&BarRect);
	StatusBar.GetWindowRect(&StatusRect);
	PreviewRect.left = BarRect.left;
	PreviewRect.top = BarRect.bottom;
	PreviewRect.right = BarRect.right;
	PreviewRect.bottom = StatusRect.top;
	this->ScreenToClient(&PreviewRect);
	PreviewDlg.MoveWindow(&PreviewRect);
}


void CPreView::OnNext() 
{
	PreviewDlg.OnNext();
}

void CPreView::OnFirst() 
{
	PreviewDlg.OnPrevi();	
}

void CPreView::OnClose() 
{
	this->OnCancel();	
}

void CPreView::OnZoomout() 
{
	PreviewDlg.OnZoomOut();	
}

void CPreView::OnZoomin() 
{
	PreviewDlg.OnZoomIn();	
}
