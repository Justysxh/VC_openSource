// RegFigureDlg.h : header file
//

#if !defined(AFX_REGFIGUREDLG_H__D9664395_532E_4B3B_B1B8_3382E5071471__INCLUDED_)
#define AFX_REGFIGUREDLG_H__D9664395_532E_4B3B_B1B8_3382E5071471__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRegFigureDlg dialog

enum Dir{left,right,up,down,none};

struct Figure
{
	Dir  Direction[16]; //方向 0-left 1-right 2-up 3 -down 
	int  DotCount ;    //断笔数
};


class CRegFigureDlg : public CDialog
{
// Construction
public:
	void DrawGrid(int row,int col);
	CRegFigureDlg(CWnd* pParent = NULL);	// standard constructor

	CRect m_rect;
	BOOL m_Buttondowned; 
	CPen pen;
	CPoint m_Startpt;
	CPoint m_Endpt;
	
	CPoint	m_Prept;		//之前的坐标点
	Figure	m_Figure;		//数字对象
	int		m_curpen;		//当前笔数
	BOOL	m_Isreg;		//是否开始识别

// Dialog Data
	//{{AFX_DATA(CRegFigureDlg)
	enum { IDD = IDD_REGFIGURE_DIALOG };
	CStatic	m_Panel;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegFigureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRegFigureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnOK();
	afx_msg void OnReg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGFIGUREDLG_H__D9664395_532E_4B3B_B1B8_3382E5071471__INCLUDED_)
