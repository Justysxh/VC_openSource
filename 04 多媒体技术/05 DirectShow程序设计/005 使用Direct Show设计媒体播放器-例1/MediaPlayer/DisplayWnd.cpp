// DisplayWnd.cpp : implementation file
//

#include "stdafx.h"
#include "MediaPlayer.h"
#include "DisplayWnd.h"
#include "DirectShowEventDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDisplayWnd dialog


CDisplayWnd::CDisplayWnd(CWnd* pParent /*=NULL*/)
	: CDialog(CDisplayWnd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDisplayWnd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	bmp.LoadBitmap(IDB_VIDEOBMP);
}


void CDisplayWnd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDisplayWnd)
	DDX_Control(pDX, IDC_PANEL, m_Panel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDisplayWnd, CDialog)
	//{{AFX_MSG_MAP(CDisplayWnd)
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	ON_COMMAND(ID_FULLSCREEN, OnFullscreen)
	ON_COMMAND(ID_GRAYIMAGE, OnGrayimage)
	ON_COMMAND(ID_STOPPLAY, OnStopplay)
	ON_COMMAND(ID_PLAYFILE, OnPlayfile)
	ON_COMMAND(ID_VIDEOSET, OnVideoset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisplayWnd message handlers

void CDisplayWnd::OnOK() 
{

}

void CDisplayWnd::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	CDirectShowEventDlg *pDlg = (CDirectShowEventDlg *)AfxGetMainWnd(); 

	if (pDlg->m_bViewPlay)
	{
		CRect ClientRC,rc;
		GetClientRect(ClientRC);
		m_Panel.MoveWindow(ClientRC);
		m_Panel.ModifyStyle(SS_BITMAP,SS_BLACKRECT);
		m_Panel.GetClientRect(rc);
		pDlg->pViewWnd->put_Height(rc.Height());
		pDlg->pViewWnd->put_Width(rc.Width());
	}
}

BOOL CDisplayWnd::OnInitDialog() 
{
	CDialog::OnInitDialog();
	return TRUE; 
}

void CDisplayWnd::OnContextMenu(CWnd* pWnd, CPoint point) 
{
		
}

void CDisplayWnd::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	
	CDialog::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

void CDisplayWnd::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void CDisplayWnd::OnFullscreen() 
{
	CDirectShowEventDlg *pDlg = (CDirectShowEventDlg *)AfxGetMainWnd();
	pDlg->OnFullScreen(); 
}

void CDisplayWnd::OnGrayimage() 
{
	CDirectShowEventDlg *pDlg = (CDirectShowEventDlg *)AfxGetMainWnd();
	pDlg->OnGray();		
}

void CDisplayWnd::OnStopplay() 
{
	CDirectShowEventDlg *pDlg = (CDirectShowEventDlg *)AfxGetMainWnd();
	pDlg->OnTbStop() ;		
}

void CDisplayWnd::OnPlayfile() 
{
	CDirectShowEventDlg *pDlg = (CDirectShowEventDlg *)AfxGetMainWnd();
	pDlg->OnSetFile();		
}

void CDisplayWnd::OnVideoset() 
{
	CDirectShowEventDlg *pDlg = (CDirectShowEventDlg *)AfxGetMainWnd();
	pDlg->OnVideoset();		
}
