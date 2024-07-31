; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGp3TrackInstallerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "gp3trackinstaller.h"
LastPage=0

ClassCount=7
Class1=CDlgExtract
Class2=CDlgOptions
Class3=CDlgProgress
Class4=CDlgReport
Class5=CGp3TrackInstallerApp
Class6=CAboutDlg
Class7=CGp3TrackInstallerDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX (English (U.S.))
Resource2=IDD_DIALOG_OPTIONS
Resource3=IDD_DIALOG_REPORT
Resource4=IDD_GP3TRACKINSTALLER_DIALOG (English (U.S.))
Resource5=IDD_DIALOG_PROGRESS
Resource6=IDR_MAINMENU

[CLS:CDlgExtract]
Type=0
BaseClass=CDialog
HeaderFile=DlgExtract.h
ImplementationFile=DlgExtract.cpp

[CLS:CDlgOptions]
Type=0
BaseClass=CDialog
HeaderFile=DlgOptions.h
ImplementationFile=DlgOptions.cpp

[CLS:CDlgProgress]
Type=0
BaseClass=CDialog
HeaderFile=DlgProgress.h
ImplementationFile=DlgProgress.cpp

[CLS:CDlgReport]
Type=0
BaseClass=CDialog
HeaderFile=DlgReport.h
ImplementationFile=DlgReport.cpp

[CLS:CGp3TrackInstallerApp]
Type=0
BaseClass=CWinApp
HeaderFile=Gp3TrackInstaller.h
ImplementationFile=Gp3TrackInstaller.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Gp3TrackInstallerDlg.cpp
ImplementationFile=Gp3TrackInstallerDlg.cpp
LastObject=CAboutDlg

[CLS:CGp3TrackInstallerDlg]
Type=0
BaseClass=CDialog
HeaderFile=Gp3TrackInstallerDlg.h
ImplementationFile=Gp3TrackInstallerDlg.cpp
LastObject=CGp3TrackInstallerDlg

[DLG:IDD_DIALOG_EXTRACT]
Type=1
Class=CDlgExtract

[DLG:IDD_DIALOG_OPTIONS]
Type=1
Class=CDlgOptions
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CHECK_OVERWRITE,button,1342242819
Control4=IDC_CHECK_STATUS_REPORT,button,1342242819
Control5=IDC_STATIC_ZIP_SETTINGS,button,1342177287
Control6=IDC_EDIT_UNZIP_PATH,edit,1484851328
Control7=IDC_BUTTON_UNZIP_BROWSE,button,1342242816
Control8=IDC_STATIC_EXTRACT_TO,static,1342308352
Control9=IDC_CHECK_REMOVE,button,1342242819
Control10=IDC_CHECK_TEMP_FOLDER,button,1342242819
Control11=IDC_CHECK_SHOW_GP3FORM,button,1342242819
Control12=IDC_STATIC_MISC_SETTINGS,button,1342177287
Control13=IDC_COMBO_LANGUAGE,combobox,1344340227
Control14=IDC_STATIC_LANGUAGE,static,1342308352

[DLG:IDD_DIALOG_PROGRESS]
Type=1
Class=CDlgProgress
ControlCount=4
Control1=IDC_PROGRESS_BAR,msctls_progress32,1350565889
Control2=IDC_STATIC_TITLE,static,1342308352
Control3=IDC_STATIC_SUB_TITLE,static,1342308352
Control4=IDC_STATIC_DATA,static,1342308352

[DLG:IDD_DIALOG_REPORT]
Type=1
Class=CDlgReport
ControlCount=2
Control1=IDC_EDIT_REPORT,edit,1352730628
Control2=IDC_BUTTON_OK,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg

[DLG:IDD_GP3TRACKINSTALLER_DIALOG]
Type=1
Class=CGp3TrackInstallerDlg

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=8
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC_CREDITS,static,1342308352

[DLG:IDD_GP3TRACKINSTALLER_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=38
Control1=IDC_STATIC_SETTINGS,button,1342177287
Control2=IDC_EDIT_GP3PATH,edit,1350633600
Control3=IDC_STATIC_GP3,static,1342308352
Control4=IDC_EDIT_GP32KPATH,edit,1350633600
Control5=IDC_STATIC_GP32K,static,1342308352
Control6=IDC_BUTTON_GP3_BROWSE,button,1342242816
Control7=IDC_BUTTON_GP32K_BROWSE,button,1342242816
Control8=IDC_BUTTON_INSTALL_GP3,button,1342242816
Control9=IDC_BUTTON_INSTALL_GP32K,button,1342242816
Control10=IDC_BUTTON_INSTALL_BOTH,button,1342242816
Control11=IDC_STATIC_INSTALL,button,1342177287
Control12=IDC_EDIT_GP3TRACKDIR,edit,1484849280
Control13=IDC_STATIC_TRACKDIR,static,1476526080
Control14=IDC_BUTTON_TRACKDIR_BROWSE,button,1476460544
Control15=IDC_CHECK_TRACKDIR_ENABLE,button,1342242819
Control16=IDC_BUTTON1,button,1073807361
Control17=IDC_STATIC,static,1342177296
Control18=IDC_STATIC_TRACKFRAME,button,1342177287
Control19=IDC_STATIC_TRACK_FILE,static,1342308352
Control20=IDC_STATIC_TRACK_INFO,button,1342177287
Control21=IDC_STATIC_LABEL_COUNTRY,static,1342308352
Control22=IDC_STATIC_LABEL_LENGTH,static,1342308352
Control23=IDC_STATIC_LABEL_NAME,static,1342308352
Control24=IDC_STATIC_LABEL_LAPS,static,1342308352
Control25=IDC_STATIC_LABEL_YEAR,static,1342308352
Control26=IDC_STATIC_LABEL_DESC,static,1342308352
Control27=IDC_STATIC_LABEL_SLOT,static,1342308352
Control28=IDC_STATIC_LABEL_AUTHOR,static,1342308352
Control29=IDC_STATIC_LABEL_EVENT,static,1342308352
Control30=IDC_STATIC_LENGHT,static,1342308352
Control31=IDC_STATIC_LAPS,static,1342308352
Control32=IDC_STATIC_EVENT,static,1342308352
Control33=IDC_STATIC_YEAR,static,1342308352
Control34=IDC_STATIC_SLOT,static,1342308352
Control35=IDC_STATIC_AUTHOR,static,1342308352
Control36=IDC_STATIC_DESC,static,1342308352
Control37=IDC_STATIC_NAME,static,1342308352
Control38=IDC_STATIC_COUNTRY,static,1342308352

[MNU:IDR_MAINMENU]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_CLOSE
Command3=ID_FILE_SETTINGS
Command4=ID_FILE_EXIT
Command5=ID_HELP_ONLINE
Command6=ID_HELP_HELP
Command7=ID_HELP_ABOUT
CommandCount=7

