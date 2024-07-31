// FindFile.cpp: implementation of the CFindFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViperDefFind.h"
#include "FindFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFindFile::CFindFile()
{
	m_PosCounter=0;
	m_pFileList=NULL;
}

CFindFile::~CFindFile()
{
	if(m_pFileList!=NULL)
		delete m_pFileList;
}

char* CFindFile::Pop()
{
	return(m_pFileList->GetItem(m_PosCounter++));
}

bool CFindFile::Push(char* data)
{
	return(m_pFileList->Add(data));
}

bool CFindFile::StartSearch(char* Dir, char* FileType)
{
	if(m_pFileList!=NULL)
		delete[] m_pFileList;
	m_pFileList=new List<char>;
	m_PosCounter=0;
	return(SearchDir(Dir,FileType));
}

bool CFindFile::SearchDir(char* Dir, char* FileType)
{
WIN32_FIND_DATA wfd;
HANDLE hFile;
char* cTmp=NULL;
char* cPath=NULL;
char* cDir=NULL;

	if(Dir[strlen(Dir)-1]!='\\')
	{
		cDir=new char[strlen(Dir)+2];
		strcpy(cDir,Dir);
		strcat(cDir,"\\");
	}
	else
	{
		cDir=new char[strlen(Dir)+1];
		strcpy(cDir,Dir);
	}
	cPath=new char[strlen(cDir)+strlen(FileType)+1];
	strcpy(cPath,cDir);
	strcat(cPath,FileType);

	hFile=FindFirstFile(cPath,&wfd);
	do
	{
		if((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)&&(wfd.cFileName[0]!='.'))
		{
			cTmp=new char[strlen(cDir)+strlen(wfd.cFileName)+1];
			strcpy(cTmp,cDir);
			strcat(cTmp,wfd.cFileName);
			SearchDir(cTmp,FileType);
			delete[] cTmp;
		}
		else if(wfd.cFileName[0]!='.')
		{
			cTmp=new char[strlen(cDir)+strlen(wfd.cFileName)+1];
			strcpy(cTmp,cDir);
			strcat(cTmp,wfd.cFileName);
			Push(cTmp);
		}
	}while(FindNextFile(hFile,&wfd));
	if(cDir!=NULL)
		delete[] cDir;
	if(cPath!=NULL)
		delete[] cPath;
	return(true);
}