// FrameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Smoothness.h"
#include "FrameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrameDlg dialog


CFrameDlg::CFrameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFrameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrameDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrameDlg, CDialog)
	//{{AFX_MSG_MAP(CFrameDlg)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrameDlg message handlers

void CFrameDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int pos,min,max,thumbwidth;

	SCROLLINFO vinfo;
	GetScrollInfo(SB_HORZ,&vinfo);
	
	pos = vinfo.nPos;
	min = vinfo.nMin;
	max = vinfo.nMax;
	thumbwidth = vinfo.nPage;

	switch (nSBCode)
	{
		case SB_THUMBTRACK: //拖动滚动块
			ScrollWindow(-(nPos-pos),0);
			SetScrollPos(SB_HORZ,nPos);
			break;
		case SB_LINELEFT : //单击左箭头
			if (pos != 0)
			{
				ScrollWindow(1,0);
				SetScrollPos(SB_HORZ,pos-1);
			}
			break;
		case SB_LINERIGHT: //单击右箭头
			if (pos+thumbwidth <= max)
			{
				SetScrollPos(SB_HORZ,pos+1);
				ScrollWindow(-1,0);	
			}
			break;
		case SB_PAGELEFT: //在滚动块的左方空白滚动区域单击
			if (pos >= thumbwidth)
			{
				ScrollWindow(thumbwidth,0);
				SetScrollPos(SB_HORZ,pos-thumbwidth);
			}
			else
			{
				ScrollWindow(pos,0);
				SetScrollPos(SB_HORZ,0);
			}
			break;
		case SB_PAGERIGHT: //在滚动块的右方空白滚动区域单击
			if (pos+thumbwidth <= max-thumbwidth)
			{
				ScrollWindow(-thumbwidth,0);
				SetScrollPos(SB_HORZ,pos+thumbwidth);
			}
			else
			{
				ScrollWindow(-(max-(pos+thumbwidth)),0);
				SetScrollPos(SB_HORZ,max-thumbwidth);
			}
			break;
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CFrameDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int pos,min,max,thumbwidth;

	SCROLLINFO vinfo;
	GetScrollInfo(SB_VERT,&vinfo);
	
	pos = vinfo.nPos;
	min = vinfo.nMin;
	max = vinfo.nMax;
	thumbwidth = vinfo.nPage;

	switch (nSBCode)
	{
		case SB_THUMBTRACK:
			ScrollWindow(0,-(nPos-pos));
			SetScrollPos(SB_VERT,nPos);	
			break;
		case SB_LINELEFT:
			SetScrollPos(SB_VERT,pos-1);
			if (pos != 0)
				ScrollWindow(0,1);
			break;
		case SB_LINERIGHT:
			SetScrollPos(SB_VERT,pos+1);
			if (pos+thumbwidth < max)
				ScrollWindow(0,-1);	
			break;
		case SB_PAGELEFT: //在滚动块的上方空白滚动区域单击
			if (pos >= thumbwidth)
			{
				ScrollWindow(0,thumbwidth);
				SetScrollPos(SB_VERT,pos-thumbwidth);
			}
			else
			{
				ScrollWindow(0,pos);
				SetScrollPos(SB_VERT,0);
			}
			break;
		case SB_PAGERIGHT: //在滚动块的下方空白滚动区域单击
			if (pos+thumbwidth <= max-thumbwidth)
			{
				ScrollWindow(0,-thumbwidth);
				SetScrollPos(SB_VERT,pos+thumbwidth);
			}
			else
			{
				ScrollWindow(0,-(max-(pos+thumbwidth)));
				SetScrollPos(SB_VERT,max-thumbwidth);
			}
			break;
	}
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
