/*#include "Uppgift2.h"
#include "stdafx.h"*/
#include "ViperStringBase.h"

CViperStringBase::CViperStringBase()
{

}

CViperStringBase::~CViperStringBase()
{

}

int CViperStringBase::strlen(const char* str)
{
	int i(0);
	while(str[i++]!='\0'){};
	return(--i);
}

char* CViperStringBase::strcat(char* target, const char* source)
{
	int i(0);
	int Len(0);
	while(target[i++]!='\0'){};
	i--;
	for(Len=0;Len<this->strlen(source);Len++)
	{
		target[i++]=source[Len];
	}
	target[i]='\0';
	return(target);
}

char* CViperStringBase::stricat(char *target, const char *source, const int len)
{
	int i(0);
	int Len(0);
	while(target[i++]!='\0'){};
	i--;
	for(Len=0;Len<len;Len++)
	{
		target[i++]=source[Len];
	}
	target[i]='\0';
	return(target);
}

bool CViperStringBase::strcpy(char *target, const char *source)
{
	for(int i=0;i<this->strlen(source);i++)
		target[i]=source[i];
	target[i]='\0';
	return(true);
}

bool CViperStringBase::stricpy(char *target, const char *source, const int len)
{
	for(int i=0;i<len;i++)
		target[i]=source[i];
	target[i]='\0';
	return(true);
}

int CViperStringBase::strcmp(const char *string1, const char *string2)
{
	if(this->strlen(string1)!=this->strlen(string2))
		return(-1);
	for(int i=0;i<this->strlen(string1);i++)
	{
		if(string1[i]!=string2[i])
			return(-1);
	}
	return(0);
}

int CViperStringBase::stricmp(const char *string1, const char *string2, const int len)
{
	for(int i=0;i<len;i++)
	{
		if(string1[i]!=string2[i])
			return(-1);
	}
	return(0);
}

int CViperStringBase::strcmpi(const char* string1, const char* string2)
{
	if(this->strlen(string1)!=this->strlen(string2))
		return(-1);
	char* s1 = new char[this->strlen(string1)+1];
	char* s2 = new char[this->strlen(string2)+1];
	int i(0);
	for(i=0;i<this->strlen(s1);i++)
	{
		if((s1[i]>64&&s1[i]<91)||(s1[i]>192&&s1[i]<224))
			s1[i]=s1[i]+32;
		if((s2[i]>64&&s2[i]<91)||(s2[i]>192&&s2[i]<224))
			s2[i]=s2[i]+32;
	}

	for(i=0;i<this->strlen(s1);i++)
	{
		if(s1[i]!=s2[i])
			return(-1);
	}
	return(0);
}

int CViperStringBase::stricmpi(const char *string1, const char *string2, const int len)
{
	char* s1 = new char[this->strlen(string1)+1];
	char* s2 = new char[this->strlen(string2)+1];
	int i(0);
	for(i=0;i<this->strlen(s1);i++)
	{
		if((s1[i]>64&&s1[i]<91)||(s1[i]>192&&s1[i]<224))
			s1[i]=s1[i]+32;
		if((s2[i]>64&&s2[i]<91)||(s2[i]>192&&s2[i]<224))
			s2[i]=s2[i]+32;
	}

	for(i=0;i<len;i++)
	{
		if(s1[i]!=s2[i])
			return(-1);
	}
	return(0);
}