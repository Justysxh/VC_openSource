; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSendEMailDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SendEMail.h"

ClassCount=3
Class1=CSendEMailApp
Class2=CSendEMailDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SENDEMAIL_DIALOG

[CLS:CSendEMailApp]
Type=0
HeaderFile=SendEMail.h
ImplementationFile=SendEMail.cpp
Filter=N

[CLS:CSendEMailDlg]
Type=0
HeaderFile=SendEMailDlg.h
ImplementationFile=SendEMailDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CSendEMailDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=SendEMailDlg.h
ImplementationFile=SendEMailDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SENDEMAIL_DIALOG]
Type=1
Class=CSendEMailDlg
ControlCount=9
Control1=IDOK,button,1342275584
Control2=IDCANCEL,button,1342275584
Control3=IDC_Content,edit,1350631556
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ReceiverAddr,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_Subject,edit,1350631552
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287

