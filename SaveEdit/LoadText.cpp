// LoadText.cpp: implementation of the CLoadText class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LoadText.h"
#include "SaveEdit.h"
#include "Common.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLoadText::CLoadText()
{

}

CLoadText::~CLoadText()
{

}

bool CLoadText::LoadText()
{
HANDLE hFile;
DWORD dwSize;
DWORD dwReadSize;
char ch;
CString szPath;
CCommon m_Common;

	szPath=m_Common.RegGetValue("Software\\VG Software\\GPW Save File Editor\\Settings","GPWPath");
	if(szPath.Right(1)!="\\")
		szPath+="\\";
	szPath+="english.txt";
	hFile=CreateFile(szPath,GENERIC_READ,
					FILE_SHARE_READ,
					NULL,OPEN_EXISTING,
					FILE_ATTRIBUTE_NORMAL,
					NULL);
	if(hFile==(HANDLE)-1)
		return(false);

	dwSize=GetFileSize(hFile,NULL);

	char * lpBuffer = (char*)GlobalAlloc(GMEM_FIXED,dwSize );
	ReadFile(hFile,(LPVOID)lpBuffer,dwSize,&dwReadSize,NULL);

	CloseHandle(hFile);
	int i;
	int v;
	int start;
	start=0;
	v=0;
	i=0;
	//m_Names="";
	for(v=0;v<6534;)
	{
		ch=lpBuffer[i];
		if(ch=='\15')
		{
			v++;
			i+=10;
		}
		if((v>=4876&&v<=4973)||(v>=5696&&v<=5707)||
		   (v>=5795&&v<=5934)||(v>=5952&&v<=5966)||
		   (v>=6044&&v<=6059)||(v>=6530&&v<=6533))
		{
			i++;
			do
			{
				ch=lpBuffer[i];
				if(ch=='"'&&start==0)
				{
					start=1;
					i++;
					ch=lpBuffer[i];
				}
				if(ch=='"'&&start==1)
					start=0;
				if(start==1)
					m_Names=m_Names+ch;
				i++;
			}while(ch!='\15');
			m_Names+="|";
			v++;
		}
		i++;
	}
	GlobalFree(lpBuffer);

	Split();
	return(true);
}

void CLoadText::Split()
{
int i;
int pos=0;
int start=0;

	for(i=0;i<7;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_TeamSponcor[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}

	for(i=0;i<3;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_Tyre[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}
	
	for(i=0;i<8;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_Engine[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}

	for(i=0;i<9;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_Fuel[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}

	for(i=0;i<71;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_Sponsors[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}

	for(i=0;i<13;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_Teams[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}
	
	for(i=0;i<139;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_Name[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}

	for(i=0;i<15;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_Country[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}

	for(i=0;i<16;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_Tracks[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}

	for(i=0;i<4;i++)
	{
		pos=m_Names.Find("|",0);
		if(pos!=0)
			m_RecNames[i]=m_Names.Mid(0,pos);
		m_Names.Delete(0,pos+1);
	}
}
