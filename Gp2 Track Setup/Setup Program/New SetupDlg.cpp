// New SetupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "New Setup.h"
#include "New SetupDlg.h"
#include "Quit.h"
#include "direct.h"
#include "TrackPos.h"

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
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewSetupDlg dialog

CNewSetupDlg::CNewSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewSetupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewSetupDlg)
	m_Path = _T("");
	m_Custom = -1;
	m_Typical = -1;
	m_FullInstall = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNewSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewSetupDlg)
	DDX_Control(pDX, IDC_PathFrame, m_PathFrame);
	DDX_Control(pDX, IDC_Next, m_Next);
	DDX_Text(pDX, IDC_Dir, m_Path);
	DDX_Radio(pDX, IDC_Custom, m_Custom);
	DDX_Radio(pDX, IDC_Typical, m_Typical);
	DDX_Radio(pDX, IDC_FullInstall, m_FullInstall);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNewSetupDlg, CDialog)
	//{{AFX_MSG_MAP(CNewSetupDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Exit, OnExit)
	ON_BN_CLICKED(IDC_Next, OnNext)
	ON_BN_CLICKED(IDC_Back, OnBack)
	ON_BN_CLICKED(IDC_Typical, OnTypical)
	ON_BN_CLICKED(IDC_Custom, OnCustom)
	ON_BN_CLICKED(IDC_Browse, OnBrowse)
	ON_BN_CLICKED(IDC_View, OnView)
	ON_BN_CLICKED(IDC_FullInstall, OnFullInstall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewSetupDlg message handlers

BOOL CNewSetupDlg::OnInitDialog()
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
	iCurPos=1;
	Show1(TRUE);
	m_Custom=1;
	m_Typical=1;
	m_FullInstall=0;
	m_PathFrame.SetWindowText("Gp2 Directory");
	GetModuleFileName(NULL,szModule,260);
	//Check if a gp2form is in the setup file
	GetDlgItem(IDC_View)->EnableWindow(CheckGp2Form());

	m_Path=RegGetValue("Software\\VG Software\\Gp2 Track Setup","Gp2Path");
	m_Gp2Dir=m_Path;
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNewSetupDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNewSetupDlg::OnPaint() 
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
HCURSOR CNewSetupDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CNewSetupDlg::OnExit() 
{
int iRetVal;
	//ask user to confirm exit
	CQuit dlg;
	iRetVal=dlg.DoModal();
	if (iRetVal == IDOK)
	{
		OnOK();
	}
}

void CNewSetupDlg::OnNext() 
{	
	iCurPos+=1;	
	if (iCurPos==2)
	{
		Show1(FALSE);
		Show2(TRUE);
	}
	else if (iCurPos==3)
	{
		if (m_Path!="")
		{
			if (m_Custom==0)
			{
				m_ExtDir=m_Path;
			}
			else if (m_Typical==0)
			{
				m_Gp2Dir=m_Path;
				RegSaveValue("Software\\VG Software\\Gp2 Track Setup","Gp2Path",m_Path);
			}			
			iCurPos-=1;
			UnPackFiles();
		}
		else
		{
			if (m_Custom==1)
			{
				MessageBox("You must select your Gp2 directory","Gp2 Track Setup",NULL);
			}
			else
			{
				MessageBox("You must select a target directory","Gp2 Track Setup",NULL);
			}
		}
		
	}
}

void CNewSetupDlg::OnBack() 
{
	iCurPos-=1;
	if (iCurPos==1)
	{
		Show2(FALSE);
		Show1(TRUE);
	}
	else
	{
		iCurPos+=1;
	}
}

void CNewSetupDlg::Show1(bool Show)
{
	if (Show==TRUE)
	{
		GetDlgItem(IDC_Back)->EnableWindow(FALSE);
		GetDlgItem(IDC_Welcome)->ShowWindow(TRUE);
		GetDlgItem(IDC_MainIcon)->ShowWindow(TRUE);
		GetDlgItem(IDC_View)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_Back)->EnableWindow(TRUE);
		GetDlgItem(IDC_Welcome)->ShowWindow(FALSE);
		GetDlgItem(IDC_MainIcon)->ShowWindow(FALSE);
		GetDlgItem(IDC_View)->ShowWindow(FALSE);
	}
}

