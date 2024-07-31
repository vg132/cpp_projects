// Gp1 Lap EditorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Gp1 Lap Editor.h"
#include "Gp1 Lap EditorDlg.h"
#include "Common.h"
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
	virtual void OnOK();
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGp1LapEditorDlg dialog

CGp1LapEditorDlg::CGp1LapEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGp1LapEditorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGp1LapEditorDlg)
	m_Laps = 0;
	m_FileExt = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGp1LapEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGp1LapEditorDlg)
	DDX_Control(pDX, IDC_FILES, m_Files);
	DDX_Text(pDX, IDC_LAPS, m_Laps);
	DDV_MinMaxByte(pDX, m_Laps, 0, 127);
	DDX_CBIndex(pDX, IDC_FILEEXT, m_FileExt);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGp1LapEditorDlg, CDialog)
	//{{AFX_MSG_MAP(CGp1LapEditorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_EDIT_SETTRACKPATH, OnEditSettrackpath)
	ON_COMMAND(ID_HELP_ONLINE, OnHelpOnline)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVEAS, OnFileSaveas)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_FILES, OnItemchangedFiles)
	ON_CBN_SELCHANGE(IDC_FILEEXT, OnSelchangeFileext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGp1LapEditorDlg message handlers

BOOL CGp1LapEditorDlg::OnInitDialog()
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

	
	
CGp1LapEditorApp* pApp;

	pApp = (CGp1LapEditorApp *)AfxGetApp();
	m_pImageList=new CImageList();
	m_pImageList->Create(16, 16, ILC_MASK, 2, 2);
	m_pImageList->Add(pApp->LoadIcon(IDI_TRACK));//		0

	m_Files.SetImageList(m_pImageList,LVSIL_SMALL);

	m_Files.InsertColumn(0,"File Name",LVCFMT_LEFT,116,-1);
	szPath=m_Common.RegGetValue("Software\\VG Software\\Gp1 Lap Editor","");

	if(szPath=="")
		szPath="c:\\";
	if (szPath.Right(1)!="\\")
		szPath+="\\";
	
	m_FileExt=1;
	UpdateData(FALSE);
	ListFiles();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGp1LapEditorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGp1LapEditorDlg::OnPaint() 
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
HCURSOR CGp1LapEditorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGp1LapEditorDlg::OnFileExit() 
{
	// TODO: Add your command handler code here
	OnOK();	
}

void CGp1LapEditorDlg::OnHelpAbout() 
{
	// TODO: Add your command handler code here
CAboutDlg ab;	
	ab.DoModal();
}

void CGp1LapEditorDlg::OnEditSettrackpath() 
{
	// TODO: Add your command handler code here
	szPath=m_Common.BrowseForFolders("Select Gp1 Track Path",m_hWnd);
	if(szPath!="")
	{
		if (szPath.Right(1)!="\\")
			szPath+="\\";
		m_Common.RegSaveValue("Software\\VG Software\\Gp1 Lap Editor","",szPath);
		ListFiles();
	}
}

void CGp1LapEditorDlg::OnHelpOnline() 
{
	// TODO: Add your command handler code here
	ShellExecute(m_hWnd,"open","http://www.vgsoftware.com/",NULL,NULL,1);
}

void CGp1LapEditorDlg::OnFileOpen() 
{
TCHAR szFilter[]=_T("GP1 Track Files (f1ct*.dat)\0f1ct*.dat\0GP1 Track Files (*.dat)\0*.dat\0All Files (*.*)\0*.*\0\0");
CFileDialog f(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
	f.m_ofn.lpstrFilter=szFilter;
	f.m_ofn.lpstrTitle="Open Track File";
	f.m_ofn.lpstrInitialDir = szPath;
	if(f.DoModal()==  IDOK)
	{
		m_CurrentFile=f.m_ofn.lpstrFile;
		Load();
	}
}

void CGp1LapEditorDlg::OnFileSaveas() 
{
TCHAR szFilter[]=_T("GP1 Track Files (f1ct*.dat)\0f1ct*.dat\0GP1 Track Files (*.dat)\0*.dat\0All Files (*.*)\0*.*\0\0");
CFileDialog f(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
start:
	f.m_ofn.lpstrFilter=szFilter;
	f.m_ofn.lpstrTitle="Save Track File";
	f.m_ofn.lpstrInitialDir = szPath;
	f.m_ofn.lpstrDefExt="dat";
	if(f.DoModal()==  IDOK)
	{
		if(CopyFile(m_CurrentFile,f.m_ofn.lpstrFile,TRUE))
		{
			m_CurrentFile=f.m_ofn.lpstrFile;
			Save();
		}
		else
		{
			CString file=f.m_ofn.lpstrFileTitle;
			int retVal=MessageBox("The file " + file + " already exists. Do you want to replace the existing file?","Gp1 Lap Edit",MB_YESNOCANCEL|MB_ICONEXCLAMATION);
			if(retVal==IDYES)
			{
				DeleteFile(f.m_ofn.lpstrFile);
				CopyFile(m_CurrentFile,f.m_ofn.lpstrFile,FALSE);
			}
			else if(retVal==IDNO)
			{
				goto start;
			}
		}		
	}	
}

void CGp1LapEditorDlg::OnSave() 
{
	Save();
}

void CGp1LapEditorDlg::OnFileSave() 
{
	Save();
}

void CGp1LapEditorDlg::Load()
{
	if(m_CurrentFile!="")
	{
		BeginWaitCursor();
		CFile f;
		f.Open(m_CurrentFile,CFile::modeRead,NULL);
		f.Seek(f.GetLength()-10,CFile::begin);
		f.Read((char*)&bLaps,sizeof(bLaps));
		f.Close();
		m_Laps=bLaps;
		UpdateData(FALSE);
		SetWindowText("Gp1 Lap Edit v1.1 "+m_CurrentFile);
		EndWaitCursor();
	}
}

void CGp1LapEditorDlg::Save()
{
	if(m_CurrentFile!="")
	{
		BeginWaitCursor();
		CFile f;
		UpdateData(TRUE);	
		f.Open(m_CurrentFile,CFile::modeWrite,NULL);
		f.Seek(f.GetLength()-10,CFile::begin);
		bLaps=m_Laps;
		f.Write((char*)&bLaps,sizeof(bLaps));
		f.Close();
		CheckSum();
		EndWaitCursor();
	}
}

void CGp1LapEditorDlg::ListFiles()
{
BOOL bFound=FALSE;
CString cFile;
CString cFileExt;
WIN32_FIND_DATA wfd;
HANDLE hFile;
CString szDir;
CString szExt;

	UpdateData(TRUE);

	if(m_FileExt==0)
		szExt="*.dat";
	else if(m_FileExt==1)
		szExt="f1ct*.dat";
	else if(m_FileExt==2)
		szExt="*.*";

	hFile=(HANDLE)-1;
	m_Files.DeleteAllItems();
	szDir=szPath+szExt;	

	hFile=FindFirstFile(szDir,&wfd);
	while(!bFound)
	{
		cFile=wfd.cFileName;
		cFile.MakeLower();
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
		}
		else
		{
			m_Files.InsertItem(NULL,cFile,0);
		}
		bFound = !FindNextFile(hFile,&wfd);
    }
}

void CGp1LapEditorDlg::OnItemchangedFiles(NMHDR* pNMHDR, LRESULT* pResult) 
{
POSITION pos;
int iItem;
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	
	pos=m_Files.GetFirstSelectedItemPosition();
	iItem=m_Files.GetNextSelectedItem(pos);
	if(m_Files.GetItemText(iItem,0)!="")
	{
		m_CurrentFile=szPath + m_Files.GetItemText(iItem,0);
		Load();
	}
	*pResult = 0;
}

void CGp1LapEditorDlg::OnSelchangeFileext() 
{
	ListFiles();
}

void CGp1LapEditorDlg::CheckSum()
{
	CFile f;
	long datasize;
	unsigned short sum=0,cycle=0;
	unsigned char c;
	f.Open(m_CurrentFile,CFile::modeReadWrite,NULL);
	datasize=f.GetLength()-4;
	f.SeekToBegin();

	while (datasize--)
	{
		f.Read((char*)&c,sizeof(c));
		sum+=c;
		cycle = (cycle<<3)+(cycle>>13);
		cycle +=c;
	}
	f.Seek(f.GetLength()-4,CFile::begin);
	f.Write((char*)&sum,sizeof(sum));
	f.Write((char*)&cycle,sizeof(cycle));
	f.Close();	
}

void CAboutDlg::OnOK() 
{
	CDialog::OnOK();
}
