// FileListView.cpp : implementation file
//

#include "stdafx.h"
#include "FileListView.h"
#include "Mp3FileStudio.h"
#include <direct.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileListView

CFileListView::CFileListView()
{
	m_Move = FALSE;
	m_Copy=FALSE;
}

CFileListView::~CFileListView()
{

}


BEGIN_MESSAGE_MAP(CFileListView, CListCtrl)
	//{{AFX_MSG_MAP(CFileListView)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemchanged)
	ON_NOTIFY_REFLECT(LVN_KEYDOWN, OnKeydown)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_COMMAND(ID_EDIT_DELETE, OnEditDelete)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_EDIT_PLAY, OnEditPlay)
	ON_COMMAND(ID_EDIT_CLEARID3TAG, OnEditClearid3tag)
	ON_COMMAND(ID_EDIT_REMOVEID3TAG, OnEditRemoveid3tag)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileListView message handlers

int CALLBACK CFileListView::CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	FileInfo *fi1=(FileInfo*)lParam1;
	FileInfo *fi2=(FileInfo*)lParam2;

	// Always place folders ontop of files
	if((fi1->File==FALSE)&&(fi2->File==TRUE))
		return(-1);
	else if((fi1->File==TRUE)&&(fi2->File==FALSE))
		return(1);

	// 0 equals sort by file name
	if(lParamSort==0)
	{
		return(stricmp(fi1->FileName,fi2->FileName));
	}
	else if(lParamSort==1)
	{
		if(fi1->File==FALSE)
			return(stricmp(fi1->FileName,fi2->FileName));
		else
			return(fi1->Size - fi2->Size);
	}
	else if(lParamSort==2)
	{
		return(fi1->Changed.dwHighDateTime - fi2->Changed.dwHighDateTime);
	}
	return(-1);
}

int CFileListView::GetIconIndex(const CString &FileName)
{
	SHFILEINFO    sfi;
	SHGetFileInfo((LPCTSTR)FileName,
								0,
								&sfi,
								sizeof(SHFILEINFO),
								SHGFI_SYSICONINDEX|SHGFI_SMALLICON);

	return sfi.iIcon;
}

bool CFileListView::InitFileList(CWnd *pParentWnd, char *FilePattern, CImageList *Small, CImageList *Large, UINT msg)
{
	this->SetImageList(Small,LVSIL_SMALL);
	this->SetImageList(Large,LVSIL_NORMAL);
	this->InsertColumn(0,"Name",NULL,200);
	this->InsertColumn(1,"Size",NULL,100,1);
	this->InsertColumn(2,"Modified",NULL,100,0);
	this->SetExtendedStyle(LVS_EX_FULLROWSELECT);
	GetDrivers();
	m_pParentWnd=pParentWnd;
	m_Msg=msg;
	SplitPatterns(FilePattern);
	return(true);
}

