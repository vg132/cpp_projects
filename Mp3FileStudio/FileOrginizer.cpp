// FileOrginizer.cpp : implementation file
//

#include "stdafx.h"
#include "Mp3FileStudio.h"
#include "FileOrginizer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileOrginizer property page

IMPLEMENT_DYNCREATE(CFileOrginizer, CPropertyPage)

CFileOrginizer::CFileOrginizer() : CPropertyPage(CFileOrginizer::IDD)
{
	//{{AFX_DATA_INIT(CFileOrginizer)
	m_sTargetFolder = _T("");
	m_iCurDir = -1;
	m_iCurFile = 0;
	m_iSubDirs = -1;
	m_sFolderLayout = _T("");
	m_iCopy = 0;
	m_iMove = -1;
	//}}AFX_DATA_INIT
	m_Dir=NULL;
	m_pImageList=NULL;
	m_File=NULL;
}

CFileOrginizer::~CFileOrginizer()
{
	if(m_Dir!=NULL)
		delete[] m_Dir;
	if(m_pImageList!=NULL)
		delete m_pImageList;
	if(m_File!=NULL)
		delete[] m_File;
}

void CFileOrginizer::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileOrginizer)
	DDX_Control(pDX, IDC_BUTTON_ORGINIZEFILES, m_ButtonOrgenize);
	DDX_Control(pDX, IDC_FILEORGINIZER_PREVIEW, m_Tree);
	DDX_Text(pDX, IDC_FILEORGINIZER_TARGETDIR, m_sTargetFolder);
	DDV_MaxChars(pDX, m_sTargetFolder, 260);
	DDX_Radio(pDX, IDC_RADIO_ORGINIZER_CURDIR, m_iCurDir);
	DDX_Radio(pDX, IDC_RADIO_ORGINIZER_CURFILE, m_iCurFile);
	DDX_Radio(pDX, IDC_RADIO_ORGINIZER_SUBDIR, m_iSubDirs);
	DDX_Text(pDX, IDC_EDIT_FOLDERLAYOUT, m_sFolderLayout);
	DDX_Radio(pDX, IDC_RADIO_COPY, m_iCopy);
	DDX_Radio(pDX, IDC_RADIO_MOVE, m_iMove);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFileOrginizer, CPropertyPage)
	//{{AFX_MSG_MAP(CFileOrginizer)
	ON_BN_CLICKED(IDC_FILEORGINIZER_BROWSE, OnFileorginizerBrowse)
	ON_BN_CLICKED(IDC_RADIO_ORGINIZER_CURFILE, OnRadioOrginizerCurfile)
	ON_BN_CLICKED(IDC_RADIO_ORGINIZER_CURDIR, OnRadioOrginizerCurdir)
	ON_BN_CLICKED(IDC_RADIO_ORGINIZER_SUBDIR, OnRadioOrginizerSubdir)
	ON_BN_CLICKED(IDC_RADIO_COPY, OnRadioCopy)
	ON_BN_CLICKED(IDC_RADIO_MOVE, OnRadioMove)
	ON_EN_CHANGE(IDC_EDIT_FOLDERLAYOUT, OnChangeEditFolderlayout)
	ON_BN_CLICKED(IDC_BUTTON_ORGINIZEFILES, OnButtonOrginizefiles)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileOrginizer message handlers

void CFileOrginizer::OnFileorginizerBrowse() 
{
	char *Path;
	BROWSEINFO bff;
	LPITEMIDLIST pidl;

	UpdateData(TRUE);

	Path=new char[260];

	bff.hwndOwner				= this->m_hWnd;
	bff.iImage					= 0;
	bff.lParam					= 0;
	bff.lpszTitle				= "Please select a target folder";
	bff.pidlRoot				= NULL;
	bff.ulFlags					= BIF_RETURNONLYFSDIRS|BIF_EDITBOX;
	bff.pszDisplayName	= Path;
	bff.lpfn						= NULL;

	pidl=SHBrowseForFolder(&bff);
	if (pidl)
	{
		SHGetPathFromIDList(pidl,Path);
		m_sTargetFolder=Path;
		FileFilter(m_sFolderLayout);
		BuildPreviewTree();
		m_ButtonOrgenize.EnableWindow(TRUE);
		UpdateData(FALSE);
	}
	delete[] Path;
}

void CFileOrginizer::OnRadioOrginizerCurfile() 
{
	UpdateData(TRUE);
	m_iCurFile=0;
	m_iCurDir=1;
	m_iSubDirs=1;
	UpdateData(FALSE);
}

void CFileOrginizer::OnRadioOrginizerCurdir() 
{
	UpdateData(TRUE);
	m_iCurFile=1;
	m_iCurDir=0;
	m_iSubDirs=1;
	UpdateData(FALSE);
}

void CFileOrginizer::OnRadioOrginizerSubdir() 
{
	UpdateData(TRUE);
	m_iCurFile=1;
	m_iCurDir=1;
	m_iSubDirs=0;
	UpdateData(FALSE);
}

