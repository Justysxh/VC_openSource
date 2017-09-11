// HelpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PictureGame.h"
#include "HelpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg dialog


CHelpDlg::CHelpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelpDlg)
	DDX_Control(pDX, IDC_STATICHELP, m_picture);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialog)
	//{{AFX_MSG_MAP(CHelpDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg message handlers

void CHelpDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	HBITMAP m_hBitmap;
	m_hBitmap=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),m_Path,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTCOLOR|LR_DEFAULTSIZE);	
	CDC* pDC = m_picture.GetDC();
	//将位图选进设备场景中
	CDC memdc;	
	memdc.CreateCompatibleDC( pDC );
	memdc.SelectObject(m_hBitmap);
	BITMAP bmp;
	GetObject(m_hBitmap,sizeof(bmp),&bmp);	
	CRect rect;
	m_picture.GetClientRect(&rect);
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	memdc.DeleteDC();
}
