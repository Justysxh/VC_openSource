// PreviewDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PagesPreview.h"
#include "PreviewDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreviewDialog dialog


CPreviewDialog::CPreviewDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPreviewDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreviewDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPreviewDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreviewDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreviewDialog, CDialog)
	//{{AFX_MSG_MAP(CPreviewDialog)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreviewDialog message handlers

BOOL CPreviewDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
		
	PageCount = 3;//总页数
	CurrentPage = 1;//当前页
	Zoom = 100;
	CClientDC dc(this);
	Margin = CRect(1500,1500,1500,1500);
	printsetup = new CPrintDialog(false);
	printsetup->GetDefaults();
	InitPreview(printsetup->GetPrinterDC(),*printsetup->GetDevMode());
	pagesetup = new CPageSetupDialog();
	
	return TRUE; 
}

void CPreviewDialog::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	UpdateScroll();
}

void CPreviewDialog::UpdateScroll()
{
	CRect rect;
	GetClientRect(&rect);
	CClientDC dc(this);
	dc.SetMapMode(MM_ISOTROPIC);
	dc.SetWindowExt(100,100);
	dc.SetViewportExt(Zoom,Zoom);

	hp.cx = (PageSize.cx+ FrameMargin.left + FrameMargin.right);
	hp.cy = (rect.right);
	dc.DPtoLP(&hp);

	vp.cx = (PageSize.cy+ FrameMargin.top + FrameMargin.bottom);
	vp.cy = (rect.bottom);
	dc.DPtoLP(&vp);

	StartPoint.x = StartPoint.y = 0;
	SCROLLINFO scinfo;
	scinfo.cbSize = sizeof(SCROLLINFO);
	scinfo.fMask = SIF_ALL;
	scinfo.nMin = 0;
	scinfo.nMax = hp.cx* (Zoom / 100);
	scinfo.nPage = hp.cy;
	scinfo.nPos = 0;
	
	this->SetScrollInfo(SB_HORZ,&scinfo);

	scinfo.nMax = vp.cx * (Zoom / 100);
	scinfo.nPage = vp.cy;
	this->SetScrollInfo(SB_VERT,&scinfo);
	this->Invalidate(false);
}

void CPreviewDialog::OnPaint() 
{
	CPaintDC dc(this);

	dc.SetMapMode(MM_ISOTROPIC);
	dc.SetWindowExt(100,100);
	dc.SetViewportExt(Zoom,Zoom);

	CRect ClientRect;
	this->GetParent()->GetClientRect(&ClientRect);
	ClientRect.InflateRect(2,2,2,2);
	if (Zoom < 100)
		dc.DPtoLP(&ClientRect);
	CRect rect(FrameMargin.left,FrameMargin.top,
		PageSize.cx+FrameMargin.left,PageSize.cy+FrameMargin.top);
	
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc,ClientRect.right,ClientRect.bottom);
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(&bitmap);

	CBrush BkBrush(RGB(157,155,151));
	MemDC.SelectObject(&BkBrush);
	MemDC.Rectangle(&ClientRect);

	CBrush brush(RGB(255,255,255));
	CPen pen(BS_SOLID,2,RGB(0,0,255));
	MemDC.SelectObject(&brush);
	MemDC.SelectObject(&pen);
	rect.OffsetRect(-StartPoint.x,-StartPoint.y);
	rect.InflateRect(1,1,1,1);
	MemDC.Rectangle(&rect);
	rect.InflateRect(-1,-1,-1,-1);

	CPen p(BS_SOLID,1,RGB(0,0,0));
	MemDC.SelectObject(&p);

	double ratex = dc.GetDeviceCaps(LOGPIXELSX) / 25.4;
	double ratey = dc.GetDeviceCaps(LOGPIXELSY) / 25.4;
	CRect Margins = CRect((int)(ratex * (Margin.left / 100)),
		(int)(ratey * (Margin.top / 100)),
		(int)(ratex * (Margin.right / 100)),
		(int)(ratey * (Margin.bottom / 100)));

	CRect DrawRect(0,0,PageSize.cx - Margins.left - Margins.right,
		PageSize.cy - Margins.top - Margins.bottom);
	DrawRect.OffsetRect(-StartPoint.x,-StartPoint.y);

	MemDC.SetViewportOrg(FrameMargin.left + Margins.left,
		FrameMargin.top + Margins.top);

	MemDC.IntersectClipRect(&DrawRect);

	DrawPreview(&MemDC,&DrawRect);//绘制页
	MemDC.SetViewportOrg(0,0);
	
	dc.BitBlt(0,0,ClientRect.right,ClientRect.bottom,&MemDC,0,0,SRCCOPY);
	MemDC.DeleteDC();
	bitmap.DeleteObject();
}

void CPreviewDialog::DrawPreview(CDC *DrawDC,CRect *DrawRect)
{
	if (CurrentPage == 1)
		DrawDC->Rectangle(DrawRect);
	else if (CurrentPage == 2)
		DrawDC->Ellipse(DrawRect);
	else 
	{
		DrawDC->DrawEdge(DrawRect,EDGE_BUMP ,BF_RECT);
	}
}

void CPreviewDialog::OnPrintsetup() 
{
	CPrintDialog *printdlg = new CPrintDialog(false);
	if (printdlg->DoModal() == IDOK)
	{
		InitPreview(printdlg->GetPrinterDC(),*printdlg->GetDevMode());
	}
}

void CPreviewDialog::OnPagesetup() 
{
	pagesetup->m_psd.rtMargin = Margin;
	if (pagesetup->DoModal() == IDOK)
	{
		pagesetup->GetMargins(&Margin,NULL);
		InitPreview(pagesetup->CreatePrinterDC(),
			*(DEVMODE*)pagesetup->m_psd.hDevMode);
	}

}

