// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

#include "../LapLogger/include/LapLog.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	//CNet::SendData();

	//std::wstring tmp=_T("Viktor");
	/*
	std::wstring tmp=_T("ABCDEFGHIJKLMNOPQRSTUVWXYZÅÄÖabcdefghijklmnopqrstuvwxyzåäö0123456789");

	HANDLE hThread;
	hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CNet::SendData,&tmp,0,NULL);
	WaitForSingleObject(hThread,INFINITE);
	*/

	LapLog *l=new LapLog();
	l->Startup();
	l->StartSession();

	ScoringInfoV2 info;

	info.mPlayerName[0]='V';
	info.mPlayerName[1]='i';
	info.mPlayerName[2]='k';
	info.mPlayerName[3]='t';
	info.mPlayerName[4]='o';
	info.mPlayerName[5]='r';
	info.mPlayerName[6]='\0';

	info.mTrackName[0]='M';
	info.mTrackName[1]='o';
	info.mTrackName[2]='n';
	info.mTrackName[3]='z';
	info.mTrackName[4]='a';
	info.mTrackName[5]='\0';

	VehicleScoringInfoV2 info2;

	info2.mVehicleClass[0]='F';
	info2.mVehicleClass[1]='1';
	info2.mVehicleClass[2]='\0';

	info2.mVehicleName[0]='W';
	info2.mVehicleName[1]='i';
	info2.mVehicleName[2]='l';
	info2.mVehicleName[3]='l';
	info2.mVehicleName[4]='i';
	info2.mVehicleName[5]='a';
	info2.mVehicleName[6]='m';
	info2.mVehicleName[7]='s';
	info2.mVehicleName[8]='\0';

	info.mNumVehicles=1;

	info2.mLastSector1=-1.0f;
	info2.mLastSector2=-1.0f;
	info2.mLastLapTime=-1.0f;

	info.mOnPathWetness=0.0f;
	info.mOffPathWetness=0.0f;
	info.mTrackTemp=14.4f;
	info.mAmbientTemp=13.1f;
	
	TelemVect3 wind;
	wind.Set(0.0f,0.0f,0.0f);
	info.mWind=wind;

	info2.mTotalLaps=0;
	info.mVehicle=&info2;
	l->UpdateScoring(info);

	info2.mLastSector1=5.0f;
	info2.mLastSector2=10.0f;
	info2.mLastLapTime=20.0f;

	info2.mTotalLaps=1;
	l->UpdateScoring(info);

	info2.mLastSector1=15.0f;
	info2.mLastSector2=25.0f;
	info2.mLastLapTime=35.0f;

	info2.mTotalLaps=2;
	l->UpdateScoring(info);

	l->EndSession();



	l->StartSession();

	info2.mLastSector1=-1.0f;
	info2.mLastSector2=-1.0f;
	info2.mLastLapTime=-1.0f;
	
	info2.mTotalLaps=0;
	info.mVehicle=&info2;
	l->UpdateScoring(info);

	info2.mLastSector1=7.0f;
	info2.mLastSector2=14.0f;
	info2.mLastLapTime=21.0f;

	info2.mTotalLaps=1;
	l->UpdateScoring(info);

	info2.mLastSector1=8.0f;
	info2.mLastSector2=16.0f;
	info2.mLastLapTime=24.0f;

	info2.mTotalLaps=2;
	l->UpdateScoring(info);

	l->EndSession();


	l->StartSession();


	info2.mLastSector1=-1.0f;
	info2.mLastSector2=-1.0f;
	info2.mLastLapTime=-1.0f;


	info2.mTotalLaps=0;
	info.mVehicle=&info2;
	l->UpdateScoring(info);

	info2.mLastSector1=9.0f;
	info2.mLastSector2=18.0f;
	info2.mLastLapTime=27.0f;

	info2.mTotalLaps=1;
	l->UpdateScoring(info);

	info2.mLastSector1=10.0f;
	info2.mLastSector2=20.0f;
	info2.mLastLapTime=30.0f;

	info2.mTotalLaps=2;
	l->UpdateScoring(info);

	l->EndSession();


	l->Shutdown();

	return 0;
}

