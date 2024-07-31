// AutoTagEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Mp3FileStudio.h"
#include "AutoTagEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoTagEdit property page

IMPLEMENT_DYNCREATE(CAutoTagEdit, CPropertyPage)

CAutoTagEdit::CAutoTagEdit() : CPropertyPage(CAutoTagEdit::IDD)
{
	//{{AFX_DATA_INIT(CAutoTagEdit)
	m_TagFromName = 0;
	m_NameFromTag = -1;
	m_TagFileFilter = _T("");
	m_CurDir = -1;
	m_CurFile = 0;
	m_SubFolders = -1;
	m_Year = _T("");
	m_Artist = _T("");
	m_Album = _T("");
	m_bYear = FALSE;
	m_bArtist = FALSE;
	m_bAlbum = FALSE;
	//}}AFX_DATA_INIT
}

CAutoTagEdit::~CAutoTagEdit()
{
}

void CAutoTagEdit::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoTagEdit)
	DDX_Text(pDX, IDC_TAG_EDIT_FILEFILTER, m_TagFileFilter);
	DDX_Radio(pDX, IDC_RADIO_CURDIR, m_CurDir);
	DDX_Radio(pDX, IDC_RADIO_CURFILE, m_CurFile);
	DDX_Radio(pDX, IDC_RADIO_SUBDIR, m_SubFolders);
	DDX_Text(pDX, IDC_TAG_EDIT_YEAR, m_Year);
	DDV_MaxChars(pDX, m_Year, 4);
	DDX_Text(pDX, IDC_TAG_EDIT_ARTIST, m_Artist);
	DDV_MaxChars(pDX, m_Artist, 30);
	DDX_Text(pDX, IDC_TAG_EDIT_ALBUM, m_Album);
	DDV_MaxChars(pDX, m_Album, 30);
	DDX_Check(pDX, IDC_TAG_CHECK_YEAR, m_bYear);
	DDX_Check(pDX, IDC_TAG_CHECK_ARTIST, m_bArtist);
	DDX_Check(pDX, IDC_TAG_CHECK_ALBUM, m_bAlbum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAutoTagEdit, CPropertyPage)
	//{{AFX_MSG_MAP(CAutoTagEdit)
	ON_BN_CLICKED(IDC_RADIO_CURFILE, OnRadioCurfile)
	ON_BN_CLICKED(IDC_RADIO_CURDIR, OnRadioCurdir)
	ON_BN_CLICKED(IDC_RADIO_SUBDIR, OnRadioSubdir)
	ON_BN_CLICKED(IDC_BUTTON_CREATETAG, OnButtonCreatetag)
	ON_BN_CLICKED(IDC_TAG_CHECK_ARTIST, OnTagCheckArtist)
	ON_BN_CLICKED(IDC_TAG_CHECK_ALBUM, OnTagCheckAlbum)
	ON_BN_CLICKED(IDC_TAG_CHECK_YEAR, OnTagCheckYear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoTagEdit message handlers

/**
 * User presses a radio button, uncheck all other
 * buttons and check the selected
 */
void CAutoTagEdit::OnRadioCurfile() 
{
	UpdateData(TRUE);
	m_CurFile=0;
	m_CurDir=1;
	m_SubFolders=1;
	UpdateData(FALSE);
}

void CAutoTagEdit::OnRadioCurdir() 
{
	UpdateData(TRUE);
	m_CurFile=1;
	m_CurDir=0;
	m_SubFolders=1;
	UpdateData(FALSE);
}

void CAutoTagEdit::OnRadioSubdir() 
{
	UpdateData(TRUE);
	m_CurFile=1;
	m_CurDir=1;
	m_SubFolders=0;
	UpdateData(FALSE);
}

//--End Radio Button------------------------

/**
 * Save/Set current directory and add a "\" at the end
 */
void CAutoTagEdit::SetDirectory(CString Dir)
{
	if(Dir.Right(1)!="\\")
		Dir+="\\";
	this->m_Dir=Dir;
}

/**
 * Save/Set current file name (inc path)
 */
void CAutoTagEdit::SetFile(CString File)
{
	this->m_File=File;
}

void CAutoTagEdit::OnButtonCreatetag() 
{
	UpdateData(TRUE);

	BeginWaitCursor();

	FindSep(m_TagFileFilter);
	FileFilter(m_TagFileFilter);
	if(m_CurFile==0)
		FindFiles(m_Dir,2,m_File);
	else if(m_CurDir==0)
		FindFiles(m_Dir,1);
	else if(m_SubFolders==0)
		FindFiles(m_Dir);
	EndWaitCursor();
	MessageBox("Mp3 Tag(s) created successfully.","Mp3 File Studio");
}

/**
 * Find all file name separators and put them in a list
 */
void CAutoTagEdit::FindSep(CString List)
{
	char *ch;
	m_ListSep.Clear();
	for(int i=0;i<List.GetLength();i++)
	{
		if(List.GetAt(i)=='%')
		{
			i++;
		}
		else if(List.GetAt(i)!=' ')
		{
			ch=new char;
			*ch=List.GetAt(i);
			m_ListSep.Add(ch);
		}
	}
}

void CAutoTagEdit::FileFilter(CString Filter)
{
	char *ch;
	m_ListName.Clear();
	for(int i=0;i<Filter.GetLength();i++)
	{
		if(Filter.GetAt(i)=='%')
		{
			i++;
			ch=new char;
			*ch=Filter.GetAt(i);
			m_ListName.Add(ch);
		}
	}
}

void CAutoTagEdit::SetTag(int Pos, CString Text)
{
/**
 * %1=Artist
 * %2=Title
 * %3=Album
 * %4=Year
 * %5=Comment
 * %6=Track
 */

	char *ch;
	Text.TrimLeft();
	Text.TrimRight();
	ch=m_ListName.GetItem(Pos);
	if(ch[0]=='1')
	{
		ch=new char[30];
		strncpy(ch,Text,30);
		m_FileInfo->SetArtist(ch);
	}
	else if(ch[0]=='2')
	{
		ch=new char[30];
		strncpy(ch,Text,30);
		m_FileInfo->SetTitle(ch);
	}
	else if(ch[0]=='3')
	{
		ch=new char[30];
		strncpy(ch,Text,30);
		m_FileInfo->SetAlbum(ch);
	}
	else if(ch[0]=='4')
	{
		ch=new char[4];
		strncpy(ch,Text,4);
		m_FileInfo->SetYear(ch);
	}
	else if(ch[0]=='5')
	{
		ch=new char[28];
		strncpy(ch,Text,28);
		m_FileInfo->SetComments(ch);
	}
	else if(ch[0]=='6')
	{
		m_FileInfo->SetTrack((char)atoi(Text));
	}
	delete[] ch;
}

void CAutoTagEdit::SplitFileName(CString Name)
{
	int i(0),StartPos(0), StopPos(0);
	char *ch;
	CString szTemp("");

	for(i=0;i<m_ListSep.GetSize();i++)
	{
		ch=m_ListSep.GetItem(i);
		StopPos=Name.Find(ch[0],StartPos);
		if(StopPos!=-1)
		{
			szTemp=Name.Mid(StartPos,StopPos-StartPos);
			SetTag(i,szTemp);
			StartPos=StopPos+1;
		}
	}
	szTemp="";
	szTemp=Name.Mid(StartPos,Name.GetLength()-StartPos-4);
	if(szTemp!="")
		SetTag(i,szTemp);
	char *tmp;
	if(m_bAlbum==TRUE)
	{
		tmp=new char[strlen(m_Album)+1];
		strcpy(tmp,m_Album);
		m_FileInfo->SetAlbum(tmp);
		delete[] tmp;
	}
	if(m_bArtist==TRUE)
	{
		tmp=new char[strlen(m_Artist)+1];
		strcpy(tmp,m_Artist);
		m_FileInfo->SetArtist(tmp);
		delete[] tmp;
	}
	if(m_bYear==TRUE)
	{
		tmp=new char[strlen(m_Year)+1];
		strcpy(tmp,m_Year);
		m_FileInfo->SetYear(tmp);
		delete[] tmp;
	}
}

/**
 * Mode:
 * 0=Sub Dirs
 * 1=Cur Dir
 * 2=File
 */

void CAutoTagEdit::FindFiles(CString TopFolder,int Mode,CString FileName)
{
	WIN32_FIND_DATA wfd;
	HANDLE hFile;
	CString szTemp=TopFolder;

	if(szTemp.Right(1)!="\\")
	{
		TopFolder+="\\";
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
					szTemp=TopFolder;
					szTemp+=wfd.cFileName;
					FindFiles(szTemp);
				}
			}
			else if(strncmp(&wfd.cFileName[strlen(wfd.cFileName)-5],".mp3",4))
			{
				szTemp=TopFolder;
				szTemp+=wfd.cFileName;
				m_FileInfo=new CMp3FileInfo;
				if(!m_FileInfo->GetMP3Info(szTemp))
				{
					m_FileInfo->NewTag(szTemp);
					m_FileInfo->GetMP3Info(szTemp);
				}
				SplitFileName(wfd.cFileName);
				m_FileInfo->SetMP3Info();
				delete m_FileInfo;
			}
		}while(FindNextFile(hFile,&wfd));
	}
}

void CAutoTagEdit::OnTagCheckArtist() 
{
	m_bArtist=!m_bArtist;
	GetDlgItem(IDC_TAG_EDIT_ARTIST)->EnableWindow(m_bArtist);
}

void CAutoTagEdit::OnTagCheckAlbum() 
{
	m_bAlbum=!m_bAlbum;
	GetDlgItem(IDC_TAG_EDIT_ALBUM)->EnableWindow(m_bAlbum);
}

void CAutoTagEdit::OnTagCheckYear() 
{
	m_bYear=!m_bYear;
	GetDlgItem(IDC_TAG_EDIT_YEAR)->EnableWindow(m_bYear);
}