void CPreviewDialog::InitPreview(HDC hDC,DEVMODE dev)
{
	CDC pdc;
	CClientDC sdc(this);
	pdc.Attach(hDC);
	PageSize.cx = (int)(sdc.GetDeviceCaps(LOGPIXELSX) /
		25.4 * pdc.GetDeviceCaps(HORZSIZE));
	PageSize.cy = (int)(sdc.GetDeviceCaps(LOGPIXELSY) / 
		25.4 * pdc.GetDeviceCaps(VERTSIZE));
	FrameMargin = CRect(20,20,20,20);
	pdc.Detach();
	pdc.DeleteDC();
	UpdateScroll();
}

void CPreviewDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CRect rect;
	this->GetClientRect(&rect);
	switch(nSBCode)
	{
	case SB_LINELEFT:
		StartPoint.x -= 10;
		if (StartPoint.x < 0)
			StartPoint.x = 0;
		this->SetScrollPos(SB_HORZ,StartPoint.x);
		this->Invalidate(false);
		break;
	case SB_LINERIGHT:
		StartPoint.x += 10;
		if (StartPoint.x > hp.cx * (Zoom / 100) - hp.cy)
			StartPoint.x = hp.cx * (Zoom / 100) - hp.cy;
		this->SetScrollPos(SB_HORZ,StartPoint.x);
		this->Invalidate(false);
		break;
	case SB_PAGELEFT:
		StartPoint.x -= rect.right;
		if (StartPoint.x < 0)
			StartPoint.x = 0;
		this->SetScrollPos(SB_HORZ,StartPoint.x);
		this->Invalidate(false);
		break;
	case SB_PAGEDOWN:
		StartPoint.x += rect.right;
		if (StartPoint.x > hp.cx * (Zoom / 100) - hp.cy)
			StartPoint.x = hp.cx * (Zoom / 100) - hp.cy;
		this->SetScrollPos(SB_HORZ,StartPoint.x);
		this->Invalidate(false);
		break;
	case SB_THUMBTRACK:
		StartPoint.x = nPos;
		this->SetScrollPos(SB_HORZ,nPos);
		this->Invalidate(false);
		break;

	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CPreviewDialog::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CRect rect;
	this->GetClientRect(&rect);
	switch(nSBCode)
	{
	case SB_LINEUP:
		StartPoint.y -= 10;
		if (StartPoint.y < 0)
			StartPoint.y = 0;
		this->SetScrollPos(SB_VERT,StartPoint.y);
		this->Invalidate(false);
		break;
	case SB_LINEDOWN:
		StartPoint.y += 10;
		if (StartPoint.y > vp.cx * (Zoom / 100) - vp.cy)
			StartPoint.y = vp.cx * (Zoom / 100) - vp.cy;
		this->SetScrollPos(SB_VERT,StartPoint.y);
		this->Invalidate(false);
		break;
	case SB_PAGEUP:
		StartPoint.y -= rect.bottom;
		if (StartPoint.y < 0)
			StartPoint.y = 0;
		this->SetScrollPos(SB_VERT,StartPoint.y);
		this->Invalidate(false);
		break;
	case SB_PAGEDOWN:
		StartPoint.y += rect.bottom;
		if (StartPoint.y > vp.cx * (Zoom / 100) - vp.cy)
			StartPoint.y = vp.cx * (Zoom / 100) - vp.cy;
		this->SetScrollPos(SB_VERT,StartPoint.y);
		this->Invalidate(false);
		break;
	case SB_THUMBTRACK:
		StartPoint.y = nPos;
		this->SetScrollPos(SB_VERT,nPos);
		this->Invalidate(false);
		break;

	}
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CPreviewDialog::OnNext() 
{
	if (CurrentPage < PageCount)
	{
		CurrentPage += 1;
		this->Invalidate(false);
		UpdateStatusBar();
	}
}

void CPreviewDialog::OnPrevi()
{
	if (CurrentPage > 1)
	{
		CurrentPage -= 1;
		this->Invalidate(false);
		UpdateStatusBar();
	}
}

void CPreviewDialog::OnZoomOut()
{
	if (Zoom < 5000)
	{
		Zoom += 50;
		UpdateScroll();
		UpdateStatusBar();
	}
}

void CPreviewDialog::OnZoomIn()
{
	if (Zoom > 50)
	{
		Zoom -= 50;
		UpdateScroll();
		UpdateStatusBar();
	}
}

void CPreviewDialog::UpdateStatusBar()
{
	CString str;
	str.Format("%d 页",PageCount);
	StatusBar->SetPaneText(1,str);
	str.Format("第 %d 页",CurrentPage);
	StatusBar->SetPaneText(3,str);
	float n = (float)Zoom / 100;
	str.Format(" %% %d",(int)(n * 100));
	StatusBar->SetPaneText(5,str);
}


BOOL CPreviewDialog::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	if (nFlags & MK_CONTROL)
	{
		if ( zDelta < 0 )
			OnZoomOut();
		else
			OnZoomIn();
	}
	else
	{
		int pos = this->GetScrollPos(SB_VERT);
		if (zDelta < 0)
			pos += 10;
		else
			pos -= 10;
		
		if (pos < 0)
		{
			OnPrevi();
			pos = vp.cx * (Zoom / 100)-vp.cy;
		}
		else
		if (pos > vp.cx * (Zoom / 100)-vp.cy)
		{
			OnNext();
			pos = 0;
		}
		StartPoint.y = pos;
		this->SetScrollPos(SB_VERT,pos);
		this->Invalidate(false);


	}
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}

void CPreviewDialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	this->SetFocus();	
	CDialog::OnLButtonDown(nFlags, point);
}

