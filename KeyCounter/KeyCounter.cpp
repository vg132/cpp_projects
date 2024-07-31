
#include "stdafx.h"
#include "KeyCounter.h"
#include "Counter.hpp"
#include "vgreg.hpp"
#include <windowsx.h>
#include <windows.h>
#include <hash_set>
#include <Psapi.h>
#include <commctrl.h>
#include <Commdlg.h>
#include <map>
#include <string>

using namespace std;

#pragma comment ( lib, "psapi.lib")
#define MAX_LOADSTRING 100

#define WM_SHELLNOTIFY WM_USER+5000
#define IDI_TRAY 42
#define ID_MRES 421
#define ID_MABOUT 422
#define ORDER_ASC 0
#define ORDER_DESC 1

typedef struct
{
	int Keys;
	char *Name;
	const char *FullName;
}ItemData;

// Global Variables:
HINSTANCE hInst;
TCHAR szTitle[MAX_LOADSTRING];
TCHAR szWindowClass[MAX_LOADSTRING];

HHOOK hHook;
HWND m_hWnd;
HWND m_hList;
HWND m_hDataFile;
HWND m_hShowFullPath;
HWND m_hCheckProgram;
HWND m_hKeyStrokes;
char m_Buffer[_MAX_DIR];
UINT m_Order;
HMENU m_hPopupMenu;

CCounter m_Counter;
NOTIFYICONDATA m_NotifyIconData;

// Forward declarations of functions included in this code module:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// User functions
LRESULT CALLBACK KeyboardHook(int nCode, WPARAM wParam, LPARAM lParam);
void UpdateList();
bool LoadDataPath();
void SaveDataPath();
int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
bool AddItem(char *Name,int Item, int SubItem, ItemData *pItemData=NULL);
void MenuTest();

