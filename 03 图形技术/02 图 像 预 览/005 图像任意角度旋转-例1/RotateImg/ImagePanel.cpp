// ImagePanel.cpp : implementation file
//

#include "stdafx.h"
#include "RotateImg.h"
#include "ImagePanel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImagePanel dialog


CImagePanel::CImagePanel(CWnd* pParent /*=NULL*/)
	: CDialog(CImagePanel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImagePanel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CImagePanel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImagePanel)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImagePanel, CDialog)
	//{{AFX_MSG_MAP(CImagePanel)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImagePanel message handlers

void CImagePanel::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int nCurpos,nMin,nMax,nThumbWidth;
	//定义滚动信息
	SCROLLINFO siInfo;
	//获取水平滚动条的滚动信息
	GetScrollInfo(SB_HORZ,&siInfo);
	//获取当前的滚动位置
	nCurpos = siInfo.nPos;
	//获取滚动范围
	nMin = siInfo.nMin;
	nMax = siInfo.nMax;
	//获取滚动块大小
	nThumbWidth = siInfo.nPage;
	switch (nSBCode)
	{
	break;
	case SB_THUMBTRACK:		//拖动滚动块
		//滚动窗口到指定的位置
		ScrollWindow(-(nPos-nCurpos),0);
		//设置滚动条新的位置
		SetScrollPos(SB_HORZ,nPos);	
	break;
	case SB_LINELEFT : //单击左箭头
		SetScrollPos(SB_HORZ,nCurpos-1);
		if (nCurpos != 0)
			ScrollWindow(1,0);
	break;
	case SB_LINERIGHT: //单击右箭头
		SetScrollPos(SB_HORZ,nCurpos+1);
		if (nCurpos+nThumbWidth < nMax)
			ScrollWindow(-1,0);	
	break;
	case SB_PAGELEFT: //在滚动块的左方空白滚动区域单击,增量为6
		SetScrollPos(SB_HORZ,nCurpos-6);
		if (nCurpos+nThumbWidth >0)
			ScrollWindow(6,0);
	break;
	case SB_PAGERIGHT: //在滚动块的右方空白滚动区域单击,增量为6
		SetScrollPos(SB_HORZ,nCurpos+6);
		if (nCurpos+nThumbWidth <nMax)
			ScrollWindow(-6,0);
	break;
	case SB_LEFT:	
		SetScrollPos(SB_HORZ,0);
		ScrollWindow(nCurpos,0);
	break;
	}	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);	

}

void CImagePanel::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int nCurpos,nMin,nMax,nThumbWidth;
	SCROLLINFO siInfo;
	GetScrollInfo(SB_VERT,&siInfo);
	nCurpos = siInfo.nPos;
	nMin = siInfo.nMin;
	nMax = siInfo.nMax;
	nThumbWidth = siInfo.nPage;
	switch (nSBCode)
	{
	case SB_THUMBTRACK:
		nCurpos = GetScrollPos(SB_VERT);
		ScrollWindow(0,-(nPos-nCurpos));
		SetScrollPos(SB_VERT,nPos);	
	break;

	case SB_LINELEFT:
		nCurpos = GetScrollPos(SB_VERT);
		SetScrollPos(SB_VERT,nCurpos-1);
		if (nCurpos !=0)
			ScrollWindow(0,1);
	break;
	case SB_LINERIGHT:
		nCurpos = GetScrollPos(SB_VERT);
		SetScrollPos(SB_VERT,nCurpos+1);
		if (nCurpos+nThumbWidth < nMax)
			ScrollWindow(0,-1);	
	break;
	case SB_PAGELEFT: //在滚动块的上方空白滚动区域单击,增量为6
		SetScrollPos(SB_VERT,nCurpos-6);
		if (nCurpos+nThumbWidth >0)
			ScrollWindow(0,6);
	break;
	case SB_PAGERIGHT: //在滚动块的下方空白滚动区域单击,增量为6
		SetScrollPos(SB_VERT,nCurpos+6);
		if (nCurpos+nThumbWidth < nMax)
			ScrollWindow(0,-6);
	break;
	case SB_LEFT:	
		SetScrollPos(SB_VERT,0);
		ScrollWindow(0,nCurpos);
	break;
	}	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

//鼠标滚动轮动的消息
BOOL CImagePanel::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	SCROLLINFO siInfo;
	//获取垂直滚动条的滚动信息
	GetScrollInfo(SB_VERT,&siInfo);
	int nMin,nMax,nThumbWidth;
	//获取垂直滚动条的滚动范围
	nMin = siInfo.nMin;
	nMax = siInfo.nMax;
	//获取滚动块大小
	nThumbWidth = siInfo.nPage;
	//获取垂直滚动条当前滚动位置
	int nPos = GetScrollPos(SB_VERT);
	if (zDelta > 0)	//判断鼠标滚轮的滚动距离，大于零表示向前滚动，小于零表示向后滚动
	{
		if (nPos == 0)
			return TRUE;
		//设置垂直滚动条的滚动位置
		SetScrollPos(SB_VERT,nPos-6);
		//滚动窗口
		ScrollWindow(0,6);
	}
	else		//向后滚动
	{
		if ((nPos+nThumbWidth >= nMax))
			return TRUE;
		//设置垂直滚动条的滚动位置
		SetScrollPos(SB_VERT,nPos+6);
		//滚动窗口
		ScrollWindow(0,-6);
	}
	return TRUE;//CDialog::OnMouseWheel(nFlags, zDelta, pt);
}
