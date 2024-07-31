// GPWData.h: interface for the CGPWData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GPWDATA_H__9FBE5152_697F_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_GPWDATA_H__9FBE5152_697F_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGPWData  
{
public:
	void Test();
	CString ConvertCountry(int index);
	CString ConvertTeam(int index);
	void LoadData(CString file);
	void SaveData(CString file);
	void SaveTeam();
	int iDriver[12][44];
	int iCommercial[4][21];
	int iDesign[5][21];
	int iEngineering[5][21];
	int iMechanics[5][21];

	int iRoot[6][4];

	int iHead[7];
	char cPlayer[18];
	char cCreated[24];
	char cModified[24];

	int iTeam[3][11];
	CString m_File;

	bool SaveFile();
	bool LoadFile();

	CGPWData();
	virtual ~CGPWData();

private:
	void SaveRoot();
	void LoadRoot();
	void LoadHead();
	void LoadTeam();
	void SaveMechanics();
	void SaveCommercial();
	void SaveDesign();
	void SaveEngineering();
	void SaveDrivers();
	void LoadEngineering();
	void LoadDesign();
	void LoadCommercial();
	void LoadMechanics();
	void LoadDrivers();
	CFile f;
	int i;
};

#endif // !defined(AFX_GPWDATA_H__9FBE5152_697F_11D4_8FC7_0008C7636E27__INCLUDED_)
