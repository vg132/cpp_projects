#include "WinMaker.h"

void WinMaker::Show(int cmdShow)
{
	::ShowWindow(_hWnd,cmdShow);
	::UpdateWindow(_hWnd);
}

WinMaker::WinMaker(char const* caption, char const* className, HINSTANCE hInstance)
{
	_hWnd=::CreateWindow(
					className,						// Name of a registared window class
					caption,							// window caption
					WS_OVERLAPPEDWINDOW,	// Window style
					CW_USEDEFAULT,				// x position
					CW_USEDEFAULT,				// y position
					CW_USEDEFAULT,				// witdh
					CW_USEDEFAULT,				// height
					0,										// handle to parent window
					0,										// handle to menu
					hInstance,						// application instance
					0);										// window creation data
}