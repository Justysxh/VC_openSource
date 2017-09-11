// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__5FB9A9B2_8D94_44F7_A2DA_1F37A4F33D10__INCLUDED_)
#define AFX_ADOCONN_H__5FB9A9B2_8D94_44F7_A2DA_1F37A4F33D10__INCLUDED_

#import "c:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")rename("BOF","adoBOF")
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn  
{
public:
    _ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
public:
	ADOConn();
	virtual ~ADOConn();

	void OnInitADOConn();
    _RecordsetPtr&GetRecordSet(_bstr_t bstrSQL);
    BOOL ExecuteSQL(_bstr_t bstrSQL);
	void ExitConnect();
};

#endif // !defined(AFX_ADOCONN_H__5FB9A9B2_8D94_44F7_A2DA_1F37A4F33D10__INCLUDED_)
