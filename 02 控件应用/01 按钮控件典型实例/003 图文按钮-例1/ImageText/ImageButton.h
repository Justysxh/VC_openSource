#if !defined(AFX_IMAGEBUTTON_H__012D2CB2_147D_466A_BCB7_B19E01CCC69D__INCLUDED_)
#define AFX_IMAGEBUTTON_H__012D2CB2_147D_466A_BCB7_B19E01CCC69D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ImageButton window

class ImageButton : public CButton
{
private:
	CImageList* m_pImagelist;  //图像列表指针
	int m_ImageIndex; //图标索引
	BOOL IsPressed; //按钮是否被按下
// Construction
public:
	ImageButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ImageButton)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void SetImageList(CImageList* pImage);
	void SetImageIndex(UINT index);
	virtual ~ImageButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(ImageButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEBUTTON_H__012D2CB2_147D_466A_BCB7_B19E01CCC69D__INCLUDED_)