void CFileOrginizer::OnRadioCopy() 
{
	UpdateData(TRUE);
	m_iCopy=0;
	m_iMove=1;
	UpdateData(FALSE);	
}

void CFileOrginizer::OnRadioMove() 
{
	UpdateData(TRUE);
	m_iCopy=1;
	m_iMove=0;
	UpdateData(FALSE);
}

void CFileOrginizer::FileFilter(CString Filter)
{
	char *ch;
	m_ListLayout.Clear();
	for(int i=0;i<Filter.GetLength();i++)
	{
		if(Filter.GetAt(i)=='%'&&i!=Filter.GetLength()-1)
		{
			i++;
			ch=new char;
			*ch=Filter.GetAt(i);
			m_ListLayout.Add(ch);
		}
	}
}

void CFileOrginizer::OnChangeEditFolderlayout() 
{
	UpdateData(TRUE);
	FileFilter(m_sFolderLayout);
	BuildPreviewTree();
}

void CFileOrginizer::BuildPreviewTree()
{
	m_Tree.DeleteAllItems();
	if(m_sTargetFolder!="")
	{
		char* tmp=new char[m_sTargetFolder.GetLength()+1];
		strcpy(tmp,m_sTargetFolder);
		strcat(tmp,"\0");
		hChild = BuildNode(tmp,0,1,NULL,TVI_ROOT);
		delete[] tmp;
	}	
	else
		hChild = BuildNode("Root",0,1,NULL,TVI_ROOT);
	for(int i=0;i<m_ListLayout.GetSize();i++)
	{
		switch(*m_ListLayout.GetItem(i))
		{
			case '1':
				hChild = BuildNode("Artist",0,1,NULL,hChild);
				break;
			case '2':
				hChild = BuildNode("Title",0,1,NULL,hChild);
				break;
			case '3':
				hChild = BuildNode("Album",0,1,NULL,hChild);
				break;
			case '4':
				hChild = BuildNode("Year",0,1,NULL,hChild);
				break;
			case '5':
				hChild = BuildNode("Comments",0,1,NULL,hChild);
				break;
			case '6':
				hChild = BuildNode("Genre",0,1,NULL,hChild);
				break;
		}
	}
	hChild = BuildNode("Mp3 File(s)",2,2,NULL,hChild);
	m_Tree.EnsureVisible(hChild);
}

HTREEITEM CFileOrginizer::BuildNode(LPSTR szText, int Image, int SelectedImage, char* id, HTREEITEM Parant)
{
	TV_ITEM tvItem;
	TV_INSERTSTRUCT tvIns;

	// The pszText, iImage, and iSelectedImage members are filled out.
	tvItem.mask = TVIF_TEXT | TVIF_PARAM|TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	tvItem.pszText=szText;
	tvItem.iImage = Image;
	tvItem.iSelectedImage = SelectedImage;
	tvItem.lParam =(long)id;

	tvIns.hParent = Parant;
	tvIns.hInsertAfter = TVI_LAST;
	tvIns.item=tvItem;

	return(m_Tree.InsertItem(&tvIns));
}

BOOL CFileOrginizer::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	CMp3FileStudioApp* pApp;
	pApp = (CMp3FileStudioApp*)AfxGetApp();

	m_pImageList=new CImageList();
	m_pImageList->Create(16, 16, ILC_MASK|ILC_COLOR8, 2, 2);
	m_pImageList->Add(pApp->LoadIcon(IDI_FOLDERCLOSED));
	m_pImageList->Add(pApp->LoadIcon(IDI_FOLDEROPEN));
	m_pImageList->Add(pApp->LoadIcon(IDI_MP3ICON));

	m_Tree.SetImageList(m_pImageList,TVSIL_NORMAL);
	hChild = BuildNode("Root",0,1,NULL,TVI_ROOT);
	hChild = BuildNode("Mp3 File(s)",2,2,NULL,hChild);
	m_Tree.EnsureVisible(hChild);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

bool CFileOrginizer::FixFile(char* FileName, char* FileTitle)
{
	CString szTmp("");
	m_pMp3FileInfo = new CMp3FileInfo;
	if(!m_pMp3FileInfo->GetMP3Info(FileName))
		return(false);
	szTmp=CreateFolders();
	if(szTmp=="")
		return(false);

	szTmp+=FileTitle;
	if(m_iCopy==0)
		CopyFile(FileName,szTmp,false);
	else
		MoveFile(FileName,szTmp);

	return(true);
}

