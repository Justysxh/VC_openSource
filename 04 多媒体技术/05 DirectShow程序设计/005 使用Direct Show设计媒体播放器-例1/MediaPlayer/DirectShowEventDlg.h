// DirectShowEventDlg.h : header file
//

#if !defined(AFX_DIRECTSHOWEVENTDLG_H__71A12478_E511_4AC1_BC2D_ECCEA434FB9D__INCLUDED_)
#define AFX_DIRECTSHOWEVENTDLG_H__71A12478_E511_4AC1_BC2D_ECCEA434FB9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "dshow.h"
#include "D3d9.h"
#include "vmr9.h"
#include "Objbase.h"

#include "CustomSlider.h" 
#include "NumLabel.h"
#include "DisplayWnd.h"
#include "CustomGroup.h"
/////////////////////////////////////////////////////////////////////////////
// CDirectShowEventDlg dialog


#pragma comment (lib,"Strmiids")
#pragma comment (lib,"quartz")



#define VOLUMN_CLIENCE -10000L
#define CM_POSCHANGE WM_USER+1001
#define  CM_COMPLETE WM_USER+1


class CDirectShowEventDlg : public CDialog
{
// Construction
public:
	void PlayFile(LPCTSTR lpFileName);
	void OnPosChange();
	void SetViewInfo(int nFlag,float fValue);
	void Done(WPARAM wParam, LPARAM lParam);
	void OnCancel();
	CDirectShowEventDlg(CWnd* pParent = NULL);	// standard constructor
	IMediaControl     *pMediaControl ;         //媒体控制
	IGraphBuilder     *pGraph;                 //过滤图表
	ICaptureGraphBuilder2 * pBuilder;
	IGraphBuilder			*pGraphBuilder;
	IBaseFilter       *pSrc,*pBase;				//过滤器
	IMoniker          *pMoniker;               //监视器
	BOOL              m_Previewed;             //是否进行预览
	IMediaEventEx     *pEvent;                 //事件
	IVideoWindow *    pViewWnd;                //视频预览窗口
	BOOL              m_Completed;             //预览是否完成
	HANDLE            m_hThread;               //线程句柄
	BOOL              m_bFullScreen;			//是否为全屏
	long              m_lVolumn;				//记录当前音量
	BOOL              m_bMute;					//是否为静音
	BOOL              m_bSpeed;					//是否快进
	BOOL              m_bBack;					//是否为快退
	IBasicVideo       *pBaseVideo;
	IBaseFilter *pMixing ,*pRender;
	BOOL              m_bGrayImage;				//是否为黑白图像  
	float               m_fSaturation,m_fHue,m_fContrast,m_fBright;		
	VMR9ProcAmpControlRange m_HueRange;			//色调范围
	VMR9ProcAmpControlRange m_SatRange;			//饱和度范围
	VMR9ProcAmpControlRange m_ConRange;			//对比度范围
	VMR9ProcAmpControlRange m_BrightRange;		//连读范围
	BOOL              m_bPause;					//是否为暂停
	BOOL              m_bStop;					//是否停止
	CString           m_FileName;

	BOOL              m_ThreadStop;
	CDisplayWnd       m_DisplayWnd;
	BOOL              m_bViewPlay;				//视频文件是否正在播放
	IPin* FindPin(IBaseFilter *pFilter, PIN_DIRECTION dir);
	CRect m_OriginRC;							//视频窗口原始大小
	BOOL              m_bInvalidFile;			//媒体文件是否合法

// Dialog Data
	//{{AFX_DATA(CDirectShowEventDlg)
	enum { IDD = IDD_DIRECTSHOWEVENT_DIALOG };
	CCustomGroup	m_CtlList;
	CCustomGroup	m_GroupPos;
	CNumLabel	m_CurPos;
	CNumLabel	m_Progress;
	CButton	m_Stop;
	CButton	m_Pause;
	CButton	m_GrayBtn;
	CCustomSlider	m_ProgressCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDirectShowEventDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDirectShowEventDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSetFile();
	afx_msg void OnSnap();
	afx_msg void OnFullScreen();
	afx_msg void OnMute();
	afx_msg void OnVolumnmax();
	afx_msg void OnVolumnmin();
	afx_msg void OnAddSpeed();
	afx_msg void OnAddBack();
	afx_msg void OnGray();
	afx_msg void OnTimer(UINT nIDEvent);

	afx_msg void OnVideoset();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTbPause();
	afx_msg void OnTbStop();
	afx_msg void OnShowwnd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRECTSHOWEVENTDLG_H__71A12478_E511_4AC1_BC2D_ECCEA434FB9D__INCLUDED_)
