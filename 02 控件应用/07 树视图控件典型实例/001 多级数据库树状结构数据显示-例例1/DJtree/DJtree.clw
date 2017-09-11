; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDJtreeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DJtree.h"

ClassCount=3
Class1=CDJtreeApp
Class2=CDJtreeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DJTREE_DIALOG

[CLS:CDJtreeApp]
Type=0
HeaderFile=DJtree.h
ImplementationFile=DJtree.cpp
Filter=N

[CLS:CDJtreeDlg]
Type=0
HeaderFile=DJtreeDlg.h
ImplementationFile=DJtreeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DJtreeDlg.h
ImplementationFile=DJtreeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DJTREE_DIALOG]
Type=1
Class=CDJtreeDlg
ControlCount=1
Control1=IDC_TREE1,SysTreeView32,1350631427

