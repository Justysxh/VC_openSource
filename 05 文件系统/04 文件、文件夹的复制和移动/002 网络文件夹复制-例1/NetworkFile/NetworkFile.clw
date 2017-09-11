; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetworkFileDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetworkFile.h"

ClassCount=4
Class1=CNetworkFileApp
Class2=CNetworkFileDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NETWORKFILE_DIALOG

[CLS:CNetworkFileApp]
Type=0
HeaderFile=NetworkFile.h
ImplementationFile=NetworkFile.cpp
Filter=N

[CLS:CNetworkFileDlg]
Type=0
HeaderFile=NetworkFileDlg.h
ImplementationFile=NetworkFileDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=NetworkFileDlg.h
ImplementationFile=NetworkFileDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NETWORKFILE_DIALOG]
Type=1
Class=CNetworkFileDlg
ControlCount=6
Control1=IDC_EDNETWORK,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDLOCAL,edit,1350631552
Control5=IDC_BTCOPY,button,1342242816
Control6=IDC_BTEXIT,button,1342242816

