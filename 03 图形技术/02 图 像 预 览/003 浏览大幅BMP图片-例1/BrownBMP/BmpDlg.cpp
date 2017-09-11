// BmpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BrownBMP.h"
#include "BmpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpDlg dialog


CBmpDlg::CBmpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBmpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBmpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBmpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBmpDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBmpDlg, CDialog)
	//{{AFX_MSG_MAP(CBmpDlg)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpDlg message handlers

void CBmpDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int pos,min,max,thumbwidth;

	SCROLLINFO vinfo;
	GetScrollInfo(SB_HORZ,&vinfo);
	
	pos = vinfo.nPos;
	min = vinfo.nMin;
	max = vinfo.nMax;
	thumbwidth = vinfo.nPage;

	switch (nSBCode)
	{

	break;
	case SB_THUMBTRACK: //拖动滚动块
		ScrollWindow(-(nPos-pos),0);
		SetScrollPos(SB_HORZ,nPos);
	
	break;

	case SB_LINELEFT : //单击左箭头
		SetScrollPos(SB_HORZ,pos-1);
		if (pos !=0)
			ScrollWindow(1,0);
	break;

	case SB_LINERIGHT: //单击右箭头
		SetScrollPos(SB_HORZ,pos+1);
		if (pos+thumbwidth <max)
			ScrollWindow(-1,0);	
	break;

	case SB_PAGELEFT: //在滚动块的左方空白滚动区域单击,增量为6

		SetScrollPos(SB_HORZ,pos-6);
		if (pos+thumbwidth >0)
			ScrollWindow(6,0);
	break;

	case SB_PAGERIGHT: //在滚动块的右方空白滚动区域单击,增量为6

		SetScrollPos(SB_HORZ,pos+6);
		if (pos+thumbwidth <max)
			ScrollWindow(-6,0);
	break;

	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CBmpDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
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
		pos = GetScrollPos(SB_VERT);
		ScrollWindow(0,-(nPos-pos));
		SetScrollPos(SB_VERT,nPos);	
	break;

	case SB_LINELEFT:
		pos = GetScrollPos(SB_VERT);
		SetScrollPos(SB_VERT,pos-1);
		if (pos !=0)
			ScrollWindow(0,1);
	break;

	case SB_LINERIGHT:
		pos = GetScrollPos(SB_VERT);
		SetScrollPos(SB_VERT,pos+1);
		if (pos+thumbwidth <max)
			ScrollWindow(0,-1);	
	break;

	case SB_PAGELEFT: //在滚动块的上方空白滚动区域单击,增量为6

		SetScrollPos(SB_VERT,pos-6);
		if (pos+thumbwidth >0)
			ScrollWindow(0,6);
	break;

	case SB_PAGERIGHT: //在滚动块的下方空白滚动区域单击,增量为6

		SetScrollPos(SB_VERT,pos+6);
		if (pos+thumbwidth <max)
			ScrollWindow(0,-6);
	break;


	}	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CBmpDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	SCROLLINFO vinfo;
	GetScrollInfo(SB_VERT,&vinfo);

	int min,max,thumbwidth;
	min = vinfo.nMin;
	max = vinfo.nMax;
	thumbwidth = vinfo.nPage;
	int pos = GetScrollPos(SB_VERT);
	
	if (zDelta>0)
	{
		if (pos==0)
			return TRUE;
		SetScrollPos(SB_VERT,pos-6);
		ScrollWindow(0,6);
	}
	else
	{
		if ((pos+thumbwidth>=max))
			return TRUE;
		SetScrollPos(SB_VERT,pos+6);
		ScrollWindow(0,-6);
	}

	return TRUE;
	//return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}

