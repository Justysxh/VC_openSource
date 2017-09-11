// FetchVisualDlg.h : header file
//

#if !defined(AFX_FETCHVISUALDLG_H__7B5B86F1_73B9_432A_BD80_097B57EBFC56__INCLUDED_)
#define AFX_FETCHVISUALDLG_H__7B5B86F1_73B9_432A_BD80_097B57EBFC56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFetchVisualDlg dialog
#pragma comment (lib,"Strmiids")
#include <dshow.h>
class CFetchVisualDlg : public CDialog
{
// Construction
public:
	IPin* FindPin(IBaseFilter *pFilter, PIN_DIRECTION dir);
	CFetchVisualDlg(CWnd* pParent = NULL);	// standard constructor


	IMediaControl     *pMediaControl ;
	IMoniker          *pMoniker;
	IBaseFilter       *pSrc ,*pMux ,*pWriter;
	IFileSinkFilter2  *pSink ;
	IGraphBuilder     *pGraph;
	BOOL              m_IsPause;    //是否暂停
	BOOL              m_IsRecorded; //是否进行了录音
// Dialog Data
	//{{AFX_DATA(CFetchVisualDlg)
	enum { IDD = IDD_FETCHVISUAL_DIALOG };
	CButton	m_Pause;
	CEdit	m_File;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchVisualDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFetchVisualDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHVISUALDLG_H__7B5B86F1_73B9_432A_BD80_097B57EBFC56__INCLUDED_)
