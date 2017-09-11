; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAaaaaDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "aaaaa.h"

ClassCount=5
Class1=CAaaaaApp
Class2=CAaaaaDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CListButton
Class4=CQQList
Resource3=IDD_AAAAA_DIALOG

[CLS:CAaaaaApp]
Type=0
HeaderFile=aaaaa.h
ImplementationFile=aaaaa.cpp
Filter=N

[CLS:CAaaaaDlg]
Type=0
HeaderFile=aaaaaDlg.h
ImplementationFile=aaaaaDlg.cpp
Filter=D
LastObject=CAaaaaDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=aaaaaDlg.h
ImplementationFile=aaaaaDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_AAAAA_DIALOG]
Type=1
Class=CAaaaaDlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631424

[CLS:CQQList]
Type=0
HeaderFile=QQList.h
ImplementationFile=QQList.cpp
BaseClass=CListCtrl
Filter=W
VirtualFilter=FWC

[CLS:CListButton]
Type=0
HeaderFile=ListButton.h
ImplementationFile=ListButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

