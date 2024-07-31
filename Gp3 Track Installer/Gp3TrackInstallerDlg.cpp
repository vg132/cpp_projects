// Gp3TrackInstallerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Gp3TrackInstaller.h"
#include "Gp3TrackInstallerDlg.h"
#include "InfoZip/InfoZip.h"

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
	CBannerStatic	m_Credits;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
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
	DDX_Control(pDX, IDC_STATIC_CREDITS, m_Credits);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGp3TrackInstallerDlg dialog

CGp3TrackInstallerDlg::CGp3TrackInstallerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGp3TrackInstallerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGp3TrackInstallerDlg)
	m_bTrackDir = FALSE;
	m_TrackFile = _T("-[ No Track File ]-");
	m_Gp32kPath = _T("");
	m_Gp3Path = _T("");
	m_TrackDir = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGp3TrackInstallerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGp3TrackInstallerDlg)
	DDX_Check(pDX, IDC_CHECK_TRACKDIR_ENABLE, m_bTrackDir);
	DDX_Text(pDX, IDC_STATIC_TRACK_FILE, m_TrackFile);
	DDX_Text(pDX, IDC_EDIT_GP32KPATH, m_Gp32kPath);
	DDX_Text(pDX, IDC_EDIT_GP3PATH, m_Gp3Path);
	DDX_Text(pDX, IDC_EDIT_GP3TRACKDIR, m_TrackDir);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGp3TrackInstallerDlg, CDialog)
	//{{AFX_MSG_MAP(CGp3TrackInstallerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GP3_BROWSE, OnButtonGp3Browse)
	ON_BN_CLICKED(IDC_BUTTON_GP32K_BROWSE, OnButtonGp32kBrowse)
	ON_BN_CLICKED(IDC_BUTTON_INSTALL_GP3, OnButtonInstallGp3)
	ON_BN_CLICKED(IDC_BUTTON_INSTALL_GP32K, OnButtonInstallGp32k)
	ON_BN_CLICKED(IDC_BUTTON_INSTALL_BOTH, OnButtonInstallBoth)
	ON_BN_CLICKED(IDC_BUTTON_TRACKDIR_BROWSE, OnButtonTrackdirBrowse)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHECK_TRACKDIR_ENABLE, OnCheckTrackdirEnable)
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_HELP_HELP, OnHelpHelp)
	ON_COMMAND(ID_HELP_ONLINE, OnHelpOnline)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	ON_COMMAND(ID_FILE_SETTINGS, OnFileSettings)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGp3TrackInstallerDlg message handlers

