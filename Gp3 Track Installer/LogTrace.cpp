////////////////////////////////////////////////////////////////////////
//  LogTrace.cpp -- Implementation of the CLogTrace class


#include "stdafx.h"
#include <afxdisp.h>
#include "LogTrace.h"

/**************************************************

 How to use CLogTrace

	1.  Make a static CLogTrace object as a member of the application class

	2.	Add the following lines to the InitInstance of the program

	
	m_LogTrace.m_strAppName = "MyApp"; // use appropriate name here

	m_LogTrace.SetFileName("Log.txt"); // sets the log file name and puts it in the exe path

	m_LogTrace.OnStartup(TRUE, TRUE); // activates the log trace

	3.  Also in InitInstance, add the following line if you want to empty the log file
	each time the application starts
	
	m_LogTrace.ResetFile();


	4.  Any time you want to write to the log file, use the CLogTrace::WriteLine functions
	these will write the text along with date and time


*******************************************************/



//////////////////////////////////////////////////////
//  Construction/Destruction

CLogTrace::CLogTrace()
{
	m_bActive = FALSE;
	m_bTimeStamp = TRUE;

	CString s;
}


CLogTrace::~CLogTrace()
{


}

////////////////////////////////////////////////////////
//  CLogTrace operations


void CLogTrace::ResetFile()
{
#ifdef __LOG__
	CStdioFile f;
	CFileException fe;
	CString s;

	if (m_strFileName.IsEmpty()) return;

	if (f.Open(m_strFileName, CFile::modeWrite | CFile::modeCreate, &fe) == FALSE)
	{
		return;
	}

	f.Close();
#endif
}



// bActive tells us if we want the trace to be active or not
// bTimeStamp tells us if we want time stamps on each line
// eliminating the time stamp allows us to use this class for a regular log file
void CLogTrace::OnStartup(BOOL bActive, BOOL bTimeStamp)
{
#ifdef __LOG__
	m_bActive = bActive;
	m_bTimeStamp = bTimeStamp;
	if (bTimeStamp == FALSE) return;
	CString s;

	// these ***'s help to indicate when one ru of the program ends and another starts
	// because we don't always overwrite the file each time

	WriteLine("\n\n******************************************\n\n");
	s.Format("%s Log Trace %s\n\n", m_strAppName, COleDateTime::GetCurrentTime().Format());
	WriteLine(s);
#endif
}



// function to write a line of text to the log file
void CLogTrace::WriteLine(LPCTSTR szLine)
{
#ifdef __LOG__
	CStdioFile f;
	CFileException fe;
	CString s;

	if (m_bActive == FALSE) return;
	if (m_strFileName.IsEmpty()) return;

	if (f.Open(m_strFileName, CFile::modeWrite | CFile::modeCreate |
		CFile::modeNoTruncate, &fe) == FALSE)
	{
		return;
	}

	try
	{
		f.SeekToEnd();
		TRACE("LOGGIN %s\n", szLine);
		if (m_bTimeStamp)
		{
			s.Format("%s\t%s\n", COleDateTime::GetCurrentTime().Format(),
				szLine);
		}
		else
		{
			s.Format("%s\n", szLine);
		}
		f.WriteString(s);
	}
	catch (CException* e)
	{
		e->Delete();
	}
	f.Close();
#endif
}

// function to write a line of text, with an extra string
void CLogTrace::WriteLine(LPCTSTR szFormat, LPCTSTR szAddInfo)
{
#ifdef __LOG__
	if (m_bActive == FALSE) return;
	CString s;
	s.Format(szFormat, szAddInfo);
	WriteLine(s);
#endif
}


// funtion to write a line of text with an extra integer
void CLogTrace::WriteLine(LPCTSTR szFormat, int nAddInfo)
{
#ifdef __LOG__
	if (m_bActive == FALSE) return;
	CString s;
	s.Format(szFormat, nAddInfo);
	WriteLine(s);
#endif
}


// function to set the log file name.  don't pass a fill path!
// just pass something like "log.txt"
// the file will be placed in the same dir as the exe file
void CLogTrace::SetFileName(LPCTSTR szFileName)
{
#ifdef __LOG__
	TCHAR drive[_MAX_PATH], dir[_MAX_PATH], name[_MAX_PATH], ext[_MAX_PATH];

	const char *path = _pgmptr ;

	_splitpath(path, drive, dir, name, ext);

	m_strFileName.Format("%s%s%s", drive, dir, szFileName);
#endif
}