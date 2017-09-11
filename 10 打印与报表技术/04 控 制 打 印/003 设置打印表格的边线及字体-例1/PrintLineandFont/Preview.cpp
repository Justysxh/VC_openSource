// Preview.cpp : implementation file
//

#include "stdafx.h"
#include "PrintLineandFont.h"
#include "Preview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreview dialog


CPreview::CPreview(CWnd* pParent /*=NULL*/)
	: CDialog(CPreview::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreview)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPreview::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreview)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreview, CDialog)
	//{{AFX_MSG_MAP(CPreview)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreview message handlers

void CPreview::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	PreviewGrid(&dc,false);

	// Do not call CDialog::OnPaint() for painting messages
}

void CPreview::PreviewGrid(CDC * dc,bool isprint)
{
	if (PrintGrid == NULL)
		return ;

	double ratex,ratey;
	if (isprint)
		GetPrintRate(ratex,ratey);
	else
		ratex = ratey = 1;

	int columns = PrintGrid->GetHeaderCtrl()->GetItemCount();
	int items = PrintGrid->GetItemCount();
	CFont font;
	if (isfont)
		font.CreateFontIndirect(&logfont);
	else
		font.CreatePointFont(90,"ËÎÌו",dc);
	dc->SelectObject(&font);
	CPen pen(PS_SOLID,LineWidth,RGB(0,0,0));
	if (LineWidth > 0)
		dc->SelectObject(&pen);
	for (int i = 0;i< columns;i++)
	{
		CRect rect;
		PrintGrid->GetHeaderCtrl()->GetItemRect(i,&rect);
		rect.left *= ratex;
		rect.top *= ratey;
		rect.right *= ratex;
		rect.bottom *= ratey;
		if (i>0)
			rect.OffsetRect(-(int)(i*ratex),0);
		dc->Rectangle(&rect);
		LVCOLUMN column;
		char mm[255];
		column.mask = LVCF_TEXT;
		column.pszText = mm;
		column.cchTextMax = 255;
		PrintGrid->GetColumn(i,&column);
		dc->SetBkMode(TRANSPARENT);
		dc->TextOut(rect.left + 2*ratex,rect.top + 2*ratey,column.pszText);
	}
	for (int n = 0 ;n < items;n++)
	{
		CRect rect;
		PrintGrid->GetItemRect(n,&rect,LVIR_BOUNDS);
		rect.left *= ratex;
		rect.top *= ratey;
		rect.right *= ratex;
		rect.bottom *= ratey;

		rect.OffsetRect(0,-(3+n)*ratey);
		rect.InflateRect(0,0,-(columns - 1)*ratex,0);
		dc->Rectangle(&rect);
		for (int m = 0;m<columns;m++)
		{
			CRect rectw;
			PrintGrid->GetHeaderCtrl()->GetItemRect(m,&rectw);
			rectw.left *= ratex;
			rectw.top *= ratey;
			rectw.right *= ratex;
			rectw.bottom *= ratey;
			dc->MoveTo(rectw.right - m -1,rect.top);
			dc->LineTo(rectw.right - m -1,rect.bottom);
			CString text = PrintGrid->GetItemText(n,m);
			dc->TextOut(rectw.left,rect.top,text);
		}
	}
}

void CPreview::GetPrintRate(double &ratex,double &ratey)
{
	CClientDC sdc(this);
	CPrintDialog pdlg(false);
	pdlg.GetDefaults();
	CDC pdc;
	pdc.Attach(pdlg.GetPrinterDC());
	ratex = pdc.GetDeviceCaps(LOGPIXELSX) /
		sdc.GetDeviceCaps(LOGPIXELSX);
	ratey = pdc.GetDeviceCaps(LOGPIXELSY) /
		sdc.GetDeviceCaps(LOGPIXELSY);
}