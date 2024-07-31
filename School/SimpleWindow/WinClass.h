#ifndef __WINCLASS__H__
#define __WINCLASS__H__

#include <windows.h>

LRESULT CALLBACK WindowsProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class WinClass
{
private:
	WNDCLASS _class;
public:
	WinClass(WNDPROC winProc, char const * className, HINSTANCE hInst);
	void Register();
};

#endif