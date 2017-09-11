// RecordSoundDlg.h : header file
//

#if !defined(AFX_RECORDSOUNDDLG_H__B491FBAD_60C1_4C7D_9076_06F86A6A2921__INCLUDED_)
#define AFX_RECORDSOUNDDLG_H__B491FBAD_60C1_4C7D_9076_06F86A6A2921__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRecordSoundDlg dialog

class CRecordSoundDlg : public CDialog
{
// Construction
public:
	CRecordSoundDlg(CWnd* pParent = NULL);	// standard constructor
	HWND mciwav;
// Dialog Data
	//{{AFX_DATA(CRecordSoundDlg)
	enum { IDD = IDD_RECORDSOUND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordSoundDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRecordSoundDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRecord();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDSOUNDDLG_H__B491FBAD_60C1_4C7D_9076_06F86A6A2921__INCLUDED_)
