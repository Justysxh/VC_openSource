// PictureDlg.h : header file
//

#if !defined(AFX_PICTUREDLG_H__3DEDE5CE_BBFC_4A80_B46D_6BC167ED552D__INCLUDED_)
#define AFX_PICTUREDLG_H__3DEDE5CE_BBFC_4A80_B46D_6BC167ED552D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPictureDlg dialog

class CPictureDlg : public CDialog
{
// Construction
public:
	void DrawPicture(int num);
	CPictureDlg(CWnd* pParent = NULL);	// standard constructor
	BITMAP bmp;
	int num;

// Dialog Data
	//{{AFX_DATA(CPictureDlg)
	enum { IDD = IDD_PICTURE_DIALOG };
	CStatic	m_picture;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPictureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBut50();
	afx_msg void OnBut75();
	afx_msg void OnBut100();
	afx_msg void OnBut150();
	afx_msg void OnButchm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREDLG_H__3DEDE5CE_BBFC_4A80_B46D_6BC167ED552D__INCLUDED_)
