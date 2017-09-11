// SoundCardCallDlg.h : header file
//

#if !defined(AFX_SOUNDCARDCALLDLG_H__F0FA46A5_61F9_4D3D_A6A1_C6C2228597E3__INCLUDED_)
#define AFX_SOUNDCARDCALLDLG_H__F0FA46A5_61F9_4D3D_A6A1_C6C2228597E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSoundCardCallDlg dialog

typedef struct LINESTRUCT
{
	int nType;
	int State;
	char TelNum[32];
}* lpLINESTRUCT;

enum CHANNEL_STATE {
	CH_FREE,
	CH_DIAL,
	CH_CHECKSIG,
	CH_PLAY,
	CH_ONHOOK,
	CH_CONNECT,
	CH_OFFHOOK,
	CH_BUSY,
	CH_NOBODY,
	CH_NOSIGNAL,
	CH_NODIALTONE,
	CH_NORESULT
};

class CSoundCardCallDlg : public CDialog
{
// Construction
public:
	void OnCancel();
	CSoundCardCallDlg(CWnd* pParent = NULL);	// standard constructor
	lpLINESTRUCT m_pLines;

	WORD m_Chanels;

	int m_CurChanel;  //当前通道
	CString m_CurNumber; //当前号码
// Dialog Data
	//{{AFX_DATA(CSoundCardCallDlg)
	enum { IDD = IDD_SOUNDCARDCALL_DIALOG };
	CEdit	m_Number;
	CComboBox	m_Chanel;
	CListCtrl	m_CardList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoundCardCallDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSoundCardCallDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOUNDCARDCALLDLG_H__F0FA46A5_61F9_4D3D_A6A1_C6C2228597E3__INCLUDED_)
