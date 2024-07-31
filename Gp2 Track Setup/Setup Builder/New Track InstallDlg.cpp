// New Track InstallDlg.cpp : implementation file
//

#include "stdafx.h"
#include "New Track Install.h"
#include "New Track InstallDlg.h"
#include "Direct.h"
#include "About.h"
#include "TrackInfo.h"


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
	CAbout();
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
	afx_msg void OnExit();
	afx_msg void OnResume();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

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
	ON_BN_CLICKED(IDC_Exit, OnExit)
	ON_BN_CLICKED(IDC_Resume, OnResume)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewTrackInstallDlg dialog

CNewTrackInstallDlg::CNewTrackInstallDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewTrackInstallDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewTrackInstallDlg)
	m_Gp2Dir = _T("");
	m_SetupFile = _T("");
	m_WelcomeText = _T("");
	m_Gp2Form = _T("");
	m_Summary = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNewTrackInstallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewTrackInstallDlg)
	DDX_Control(pDX, IDC_JamFiles, m_JamFiles);
	DDX_Control(pDX, IDC_TrackFile2, m_TrackFile);
	DDX_Control(pDX, IDC_Next, m_NextButton);
	DDX_Text(pDX, IDC_Gp2Dir, m_Gp2Dir);
	DDX_Text(pDX, IDC_SetupFile, m_SetupFile);
	DDX_Text(pDX, IDC_WelcomeText, m_WelcomeText);
	DDX_Text(pDX, IDC_Gp2form, m_Gp2Form);
	DDX_Text(pDX, IDC_Summary, m_Summary);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNewTrackInstallDlg, CDialog)
	//{{AFX_MSG_MAP(CNewTrackInstallDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Next, OnNext)
	ON_BN_CLICKED(IDC_Back, OnBack)
	ON_BN_CLICKED(IDC_SetupBrowse, OnSetupBrowse)
	ON_BN_CLICKED(IDC_Gp2DirBrowse, OnGp2DirBrowse)
	ON_BN_CLICKED(IDC_AddJam, OnAddJam)
	ON_BN_CLICKED(IDC_AddTrack, OnAddTrack)
	ON_BN_CLICKED(IDC_RemoveAll, OnRemoveAll)
	ON_BN_CLICKED(IDC_RemoveJam, OnRemoveJam)
	ON_BN_CLICKED(IDC_RemoveTrack2, OnRemoveTrack2)
	ON_BN_CLICKED(IDC_AddGp2Form, OnAddGp2Form)
	ON_BN_CLICKED(IDC_RemoveGp2Form, OnRemoveGp2Form)
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_BN_CLICKED(IDC_Cancel, OnCancel)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewTrackInstallDlg message handlers

BOOL CNewTrackInstallDlg::OnInitDialog()
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
	iCurItem=1;
	Show1(TRUE);
	GetDlgItem(IDC_Next)->EnableWindow(FALSE);
CString RetVal;

	//Get GP2 Dir
	RetVal=RegGetValue("Software\\VG Software\\Gp2 Track Setup Wizard","Gp2Path");
	if (RetVal!="")
	{
		m_Gp2Dir=RetVal;
		GetDlgItem(IDC_Next)->EnableWindow(TRUE);
	}
	//Set default save path
	RetVal=RegGetValue("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders","Personal");
	if (RetVal!="")
	{
		if (RetVal.Right(1)=="\\")
		{
			RetVal+="Setup.exe";
			m_SetupFile=RetVal;
		}
		else
		{
			RetVal+="\\Setup.exe";
			m_SetupFile=RetVal;
		}
	}
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNewTrackInstallDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNewTrackInstallDlg::OnPaint() 
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
HCURSOR CNewTrackInstallDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAboutDlg::OnExit() 
{
	OnOK();	
}

void CAboutDlg::OnResume() 
{
	OnCancel();	
}

void CNewTrackInstallDlg::OnCancel() 
{
int iRetVal;
	//ask user to confirm exit
	CAboutDlg dlg;
	iRetVal=dlg.DoModal();
	if (iRetVal == IDOK)
	{
		OnOK();
	}
}

