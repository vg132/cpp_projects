#include "WinSimpleClass.h"

WinSimpleClass::WinSimpleClass(int resId, HINSTANCE hInst): _hInstance(hInst)
{
	ResString resStr(hInst,resId);
	_name=resStr;
}

HWND WinSimpleClass::GetRunningWindow()
{
	HWND hWnd=::FindWindow(GetName(),0);
	if(::IsWindow(hWnd))
	{
		HWND hWndPopup=::GetLastActivePopup(hWnd);
		if(::IsWindow(hWndPopup))
			hWnd=hWndPopup;
	}
	else
		hWnd=0;
	return(hWnd);
}