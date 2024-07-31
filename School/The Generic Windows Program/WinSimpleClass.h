#ifndef __WIN_SIMPLE_CLASS__H__
#define __WIN_SIMPLE_CLASS__H__

#include <windows.h>

class WinSimpleClass
{
public:
	WinSimpleClass(char const* name, HINSTANCE hInst): _name(name), _hInstance(hInst){}
	WinSimpleClass(int resId, HINSTANCE hInst);
	char const* GetName() const{return(_name.c_str();}
	HINSTANCE GetInstance() const {return(_hInstance;}
	HWND GetRunningWindow();
protected:
	HINSTANCE _hInstance;
	std::string _name;
};

#endif