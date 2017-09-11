; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLineColorDlg
LastTemplate=CTreeCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LineColor.h"

ClassCount=4
Class1=CLineColorApp
Class2=CLineColorDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CLineTree
Resource3=IDD_LINECOLOR_DIALOG

[CLS:CLineColorApp]
Type=0
HeaderFile=LineColor.h
ImplementationFile=LineColor.cpp
Filter=N

[CLS:CLineColorDlg]
Type=0
HeaderFile=LineColorDlg.h
ImplementationFile=LineColorDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TREE1

[CLS:CAboutDlg]
Type=0
HeaderFile=LineColorDlg.h
ImplementationFile=LineColorDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LINECOLOR_DIALOG]
Type=1
Class=CLineColorDlg
ControlCount=1
Control1=IDC_TREE1,SysTreeView32,1350635527

[CLS:CLineTree]
Type=0
HeaderFile=LineTree.h
ImplementationFile=LineTree.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC

