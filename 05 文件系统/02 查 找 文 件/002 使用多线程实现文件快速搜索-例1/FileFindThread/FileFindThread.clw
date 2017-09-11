; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChildFrame
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FileFindThread.h"

ClassCount=7
Class1=CFileFindThreadApp
Class2=CFileFindThreadDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CSplitter
Class5=CTreeFrame
Class6=CSplitterEx
Resource3=IDD_FILEFINDTHREAD
Class7=CChildFrame
Resource4=IDD_ChildFrame

[CLS:CFileFindThreadApp]
Type=0
HeaderFile=FileFindThread.h
ImplementationFile=FileFindThread.cpp
Filter=N

[CLS:CFileFindThreadDlg]
Type=0
HeaderFile=FileFindThreadDlg.h
ImplementationFile=FileFindThreadDlg.cpp
Filter=D
LastObject=CFileFindThreadDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FileFindThreadDlg.h
ImplementationFile=FileFindThreadDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CSplitter]
Type=0
HeaderFile=Splitter.h
ImplementationFile=Splitter.cpp
BaseClass=CWnd
Filter=W
LastObject=CSplitter
VirtualFilter=WC

[CLS:CTreeFrame]
Type=0
HeaderFile=TreeFrame.h
ImplementationFile=TreeFrame.cpp
BaseClass=CTreeView
Filter=C
LastObject=CTreeFrame
VirtualFilter=VWC

[CLS:CSplitterEx]
Type=0
HeaderFile=SplitterEx.h
ImplementationFile=SplitterEx.cpp
BaseClass=splitter
Filter=T

[DLG:IDD_ChildFrame]
Type=1
Class=CChildFrame
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_STATIC,button,1342177287
Control5=IDC_LIST1,SysListView32,1350631425

[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrame.h
ImplementationFile=ChildFrame.cpp
BaseClass=CFormView
Filter=D
LastObject=CChildFrame
VirtualFilter=VWC

[DLG:IDD_FILEFINDTHREAD]
Type=1
Class=CFileFindThreadDlg
ControlCount=0

