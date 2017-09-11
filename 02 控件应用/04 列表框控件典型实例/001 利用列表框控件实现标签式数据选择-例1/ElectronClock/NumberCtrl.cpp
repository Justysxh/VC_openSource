// NumberCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ElectronClock.h"
#include "NumberCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumberCtrl

CNumberCtrl::CNumberCtrl()
{
	m_csText = "";
	m_nNumberWidth = 26;
	m_nNumberHeight = 34;
	m_nNumberLen = 8;
}

CNumberCtrl::~CNumberCtrl()
{

}


BEGIN_MESSAGE_MAP(CNumberCtrl, CStatic)
	//{{AFX_MSG_MAP(CNumberCtrl)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumberCtrl message handlers

void CNumberCtrl::OnPaint() 
{
	CPaintDC dc(this); 
	SetRedraw(FALSE);								//禁止窗口绘制
	CRect clientRC;
	GetClientRect(clientRC);							//获取窗口客户区域
	CMemDC memDC(&dc, clientRC);					//定义内存画布
	SetWindowText("");
	CBitmap bmp;
	bmp.LoadBitmap(IDB_NUMBERBMP);					//加载位图
	CDC tmpDC;
	tmpDC.CreateCompatibleDC(&dc);					//创建一个兼容的设备上下文
	tmpDC.SelectObject(&bmp);							//选中位图对象
	BITMAP bInfo;									//定义位图信息
	bmp.GetBitmap(&bInfo);							//获取位图信息
	int nbmpWidth = bInfo.bmWidth;						//获取位图宽度
	int nbmpHeight = bInfo.bmHeight;						//获取位图高度
	int nLen = m_csText.GetLength();						//获取文本长度
	for (int i=0; i<m_nNumberLen; i++)					//绘制背景
	{
		memDC.BitBlt((i)*m_nNumberWidth, 0, m_nNumberWidth, nbmpHeight, 
			&tmpDC, 10*m_nNumberWidth, 0, SRCCOPY);
	}
	if (nLen>0 && nLen<=m_nNumberLen)					//判断数字是否合法
	{
		for (int n=0; n<nLen; n++)
		{
			char ch = m_csText[nLen-n-1];
			if (ch == ':' )
			{
				memDC.BitBlt((m_nNumberLen-10)*m_nNumberWidth, 0, m_nNumberWidth,
						nbmpHeight, &tmpDC, m_nNumberWidth, 0, SRCCOPY);
			}
			else
			{
				int nCh = atoi(&ch);
				//绘制数字位图
				memDC.BitBlt((m_nNumberLen-n-1)*m_nNumberWidth, 0, m_nNumberWidth,
						nbmpHeight, &tmpDC, (nCh)*m_nNumberWidth, 0, SRCCOPY);
			}
		}
	}
	bmp.DeleteObject();								//删除位图对象
	tmpDC.DeleteDC();
	SetRedraw();									//激活窗口绘制
}

void CNumberCtrl::SetText(LPCTSTR text)
{
	m_csText = text;
	RedrawWindow();
}

LPTSTR CNumberCtrl::GetText()
{
	return m_csText.GetBuffer(0);
}

void CNumberCtrl::SubClassCtrl(UINT uID, CWnd *pParent)
{
	SubclassDlgItem(uID, pParent);						//子类化对象
	CRect winRC;
	GetWindowRect(winRC);							//获取窗口区域
	ScreenToClient(winRC);
	MapWindowPoints(pParent,winRC);					//将窗口坐标映射到父窗口中
	winRC.right = winRC.left+m_nNumberLen*m_nNumberWidth;//设置窗口宽度
	winRC.bottom = winRC.top+m_nNumberHeight;			//设置窗口高度
	MoveWindow(winRC);								//设置控件显示的位置
}

