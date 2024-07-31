// GPWData.cpp: implementation of the CGPWData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SaveEdit.h"
#include "GPWData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGPWData::CGPWData()
{

}

CGPWData::~CGPWData()
{

}

bool CGPWData::LoadFile()
{
	if(m_File!="")
	{
		f.Open(m_File,CFile::modeRead,NULL);
		LoadDesign();
		LoadDrivers();
		LoadEngineering();
		LoadMechanics();
		LoadCommercial();
		LoadTeam();
		LoadHead();
		LoadRoot();
		f.Close();
		return(TRUE);
	}
	return(FALSE);
}

bool CGPWData::SaveFile()
{
	if(m_File!="")
	{
		f.Open(m_File,CFile::modeWrite,NULL);
		SaveDesign();
		SaveDrivers();
		SaveEngineering();
		SaveMechanics();
		SaveCommercial();
		SaveTeam();
		SaveRoot();
		f.Close();
		return(TRUE);
	}
	return(FALSE);
}

void CGPWData::LoadDrivers()
//load driver data
{
int iDriv[44]={5,6,7,13,14,15,21,22,23,29,30,31,37,38,39,45,46,47,53,54,55,61,62,63,69,70,71,77,78,79,85,86,87,128,129,130,131,132,133,134,135,136,137,138};
	for(i=0;i<44;i++)
	{
		f.Seek(97844+(3576*iDriv[i]),CFile::begin);
		f.Read((char*)&iDriver[0][i],sizeof(int));//Salary
		f.Seek(4,CFile::current);
		f.Read((char*)&iDriver[1][i],sizeof(int));//Race Bonus
		f.Read((char*)&iDriver[2][i],sizeof(int));//WC Bonus
		f.Seek(8,CFile::current);
		f.Read((char*)&iDriver[3][i],sizeof(int));//Points

		f.Seek(3088,CFile::current);
		f.Read((char*)&iDriver[4][i],sizeof(int));//Speed
		f.Read((char*)&iDriver[5][i],sizeof(int));//Overtaking
		f.Read((char*)&iDriver[6][i],sizeof(int));//Wet Wether
		f.Read((char*)&iDriver[7][i],sizeof(int));//Concentration
		f.Read((char*)&iDriver[8][i],sizeof(int));//Experience
		f.Read((char*)&iDriver[9][i],sizeof(int));//Stamina
		f.Read((char*)&iDriver[10][i],sizeof(int));//Morale
		f.Seek(4,CFile::current);
		f.Read((char*)&iDriver[11][i],sizeof(int));//Skill
	}
}

void CGPWData::LoadMechanics()
//Load Mechanics data
{
int iMec[21]={4,12,20,28,36,44,52,60,68,76,84,118,119,120,121,122,123,124,125,126,127};
	for(i=0;i<21;i++)
	{
		f.Seek(97844+(3576*iMec[i]),CFile::begin);
		f.Read((char*)&iMechanics[0][i],sizeof(int));//Salary
		f.Seek(4,CFile::current);
		f.Read((char*)&iMechanics[1][i],sizeof(int));//Race Bonus
		f.Read((char*)&iMechanics[2][i],sizeof(int));//WC Bonus
		f.Seek(4,CFile::current);
		f.Read((char*)&iMechanics[3][i],sizeof(int));//Ability
		f.Seek(132,CFile::current);
		f.Read((char*)&iMechanics[4][i],sizeof(int));//Last Year
	}
}

void CGPWData::LoadCommercial()
//Load commercial data
{
int iCom[21]={1,9,17,25,33,41,49,57,65,73,81,88,89,90,91,92,93,94,95,96,97};
	for(i=0;i<21;i++)
	{
		f.Seek(97844+(3576*iCom[i]),CFile::begin);
		f.Read((char*)&iCommercial[0][i],sizeof(int));//Salary
		f.Seek(12,CFile::current);
		f.Read((char*)&iCommercial[1][i],sizeof(int));//Royalty
		f.Read((char*)&iCommercial[2][i],sizeof(int));//Ability
		f.Seek(132,CFile::current);
		f.Read((char*)&iCommercial[3][i],sizeof(int));//Last Year
	}
}

