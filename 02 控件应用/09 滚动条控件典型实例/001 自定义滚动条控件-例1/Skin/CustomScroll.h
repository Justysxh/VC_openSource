#if !defined(AFX_CUSTOMSCROLL_H__783E2CD7_18AF_4F83_B4DC_D38723370FCE__INCLUDED_)
#define AFX_CUSTOMSCROLL_H__783E2CD7_18AF_4F83_B4DC_D38723370FCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomScroll.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomScroll window


class CMemDC : public CDC 
{
private:
	CBitmap*	m_bmp;
	CBitmap*	m_oldbmp;
	CDC*		m_pDC;
	CRect		m_Rect;
public:
	CMemDC(CDC* pDC, const CRect& rect) : CDC()
	{
		CreateCompatibleDC(pDC);
		m_bmp = new CBitmap;
		m_bmp->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
		m_oldbmp = SelectObject(m_bmp);
		m_pDC = pDC;
		m_Rect = rect;
	}
	~CMemDC() 
	{
		m_pDC->BitBlt(m_Rect.left, m_Rect.top, m_Rect.Width(), m_Rect.Height(), 
				this, m_Rect.left, m_Rect.top, SRCCOPY);
		SelectObject(m_oldbmp);
		if (m_bmp != NULL) 
			delete m_bmp;
	}
};


class CCustomScroll : public CStatic
{
// Construction
public:
	CCustomScroll();
	UINT       m_ThumbWidth;  //滚动块和箭头宽度
	UINT       m_ThumbHeight; //滚动块和箭头高度
	CWnd*      m_pParent;     //父窗口
	CRect      m_ClientRect;  //窗口客户区域

	CRect      m_ThumbRect;   //滚动块区域

	BOOL       m_ButtonDown;  //鼠标是否单击滚动块
	CPoint     m_Startpt;     //鼠标按下时的起点
	BOOL       m_IsLeft;      //滚动块是否超过左箭头
	BOOL       m_IsLeftArrow; //是否单击左滚动条按钮
	BOOL       m_IsRightArrow;//是否单击右滚动条按钮  
	BOOL       m_IsLeftRange; //是否单击了左滚动区域
	BOOL       m_IsRightRange;//是否单击了右滚动区域

	UINT       m_MinRange;    //最小滚动范围
	UINT       m_MaxRange;    //最大滚动范围
	UINT       m_CurPos;      //当前的位置(逻辑单位)
	double     m_Rate;        //物理像素与逻辑单位的比率

	UINT       m_LeftArrow;   //左箭头位图ID
	UINT       m_RightArrow;  //右箭头位图ID
	UINT       m_ChanelBK;    //背景位图ID
	UINT       m_ThumbBK;     //滚动块位图ID

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomScroll)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetScrollRange(int minRange,int maxRange);
	void DrawHorScroll();
	void DrawControl();
	BOOL CreateStatic(CWnd* pParent,DWORD dwStyle,UINT nIDStatic,UINT nID);
	virtual ~CCustomScroll();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomScroll)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMSCROLL_H__783E2CD7_18AF_4F83_B4DC_D38723370FCE__INCLUDED_)
