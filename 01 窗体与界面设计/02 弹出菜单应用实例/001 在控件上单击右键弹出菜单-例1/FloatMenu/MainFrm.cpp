// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "FloatMenu.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
//	ON_COMMAND(ID_BUTTON32776, OnButton32776)
	ON_NOTIFY(TBN_DROPDOWN,AFX_IDW_TOOLBAR,OnToolbarDropDown)
	ON_COMMAND(ID_MENUITEM32780111, OnMenuitem32780111)
	ON_COMMAND_RANGE(ID_BUTTON1,ID_BUTTON1+4, OnButton32772)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_ispressed = false;	
}

CMainFrame::~CMainFrame()
{

}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC ) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;        // fail to create
	}

	if (!m_wndFloatTool.CreateEx(this, TBSTYLE_FLAT|TBSTYLE_AUTOSIZE , WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY |TBSTYLE_WRAPABLE| CBRS_SIZE_DYNAMIC))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	
	m_wndFloatTool.AddButtonFromMenu(IDR_MAINFRAME);


	m_wndFloatTool.GetToolBarCtrl().SetBitmapSize(CSize(0,0));
	m_wndFloatTool.GetToolBarCtrl().SetButtonSize(CSize(70,22));


	SetMenu(NULL);

	EnableDocking(CBRS_ALIGN_ANY);

	m_bAutoMenuEnable = TRUE;
	

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndFloatTool.EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_wndFloatTool);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
/*	CFrameWnd::OnSize(nType, cx, cy);
	CRect rect;

	GetClientRect(rect);
	if (IsWindow(m_dock.m_hWnd))
	{
		
		m_dock.SetWindowPos(NULL,0,0,rect.Width(),40,SWP_SHOWWINDOW );

	}

	if (IsWindow(m_Dlg.m_hWnd))
	{
		CRect rect;
		m_dock.GetClientRect(rect);
		m_Dlg.SetWindowPos(NULL,0,0,rect.Width()-20,30,SWP_SHOWWINDOW );
	}*/	
}

void CMainFrame::OnButton32776() 
{
	
}

void CMainFrame::OnToolbarDropDown(NMTOOLBAR *pnmtb, LRESULT *plr)
{
	CWnd* pWnd = &m_wndFloatTool;
	UINT nID = IDR_MAINFRAME;

	CMenu menu;
	menu.LoadMenu(nID);
	CMenu* pPop = menu.GetSubMenu(pnmtb->iItem-ID_BUTTON1);
	
	m_wndFloatTool.m_pSubMenu = pPop;
	m_wndFloatTool.MenuPopIndex = pnmtb->iItem-ID_BUTTON1;

	CRect rc;
	m_wndFloatTool.GetToolBarCtrl().GetItemRect(pnmtb->iItem-ID_BUTTON1,rc);
	pWnd->ClientToScreen(&rc);
	pPop->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_VERTICAL,rc.left,rc.bottom,this,&rc);	
	m_wndFloatTool.MenuPopIndex = -1;

}

void CMainFrame::OnMenuitem32780111() 
{
	

}

void CMainFrame::OnButton32772() 
{
	

}

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg) 
{
	return CFrameWnd::PreTranslateMessage(pMsg);
}

BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam) 
{	
	return CFrameWnd::OnCommand(wParam, lParam);
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	m_wndFloatTool.OnCmdMsg( nID, nCode, pExtra, pHandlerInfo);	
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
