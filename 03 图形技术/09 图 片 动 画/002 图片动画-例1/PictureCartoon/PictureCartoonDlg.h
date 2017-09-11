// PictureCartoonDlg.h : header file
//

#if !defined(AFX_PICTURECARTOONDLG_H__7DDD0673_24DD_4DEA_8129_C55431D04ADE__INCLUDED_)
#define AFX_PICTURECARTOONDLG_H__7DDD0673_24DD_4DEA_8129_C55431D04ADE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPictureCartoonDlg dialog

class CPictureCartoonDlg : public CDialog
{
// Construction
public:
	CPictureCartoonDlg(CWnd* pParent = NULL);	// standard constructor
	double lpi;
	CPoint arrays[40];
	int n;
	BOOL result;
// Dialog Data
	//{{AFX_DATA(CPictureCartoonDlg)
	enum { IDD = IDD_PICTURECARTOON_DIALOG };
	CStatic	m_picture;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureCartoonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPictureCartoonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTURECARTOONDLG_H__7DDD0673_24DD_4DEA_8129_C55431D04ADE__INCLUDED_)
