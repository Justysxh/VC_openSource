// Employee.cpp : implementation file
//

#include "stdafx.h"
#include "CheckAttendance.h"
#include "Employee.h"
#include "CheckAttendanceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployee dialog
extern _ConnectionPtr m_pCon;
extern	_RecordsetPtr m_pRecord;


CEmployee::CEmployee(CWnd* pParent /*=NULL*/)
	: CDialog(CEmployee::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmployee)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEmployee::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmployee)
	DDX_Control(pDX, IDC_WORDID, m_WordID);
	DDX_Control(pDX, IDC_WORDERNAME, m_Name);
	DDX_Control(pDX, IDC_SEX, m_Sex);
	DDX_Control(pDX, IDC_ICID, m_Card);
	DDX_Control(pDX, IDC_DUTY, m_Duty);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmployee, CDialog)
	//{{AFX_MSG_MAP(CEmployee)
	ON_BN_CLICKED(IDC_REFRESH, OnRefreshCard)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_BUTTONCANCEL, OnButtoncancel)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmployee message handlers

void CEmployee::OnRefreshCard() 
{
	CCheckAttendanceDlg* pDlg = (CCheckAttendanceDlg*)AfxGetMainWnd();
	m_icdev  = pDlg->icdev;		
	//获取IC卡状态
	__int16 status = -1;
	
	__int16 result =get_status(m_icdev,&status);

	if (result<0)
	{
		MessageBox("获取IC卡状态错误");
		return;
	}
	else if ((result==0)&&(status==0))
	{
		MessageBox("请插入ID卡");
		return;
	}
	
	unsigned char data[224];
	result = srd_4442(m_icdev,33,223,data);
	//蜂鸣
	dv_beep(m_icdev,20);
	if (result<0)
		MessageBox("数据读取失败");
	else
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
		m_Card.SetWindowText((char*)pArray);
		delete pArray;
	}
	


}

BOOL CEmployee::PreTranslateMessage(MSG* pMsg) 
{
	if ((pMsg->message==WM_KEYDOWN)&&(pMsg->wParam==13))
	{
		
		CWnd* pTemp = GetFocus();
		if ((pTemp->IsKindOf(RUNTIME_CLASS(CEdit))==TRUE)||(pTemp->IsKindOf(RUNTIME_CLASS(CComboBox))==TRUE))
		{
			pMsg->wParam = 9;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CEmployee::OnOK()
{

}

void CEmployee::OnExit() 
{
	OnCancel();	
}

void CEmployee::OnCancel()
{
	CDialog::OnCancel();
}

//清空编辑框文本
void CEmployee::OnButtoncancel() 
{
	CWnd* pTopWnd = GetTopWindow();
	while ((pTopWnd->IsKindOf(RUNTIME_CLASS(CEdit)))||(pTopWnd->IsKindOf(RUNTIME_CLASS(CComboBox))))
	{
		{
			pTopWnd->SetWindowText("");
		}
		pTopWnd = pTopWnd->GetNextWindow();
	}
}

//判断基础信息是否为空
BOOL CEmployee::InfoIsNull()
{
	CString str;
	CWnd* pTopWnd = GetTopWindow();
	while ((pTopWnd->IsKindOf(RUNTIME_CLASS(CEdit)))||(pTopWnd->IsKindOf(RUNTIME_CLASS(CComboBox))))
	{
		pTopWnd->GetWindowText(str);
		if (str.IsEmpty())
			return TRUE;
		pTopWnd = pTopWnd->GetNextWindow();
	}
	return FALSE;
}

//添加信息
void CEmployee::OnAdd() 
{
	if (InfoIsNull())
	{
		MessageBox("基础信息为空。","提示",64);
		return;
	}

	CString c_workid,c_name,c_sex,c_duty,c_icid;

	m_WordID.GetWindowText(c_workid);
	m_Name.GetWindowText(c_name);
	m_Sex.GetWindowText(c_sex);
	m_Duty.GetWindowText(c_duty);
	m_Card.GetWindowText(c_icid);

	CString sql;
	sql.Format("insert into worker values ('%s','%s','%s','%s','%s')",c_workid,c_name,c_sex,c_duty,c_icid);
	
	try
	{
		m_pCon->Execute((_bstr_t)sql,NULL,-1);
	}
	catch(_com_error &e)
	{
		#ifdef _DEBUG
		{
			MessageBox(e.ErrorMessage());
		}
		#else
			MessageBox("操作失败");
		#endif 			
		return;
	}
	MessageBox("操作成功");
	OnButtoncancel();
}
