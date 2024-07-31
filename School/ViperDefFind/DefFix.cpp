// DefFix.cpp: implementation of the CDefFix class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViperDefFind.h"
#include "DefFix.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDefFix::CDefFix()
{
	m_FileName=NULL;
	m_Find=NULL;
	m_Add=NULL;
}

CDefFix::~CDefFix()
{
	if(m_FileName!=NULL)
		delete[] m_FileName;
	if(m_Find!=NULL)
		delete[] m_Find;
	if(m_Add!=NULL)
		delete[] m_Add;
}

bool CDefFix::FixFile(char* File, char* Find, char* Add)
{
	if(m_FileName!=NULL)
		delete[] m_FileName;
	if(m_Find!=NULL)
		delete[] m_Find;
	if(m_Add!=NULL)
		delete[] m_Add;
	m_FileName=new char[strlen(File)+1];
	m_Find=new char[strlen(Find)+1];
	m_Add=new char[strlen(Add)+1];
	strcpy(m_FileName,File);
	strcpy(m_Find,Find);
	strcpy(m_Add,Add);
	m_Fin.open(File,ios::in|ios::binary);

	return(Replace());
}

bool CDefFix::Replace()
{
	char* buff=NULL;
	char* c=new char[2];
	int filesize=0;
	char* line=NULL;
	bool Found=false;
	char* m_NewFile=NULL;

	m_Fin.seekg(0,ios::end);
	filesize=m_Fin.tellg()*2;
	if(filesize>0)
	{
		m_NewFile=new char[filesize];
		m_NewFile[0]='\0';
	}
	m_Fin.seekg(0,ios::beg);

	line=new char[200];
	while(m_Fin.getline(line,200))
	{
		if(FindMatch(line,m_Find))
		{
			buff=new char[200];
			strcpy(buff,"//");
			strcat(buff,line);
			strcpy(line,buff);
			delete[] buff;
			buff=NULL;
			Found=true;
		}
		strcat(m_NewFile,line);
		strcat(m_NewFile,"\n");
	};
	m_Fin.close();
	if(Found==true)
	{
		buff=new char[filesize*2];
		strcpy(buff,m_Add);
		strcat(buff,"\15\12");
		strcat(buff,m_NewFile);
		strcpy(m_NewFile,buff);

		m_Fout.open(m_FileName,ios::out|ios::binary|ios::trunc);
		m_Fout.write((char*)m_NewFile,strlen(m_NewFile));
		m_Fout.close();
		delete[] buff;
		buff=NULL;
	}
	if(m_NewFile!=NULL)
		delete[] m_NewFile;
	if(line!=NULL)
		delete[] line;
	if(c!=NULL)
		delete[] c;
	return(true);
}

bool CDefFix::FindMatch(char* line, char* find)
{
	int iTop=strlen(line)-strlen(m_Find);
	for(int i=0;i<iTop;i++)
	{
		if(!Vipercmp(&line[i],m_Find,strlen(m_Find)))
			return(true);
	}
	return(false);
}

int CDefFix::Vipercmp(const char* string1, const char* string2, const int len)
{
	char* s1;
	char* s2;
	if(strlen(string1)>=len)
	{
		int Retval(0);
		s1=new char[strlen(string1)+1];
		s2=new char[strlen(string2)+1];
		strcpy(s1,string1);
		strcpy(s2,string2);
		s1[len]='\0';
		s2[len]='\0';
		Retval = strcmp(s1,s2);
		delete[] s1;
		delete[] s2;
		return(Retval);
	}
	else
	{
		return(-1);
	}
}
