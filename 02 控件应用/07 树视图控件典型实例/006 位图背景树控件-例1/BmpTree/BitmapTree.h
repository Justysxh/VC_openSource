#if !defined(AFX_BITMAPTREE_H__44B31CA2_471B_449A_A25B_FFBA9636421E__INCLUDED_)
#define AFX_BITMAPTREE_H__44B31CA2_471B_449A_A25B_FFBA9636421E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BitmapTree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBitmapTree window
class CMemDC : public CDC 
{
private:
	CBitmap*	m_Bmp;
	CBitmap*	m_OldBmp;
	CDC*		m_pDC;
	CRect		m_Rect;
public:
	CMemDC(CDC* pDC, const CRect& rect) : CDC()
	{
		CreateCompatibleDC(pDC);
		m_Bmp = new CBitmap;
		m_Bmp->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
		m_OldBmp = SelectObject(m_Bmp);
		m_pDC = pDC;
		m_Rect = rect;
	}
	~CMemDC() 
	{
		m_pDC->BitBlt(m_Rect.left, m_Rect.top, m_Rect.Width(), m_Rect.Height(), 
				this, m_Rect.left, m_Rect.top, SRCCOPY);
		SelectObject(m_OldBmp);
		if(m_Bmp != NULL) 
			delete m_Bmp;
	}
};

class CBitmapTree : public CTreeCtrl
{
// Construction
public:
	CBitmapTree();
	CBitmap		m_Bitmap;
	HANDLE		m_hBmp;
	CString		m_Path;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapTree)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL SetTreeBK(CString path);
	virtual ~CBitmapTree();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBitmapTree)
	afx_msg void OnPaint();
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPTREE_H__44B31CA2_471B_449A_A25B_FFBA9636421E__INCLUDED_)