BOOL CGp3TrackInstallerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_pExtractDirectory=NULL;

	m_Log.SetFileName("Gp3ti.log");
	m_Log.m_strAppName="Gp3 Track Installer v1.0 Release";
	m_Log.OnStartup(TRUE,TRUE);
	m_Log.ResetFile();
	m_Log.WriteLine("%s",m_Log.m_strAppName);
	// Read data from the registry

	LoadSettings();
	OnCheckTrackdirEnable();

	if(m_pGp3TrackFile==NULL)
	{
		OnFileClose();
		m_Log.WriteLine("No track file found in command line");
	}
	else
	{
		EnableInstall(true);
		EnableTrackDir(m_bTrackDir);
		SetDlgItemText(IDC_STATIC_TRACK_FILE,m_pGp3TrackFile);
		CMenu* menu;
		menu=this->GetMenu();
		menu->EnableMenuItem(ID_FILE_CLOSE,MF_ENABLED);
		ShowGp3Info();
		m_Log.WriteLine("Track file found in command line, %s",m_pGp3TrackFile);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGp3TrackInstallerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGp3TrackInstallerDlg::OnPaint() 
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
HCURSOR CGp3TrackInstallerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/**
 * Find the pos where the jam table starts
 */
int CGp3TrackInstallerDlg::GetJamStart(CFile* pFile)
{
	//Check if the file is missing #GP3INFO section
	char* pData;
	pData=new char[5];
	pData[4]='\0';
	pFile->Seek(-9,CFile::end);
	pFile->Read(pData,4);
	m_Log.WriteLine("GetJamStart(%s)",pFile->GetFileName());
	if(strcmp(pData,".jam"))
	{
		delete[] pData;
		pData=new char[9];
		pData[8]='\0';
		//Seek until we find the start of the Gp3Info data block
		while(pFile->GetPosition()>pFile->GetLength()-2000&&strcmp(pData,"#GP3INFO"))
		{
			pFile->Seek(-9,CFile::current);
			pFile->Read(pData,8);
		}
		pFile->Seek(-9,CFile::current);
	}
	//Only enter if GP3info was found or original track file
	if(!strcmp(pData,".jam")||!strcmp(pData,"#GP3INFO"))
	{
		delete[] pData;
		pData=new char[3];
		pData[2]='\0';
		while(pFile->GetPosition()>pFile->GetLength()-5000&&strcmp(pData,"\14\15"))
		{
			pFile->Seek(-3,CFile::current);
			pFile->Read(pData,2);
		}
		pFile->Seek(2,CFile::current);
		if(!strcmp(pData,"\14\15"))
		{
			delete[] pData;
			return(pFile->GetPosition());
		}
		else
		{
			delete[] pData;
			return(-1);
		}
	}
	else
	{
		m_Log.WriteLine("GetJamStart(): No Jamstart found");
		delete[] pData;
		return(-1);
	}
}

/**
 * Read the jam table and put them in a list
 */
bool CGp3TrackInstallerDlg::ReadJamTable(CFile *pFile, int iJamStart)
{
	if(iJamStart!=-1)
	{
		m_Log.WriteLine("ReadJamTable(%s)",pFile->GetFileName());
		short int Jams(0);
		short int Pos(0);
		char* pData;
		char* pJamFile;
		pFile->Seek(iJamStart,CFile::begin);
		pFile->Read((char*)&Jams,sizeof(Jams));
		pData=new char[(pFile->GetLength()-iJamStart-4)];
		pFile->Read(pData,(pFile->GetLength()-iJamStart-4));

		for(int i=0;i<Jams;i++)
		{
			pJamFile=new char[strlen(&pData[Pos])+1];
			strcpy(pJamFile,&pData[Pos]);
			m_JamList.Add(pJamFile);
			Pos+=strlen(&pData[Pos])+1;
		}
		delete[] pData;
		return(true);
	}
	else
		return(false);
}

void CGp3TrackInstallerDlg::OnButtonGp3Browse() 
{
	char* path;
	path = BrowseForFolders("Select your Gp3 directory");
	if(path!=NULL)
	{
		m_Gp3Path=path;
		delete[] path;
		m_Log.WriteLine("New Gp3 directory selected, %s",m_Gp3Path);
		UpdateData(FALSE);
	}
}

void CGp3TrackInstallerDlg::OnButtonGp32kBrowse() 
{
	char* path;
	path = BrowseForFolders("Select your Gp3 2000 directory");
	if(path!=NULL)
	{
		m_Gp32kPath=path;
		delete[] path;
		m_Log.WriteLine("New Gp3-2000 directory selected, %s",m_Gp32kPath);
		UpdateData(FALSE);
	}
}

void CGp3TrackInstallerDlg::OnButtonTrackdirBrowse() 
{
	char* path;
	path = BrowseForFolders("Select your Gp3 track directory");
	if(path!=NULL)
	{
		m_TrackDir=path;
		delete[] path;
		m_Log.WriteLine("New track directory selected, %s",m_TrackDir);
		UpdateData(FALSE);
	}
}

void CGp3TrackInstallerDlg::OnButtonInstallGp3() 
{
	BeginWaitCursor();
	UpdateData(TRUE);
	if((m_Gp3Path!="")&&(FileExists(m_Gp3Path)==true))
	{
		if(m_Gp3Path.Right(1)!='\\')
			m_Gp3Path+="\\";
		InstallJams(m_Gp3Path);
		if(m_bTrackDir==TRUE)
			CopyTrack();
	}
	else
	{
		MessageBox(m_Language.GetText(m_Language.NO_GP3_DIRECTORY));
	}
	EndWaitCursor();
}

void CGp3TrackInstallerDlg::OnButtonInstallGp32k() 
{
	BeginWaitCursor();
	UpdateData(TRUE);
	if((m_Gp32kPath!="")&&(FileExists(m_Gp32kPath)==true))
	{
		if(m_Gp32kPath.Right(1)!='\\')
			m_Gp32kPath+="\\";
		InstallJams(m_Gp32kPath);
		if(m_bTrackDir==TRUE)
			CopyTrack();
	}
	else
	{
		MessageBox(m_Language.GetText(m_Language.NO_GP3_2000_DIRECTORY));
	}
	EndWaitCursor();
}

void CGp3TrackInstallerDlg::OnButtonInstallBoth() 
{
	BeginWaitCursor();
	UpdateData(TRUE);
	if((m_Gp32kPath!="")&&(m_Gp3Path!="")&&(FileExists(m_Gp3Path)==true)&&(FileExists(m_Gp32kPath)==true))
	{
		if(m_Gp32kPath.Right(1)!='\\')
			m_Gp32kPath+="\\";
		if(m_Gp3Path.Right(1)!='\\')
			m_Gp3Path+="\\";
		InstallJams(m_Gp3Path);
		InstallJams(m_Gp32kPath);
		if(m_bTrackDir==TRUE)
			CopyTrack();
	}
	else
	{
		MessageBox(m_Language.GetText(m_Language.NO_GP3_AND_2000_DIRECTORY));
	}
	EndWaitCursor();
}

/**
 * Show a browse of foulders window with a optional title
 * return a char pointer with the selected directory.
 */
char* CGp3TrackInstallerDlg::BrowseForFolders(char* title)
{
	char* pPath;
	BROWSEINFO bff;
	LPITEMIDLIST pidl;
	
	pPath=new char[_MAX_PATH];

	bff.hwndOwner				= this->m_hWnd;
	bff.iImage					= 0;
	bff.lParam					= 0;
	bff.lpszTitle				= title;
	bff.pidlRoot				= NULL;
	bff.ulFlags					= BIF_RETURNONLYFSDIRS|BIF_EDITBOX;
	bff.pszDisplayName	= pPath;
	bff.lpfn						= NULL;

	pidl=SHBrowseForFolder(&bff);
	if (pidl)
	{
		SHGetPathFromIDList(pidl,pPath);
		return(pPath);
	}

	delete[] pPath;
	return(NULL);
}

//Save all settings in the registry
void CGp3TrackInstallerDlg::OnClose() 
{
	OnFileClose();
	SaveSettings();
	CDialog::OnClose();
}

//Enable/Disable the track items
void CGp3TrackInstallerDlg::EnableTrackDir(BOOL enable)
{
	GetDlgItem(IDC_EDIT_GP3TRACKDIR)->EnableWindow(enable);
	GetDlgItem(IDC_STATIC_TRACKDIR)->EnableWindow(enable);
	GetDlgItem(IDC_BUTTON_TRACKDIR_BROWSE)->EnableWindow(enable);
}

void CGp3TrackInstallerDlg::OnCheckTrackdirEnable() 
{
	UpdateData(TRUE);
	EnableTrackDir(m_bTrackDir);
}

//Create a directory structure
bool CGp3TrackInstallerDlg::CreateSubDirectorys(char* dir)
{
	//check is it is a full path e.g starts with a drive
	if(dir[1]!=':')
		return(false);
	char* pNewDir;
	char* pTmpDir;
	if(dir[strlen(dir)-1]!='\\')
	{
		pNewDir=new char[strlen(dir)+2];
		strcpy(pNewDir,dir);
		strcat(pNewDir,"\\");
	}
	else
	{
		pNewDir=new char[strlen(dir)+1];
		strcpy(pNewDir,dir);
	}
	
	//loop throw the dir structure and create one dir at a time
	pTmpDir=new char[_MAX_PATH];
	for(unsigned int i=3;i<strlen(pNewDir);i++)
	{
		if(pNewDir[i]=='\\')
		{
			pTmpDir[0]='\0';
			strncpy(pTmpDir,dir,i);
			pTmpDir[i]='\0';
			CreateDirectory(pTmpDir,NULL);
		}
	}
	//Free memory
	delete[] pTmpDir;
	delete[] pNewDir;
	return(true);
}

/**
 * Read the header of the jam file to determent the type
 * Return 0 if its a software jam
 * Return 1 if its a hardware jam
 */
int CGp3TrackInstallerDlg::GetJamType(char* file)
{
	CFile JamFile;
	int Type(0);
	JamFile.Open(file,CFile::modeRead);
	JamFile.SeekToBegin();
	JamFile.Read((char*)&Type,sizeof(Type));
	JamFile.Close();
	if(Type==9999999)
		return(1);
	else
		return(0);
}

/**
 * CString Wrapper function for FileExists(char* file)
 */
bool CGp3TrackInstallerDlg::FileExists(CString file)
{
	char* pBuffer=new char[_MAX_PATH];
	bool bRetVal=false;
	sprintf(pBuffer,"%s",file);
	bRetVal=FileExists(pBuffer);
	delete[] pBuffer;
	return(bRetVal);
}

/**
 * Check is a file exists or not
 * return false if file is not found
 * return true if file is found
 */
bool CGp3TrackInstallerDlg::FileExists(char *file)
{
	WIN32_FIND_DATA wfd;
	HANDLE hFile;
	char* pBuffer=new char[_MAX_PATH];
	bool bRetVal=false;

	strcpy(pBuffer,file);
	if(pBuffer[strlen(pBuffer)-1]=='\\')
		pBuffer[strlen(pBuffer)-1]='\0';
	hFile=FindFirstFile(pBuffer,&wfd);
	if(hFile==INVALID_HANDLE_VALUE)
		bRetVal=false;
	else
		bRetVal=true;
	FindClose(hFile);
	delete[] pBuffer;
	return(bRetVal);
}

/**
 * Return a pointer to the directory based on a file name
 */
char* CGp3TrackInstallerDlg::GetDirectory(char* file)
{
	char* pDrive=new char[_MAX_PATH];
	char* pDir=new char[_MAX_PATH];
	char* pPath=new char[_MAX_PATH];

	_splitpath(file,pDrive,pDir,NULL,NULL);
	strcpy(pPath,pDrive);
	strcat(pPath,pDir);

	delete[] pDir;
	delete[] pDrive;
	return(pPath);
}

/**
 * Main install function
 */
void CGp3TrackInstallerDlg::InstallJams(CString szGp3Path)
{
	CFile TrackFile;
	CDlgProgress* pDlgProgress=new CDlgProgress();
	CDlgReport* pDlgReport=NULL;
	char* pDestinationFilePath=new char[_MAX_PATH];
	char* pFileName=new char[_MAX_PATH];
	char* pExt=new char[_MAX_PATH];
	char* pDrive=new char[_MAX_PATH];
	char* pDir=new char[_MAX_PATH];
	char* pSourceFilePath=NULL;
	char* pTrackPath;
	char* pMessage;
	char* pReport=NULL;

	char* pJamFile=new char[_MAX_PATH];
	char* pJadFile=new char[_MAX_PATH];


	int i(0);
	int iLoop(0);
	int iInstallCounter(0);

	UpdateData(TRUE);

	// Open track file
	TrackFile.Open(m_pGp3TrackFile,CFile::modeRead);
	//first check if track file is more then 5k, if not it's not a track file :)
	if(TrackFile.GetLength()>5000)
	{
		//Get Jam table position and read jam table
		if(ReadJamTable(&TrackFile,GetJamStart(&TrackFile)))
		{
			pDlgProgress->Create(IDD_DIALOG_PROGRESS);
			//Set max to nr of jams + 1 for the track
			pDlgProgress->InitProgressBar(0,m_JamList.GetSize());
			pMessage=new char[1000];
			sprintf(pMessage,"%s %s",m_Language.GetText(m_Language.PROGRESS_TITLE),m_pGp3TrackFile);
			pDlgProgress->SetTitleText(pMessage);
			pDlgProgress->SetSubTitleText(m_Language.GetText(m_Language.PROGRESS_SUB_TITLE));
			delete[] pMessage;
			pDlgProgress->ShowWindow(SW_SHOW);
			pDlgProgress->RedrawWindow();
			// set pReport to jamfiles*512 in memory size
			pReport=new char[m_JamList.GetSize()*512];
			pReport[0]='\0';
			//Get the working directory for the jam files and track file.
			pTrackPath=GetDirectory(m_pGp3TrackFile);

			//check what files we need to install
			for(i=0;i<m_JamList.GetSize();i++)
			{
				pDlgProgress->SetDataText(m_JamList.GetItem(i));
				pDlgProgress->StepIt();
				//add file to pReport
				strcat(pReport,"Jam file: ");
				strcat(pReport,m_JamList.GetItem(i));
				//create a path to the destination
				strcpy(pDestinationFilePath,szGp3Path);
				//add filename to path
				strcat(pDestinationFilePath,m_JamList.GetItem(i));

				//Get the filename
				_splitpath(pDestinationFilePath,NULL,NULL,pFileName,pExt);

				strcpy(pJamFile,pFileName);
				strcat(pJamFile,pExt);
				pSourceFilePath=SearchDirectory(pTrackPath,pJamFile);
				if(pSourceFilePath==NULL)
				{
					strcpy(pJadFile,pFileName);
					strcat(pJadFile,pExt);
					pSourceFilePath=SearchDirectory(pTrackPath,pJadFile);
					if(pSourceFilePath!=NULL)
					{
						ConvertFile(pSourceFilePath,false);
						pSourceFilePath=SearchDirectory(pTrackPath,pJamFile);
					}
				}

				//Check is source file exists, if not dont do anything
				if(pSourceFilePath!=NULL&&FileExists(pSourceFilePath))
				{
					strcat(pReport,"\r\nInstalled to: ");
					strcat(pReport,pDestinationFilePath);
					// one more file found and installed
					iInstallCounter++;

					//Check if its a hardware or software jam file
					//if its a hardware jam file change the destination dir to gp3jamsH
					if(GetJamType(pSourceFilePath)==1)
					{
						//strcpy(pDestinationFilePath,m_JamList.GetItem(i));
						strncpy(pDir,m_JamList.GetItem(i),8);
						pDir[8]='\0';
						if(!strcmpi(pDir,"gp3jams\\"))
						{
							strcpy(pDir,"gp3jamsh\\");
							strcat(pDir,&m_JamList.GetItem(i)[8]);
							strcpy(pDestinationFilePath,szGp3Path);
							strcat(pDestinationFilePath,pDir);
						}
					}
					
					//remove file name from pDestinationFilePath and put the
					//result in pDir (the result will be the dirs) and create folders
					_splitpath(pDestinationFilePath,pDrive,pDir,pFileName,pExt);
					strcat(pDrive,pDir);
					strcpy(pDir,pDrive);
					strcat(pFileName,pExt);
					if(!FileExists(pDir))
						CreateSubDirectorys(pDir);

					//try to copy file, fail if it is already there.
					if(FileExists(pDestinationFilePath))
						SetFileAttributes(pDestinationFilePath,FILE_ATTRIBUTE_NORMAL);
					if(!CopyFile(pSourceFilePath,pDestinationFilePath,!m_bOverwrite))
					{
						//FAILD! Show Error message and wait for user input.
						pMessage=new char[1000];

						sprintf(pMessage,m_Language.GetText(m_Language.FOLDER_CONTAINS_FILE),pDir,pFileName,'\n','\n');
						MessageBeep(MB_ICONQUESTION);
						int ret = MessageBox(pMessage,"Gp3 Track Installer",MB_YESNOCANCEL|MB_DEFBUTTON2|MB_APPLMODAL|MB_SETFOREGROUND|MB_ICONQUESTION);
						delete[] pMessage;
						if(ret==IDYES)
							//Overwrite the existing file
							CopyFile(pSourceFilePath,pDestinationFilePath,false);
						else if(ret==IDCANCEL)
							//Exit installation
							break;
					}
					if(pSourceFilePath!=NULL)
						delete[] pSourceFilePath;
					pSourceFilePath=NULL;
				}
				else
					strcat(pReport," - File not found");
				strcat(pReport,"\r\n\r\n");
			}
		}
	}
	//Close track file
	TrackFile.Close();
	pDlgProgress->DestroyWindow();

	if(m_bShowReport==TRUE)
	{
		pDlgReport=new CDlgReport();
		pDlgReport->Init(&m_Language,pReport,false);
		pDlgReport->DoModal();
		delete pDlgReport;
		pDlgReport=NULL;
		delete[] pReport;
		pReport=NULL;
	}


	if(m_bShowGp3Form==TRUE)
	{
		pMessage=SearchDirectory(pTrackPath,"*.txt");
		if(pMessage!=NULL)
		{
			CFile file;
			file.Open(pMessage,CFile::modeRead);
			delete[] pMessage;
			pMessage=new char[file.GetLength()+1];
			file.Read((char*)pMessage,file.GetLength());
			pMessage[file.GetLength()]='\0';
			file.Close();
			pDlgReport=new CDlgReport();
			pDlgReport->Init(&m_Language,pMessage);
			pDlgReport->DoModal();
			delete pDlgReport;
			pDlgReport=NULL;
			delete[] pMessage;
			pMessage=NULL;
		}
	}

	if(iInstallCounter==0)
		MessageBox(m_Language.GetText(m_Language.NO_JAM_FILES_INSTALLED),"Gp3 Track Installer",MB_ICONWARNING|MB_OK);

	//Free memory
	delete[] pDir;
	delete[] pExt;
	delete[] pFileName;
	delete[] pDrive;
	delete[] pDestinationFilePath;
	delete[] pTrackPath;
	delete[] pDlgProgress;
	delete[] pJamFile;
	delete[] pJadFile;
	if(pReport!=NULL)
		delete[] pReport;
	if(pSourceFilePath!=NULL)
		delete[] pSourceFilePath;
	if(pDlgReport!=NULL)
		delete pDlgReport;
}

void CGp3TrackInstallerDlg::CopyTrack()
{
	char* pDrive=new char[_MAX_PATH];
	char* pDir=new char[_MAX_PATH];
	char* pFileName=new char[_MAX_PATH];
	char* pExt=new char[_MAX_PATH];
	char* pDestinationFileName=new char[_MAX_PATH];
	char* pMessage;
	UpdateData(TRUE);
	//Create the destination dir's
	if(m_TrackDir.Right(4)!=".dat"&&m_TrackDir.Right(1)!="\\")
		m_TrackDir+="\\";
	_splitpath(m_TrackDir,pDrive,pDir,pFileName,pExt);
	strcat(pDrive,pDir);
	CreateSubDirectorys(pDrive);
	if(strcmp(pExt,".dat"))
	{
		_splitpath(m_pGp3TrackFile,NULL,NULL,pFileName,pExt);
		_splitpath(m_TrackDir,pDrive,pDir,NULL,NULL);
		strcat(pDrive,pDir);
		strcat(pDrive,pFileName);
		strcat(pDrive,pExt);
		strcpy(pDestinationFileName,pDrive);
	}
	else
		strcpy(pDestinationFileName,m_TrackDir);

	if(!CopyFile(m_pGp3TrackFile,pDestinationFileName,!m_bOverwrite))
	{
		_splitpath(pDestinationFileName,pDrive,pDir,pFileName,pExt);
		strcat(pDrive,pDir);
		strcat(pFileName,pExt);
		pMessage=new char[_MAX_PATH];
		sprintf(pMessage,m_Language.GetText(m_Language.FOLDER_CONTAINS_FILE),pDrive,pFileName,'\n','\n');
		MessageBeep(MB_ICONQUESTION);
		if(MessageBox(pMessage,"Gp3 Track Installer",MB_YESNO|MB_DEFBUTTON2|MB_APPLMODAL|MB_SETFOREGROUND|MB_ICONQUESTION)==IDYES)
			//Overwrite the existing file
			CopyFile(m_pGp3TrackFile,pDestinationFileName,false);
		delete[] pMessage;
	}

	delete[] pDrive;
	delete[] pDir;
	delete[] pExt;
	delete[] pFileName;
	delete[] pDestinationFileName;
}

/**
 * Save all settings to the registry
 */
void CGp3TrackInstallerDlg::SaveSettings()
{
	UpdateData(TRUE);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"Gp3Path",
												m_Gp3Path);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"Gp32kPath",
												m_Gp32kPath);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"TrackDir",
												m_TrackDir);
	m_RegEdit.SaveSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"EnableTrackDir",
												m_bTrackDir);

	m_szExtractPath.Empty();
	if(m_pExtractDirectory!=NULL)
		delete[] m_pExtractDirectory;
	m_pExtractDirectory=NULL;

}

