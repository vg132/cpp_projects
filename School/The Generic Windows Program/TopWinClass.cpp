#include "TopWinClass.h"

TopWinClass::TopWinClass(int resId, HINSTANCE hInst, WNDPROC wndProc)
: WinClass(resId,hInst,wndProc)
{
	SetResIcons(resId);
	_class.lpszMenuName=MAKEINTRESOURCE(resId);
}