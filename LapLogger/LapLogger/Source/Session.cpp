#include "../include/Session.hpp"

CSession::CSession(void)
{
	_currentLap=0;
	_initialized=false;
}

CSession::~CSession(void)
{
	Reset();
}

void CSession::Reset()
{
	_playerName.clear();
	_trackName.clear();
	_vehicleName.clear();
	_vehicleClass.clear();
	_vehicleClass.clear();
	_currentLap=0;
	_laps.clear();
	_initialized=false;
}

void CSession::AddLap(CLap lap)
{
	if(GetCurrentLap()!=lap.GetLap())
	{
		_currentLap=lap.GetLap();
		_laps.push_back(lap);
	}
}

void CSession::Initialize(const char *playerName, const char *trackName, const char *vehicleName, const char *vehicleClass, long numberOfVehicles, float lapDistance)
{
	_playerName.append(playerName);
	_trackName.append(trackName);
	_vehicleName.append(vehicleName);
	_vehicleClass.append(vehicleClass);
	_numberOfVehicles= numberOfVehicles;
	_lapDistance=lapDistance;
	_initialized=true;
}

std::string CSession::Dump()
{
	CLap lap;
	std::list<CLap>::const_iterator it;
	std::ostringstream os;

	os << "LapLogger1" << std::endl;
	os << GetPlayerName() << ":" << GetTrackName() << ":" << GetVehicleName() << ":" << GetVehicleClass() << ":" << GetNumberOfVehicles() << ":" << GetLapDistance() << std::endl;

	for(it=_laps.begin();it!=_laps.end();++it)
	{
		lap=(CLap)*it;
		os << lap.GetAmbientTemp() << ":" << lap.GetTrackTemp() << ":" << lap.GetRaining() << ":" << lap.GetOffPathWetness() << ":" << lap.GetOnPathWetness() << ":" << lap.GetWindX() << ":" << lap.GetWindY() << ":" << lap.GetWindZ() << ":" << lap.GetLap() << ":" << lap.GetSector1() << ":" << lap.GetSector2() << ":" << lap.GetLapTime() << std::endl;
	}
	return os.str();
}