void CFileListView::SetDirectory(CString Path)
{
	WIN32_FIND_DATA wfd;
	HANDLE hFile;
	SYSTEMTIME SystemTime;

	LVITEMA lvI;
	FileInfo *fi;
	CString szPath(Path);
	CString szTemp("");
	int Pos(0);
	int Size(0);
	char ch[30];
	this->SetRedraw(FALSE);
	if(Path=="My Computer")
	{
		m_CurrentPath="My Computer";
		MyComputer();
	}
	else
	{
		if(_chdrive(Path.GetAt(0)-'A'+1))
		{

			szTemp.Empty();
			szTemp.Format("Drive %c is not available", Path.GetAt(0));
			MessageBox(szTemp);
			this->SetRedraw(TRUE);
			return;
		}
		GetSystemTime(&SystemTime);
		if(szPath.Right(1)!="\\")
		{
			szPath+="\\*.*";
			Path+="\\";
		}
		else
			szPath+="*.*";

		this->DeleteAllItems();
		m_CurrentPath=Path;
		// Standard listview item
		lvI.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
		lvI.state = 0; 
		lvI.stateMask = 0;
		lvI.iItem=0;
		lvI.iSubItem = 0;
		

		hFile = FindFirstFile(szPath,&wfd);
		if(hFile!=(HANDLE)-1)
		{
			do
			{
				if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if(wfd.cFileName[0]!='.')
					{
						fi=new FileInfo;
						strcpy(fi->FileName,wfd.cFileName);
						fi->File=FALSE;
						fi->Size=0;
						fi->Changed = wfd.ftLastWriteTime;
						lvI.pszText = wfd.cFileName;
						szTemp=Path;
						szTemp+=wfd.cFileName;
						lvI.iImage=GetIconIndex(szTemp);
						lvI.pszText = wfd.cFileName;
						lvI.lParam = (LPARAM)fi;
						Pos = this->InsertItem(&lvI);
						this->SetItem(Pos,1,LVIF_TEXT,"",NULL,NULL,NULL,NULL);
						FileTimeToSystemTime(&wfd.ftLastWriteTime,&SystemTime);
						sprintf(ch,"%d-%.2d-%.2d %.2d:%.2d",SystemTime.wYear,SystemTime.wMonth,SystemTime.wDay,SystemTime.wHour,SystemTime.wMinute);
						this->SetItem(Pos,2,LVIF_TEXT,ch,NULL,NULL,NULL,NULL);
					}
				}
				else
				{
					szTemp=wfd.cFileName;
					Pos = szTemp.ReverseFind('.');
					if(Pos!=-1)
					{
						szTemp=szTemp.Mid(Pos+1);
						for(int i=0;i<m_PatternList.GetSize();i++)
						{
							if((stricmp(szTemp,m_PatternList.GetItem(i))==0)||(stricmp("*",m_PatternList.GetItem(i))==0))
							{
								szTemp=Path;
								szTemp+=wfd.cFileName;
								fi=new FileInfo;
								strcpy(fi->FileName,wfd.cFileName);
								fi->File=TRUE;
								fi->Size=wfd.nFileSizeLow;
								fi->Changed = wfd.ftLastWriteTime;
								lvI.pszText = wfd.cFileName;
								lvI.iImage = GetIconIndex(szTemp);
								lvI.pszText = wfd.cFileName;
								lvI.lParam = (LPARAM)fi;
								Pos = this->InsertItem(&lvI);
								Size=wfd.nFileSizeLow;
								itoa(Size/1000,ch,10);
								strcat(ch," KB");
								this->SetItem(Pos,1,LVIF_TEXT,ch,NULL,NULL,NULL,NULL);
								FileTimeToSystemTime(&wfd.ftLastWriteTime,&SystemTime);
								sprintf(ch,"%d-%.2d-%.2d %.2d:%.2d",SystemTime.wYear,SystemTime.wMonth,SystemTime.wDay,SystemTime.wHour,SystemTime.wMinute);
								this->SetItem(Pos,2,LVIF_TEXT,ch,NULL,NULL,NULL,NULL);
								break;
							}
						}
					}
				}
			}while(FindNextFile(hFile,&wfd));
		}
		this->SortItems((PFNLVCOMPARE)CompareFunc,(LPARAM)0);
	}
	this->SetRedraw(TRUE);
}

CString CFileListView::GetDirectory()
{
	return(m_CurrentPath);
}

CString CFileListView::GetFile()
{
	CString szTmp;
	int iSelItem(0);
	POSITION pos;
	pos =this->GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		iSelItem=this->GetNextSelectedItem(pos);
		szTmp = this->GetItemText(iSelItem,0);
		szTmp.Insert(0,m_CurrentPath);
		return(szTmp);
	}
	return("");
}

void CFileListView::SplitPatterns(char *FilePattern)
{
	char *temp;
	unsigned int start(0);
	for(unsigned int i=0;i<strlen(FilePattern);i++)
	{
		if(FilePattern[i]==';')
		{
			temp=new char[strlen(FilePattern)+1];
			strncpy(temp,&FilePattern[start],i-start);
			temp[i-start]='\0';
			m_PatternList.Add(temp);
			start=i+1;
		}
		else if(FilePattern[i]=='.')
			start=i+1;
	}
	if(start<strlen(FilePattern))
	{
		temp=new char[strlen(FilePattern)+1];
		strncpy(temp,&FilePattern[start],strlen(FilePattern)-start);
		temp[strlen(FilePattern)-start]='\0';
		m_PatternList.Add(temp);
	}
}

