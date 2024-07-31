#include "stdafx.h"
#include "Gp3 Setup Spliter.h"
#include "SetupFile.h"

CSetupFile::CSetupFile()
{
	m_GpXSetupFile=NULL;
	m_FileName=NULL;
}

CSetupFile::~CSetupFile()
{
	if(m_GpXSetupFile!=NULL)
	{
		if(GetFileType()>=3)
			delete[] m_GpXSetupFile;
		else
			delete m_GpXSetupFile;
		m_GpXSetupFile=NULL;
	}
	if(m_FileName!=NULL)
		delete[] m_FileName;
}

bool CSetupFile::ReadGp2SetupFile()
{
	m_GpXSetupFileHeader=new GpXSetupFileHeader;
	m_GpXSetupFile=new GpXSetupFile[1];
	CFile file;
	file.Open(m_FileName,CFile::modeRead);
	file.Read((char*)m_GpXSetupFileHeader,32);
	file.Read((char*)m_GpXSetupFile,sizeof(GpXSetupFile));
	file.Close();
	return(true);
}

bool CSetupFile::ReadGp3SetupFile()
{
	m_GpXSetupFileHeader=new GpXSetupFileHeader;
	m_GpXSetupFile=new GpXSetupFile[1];
	CFile file;
	file.Open(m_FileName,CFile::modeRead);
	file.Read((char*)m_GpXSetupFileHeader,32);
	file.Read((char*)m_GpXSetupFile,sizeof(GpXSetupFile));
	file.Close();
	return(true);
}

bool CSetupFile::ReadGp2MultiSetupFile()
{
	m_GpXSetupFileHeader=new GpXSetupFileHeader;
	m_GpXSetupFile=new GpXSetupFile[64];
	CFile file;
	file.Open(m_FileName,CFile::modeRead);
	file.Read((char*)m_GpXSetupFileHeader,34);
	for(int i=0;i<64;i+=4)
	{
		file.Read(&m_GpXSetupFile[i],48);
		file.Read(&m_GpXSetupFile[i+1],48);
		file.Read(&m_GpXSetupFile[i+2],48);
		file.Read(&m_GpXSetupFile[i+3],48);
	}
	return(true);
}

bool CSetupFile::ReadGp3MultiSetupFile()
{
	m_GpXSetupFileHeader=new GpXSetupFileHeader;
	m_GpXSetupFile=new GpXSetupFile[64];
	CFile file;
	file.Open(m_FileName,CFile::modeRead);
	file.Read((char*)m_GpXSetupFileHeader,40);
	for(int i=0;i<64;i+=4)
	{
		int k=sizeof(GpXSetupFile);
		file.Read(&m_GpXSetupFile[i],sizeof(GpXSetupFile));
		file.Read(&m_GpXSetupFile[i+1],sizeof(GpXSetupFile));
		file.Read(&m_GpXSetupFile[i+2],sizeof(GpXSetupFile));
		file.Read(&m_GpXSetupFile[i+3],sizeof(GpXSetupFile));
		file.Seek(4,CFile::current);
	}
	return(true);
}

bool CSetupFile::OpenFile(char *FileName)
{
	m_FileName=new char[strlen(FileName)+1];
	strcpy(m_FileName,FileName);

	int iTmp = GetFileTypeId(FileName);
	if(iTmp==-1)
		return(false);
	SetFileType(iTmp);
	if(iTmp==1)
		ReadGp2SetupFile();
	else if(iTmp==2)
		ReadGp3SetupFile();
	else if(iTmp==3)
		ReadGp2MultiSetupFile();
	else if(iTmp==4)
		ReadGp3MultiSetupFile();
	return(true);
}

int CSetupFile::GetFrontWing(int id)
{
	return(m_GpXSetupFile[id].FrontWing);
}

int CSetupFile::GetRearWing(int id)
{
	return(m_GpXSetupFile[id].RearWing);
}

int CSetupFile::GetGear1(int id)
{
	return(m_GpXSetupFile[id].Gear1);
}

int CSetupFile::GetGear2(int id)
{
	return(m_GpXSetupFile[id].Gear2);
}

int CSetupFile::GetGear3(int id)
{
	return(m_GpXSetupFile[id].Gear3);
}

