#if !defined(AFX_DOCKBARCTRL_H__52BCC555_E091_4BCA_9991_2B2A36F655AB__INCLUDED_)
#define AFX_DOCKBARCTRL_H__52BCC555_E091_4BCA_9991_2B2A36F655AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DockBarCtrl.h : header file
//
#include "afxpriv.h"
/////////////////////////////////////////////////////////////////////////////
// CDockBarCtrl window

class CDockBarCtrl : public CControlBar
{
// Construction
public:
	CDockBarCtrl();

// Attributes
public:
	UINT m_DockBarID;
	
	CDialog *m_pDlg;      //关联的对话框
	CBrush m_bkBrush;     //背景画刷
	CString m_Caption;    //窗口标题

	CRect m_FloatRect;    //浮动时的窗口区域
	CRect m_VerRect;      //拖入时,在左\右显示时的区域
	CRect m_HorRect;      //拖入时,在上\下显示时的区域

	//确定控制条的非客户区域部分
	int m_ncTBandHeight;  //非客户区域上边条高度
	int m_ncRBandWidth;   //右边条的宽度
	int m_ncLBandWidth ;  //确定左边条的宽度
	int m_ncBBandHeight;  // 确定底边条的宽度

	//定义标题栏按钮的显示区域
	
	CRect m_closeRC; //关闭按钮的显示区域
	CRect m_maxRc;   //最大化按钮的显示区域

	int m_ncLeftWidth ; //记录垂直显示时的非客户区域左边条宽度
	int m_ncTopHeight;  // 记录水平显示时的非客户区域上边条的宽度

	COLORREF m_TopBandColor,m_BottomBandColor; //标题线条的颜色

	BOOL  m_IsTraking; //是否处于调整控制条大小状态
	BOOL  m_IsInRect;  //判断控制条是否处于停靠状态
	
	CPoint m_OldPos;  //鼠标按下时原始点位置
	CRect m_Bandrc;   //拖动的边条区域

	CRect m_temprc;   //临时的区域
	int m_TopInterval,m_LeftInterval; //控制条相对父窗口的位置

	int m_HitTest;
	CSize m_Min; //当控制条处于浮动状态时,限制用户改变控制小的最小区域

	 
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDockBarCtrl)
	public:
	virtual BOOL Create(CWnd* pParentWnd, CDialog* pDialog, UINT nID, DWORD dwStyle= WS_CHILD | WS_VISIBLE | CBRS_LEFT, CCreateContext* pContext = NULL);
	virtual CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz);
	virtual CSize CalcDynamicLayout(int nLength, DWORD nMode);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawDashLine(CRect rect);
	void EndTracking();
	void BeginTracking();
	void DrowTitleLine(CDC* pDC);
	virtual ~CDockBarCtrl();
	
	//实现父类的抽象方法
	virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler);
	// Generated message map functions
protected:
	//{{AFX_MSG(CDockBarCtrl)
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	afx_msg void OnNcPaint();
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCKBARCTRL_H__52BCC555_E091_4BCA_9991_2B2A36F655AB__INCLUDED_)
