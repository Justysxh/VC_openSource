; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPrintLineandFontDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PrintLineandFont.h"

ClassCount=4
Class1=CPrintLineandFontApp
Class2=CPrintLineandFontDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PRINTLINEANDFONT_DIALOG
Class4=CPreview
Resource4=IDD_DIALOG1

[CLS:CPrintLineandFontApp]
Type=0
HeaderFile=PrintLineandFont.h
ImplementationFile=PrintLineandFont.cpp
Filter=N

[CLS:CPrintLineandFontDlg]
Type=0
HeaderFile=PrintLineandFontDlg.h
ImplementationFile=PrintLineandFontDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPrintLineandFontDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=PrintLineandFontDlg.h
ImplementationFile=PrintLineandFontDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PRINTLINEANDFONT_DIALOG]
Type=1
Class=CPrintLineandFontDlg
ControlCount=6
Control1=IDC_LIST1,SysListView32,1350631429
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_BUTTON2,button,1342242816
Control6=IDC_BUTTON3,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CPreview
ControlCount=0

[CLS:CPreview]
Type=0
HeaderFile=Preview.h
ImplementationFile=Preview.cpp
BaseClass=CDialog
Filter=D
LastObject=CPreview
VirtualFilter=dWC

