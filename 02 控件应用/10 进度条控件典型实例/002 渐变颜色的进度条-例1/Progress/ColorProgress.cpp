// ColorProgress.cpp : implementation file
//

#include "stdafx.h"
#include "Progress.h"
#include "ColorProgress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorProgress

CColorProgress::CColorProgress()
{
}

CColorProgress::~CColorProgress()
{
}


BEGIN_MESSAGE_MAP(CColorProgress, CProgressCtrl)
	//{{AFX_MSG_MAP(CColorProgress)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorProgress message handlers

void CColorProgress::OnPaint() 
{
//	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	PAINTSTRUCT ps;
	CDC* pDC = BeginPaint(&ps);						//开始绘制
	int nPos = GetPos();							//获取当前进度条的位置
	CRect clientRC;
	GetClientRect(clientRC);						//获取客户区域
	pDC->SetBkMode(TRANSPARENT);					//将设备上下文的背景模式设置为透明
	int nMin, nMax;
	GetRange(nMin, nMax);							//获取进度条的显示范围
	//获取单位刻度
	double dFraction = (double)clientRC.Width() / (nMax-nMin);
	int nLeft = nPos * dFraction;					//计算左边距
	CRect leftRC  = clientRC;
	leftRC.right  = nLeft;
	CRect rightRC = clientRC;
	rightRC.left  = nLeft;
	for(int m=255;m>0;m--)
	{
		int x,y;
		x = leftRC.Width() * m / 255;
		pDC->FillRect(CRect(0,0,x,leftRC.Height()),&CBrush(RGB(255,m,0)));
	}
	pDC->FillRect(rightRC, &CBrush(RGB(255, 255, 255)));		//使用白色标识剩余的部分
	ReleaseDC(pDC);									//释放设备上下文
	EndPaint(&ps);									//结束窗口绘制
	// Do not call CProgressCtrl::OnPaint() for painting messages
}