void CNewTrackInstallDlg::Show1(bool Show)
{
	if (Show==TRUE)
	{
		GetDlgItem(IDC_WelcomeText)->ShowWindow(TRUE);
		GetDlgItem(IDC_InstallLogo)->ShowWindow(TRUE);
		GetDlgItem(IDC_SetupFrame)->ShowWindow(TRUE);
		GetDlgItem(IDC_SetupFile)->ShowWindow(TRUE);
		GetDlgItem(IDC_SetupBrowse)->ShowWindow(TRUE);
		GetDlgItem(IDC_Gp2Dir)->ShowWindow(TRUE);
		GetDlgItem(IDC_Gp2DirFrame)->ShowWindow(TRUE);
		GetDlgItem(IDC_Gp2DirBrowse)->ShowWindow(TRUE);
		GetDlgItem(IDC_Back)->EnableWindow(FALSE);
		m_WelcomeText.LoadString(1);
	}
	else
	{
		GetDlgItem(IDC_WelcomeText)->ShowWindow(FALSE);
		GetDlgItem(IDC_InstallLogo)->ShowWindow(FALSE);
		GetDlgItem(IDC_SetupFrame)->ShowWindow(FALSE);
		GetDlgItem(IDC_SetupFile)->ShowWindow(FALSE);
		GetDlgItem(IDC_SetupBrowse)->ShowWindow(FALSE);
		GetDlgItem(IDC_Gp2Dir)->ShowWindow(FALSE);
		GetDlgItem(IDC_Gp2DirFrame)->ShowWindow(FALSE);
		GetDlgItem(IDC_Gp2DirBrowse)->ShowWindow(FALSE);
		GetDlgItem(IDC_Back)->EnableWindow(TRUE);
		m_WelcomeText.LoadString(1);
	}

}

void CNewTrackInstallDlg::Show2(bool Show)
{
	if (Show==TRUE)
	{
		GetDlgItem(IDC_TrackFile2)->ShowWindow(TRUE);
		GetDlgItem(IDC_AddTrack)->ShowWindow(TRUE);
		GetDlgItem(IDC_RemoveTrack2)->ShowWindow(TRUE);
		GetDlgItem(IDC_Gp2form)->ShowWindow(TRUE);
		GetDlgItem(IDC_AddGp2Form)->ShowWindow(TRUE);
		GetDlgItem(IDC_RemoveGp2Form)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_TrackFile2)->ShowWindow(FALSE);
		GetDlgItem(IDC_AddTrack)->ShowWindow(FALSE);
		GetDlgItem(IDC_RemoveTrack2)->ShowWindow(FALSE);
		GetDlgItem(IDC_Gp2form)->ShowWindow(FALSE);
		GetDlgItem(IDC_AddGp2Form)->ShowWindow(FALSE);
		GetDlgItem(IDC_RemoveGp2Form)->ShowWindow(FALSE);
	}
}

void CNewTrackInstallDlg::Show3(bool Show)
{
	if (Show==TRUE)
	{
		GetDlgItem(IDC_JamFiles)->ShowWindow(TRUE);
		GetDlgItem(IDC_AddJam)->ShowWindow(TRUE);
		GetDlgItem(IDC_RemoveJam)->ShowWindow(TRUE);
		GetDlgItem(IDC_RemoveAll)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_JamFiles)->ShowWindow(FALSE);
		GetDlgItem(IDC_AddJam)->ShowWindow(FALSE);
		GetDlgItem(IDC_RemoveJam)->ShowWindow(FALSE);
		GetDlgItem(IDC_RemoveAll)->ShowWindow(FALSE);
	}
}

void CNewTrackInstallDlg::Show4(bool Show)
{
	if (Show==TRUE)
	{
		GetDlgItem(IDC_Summary)->ShowWindow(TRUE);
		m_NextButton.SetWindowText("Finish!");
	}
	else
	{
		GetDlgItem(IDC_Summary)->ShowWindow(FALSE);
		m_NextButton.SetWindowText("Next >");
	}
}

