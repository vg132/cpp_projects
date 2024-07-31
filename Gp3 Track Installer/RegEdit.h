// RegEdit.h: interface for the CRegEdit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGEDIT_H__84819202_8D4C_4C7F_BB30_86398CD5B097__INCLUDED_)
#define AFX_REGEDIT_H__84819202_8D4C_4C7F_BB30_86398CD5B097__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRegEdit  
{
public:
	char* GetSettings(HKEY hKey, CString Path, CString Value, char* Default);
	CString GetSettings(HKEY hKey, CString Path, CString Value, CString Default);
	int GetSettings(HKEY hKey, CString Path, CString Value, int Default);
	bool SaveSettings(HKEY hKey, CString Path, CString Value, CString Data);
	bool SaveSettings(HKEY hKey, CString Path, CString Value, int Data);
	CRegEdit();
	virtual ~CRegEdit();
};

#endif // !defined(AFX_REGEDIT_H__84819202_8D4C_4C7F_BB30_86398CD5B097__INCLUDED_)
