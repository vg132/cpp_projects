// SystemImageList.cpp: implementation of the CSystemImageList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Mp3FileStudio.h"
#include "SystemImageList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSystemImageList::CSystemImageList()
{
	if(m_SmallImageList==NULL)
	{
		m_SmallImageList.DeleteImageList();
		m_LargeImageList.DeleteImageList();

		m_SmallImageList.Create(16, 16, ILC_MASK | ILC_COLORDDB, 700, 500);
		m_LargeImageList.Create(32, 32, ILC_MASK | ILC_COLORDDB, 700, 500);

		m_SmallImageList.SetBkColor(ILD_TRANSPARENT);
		m_LargeImageList.SetBkColor(ILD_TRANSPARENT);

		//image list setup 
		HIMAGELIST	hSystemSmallImageList, hSystemLargeImageList; 
		SHFILEINFO	ssfi, lsfi; 

		//get a handle to the system small icon list 
		hSystemSmallImageList = (HIMAGELIST)SHGetFileInfo((LPCTSTR)_T("C:\\"),
														0,
														&ssfi,
														sizeof(SHFILEINFO),
														SHGFI_SYSICONINDEX | SHGFI_SMALLICON); 

		//attach it to the small image list 
		//--DON'T FORGET TO PUT m_smallImageList.Detach();  in your destructor 
		m_SmallImageList.Detach();

		m_SmallImageList.Attach(hSystemSmallImageList); 

		//do the same for the large 
		hSystemLargeImageList = (HIMAGELIST)SHGetFileInfo((LPCTSTR)_T("C:\\"),
														0,
														&lsfi,
														sizeof(SHFILEINFO),
														SHGFI_SYSICONINDEX | SHGFI_ICON);
		m_LargeImageList.Detach();
		m_LargeImageList.Attach(hSystemLargeImageList);
	}
}

CSystemImageList::~CSystemImageList()
{
	m_SmallImageList.Detach();
	m_LargeImageList.Detach();
}
