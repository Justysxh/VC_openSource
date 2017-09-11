; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTabCtrlDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TabCtrl.h"

ClassCount=5
Class1=CTabCtrlApp
Class2=CTabCtrlDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_TABCTRL_DIALOG
Resource2=IDR_MAINFRAME
Class4=CNetTabCtrl
Resource3=IDD_ABOUTBOX
Class5=CIndexDlg
Resource4=IDD_INDEXDLG_DIALOG

[CLS:CTabCtrlApp]
Type=0
HeaderFile=TabCtrl.h
ImplementationFile=TabCtrl.cpp
Filter=N

[CLS:CTabCtrlDlg]
Type=0
HeaderFile=TabCtrlDlg.h
ImplementationFile=TabCtrlDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TAB1

[CLS:CAboutDlg]
Type=0
HeaderFile=TabCtrlDlg.h
ImplementationFile=TabCtrlDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TABCTRL_DIALOG]
Type=1
Class=CTabCtrlDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342185474

[CLS:CNetTabCtrl]
Type=0
HeaderFile=NetTabCtrl.h
ImplementationFile=NetTabCtrl.cpp
BaseClass=CTabCtrl
Filter=W
LastObject=CNetTabCtrl
VirtualFilter=UWC

[DLG:IDD_INDEXDLG_DIALOG]
Type=1
Class=CIndexDlg
ControlCount=2
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,static,1350565894

[CLS:CIndexDlg]
Type=0
HeaderFile=IndexDlg.h
ImplementationFile=IndexDlg.cpp
BaseClass=CDialog
Filter=D

