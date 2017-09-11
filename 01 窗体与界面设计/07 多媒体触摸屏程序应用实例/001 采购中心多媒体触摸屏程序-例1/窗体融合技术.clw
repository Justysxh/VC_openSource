; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "窗体融合技术.h"
LastPage=0

ClassCount=7
Class1=CMyApp
Class2=CMyDoc
Class3=CMyView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TOOLS_DIALOG
Class5=CAboutDlg
Class6=CDockBarCtrl
Class7=CTools

[CLS:CMyApp]
Type=0
HeaderFile=窗体融合技术.h
ImplementationFile=窗体融合技术.cpp
Filter=N

[CLS:CMyDoc]
Type=0
HeaderFile=窗体融合技术Doc.h
ImplementationFile=窗体融合技术Doc.cpp
Filter=N

[CLS:CMyView]
Type=0
HeaderFile=窗体融合技术View.h
ImplementationFile=窗体融合技术View.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_SHOW




[CLS:CAboutDlg]
Type=0
HeaderFile=窗体融合技术.cpp
ImplementationFile=窗体融合技术.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_SHOW
Command17=ID_APP_ABOUT
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CDockBarCtrl]
Type=0
HeaderFile=DockBarCtrl.h
ImplementationFile=DockBarCtrl.cpp
BaseClass=CControlBar
Filter=W
VirtualFilter=WC

[DLG:IDD_TOOLS_DIALOG]
Type=1
Class=CTools
ControlCount=0

[CLS:CTools]
Type=0
HeaderFile=Tools.h
ImplementationFile=Tools.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

