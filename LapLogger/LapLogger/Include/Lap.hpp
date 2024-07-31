#pragma once

class CLap
{
private:
	short _lap;
	float _sector1, _sector2, _lapTime;
	float _ambientTemp, _trackTemp;
	float _raining, _onPathWetness, _offPathWetness;
	float _windX, _windY, _windZ;

public:
	void SetLap(short lap){_lap=lap;};

	short GetLap(){return _lap;};

	void SetSector1(float time){_sector1=time;};
	void SetSector2(float time){_sector2=time;};
	void SetLapTime(float time){_lapTime=time;};

	void SetRaining(float raining){_raining=raining;};
	void SetOnPathWetness(float onPathWetness){_onPathWetness=onPathWetness;};
	void SetOffPathWetness(float offPathWetness){_offPathWetness=offPathWetness;};

	void SetWindX(float windX){_windX=windX;};
	void SetWindY(float windY){_windY=windY;};
	void SetWindZ(float windZ){_windZ=windZ;};

	void SetAmbientTemp(float ambientTemp){_ambientTemp=ambientTemp;};
	void SetTrackTemp(float trackTemp){_trackTemp=trackTemp;};

	float GetSector1(){return _sector1;};
	float GetSector2(){return _sector2;};
	float GetLapTime(){return _lapTime;};

	float GetRaining(){return _raining;};
	float GetOnPathWetness(){return _onPathWetness;};
	float GetOffPathWetness(){return _offPathWetness;};

	float GetWindX(){return _windX;};
	float GetWindY(){return _windY;};
	float GetWindZ(){return _windZ;};

	float GetAmbientTemp(){return _ambientTemp;};
	float GetTrackTemp(){return _trackTemp;};

	CLap(void);
	~CLap(void);
};
