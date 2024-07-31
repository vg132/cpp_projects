// DataBase.h: interface for the CDataBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASE_H__E9E20080_6B08_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_DATABASE_H__E9E20080_6B08_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LoadText.h"
#include "GPWData.h"

class CDataBase  
{
public:
	void LoadAll();
	CString GetTeam(int nr);
	
	CDataBase();
	virtual ~CDataBase();

private:
	CLoadText m_Text;
	CGPWData m_Data;
};

#endif // !defined(AFX_DATABASE_H__E9E20080_6B08_11D4_8FC7_0008C7636E27__INCLUDED_)
