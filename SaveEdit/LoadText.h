// LoadText.h: interface for the CLoadText class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOADTEXT_H__C854BDA1_484F_11D4_A39C_0008C7636E27__INCLUDED_)
#define AFX_LOADTEXT_H__C854BDA1_484F_11D4_A39C_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLoadText  
{
public:
	bool LoadText();
	CLoadText();
	virtual ~CLoadText();
	CString m_Name[139];

	CString m_Teams[12];

	CString m_Engine[9];
	CString m_TeamSponcor[7];
	CString m_Tyre[3];
	CString m_Fuel[8];
	CString m_Sponsors[71];

	CString m_Tracks[16];
	CString m_RecNames[4];
	CString m_Country[15];
	CString m_Names;

private:
	void Split();
};

#endif // !defined(AFX_LOADTEXT_H__C854BDA1_484F_11D4_A39C_0008C7636E27__INCLUDED_)
