; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCustomStatic
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FetchAndSaveIcon.h"

ClassCount=4
Class1=CFetchAndSaveIconApp
Class2=CFetchAndSaveIconDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CCustomStatic
Resource3=IDD_FETCHANDSAVEICON_DIALOG

[CLS:CFetchAndSaveIconApp]
Type=0
HeaderFile=FetchAndSaveIcon.h
ImplementationFile=FetchAndSaveIcon.cpp
Filter=N

[CLS:CFetchAndSaveIconDlg]
Type=0
HeaderFile=FetchAndSaveIconDlg.h
ImplementationFile=FetchAndSaveIconDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_FILENAME

[CLS:CAboutDlg]
Type=0
HeaderFile=FetchAndSaveIconDlg.h
ImplementationFile=FetchAndSaveIconDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FETCHANDSAVEICON_DIALOG]
Type=1
Class=CFetchAndSaveIconDlg
ControlCount=7
Control1=IDC_FETCH,button,1342275584
Control2=IDC_FILENAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BROWN,button,1342242816
Control5=IDC_DEMOSTATE,static,1342177283
Control6=IDC_SAVE,button,1342275584
Control7=IDC_STATIC,button,1342177287

[CLS:CCustomStatic]
Type=0
HeaderFile=CustomStatic.h
ImplementationFile=CustomStatic.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC

