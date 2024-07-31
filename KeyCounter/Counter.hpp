#ifndef __CCOUNTER__HPP__
#define __CCOUNTER__HPP__

#include <Psapi.h>
#include "stdafx.h"
#include <string>
#include <map>
#include <algorithm>

#pragma comment ( lib, "psapi.lib")

using namespace std;

class CCounter
{
private:
	int m_KeyStrokes;
	bool m_ShowFullPath, m_CheckProgram;
	string m_DataFile;

	map<string,int> m_Counter;
	map<string,int>::iterator m_CounterIterator;

	string GetForgroundProcessName();
	bool AddKeyStroke(string Program, int Count=1);

	string m_Dummy;

	static UINT WINAPI KeyThread(LPVOID Param);
public:
	CCounter(void);
	~CCounter(void);

	bool Save(string FileName);
	bool Save(){return(Save(m_DataFile));};
	bool Load(string FileName);
	bool Load(){return(Load(m_DataFile));};

	void SetShowFullPath(bool FullPath){m_ShowFullPath=FullPath;};
	bool GetShowFullPath(){return(m_ShowFullPath);};
	void SetCheckProgram(bool CheckProgram){m_CheckProgram=CheckProgram;};
	bool GetCheckProgram(){return(m_CheckProgram);};

	void SetDataFile(string DataFile){m_DataFile=DataFile;};
	string GetDataFile(){return(m_DataFile);};

	int GetKeyStrokes(){return(m_KeyStrokes);};

	bool RemoveProgram(string Prog);

	bool AddKeyStroke(int Count=1);
	map<string,int> GetMap(){return(m_Counter);};

	void ThreadTest();
};

#endif