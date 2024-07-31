#include "../include/LapLog.hpp"

// plugin information
unsigned g_uPluginID          = 0;
char     g_szPluginName[]     = "Lap Log Plugin - 2007-10-03";
unsigned g_uPluginVersion     = 001;
unsigned g_uPluginObjectCount = 1;
InternalsPluginInfo g_PluginInfo;

// interface to plugin information
extern "C" __declspec(dllexport)
const char* __cdecl GetPluginName() { return g_szPluginName; }

extern "C" __declspec(dllexport)
unsigned __cdecl GetPluginVersion() { return g_uPluginVersion; }

extern "C" __declspec(dllexport)
unsigned __cdecl GetPluginObjectCount() { return g_uPluginObjectCount; }

// get the plugin-info object used to create the plugin.
extern "C" __declspec(dllexport)
PluginObjectInfo* __cdecl GetPluginObjectInfo( const unsigned uIndex )
{
  switch(uIndex)
  {
    case 0:
      return  &g_PluginInfo;
    default:
      return 0;
  }
}


// InternalsPluginInfo class

InternalsPluginInfo::InternalsPluginInfo()
{
  // put together a name for this plugin
  sprintf_s(m_szFullName,128,"%s - %s", g_szPluginName, InternalsPluginInfo::GetName() );
}

const char*    InternalsPluginInfo::GetName()     const { return LapLog::GetName(); }
const char*    InternalsPluginInfo::GetFullName() const { return m_szFullName; }
const char*    InternalsPluginInfo::GetDesc()     const { return "Lap Log Plugin"; }
const unsigned InternalsPluginInfo::GetType()     const { return LapLog::GetType(); }
const char*    InternalsPluginInfo::GetSubType()  const { return LapLog::GetSubType(); }
const unsigned InternalsPluginInfo::GetVersion()  const { return LapLog::GetVersion(); }
void*          InternalsPluginInfo::Create()      const { return new LapLog(); }

// InternalsPlugin class

const char LapLog::m_szName[] = "InternalsPlugin";
const char LapLog::m_szSubType[] = "Internals";
const unsigned LapLog::m_uID = 1;
const unsigned LapLog::m_uVersion = 3;  // set to 3 for InternalsPluginV3 functionality and added graphical and vehicle info

PluginObjectInfo *LapLog::GetInfo()
{
  return &g_PluginInfo;
}

void LapLog::Startup()
{
}

void LapLog::Shutdown()
{
}

void LapLog::StartSession()
{
}


void LapLog::EndSession()
{
	std::string tmp=_session.Dump();
	_session.Reset();

	HANDLE hThread;
	hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CNet::SendData,&tmp,0,NULL);
	WaitForSingleObject(hThread,INFINITE);
}

void LapLog::UpdateScoring( const ScoringInfoV2 &info )
{
	for( long i = 0; i < info.mNumVehicles; ++i )
	{
		VehicleScoringInfoV2 &vinfo = info.mVehicle[i];
		if(vinfo.mIsPlayer)
		{
			if(!_session.IsInitialized())
			{
				_session.Initialize(info.mPlayerName, info.mTrackName,vinfo.mVehicleName, vinfo.mVehicleClass, info.mNumVehicles, info.mLapDist);
			}
			if(vinfo.mTotalLaps>_session.GetCurrentLap())
			{
				CLap lap;//=new CLap();
				lap.SetLap(vinfo.mTotalLaps);
				lap.SetSector1(vinfo.mLastSector1);
				lap.SetSector2(vinfo.mLastSector2);
				lap.SetLapTime(vinfo.mLastLapTime);
				lap.SetTrackTemp(info.mTrackTemp);
				lap.SetAmbientTemp(info.mAmbientTemp);
				lap.SetOnPathWetness(info.mOnPathWetness);
				lap.SetOffPathWetness(info.mOffPathWetness);
				lap.SetWindX(info.mWind.x);
				lap.SetWindY(info.mWind.y);
				lap.SetWindZ(info.mWind.z);
				lap.SetRaining(info.mRaining);
				_session.AddLap(lap);
			}
		}
	}
}