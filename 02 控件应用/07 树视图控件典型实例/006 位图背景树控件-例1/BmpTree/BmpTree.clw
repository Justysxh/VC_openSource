; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBmpTreeDlg
LastTemplate=CTreeCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BmpTree.h"

ClassCount=4
Class1=CBmpTreeApp
Class2=CBmpTreeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CBitmapTree
Resource3=IDD_BMPTREE_DIALOG

[CLS:CBmpTreeApp]
Type=0
HeaderFile=BmpTree.h
ImplementationFile=BmpTree.cpp
Filter=N

[CLS:CBmpTreeDlg]
Type=0
HeaderFile=BmpTreeDlg.h
ImplementationFile=BmpTreeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CBmpTreeDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=BmpTreeDlg.h
ImplementationFile=BmpTreeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BMPTREE_DIALOG]
Type=1
Class=CBmpTreeDlg
ControlCount=3
Control1=IDC_TREE1,SysTreeView32,1350631431
Control2=IDC_BUTSET,button,1342242816
Control3=IDC_STATIC1,static,1342308352

[CLS:CBitmapTree]
Type=0
HeaderFile=BitmapTree.h
ImplementationFile=BitmapTree.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC

