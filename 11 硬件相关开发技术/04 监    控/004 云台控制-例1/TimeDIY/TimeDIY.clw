; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTimeDIYDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TimeDIY.h"

ClassCount=4
Class1=CTimeDIYApp
Class2=CTimeDIYDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TIMEDIY_DIALOG
Class4=CCtrlFrm
Resource4=IDD_CTRLFRM_DIALOG

[CLS:CTimeDIYApp]
Type=0
HeaderFile=TimeDIY.h
ImplementationFile=TimeDIY.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CTimeDIYDlg]
Type=0
HeaderFile=TimeDIYDlg.h
ImplementationFile=TimeDIYDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTimeDIYDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=TimeDIYDlg.h
ImplementationFile=TimeDIYDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TIMEDIY_DIALOG]
Type=1
Class=CTimeDIYDlg
ControlCount=14
Control1=IDC_PANEL,static,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242857
Control4=IDC_STARTTAIL,button,1342242816
Control5=IDC_STOPTAIL,button,1342242816
Control6=IDC_MSCOMM,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control7=IDC_CloudMsg,button,1342242816
Control8=IDC_QUIT,button,1342242816
Control9=IDC_UP,button,1342242816
Control10=IDC_DOWN,button,1342242816
Control11=IDC_LEFT,button,1342242816
Control12=IDC_RIGHT,button,1342242816
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,button,1342177287

[DLG:IDD_CTRLFRM_DIALOG]
Type=1
Class=CCtrlFrm
ControlCount=33
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308363
Control4=IDC_PORT,combobox,1344339971
Control5=IDC_STATIC,static,1342308363
Control6=IDC_SETTINGS,edit,1350631552
Control7=IDC_STATIC,static,1342308363
Control8=IDC_BYTE1,edit,1350631552
Control9=IDC_STATIC,static,1342308363
Control10=IDC_BYTE2,edit,1350631552
Control11=IDC_STATIC,static,1342308363
Control12=IDC_BYTE3,edit,1350631552
Control13=IDC_STATIC,static,1342308363
Control14=IDC_BYTE4,edit,1350631552
Control15=IDC_STATIC,static,1342308363
Control16=IDC_BYTE5,edit,1350631552
Control17=IDC_STATIC,static,1342308363
Control18=IDC_BYTE6,edit,1350631552
Control19=IDC_STATIC,static,1342308363
Control20=IDC_BYTE7,edit,1350631552
Control21=IDC_STATIC,static,1342308363
Control22=IDC_BYTE8,edit,1350631552
Control23=IDC_STATIC,static,1342308363
Control24=IDC_ACTIONS,combobox,1344339971
Control25=IDC_PORTSET,button,1342275584
Control26=IDC_CMDSET,button,1342275584
Control27=IDC_QUIT,button,1342275584
Control28=IDC_STATIC,static,1342308363
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308363
Control31=IDC_BYTENUM,edit,1350639744
Control32=IDC_STATIC,static,1342308363
Control33=IDC_ACTIONNUM,edit,1350639744

[CLS:CCtrlFrm]
Type=0
HeaderFile=CtrlFrm.h
ImplementationFile=CtrlFrm.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_ACTIONS

