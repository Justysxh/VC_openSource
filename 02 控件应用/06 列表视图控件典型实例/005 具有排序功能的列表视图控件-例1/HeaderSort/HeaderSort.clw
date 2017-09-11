; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHeaderSortDlg
LastTemplate=CListCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HeaderSort.h"

ClassCount=5
Class1=CHeaderSortApp
Class2=CHeaderSortDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CListHeaderCtrl
Class4=CListHeader
Resource3=IDD_HEADERSORT_DIALOG

[CLS:CHeaderSortApp]
Type=0
HeaderFile=HeaderSort.h
ImplementationFile=HeaderSort.cpp
Filter=N

[CLS:CHeaderSortDlg]
Type=0
HeaderFile=HeaderSortDlg.h
ImplementationFile=HeaderSortDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=HeaderSortDlg.h
ImplementationFile=HeaderSortDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_HEADERSORT_DIALOG]
Type=1
Class=CHeaderSortDlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631425

[CLS:CListHeader]
Type=0
HeaderFile=ListHeader.h
ImplementationFile=ListHeader.cpp
BaseClass=CHeaderCtrl
Filter=W

[CLS:CListHeaderCtrl]
Type=0
HeaderFile=ListHeaderCtrl.h
ImplementationFile=ListHeaderCtrl.cpp
BaseClass=CListCtrl
Filter=W
VirtualFilter=FWC
LastObject=CListHeaderCtrl

