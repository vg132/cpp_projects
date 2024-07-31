// Common.h: interface for the CCommon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMON_H__8DA565A0_361F_11D4_A39C_0008C7636E27__INCLUDED_)
#define AFX_COMMON_H__8DA565A0_361F_11D4_A39C_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCommon  
{
public:
	CString BrowseForFolders(CString szTitle, HWND m_hWnd);
	CString GetFileName(CString cFileName);
	CString GetFileNameNoExt(CString cFileName);
	CString AppPath();
	CString RegGetValue(CString cKey,CString cValue);
	void RegSaveValue(CString cKey,CString cValue,CString cData);

	CCommon();
	virtual ~CCommon();

private:
};

#endif // !defined(AFX_COMMON_H__8DA565A0_361F_11D4_A39C_0008C7636E27__INCLUDED_)
