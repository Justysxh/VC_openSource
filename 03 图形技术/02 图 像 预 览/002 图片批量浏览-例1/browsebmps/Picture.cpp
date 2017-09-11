// Picture.cpp : implementation file
//

#include "stdafx.h"
#include "browsebmps.h"
#include "Picture.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicture

CPicture::CPicture()
{
}

CPicture::~CPicture()
{
}


BEGIN_MESSAGE_MAP(CPicture, CStatic)
	//{{AFX_MSG_MAP(CPicture)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicture message handlers

void CPicture::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	//获得窗口大小
	CRect r;
	GetClientRect(&r);
	//将位图选进设备场景中
	CDC memdc;	
	memdc.CreateCompatibleDC( &dc );
	memdc.SelectObject(hBitmap);

	dc.StretchBlt(r.left,r.top,270,200,&memdc,0,0,
			(r.right-r.left),(r.bottom-r.top),SRCCOPY);	
	memdc.DeleteDC();
	// Do not call CStatic::OnPaint() for painting messages
}

void CPicture::SetImage(HBITMAP Bitmap)
{
	hBitmap = Bitmap;
	SetBitmap(Bitmap);
}



void CPicture::Picturerect(int height, int width)
{
	pHeight = height;
	pWidth = width;
}
