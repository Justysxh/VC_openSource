// ADO.cpp: implementation of the CADO class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DistillSQL.h"
#include "ADO.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CADO::CADO()
{

}

CADO::~CADO()
{

}

BOOL CADO::OnInitADOConn(CString database, CString server,CString name,CString password)
{
	CString strname;
	try
	{
		if(name.IsEmpty())
		{
			AfxMessageBox("ÇëÊäÈëÓÃ»§£¡");
			return FALSE;
		}
		else
		{
			strname.Format("Provider=SQLOLEDB.1;Persist Security Info=False;User ID=%s;\
				pwd=%s;Initial Catalog=%s;Data Source=%s",name,password,database,server);
			m_pConnection.CreateInstance("ADODB.Connection");
			_bstr_t strConnect=strname;
			m_pConnection->Open(strConnect,"","",adModeUnknown);
		}
		return TRUE;
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return FALSE;
	}
}

void CADO::ExitConnect()
{
	if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
}
