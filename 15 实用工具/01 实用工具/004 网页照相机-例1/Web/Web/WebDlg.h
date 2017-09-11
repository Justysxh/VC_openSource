// WebDlg.h : 头文件
//

#pragma once
#include "explorer1.h"
#include "afxwin.h"


// CWebDlg 对话框
class CWebDlg : public CDialog
{
// 构造
public:
	CWebDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WEB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_Web;
public:
	afx_msg void OnBnClickedOk();
public:
	CEdit m_Url;
public:
	afx_msg void OnBnClickedLocate();
};
