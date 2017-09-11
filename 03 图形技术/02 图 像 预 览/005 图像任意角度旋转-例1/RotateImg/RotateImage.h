#if !defined(AFX_ROTATEIMAGE_H__EA81F65C_16B5_42D0_BB1D_9F8ADB0AA1BB__INCLUDED_)
#define AFX_ROTATEIMAGE_H__EA81F65C_16B5_42D0_BB1D_9F8ADB0AA1BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RotateImage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRotateImage dialog
#include "ImagePanel.h"

class CRotateImage : public CDialog
{
// Construction
public:
	void OnLBtnRadio(UINT nID);
	void RotateBmp(BYTE* pBmpData, BYTE*& pDesData, int nWidth, int nHeight,
			int nDesWidth, int nDesHeight,double dAngle);
	void RotationImage(BITMAPINFOHEADER *pBmInfo,int nDegree);
	CRotateImage(CWnd* pParent = NULL);   // standard constructor

	CImagePanel m_ImagePanel;		//图片显示的容器
	HBITMAP m_hBmp;					//定义位图句柄
	BOOL m_bLoaded;					//表示是否加载了位图
	BITMAPINFOHEADER desBmInfo;		//保存位图时使用的位图信息头
	BYTE *m_pBmpData;				//定义一个指针，用于记录位图数据

	BITMAPFILEHEADER m_bmFileHeader;	//位图文件头
	BITMAPINFOHEADER m_bmInfoHeader;	//位图信息头

	HGLOBAL  m_hGlobal;					//定义一个全局对象
	BYTE* m_RotData;					//定义一个指针，表示旋转后的图像
	CString m_SrcFile;					//记录加载的位图文件名

// Dialog Data
	//{{AFX_DATA(CRotateImage)
	enum { IDD = IDD_ROTATEIMAGE_DIALOG };
	CSliderCtrl	m_SetDegree;
	CStatic	m_Panel;
	CStatic	m_Image;
	CEdit	m_BmpName;
	UINT	m_nDegree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotateImage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRotateImage)
	virtual void OnCancel();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnBtLoad();
	afx_msg void OnBtSave();
	afx_msg void OnBtRotate();
	afx_msg void OnChangeDegree();
	afx_msg void OnFixdegree();
	afx_msg void OnRanddegree();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEIMAGE_H__EA81F65C_16B5_42D0_BB1D_9F8ADB0AA1BB__INCLUDED_)
