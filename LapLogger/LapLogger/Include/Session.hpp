#pragma once

#include <windows.h>
#include <list>
#include <string>
#include <sstream>
#include "Lap.hpp"

class CSession
{
private:
	bool _initialized;
	short _currentLap;
	long _numberOfVehicles;
	float _lapDistance;

	std::list<CLap> _laps;
	std::string _trackName;
	std::string _playerName;
	std::string _vehicleClass;
	std::string _vehicleName;

public:
	void Initialize(const char *playerName, const char *trackName, const char *vehicleName, const char *vehicleClass, long numberOfVehicles, float lapDistance);

	bool IsInitialized(){return _initialized;};

	std::string GetTrackName(){return _trackName;};
	std::string GetPlayerName(){return _playerName;};
	std::string GetVehicleName(){return _vehicleName;};
	std::string GetVehicleClass(){return _vehicleClass;};

	short GetCurrentLap(){return _currentLap;};
	long GetNumberOfVehicles(){return _numberOfVehicles;};
	float GetLapDistance(){return _lapDistance;};

	void Reset();

	void AddLap(CLap lap);
	std::list<CLap> GetLaps(){return _laps;};

	std::string Dump();

	CSession(void);
	~CSession(void);
};
