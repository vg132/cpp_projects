#ifndef __CSETUPFILE__H__
#define __CSETUPFILE__H__

#include "GpXFileInfo.h"

struct GpXSetupFileHeader
{
	int FirstData;	//0-3
	unsigned char SecondData;	//4
	unsigned char SetupPos;	//5
	unsigned char Empty[34];	//6-31
};

struct GpXSetupFile
{
	unsigned char FrontWing; //32
	unsigned char RearWing;	//33
	unsigned char Gear1;			//34
	unsigned char Gear2;			//35
	unsigned char Gear3;			//36
	unsigned char Gear4;			//37
	unsigned char Gear5;			//38
	unsigned char Gear6;			//39

	unsigned char TyreChoice;	//40 (Only Gp3)
	unsigned char BrakeBalans;	//41
	unsigned char NrOfStops;	//42
	unsigned char EditLevel;	//43
	unsigned char FirstStop;	//44
	unsigned char SecondStop;	//45
	unsigned char ThirdStop;	//46
	unsigned char Empty2;	//47

	unsigned char LeftRearPackers;	//48
	unsigned char RightRearPackers;	//49
	unsigned char LeftFrontPackers;	//50
	unsigned char RightFrontPackers;	//51

	unsigned char LeftRearDumperFastBump;	//52
	unsigned char RightRearDumperFastBump;	//53
	unsigned char LeftFrontDumperFastBump;	//54
	unsigned char RightFrontDumperFastBump;	//55

	unsigned char LeftRearFastRebound;	//56
	unsigned char RightRearFastRebound;	//57
	unsigned char LeftFrontFastRebound;	//58
	unsigned char RightFrontFastRebound;	//59

	unsigned char LeftRearSlowBump;	//60
	unsigned char RightRearSlowBump;	//61
	unsigned char LeftFrontSlowBump;	//62
	unsigned char RightFrontSlowBump;	//63

	unsigned char LeftRearSlowRebound;	//64
	unsigned char RightRearSlowRebound;	//65
	unsigned char LeftFrontSlowRebound;	//66
	unsigned char RightFrontSlowRebound;	//67

	unsigned char LeftRearSpring;	//68
	unsigned char RightRearSpring;	//69
	unsigned char LeftFrontSpring;	//70
	unsigned char RightFrontSpring;	//71

	unsigned char LeftRearRideHeight;	//72
	unsigned char RightRearRideHeight;	//73
	unsigned char LeftFrontRideHeight;	//74
	unsigned char RightFrontRideHeight;	//75

	unsigned char RearAntiRollBar;	//76
	unsigned char Empty3;	//77
	unsigned char FrontAntiRollBar;	//78
	unsigned char Empty4;	//79

	unsigned char Differential;	//80 (Only Gp3)

	unsigned char Empty5;	//81
	unsigned char Empty6;	//82
	unsigned char Empty7;	//83
	unsigned char Empty8;	//84
	unsigned char Empty9;	//85
	unsigned char Empty10;	//86
	unsigned char Empty11;	//87

};

class CSetupFile : public CGpXFileInfo
{
private:
	bool ReadGp3MultiSetupFile();
	bool ReadGp2MultiSetupFile();
	bool ReadGp3SetupFile();
	bool ReadGp2SetupFile();

	GpXSetupFile *m_GpXSetupFile;
	GpXSetupFileHeader *m_GpXSetupFileHeader;
	char *m_FileName;
	bool CheckSum(char* FileName=NULL);
public:
	void SaveGp3MultiFile(char* FileName=NULL);
	void SaveGp2MultiFile(char* FileName=NULL);
	void SaveGp3File(int pos=-1, int id=0, char* FileName=NULL);
	void SaveGp2File(int pos=-1, int id=0, char* FileName=NULL);
	char* GetFileName();
	int GetFileTypeId(char *FileName);
	bool IsOpen();
	bool OpenFile(char *FileName);
	CSetupFile();
	~CSetupFile();