// Message Handlers
void OnSize(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
void OnShellNotify(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
void OnInitDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
void OnCommand(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
void OnNotify(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;
	hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHook, GetModuleHandle(NULL), 0);

	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_KEYCOUNTER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if(!InitInstance(hInstance, nCmdShow))
	{
		return(FALSE);
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_KEYCOUNTER);

	//Update checkbox state
	Button_SetCheck(GetDlgItem(m_hWnd,IDC_CHECK_PROGRAM_INFO),m_Counter.GetCheckProgram());
	Button_SetCheck(GetDlgItem(m_hWnd,IDC_CHECK_FULL_PATH),m_Counter.GetShowFullPath());

	if(!LoadDataPath())
		return(FALSE);

	//Reset key counter
	m_Counter.Load();

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return((int)msg.wParam);
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize=sizeof(WNDCLASSEX); 

	wcex.style=CS_HREDRAW|CS_VREDRAW;
	wcex.lpfnWndProc=(WNDPROC)WndProc;
	wcex.cbClsExtra=0;
	wcex.cbWndExtra=DLGWINDOWEXTRA;
	wcex.hInstance=hInstance;
	wcex.hIcon=LoadIcon(hInstance,(LPCTSTR)IDI_KEYBOARD);
	wcex.hCursor=LoadCursor(NULL,IDC_ARROW);
	wcex.hbrBackground=(HBRUSH)(COLOR_BTNFACE+1);
	wcex.lpszMenuName=NULL;
	wcex.lpszClassName=szWindowClass;
	wcex.hIconSm=LoadIcon(wcex.hInstance,(LPCTSTR)IDI_KEYBOARD);

	return(RegisterClassEx(&wcex));
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst=hInstance;
	m_hWnd=CreateDialog(hInstance,(LPCTSTR)IDD_MAIN,NULL,(DLGPROC)WndProc);
	if(!m_hWnd)
		return(FALSE);
	ShowWindow(m_hWnd, SW_MINIMIZE);

	// Create the notify icon.
	m_NotifyIconData.cbSize=sizeof(NOTIFYICONDATA);
	m_NotifyIconData.hIcon=LoadIcon(hInst,MAKEINTRESOURCE(IDI_KEYBOARD));
	m_NotifyIconData.hWnd=m_hWnd;
	m_NotifyIconData.uCallbackMessage=WM_SHELLNOTIFY;

	sprintf(m_Buffer,"Keystrokes: %d",m_Counter.GetKeyStrokes());
	lstrcpy(m_NotifyIconData.szTip, m_Buffer);
	SetWindowText(m_hKeyStrokes,m_Buffer);

	m_NotifyIconData.uID=IDI_TRAY;
	m_NotifyIconData.uFlags=NIF_ICON | NIF_MESSAGE | NIF_TIP;
	ShowWindow(m_hWnd,SW_HIDE);
	Shell_NotifyIcon(NIM_ADD,&m_NotifyIconData);

	// Load menu
	m_hPopupMenu=LoadMenu(hInst,MAKEINTRESOURCE(IDR_MENU_POPUP));

	return(TRUE);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message) 
	{
		case WM_NOTIFY:
			OnNotify(hWnd,message,wParam,lParam);
		case WM_SIZE:
			OnSize(hWnd,message,wParam,lParam);
			break;
		case WM_INITDIALOG:
			OnInitDialog(hWnd,message,wParam,lParam);
			break;
		case WM_CLOSE:
			if(MessageBox(hWnd,"Close Program?","Confirm",MB_YESNO|MB_ICONQUESTION)==IDYES)
				DestroyWindow(hWnd);
			return(TRUE);
		case WM_SHELLNOTIFY:
			OnShellNotify(hWnd,message,wParam,lParam);
			break;
		case WM_COMMAND:
			OnCommand(hWnd,message,wParam,lParam);
			break;
		case WM_DESTROY:
			UnhookWindowsHookEx(hHook);
			m_Counter.Save();
			Shell_NotifyIcon(NIM_DELETE,&m_NotifyIconData);
			PostQuitMessage(0);
			break;
		default:
			return(DefWindowProc(hWnd, message, wParam, lParam));
	}
	return 0;
}

void OnNotify(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	if(wParam==IDC_LIST_PROGRAM_KEYSTROKE)
	{
		LV_DISPINFO *pLvdi=(LV_DISPINFO*)lParam;
		NM_LISTVIEW *pNm=(NM_LISTVIEW*)lParam;
		switch(pLvdi->hdr.code)
		{
			case LVN_COLUMNCLICK:
			{
				ListView_SortItems(pNm->hdr.hwndFrom,CompareFunc,(LPARAM)(pNm->iSubItem));
				if(m_Order==ORDER_ASC)
					m_Order=ORDER_DESC;
				else
					m_Order=ORDER_ASC;
				break;
			}
			case NM_RCLICK:
			{
				POINT pt;
				GetCursorPos(&pt);
				TrackPopupMenu(GetSubMenu(m_hPopupMenu,1),TPM_LEFTALIGN|TPM_LEFTBUTTON,pt.x,pt.y,0,m_hWnd,NULL);
			}
		}
	}
}

void OnSize(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	if(wParam==SIZE_MINIMIZED)
	{
		ShowWindow(m_hWnd,SW_HIDE);
	}
}

void OnShellNotify(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	if(lParam==WM_LBUTTONDBLCLK)
	{
		ShowWindow(m_hWnd,SW_SHOWNORMAL);
		SetForegroundWindow(m_hWnd);

		sprintf(m_Buffer,"Keystrokes: %d",m_Counter.GetKeyStrokes());
		lstrcpy(m_NotifyIconData.szTip, m_Buffer);
		SetWindowText(m_hKeyStrokes,m_Buffer);
		UpdateList();
	}
	else if(lParam==WM_RBUTTONUP)
	{
		POINT pt;
		GetCursorPos(&pt);
		TrackPopupMenu(GetSubMenu(m_hPopupMenu,0),TPM_RIGHTALIGN|TPM_LEFTBUTTON,pt.x,pt.y,0,m_hWnd,NULL);
	}
}

void OnInitDialog(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	m_hDataFile=GetDlgItem(hWnd,IDC_EDIT_DATA_PATH);
	m_hList=GetDlgItem(hWnd,IDC_LIST_PROGRAM_KEYSTROKE);
	m_hCheckProgram=GetDlgItem(hWnd,IDC_CHECK_PROGRAM_INFO);
	m_hShowFullPath=GetDlgItem(hWnd,IDC_CHECK_FULL_PATH);
	m_hKeyStrokes=GetDlgItem(hWnd,IDC_STATIC_KEYSTROKES);

	SendMessage(m_hList,LVM_SETEXTENDEDLISTVIEWSTYLE,0,LVS_EX_FULLROWSELECT);

	// Add headers to listbox.
	LV_COLUMN LvCol;
	memset(&LvCol,0,sizeof(LvCol));
	LvCol.mask=LVCF_TEXT|LVCF_WIDTH|LVCF_SUBITEM;
	LvCol.pszText="Keys";
	LvCol.cx=70;
	SendMessage(m_hList,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol);
	LvCol.cx=190;
	LvCol.pszText="Program";
	SendMessage(m_hList,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol);
}

void OnCommand(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	switch(LOWORD(wParam))
	{
		case IDC_CHECK_FULL_PATH:
		{
			m_Counter.SetShowFullPath(Button_GetCheck(m_hShowFullPath));
			UpdateList();
			break;
		}
		case IDC_CHECK_PROGRAM_INFO:
		{
			m_Counter.SetCheckProgram(Button_GetCheck(m_hCheckProgram));
			break;
		}
		case IDC_BUTTON_BROWSE:
		{
			OPENFILENAME ofn;
			char szFile[_MAX_DIR];

			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = m_hWnd;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = "Keystore Datafile (*.kdt)\0*.kdt\0All Files (*.*)\0*.*\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.lpstrDefExt="kdt";
			ofn.Flags = OFN_PATHMUSTEXIST;
			if (GetOpenFileName(&ofn)==TRUE)
			{
				SetWindowText(m_hDataFile,szFile);
				m_Counter.SetDataFile(szFile);
				SaveDataPath();
			}
		}
		case ID_TRAYPOPUP_SHOW:
		{
			m_Counter.ThreadTest();
		//	PostMessage(m_hWnd,WM_SHELLNOTIFY,NULL,WM_LBUTTONDBLCLK);
			break;
		}
		case ID_TRAYPOPUP_EXIT:
		{
			PostMessage(m_hWnd,WM_CLOSE,NULL,NULL);
			break;
		}
		case ID_LISTPOPUP_REMOVE:
		{
			if(MessageBox(m_hWnd,"Remove Program?","Confirm",MB_YESNO|MB_ICONQUESTION)==IDYES)
			{
				int Selected;
				if((Selected=SendMessage(m_hList,LVM_GETNEXTITEM,-1,LVNI_FOCUSED))!=-1)
				{
					LVITEM LvItem;
					memset(&LvItem,0,sizeof(LvItem));
					LvItem.mask=LVIF_PARAM;
					LvItem.iItem=Selected;
					LvItem.iSubItem=0;
					if(SendMessage(m_hList,LVM_GETITEM,0,(LPARAM)(LPLVITEM)&LvItem)==TRUE)
					{
						ItemData *id=(ItemData*)LvItem.lParam;
						m_Counter.RemoveProgram(id->FullName);
						SendMessage(m_hList,LVM_DELETEITEM,Selected,0);
					}
					else
					{
						MessageBox(m_hWnd,"FALSE!","Error",MB_OK|MB_ICONINFORMATION);
					}
				}
				else
				{
					MessageBox(m_hWnd,"No item selected.","Error",MB_OK|MB_ICONINFORMATION);
				}
			}
		}
	}
}

LRESULT CALLBACK KeyboardHook(int nCode, WPARAM wParam, LPARAM lParam)
{
	if(wParam==WM_KEYUP)
	{
		sprintf(m_Buffer,"Keystrokes: %d",m_Counter.GetKeyStrokes());
		lstrcpy(m_NotifyIconData.szTip, m_Buffer);
		SetDlgItemText(m_hWnd,IDC_STATIC_KEYSTROKES,m_Buffer);
		Shell_NotifyIcon(NIM_MODIFY,&m_NotifyIconData);
		m_Counter.AddKeyStroke();
	}
	return(CallNextHookEx(hHook,nCode,wParam,lParam));
}

void UpdateList()
{
	char *Temp=NULL;
	ItemData *pItemData=NULL;
	int i=0;
	map<string,int> keys=m_Counter.GetMap();
	map<string,int>::iterator iter;

	// Clear all items
	SendMessage(m_hList,LVM_DELETEALLITEMS,0,0);
	m_Order=ORDER_ASC;
	for(iter=keys.begin();iter!=keys.end();iter++)
	{
		pItemData=new ItemData();
		pItemData->FullName=iter->first.c_str();
		Temp=new char[_MAX_DIR];
		if(!m_Counter.GetShowFullPath())
			sprintf(Temp,"%s",iter->first.substr(iter->first.find_last_of('\\')+1).c_str());
		else
			sprintf(Temp,"%s",iter->first.c_str());
		pItemData->Keys=iter->second;
		pItemData->Name=Temp;
		AddItem(Temp,i,0,pItemData);
		Temp=new char[_MAX_DIR];
		sprintf(Temp,"%d",iter->second);
		AddItem(Temp,i++,1);
	}
}

bool AddItem(char *Name, int Item, int SubItem, ItemData *pItemData)
{
	LVITEM LvItem;

	memset(&LvItem,0,sizeof(LvItem));
	if(SubItem==0)
		LvItem.mask=LVIF_TEXT|LVIF_PARAM;
	else
		LvItem.mask=LVIF_TEXT;
	LvItem.cchTextMax=256;
	LvItem.pszText=Name;
	LvItem.lParam=(LPARAM)pItemData;
	LvItem.iItem=Item;
	LvItem.iSubItem=SubItem;
	if(SubItem==0)
		SendMessage(m_hList,LVM_INSERTITEM,0,(LPARAM)&LvItem);
	else
		SendMessage(m_hList,LVM_SETITEM,0,(LPARAM)&LvItem);
	return(true);
}

void SaveDataPath()
{
	VGReg reg;
	strcpy(m_Buffer,m_Counter.GetDataFile().c_str());
	reg.WriteValue(HKEY_CURRENT_USER,"Software\\VG Software\\KeyCounter","Path",REG_SZ,m_Buffer,strlen(m_Buffer));
}

bool LoadDataPath()
{
	VGReg reg;
	int i(0);
	if(!reg.ReadValue(HKEY_CURRENT_USER,"Software\\VG Software\\KeyCounter","Path",m_Buffer,_MAX_DIR))
	{
		if(reg.ReadValue(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders","Personal",m_Buffer,_MAX_DIR))
		{
			if(m_Buffer[strlen(m_Buffer)-1]!='\\')
				strcat(m_Buffer,"\\keystrokes.kdt");
			else
				strcat(m_Buffer,"keystrokes.kdt");
			SetWindowText(m_hDataFile,m_Buffer);
			m_Counter.SetDataFile(m_Buffer);
			SaveDataPath();
			return(true);
		}
	}
	else
	{
		SetWindowText(m_hDataFile,m_Buffer);
		m_Counter.SetDataFile(m_Buffer);
		return(true);
	}
	MessageBox(m_hWnd,"Could not create a datafile.","Error",MB_OK|MB_ICONEXCLAMATION);
	return(false);
}

int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	ItemData *Data1=(ItemData*)lParam1;
	ItemData *Data2=(ItemData*)lParam2;
	int iResult=0;
	if(lParamSort==0)
		iResult=strcmpi(Data1->Name,Data2->Name);
	else
		iResult=Data2->Keys-Data1->Keys;
	if(m_Order==ORDER_DESC)
		iResult=iResult-(iResult*2);
	return(iResult);
}
