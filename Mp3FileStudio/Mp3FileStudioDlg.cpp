// Mp3FileStudioDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mp3FileStudio.h"
#include "Mp3FileStudioDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMp3FileStudioDlg dialog

CMp3FileStudioDlg::CMp3FileStudioDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMp3FileStudioDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMp3FileStudioDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMp3FileStudioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMp3FileStudioDlg)
	DDX_Control(pDX, IDC_DRIVEPICKER, m_DriveList);
	DDX_Control(pDX, IDC_FILELIST, m_FileList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMp3FileStudioDlg, CDialog)
	//{{AFX_MSG_MAP(CMp3FileStudioDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_UP1LVL, OnUp1lvl)
	ON_COMMAND(ID_ICONLIST, OnList)
	ON_COMMAND(ID_REPORT, OnReport)
	ON_COMMAND(ID_BIGICONS, OnBigIcons)
	ON_COMMAND(ID_APP_HELP, OnHelp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_HELP_ONLINE, OnHelpOnline)
	ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_WM_SIZE()
	ON_COMMAND(ID_VIEW_ALWAYSONTOP, OnViewAlwaysontop)
	ON_COMMAND(ID_VIEW_LIST, OnList)
	ON_COMMAND(ID_VIEW_DETAILS, OnReport)
	ON_COMMAND(ID_VIEW_LARGEICONS, OnBigIcons)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMp3FileStudioDlg message handlers

