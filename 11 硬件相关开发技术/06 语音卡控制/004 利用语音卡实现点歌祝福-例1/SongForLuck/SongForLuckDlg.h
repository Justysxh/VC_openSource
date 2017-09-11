// SongForLuckDlg.h : header file
//

#if !defined(AFX_SONGFORLUCKDLG_H__C88B91C9_A518_46B2_82A5_E473C30B1D58__INCLUDED_)
#define AFX_SONGFORLUCKDLG_H__C88B91C9_A518_46B2_82A5_E473C30B1D58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSongForLuckDlg dialog
typedef struct LINESTRUCT
{
	int     nType;
	int     State;
	CString CallerID;
	char    Dtmf[32];
	int     nTimeElapse;
	BOOL    RING;
	WORD    m_BusySum;
	BOOL    IsSong;
	BOOL    Inited;
} *lpLINESTRUCT ;



class CSongForLuckDlg : public CDialog
{
// Construction
public:
	CSongForLuckDlg(CWnd* pParent = NULL);	// standard constructor

	char ConvertToASCII(short ch);


	int           m_ChanelCount;  //通道数量
	BOOL          m_Received;     
	CString       m_PressCh;      //按键字符
	BOOL          m_IsSong;       //是否开始播放歌曲
	lpLINESTRUCT  m_pChanel;      //通道列表
// Dialog Data
	//{{AFX_DATA(CSongForLuckDlg)
	enum { IDD = IDD_SONGFORLUCK_DIALOG };
	CListCtrl	m_CardList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSongForLuckDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSongForLuckDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SONGFORLUCKDLG_H__C88B91C9_A518_46B2_82A5_E473C30B1D58__INCLUDED_)
