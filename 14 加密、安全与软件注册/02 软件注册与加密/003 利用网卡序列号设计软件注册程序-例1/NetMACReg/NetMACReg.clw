; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetMACRegDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetMACReg.h"

ClassCount=3
Class1=CNetMACRegApp
Class2=CNetMACRegDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NETMACREG_DIALOG

[CLS:CNetMACRegApp]
Type=0
HeaderFile=NetMACReg.h
ImplementationFile=NetMACReg.cpp
Filter=N

[CLS:CNetMACRegDlg]
Type=0
HeaderFile=NetMACRegDlg.h
ImplementationFile=NetMACRegDlg.cpp
Filter=D
LastObject=CNetMACRegDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=NetMACRegDlg.h
ImplementationFile=NetMACRegDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NETMACREG_DIALOG]
Type=1
Class=CNetMACRegDlg
ControlCount=4
Control1=IDC_MACADDRESS,static,1342308352
Control2=IDC_MACADDR,edit,1350631552
Control3=IDC_BTREG,button,1342242816
Control4=IDC_EDREGCODE,edit,1350631552