/**
 * Save and exit
 */
void CGp3TrackInstallerDlg::OnFileExit() 
{
	OnFileClose();
	SaveSettings();
	OnOK();
}

/**
 * Show about dialog
 */
void CGp3TrackInstallerDlg::OnHelpAbout() 
{
	CAboutDlg about;
	about.DoModal();
}

/**
 * Show help file
 */
void CGp3TrackInstallerDlg::OnHelpHelp() 
{
	char* pBuffer=new char[_MAX_PATH];
	GetModuleFileName(NULL,pBuffer,_MAX_PATH);
	for(int i=strlen(pBuffer);i>=1;i--)
	{
		if(pBuffer[i]=='\\')
		{
			pBuffer[i+1]='\0';
			break;
		}
	}
	strcat(pBuffer,"help\\index.html");
	ShellExecute(this->m_hWnd,"open",pBuffer,"","",1);
	delete[] pBuffer;
}

/**
 * Start default web browser and point the location to www.vgsoftware.com
 */
void CGp3TrackInstallerDlg::OnHelpOnline() 
{
	ShellExecute(this->m_hWnd,"open","http://www.vgsoftware.com/","","",1);	
}

/**
 * Open a track file for installation
 */
void CGp3TrackInstallerDlg::OnFileOpen() 
{
	CFileDialog FileDlg(TRUE,
											NULL,
											NULL,
											OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
											"All Supported Files (*.dat;*.zip)|*.dat;*.zip|Gp3 Track File (*.dat)|*.dat|Zip Files (*.zip)|*.zip||");
	if(FileDlg.DoModal()==IDOK)
	{
		if(strcmpi(FileDlg.GetFileExt(),"dat")&&strcmpi(FileDlg.GetFileExt(),"zip"))
			MessageBox(m_Language.GetText(m_Language.NO_GP3_TRACK_FILE),"Gp3 Track Installer");
		else if(!FileExists(FileDlg.m_ofn.lpstrFile))
			MessageBox(m_Language.GetText(m_Language.FILE_NOT_FOUND),"Gp3 Track Installer");
		else
		{
			if(m_pGp3TrackFile!=NULL)
				OnFileClose();
			if(!strcmpi(FileDlg.GetFileExt(),"zip"))
			{
				if(!Unzip(FileDlg.m_ofn.lpstrFile))
					return;
			}
			else
			{
				m_pGp3TrackFile=new char[_MAX_PATH];
				strcpy(m_pGp3TrackFile,FileDlg.m_ofn.lpstrFile);
			}
			EnableInstall(true);
			EnableTrackDir(m_bTrackDir);
			SetDlgItemText(IDC_STATIC_TRACK_FILE,m_pGp3TrackFile);
			CMenu* menu;
			menu=this->GetMenu();
			menu->EnableMenuItem(ID_FILE_CLOSE,MF_ENABLED);
			ShowGp3Info();
		}
	}
}

