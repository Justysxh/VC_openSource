// EnumSysFontDlg.h : header file
//

#if !defined(AFX_ENUMSYSFONTDLG_H__4542DF07_F724_4E97_A8E7_727117AF911C__INCLUDED_)
#define AFX_ENUMSYSFONTDLG_H__4542DF07_F724_4E97_A8E7_727117AF911C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnumSysFontDlg dialog
//typedef   int EnumFontsProc (LOGFONT*,TEXTMETRIC*,DWORD,LPARAM) ;

//CALLBACK int EnumFontList (LOGFONT* logfont,TEXTMETRIC* textmetric,DWORD fonttype,LPARAM lparam);

//EnumFontsProc EnumFont;
//CString fontname1;



class CEnumSysFontDlg : public CDialog
{
// Construction
public:
	CEnumSysFontDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEnumSysFontDlg)
	enum { IDD = IDD_ENUMSYSFONT_DIALOG };
	CStatic	m_demo;
	CComboBox	m_FontList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumSysFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEnumSysFontDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSelchangeFontlist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMSYSFONTDLG_H__4542DF07_F724_4E97_A8E7_727117AF911C__INCLUDED_)
