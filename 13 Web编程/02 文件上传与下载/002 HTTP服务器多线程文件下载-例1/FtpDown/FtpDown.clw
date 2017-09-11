; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFtpDownDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FtpDown.h"

ClassCount=3
Class1=CFtpDownApp
Class2=CFtpDownDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FTPDOWN_DIALOG

[CLS:CFtpDownApp]
Type=0
HeaderFile=FtpDown.h
ImplementationFile=FtpDown.cpp
Filter=N

[CLS:CFtpDownDlg]
Type=0
HeaderFile=FtpDownDlg.h
ImplementationFile=FtpDownDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_DIR

[CLS:CAboutDlg]
Type=0
HeaderFile=FtpDownDlg.h
ImplementationFile=FtpDownDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FTPDOWN_DIALOG]
Type=1
Class=CFtpDownDlg
ControlCount=4
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DIR,edit,1350631552
Control4=IDC_DOWNLOAD,button,1342275584

