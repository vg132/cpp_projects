#include "StdAfx.h"
#include "vgreg.hpp"

VGReg::VGReg(void)
{
}

VGReg::~VGReg(void)
{
}

bool VGReg::ReadValue(HKEY root, char* path, char* value, char* data, DWORD size)
{
	HKEY hKey;
	if(RegOpenKeyEx(root,path,0,KEY_READ,&hKey)==ERROR_SUCCESS)
	{
		if(RegQueryValueEx(hKey,value,NULL,NULL,(LPBYTE)data,&size)==ERROR_SUCCESS)
			return(true);
	}
	return(false);
}
bool VGReg::WriteValue(HKEY root, char* path, char* value,DWORD type, char* data, DWORD size)
{
	HKEY hKey;
	if(RegCreateKeyEx(root,path,0,NULL,REG_OPTION_NON_VOLATILE,KEY_WRITE,NULL,&hKey,NULL)==ERROR_SUCCESS)
	{
		if(RegSetValueEx(hKey,value,0,type,(LPBYTE)data,size)==ERROR_SUCCESS)
			return(true);
	}
	return(false);
}