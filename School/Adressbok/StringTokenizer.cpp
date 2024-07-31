//Copyrigth (C) Viktor Gars 2001

#include "stdafx.h"
#include "Adressbok.h"

#include "StringTokenizer.h"

StringTokenizer::StringTokenizer(char* token, char spliter)
{
	this->token=new char[strlen(token)+1];
	strcpy(this->token,token);
	this->spliter=spliter;
	pos=0;
	tokens=0;
	while(pos<strlen(this->token))
	{
		if(this->token[pos]==this->spliter)
			tokens++;
		pos++;
	};
	curpos=0;
}

StringTokenizer::~StringTokenizer()
{
	delete[] token;
}

bool StringTokenizer::HasMoreTokens()
{
	if(tokens>0)
		return(true);
	else
		return(false);
}

char* StringTokenizer::NextToken()
{
	if(tokens>=0)
	{
		pos=curpos;
		while(token[pos]!=spliter&&pos<strlen(token))
		{
			pos++;
		};
		char* tmp=new char[pos-curpos+1];
		strncpy(tmp,&token[curpos],(pos-curpos));
		tmp[pos-curpos]='\0';
		curpos=pos+1;
		tokens--;
		return(tmp);
	}
	else
	{
		return(NULL);
	}
}

void StringTokenizer::Reset()
{
	pos=0;
	tokens=0;
	while(pos<strlen(this->token))
	{
		if(this->token[pos]==this->spliter)
			tokens++;
		pos++;
	};
	curpos=0;
}