void CGPWData::LoadDesign()
//Load design data
{
int iDes[21]={2,10,18,26,34,42,50,58,66,74,82,98,99,100,101,102,103,104,105,106,107};
	for(i=0;i<21;i++)
	{
		f.Seek(97844+(3576*iDes[i]),CFile::begin);
		f.Read((char*)&iDesign[0][i],sizeof(int));//Salary
		f.Seek(4,CFile::current);
		f.Read((char*)&iDesign[1][i],sizeof(int));//Race Bonus
		f.Read((char*)&iDesign[2][i],sizeof(int));//WC Bonus
		f.Seek(4,CFile::current);
		f.Read((char*)&iDesign[3][i],sizeof(int));//Ability
		f.Seek(132,CFile::current);
		f.Read((char*)&iDesign[4][i],sizeof(int));//Last Year
	}
}

void CGPWData::LoadEngineering()
//load engineering data
{
int iEng[21]={3,11,19,27,35,43,51,59,67,75,83,108,19,110,111,112,113,114,115,116,117};
	for(i=0;i<21;i++)
	{
		f.Seek(97844+(3576*iEng[i]),CFile::begin);
		f.Read((char*)&iEngineering[0][i],sizeof(int));//Salary
		f.Seek(4,CFile::current);
		f.Read((char*)&iEngineering[1][i],sizeof(int));//Race Bonus
		f.Read((char*)&iEngineering[2][i],sizeof(int));//WC Bonus
		f.Seek(4,CFile::current);
		f.Read((char*)&iEngineering[3][i],sizeof(int));//Ability
		f.Seek(132,CFile::current);
		f.Read((char*)&iEngineering[4][i],sizeof(int));//Last Year
	}
}

void CGPWData::LoadTeam()
//Load team data
{
	for(i=0;i<11;i++)
	{
		f.Seek(10712+(7824*i),CFile::begin);
		f.Read((char*)&iTeam[0][i],sizeof(int));//Budget
		f.Seek(2761216+(224*i),CFile::begin);
		f.Read((char*)&iTeam[1][i],sizeof(int));//Test Price
		f.Seek(8276+(7824*i),CFile::begin);
		f.Read((char*)&iTeam[2][i],sizeof(int));//Team Points
	}
}

void CGPWData::LoadRoot()
//Load Root data
{
int tmp=iHead[0]-1;
	f.Seek(9236+(7824*tmp),CFile::begin);
	//0=Commercial
	//1=Design
	//2=Engineering
	//3=Mechanics
	for(i=0;i<4;i++)
	{
		f.Read((char*)&iRoot[0][i],sizeof(int)); //Trainee
		f.Read((char*)&iRoot[1][i],sizeof(int)); //Average
		f.Read((char*)&iRoot[2][i],sizeof(int)); //Good
		f.Read((char*)&iRoot[3][i],sizeof(int)); //Very Good
		f.Read((char*)&iRoot[4][i],sizeof(int)); //Excellent
		if(i==0)
		{
			f.Seek(9160+(7824*tmp),CFile::begin);
			f.Read((char*)&iRoot[5][i],sizeof(int)); //Morale
			f.Seek(9620+(7824*tmp),CFile::begin);
		}
		else if(i==1)
		{
			f.Seek(9544+(7824*tmp),CFile::begin);
			f.Read((char*)&iRoot[5][i],sizeof(int)); //Morale
			f.Seek(10004+(7824*tmp),CFile::begin);
		}
		else if (i==2)
		{
			f.Seek(9928+(7824*tmp),CFile::begin);
			f.Read((char*)&iRoot[5][i],sizeof(int)); //Morale
			f.Seek(10416+(7824*tmp),CFile::begin);
		}
		else if(i==3)
		{
			f.Seek(10312+(7824*tmp),CFile::begin);
			f.Read((char*)&iRoot[5][i],sizeof(int)); //Morale
		}
	}
}

