// barcodeDlg.h : header file
//

#if !defined(AFX_BARCODEDLG_H__079A29CA_BFB9_4B02_99D5_AC6F75D6AAC8__INCLUDED_)
#define AFX_BARCODEDLG_H__079A29CA_BFB9_4B02_99D5_AC6F75D6AAC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBarcodeDlg dialog

typedef struct tagbarcode
{
	char code[25];//条形码
	char count[14];//数量
}BarCode;

class CBarcodeDlg : public CDialog
{
// Construction
protected:
	_ConnectionPtr m_pConnection;

	void InitList();
public:
	CBarcodeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBarcodeDlg)
	enum { IDD = IDD_BARCODE_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBarcodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBarcodeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLoadData();
	afx_msg void OnClose();
	afx_msg void OnBalance();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BARCODEDLG_H__079A29CA_BFB9_4B02_99D5_AC6F75D6AAC8__INCLUDED_)
