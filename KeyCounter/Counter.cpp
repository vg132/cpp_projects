#include "StdAfx.h"
#include "counter.hpp"

CCounter::CCounter(void)
{
	m_CheckProgram=true;
	m_ShowFullPath=false;
	m_KeyStrokes=0;
}

CCounter::~CCounter(void)
{
}

bool CCounter::RemoveProgram(string Program)
{
	transform(Program.begin(),Program.end(),Program.begin(),tolower);
	m_CounterIterator=m_Counter.find(Program);
	if(m_CounterIterator==m_Counter.end())
		return(false);
	m_Counter.erase(m_CounterIterator);
	return(true);
}

bool CCounter::AddKeyStroke(string Program, int Count)
{
	m_KeyStrokes+=Count;
	if(m_CheckProgram)
	{
		string Program=GetForgroundProcessName();
		m_CounterIterator=m_Counter.find(Program);
		if(m_CounterIterator==m_Counter.end())
			m_Counter.insert(make_pair(Program,Count));
		else
			m_Counter[Program]+=Count;
	}
	if((m_KeyStrokes%1000)==0)
		Save();
	return(true);
}

bool CCounter::AddKeyStroke(int Count)
{
	if(m_CheckProgram)
		return(AddKeyStroke(GetForgroundProcessName(),Count));
	else
		return(AddKeyStroke(m_Dummy,Count));
}

bool CCounter::Load(string FileName)
{
	HANDLE hFile=CreateFile(FileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(hFile!=INVALID_HANDLE_VALUE)
	{
		DWORD nRead;
		char *buffer=new char[_MAX_DIR];
		int tmp=0;
		ReadFile(hFile,(char*)&m_KeyStrokes,sizeof(m_KeyStrokes),&nRead,NULL);
		ReadFile(hFile,(char*)&m_CheckProgram,sizeof(m_CheckProgram),&nRead,NULL);
		ReadFile(hFile,(char*)&m_ShowFullPath,sizeof(m_ShowFullPath),&nRead,NULL);

		while((ReadFile(hFile,buffer,_MAX_DIR,&nRead,NULL))&&(nRead!=0))
		{
			ReadFile(hFile,(char*)&tmp,sizeof(tmp),&nRead,NULL);
			AddKeyStroke(buffer,tmp);
		}
		CloseHandle(hFile);
	}
	else
	{
		return(false);
	}
	return(true);
}

bool CCounter::Save(string FileName)
{
	HANDLE hFile=CreateFile(FileName.c_str(),GENERIC_WRITE, FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	if(hFile!=INVALID_HANDLE_VALUE)
	{
		char *buffer=new char[_MAX_DIR];
		DWORD nWritten;
		WriteFile(hFile,(char*)&m_KeyStrokes,sizeof(m_KeyStrokes),&nWritten,NULL);
		WriteFile(hFile,(char*)&m_CheckProgram,sizeof(m_CheckProgram),&nWritten,NULL);
		WriteFile(hFile,(char*)&m_ShowFullPath,sizeof(m_ShowFullPath),&nWritten,NULL);
		for(m_CounterIterator=m_Counter.begin();m_CounterIterator!=m_Counter.end();m_CounterIterator++)
		{
			WriteFile(hFile,m_CounterIterator->first.c_str(),_MAX_DIR,&nWritten,NULL);
			WriteFile(hFile,(char*)&m_CounterIterator->second,sizeof(m_CounterIterator->second),&nWritten,NULL);
		}
		delete[] buffer;
		CloseHandle(hFile);
	}
	else
	{
		return(false);
	}
	return(true);
}

// Get the exe name and path to the current active window
string CCounter::GetForgroundProcessName()
{
	DWORD dwProcessId(0),dwNeeded(0);
	HANDLE hProcess;
	HMODULE hMods[1024];
	char Buffer[_MAX_DIR], Buffer2[_MAX_DIR];
	HWND fhWnd=GetForegroundWindow();
	GetWindowThreadProcessId(fhWnd,&dwProcessId);
	hProcess=OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_VM_READ,FALSE,dwProcessId);
	EnumProcessModules(hProcess,hMods,sizeof(hMods),&dwNeeded);
	GetModuleFileNameEx(hProcess,hMods[0],Buffer,_MAX_DIR);	
	GetLongPathName(Buffer,Buffer2,_MAX_DIR);
	string str=Buffer2;
	transform(str.begin(),str.end(),str.begin(),tolower);
	return(str);
}
/*
UINT ThreadProc2(LPVOID lpvoid)
{


	thread2 *temp = (thread2*)lpvoid;
	HWND hwnd= temp->hwnd2;
	int no = temp->no2;
	char buff[200];
	HDC hdc= GetDC(hwnd);

	for(int i=0;i<no;i++)
	{
		wsprintf(buff,"Thread 2 Function :%d",i+1);
		TextOut(hdc,448,50,(LPCTSTR)buff,strlen(buff));
		Sleep(75);
	}

	return 0;
}

*/
UINT WINAPI CCounter::KeyThread(LPVOID Param)
{
	return(0);
}

/*
			 SetThreadPriority(hThrd1,THREAD_PRIORITY_HIGHEST);

			 // Run the secound Thread

			obj2.hwnd2 = hWnd;
			obj2.no2 = 260;
			 hThrd2 = CreateThread(NULL,  // no security attributes 
							 0,                // use default stack size 
							 (LPTHREAD_START_ROUTINE) ThreadProc2, 
							 (LPVOID)&obj2, // param to thread func 
							 CREATE_SUSPENDED, // creation flag 
						 NULL);       // 
			 ResumeThread(hThrd2);
					 
			 SetThreadPriority(hThrd1,THREAD_PRIORITY_LOWEST);
*/

void CCounter::ThreadTest()
{
	HANDLE hThread1;

	hThread1=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CCounter::KeyThread,NULL,CREATE_SUSPENDED,NULL);
	ResumeThread(hThread1);
	SetThreadPriority(hThread1,THREAD_PRIORITY_NORMAL);
}