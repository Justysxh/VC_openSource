// PreviewDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ScrollPreview.h"
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
	Create(IDD_PreviewDialog);
	isPrint = false;

}


void CPreviewDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreviewDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

void CPreviewDialog::Show()
{
	ShowWindow(SW_SHOW);
}

void CPreviewDialog::SetPreviewEvent(DrawPreview OnEvent)
{
	if (OnEvent != NULL)
		OnDrawPreview = OnEvent;
}

BEGIN_MESSAGE_MAP(CPreviewDialog, CDialog)
	//{{AFX_MSG_MAP(CPreviewDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreviewDialog message handlers

void CPreviewDialog::OnPaint() 
{

	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here

	CRect rect;
	GetClientRect(&rect);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc,rect.right,rect.bottom);
	CDC memdc;
	memdc.CreateCompatibleDC(NULL);
	memdc.SelectObject(&bitmap);
	CBrush *b;
	b = (memdc.GetHalftoneBrush());
	memdc.SelectObject(b);
	rect.InflateRect(5,5,5,5);
	memdc.Rectangle(&rect);

	CPen pen(BS_SOLID,2,RGB(0,0,0));
	CBrush brush(RGB(255,255,255));
	memdc.SelectObject(&pen);
	memdc.SelectObject(&brush);
	CRect DrawRect(50-posx,50-posy,50-posx +nW,50-posy+nH);
	DrawRect.InflateRect(2,2,2,2);
	memdc.Rectangle(&DrawRect);

	if (OnDrawPreview != NULL)
	{
		CRect DrawClientRect(posx,posy,nW-posx,nH-posy);
		memdc.SetViewportOrg(50-posx,50-posy);
		OnDrawPreview((CDC*)&memdc,DrawClientRect,isPrint);
		memdc.SetViewportOrg(0,0);
		dc.BitBlt(0,0,rect.right,rect.bottom
			,&memdc,0,0,SRCCOPY);
	}
}

HBRUSH CPreviewDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	return hbr;
}

BOOL CPreviewDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CPrintDialog pdlg(false);
	pdlg.GetDefaults();
	PrintDC.Attach(pdlg.GetPrinterDC());
	CClientDC screendc(this);
	nW = (int)(screendc.GetDeviceCaps(LOGPIXELSX) 
			/ 25.4 * PrintDC.GetDeviceCaps(HORZSIZE));
	nH = (int)(screendc.GetDeviceCaps(LOGPIXELSY) 
			/ 25.4 * PrintDC.GetDeviceCaps(VERTSIZE));

	this->ModifyStyle(0,WS_HSCROLL | WS_VSCROLL,0);

	int vW,vH;
	vW = nW + 100;
	vH = nH + 100;

	this->SetScrollRange(SB_HORZ,0,vW,true);
	this->SetScrollRange(SB_VERT,0,vH,true);

	posx = 0;
	posy = 0;

	return TRUE;  
}

void CPreviewDialog::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	SetScrollbar(cx, cy);
	this->Invalidate(false);

}

	void CPreviewDialog::SetScrollbar(int cx, int cy)
	{
		int vW,vH;
		vW = nW + 100;
		vH = nH + 100;

		posx = posy = 0;

		CRect rect;
		GetClientRect(&rect);

		SCROLLINFO si;
		si.cbSize = sizeof (si) ;
		si.fMask  = SIF_ALL;
		si.nMin   = 0;
		si.nMax   = vH;		//内容的高度
		si.nPage  = rect.Height();	//页面的高度
		si.nPos = 0;
		SetScrollInfo(SB_VERT, &si, TRUE);


		si.nMin   = 0;
		si.nMax   = vW;		//内容的宽度
		si.nPage  = rect.Width();	//页面的宽度
		si.nPos = 0;
		SetScrollInfo(SB_HORZ, &si, TRUE);
	}


void CPreviewDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nSBCode)
	{
		case SB_THUMBTRACK:
			this->SetScrollPos(SB_HORZ,nPos);
			posx = nPos;
			this->Invalidate(false);
			break;
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CPreviewDialog::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nSBCode)
	{
		case SB_TOP:
			break;
		case SB_BOTTOM:
			;	break;
		case SB_LINEUP:
			;	break;
		case SB_LINEDOWN:
			;	break;
		case SB_PAGEUP:
			;	break;
		case SB_PAGEDOWN:
			posy = nPos;
			this->Invalidate(false);
			break;
		case SB_THUMBPOSITION:
			this->SetScrollPos(SB_VERT,nPos);
			break;
		case SB_THUMBTRACK:
			posy = nPos;
			this->Invalidate(false);
			break;
	}
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CPreviewDialog::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	int pos = this->GetScrollPos(SB_VERT);
	if (zDelta < 0)
		pos += 10;
	else
		pos -= 10;
	posy = pos;
	if (posy < 0)
		posy = 0;
	if (posy > nH + 100)
		posy = nH + 100;
	this->SetScrollPos(SB_VERT,pos);
	this->Invalidate(false);
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}