void CFileListView::MyComputer()
{
	Drive *drive;
	LVITEMA lvI;
	FileInfo *fi;
	this->DeleteAllItems();
	// Standard listview item
	lvI.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
	lvI.state = 0; 
	lvI.stateMask = 0;
	lvI.iItem=0;
	lvI.iSubItem = 0;

	for(int i=0;i<m_DriveList.GetSize();i++)
	{
		fi=new FileInfo;
		drive=m_DriveList.GetItem(i);
		lvI.pszText = drive->DriveTitle;
		lvI.iImage=GetIconIndex(drive->DriveLetter);
		strcpy(fi->FileName,drive->DriveLetter);
		fi->File=FALSE;
		lvI.lParam=(LPARAM)fi;
		this->InsertItem(&lvI);
	}
	this->SortItems((PFNLVCOMPARE)CompareFunc,(LPARAM)0);
}

void CFileListView::Up1Level()
{
	int i(0);
	CString szTemp;
	if(m_CurrentPath.GetLength()<0)
		return;
	szTemp = m_CurrentPath.Mid(0,m_CurrentPath.GetLength()-1);
	i = szTemp.ReverseFind('\\');
	if(i!=-1)
	{
		m_CurrentPath = m_CurrentPath.Mid(0,i);
		SetDirectory(m_CurrentPath);
	}
	else
	{
		m_CurrentPath="My Computer";
		MyComputer();
	}
	m_pParentWnd->SendMessage(m_Msg,WM_CHANGEDFOLDER,0);
	m_SelectedFileType = 0;
}

void CFileListView::GetDrivers()
{
char *drv  = new char[260];
int drvType(0);
int dCount(0);
Drive *drive;
char tmp[2];
	dCount=GetLogicalDriveStrings(260,drv);
	dCount/=4;
	for(int i=0;i<dCount;i++)
	{
		drive=new Drive;
		strncpy(drive->DriveLetter,&drv[i*4],3);
		if(drive->DriveLetter[0]>='a')
			drive->DriveLetter[0]-=32;
		drive->DriveLetter[3]='\0';
		drive->DriveType=GetDriveType(drive->DriveLetter);
		drive->DriveName[0]='\0';
		if(drive->DriveType!=DRIVE_REMOVABLE)
			GetVolumeInformation(drive->DriveLetter,drive->DriveName,20,NULL,NULL,NULL,NULL,NULL);
		if(drive->DriveName[0]=='\0')
			strcpy(drive->DriveName,"No Name");
		drive->DriveTitle[0]='\0';
		strcat(drive->DriveTitle,drive->DriveName);
		strcat(drive->DriveTitle," (");
		tmp[0]=drive->DriveLetter[0];
		tmp[1]='\0';
		strcat(drive->DriveTitle,tmp);
		strcat(drive->DriveTitle,":)\0");
		m_DriveList.Add(drive);
	}
}

void CFileListView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	POSITION pos;
	WIN32_FIND_DATA wfd;
	HANDLE hFile((HANDLE)-1);
	CString szTmp;
	Drive *drive;
	int iSelItem;

	pos=this->GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		iSelItem=this->GetNextSelectedItem(pos);
		if(this->GetDirectory()=="My Computer")
		{
			drive=this->m_DriveList.GetItem(iSelItem);
			this->SetDirectory(drive->DriveLetter);
			m_pParentWnd->SendMessage(m_Msg,WM_CHANGEDFOLDER,0);
		}
		else
		{
			szTmp=this->GetDirectory();
			szTmp+=this->GetItemText(iSelItem,0);
			hFile=FindFirstFile(szTmp,&wfd);
			if(hFile!=(HANDLE)-1&&wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				this->SetDirectory(szTmp);
				m_pParentWnd->SendMessage(m_Msg,WM_CHANGEDFOLDER,0);
			}
		}
	}
	*pResult = 0;
}

void CFileListView::OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;

	WIN32_FIND_DATA wfd;
	HANDLE hFile(0);
	CString szTmp("");
	szTmp=this->GetFile();
	if(szTmp!=""&&m_CurrentFile!=szTmp)
	{
		m_CurrentFile=szTmp;
		hFile=FindFirstFile(szTmp,&wfd);
		if(hFile!=(HANDLE)-1)
		{
			if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				m_pParentWnd->SendMessage(m_Msg,WM_FOLDERSELECTED,0);
				m_SelectedFileType=1;
			}
			else
			{
				m_pParentWnd->SendMessage(m_Msg,WM_FILESELECTED,0);
				m_CurrentFile=szTmp;
				m_SelectedFileType=2;
			}
		}
	}
	else
	{
		m_pParentWnd->SendMessage(m_Msg,WM_NONSELECTED,0);
		m_CurrentFile="";
		m_SelectedFileType=0;
	}
	*pResult = 0;
}

