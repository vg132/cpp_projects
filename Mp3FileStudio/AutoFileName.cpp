// AutoFileName.cpp : implementation file
//

#include "stdafx.h"
#include "Mp3FileStudio.h"
#include "AutoFileName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoFileName property page

IMPLEMENT_DYNCREATE(CAutoFileName, CPropertyPage)

CAutoFileName::CAutoFileName() : CPropertyPage(CAutoFileName::IDD)
{
	//{{AFX_DATA_INIT(CAutoFileName)
	m_iSubDir = -1;
	m_iCurFile = 0;
	m_iCurDir = -1;
	m_sFileName = _T("");
	//}}AFX_DATA_INIT
}

CAutoFileName::~CAutoFileName()
{
}

void CAutoFileName::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoFileName)
	DDX_Radio(pDX, IDC_RADIO_FILENAME_SUBDIR, m_iSubDir);
	DDX_Radio(pDX, IDC_RADIO_FILENAME_CURFILE, m_iCurFile);
	DDX_Radio(pDX, IDC_RADIO_FILENAME_CURDIR, m_iCurDir);
	DDX_Text(pDX, IDC_FILENAME_EDIT_FILENAMELAYOUT, m_sFileName);
	DDV_MaxChars(pDX, m_sFileName, 200);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAutoFileName, CPropertyPage)
	//{{AFX_MSG_MAP(CAutoFileName)
	ON_BN_CLICKED(IDC_RADIO_FILENAME_CURFILE, OnRadioFilenameCurfile)
	ON_BN_CLICKED(IDC_RADIO_FILENAME_CURDIR, OnRadioFilenameCurdir)
	ON_BN_CLICKED(IDC_RADIO_FILENAME_SUBDIR, OnRadioFilenameSubdir)
	ON_BN_CLICKED(IDC_BUTTON_CREATEFILENAME, OnButtonCreatefilename)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoFileName message handlers

void CAutoFileName::SetFile(CString File)
{
	m_File=File;
}

void CAutoFileName::SetDirectory(CString Dir)
{
	m_Dir=Dir;
}
void CAutoFileName::OnRadioFilenameCurfile() 
{
	UpdateData(TRUE);
	m_iCurFile=0;
	m_iCurDir=1;
	m_iSubDir=1;
	UpdateData(FALSE);
}

void CAutoFileName::OnRadioFilenameCurdir() 
{
	UpdateData(TRUE);
	m_iCurDir=0;
	m_iCurFile=1;
	m_iSubDir=1;
	UpdateData(FALSE);
}

void CAutoFileName::OnRadioFilenameSubdir() 
{
	UpdateData(TRUE);
	m_iSubDir=0;
	m_iCurDir=1;
	m_iCurFile=1;
	UpdateData(FALSE);
}

void CAutoFileName::OnButtonCreatefilename() 
{
	UpdateData(TRUE);
	BeginWaitCursor();
	if(m_iCurFile==0)
		FindFiles(m_Dir,2,m_File);
	else if(m_iCurDir==0)
		FindFiles(m_Dir,1);
	else
		FindFiles(m_Dir,0);
	m_FileListView->SetDirectory(m_Dir);
	EndWaitCursor();
	MessageBox("File Name(s) changed");
}

/**
 * Mode:
 * 0=Sub Dirs
 * 1=Cur Dir
 * 2=File
 */
void CAutoFileName::FindFiles(CString Folder,int Mode, CString FileName)
{
	WIN32_FIND_DATA wfd;
	HANDLE hFile;
	CString szTemp=Folder;
	CString sTmp;
	char *sTmp2;

	if(szTemp.Right(1)!="\\")
	{
		Folder+="\\";
		szTemp+="\\";
	}

	if(Mode==1)
		szTemp+="*.mp3";
	else if(Mode==2)
		szTemp=FileName;
	else if(Mode==0)
		szTemp+="*.*";

	hFile=FindFirstFile(szTemp,&wfd);
	if(hFile!=(HANDLE)-1)
	{
		do
		{
			if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if(wfd.cFileName[0]!='.')
				{
					szTemp=Folder;
					szTemp+=wfd.cFileName;
					FindFiles(szTemp);
				}
			}
			else if(strncmp(&wfd.cFileName[strlen(wfd.cFileName)-5],".mp3",4))
			{
				szTemp=Folder;
				szTemp+=wfd.cFileName;
				m_Mp3FileInfo=new CMp3FileInfo;
				if(m_Mp3FileInfo->GetMP3Info(szTemp))
				{
					sTmp=m_sFileName;
					sTmp.Replace("%1",m_Mp3FileInfo->GetArtist());
					sTmp.Replace("%2",m_Mp3FileInfo->GetTitle());
					sTmp.Replace("%3",m_Mp3FileInfo->GetAlbum());
					sTmp.Replace("%4",m_Mp3FileInfo->GetYear());
					sTmp.Replace("%5",m_Mp3FileInfo->GetComments());
					sTmp2=new char[10];
					itoa(m_Mp3FileInfo->GetTrack(),sTmp2,10);
					sTmp.Replace("%6",sTmp2);
					delete[] sTmp2;
					if(sTmp!="")
					{
						sTmp.Replace("\\","");
						sTmp.Replace("/","");
						sTmp.Replace("\"","");
						sTmp.Replace(":","");
						sTmp.Replace("*","");
						sTmp.Replace("?","");
						sTmp.Replace("<","");
						sTmp.Replace(">","");
						sTmp.Replace("|","");
						sTmp+=".mp3";
						sTmp.Insert(0,Folder);
						rename(szTemp,sTmp);
					}
				}
				delete m_Mp3FileInfo;
			}
		}while(FindNextFile(hFile,&wfd));
	}
}

void CAutoFileName::SetFileListView(CFileListView *FileListView)
{
	m_FileListView = FileListView;
}