void CNewTrackInstallDlg::OnNext() 
{
	iCurItem+=1;
	if (iCurItem==2)
	{
		Show1(FALSE);
		Show2(TRUE);
	}
	else if (iCurItem==3)
	{
		Show2(FALSE);
		Show3(TRUE);
	}
	else if (iCurItem==4)
	{
		Show3(FALSE);
		Show4(TRUE);
		MakeSummary();
	}
	else
	{
		AddFiles();
	}
}

void CNewTrackInstallDlg::OnBack() 
{
	iCurItem-=1;	
	if (iCurItem==1)
	{
		Show2(FALSE);
		Show1(TRUE);
	}
	else if (iCurItem==2)
	{
		Show3(FALSE);
		Show2(TRUE);
	}
	else if (iCurItem==3)
	{
		Show4(FALSE);
		Show3(TRUE);
	}
	else
	{
		iCurItem=1;
	}
}

void CNewTrackInstallDlg::OnSetupBrowse() 
{
TCHAR szFilter[]=_T("Install File (*.exe)\0*.exe\0\0");

	CFileDialog fDialog(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
	fDialog.m_ofn.lpstrFilter=szFilter;
	fDialog.m_ofn.lpstrDefExt="exe";
	fDialog.m_ofn.lpstrInitialDir=m_SetupFile;
	int iReturn = fDialog.DoModal();
	if(iReturn ==  IDOK)
	{
		m_SetupFile=fDialog.GetPathName();
		UpdateData(FALSE);
	}
}

void CNewTrackInstallDlg::ConvertFile(CString cFileName,bool bDelete)
{
// Decryption variables
unsigned long pattern = 0xB082F165;
unsigned long value = 0;
int nNumBytes;
int bSuccess = 1;
CString cNewFile;
int iLen;

	// Work out the filename to which we're going to save
	cFileName.MakeLower();
	//If jam file then new file will be a jad file
	if (cFileName.Right(3)=="jam")
	{
		iLen=cFileName.GetLength();
		cNewFile=cFileName.Mid(0,iLen-1);
		cNewFile+="d";
	}
	else
	{
		iLen=cFileName.GetLength();
		cNewFile=cFileName.Mid(0,iLen-1);
		cNewFile+="m";
	}
	// Open the input file
	CFile fInput(cFileName,CFile::modeRead);
	
	// Open the output file
	CFile fOutput(cNewFile,CFile::modeReadWrite | CFile::modeCreate);

	// Loop through the file, 4 bytes at a time, en/decrypting the
	// contents into the output file as we go.
	nNumBytes=fInput.GetLength();
	for (int nNumBlocks = nNumBytes / 4; nNumBlocks > 0;nNumBlocks--)
	{
		fInput.Read((char*)&value,4);
		// Jams use a simple XOR encryption method, with the encryption key
		// changing for each subsequent 4 bytes.  Thus, the same process can
		// be repeated to encrypt/decrypt the files.
		value ^= pattern;
		pattern *= 5;

		// Output the en/decrypted value
		fOutput.Write((char *) &value,4);
	}
	// Tidy up by closing the files
	fOutput.Close();
	fInput.Close();
	// Finally, if the conversion was a success, delete the input file
	if (bDelete==TRUE)
	{
		DeleteFile(cFileName);
	}
}

void CNewTrackInstallDlg::OnGp2DirBrowse() 
{
char Path[260];
//Browse for folders
BROWSEINFO bff;
LPITEMIDLIST pidl;
WIN32_FIND_DATA* wfd;
HANDLE hFile;
CString cFileName;

bff.hwndOwner		=m_hWnd;
bff.iImage			=0;
bff.lParam			=0;
bff.lpszTitle		="Select Gp2 Directory";
bff.pidlRoot		=NULL;
bff.ulFlags			=BIF_RETURNONLYFSDIRS;
bff.pszDisplayName	=Path;
bff.lpfn			=NULL;

	pidl=SHBrowseForFolder(&bff);
	if (pidl)
	{
		SHGetPathFromIDList(pidl,Path);
		cFileName=Path;
		cFileName=cFileName + "\\gp2.exe";
		hFile=FindFirstFile(cFileName,wfd);
		if (hFile!=(HANDLE)(-1))
		{
			m_Gp2Dir=Path;
			RegSaveValue("Software\\VG Software\\Gp2 Track Setup Wizard","Gp2Path",m_Gp2Dir);
			GetDlgItem(IDC_Next)->EnableWindow(TRUE);
		}
		else
		{
			MessageBox("This is not your Gp2 directory!","Gp2 Track Setup Wizard",NULL);
		}
	}
	UpdateData(FALSE);	
}

void CNewTrackInstallDlg::RegSaveValue(CString cKey,CString cValue,CString cData)
{
HKEY hKey;
TCHAR szData[260];

	lstrcpy(szData, TEXT(cData));     
	hKey=HKEY_CURRENT_USER;
	if (RegCreateKey(hKey,cKey,&hKey)==ERROR_SUCCESS)
	{
		hKey=HKEY_CURRENT_USER;
		if (RegOpenKey(hKey,cKey,&hKey)==ERROR_SUCCESS)
		{
			RegSetValueEx(hKey,cValue,NULL,1,(LPBYTE)szData,sizeof(szData)+1);
		}
	}
}

CString CNewTrackInstallDlg::RegGetValue(CString cKey,CString cValue)
{
HKEY hKey;
char lpBuffer[260];
int RetVal;
unsigned long lwSize=260;
CString Conv;

	hKey=HKEY_CURRENT_USER;
	if (RegOpenKey(hKey,cKey,&hKey)==ERROR_SUCCESS)
	{
		if (RetVal=RegQueryValueEx(hKey,cValue,NULL,0,(LPBYTE)lpBuffer,&lwSize)==ERROR_SUCCESS)
		{
			Conv=lpBuffer;
			return(Conv);
		}
		else
		{
			return("");
		}
	}
	else
	{
		return("");
	}
}

void CNewTrackInstallDlg::OnAddJam() 
{
TCHAR szFilter[]=_T("Gp2 Jam Files (*.jam)\0*.jam\0All Files (*.*)\0*.*\0\0");
DWORD Max_File=2562;
CString cFile;
CString cFileExt;
POSITION pos;

	UpdateData(TRUE);

	CFileDialog fDialog( TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT | OFN_EXPLORER, NULL, NULL);
	fDialog.m_ofn.lpstrFilter=szFilter;
	fDialog.m_ofn.lpstrInitialDir=m_Gp2Dir;
	fDialog.m_ofn.nMaxFile=Max_File;
    char* pc = new char[Max_File];
    fDialog.m_ofn.lpstrFile = pc;
	fDialog.m_ofn.lpstrFile[0] = NULL;
	int iReturn = fDialog.DoModal();
	if(iReturn ==  IDOK)
	{
		int nCount = 0;
		pos = fDialog.GetStartPosition();
		while (pos!= NULL)
		{
			cFile=fDialog.GetNextPathName(pos);
			m_JamFiles.InsertItem(NULL,cFile,NULL);
		}
	}	
	UpdateData(FALSE);
}

void CNewTrackInstallDlg::OnAddTrack() 
{
TCHAR szFilter[]=_T("Gp2 Track Files (*.dat)\0*.dat\0\0");
CString InitDir;
DWORD Max_File=2562;
CString cFile;
CString cFileExt;
POSITION pos;

	UpdateData(TRUE);

	CFileDialog fDialog( TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT | OFN_EXPLORER, NULL, NULL);
	fDialog.m_ofn.lpstrFilter=szFilter;
	fDialog.m_ofn.lpstrInitialDir=InitDir;
	fDialog.m_ofn.nMaxFile=Max_File;
    char* pc = new char[Max_File];
    fDialog.m_ofn.lpstrFile = pc;
	fDialog.m_ofn.lpstrFile[0] = NULL;
	int iReturn = fDialog.DoModal();
	if(iReturn ==  IDOK)
	{
		int nCount = 0;
		pos = fDialog.GetStartPosition();
		while (pos!= NULL)
		{
			cFile=fDialog.GetNextPathName(pos);
			m_TrackFile.InsertItem(NULL,cFile,NULL);
		}
	}	
	UpdateData(FALSE);	
}

void CNewTrackInstallDlg::OnRemoveAll() 
{
	m_JamFiles.DeleteAllItems();	
}

void CNewTrackInstallDlg::OnRemoveJam() 
{
POSITION pos;
int iRetVal;
	UpdateData(TRUE);
	pos=m_JamFiles.GetFirstSelectedItemPosition();
	iRetVal=m_JamFiles.GetNextSelectedItem(pos);
	m_JamFiles.DeleteItem(iRetVal);
}

void CNewTrackInstallDlg::OnRemoveTrack2() 
{
POSITION pos;
int iRetVal;
	UpdateData(TRUE);
	pos=m_TrackFile.GetFirstSelectedItemPosition();
	iRetVal=m_TrackFile.GetNextSelectedItem(pos);
	m_TrackFile.DeleteItem(iRetVal);	
}

void CNewTrackInstallDlg::OnAddGp2Form() 
{
TCHAR szFilter[]=_T("Gp2Form (*.txt)\0*.txt\0Gp2Form (*.htm)\0*.htm*\0All Files (*.*)\0*.*\0\0");
CString InitDir;
DWORD Max_File=260;

DWORD dwSize;
DWORD dwReadSize;
char *lpBuffer;
HANDLE hFile;

	UpdateData(TRUE);

	CFileDialog fDialog( TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
	fDialog.m_ofn.lpstrFilter=szFilter;
	fDialog.m_ofn.nMaxFile=Max_File;
    char* pc = new char[Max_File];
    fDialog.m_ofn.lpstrFile = pc;
	fDialog.m_ofn.lpstrFile[0] = NULL;
	int iReturn = fDialog.DoModal();
	if(iReturn ==  IDOK)
	{
		//Set path to cGp2FormName
		cGp2FormName=fDialog.GetPathName();
		//Open File and read to show
		hFile = CreateFile((LPCTSTR)fDialog.GetPathName(),
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			(HANDLE)NULL);
		dwSize=GetFileSize(hFile,NULL);
		lpBuffer = (char *)GlobalAlloc( GMEM_FIXED, dwSize );
		ReadFile(hFile,(LPVOID)lpBuffer,dwSize,&dwReadSize,NULL);
		CloseHandle(hFile);
		m_Gp2Form=lpBuffer;
	}	
	UpdateData(FALSE);	
}

void CNewTrackInstallDlg::OnRemoveGp2Form() 
{
	m_Gp2Form="";
	cGp2FormName="";
	UpdateData(FALSE);
}

void CNewTrackInstallDlg::MakeSummary()
{
CString cSummary;
int iCount;
int i;

	cSummary.LoadString(2);
	cSummary+="\r\nGp2Form:";
	cSummary+="\r\n  ";
	cSummary+=cGp2FormName;
	cSummary+="\r\n\r\nTracks:";
	iCount=m_TrackFile.GetItemCount();
	for (i=0;i<iCount;i++)
	{
		cSummary+="\r\n  ";
		cSummary+=m_TrackFile.GetItemText(i,0);
	}
	cSummary+="\r\n\r\nJam Files:";

	iCount=m_JamFiles.GetItemCount();
	for (i=0;i<iCount;i++)
	{
		cSummary+="\r\n  ";
		cSummary+=m_JamFiles.GetItemText(i,0);
	}

	cSummary+="\r\n\r\n---End of Summary---";
	m_Summary=cSummary;
	UpdateData(FALSE);
}

CString CNewTrackInstallDlg::CreateTempDir()
// Overview: Create a temp dir in the system temp dir
{
char szTempDir[260];
char szTempDir2[260];

	GetTempPath(260,szTempDir);
	GetTempFileName((LPCTSTR)szTempDir,"~gp",0,(LPTSTR)szTempDir2);
	DeleteFile((LPCTSTR)szTempDir2);
	CreateDirectory((LPCTSTR)szTempDir2,NULL);
	return(szTempDir2);
}

void CNewTrackInstallDlg::AddFiles()
{
CString szTempDir;
	BeginWaitCursor();

	szTempDir=CreateTempDir();
	//If not end with \\ then add this
	if (szTempDir.Right(1)!="\\")
	{
		szTempDir+="\\";
	}
	//Create setup file
	CopyBinFile();
	//Copy Gp2Form
	CopyGp2Form();
	//Copy Jam Files, Convert them to jad files and add them to setup.exe
	CopyJamFiles(szTempDir);
	//Copy Track Files
	CopyTrackFile();
	//Delete temp dir
	DeleteTempDir(szTempDir);
	EndWaitCursor();
	MessageBox("You setup file was successfully created!","Gp2 Track Setup Wizard",NULL);
}

void CNewTrackInstallDlg::DeleteTempDir(CString cDir)
// Overview: Delete all files in a dir and then delete the dir
{
CString cFile;
WIN32_FIND_DATA wfd;
BOOL fDone = FALSE;
HANDLE hFile;

	if (cDir.Right(1)!="\\")
	{
		cDir+="\\";
	}
	hFile=FindFirstFile(cDir+"*.*",&wfd);
	while(!fDone)
	{
		cFile=wfd.cFileName;
		if (cFile!=".")
		{
			if (cFile!="..")
			{
				cFile=cDir+cFile;
				SetFileAttributes(cFile,FILE_ATTRIBUTE_NORMAL);
				DeleteFile(cFile);
			}
		}
		fDone = !FindNextFile(hFile,&wfd);
    }
	//Remove dir
	_rmdir(cDir);
}

CString CNewTrackInstallDlg::GetFileName(CString cFileName)
{
// Overview: Return file title from a file path
int iPos;

	iPos=cFileName.GetLength();
	for(int i=iPos;i>=1;i--)
	{
		if (cFileName.Mid(i,1)=="\\")
		{
			iPos=cFileName.GetLength()-i;
			cFileName=cFileName.Right(iPos-1);
			break;
		}
	}
	return(cFileName);
}

void CNewTrackInstallDlg::CopyJamFiles(CString cTempDir)
{
int iCount;
int i;
CString cFile;
CString cTarget;
DWORD dwFileSize;
DWORD dwReadSize;
char *lpBuffer;
HANDLE hFile;
byte bNameSize;
int iTemp;

	UpdateData(TRUE);

	CFile fSetup;
	fSetup.Open(m_SetupFile,CFile::modeReadWrite,NULL);
	fSetup.SeekToEnd();
	iCount=m_JamFiles.GetItemCount();
	for (i=0;i<iCount;i++)
	{
		cFile=m_JamFiles.GetItemText(i,0);
		cTarget=cTempDir;
		cTarget+=GetFileName(cFile);
		CopyFile(cFile,cTarget,FALSE);
		//Convert jam to jad
		ConvertFile(cTarget,TRUE);
		//Open and read file
		iTemp=cTarget.GetLength();
		cTarget=cTarget.Left(iTemp-1);
		cTarget+="d";
		hFile = CreateFile((LPCTSTR)cTarget,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			(HANDLE)NULL);

		dwFileSize=GetFileSize(hFile,NULL);
		lpBuffer = (char *)GlobalAlloc( GMEM_FIXED, dwFileSize );
		ReadFile(hFile,(LPVOID)lpBuffer,dwFileSize,&dwReadSize,NULL);
		CloseHandle(hFile);
		//Write jam info to setup file
		fSetup.SeekToEnd();
		iTemp=m_Gp2Dir.GetLength();
		cFile.Delete(0,iTemp);
		bNameSize=cFile.GetLength();
		//Name len
		fSetup.Write((char*)&bNameSize,sizeof(bNameSize));
		fSetup.SeekToEnd();
		//Name
		fSetup.Write(cFile,cFile.GetLength());
		fSetup.SeekToEnd();
		//File Size
		fSetup.Write((char*)&dwFileSize,sizeof(dwFileSize));
		//File
		fSetup.Write(lpBuffer,dwFileSize);
		fSetup.SeekToEnd();
	}
	fSetup.Close();
}

void CNewTrackInstallDlg::CopyTrackFile()
{
int iCount;
int i;
CString cFile;
CString cTarget;
DWORD dwFileSize;
DWORD dwReadSize;
char *lpBuffer;
HANDLE hFile;
byte bNameSize;

	UpdateData(TRUE);

	CFile fSetup;
	fSetup.Open(m_SetupFile,CFile::modeReadWrite,NULL);
	fSetup.SeekToEnd();
	iCount=m_TrackFile.GetItemCount();
	for (i=0;i<iCount;i++)
	{
		cFile=m_TrackFile.GetItemText(i,0);
		//Open and read file
		hFile = CreateFile((LPCTSTR)cFile,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			(HANDLE)NULL);

		dwFileSize=GetFileSize(hFile,NULL);
		lpBuffer = (char *)GlobalAlloc( GMEM_FIXED, dwFileSize );
		ReadFile(hFile,(LPVOID)lpBuffer,dwFileSize,&dwReadSize,NULL);
		CloseHandle(hFile);
		//Write track file info to setup file
		cFile=GetFileName(cFile);
		bNameSize=cFile.GetLength();
		//Name len
		fSetup.Write((char*)&bNameSize,sizeof(bNameSize));
		fSetup.SeekToEnd();
		//Name
		fSetup.Write(cFile,cFile.GetLength());
		fSetup.SeekToEnd();
		//File Size
		fSetup.Write((char*)&dwFileSize,sizeof(dwFileSize));
		//File
		fSetup.Write(lpBuffer,dwFileSize);
		fSetup.SeekToEnd();
	}
	fSetup.Close();
}

void CNewTrackInstallDlg::CopyGp2Form()
{
CString cFile;
CString cTarget;
DWORD dwFileSize;
DWORD dwReadSize;
char *lpBuffer;
HANDLE hFile;
byte bNameSize;
DWORD dwCount;

	UpdateData(TRUE);

	//Count nr of files
	dwCount=m_JamFiles.GetItemCount();
	dwCount+=m_TrackFile.GetItemCount();
	CFile fSetup;
	fSetup.Open(m_SetupFile,CFile::modeReadWrite,NULL);
	fSetup.SeekToEnd();
	cFile=cGp2FormName;
	if (cFile!="")
	{
		//Add 1 to dwCount
		dwCount+=1;
		//If it's a Gp2Form then set first byte to 1
		bNameSize=1;
		fSetup.Write((char*)&dwCount,sizeof(dwCount));
		fSetup.Write((char*)&bNameSize,sizeof(bNameSize));
		fSetup.SeekToEnd();
		//Open and read file
		hFile = CreateFile((LPCTSTR)cFile,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			(HANDLE)NULL);
		dwFileSize=GetFileSize(hFile,NULL);
		lpBuffer = (char *)GlobalAlloc( GMEM_FIXED, dwFileSize );
		ReadFile(hFile,(LPVOID)lpBuffer,dwFileSize,&dwReadSize,NULL);
		CloseHandle(hFile);
		//Write gp2form info to setup file
		cFile=GetFileName(cFile);
		bNameSize=cFile.GetLength();
		//Name len
		fSetup.Write((char*)&bNameSize,sizeof(bNameSize));
		fSetup.SeekToEnd();
		//Name
		fSetup.Write(cFile,cFile.GetLength());
		fSetup.SeekToEnd();
		//File Size
		fSetup.Write((char*)&dwFileSize,sizeof(dwFileSize));
		//File
		fSetup.Write(lpBuffer,dwFileSize);
		fSetup.SeekToEnd();
	}
	else
	{
		//If it's no Gp2Form then set first byte to 0 and write dwCount 
		bNameSize=0;
		fSetup.Write((char*)&dwCount,sizeof(dwCount));
		fSetup.Write((char*)&bNameSize,sizeof(bNameSize));
	}
	fSetup.Close();
}

void CNewTrackInstallDlg::CopyBinFile()
{
CString cTemp;
int iTemp;
int iTemp2;
CString cFileName;
char szModule[260];
	GetModuleFileName(NULL,szModule,260);
	cFileName=szModule;
	cTemp=GetFileName(cFileName);
	iTemp=cTemp.GetLength();
	iTemp2=cFileName.GetLength();
	iTemp=iTemp2-iTemp;
	cFileName=cFileName.Left(iTemp);
	cFileName+="Win32.bin";
	CopyFile(cFileName,m_SetupFile,FALSE);
}

void CNewTrackInstallDlg::OnFileExit() 
{
	OnCancel();	
}

void CNewTrackInstallDlg::OnHelpAbout() 
{
	CAbout dlg;
	dlg.DoModal();
}
