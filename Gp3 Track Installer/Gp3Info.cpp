// Gp3Info.cpp: implementation of the CGp3Info class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "gp3trackinstaller.h"
#include "Gp3Info.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGp3Info::CGp3Info()
{

}

CGp3Info::~CGp3Info()
{

}


bool CGp3Info::LoadInfo(char *file)
{
	HANDLE hFile;
	DWORD dwSize;
	DWORD dwReadSize;
	char* lpBuffer;

	hFile=CreateFile(file,
				GENERIC_READ,
				FILE_SHARE_READ,
				NULL,
				OPEN_EXISTING,
				FILE_ATTRIBUTE_NORMAL,
				NULL);
	if(hFile==INVALID_HANDLE_VALUE)
		return(false);
	dwSize=GetFileSize(hFile,NULL);
	lpBuffer=new char[dwSize];
	ReadFile(hFile,lpBuffer,dwSize,&dwReadSize,NULL);
	CloseHandle(hFile);

	char* lpData=new char[9];
	dwSize=dwReadSize;
	dwReadSize-=10;
	while(strcmpi(lpData,"#GP3INFO")&&dwReadSize>3000)
	{
		strncpy(lpData,&lpBuffer[dwReadSize--],8);
		lpData[8]='\0';
	};
	delete[] lpData;
	lpData=new char[dwSize-dwReadSize];
	strncpy(lpData,&lpBuffer[dwReadSize+1],dwSize-dwReadSize-1);
	strcat(lpData,"\0");
	m_szGp3Info.Insert(0,lpData);
	delete[] lpData;
	delete[] lpBuffer;
	return(true);
}

CString CGp3Info::GetName()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|Name|",0);
	if(iPos!=-1)
	{
		iPos+=6;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}

CString CGp3Info::GetCountry()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|Country|",0);
	if(iPos!=-1)
	{
		iPos+=9;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}

CString CGp3Info::GetLength()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|LengthMeters|",0);
	if(iPos!=-1)
	{
		iPos+=14;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}

CString CGp3Info::GetLaps()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|Laps|",0);
	if(iPos!=-1)
	{
		iPos+=6;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}

CString CGp3Info::GetSlot()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|Slot|",0);
	if(iPos!=-1)
	{
		iPos+=6;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}

CString CGp3Info::GetWare()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|Tyre|",0);
	if(iPos!=-1)
	{
		iPos+=6;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}

CString CGp3Info::GetDesc()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|Desc|",0);
	if(iPos!=-1)
	{
		iPos+=6;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}

CString CGp3Info::GetQualRec()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|LapRecordQualify|",0);
	if(iPos!=-1)
	{
		iPos+=18;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	if(szBuffer=="None Entered")
		CString szBuffer("");
	return(szBuffer);
}

CString CGp3Info::GetRaceRec()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|LapRecord|",0);
	if(iPos!=-1)
	{
		iPos+=11;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	if(szBuffer=="None Entered")
		CString szBuffer("");
	return(szBuffer);
}

CString CGp3Info::GetAuthor()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|Author|",0);
	if(iPos!=-1)
	{
		iPos+=8;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}

CString CGp3Info::GetEvent()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|Event|",0);
	if(iPos!=-1)
	{
		iPos+=7;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}

