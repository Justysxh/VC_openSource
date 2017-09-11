; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMediaDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Media.h"

ClassCount=3
Class1=CMediaApp
Class2=CMediaDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MEDIA_DIALOG

[CLS:CMediaApp]
Type=0
HeaderFile=Media.h
ImplementationFile=Media.cpp
Filter=N

[CLS:CMediaDlg]
Type=0
HeaderFile=MediaDlg.h
ImplementationFile=MediaDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_QUIT

[CLS:CAboutDlg]
Type=0
HeaderFile=MediaDlg.h
ImplementationFile=MediaDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MEDIA_DIALOG]
Type=1
Class=CMediaDlg
ControlCount=2
Control1=IDC_QUIT,static,1342308619
Control2=IDC_STATIC,static,1342177294