void CFileListView::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;

	if(pLVKeyDow->wVKey==VK_BACK)
		this->Up1Level();
	else if(pLVKeyDow->wVKey==VK_F5)
		this->SetDirectory(this->GetDirectory());

	*pResult = 0;
}

void CFileListView::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_SelectedFileType!=2&&m_File=="")
		return;
	CMenu main;
	main.LoadMenu(IDR_POPUP);
	CMenu* editMenu;
	if(m_SelectedFileType!=2)
		editMenu = main.GetSubMenu(1);
	else
		editMenu = main.GetSubMenu(0);

	CPoint pt;
	GetCursorPos(&pt);
	editMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt.x, pt.y, this);

	*pResult = 0;
}

void CFileListView::SetPlayer(CString player)
{
	m_Player=player;
}

void CFileListView::OnEditDelete() 
{
	char buffer[300];
	sprintf(buffer,"Are you sure you want to delete '%s'?",GetFile());
	if(MessageBox(buffer,"Confirm File Delete",MB_YESNO|MB_ICONQUESTION)==IDYES)
		DeleteFile(GetFile());
	this->SetDirectory(this->GetDirectory());
}

void CFileListView::OnEditCopy() 
{
	m_Copy=TRUE;
	m_File=GetFile();
}

void CFileListView::OnEditCut() 
{
	m_Move=TRUE;
	m_File = GetFile();
}

void CFileListView::OnEditPaste() 
{
	BeginWaitCursor();
	char buffer[260];
	if(m_Move==TRUE)
	{
		sprintf(buffer,"%s%s",GetDirectory(),GetFileTitle(m_File));
		MoveFile(m_File,buffer);
		m_Move=FALSE;
		this->SetDirectory(this->GetDirectory());
	}
	else if(m_Copy==TRUE)
	{
		sprintf(buffer,"%s%s",GetDirectory(),GetFileTitle(m_File));
		if(!CopyFile(m_File,buffer,true))
		{
			char buffer2[255];
			sprintf(buffer2,"This folder already contains a file named '%s'.\n\nWould you like to replace the existing file?",GetFileTitle(m_File));
			if(MessageBox(buffer2,"Confirm File Replace",MB_YESNO|MB_ICONQUESTION)==IDYES)
				CopyFile(m_File,buffer,false);
		}
		this->SetDirectory(this->GetDirectory());
	}
	EndWaitCursor();
}

CString CFileListView::GetFileTitle(CString path)
{
	int i(0);
	i=path.GetLength();
	do
	{
		i--;
	}while(path.GetAt(i)!='\\');
	return(path.Mid(++i));
}

void CFileListView::OnEditPlay() 
{
	if(m_Player!="")
	{
		char *buffer;
		buffer=new char[260];
		sprintf(buffer,"\"%s\"",GetFile());
		ShellExecute(NULL,"open",m_Player,buffer,NULL,1);
		delete buffer;
	}
}

void CFileListView::OnEditClearid3tag() 
{
	m_pParentWnd->SendMessage(m_Msg,WM_SAVEFILE,0);
	m_pMp3FileInfo=new CMp3FileInfo;
	m_pMp3FileInfo->GetMP3Info(GetFile());
	m_pMp3FileInfo->RemoveTag();
	m_pMp3FileInfo->NewTag(GetFile());
	delete m_pMp3FileInfo;
	m_CurrentFile="";
	m_SelectedFileType=0;
}

void CFileListView::OnEditRemoveid3tag() 
{
	m_pParentWnd->SendMessage(m_Msg,WM_SAVEFILE,0);
	m_pMp3FileInfo=new CMp3FileInfo;
	m_pMp3FileInfo->GetMP3Info(GetFile());
	m_pMp3FileInfo->RemoveTag();
	delete m_pMp3FileInfo;
	m_CurrentFile="";
	m_SelectedFileType=0;
}