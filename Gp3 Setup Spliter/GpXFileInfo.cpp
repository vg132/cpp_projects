// GpXFileInfo.cpp: implementation of the CGpXFileInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Gp3 Setup Spliter.h"
#include "GpXFileInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGpXFileInfo::CGpXFileInfo()
{

}

CGpXFileInfo::~CGpXFileInfo()
{

}

void CGpXFileInfo::SetFileType(int FileType)
{
	m_FileType=FileType;
}

/**
 * Return the type of this setup file
 *
 * 1. Single Gp2 Setup File
 * 2. Single Gp3 Setup File
 * 3. Multi Gp2 Setup File
 * 4. Multi Gp3 Setup File
 */
int CGpXFileInfo::GetFileType()
{
	return(m_FileType);
}
