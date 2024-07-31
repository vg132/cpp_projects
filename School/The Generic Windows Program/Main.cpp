#include "WinClass.h"
#include "WinMaker.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, char* cmdParam, int cmdShow);
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, char* cmdParam, int cmdShow)
{
	_set_new_handler(&NewHandler);

	// Using exceptions here helps debugging your program
	// and protects from unexpected incidents.
	try
	{
		TopWinClass topWinClass(ID_MAIN,hInst,MainWndProc);
		HWND hWndOther=topWinClass.GetRunningWindow();
		if(hWndOther!=0)
		{
			::SetForegroundWindow(hWndOther);
			if(::IsIconic(hWndOther))
				::ShowWindow(hWndOther,SW_RESTORE);
			return(0);
		}
		topWinClass.Register();

		// Create top window

		ResString caption(hInst, ID_CAPTION);
		TopWinMaker topWin(topWinClass,caption);
		topWin.Create();
		topWin.Show(cmdShow);
		// The main message loop
		MSG msg;
		int status;
		while((status=::GetMessage(&msg,0,0,0))!=0)
		{
			if(status==-1)
				return(-1);
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		return(msg.wParam);
	}
	catch(WinException e)
	{
		char buf[50];
		wsprintf(buf,"%s, Error %d", e.GetMessage(), e.GetError());
		::MessageBox(0, buf,"Exception", MB_ICONEXCLAMATION|MB_OK);
	}
