// inputvoiceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "inputvoice.h"
#include "inputvoiceDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputvoiceDlg dialog

CInputvoiceDlg::CInputvoiceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInputvoiceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputvoiceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInputvoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputvoiceDlg)
	DDX_Control(pDX, IDC_EDIT2, m_kzm);
	DDX_Control(pDX, IDC_EDIT1, m_editlj);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CInputvoiceDlg, CDialog)
	//{{AFX_MSG_MAP(CInputvoiceDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTLIULAN, OnButliulan)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTCREATE, OnButcreate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputvoiceDlg message handlers

BOOL CInputvoiceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	AddToCombo();
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strPath = buf;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CInputvoiceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CInputvoiceDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CInputvoiceDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CInputvoiceDlg::OnButliulan() 
{
	// TODO: Add your control notification handler code here
	CFileDialog file(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"All Files(*.*)|*.*| |",AfxGetMainWnd());
		if(file.DoModal()==IDOK)
		{
			CString str;
			strText=file.GetPathName();
			str=file.GetFileName();
			strName = str.Left(str.GetLength()-4);
			strkzm = str.Right(4);	
			m_editlj.SetWindowText(strText);
		}
}

void CInputvoiceDlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	try
	{
		char *m_pBuffer;
		CFile file;
		if(!file.Open(strText,CFile::modeRead))
		{
			MessageBox("无法打开文件");
			return;
		}
		DWORD m_filelen;
		m_filelen = file.GetLength();
		m_pBuffer = new char[m_filelen + 1];
		if(file.ReadHuge(m_pBuffer,m_filelen)!=m_filelen)
		{
			MessageBox("读取文件出现错误");
			return;
		}
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		_bstr_t sql;
		sql = "select*from voice";
		_RecordsetPtr m_pRecordset;
		m_pRecordset=m_AdoConn.GetRecordSet(sql);
		m_pRecordset->AddNew();//添加新行
		VARIANT varblob;
		SAFEARRAY *psa;
		SAFEARRAYBOUND rgsabound[1];
		rgsabound[0].lLbound = 0;
		rgsabound[0].cElements = m_filelen;
		psa = SafeArrayCreate(VT_UI1,1,rgsabound);
		for(long i=0;i<(long)m_filelen;i++)
		{
			SafeArrayPutElement(psa,&i,m_pBuffer++);
		}
		varblob.vt = VT_ARRAY|VT_UI1;
		varblob.parray = psa;
		m_pRecordset->GetFields()->GetItem("name")->Value = (_bstr_t)strName;
		m_pRecordset->GetFields()->GetItem("postfix")->Value = (_bstr_t)strkzm;
		m_pRecordset->GetFields()->GetItem("voice")->AppendChunk(varblob);
		m_pRecordset->Update();
		m_AdoConn.ExitConnect();
	}
	catch(...)
	{
		MessageBox("操作失败");
		return;
	}
	MessageBox("操作成功.");
	m_combo.ResetContent();
	AddToCombo();
}

void CInputvoiceDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString m_name;
	m_combo.GetLBText(m_combo.GetCurSel(),m_name);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t sql;
	sql = "select*from voice where name='"+m_name+"' ";
	m_AdoConn.GetRecordSet(sql);
	m_kzm.SetWindowText((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("postfix"));
	m_AdoConn.ExitConnect();
}

void CInputvoiceDlg::OnButcreate() 
{
	// TODO: Add your control notification handler code here
	CString name,kzm;
	m_combo.GetWindowText(name);//m_combo.GetCurSel(),
	if(name=="")
	{
		MessageBox("请选择文件名！");
		return;
	}
	m_kzm.GetWindowText(kzm);
	try
	{
		ADOConn m_AdoConn;
		m_AdoConn.OnInitADOConn();
		//设置SELECT语句
		_bstr_t vSQL;
		vSQL = "select*from voice where name='"+name+"' ";
		//执行SELETE语句
		_RecordsetPtr m_pRecordset;
		m_pRecordset = m_AdoConn.GetRecordSet(vSQL);	
		long lDataSize = m_pRecordset->GetFields()->GetItem("voice")->ActualSize;
		char *m_pBuffer; //定义缓冲变量
		if(lDataSize > 0)
		{
			//从字段中读取数据到varBLOB中
			_variant_t varBLOB;
			varBLOB = m_pRecordset->GetFields()->GetItem("voice")->GetChunk(lDataSize);
			if(varBLOB.vt == (VT_ARRAY | VT_UI1))
			{
				if(m_pBuffer = new char[lDataSize+1]) //分配必要的存储空间
				{	
					char *pBuf = NULL;
					SafeArrayAccessData(varBLOB.parray,(void **)&pBuf);
					memcpy(m_pBuffer,pBuf,lDataSize); //复制数据到缓冲区m_pBuffer
					SafeArrayUnaccessData (varBLOB.parray);
				}
			}
		}
		m_AdoConn.ExitConnect();
		CString path;
		path = strPath + "\\" + name + kzm;
		CFile file(_T(path),CFile::modeCreate|CFile::modeWrite);
		file.Write(m_pBuffer,lDataSize);
		file.Flush();
		file.Close();
	}
	catch(...)
	{
		MessageBox("操作失败");
		return;
	}
	MessageBox("操作成功.");
}

void CInputvoiceDlg::AddToCombo()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t sql;
	sql = "select*from voice order by name";
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		m_combo.InsertString(i,(char*)(_bstr_t)m_pRecordset->GetCollect("name"));	
		m_pRecordset->MoveNext();
		i++;
	}
	m_AdoConn.ExitConnect();

}
