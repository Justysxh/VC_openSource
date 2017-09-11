// IncomingShowDlg.h : header file
//

#if !defined(AFX_INCOMINGSHOWDLG_H__FB6D9718_7C3D_4E42_AA20_D73E3EE584FF__INCLUDED_)
#define AFX_INCOMINGSHOWDLG_H__FB6D9718_7C3D_4E42_AA20_D73E3EE584FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIncomingShowDlg dialog

typedef struct LINESTRUCT
{
	int     nType;
	int     State;
	CString CallerID;
	char    Dtmf[32];
	int     nTimeElapse;
	BOOL    IsReceiving;
	BOOL    Inited;
	WORD    m_BusySum;
} *lpLINESTRUCT;

enum CHANNEL_STATE {
	CH_FREE,
	CH_RECEIVEID,
	CH_WAITSECONDRING,
	CH_WELCOME,
	CH_ACCOUNT,
	CH_ACCOUNT1,
	CH_PASSWORD,
	CH_PASSWORD1,
	CH_SELECT,
	CH_SELECT1,
	CH_PLAYRESULT,
	CH_RECORDFILE,
	CH_PLAYRECORD,
	CH_OFFHOOK,
	CH_WAITUSERONHOOK,


	CH_CS_RING,
	CH_CS_PLAY,

	CH_EMVOC_SENDDTMF,

};

class CIncomingShowDlg : public CDialog
{
// Construction
public:
	void ReadNumber(WORD nID);
	void OnCancel();
	CIncomingShowDlg(CWnd* pParent = NULL);	// standard constructor
	
	WORD          m_ChanelCount;
	
	BOOL          m_IsReceiving;
	lpLINESTRUCT  m_pLines;
	CString       m_CurNumber ;
	CString       m_CurTime;


// Dialog Data
	//{{AFX_DATA(CIncomingShowDlg)
	enum { IDD = IDD_INCOMINGSHOW_DIALOG };
	CListCtrl	m_CardList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIncomingShowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIncomingShowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INCOMINGSHOWDLG_H__FB6D9718_7C3D_4E42_AA20_D73E3EE584FF__INCLUDED_)