void CGPWData::SaveDrivers()
//Save driver data
{
int iDriv[44]={5,6,7,13,14,15,21,22,23,29,30,31,37,38,39,45,46,47,53,54,55,61,62,63,69,70,71,77,78,79,85,86,87,128,129,130,131,132,133,134,135,136,137,138};
	for(i=0;i<44;i++)
	{
		f.Seek(97844+(3576*iDriv[i]),CFile::begin);
		f.Write((char*)&iDriver[0][i],sizeof(int));//Salary
		f.Seek(4,CFile::current);
		f.Write((char*)&iDriver[1][i],sizeof(int));//Race Bonus
		f.Write((char*)&iDriver[2][i],sizeof(int));//WC Bonus
		f.Seek(12,CFile::current);//8 if point is writen to file!
//		f.Write((char*)&iDriver[3][i],sizeof(int));//Points

		f.Seek(3088,CFile::current);
		f.Write((char*)&iDriver[4][i],sizeof(int));//Speed
		f.Write((char*)&iDriver[5][i],sizeof(int));//Overtaking
		f.Write((char*)&iDriver[6][i],sizeof(int));//Wet Wether
		f.Write((char*)&iDriver[7][i],sizeof(int));//Concentration
		f.Write((char*)&iDriver[8][i],sizeof(int));//Experience
		f.Write((char*)&iDriver[9][i],sizeof(int));//Stamina
		f.Write((char*)&iDriver[10][i],sizeof(int));//Morale
		f.Seek(4,CFile::current);
		f.Write((char*)&iDriver[11][i],sizeof(int));//Skill
	}
}

void CGPWData::SaveEngineering()
//Save engineering data
{
int iEng[21]={3,11,19,27,35,43,51,59,67,75,83,108,19,110,111,112,113,114,115,116,117};
	for(i=0;i<21;i++)
	{
		f.Seek(97844+(3576*iEng[i]),CFile::begin);
		f.Write((char*)&iEngineering[0][i],sizeof(int));//Salary
		f.Seek(4,CFile::current);
		f.Write((char*)&iEngineering[1][i],sizeof(int));//Race Bonus
		f.Write((char*)&iEngineering[2][i],sizeof(int));//WC Bonus
		f.Seek(4,CFile::current);
		f.Write((char*)&iEngineering[3][i],sizeof(int));//Ability
		f.Seek(132,CFile::current);
		f.Write((char*)&iEngineering[4][i],sizeof(int));//Last Year
	}
}

void CGPWData::SaveDesign()
//Save design data
{
int iDes[21]={2,10,18,26,34,42,50,58,66,74,82,98,99,100,101,102,103,104,105,106,107};
	for(i=0;i<21;i++)
	{
		f.Seek(97844+(3576*iDes[i]),CFile::begin);
		f.Write((char*)&iDesign[0][i],sizeof(int));//Salary
		f.Seek(4,CFile::current);
		f.Write((char*)&iDesign[1][i],sizeof(int));//Race Bonus
		f.Write((char*)&iDesign[2][i],sizeof(int));//WC Bonus
		f.Seek(4,CFile::current);
		f.Write((char*)&iDesign[3][i],sizeof(int));//Ability
		f.Seek(132,CFile::current);
		f.Write((char*)&iDesign[4][i],sizeof(int));//Last Year
	}
}

void CGPWData::SaveCommercial()
//Save Commercial data
{
int iCom[21]={1,9,17,25,33,41,49,57,65,73,81,88,89,90,91,92,93,94,95,96,97};
	for(i=0;i<21;i++)
	{
		f.Seek(97844+(3576*iCom[i]),CFile::begin);
		f.Write((char*)&iCommercial[0][i],sizeof(int));//Salary
		f.Seek(12,CFile::current);
		f.Write((char*)&iCommercial[1][i],sizeof(int));//Royalty
		f.Write((char*)&iCommercial[2][i],sizeof(int));//Ability
		f.Seek(132,CFile::current);
		f.Write((char*)&iCommercial[3][i],sizeof(int));//Last Year
	}
}

