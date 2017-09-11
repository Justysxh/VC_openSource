// wavDlg.h : header file
//

#if !defined(AFX_WAVDLG_H__E46DD4CC_E285_4FB7_A90C_F2A09264B960__INCLUDED_)
#define AFX_WAVDLG_H__E46DD4CC_E285_4FB7_A90C_F2A09264B960__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWavDlg dialog
#pragma comment (lib,"Strmiids")
#include <dshow.h>

class CWavDlg : public CDialog
{
// Construction
public:
	IPin* FindPin(IBaseFilter* pFilter,PIN_DIRECTION dir);
	CWavDlg(CWnd* pParent = NULL);	// standard constructor

	IMediaControl* pMediaControl ;
	IMoniker *pMoniker;
	IBaseFilter *pSrc ,*pWaveDest ,*pWriter;
	IFileSinkFilter2* pSink ;
	IGraphBuilder *pGraph;

	BOOL m_IsPause; //是否暂停
	BOOL m_IsRecorded; //是否进行了录音
// Dialog Data
	//{{AFX_DATA(CWavDlg)
	enum { IDD = IDD_WAV_DIALOG };
	CButton	m_Pause;
	CEdit	m_WavFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWavDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWavDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButbrown();
	afx_msg void OnOk2();
	afx_msg void OnOk3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAVDLG_H__E46DD4CC_E285_4FB7_A90C_F2A09264B960__INCLUDED_)
