#include "StdAfx.h"
#include "replaydirwatcher.h"

CReplayDirWatcher::CReplayDirWatcher(void)
{
	m_strHotlapName="";
	m_strReplayName="";
	m_strTmp="";
}

CReplayDirWatcher::~CReplayDirWatcher(void)
{
}

void CReplayDirWatcher::On_FileModified(const CString &strFileName)
{
	if(strFileName.Right(12).CompareNoCase(" Hot Lap.Vcr")==0)
		m_strHotlapName=strFileName;
	else if(strFileName.Right(4).CompareNoCase(".vcr")==0)
		m_strReplayName=strFileName;
}

void CReplayDirWatcher::On_FileRemoved(const CString & strFileName)
{
	m_strTmp=strFileName.Right(10).MakeLower();
	if(strFileName.Right(10).CompareNoCase("\\__vcr.tmp")==0)
	{
		CTime time=CTime::GetCurrentTime();
		if(m_strReplayName!="")
		{
			m_strTmp=m_strReplayName;
			m_strTmp.Insert(m_strTmp.GetLength()-4,time.Format("_%Y_%m_%d_%H_%M_%S"));
			MoveFile(m_strReplayName,m_strTmp);
		}
		if(m_strHotlapName!="")
		{
			m_strTmp=m_strHotlapName;
			m_strTmp.Insert(m_strTmp.GetLength()-4,time.Format("_%Y_%m_%d_%H_%M_%S"));
			MoveFile(m_strHotlapName,m_strTmp);
		}
		m_strHotlapName="";
		m_strReplayName="";
		m_strTmp="";
	}
}