/**
 * enable/disable all controls
 */
void CGp3TrackInstallerDlg::EnableInstall(bool bEnable)
{
	GetDlgItem(IDC_BUTTON_INSTALL_GP3)->EnableWindow(bEnable);
	GetDlgItem(IDC_BUTTON_INSTALL_GP32K)->EnableWindow(bEnable);
	GetDlgItem(IDC_BUTTON_INSTALL_BOTH)->EnableWindow(bEnable);
	GetDlgItem(IDC_STATIC_INSTALL)->EnableWindow(bEnable);
	GetDlgItem(IDC_STATIC_TRACK_FILE)->EnableWindow(bEnable);
	GetDlgItem(IDC_STATIC_TRACKFRAME)->EnableWindow(bEnable);
}

/**
 * This will convert jam files to jad files and jad files to jam files
 * Only use with software jams
 */
void CGp3TrackInstallerDlg::ConvertFile(char* file, bool bDelete)
{
	// Decryption variables
	unsigned long lPattern(0xB082F165);
	unsigned long lValue(0);
	int nNumBytes(0);
	int bSuccess(1);
	int iLen(0);

	char* pNewFile=new char[_MAX_PATH];
	//If jam file then new file will be a jad file
	strcpy(pNewFile,file);

	if(!strcmpi(&file[strlen(file)-4],"jam"))
		pNewFile[strlen(pNewFile)-1]='d';
	else
		pNewFile[strlen(pNewFile)-1]='m';

	// Open the input file
	CFile fInput(file,CFile::modeRead);

	// Open the output file
	CFile fOutput(pNewFile,CFile::modeReadWrite | CFile::modeCreate);

	// Loop through the file, 4 bytes at a time, en/decrypting the
	// contents into the output file as we go.
	nNumBytes=fInput.GetLength();
	for (int nNumBlocks = nNumBytes / 4; nNumBlocks > 0;nNumBlocks--)
	{
		fInput.Read((char*)&lValue,4);
		// Jams use a simple XOR encryption method, with the encryption key
		// changing for each subsequent 4 bytes.  Thus, the same process can
		// be repeated to encrypt/decrypt the files.
		lValue ^= lPattern;
		lPattern *= 5;

		// Output the en/decrypted value
		fOutput.Write((char*) &lValue,4);
	}
	// Tidy up by closing the files
	fOutput.Close();
	fInput.Close();
	// Finally, if the conversion was a success, delete the input file
	if (bDelete==true)
		DeleteFile(file);
}