BOOL CMp3FileStudioDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_AlwaysOnTop=false;

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Register ower own message
	m_Message=RegisterWindowMessage("MP3_FILE_STUDIO_MESSAGE");

	//build tab structure
	m_PropertySheet.AddPage(&m_TagEdit);
	m_PropertySheet.AddPage(&m_AutoTagEdit);
	m_PropertySheet.AddPage(&m_AutoFileName);
	m_PropertySheet.AddPage(&m_FileOrginizer);
	m_PropertySheet.AddPage(&m_Settings);
	m_PropertySheet.Create(this,WS_CHILD|WS_VISIBLE|WS_TABSTOP,WS_EX_CONTROLPARENT);
	CRect rcSheet;
	GetDlgItem(IDC_TEST)->GetWindowRect(&rcSheet);
	ScreenToClient(&rcSheet);
	m_PropertySheet.SetWindowPos(NULL,rcSheet.left-7,rcSheet.top-7,0,0,SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE);

	m_Settings.SetPlayer(m_RegEdit.GetSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Player",""));
	m_PropertySheet.SetActivePage(m_RegEdit.GetSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Page",0));
	m_AutoFileName.SetFileListView(&m_FileList);
	//Init tool bar
	BuildToolbar();
	m_Settings.Init(this,m_Message);

	//init files list and drive list with correct directory
	//and settings

	m_FileList.InitFileList(this,"*.mp3",&m_SmallImageList,&m_LargeImageList,m_Message);

	m_DriveList.Init(this,&m_SmallImageList,m_Message);
	m_FileList.SetPlayer(m_RegEdit.GetSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Player",""));
	CString dir;
	dir=m_RegEdit.GetSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Directory","C:\\");

	WIN32_FIND_DATA wfd;
	HANDLE hFile;
	hFile = FindFirstFile(dir+"*.*",&wfd);
	if(hFile==(HANDLE)-1)
		dir="My Computer";

	m_FileList.SetDirectory(dir);
	m_DriveList.SetDirectory(dir);

	m_AutoTagEdit.SetDirectory(dir);
	m_AutoFileName.SetDirectory(dir);
	m_AutoTagEdit.SetDirectory(dir);
	m_FileOrginizer.SetDirectory(dir);

	m_TagEdit.DisableAndSave();
	m_TagEdit.SetAutoSave(m_RegEdit.GetSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Auto Save",0));

	m_WinAmpPath = m_RegEdit.GetSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","WinAmp","");
	if(m_WinAmpPath=="")
	{
		// Gör något
	}

	//set corect view settings for list box
	m_ToolBarStatus = m_RegEdit.GetSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Toolbar","0");

	if(m_ToolBarStatus=="2")
		OnReport();
	else if(m_ToolBarStatus=="1")
		OnList();
	else if(m_ToolBarStatus=="0")
		OnBigIcons();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMp3FileStudioDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMp3FileStudioDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMp3FileStudioDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAboutDlg::OnOk() 
{
	OnOK();	
}

void CMp3FileStudioDlg::BuildToolbar()
{
	m_Toolbar.Create(WS_CHILDWINDOW|WS_VISIBLE|TBSTYLE_FLAT|CCS_NODIVIDER|CCS_NORESIZE|CCS_TOP,
									CRect(353,10,484,32),
									this,
									IDC_TOOLBAR);

	//Build toolbar buttons
	int m_nButtonCount=5;
	TBBUTTON *m_pTBButtons;

	VERIFY(m_Toolbar.AddBitmap(m_nButtonCount,IDB_TOOLBAR)!=-1);
	m_pTBButtons = new TBBUTTON[m_nButtonCount];
	for(int nIndex=0;nIndex<m_nButtonCount;nIndex++)
	{
			m_pTBButtons[nIndex].iString = NULL;
			m_pTBButtons[nIndex].fsState = TBSTATE_ENABLED;
			m_pTBButtons[nIndex].fsStyle = TBSTYLE_BUTTON;
			m_pTBButtons[nIndex].dwData = 0;
			m_pTBButtons[nIndex].iBitmap=nIndex;
			m_pTBButtons[nIndex].idCommand=ID_UP1LVL+nIndex;
	}

	TBBUTTON sepButton;
	sepButton.idCommand = 0;
	sepButton.fsStyle = TBSTYLE_SEP;
	sepButton.fsState = TBSTATE_ENABLED;
	sepButton.iString = 0;
	sepButton.iBitmap = 0;
	sepButton.dwData = 0;

	for (nIndex = 0; nIndex < m_nButtonCount; nIndex++)
	{
		VERIFY(m_Toolbar.AddButtons(1,&m_pTBButtons[nIndex]));
		if(nIndex==0||nIndex==3)
		{
			VERIFY(m_Toolbar.AddButtons(1,&sepButton));
		}
	}
}
void CMp3FileStudioDlg::OnUp1lvl()
{
	BeginWaitCursor();
	m_FileList.Up1Level();
	EndWaitCursor();
}

void CMp3FileStudioDlg::OnList()
{
	m_FileList.ModifyStyle(LVS_ICON|LVS_REPORT,LVS_LIST);
	m_Toolbar.CheckButton(ID_REPORT,FALSE);
	m_Toolbar.CheckButton(ID_BIGICONS,FALSE);
	m_Toolbar.CheckButton(ID_ICONLIST);
	this->GetMenu()->CheckMenuItem(ID_VIEW_LIST,MF_CHECKED);
	this->GetMenu()->CheckMenuItem(ID_VIEW_DETAILS,MF_UNCHECKED);
	this->GetMenu()->CheckMenuItem(ID_VIEW_LARGEICONS,MF_UNCHECKED);
	m_ToolBarStatus="1";
}

void CMp3FileStudioDlg::OnReport()
{
	m_FileList.ModifyStyle(LVS_ICON|LVS_LIST,LVS_REPORT);
	m_Toolbar.CheckButton(ID_REPORT);
	m_Toolbar.CheckButton(ID_BIGICONS,FALSE);
	m_Toolbar.CheckButton(ID_ICONLIST,FALSE);
	this->GetMenu()->CheckMenuItem(ID_VIEW_LIST,MF_UNCHECKED);
	this->GetMenu()->CheckMenuItem(ID_VIEW_DETAILS,MF_CHECKED);
	this->GetMenu()->CheckMenuItem(ID_VIEW_LARGEICONS,MF_UNCHECKED);
	m_ToolBarStatus="2";
}

void CMp3FileStudioDlg::OnBigIcons()
{
	m_FileList.ModifyStyle(LVS_LIST|LVS_REPORT,LVS_ICON);
	m_Toolbar.CheckButton(ID_REPORT,FALSE);
	m_Toolbar.CheckButton(ID_BIGICONS);
	m_Toolbar.CheckButton(ID_ICONLIST,FALSE);
	this->GetMenu()->CheckMenuItem(ID_VIEW_LIST,MF_UNCHECKED);
	this->GetMenu()->CheckMenuItem(ID_VIEW_DETAILS,MF_UNCHECKED);
	this->GetMenu()->CheckMenuItem(ID_VIEW_LARGEICONS,MF_CHECKED);
	m_ToolBarStatus="0";
}

/**
 * Functions to call when program stops.
 */
BOOL CMp3FileStudioDlg::DestroyWindow() 
{
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Directory",m_FileList.GetDirectory());
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Toolbar",m_ToolBarStatus);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Page",m_PropertySheet.GetActiveIndex());
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Auto Save",m_TagEdit.GetAutoSave());
	return CDialog::DestroyWindow();
}

/**
 * Load and show about dialog
 */
void CMp3FileStudioDlg::OnAppAbout()
{
	CAboutDlg a;
	a.DoModal();
}

/**
 * Start the default internet webbrowser and locate it to the
 * VG Software site
 */
void CMp3FileStudioDlg::OnHelpOnline() 
{
	ShellExecute(m_hWnd,"open","http://www.vgsoftware.com/",NULL,NULL,1);
}

void CMp3FileStudioDlg::OnViewRefresh() 
{
	m_FileList.SetDirectory(m_FileList.GetDirectory());
}

void CMp3FileStudioDlg::OnHelp()
{
	MessageBox("HELP!\n\nThis is only a Beta version, no help file here.\nYou have to figure out how to use this program all by your self! :)\n\n/Viktor");
}

LRESULT CMp3FileStudioDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if(message==m_Message)
	{
		CString szTmp("");
		switch(wParam)
		{
			case WM_CHANGED:
			{
				KillTimer(ID_TIMER_FILESELECT);
				szTmp=m_DriveList.GetDirectory();
				m_FileList.SetDirectory(szTmp);
				m_AutoTagEdit.SetDirectory(szTmp);
				m_AutoFileName.SetDirectory(szTmp);
				m_FileOrginizer.SetDirectory(szTmp);
				if(m_PropertySheet.GetActiveIndex()==0)
					m_TagEdit.DisableAndSave();
				if(szTmp=="My Computer")
					m_Toolbar.EnableButton(ID_UP1LVL,FALSE);
				else
					m_Toolbar.EnableButton(ID_UP1LVL,TRUE);
				break;
			}
			case WM_CHANGEDFOLDER:
			{
				KillTimer(ID_TIMER_FILESELECT);
				szTmp=m_FileList.GetDirectory();
				m_DriveList.SetDirectory(szTmp);
				m_AutoTagEdit.SetDirectory(szTmp);
				m_AutoFileName.SetDirectory(szTmp);
				m_FileOrginizer.SetDirectory(szTmp);
				if(m_PropertySheet.GetActiveIndex()==0)
					m_TagEdit.DisableAndSave();
				if(szTmp=="My Computer")
					m_Toolbar.EnableButton(ID_UP1LVL,FALSE);
				else
					m_Toolbar.EnableButton(ID_UP1LVL,TRUE);
				break;
			}
			case WM_FILESELECTED:
			{
				KillTimer(ID_TIMER_FILESELECT);
				m_AutoTagEdit.SetFile(m_FileList.GetFile());
				m_AutoFileName.SetFile(m_FileList.GetFile());
				m_FileOrginizer.SetFile(m_FileList.GetFile());
				if(m_PropertySheet.GetActiveIndex()==0)
				{
					m_TagEdit.SetFile(m_FileList.GetFile(),false);
				}
				else if(m_PropertySheet.GetActiveIndex()==1)
				{
					m_TagEdit.SetFile(m_FileList.GetFile(),true);
				}
				break;
			}
			case WM_FOLDERSELECTED:
			{
				KillTimer(ID_TIMER_FILESELECT);
				m_TagEdit.DisableAndSave();
				m_AutoTagEdit.SetDirectory(m_FileList.GetDirectory());
				break;
			}
			case WM_NONSELECTED:
			{
				SetTimer(ID_TIMER_FILESELECT,10,NULL);
				break;
			}
			case WM_NEWPLAYER:
			{
				m_FileList.SetPlayer(m_Settings.GetPlayer());
				m_RegEdit.SaveSettings(HKEY_CURRENT_USER,"Software\\VG Software\\Mp3FileStudio","Player",m_Settings.GetPlayer());
				break;
			}
			case WM_SAVEFILE:
			{
				m_TagEdit.DisableAndSave();
			}
		}
	}
	return CDialog::WindowProc(message, wParam, lParam);
}

void CMp3FileStudioDlg::OnFileSave() 
{
	if(m_PropertySheet.GetActiveIndex()==0)
		m_TagEdit.SaveTag();
}

void CMp3FileStudioDlg::OnSize(UINT nType, int cx, int cy) 
{
//	CDialog::OnSize(nType, cx, cy);
}

void CMp3FileStudioDlg::OnViewAlwaysontop() 
{
	CRect rect;
	GetWindowRect(rect);

	if(m_AlwaysOnTop==true)
	{
		::SetWindowPos(m_hWnd ,       // handle to window
									HWND_NOTOPMOST,  // placement-order handle
									rect.left,     // horizontal position
									rect.top,      // vertical position
									rect.Width(),  // width
									rect.Height(), // height
									SWP_SHOWWINDOW // window-positioning options
									);
	}
	else
	{
		::SetWindowPos(m_hWnd ,       // handle to window
									HWND_TOPMOST,  // placement-order handle
									rect.left,     // horizontal position
									rect.top,      // vertical position
									rect.Width(),  // width
									rect.Height(), // height
									SWP_SHOWWINDOW // window-positioning options
									);
	}
	m_AlwaysOnTop=!m_AlwaysOnTop;

	CMenu* pMenu = GetMenu();
	pMenu = pMenu->GetSubMenu(1);
	if (pMenu!=NULL&&m_AlwaysOnTop==true)
		pMenu->CheckMenuItem(ID_VIEW_ALWAYSONTOP,MF_BYCOMMAND|MF_CHECKED);
	else if (pMenu!=NULL&&m_AlwaysOnTop==false)
		pMenu->CheckMenuItem(ID_VIEW_ALWAYSONTOP,MF_BYCOMMAND|MF_UNCHECKED);	
}

void CMp3FileStudioDlg::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent==ID_TIMER_FILESELECT)
		m_TagEdit.DisableAndSave();	
	CDialog::OnTimer(nIDEvent);
}
