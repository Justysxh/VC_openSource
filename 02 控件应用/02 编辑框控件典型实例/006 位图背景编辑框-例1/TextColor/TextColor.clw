; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTextColorDlg
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TextColor.h"

ClassCount=4
Class1=CTextColorApp
Class2=CTextColorDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CColorEdit
Resource3=IDD_TEXTCOLOR_DIALOG

[CLS:CTextColorApp]
Type=0
HeaderFile=TextColor.h
ImplementationFile=TextColor.cpp
Filter=N

[CLS:CTextColorDlg]
Type=0
HeaderFile=TextColorDlg.h
ImplementationFile=TextColorDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTextColorDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=TextColorDlg.h
ImplementationFile=TextColorDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TEXTCOLOR_DIALOG]
Type=1
Class=CTextColorDlg
ControlCount=4
Control1=IDC_EDIT1,edit,1350635652
Control2=IDC_EDIT2,edit,1350635652
Control3=IDC_EDIT3,edit,1350635652
Control4=IDC_EDIT4,edit,1350635652

[CLS:CColorEdit]
Type=0
HeaderFile=ColorEdit.h
ImplementationFile=ColorEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=CColorEdit

