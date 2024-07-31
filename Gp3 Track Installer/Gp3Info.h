// Gp3Info.h: interface for the CGp3Info class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GP3INFO_H__2769F62F_69AC_46EA_8FEC_360B2A7B6720__INCLUDED_)
#define AFX_GP3INFO_H__2769F62F_69AC_46EA_8FEC_360B2A7B6720__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGp3Info  
{
private:
	CString m_szGp3Info;
public:

	CString GetName();
	CString GetCountry();
	CString GetLength();
	CString GetLaps();
	CString GetSlot();
	CString GetWare();
	CString GetDesc();
	CString GetQualRec();
	CString GetRaceRec();
	CString GetAuthor();
	CString GetEvent();
	CString GetYear();

	bool LoadInfo(char* file);
	CGp3Info();
	virtual ~CGp3Info();
};

#endif // !defined(AFX_GP3INFO_H__2769F62F_69AC_46EA_8FEC_360B2A7B6720__INCLUDED_)
