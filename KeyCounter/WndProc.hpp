#pragma once

namespace WndProc
{
	void OnSize(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
	void OnShellNotify(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
	void OnInitDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
	void OnCommand(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
	void OnNotify(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
}