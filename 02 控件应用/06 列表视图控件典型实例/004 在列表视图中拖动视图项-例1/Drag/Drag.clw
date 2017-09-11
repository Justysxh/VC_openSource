; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDragDlg
LastTemplate=CListCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Drag.h"

ClassCount=4
Class1=CDragApp
Class2=CDragDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CDragList
Resource3=IDD_DRAG_DIALOG

[CLS:CDragApp]
Type=0
HeaderFile=Drag.h
ImplementationFile=Drag.cpp
Filter=N

[CLS:CDragDlg]
Type=0
HeaderFile=DragDlg.h
ImplementationFile=DragDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CDragDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=DragDlg.h
ImplementationFile=DragDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DRAG_DIALOG]
Type=1
Class=CDragDlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350632397

[CLS:CDragList]
Type=0
HeaderFile=DragList.h
ImplementationFile=DragList.cpp
BaseClass=CListCtrl
Filter=W
VirtualFilter=FWC

