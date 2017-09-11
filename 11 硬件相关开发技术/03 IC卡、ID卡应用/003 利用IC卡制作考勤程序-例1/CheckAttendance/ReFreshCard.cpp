// ReFreshCard.cpp : implementation file
//

#include "stdafx.h"
#include "CheckAttendance.h"
#include "ReFreshCard.h"
#include "CheckAttendanceDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReFreshCard dialog

extern _ConnectionPtr m_pCon;
extern	_RecordsetPtr m_pRecord;

CReFreshCard::CReFreshCard(CWnd* pParent /*=NULL*/)
	: CDialog(CReFreshCard::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReFreshCard)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_IsCard = FALSE;
}


void CReFreshCard::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReFreshCard)
	DDX_Control(pDX, IDC_HINT, m_HINT);
	DDX_Control(pDX, IDC_WORDID, m_WorkID);
	DDX_Control(pDX, IDC_WORDERNAME, m_Name);
	DDX_Control(pDX, IDC_SEX, m_Sex);
	DDX_Control(pDX, IDC_ICID, m_ID);
	DDX_Control(pDX, IDC_DUTY, m_Duty);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReFreshCard, CDialog)
	//{{AFX_MSG_MAP(CReFreshCard)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReFreshCard message handlers

void CReFreshCard::OnOK() 
{
	
}

void CReFreshCard::OnCancel() 
{
	
	CDialog::OnCancel();
}

BOOL CReFreshCard::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CCheckAttendanceDlg* pDlg = (CCheckAttendanceDlg*)AfxGetMainWnd();
	m_icdev  = pDlg->icdev;	
	
	SetTimer(1,800,NULL);
	return TRUE;  
}

void CReFreshCard::OnTimer(UINT nIDEvent) 
{
	//获取IC卡状态
	__int16 status = -1;	
	__int16 result =get_status(m_icdev,&status);
	
	setsc_md(m_icdev,1);

	if (result<0)
	{
		return;
	}
	else if ((result==0)&&(status==0))
	{
		m_IsCard = FALSE;
		m_HINT.SetWindowText("请插入IC卡");
		return;
	}

	if (m_IsCard )
		return;	

	//读取卡中的数据
	unsigned char data[224];
	result = srd_4442(m_icdev,33,223,data);
	//蜂鸣
	dv_beep(m_icdev,20);
	if (result==0)
	{
		int i =0;
		for (i= 0; i<224;i++)
		{
			if (data[i]==255)
				break;
		}
		unsigned char* pArray = new unsigned char[i+1];
		memset(pArray,0,i+1);
		memcpy(pArray,data,i);
		pArray[i]= 0;
		
		CString sql;
		sql.Format("select * from worker where icid = '%s'",pArray);
		delete pArray;

		CString c_workerid,c_name,c_sex,c_duty,c_id;
		m_pRecord = m_pCon->Execute((_bstr_t)sql,NULL,-1);
		try
		{
			c_workerid = (char* )(_bstr_t)m_pRecord->GetFields()->GetItem("ID")->Value;
			c_name = (char* )(_bstr_t)m_pRecord->GetFields()->GetItem("Name")->Value;
			c_sex = (char* )(_bstr_t)m_pRecord->GetFields()->GetItem("Sex")->Value;
			c_duty = (char* )(_bstr_t)m_pRecord->GetFields()->GetItem("Duty")->Value;
			c_id = (char* )(_bstr_t)m_pRecord->GetFields()->GetItem("ICID")->Value;
			
			m_WorkID.SetWindowText(c_workerid);
			m_Name.SetWindowText(c_name);
			if (c_sex=="男")
				m_Sex.SetCurSel(0);
			else 
				m_Sex.SetCurSel(1);

			m_Duty.SetWindowText(c_duty);
			m_ID.SetWindowText(c_id);

			m_IsCard = TRUE;

			sql.Format("insert into record values ('%s','%s')",c_id,CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S"));
			
			try
			{
				m_pCon->Execute((_bstr_t)sql,NULL,-1);
				m_HINT.SetWindowText("刷卡成功");
			}
			catch(...)
			{
				m_HINT.SetWindowText("数据记录失败,请重新插入IC卡");		
			}
		}
		catch(...)
		{
			m_WorkID.SetWindowText("");
			m_Name.SetWindowText("");
			m_Sex.SetWindowText("");
			m_Duty.SetWindowText("");
			m_ID.SetWindowText("");	
			m_HINT.SetWindowText("提示:  该卡不存在用户");
			dv_beep(m_icdev,10);
			dv_beep(m_icdev,10);
			m_IsCard =TRUE;
		}
	}	
	CDialog::OnTimer(nIDEvent);
}
