; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBitTreeDlg
LastTemplate=CTreeCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BitTree.h"

ClassCount=4
Class1=CBitTreeApp
Class2=CBitTreeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CBitTreeCtl
Resource3=IDD_BITTREE_DIALOG

[CLS:CBitTreeApp]
Type=0
HeaderFile=BitTree.h
ImplementationFile=BitTree.cpp
Filter=N

[CLS:CBitTreeDlg]
Type=0
HeaderFile=BitTreeDlg.h
ImplementationFile=BitTreeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TREE

[CLS:CAboutDlg]
Type=0
HeaderFile=BitTreeDlg.h
ImplementationFile=BitTreeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BITTREE_DIALOG]
Type=1
Class=CBitTreeDlg
ControlCount=1
Control1=IDC_TREE,SysTreeView32,1350637863

[CLS:CBitTreeCtl]
Type=0
HeaderFile=BitTreeCtl.h
ImplementationFile=BitTreeCtl.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC

