; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTitleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Title.h"

ClassCount=4
Class1=CTitleApp
Class2=CTitleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TITLE_DIALOG

[CLS:CTitleApp]
Type=0
HeaderFile=Title.h
ImplementationFile=Title.cpp
Filter=N

[CLS:CTitleDlg]
Type=0
HeaderFile=TitleDlg.h
ImplementationFile=TitleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TitleDlg.h
ImplementationFile=TitleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TITLE_DIALOG]
Type=1
Class=CTitleDlg
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816

