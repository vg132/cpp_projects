// DataBase.cpp: implementation of the CDataBase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SaveEdit.h"
#include "DataBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDataBase::CDataBase()
{

}

CDataBase::~CDataBase()
{

}

CString CDataBase::GetTeam(int nr)
{
	return(m_Text.m_Teams[nr]);
}

void CDataBase::LoadAll()
{
	m_Text.LoadText("e:\\gpw\\english.txt");
}
