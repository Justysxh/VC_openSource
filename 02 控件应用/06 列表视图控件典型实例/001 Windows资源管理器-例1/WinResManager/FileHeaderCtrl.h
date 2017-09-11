#if !defined(AFX_FILEHEADERCTRL_H__D8D23A24_254E_4E1B_ADC9_2A4202E09874__INCLUDED_)
#define AFX_FILEHEADERCTRL_H__D8D23A24_254E_4E1B_ADC9_2A4202E09874__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileHeaderCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileHeaderCtrl window

class CFileHeaderCtrl : public CHeaderCtrl
{
// Construction
public:
	CFileHeaderCtrl();
	int		m_nSortColumn;	//ÅÅÐòÁÐ
	BOOL	m_bAscend;		//ÊÇ·ñÎªÉýÐò
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileHeaderCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawItem( LPDRAWITEMSTRUCT lpDrawItemStruct );
	void SetSortColomn(int nColumn,BOOL bAscend);
	virtual ~CFileHeaderCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFileHeaderCtrl)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEHEADERCTRL_H__D8D23A24_254E_4E1B_ADC9_2A4202E09874__INCLUDED_)
