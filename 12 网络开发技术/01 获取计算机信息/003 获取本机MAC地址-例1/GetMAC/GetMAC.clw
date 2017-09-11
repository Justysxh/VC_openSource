; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGetMACDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GetMAC.h"

ClassCount=3
Class1=CGetMACApp
Class2=CGetMACDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_GETMAC_DIALOG

[CLS:CGetMACApp]
Type=0
HeaderFile=GetMAC.h
ImplementationFile=GetMAC.cpp
Filter=N

[CLS:CGetMACDlg]
Type=0
HeaderFile=GetMACDlg.h
ImplementationFile=GetMACDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=GetMACDlg.h
ImplementationFile=GetMACDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_GETMAC_DIALOG]
Type=1
Class=CGetMACDlg
ControlCount=4
Control1=IDC_BUTMAC,button,1342242816
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_BUTEXIT,button,1342242816

