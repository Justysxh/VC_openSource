#if !defined(AFX_PREVIEWDIALOG_H__B5C017B9_37BD_46D6_8BF3_B71C63D31C4A__INCLUDED_)
#define AFX_PREVIEWDIALOG_H__B5C017B9_37BD_46D6_8BF3_B71C63D31C4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PreviewDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreviewDialog dialog
//定义方法指针
typedef void (*DrawPreview)(CDC *PreviewDC,CRect DrawRect,BOOL isPrint = false);

class CPreviewDialog : public CDialog
{
// Construction
protected:
	int nH,nW;//页面宽、高
	int posx,posy;
	BOOL isPrint;//是否打印
	CDC PrintDC;//打印DC
	DrawPreview OnDrawPreview;//打印事件

	void SetScrollbar(int cx, int cy);
public:
		
	CPreviewDialog(CWnd* pParent = NULL);   // standard constructor
	void Show();
	void SetPreviewEvent(DrawPreview OnEvent);	
// Dialog Data
	//{{AFX_DATA(CPreviewDialog)
	enum { IDD = IDD_PreviewDialog };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreviewDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreviewDialog)
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEWDIALOG_H__B5C017B9_37BD_46D6_8BF3_B71C63D31C4A__INCLUDED_)