void CGPWData::SaveMechanics()
//Save Mechanics data
{
int iMec[21]={4,12,20,28,36,44,52,60,68,76,84,118,119,120,121,122,123,124,125,126,127};
	for(i=0;i<21;i++)
	{
		f.Seek(97844+(3576*iMec[i]),CFile::begin);
		f.Write((char*)&iMechanics[0][i],sizeof(int));//Salary
		f.Seek(4,CFile::current);
		f.Write((char*)&iMechanics[1][i],sizeof(int));//Race Bonus
		f.Write((char*)&iMechanics[2][i],sizeof(int));//WC Bonus
		f.Seek(4,CFile::current);
		f.Write((char*)&iMechanics[3][i],sizeof(int));//Ability
		f.Seek(132,CFile::current);
		f.Write((char*)&iMechanics[4][i],sizeof(int));//Last Year
	}
}

void CGPWData::SaveTeam()
//Save Team data
{
	for(i=0;i<11;i++)
	{
		f.Seek(10712+(7824*i),CFile::begin);
		f.Write((char*)&iTeam[0][i],sizeof(int));//Budget
		f.Seek(2761216+(224*i),CFile::begin);
		f.Write((char*)&iTeam[1][i],sizeof(int));//Test Price
//		f.Seek(8276+(7824*i),CFile::begin);
//		f.Read((char*)&iTeam[2][i],sizeof(int));//Team Points
	}
}

void CGPWData::SaveRoot()
{
int tmp=iHead[0]-1;
	f.Seek(9236+(7824*tmp),CFile::begin);
	//0=Commercial
	//1=Design
	//2=Engineering
	//3=Mechanics
	for(i=0;i<4;i++)
	{
		f.Write((char*)&iRoot[0][i],sizeof(int)); //Trainee
		f.Write((char*)&iRoot[1][i],sizeof(int)); //Average
		f.Write((char*)&iRoot[2][i],sizeof(int)); //Good
		f.Write((char*)&iRoot[3][i],sizeof(int)); //Very Good
		f.Write((char*)&iRoot[4][i],sizeof(int)); //Excellent
		if(i==0)
		{
			f.Seek(9160+(7824*tmp),CFile::begin);
			f.Write((char*)&iRoot[5][i],sizeof(int)); //Morale
			f.Seek(9620+(7824*tmp),CFile::begin);
		}
		else if(i==1)
		{
			f.Seek(9544+(7824*tmp),CFile::begin);
			f.Write((char*)&iRoot[5][i],sizeof(int)); //Morale
			f.Seek(10004+(7824*tmp),CFile::begin);
		}
		else if (i==2)
		{
			f.Seek(9928+(7824*tmp),CFile::begin);
			f.Write((char*)&iRoot[5][i],sizeof(int)); //Morale
			f.Seek(10416+(7824*tmp),CFile::begin);
		}
		else if(i==3)
		{
			f.Seek(10312+(7824*tmp),CFile::begin);
			f.Write((char*)&iRoot[5][i],sizeof(int)); //Morale
		}
	}
}