/*
	Unzip a zip file and find the .dat file
*/
bool CGp3TrackInstallerDlg::Unzip(char *file)
{
	char* pBuffer;
	UpdateData(TRUE);
	RemoveExtractDirectory();
	m_pExtractDirectory=new char[_MAX_PATH];

	if(m_bTempFolder==TRUE)
		GetTempPath(_MAX_PATH,m_pExtractDirectory);
	else
		sprintf(m_pExtractDirectory,"%s",m_szExtractPath);
//		strcpy(m_pExtractDirectory,m_szExtractPath);
	if(strlen(m_pExtractDirectory)>0)
	{
		if(m_bTempFolder==TRUE)
		{
			GetTempFileName(m_pExtractDirectory,"gp3ti",0,m_pExtractDirectory);
			DeleteFile(m_pExtractDirectory);
			strcat(m_pExtractDirectory,"\\");
			if(FileExists(m_pExtractDirectory))
				RemoveDirectory(m_pExtractDirectory);
		}
		else
		{
			if(m_pExtractDirectory[strlen(m_pExtractDirectory)-1]!='\\')
				strcat(m_pExtractDirectory,"\\");
			pBuffer=new char[_MAX_PATH];
			_splitpath(file,NULL,NULL,pBuffer,NULL);
			strcat(m_pExtractDirectory,pBuffer);
			delete[] pBuffer;
		}
		while(CreateDirectory(m_pExtractDirectory,NULL)==false)
		{
			strcat(m_pExtractDirectory,"0");
		};

		CInfoZip InfoZip;
		if (InfoZip.InitializeUnzip()&&
				InfoZip.ExtractFiles(file, m_pExtractDirectory)&&
				InfoZip.FinalizeUnzip())
		{
			m_pGp3TrackFile=SearchDirectory(m_pExtractDirectory,"*.dat");
			return(true);
		}
		else
		{
			if(FileExists(m_pExtractDirectory))
				RemoveDirectory(m_pExtractDirectory);
			sprintf(m_pExtractDirectory,m_Language.GetText(m_Language.EXTRACT_ERROR),file,'\n','\n');
			MessageBox(m_pExtractDirectory,"Gp3 Track Installer",MB_ICONSTOP|MB_OK);
		}
	}
	if(FileExists(m_pExtractDirectory))
		RemoveDirectory(m_pExtractDirectory);
	delete[] m_pExtractDirectory;
	m_pExtractDirectory=NULL;
	OnClose();
	return(false);
}