int CSetupFile::GetGear4(int id)
{
	return(m_GpXSetupFile[id].Gear4);
}

int CSetupFile::GetGear5(int id)
{
	return(m_GpXSetupFile[id].Gear5);
}

int CSetupFile::GetGear6(int id)
{
	return(m_GpXSetupFile[id].Gear6);
}

int CSetupFile::GetTyreChoice(int id)
{
	return(m_GpXSetupFile[id].TyreChoice);
}

int CSetupFile::GetBrakeBalans(int id)
{
	return(m_GpXSetupFile[id].BrakeBalans);
}

int CSetupFile::GetNrOfStops(int id)
{
	return(m_GpXSetupFile[id].NrOfStops);
}

int CSetupFile::GetFirstStop(int id)
{
	return(m_GpXSetupFile[id].FirstStop);
}

int CSetupFile::GetSecondStop(int id)
{
	return(m_GpXSetupFile[id].SecondStop);
}

int CSetupFile::GetThirdStop(int id)
{
	return(m_GpXSetupFile[id].ThirdStop);
}

int CSetupFile::GetLeftRearPackers(int id)
{
	return(m_GpXSetupFile[id].LeftRearPackers);
}

int CSetupFile::GetRightRearPackers(int id)
{
	return(m_GpXSetupFile[id].RightRearPackers);
}

int CSetupFile::GetLeftFrontPackers(int id)
{
	return(m_GpXSetupFile[id].LeftFrontPackers);
}

int CSetupFile::GetRightFrontPackers(int id)
{
	return(m_GpXSetupFile[id].RightFrontPackers);
}

int CSetupFile::GetLeftRearDumperFastBump(int id)
{
	return(m_GpXSetupFile[id].LeftRearDumperFastBump);
}

int CSetupFile::GetRightRearDumperFastBump(int id)
{
	return(m_GpXSetupFile[id].RightRearDumperFastBump);
}

int CSetupFile::GetLeftFrontDumperFastBump(int id)
{
	return(m_GpXSetupFile[id].LeftFrontDumperFastBump);
}

int CSetupFile::GetRightFrontDumperFastBump(int id)
{
	return(m_GpXSetupFile[id].RightFrontDumperFastBump);
}

int CSetupFile::GetLeftRearFastRebound(int id)
{
	return(m_GpXSetupFile[id].LeftRearFastRebound);
}

int CSetupFile::GetRightRearFastRebound(int id)
{
	return(m_GpXSetupFile[id].RightRearFastRebound);
}

int CSetupFile::GetLeftFrontFastRebound(int id)
{
	return(m_GpXSetupFile[id].LeftFrontFastRebound);
}

int CSetupFile::GetRightFrontFastRebound(int id)
{
	return(m_GpXSetupFile[id].RightFrontFastRebound);
}

int CSetupFile::GetLeftRearSlowBump(int id)
{
	return(m_GpXSetupFile[id].LeftRearSlowBump);
}

int CSetupFile::GetRightRearSlowBump(int id)
{
	return(m_GpXSetupFile[id].RightRearSlowBump);
}

int CSetupFile::GetLeftFrontSlowBump(int id)
{
	return(m_GpXSetupFile[id].LeftFrontSlowBump);
}

int CSetupFile::GetRightFrontSlowBump(int id)
{
	return(m_GpXSetupFile[id].RightFrontSlowBump);
}

int CSetupFile::GetLeftRearSlowRebound(int id)
{
	return(m_GpXSetupFile[id].LeftRearSlowRebound);
}

int CSetupFile::GetRightRearSlowRebound(int id)
{
	return(m_GpXSetupFile[id].RightRearSlowRebound);
}

int CSetupFile::GetLeftFrontSlowRebound(int id)
{
	return(m_GpXSetupFile[id].LeftFrontSlowRebound);
}

int CSetupFile::GetRightFrontSlowRebound(int id)
{
	return(m_GpXSetupFile[id].RightFrontSlowRebound);
}

int CSetupFile::GetLeftRearSpring(int id)
{
		return(m_GpXSetupFile[id].LeftRearSpring);
}

int CSetupFile::GetRightRearSpring(int id)
{
	return(m_GpXSetupFile[id].RightRearSpring);
}

