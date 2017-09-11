// CtrlFrm.cpp : implementation file
//

#include "stdafx.h"
#include "TimeDIY.h"
#include "CtrlFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCtrlFrm dialog


CCtrlFrm::CCtrlFrm(CWnd* pParent /*=NULL*/)
	: CDialog(CCtrlFrm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCtrlFrm)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCtrlFrm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCtrlFrm)
	DDX_Control(pDX, IDC_SETTINGS, m_Setting);
	DDX_Control(pDX, IDC_PORT, m_Port);
	DDX_Control(pDX, IDC_BYTENUM, m_ByteNum);
	DDX_Control(pDX, IDC_BYTE8, m_Byte8);
	DDX_Control(pDX, IDC_BYTE7, m_Byte7);
	DDX_Control(pDX, IDC_BYTE6, m_Byte6);
	DDX_Control(pDX, IDC_BYTE5, m_Byte5);
	DDX_Control(pDX, IDC_BYTE4, m_Byte4);
	DDX_Control(pDX, IDC_BYTE3, m_Byte3);
	DDX_Control(pDX, IDC_BYTE2, m_Byte2);
	DDX_Control(pDX, IDC_BYTE1, m_Byte1);
	DDX_Control(pDX, IDC_ACTIONS, m_Actions);
	DDX_Control(pDX, IDC_ACTIONNUM, m_ActionNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCtrlFrm, CDialog)
	//{{AFX_MSG_MAP(CCtrlFrm)
	ON_BN_CLICKED(IDC_PORTSET, OnPortset)
	ON_BN_CLICKED(IDC_CMDSET, OnCmdset)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	ON_CBN_SELCHANGE(IDC_ACTIONS, OnSelchangeActions)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtrlFrm message handlers

void CCtrlFrm::OnOK() 
{

}

BOOL CCtrlFrm::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_pEdit[0] = &m_Byte1;
	m_pEdit[1] = &m_Byte2;
	m_pEdit[2] = &m_Byte3;
	m_pEdit[3] = &m_Byte4;
	m_pEdit[4] = &m_Byte5;
	m_pEdit[5] = &m_Byte6;
	m_pEdit[6] = &m_Byte7;
	m_pEdit[7] = &m_Byte8;

	m_pMain = (CTimeDIYDlg*)AfxGetApp()->GetMainWnd(); 
	
	m_Port.SetCurSel(m_pMain->m_Port-1);
	m_Setting.SetWindowText(m_pMain->m_Setting);

	char data[20];
	itoa(m_pMain->m_ActoinCount,data,10);
	m_ActionNum.SetWindowText(data);
	
	char buff[20];
	itoa(m_pMain->m_Len,buff,10);
	m_ByteNum.SetWindowText(buff);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCtrlFrm::OnPortset() 
{
	//设置端口信息
	CString port;
	m_Port.GetWindowText(port);
	if (!port.IsEmpty())
	{
		m_pMain->m_Port = m_Port.GetCurSel()+1; //atoi(port.GetBuffer(0));
		port.Format("%i",m_pMain->m_Port);
		WritePrivateProfileString("端口设置","端口号",port,"./stage.ini");
		m_pMain->m_Com.SetPortOpen(FALSE);
		m_pMain->m_Com.SetCommPort(m_pMain->m_Port);
		m_pMain->m_Com.SetPortOpen(TRUE);
	}
	CString setting;
	m_Setting.GetWindowText(setting);
	if (!setting.IsEmpty())
	{
		m_pMain->m_Setting = setting;
		WritePrivateProfileString("端口设置","环境设置",setting,"./stage.ini");
		m_pMain->m_Com.SetPortOpen(FALSE);
		m_pMain->m_Com.SetSettings(setting);
		m_pMain->m_Com.SetPortOpen(TRUE);
	}	
}

void CCtrlFrm::OnCmdset() 
{
	//设置控制码
	int index  = m_Actions.GetCurSel();
	if (index != -1)
	{
		for (int j = 0 ; j<m_pMain->m_Len; j++)
		{
			char data[20]; 
			m_pEdit[j]->GetWindowText(data,20);
			
			char* stop;
			int x = strtol(data,&stop,16);

			m_pMain->m_pData[index][j] = strtol(data,&stop,16);
			char sec[20] = {0};
			char key[20] = "字节";
			char num[10] = {0};
			itoa(j+1,num,10);
			strcat(key,num);
			itoa(index+1,sec,10);
			WritePrivateProfileString(sec,key,data,"./stage.ini");
		}
	}
	//设置动作数和协议使用的字节数
	CString num;
	m_ByteNum.GetWindowText(num);
	
	if (!num.IsEmpty())
	{
		WritePrivateProfileString("使用字节数","字节数",num,"./stage.ini");
	}
	
	CString actions;
	m_ActionNum.GetWindowText(actions);
	if (! actions.IsEmpty())
	{
		WritePrivateProfileString("控制项","控制数",actions,"./stage.ini");		
	}
	CDialog::OnCancel();	
}

void CCtrlFrm::OnQuit() 
{
	CDialog::OnCancel();	
}

void CCtrlFrm::OnSelchangeActions() 
{
	int index  = m_Actions.GetCurSel();

	if (index != -1)
	{
		for (int j = 0 ; j<m_pMain->m_Len; j++)
			for (int i = 0 ; i< m_pMain->m_ActoinCount; i++)
			{
				char buff[20] = {0};
				char prex[20]= "0x";
				itoa(m_pMain->m_pData[index][j],buff,16);
				strcat(prex,buff);
				m_pEdit[j]->SetWindowText(prex);	
			}
	}	
}

HBRUSH CCtrlFrm::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if (nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