void CGPWData::SaveData(CString file)
//Export data to gsf
{
CFile f;
	f.Open(file,CFile::modeCreate|CFile::modeWrite,NULL);
	//Driver
	for(i=0;i<44;i++)
	{
		f.Write((char*)&iDriver[0][i],sizeof(int));//Salary
		f.Write((char*)&iDriver[1][i],sizeof(int));//Race Bonus
		f.Write((char*)&iDriver[2][i],sizeof(int));//WC Bonus
		f.Write((char*)&iDriver[3][i],sizeof(int));//Points
		f.Write((char*)&iDriver[4][i],sizeof(int));//Speed
		f.Write((char*)&iDriver[5][i],sizeof(int));//Overtaking
		f.Write((char*)&iDriver[6][i],sizeof(int));//Wet Wether
		f.Write((char*)&iDriver[7][i],sizeof(int));//Concentration
		f.Write((char*)&iDriver[8][i],sizeof(int));//Experience
		f.Write((char*)&iDriver[9][i],sizeof(int));//Stamina
		f.Write((char*)&iDriver[10][i],sizeof(int));//Morale
		f.Write((char*)&iDriver[11][i],sizeof(int));//Skill
	}
	
	for(i=0;i<21;i++)
	{
		//Engineering
		f.Write((char*)&iEngineering[0][i],sizeof(int));//Salary
		f.Write((char*)&iEngineering[1][i],sizeof(int));//Race Bonus
		f.Write((char*)&iEngineering[2][i],sizeof(int));//WC Bonus
		f.Write((char*)&iEngineering[3][i],sizeof(int));//Ability
		f.Write((char*)&iEngineering[4][i],sizeof(int));//Last Year
		//Design
		f.Write((char*)&iDesign[0][i],sizeof(int));//Salary
		f.Write((char*)&iDesign[1][i],sizeof(int));//Race Bonus
		f.Write((char*)&iDesign[2][i],sizeof(int));//WC Bonus
		f.Write((char*)&iDesign[3][i],sizeof(int));//Ability
		f.Write((char*)&iDesign[4][i],sizeof(int));//Last Year
		//Commercial
		f.Write((char*)&iCommercial[0][i],sizeof(int));//Salary
		f.Write((char*)&iCommercial[1][i],sizeof(int));//Royalty
		f.Write((char*)&iCommercial[2][i],sizeof(int));//Ability
		f.Write((char*)&iCommercial[3][i],sizeof(int));//Last Year
		//Mechanics
		f.Write((char*)&iMechanics[0][i],sizeof(int));//Salary
		f.Write((char*)&iMechanics[1][i],sizeof(int));//Race Bonus
		f.Write((char*)&iMechanics[2][i],sizeof(int));//WC Bonus
		f.Write((char*)&iMechanics[3][i],sizeof(int));//Ability
		f.Write((char*)&iMechanics[4][i],sizeof(int));//Last Year
		//Team
		f.Write((char*)&iTeam[0][i],sizeof(int));//Budget
		f.Write((char*)&iTeam[1][i],sizeof(int));//Test Price
		f.Write((char*)&iTeam[2][i],sizeof(int));//Team Points
	}
	//Root
	for(i=0;i<4;i++)
	{
		f.Write((char*)&iRoot[0][i],sizeof(int)); //Trainee
		f.Write((char*)&iRoot[1][i],sizeof(int)); //Average
		f.Write((char*)&iRoot[2][i],sizeof(int)); //Good
		f.Write((char*)&iRoot[3][i],sizeof(int)); //Very Good
		f.Write((char*)&iRoot[4][i],sizeof(int)); //Excellent
		f.Write((char*)&iRoot[5][i],sizeof(int)); //Morale
	}
	f.Close();
}