int CSetupFile::GetLeftFrontSpring(int id)
{
	return(m_GpXSetupFile[id].LeftFrontSpring);
}

int CSetupFile::GetRightFrontSpring(int id)
{
	return(m_GpXSetupFile[id].RightFrontSpring);
}

int CSetupFile::GetLeftRearRideHeight(int id)
{
	return(m_GpXSetupFile[id].LeftRearRideHeight);
}

int CSetupFile::GetRightRearRideHeight(int id)
{
	return(m_GpXSetupFile[id].RightRearRideHeight);
}

int CSetupFile::GetLeftFrontRideHeight(int id)
{
	return(m_GpXSetupFile[id].LeftFrontRideHeight);
}

int CSetupFile::GetRightFrontRideHeight(int id)
{
	return(m_GpXSetupFile[id].RightFrontRideHeight);
}

int CSetupFile::GetRearAntiRollBar(int id)
{
	return(m_GpXSetupFile[id].RearAntiRollBar);
}

int CSetupFile::GetFrontAntiRollBar(int id)
{
	return(m_GpXSetupFile[id].FrontAntiRollBar);
}

int CSetupFile::GetDifferential(int id)
{
	return(m_GpXSetupFile[id].Differential);
}

bool CSetupFile::IsOpen()
{
	if(m_GpXSetupFile!=NULL)
		return(true);
	else
		return(false);
}

int CSetupFile::GetFileTypeId(char *FileName)
{
	int iFileSize;
	CFile file;

	file.Open(FileName,CFile::modeRead);
	iFileSize=file.GetLength();
	file.Close();

	if(iFileSize==92)
		return(2);
	else if(iFileSize==84)
		return(1);
	else if(iFileSize==3110)
		return(3);
	else if(iFileSize==3688)
		return(4);
	else
		return(-1);
}

char* CSetupFile::GetFileName()
{
	return(m_FileName);
}

void CSetupFile::SetFrontWing(int value, int id)
{
	m_GpXSetupFile[id].FrontWing=value;
}

void CSetupFile::SetRearWing(int value, int id)
{
	m_GpXSetupFile[id].RearWing=value;
}

void CSetupFile::SetGear1(int value, int id)
{
	m_GpXSetupFile[id].Gear1=value;
}

void CSetupFile::SetGear2(int value, int id)
{
	m_GpXSetupFile[id].Gear2=value;
}

void CSetupFile::SetGear3(int value, int id)
{
	m_GpXSetupFile[id].Gear3=value;
}

void CSetupFile::SetGear4(int value, int id)
{
	m_GpXSetupFile[id].Gear4=value;
}

void CSetupFile::SetGear5(int value, int id)
{
	m_GpXSetupFile[id].Gear5=value;
}

void CSetupFile::SetGear6(int value, int id)
{
	m_GpXSetupFile[id].Gear6=value;
}

void CSetupFile::SetTyreChoice(int value, int id)
{
	m_GpXSetupFile[id].TyreChoice=value;
}

void CSetupFile::SetBrakeBalans(int value, int id)
{
	m_GpXSetupFile[id].BrakeBalans=value;
}

void CSetupFile::SetNrOfStops(int value, int id)
{
	m_GpXSetupFile[id].NrOfStops=value;
}

void CSetupFile::SetFirstStop(int value, int id)
{
	m_GpXSetupFile[id].FirstStop=value;
}

void CSetupFile::SetSecondStop(int value, int id)
{
	m_GpXSetupFile[id].SecondStop=value;
}

void CSetupFile::SetThirdStop(int value, int id)
{
	m_GpXSetupFile[id].ThirdStop=value;
}

void CSetupFile::SetLeftRearPackers(int value, int id)
{
	m_GpXSetupFile[id].LeftRearPackers=value;
}

void CSetupFile::SetRightRearPackers(int value, int id)
{
	m_GpXSetupFile[id].RightRearPackers=value;
}

void CSetupFile::SetLeftFrontPackers(int value, int id)
{
	m_GpXSetupFile[id].LeftFrontPackers=value;
}

void CSetupFile::SetRightFrontPackers(int value, int id)
{
	m_GpXSetupFile[id].RightFrontPackers=value;
}

void CSetupFile::SetLeftRearDumperFastBump(int value, int id)
{
	m_GpXSetupFile[id].LeftRearDumperFastBump=value;
}

