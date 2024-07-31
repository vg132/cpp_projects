#include "StdAfx.h"
#include "replayinfo.h"

CReplayInfo::CReplayInfo(void)
{
	m_pReplayDirectory=NULL;
	m_pExecutable=NULL;
	m_pName=NULL;
	m_pStartupDirectory=NULL;
}

CReplayInfo::~CReplayInfo(void)
{
	if(m_pReplayDirectory!=NULL)
		delete m_pReplayDirectory;
	if(m_pExecutable!=NULL)
		delete m_pExecutable;
	if(m_pName!=NULL)
		delete m_pName;
	if(m_pStartupDirectory!=NULL)
		delete m_pStartupDirectory;
}

void CReplayInfo::SetReplayDirectory(char *replay_directory)
{
	if(m_pReplayDirectory!=NULL)
		delete m_pReplayDirectory;
	m_pReplayDirectory=new char[strlen(replay_directory)+1];
	strcpy(m_pReplayDirectory,replay_directory);
}

void CReplayInfo::SetExecutable(char *executable)
{
	if(m_pExecutable!=NULL)
		delete m_pExecutable;
	m_pExecutable=new char[strlen(executable)+1];
	strcpy(m_pExecutable,executable);
}

void CReplayInfo::SetName(char *name)
{
	if(m_pName!=NULL)
		delete m_pName;
	m_pName=new char[strlen(name)+1];
	strcpy(m_pName,name);
}

void CReplayInfo::SetStartupDirectory(char *startup_directory)
{
	if(m_pStartupDirectory!=NULL)
		delete m_pStartupDirectory;
	m_pStartupDirectory=new char[strlen(startup_directory)+1];
	strcpy(m_pStartupDirectory,startup_directory);
}