#ifndef __WINMAKER__H__
#define __WINMAKER__H__

#include <windows.h>

class WinMaker
{
public:
	WinMaker(): _hWnd(0){}
	WinMaker(char const* caption, char const* className, HINSTANCE hInstance);
	void Show(int cmdShow);
protected:
	HWND _hWnd;
};

#endif