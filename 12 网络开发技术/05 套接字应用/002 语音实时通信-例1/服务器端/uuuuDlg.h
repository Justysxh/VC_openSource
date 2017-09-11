// uuuuDlg.h : header file
//

#if !defined(AFX_UUUUDLG_H__B55657CD_B0A1_4DC0_8C0C_94BC1A7CE7A6__INCLUDED_)
#define AFX_UUUUDLG_H__B55657CD_B0A1_4DC0_8C0C_94BC1A7CE7A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUuuuDlg dialog
#include "ClientSocket.h";
#include "ServerSocket.h"
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")

class CClientSocket;
class CServerSocket;

const int MAXNUM = 2;

#define CM_SHOWIMAGE WM_USER +1

enum TransType { ttVideo,ttAudio,ttText} ; //传输类型

class CUuuuDlg : public CDialog
{
// Construction
public:
	void OnReveiveAudioData(CClientSocket *sock);
	void AcceptAudioConnection();
	void PlayAudio();
	void InitAudio();
	void OnCancel();
	void AcceptConnect();
	CUuuuDlg(CWnd* pParent = NULL);	// standard constructor
	UINT m_Index;


	CServerSocket* m_pServerSock;
	CServerSocket* m_pServerAudio;


	CClientSocket* m_pClientSock[2]; //0表示视频,1表示语音

	BOOL           m_IsStop;
	BOOL           m_AudioStop;
	CFile          m_file;
	BOOL           m_IsRead;
	BOOL           m_IsReceived;
	TransType      m_TransType;

	HWAVEIN         m_hWaveIn;      //录音设备
	HWAVEOUT        m_hWaveOut;     //放音设备
	WAVEFORMATEX    waveform;	    //声音格式
	WAVEHDR         lpInWaveHdr[1]; //录音缓存
	WAVEHDR         lpOutWaveHdr[1];//放音缓存
	char            lpInbuf[4097]; 
	char            lpOutbuf[4097];


// Dialog Data
	//{{AFX_DATA(CUuuuDlg)
	enum { IDD = IDD_UUUU_DIALOG };
	UINT	m_Port;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUuuuDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUuuuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUUUDLG_H__B55657CD_B0A1_4DC0_8C0C_94BC1A7CE7A6__INCLUDED_)
