// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__A22F5A67_CEF8_49E8_8E84_61E23D66B409__INCLUDED_)
#define AFX_ADOCONN_H__A22F5A67_CEF8_49E8_8E84_61E23D66B409__INCLUDED_
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")rename("BOF","adoBOF")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn  
{
public:
	//添加一个指向Connection对象的指针
    _ConnectionPtr m_pConnection;
	//添加一个指向Recordset对象的指针
	_RecordsetPtr m_pRecordset;
public:
	ADOConn();
	virtual ~ADOConn();

	//初始化--连接数据库
    void OnInitADOConn();
	//执行查询
    _RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	//执行SQL语句
    BOOL ExecuteSQL(_bstr_t bstrSQL);
	//断开数据库连接
	void ExitConnect();
};

#endif // !defined(AFX_ADOCONN_H__A22F5A67_CEF8_49E8_8E84_61E23D66B409__INCLUDED_)