void CGPWData::LoadData(CString file)
//Import data from gsf
{
CFile f;
	f.Open(file,CFile::modeRead,NULL);
	//Driver
	for(i=0;i<44;i++)
	{
		f.Read((char*)&iDriver[0][i],sizeof(int));//Salary
		f.Read((char*)&iDriver[1][i],sizeof(int));//Race Bonus
		f.Read((char*)&iDriver[2][i],sizeof(int));//WC Bonus
		f.Read((char*)&iDriver[3][i],sizeof(int));//Points
		f.Read((char*)&iDriver[4][i],sizeof(int));//Speed
		f.Read((char*)&iDriver[5][i],sizeof(int));//Overtaking
		f.Read((char*)&iDriver[6][i],sizeof(int));//Wet Wether
		f.Read((char*)&iDriver[7][i],sizeof(int));//Concentration
		f.Read((char*)&iDriver[8][i],sizeof(int));//Experience
		f.Read((char*)&iDriver[9][i],sizeof(int));//Stamina
		f.Read((char*)&iDriver[10][i],sizeof(int));//Morale
		f.Read((char*)&iDriver[11][i],sizeof(int));//Skill
	}
	
	for(i=0;i<21;i++)
	{
		//Engineering
		f.Read((char*)&iEngineering[0][i],sizeof(int));//Salary
		f.Read((char*)&iEngineering[1][i],sizeof(int));//Race Bonus
		f.Read((char*)&iEngineering[2][i],sizeof(int));//WC Bonus
		f.Read((char*)&iEngineering[3][i],sizeof(int));//Ability
		f.Read((char*)&iEngineering[4][i],sizeof(int));//Last Year
		//Design
		f.Read((char*)&iDesign[0][i],sizeof(int));//Salary
		f.Read((char*)&iDesign[1][i],sizeof(int));//Race Bonus
		f.Read((char*)&iDesign[2][i],sizeof(int));//WC Bonus
		f.Read((char*)&iDesign[3][i],sizeof(int));//Ability
		f.Read((char*)&iDesign[4][i],sizeof(int));//Last Year
		//Commercial
		f.Read((char*)&iCommercial[0][i],sizeof(int));//Salary
		f.Read((char*)&iCommercial[1][i],sizeof(int));//Royalty
		f.Read((char*)&iCommercial[2][i],sizeof(int));//Ability
		f.Read((char*)&iCommercial[3][i],sizeof(int));//Last Year
		//Mechanics
		f.Read((char*)&iMechanics[0][i],sizeof(int));//Salary
		f.Read((char*)&iMechanics[1][i],sizeof(int));//Race Bonus
		f.Read((char*)&iMechanics[2][i],sizeof(int));//WC Bonus
		f.Read((char*)&iMechanics[3][i],sizeof(int));//Ability
		f.Read((char*)&iMechanics[4][i],sizeof(int));//Last Year
		//Team
		f.Read((char*)&iTeam[0][i],sizeof(int));//Budget
		f.Read((char*)&iTeam[1][i],sizeof(int));//Test Price
		f.Read((char*)&iTeam[2][i],sizeof(int));//Team Points
	}
	//Root
	for(i=0;i<4;i++)
	{
		f.Read((char*)&iRoot[0][i],sizeof(int)); //Trainee
		f.Read((char*)&iRoot[1][i],sizeof(int)); //Average
		f.Read((char*)&iRoot[2][i],sizeof(int)); //Good
		f.Read((char*)&iRoot[3][i],sizeof(int)); //Very Good
		f.Read((char*)&iRoot[4][i],sizeof(int)); //Excellent
		f.Read((char*)&iRoot[5][i],sizeof(int)); //Morale
	}
	f.Close();
}

void CGPWData::LoadHead()
{
	f.Seek(144,CFile::begin);
	f.Read((char*)&iHead[0],sizeof(int));//Team
	f.Seek(100,CFile::current);
	f.Read((char*)&iHead[1],sizeof(int));//Score
	f.Read((char*)&iHead[2],sizeof(int));//Years
	f.Read((char*)&iHead[3],sizeof(int));//Year
	f.Read((char*)&iHead[4],sizeof(int));//Pos
	f.Read((char*)&iHead[5],sizeof(int));//Point
	f.Read((char*)&iHead[6],sizeof(int));//Next Race

	f.Seek(113,CFile::begin);
	f.Read((char*)&cPlayer,23);
	f.Seek(198,CFile::begin);
	f.Read((char*)&cCreated,sizeof(cCreated));
	f.Seek(148,CFile::begin);
	f.Read((char*)&cModified,sizeof(cModified));
}

CString CGPWData::ConvertTeam(int index)
{
CString team[11]={"Williams","Ferrari","Benetton","McLaren","Jordan","Prost","Sauber","Arrows","Stewart","Tyrrell","Minardi"};
	if(index<=11)
		return(team[index-1]);
	else
		return("");
}

CString CGPWData::ConvertCountry(int index)
{
CString country[16]={"Australian","Brazilian","Argentine","San Marino","Spanish","Monaco","Canadian","Franch","British","Austrian","German","Hungarian","Belgian","Italian","Luxembourg","Japanese"};
	if(index<=16)
		return(country[index-1]);
	else
		return("");
}
