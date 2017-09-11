// ConfigINIDlg.h : header file
//

#if !defined(AFX_CONFIGINIDLG_H__65B52409_B71F_4932_9522_315494C6A987__INCLUDED_)
#define AFX_CONFIGINIDLG_H__65B52409_B71F_4932_9522_315494C6A987__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CConfigINIDlg dialog

typedef struct _Configinfo
{
	int height;
	int width;
	int left;
	int top;
}ConfigInfo;

class CConfigINIDlg : public CDialog
{
// Construction
public:
	CString m_ConfigPath;
	CConfigINIDlg(CWnd* pParent = NULL);	// standard constructor
	CString GetAppPath();

// Dialog Data
	//{{AFX_DATA(CConfigINIDlg)
	enum { IDD = IDD_CONFIGINI_DIALOG };
	CEdit	m_caption;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigINIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CConfigINIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIGINIDLG_H__65B52409_B71F_4932_9522_315494C6A987__INCLUDED_)
