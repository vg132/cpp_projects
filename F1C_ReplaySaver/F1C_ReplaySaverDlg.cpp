// F1C_ReplaySaverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "F1C_ReplaySaver.h"
#include "F1C_ReplaySaverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CF1C_ReplaySaverDlg dialog



CF1C_ReplaySaverDlg::CF1C_ReplaySaverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CF1C_ReplaySaverDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CF1C_ReplaySaverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DIRECTORYS, m_lstDirectorys);
}

BEGIN_MESSAGE_MAP(CF1C_ReplaySaverDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_ADDDIR, OnBnClickedButtonAdddir)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_DELDIR, OnBnClickedButtonDeldir)
	ON_BN_CLICKED(IDC_BUTTON_START, OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_DEFAULT, OnBnClickedButtonDefault)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CF1C_ReplaySaverDlg message handlers

BOOL CF1C_ReplaySaverDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	char tmp[_MAX_PATH];
	GetModuleFileName(NULL, tmp, _MAX_PATH);
	m_strStartupPath=tmp;
	m_strStartupPath=m_strStartupPath.Left(m_strStartupPath.ReverseFind('\\'));
	LoadConfig();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CF1C_ReplaySaverDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CF1C_ReplaySaverDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CF1C_ReplaySaverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
/*
void CF1C_ReplaySaverDlg::OnBnClickedButton1()
{
	
	UpdateData(TRUE);
	m_DirWatcher.WatchDirectory(m_WatchDir,FILE_NOTIFY_CHANGE_FILE_NAME|FILE_NOTIFY_CHANGE_LAST_WRITE|FILE_NOTIFY_CHANGE_SIZE,&m_ReplayWatcher);
	UpdateData(FALSE);
*/
/*

	DWORD dwChangeNotifyFlags = 0UL;
	FLAG_INFO arFlagInfo[]={
		{IDC_CHECK_FILE_NAME1,		FILE_NOTIFY_CHANGE_FILE_NAME},
		{IDC_CHECK_DIR_NAME1,		FILE_NOTIFY_CHANGE_DIR_NAME},
		{IDC_CHECK_LAST_WRITE1,		FILE_NOTIFY_CHANGE_LAST_WRITE},
		{IDC_CHECK_LAST_ACCESS1,	FILE_NOTIFY_CHANGE_LAST_ACCESS},
		{IDC_CHECK_SIZE1,			FILE_NOTIFY_CHANGE_SIZE},
		{IDC_CHECK_ATTRIBUTES1,		FILE_NOTIFY_CHANGE_ATTRIBUTES},
		{IDC_CHECK_LAST_WRITE1,		FILE_NOTIFY_CHANGE_LAST_WRITE},
		{IDC_CHECK_LAST_ACCESS1,	FILE_NOTIFY_CHANGE_LAST_ACCESS},
		{IDC_CHECK_CREATION1,		FILE_NOTIFY_CHANGE_CREATION},
		{IDC_CHECK_SECURITY1,		FILE_NOTIFY_CHANGE_SECURITY}
	};

	for(int i = 0; i < sizeof(arFlagInfo)/sizeof(arFlagInfo[0]); ++i)
	{
		dwChangeNotifyFlags |= (IsDlgButtonChecked(arFlagInfo[i].nCtrlId) == BST_CHECKED)? arFlagInfo[i].nFlag : 0;
	}

	if( ERROR_SUCCESS != (dwWatch = m_DirWatcher.WatchDirectory(m_strDirectoryToMonitor, 
													dwChangeFilter,
													&m_DirChangeHandler,
													bWatchSubDir,
													m_strIncludeFilter1,
													m_strExcludeFilter1)) )

													*/
/*
}

void CF1C_ReplaySaverDlg::OnBnClickedButton2()
{
}

void CF1C_ReplaySaverDlg::OnBnClickedButton3()
{
*/
/*
	UpdateData(TRUE);
	if(m_DirWatcher.IsWatchingDirectory(m_WatchDir))
		m_DirWatcher.UnwatchDirectory(m_WatchDir);
	UpdateData(FALSE);
	*/
