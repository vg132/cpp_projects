#include "WinClass.h"

WinClass::WinClass(WNDPROC winProc, const char *className, HINSTANCE hInst)
{
	_class.style=0;
	_class.lpfnWndProc=winProc;	//Window procedure: mandatory
	_class.cbClsExtra=0;
	_class.cbWndExtra=0;
	_class.hInstance=hInst;			//owner of the class: mandatory
	_class.hIcon=0;
	_class.hCursor=::LoadCursor(0,IDC_ARROW);
	_class.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	_class.lpszMenuName=0;
	_class.lpszClassName=className;	//mandatory
}

void WinClass::Register()
{
	::RegisterClass(&_class);
}