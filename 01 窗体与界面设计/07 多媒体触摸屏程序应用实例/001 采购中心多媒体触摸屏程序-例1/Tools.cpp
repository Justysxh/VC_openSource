// Tools.cpp : implementation file
//

#include "stdafx.h"
#include "窗体融合技术.h"
#include "Tools.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTools dialog


CTools::CTools(CWnd* pParent /*=NULL*/)
	: CDialog(CTools::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTools)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTools::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTools)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTools, CDialog)
	//{{AFX_MSG_MAP(CTools)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTools message handlers

void CTools::OnOK() 
{
	MessageBox("sdfasdf");
}

void CTools::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	BITMAPINFO bInfo;
	bmp.GetObject(sizeof(bInfo),&bInfo);

	int bWidth = bInfo.bmiHeader.biWidth;
	int bHeight = bInfo.bmiHeader.biHeight;

	CRect rect;
	GetClientRect(rect);

	memdc.SelectObject(&bmp);

	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,bWidth,bHeight,SRCCOPY);

	bmp.DeleteObject();
	
	// Do not call CDialog::OnPaint() for painting messages
}
