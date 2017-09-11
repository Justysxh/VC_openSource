// ShowGIFDlg.h : header file
//

#if !defined(AFX_SHOWGIFDLG_H__6C898078_57B6_4AC4_9508_47F3E430B1A0__INCLUDED_)
#define AFX_SHOWGIFDLG_H__6C898078_57B6_4AC4_9508_47F3E430B1A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShowGIFDlg dialog
#pragma comment (lib, "Gdiplus//GdiPlus.lib")
#include "Gdiplus//Gdiplus.h"
using namespace Gdiplus;

class CShowGIFDlg : public CDialog
{
// Construction
public:
	CShowGIFDlg(CWnd* pParent = NULL);	//standard constructor

	GdiplusStartupInput m_Gdiplus;		//定义GDI+初始化变量
	ULONG_PTR			m_pGdiToken;	//定义GID+标识
	Bitmap*             m_pBmp;			//定义位图对象
	BOOL				m_bLoaded;		//是否已加载图像
	int					m_nFrameIndex;	//记录当前显示帧索引
// Dialog Data
	//{{AFX_DATA(CShowGIFDlg)
	enum { IDD = IDD_SHOWGIF_DIALOG };
	CStatic	m_DemoArea;
	CEdit	m_GifName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowGIFDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CShowGIFDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBrown();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWGIFDLG_H__6C898078_57B6_4AC4_9508_47F3E430B1A0__INCLUDED_)
