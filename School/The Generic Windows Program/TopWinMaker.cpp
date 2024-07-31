#include "TopWinMaker.h"

// Makes top overlapped window with caption

TopWinMaker::TopWinMaker(WinClass & winClass, char const* caption)
: WinMaker(winClass)
{
	_style=WS_OVERLAPPEDWINDOW|WS_VISIBLE;
	_windowName = caption;
}