// TextProgress1.cpp : implementation file
//

#include "stdafx.h"
#include "TextProgress.h"
#include "TextProgress1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextProgress

CTextProgress::CTextProgress()
{
	m_crText	 = RGB(0, 255, 0);
	m_crBlank	 = RGB(255, 255, 255);
	m_crProgress = RGB(0, 0, 255);
}

CTextProgress::~CTextProgress()
{
}


BEGIN_MESSAGE_MAP(CTextProgress, CProgressCtrl)
	//{{AFX_MSG_MAP(CTextProgress)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextProgress message handlers

void CTextProgress::OnPaint() 
{
	PAINTSTRUCT ps;
	CDC* pDC = BeginPaint(&ps);						//开始绘制
	int nPos = GetPos();							//获取当前进度条的位置
	CString csPos;
	csPos.Format("%d%%", nPos);						//格式化字符串
	CRect clientRC;
	GetClientRect(clientRC);						//获取客户区域
	CSize sztext = pDC->GetTextExtent(csPos);		//获取字符串的高度和宽度
	int nX = (clientRC.Width() - sztext.cx) / 2;	//计算中心位置
	int nY = (clientRC.Height() - sztext.cy) / 2;
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
	pDC->FillRect(leftRC, &CBrush(m_crProgress));	//使用蓝色标识当前的进度
	pDC->FillRect(rightRC, &CBrush(m_crBlank));		//使用白色标识剩余的部分
	pDC->SetTextColor(m_crText);					//设置文本颜色
	pDC->TextOut(nX, nY, csPos);					//输出当前的进度
	ReleaseDC(pDC);									//释放设备上下文
	EndPaint(&ps);									//结束窗口绘制	
}


