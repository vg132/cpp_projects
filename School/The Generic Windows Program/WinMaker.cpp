#include "WinMaker.h"

WinMaker::WinMaker(WinClass & winClass)
: _hWnd(0), _class(winClass),_exStyle(0),_windowName(0),_style(WS_OVERLAPPED),
_x(CW_USEDEFAULT), _y(0), _width(CW_USEDEFAULT), _height(0),_hWndParent(0),_hMenu(0),_data(0)
{
}

void WinMaker::Create()
{
	_hWnd=::CreateWindowEx(_exStyle,
													_class.GetName(),
													_windowName,
													_style,
													_x,
													_y,
													_width,
													_height,
													_hWndParent,
													_hMenu,
													_class.GetInstance(),
													_data);
	if(_hWnd==0)
		throw WinException("Internal error: Window Creation Faild.");
}

void WinMaker::Show(int nCmdShow)
{
	::ShowWindow(_hWnd,nCmdShow);
	::UpdateWindow(_hWnd);
}