CString CFileOrginizer::CreateFolders()
{
	UpdateData(TRUE);
	for(int i=0;i<m_ListLayout.GetSize();i++)
	{
		if(m_sTargetFolder.Right(1)!="\\")
			m_sTargetFolder+="\\";
		switch(*m_ListLayout.GetItem(i))
		{
			case '1':
				m_sTargetFolder+=m_pMp3FileInfo->GetArtist();
				CreateDirectory(m_sTargetFolder,NULL);
				break;
			case '2':
				m_sTargetFolder+=m_pMp3FileInfo->GetTitle();
				CreateDirectory(m_sTargetFolder,NULL);
				break;
			case '3':
				m_sTargetFolder+=m_pMp3FileInfo->GetAlbum();
				CreateDirectory(m_sTargetFolder,NULL);
				break;
			case '4':
				m_sTargetFolder+=m_pMp3FileInfo->GetYear();
				CreateDirectory(m_sTargetFolder,NULL);
				break;
			case '5':
				m_sTargetFolder+=m_pMp3FileInfo->GetArtist();
				CreateDirectory(m_sTargetFolder,NULL);
				break;
			case '6':
				m_sTargetFolder+=GetGenreName((unsigned char)m_pMp3FileInfo->GetGenre());
				CreateDirectory(m_sTargetFolder,NULL);
				break;
		}
	}
	if(m_sTargetFolder.Right(1)!="\\")
		m_sTargetFolder+="\\";
	return(m_sTargetFolder);
}

void CFileOrginizer::OnButtonOrginizefiles() 
{
	char* FileName;
	char FileTitle[260], Ext[260];//,Folder[260],Drive[260];
	BeginWaitCursor();
	m_Progress.Create(IDD_PROGRESS);
	m_Progress.ShowWindow(SW_SHOW);
	m_Progress.CenterWindow();
	m_Progress.SetText("Searching for Mp3 files...");
	if(m_iCurDir==0)
		m_FileList.FindFiles(m_Dir,1,"*.mp3");
	else if(m_iSubDirs==0)
		m_FileList.FindFiles(m_Dir,0,"*.mp3");
	m_Progress.SetProgressBar(m_FileList.GetNrOfFiles());
	m_Progress.SetHeader("Processing");
	do
	{
		FileName=m_FileList.Pop();
		if(FileName!=NULL)
		{
			_splitpath(FileName,NULL,NULL,FileTitle,Ext);

			char* tmp2=new char[1000];
			sprintf(tmp2,"%s%s",FileTitle,Ext);
			m_Progress.SetText(tmp2);
			m_Progress.StepProgressBar();
			delete[] tmp2;

			strcat(FileTitle,Ext);
			FixFile(FileName,FileTitle);
			delete[] FileName;
		}
	}while(FileName!=NULL);
	EndWaitCursor();
	m_Progress.DestroyWindow();
}

void CFileOrginizer::SetDirectory(CString dir)
{
	if(m_Dir!=NULL)
		delete[] m_Dir;
	m_Dir=new char[dir.GetLength()+1];
	strcpy(m_Dir,dir);
	strcat(m_Dir,"\0");
}

void CFileOrginizer::SetFile(CString file)
{
	if(m_File!=NULL)
		delete[] m_File;
	m_File=new char[file.GetLength()+1];
	strcpy(m_File,file);
	strcat(m_File,"\0");
}

CString CFileOrginizer::GetGenreName(int id)
{
	int start(-1);
	int end(0);
	CString tmp = "Blues|Classic Rock|Country|Dance|Disco|Funk|Grunge|Hip-Hop|Jazz|Metal|New Age|Oldies|Other|Pop|R&B|Rap|Reggae|Rock|Techno|Industrial|Alternative|Ska|Death Metal|Pranks|Soundtrack|Euro-Techno|Ambient|Trip Hop|Vocal|Jazz+Funk|Fusion|Trance|Classical|Instrumental|Acid|House|Game|Sound Clip|Gospel|Noise|Alt. Rock|Bass|Soul|Punk|Space|Meditative|Instrumental Pop|Instrumental Rock|Ethnic|Gothic|Darkwave|Techno-Industrial|Electronic|Pop-Folk|Eurodance|Dream|Southern Rock|Comedy|Cult|Gangsta Rap|Top 40|Christian Rap|Pop/Punk|Jungle|Native American|Cabaret|New Wave|Phychedelic|Rave|Showtunes|Trailer|Lo-Fi|Tribal|Acid Punk|Acid Jazz|Polka|Retro|Musical|Rock & Roll|Hard Rock|Folk|Folk/Rock|National Folk|Swing|Fast-Fusion|Bebob|Latin|Revival|Celtic|Blue Grass|Avantegarde|Gothic Rock|Progressive Rock|Psychedelic Rock|Symphonic Rock|Slow Rock|Big Band|Chorus|Easy Listening|Acoustic|Humour|Speech|Chanson|Opera|Chamber Music|Sonata|Symphony|Booty Bass|Primus|Porn Groove|Satire|Slow Jam|Club|Tango|Samba|Folklore|Ballad|power Ballad|Rhythmic Soul|Freestyle|Duet|Punk Rock|Drum Solo|A Capella|Euro-House|Dance Hall|Goa|Drum & Bass|Club-House|Hardcore|Terror|Indie|Brit Pop|Negerpunk|Polsk Punk|Beat|Christian Gangsta Rap|Heavy Metal|Black Metal|Crossover|Comteporary Christian|Christian Rock|Merengue|Salsa|Trash Metal|Anime|JPop|Synth Pop|";
	for(int i = 0;i<id;i++)
		start = tmp.Find("|",++start);
	end = tmp.Find("|",++start);
	return(tmp.Mid(start,(end-start)));
}