void CGp3TrackInstallerDlg::OnFileClose() 
{
	RemoveExtractDirectory();
	if(m_pGp3TrackFile!=NULL)
		delete[] m_pGp3TrackFile;
	m_pGp3TrackFile=NULL;
	m_pExtractDirectory=NULL;
	EnableInstall(false);
	SetDlgItemText(IDC_STATIC_TRACK_FILE,m_Language.GetText(m_Language.NO_TRACK));
	CMenu* menu;
	menu=this->GetMenu();
	menu->EnableMenuItem(ID_FILE_CLOSE,MF_GRAYED);
}

char* CGp3TrackInstallerDlg::SearchDirectory(char* dir, char *file)
{
WIN32_FIND_DATA wfd;
HANDLE hFile;
char* pSearchStr=new char[_MAX_PATH];
char* pDir=new char[_MAX_PATH];
char* pFoundFile=NULL;
char* pBuffer=NULL;

	pFoundFile=SearchFile(dir,file);

	if(dir[strlen(dir)-1]!='\\')
	{
		strcpy(pDir,dir);
		strcat(pDir,"\\*.*");
	}
	else
	{
		strcpy(pDir,dir);
		strcat(pDir,"*.*");
	}

	hFile=FindFirstFile(pDir,&wfd);
	if(hFile!=INVALID_HANDLE_VALUE&&pFoundFile==NULL)
	{
		do
		{
			if((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)&&(wfd.cFileName[0]!='.'))
			{
				pBuffer=new char[_MAX_PATH];
				strcpy(pBuffer,dir);
				if(pBuffer[strlen(pBuffer)-1]!='\\')
					strcat(pBuffer,"\\");
				strcat(pBuffer,wfd.cFileName);
				pFoundFile=SearchDirectory(pBuffer,file);
				delete[] pBuffer;
			}
		}while(FindNextFile(hFile,&wfd)&&pFoundFile==NULL);
	}
	FindClose(hFile);
	delete[] pSearchStr;
	delete[] pDir;
	return(pFoundFile);
}

