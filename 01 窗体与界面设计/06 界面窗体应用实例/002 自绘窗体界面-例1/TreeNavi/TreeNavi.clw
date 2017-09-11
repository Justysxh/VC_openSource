; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=TreeView
LastTemplate=CTreeView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TreeNavi.h"
LastPage=0

ClassCount=6
Class1=CTreeNaviApp
Class2=CTreeNaviDoc
Class3=CTreeNaviView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=TreeView
Resource2=IDD_ABOUTBOX

[CLS:CTreeNaviApp]
Type=0
HeaderFile=TreeNavi.h
ImplementationFile=TreeNavi.cpp
Filter=N

[CLS:CTreeNaviDoc]
Type=0
HeaderFile=TreeNaviDoc.h
ImplementationFile=TreeNaviDoc.cpp
Filter=N

[CLS:CTreeNaviView]
Type=0
HeaderFile=TreeNaviView.h
ImplementationFile=TreeNaviView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=TreeNavi.cpp
ImplementationFile=TreeNavi.cpp
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

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_MRU_FILE1
Command2=ID_APP_EXIT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

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

[CLS:TreeView]
Type=0
HeaderFile=TreeView.h
ImplementationFile=TreeView.cpp
BaseClass=CTreeView
Filter=C
LastObject=TreeView
VirtualFilter=VWC

