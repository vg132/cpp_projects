// Common.cpp: implementation of the CCommon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Common.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommon::CCommon()
{

}

CCommon::~CCommon()
{

}

CString CCommon::BrowseForFolders(CString szTitle, HWND m_hWnd)
{
//Browse for folders
char szPath[260];
BROWSEINFO bff;
LPITEMIDLIST pidl;
CString cDir="";

bff.hwndOwner		=m_hWnd;
bff.iImage			=0;
bff.lParam			=0;
bff.lpszTitle		=szTitle;
bff.pidlRoot		=NULL;
bff.ulFlags			=BIF_RETURNONLYFSDIRS;
bff.pszDisplayName	=szPath;
bff.lpfn			=NULL;

	//Show Browse for folders
	pidl=SHBrowseForFolder(&bff);
	if (pidl)
	{
		//Get Selected path
		SHGetPathFromIDList(pidl,szPath);
		cDir=szPath;
	}
	else
	{
		cDir="";
	}
	return(cDir);
}
/*
CString CCommon::GetFileName(CString cFileName)
{
// Overview: Return file title from a file path
int iPos;

	iPos=cFileName.GetLength();
	for(int i=iPos;i>=1;i--)
	{
		if (cFileName.Mid(i,1)=="\\")
		{
			iPos=cFileName.GetLength()-i;
			cFileName=cFileName.Right(iPos-1);
			break;
		}
	}
	return(cFileName);
}*/

CString CCommon::RegGetValue(CString cKey,CString cValue)
{
HKEY hKey;
char lpBuffer[260];
int RetVal;
unsigned long lwSize=260;
CString Conv;

	hKey=HKEY_CURRENT_USER;
	if (RegOpenKey(hKey,cKey,&hKey)==ERROR_SUCCESS)
	{
		RetVal=RegQueryValueEx(hKey,cValue,NULL,0,(LPBYTE)lpBuffer,&lwSize);
		Conv=lpBuffer;
	}
	else
		return("");
	if(Conv.GetAt(0)=='Ì')
		return("");
	else
		return(Conv);
}

void CCommon::RegSaveValue(CString cKey,CString cValue,CString cData)
{
HKEY hKey;
TCHAR szData[260];

	lstrcpy(szData, TEXT(cData));     
	hKey=HKEY_CURRENT_USER;
	RegCreateKey(hKey,cKey,&hKey);
	hKey=HKEY_CURRENT_USER;
	if (RegOpenKey(hKey,cKey,&hKey)==ERROR_SUCCESS)
	{
		RegSetValueEx(hKey,cValue,NULL,1,(LPBYTE)szData,sizeof(szData)+1);
	}
}
/*
CString CCommon::AppPath()
{
	TCHAR szModule[_MAX_PATH];
	GetModuleFileName(NULL, szModule, _MAX_PATH);
	CString sTemp=szModule;
	int iPos=sTemp.GetLength();
	for(int i=iPos;i>=1;i--)
	{
		if (sTemp.Mid(i,1)=="\\")
		{
			return(sTemp.Left(i+1));
		}
	}
	return("");
}

CString CCommon::GetFileNameNoExt(CString cFileName)
{
	int iPos=cFileName.GetLength();
	for(int i=iPos;i>=1;i--)
	{
		if (cFileName.Mid(i,1)==".")
		{
			return(cFileName.Left(i));
		}
	}
	return("");
}*/
