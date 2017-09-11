// KinescodeDlg.h : header file
//

#if !defined(AFX_KINESCODEDLG_H__B73CC7D3_0F5C_4891_947A_3985421EA530__INCLUDED_)
#define AFX_KINESCODEDLG_H__B73CC7D3_0F5C_4891_947A_3985421EA530__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "vfw.h"
#pragma comment (lib,"vfw32.lib")
#include <afxmt.h>

#include "ClientSocket.h"
#include "Login.h"

#define CM_SendImage WM_USER+2

//class CClientSocket;
/////////////////////////////////////////////////////////////////////////////
// CKinescodeDlg dialog
class CKinescodeDlg : public CDialog
{
// Construction
public:

	void StartRecord();
	void InitAudio();
	void SendImage();
	void SendData();
	virtual void OnCancel();
	CKinescodeDlg(CWnd* pParent = NULL);	// standard constructor

	HWND            m_hVideoWnd;   //视频捕捉窗口
	CWinThread*     m_pThread;     //线程对象指针
	CEvent          m_Event;       //事件对象,用于线程同步
	BOOL            m_IsKindscode; //是否录像
	CClientSocket*  m_pSock;       //客户端视频套接字
	CClientSocket*  m_pAudioSock;  //客户端音频套接字
	BOOL            m_IsSend;      //是否发送
	BOOL            m_IsReceived;  //服务器端接收数据是否完成

	HWAVEIN         m_hWaveIn;      //录音设备
	HWAVEOUT        m_hWaveOut;     //放音设备
	WAVEFORMATEX    waveform;	    //声音格式
	WAVEHDR         lpInWaveHdr[2]; //录音缓存

	WAVEHDR         lpOutWaveHdr[1];//放音缓存

	char            lpInbuf[4096]; 
	char            lpInbuf1[4096]; 
	char            lpOutbuf[4096];

	BOOL            m_Played;
	BOOL            m_Change;

	static UINT ThreadFun( LPVOID wParam );


// Dialog Data
	//{{AFX_DATA(CKinescodeDlg)
	enum { IDD = IDD_KINESCODE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKinescodeDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKinescodeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnKinescode();
	afx_msg void OnStopkinescode();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLinkserver();
	afx_msg void EndRecord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KINESCODEDLG_H__B73CC7D3_0F5C_4891_947A_3985421EA530__INCLUDED_)
