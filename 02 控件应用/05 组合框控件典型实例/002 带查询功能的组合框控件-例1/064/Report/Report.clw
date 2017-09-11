; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CReportDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Report.h"

ClassCount=3
Class1=CReportApp
Class2=CReportDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_REPORT_DIALOG

[CLS:CReportApp]
Type=0
HeaderFile=Report.h
ImplementationFile=Report.cpp
Filter=N

[CLS:CReportDlg]
Type=0
HeaderFile=ReportDlg.h
ImplementationFile=ReportDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ReportDlg.h
ImplementationFile=ReportDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_REPORT_DIALOG]
Type=1
Class=CReportDlg
ControlCount=2
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_STATIC,static,1342177294

