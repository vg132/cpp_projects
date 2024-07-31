// ViperString.cpp: implementation of the CViperString class.
//
//////////////////////////////////////////////////////////////////////
/*
#include "stdafx.h"
#include "Uppgift2.h"*/
#include "ViperString.h"
/*
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
*/
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CViperString::CViperString()
{
	m_Str=NULL;
	m_TmpStr=NULL;
	s1=NULL;
	s2=NULL;
}

CViperString::CViperString(const CViperString &s)
{
	m_Str = new char[vsb.strlen(s.m_Str)+1];
	strcpy(m_Str,s.m_Str);
	m_TmpStr=NULL;
	s1=NULL;
	s2=NULL;
}

CViperString::CViperString(const char* str)
{
	m_Str=new char[vsb.strlen(str)+1];
	strcpy(m_Str,str);
	m_TmpStr=NULL;
	s1=NULL;
	s2=NULL;
}

CViperString::~CViperString()
{
	if(m_Str!=NULL)
		delete[] m_Str;
	if(m_TmpStr!=NULL)
		delete[] m_TmpStr;
	if(s1!=NULL)
		delete[] s1;
	if(s2!=NULL)
		delete[] s2;
}

CViperString CViperString::uppercase()
{
	m_TmpStr=new char[vsb.strlen(m_Str)+1];
	for(int i=0;i<vsb.strlen(m_Str);i++)
	{
		if((m_Str[i]>96&&m_Str[i]<123)||(m_Str[i]>223))
			m_TmpStr[i]=m_Str[i]-32;
		else
			m_TmpStr[i]=m_Str[i];
	}
	m_TmpStr[i]='\0';
	CViperString Tmp(m_TmpStr);
	delete[] m_TmpStr;
	m_TmpStr=NULL;
	return(Tmp);
}

CViperString CViperString::lowercase()
{
	m_TmpStr=new char[vsb.strlen(m_Str)+1];
	for(int i=0;i<vsb.strlen(m_Str);i++)
	{
		if((m_Str[i]>64&&m_Str[i]<91)||(m_Str[i]>192&&m_Str[i]<224))
			m_TmpStr[i]=m_Str[i]+32;
		else
			m_TmpStr[i]=m_Str[i];
	}
	m_TmpStr[i]='\0';
	CViperString Tmp(m_TmpStr);
	delete[] m_TmpStr;
	m_TmpStr=NULL;
	return(Tmp);
}

CViperString CViperString::replace(const char* find, const char* replace)
{
	int found(0);
	int len(0);
	int i(0);
	int Posnew(0);
	int Posold(0);
	for(i=0;i<vsb.strlen(m_Str);i++)
	{
		if(!vsb.stricmp(&m_Str[i],find,vsb.strlen(find)))
			found++;
	}
	len=vsb.strlen(replace)-vsb.strlen(find);
	len*=found;
	len=vsb.strlen(m_Str)+len;
	m_TmpStr=new char[len+1];
	m_TmpStr[0]='\0';
	while(Posold<vsb.strlen(m_Str))
	{
		if(!vsb.stricmp(&m_Str[Posold],find,vsb.strlen(find)))
		{
			vsb.strcat(m_TmpStr,replace);
			Posnew+=vsb.strlen(replace);
			Posold+=vsb.strlen(find);
		}
		else
		{
			m_TmpStr[Posnew++]=m_Str[Posold];
			m_TmpStr[Posnew]='\0';
			Posold++;
		}
	};
	CViperString Tmp(m_TmpStr);
	delete[] m_TmpStr;
	m_TmpStr=NULL;
	return(Tmp);
}

CViperString CViperString::reverse()
{
	int Strlen=vsb.strlen(m_Str);
	m_TmpStr=new char[Strlen+1];
	for(int i=0;i<Strlen;i++)
	{
		m_TmpStr[Strlen-i]=m_Str[i];
	}
	m_TmpStr[i]='\0';
	CViperString Tmp(m_TmpStr);
	delete[] m_TmpStr;
	m_TmpStr=NULL;
	return(Tmp);
}

int CViperString::count()
{
	return(vsb.strlen(m_Str));
}

void CViperString::operator =(const CViperString &cvs)
{
	delete[] m_Str;
	m_Str=new char[vsb.strlen(cvs.m_Str)+1];
	vsb.strcpy(m_Str,cvs.m_Str);	
}

CViperString CViperString::operator +(const CViperString &cvs)
{
	m_TmpStr=new char[vsb.strlen(m_Str)+vsb.strlen(cvs.m_Str)+1];
	vsb.strcpy(m_TmpStr,m_Str);
	vsb.strcat(m_TmpStr,cvs.m_Str);
	CViperString Tmp(m_TmpStr);
	delete[] m_TmpStr;
	m_TmpStr=NULL;
	return(Tmp);
}

CViperString CViperString::operator +(const char* str)
{
	m_TmpStr=new char[vsb.strlen(m_Str)+vsb.strlen(str)+1];
	vsb.strcpy(m_TmpStr,m_Str);
	vsb.strcat(m_TmpStr,str);
	CViperString Tmp(m_TmpStr);
	delete[] m_TmpStr;
	m_TmpStr=NULL;
	return(Tmp);
}

char* CViperString::ToChar()
{
	return(m_Str);
}

void CViperString::operator =(const char *str)
{
	delete[] m_Str;
	m_Str=NULL;
	m_Str=new char[vsb.strlen(str)+1];
	vsb.strcpy(m_Str,str);
}

ostream & operator<<(ostream & os, CViperString & vs)
{
	os << vs.ToChar();
	return(os);
}

istream & operator>>(istream & is, CViperString & vs)
{/*
//	os >> vs.ToChar();
	is.seekg(0,ios::end);
	int len=is.tellg();
	char* tmp=new char[len+1];
	is.seekg(0,ios::beg);
	is.read(tmp,len);
	vs=tmp;
	delete[] tmp;*/
/*	char temp[80];
	is.getline(temp,80);
	if(is)
		vs=temp;*/
	return(is);
}

ifstream & operator>>(ifstream & fis, CViperString & vs)
{
	char ch;
	vs="";
	while(fis.get(ch))
	{
		vs+=ch;
	}
	return(fis);
}

void CViperString::operator +=(const char *str)
{
	m_TmpStr=new char[vsb.strlen(m_Str)+vsb.strlen(str)+1];
	vsb.strcpy(m_TmpStr,m_Str);
	vsb.strcat(m_TmpStr,str);
	delete[] m_Str;
	m_Str=NULL;
	m_Str=new char[vsb.strlen(m_TmpStr)+1];
	vsb.strcpy(m_Str,m_TmpStr);
//	delete[] m_TmpStr;
}

void CViperString::operator +=(const char str)
{
	m_TmpStr=new char[vsb.strlen(m_Str)+2];
	vsb.strcpy(m_TmpStr,m_Str);
	m_TmpStr[vsb.strlen(m_Str)]=str;
	m_TmpStr[vsb.strlen(m_Str)+1]='\0';
	delete[] m_Str;
	m_Str=NULL;
	m_Str=new char[vsb.strlen(m_TmpStr)+1];
	vsb.strcpy(m_Str,m_TmpStr);
	delete[] m_TmpStr;
	m_TmpStr=NULL;
}