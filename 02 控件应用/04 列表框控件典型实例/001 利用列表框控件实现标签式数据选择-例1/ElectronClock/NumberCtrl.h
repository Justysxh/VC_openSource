#if !defined(AFX_NUMBERCTRL_H__5960BDEC_1B08_48E9_A697_1850AABDFE38__INCLUDED_)
#define AFX_NUMBERCTRL_H__5960BDEC_1B08_48E9_A697_1850AABDFE38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NumberCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumberCtrl window
class CMemDC : public CDC 
{
private:
	CBitmap*	m_bmp;
	CBitmap*	m_oldbmp;
	CDC*		m_pDC;
	CRect		m_Rect;
public:
	CMemDC(CDC* pDC, const CRect& rect) : CDC()
	{
		CreateCompatibleDC(pDC);
		m_bmp = new CBitmap;
		m_bmp->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
		m_oldbmp = SelectObject(m_bmp);
		m_pDC = pDC;
		m_Rect = rect;
	}
	~CMemDC() 
	{
		m_pDC->BitBlt(m_Rect.left, m_Rect.top, m_Rect.Width(), m_Rect.Height(), 
				this, m_Rect.left, m_Rect.top, SRCCOPY);
		SelectObject(m_oldbmp);
		if (m_bmp != NULL) 
			delete m_bmp;
	}
};


class CNumberCtrl : public CStatic
{
// Construction
public:
	CNumberCtrl();

private:
	CString m_csText;		//文本
	int m_nNumberWidth;		//数字宽度
	int m_nNumberHeight;	//数字高度
	int m_nNumberLen;		//数字位数
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumberCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SubClassCtrl(UINT uID, CWnd* pParent);
	LPTSTR GetText();
	void SetText(LPCTSTR text);
	virtual ~CNumberCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNumberCtrl)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMBERCTRL_H__5960BDEC_1B08_48E9_A697_1850AABDFE38__INCLUDED_)
