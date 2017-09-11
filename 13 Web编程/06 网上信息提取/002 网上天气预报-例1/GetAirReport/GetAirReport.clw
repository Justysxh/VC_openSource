; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGetAirReportDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GetAirReport.h"

ClassCount=3
Class1=CGetAirReportApp
Class2=CGetAirReportDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_GETAIRREPORT_DIALOG

[CLS:CGetAirReportApp]
Type=0
HeaderFile=GetAirReport.h
ImplementationFile=GetAirReport.cpp
Filter=N

[CLS:CGetAirReportDlg]
Type=0
HeaderFile=GetAirReportDlg.h
ImplementationFile=GetAirReportDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_REPORTLIST

[CLS:CAboutDlg]
Type=0
HeaderFile=GetAirReportDlg.h
ImplementationFile=GetAirReportDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_GETAIRREPORT_DIALOG]
Type=1
Class=CGetAirReportDlg
ControlCount=3
Control1=IDC_REPORTLIST,SysListView32,1350631425
Control2=IDC_BTGET,button,1342275584
Control3=IDC_BTEXIT,button,1342275584

