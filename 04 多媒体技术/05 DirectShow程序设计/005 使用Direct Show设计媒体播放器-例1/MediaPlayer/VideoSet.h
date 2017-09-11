#if !defined(AFX_VIDEOSET_H__77F87FF9_8146_4971_AAA2_0AE4F5AA6788__INCLUDED_)
#define AFX_VIDEOSET_H__77F87FF9_8146_4971_AAA2_0AE4F5AA6788__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoSet.h : header file
//
#include "CustomSlider.h"
/////////////////////////////////////////////////////////////////////////////
// CVideoSet dialog

class CVideoSet : public CDialog
{
// Construction
public:
	CVideoSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CVideoSet)
	enum { IDD = IDD_VIDEOSET_DIALOG };
	CEdit	m_ConNum;
	CEdit	m_BrightNum;
	CEdit	m_SatNum;
	CEdit	m_HueNum;
	CCustomSlider	m_Saturation;
	CCustomSlider	m_Hue;
	CCustomSlider	m_Contrast;
	CCustomSlider	m_Brightness;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVideoSet)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnChangeHuenum();
	afx_msg void OnChangeSatnum();
	afx_msg void OnChangeBrightnum();
	afx_msg void OnChangeContrastnum();
	afx_msg void OnTbCancel();
	afx_msg void OnDefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOSET_H__77F87FF9_8146_4971_AAA2_0AE4F5AA6788__INCLUDED_)
