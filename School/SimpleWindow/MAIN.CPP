#include "WinClass.h"
#include "WinMaker.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, char* cmdParam, int cmdShow);
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, char* cmdParam, int cmdShow)
{
	char className[]="Winnie";
	WinClass winClass(WindowProcedure,className,hInst);
	winClass.Register();

	WinMaker win("Hello Windows!",className,hInst);
	win.Show(cmdShow);
	MSG msg;
	int status;

	while((status=::GetMessage(&msg,0,0,0))!=0)
	{
		if(status==-1)
			return(-1);
		::DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_DESTROY:
		{
			::PostQuitMessage(0);
			return(0);
			break;
		}
	}
	return(::DefWindowProc(hWnd,message,wParam,lParam));
}