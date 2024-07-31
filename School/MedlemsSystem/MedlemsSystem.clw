; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MedlemsSystem.h"
LastPage=0

ClassCount=8
Class1=CMedlemsSystemApp
Class2=CMedlemsSystemDoc
Class3=CMedlemsSystemView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_MEDLEMSSYSTEM_FORM
Resource4=IDD_MENU
Resource5=IDR_MAINFRAME (English (U.S.))
Resource6=IDD_MEDLEMSSYSTEM_FORM (English (U.S.))
Class6=CMain
Resource7=IDD_ABOUTBOX (English (U.S.))
Class7=CLeftMenu
Resource8=IDD_MAIN
Class8=CMemberEdit
Resource9=IDD_MEMBER

[CLS:CMedlemsSystemApp]
Type=0
HeaderFile=MedlemsSystem.h
ImplementationFile=MedlemsSystem.cpp
Filter=N
LastObject=ID_APP_ABOUT
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CMedlemsSystemDoc]
Type=0
HeaderFile=MedlemsSystemDoc.h
ImplementationFile=MedlemsSystemDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_FILE_SAVE

[CLS:CMedlemsSystemView]
Type=0
HeaderFile=MedlemsSystemView.h
ImplementationFile=MedlemsSystemView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CMedlemsSystemView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_FILE_VGSAVE




[CLS:CAboutDlg]
Type=0
HeaderFile=MedlemsSystem.cpp
ImplementationFile=MedlemsSystem.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE

[DLG:IDD_MEDLEMSSYSTEM_FORM]
Type=1
Class=CMedlemsSystemView

[DLG:IDD_MEDLEMSSYSTEM_FORM (English (U.S.))]
Type=1
Class=CMedlemsSystemView
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_ADDMEMBER
Command8=ID_EDIT_REMOVEMEMBER
Command9=ID_APP_ABOUT
CommandCount=9

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_VGSAVE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_EDIT_ADDMEMBER
Command9=ID_EDIT_REMOVEMEMBER
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
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

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MAIN]
Type=1
Class=CMain
ControlCount=1
Control1=IDC_STATIC,static,1342179342

[CLS:CMain]
Type=0
HeaderFile=Main.h
ImplementationFile=Main.cpp
BaseClass=CFormView
Filter=D
LastObject=CMain
VirtualFilter=VWC

[DLG:IDD_MENU]
Type=1
Class=CLeftMenu
ControlCount=1
Control1=IDC_CONTACT,SysTreeView32,1350631463

[CLS:CLeftMenu]
Type=0
HeaderFile=LeftMenu.h
ImplementationFile=LeftMenu.cpp
BaseClass=CFormView
Filter=D
LastObject=CLeftMenu
VirtualFilter=VWC

[DLG:IDD_MEMBER]
Type=1
Class=CMemberEdit
ControlCount=21
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_MEMBERID,edit,1350631552
Control12=IDC_MEMBERSENCE,edit,1350631552
Control13=IDC_MEMBERTO,edit,1350631552
Control14=IDC_LASTNAME,edit,1350631552
Control15=IDC_FIRSTNAME,edit,1350631552
Control16=IDC_DATEOFBIRTH,edit,1350631552
Control17=IDC_PHONE,edit,1350631552
Control18=IDC_ADDRESS,edit,1350631552
Control19=IDC_SAVE,button,1342242817
Control20=IDC_MEMBERTYPE,edit,1350631552
Control21=IDC_STATIC,static,1342308352

[CLS:CMemberEdit]
Type=0
HeaderFile=MemberEdit.h
ImplementationFile=MemberEdit.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC
LastObject=CMemberEdit