/*
}
*/

bool CF1C_ReplaySaverDlg::LoadConfig(void)
{
	char buffer[_MAX_PATH], config[_MAX_PATH], tmp[30];
	int replays(0);
	CReplayInfo *ri=NULL;
	strcpy(config,m_strStartupPath);
	strcat(config,"\\config.ini");
	GetPrivateProfileString("Header","Replays","0",buffer,_MAX_PATH,config);
	replays=atoi(buffer);
	GetPrivateProfileString("Header","Default","0",buffer,_MAX_PATH,config);
	m_iDefaut=atoi(buffer);
	if(replays!=0)
	{
		for(int i=0;i<replays;i++)
		{
			ri=new CReplayInfo();
			strcpy(tmp,"Conf");
			itoa(i,buffer,10);
			strcat(tmp,buffer);
			GetPrivateProfileString(tmp,"Name","",buffer,_MAX_PATH,config);
			ri->SetName(buffer);
			GetPrivateProfileString(tmp,"Replay Directory","",buffer,_MAX_PATH,config);
			ri->SetReplayDirectory(buffer);
			GetPrivateProfileString(tmp,"Executable","",buffer,_MAX_PATH,config);
			ri->SetExecutable(buffer);
			GetPrivateProfileString(tmp,"Startup Directory","",buffer,_MAX_PATH,config);
			ri->SetStartupDirectory(buffer);
			m_mapReplayInfo[ri->GetName()]=ri;
			m_lstDirectorys.AddString(ri->GetName());
			if(i==m_iDefaut)
				m_lstDirectorys.SelectString(0,ri->GetName());
		}
	}
	return(true);
}
void CF1C_ReplaySaverDlg::OnBnClickedButtonAdddir()
{
	CNewConfigDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		CReplayInfo *ri=new CReplayInfo();
		ri->SetReplayDirectory((char*)(LPCTSTR)dlg.m_ReplayDirectory);
		ri->SetExecutable((char*)(LPCTSTR)dlg.m_Executable);
		ri->SetName((char*)(LPCTSTR)dlg.m_Name);
		ri->SetStartupDirectory((char*)(LPCTSTR)dlg.m_StartupDirectory);
		m_lstDirectorys.AddString(ri->GetName());
		m_mapReplayInfo[ri->GetName()]=ri;
	}
	SaveConfig();
}

void CF1C_ReplaySaverDlg::OnBnClickedButtonEdit()
{
	CNewConfigDlg dlg;
	CReplayInfo *ri;
	CString sel;
	int curSel=m_lstDirectorys.GetCurSel();
	if(curSel!=-1)
	{
		m_lstDirectorys.GetText(curSel,sel);
		ri=(CReplayInfo*)m_mapReplayInfo[sel];
		if(ri!=NULL)
		{
			dlg.m_ReplayDirectory=ri->GetReplayDirecotry();
			dlg.m_Executable=ri->GetExecutable();
			dlg.m_Name=ri->GetName();
			dlg.m_StartupDirectory=ri->GetStartupDirectory();
			if(dlg.DoModal()==IDOK)
			{
				m_mapReplayInfo.RemoveKey(ri->GetName());
				ri->SetReplayDirectory((char*)(LPCTSTR)dlg.m_ReplayDirectory);
				ri->SetExecutable((char*)(LPCTSTR)dlg.m_Executable);
				ri->SetName((char*)(LPCTSTR)dlg.m_Name);
				ri->SetStartupDirectory((char*)(LPCTSTR)dlg.m_StartupDirectory);
				m_mapReplayInfo[ri->GetName()]=ri;
				m_lstDirectorys.DeleteString(curSel);
				m_lstDirectorys.InsertString(curSel, ri->GetName());
				SaveConfig();
			}
		}
	}
}

