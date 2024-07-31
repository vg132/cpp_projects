#include "stdafx.h"
#include "FileList.h"

CFileList::CFileList()
{

}

CFileList::~CFileList()
{

}

bool CFileList::FindFiles(char *Folder, int Type, char *Filter)
{
	SplitFileFilter(Filter);
	if(Folder[strlen(Folder)-1]!='\\')
	{
		m_Folder=new char[strlen(Folder)+2];
		strcpy(m_Folder,Folder);
		strcat(m_Folder,"\\");
	}
	else
	{
		m_Folder=new char[strlen(Folder)+1];
		strcpy(m_Folder,Folder);
	}
	m_Type=Type;
	Search(m_Folder);
	return(true);
}

void CFileList::SplitFileFilter(char *Filter)
{
	char *temp;
	unsigned int start(0);
	for(unsigned int i=0;i<strlen(Filter);i++)
	{
		if(Filter[i]==';')
		{
			temp=new char[i-start+1];
			strncpy(temp,&Filter[start],i-start);
			temp[i-start]='\0';
			m_ListFilter.Add(temp);
			start=i+1;
		}
		else if(Filter[i]=='.')
			start=i;
	}
	if(start<strlen(Filter))
	{
		temp=new char[strlen(Filter)-start+1];
		strncpy(temp,&Filter[start],strlen(Filter)-start);
		temp[strlen(Filter)-start]='\0';
		m_ListFilter.Add(temp);
	}
}

void CFileList::Search(char* Folder)
{
	WIN32_FIND_DATA wfd;
	HANDLE hFile;
	char* NewFolder;
	char* SearchString;
	int iLoop(0);
	SearchString=new char[strlen(Folder)+4];
	strcpy(SearchString,Folder);
	strcat(SearchString,"*.*");
	hFile = FindFirstFile(SearchString,&wfd);
	if(hFile!=(HANDLE)-1)
	{
		do
		{
			if((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)&&m_Type==0)
			{
				if(wfd.cFileName[0]!='.')
				{
					NewFolder=new char[strlen(Folder)+strlen(wfd.cFileName)+2];
					strcpy(NewFolder,Folder);
					strcat(NewFolder,wfd.cFileName);
					strcat(NewFolder,"\\");
					Search(NewFolder);
					delete[] NewFolder;
				}
			}
			else
			{
				for(iLoop=0;iLoop<m_ListFilter.GetSize();iLoop++)
				{
					if(strncmp(&wfd.cFileName[strlen(wfd.cFileName)-4],m_ListFilter.GetItem(iLoop),4)==0)
					{
						NewFolder = new char[strlen(wfd.cFileName)+strlen(Folder)+1];
						strcpy(NewFolder,Folder);
						strcat(NewFolder,wfd.cFileName);
						strcat(NewFolder,"\0");
						m_ListFiles.Add(NewFolder);
						break;
					}
				}
			}
		}while(FindNextFile(hFile,&wfd));
	}
}

char* CFileList::Pop()
{
	char* tmp;
	if(m_ListFiles.GetSize()==0)
		return(NULL);
	tmp=m_ListFiles.GetItem(m_ListFiles.GetSize()-1);
	m_ListFiles.Remove(m_ListFiles.GetSize()-1);
	return(tmp);
}

int CFileList::GetNrOfFiles()
{
	return(m_ListFiles.GetSize());
}
