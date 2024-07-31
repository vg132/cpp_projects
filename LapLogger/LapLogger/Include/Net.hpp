#pragma once

#include <windows.h>
#include <string>
#include <sstream>
#include <tchar.h>
#include "winhttp.h"
#include "Crypt.hpp"

class CNet
{
private:
	static void PadRight(std::string *str);
public:
	static void __cdecl SendData(LPVOID iValue);

	CNet();
	~CNet();
};