char* CGp3TrackInstallerDlg::SearchFile(char *dir, char *file)
{
WIN32_FIND_DATA wfd;
HANDLE hFile;
char* pBuffer=new char[_MAX_PATH];
	strcpy(pBuffer,dir);
	if(dir[strlen(dir)-1]!='\\')
		strcat(pBuffer,"\\");
	strcat(pBuffer,file);
	hFile=FindFirstFile(pBuffer,&wfd);
	if(hFile!=INVALID_HANDLE_VALUE)
	{
		strcpy(pBuffer,dir);
		if(dir[strlen(dir)-1]!='\\')
			strcat(pBuffer,"\\");
		strcat(pBuffer,wfd.cFileName);
		FindClose(hFile);
		return(pBuffer);
	}
	FindClose(hFile);
	delete[] pBuffer;
	return(NULL);
}

bool CGp3TrackInstallerDlg::ClearAndRemoveDirectory(char *dir)
{
WIN32_FIND_DATA wfd;
HANDLE hFile;
char* pBuffer=new char[_MAX_PATH];
char* pFile=new char[_MAX_PATH];

	if(dir[strlen(dir)-1]!='\\')
	{
		strcpy(pBuffer,dir);
		strcat(pBuffer,"\\*.*");
	}
	else
	{
		strcpy(pBuffer,dir);
		strcat(pBuffer,"*.*");
	}

	hFile=FindFirstFile(pBuffer,&wfd);
	if(hFile!=(HANDLE)-1)
	{
		do
		{
			if((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)&&(wfd.cFileName[0]!='.'))
			{
				strcpy(pFile,dir);
				if(dir[strlen(dir)-1]!='\\')
					strcat(pFile,"\\");
				strcat(pFile,wfd.cFileName);
				ClearAndRemoveDirectory(pFile);
			}
			else if(wfd.cFileName[0]!='.')
			{
				strcpy(pFile,dir);
				if(dir[strlen(dir)-1]!='\\')
					strcat(pFile,"\\");
				strcat(pFile,wfd.cFileName);
				if(wfd.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
					SetFileAttributes(pFile, FILE_ATTRIBUTE_NORMAL); 
				if(!DeleteFile(pFile))
					Error("ClearAndRemoveDirectory");
			}
		}while(FindNextFile(hFile,&wfd));
	}
	FindClose(hFile);
	delete[] pBuffer;
	delete[] pFile;
	if(!RemoveDirectory(dir))
		Error("ClearAndRemoveDirectory");
	return(true);
}

void CGp3TrackInstallerDlg::Error(char *pFunction)
{
	CHAR szBuf[80];
	DWORD dw = GetLastError();

	sprintf(szBuf, "%s failed: GetLastError returned %u\n", pFunction, dw);

	MessageBox(szBuf, "Error", MB_OK);
	ExitProcess(dw);
}

void CGp3TrackInstallerDlg::RemoveExtractDirectory()
{
	UpdateData(TRUE);
	if(m_pExtractDirectory!=NULL&&m_bRemove==TRUE)
		if(FileExists(m_pExtractDirectory))
			ClearAndRemoveDirectory(m_pExtractDirectory);
	delete[] m_pExtractDirectory;
	m_pExtractDirectory=NULL;
}

void CGp3TrackInstallerDlg::LoadText()
{
	CMenu* menu;
	menu=this->GetMenu();
	menu->ModifyMenu(0,MF_BYPOSITION,0,m_Language.GetText(m_Language.FILE_MENU));
	menu->ModifyMenu(1,MF_BYPOSITION,1,m_Language.GetText(m_Language.HELP_MENU));
	menu->ModifyMenu(ID_FILE_OPEN,MF_BYCOMMAND,ID_FILE_OPEN,m_Language.GetText(m_Language.FILE_OPEN));
	menu->ModifyMenu(ID_FILE_CLOSE,MF_BYCOMMAND,ID_FILE_CLOSE,m_Language.GetText(m_Language.FILE_CLOSE));
	menu->ModifyMenu(ID_FILE_SETTINGS,MF_BYCOMMAND,ID_FILE_SETTINGS,m_Language.GetText(m_Language.FILE_SETTINGS));
	menu->ModifyMenu(ID_FILE_EXIT,MF_BYCOMMAND,ID_FILE_EXIT,m_Language.GetText(m_Language.FILE_EXIT));
	menu->ModifyMenu(ID_HELP_ONLINE,MF_BYCOMMAND,ID_HELP_ONLINE,m_Language.GetText(m_Language.HELP_ONLINE));
	menu->ModifyMenu(ID_HELP_HELP,MF_BYCOMMAND,ID_HELP_HELP,m_Language.GetText(m_Language.HELP_HELP));
	menu->ModifyMenu(ID_HELP_ABOUT,MF_BYCOMMAND,ID_HELP_ABOUT,m_Language.GetText(m_Language.HELP_ABOUT));

	SetDlgItemText(IDC_STATIC_TRACKFRAME,m_Language.GetText(m_Language.TRACK_FILE_FRAME));

	SetDlgItemText(IDC_STATIC_SETTINGS,m_Language.GetText(m_Language.GP3_SETTINGS_FRAME));
	SetDlgItemText(IDC_STATIC_GP3,m_Language.GetText(m_Language.GP3_PATH));
	SetDlgItemText(IDC_STATIC_GP32K,m_Language.GetText(m_Language.GP3_2000_PATH));
	SetDlgItemText(IDC_STATIC_TRACKDIR,m_Language.GetText(m_Language.GP3_TRACK_DIR));

	SetDlgItemText(IDC_STATIC_INSTALL,m_Language.GetText(m_Language.INSTALL_FRAME));
	SetDlgItemText(IDC_BUTTON_INSTALL_GP3,m_Language.GetText(m_Language.GP3_INSTALL_BUTTON));
	SetDlgItemText(IDC_BUTTON_INSTALL_GP32K,m_Language.GetText(m_Language.GP3_2000_INSTALL_BUTTON));
	SetDlgItemText(IDC_BUTTON_INSTALL_BOTH,m_Language.GetText(m_Language.BOTH_INSTALL_BUTTON));

	SetDlgItemText(IDC_STATIC_LABEL_NAME,m_Language.GetText(m_Language.GP3INFO_NAME));
	SetDlgItemText(IDC_STATIC_LABEL_COUNTRY,m_Language.GetText(m_Language.GP3INFO_COUNTRY));
	SetDlgItemText(IDC_STATIC_LABEL_LENGTH,m_Language.GetText(m_Language.GP3INFO_LENGTH));
	SetDlgItemText(IDC_STATIC_LABEL_LAPS,m_Language.GetText(m_Language.GP3INFO_LAPS));
	SetDlgItemText(IDC_STATIC_LABEL_YEAR,m_Language.GetText(m_Language.GP3INFO_YEAR));
	SetDlgItemText(IDC_STATIC_LABEL_SLOT,m_Language.GetText(m_Language.GP3INFO_SLOT));
	SetDlgItemText(IDC_STATIC_LABEL_EVENT,m_Language.GetText(m_Language.GP3INFO_EVENT));
	SetDlgItemText(IDC_STATIC_LABEL_AUTHOR,m_Language.GetText(m_Language.GP3INFO_AUTHOR));
	SetDlgItemText(IDC_STATIC_LABEL_DESC,m_Language.GetText(m_Language.GP3INFO_DESC));
	SetDlgItemText(IDC_STATIC_TRACK_INFO,m_Language.GetText(m_Language.GP3INFO_FRAME_TITLE));

	DrawMenuBar();

}

int CGp3TrackInstallerDlg::FindMenuItem(CMenu* Menu, LPCTSTR MenuString)
{
   ASSERT(Menu);
   ASSERT(::IsMenu(Menu->GetSafeHmenu()));

   int count = Menu->GetMenuItemCount();
   for (int i = 0; i < count; i++)
   {
      CString str;
      if (Menu->GetMenuString(i, str, MF_BYPOSITION) &&
         (strcmp(str, MenuString) == 0))
         return i;
   }

   return -1;
}

void CGp3TrackInstallerDlg::OnFileSettings() 
{
	CDlgOptions opt;
	opt.Init(&m_Language);
	opt.DoModal();
	LoadSettings();
	OnFileClose();
}

void CGp3TrackInstallerDlg::LoadSettings()
{
	m_Gp3Path = m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"Gp3Path",
												(CString)"");
	m_Gp32kPath = m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"Gp32kPath",
												(CString)"");
	m_TrackDir = m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"TrackDir",
												(CString)"");

	m_szExtractPath=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ExtractDir",
												(CString)"c:\\");

	m_bTrackDir = m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"EnableTrackDir",
												FALSE);

	m_bRemove=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"RemoveExtract",
												TRUE);
	m_bTempFolder=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ExtractToTemp",
												TRUE);
	m_bOverwrite=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"OverwriteFiles",
												FALSE);
	m_bShowReport=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ShowReport",
												TRUE);
	m_bShowGp3Form=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"ShowGp3Form",
												TRUE);
	m_pLanguage=m_RegEdit.GetSettings(HKEY_CURRENT_USER,
												"Software\\VG Software\\Gp3 Track Installer",
												"Language",
												"");
		

	if((m_pLanguage==NULL)||(!FileExists(m_pLanguage)))
	{
		char* pBuffer=new char[_MAX_PATH];
		GetModuleFileName(NULL,pBuffer,_MAX_PATH);
		for(int i=strlen(pBuffer);i>=1;i--)
		{
			if(pBuffer[i]=='\\')
			{
				pBuffer[i+1]='\0';
				break;
			}
		}
		if(m_pLanguage!=NULL)
			delete[] m_pLanguage;
		m_pLanguage=new char[_MAX_PATH];
		strcat(pBuffer,"language\\english.ini");
		strcpy(m_pLanguage,pBuffer);
		delete[] pBuffer;
	}
	m_Language.LoadLanguageFile(m_pLanguage);
	LoadText();
	if(m_pLanguage!=NULL)
		delete[] m_pLanguage;

	if(m_Gp3Path=="")
	{
		m_Gp3Path = m_RegEdit.GetSettings(HKEY_LOCAL_MACHINE,
								"SOFTWARE\\Microprose\\Grand Prix 3\\3.00.000\\Install Dir",
								"Directory",
								(CString)"");
	}

	if(m_Gp32kPath=="")
	{
		m_Gp32kPath = m_RegEdit.GetSettings(HKEY_LOCAL_MACHINE,
									"SOFTWARE\\Microprose\\Grand Prix 3 2000\\3.20.000\\Install Dir",
									"Directory",
									(CString)"");
	}

	UpdateData(FALSE);
}

