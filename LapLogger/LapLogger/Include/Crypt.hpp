#pragma once

#include <windows.h>
#include <string>
#include <sstream>

class Crypt
{
public:
	Crypt(){};
	~Crypt(){};
	BYTE* Encrypt(BYTE* pbJamData, int nNumBytes);
};
