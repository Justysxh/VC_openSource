// ImageConvertDlg.h : header file
//

#if !defined(AFX_IMAGECONVERTDLG_H__89A3724A_CD80_469B_A3C2_BBCDFD9B6662__INCLUDED_)
#define AFX_IMAGECONVERTDLG_H__89A3724A_CD80_469B_A3C2_BBCDFD9B6662__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CImageConvertDlg dialog

#include "Gdiplus//Gdiplus.h"
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus//gdiplus.lib")
 
enum IImageType  {IT_BMP, IT_JPG, IT_PNG};

class CImageConvertDlg : public CDialog
{
// Construction
public:

	CImageConvertDlg(CWnd* pParent = NULL);	// standard constructor
	GdiplusStartupInput		m_Gdiplus;		//定义GDI+初始化变量
	ULONG_PTR				m_pGdiToken;	//定义GDI+标识
	LOGFONT					m_LogFont;
	CString					m_Strextend;
	CString					m_FileName;
// Dialog Data
	//{{AFX_DATA(CImageConvertDlg)
	enum { IDD = IDD_IMAGECONVERT_DIALOG };
	CEdit	m_FileDir;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageConvertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

		void GetImageType(enum IImageType& itSrc,enum IImageType& itDes);
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CImageConvertDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBrowse();
	afx_msg void OnTransform();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGECONVERTDLG_H__89A3724A_CD80_469B_A3C2_BBCDFD9B6662__INCLUDED_)
