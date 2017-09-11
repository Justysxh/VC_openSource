// ADOConn.cpp: implementation of the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "insertdates.h"
#include "ADOConn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOConn::ADOConn()
{

}

ADOConn::~ADOConn()
{

}

void ADOConn::OnInitADOConn()
{
	//初始化OLE/COM库环境
    ::CoInitialize(NULL);
	try
	{
		//创建connection对象
       m_pConnection.CreateInstance("ADODB.Connection");	   
	   //设置连接字符串
	   _bstr_t strConnect="Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=shujuku;Data Source=.";
	   //SERVER和UID,PWD的设置根据实际情况来设置
	   m_pConnection->Open(strConnect,"","",adModeUnknown);
	}
	//捕捉异常
	catch(_com_error e)
	{
		//显示错误信息
		AfxMessageBox(e.Description());
	}
}

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
    try
	{
		//连接数据库，如果connection对象为空，则重新连接数据库
		if(m_pConnection==NULL)
              OnInitADOConn();
		//创建记录集对象
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//取得表中的记录
        m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
    catch(_com_error e)
	{
		e.Description();
	}
	//返回记录集
	return m_pRecordset;
}

BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	_variant_t RecordsAffected;
	try
	{
		//是否已连接数据库
        if(m_pConnection==NULL)
	     	OnInitADOConn();
		//connection对象的Execute方法(_bstr_t CommandText,
        //VARIANT * RecordsAffected,long Options)
		//其中CommandText是命令字符串,通常是SQL命令
		//参数RecordsAffected是操作完成后所影响的行数
		//参数Options表示CommandText的类型,adCmdText-文本命令,adCmdTable-表名
		//adCmdProc-存储过程,adCmdUnknown-未知
        m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		e.Description();
		return false;
	}
}

void ADOConn::ExitConnect()
{
	//关闭记录集和连接
    if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	//释放环境
	::CoUninitialize();
}