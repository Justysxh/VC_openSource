#if !defined(AFX_CUSTOMSLIDER_H__64F83B8D_4582_4635_A1D8_02FA4EA3AF96__INCLUDED_)
#define AFX_CUSTOMSLIDER_H__64F83B8D_4582_4635_A1D8_02FA4EA3AF96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomSlider.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomSlider window
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

class CCustomSlider : public CSliderCtrl
{
// Construction
public:
	CCustomSlider();
	BOOL m_bDown;
//	CRect m_SrcRC;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomSlider)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomSlider();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomSlider)
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMSLIDER_H__64F83B8D_4582_4635_A1D8_02FA4EA3AF96__INCLUDED_)
