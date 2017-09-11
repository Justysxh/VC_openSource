; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSuperConnectDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SuperConnect.h"

ClassCount=4
Class1=CSuperConnectApp
Class2=CSuperConnectDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CSuperLabel
Resource3=IDD_SUPERCONNECT_DIALOG

[CLS:CSuperConnectApp]
Type=0
HeaderFile=SuperConnect.h
ImplementationFile=SuperConnect.cpp
Filter=N

[CLS:CSuperConnectDlg]
Type=0
HeaderFile=SuperConnectDlg.h
ImplementationFile=SuperConnectDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CONNECT

[CLS:CAboutDlg]
Type=0
HeaderFile=SuperConnectDlg.h
ImplementationFile=SuperConnectDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SUPERCONNECT_DIALOG]
Type=1
Class=CSuperConnectDlg
ControlCount=9
Control1=IDC_CONNECT,static,1342308608
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT3,edit,1350631552
Control9=IDC_STATIC,static,1342308352

[CLS:CSuperLabel]
Type=0
HeaderFile=SuperLabel.h
ImplementationFile=SuperLabel.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CSuperLabel

