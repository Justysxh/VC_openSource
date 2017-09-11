#if !defined(AFX_PICTURE_H__63966F07_52B7_47CF_9684_E811089AEC62__INCLUDED_)
#define AFX_PICTURE_H__63966F07_52B7_47CF_9684_E811089AEC62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Picture.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPicture window

class CPicture : public CStatic
{
// Construction
public:
	CPicture();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicture)
	//}}AFX_VIRTUAL

// Implementation
public:
	int pHeight,pWidth;
	void Picturerect(int height,int width);
	HBITMAP hBitmap;
	void SetImage(HBITMAP Bitmap);
	virtual ~CPicture();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPicture)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTURE_H__63966F07_52B7_47CF_9684_E811089AEC62__INCLUDED_)