void CSetupFile::SetRightRearDumperFastBump(int value, int id)
{
	m_GpXSetupFile[id].RightRearDumperFastBump=value;
}

void CSetupFile::SetLeftFrontDumperFastBump(int value, int id)
{
	m_GpXSetupFile[id].LeftFrontDumperFastBump=value;
}

void CSetupFile::SetRightFrontDumperFastBump(int value, int id)
{
	m_GpXSetupFile[id].RightFrontDumperFastBump=value;
}

void CSetupFile::SetLeftRearFastRebound(int value, int id)
{
	m_GpXSetupFile[id].LeftRearFastRebound=value;
}

void CSetupFile::SetRightRearFastRebound(int value, int id)
{
	m_GpXSetupFile[id].RightRearFastRebound=value;
}

void CSetupFile::SetLeftFrontFastRebound(int value, int id)
{
	m_GpXSetupFile[id].LeftFrontFastRebound=value;
}

void CSetupFile::SetRightFrontFastRebound(int value, int id)
{
	m_GpXSetupFile[id].RightFrontFastRebound=value;
}

void CSetupFile::SetLeftRearSlowBump(int value, int id)
{
	m_GpXSetupFile[id].LeftRearSlowBump=value;
}

void CSetupFile::SetRightRearSlowBump(int value, int id)
{
	m_GpXSetupFile[id].RightRearSlowBump=value;
}

void CSetupFile::SetLeftFrontSlowBump(int value, int id)
{
	m_GpXSetupFile[id].LeftFrontSlowBump=value;
}

void CSetupFile::SetRightFrontSlowBump(int value, int id)
{
	m_GpXSetupFile[id].RightFrontSlowBump=value;
}

void CSetupFile::SetLeftRearSlowRebound(int value, int id)
{
	m_GpXSetupFile[id].LeftRearSlowRebound=value;
}

void CSetupFile::SetRightRearSlowRebound(int value, int id)
{
	m_GpXSetupFile[id].RightRearSlowRebound=value;
}

void CSetupFile::SetLeftFrontSlowRebound(int value, int id)
{
	m_GpXSetupFile[id].LeftFrontSlowRebound=value;
}

void CSetupFile::SetRightFrontSlowRebound(int value, int id)
{
	m_GpXSetupFile[id].RightFrontSlowRebound=value;
}

void CSetupFile::SetLeftRearSpring(int value, int id)
{
	m_GpXSetupFile[id].LeftRearSpring=value;
}

void CSetupFile::SetRightRearSpring(int value, int id)
{
	m_GpXSetupFile[id].RightRearSpring=value;
}

void CSetupFile::SetLeftFrontSpring(int value, int id)
{
	m_GpXSetupFile[id].LeftFrontSpring=value;
}

void CSetupFile::SetRightFrontSpring(int value, int id)
{
	m_GpXSetupFile[id].RightFrontSpring=value;
}

void CSetupFile::SetLeftRearRideHeight(int value, int id)
{
	m_GpXSetupFile[id].LeftRearRideHeight=value;
}

void CSetupFile::SetRightRearRideHeight(int value, int id)
{
	m_GpXSetupFile[id].RightRearRideHeight=value;
}

void CSetupFile::SetLeftFrontRideHeight(int value, int id)
{
	m_GpXSetupFile[id].LeftFrontRideHeight=value;
}

void CSetupFile::SetRightFrontRideHeight(int value, int id)
{
	m_GpXSetupFile[id].RightFrontRideHeight=value;
}

void CSetupFile::SetRearAntiRollBar(int value, int id)
{
	m_GpXSetupFile[id].RearAntiRollBar=value;
}

void CSetupFile::SetFrontAntiRollBar(int value, int id)
{
	m_GpXSetupFile[id].FrontAntiRollBar=value;
}

void CSetupFile::SetDifferential(int value, int id)
{
	m_GpXSetupFile[id].Differential=value;
}