CString CGp3Info::GetYear()
{
	char ch;
	int iPos(0);
	CString szBuffer("");
	iPos=m_szGp3Info.Find("|Year|",0);
	if(iPos!=-1)
	{
		iPos+=6;
		while((ch=m_szGp3Info.GetAt(iPos))!='|')
		{
			szBuffer+=ch;
			iPos++;
		}
	}
	return(szBuffer);
}
/*
bool CGp3Info::OrgTrack(int nr)
{
	if(nr==0)
		m_szGp3Info="#GP3INFO|Name|Melbourne|Country|Australia|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|58|Slot|1|Tyre|25000|LengthMeters|5301|LapRecord|1:31.649|LapRecordQualify|1:30.010|";
	else if(nr==1)
		m_szGp3Info="#GP3INFO|Name|Interlagos|Country|Brazil|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|72|Slot|2|Tyre|25000|LengthMeters|4330|LapRecord|1:19.337|LapRecordQualify|1:17.092|";
	else if(nr==2)
		m_szGp3Info="#GP3INFO|Name|Buenos Aires|Country|Argentina|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|72|Slot|3|Tyre|25000|LengthMeters|4257|LapRecord|1:28.179|LapRecordQualify|1:25.852|";
	else if(nr==3)
		m_szGp3Info="#GP3INFO|Name|Imola|Country|San Marino|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|62|Slot|4|Tyre|25000|LengthMeters|4930|LapRecord|1:29.345|LapRecordQualify|1:25.973|";
	else if(nr==4)
		m_szGp3Info="#GP3INFO|Name|Barcelona|Country|Spain|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|65|Slot|5|Tyre|25000|LengthMeters|4725|LapRecord|1:24.275|LapRecordQualify|1:20.262|";
	else if(nr==5)
		m_szGp3Info="#GP3INFO|Name|Monte Carlo|Country|Monaco|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|78|Slot|6|Tyre|25000|LengthMeters|3418|LapRecord|1:22.948|LapRecordQualify|1:19.798|";
	else if(nr==6)
		m_szGp3Info="#GP3INFO|Name|Montreal|Country|Canada|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|69|Slot|7|Tyre|25000|LengthMeters|4418|LapRecord|1:19.379|LapRecordQualify|1:18.213|";
	else if(nr==7)
		m_szGp3Info="#GP3INFO|Name|Magny Cours|Country|France|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|71|Slot|8|Tyre|25000|LengthMeters|4247|LapRecord|1:17.523|LapRecordQualify|1:14.929|";
	else if(nr==8)
		m_szGp3Info="#GP3INFO|Name|Silverstone|Country|United Kingdom|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|70|Slot|9|Tyre|25000|LengthMeters|5174|LapRecord|1:35.704|LapRecordQualify|1:23.271|";
	else if(nr==9)
		m_szGp3Info="#GP3INFO|Name|A1-ring|Country|Austria|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|71|Slot|10|Tyre|25000|LengthMeters|4315|LapRecord|1:12.878|LapRecordQualify|1:29.598|";
	else if(nr==10)
		m_szGp3Info="#GP3INFO|Name|Hockenheim|Country|Germany|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|45|Slot|11|Tyre|25000|LengthMeters|6822|LapRecord|1:46.116|LapRecordQualify|1:41.838|";
	else if(nr==11)
		m_szGp3Info="#GP3INFO|Name|Hungaroring|Country|Hungary|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|77|Slot|12|Tyre|25000|LengthMeters|3969|LapRecord|1:16.973|LapRecordQualify|1:19.286|";
	else if(nr==12)
		m_szGp3Info="#GP3INFO|Name|Spa-Francorchamps|Country|Belgium|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|44|Slot|13|Tyre|25000|LengthMeters|6973|LapRecord|2:03.766|LapRecordQualify|1:48.682|";
	else if(nr==13)
		m_szGp3Info="#GP3INFO|Name|Monza|Country|Italy|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|53|Slot|14|Tyre|25000|LengthMeters|5769|LapRecord|1:25.139|LapRecordQualify|1:25.280|";
	else if(nr==14)
		m_szGp3Info="#GP3INFO|Name|Nurburgring|Country|Germany|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|67|Slot|15|Tyre|25000|LengthMeters|4554|LapRecord|1:20.450|LapRecordQualify|1:18.561|";
	else if(nr==15)
		m_szGp3Info="#GP3INFO|Name|Suzuka|Country|Japan|Created|Created by GP3Track Editor written by Paul Hoad see (License.txt about distributing this track)|Author|Microprose|Year|1998|Event|Formula 1|Desc||Laps|51|Slot|16|Tyre|25000|LengthMeters|5861|LapRecord|1:40.190|LapRecordQualify|1:36.293|";
	return(true);
}
*/