// CartSet.cpp : implementation file
//

#include "stdafx.h"
#include "CheckAttendance.h"
#include "CartSet.h"

#include "CheckAttendanceDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCartSet dialog
extern _ConnectionPtr m_pCon;
extern	_RecordsetPtr m_pRecord;

CCartSet::CCartSet(CWnd* pParent /*=NULL*/)
	: CDialog(CCartSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCartSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_IsWrite = FALSE;
}


void CCartSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCartSet)
	DDX_Control(pDX, IDC_WRITE, m_Write);
	DDX_Control(pDX, IDC_CARDID, m_Card);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCartSet, CDialog)
	//{{AFX_MSG_MAP(CCartSet)
	ON_BN_CLICKED(IDC_GENERATEID, OnGenerateid)
	ON_BN_CLICKED(IDC_WRITE, OnWrite)
	ON_BN_CLICKED(IDC_REFRESHCARD, OnRefreshcard)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCartSet message handlers

void CCartSet::OnGenerateid() 
{
	if (m_IsWrite==TRUE)
	{
		CString sql = "select max(ICID) as ID from ICID";
		
		m_pRecord = m_pCon->Execute((_bstr_t)sql,NULL,-1);
		CString sID = "";
		BOOL isNULL = FALSE;
		try
		{
			sID = (char*)(_bstr_t)m_pRecord->GetFields()->GetItem("ID")->Value;
			
		}
		catch(_com_error &e)
		{
			isNULL = TRUE;
		
		}
		if (isNULL)
				sID = "IC-001";
		else
		{
   			CString sTemp =sID;
			int pos = sID.Find("-",0);
			CString sInt = sID.Right(pos+1);
			int ID = atoi(sInt);
			ID+=1;
			sTemp.Format("%i",ID);
			switch (sTemp.GetLength())
			{
			case 1:{
						sID = "IC-00"+sTemp;
						break;
				   }
			case 2:{
						sID = "IC-0"+sTemp;
						break;
				 }
			default:
				{
						sID = "IC-"+sTemp;
						break;
				}
			}
		}
		m_Card.SetWindowText(sID);
		m_Write.EnableWindow();
	}
	else
	{
		MessageBox("当前IC卡可能没有验证密码，IC卡不可写。");
	}
}

BOOL CCartSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	

	CCheckAttendanceDlg* pDlg = (CCheckAttendanceDlg*)AfxGetMainWnd();
	m_icdev  = pDlg->icdev;	
	OnRefreshcard() ;	
	return TRUE; 
}

void CCartSet::OnWrite() 
{
	if (MessageBox("确实要写入数据吗？","提示",MB_YESNO)==IDYES)
	{
		CString str;
		m_Card.GetWindowText(str);
		if (str.IsEmpty())
		{
			MessageBox("请输入数据");
			return;
		}
		if (str.GetLength()>224)
		{
			MessageBox("写入数据不能超过224个字符","提示",64);
			return;
		}

		__int16 result;
		//向数据库中插入数据
		m_pCon->BeginTrans();
		
		CString sql;
		sql.Format("insert into ICID values ('%s')",str);
		try
		{
			m_pCon->Execute((_bstr_t)sql,NULL,-1);

			//在IC卡的应用区中写入数据
			result =swr_4442(m_icdev,33,str.GetLength(),(unsigned char*)str.GetBuffer(0));
				
			if (result==0)
			{
				m_pCon->CommitTrans();
				MessageBox("数据写入成功.","提示",64);
			}
			else
			{
				m_pCon->RollbackTrans();
				MessageBox("数据写入失败.","提示",64);
			}
		}
		catch(...)
		{
			m_pCon->RollbackTrans();
			MessageBox("操作失败");
			return;
		
		}
		m_Write.EnableWindow(FALSE);
		m_Card.SetWindowText("");
	}
}

void CCartSet::OnRefreshcard() 
{
	m_IsWrite = TRUE;	
	//获取ID卡状态
	__int16 status = -1;
	
	__int16 result =get_status(m_icdev,&status);

	if (result<0)
	{
		MessageBox("获取IC卡状态错误");
		m_IsWrite = FALSE;
	}
	else if ((result==0)&&(status==0))
	{
		MessageBox("请插入ID卡");
		m_IsWrite = FALSE;
	}
	//西门子4442IC卡初试密码为ffffff
	unsigned char pass[3]={0xff,0xff,0xff};
	//验证密码
	__int16 rpass =csc_4442(m_icdev,3,pass);
	if (rpass<0)
	{
		MessageBox("IC卡密码核对错误,只能读取数据");
		m_IsWrite = FALSE;
	}	
	
}
