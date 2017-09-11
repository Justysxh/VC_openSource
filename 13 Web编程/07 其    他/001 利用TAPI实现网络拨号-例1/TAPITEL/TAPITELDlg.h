// TAPITELDlg.h : header file
//

#if !defined(AFX_TAPITELDLG_H__F1F53FC4_06FF_4AEB_AF9C_86DFEEA10901__INCLUDED_)
#define AFX_TAPITELDLG_H__F1F53FC4_06FF_4AEB_AF9C_86DFEEA10901__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTAPITELDlg dialog
typedef struct _tagADDRESSINFO{
HWND hStatus;     
HWND hAnswer;     
HCALL hCall;     
BOOL bCall;
}ADDRESSINFO,*PADDRESSINFO;

class CTAPITELDlg : public CDialog
{
// Construction
public:
	CTAPITELDlg(CWnd* pParent = NULL);	// standard constructor
	HANDLE ghCompletionPort;
	PADDRESSINFO pAddressInfo; 
	HLINEAPP ghLineApp;
	DWORD gdwAddresses;
	DWORD gdwDeviceID;
	HLINE ghLine; 
	HCALL call;
// Dialog Data
	//{{AFX_DATA(CTAPITELDlg)
	enum { IDD = IDD_TAPITEL_DIALOG };
	CListBox	m_linelist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTAPITELDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTAPITELDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkLinelist();
	afx_msg void OnDial();
	afx_msg void OnDrop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAPITELDLG_H__F1F53FC4_06FF_4AEB_AF9C_86DFEEA10901__INCLUDED_)
