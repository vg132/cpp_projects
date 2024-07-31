// GP1 LapDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GP1 Lap.h"
#include "GP1 LapDlg.h"

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
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGP1LapDlg dialog

CGP1LapDlg::CGP1LapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGP1LapDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGP1LapDlg)
	m_Laps = 0;
	m_FileName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CGP1LapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGP1LapDlg)
	DDX_Control(pDX, IDC_Export, m_Test);
	DDX_Text(pDX, IDC_EDIT1, m_Laps);
	DDV_MinMaxInt(pDX, m_Laps, 0, 127);
	DDX_Text(pDX, IDC_FileName, m_FileName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGP1LapDlg, CDialog)
	//{{AFX_MSG_MAP(CGP1LapDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Export, OnExport)
	ON_BN_CLICKED(IDC_Import, OnImport)
	ON_BN_CLICKED(IDC_About, OnAbout)
	ON_COMMAND(MNU_Exit, OnExit)
	ON_COMMAND(MNU_TrackDir, OnTrackDir)
	ON_COMMAND(MNU_About, OnAbout)
	ON_BN_CLICKED(IDC_Exit, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGP1LapDlg message handlers

BOOL CGP1LapDlg::OnInitDialog()
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
	
	GetTrackDir();


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGP1LapDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGP1LapDlg::OnPaint() 
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
HCURSOR CGP1LapDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGP1LapDlg::OnExport() 
{
byte Laps;
TCHAR szModule[_MAX_PATH];
CString sCheck;
CString sTemp;
int iPos;

	//Get control data
	UpdateData(TRUE);
	//Open Track File
	CFile m_TrackFile(m_Path,CFile::modeWrite);
	//Seek to Laps Pos
	m_TrackFile.Seek(m_TrackFile.GetLength()-10,CFile::begin);
	//Write the new byte
	Laps=m_Laps;
	m_TrackFile.Write((char*) &Laps,sizeof(Laps));
	//Close File
	m_TrackFile.Close();

	GetModuleFileName(NULL, szModule, _MAX_PATH);
	
	sTemp=szModule;


	iPos=sTemp.GetLength();

	for(int i=iPos;i>=1;i--)
	{
		if (sTemp.Mid(i,1)=="\\")
		{
			sCheck=sTemp.Left(i);
			break;
		}
	}
	ShellExecute(m_hWnd,"open",sCheck+"\\gpchksum.exe",m_Path,sCheck,SW_SHOWNORMAL);
}


void CGP1LapDlg::OnImport() 
{
byte Laps;

OPENFILENAME OpenFileName;
TCHAR szFilter[]=_T("GP1 Track Files (f1ct*.dat)\0f1ct*.dat\0GP1 Track Files (*.dat)\0*.dat\0All Files (*.*)\0*.*\0\0");
TCHAR szFile[MAX_PATH];
CString m_File;

wsprintf (szFile, TEXT(""));

	OpenFileName.Flags=OFN_HIDEREADONLY;
    OpenFileName.lStructSize       = sizeof(OPENFILENAME);
	OpenFileName.hwndOwner         = m_hWnd;
	OpenFileName.hInstance         = 0;
	OpenFileName.lpstrFilter       = szFilter;
	OpenFileName.lpstrCustomFilter = (LPTSTR) NULL;
	OpenFileName.nMaxCustFilter    = 0L;
	OpenFileName.nFilterIndex      = 1L;
	OpenFileName.lpstrFile         = szFile;
	OpenFileName.nMaxFile          = sizeof(szFile);
	OpenFileName.lpstrFileTitle    = NULL;
	OpenFileName.nMaxFileTitle     = 0;
	OpenFileName.lpstrInitialDir   = m_TrackPath;
	OpenFileName.lpstrTitle        = __TEXT("Open Track File");
	OpenFileName.nFileOffset       = 0;
	OpenFileName.nFileExtension    = 0;
	OpenFileName.lpstrDefExt       = NULL; // No default extension     
	OpenFileName.lpTemplateName	   = NULL;
	OpenFileName.lCustData         = 0;

	//Show Common dialog

	if (GetOpenFileName(&OpenFileName))
	{


		m_File=szFile;


		GetShortPathName(OpenFileName.lpstrFile,m_Path,MAX_PATH);
		//assign track file to a CFile
		CFile m_TrackFile;
		//Open CFile
		m_TrackFile.Open(OpenFileName.lpstrFile,0,NULL);
		//Seek to lap pos in file
		m_TrackFile.Seek(m_TrackFile.GetLength()-10,CFile::begin);
		//Read laps into Test
		m_TrackFile.Read((char*) &Laps,sizeof(Laps));
		//Show Test in text box
		m_Laps=Laps;
		//Close file
		m_TrackFile.Close();
		//Show text in text box
		UpdateData(FALSE);
	}
}

void CGP1LapDlg::OnAbout() 
{
	CAboutDlg m_About;
	m_About.DoModal();
}

void CGP1LapDlg::OnExit() 
{
	OnOK();	
}

void CGP1LapDlg::OnTrackDir() 
{
char m_TDir[MAX_PATH];

BROWSEINFO bi;
LPITEMIDLIST pidl;
char ach[MAX_PATH];

bi.hwndOwner      = m_hWnd;
bi.pidlRoot       = NULL;
bi.pszDisplayName = ach;
bi.lpszTitle      = "Select Track Directory";
bi.ulFlags        = BIF_RETURNONLYFSDIRS;
bi.lpfn           = NULL;
bi.lParam         = 0;
bi.iImage         = 0;

	pidl = SHBrowseForFolder(&bi);
	if (pidl)
	{
		SHGetPathFromIDList(pidl,m_TDir);
		HKEY hKey;
		hKey=HKEY_CURRENT_USER;
		RegSetValue(hKey,"Software\\VG Software\\Gp1 Lap Editor",REG_SZ,m_TDir,lstrlen(m_TDir));
		RegCloseKey(hKey);
	}
}

void CGP1LapDlg::GetTrackDir()
{
#define MAX_LENGTH 512 
HKEY hKey;
long lRet;
DWORD dwLength = MAX_LENGTH, dwType = REG_SZ; 
char szBuffer[MAX_LENGTH];


	hKey=HKEY_CURRENT_USER;
	if (RegOpenKey( HKEY_CURRENT_USER, "Software\\Gp1 Lap Editor", &hKey)== ERROR_SUCCESS) 
	{
		lRet = RegQueryValueEx( hKey, "", NULL, &dwType, (LPBYTE)szBuffer, &dwLength);
		if (dwLength!=1)
		{
			m_TrackPath=szBuffer;
		} 
	}
}