	int GetFrontWing(int id=0);
	int GetRearWing(int id=0);
	int GetGear1(int id=0);
	int GetGear2(int id=0);
	int GetGear3(int id=0);
	int GetGear4(int id=0);
	int GetGear5(int id=0);
	int GetGear6(int id=0);
	int GetTyreChoice(int id=0);
	int GetBrakeBalans(int id=0);
	int GetNrOfStops(int id=0);
	int GetFirstStop(int id=0);
	int GetSecondStop(int id=0);
	int GetThirdStop(int id=0);
	int GetLeftRearPackers(int id=0);
	int GetRightRearPackers(int id=0);
	int GetLeftFrontPackers(int id=0);
	int GetRightFrontPackers(int id=0);
	int GetLeftRearDumperFastBump(int id=0);
	int GetRightRearDumperFastBump(int id=0);
	int GetLeftFrontDumperFastBump(int id=0);
	int GetRightFrontDumperFastBump(int id=0);
	int GetLeftRearFastRebound(int id=0);
	int GetRightRearFastRebound(int id=0);
	int GetLeftFrontFastRebound(int id=0);
	int GetRightFrontFastRebound(int id=0);
	int GetLeftRearSlowBump(int id=0);
	int GetRightRearSlowBump(int id=0);
	int GetLeftFrontSlowBump(int id=0);
	int GetRightFrontSlowBump(int id=0);
	int GetLeftRearSlowRebound(int id=0);
	int GetRightRearSlowRebound(int id=0);
	int GetLeftFrontSlowRebound(int id=0);
	int GetRightFrontSlowRebound(int id=0);
	int GetLeftRearSpring(int id=0);
	int GetRightRearSpring(int id=0);
	int GetLeftFrontSpring(int id=0);
	int GetRightFrontSpring(int id=0);
	int GetLeftRearRideHeight(int id=0);
	int GetRightRearRideHeight(int id=0);
	int GetLeftFrontRideHeight(int id=0);
	int GetRightFrontRideHeight(int id=0);
	int GetRearAntiRollBar(int id=0);
	int GetFrontAntiRollBar(int id=0);
	int GetDifferential(int id=0);

	void SetFrontWing(int value, int id=0);
	void SetRearWing(int value, int id=0);
	void SetGear1(int value, int id=0);
	void SetGear2(int value, int id=0);
	void SetGear3(int value, int id=0);
	void SetGear4(int value, int id=0);
	void SetGear5(int value, int id=0);
	void SetGear6(int value, int id=0);
	void SetTyreChoice(int value, int id=0);
	void SetBrakeBalans(int value, int id=0);
	void SetNrOfStops(int value, int id=0);
	void SetFirstStop(int value, int id=0);
	void SetSecondStop(int value, int id=0);
	void SetThirdStop(int value, int id=0);
	void SetLeftRearPackers(int value, int id=0);
	void SetRightRearPackers(int value, int id=0);
	void SetLeftFrontPackers(int value, int id=0);
	void SetRightFrontPackers(int value, int id=0);
	void SetLeftRearDumperFastBump(int value, int id=0);
	void SetRightRearDumperFastBump(int value, int id=0);
	void SetLeftFrontDumperFastBump(int value, int id=0);
	void SetRightFrontDumperFastBump(int value, int id=0);
	void SetLeftRearFastRebound(int value, int id=0);
	void SetRightRearFastRebound(int value, int id=0);
	void SetLeftFrontFastRebound(int value, int id=0);
	void SetRightFrontFastRebound(int value, int id=0);
	void SetLeftRearSlowBump(int value, int id=0);
	void SetRightRearSlowBump(int value, int id=0);
	void SetLeftFrontSlowBump(int value, int id=0);
	void SetRightFrontSlowBump(int value, int id=0);
	void SetLeftRearSlowRebound(int value, int id=0);
	void SetRightRearSlowRebound(int value, int id=0);
	void SetLeftFrontSlowRebound(int value, int id=0);
	void SetRightFrontSlowRebound(int value, int id=0);
	void SetLeftRearSpring(int value, int id=0);
	void SetRightRearSpring(int value, int id=0);
	void SetLeftFrontSpring(int value, int id=0);
	void SetRightFrontSpring(int value, int id=0);
	void SetLeftRearRideHeight(int value, int id=0);
	void SetRightRearRideHeight(int value, int id=0);
	void SetLeftFrontRideHeight(int value, int id=0);
	void SetRightFrontRideHeight(int value, int id=0);
	void SetRearAntiRollBar(int value, int id=0);
	void SetFrontAntiRollBar(int value, int id=0);
	void SetDifferential(int value, int id=0);
};

#endif