void CNewSetupDlg::Show2(bool Show)
{
	if (Show==TRUE)
	{
		GetDlgItem(IDC_TypeOfSetup)->ShowWindow(TRUE);
		GetDlgItem(IDC_TypicalText)->ShowWindow(TRUE);
		GetDlgItem(IDC_Typical)->ShowWindow(TRUE);
		GetDlgItem(IDC_Custom)->ShowWindow(TRUE);
		GetDlgItem(IDC_CustomText)->ShowWindow(TRUE);
		GetDlgItem(IDC_PathFrame)->ShowWindow(TRUE);
		GetDlgItem(IDC_Dir)->ShowWindow(TRUE);
		GetDlgItem(IDC_Browse)->ShowWindow(TRUE);
		GetDlgItem(IDC_Full)->ShowWindow(TRUE);
		GetDlgItem(IDC_FullInstall)->ShowWindow(TRUE);
		m_Next.SetWindowText("Finish!");
	}
	else
	{
		GetDlgItem(IDC_TypeOfSetup)->ShowWindow(FALSE);
		GetDlgItem(IDC_TypicalText)->ShowWindow(FALSE);
		GetDlgItem(IDC_Typical)->ShowWindow(FALSE);
		GetDlgItem(IDC_Custom)->ShowWindow(FALSE);
		GetDlgItem(IDC_CustomText)->ShowWindow(FALSE);
		GetDlgItem(IDC_PathFrame)->ShowWindow(FALSE);
		GetDlgItem(IDC_Dir)->ShowWindow(FALSE);
		GetDlgItem(IDC_Browse)->ShowWindow(FALSE);
		GetDlgItem(IDC_Full)->ShowWindow(FALSE);
		GetDlgItem(IDC_FullInstall)->ShowWindow(FALSE);
		m_Next.SetWindowText("Next >");
	}
}

void CNewSetupDlg::OnTypical() 
{
	UpdateData(TRUE);
	if (m_Custom==0)
	{
		m_ExtDir=m_Path;
	}
	m_PathFrame.SetWindowText("Gp2 Directory");	
	m_Path=m_Gp2Dir;
	m_Custom=1;
	m_FullInstall=1;
	m_Typical=0;
	UpdateData(FALSE);
	m_Next.SetWindowText("Finish!");
}

void CNewSetupDlg::OnCustom() 
{
	UpdateData(TRUE);
	m_Gp2Dir=m_Path;
	m_PathFrame.SetWindowText("Target Directory");	
	m_Path=m_ExtDir;
	m_Custom=0;
	m_FullInstall=1;
	m_Typical=1;
	UpdateData(FALSE);
	m_Next.SetWindowText("Finish!");
}

void CNewSetupDlg::OnFullInstall() 
{
	UpdateData(TRUE);
	if (m_Custom==0)
	{
		m_ExtDir=m_Path;
	}
	m_PathFrame.SetWindowText("Gp2 Directory");	
	m_Path=m_Gp2Dir;
	m_Custom=1;
	m_Typical=1;
	m_FullInstall=0;
	UpdateData(FALSE);
	m_Next.SetWindowText("Next >");
}

void CNewSetupDlg::OnBrowse() 
{
CString cTitle;
	if (m_Custom==1)
	{
		cTitle="Select Gp2 Directory";
	}
	else
	{
		cTitle="Select Target Directory";
	}

	cTitle=BrowseForFolders(cTitle);
	if (cTitle!="")
	{
		m_Path=cTitle;
	}
	UpdateData(FALSE);
}

bool CNewSetupDlg::CheckGp2Form()
// Overview: Check if a Gp2Form was added to the setup file
{
byte bCheck;
	CFile fSetup;
	//Use this one in finale verison!
	fSetup.Open(szModule,CFile::shareDenyNone,NULL);
	//fSetup.Open("c:\\my documents\\setup.exe",CFile::shareDenyNone,NULL);
	//Set 4 to empty setup file size
	//fSetup.Seek(4,CFile::begin);
	fSetup.Seek(36868,CFile::begin);
	fSetup.Read((char*)&bCheck,sizeof(bCheck));
	fSetup.Close();
	if (bCheck==1)
	{
		return(TRUE);
	}
	else
	{
		return(FALSE);
	}
}

