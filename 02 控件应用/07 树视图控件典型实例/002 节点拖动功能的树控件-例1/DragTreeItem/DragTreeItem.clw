; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDragTreeItemDlg
LastTemplate=CTreeCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DragTreeItem.h"

ClassCount=4
Class1=CDragTreeItemApp
Class2=CDragTreeItemDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CDragTree
Resource3=IDD_DRAGTREEITEM_DIALOG

[CLS:CDragTreeItemApp]
Type=0
HeaderFile=DragTreeItem.h
ImplementationFile=DragTreeItem.cpp
Filter=N

[CLS:CDragTreeItemDlg]
Type=0
HeaderFile=DragTreeItemDlg.h
ImplementationFile=DragTreeItemDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_DRAGTREE

[CLS:CAboutDlg]
Type=0
HeaderFile=DragTreeItemDlg.h
ImplementationFile=DragTreeItemDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DRAGTREEITEM_DIALOG]
Type=1
Class=CDragTreeItemDlg
ControlCount=1
Control1=IDC_DRAGTREE,SysTreeView32,1350631439

[CLS:CDragTree]
Type=0
HeaderFile=DragTree.h
ImplementationFile=DragTree.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC

