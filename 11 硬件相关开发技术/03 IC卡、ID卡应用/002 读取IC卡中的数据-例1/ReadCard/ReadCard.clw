; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CReadCardDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ReadCard.h"

ClassCount=3
Class1=CReadCardApp
Class2=CReadCardDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_READCARD_DIALOG

[CLS:CReadCardApp]
Type=0
HeaderFile=ReadCard.h
ImplementationFile=ReadCard.cpp
Filter=N

[CLS:CReadCardDlg]
Type=0
HeaderFile=ReadCardDlg.h
ImplementationFile=ReadCardDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ReadCardDlg.h
ImplementationFile=ReadCardDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_READCARD_DIALOG]
Type=1
Class=CReadCardDlg
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DATA,edit,1350631552
Control4=IDC_READ,button,1342275584
Control5=IDC_CANCEL,button,1342275584

