// PhoneRecordDlg.h : header file
//

#if !defined(AFX_PHONERECORDDLG_H__A58C27EC_1A72_4A21_B9E9_89AB8FABE0C9__INCLUDED_)
#define AFX_PHONERECORDDLG_H__A58C27EC_1A72_4A21_B9E9_89AB8FABE0C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPhoneRecordDlg dialog

class CPhoneRecordDlg : public CDialog
{
// Construction
public:
	void OnCancel();
	CPhoneRecordDlg(CWnd* pParent = NULL);	// standard constructor
	
	BOOL m_IsOffHook;   //是否摘机
	WORD m_ChanelCount; //通道数
	int  m_Num;         //计数
// Dialog Data
	//{{AFX_DATA(CPhoneRecordDlg)
	enum { IDD = IDD_PHONERECORD_DIALOG };
	CListCtrl	m_CardList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhoneRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPhoneRecordDlg)
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

#endif // !defined(AFX_PHONERECORDDLG_H__A58C27EC_1A72_4A21_B9E9_89AB8FABE0C9__INCLUDED_)
