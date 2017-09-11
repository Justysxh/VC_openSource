; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COutInterfaceDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OutInterface.h"

ClassCount=5
Class1=COutInterfaceApp
Class2=COutInterfaceDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDR_TOOLBAR1
Resource2=IDR_MAINFRAME
Class4=COutlookList
Class5=CListButton
Resource3=IDD_OUTINTERFACE_DIALOG
Resource4=IDR_MENU1
Resource5=IDD_ABOUTBOX

[CLS:COutInterfaceApp]
Type=0
HeaderFile=OutInterface.h
ImplementationFile=OutInterface.cpp
Filter=N

[CLS:COutInterfaceDlg]
Type=0
HeaderFile=OutInterfaceDlg.h
ImplementationFile=OutInterfaceDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=OutInterfaceDlg.h
ImplementationFile=OutInterfaceDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_OUTINTERFACE_DIALOG]
Type=1
Class=COutInterfaceDlg
ControlCount=2
Control1=IDC_LIST1,SysListView32,1342242816
Control2=IDC_STATIC,static,1342177287

[CLS:COutlookList]
Type=0
HeaderFile=OutlookList.h
ImplementationFile=OutlookList.cpp
BaseClass=CListCtrl
Filter=W
VirtualFilter=FWC

[CLS:CListButton]
Type=0
HeaderFile=ListButton.h
ImplementationFile=ListButton.cpp
BaseClass=CButton
Filter=W
LastObject=CListButton

[MNU:IDR_MENU1]
Type=1
Class=?
CommandCount=0

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_BUTTON32771
Command2=ID_BUTTON32772
Command3=ID_BUTTON32773
Command4=ID_BUTTON32774
Command5=ID_BUTTON32775
CommandCount=5