bool CSetupFile::CheckSum(char* FileName)
{
long datasize;
unsigned short sum=0,cycle=0;
unsigned char c;

	CFile file;
	if(FileName==NULL)
		file.Open(m_FileName,CFile::modeReadWrite);
	else
		file.Open(FileName,CFile::modeReadWrite);

	datasize=file.GetLength()-4;

	while(datasize--)
	{
		file.Read((char*)&c,sizeof(c));
		sum+=c;
		cycle=(cycle<<3)+(cycle>>13);
		cycle+=c;
	}
	file.Seek(-4,CFile::end);
	file.Write((char*)&sum,sizeof(sum));
	file.Write((char*)&cycle,sizeof(cycle));
	file.Close();
	return(true);
}

void CSetupFile::SaveGp2File(int pos, int id, char* FileName)
{
	CFile file;
	if(GetFileType()<3)
	{
		if(FileName!=NULL)
		{
			delete[] m_FileName;
			m_FileName=new char[strlen(FileName)+1];
			strcpy(m_FileName,FileName);
		}
		file.Open(m_FileName,CFile::modeWrite|CFile::modeCreate);
	}
	else
	{
		file.Open(FileName,CFile::modeWrite|CFile::modeCreate);
	}
	if(pos!=-1)
		m_GpXSetupFileHeader->SetupPos=pos;
	file.Write(m_GpXSetupFileHeader,32);
	file.Write(&m_GpXSetupFile[id],sizeof(GpXSetupFile)-8);
	file.Write((char*)"\0\0\0\0",4);
	file.Close();
	if(GetFileType()<3)
	{
		CheckSum();
		SetFileType(1);
	}
	else
	{
		CheckSum(FileName);
	}
}

void CSetupFile::SaveGp3File(int pos, int id, char *FileName)
{
	CFile file;
	if(GetFileType()<3)
	{
		if(FileName!=NULL)
		{
			delete[] m_FileName;
			m_FileName=new char[strlen(FileName)+1];
			strcpy(m_FileName,FileName);
		}
		file.Open(m_FileName,CFile::modeWrite|CFile::modeCreate);
	}
	else
	{
		file.Open(FileName,CFile::modeWrite|CFile::modeCreate);
	}
	if(pos!=-1)
		m_GpXSetupFileHeader->SetupPos=pos;
	file.Write(m_GpXSetupFileHeader,32);
	file.Write(&m_GpXSetupFile[id],sizeof(GpXSetupFile));
	file.Write((char*)"\0\0\0\0",4);
	file.Close();
	CheckSum();
	if(GetFileType()<3)
	{
		CheckSum();
		SetFileType(2);
	}
	else
	{
		CheckSum(FileName);
	}
}


void CSetupFile::SaveGp2MultiFile(char *FileName)
{
	CFile file;
	if(FileName!=NULL)
	{
		delete[] m_FileName;
		m_FileName=new char[strlen(FileName)+1];
		strcpy(m_FileName,FileName);
	}
	file.Open(m_FileName,CFile::modeWrite|CFile::modeCreate);
	file.Write(m_GpXSetupFileHeader,34);
	for(int i=0;i<64;i+=4)
	{
		file.Write(&m_GpXSetupFile[i],48);
		file.Write(&m_GpXSetupFile[i+1],48);
		file.Write(&m_GpXSetupFile[i+2],48);
		file.Write(&m_GpXSetupFile[i+3],48);
	}
	file.Write((char*)"\0\0\0\0",4);
	file.Close();
	CheckSum();
	SetFileType(4);
}

void CSetupFile::SaveGp3MultiFile(char *FileName)
{
	CFile file;
	int data=1241513728;
	if(FileName!=NULL)
	{
		delete[] m_FileName;
		m_FileName=new char[strlen(FileName)+1];
		strcpy(m_FileName,FileName);
	}
	file.Open(m_FileName,CFile::modeWrite|CFile::modeCreate);
	file.Write(m_GpXSetupFileHeader,40);
	for(int i=0;i<64;i+=4)
	{
		file.Write(&m_GpXSetupFile[i],sizeof(GpXSetupFile));
		file.Write(&m_GpXSetupFile[i+1],sizeof(GpXSetupFile));
		file.Write(&m_GpXSetupFile[i+2],sizeof(GpXSetupFile));
		file.Write(&m_GpXSetupFile[i+3],sizeof(GpXSetupFile));
		file.Write((char*)&data,sizeof(int));
	}
	file.Close();
	CheckSum();
	SetFileType(4);
}
