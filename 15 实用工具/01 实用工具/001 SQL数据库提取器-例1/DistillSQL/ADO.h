// ADO.h: interface for the CADO class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADO_H__7A4D39F8_17B0_47F4_825F_A31F6F8A2AE4__INCLUDED_)
#define AFX_ADO_H__7A4D39F8_17B0_47F4_825F_A31F6F8A2AE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CADO  
{
public:
	void ExitConnect();
	BOOL OnInitADOConn(CString database, CString server,CString name,CString password);
	CADO();
	virtual ~CADO();
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
};

#endif // !defined(AFX_ADO_H__7A4D39F8_17B0_47F4_825F_A31F6F8A2AE4__INCLUDED_)
