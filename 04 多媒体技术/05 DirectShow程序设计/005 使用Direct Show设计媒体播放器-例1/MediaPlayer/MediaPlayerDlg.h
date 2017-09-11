// MediaPlayerDlg.h : header file
//

#if !defined(AFX_MEDIAPLAYERDLG_H__5990E3A4_5F98_4E57_9650_8CD3744ED880__INCLUDED_)
#define AFX_MEDIAPLAYERDLG_H__5990E3A4_5F98_4E57_9650_8CD3744ED880__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayerDlg dialog

class CMediaPlayerDlg : public CDialog
{
// Construction
public:
	CMediaPlayerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMediaPlayerDlg)
	enum { IDD = IDD_MEDIAPLAYER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMediaPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIAPLAYERDLG_H__5990E3A4_5F98_4E57_9650_8CD3744ED880__INCLUDED_)
