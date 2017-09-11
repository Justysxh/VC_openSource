#if !defined(AFX_QQLIST_H__C1D981D1_5FDD_4E18_9307_5E54DABF9E5C__INCLUDED_)
#define AFX_QQLIST_H__C1D981D1_5FDD_4E18_9307_5E54DABF9E5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QQList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQQList window
//定义双击列表视图项的回调函数
typedef void(ItemDlbFun)(const CListCtrl* pListCtrl,int nItemIndex);
class CQQList : public CListCtrl
{
// Construction
public:
	CQQList();
	CPtrArray	m_pButton;				//按钮数组
	UINT		m_ButtonCount ;			//按钮数量
	UINT		m_ButtonHeight;			//按钮高度
	UINT		m_LeftMargin;			//图像列表显示的左边距
	CListCtrl	m_ClientList;			//在客户区域显示视图项
	ItemDlbFun* m_pItemDlbFun;			//视图项的双击事件
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQList)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetImageLists(CImageList *pImagelist);
	void ShowButtonItems(UINT nIndex);//显示指定按钮关联的列表视图项
	void AddButtonItems(UINT nIndex, CString &strItem, int nImageIndex);
	CRect GetListClientRect();
	UINT GetBtmTopIndex();//获取下方按钮的顶层索引
	UINT GetBtmBtnHeight();
	UINT GetTopButtonHeight();//返回顶层按钮的高度
	UINT CommandToIndex(UINT nID);//根据按钮命令返回索引
	void OnButtonDown(UINT bIndex, UINT nID);//按钮的单击处理
	CRect GetAddButtonRect();//获取将要添加按钮的客户区域
	void AddButton(LPCSTR Btntext,UINT uID);
	virtual ~CQQList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CQQList)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQLIST_H__C1D981D1_5FDD_4E18_9307_5E54DABF9E5C__INCLUDED_)
