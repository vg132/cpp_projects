// RegEdit.cpp: implementation of the CRegEdit class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RegEdit.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRegEdit::CRegEdit()
{

}

CRegEdit::~CRegEdit()
{

}

bool CRegEdit::SaveSettings(HKEY hKey, CString Path, CString Value, CString Data)
{
	HKEY phKey(NULL);
	DWORD dwDummy(0);
	char *lpBuffer = new char[Data.GetLength()+1];
	strcpy(lpBuffer,Data);
	if(RegCreateKeyEx(hKey,
										Path,
										0,
										"REG_SZ",
										REG_OPTION_NON_VOLATILE,
										KEY_ALL_ACCESS,
										NULL,
										&phKey,
										&dwDummy)==ERROR_SUCCESS)
	{
		RegSetValueEx(phKey,
									Value,
									0,
									REG_SZ,
									(unsigned char*)lpBuffer,
									Data.GetLength());


	}
	RegCloseKey(phKey);
	delete[] lpBuffer;
	return(true);
}

bool CRegEdit::SaveSettings(HKEY hKey, CString Path, CString Value, int Data)
{
	HKEY phKey(NULL);
	DWORD dwDummy(0);
	char *lpBuffer = new char[5];
	itoa(Data,lpBuffer,10);
	if(RegCreateKeyEx(hKey,
										Path,
										0,
										"REG_SZ",
										REG_OPTION_NON_VOLATILE,
										KEY_ALL_ACCESS,
										NULL,
										&phKey,
										&dwDummy)==ERROR_SUCCESS)
	{
		RegSetValueEx(phKey,
									Value,
									0,
									REG_SZ,
									(unsigned char*)lpBuffer,
									strlen(lpBuffer));


	}
	RegCloseKey(phKey);
	delete[] lpBuffer;
	return(true);
}

CString CRegEdit::GetSettings(HKEY hKey, CString Path, CString Value, CString Default)
{
	HKEY phKey(NULL);
	unsigned char *lpBuffer=new unsigned char[_MAX_PATH];
	DWORD dType(0), dSize(_MAX_PATH);
	CString szTemp("");
	lpBuffer[0]='\0';
	if(RegOpenKeyEx(hKey,
									Path,
									0,
									KEY_ALL_ACCESS,
									&phKey)==ERROR_SUCCESS)
	{
		RegQueryValueEx(phKey,
										Value,
										0,
										&dType,
										lpBuffer,
										&dSize);
		szTemp=lpBuffer;
		szTemp.TrimLeft();
	}
	delete[] lpBuffer;
	if(szTemp=="")
		return(Default);
	else
		return(szTemp);
}

int CRegEdit::GetSettings(HKEY hKey, CString Path, CString Value, int Default)
{
	HKEY phKey(NULL);
	unsigned char *lpBuffer=new unsigned char[_MAX_PATH];
	DWORD dType(0), dSize(_MAX_PATH);
	CString szTemp("");
	lpBuffer[0]='\0';
	if(RegOpenKeyEx(hKey,
									Path,
									0,
									KEY_ALL_ACCESS,
									&phKey)==ERROR_SUCCESS)
	{
		RegQueryValueEx(phKey,
										Value,
										0,
										&dType,
										lpBuffer,
										&dSize);
		szTemp=lpBuffer;
		szTemp.TrimLeft();
	}
	delete[] lpBuffer;
	if(szTemp=="")
		return(Default);
	else
		return(atoi(szTemp));
}

char* CRegEdit::GetSettings(HKEY hKey, CString Path, CString Value, char* Default)
{
	HKEY phKey(NULL);
	char *lpBuffer=new char[_MAX_PATH];
	DWORD dType(0), dSize(_MAX_PATH);
	CString szTemp("");
	lpBuffer[0]='\0';
	if(RegOpenKeyEx(hKey,
									Path,
									0,
									KEY_ALL_ACCESS,
									&phKey)==ERROR_SUCCESS)
	{
		RegQueryValueEx(phKey,
										Value,
										0,
										&dType,
										(unsigned char*)lpBuffer,
										&dSize);
		szTemp=lpBuffer;
		szTemp.TrimLeft();
	}
	if(szTemp=="")
	{
		strcpy(lpBuffer,Default);
		return(lpBuffer);
	}
	sprintf(lpBuffer,"%s",szTemp);
	return(lpBuffer);
}