void CF1C_ReplaySaverDlg::OnBnClickedButtonDeldir()
{
	CString sel;
	int curSel=m_lstDirectorys.GetCurSel();
	if(curSel!=-1)
	{
		m_lstDirectorys.GetText(curSel,sel);

		if(MessageBox("Do you want to delete configuration '"+sel+"' now?","Delete",MB_YESNO)==IDYES)
		{
			m_mapReplayInfo.RemoveKey((char*)(LPCTSTR)sel);
			m_lstDirectorys.DeleteString(curSel);
			if(curSel==m_iDefaut)
				m_iDefaut=0;
			else if(curSel<m_iDefaut)
				m_iDefaut--;
			SaveConfig();
		}
	}
}

void CF1C_ReplaySaverDlg::OnBnClickedButtonStart()
{
	CReplayInfo *ri;
	CString sel;
	m_DirWatcher.UnwatchAllDirectories();
	int curSel=m_lstDirectorys.GetCurSel();
	if(curSel!=-1)
	{
		m_lstDirectorys.GetText(curSel,sel);
		ri=(CReplayInfo*)m_mapReplayInfo[sel];
		if(ri!=NULL)
		{
			m_DirWatcher.WatchDirectory(ri->GetReplayDirecotry(),FILE_NOTIFY_CHANGE_FILE_NAME|FILE_NOTIFY_CHANGE_LAST_WRITE|FILE_NOTIFY_CHANGE_SIZE,&m_ReplayWatcher);
/*
			SHELLEXECUTEINFO exInfo;
			exInfo.cbSize = sizeof(exInfo);
			exInfo.hwnd = m_hWnd;
			exInfo.lpFile = ri->GetExecutable();
			exInfo.lpParameters = NULL;
			exInfo.lpDirectory=ri->GetStartupDirectory();
			exInfo.nShow = SW_SHOWNORMAL;
			exInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
			exInfo.lpVerb = "open";
			ShellExecuteEx(&exInfo);*/
			ShellExecute(m_hWnd,"open",ri->GetExecutable(),NULL,ri->GetStartupDirectory(),SW_SHOWNORMAL);
/*			WaitForSingleObject(exInfo.hProcess, INFINITE);
			if(m_DirWatcher.IsWatchingDirectory(ri->GetReplayDirecotry()))
			{
				m_DirWatcher.UnwatchDirectory(ri->GetReplayDirecotry());
			}*/
		}
	}
}

bool CF1C_ReplaySaverDlg::SaveConfig(void)
{
	char config[_MAX_PATH], buffer[_MAX_PATH], tmp[30];
	int i(0);
	CReplayInfo* ri;
	CString key;
	strcpy(config,m_strStartupPath);
	strcat(config,"\\config.ini");
	DeleteFile(config);
	POSITION pos=m_mapReplayInfo.GetStartPosition();
	while(pos)
	{
		m_mapReplayInfo.GetNextAssoc(pos,key,(void*&)ri);

		strcpy(buffer,"Conf");
		itoa(i++,tmp,10);
		strcat(buffer,tmp);
		WritePrivateProfileString(buffer,"Name",ri->GetName(),config);
		WritePrivateProfileString(buffer,"Replay Directory",ri->GetReplayDirecotry(),config);
		WritePrivateProfileString(buffer,"Executable",ri->GetExecutable(),config);
		WritePrivateProfileString(buffer,"Startup Directory",ri->GetStartupDirectory(),config);
	};
	itoa(i,tmp,10);
	WritePrivateProfileString("Header","Replays",tmp,config);
	itoa(m_iDefaut,tmp,10);
	WritePrivateProfileString("Header","Default",tmp,config);
	return(true);
}

void CF1C_ReplaySaverDlg::OnBnClickedButtonDefault()
{
	m_iDefaut=m_lstDirectorys.GetCurSel();
}

void CF1C_ReplaySaverDlg::OnClose()
{
	CReplayInfo *ri;
	CString key;
	m_DirWatcher.UnwatchAllDirectories();
	POSITION pos=m_mapReplayInfo.GetStartPosition();
	while(pos)
	{
		m_mapReplayInfo.GetNextAssoc(pos,key,(void*&)ri);
		m_mapReplayInfo.RemoveKey(ri->GetName());
		delete ri;
	};
	CDialog::OnClose();
}
