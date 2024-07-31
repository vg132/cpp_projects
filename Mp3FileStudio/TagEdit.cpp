// TagEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Mp3FileStudio.h"
#include "TagEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTagEdit property page

IMPLEMENT_DYNCREATE(CTagEdit, CPropertyPage)

CTagEdit::CTagEdit() : CPropertyPage(CTagEdit::IDD)
{
	//{{AFX_DATA_INIT(CTagEdit)
	m_Album = _T("");
	m_Artist = _T("");
	m_AutoSave = FALSE;
	m_Bitrate = _T("");
	m_Comments = _T("");
	m_Copyright = _T("");
	m_CRC = _T("");
	m_Emphasis = _T("");
	m_FileSize = _T("");
	m_Frequency = _T("");
	m_MpegVersion = _T("");
	m_Original = _T("");
	m_Title = _T("");
	m_Year = _T("");
	m_Length = _T("");
	m_Track = 0;
	//}}AFX_DATA_INIT
	m_FileInfo=NULL;
}

CTagEdit::~CTagEdit()
{
	if(m_FileInfo!=NULL)
		delete m_FileInfo;
}

void CTagEdit::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTagEdit)
	DDX_Control(pDX, IDC_GENRE, m_Genre);
	DDX_Text(pDX, IDC_ALBUM, m_Album);
	DDV_MaxChars(pDX, m_Album, 30);
	DDX_Text(pDX, IDC_ARTIST, m_Artist);
	DDV_MaxChars(pDX, m_Artist, 30);
	DDX_Check(pDX, IDC_AUTOSAVE, m_AutoSave);
	DDX_Text(pDX, IDC_BITRATE, m_Bitrate);
	DDX_Text(pDX, IDC_COMMENTS, m_Comments);
	DDV_MaxChars(pDX, m_Comments, 28);
	DDX_Text(pDX, IDC_COPYRIGHT, m_Copyright);
	DDX_Text(pDX, IDC_CRC, m_CRC);
	DDX_Text(pDX, IDC_EMPHASIS, m_Emphasis);
	DDX_Text(pDX, IDC_FILESIZE, m_FileSize);
	DDX_Text(pDX, IDC_FREQUENCY, m_Frequency);
	DDX_Text(pDX, IDC_MPEGVERSION, m_MpegVersion);
	DDX_Text(pDX, IDC_ORIGINAL, m_Original);
	DDX_Text(pDX, IDC_TITLE, m_Title);
	DDV_MaxChars(pDX, m_Title, 30);
	DDX_Text(pDX, IDC_YEAR, m_Year);
	DDV_MaxChars(pDX, m_Year, 4);
	DDX_Text(pDX, IDC_LENGTH, m_Length);
	DDX_Text(pDX, IDC_TRACK, m_Track);
	DDV_MinMaxInt(pDX, m_Track, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTagEdit, CPropertyPage)
	//{{AFX_MSG_MAP(CTagEdit)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTagEdit message handlers

void CTagEdit::SetFile(CString FileName, bool Silent)
{
	BeginWaitCursor();
	char *info=new char[31];
	UpdateData(TRUE);
	if(m_FileInfo!=NULL)
	{
		if(m_AutoSave==TRUE)
			SaveTag();
		delete m_FileInfo;
		m_FileInfo=NULL;
	}
	m_FileInfo=new CMp3FileInfo;
	if(!Silent)
		ResetControls();
	if(m_FileInfo->GetMP3Info(FileName))
	{
		EnableTagEdit(true);
		info[30]='\0';
		// Load tag data from file
		info=m_FileInfo->GetArtist();
		info[30]='\0';
		m_Artist=info;
		m_Artist.TrimRight();
		
		info=m_FileInfo->GetTitle();
		info[30]='\0';
		m_Title=info;
		m_Title.TrimRight();

		info=m_FileInfo->GetAlbum();
		info[30]='\0';
		m_Album=info;
		m_Album.TrimRight();

		info=m_FileInfo->GetComments();
		info[30]='\0';
		m_Comments=info;
		m_Comments.TrimRight();

		info=m_FileInfo->GetYear();
		info[4]='\0';
		m_Year=info;

		m_Genre.SetCurSel((unsigned char)m_FileInfo->GetGenre());

		m_Track=m_FileInfo->GetTrack();

		// Load mp3 info data from file
		m_MpegVersion=m_FileInfo->GetMpegVersion();
		info = m_FileInfo->GetMpegLayer();
		m_MpegVersion+=", ";
		m_MpegVersion+=info;
		
		m_CRC="CRC: ";
		m_CRC+=m_FileInfo->GetCRC();
		m_Copyright="Copyrighted: ";
		m_Copyright+=m_FileInfo->GetCopyright();
		m_Emphasis="Emphasis: ";
		m_Emphasis+=m_FileInfo->GetEmphasis();
		m_Original="Original: ";
		m_Original+=m_FileInfo->GetOriginal();
		
		info=new char[20];
		itoa(m_FileInfo->GetBitrate(),info,10);
		m_Bitrate=info;
		m_Bitrate+="kbits";
		m_Bitrate+=", ";
		itoa(m_FileInfo->GetFrames(),info,10);
		m_Bitrate+=info;
		m_Bitrate+=" frames";
		itoa(m_FileInfo->GetFrequency(),info,10);
		m_Frequency=info;
		m_Frequency+="hz";
		m_Frequency+=" ";
		m_Frequency+=m_FileInfo->GetChannelMode();
		itoa(m_FileInfo->GetFileSize(),info,10);
		m_FileSize="File size: ";
		m_FileSize+=info;
		m_FileSize+=" bites";
		itoa(m_FileInfo->GetLength(),info,10);
		m_Length=info;
		m_Length+=" seconds";
		delete[] info;
	}
	else if(!Silent)
	{
		if(MessageBox("No MP3 Tag was found on this file. Do you want to add one?","New Mp3 Tag",MB_YESNO)==IDYES)
		{
			m_FileInfo->NewTag(FileName);
			SetFile(FileName,Silent);
		}
		else
		{
			delete m_FileInfo;
			m_FileInfo=NULL;
			EnableTagEdit(false);
		}
	}
	else if(Silent)
	{
		delete m_FileInfo;
		m_FileInfo=NULL;
		EnableTagEdit(false);
	}
	UpdateData(FALSE);
	EndWaitCursor();
}

