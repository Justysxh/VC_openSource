; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSendMsgDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SendMsg.h"

ClassCount=3
Class1=CSendMsgApp
Class2=CSendMsgDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SENDMSG_DIALOG

[CLS:CSendMsgApp]
Type=0
HeaderFile=SendMsg.h
ImplementationFile=SendMsg.cpp
Filter=N

[CLS:CSendMsgDlg]
Type=0
HeaderFile=SendMsgDlg.h
ImplementationFile=SendMsgDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SENDINFO

[CLS:CAboutDlg]
Type=0
HeaderFile=SendMsgDlg.h
ImplementationFile=SendMsgDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SENDMSG_DIALOG]
Type=1
Class=CSendMsgDlg
ControlCount=17
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_PORT,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BAUD,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_MERCHANEID,edit,1350639744
Control8=IDC_GETINFO,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_ACCREDIT,edit,1350631552
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_RECEIVERID,edit,1350639744
Control14=IDC_STATIC,static,1342308352
Control15=IDC_CONTENT,edit,1350635652
Control16=IDC_SENDINFO,button,1342242816
Control17=IDC_STATIC,static,1342308352

