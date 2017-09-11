; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMoneyBoxDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MoneyBox.h"

ClassCount=4
Class1=CMoneyBoxApp
Class2=CMoneyBoxDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyLabel
Resource3=IDD_MONEYBOX_DIALOG

[CLS:CMoneyBoxApp]
Type=0
HeaderFile=MoneyBox.h
ImplementationFile=MoneyBox.cpp
Filter=N

[CLS:CMoneyBoxDlg]
Type=0
HeaderFile=MoneyBoxDlg.h
ImplementationFile=MoneyBoxDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COM3

[CLS:CAboutDlg]
Type=0
HeaderFile=MoneyBoxDlg.h
ImplementationFile=MoneyBoxDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MONEYBOX_DIALOG]
Type=1
Class=CMoneyBoxDlg
ControlCount=17
Control1=IDOK,button,1342275584
Control2=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control3=IDC_TITLE,static,1342308352
Control4=IDC_LIST1,SysListView32,1350633473
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT1,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,button,1342177287
Control14=IDC_COM1,button,1342177289
Control15=IDC_COM2,button,1342177289
Control16=IDC_COM3,button,1342177289
Control17=IDOK2,button,1342275584

[CLS:CMyLabel]
Type=0
HeaderFile=MyLabel.h
ImplementationFile=MyLabel.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC

