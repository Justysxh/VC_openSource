// PrintResumeDlg.h : header file
//

#if !defined(AFX_PRINTRESUMEDLG_H__63DCB9CE_DFBC_4AD6_9758_AB07EE1FF992__INCLUDED_)
#define AFX_PRINTRESUMEDLG_H__63DCB9CE_DFBC_4AD6_9758_AB07EE1FF992__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrintResumeDlg dialog


class CPrintResumeDlg : public CDialog
{
// Construction
public:
	HBITMAP GetBitmapFromField();
	void DrawReport(CDC* pDC,CRect m_rect,BOOL isPrinted);

	CPrintResumeDlg(CWnd* pParent = NULL);	// standard constructor

	CImageList m_imagelist; //图像列表
	CReBar     m_rebar;     //Rebar控件
	CToolBar   m_toolbar;   //工具栏

	BOOL isInited;
	HBITMAP  hbitmap;
	CBitmap m_bitmap;
	CBitmap bitmap;

	int screenx,screeny;
	int printerx,printery;
	double ratex,ratey;

	CDC* tempDC;

// Dialog Data
	//{{AFX_DATA(CPrintResumeDlg)
	enum { IDD = IDD_PRINTRESUME_DIALOG };

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintResumeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrintResumeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButtonprint();
	afx_msg void OnMenuitem32771();
	afx_msg void OnMovePrior();
	afx_msg void OnMoveNext();
	afx_msg void OnPrint();
	afx_msg void OnQuit();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTRESUMEDLG_H__63DCB9CE_DFBC_4AD6_9758_AB07EE1FF992__INCLUDED_)
