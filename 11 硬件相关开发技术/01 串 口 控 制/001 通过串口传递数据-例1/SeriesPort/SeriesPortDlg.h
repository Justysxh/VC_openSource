// SeriesPortDlg.h : header file
//

#if !defined(AFX_SERIESPORTDLG_H__176D8858_6FF2_4DAF_A7B8_36B62FCC41E0__INCLUDED_)
#define AFX_SERIESPORTDLG_H__176D8858_6FF2_4DAF_A7B8_36B62FCC41E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSeriesPortDlg dialog

class CSeriesPortDlg : public CDialog
{
// Construction
public:
	
	CSeriesPortDlg(CWnd* pParent = NULL);	// standard constructor
	
	HANDLE hCom; //串口句柄
	HANDLE hThread;//线程句柄
	DWORD dwThreadID; //线程ID
	CString str; 
	char DataBuffer[1024]; //接收数据的缓冲区

// Dialog Data
	//{{AFX_DATA(CSeriesPortDlg)
	enum { IDD = IDD_SERIESPORT_DIALOG };
	CEdit	m_info;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeriesPortDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSeriesPortDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnRecieveData(WPARAM wParam,LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIESPORTDLG_H__176D8858_6FF2_4DAF_A7B8_36B62FCC41E0__INCLUDED_)
