#include "stdafx.h"

class SysTray
{
public:
	SysTray();
	BOOL SetIcon(HICON hNewIcon);
	HICON GetIcon();
	BOOL SetTipText(char *lpstrNewTipText);
	char *GetTipText();
	BOOL AddIcon();
	BOOL RemoveIcon();
	HWND hWnd;
	UINT uID;
protected:
	NOTIFYICONDATA NotifyIconData;
	bool bInTray;
};

SysTray::SysTray()
{
	bInTray = false;
	NotifyIconData.cbSize = sizeof(NotifyIconData);
	NotifyIconData.uID = uID = 2;
	NotifyIconData.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	NotifyIconData.uCallbackMessage = WM_TRAYNOTIFY;
	NotifyIconData.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	NotifyIconData.szTip[0] = '\0';
	NotifyIconData.hWnd = NULL;
}

HICON SysTray::GetIcon()
{
	return(NotifyIconData.hIcon);
}

BOOL SysTray::SetIcon(HICON hNewIcon)
{
	NotifyIconData.hIcon = hNewIcon;
	if(bInTray)
	{
		BOOL iRetVal;
		iRetVal = Shell_NotifyIcon(NIM_MODIFY, &NotifyIconData);
		if(iRetVal)
			bInTray = true;
		return(iRetVal);
	}
	else
	{
		return(1);
	}
}

char *SysTray::GetTipText()
{
	return(NotifyIconData.szTip);
}

BOOL SysTray::SetTipText(char *lpstrNewTipText)
{
	strcpy(NotifyIconData.szTip, lpstrNewTipText);
	if(bInTray)
	{
		BOOL iRetVal;
		iRetVal = Shell_NotifyIcon(NIM_MODIFY, &NotifyIconData);
		if(iRetVal)
			bInTray = true;
		return(iRetVal);
	}
	else
	{
		return(1);
	}
}

BOOL SysTray::AddIcon()
{
	BOOL iRetVal;
	NotifyIconData.hWnd = hWnd;
	NotifyIconData.uID = (UINT)hWnd;
	iRetVal = Shell_NotifyIcon(NIM_ADD, &NotifyIconData);
	if(iRetVal)
		bInTray = true;
	return(iRetVal);
}

BOOL SysTray::RemoveIcon()
{
	BOOL iRetVal;
	iRetVal = Shell_NotifyIcon(NIM_DELETE, &NotifyIconData);
	if(iRetVal)
		bInTray = false;
	return(iRetVal);
}
