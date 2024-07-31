// Id.cpp: implementation of the CId class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bokning.h"
#include "Id.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CId::m_Counter=0;

CId::CId()
{
	m_Id=NULL;
	m_Counter++;
}

CId::CId(char ch)
{
	CTime timer;
	char* szBuffer=new char[50];
	char* szCounter = new char[50];
	char* newid=new char[50];

	time_t ltime;
	time(&ltime);

	timer=timer.GetCurrentTime();

	sprintf(szBuffer,"%ld\0",ltime);
	sprintf(szCounter,"%ld\0",m_Counter);
	sprintf(newid,"%c%s-%s%s\0",ch, timer.FormatGmt("%y%m%d"),&szBuffer[strlen(szBuffer)-5],szCounter);

	m_Id=new char[strlen(newid)+1];
	strcpy(m_Id,newid);

	delete[] szBuffer;
	delete[] szCounter;
	delete[] newid;
}

CId::~CId()
{
	if(m_Id!=NULL)
		delete[] m_Id;
}

void CId::SetId(char* id)
{
	if(m_Id!=NULL)
		delete[] m_Id;
	m_Id=new char[strlen(id)+1];
	strcpy(m_Id,id);
}

void CId::operator=(const CId *id)
{
	SetId(id->m_Id);
}

bool CId::operator==(const CId *id)
{
	if(!strcmp(m_Id,id->m_Id))
		return(true);
	else
		return(false);
}

bool CId::operator!=(const CId *id)
{
	return(strcmp(m_Id,id->m_Id));
}