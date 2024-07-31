// Unzip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Unzip.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	WIN32_FIND_DATA wfd;
	HANDLE hFile;
	char* pDir=new char[_MAX_PATH];
	GetCurrentDirectory(_MAX_PATH,pDir);
	char* pBuffer;


	if(pDir[strlen(pDir)-1]!='\\')
		strcat(pDir,"\\*.zip");
	else
		strcat(pDir,"*.zip");

	hFile=FindFirstFile(pDir,&wfd);
	if(hFile!=INVALID_HANDLE_VALUE)
	{
		do
		{
			if(!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				pBuffer=new char[_MAX_PATH];
				GetCurrentDirectory(_MAX_PATH,pBuffer);
				if(pBuffer[strlen(pBuffer)-1]!='\\')
					strcat(pBuffer,"\\");
				strcat(pBuffer,wfd.cFileName);
				Unzip(pBuffer);
				delete[] pBuffer;
			}
		}while(FindNextFile(hFile,&wfd));
	}

	delete[] pDir;
	return(0);
}

bool Unzip(char* file)
{
CInfoZip InfoZip;
char* pDir=new char[_MAX_PATH];
	GetCurrentDirectory(_MAX_PATH,pDir);
	if(InfoZip.InitializeUnzip()&&InfoZip.ExtractFiles(file, pDir)&&InfoZip.FinalizeUnzip())
		return(true);
	else
		return(false);
}
