// FileComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "FileComboBox.h"
#include "Mp3FileStudio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileComboBox

CFileComboBox::CFileComboBox()
{
}

CFileComboBox::~CFileComboBox()
{
}


BEGIN_MESSAGE_MAP(CFileComboBox, CComboBoxEx)
	//{{AFX_MSG_MAP(CFileComboBox)
	ON_CONTROL_REFLECT(CBN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileComboBox message handlers

void CFileComboBox::GetDrives()
{
char *drv  = new char[260];
int drvType(0);
int dCount(0);
Drive *drive;
char tmp[2];
	drive=new Drive;
	drive->DriveLetter[0]='\0';
	strcpy(drive->DriveName,"My Computer");
	drive->DriveType=99;
	strcpy(drive->DriveTitle,"My Computer");
	m_DriveList.Add(drive);
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

void CFileComboBox::Init(CWnd *pParentWnd,CImageList *Small, UINT message)
{
	m_pParentWnd=pParentWnd;
	m_Msg=message;
	this->SetImageList(Small);
	GetDrives();
}

void CFileComboBox::SetDirectory(CString Directory)
{
	COMBOBOXEXITEMA *cItem;
	Drive *drive;
	CString driveLetter=Directory.Mid(0,3);
	int indent(0);
	char buffer[260];
	int tmp(260);
	int Counter(0);
	PathInfo *pi;
	int pos(0);
	int oldPos(3);
	char info[260];

	GetWindowsDirectory(buffer,tmp);
	if(buffer[tmp]!='\\')
		strcat(buffer,"\\explorer.exe");
	else
		strcat(buffer,"explorer.exe");

	if(Directory.Right(1)!="\\"&&Directory!="My Computer")
		Directory+="\\";

	while(this->DeleteItem(0)!=-1);
	for(int i=0;i<m_DriveList.GetSize();i++)
	{
		cItem=new COMBOBOXEXITEMA;
		pi=new PathInfo;
		drive=m_DriveList.GetItem(i);
		cItem->iIndent=indent;
		if(stricmp(drive->DriveLetter,"")!=0)
		{
			cItem->iImage=GetIconIndex(drive->DriveLetter);
			cItem->iSelectedImage=GetIconIndex(drive->DriveLetter);
			strcpy(pi->Path,drive->DriveLetter);
		}
		else
		{
			cItem->iImage=GetIconIndex(buffer);
			cItem->iSelectedImage=GetIconIndex(buffer);
			indent+=1;
			strcpy(pi->Path,"My Computer");
		}
		cItem->pszText=drive->DriveTitle;
		cItem->iItem=Counter++;
		cItem->mask = CBEIF_TEXT|CBEIF_IMAGE|CBEIF_INDENT|CBEIF_SELECTEDIMAGE;
		pos = this->InsertItem(cItem);
		this->SetItemDataPtr(pos,pi);
		if(strcmp(Directory,pi->Path)==0)
			this->SetCurSel(Counter-1);
		delete cItem;
		if(stricmp(driveLetter,drive->DriveLetter)==0)
		{
			int tmpIndent=indent+1;

			CString m_CurrentPath = Directory;
			do
			{
				cItem=new COMBOBOXEXITEMA;	
				if(m_CurrentPath.Right(1)!="\\")
					m_CurrentPath+="\\";
				pos=m_CurrentPath.Find("\\",oldPos);
				if(pos!=-1)
				{
					sprintf(info,"%s",m_CurrentPath.Mid(oldPos,pos-oldPos));
					cItem->pszText=info;
					cItem->iIndent=tmpIndent++;
					cItem->iSelectedImage=GetIconIndex(m_CurrentPath.Mid(0,pos));
					cItem->iImage=GetIconIndex(m_CurrentPath.Mid(0,pos));
					cItem->iItem=Counter++;
					cItem->mask = CBEIF_TEXT|CBEIF_IMAGE|CBEIF_INDENT|CBEIF_SELECTEDIMAGE;
					oldPos = this->InsertItem(cItem);
					pi=new PathInfo;
					strcpy(pi->Path,m_CurrentPath.Mid(0,pos));
					this->SetItemDataPtr(oldPos,pi);
					delete cItem;
					oldPos=pos+1;
				}
			}while(m_CurrentPath.Find("\\",oldPos)!=-1);
			this->SetCurSel(Counter-1);
			delete[] pi;
		}
	}
}

int CFileComboBox::GetIconIndex(const CString &FileName)
{
	SHFILEINFO    sfi;
	SHGetFileInfo((LPCTSTR)FileName,
								0,
								&sfi,
								sizeof(SHFILEINFO),
								SHGFI_SYSICONINDEX|SHGFI_SMALLICON);

	return sfi.iIcon;
}

void CFileComboBox::OnSelchange() 
{
	PathInfo *pi;
	int i;
	i=this->GetCurSel();
	pi=(PathInfo*)this->GetItemDataPtr(i);
	this->SetDirectory(pi->Path);
	m_Directory=pi->Path;
	m_pParentWnd->SendMessage(m_Msg,WM_CHANGED,0);
	delete pi;
}

CString CFileComboBox::GetDirectory()
{
	return(m_Directory);
}
