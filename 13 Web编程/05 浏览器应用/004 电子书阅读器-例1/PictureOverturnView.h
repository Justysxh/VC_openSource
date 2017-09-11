// PictureOverturnView.h : interface of the CPictureOverturnView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICTUREOVERTURNVIEW_H__B9213B7C_91B2_46D7_890F_BCB006CE3356__INCLUDED_)
#define AFX_PICTUREOVERTURNVIEW_H__B9213B7C_91B2_46D7_890F_BCB006CE3356__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPictureOverturnView : public CView
{
protected: // create from serialization only
	CPictureOverturnView();
	DECLARE_DYNCREATE(CPictureOverturnView)

// Attributes
public:
	CPictureOverturnDoc* GetDocument();
	////自定义的变量
	int picture_count[17];
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureOverturnView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void OverPicture_RToL2();
	void DrawRToL(int ,int);
	void OverPicture_RToL();
	void OverPicture_LToR2();
	int m_BS_now;//用来保存当前位图的ID
	void DrawLToR(int ,int);
	void OverPicture_LToR();
	int m_ID_next;//用来保存传递时下一张位图的ID
	int m_ID_now;//用来保存传递时当前位图的ID

	virtual ~CPictureOverturnView();
	void DrawPicture(int );
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPictureOverturnView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PictureOverturnView.cpp
inline CPictureOverturnDoc* CPictureOverturnView::GetDocument()
   { return (CPictureOverturnDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREOVERTURNVIEW_H__B9213B7C_91B2_46D7_890F_BCB006CE3356__INCLUDED_)
