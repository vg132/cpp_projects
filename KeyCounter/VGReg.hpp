#pragma once

class VGReg
{
private:

public:
	bool WriteValue(HKEY root, char* path, char* value,DWORD type, char* data, DWORD size);
	bool ReadValue(HKEY root, char* path, char* value, char* data, DWORD size);
	VGReg(void);
	~VGReg(void);
};