void CGp3TrackInstallerDlg::ShowGp3Info()
{
	CGp3Info Gp3Info;

	if(Gp3Info.LoadInfo(m_pGp3TrackFile))
	{
		SetDlgItemText(IDC_STATIC_NAME,Gp3Info.GetName());
		SetDlgItemText(IDC_STATIC_COUNTRY,Gp3Info.GetCountry());
		SetDlgItemText(IDC_STATIC_LENGHT,Gp3Info.GetLength());
		SetDlgItemText(IDC_STATIC_YEAR,Gp3Info.GetYear());
		SetDlgItemText(IDC_STATIC_LAPS,Gp3Info.GetLaps());
		SetDlgItemText(IDC_STATIC_EVENT,Gp3Info.GetEvent());
		SetDlgItemText(IDC_STATIC_AUTHOR,Gp3Info.GetAuthor());
		SetDlgItemText(IDC_STATIC_SLOT,Gp3Info.GetSlot());
		SetDlgItemText(IDC_STATIC_DESC,Gp3Info.GetDesc());
	}
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	m_Credits.AddString("Beta testers: Fredrik Andersson, Martin Lindeberg, Hans Mörtsjö, Lars-Erik Mörtsjö");
	m_Credits.SetScrollSpeed(250);
	return TRUE;
}
