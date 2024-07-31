//**************************************
//INCLUDE files for :System Tray Class (Very Easy To Use)
//**************************************
#include <Shellapi.h>
//**************************************
// Name: System Tray Class (Very Easy To Use)
// Description:This class I developed makes it very easy to put/delete/modify icons in the system tray. You can also get mouse notifications from the system tray. Once again, NO MFC!
// By: Mike Riehl
//
//
// Inputs:None
//
// Returns:None
//
//Assumes:None
//
//Side Effects:None
//This code is copyrighted and has limited warranties.
//Please see http://www.Planet-Source-Code.com/xq/ASP/txtCodeId.538/lngWId.3/qx/vb/scripts/ShowCode.htm
//for details.
//**************************************

//Class Code (Copy And Paste it Somewhere)//
#define WM_TRAYNOTIFY 0xA44C
#include <Shellapi.h>
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