void CNewSetupDlg::ShowGp2Form()
{
DWORD dwFileSize;
char *lpBuffer;
byte bNameSize;
CString cTempDir;
CString cFileName;
	cTempDir=CreateTempDir();
	cTempDir+="\\";
	CFile fSetup;
	//Use this one in finale verison!
	fSetup.Open(szModule,CFile::shareDenyNone,NULL);
	//fSetup.Open("c:\\my documents\\setup.exe",CFile::shareDenyNone,NULL);
	//Set 5 to empty setup file size+5
	//fSetup.Seek(5,CFile::begin);
	fSetup.Seek(36869,CFile::begin);
	fSetup.Read((char*)&bNameSize,sizeof(bNameSize));

	lpBuffer = (char*)GlobalAlloc(GMEM_FIXED, bNameSize);
	
	fSetup.Read(lpBuffer,bNameSize);
	cFileName=lpBuffer;
	cFileName=cFileName.Left(bNameSize);
	fSetup.Read((char*)&dwFileSize,sizeof(dwFileSize));
	lpBuffer=(char*)GlobalAlloc(GMEM_FIXED, dwFileSize);
	fSetup.Read(lpBuffer,dwFileSize);

	cFileName.Insert(0,cTempDir);
	CFile fGp2Form;
	fGp2Form.Open(cFileName,CFile::modeReadWrite | CFile::modeCreate,NULL);
	fGp2Form.Write(lpBuffer,dwFileSize);
	fGp2Form.Close();
	fSetup.Close();
	ShellExecute(m_hWnd,"open",cFileName,"","",1);
	Sleep(1000);
	DeleteTempDir(cTempDir);
}

CString CNewSetupDlg::CreateTempDir()
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

CString CNewSetupDlg::GetFileName(CString cFileName)
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

