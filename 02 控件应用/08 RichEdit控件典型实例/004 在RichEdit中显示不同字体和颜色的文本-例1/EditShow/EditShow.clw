; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEditShowDlg
LastTemplate=CRichEditCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "EditShow.h"

ClassCount=4
Class1=CEditShowApp
Class2=CEditShowDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CCustomRdit
Resource3=IDD_EDITSHOW_DIALOG

[CLS:CEditShowApp]
Type=0
HeaderFile=EditShow.h
ImplementationFile=EditShow.cpp
Filter=N

[CLS:CEditShowDlg]
Type=0
HeaderFile=EditShowDlg.h
ImplementationFile=EditShowDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_RICHEDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=EditShowDlg.h
ImplementationFile=EditShowDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EDITSHOW_DIALOG]
Type=1
Class=CEditShowDlg
ControlCount=2
Control1=IDC_RICHEDIT1,RICHEDIT,1353781444
Control2=IDC_BUTFONT,button,1342242816

[CLS:CCustomRdit]
Type=0
HeaderFile=CustomRdit.h
ImplementationFile=CustomRdit.cpp
BaseClass=CRichEditCtrl
Filter=W
VirtualFilter=WC
LastObject=CCustomRdit