void CTagEdit::EnableTagEdit(bool enable)
{
	if(m_CurrentState!=enable)
	{
		m_CurrentState=enable;
		m_Artist="";
		m_Title="";
		m_Album="";
		m_Comments="";
		m_Year="";
		m_Genre.SetCurSel(0);
		m_MpegVersion="";
		m_CRC="";
		m_Copyright="";
		m_Emphasis="";
		m_Original="";
		m_Bitrate="";
		m_Frequency="";
		m_FileSize="";
		m_Length="";
		m_Track = 0;

		GetDlgItem(IDC_TITLE)->EnableWindow(enable);
		GetDlgItem(IDC_ALBUM)->EnableWindow(enable);
		GetDlgItem(IDC_ARTIST)->EnableWindow(enable);
		GetDlgItem(IDC_YEAR)->EnableWindow(enable);
		GetDlgItem(IDC_GENRE)->EnableWindow(enable);
		GetDlgItem(IDC_COMMENTS)->EnableWindow(enable);

		GetDlgItem(IDC_COPYRIGHT)->EnableWindow(enable);
		GetDlgItem(IDC_LENGTH)->EnableWindow(enable);
		GetDlgItem(IDC_MPEGVERSION)->EnableWindow(enable);
		GetDlgItem(IDC_FREQUENCY)->EnableWindow(enable);
		GetDlgItem(IDC_FILESIZE)->EnableWindow(enable);
		GetDlgItem(IDC_ORIGINAL)->EnableWindow(enable);
		GetDlgItem(IDC_BITRATE)->EnableWindow(enable);
		GetDlgItem(IDC_CRC)->EnableWindow(enable);
		GetDlgItem(IDC_EMPHASIS)->EnableWindow(enable);

		GetDlgItem(IDC_STATIC_TAGFRAME)->EnableWindow(enable);
		GetDlgItem(IDC_STATIC_FILEINFO)->EnableWindow(enable);
		GetDlgItem(IDC_STATIC_TITLE)->EnableWindow(enable);
		GetDlgItem(IDC_STATIC_ALBUM)->EnableWindow(enable);
		GetDlgItem(IDC_STATIC_ARTIST)->EnableWindow(enable);
		GetDlgItem(IDC_STATIC_YEAR)->EnableWindow(enable);
		GetDlgItem(IDC_STATIC_GENRE)->EnableWindow(enable);
		GetDlgItem(IDC_STATIC_COMMENTS)->EnableWindow(enable);
		GetDlgItem(IDC_AUTOSAVE)->EnableWindow(enable);
		GetDlgItem(IDC_STATIC_TRACK)->EnableWindow(enable);
		GetDlgItem(IDC_TRACK)->EnableWindow(enable);
		UpdateData(FALSE);
	}
}

void CTagEdit::SaveTag()
{
	if(UpdateData(TRUE)&&m_CurrentState==true&&m_FileInfo!=NULL)
	{
		char *info = new char[31];
		strcpy(info,m_Title);
		m_FileInfo->SetTitle(info);
		strcpy(info,m_Artist);
		m_FileInfo->SetArtist(info);
		strcpy(info,m_Comments);
		m_FileInfo->SetComments(info);
		strcpy(info,m_Album);
		m_FileInfo->SetAlbum(info);
		delete[] info;
		info=new char[5];
		strcpy(info,m_Year);
		m_FileInfo->SetYear(info);
		m_FileInfo->SetGenre((char)m_Genre.GetCurSel());
		m_FileInfo->SetTrack((char)m_Track);
		m_FileInfo->SetMP3Info();
		delete[] info;
	}
}

void CTagEdit::DisableAndSave()
{
	UpdateData(TRUE);
	if(m_FileInfo!=NULL)
	{
		if(m_AutoSave==TRUE)
			SaveTag();
		delete m_FileInfo;
		m_FileInfo=NULL;
	}
	EnableTagEdit(false);
}

void CTagEdit::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CPropertyPage::OnShowWindow(bShow, nStatus);
	if(!bShow)
		DisableAndSave();
}

int CTagEdit::GetAutoSave()
{
	UpdateData(TRUE);
	return(m_AutoSave);
}

void CTagEdit::SetAutoSave(int autosave)
{
	UpdateData(TRUE);
	m_AutoSave=autosave;
	UpdateData(FALSE);
}

void CTagEdit::ResetControls()
{
	m_Album = _T("");
	m_Artist = _T("");
	m_Bitrate = _T("");
	m_Comments = _T("");
	m_Copyright = _T("");
	m_CRC = _T("");
	m_Emphasis = _T("");
	m_FileSize = _T("");
	m_Frequency = _T("");
	m_MpegVersion = _T("");
	m_Original = _T("");
	m_Title = _T("");
	m_Year = _T("");
	m_Length = _T("");
	m_Genre.SetCurSel(0);
	m_Track = 0;
	UpdateData(FALSE);
}