void CNewSetupDlg::DeleteTempDir(CString cDir)
{
// Overview: Delete all files in a dir and then delete the dir
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

void CNewSetupDlg::OnView() 
{
	ShowGp2Form();
}

void CNewSetupDlg::ConvertFile(CString cFileName,bool bDelete)
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
		//If jad file then new file will be jam file :)
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

void CNewSetupDlg::UnPackFiles()
{
CString cDestDir;
DWORD dwFiles;
DWORD dwFileSize;
char *lpBuffer;
byte bNameSize;
int i;
CStringArray caArray;
CString cFileName;
int iTemp;
CString cTempFileName;
CString cMsg;
CString cTrackDir;
bool bGp2Form;

	BeginWaitCursor();
	UpdateData(TRUE);
	//Create temp dir if install to gp2 else no temp dir
	if (m_Custom==0)
	{
		cDestDir=m_Path;
	}
	else if (m_Typical==0)
	{
		cDestDir=CreateTempDir();
	}
	//check if cDestDir ends with \\ else add this
	if (cDestDir.Right(1)!="\\")
	{
		cDestDir+="\\";
	}
	CFile fSetup;
	
	//Use this in final version!
	fSetup.Open(szModule,CFile::shareDenyNone,NULL);
	//fSetup.Open("C:\\my documents\\setup.exe",CFile::shareDenyNone,NULL);
	//Change 0 to filesize of setup!
	//fSetup.Seek(0,CFile::begin);
	fSetup.Seek(36864,CFile::begin);
	//Get nr of files
	fSetup.Read((char*)&dwFiles,sizeof(dwFiles));
	//Change 5 to filesize+5 of setup
	//fSetup.Seek(5,CFile::begin);
	fSetup.Seek(36869,CFile::begin);

	//loop once for every file
	//This will extract all files and convert jad files to jam files!
	for (i=0;i<dwFiles;i++)
	{
		//Get name len
		fSetup.Read((char*)&bNameSize,sizeof(bNameSize));
		//Set buffer to name len
		lpBuffer=(char*)GlobalAlloc(GMEM_FIXED,bNameSize);
		//read name
		fSetup.Read(lpBuffer,bNameSize);
		//set cFileName to file name
		cFileName=lpBuffer;
		cFileName=cFileName.Left(bNameSize);
		cFileName.MakeLower();
		//add path and filename to caArray
		caArray.Add(cFileName);
		//Remove path and save file name
		cFileName=GetFileName(cFileName);
		//Check if it's a jam file
		if (cFileName.Right(3)=="jam")
		{
			iTemp=cFileName.GetLength();
			cFileName.Delete(iTemp-1,1);
			cFileName+="d";
		}
		fSetup.Read((char*)&dwFileSize,sizeof(dwFileSize));
		lpBuffer=(char*)GlobalAlloc(GMEM_FIXED,dwFileSize);
		fSetup.Read(lpBuffer,dwFileSize);
		CFile fNewFile;
		cFileName.Insert(0,cDestDir);
		fNewFile.Open(cFileName,CFile::modeCreate| CFile::modeReadWrite,NULL);
		fNewFile.Write(lpBuffer,dwFileSize);
		fNewFile.Close();
		if (cFileName.Right(3)=="jad")
		{
			ConvertFile(cFileName,TRUE);
		}
	}
	//If Typical is selected then move on to this!
	if (m_Typical==0)
	{
		iTemp=caArray.GetUpperBound();
		iTemp+=1;
		for (i=0;i<iTemp;i++)
		{
			cFileName=caArray.GetAt(i);
			cFileName.MakeLower();
			if (cFileName.Right(3)=="jam")
			{
				CreateDir(cFileName);
				Sleep(10);
				cTempFileName=GetFileName(cFileName);
				cTempFileName.Insert(0,cDestDir);
				cFileName.Insert(0,m_Gp2Dir);
				
				if (!CopyFile(cTempFileName, cFileName, TRUE)) 
				{
					cMsg="File ";
					cMsg+=cFileName;
					cMsg+=" already exists, overwrite this file?";
					if (MessageBox(cMsg,"Gp2 Track Setup",MB_ICONEXCLAMATION | MB_YESNO)==IDYES)
					{
						CopyFile(cTempFileName, cFileName, FALSE);
					}
				}
			}
			else
			{
				cFileName=caArray.GetAt(i);
				if (cTrackDir=="")
				{
					do{
						MessageBox("Please select a directory where you want to place the track and gp2form files to.","Gp2 Track Setup",MB_OK);
						cTrackDir=BrowseForFolders("Select Track Dir");
					}while(cTrackDir=="");
				}
				cFileName=GetFileName(cFileName);
				cTempFileName=cFileName;
				cTempFileName.Insert(0,cDestDir);
				cFileName.Insert(0,"\\");
				cFileName.Insert(0,cTrackDir);
				if (!CopyFile(cTempFileName,cFileName,TRUE))
				{
					cMsg="File: ";
					cMsg+=cFileName;
					cMsg+=" already exists, overwrite this file?";
					if (MessageBox(cMsg,"Gp2 Track Setup",MB_ICONEXCLAMATION | MB_YESNO)==IDYES)
					{
						CopyFile(cTempFileName,cFileName,FALSE);
					}

				}
			}
		}
		DeleteTempDir(cDestDir);
	}

	EndWaitCursor();
	MessageBox("The files have been successfully extracted!","Gp2 Track Setup",NULL);
	bGp2Form=CheckGp2Form();
	if (bGp2Form==TRUE)
	{
		ShowGp2Form();
	}
	OnOK();
}

void CNewSetupDlg::CreateDir(CString cDir)
{
CString cNewDir;
int i;
int iCount;
	UpdateData(TRUE);
	iCount=cDir.GetLength();
	for (i=0;i<iCount;i++)
	{
		if (cDir.Mid(i,1)=="\\")
		{
			cNewDir=m_Gp2Dir;
			cNewDir+=cDir.Mid(0,i);
			CreateDirectory(cNewDir,NULL);
		}
	}
}

CString CNewSetupDlg::BrowseForFolders(CString cTitle)
{
char Path[260];
//Browse for folders
BROWSEINFO bff;
LPITEMIDLIST pidl;
CString cTemp;

bff.hwndOwner		=m_hWnd;
bff.iImage			=0;
bff.lParam			=0;
bff.lpszTitle		=cTitle;
bff.pidlRoot		=NULL;
bff.ulFlags			=BIF_RETURNONLYFSDIRS;
bff.pszDisplayName	=Path;
bff.lpfn			=NULL;

	pidl=SHBrowseForFolder(&bff);
	if (pidl)
	{
		SHGetPathFromIDList(pidl,Path);
		cTemp=Path;
		return(cTemp);
	}
	else
	{
		return("");
	}
	
}

void CNewSetupDlg::RegSaveValue(CString cKey,CString cValue,CString cData)
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

CString CNewSetupDlg::RegGetValue(CString cKey,CString cValue)
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

//WRITE DATA TO GP2.EXE CODE ---- NEW 2000-01-25 - 52-10-0002 WEN ---- EDOC EXE.2PG OT ATAD ETIRW

void CNewSetupDlg::AddTrackData(int iPos)
{
CString cVer;
CString Gp2File;


	UpdateData(TRUE);
	Gp2File=m_Gp2Dir;
	if (Gp2File.Right(1)!="\\")
	{
		Gp2File+="\\";
	}
	Gp2File+="Gp2.exe";

	cVer=GetGp2Version(Gp2File);

	if (cVer=="")
	{
		MessageBox("Error when installing track!","Gp2 Track Setup",NULL);
	}
	else if (cVer=="UK")
	{
		iLen=1953837;
		iText=5682444;
		iLaps=1951848;
	}
	else if (cVer=="US")
	{
		iLen=1953837;
		iText=5682443;
		iLaps=1951848;
	}
	else if (cVer=="IT")
	{
		iLen=1953889;
		iText=5685990;
		iLaps=1951900;
	}
	else if (cVer=="NL")
	{
		iLen=1953885;
		iText=5684785;
		iLaps=1951896;
	}
	else if (cVer=="DE")
	{
		iLen=1953949;
		iText=5686489;
		iLaps=1951960;
	}
	else if (cVer=="SP")
	{
		iLen=1953921;
		iText=5687336;
		iLaps=1951932;
	}
	else if (cVer=="FR")
	{
		iLen=1953885;
		iText=5686682;
		iLaps=1951896;
	}
	if (cVer!="")
	{
		//Load Text to array's
		GetGp2Text(Gp2File);
		//Write text to Gp2.exe
		WriteGp2Text(Gp2File);
		//Write Laps
		WriteLaps(Gp2File,iPos);
		//Write len
		WriteLen(Gp2File,iPos);
	}
}

void CNewSetupDlg::GetGp2Text(CString Gp2File)
{
char lpBuffer[50];
int iLen;
CString cTemp;
int iPos;
int iCountry;
int i;

	CFile fGp2;
	fGp2.Open(Gp2File,CFile::modeRead,NULL);
	iPos=iText;
	iLen=0;
	for (i=1;i<17;i++)
	{
		fGp2.Seek(iPos,CFile::begin);
		fGp2.Read(lpBuffer,50);
		cTemp=lpBuffer;
		caTracks.Add(cTemp);
		iLen+=cTemp.GetLength()+1;
		iPos=iText+iLen;
	}

	iCountry=iText+iLen+16;
	iPos=iCountry;
	iLen=0;
	for (i=1;i<17;i++)
	{
		fGp2.Seek(iPos,CFile::begin);
		fGp2.Read(lpBuffer,50);
		cTemp=lpBuffer;
		caCountry.Add(cTemp);
		iLen+=cTemp.GetLength()+1;
		iPos=iCountry+iLen;
	}

	for (int ii=0;ii<4;ii++)
	{
		iCountry=iPos+16;
		iPos=iCountry;
		cTemp="";
		iLen=0;
		for (i=1;i<17;i++)
		{
			fGp2.Seek(iPos,CFile::begin);
			fGp2.Read(lpBuffer,50);
			cTemp+="\r\n";
			cTemp+=lpBuffer;
			iLen=cTemp.GetLength()-i;
			iPos=iCountry+iLen;
		}
	}

	iCountry=iPos+16;
	iPos=iCountry;
	iLen=0;
	for (i=1;i<17;i++)
	{
		fGp2.Seek(iPos,CFile::begin);
		fGp2.Read(lpBuffer,50);
		cTemp=lpBuffer;
		caAdjective.Add(cTemp);
		iLen+=cTemp.GetLength()+1;
		iPos=iCountry+iLen;
	}
	fGp2.Close();
}

CString CNewSetupDlg::GetGp2Version(CString Gp2File)
//Get Gp2 Version
{
char Read[5];
CString cCheck;
CString cVer;
	CFile fGp2;
	fGp2.Open(Gp2File,CFile::modeRead,NULL);
	//US Version
	fGp2.Seek(5671741,CFile::begin);
	fGp2.Read(Read,5);
	cCheck=Read;
	cCheck=cCheck.Left(5);
	if (cCheck=="US En")
	{
		cVer="US";
	}
	//UK Version
	fGp2.Seek(5671742,CFile::begin);
	fGp2.Read(Read,5);
	cCheck=Read;
	cCheck=cCheck.Left(5);
	if (cCheck=="UK En")
	{
		cVer="UK";
	}
	//Dutch Version
	fGp2.Seek(5673613,CFile::begin);
	fGp2.Read(Read,5);
	cCheck=Read;
	cCheck=cCheck.Left(5);
	if (cCheck=="Neder")
	{
		cVer="NL";
	}
	//Spanish Version
	fGp2.Seek(5675457,CFile::begin);
	fGp2.Read(Read,5);
	cCheck=Read;
	cCheck=cCheck.Left(5);
	if (cCheck=="Versi")
	{
		cVer="SP";
	}
	//French Version
	fGp2.Seek(5674989,CFile::begin);
	fGp2.Read(Read,5);
	cCheck=Read;
	cCheck=cCheck.Left(5);
	if (cCheck=="Versi")
	{
		cVer="FR";
	}
	//Italian Version
	fGp2.Seek(5674330,CFile::begin);
	fGp2.Read(Read,5);
	cCheck=Read;
	cCheck=cCheck.Left(5);
	if (cCheck=="Versi")
	{
		cVer="IT";
	}
	//Italian Version
	fGp2.Seek(5674543,CFile::begin);
	fGp2.Read(Read,5);
	cCheck=Read;
	cCheck=cCheck.Left(5);
	if (cCheck=="Deuts")
	{
		cVer="DE";
	}
	fGp2.Close();
	return(cVer);
}

void CNewSetupDlg::WriteGp2Text(CString Gp2File)
//Write text to Gp2.exe
{
CString cTemp;
int i;
char Space[16]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

	CFile fGp2;
	fGp2.Open(Gp2File,CFile::modeWrite,NULL);
	for (i=0;i<16;i++)
	{
		cTemp=caTracks.GetAt(i);
		fGp2.Write(cTemp,cTemp.GetLength()+1);
	}
	fGp2.Write(Space,16);
	for (int k=0;k<5;k++)
	{
		for (i=0;i<16;i++)
		{
			cTemp=caCountry.GetAt(i);
			fGp2.Write(cTemp,cTemp.GetLength()+1);
		}
		fGp2.Write(Space,16);
	}
	for (i=0;i<16;i++)
	{
		cTemp=caAdjective.GetAt(i);
		fGp2.Write(cTemp,cTemp.GetLength()+1);
	}
	fGp2.Write(Space,16);
}

void CNewSetupDlg::WriteLaps(CString Gp2File, int iPos)
//Write laps to Gp2.exe
{
	CFile fGp2;
	fGp2.Open(Gp2File,CFile::modeWrite,NULL);
	fGp2.Seek(iLaps+iPos,CFile::begin);
	fGp2.Write((char*)&bNewLaps,sizeof(bNewLaps));
	fGp2.Close();
}

void CNewSetupDlg::WriteLen(CString Gp2File, int iPos)
//Write track len to Gp2.exe
{
int iTempPos;

	CFile fGp2;
	fGp2.Open(Gp2File,CFile::modeWrite,NULL);
	iNewLen=iNewLen * 3.28212677519917;
	iTempPos=iLen;
	iTempPos=iTempPos+(iPos*7);
	fGp2.Seek(iTempPos,CFile::begin);
	fGp2.Write((char*)&iNewLen,sizeof(iNewLen));
	fGp2.Close();
}
