// DirecotryReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DirecotryReader.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

CFile file;
void read_dirs(char* path);

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		cout << "Börjar!" << endl;
		file.Open("c:\\F1 Misc.txt",CFile::modeWrite|CFile::modeCreate|CFile::modeNoTruncate);
		read_dirs("i:\\");
		file.Close();
		cout << "Klar!" << endl;
	}

	return nRetCode;
}

void read_dirs(char* path)
{
WIN32_FIND_DATA wfd;
HANDLE hFile;
char* pBuffer=new char[_MAX_PATH];
char* pPath=new char[_MAX_PATH];

	if(path[strlen(path)-1]!='\\')
		strcat(path,"\\");
	strcpy(pPath,path);
	strcpy(pBuffer,path);
	if(pBuffer[strlen(pBuffer)-1]!='*')
		strcat(pBuffer,"*.*");
	hFile=FindFirstFile(pBuffer,&wfd);
	if(hFile!=(HANDLE)-1)
	{
		do
		{
			if((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)&&(wfd.cFileName[0]!='.')&&(strcmp(wfd.cFileName,"images")))
			{
				char* t=new char[_MAX_PATH];
				strcpy(t,pPath);
				strcat(t,wfd.cFileName);
				read_dirs(t);
				delete[] t;
			}
			else if((wfd.cFileName[0]!='.')&&(strcmp(wfd.cFileName,"images")))
			{
				file.Write(path,strlen(path));
				file.Write(wfd.cFileName,strlen(wfd.cFileName));
				file.Write("\r\n",2);
			}
		}while(FindNextFile(hFile,&wfd));
	}
	delete[] pBuffer;
	delete[] pPath;
}